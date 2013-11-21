SUBDIRS = src/libgrml src/ModelGenerator/Eval src/ModelGenerator/GspnParser src/ModelGenerator/LhaParser src/ModelGenerator src/Simulator test automataGen utils

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = Examples/Makefile Examples/testTeamCity.ml\
	Examples/TandemQN/test.ml Examples/TandemQN/tqn.gspn Examples/TandemQN/tqn.lha\
	Examples/pi/test.ml Examples/pi/pi.grml Examples/pi/pilha.grml \
	Examples/testDistribution/test.ml Examples/testDistribution/test.ml \
	Examples/testDistribution/testdeterministic.grml \
	Examples/testDistribution/testdiscreteuniform.grml \
	Examples/testDistribution/testdistrib.grml \
	Examples/testDistribution/testdistrib.lha \
	Examples/testDistribution/testerlang.grml \
	Examples/testDistribution/testexponential.grml \
	Examples/testDistribution/testgamma.grml \
	Examples/testDistribution/testgeometric.grml \
	Examples/testDistribution/testlognormal.grml \
	Examples/testDistribution/testtriangle.grml \
	Examples/testDistribution/testuniform.grml \
	Examples/Workflow-Net/test.ml \
	Examples/Workflow-Net/workflow-out-1-imm.gspn \
	Examples/Workflow-Net/workflow-out-1-imm.lha \
	Examples/Workflow-Net/workflow-out-1.gspn \
	Examples/Workflow-Net/workflow-out-2-imm.gspn \
	Examples/Workflow-Net/workflow-out-2.gspn \
	Examples/Workflow-Net/workflow-out-3-imm.gspn \
	Examples/Workflow-Net/workflow-out-3.gspn \
	Examples/Workflow-Net/workflow-out-4-imm.gspn \
	Examples/Workflow-Net/workflow-out-4.gspn \
	Examples/Workflow-Net/workflow-out-5-imm.gspn \
	Examples/Workflow-Net/workflow-out-5.gspn \
	Examples/QueueMM1/InterArrival_Max/MM1.gspn \
	Examples/QueueMM1/InterArrival_Max/MM1.lha \
	Examples/QueueMM1/InterArrival_Mean/MM1.gspn \
	Examples/QueueMM1/InterArrival_Mean/MM1.lha \
	Examples/QueueMM1/ProbEmptySys/MM1.gspn \
	Examples/QueueMM1/ProbEmptySys/MM1.lha \
	Examples/QueueMM1/SystemLength/MM1.gspn \
	Examples/QueueMM1/SystemLength/MM1.lha \
	Examples/QueueMM1/test.ml \
	Examples/RareEventUnbounded/lumpingfun.cpp \
	Examples/RareEventUnbounded/tandem.grml \
	Examples/RareEventUnbounded/tandem.gspn \
	Examples/RareEventUnbounded/tandem.lha \
	Examples/RareEventUnbounded/tandemlha.grml \
	Examples/RareEventUnbounded/tandemRE.grml \
	Examples/RareEventUnbounded/tandemReduit.grml \
	Examples/RareEventUnbounded/tandemRElha.grml \
	Examples/RareEventUnbounded/test.ml \
	Examples/RareEventUnbounded/test2.ml \
	Examples/DataBase/database.grml \
	Examples/DataBase/databaselha.grml \
	Examples/DataBase/test.ml \
	Examples/TandemCosy/tandemPrism.grml \
	Examples/TandemCosy/tandemPrismlha.grml \
	Examples/TandemCosy/testPrism.ml \
	Examples/SharedMemory/sms_Unif.gspn \
	Examples/SharedMemory/sms_Unif.lha Examples/SharedMemory/test.ml \
	Examples/RareEventU/lumpingfun.cpp \
	Examples/RareEventU/tandem.gspn \
	Examples/RareEventU/tandem.lha \
	Examples/RareEventU/tandem_agr.gspn \
	Examples/RareEventU/tandem_agr.lha \
	Examples/RareEventU/test.ml \
	prism


AM_LDFLAGS = -lrt $(PTHREAD_LIBS)
AM_CPPFLAGS = $(BOOST_CPPFLAGS)


# AM_CPPFLAGS = $(BOOST_CPPFLAGS)
# LIBS = $(BOOST_THREAD_LIBS)