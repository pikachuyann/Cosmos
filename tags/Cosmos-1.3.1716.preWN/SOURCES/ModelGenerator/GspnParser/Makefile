 
	
all: Gspn-parser.tab.cc lex.gspn.c

%.tab.cc: %.yy
	$(BISON) -dv $*.yy -p gspn
	
lex.gspn.c: Gspn-parser.tab.cc Gspn-scanner.ll
	$(FLEX) --prefix=gspn Gspn-scanner.ll

clean:
	rm *.tab.cc *.hh *.output lex.gspn.c