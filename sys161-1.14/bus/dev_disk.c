#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include "config.h"

#include "console.h"
#include "clock.h"
#include "main.h"
#include "util.h"

#include "lamebus.h"
#include "busids.h"


const char rcsid_dev_disk_c[] =
    "$Id: dev_disk.c,v 1.22 2002/08/08 22:59:43 dholland Exp $";

/* Disk underlying I/O definitions */
#define HEADER_MESSAGE  "System/161 Disk Image"
#define HEADERSIZE      SECTSIZE

/* Disk physical parameters */
#define SECTSIZE               512   /* bytes */
#define SECTOR_FUDGE          1.06
#define OUTER_DIAM				80
#define INNER_DIAM				20
#define PLATTER_AREA			((OUTER_DIAM)*(OUTER_DIAM) - \
								(INNER_DIAM)*(INNER_DIAM)) \
								*PI/4

#define PI						3.14159

#define NUMTRACKS				32

/* Disk timing parameters */
#define CACHE_READ_TIME      500       /* ns */
#define CACHE_WRITE_TIME     500       /* ns */

/* Number of tries after which we assume the timing code has lost its marbles*/
#define MAX_WORKTRIES    10

/* Register offsets */
#define DISKREG_NSECT 0
#define DISKREG_STAT  4
#define DISKREG_SECT  8
#define DISKREG_RPM   12

/* Transfer buffer offsets */
#define DISK_BUF_START  32768
#define DISK_BUF_END    (DISK_BUF_START + SECTSIZE)

/* Bits for status registers */
#define DISKBIT_INPROGRESS    1
#define DISKBIT_ISWRITE       2
#define DISKBIT_COMPLETE      4
#define DISKBIT_INVSECT       8
#define DISKBIT_MEDIAERR      16

/* The legal values that can be written to the status register */
#define DISKSTAT_IDLE          0
#define DISKSTAT_READING       (DISKBIT_INPROGRESS)
#define DISKSTAT_WRITING       (DISKBIT_INPROGRESS|DISKBIT_ISWRITE)

/* Masks for the other values for the status register */
#define DISKSTAT_COMPLETE      (DISKBIT_COMPLETE)
#define DISKSTAT_INVSECT       (DISKBIT_COMPLETE|DISKBIT_INVSECT)
#define DISKSTAT_MEDIAERR      (DISKBIT_COMPLETE|DISKBIT_MEDIAERR)

/* Macros for manipulating status registers */
#define FINISH(r,bits)    ((r)=((r) & ~DISKBIT_INPROGRESS)|(bits))
#define COMPLETE(r)       FINISH(r, DISKSTAT_COMPLETE)
#define INVSECT(r)        FINISH(r, DISKSTAT_INVSECT)
#define MEDIAERR(r)       FINISH(r, DISKSTAT_MEDIAERR)

/*
 * Data for holding the device state
 */
struct disk_data {
	/*
	 * Bus info
	 */
	int dd_slot;

	/*
	 * Raw I/O
	 */
	int dd_fd;
	int dd_paranoid;     /* if nonzero, fsync on every write */

	/* 
	 * Geometry:
	 * dd_sectors[] has dd_cylinders entries. 
	 * sum(dd_sectors) * dd_heads should give dd_totsectors.
	 * sum(dd_sectors) should give dd_totsectors.
	 */
	u_int32_t *dd_sectors;
	u_int32_t dd_tracks;	 	/* always is == NUMTRACKS */
	u_int32_t dd_totsectors;
	u_int32_t dd_rpm;
	u_int32_t dd_nsecs_per_rev;

	/* 
	 * Timing status
	 */
	int dd_current_track;
	u_int32_t dd_trackarrival_secs;
	u_int32_t dd_trackarrival_nsecs;
	int dd_iostatus;
	int dd_timedop;             /* nonzero if waiting for a timer event */

