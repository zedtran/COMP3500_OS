VPATH = /home/blakedonzac/cs161/cs161-gdb-1.5/./gdb-6.6+cs161/gdb/testsuite/gdb.trace
srcdir = /home/blakedonzac/cs161/cs161-gdb-1.5/./gdb-6.6+cs161/gdb/testsuite/gdb.trace

.PHONY: all clean mostlyclean distclean realclean

all info install-info dvi install uninstall installcheck check:
	@echo "Nothing to be done for $@..."

clean mostlyclean:
	-rm -f actions circ collection limits
	-rm -f *.o *.diff *~ *.bad core sh3 hppa mn10300

distclean maintainer-clean realclean: clean
	-rm -f Makefile config.status config.log
