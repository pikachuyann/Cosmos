bin_SCRIPTS = prism2SPT

PACKAGES = 
LIBS     = 

prism2SPT: generator.ml lexer.mll parser.mly type.ml
	cd $(srcdir); ocamlbuild -cflags -I,+xml-light,-I,+zip -lflags -I,+xml-light,-I,+zip/ -libs unix,xml-light,zip,Str prism2SPT.native
	cp $(srcdir)/prism2SPT.native prism2SPT

EXTRA_DIST = DataFile.ml PetriNet.ml StochasticPetriNet.ml data.ml generator.ml  pnmlparser.ml prism2SPT.ml prismType.ml simulinkType.ml simulinkparser.ml type.ml parser.mly parserSimulEdge.mly lexer.mll lexerSimulEdge.mll


CLEANFILES = _build/* $(bin_SCRIPTS) *~

