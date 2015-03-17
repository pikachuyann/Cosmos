
noinst_PROGRAMS = ClientSim2 gtest

# ClientSim1_SOURCES = \
	../src/Simulator/BatchR.cpp \
	../src/Simulator/EventsQueue.hpp ../src/Simulator/macro.h ../src/Simulator/numSolverBB.cpp ../src/Simulator/SimulatorContinuousBounded.cpp ../src/Simulator/sparse_io.hpp ../src/Simulator/BatchR.hpp ../src/Simulator/foxglynn.cpp ../src/Simulator/numSolverBB.hpp ../src/Simulator/SimulatorContinuousBounded.hpp ../src/Simulator/spn.hpp ../src/Simulator/clientsim.cpp ../src/Simulator/foxglynn.hpp ../src/Simulator/numSolverSH.cpp ../src/Simulator/Simulator.cpp ../src/Simulator/stateSpace.cpp ../src/Simulator/Event.cpp ../src/Simulator/LHA.hpp ../src/Simulator/marking.hpp ../src/Simulator/numSolverSH.hpp ../src/Simulator/Simulator.hpp ../src/Simulator/stateSpace.hpp ../src/Simulator/Event.hpp ../src/Simulator/LHA_orig.cpp ../src/Simulator/numericalSolver.cpp ../src/Simulator/SimulatorBoundedRE.cpp ../src/Simulator/SimulatorRE.cpp ../src/Simulator/EventsQueue.cpp ../src/Simulator/numericalSolver.hpp ../src/Simulator/SimulatorBoundedRE.hpp ../src/Simulator/SimulatorRE.hpp LHA.cpp markingImpl.hpp spn.cpp


spn.cpp:
	../src/ModelGenerator/Cosmos $(srcdir)/../Examples/Hospital/Hospital.grml --loop 100000 --max-run 0 --tmp-status 2
	cp tmp/spn.cpp ./
	cp tmp/LHA.cpp ./
	cp tmp/markingImpl.hpp ./

LHA.cpp: spn.cpp
markingImpl.hpp: spn.cpp

BUILT_SOURCES = LHA.cpp markingImpl.hpp spn.cpp

ClientSim2_SOURCES = LHA.cpp markingImpl.hpp spn.cpp

ClientSim2_LDADD = ../src/Simulator/libClientSim.la

ClientSim2_CPPFLAGS = -Wno-unused-const-variable -Wno-unused-parameter -I$(srcdir)/../src/Simulator

gtest_SOURCES = \
	src/gtest-all.cc src/gtest-death-test.cc src/gtest-filepath.cc src/gtest-internal-inl.h src/gtest-port.cc src/gtest-printers.cc src/gtest-test-part.cc src/gtest-typed-test.cc src/gtest.cc src/gtest_main.cc \
	include/gtest/gtest-death-test.h include/gtest/gtest-message.h include/gtest/gtest-param-test.h include/gtest/gtest-param-test.h.pump include/gtest/gtest-printers.h include/gtest/gtest-spi.h include/gtest/gtest-test-part.h include/gtest/gtest-typed-test.h include/gtest/gtest.h include/gtest/gtest_pred_impl.h include/gtest/gtest_prod.h include/gtest/internal/gtest-death-test-internal.h include/gtest/internal/gtest-filepath.h include/gtest/internal/gtest-internal.h include/gtest/internal/gtest-linked_ptr.h include/gtest/internal/gtest-param-util-generated.h include/gtest/internal/gtest-param-util-generated.h.pump include/gtest/internal/gtest-param-util.h include/gtest/internal/gtest-port.h include/gtest/internal/gtest-string.h include/gtest/internal/gtest-tuple.h include/gtest/internal/gtest-tuple.h.pump include/gtest/internal/gtest-type-util.h include/gtest/internal/gtest-type-util.h.pump \
	sample1.cc \
	sample1_unittest.cc

AM_CPPFLAGS =  -I$(srcdir)/include/gtest/internal/ -I$(srcdir)/include -isystem -I$(srcdir)/include $(BOOST_CPPFLAGS) $(PTHREAD_CFLAGS)

AM_LDFLAGS = $(PTHREAD_CFLAGS)

AUTOMAKE_OPTIONS = subdir-objects
