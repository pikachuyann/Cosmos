#!/bin/bash

mkdir -p ../bin
rm -rf tmp
#ocamlbuild -use-ocamlfind -j 4 -pp "camlp4o pa_macro.cmo -DHAS_XML -DHAS_ZIP" -I ClessParser prism2SPT.native modelConvert.native parserUnparseAttribute.native
ocamlbuild -use-ocamlfind -j 4 -I ClessParser -I Prism -I Semantics prism2SPT.native StochasticPetriNet.cmo modelConvert.native parserUnparseAttribute.native modelConvert.byte testSimulink.native
#cd _build
#ocamlmktop type.cmo prismType.cmo parserPrism.cmo lexerPrism.cmo PetriNet.cmo StochPTPrinter.cmo SemanticPT.cmo StochasticPetriNet.cmo -o petriscript
#cd ..

cp modelConvert.native ../bin/modelConvert
cp testSimulink.native ../bin/testSimulink

