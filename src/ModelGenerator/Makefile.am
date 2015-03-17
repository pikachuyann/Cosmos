

bin_PROGRAMS = Cosmos
noinst_LTLIBRARIES = libeval.la libgspn.la liblha.la

Cosmos_SOURCES = \
	../Simulator/BatchR.cpp ../Simulator/BatchR.hpp \
	casesWriter.cpp casesWriter.hpp \
	parameters.cpp parameters.hpp \
	result.cpp result.hpp \
	server.cpp server.hpp \
	HaslFormula.cpp HaslFormula.hpp \
	Generator.cpp Generator.hpp \
    expressionStruct.cpp expressionStruct.hpp \
	Cosmos.cpp

Cosmos_LDADD = ../libgrml/libgrml.la libeval.la libgspn.la liblha.la

AM_CPPFLAGS = -I$(srcdir)/../libgrml -I$(srcdir)/Eval -I../libgrml -IEval -IGspnParser -ILhaParser $(BOOST_CPPFLAGS) $(PTHREAD_LIBS)

AUTOMAKE_OPTIONS = subdir-objects

AM_LDFLAGS = $(PTHREAD_LIBS)

BUILT_SOURCES = LhaParser/Lha-parser.cc GspnParser/Gspn-parser.cc Eval/Eval-parser.cc


libeval_la_SOURCES = Eval/Eval.cpp Eval/Eval.hpp Eval/Eval-scanner.ll Eval/Eval-parser.yy
libeval_AM_YFLAGS = -y -p eval
libeval_AM_LFLAGS = -oEval/$(LEX_OUTPUT_ROOT).c --prefix=eval


libgspn_la_SOURCES = \
	GspnParser/Gspn-Writer.cpp GspnParser/Gspn-Writer.hpp \
	GspnParser/Gspn-Reader.cpp GspnParser/Gspn-Reader.hpp \
	GspnParser/Gspn-scanner.ll GspnParser/Gspn-parser.yy \
	GspnParser/unfolder.cpp GspnParser/unfolder.hpp \
	GspnParser/Gspn_gmlparser.cpp GspnParser/Gspn_gmlparser.hpp
libgspn_la_LIBADD = ../libgrml/libgrml.la
libgspn_la_AM_YFLAGS = -y -p gspn
libgspn_la_AM_CPPFLAGS = -I$(srcdir)/../../libgrml -I../Eval -I$(srcdir)/../Eval
libgspn_la_AM_LFLAGS = -oGspnParser/$(LEX_OUTPUT_ROOT).c --prefix=gspn


liblha_la_SOURCES = \
	LhaParser/Lha-Reader.cpp LhaParser/Lha-Reader.hpp \
	LhaParser/Lha-scanner.ll LhaParser/Lha-parser.yy \
	LhaParser/Lha_gmlparser.cpp LhaParser/Lha_gmlparser.hpp
liblha_la_AM_YFLAGS = -y -p lha
liblha_la_AM_CPPFLAGS = -I$(srcdir)/../../libgrml -I../Eval -I$(srcdir)/../Eval -I../GspnParser -I$(srcdir)/../GspnParser
liblha_la_AM_LFLAGS = -oLhsParser$(LEX_OUTPUT_ROOT).c --prefix=lha
