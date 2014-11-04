bin_SCRIPTS = prism2spt

PACKAGES = 
LIBS     = 

prism2spt: generator.ml lexer.mll parser.mly type.ml
	cd $(srcdir); ocamlbuild generator.native
	cp $(srcdir)/generator.native prism2spt

EXTRA_DIST = generator.ml lexer.mll parser.mly type.ml petriNet.ml stochasticPetriNet.ml prism2SPT.ml

CLEANFILES = _build/* $(bin_SCRIPTS) *~

