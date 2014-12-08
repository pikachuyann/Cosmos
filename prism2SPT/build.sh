rm -rf tmp
ocamlbuild -cflags -I,+xml-light,-I,/Users/barbot/.opam/system/lib/zip -lflags -I,+xml-light,-I,/Users/barbot/.opam/system/lib/zip/ -libs unix,xml-light,zip,Str prism2SPT.native
