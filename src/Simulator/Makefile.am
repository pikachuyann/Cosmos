
lib_LTLIBRARIES = libClientSim.la libClientSimMain.la libClientSimBase.la

libClientSim_la_SOURCES = \
	timeGenBis.cpp timeGenBis.hpp \
	spn.hpp \
	EventsQueueSet.cpp EventsQueueSet.hpp \
	SPNBase.cpp SPNBase.hpp \
	NLHA.cpp NLHA.hpp \
	RareEvents/SimulatorRE.cpp RareEvents/SimulatorRE.hpp \
	sparse_io.hpp \
	stateSpace.cpp stateSpace.hpp \
	RareEvents/numericalSolver.cpp RareEvents/numericalSolver.hpp \
	RareEvents/numSolverBB.cpp RareEvents/numSolverBB.hpp \
	RareEvents/numSolverSH.cpp  RareEvents/numSolverSH.hpp \
	RareEvents/SimulatorBoundedRE.cpp RareEvents/SimulatorBoundedRE.hpp \
	RareEvents/foxglynn.cpp RareEvents/foxglynn.hpp \
	RareEvents/SimulatorContinuousBounded.cpp RareEvents/SimulatorContinuousBounded.hpp \
        Simulink/SKTime.cpp Simulink/SKTime.hpp \
	InstanceSPNSim.cpp RareEvents/InstanceSPNSimRE.cpp

libClientSimMain_la_SOURCES = \
	timeGenBis.cpp timeGenBis.hpp \
	spn.hpp \
	SPNBase.hpp \
	main.cpp
	
libClientSimBase_la_SOURCES = \
	BatchR.cpp BatchR.hpp \
	Event.cpp  Event.hpp \
	EventsQueue.cpp EventsQueue.hpp \
	timeGen.cpp timeGen.hpp \
	marking.hpp \
	LHA_orig.cpp LHA_orig.hpp \
	LHA.hpp \
	Simulator.cpp Simulator.hpp \
    clientsim.cpp

includesdir = $(includedir)
includes_HEADERS = LHA.hpp marking.hpp spn.hpp Polynome.hpp markingTemplate.hpp DistributionDef.hpp \
	timeGen.hpp timeGenBis.hpp Event.hpp EventsQueue.hpp BatchR.hpp EventsQueueSet.hpp \
	Simulator.hpp stateSpace.hpp MarkovChain.hpp SPNBase.hpp \
	LHA_orig.hpp NLHA.hpp clientsim.hpp \
        Simulink/SKTime.hpp

otherincludedir = $(includedir)/RareEvents
otherinclude_HEADERS = RareEvents/numericalSolver.hpp \
	RareEvents/foxglynn.hpp RareEvents/numSolverBB.hpp RareEvents/numSolverSH.hpp\
	RareEvents/SimulatorRE.hpp RareEvents/SimulatorBoundedRE.hpp RareEvents/SimulatorContinuousBounded.hpp


AM_LDFLAGS = $(PTHREAD_LIBS)
AM_CPPFLAGS = -Wall -Wextra -Wno-unused-local-typedef  -Wno-unused-parameter $(BOOST_CPPFLAGS) 
