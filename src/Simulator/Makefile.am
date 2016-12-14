
lib_LTLIBRARIES = libClientSim.la

libClientSim_la_SOURCES = \
	BatchR.cpp BatchR.hpp \
	Event.cpp  Event.hpp \
	EventsQueueSet.cpp EventsQueueSet.hpp \
	EventsQueue.cpp EventsQueue.hpp \
	timeGen.cpp timeGen.hpp \
	marking.hpp spn.hpp \
    SPNBase.cpp SPNBase.hpp \
    LHA_orig.cpp LHA_orig.hpp \
    LHA.hpp \
    NLHA.cpp NLHA.hpp \
	Simulator.cpp Simulator.hpp \
	SimulatorRE.cpp SimulatorRE.hpp \
	sparse_io.hpp \
	stateSpace.cpp stateSpace.hpp \
	numericalSolver.cpp numericalSolver.hpp \
	numSolverBB.cpp numSolverBB.hpp \
	numSolverSH.cpp  numSolverSH.hpp \
	SimulatorBoundedRE.cpp SimulatorBoundedRE.hpp \
	foxglynn.cpp foxglynn.hpp \
	SimulatorContinuousBounded.cpp SimulatorContinuousBounded.hpp \
    MarkovChain.cpp MarkovChain.hpp \
	clientsim.cpp

includes_HEADERS = LHA.hpp marking.hpp spn.hpp Polynome.hpp markingTemplate.hpp DistributionDef.hpp
includesdir = $(includedir)

AM_LDFLAGS = $(PTHREAD_LIBS)
AM_CPPFLAGS = $(BOOST_CPPFLAGS)
