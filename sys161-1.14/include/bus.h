#ifndef BUS_H
#define BUS_H

/*
 * One bit for each bus interrupt line.
 * Code outside the bus directory should really only interpret this as
 * zero (no interrupts) or nonzero (interrupts requested).
 *
 * NOTICE: also declared in bus/lamebus.h.
 */
extern u_int32_t bus_interrupts;

/*
 * Addresses are relative to the start of RAM pretending it's contiguous,
 * or relative to the start of I/O space. We split things up this way
 * because the actual memory layout is machine-dependent.
 *
 * The _mem_ functions are now kept in inlinemem.h
 */

//int bus_mem_fetch(u_int32_t addr, u_int32_t *);
//int bus_mem_store(u_int32_t addr, u_int32_t);
int bus_io_fetch(u_int32_t addr, u_int32_t *);
int bus_io_store(u_int32_t addr, u_int32_t);

/*
 * Set up bus and cards in bus.
 */
void bus_config(const char *configfile);

/*
 * Clean up bus in preparation for exit.
 */
void bus_cleanup(void);

/*
 * Diagnostics.
 */
void bus_dumpstate(void);

/*
 * Load kernel. (boot.c)
 */
void load_kernel(const char *image, const char *argument);

#endif /* BUS_H */
