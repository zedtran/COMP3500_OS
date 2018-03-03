#!/bin/sh
#
# toolbuild.sh - script for building cs161 toolchain component
# usage: ./toolbuild.sh [--cs161dir=CS161DIR] [--help]
#
# notice: build binutils first, then gcc, then gdb.

PKG=gdb
VER=6.6+cs161
TARGET=mips-elf
CFGARGS=
PROGS='gdb'

PKGDIR=${PKG}-${VER}

############################################################

# Default 161 dir
CS161DIR=$HOME/cs161

# Default make
#
# This allows you to set MAKE in the environment if for some reason you
# need to use a different make.
#
if [ "x$MAKE" = "x" ]; then
    MAKE=make
    export MAKE
fi

############################################################

while [ "x$1" != x ]; do
    case "$1" in
	--help)
cat <<EOF
Usage: toolbuild.sh [--cs161dir=CS161DIR]
  CS161DIR is the dir CS161 stuff goes in. The default is ~/cs161.
  The tools will go in CS161DIR/tools, and symbolic links will be placed in
  CS161DIR/bin.

  Note that this directory gets compiled in; moving the tools requires a
  recompile.
EOF
	    exit
	    ;;
	--cs161dir=*|--CS161dir=*|--CS161DIR=*|--os161dir=*|--OS161dir=*|--OS161DIR=*)
	    CS161DIR=`echo $1 | sed 's,^[^=]*=,,'`
	    ;;
	*)
	    echo "$0: Unknown option $1 (try --help)"
	    exit 1
	    ;;
    esac
shift
done

##############################

echo -n "Checking directory... "
case "$CS161DIR" in
    /*) ;;
    *)
	echo "invalid"
	echo "$0: CS161 dir $CS161DIR is not an absolute path"
	exit 1
	;;
esac
echo "$CS161DIR"

PREFIX="$CS161DIR/tools"

if [ "$PKG" = gcc ]; then
    if [ ! -x ${PREFIX}/bin/mips-linux-as ]; then
	echo "$0: I don't see ${PREFIX}/bin/mips-linux-as"
	echo "$0: Install binutils before gcc"
	exit 1
    fi
fi

##############################

echo -n "Checking where the files are... "

SRCDIR=
for DISTDIR in `echo $0 | sed 's,[^/]*$,,;s,/$,,;s,^$,.,'` . ..; do
    case "$DISTDIR" in
	/*) ;;
	*) DISTDIR="`pwd`/$DISTDIR";;
    esac

    if [ -d "$DISTDIR/$PKGDIR" ]; then
	SRCDIR="$DISTDIR/$PKGDIR"
	break;
    fi
done

if [ "x$SRCDIR" = x ]; then
    echo "missing"
    echo "Cannot find the distribution files."
    echo "Run $0 out of the same directory the rest of the files are in."
    exit 1
fi

echo "$SRCDIR"

##############################

if [ "$PKG" = gcc ]; then
    echo -n "Checking your make... "

    awk 'BEGIN {
	printf "wrong:\n";
	printf "\t@echo wrong\n";
	printf "\t@false\n";

	printf "%%.muck: %%.mk\n";
	printf "\t@echo p $@ q\n";
    }' > conftest.mk

    T=`($MAKE -f conftest.mk conftest.muck) 2>&1`
    if [ $? != 0 -o -f conftest.muck -o "$T" != "p conftest.muck q" ]; then
	echo "broken or not GNU make"
	echo "gcc4 requires GNU make to build (this is not my fault)"
	echo "Set the MAKE environment variable to name a copy of GNU make."
	exit 1
    fi

    rm -f conftest.mk conftest.muck
    echo 'ok'
fi

############################################################

#
# gcc 3.0.3, and also 3.2.1, won't build unless mips-linux-ar is in
# the path.
#
# This is still true in 4.1.2 - don't they ever test these things?
#
PATH="${PATH}:${PREFIX}/bin"
export PATH

############################################################

for DIR in "$CS161DIR" "$CS161DIR/bin" "$PREFIX"; do
    if [ ! -d "$DIR" ]; then
	echo "Making directory: $DIR"
	mkdir "$DIR" || exit 1
    fi
done

echo "******** Configuring $PKG ********"
"${SRCDIR}/configure" --target=${TARGET} ${CFGARGS} \
    --prefix="$PREFIX" || exit 1

echo "******** Compiling $PKG ********"
$MAKE || exit 1

echo "******** Installing $PKG ********"
$MAKE install || exit 1

echo "******** Creating symlinks ********"

BINDIR="$CS161DIR/bin"
for P in $PROGS; do
    rm -f "$BINDIR"/cs161-$P
    ln -s ../tools/bin/${TARGET}-$P "$BINDIR"/cs161-$P
    echo -n "$P "
done
echo

echo "******** Done ********"
