bin_SCRIPTS = linecombinator sptToPt ptToSpt sptToSwn readserial

PACKAGES = 
LIBS     = 

linecombinator: linecombinator.ml readserial.ml
	cd $(srcdir); $(OCAMLBUILD) -libs str,unix linecombinator.native readserial.native
	cp $(srcdir)/linecombinator.native linecombinator
	cp $(srcdir)/readserial.native readserial

EXTRA_DIST = linecombinator.ml sptToPt ptToSpt mlcall.ml sptToSwn readserial.ml

CLEANFILES = _build/* $(bin_SCRIPTS) *~

