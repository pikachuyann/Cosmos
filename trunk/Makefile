export CC=g++
export OPTIONS= -O3 -Wall -arch i386 -arch x86_64
export BOOSTPATH=/data/usr64/include
export BISON=/opt/local/bin/bison
export FLEX=/opt/local/bin/flex

export AR=libtool
export ARFLAGS=-static -o

files=find SOURCES -type f | grep "\(.cpp\|.hpp\|.c\|.h\|Makefile\)$$"

.PHONY: lib generator clean sim dir

all: dir lib generator 

dir:
	mkdir -p bin
	mkdir -p Obj/Cosmos
	mkdir -p Obj/ModelGenerator/Eval
	mkdir -p Obj/ModelGenerator/GspnParser
	mkdir -p Obj/ModelGenerator/LhaParser

lib:
	@(cd SOURCES/Cosmos && $(MAKE) ../../bin/libClientSim.a)

generator:
	@(cd SOURCES/ModelGenerator && $(MAKE) ../../bin/Cosmos)

clean:
	@(cd SOURCES/Cosmos && $(MAKE) $@)
	@(cd SOURCES/ModelGenerator && $(MAKE) $@)
	@(rm -rf package-alligator.zip)
#	@(rm -rf package)

cleansim:
	@(cd SOURCES/Cosmos && $(MAKE) clean)

sim:
	@(cd SOURCES/Cosmos && $(MAKE) ../../bin/ClientSim)

parser:
	@(cd SOURCES/ModelGenerator && $(MAKE) parser)

cleanparser:
	@(cd SOURCES/ModelGenerator && $(MAKE) cleanparser)