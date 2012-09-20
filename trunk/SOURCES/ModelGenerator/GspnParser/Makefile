 
all:
	$(BISON) -dv Gspn-parser.yy -p gspn
	$(FLEX)  --prefix=gspn Gspn-scanner.ll

clean:
	rm *.tab.cc *.hh *.output lex.gspn.c