	/*
	 * Timing protection
	 */
	int dd_worktries;	/* # times dd_work called during this I/O */

	/*
	 * Registers
	 */
	u_int32_t dd_stat;
	u_int32_t dd_sect;

	/*
	 * I/O buffer
	 */
	char dd_buf[SECTSIZE];
};

////////////////////////////////////////////////////////////
//
// Raw I/O


static
int
doread(int fd, off_t offset, char *buf, size_t bufsize)
{
	size_t tot=0;
	int r;

	if (lseek(fd, offset, SEEK_SET)<0) {
		return -1;
	}

	while (tot < bufsize) {
		r = read(fd, buf + tot, bufsize - tot);
		if (r<0 && (errno==EINTR || errno==EAGAIN)) {
			continue;
		}
		if (r<0) {
			return -1;
		}
		if (r==0) {
			/* 
			 * Unexpected EOF.
			 * This means that the file isn't as large as
			 * it's supposed to be. This can happen, if,
			 * for instance, someone creats a 5M image,
			 * and then changes the config to say 10M.
			 * Pretend we read back zeros.
			 */
			memset(buf+tot, 0, bufsize-tot);
			r = bufsize-tot;
		}
		tot += r;
	}

	return 0;
}

static
int
dowrite(int fd, off_t offset, const char *buf, size_t bufsize, int paranoid)
{
	size_t tot=0;
	int r;

	if (lseek(fd, offset, SEEK_SET)<0) {
		return -1;
	}

	while (tot < bufsize) {
		r = write(fd, buf + tot, bufsize - tot);
		if (r<0 && (errno==EINTR || errno==EAGAIN)) {
			continue;
		}
		if (r<0) {
			return -1;
		}
		if (r==0) {
			/*
			 * :-?
			 */

			msg("disk: unexpected short write");
			msg("disk: fd %d, offset %ld, tot %lu, tried %lu",
			    fd, (long) offset, (unsigned long) tot,
			    (unsigned long) (bufsize - tot));

			errno = EIO;
			return -1;
		}
		tot += r;
	}

	if (paranoid) {
		if (fsync(fd)) {
			return -1;
		}
	}

	return 0;
}

static
void
writeheader(struct disk_data *dd, const char *filename)
{
	off_t fsize;
	char buf[HEADERSIZE];

	memset(buf, 0, HEADERSIZE);
	strcpy(buf, HEADER_MESSAGE);

	if (dowrite(dd->dd_fd, 0, buf, HEADERSIZE, dd->dd_paranoid)) {
		msg("disk: slot %d: %s: Write of header: %s",
		    dd->dd_slot, filename, strerror(errno));
		die();
	}
	
	fsize = dd->dd_totsectors;
	fsize *= SECTSIZE;
	fsize += HEADERSIZE;

	if (ftruncate(dd->dd_fd, fsize)) {
		msg("disk: slot %d: %s: ftruncate: %s",
		    dd->dd_slot, filename, strerror(errno));
		die();
	}
}

static
void
readheader(struct disk_data *dd, const char *filename)
{
	char buf[HEADERSIZE];
	if (doread(dd->dd_fd, 0, buf, HEADERSIZE)) {
		msg("disk: slot %d: %s: Reading header: %s",
		    dd->dd_slot, filename, strerror(errno));
		die();
	}

	/* just in case */
	buf[HEADERSIZE-1] = 0;

	if (strcmp(buf, HEADER_MESSAGE)) {
		msg("disk: slot %d: %s is not a disk image",
		    dd->dd_slot, filename);
		die();
	}
}

