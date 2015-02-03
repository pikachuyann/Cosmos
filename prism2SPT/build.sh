#!/bin/bash

rm -rf tmp
ocamlbuild -use-ocamlfind -pp "camlp4o pa_macro.cmo -DHAS_XML -DHAS_ZIP" prism2SPT.native modelConvert.native
cp modelConvert.native ../bin/modelConvert
