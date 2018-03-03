#include <sys/types.h>
#include <string.h>
#include "config.h"
 
#include "cpu.h"
#include "bus.h"
#include "console.h"
#include "clock.h"
#include "gdb.h"
#include "main.h"
#include "trace.h"
#include "prof.h"
#include "memdefs.h"
#include "inlinemem.h"

#include "mips-insn.h"
#include "mips-ex.h"
#include "bootrom.h"

// XXX: For now, leave this off, as it isn't compatible with address space ids
//#define USE_TLBMAP


const char rcsid_mips_c[] =
	"$Id: mips.c,v 1.84 2004/04/15 20:14:25 dholland Exp $";


/* number of tlb entries */
#define NTLB  64

/* tlb fields */
#define TLBLO_GLOBAL		0x00000100
#define TLBLO_VALID		0x00000200
#define TLBLO_DIRTY		0x00000400
#define TLBLO_NOCACHE		0x00000800
#define TLBHI_PID		0x00000fc0
#define TLB_PAGEFRAME		0xfffff000

/* status register fields */
#define STATUS_BITS		0xf07ff800	/* these go in status_bits */
/*				0x0f800000  	   RESERVED set to 0 */
#define STATUS_HARDMASK		0x00000400	/* mask bit for lamebus irq */
#define STATUS_SOFTMASK		0x00000300	/* mask bits for soft irqs */
/*				0x000000c0  	   RESERVED set to 0 */
#define STATUS_KUo		0x00000020	/* old_usermode */
#define STATUS_IEo		0x00000010	/* old_irqon */
#define STATUS_KUp		0x00000008	/* prev_usermode */
#define STATUS_IEp		0x00000004	/* prev_irqon */
#define STATUS_KUc		0x00000002	/* current_usermode */
#define STATUS_IEc		0x00000001	/* current_irqon */

/* cause register fields */
#define CAUSE_BD		0x80000000	/* branch-delay flag */
/*				0x40000000	   RESERVED set to 0 */
#define CAUSE_CE		0x30000000	/* coprocessor # of exn */
/*				0x0fff0000	   RESERVED set to 0 */
/*				0x0000f800	   unused hardware irqs */
#define CAUSE_HARDIRQ		0x00000400	/* lamebus hardware irq bit */
#define CAUSE_SOFTIRQ		0x00000300	/* soft interrupt triggers */
/*				0x000000c0	   RESERVED set to 0 */
#define CAUSE_EXCODE		0x0000003c	/* exception code */
/*				0x00000003	   RESERVED Set to 0 */

/* tlb random register parameters (it ranges from 8 to 63) */
#define RANDREG_MAX		56
#define RANDREG_OFFSET		8

/* system coprocessor (cop0) registers */
#define C0_INDEX   0
#define C0_RANDOM  1
#define C0_TLBLO   2
#define C0_CONTEXT 4
#define C0_VADDR   8
#define C0_TLBHI   10
#define C0_STATUS  12
#define C0_CAUSE   13
#define C0_EPC     14
#define C0_PRID    15

/* MIPS hardwired memory segments */
#define KSEG2	0xc0000000
#define KSEG1	0xa0000000
#define KSEG0	0x80000000
#define KUSEG	0x00000000

#ifdef USE_TLBMAP
/* tlbmap value for "nothing" */
#define TM_NOPAGE    255
#endif

/* number of general registers */
#define NREGS 32

struct mipstlb {
	int mt_global;		// 1: translation is global
	int mt_valid;		// 1: translation is valid for use
	int mt_dirty;		// 1: write enable
	int mt_nocache;		// 1: cache disable
	u_int32_t mt_pfn;	// page number part of physical address
	u_int32_t mt_vpn;	// page number part of virtual address
	u_int32_t mt_pid;	// address space id (note: shifted left 6)
};

struct mipscpu {
	// general registers
	int32_t r[NREGS];

	// special registers
	int32_t lo, hi;

	// pipeline stall logic
	int lowait, hiwait; // cycles to wait for lo/hi to become ready

	// "jumping" is set by the jump instruction.
	// "in_jumpdelay" is set during decoding of the instruction in a jump 
	// delay slot.
	int jumping;
	int in_jumpdelay;

	// pc/exception stuff
	//
	// at instruction decode time, pc points to the delay slot and
	// nextpc points to the instruction after. thus, a branch
	// instruction alters nextpc. expc points to the instruction
	// being executed (unless it's in the delay slot of a jump).

	u_int32_t expc;         // pc for exception (not incr. while jumping)
	
	u_int32_t pc;           // pc
	u_int32_t nextpc;       // succeeding pc
	u_int32_t pcoff;	// page offset of pc
	u_int32_t nextpcoff;	// page offset of nextpc
	const u_int32_t *pcpage;	// precomputed memory page of pc
	const u_int32_t *nextpcpage;	// precomputed memory page of nextpc

	// mmu
	struct mipstlb tlb[NTLB];
	struct mipstlb tlbentry;	// cop0 register 2 (lo) and 10 (hi)
#ifdef USE_TLBMAP
	u_int8_t tlbmap[1024*1024];	// vpn -> tlbentry map
#endif

	/*
	 * tlb index register (cop0 register 0)
	 */
	int tlbindex;		// not shifted; 0-63
	int tlbpf;		// true if a tlpb failed

	/*
	 * tlb random register (cop0 register 1)
	 */
	int tlbrandom;		// not shifted, not bounded, 0-based

	// exception stuff

	/*
	 * status register (cop0 register 12)
	 */
	int old_usermode;
	int old_irqon;
	int prev_usermode;
	int prev_irqon;
	int current_usermode;
	int current_irqon;
	int status_hardmask;		// true if lamebus irq is masked
	u_int32_t status_softmask;	// soft interrupt masking bits
	u_int32_t status_bits;  // unsplit bits from status register
	
	/*
	 * cause register (cop0 register 13)
	 */
	int cause_bd;			// NOT shifted
	u_int32_t cause_ce;		// already shifted
	u_int32_t cause_softirq;	// already shifted
	u_int32_t cause_code;		// already shifted

	u_int32_t ex_context;	// cop0 register 4
	u_int32_t ex_epc;	// cop0 register 14
	u_int32_t ex_vaddr;	// cop0 register 8
	u_int32_t ex_prid;	// cop0 register 15
};

#define IS_USERMODE(cpu) ((cpu)->current_usermode)

static struct mipscpu mycpu;

/*************************************************************/

static const char *exception_names[13] = {
	"interrupt",
	"TLB modify",
	"TLB miss - load",
	"TLB miss - store",
	"Address error - load",
	"Address error - store",
	"Bus error - code",
	"Bus error - data",
	"System call",
	"Breakpoint",
	"Illegal instruction",
	"Coprocessor unusable",
	"Arithmetic overflow",
};

static
const char *
exception_name(int code)
{
	if (code >= 0 && code < 13) {
		return exception_names[code];
	}
	smoke("Name of invalid exception code requested");
	return "???";
}

/*************************************************************/

/*
 * These are further down.
 */
static int precompute_pc(struct mipscpu *cpu);
static int precompute_nextpc(struct mipscpu *cpu);

/*
 * The MIPS doesn't clear the TLB on reset, so it's perfectly correct
 * to do nothing here. However, let's initialize it to all entries that
 * can't be matched.
 */

static
void
reset_tlbentry(struct mipstlb *mt, int index)
{
	mt->mt_global = 0;
	mt->mt_valid = 0;
	mt->mt_dirty = 0;
	mt->mt_nocache = 0;
	mt->mt_pfn = 0;
	mt->mt_vpn = 0x81000000 + index*0x1000;
	mt->mt_pid = 0;
}

static
void
mips_init(struct mipscpu *cpu)
{
	int i;
	for (i=0; i<NREGS; i++) {
		cpu->r[i] = 0;
	}
	cpu->lo = cpu->hi = 0;
	cpu->lowait = cpu->hiwait = 0;

	cpu->jumping = cpu->in_jumpdelay = 0;

	cpu->expc = 0;

	/* pc starts at 0xbfc00000; nextpc at 0xbfc00004 */
	cpu->pc = 0xbfc00000;
	cpu->nextpc = 0xbfc00004;
	if (precompute_pc(cpu)) {
		smoke("precompute_pc failed in mips_init");
	}
	if (precompute_nextpc(cpu)) {
		smoke("precompute_nextpc failed in mips_init");
	}

	for (i=0; i<NTLB; i++) {
		reset_tlbentry(&cpu->tlb[i], i);
	}
	reset_tlbentry(&cpu->tlb[i], NTLB);
#ifdef USE_TLBMAP
	memset(cpu->tlbmap, TM_NOPAGE, sizeof(cpu->tlbmap));
#endif
	cpu->tlbindex = 0;
	cpu->tlbrandom = RANDREG_MAX-1;

	cpu->status_bits = 0x00400000;
	cpu->status_hardmask = 0;
	cpu->status_softmask = 0;
	cpu->old_usermode = 0;
	cpu->old_irqon = 0;
	cpu->prev_usermode = 0;
	cpu->prev_irqon = 0;
	cpu->current_usermode = 0;
	cpu->current_irqon = 0;

	cpu->cause_bd = 0;
	cpu->cause_ce = 0;
	cpu->cause_softirq = 0;
	cpu->cause_code = 0;

	cpu->ex_context = 0;
	cpu->ex_epc = 0;
	cpu->ex_vaddr = 0;
	cpu->ex_prid = 0x03ff;  // implementation 3, revision 0xff (XXX)
}

static
u_int32_t
tlbgetlo(const struct mipstlb *mt)
{
	u_int32_t val = mt->mt_pfn;
	if (mt->mt_global) {
		val |= TLBLO_GLOBAL;
	}
	if (mt->mt_valid) {
		val |= TLBLO_VALID;
	}
	if (mt->mt_dirty) {
		val |= TLBLO_DIRTY;
	}
	if (mt->mt_nocache) {
		val |= TLBLO_NOCACHE;
	}
	return val;
}

static
u_int32_t
tlbgethi(const struct mipstlb *mt)
{
	u_int32_t val = mt->mt_vpn;
	val |= mt->mt_pid;
	return val;
}

static
void
tlbsetlo(struct mipstlb *mt, u_int32_t val)
{
	mt->mt_global = val & TLBLO_GLOBAL;
	mt->mt_valid = val & TLBLO_VALID;
	mt->mt_dirty = val & TLBLO_DIRTY;
	mt->mt_nocache = val & TLBLO_NOCACHE;
	mt->mt_pfn = val & TLB_PAGEFRAME;
}

static
void
tlbsethi(struct mipstlb *mt, u_int32_t val)
{
	mt->mt_vpn = val & TLB_PAGEFRAME;
	mt->mt_pid = val & TLBHI_PID;
}

