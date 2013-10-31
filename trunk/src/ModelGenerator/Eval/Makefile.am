
noinst_LTLIBRARIES = libeval.la
libeval_la_SOURCES = \
	Eval.cpp Eval.hpp \
	Eval-scanner.ll Eval-parser.yy

BUILT_SOURCES = Eval-parser.cc

AM_YFLAGS = -y -p eval
AM_LFLAGS = -o$(LEX_OUTPUT_ROOT).c --prefix=eval