static
void
disk_open(struct disk_data *dd, const char *filename)
{
	dd->dd_fd = open(filename, O_RDWR);
	if (dd->dd_fd<0 && errno==ENOENT) {
		dd->dd_fd = open(filename, O_RDWR|O_CREAT|O_EXCL, 0664);
		if (dd->dd_fd<0) {
			msg("disk: slot %d: %s: %s",
			    dd->dd_slot, filename, strerror(errno));
			die();
		}
		writeheader(dd, filename);
		return;
	}
	if (dd->dd_fd<0) {
		msg("disk: slot %d: %s: %s",
		    dd->dd_slot, filename, strerror(errno));
		die();
	}
	readheader(dd, filename);
}

static
void
disk_close(struct disk_data *dd)
{
	if (close(dd->dd_fd)) {
		smoke("disk: slot %d: close: %s", 
		      dd->dd_slot, strerror(errno));
	}
}

static
int
disk_readsector(struct disk_data *dd)
{
	off_t offset = dd->dd_sect;
	offset *= SECTSIZE;
	offset += HEADERSIZE;

	g_stats.s_rsects++;

	return doread(dd->dd_fd, offset, dd->dd_buf, SECTSIZE);
}

static
int
disk_writesector(struct disk_data *dd)
{
	off_t offset = dd->dd_sect;
	offset *= SECTSIZE;
	offset += HEADERSIZE;

	g_stats.s_wsects++;

	return dowrite(dd->dd_fd, offset, dd->dd_buf, SECTSIZE,
		       dd->dd_paranoid);
}

////////////////////////////////////////////////////////////
//
// Geometry modeling

static
int
compute_sectors(struct disk_data *dd)
{
	u_int32_t physsectors;      // total number of actual sectors
	u_int32_t sectorspertrack;  // average sectors per track
	u_int32_t i, tot;

	double sectors_per_area;
	double trackwidth;

	/*
	 * Compute number of physical sectors. We use a bit more than the
	 * requested space so as to leave room for sector remapping. Not
	 * that we actually do sector remapping when computing latencies,
	 * but we could. Note that these spare sectors do not appear in
	 * the file we use for underlying storage.
	 */
	physsectors = (u_int32_t)(dd->dd_totsectors * SECTOR_FUDGE);
	if (physsectors < dd->dd_totsectors) {
		/* Overflow - didn't fit in u_int32_t */
		smoke("Fatal error computing disk geometry");
		return -1;
	}

	sectorspertrack = physsectors/NUMTRACKS;
	dd->dd_tracks = NUMTRACKS;

	/* allocate space for dd_tracks entries */
	dd->dd_sectors = domalloc(dd->dd_tracks*sizeof(u_int32_t));

	/* compute the width of each track */
	trackwidth = ((OUTER_DIAM - INNER_DIAM)/2) / (double)dd->dd_tracks;
	
	/* compute the number of sectors per unit area of disk */
	sectors_per_area = physsectors / (PLATTER_AREA);

	/*
	 * Now, figure out how many sectors are on each track.
	 * We do this by computing the area of the track and multiplying
	 * by sectors_per_area, truncating to the next smallest integer.
	 * We reserve one sector on each track.
	 */
	for (i=0; i<dd->dd_tracks; i++) {
		double inside = INNER_DIAM/2.0 + i*trackwidth;
		double outside = inside + trackwidth;

		/* 
		 * this track's area = pi*(outside^2 - inside^2) = pi*(outside +
		 * inside)*(outside - inside) = pi*(outside +
		 * inside)*(trackwidth)
		 */

		double trackarea = (outside+inside)*trackwidth*PI;
		double sectors = sectors_per_area*trackarea;

		if (sectors < 2.0) {
			/* too small */
			return -1;
		}

		dd->dd_sectors[i] = ((int)sectors) - 1;
	}

    /* Now compute the total number of sectors available. */
    tot = 0;
    for (i=0; i<dd->dd_tracks; i++) {
        tot += dd->dd_sectors[i];
    }

    /* Make sure we've got enough space. */
    if (tot < dd->dd_totsectors) {
        /* 
         * Shouldn't happen. If it does, increase SECTOR_FUDGE.
         */
        return -1;
    }

	return 0;
}

