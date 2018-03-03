#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"

#include "util.h"
#include "bus.h"
#include "cpu.h"
#include "speed.h"
#include "console.h"
#include "gdb.h"
#include "onsel.h"
#include "clock.h"
#include "main.h"
#include "memdefs.h"

#include "lamebus.h"
#include "busids.h"
#include "busdefs.h"

/*
 * Maximum amount of physical memory we allow.
 * For now, 16M.
 */

const char rcsid_lamebus_c[] =
    "$Id: lamebus.c,v 1.27 2003/02/01 23:06:43 dholland Exp $";

#define MAXMEM (16*1024*1024)

/*
 * Bus controller's own registers.
 */
u_int32_t bus_ramsize;
u_int32_t bus_interrupts;

/*
 * A slot.
 */
struct lamebus_slot {
   void                             *ls_devdata;
   const struct lamebus_device_info *ls_info;
};

static struct lamebus_slot devices[LAMEBUS_NSLOTS];
char *ram;

/***************************************************************/

/*
 * Fetch device register.
 */
int
bus_io_fetch(u_int32_t offset, u_int32_t *ret)
{
	u_int32_t slot = offset / LAMEBUS_SLOT_MEM;
	u_int32_t slotoffset = offset % LAMEBUS_SLOT_MEM;

	if (slot >= LAMEBUS_NSLOTS) {
		/* Out of range */
		return -1;
	}

	Assert((offset & 0x3)==0);

	if (devices[slot].ls_info==NULL) {
		return -1;
	}

	return devices[slot].ls_info->ldi_fetch(devices[slot].ls_devdata,
						slotoffset, ret);
}

/*
 * Store to device registers.
 */
int
bus_io_store(u_int32_t offset, u_int32_t val)
{
	u_int32_t slot = offset / LAMEBUS_SLOT_MEM;
	u_int32_t slotoffset = offset % LAMEBUS_SLOT_MEM;

	if (slot >= LAMEBUS_NSLOTS) {
		/* Out of range */
		return -1;
	}

	Assert((offset & 0x3)==0);

	if (devices[slot].ls_info==NULL) {
		return -1;
	}

	return devices[slot].ls_info->ldi_store(devices[slot].ls_devdata, 
						slotoffset, val);
}

/***************************************************************/

/* LAMEbus controller registers (offsets into a config region) */
#define LBC_OFFSET_VENDORID         0x0
#define LBC_OFFSET_DEVICEID         0x4
#define LBC_OFFSET_REVISION         0x8
#define LBC_OFFSET_RAMSIZE          0x200  /* bus controller slot only */
#define LBC_OFFSET_IRQS             0x204  /* bus controller slot only */
#define LBC_OFFSET_POWER            0x208  /* bus controller slot only */

static
void *
lamebus_controller_init(int slot, int argc, char *argv[])
{
	int i;

	Assert(slot==LAMEBUS_CONTROLLER_SLOT);


	/*
	 * Defaults
	 */
	bus_ramsize = 0; /* for now require configuration */

	for (i=1; i<argc; i++) {
		if (!strncmp(argv[i], "ramsize=", 8)) {
			bus_ramsize = strtoul(argv[i]+8, NULL, 0);
		}
		else {
			msg("busctl: invalid option `%s'", argv[i]);
			die();
		}
	}

	return NULL;
}

static
int
lamebus_controller_doaddress(u_int32_t offset, 
			     u_int32_t *cfg, u_int32_t *cfgoffset)
{
	Assert((offset & 3)==0);

	/* Top half of controller space is reserved for ROM. */
	if (offset >= 32768) {
		return -1;
	}

	*cfg = offset / LAMEBUS_CONFIG_SIZE;
	*cfgoffset = offset % LAMEBUS_CONFIG_SIZE;
	
	Assert(*cfg < LAMEBUS_NSLOTS);

	switch (*cfgoffset) {
	    case LBC_OFFSET_VENDORID:
	    case LBC_OFFSET_DEVICEID:
	    case LBC_OFFSET_REVISION:
		return 0;
	}

	if (*cfg != LAMEBUS_CONTROLLER_SLOT) {
		return -1;
	}

	switch (*cfgoffset) {
	    case LBC_OFFSET_RAMSIZE:
	    case LBC_OFFSET_IRQS:
	    case LBC_OFFSET_POWER:
		return 0;
	}

	return -1;
}

