bin_SCRIPTS = modelConvert

PACKAGES = 
LIBS     = 

modelConvert: generator.ml lexer.mll parser.mly type.ml
	cd $(srcdir); $(OCAMLBUILD) -libs unix,str prism2SPT.native
	cp $(srcdir)/prism2SPT.native modelConvert

EXTRA_DIST = DataFile.ml PetriNet.ml StochasticPetriNet.ml data.ml generator.ml  pnmlparser.ml prism2SPT.ml prismType.ml simulinkType.ml simulinkparser.ml type.ml parser.mly parserSimulEdge.mly lexer.mll lexerSimulEdge.mll


CLEANFILES = _build/* $(bin_SCRIPTS) *~

