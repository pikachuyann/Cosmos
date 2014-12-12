#!/bin/bash

rm -rf tmp
ocamlbuild -pp "camlp4o pa_macro.cmo -DHAS_XML -DHAS_ZIP" -cflags -I,+xml-light,-I,+zip -lflags -I,+xml-light,-I,+zip -libs unix,xml-light,zip,Str prism2SPT.native modelConvert.native