static
int
lamebus_controller_fetch(void *data, u_int32_t offset, u_int32_t *ret)
{
	const struct lamebus_device_info *inf;
	u_int32_t cfg, cfgoffset;
	(void)data;
	if (lamebus_controller_doaddress(offset, &cfg, &cfgoffset)) {
		return -1;
	}

	inf = devices[cfg].ls_info;

	switch (cfgoffset) {
	    case LBC_OFFSET_VENDORID:
		*ret = inf ? inf->ldi_vendorid : 0;
		return 0;
	    case LBC_OFFSET_DEVICEID:
		*ret = inf ? inf->ldi_deviceid : 0;
		return 0;
	    case LBC_OFFSET_REVISION:
		*ret = inf ? inf->ldi_revision : 0;
		return 0;
	    case LBC_OFFSET_RAMSIZE:
		*ret = bus_ramsize;
		return 0;
	    case LBC_OFFSET_IRQS:
		*ret = bus_interrupts;
		return 0;
	    case LBC_OFFSET_POWER:
		hang("Read from LAMEbus controller power register");
		return 0;
	}

	return -1;
}

static
void
dopoweroff(void *junk1, u_int32_t junk2)
{
	(void)junk1;
	(void)junk2;

	/*
	 * This is never seen by the processor, but it breaks the clock
	 * module out of the idle loop.
	 */
	RAISE_IRQ(LAMEBUS_CONTROLLER_SLOT);

	main_poweroff();
}

static
int
lamebus_controller_store(void *data, u_int32_t offset, u_int32_t val)
{
	u_int32_t cfg, cfgoffset;
	(void)data;
	if (lamebus_controller_doaddress(offset, &cfg, &cfgoffset)) {
		return -1;
	}


	switch (cfgoffset) {
	    case LBC_OFFSET_POWER:
		if (val==0) {
			schedule_event(POWEROFF_NSECS, NULL, 0, dopoweroff,
				       "poweroff");
		}
		return 0;
	    default:
		break;
	}

	return -1;
}

static
void
lamebus_controller_dumpstate(void *data)
{
	(void)data;
	msg("LAMEbus controller rev %d", BUSCTL_REVISION);
	msg("    ramsize: %lu (%luk)", 
	    (unsigned long)bus_ramsize, 
	    (unsigned long)bus_ramsize/1024);
	msg("    irqs: 0x%08x", bus_interrupts);
}

static struct lamebus_device_info lamebus_controller_info = {
	LBVEND_CS161,
	LBVEND_CS161_CTL,
	BUSCTL_REVISION,
	lamebus_controller_init,
	lamebus_controller_fetch,
	lamebus_controller_store,
	lamebus_controller_dumpstate,
	NULL,
};


/***************************************************************/

struct bus_device {
	const char *dev_name;
	const struct lamebus_device_info *dev_info;
};

static const struct bus_device devtable[] = {
	{ "busctl",     &lamebus_controller_info },
	{ "timer",      &timer_device_info }, 
	{ "disk",       &disk_device_info },
	{ "serial",     &serial_device_info },
	{ "screen",     &screen_device_info },
	{ "nic",        &net_device_info },
	{ "emufs",      &emufs_device_info },
	{ "trace",      &trace_device_info },
	{ "random",     &random_device_info },
	{ NULL, NULL }
};

static 
const struct bus_device *
find_dev(const char *name)
{
	int i;
	for (i=0; devtable[i].dev_name; i++) {
		if (!strcmp(devtable[i].dev_name, name)) {
			return &devtable[i];
		}
	}
	return NULL;
}