static
void
locate_sector(struct disk_data *dd,
	      u_int32_t sector, int *track, int *rotoffset)
{
	/* 
	 * Assume sector has already been checked for being in bounds.
	 *
	 * Note that we start numbering sectors from the outermost
	 * (fastest) track.
	 */
	
	u_int32_t i;
	u_int32_t start = 0;

	for (i = dd->dd_tracks; i > 0; i--) {
		u_int32_t tr = i-1;
		u_int32_t end = start + dd->dd_sectors[tr];
		if (sector >= start && sector < end) {
			*track = tr;
			*rotoffset = sector - start;
			return;
		}
		start = end;
	}
	
	smoke("Cannot locate sector %u\n", sector);
}

static
u_int32_t
disk_seektime(struct disk_data *dd, int ntracks)
{
	double nt;
	(void)dd;

	nt = ntracks;
	if (nt > 5) {
		nt = sqrt(nt);
	}
	return nt * 200000;
}

static
u_int32_t
disk_readrotdelay(struct disk_data *dd, u_int32_t cyl, u_int32_t rotoffset)
{
	u_int32_t nowsecs, nownsecs;

	/*
	 * Time for crossing a single sector.
	 */
	u_int32_t nsecs_per_sector = dd->dd_nsecs_per_rev/dd->dd_sectors[cyl];

	/*
	 * Next sector after the one we want.
	 */
	u_int32_t targsector = (rotoffset+1) % dd->dd_sectors[cyl];

	/*
	 * Compute when the next sector would first be reached after
	 * hitting the track. (When the next sector is reached, the
	 * sector we want is fully read.)
	 *
	 * Note that we require that there are an integral number of
	 * revs per second, and that we assume the platters are always
	 * at position 0 when nownsecs = 0.
	 */
	u_int32_t targsecs = dd->dd_trackarrival_secs;
	u_int32_t targnsecs = targsector * nsecs_per_sector;
	while (targnsecs < dd->dd_trackarrival_nsecs) {
		targnsecs += dd->dd_nsecs_per_rev;
	}
	while (targnsecs >= 1000000000) {
		targnsecs -= 1000000000;
		targsecs++;
	}

	clock_time(&nowsecs, &nownsecs);

	/*
	 * If we've reached that time, we've already crossed the
	 * sector and it's in our track buffer.
	 */
	if (targsecs < nowsecs ||
	    (targsecs == nowsecs && targnsecs <= nownsecs)) {
		return 0;
	}

	/*
	 * Otherwise, we need to wait until that time.
	 */
	targsecs -= nowsecs;
	targnsecs -= nownsecs;
	targnsecs += 1000000000*targsecs;  // should not overflow

	return targnsecs;
}

static
u_int32_t
disk_writerotdelay(struct disk_data *dd, u_int32_t cyl, u_int32_t rotoffset)
{
	u_int32_t nowsecs, nownsecs;

	/*
	 * Time for crossing a single sector.
	 */
	u_int32_t nsecs_per_sector = dd->dd_nsecs_per_rev/dd->dd_sectors[cyl];

	/*
	 * Compute when the sector we want will next be reached.
	 * (Ignore seconds. The disk must be at least 60 rpm, so we
	 * can get to any sector without overflowing a u_int32_t of
	 * nsecs.)
	 */
	u_int32_t targnsecs = rotoffset * nsecs_per_sector;
	u_int32_t delay;

	clock_time(&nowsecs, &nownsecs);

	while (targnsecs < nownsecs) {
		targnsecs += dd->dd_nsecs_per_rev;
	}

	/*
	 * Add in how long it takes to do the write.
	 */
	targnsecs += nsecs_per_sector;

	/*
	 * Wait until then.
	 */
	delay = targnsecs - nownsecs;

	return delay;
}

////////////////////////////////////////////////////////////
//
// Setup


