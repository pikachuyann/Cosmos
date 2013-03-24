OBJPATH=../../Obj/Cosmos
BINPATH=../../bin
OPTIONS2= -Wno-deprecated $(OPTIONS) 

CLASSES= $(OBJPATH)/BatchR.o \
	$(OBJPATH)/LHA_orig.o \
	$(OBJPATH)/Event.o \
	$(OBJPATH)/EventsQueue.o \
	$(OBJPATH)/Simulator.o \
	$(OBJPATH)/stateSpace.o \
	$(OBJPATH)/numericalSolver.o \
	$(OBJPATH)/numSolverBB.o \
    $(OBJPATH)/numSolverSH.o \
    $(OBJPATH)/foxglynn.o \
	$(OBJPATH)/clientsim.o \
	$(OBJPATH)/SimulatorRE.o \
	$(OBJPATH)/SimulatorBoundedRE.o \
	$(OBJPATH)/SimulatorContinuousBounded.o



$(OBJPATH)/%.o: %.cpp
	$(CXX) -I$(BOOSTPATH) $(OPTIONS2) -c $(abspath $*.cpp) -o $(abspath $@)

$(OBJPATH)/%.o: %.c
	$(CXX) $(OPTIONS) -c $(abspath $*.c) -o $(abspath $@)

.PHONY: clean

$(BINPATH)/libClientSim.a: $(CLASSES)
	$(AR) $(ARFLAGS) $(BINPATH)/libClientSim.a $(CLASSES)

$(BINPATH)/ClientSim: $(OBJPATH)/spn.o $(OBJPATH)/LHA.o $(CLASSES)
	$(GXX) -I /usr/local/include $(OPTIONS) $^ -o $@

clean:
	rm -rf $(OBJPATH)
	rm $(BINPATH)/libClientSim.a
	