/*
 * Config file syntax is:
 *
 *     slot device-name args
 */
#define MAXARGS 128
void
bus_config(const char *configfile)
{
	char *s;
	const struct bus_device *dev;
	char buf[1024], *argv[MAXARGS];
	int argc, slot, line=0;
	FILE *f = fopen(configfile, "r");
	if (!f) {
		msg("Cannot open config file %s", configfile);
		die();
	}

	while (fgets(buf, sizeof(buf),f)) {
		line++;
		s = strchr(buf, '#');
		if (s) *s = 0;
		argc=0;
		for (s=strtok(buf, " \t\r\n"); s; s=strtok(NULL, " \t\r\n")) {
			if (argc<MAXARGS) argv[argc++] = s;
		}
		if (argc>=MAXARGS) {
			msg("config %s: line %d: Too many args", 
			    configfile, line);
			die();
		}
		argv[argc] = NULL;
		if (argc==0) continue;

		slot = strtol(argv[0], &s, 0);
		if (strlen(s)>0 || slot<0 || slot>=LAMEBUS_NSLOTS) {
			msg("config %s: line %d: Invalid slot `%s' (should "
			    "be 0-%d)", 
			    configfile, line, argv[0], LAMEBUS_NSLOTS-1);
			die();
		}
      
		if (argc==1) {
			msg("config %s: line %d: slot %d: No device", 
			    configfile, line, slot);
			die();
		}

		if (devices[slot].ls_info!=NULL) {
			msg("config %s: line %d: slot %d: Already in use",
			    configfile, line, slot);
			die();
		}
		
		dev = find_dev(argv[1]);
		if (!dev) {
			msg("config %s: line %d: slot %d: No such "
			    "hardware `%s'", 
			    configfile, line, slot, argv[1]);
			die();
		}
		
		{
			int isbus = !strcmp(dev->dev_name, "busctl");
			int isbusslot = slot==LAMEBUS_CONTROLLER_SLOT;

			if ((isbus && !isbusslot) || (!isbus && isbusslot)) {
				msg("config %s: line %d: slot %d: "
				    "%s: Bus controller must "
				    "go in slot %d", 
				    configfile, line, slot, argv[1], 
				    LAMEBUS_CONTROLLER_SLOT);
				die();
			}
		}
		
		devices[slot].ls_info = dev->dev_info;
		devices[slot].ls_devdata = 
			dev->dev_info->ldi_init(slot, argc-1, argv+1);
	}
	
	fclose(f);
	
	if (bus_ramsize == 0) {
		msg("config %s: No system memory", configfile);
		die();
	}
	if (bus_ramsize & 0xfff) {
		msg("config %s: System memory size not page-aligned", 
		    configfile);
		die();
	}
	if (bus_ramsize > MAXMEM) {
		msg("config %s: System memory too large", configfile);
		die();
	}
	
	ram = calloc(bus_ramsize, 1);
	if (!ram) {
		msg("config %s: Cannot allocate system memory", configfile);
		die();
	}
}

void
bus_cleanup(void)
{
	int i;

	free(ram);
	ram = NULL;

	for (i=0; i<LAMEBUS_NSLOTS; i++) {
		if (devices[i].ls_info==NULL) {
			continue;
		}
		if (devices[i].ls_info->ldi_cleanup==NULL) {
			continue;
		}
		devices[i].ls_info->ldi_cleanup(devices[i].ls_devdata);
	}
}

void
bus_dumpstate(void)
{
	int i;

	for (i=0; i<LAMEBUS_NSLOTS; i++) {
		if (devices[i].ls_info==NULL) {
			continue;
		}
		msg("************ Slot %d ************", i);
		devices[i].ls_info->ldi_dumpstate(devices[i].ls_devdata);
	}

	msg("RAM:");
	dohexdump(ram, bus_ramsize);
}
