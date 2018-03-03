# Automatically generated file - do not edit here
include defs.mk
include $S/version.mk

all: $(PROG)

include rules.mk
include depend.mk

CFLAGS+=-I.
SRCFILES+=nethub  array.c nethub.c

distclean clean:
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
