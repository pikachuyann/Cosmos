bin_SCRIPTS = modelConvert

#modelConvert: generator.ml lexer.mll parser.mly type.ml
#	cd $(srcdir); $(OCAMLBUILD) -libs unix,str prism2SPT.native
#	cp $(srcdir)/prism2SPT.native modelConvert

modelConvert: DataFile.ml PetriNet.ml StochasticPetriNet.ml generator.ml  pnmlparser.ml prism2SPT.ml prismType.ml stateflowType.ml simulinkparser.ml stateflowparser.ml type.ml parserPrism.mly parserSimulEdge.mly lexerPrism.mll lexerSimulEdge.mll prelexer.mll preparser.mly modelConvert.ml simulinkTrans.ml prism2SPT.ml ClessParser/cless_ast.ml _tags
	cd $(srcdir); $(OCAMLBUILD) -use-ocamlfind -I ClessParser prism2SPT.native modelConvert.native
	cp $(srcdir)/modelConvert.native modelConvert

EXTRA_DIST = DataFile.ml PetriNet.ml StochasticPetriNet.ml generator.ml pnmlparser.ml\
	prism2SPT.ml prismType.ml stateflowType.ml simulinkparser.ml stateflowparser.ml simulinkTrans.ml\
	stateflowTrans.ml\
	type.ml parserPrism.mly parserSimulEdge.mly lexerPrism.mll lexerSimulEdge.mll\
	prelexer.mll preparser.mly StochPTPrinter.ml GrMLParser.ml \
	ClessParser/cless_ast.ml  ClessParser/cless.ml ClessParser/cless.mli ClessParser/cless_lexer.mll ClessParser/cless_parser.mly\
	Simulation.ml SemanticPT.ml cless2PT.ml \
	modelConvert.ml _tags build.sh

CLEANFILES = _build/* $(bin_SCRIPTS) *~

