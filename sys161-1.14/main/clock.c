#include <sys/types.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

#include "console.h"
#include "speed.h"
#include "clock.h"
#include "cpu.h"
#include "bus.h"
#include "onsel.h"
#include "main.h"

/*
 * random() is a BSD function that is usually documented to return
 * values in the range 0 to 2^31-1, independent of RAND_MAX. It
 * appears, on some systems, that this is in fact the case and that
 * RAND_MAX must be ignored. So define RANDOM_MAX for our own purposes.
 * (Also see comment in dev_random.c.)
 *
 * Nowadays NetBSD defines RANDOM_MAX for us; maybe other systems will
 * sometime too.
 */

#ifndef RANDOM_MAX
#define RANDOM_MAX 0x7fffffffUL
#endif


const char rcsid_clock_c[] =
    "$Id: clock.c,v 1.16 2008/06/27 21:24:27 dholland Exp $";

struct timed_action {
	struct timed_action *ta_next;
	u_int64_t ta_clocksat;
	void *ta_data;
	u_int32_t ta_code;
	void (*ta_func)(void *, u_int32_t);
	const char *ta_desc;
};

static u_int32_t now_secs;
static u_int32_t now_nsecs;

static u_int32_t start_secs, start_nsecs;

static u_int64_t now_clocks;

/**************************************************************/

/* up to 16 simultaneous timed actions per device */
#define MAXACTIONS 1024
static struct timed_action action_storage[MAXACTIONS];
static struct timed_action *ta_freelist = NULL;

static
struct timed_action *
acalloc(void)
{
	struct timed_action *ta;
	if (ta_freelist == NULL) {
		smoke("Too many pending hardware interrupts");
	}
	ta = ta_freelist;
	ta_freelist = ta->ta_next;
	return ta;
}

static
void
acfree(struct timed_action *ta)
{
	ta->ta_next = ta_freelist;
	ta_freelist = ta;
}

static
void
acalloc_init(void)
{
	int i;
	for (i=0; i<MAXACTIONS; i++) {
		acfree(&action_storage[i]);
	}
}

/*************************************************************/

static struct timed_action *queuehead = NULL;

static
void
check_queue(void)
{
	struct timed_action *ta;
	while (queuehead != NULL) {
		ta = queuehead;
		if (ta->ta_clocksat != now_clocks) {
			return;
		}
		
		ta->ta_func(ta->ta_data, ta->ta_code);
		queuehead = ta->ta_next;
		acfree(ta);
	}
}

void
schedule_event(u_int64_t nsecs, void *data, u_int32_t code,
	       void (*func)(void *, u_int32_t),
	       const char *desc)
{
	u_int64_t clocks;
	struct timed_action *n, **p;

	nsecs += (u_int64_t)((random()*(nsecs*0.01))/RANDOM_MAX);

	clocks = nsecs / NSECS_PER_CLOCK;

	n = acalloc();
	n->ta_clocksat = now_clocks + clocks;
	n->ta_data = data;
	n->ta_code = code;
	n->ta_func = func;
	n->ta_desc = desc;

	/*
	 * Sorted linked-list insert.
	 */

	for (p = &queuehead; (*p) != NULL; p = &(*p)->ta_next) {
		if (n->ta_clocksat < (*p)->ta_clocksat) {
			break;
		}
	}

	n->ta_next = (*p);
	(*p) = n;
}

void
clock_time(u_int32_t *secs, u_int32_t *nsecs)
{
	if (secs) *secs = now_secs;
	if (nsecs) *nsecs = now_nsecs;
}

void
clock_setsecs(u_int32_t secs)
{
	//reschedule_queue(secs - now_secs, 0);
	now_secs = secs;
}

void
clock_setnsecs(u_int32_t nsecs)
{
	//reschedule_queue(0, nsecs - now_nsecs);
	now_nsecs = nsecs;
}

/* Always call clock_advance or check_queue after this */
static
inline
void
clock_advance_secs(u_int32_t secs)
{
	now_secs += secs;
}

static
inline
void
clock_advance(u_int32_t nsecs)
{
	/* Believe it or not, gcc generates better code with this here */
	u_int32_t tmp;

	tmp = now_nsecs;

	tmp += nsecs;
	if (tmp >= 1000000000) {
		tmp -= 1000000000;
		now_secs++;
	}

	now_nsecs = tmp;

	check_queue();
}

void
clock_init(void)
{
	struct timeval tv;
	u_int32_t offset;

	acalloc_init();
	gettimeofday(&tv, NULL);
	now_secs = tv.tv_sec;
	now_nsecs = 1000*tv.tv_usec;
	now_clocks = 0;

	/* Shift the clock ahead a random fraction of 10 ms. */
	offset = random() % 10000000;
	clock_advance(offset);

	start_secs = now_secs;
	start_nsecs = now_nsecs;
}

