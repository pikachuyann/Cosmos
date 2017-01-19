
lib_LTLIBRARIES = libClientSim.la libClientSimMain.la

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
	clientsim.cpp

libClientSimMain_la_SOURCES = main.cpp

includes_HEADERS = LHA.hpp marking.hpp spn.hpp Polynome.hpp markingTemplate.hpp DistributionDef.hpp \
	timeGen.hpp Event.hpp EventsQueue.hpp BatchR.hpp EventsQueueSet.hpp \
	Simulator.hpp SimulatorRE.hpp SimulatorBoundedRE.hpp SimulatorContinuousBounded.hpp stateSpace.hpp numericalSolver.hpp \
	foxglynn.hpp numSolverBB.hpp numSolverSH.hpp\
	MarkovChain.hpp SPNBase.hpp \
	LHA_orig.hpp NLHA.hpp clientsim.hpp
includesdir = $(includedir)

AM_LDFLAGS = $(PTHREAD_LIBS)
AM_CPPFLAGS = $(BOOST_CPPFLAGS)
