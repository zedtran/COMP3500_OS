# Automatically generated file - do not edit here
include defs.mk
include cpu.mk
include $S/version.mk

all: $(PROG)

include rules.mk
include depend.mk

CFLAGS+=-I$S/include -I.
SRCFILES+=bus     lamebus.c boot.c \
                  dev_disk.c dev_emufs.c dev_net.c dev_random.c \
                  dev_screen.c dev_serial.c dev_timer.c dev_trace.c \
          gdb     gdb_fe.c gdb_be.c \
          main    main.c onsel.c clock.c console.c \
                  prof.c meter.c trace.c util.c

tidy:
	(find $S -name '*~' -print | xargs rm -f)

distclean clean: #tidy
	rm -f *.o $(PROG)

rules:
	@echo Making rules...
	@echo $(SRCFILES) | $S/makerules.sh > rules.mk

depend:
	$(MAKE) rules
	$(MAKE) realdepend

realdepend:
	$(CC) $(CFLAGS) $(DEPINCLUDES) -MM $(SRCS) > depend.mk

install:
	[ -d "$(INSTALLDIR)" ] || mkdir -p $(INSTALLDIR)
	$S/installit.sh "$(INSTALLDIR)" "$(PROG)" "$(VERSION)"

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -lm -o $(PROG)