#define TLBTRP(t) TRACEL(DOTRACE_TLB, \
			("%05x %s%s%s%s", \
				(t)->mt_pfn >> 12, \
				(t)->mt_global ? "G" : "-", \
				(t)->mt_valid ? "V" : "-", \
				(t)->mt_dirty ? "D" : "-", \
				(t)->mt_nocache ? "N" : "-"))
#define TLBTRV(t) TRACEL(DOTRACE_TLB, \
			("%05x/%03x -> ", \
				(t)->mt_vpn >> 12, (t)->mt_pid))
#define TLBTR(t) {TLBTRV(t);TLBTRP(t);}

static
void
tlbmsg(const char *what, int index, const struct mipstlb *t)
{
	msgl("%s: ", what);
	if (index>=0) {
		msgl("index %d, %s", index, index < 10 ? " " : "");
	}
	else {
		msgl("tlbhi/lo, ");
	}
	msgl("vpn 0x%08lx, ", (unsigned long) t->mt_vpn);
	     
	if (t->mt_global) {
		msgl("global, ");
	}
	else {
		msgl("pid %d, %s", (int) t->mt_pid,
		     t->mt_pid < 10 ? " " : "");
	}

	msg("ppn 0x%08lx (%s%s%s)",
	    (unsigned long) t->mt_pfn,
	    t->mt_valid ? "V" : "-",
	    t->mt_dirty ? "D" : "-",
	    t->mt_nocache ? "N" : "-");
}

static
void
check_tlb_dups(struct mipscpu *cpu, int newix)
{
	u_int32_t vpn, pid;
	int gbl, i;

	vpn = cpu->tlb[newix].mt_vpn;
	pid = cpu->tlb[newix].mt_pid;
	gbl = cpu->tlb[newix].mt_global;

	for (i=0; i<NTLB; i++) {
		if (i == newix) {
			continue;
		}
		if (vpn != cpu->tlb[i].mt_vpn) {
			continue;
		}

		/*
		 * We've got two translations for the same virtual page.
		 * If both translations would ever match at once, it's bad.
		 * This is true if *either* is global or if the pids are
		 * the same. Note that it doesn't matter if the valid bits
		 * are set - translations that are not valid are still 
		 * accessed.
		 */

		if (gbl ||
		    cpu->tlb[i].mt_global ||
		    pid == cpu->tlb[i].mt_pid) {
			msg("Duplicate TLB entries!");
			tlbmsg("New entry", newix, &cpu->tlb[newix]);
			tlbmsg("Old entry", i, &cpu->tlb[i]);
			hang("Duplicate TLB entries for vpage %x",
			     cpu->tlb[i].mt_vpn);
		}
	}
}

static
inline
int
findtlb(const struct mipscpu *cpu, u_int32_t vpage)
{
#ifdef USE_TLBMAP
	u_int8_t tm;

	tm = cpu->tlbmap[vpage >> 12];
	if (tm == TM_NOPAGE) {
		return -1;
	}
	return tm;
#else
	int i;
	for (i=0; i<NTLB; i++) {
		const struct mipstlb *mt = &cpu->tlb[i];
		if (mt->mt_vpn!=vpage) continue;
		if (mt->mt_pid==cpu->tlbentry.mt_pid || mt->mt_global) {
			return i;
		}
	}

	return -1;
#endif
}

static
void
probetlb(struct mipscpu *cpu)
{
	u_int32_t vpage;
	int ix;

	vpage = cpu->tlbentry.mt_vpn;
	ix = findtlb(cpu, vpage);

	TRACEL(DOTRACE_TLB, ("tlbp:       "));
	TLBTRV(&cpu->tlbentry);

	if (ix<0) {
		TRACE(DOTRACE_TLB, ("NOT FOUND"));
		cpu->tlbpf = 1;
	}
	else {
		TLBTRP(&cpu->tlb[ix]);
		TRACE(DOTRACE_TLB, (": [%d]", ix));
		cpu->tlbindex = ix;
		cpu->tlbpf = 0;
	}
}

static
void
writetlb(struct mipscpu *cpu, int ix, const char *how)
{
	(void)how;
	TRACEL(DOTRACE_TLB,("%s: [%2d] ", how, ix));
	TLBTR(&cpu->tlb[ix]);
	TRACEL(DOTRACE_TLB, (" ==> "));
	TLBTR(&cpu->tlbentry);
	TRACE(DOTRACE_TLB, (" "));

#ifdef USE_TLBMAP
	cpu->tlbmap[cpu->tlb[ix].mt_vpn >> 12] = TM_NOPAGE;
#endif

	cpu->tlb[ix] = cpu->tlbentry;

#ifdef USE_TLBMAP
	cpu->tlbmap[cpu->tlb[ix].mt_vpn >> 12] = ix;
#endif

	check_tlb_dups(cpu, ix);

	/* 
	 * If the OS coder is a lunatic, the mapping for the pc might
	 * have changed. If this causes an exception, we don't need
	 * to do anything special, though.
	 */
	(void) precompute_pc(cpu);
	(void) precompute_nextpc(cpu);
}

static
void
do_wait(struct mipscpu *cpu)
{
	(void)cpu;
	TRACE(DOTRACE_IRQ, ("Waiting for interrupt"));
	clock_waitirq();
}

static
void
do_rfe(struct mipscpu *cpu)
{
	//u_int32_t bits;

	if (IS_USERMODE(cpu)) {
		smoke("RFE in usermode not caught by instruction decoder");
	}

	cpu->current_usermode = cpu->prev_usermode;
	cpu->current_irqon = cpu->prev_irqon;
	cpu->prev_usermode = cpu->old_usermode;
	cpu->prev_irqon = cpu->old_irqon;
	TRACE(DOTRACE_EXN, ("Return from exception: %s mode, interrupts %s",
			    (cpu->current_usermode) ? "user" : "kernel",
			    (cpu->current_irqon) ? "on" : "off"));

	/*
	 * Re-lookup the translations for the pc, because we might have
	 * changed to usermode.
	 *
	 * Furthermore, hack the processor state so the exception happens
	 * with things pointing to the instruction happening after the rfe,
	 * not the rfe itself.
	 */
	
	cpu->in_jumpdelay = 0;
	cpu->expc = cpu->pc;

	precompute_pc(cpu);
	precompute_nextpc(cpu);
}

/*
 * This corrects the state of the processor if we're handling a
 * breakpoint with the remote gdb code. The remote gdb code should use
 * cpu->expc as the place execution stopped; in that case something
 * vaguely reasonable will happen if some nimrod puts a breakpoint in
 * a branch delay slot.
 */
static
void
phony_exception(struct mipscpu *cpu)
{
	cpu->jumping = 0;
	cpu->in_jumpdelay = 0;
	cpu->pc = cpu->expc;
	cpu->nextpc = cpu->pc + 4;

	/*
	 * These shouldn't fail because we were just executing with 
	 * the same values.
	 */
	if (precompute_pc(cpu)) {
		smoke("precompute_pc failed in phony_exception");
	}
	if (precompute_nextpc(cpu)) {
		smoke("precompute_nextpc failed in phony_exception");
	}
}

static
void
exception(struct mipscpu *cpu, int code, int cn_or_user, u_int32_t vaddr)
{
	//u_int32_t bits;
	int boot = (cpu->status_bits & 0x00400000)!=0;

	TRACE(DOTRACE_EXN, ("exception: code %d (%s), expc %x, vaddr %x", 
	      code, exception_name(code), cpu->expc, vaddr));

	if (code==EX_IRQ) {
		g_stats.s_irqs++;
	}
	else {
		g_stats.s_exns++;
	}

	cpu->cause_bd = cpu->in_jumpdelay;
	if (code==EX_CPU) {
		cpu->cause_ce = ((u_int32_t)cn_or_user << 28);
	}
	else {
		cpu->cause_ce = 0;
	}
	cpu->cause_code = code << 2;

	cpu->jumping = 0;
	cpu->in_jumpdelay = 0;

	// roll the status bits
	cpu->old_usermode = cpu->prev_usermode;
	cpu->old_irqon = cpu->prev_irqon;
	cpu->prev_usermode = cpu->current_usermode;
	cpu->prev_irqon = cpu->current_irqon;
	cpu->current_usermode = 0;
	cpu->current_irqon = 0;

	cpu->ex_vaddr = vaddr;
	cpu->ex_context &= 0xffe00000;
	cpu->ex_context |= ((vaddr & 0x7ffff000) >> 10);
	
	cpu->ex_epc = cpu->expc;

	if ((code==EX_TLBL || code==EX_TLBS) && cn_or_user) {
		// use special UTLB exception vector
		cpu->pc = boot ? 0xbfc00100 : 0x80000000;
	}
	else {
		cpu->pc = boot ? 0xbfc00180 : 0x80000080;
	}
	cpu->nextpc = cpu->pc + 4;

	/*
	 * These cannot fail. Furthermore, if for some reason they do,
	 * they'll likely recurse forever and not return, so checking
	 * the return value is fairly pointless.
	 */
	(void) precompute_pc(cpu);
	(void) precompute_nextpc(cpu);
}

/*
 * Warning: do not change this function without making corresponding
 * changes to debug_translatemem (below).
 */
static
inline
int
translatemem(struct mipscpu *cpu, u_int32_t vaddr, int iswrite, u_int32_t *ret)
{
	u_int32_t seg;
	u_int32_t paddr;

	// MIPS hardwired memory layout:
	//    0xc0000000 - 0xffffffff   kseg2 (kernel, tlb-mapped)
	//    0xa0000000 - 0xbfffffff   kseg1 (kernel, unmapped, uncached)
	//    0x80000000 - 0x9fffffff   kseg0 (kernel, unmapped, cached)
	//    0x00000000 - 0x7fffffff   kuseg (user, tlb-mapped)
	//
	// Since we don't implement cache, we can consider kseg0 and kseg1
	// equivalent (except remember that the base of each maps to paddr 0.)

	/*
	 * On intel at least it's noticeably faster this way:
	 * compute seg first, but don't use it when checking for address
	 * error, only for whether we're in a direct-mapped segment.
	 *
	 * My guess is that gcc's instruction scheduler isn't good enough to
	 * handle this on its own and we get pipeline stalls with a more
	 * sensible organization.
	 */
	seg = vaddr >> 30;

	if ((vaddr >= 0x80000000 && IS_USERMODE(cpu)) || (vaddr & 0x3)!=0) {
		exception(cpu, iswrite ? EX_ADES : EX_ADEL, 0, vaddr);
		return -1;
	}

	if (seg==2) {
		paddr = vaddr & 0x1fffffff;
	}
	else {
		u_int32_t vpage;
		u_int32_t off;
		u_int32_t ppage;
		int ix;

		vpage = vaddr & 0xfffff000;
		off   = vaddr & 0x00000fff;

		TRACEL(DOTRACE_TLB, ("tlblookup:  %05x/%03x -> ", 
				     vpage >> 12, cpu->tlbentry.mt_pid));

		cpu->tlbentry.mt_vpn = vpage;
		ix = findtlb(cpu, vpage);

		if (ix<0) {
			int exc = iswrite ? EX_TLBS : EX_TLBL;
			int isuseraddr = vaddr < 0x80000000;
			TRACE(DOTRACE_TLB, ("MISS"));
			exception(cpu, exc, isuseraddr, vaddr);
			return -1;
		}
		TLBTRP(&cpu->tlb[ix]);
		TRACEL(DOTRACE_TLB, (": [%d]", ix));

		if (!cpu->tlb[ix].mt_valid) {
			int exc = iswrite ? EX_TLBS : EX_TLBL;
			TRACE(DOTRACE_TLB, (" - INVALID"));
			exception(cpu, exc, 0, vaddr);
			return -1;
		}
		if (iswrite && !cpu->tlb[ix].mt_dirty) {
			TRACE(DOTRACE_TLB, (" - READONLY"));
			exception(cpu, EX_MOD, 0, vaddr);
			return -1;
		}
		TRACE(DOTRACE_TLB, (" - OK"));
		ppage = cpu->tlb[ix].mt_pfn;
		paddr = ppage|off;
	}

	*ret = paddr;
	return 0;
}