static
void *
disk_init(int slot, int argc, char *argv[])
{
	struct disk_data *dd = domalloc(sizeof(struct disk_data));
	const char *filename = NULL;
	u_int32_t totsectors=0;
	u_int32_t rpm = 3600;
	int i, paranoid=0;

	for (i=1; i<argc; i++) {
		if (!strncmp(argv[i], "rpm=", 4)) {
			rpm = atoi(argv[i]+4);
		}
		else if (!strncmp(argv[i], "sectors=", 8)) {
			totsectors = atoi(argv[i]+8);
		}
		else if (!strncmp(argv[i], "file=", 5)) {
			filename = argv[i]+5;
		}
		else if (!strcmp(argv[i], "paranoid")) {
			paranoid = 1;
		}
		else {
			msg("disk: slot %d: invalid option %s", slot, argv[i]);
			die();
		}
	}

	if (totsectors < 128) {
		msg("disk: slot %d: Too small", slot);
		die();
	}

	dd->dd_slot = slot;
	dd->dd_totsectors = totsectors;

	/* set dd_cylinders, dd_sectors, dd_heads */
	if (compute_sectors(dd)) {
		msg("disk: slot %d: Geometry initialization failed "
		    "(try another size)", slot);
		die();
	}


	if (rpm < 60) {
		msg("disk: slot %d: RPM too low (%d)", slot, rpm);
		die();
	}
	if (rpm % 60) {
		msg("disk: slot %d: RPM %d not a multiple of 60", slot, rpm);
		die();
	}

	dd->dd_rpm = rpm;
	dd->dd_nsecs_per_rev = 1000000000 / (dd->dd_rpm / 60);

	dd->dd_current_track = 0;
	
	clock_time(&dd->dd_trackarrival_secs, &dd->dd_trackarrival_nsecs);

	dd->dd_stat = DISKSTAT_IDLE;
	dd->dd_sect = 0;

	dd->dd_paranoid = paranoid;

	dd->dd_iostatus = -1;

	dd->dd_worktries = 0;

	if (filename==NULL) {
		msg("disk: slot %d: No filename specified", slot);
		die();
	}

	disk_open(dd, filename);

	return dd;
}

static
void
disk_cleanup(void *data)
{
	struct disk_data *dd = data;
	disk_close(dd);
	free(dd);
}

////////////////////////////////////////////////////////////
//
// Operations

static void disk_update(struct disk_data *dd);

static
void
disk_seekdone(void *data, u_int32_t cyl)
{
	struct disk_data *dd = data;

	dd->dd_current_track = cyl;
	clock_time(&dd->dd_trackarrival_secs, &dd->dd_trackarrival_nsecs);

	dd->dd_timedop = 0;
	disk_update(dd);
}

static
void
disk_waitdone(void *data, u_int32_t status)
{
	struct disk_data *dd = data;

	dd->dd_iostatus = status;

	dd->dd_timedop = 0;
	disk_update(dd);
}

