
lib_LTLIBRARIES = libClientSim.la libClientSimLight.la

libClientSim_la_SOURCES = \
	BatchR.cpp BatchR.hpp \
	Event.cpp  Event.hpp \
	EventsQueue.cpp EventsQueue.hpp \
	timeGen.cpp timeGen.hpp \
	marking.hpp spn.hpp \
	LHA_orig.cpp LHA.hpp \
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

libClientSimLight_la_SOURCES = \
    Event.cpp  Event.hpp \
    EventsQueue.cpp EventsQueue.hpp \
    marking.hpp spn.hpp \
    SimLight.cpp SimLight.hpp \
    clientsimLight.cpp

includes_HEADERS = LHA.hpp marking.hpp spn.hpp
includesdir = $(includedir)

AM_LDFLAGS = $(PTHREAD_LIBS)
AM_CPPFLAGS = $(BOOST_CPPFLAGS)