/*
 * Special version of translatemem for use from the gdb access code. It
 * does not touch the cpu state and always considers itself to be in 
 * supervisor mode.
 *
 * Warning: do not change this function without making corresponding
 * changes to the original translatemem (above).
 */
static
inline
int
debug_translatemem(const struct mipscpu *cpu, u_int32_t vaddr, 
		   int iswrite, u_int32_t *ret)
{
	u_int32_t paddr;

	if ((vaddr & 0x3)!=0) {
		return -1;
	}

	if ((vaddr >> 30)==2) {
		paddr = vaddr & 0x1fffffff;
	}
	else {
		u_int32_t vpage;
		u_int32_t off;
		u_int32_t ppage;
		int ix;

		vpage = vaddr & 0xfffff000;
		off   = vaddr & 0x00000fff;

		TRACEL(DOTRACE_TLB, ("tlblookup (debugger):  %05x/%03x -> ", 
				     vpage >> 12, cpu->tlbentry.mt_pid));

		ix = findtlb(cpu, vpage);

		if (ix<0) {
			TRACE(DOTRACE_TLB, ("MISS"));
			return -1;
		}
		TLBTRP(&cpu->tlb[ix]);
		TRACEL(DOTRACE_TLB, (": [%d]", ix));

		if (!cpu->tlb[ix].mt_valid) {
			TRACE(DOTRACE_TLB, (" - INVALID"));
			return -1;
		}
		if (iswrite && !cpu->tlb[ix].mt_dirty) {
			TRACE(DOTRACE_TLB, (" - READONLY"));
			return -1;
		}
		TRACE(DOTRACE_TLB, (" - OK"));
		ppage = cpu->tlb[ix].mt_pfn;
		paddr = ppage|off;
	}

	*ret = paddr;
	return 0;

}

static
inline
int
accessmem(struct mipscpu *cpu, u_int32_t paddr, int iswrite, u_int32_t *val)
{
	int buserr;

	/*
	 * Physical memory layout: 
	 *    0x00000000 - 0x1fbfffff     RAM
	 *    0x1fc00000 - 0x1fdfffff     Boot ROM
	 *    0x1fe00000 - 0x1fffffff     LAMEbus mapped I/O
	 *    0x20000000 - 0xffffffff     RAM
	 */
	
	if (paddr < 0x1fc00000) {
		if (iswrite) {
			buserr = bus_mem_store(paddr, *val);
		}
		else {
			buserr = bus_mem_fetch(paddr, val);
		}
	}
	else if (paddr < 0x1fe00000) {
		if (iswrite) {
			buserr = -1; /* ROM is, after all, read-only */
		}
		else {
			buserr = bootrom_fetch(paddr - 0x1fc00000, val);
		}
	}
	else if (paddr < 0x20000000) {
		if (iswrite) {
			buserr = bus_io_store(paddr-0x1fe00000, *val);
		}
		else {
			buserr = bus_io_fetch(paddr-0x1fe00000, val);
		}
	}
	else {
		if (iswrite) {
			buserr = bus_mem_store(paddr-0x00400000, *val);
		}
		else {
			buserr = bus_mem_fetch(paddr-0x00400000, val);
		}
	}

	if (buserr) {
		exception(cpu, EX_DBE, 0, 0);
		return -1;
	}
	
	return 0;
}

/*
 * This is a special version of accessmem used for instruction fetch.
 * It returns a pointer to an entire page of memory which can then be
 * used repeatedly. Note that it doesn't call exception() - it just
 * returns NULL if the memory doesn't exist.
 */
static
inline
const u_int32_t *
mapmem(u_int32_t paddr)
{
	/*
	 * Physical memory layout: 
	 *    0x00000000 - 0x1fbfffff     RAM
	 *    0x1fc00000 - 0x1fdfffff     Boot ROM
	 *    0x1fe00000 - 0x1fffffff     LAMEbus mapped I/O
	 *    0x20000000 - 0xffffffff     RAM
	 */
	paddr &= 0xfffff000;

	if (paddr < 0x1fc00000) {
		return bus_mem_map(paddr);
	}

	if (paddr < 0x1fe00000) {
		return bootrom_map(paddr - 0x1fc00000);
	}

	if (paddr < 0x20000000) {
		/* don't allow executing from I/O registers */
		return NULL;
	}

	return bus_mem_map(paddr-0x00400000);
}

/*
 * iswrite should be true if *this* domem operation is a write.
 *
 * willbewrite should be true if any domem operation on this
 * cycle is (or will be) a write, even if *this* one isn't.
 * (This is for preventing silly exception behavior when writing
 * a sub-word quantity.)
 */
static
int
domem(struct mipscpu *cpu, u_int32_t vaddr, u_int32_t *val, 
      int iswrite, int willbewrite)
{
	u_int32_t paddr;
	
	if (translatemem(cpu, vaddr, willbewrite, &paddr)) {
		return -1;
	}

	return accessmem(cpu, paddr, iswrite, val);
}

static
int
precompute_pc(struct mipscpu *cpu)
{
	u_int32_t physpc;
	if (translatemem(cpu, cpu->pc, 0, &physpc)) {
		return -1;
	}
	cpu->pcpage = mapmem(physpc);
	if (cpu->pcpage == NULL) {
		exception(cpu, EX_IBE, 0, 0);
		if (cpu->pcpage == NULL) {
			smoke("Bus error invoking exception handler");
		}
		return -1;
	}
	cpu->pcoff = physpc & 0xfff;
	return 0;
}

static
int
precompute_nextpc(struct mipscpu *cpu)
{
	u_int32_t physnext;
	if (translatemem(cpu, cpu->nextpc, 0, &physnext)) {
		return -1;
	}
	cpu->nextpcpage = mapmem(physnext);
	if (cpu->nextpcpage == NULL) {
		exception(cpu, EX_IBE, 0, 0);
		if (cpu->nextpcpage == NULL) {
			smoke("Bus error invoking exception handler");
		}
		return -1;
	}
	cpu->nextpcoff = physnext & 0xfff;
	return 0;
}


typedef enum {
	S_SBYTE,
	S_UBYTE,
	S_SHALF,
	S_UHALF,
	S_WORDL,
	S_WORDR,
} memstyles;

static
void
doload(struct mipscpu *cpu, memstyles ms, u_int32_t addr, u_int32_t *res)
{
	switch (ms) {
	    case S_SBYTE:
	    case S_UBYTE:
	    {
		u_int32_t val;
		u_int8_t bval = 0;
		if (domem(cpu, addr & 0xfffffffc, &val, 0, 0)) return;
		switch (addr & 3) {
			case 0: bval = (val & 0xff000000)>>24; break;
			case 1: bval = (val & 0x00ff0000)>>16; break;
			case 2: bval = (val & 0x0000ff00)>>8; break;
			case 3: bval = val & 0x000000ff; break;
		}
		if (ms==S_SBYTE) *res = (int32_t)(int8_t)bval;
		else *res = bval;
	    }
	    break;

	    case S_SHALF:
	    case S_UHALF:
	    {
		u_int32_t val;
		u_int16_t hval = 0;
		if (domem(cpu, addr & 0xfffffffd, &val, 0, 0)) return;
		switch (addr & 2) {
			case 0: hval = (val & 0xffff0000)>>16; break;
			case 2: hval = val & 0x0000ffff; break;
		}
		if (ms==S_SHALF) *res = (int32_t)(int16_t)hval;
		else *res = hval;
	    }
	    break;
     
	    case S_WORDL:
	    {
		u_int32_t val;
		u_int32_t mask = 0;
		int shift = 0;
		if (domem(cpu, addr & 0xfffffffc, &val, 0, 0)) return;
		switch (addr & 0x3) {
		    case 0: mask = 0xffffffff; shift=0; break;
		    case 1: mask = 0xffffff00; shift=8; break;
		    case 2: mask = 0xffff0000; shift=16; break;
		    case 3: mask = 0xff000000; shift=24; break;
		}
		val <<= shift;
		*res = (*res & ~mask) | (val & mask);
	    }
	    break;
	    case S_WORDR:
	    {
		u_int32_t val;
		u_int32_t mask = 0;
		int shift = 0;
		if (domem(cpu, addr & 0xfffffffc, &val, 0, 0)) return;
		switch (addr & 0x3) {
			case 0: mask = 0x000000ff; shift=24; break;
			case 1: mask = 0x0000ffff; shift=16; break;
			case 2: mask = 0x00ffffff; shift=8; break;
			case 3: mask = 0xffffffff; shift=0; break;
		}
		val >>= shift;
		*res = (*res & ~mask) | (val & mask);
	    }
	    break;
	    default:
		smoke("doload: Illegal addressing mode");
	}
}

