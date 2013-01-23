
 
	
all: Eval-parser.tab.cc lex.eval.c

%.tab.cc: %.yy
	$(BISON) -dv $*.yy -p eval
	
lex.eval.c: Eval-parser.tab.cc Eval-scanner.ll
	$(FLEX) --prefix=eval Eval-scanner.ll

clean:
	rm *.tab.cc *.hh *.output lex.eval.c