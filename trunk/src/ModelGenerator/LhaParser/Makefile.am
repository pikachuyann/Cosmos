
noinst_LTLIBRARIES = liblha.la

liblha_la_SOURCES = \
	Lha-Reader.cpp Lha-Reader.hpp \
	Lha-scanner.ll Lha-parser.yy \
	Lha_gmlparser.cpp Lha_gmlparser.hpp

BUILT_SOURCES = Lha-parser.cc

AM_YFLAGS = -y -p lha
AM_CPPFLAGS = -I$(srcdir)/../../libgrml -I../Eval -I$(srcdir)/../Eval -I../GspnParser -I$(srcdir)/../GspnParser
AM_LFLAGS = -o$(LEX_OUTPUT_ROOT).c --prefix=lha