static
void
dostore(struct mipscpu *cpu, memstyles ms, u_int32_t addr, u_int32_t val)
{
	switch (ms) {
	    case S_UBYTE:
	    {
		u_int32_t wval;
		u_int32_t mask = 0;
		int shift = 0;
		switch (addr & 3) {
		    case 0: mask = 0xff000000; shift=24; break;
		    case 1: mask = 0x00ff0000; shift=16; break;
		    case 2: mask = 0x0000ff00; shift=8; break;
		    case 3: mask = 0x000000ff; shift=0; break;
		}
		if (domem(cpu, addr & 0xfffffffc, &wval, 0, 1)) return;
		wval = (wval & ~mask) | ((val&0xff) << shift);
		if (domem(cpu, addr & 0xfffffffc, &wval, 1, 1)) return;
	    }
	    break;

	    case S_UHALF:
	    {
		u_int32_t wval;
		u_int32_t mask = 0;
		int shift = 0;
		switch (addr & 2) {
			case 0: mask = 0xffff0000; shift=16; break;
			case 2: mask = 0x0000ffff; shift=0; break;
		}
		if (domem(cpu, addr & 0xfffffffd, &wval, 0, 1)) return;
		wval = (wval & ~mask) | ((val&0xffff) << shift);
		if (domem(cpu, addr & 0xfffffffd, &wval, 1, 1)) return;
	    }
	    break;
	
	    case S_WORDL:
	    {
		u_int32_t wval;
		u_int32_t mask = 0;
		int shift = 0;
		if (domem(cpu, addr & 0xfffffffc, &wval, 0, 1)) return;
		switch (addr & 0x3) {
			case 0: mask = 0xffffffff; shift=0; break;
			case 1: mask = 0x00ffffff; shift=8; break;
			case 2: mask = 0x0000ffff; shift=16; break;
			case 3: mask = 0x000000ff; shift=24; break;
		}
		val >>= shift;
		wval = (wval & ~mask) | (val & mask);

		if (domem(cpu, addr & 0xfffffffc, &wval, 1, 1)) return;
	    }
	    break;
	    case S_WORDR:
	    {
		u_int32_t wval;
		u_int32_t mask = 0;
		int shift = 0;
		if (domem(cpu, addr & 0xfffffffc, &wval, 0, 1)) return;
		switch (addr & 0x3) {
			case 0: mask = 0xff000000; shift=24; break;
			case 1: mask = 0xffff0000; shift=16; break;
			case 2: mask = 0xffffff00; shift=8; break;
			case 3: mask = 0xffffffff; shift=0; break;
		}
		val <<= shift;
		wval = (wval & ~mask) | (val & mask);

		if (domem(cpu, addr & 0xfffffffc, &wval, 1, 1)) return;
	    }
	    break;

	    default:
		smoke("dostore: Illegal addressing mode");
	}
}

static 
void
abranch(struct mipscpu *cpu, u_int32_t addr)
{
	TRACE(DOTRACE_JUMP, ("jump: %x -> %x", cpu->nextpc-8, addr));

	if ((addr & 0x3) != 0) {
		exception(cpu, EX_ADEL, 0, addr);
		return;
	}

	// Branches update nextpc (which points to the insn after 
	// the delay slot).

	cpu->nextpc = addr;
	cpu->jumping = 1;

	/*
	 * If the instruction in the delay slot is RFE, don't call
	 * precompute_nextpc. Instead, clear the precomputed nextpc
	 * stuff and call precompute_pc once the RFE has done its
	 * thing. This is important to make sure the new PC is fetched
	 * in user mode if the RFE is switching thereto.
	 */
	if (bus_use_map(cpu->pcpage, cpu->pcoff) == FULLOP_RFE) {
		cpu->nextpcpage = NULL;
		cpu->nextpcoff = 0;
	}
	else {
		/* if this fails, no special action is required */
		precompute_nextpc(cpu);
	}
}

static
void
ibranch(struct mipscpu *cpu, u_int32_t imm)
{
	// The mips book is helpfully not specific about whether the
	// address to take the upper bits of is the address of the
	// jump or the delay slot or what. it just says "the current
	// program counter", which I shall interpret as the address of
	// the delay slot. Fortunately, one isn't likely to ever be
	// executing a jump that lies across a boundary where it would
	// matter.
	//
	// (Note that cpu->pc aims at the delay slot by the time we
	// get here.)
   
	u_int32_t addr = (cpu->pc & 0xf0000000) | imm;
	abranch(cpu, addr);
}

static
void
rbranch(struct mipscpu *cpu, int32_t rel)
{
	u_int32_t addr = cpu->pc + rel;  // relative to addr of delay slot
	abranch(cpu, addr);
}

static
u_int32_t
getstatus(struct mipscpu *cpu)
{
	u_int32_t val;
	val = cpu->status_bits | cpu->status_softmask;
	if (cpu->status_hardmask) val |= STATUS_HARDMASK;
	if (cpu->old_usermode) val |= STATUS_KUo;
	if (cpu->old_irqon) val |= STATUS_IEo;
	if (cpu->prev_usermode) val |= STATUS_KUp;
	if (cpu->prev_irqon) val |= STATUS_IEp;
	if (cpu->current_usermode) val |= STATUS_KUc;
	if (cpu->current_irqon) val |= STATUS_IEc;
	return val;
}

static
void
setstatus(struct mipscpu *cpu, u_int32_t val)
{
	cpu->status_bits = val & STATUS_BITS;
	cpu->status_hardmask = val & STATUS_HARDMASK;
	cpu->status_softmask = val & STATUS_SOFTMASK;
	cpu->old_usermode = val & STATUS_KUo;
	cpu->old_irqon = val & STATUS_IEo;
	cpu->prev_usermode = val & STATUS_KUp;
	cpu->prev_irqon = val & STATUS_IEp;
	cpu->current_usermode = val & STATUS_KUc;
	cpu->current_irqon = val & STATUS_IEc;
}


static
u_int32_t
getcause(struct mipscpu *cpu)
{
	u_int32_t val;
	val = cpu->cause_ce | cpu->cause_softirq | cpu->cause_code;

	if (cpu->cause_bd) {
		val |= CAUSE_BD;
	}

	if (bus_interrupts) {
		val |= CAUSE_HARDIRQ;
	}

	return val;
}

static
void
setcause(struct mipscpu *cpu, u_int32_t val)
{
	/* c0_cause is read-only except for the soft irq bits */
	cpu->cause_softirq = val & CAUSE_SOFTIRQ;
}

static
u_int32_t
getindex(struct mipscpu *cpu)
{
	u_int32_t val = cpu->tlbindex << 8;
	if (cpu->tlbpf) {
		val |= 0x80000000;
	}
	return val;
}

static
void
setindex(struct mipscpu *cpu, u_int32_t val)
{
	cpu->tlbindex = (val >> 8) & 63;
	cpu->tlbpf = val & 0x80000000;
}

static
u_int32_t
getrandom(struct mipscpu *cpu)
{
	cpu->tlbrandom %= RANDREG_MAX;
	return (cpu->tlbrandom+RANDREG_OFFSET) << 8;
}

/*************************************************************/

// disassembly support
#ifdef USE_TRACE
static
const char *
regname(unsigned reg)
{
	switch (reg) {
	    case 0: return "$z0";
	    case 1: return "$at";
	    case 2: return "$v0";
	    case 3: return "$v1";
	    case 4: return "$a0";
	    case 5: return "$a1";
	    case 6: return "$a2";
	    case 7: return "$a3";
	    case 8: return "$t0";
	    case 9: return "$t1";
	    case 10: return "$t2";
	    case 11: return "$t3";
	    case 12: return "$t4";
	    case 13: return "$t5";
	    case 14: return "$t6";
	    case 15: return "$t7";
	    case 16: return "$s0";
	    case 17: return "$s1";
	    case 18: return "$s2";
	    case 19: return "$s3";
	    case 20: return "$s4";
	    case 21: return "$s5";
	    case 22: return "$s6";
	    case 23: return "$s7";
	    case 24: return "$t8";
	    case 25: return "$t9";
	    case 26: return "$k0";
	    case 27: return "$k1";
	    case 28: return "$gp";
	    case 29: return "$sp";
	    case 30: return "$s8";
	    case 31: return "$ra";
	}
	return "$??";
}

static int tracehow;		// how to trace the current instruction

#endif

#define LINK2(rg)  (cpu->r[rg] = cpu->nextpc)
#define LINK LINK2(31)

/* registers as lvalues */
#define RTx  (cpu->r[rt])
#define RSx  (cpu->r[rs])
#define RDx  (cpu->r[rd])

/* registers as signed 32-bit rvalues */
#define RTs  ((int32_t)RTx)
#define RSs  ((int32_t)RSx)
#define RDs  ((int32_t)RDx)

/* registers as unsigned 32-bit rvalues */
#define RTu  ((u_int32_t)RTx)
#define RSu  ((u_int32_t)RSx)
#define RDu  ((u_int32_t)RDx)

/* registers as printf-able signed values */
#define RTsp  ((long)RTs)
#define RSsp  ((long)RSs)
#define RDsp  ((long)RDs)

/* registers as printf-able unsigned values */
#define RTup  ((unsigned long)RTu)
#define RSup  ((unsigned long)RSu)
#define RDup  ((unsigned long)RDu)

#define STALL { phony_exception(cpu); }
#define WHILO {if (cpu->hiwait>0 || cpu->lowait>0) { STALL; return; }}
#define WHI   {if (cpu->hiwait>0) { STALL; return; }}
#define WLO   {if (cpu->lowait>0) { STALL; return; }}
#define SETHILO(n) (cpu->hiwait = cpu->lowait = (n))
#define SETHI(n)   (cpu->hiwait = (n))
#define SETLO(n)   (cpu->lowait = (n))

#define OVF	  { exception(cpu, EX_OVF, 0, 0); }
#define CHKOVF(v) {if (((int64_t)(int32_t)(v))!=(v)) { OVF; return; }}

#define TRL(args)  TRACEL(tracehow, args)
#define TR(args)   TRACE(tracehow, args)

#define NEEDRS	 u_int32_t rs = (insn & 0x03e00000) >> 21	// register
#define NEEDRT	 u_int32_t rt = (insn & 0x001f0000) >> 16	// register
#define NEEDRD	 u_int32_t rd = (insn & 0x0000f800) >> 11	// register
#define NEEDTARG u_int32_t targ=(insn & 0x03ffffff)           // target of jump
#define NEEDSH	 u_int32_t sh = (insn & 0x000007c0) >> 6	// shift count
#define NEEDCN	 u_int32_t cn = (insn & 0x0c000000) >> 26	// coproc. no.
#define NEEDIMM	 u_int32_t imm= (insn & 0x0000ffff)	     // immediate value
#define NEEDSMM	 NEEDIMM; int32_t smm = (int32_t)(int16_t)imm 
					       // sign-extended immediate value
#define NEEDADDR NEEDRS; NEEDSMM; u_int32_t addr = RSu + (u_int32_t)smm
                                                     // register+offset address


static
void
domf(struct mipscpu *cpu, int cn, int reg, int32_t *greg)
{
	if (cn!=0 || IS_USERMODE(cpu)) {
		exception(cpu, EX_CPU, cn, 0);
		return;
	}
	switch (reg) {
	    case C0_INDEX:   *greg = getindex(cpu); break;
	    case C0_RANDOM:  *greg = getrandom(cpu); break;
	    case C0_TLBLO:   *greg = tlbgetlo(&cpu->tlbentry); break;
	    case C0_CONTEXT: *greg = cpu->ex_context; break;
	    case C0_VADDR:   *greg = cpu->ex_vaddr; break;
	    case C0_TLBHI:   *greg = tlbgethi(&cpu->tlbentry); break;
	    case C0_STATUS:  *greg = getstatus(cpu); break;
	    case C0_CAUSE:   *greg = getcause(cpu); break;
	    case C0_EPC:     *greg = cpu->ex_epc; break;
	    case C0_PRID:    *greg = cpu->ex_prid; break;
	    default:
		exception(cpu, EX_RI, cn, 0);
		break;
	}
}

