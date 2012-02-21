export CC=g++
export OPTIONS=-O3
 
.PHONY: classes Generator clean sim

all: classes Generator 


classes:
	@(cd SOURCES/Cosmos && $(MAKE) $@)

Generator:
	@(cd SOURCES/ModelGenerator && $(MAKE) ../../bin/Cosmos)

clean:
	@(cd SOURCES/Cosmos && $(MAKE) $@)
	@(cd SOURCES/ModelGenerator && $(MAKE) $@)

cleansim:
	@(cd SOURCES/Cosmos && $(MAKE) clean)

sim:
	@(cd SOURCES/Cosmos && $(MAKE) ../../bin/ClientSim)
