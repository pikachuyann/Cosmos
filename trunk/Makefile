export CC=g++
export OPTIONS=-O3

.PHONY: classes generator clean sim

all: classes generator 

classes:
	@(cd SOURCES/Cosmos && $(MAKE) $@)

generator:
	@(cd SOURCES/ModelGenerator && $(MAKE) ../../bin/Cosmos)

clean:
	@(cd SOURCES/Cosmos && $(MAKE) $@)
	@(cd SOURCES/ModelGenerator && $(MAKE) $@)
	@(rm package-alligator.zip)
	@(rm -rf package)

cleansim:
	@(cd SOURCES/Cosmos && $(MAKE) clean)

sim:
	@(cd SOURCES/Cosmos && $(MAKE) ../../bin/ClientSim)

package: generator
	mkdir package
	mkdir package/bin
	mkdir package/Obj
	mkdir -p package/SOURCES/Cosmos
	cp bin/Cosmos package/bin/
	cp SOURCES/Cosmos/*.cpp package/SOURCES/Cosmos/
	cp SOURCES/Cosmos/*.hpp package/SOURCES/Cosmos/
	cp Makefile package/
	cp cosmosTool package/
	cp Readme.txt package/
	cp COPYING package/
	zip -r package-alligator.zip package