static
void
disk_work(struct disk_data *dd)
{
	int cyl, rotoffset;
	u_int32_t rotdelay;
	int err;

	if (dd->dd_timedop) {
		/*
		 * Something's presently happening. Nothing more happens until
		 * it finishes.
		 */
		return;
	}

	if ((dd->dd_stat & DISKBIT_INPROGRESS)==0) {
		/*
		 * Nothing to do.
		 */
		return;
	}

	if (dd->dd_sect >= dd->dd_totsectors) {
		TRACE(DOTRACE_DISK, ("disk: slot %d: Invalid sector", 
				     dd->dd_slot));
		INVSECT(dd->dd_stat);
		dd->dd_worktries = 0;
		return;
	}

	dd->dd_worktries++;
	if (dd->dd_worktries > MAX_WORKTRIES) {
		msg("Geometry modeling fault! Please report to maintainer.)");
		TRACE(DOTRACE_DISK, ("disk: slot %d: Too many loops through "
				     "timing code!", dd->dd_slot));
		TRACE(DOTRACE_DISK, ("disk: current track %d; arrival %u.%09u;"
				     "iostatus %d",
				     dd->dd_current_track,
				     dd->dd_trackarrival_secs,
				     dd->dd_trackarrival_nsecs,
				     dd->dd_iostatus));

		dd->dd_current_track = 0;
		clock_time(&dd->dd_trackarrival_secs, 
			   &dd->dd_trackarrival_nsecs);
		dd->dd_iostatus = -1;
		dd->dd_timedop = 0;

		/* skip over all the timing crap */
		goto forceio;
	}

	locate_sector(dd, dd->dd_sect, &cyl, &rotoffset);

	if (dd->dd_current_track != cyl) {
		/*
		 * Need to seek.
		 */
		u_int32_t nsecs;
		int distance;

		TRACE(DOTRACE_DISK, ("disk: slot %d: seeking to track %d",
				     dd->dd_slot, cyl));

		distance = cyl - dd->dd_current_track;
		if (distance<0) {
			distance = -distance;
		}
		
		nsecs = disk_seektime(dd, distance);
		
		dd->dd_timedop = 1;
		schedule_event(nsecs, dd, cyl, disk_seekdone, "disk seek");
		return;
	}

	if (dd->dd_stat & DISKBIT_ISWRITE && dd->dd_iostatus < 1) {
		//TRACE(DOTRACE_DISK, ("disk: slot %d: write copy latency", 
		//		     dd->dd_slot));
		dd->dd_timedop = 1;
		schedule_event(CACHE_WRITE_TIME, dd, 1, disk_waitdone,
			       "disk cache write");
		return;
	}
	
	if (dd->dd_iostatus < 2) {
		if (dd->dd_stat & DISKBIT_ISWRITE) {
			rotdelay = disk_writerotdelay(dd, cyl, rotoffset);
		}
		else {
			rotdelay = disk_readrotdelay(dd, cyl, rotoffset);
		}
		if (rotdelay > 0) {
			TRACE(DOTRACE_DISK, ("disk: slot %d: rotdelay %u ns", 
					     dd->dd_slot, rotdelay));
			dd->dd_timedop = 1;
			schedule_event(rotdelay, dd, 2, disk_waitdone,
				       "disk rotation");
			return;
		}
		else {
			TRACE(DOTRACE_DISK, ("disk: slot %d: rotdelay 0 ns", 
					     dd->dd_slot));
			dd->dd_iostatus = 2;
		}
	}

	if ((dd->dd_stat & DISKBIT_ISWRITE)==0 && dd->dd_iostatus < 3) {
		//TRACE(DOTRACE_DISK, ("disk: slot %d: read copy latency", 
		//		     dd->dd_slot));
		dd->dd_timedop = 1;
		schedule_event(CACHE_WRITE_TIME, dd, 3, disk_waitdone,
			       "disk cache read");
		return;
	}

 forceio:

	/*
	 * We're here.
	 */
	if (dd->dd_stat & DISKBIT_ISWRITE) {
		TRACE(DOTRACE_DISK, ("disk: slot %d: write sector %u", 
				     dd->dd_slot, dd->dd_sect));
		err = disk_writesector(dd);
	}
	else {
		TRACE(DOTRACE_DISK, ("disk: slot %d: read sector %u", 
				     dd->dd_slot, dd->dd_sect));
		err = disk_readsector(dd);
	}

	if (err) {
		TRACE(DOTRACE_DISK, ("disk: slot %d: media error", 
				     dd->dd_slot));
		MEDIAERR(dd->dd_stat);
		dd->dd_worktries = 0;
	}
	else {
		COMPLETE(dd->dd_stat);
		dd->dd_worktries = 0;
	}

}