static
void
domt(struct mipscpu *cpu, int cn, int reg, int32_t greg)
{
	if (cn!=0 || IS_USERMODE(cpu)) {
		exception(cpu, EX_CPU, cn, 0);
		return;
	}
	switch (reg) {
	    case C0_INDEX:   setindex(cpu, greg); break;
	    case C0_RANDOM:  /* read-only register */ break;
	    case C0_TLBLO:   tlbsetlo(&cpu->tlbentry, greg); break;
	    case C0_CONTEXT: cpu->ex_context = greg; break;
	    case C0_VADDR:   cpu->ex_vaddr = greg; break;
	    case C0_TLBHI:   tlbsethi(&cpu->tlbentry, greg); break;
	    case C0_STATUS:  setstatus(cpu, greg); break;
	    case C0_CAUSE:   setcause(cpu, greg); break;
	    case C0_EPC:     /* read-only register */ break;
	    case C0_PRID:    /* read-only register */ break;
	    default:
		exception(cpu, EX_RI, cn, 0);
		break;
	}
}

static
void
dolwc(struct mipscpu *cpu, int cn, u_int32_t addr, int reg)
{
	(void)addr;
	(void)reg;
	exception(cpu, EX_CPU, cn, 0);
}

static
void
doswc(struct mipscpu *cpu, int cn, u_int32_t addr, int reg)
{
	(void)addr;
	(void)reg;
	exception(cpu, EX_CPU, cn, 0);
}

static
inline
void
mx_add(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	int64_t t64;

	TRL(("add %s, %s, %s: %ld + %ld -> ",
	     regname(rd), regname(rs), regname(rt), RSsp, RTsp));
	t64 = (int64_t)RSs + (int64_t)RTs;
	CHKOVF(t64);
	RDx = (int32_t)t64;
	TR(("%ld", RDsp));
}

static
inline
void
mx_addi(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDSMM;
	int64_t t64;

	TRL(("addi %s, %s, %lu: %ld + %ld -> ",
	     regname(rt), regname(rs), (unsigned long)imm, RSsp, (long)smm));
	t64 = (int64_t)RSs + smm;
	CHKOVF(t64);
	RTx = (int32_t)t64;
	TR(("%ld", RTsp));
}

static
inline
void
mx_addiu(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDRS; NEEDSMM;
	TRL(("addiu %s, %s, %lu: %ld + %ld -> ", 
	     regname(rt), regname(rs), (unsigned long)imm, RSsp, (long)smm));

	/* must add as unsigned, or overflow behavior is not defined */
	RTx = RSu + (u_int32_t)smm;

	TR(("%ld", RTsp));
}

static
inline
void
mx_addu(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	TRL(("addu %s, %s, %s: %ld + %ld -> ",
	     regname(rd), regname(rs), regname(rt), RSsp, RTsp));
	RDx = RSu + RTu;
	TR(("%ld", RDsp));
}

static
inline
void
mx_and(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	TRL(("and %s, %s, %s: 0x%lx & 0x%lx -> ", 
	     regname(rd), regname(rs), regname(rt), RSup, RTup));
	RDx = RSu & RTu;
	TR(("0x%lx", RDup));
}

static
inline
void
mx_andi(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDIMM;
	TRL(("andi %s, %s, %lu: 0x%lx & 0x%lx -> ", 
	     regname(rt), regname(rs), (unsigned long) imm, RSup, 
	     (unsigned long) imm));
	RTx = RSu & imm;
	TR(("0x%lx", RTup));
}

static
inline
void
mx_bcf(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDSMM; NEEDCN;
	(void)smm;
	TR(("bc%df %ld", cn, (long)smm));
	exception(cpu, EX_CPU, cn, 0);
}

static
inline
void
mx_bct(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDSMM; NEEDCN;
	(void)smm;
	TR(("bc%dt %ld", cn, (long)smm));
	exception(cpu, EX_CPU, cn, 0);
}

static
inline
void
mx_beq(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDRS; NEEDSMM;
	TRL(("beq %s, %s, %ld: %lu==%lu? ", 
	     regname(rs), regname(rt), (long)smm, RSup, RTup));
	if (RSu==RTu) {
		TR(("yes"));
		rbranch(cpu, smm<<2);
	}
	else {
		TR(("no"));
	}
}

static
inline
void
mx_bgezal(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDSMM;
	TRL(("bgezal %s, %ld: %ld>=0? ", regname(rs), (long)smm, RSsp));
	LINK;
	if (RSs>=0) {
		TR(("yes"));
		rbranch(cpu, smm<<2); 
	}
	else {
		TR(("no"));
	}
}

static
inline
void
mx_bgez(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDSMM;
	TRL(("bgez %s, %ld: %ld>=0? ", regname(rs), (long)smm, RSsp));
	if (RSs>=0) {
		TR(("yes"));
		rbranch(cpu, smm<<2);
	}
	else {
		TR(("no"));
	}
}

static
inline
void
mx_bltzal(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDSMM;
	TRL(("bltzal %s, %ld: %ld<0? ", regname(rs), (long)smm, RSsp));
	LINK;
	if (RSs<0) {
		TR(("yes"));
		rbranch(cpu, smm<<2);
	}
	else {
		TR(("no"));
	}
}

static
inline
void
mx_bltz(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDSMM;
	TRL(("bltz %s, %ld: %ld<0? ", regname(rs), (long)smm, RSsp));
	if (RSs<0) {
		TR(("yes"));
		rbranch(cpu, smm<<2);
	}
	else {
		TR(("no"));
	}
}

static
inline
void
mx_bgtz(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDSMM;
	TRL(("bgtz %s, %ld: %ld>0? ", regname(rs), (long)smm, RSsp));
	if (RSs>0) {
		TR(("yes"));
		rbranch(cpu, smm<<2);
	}
	else {
		TR(("no"));
	}
}

static
inline
void
mx_blez(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDSMM;
	TRL(("blez %s, %ld: %ld<=0? ", regname(rs), (long)smm, RSsp));
	if (RSs<=0) {
		TR(("yes"));
		rbranch(cpu, smm<<2);
	}
	else {
		TR(("no"));
	}
}

static
inline
void
mx_bne(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDSMM;
	TRL(("bne %s, %s, %ld: %lu!=%lu? ", 
	     regname(rs), regname(rt), (long)smm, RSup, RTup));
	if (RSu!=RTu) {
		TR(("yes"));
		rbranch(cpu, smm<<2);
	}
	else {
		TR(("no"));
	}
}

static
inline
void
mx_cf(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDRD; NEEDCN;
	(void)rt;
	(void)rd;
	TR(("cfc%d %s, $%u", cn, regname(rt), rd));
	exception(cpu, EX_CPU, cn, 0);
}

static
inline
void
mx_ct(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDRD; NEEDCN;
	(void)rt;
	(void)rd;
	TR(("ctc%d %s, $%u", cn, regname(rt), rd));
	exception(cpu, EX_CPU, cn, 0);
}

static
inline
void
mx_j(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDTARG;
	TR(("j 0x%lx", (unsigned long)(targ<<2)));
	ibranch(cpu, targ<<2);
}

static
inline
void
mx_jal(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDTARG;
	TR(("jal 0x%lx", (unsigned long)(targ<<2)));
	LINK;
	ibranch(cpu, targ<<2);
#ifdef USE_TRACE
	prof_call(cpu->pc, cpu->nextpc);
#endif
}

static
inline
void
mx_lb(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TRL(("lb %s, %ld(%s): [0x%lx] -> ", 
	     regname(rt), (long)smm, regname(rs), (unsigned long)addr));
	doload(cpu, S_SBYTE, addr, (u_int32_t *) &RTx);
	TR(("%ld", RTsp));
}

static
inline
void
mx_lbu(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TRL(("lbu %s, %ld(%s): [0x%lx] -> ",
	     regname(rt), (long)smm, regname(rs), (unsigned long)addr));
	doload(cpu, S_UBYTE, addr, (u_int32_t *) &RTx);
	TR(("%ld", RTsp));
}

static
inline
void
mx_lh(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TRL(("lh %s, %ld(%s): [0x%lx] -> ", 
	     regname(rt), (long)smm, regname(rs), (unsigned long)addr));
	doload(cpu, S_SHALF, addr, (u_int32_t *) &RTx);
	TR(("%ld", RTsp));
}

static
inline
void
mx_lhu(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TRL(("lhu %s, %ld(%s): [0x%lx] -> ", 
	     regname(rt), (long)smm, regname(rs), (unsigned long)addr));
	doload(cpu, S_UHALF, addr, (u_int32_t *) &RTx);
	TR(("%ld", RTsp));
}

static
inline
void
mx_lui(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDIMM;
	TR(("lui %s, 0x%x", regname(rt), imm));
	RTx = imm << 16;
}

static
inline
void
mx_lw(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TRL(("lw %s, %ld(%s): [0x%lx] -> ", 
	     regname(rt), (long)smm, regname(rs), (unsigned long)addr));
	domem(cpu, addr, (u_int32_t *) &RTx, 0, 0);
	TR(("%ld", RTsp));
}

static
inline
void
mx_lwc(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR; NEEDCN;
	TR(("lwc%d $%u, %ld(%s)", cn, rt, (long)smm, regname(rs)));
	dolwc(cpu, cn, addr, rt);
}

static
inline
void
mx_lwl(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TRL(("lwl %s, %ld(%s): [0x%lx] -> ", 
	     regname(rt), (long)smm, regname(rs), (unsigned long)addr));
	doload(cpu, S_WORDL, addr, (u_int32_t *) &RTx);
	TR(("0x%lx", RTup));
}

static
inline
void
mx_lwr(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TRL(("lwr %s, %ld(%s): [0x%lx] -> ", 
	     regname(rt), (long)smm, regname(rs), (unsigned long)addr));
	doload(cpu, S_WORDR, addr, (u_int32_t *) &RTx);
	TR(("0x%lx", RTup));
}

static
inline
void
mx_sb(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TR(("sb %s, %ld(%s): %d -> [0x%lx]", 
	    regname(rt), (long)smm, regname(rs),
	    (int)(RTu&0xff), (unsigned long)addr));
	dostore(cpu, S_UBYTE, addr, RTu);
}

