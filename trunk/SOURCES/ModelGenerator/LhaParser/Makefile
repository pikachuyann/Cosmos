
all:
	$(BISON) -dv Lha-parser.yy -p lha
	$(FLEX) --prefix=lha Lha-scanner.ll

clean:
	rm *.tab.cc *.hh *.output lex.lha.c