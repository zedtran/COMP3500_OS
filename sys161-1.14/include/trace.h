
#include "console.h"   // make sure we have PF()

#ifndef TRACE_H
#define TRACE_H

#ifdef USE_TRACE

#define DOTRACE_KINSN	0	/* trace instructions in kernel mode */
#define DOTRACE_UINSN	1	/* trace instructions in user mode */
#define DOTRACE_JUMP	2	/* trace jump instructions */
#define DOTRACE_TLB     3	/* trace tlb operations */
#define DOTRACE_EXN     4	/* trace exceptions */
#define DOTRACE_IRQ     5	/* trace exceptions */
#define DOTRACE_DISK	6	/* trace disk ops */
#define DOTRACE_NET	7	/* trace net ops */
#define DOTRACE_EMUFS	8	/* trace emufs ops */
#define NDOTRACES	9

extern int g_traceflags[NDOTRACES];

int adjust_traceflag(int flag, int onoff); /* returns -1 on error */
void set_traceflags(const char *letters);
void print_traceflags(void);


/* These three functions are actually in console.c */

void set_tracefile(const char *filename);    /* set output destination */
void trace(const char *fmt, ...) PF(1,2);    /* trace output */
void tracel(const char *fmt, ...) PF(1,2);   /* trace w/o newline */


#define TRACEL(k, args)   (g_traceflags[(k)] ? tracel args : (void)0)
#define TRACE(k, args)    (g_traceflags[(k)] ? trace args : (void)0)



#else /* not USE_TRACE */


#define TRACEL(k, args)
#define TRACE(k, args)


#endif /* USE_TRACE */

#endif /* TRACE_H */
