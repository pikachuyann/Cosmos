
all:
	$(BISON) -dv Eval-parser.yy -p eval
	$(FLEX) --prefix=eval Eval-scanner.ll

clean:
	rm *.tab.cc *.hh *.output lex.eval.c