#include "trace.h"

#ifndef LAMEBUS_H
#define LAMEBUS_H

/*
 * Info for a simulated device.
 */
struct lamebus_device_info {
   u_int32_t ldi_vendorid;
   u_int32_t ldi_deviceid;
   u_int32_t ldi_revision;
   void   *(*ldi_init)(int slot, int argc, char *argv[]);
   int     (*ldi_fetch)(void *, u_int32_t offset, u_int32_t *rt);
   int     (*ldi_store)(void *, u_int32_t offset, u_int32_t val);
   void    (*ldi_dumpstate)(void *);
   void    (*ldi_cleanup)(void *);
};

/*
 * Existing devices.
 */
extern const struct lamebus_device_info
   timer_device_info,
   disk_device_info,
   serial_device_info,
   screen_device_info,
   net_device_info,
   emufs_device_info,
   trace_device_info,
   random_device_info;

/*
 * Interrupt management.
 */
extern u_int32_t bus_interrupts;  // NOTICE: also declared in bus.h

#define RAISE_IRQ2(slot) (bus_interrupts |= (1<<(u_int32_t)(slot)))
#define LOWER_IRQ2(slot) (bus_interrupts &= ~(1<<(u_int32_t)(slot)))
#define CHECK_IRQ(slot) ((bus_interrupts & (1<<(u_int32_t)(slot))) != 0)

#ifdef USE_TRACE

#define RAISE_IRQ(slot) { \
	RAISE_IRQ2(slot); \
	TRACE(DOTRACE_IRQ, ("Slot %2d: irq ON", (slot))); \
}

#define LOWER_IRQ(slot) { \
	LOWER_IRQ2(slot); \
	TRACE(DOTRACE_IRQ, ("Slot %2d: irq OFF", (slot))); \
}

#else /* not USE_TRACE */

#define RAISE_IRQ(slot) RAISE_IRQ2(slot)
#define LOWER_IRQ(slot) LOWER_IRQ2(slot)

#endif /* USE_TRACE */

#endif /* LAMEBUS_H */