static
inline
void
mx_sh(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TR(("sh %s, %ld(%s): %d -> [0x%lx]", 
	    regname(rt), (long)smm, regname(rs),
	    (int)(RTu&0xffff), (unsigned long)addr));
	dostore(cpu, S_UHALF, addr, RTu);
}

static
inline
void
mx_sw(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TR(("sw %s, %ld(%s): %ld -> [0x%lx]", 
	    regname(rt), (long)smm, regname(rs), RTsp, (unsigned long)addr));
	domem(cpu, addr, (u_int32_t *) &RTx, 1, 1);
}

static
inline
void
mx_swc(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR; NEEDCN;
	TR(("swc%d $%u, %ld(%s)", cn, rt, (long)smm, regname(rs)));
	doswc(cpu, cn, addr, rt);
}

static
inline
void
mx_swl(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TR(("swl %s, %ld(%s): 0x%lx -> [0x%lx]", 
	    regname(rt), (long)smm, regname(rs), RTup, (unsigned long)addr));
	dostore(cpu, S_WORDL, addr, RTu);
}

static
inline
void
mx_swr(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDADDR;
	TR(("swr %s, %ld(%s): 0x%lx -> [0x%lx]", 
	    regname(rt), (long)smm, regname(rs), RTup, (unsigned long)addr));
	dostore(cpu, S_WORDR, addr, RTu);
}

static
inline
void
mx_break(struct mipscpu *cpu, u_int32_t insn)
{
	(void)insn;
	TR(("break"));
	exception(cpu, EX_BP, 0, 0);
}

static
inline
void
mx_div(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT;
	TRL(("div %s %s: %ld / %ld -> ", 
	     regname(rs), regname(rt), RSsp, RTsp));

	WHILO;
	if (RTs==0) {
		/*
		 * On divide-by-zero the mips doesn't trap.
		 * Instead, the assembler emits an integer check for
		 * zero that (on the real chip) runs in parallel with
		 * the divide unit.
		 *
		 * I don't know what the right values to load in the
		 * result are, if there are any that are specified,
		 * but I'm going to make up what seems like a good
		 * excuse for machine infinity.
		 */
		if (RSs < 0) {
			cpu->lo = 0xffffffff;
		}
		else {
			cpu->lo = 0x7fffffff;
		}
		cpu->hi = 0;
		TR(("ERR"));
	}
	else {
		cpu->lo = RSs/RTs;
		cpu->hi = RSs%RTs;
		TR(("%ld, remainder %ld", 
		    (long)(int32_t)cpu->lo, (long)(int32_t)cpu->hi));
	}
	SETHILO(2);
}

static
inline
void
mx_divu(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT;
	TRL(("divu %s %s: %lu / %lu -> ", 
	     regname(rs), regname(rt), RSup, RTup));

	WHILO;
	if (RTu==0) {
		/*
		 * See notes under signed divide above.
		 */
		cpu->lo = 0xffffffff;
		cpu->hi = 0;
		TR(("ERR"));
	}
	else {
		cpu->lo=RSu/RTu;
		cpu->hi=RSu%RTu;
		TR(("%lu, remainder %lu", 
		    (unsigned long)(u_int32_t)cpu->lo, 
		    (unsigned long)(u_int32_t)cpu->hi));
	}
	SETHILO(2);
}

static
inline
void
mx_jr(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS;
	TR(("jr %s: 0x%lx", regname(rs), RSup));
	abranch(cpu, RSu);
}

static
inline
void
mx_jalr(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRD;
	TR(("jalr %s, %s: 0x%lx", regname(rd), regname(rs), RSup));
	LINK2(rd);
	abranch(cpu, RSu);
#ifdef USE_TRACE
	prof_call(cpu->pc, cpu->nextpc);
#endif
}

static
inline
void
mx_mf(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDRD; NEEDCN;
	TRL(("mfc%d %s, $%u: ... -> ", cn, regname(rt), rd));
	domf(cpu, cn, rd, &RTx);
	TR(("0x%lx", RTup));
}

static
inline
void
mx_mfhi(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRD;
	TRL(("mfhi %s: ... -> ", regname(rd)));
	WHI;
	RDx = cpu->hi;
	SETHI(2);
	TR(("0x%lx", RDup));
}

static
inline
void
mx_mflo(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRD;
	TRL(("mflo %s: ... -> ", regname(rd)));
	WLO;
	RDx = cpu->lo;
	SETLO(2);
	TR(("0x%lx", RDup));
}

static
inline
void
mx_mt(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRT; NEEDRD; NEEDCN;
	TR(("mtc%d %s, $%u: 0x%lx -> ...", cn, regname(rt), rd, RTup));
	domt(cpu, cn, rd, RTs);
}

static
inline
void
mx_mthi(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS;
	TR(("mthi %s: 0x%lx -> ...", regname(rs), RSup));
	WHI;
	cpu->hi = RSu;
	SETHI(2);
}

static
inline
void
mx_mtlo(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS;
	TR(("mtlo %s: 0x%lx -> ...", regname(rs), RSup));
	WLO;
	cpu->lo = RSu;
	SETLO(2);
}

static
inline
void
mx_mult(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT;
	int64_t t64;
	TRL(("mult %s, %s: %ld * %ld -> ", 
	     regname(rs), regname(rt), RSsp, RTsp));
	WHILO;
	t64=(int64_t)RSs*(int64_t)RTs;
	cpu->hi = (((u_int64_t)t64)&0xffffffff00000000ULL) >> 32;
	cpu->lo = (u_int32_t)(((u_int64_t)t64)&0x00000000ffffffffULL);
	SETHILO(2);
	TR(("%ld %ld", (long)(int32_t)cpu->hi, (long)(int32_t)cpu->lo));
}

static
inline
void
mx_multu(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT;
	u_int64_t t64;
	TRL(("multu %s, %s: %lu * %lu -> ", 
	     regname(rs), regname(rt), RSup, RTup));
	WHILO;
	t64=(u_int64_t)RSu*(u_int64_t)RTu;
	cpu->hi = (t64&0xffffffff00000000ULL) >> 32;
	cpu->lo = (u_int32_t)(t64&0x00000000ffffffffULL);
	SETHILO(2);
	TR(("%lu %lu",
	    (unsigned long)(u_int32_t)cpu->hi,
	    (unsigned long)(u_int32_t)cpu->lo));
}

static
inline
void
mx_nor(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	TRL(("nor %s, %s, %s: ~(0x%lx | 0x%lx) -> ",
	     regname(rd), regname(rs), regname(rt), RSup, RTup));
	RDx = ~(RSu | RTu);
	TR(("0x%lx", RDup));
}

static
inline
void
mx_or(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	TRL(("or %s, %s, %s: 0x%lx | 0x%lx -> ", 
	     regname(rd), regname(rs), regname(rt), RSup, RTup));
	RDx = RSu | RTu;
	TR(("0x%lx", RDup));
}

static
inline
void
mx_ori(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDIMM;
	TRL(("ori %s, %s, %lu: 0x%lx | 0x%lx -> ", 
	     regname(rt), regname(rs), (unsigned long)imm,
	     RSup, (unsigned long)imm));
	RTx = RSu | imm;
	TR(("0x%lx", RTup));
}

static
inline
void
mx_rfe(struct mipscpu *cpu, u_int32_t insn)
{
	(void)insn;
	TR(("rfe"));
	do_rfe(cpu);
}

static
inline
void
mx_sll(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRD; NEEDRT; NEEDSH;
	TRL(("sll %s, %s, %u: 0x%lx << %u -> ", 
	     regname(rd), regname(rt), (unsigned)sh, RTup, (unsigned)sh));
	RDx = RTu << sh;
	TR(("0x%lx", RDup));
}

static
inline
void
mx_sllv(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRD; NEEDRT; NEEDRS;
	unsigned vsh = (RSu&31);
	TRL(("sllv %s, %s, %s: 0x%lx << %u -> ", 
	     regname(rd), regname(rt), regname(rs), RTup, vsh));
	RDx = RTu << vsh;
	TR(("0x%lx", RDup));
}

static
inline
void
mx_slt(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	TRL(("slt %s, %s, %s: %ld < %ld -> ", 
	     regname(rd), regname(rs), regname(rt), RSsp, RTsp));
	RDx = RSs < RTs;
	TR(("%ld", RDsp));
}

static
inline
void
mx_slti(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDSMM;
	TRL(("slti %s, %s, %ld: %ld < %ld -> ", 
	     regname(rt), regname(rs), (long)smm, RSsp, (long)smm));
	RTx = RSs < smm;
	TR(("%ld", RTsp));
}

static
inline
void
mx_sltiu(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDSMM;
	TRL(("sltiu %s, %s, %lu: %lu < %lu -> ", 
	     regname(rt), regname(rs), (unsigned long)imm, RSup, 
	     (unsigned long)(u_int32_t)smm));
	// Yes, the immediate is sign-extended then treated as
	// unsigned, according to my mips book. Blech.
	RTx = RSu < (u_int32_t) smm;
	TR(("%ld", RTsp));
}

static
inline
void
mx_sltu(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	TRL(("sltu %s, %s, %s: %lu < %lu -> ", 
	     regname(rd), regname(rs), regname(rt), RSup, RTup));
	RDx = RSu < RTu;
	TR(("%ld", RDsp));
}

static
inline
u_int32_t
signedshift(u_int32_t val, unsigned amt)
{
	/* There's no way to express a signed shift directly in C. */
	u_int32_t result;
	result = val >> amt;
	if (val & 0x80000000) {
		result |= (0xffffffff << (31-amt));
	}
	return result;
}

static
inline
void
mx_sra(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRD; NEEDRT; NEEDSH;
	TRL(("sra %s, %s, %u: 0x%lx >> %u -> ", 
	     regname(rd), regname(rt), (unsigned)sh, RTup, (unsigned)sh));
	RDx = signedshift(RTu, sh);
	TR(("0x%lx", RDup));
}

static
inline
void
mx_srav(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	unsigned vsh = (RSu&31);
	TRL(("srav %s, %s, %s: 0x%lx >> %u -> ", 
	     regname(rd), regname(rt), regname(rs), RTup, vsh));
	RDx = signedshift(RTu, vsh);
	TR(("0x%lx", RDup));
}

static
inline
void
mx_srl(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRD; NEEDRT; NEEDSH;
	TRL(("srl %s, %s, %u: 0x%lx >> %u -> ", 
	     regname(rd), regname(rt), (unsigned)sh, RTup, (unsigned)sh));
	RDx = RTu >> sh;
	TR(("0x%lx", RDup));
}

static
inline
void
mx_srlv(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	unsigned vsh = (RSu&31);
	TRL(("srlv %s, %s, %s: 0x%lx >> %u -> ", 
	     regname(rd), regname(rt), regname(rs), RTup, vsh));
	RDx = RTu >> vsh;
	TR(("0x%lx", RDup));
}

