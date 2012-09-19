OBJPATH=../../Obj/ModelGenerator
BINPATH=../../bin
LIBGMLPATH=../libgml/

FILES= $(OBJPATH)/parameters.o \
    $(OBJPATH)/server.o \
    $(OBJPATH)/result.o \
	$(OBJPATH)/Cosmos.o \
	$(OBJPATH)/Eval/Eval-parser.tab.o \
	$(OBJPATH)/Eval/Eval.o \
	$(OBJPATH)/GspnParser/Gspn-parser.tab.o \
	$(OBJPATH)/GspnParser/Gspn-Reader.o \
	$(OBJPATH)/GspnParser/Gspn_gmlparser.o \
	$(OBJPATH)/LhaParser/Lha-Reader.o \
	$(OBJPATH)/LhaParser/Lha-parser.tab.o  \
	$(OBJPATH)/LhaParser/Lha_gmlparser.o  \
	$(OBJPATH)/../Cosmos/BatchR.o \
	$(OBJPATH)/expatmodelparser.o \
	$(OBJPATH)/modelwriter.o


$(OBJPATH)/%.o: %.cpp
	$(CC) -I../libgml/ -I$(BOOSTPATH) $(OPTIONS) -c $*.cpp -o $@	
$(OBJPATH)/%.o: %.cc
	$(CC) -I../libgml/ $(OPTIONS) -c $*.cc -o $@
$(OBJPATH)/%.o: $(LIBGMLPATH)/%.cc
	$(CC) $(OPTIONS) -c $(LIBGMLPATH)/$*.cc -o $@

$(BINPATH)/Cosmos: $(FILES) 
	$(CC) $(OPTIONS) -L/usr/lib/ -lexpat $^ -o $@

clean:
	@(cd LhaParser && $(MAKE) clean)
	@(cd GspnParser && $(MAKE) clean)
	rm $(OBJPATH)/Eval/*.o
	rm $(OBJPATH)/GspnParser/*.o
	rm $(OBJPATH)/LhaParser/*.o
	rm $(OBJPATH)/*.o
	rm $(BINPATH)/Cosmos
	rm $(BINPATH)/ClientSim	