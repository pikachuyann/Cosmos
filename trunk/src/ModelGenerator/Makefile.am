
bin_PROGRAMS = Cosmos
Cosmos_SOURCES = \
	../Simulator/BatchR.cpp ../Simulator/BatchR.hpp \
	Eval/Eval.cpp Eval/Eval.hpp Eval/Eval-parser.tab.cc \
	Eval/Eval-parser.tab.hh Eval/location.hh Eval/position.hh Eval/stack.hh \
	GspnParser/Gspn-Reader.cpp GspnParser/Gspn-Reader.hpp \
	GspnParser/Gspn_gmlparser.cpp GspnParser/Gspn_gmlparser.hpp \
	GspnParser/Gspn-parser.tab.cc 	GspnParser/Gspn-parser.tab.hh \
	GspnParser/location.hh GspnParser/position.hh GspnParser/stack.hh \
	LhaParser/Lha-Reader.cpp LhaParser/Lha-Reader.hpp \
	LhaParser/Lha_gmlparser.cpp LhaParser/Lha_gmlparser.hpp \
	LhaParser/Lha-parser.tab.cc  LhaParser/Lha-parser.tab.hh \
	LhaParser/location.hh LhaParser/position.hh LhaParser/stack.hh \
	casesWriter.cpp casesWriter.hpp \
	parameters.cpp parameters.hpp \
	result.cpp result.hpp \
	server.cpp  server.hpp \
	HaslFormula.cpp HaslFormula.hpp \
	Cosmos.cpp

Cosmos_LDADD = ../libgrml/libgrml.la

AM_CPPFLAGS = -I$(srcdir)/../libgrml $(BOOST_CPPFLAGS)

AUTOMAKE_OPTIONS = subdir-objects