static
inline
void
mx_sub(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	int64_t t64;
	TRL(("sub %s, %s, %s: %ld - %ld -> ", 
	     regname(rd), regname(rs), regname(rt), RSsp, RTsp));
	t64 = (int64_t)RSs - (int64_t)RTs;
	CHKOVF(t64);
	RDx = (int32_t)t64;
	TR(("%ld", RDsp));
}

static
inline
void
mx_subu(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	TRL(("subu %s, %s, %s: %ld - %ld -> ", 
	     regname(rd), regname(rs), regname(rt), RSsp, RTsp));
	RDx = RSu - RTu;
	TR(("%ld", RDsp));
}

static
inline
void
mx_syscall(struct mipscpu *cpu, u_int32_t insn)
{
	(void)insn;
	TR(("syscall"));
	exception(cpu, EX_SYS, 0, 0);
}

static
inline
void
mx_tlbp(struct mipscpu *cpu, u_int32_t insn)
{
	(void)insn;
	TR(("tlbp"));
	probetlb(cpu);
}

static
inline
void
mx_tlbr(struct mipscpu *cpu, u_int32_t insn)
{
	(void)insn;
	TR(("tlbr"));
	cpu->tlbentry = cpu->tlb[cpu->tlbindex];
	TRACEL(DOTRACE_TLB, ("tlbr:  [%2d] ", cpu->tlbindex));
	TLBTR(&cpu->tlbentry);
	TRACE(DOTRACE_TLB, (" "));
}

static
inline
void
mx_tlbwi(struct mipscpu *cpu, u_int32_t insn)
{
	(void)insn;
	TR(("tlbwi"));
	writetlb(cpu, cpu->tlbindex, "tlbwi");
}

static
inline
void
mx_tlbwr(struct mipscpu *cpu, u_int32_t insn)
{
	(void)insn;
	TR(("tlbwr"));
	cpu->tlbrandom %= RANDREG_MAX;
	writetlb(cpu, cpu->tlbrandom+RANDREG_OFFSET, "tlbwr");
}

static
inline
void
mx_wait(struct mipscpu *cpu, u_int32_t insn)
{
	(void)insn;
	TR(("wait"));
	do_wait(cpu);
}

static
inline
void
mx_xor(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDRD;
	TRL(("xor %s, %s, %s: 0x%lx ^ 0x%lx -> ",
	     regname(rd), regname(rs), regname(rt), RSup, RTup));
	RDx = RSu ^ RTu;
	TR(("0x%lx", RDup));
}

static
inline
void
mx_xori(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDRS; NEEDRT; NEEDIMM;
	TRL(("xori %s, %s, %lu: 0x%lx ^ 0x%lx -> ",
	     regname(rt), regname(rs), (unsigned long)imm, 
	     RSup, (unsigned long)imm));
	RTx = RSu ^ imm;
	TR(("0x%lx", RTup));
}

static
inline
void
mx_ill(struct mipscpu *cpu, u_int32_t insn)
{
	(void)insn;
	TR(("[illegal instruction %08lx]", (unsigned long) insn));
	exception(cpu, EX_RI, 0, 0);
}

/*
 * Note: OP_WAIT is not defined for mips r2000/r3000 - it's from later
 * MIPS versions. However, we support it here anyway because spinning
 * in an idle loop is just plain stupid.
 */
static
inline
void
mx_copz(struct mipscpu *cpu, u_int32_t insn)
{
	NEEDCN;
	u_int32_t copop;

	if (cn!=0) {
		exception(cpu, EX_CPU, cn, 0);
		return;
	}
	if (IS_USERMODE(cpu)) {
		exception(cpu, EX_CPU, cn, 0);
		return;
	}

	copop = (insn & 0x03e00000) >> 21;	// coprocessor opcode

	if (copop & 0x10) {
		copop = (insn & 0x01ffffff);	// real coprocessor opcode
		switch (copop) {
		    case 1: mx_tlbr(cpu, insn); break;
		    case 2: mx_tlbwi(cpu, insn); break;
		    case 6: mx_tlbwr(cpu, insn); break;
		    case 8: mx_tlbp(cpu, insn); break;
		    case 16: mx_rfe(cpu, insn); break;
		    case 32: mx_wait(cpu, insn); break;
		    default: mx_ill(cpu, insn); break;
		}
	}
	else switch (copop) {
	    case 0: mx_mf(cpu, insn); break;
	    case 2: mx_cf(cpu, insn); break;
	    case 4: mx_mt(cpu, insn); break;
	    case 6: mx_ct(cpu, insn); break;
	    case 8:
	    case 12:
		if (insn & 0x00010000) {
			mx_bcf(cpu, insn);
		}
		else {
			mx_bct(cpu, insn);
		}
		break;
	    default: mx_ill(cpu, insn);
	}
}

int
cpu_cycle(void)
{
	struct mipscpu *cpu = &mycpu;
	u_int32_t insn;
	u_int32_t op;

	/*
	 * First, update exception PC.
	 *
	 * Once we've done this, we can take exceptions this cycle and
	 * have them report the correct PC.
	 *
	 * If we're executing the delay slot of a jump, expc remains pointing
	 * to the jump and we clear the flag that tells us to do this.
	 */
	if (cpu->jumping) {
		cpu->jumping = 0;
		cpu->in_jumpdelay = 1;
	}
	else {
		cpu->expc = cpu->pc;
	}

	/*
	 * Check for interrupts.
	 */
	if (cpu->current_irqon) {
		u_int32_t soft = cpu->status_softmask & cpu->cause_softirq;
		if ((cpu->status_hardmask && bus_interrupts) || soft) {
			TRACE(DOTRACE_IRQ, ("Taking interrupt"));
			exception(cpu, EX_IRQ, 0, 0);
			/*
			 * Start processing the interrupt this cycle.
			 *
			 * That is, repeat the code above us in this
			 * function.
			 *
			 * At this point we're executing the first 
			 * instruction of the exception handler, which
			 * cannot be a jump delay slot.
			 *
			 * Thus, just set expc.
			 */
			cpu->expc = cpu->pc;
		}
	}

	if (IS_USERMODE(cpu)) {
		g_stats.s_ucycles++;
#ifdef USE_TRACE
		tracehow = DOTRACE_UINSN;
#endif
	}
	else {
		g_stats.s_kcycles++;
#ifdef USE_TRACE
		tracehow = DOTRACE_KINSN;
#endif
	}
	
	/*
	 * Fetch instruction.
	 *
	 * We cache the page translation for the PC.
	 * Use the page part of the precomputed physpc and also the
	 * precomputed page pointer.
	 *
	 * Note that as a result of precomputing everything, exceptions
	 * related to PC mishaps occur at jump time, or possibly when
	 * *nextpc* crosses a page boundary (below) or whatnot, never 
	 * during instruction fetch itself. I believe this is acceptable
	 * behavior to exhibit.
	 */
	insn = bus_use_map(cpu->pcpage, cpu->pcoff);

	// Update PC. 
	cpu->pc = cpu->nextpc;
	cpu->pcoff = cpu->nextpcoff;
	cpu->pcpage = cpu->nextpcpage;
	cpu->nextpc += 4;
	if ((cpu->nextpc & 0xfff)==0) {
		/* crossed page boundary */
		if (insn == FULLOP_RFE) {
			/* defer precompute_nextpc() */
			cpu->nextpcpage = NULL;
			cpu->nextpcoff = 0;
		}
		else if (precompute_nextpc(cpu)) {
			/* exception */
			return 1;
		}
	}
	else {
		cpu->nextpcoff += 4;
	}

	TRL(("at %08x: ", cpu->expc));
	
	/*
	 * Decode instruction.
	 */
	
	op = (insn & 0xfc000000) >> 26;   // opcode

	switch (op) {
	    case OPM_SPECIAL:
		// use function field
		switch (insn & 0x3f) {
		    case OPS_SLL: mx_sll(cpu, insn); break;
		    case OPS_SRL: mx_srl(cpu, insn); break;
		    case OPS_SRA: mx_sra(cpu, insn); break;
		    case OPS_SLLV: mx_sllv(cpu, insn); break;
		    case OPS_SRLV: mx_srlv(cpu, insn); break;
		    case OPS_SRAV: mx_srav(cpu, insn); break;
		    case OPS_JR: mx_jr(cpu, insn); break;
		    case OPS_JALR: mx_jalr(cpu, insn); break;
		    case OPS_SYSCALL: mx_syscall(cpu, insn); break;
		    case OPS_BREAK: 
			/*
			 * If we're in the range that we can debug in (that
			 * is, not the TLB-mapped segments), activate the
			 * kernel debugging hooks.
			 */
			if (gdb_canhandle(cpu->expc)) {
				phony_exception(cpu);
				main_stop();
				/*
				 * Don't bill time for hitting the breakpoint.
				 */
				return 0;
			}
			mx_break(cpu, insn);
			break;
		    case OPS_MFHI: mx_mfhi(cpu, insn); break;
		    case OPS_MTHI: mx_mthi(cpu, insn); break;
		    case OPS_MFLO: mx_mflo(cpu, insn); break;
		    case OPS_MTLO: mx_mtlo(cpu, insn); break;
		    case OPS_MULT: mx_mult(cpu, insn); break;
		    case OPS_MULTU: mx_multu(cpu, insn); break;
		    case OPS_DIV: mx_div(cpu, insn); break;
		    case OPS_DIVU: mx_divu(cpu, insn); break;
		    case OPS_ADD: mx_add(cpu, insn); break;
		    case OPS_ADDU: mx_addu(cpu, insn); break;
		    case OPS_SUB: mx_sub(cpu, insn); break;
		    case OPS_SUBU: mx_subu(cpu, insn); break;
		    case OPS_AND: mx_and(cpu, insn); break;
		    case OPS_OR: mx_or(cpu, insn); break;
		    case OPS_XOR: mx_xor(cpu, insn); break;
		    case OPS_NOR: mx_nor(cpu, insn); break;
		    case OPS_SLT: mx_slt(cpu, insn); break;
		    case OPS_SLTU: mx_sltu(cpu, insn); break;
		    default: mx_ill(cpu, insn); break;
		}
		break;
	    case OPM_BCOND:
		// use rt field
		switch ((insn & 0x001f0000) >> 16) {
		    case 0: mx_bltz(cpu, insn); break;
		    case 1: mx_bgez(cpu, insn); break;
		    case 16: mx_bltzal(cpu, insn); break;
		    case 17: mx_bgezal(cpu, insn); break;
		    default: mx_ill(cpu, insn); break;
		}
		break;
	    case OPM_J: mx_j(cpu, insn); break;
	    case OPM_JAL: mx_jal(cpu, insn); break;
	    case OPM_BEQ: mx_beq(cpu, insn); break;
	    case OPM_BNE: mx_bne(cpu, insn); break;
	    case OPM_BLEZ: mx_blez(cpu, insn); break;
	    case OPM_BGTZ: mx_bgtz(cpu, insn); break;
	    case OPM_ADDI: mx_addi(cpu, insn); break;
	    case OPM_ADDIU: mx_addiu(cpu, insn); break;
	    case OPM_SLTI: mx_slti(cpu, insn); break;
	    case OPM_SLTIU: mx_sltiu(cpu, insn); break;
	    case OPM_ANDI: mx_andi(cpu, insn); break;
	    case OPM_ORI: mx_ori(cpu, insn); break;
	    case OPM_XORI: mx_xori(cpu, insn); break;
	    case OPM_LUI: mx_lui(cpu, insn); break;
	    case OPM_COP0:
	    case OPM_COP1:
	    case OPM_COP2:
	    case OPM_COP3: mx_copz(cpu, insn); break;
	    case OPM_LB: mx_lb(cpu, insn); break;
	    case OPM_LH: mx_lh(cpu, insn); break;
	    case OPM_LWL: mx_lwl(cpu, insn); break;
	    case OPM_LW: mx_lw(cpu, insn); break;
	    case OPM_LBU: mx_lbu(cpu, insn); break;
	    case OPM_LHU: mx_lhu(cpu, insn); break;
	    case OPM_LWR: mx_lwr(cpu, insn); break;
	    case OPM_SB: mx_sb(cpu, insn); break;
	    case OPM_SH: mx_sh(cpu, insn); break;
	    case OPM_SWL: mx_swl(cpu, insn); break;
	    case OPM_SW: mx_sw(cpu, insn); break;
	    case OPM_SWR: mx_swr(cpu, insn); break;
	    case OPM_LWC0:
	    case OPM_LWC1:
	    case OPM_LWC2:
	    case OPM_LWC3: mx_lwc(cpu, insn); break;
	    case OPM_SWC0:
	    case OPM_SWC1:
	    case OPM_SWC2:
	    case OPM_SWC3: mx_swc(cpu, insn); break;
	    default: mx_ill(cpu, insn); break;
	}

	if (cpu->lowait > 0) {
		cpu->lowait--;
	}
	if (cpu->hiwait > 0) {
		cpu->hiwait--;
	}

	cpu->in_jumpdelay = 0;
	
	cpu->tlbrandom++;

	return 1;
}

