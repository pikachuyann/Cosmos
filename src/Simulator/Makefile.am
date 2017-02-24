
lib_LTLIBRARIES = libClientSim.la libClientSimMain.la libClientSimBase.la

libClientSim_la_SOURCES = \
	timeGenBis.cpp timeGenBis.hpp \
	spn.hpp \
	SPNBase.cpp SPNBase.hpp \
	NLHA.cpp NLHA.hpp \
	SimulatorRE.cpp SimulatorRE.hpp \
	sparse_io.hpp \
	stateSpace.cpp stateSpace.hpp \
	numericalSolver.cpp numericalSolver.hpp \
	numSolverBB.cpp numSolverBB.hpp \
	numSolverSH.cpp  numSolverSH.hpp \
	SimulatorBoundedRE.cpp SimulatorBoundedRE.hpp \
	foxglynn.cpp foxglynn.hpp \
	SimulatorContinuousBounded.cpp SimulatorContinuousBounded.hpp \
	InstanceSPNSim.cpp InstanceSPNSimRE.cpp

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

includes_HEADERS = LHA.hpp marking.hpp spn.hpp Polynome.hpp markingTemplate.hpp DistributionDef.hpp \
	timeGen.hpp Event.hpp EventsQueue.hpp BatchR.hpp EventsQueueSet.hpp \
	Simulator.hpp SimulatorRE.hpp SimulatorBoundedRE.hpp SimulatorContinuousBounded.hpp stateSpace.hpp numericalSolver.hpp \
	foxglynn.hpp numSolverBB.hpp numSolverSH.hpp\
	MarkovChain.hpp SPNBase.hpp \
	LHA_orig.hpp NLHA.hpp clientsim.hpp

includesdir = $(includedir)

AM_LDFLAGS = $(PTHREAD_LIBS)
AM_CPPFLAGS = -Wall -Wextra -Wno-unused-local-typedef  -Wno-unused-parameter $(BOOST_CPPFLAGS) 
