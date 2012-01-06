OBJPATH=../../Obj/Cosmos
BINPATH=../../bin
OPTIONS2= -Wno-deprecated $(OPTIONS) 

CLASSES= $(OBJPATH)/BatchR.o \
	$(OBJPATH)/spn_orig.o \
	$(OBJPATH)/LHA_orig.o \
	$(OBJPATH)/Event.o \
	$(OBJPATH)/EventsQueue.o \
	$(OBJPATH)/tab.o \
	$(OBJPATH)/Simulator.o \
	$(OBJPATH)/SimulatorRE.o \
	$(OBJPATH)/SimulatorBoundedRE.o \
	$(OBJPATH)/stateSpace.o \
	$(OBJPATH)/numericalSolver.o \
	$(OBJPATH)/numSolverBB.o \
	$(OBJPATH)/clientsim.o


#$(OBJPATH)/Simulator.o: SimulatorRE.cpp

LHA.hpp:
	cat ../ModelGenerator/LHA_orig.hpp end.cpp > LHA.hpp
spn.hpp:
	cat ../ModelGenerator/spn_orig.hpp end.cpp > spn.hpp

$(OBJPATH)/%.o: %.cpp
	$(CC) $(OPTIONS2) -c $*.cpp -o $@	

.PHONY: classes clean

classes: SimulatorRE.cpp $(CLASSES)

$(BINPATH)/ClientSim: $(OBJPATH)/spn.o $(OBJPATH)/LHA.o $(CLASSES)
	$(CC) -I /usr/local/include -larmadillo -framework Accelerate $(OPTIONS) $^ -o $@

clean:
	rm $(OBJPATH)/*.o
#	rm spn.hpp
#	rm LHA.hpp
	rm LHA.cpp
	rm spn.cpp


server:
	$(CC) $(OPTIONS2) -c serversim.cpp -o $(OBJPATH)/serversim.o
	$(CC) $(OPTIONS2) $(OBJPATH)/serversim.o \
	-o $(BINPATH)/ServerSim