/*************************************************************/

void
cpu_init(void)
{
	mips_init(&mycpu);
}

void
cpu_dumpstate(void)
{
	int i;

	msg("1 cpu: MIPS r2000");
	for (i=0; i<NREGS; i++) {
		msgl("r%d:%s 0x%08lx  ", i, i<10 ? " " : "",
		     (unsigned long) mycpu.r[i]);
		if (i%4==3) {
			msg(" ");
		}
	}
	msg("lo:  0x%08lx  hi:  0x%08lx  pc:  0x%08lx  npc: 0x%08lx", 
	    (unsigned long) mycpu.lo,
	    (unsigned long) mycpu.hi,
	    (unsigned long) mycpu.pc,
	    (unsigned long) mycpu.nextpc);

	for (i=0; i<NTLB; i++) {
		tlbmsg("TLB", i, &mycpu.tlb[i]);
	}
	tlbmsg("TLB", -1, &mycpu.tlbentry);
	msg("tlb index: %d %s", mycpu.tlbindex, 
	    mycpu.tlbpf ? "[last probe failed]" : "");
	msg("tlb random: %d", (mycpu.tlbrandom%RANDREG_MAX)+RANDREG_OFFSET);

	msgl("Status register: ");
	msgl("%s%s%s%s-----",
	     mycpu.status_bits & 0x80000000 ? "3" : "-",
	     mycpu.status_bits & 0x40000000 ? "2" : "-",
	     mycpu.status_bits & 0x20000000 ? "1" : "-",
	     mycpu.status_bits & 0x10000000 ? "0" : "-");
	msgl("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
	     mycpu.status_bits & 0x00400000 ? "B" : "-",
	     mycpu.status_bits & 0x00200000 ? "T" : "-",
	     mycpu.status_bits & 0x00100000 ? "E" : "-",
	     mycpu.status_bits & 0x00080000 ? "M" : "-",
	     mycpu.status_bits & 0x00040000 ? "Z" : "-",
	     mycpu.status_bits & 0x00020000 ? "S" : "-",
	     mycpu.status_bits & 0x00010000 ? "I" : "-",
	     mycpu.status_bits & 0x00008000 ? "h" : "-",
	     mycpu.status_bits & 0x00004000 ? "h" : "-",
	     mycpu.status_bits & 0x00002000 ? "h" : "-",
	     mycpu.status_bits & 0x00001000 ? "h" : "-",
	     mycpu.status_bits & 0x00000800 ? "h" : "-",
	     mycpu.status_hardmask ? "H" : "-",
	     mycpu.status_softmask & 0x0200 ? "S" : "-",
	     mycpu.status_softmask & 0x0100 ? "S" : "-");
	msg("--%s%s%s%s%s%s",
	    mycpu.old_usermode ? "U" : "-",
	    mycpu.old_irqon ? "I" : "-",
	    mycpu.prev_usermode ? "U" : "-",
	    mycpu.prev_irqon ? "I" : "-",
	    mycpu.current_usermode ? "U" : "-",
	    mycpu.current_irqon ? "I" : "-");

	msg("Cause register: %s %d -----%s%s%s %d [%s]",
	    mycpu.cause_bd ? "B" : "-",
	    mycpu.cause_ce >> 28,
	    bus_interrupts ? "H" : "-",
	    (mycpu.cause_softirq & 0x200) ? "S" : "-",
	    (mycpu.cause_softirq & 0x100) ? "S" : "-",
	    mycpu.cause_code >> 2,
	    exception_name(mycpu.cause_code>>2));

	msg("VAddr register: 0x%08lx", (unsigned long)mycpu.ex_vaddr);
	msg("Context register: 0x%08lx", (unsigned long)mycpu.ex_context);
	msg("EPC register: 0x%08lx", (unsigned long)mycpu.ex_epc);
}

#define BETWEEN(addr, size, base, top) \
          ((addr) >= (base) && (size) <= (top)-(base) && (addr)+(size) < (top))

int
cpu_get_load_paddr(u_int32_t vaddr, u_int32_t size, u_int32_t *paddr)
{
	if (!BETWEEN(vaddr, size, KSEG0, KSEG2)) {
		return -1;
	}

	if (vaddr >= KSEG1) {
		*paddr = vaddr - KSEG1;
	}
	else {
		*paddr = vaddr - KSEG0;
	}
	return 0;
}

int
cpu_get_load_vaddr(u_int32_t paddr, u_int32_t size, u_int32_t *vaddr)
{
	u_int32_t zero = 0;  /* suppresses silly gcc warning */
	if (!BETWEEN(paddr, size, zero, KSEG1-KSEG0)) {
		return -1;
	}
	*vaddr = paddr + KSEG0;
	return 0;
}

void
cpu_set_entrypoint(u_int32_t addr)
{
	if ((addr & 0x3) != 0) {
		hang("Kernel entry point is not properly aligned");
		addr &= 0xfffffffc;
	}
	mycpu.expc = addr;
	mycpu.pc = addr;
	mycpu.nextpc = addr+4;
	if (precompute_pc(&mycpu)) {
		hang("Kernel entry point is an invalid address");
	}
	if (precompute_nextpc(&mycpu)) {
		hang("Kernel entry point is an invalid address");
	}
}

void
cpu_set_stack(u_int32_t stackaddr, u_int32_t argument)
{
	mycpu.r[29] = stackaddr;   /* register 29: stack pointer */
	mycpu.r[4] = argument;     /* register 4: first argument */
	
	/* don't need to set $gp - in the ELF model it's start's problem */
}

void
cpudebug_get_bp_region(u_int32_t *start, u_int32_t *end)
{
	*start = KSEG0;
	*end = KSEG2;
}

int
cpudebug_fetch_byte(u_int32_t va, u_int8_t *byte)
{
	u_int32_t pa;
	u_int32_t aligned_va;

	aligned_va = va & 0xfffffffc;

	/*
	 * For now, only allow KSEG0/1
	 */

	if (debug_translatemem(&mycpu, aligned_va, 0, &pa)) {
		return -1;
	}

	pa |= (va & 3);

	if (bus_mem_fetchbyte(pa, byte)) {
		return -1;
	}
	return 0;
}

int
cpudebug_fetch_word(u_int32_t va, u_int32_t *word)
{
	u_int32_t pa;

	/*
	 * For now, only allow KSEG0/1
	 */
	

	if (debug_translatemem(&mycpu, va, 0, &pa)) {
		return -1;
	}

	if (bus_mem_fetch(pa, word)) {
		return -1;
	}
	return 0;
}

int
cpudebug_store_byte(u_int32_t va, u_int8_t byte)
{
	u_int32_t pa;

	/*
	 * For now, only allow KSEG0/1
	 */
	
	if (debug_translatemem(&mycpu, va, 1, &pa)) {
		return -1;
	}

	if (bus_mem_storebyte(pa, byte)) {
		return -1;
	}
	return 0;
}

int
cpudebug_store_word(u_int32_t va, u_int32_t word)
{
	u_int32_t pa;

	/*
	 * For now, only allow KSEG0/1
	 */
	
	if (debug_translatemem(&mycpu, va, 1, &pa)) {
		return -1;
	}

	if (bus_mem_store(pa, word)) {
		return -1;
	}
	return 0;
}


static
inline
void
addreg(u_int32_t *regs, int maxregs, int pos, u_int32_t val)
{
	if (pos < maxregs) {
		regs[pos] = val;
	}
}

#define GETREG(r) addreg(regs, maxregs, j++, r)

void
cpudebug_getregs(u_int32_t *regs, int maxregs, int *nregs)
{
	int i, j=0;
	for (i=0; i<NREGS; i++) {
		GETREG(mycpu.r[i]);
	}
	GETREG(getstatus(&mycpu));
	GETREG(mycpu.lo);
	GETREG(mycpu.hi);
	GETREG(mycpu.ex_vaddr);
	GETREG(getcause(&mycpu));
	GETREG(mycpu.pc);
	GETREG(0); /* fp status? */
	GETREG(0); /* fp something-else? */
	GETREG(0); /* fp ? */
	GETREG(getindex(&mycpu));
	GETREG(getrandom(&mycpu));
	GETREG(tlbgetlo(&mycpu.tlbentry));
	GETREG(mycpu.ex_context);
	GETREG(tlbgethi(&mycpu.tlbentry));
	GETREG(mycpu.ex_epc);
	GETREG(mycpu.ex_prid);
	*nregs = j;
}

u_int32_t
cpuprof_sample(void)
{
	return mycpu.pc;
}
