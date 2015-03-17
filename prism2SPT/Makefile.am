bin_SCRIPTS = modelConvert

#modelConvert: generator.ml lexer.mll parser.mly type.ml
#	cd $(srcdir); $(OCAMLBUILD) -libs unix,str prism2SPT.native
#	cp $(srcdir)/prism2SPT.native modelConvert

modelConvert: DataFile.ml PetriNet.ml StochasticPetriNet.ml generator.ml  pnmlparser.ml prism2SPT.ml prismType.ml simulinkType.ml simulinkparser.ml type.ml parser.mly parserSimulEdge.mly lexer.mll lexerSimulEdge.mll prelexer.mll preparser.mly modelConvert.ml simulinkTrans.ml prism2SPT.ml _tags
	cd $(srcdir); $(OCAMLBUILD) -use-ocamlfind -pp "camlp4o pa_macro.cmo -DHAS_XML -DHAS_ZIP" prism2SPT.native modelConvert.native
	cp $(srcdir)/modelConvert.native modelConvert

EXTRA_DIST = DataFile.ml PetriNet.ml StochasticPetriNet.ml generator.ml  pnmlparser.ml prism2SPT.ml prismType.ml simulinkType.ml simulinkparser.ml simulinkTrans.ml type.ml parser.mly parserSimulEdge.mly lexer.mll lexerSimulEdge.mll prelexer.mll preparser.mly modelConvert.ml _tags

CLEANFILES = _build/* $(bin_SCRIPTS) *~

