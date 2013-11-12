bin_SCRIPTS = linecombinator sptToPt ptToSpt

PACKAGES = 
LIBS     = 

linecombinator: linecombinator.ml
	cd $(srcdir); ocamlbuild -lib Str linecombinator.native
	cp $(srcdir)/linecombinator.native linecombinator

EXTRA_DIST = linecombinator.ml

CLEANFILES = _build/* $(bin_SCRIPTS) *~

