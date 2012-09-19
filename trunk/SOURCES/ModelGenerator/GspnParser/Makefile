
all:
	/opt/local/bin/bison -dv Gspn-parser.yy -p gspn
	/opt/local/bin/flex  --prefix=gspn Gspn-scanner.ll

clean:
	rm *.tab.cc *.hh *.output lex.lha.c