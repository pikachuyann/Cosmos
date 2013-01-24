
all: Lha-parser.tab.cc lex.lha.c

%.tab.cc: %.yy
	$(BISON) -dv $*.yy -p lha
	
lex.lha.c: Lha-parser.tab.cc Lha-scanner.ll
	$(FLEX) --prefix=lha Lha-scanner.ll

clean:
	rm *.tab.cc *.hh *.output lex.lha.c