export CC=g++
export OPTIONS= -O3 -Wall -Wextra
export BOOSTPATH=/data/usr64/include
export BISON=/opt/local/bin/bison
export FLEX=/opt/local/bin/flex


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

package: generator
	mkdir package
	mkdir package/bin
	mkdir -p package/Obj/Cosmos
#	mkdir -p package/Obj/ModelGenerator
#	mkdir -p package/SOURCES/Cosmos
	mkdir -p package/Obj/ModelGenerator/Eval
	mkdir -p package/Obj/ModelGenerator/GspnParser
	mkdir -p package/Obj/ModelGenerator/LhaParser
#	cp bin/Cosmos package/bin/
#	cp -r SOURCES package/
	svn export SOURCES package/SOURCES
	find package/SOURCES -name "*.yy" -delete
	find package/SOURCES -name "*.ll" -delete
	cp SOURCES/Cosmos/lumpingfuntriv.cpp package/SOURCES/Cosmos/lumpingfun.cpp
	cp Makefile package/
	cp cosmosTool package/
	cp Readme.txt package/
	cp COPYING package/
	cp Examples/RareEventUnbounded/mu_table package/
	@(cd package && $(MAKE) all)
	rm -rf package/Obj/ModelGenerator
#	cd package && zip -r ../cosmosService-0.9.zip *
#	rm -rf package

packagemac: package
	mv cosmosService-0.9.zip cosmosService-0.9-darwin.zip

packagelinux32: package
	mv cosmosService-0.9.zip cosmosService-0.9-linux32.zip

packagelinux64: package
	mv cosmosService-0.9.zip cosmosService-0.9-linux64.zip
