bin_SCRIPTS = linecombinator sptToPt ptToSpt sptToSwn readserial.ml

PACKAGES = 
LIBS     = 

linecombinator: linecombinator.ml
	cd $(srcdir); $(OCAMLBUILD) -lib str linecombinator.native
	cp $(srcdir)/linecombinator.native linecombinator

EXTRA_DIST = linecombinator.ml sptToPt ptToSpt mlcall.ml sptToSwn

CLEANFILES = _build/* $(bin_SCRIPTS) *~

