#!/bin/zsh

mkdir -p ../bin
rm -rf tmp
ocamlbuild -use-ocamlfind -j 4 -pp "camlp4o pa_macro.cmo -DHAS_XML -DHAS_ZIP" prism2SPT.native modelConvert.native parserUnparseAttribute.native
cd _build
ocamlmktop type.cmo PetriNet.cmo StochPTPrinter.cmo StochasticPetriNet.cmo -o petriscript
cd ..


cp modelConvert.native ../bin/modelConvert