void
clock_cleanup(void)
{
	u_int32_t secs, nsecs;

	secs = now_secs - start_secs;
	if (now_nsecs < start_nsecs) {
		nsecs = (1000000000 + now_nsecs) - start_nsecs;
		secs--;
	}
	else {
		nsecs = now_nsecs - start_nsecs;
	}

	msg("Elapsed virtual time: %lu.%09lu seconds (%d mhz)", 
	    (unsigned long)secs, 
	    (unsigned long)nsecs,
	    1000/NSECS_PER_CLOCK);
}

void
clock_dumpstate(void)
{
	struct timed_action *ta;

	msg("clock: %lu.%09lu secs (start at %lu.%09lu)", 
	    (unsigned long) now_secs,
	    (unsigned long) now_nsecs,
	    (unsigned long) start_secs,
	    (unsigned long) start_nsecs);
	if (sizeof(now_clocks)==sizeof(unsigned long)) {
		msg("clock:    %9lu ticks", (unsigned long) now_clocks);
	}
	else {
		msg("clock:    %9llu ticks", now_clocks);
	}

	if (queuehead==NULL) {
		msg("clock: No events pending");
		return;
	}

	for (ta = queuehead; ta; ta = ta->ta_next) {
		msgl("clock: at ");
		if (sizeof(now_clocks)==sizeof(unsigned long)) {
			msgl("%9lu", (unsigned long) ta->ta_clocksat);
		}
		else {
			msgl("%9llu", ta->ta_clocksat);
		}
		msg(": %s", ta->ta_desc);
	}
}

void
clock_tick(void)
{
	clock_advance(NSECS_PER_CLOCK);
	now_clocks++;
}

static
void
report_idletime(u_int32_t secs, u_int32_t nsecs)
{
	u_int64_t idlensecs;
	static u_int32_t slop;

	idlensecs = secs * (u_int64_t)1000000000 + nsecs + slop;

	g_stats.s_icycles += idlensecs / NSECS_PER_CLOCK;
	slop = idlensecs % NSECS_PER_CLOCK;
}

static
void
clock_dowait(u_int32_t secs, u_int32_t nsecs, u_int64_t clocks)
{
	struct timeval tv;
	int32_t wsecs, wnsecs;

	now_clocks += clocks;
	clock_advance_secs(secs);
	clock_advance(nsecs);
	report_idletime(secs, nsecs);

	if (queuehead != NULL) {
		if (queuehead->ta_clocksat < now_clocks) {
			smoke("Hardware event queue screwed up");
		}
	}

	/*
	 * Figure out how far ahead of real wall time we are.  If we
	 * aren't, don't sleep. If we are, sleep to synchronize, as
	 * long as it's more than 10 ms. (If it's less than that,
	 * we're not likely to return from select in anything
	 * approaching an expeditions manner. Also, on some systems,
	 * select with small timeouts does timing loops to implement
	 * usleep(), and we don't want that. The only point of
	 * sleeping at all is to be nice to other users on the system.)
	 */
	gettimeofday(&tv, NULL);
	wsecs = now_secs - tv.tv_sec;
	wnsecs = now_nsecs - 1000*tv.tv_usec;
	if (wnsecs < 0) {
		wnsecs += 1000000000;
		wsecs--;
	}

	if (wsecs >= 0 && wnsecs > 10000000) {
		tryselect(1, wsecs, wnsecs);
	}
	else {
		tryselect(1, 0, 0);
	}
}

void
clock_waitirq(void)
{
	while (bus_interrupts==0) {
		if (queuehead != NULL) {
			u_int64_t clocks;
			u_int64_t nsecs;
			u_int32_t secs;

			clocks = queuehead->ta_clocksat - now_clocks;
			nsecs = clocks * NSECS_PER_CLOCK;

			secs = nsecs / 1000000000;
			nsecs = nsecs % 1000000000;

			clock_dowait(secs, nsecs, clocks);
		}
		else {
			struct timeval tv1, tv2;

			gettimeofday(&tv1, NULL);
			tryselect(0, 0, 0);
			gettimeofday(&tv2, NULL);

			tv2.tv_sec -= tv1.tv_sec;
			if (tv2.tv_usec < tv1.tv_usec) {
				tv2.tv_usec += 1000000;
			}
			tv2.tv_usec -= tv1.tv_usec;

			clock_advance_secs(tv2.tv_sec);
			clock_advance(tv2.tv_usec * 1000);
			report_idletime(tv2.tv_sec, tv2.tv_usec * 1000);

			/* don't advance now_clocks - no reason to bother */
		}
	}
}
