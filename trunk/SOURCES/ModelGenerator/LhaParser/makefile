
all:
	/opt/local/bin/bison -dv Lha-parser.yy -p lha
	/opt/local/bin/flex --prefix=lha Lha-scanner.ll

clean:
	rm *.tab.cc *.hh *.output lex.lha.c