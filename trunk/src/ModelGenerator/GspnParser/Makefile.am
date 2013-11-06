
noinst_LTLIBRARIES = libgspn.la

libgspn_la_SOURCES = \
	Gspn-Reader.cpp Gspn-Reader.hpp \
	Gspn-scanner.ll Gspn-parser.yy \
	Gspn_gmlparser.cpp Gspn_gmlparser.hpp

libgspn_la_LIBADD = ../../libgrml/libgrml.la ../Eval/libeval.la

BUILT_SOURCES = Gspn-parser.cc

AM_YFLAGS = -y -p gspn
AM_CPPFLAGS = -I$(srcdir)/../../libgrml -I../Eval -I$(srcdir)/../Eval
AM_LFLAGS = -o$(LEX_OUTPUT_ROOT).c --prefix=gspn
