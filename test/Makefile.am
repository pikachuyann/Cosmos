
noinst_PROGRAMS = ClientSim2

# ClientSim1_SOURCES = \
	../src/Simulator/BatchR.cpp \
	../src/Simulator/EventsQueue.hpp ../src/Simulator/macro.h ../src/Simulator/numSolverBB.cpp ../src/Simulator/SimulatorContinuousBounded.cpp ../src/Simulator/sparse_io.hpp ../src/Simulator/BatchR.hpp ../src/Simulator/foxglynn.cpp ../src/Simulator/numSolverBB.hpp ../src/Simulator/SimulatorContinuousBounded.hpp ../src/Simulator/spn.hpp ../src/Simulator/clientsim.cpp ../src/Simulator/foxglynn.hpp ../src/Simulator/numSolverSH.cpp ../src/Simulator/Simulator.cpp ../src/Simulator/stateSpace.cpp ../src/Simulator/Event.cpp ../src/Simulator/LHA.hpp ../src/Simulator/marking.hpp ../src/Simulator/numSolverSH.hpp ../src/Simulator/Simulator.hpp ../src/Simulator/stateSpace.hpp ../src/Simulator/Event.hpp ../src/Simulator/LHA_orig.cpp ../src/Simulator/numericalSolver.cpp ../src/Simulator/SimulatorBoundedRE.cpp ../src/Simulator/SimulatorRE.cpp ../src/Simulator/EventsQueue.cpp ../src/Simulator/numericalSolver.hpp ../src/Simulator/SimulatorBoundedRE.hpp ../src/Simulator/SimulatorRE.hpp LHA.cpp markingImpl.hpp spn.cpp

ClientSim2_SOURCES = LHA.cpp markingImpl.hpp spn.cpp

ClientSim2_LDADD = ../src/Simulator/libClientSim.la

AM_CPPFLAGS = -I$(srcdir)/../src/Simulator $(BOOST_CPPFLAGS)