static
void
disk_update(struct disk_data *dd)
{
	disk_work(dd);

	if (dd->dd_stat & DISKBIT_COMPLETE) {
		RAISE_IRQ(dd->dd_slot);
	}
	else {
		LOWER_IRQ(dd->dd_slot);
	}
}



static
void
disk_setstatus(struct disk_data *dd, u_int32_t val)
{
	switch (val) {
	    case DISKSTAT_IDLE:
		TRACE(DOTRACE_DISK, ("disk: slot %d: idle", dd->dd_slot));
		dd->dd_iostatus = -1;
		break;
	    case DISKSTAT_READING:
		TRACE(DOTRACE_DISK, ("disk: slot %d: read starts",
				     dd->dd_slot));
		dd->dd_iostatus = 0;
		break;
	    case DISKSTAT_WRITING:
		TRACE(DOTRACE_DISK, ("disk: slot %d: write starts", 
				     dd->dd_slot));
		dd->dd_iostatus = 0;
		break;
	    default:
		hang("disk: Invalid write %u to status register", val);
		return;
	}

	dd->dd_stat = val;

	disk_update(dd);
}

static
int
disk_fetch(void *data, u_int32_t offset, u_int32_t *ret)
{
	struct disk_data *dd = data;
	u_int32_t *ptr;

	if (offset >= DISK_BUF_START && offset < DISK_BUF_END) {
		offset -= DISK_BUF_START;
		ptr = (u_int32_t *)(dd->dd_buf + offset);
		*ret = ntohl(*ptr);
		return 0;
	}

	switch (offset) {
	    case DISKREG_NSECT: *ret = dd->dd_totsectors; return 0;
	    case DISKREG_RPM: *ret = dd->dd_rpm; return 0;
	    case DISKREG_STAT: *ret = dd->dd_stat; return 0;
	    case DISKREG_SECT: *ret = dd->dd_sect; return 0;
	}
	return -1;
}

static
int
disk_store(void *data, u_int32_t offset, u_int32_t val)
{
	struct disk_data *dd = data;
	u_int32_t *ptr;

	if (offset >= DISK_BUF_START && offset < DISK_BUF_END) {
		offset -= DISK_BUF_START;
		ptr = (u_int32_t *)(dd->dd_buf + offset);
		*ptr = htonl(val);
		return 0;
	}

	switch (offset) {
	    case DISKREG_STAT: disk_setstatus(dd, val); return 0;
	    case DISKREG_SECT: dd->dd_sect = val; return 0;
	}

	return -1;
}

static
void
disk_dumpstate(void *data)
{
	struct disk_data *dd = data;

	msg("CS161 disk rev %d", DISK_REVISION);
	msg("    Paranoid flag: %s", dd->dd_paranoid ? "ON" : "off");
	msg("    Tracks: %lu  Total sectors: %lu  RPM: %lu",
	    (unsigned long) dd->dd_tracks,
	    (unsigned long) dd->dd_totsectors,
	    (unsigned long) dd->dd_rpm);
	msg("    Current track: %d  [arrived: %lu.%09lu]",
	    dd->dd_current_track,
	    (unsigned long) dd->dd_trackarrival_secs,
	    (unsigned long) dd->dd_trackarrival_nsecs);
	msg("    Status: try %d, code %d, %s", 
	    dd->dd_worktries,
	    dd->dd_iostatus,
	    dd->dd_timedop ? "event in progress" : "idle");
	msg("    Registers: status 0x%08lx  sector 0x%08lx", 
	    (unsigned long) dd->dd_stat,
	    (unsigned long) dd->dd_sect);

	msg("    Transfer buffer:");
	dohexdump(dd->dd_buf, sizeof(dd->dd_buf));
}

const struct lamebus_device_info disk_device_info = {
	LBVEND_CS161,
	LBVEND_CS161_DISK,
	DISK_REVISION,
	disk_init,
	disk_fetch,
	disk_store,
	disk_dumpstate,
	disk_cleanup,
};
