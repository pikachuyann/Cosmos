
bin_PROGRAMS = Cosmos
Cosmos_SOURCES = \
	../Simulator/BatchR.cpp ../Simulator/BatchR.hpp \
	../Simulator/sharedMemory.cpp ../Simulator/sharedMemory.hpp \
	casesWriter.cpp casesWriter.hpp \
	parameters.cpp parameters.hpp \
	result.cpp result.hpp \
	server.cpp server.hpp \
	HaslFormula.cpp HaslFormula.hpp \
	Cosmos.cpp

Cosmos_LDADD = ../libgrml/libgrml.la Eval/libeval.la GspnParser/libgspn.la LhaParser/liblha.la

AM_CPPFLAGS = -I$(srcdir)/../libgrml -I$(srcdir)/Eval -I../libgrml -IEval -IGspnParser -ILhaParser $(BOOST_CPPFLAGS) $(PTHREAD_LIBS)

AUTOMAKE_OPTIONS = subdir-objects

AM_LDFLAGS = -lrt $(PTHREAD_LIBS)