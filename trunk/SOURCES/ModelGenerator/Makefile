OBJPATH=../../Obj/ModelGenerator
BINPATH=../../bin
LIBGMLPATH=../libgml/

FILES=$(OBJPATH)/server.o \
	$(OBJPATH)/mainGPP.o \
	$(OBJPATH)/Eval/Eval-parser.tab.o \
	$(OBJPATH)/Eval/Eval.o \
	$(OBJPATH)/GspnParser/Gspn-parser.tab.o \
	$(OBJPATH)/GspnParser/Gspn-Reader.o \
	$(OBJPATH)/GspnParser/Gspn_gmlparser.o \
	$(OBJPATH)/LhaParser/Lha-Reader.o \
	$(OBJPATH)/LhaParser/Lha-parser.tab.o  \
	$(OBJPATH)/../Cosmos/BatchR.o \
	$(OBJPATH)/expatmodelparser.o \
	$(OBJPATH)/modelwriter.o

$(OBJPATH)/%.o: %.cpp
	$(CC) $(OPTIONS) -c $*.cpp -o $@	
$(OBJPATH)/%.o: %.cc
	$(CC) $(OPTIONS) -c $*.cc -o $@
$(OBJPATH)/%.o: $(LIBGMLPATH)/%.cc
	$(CC) $(OPTIONS) -c $(LIBGMLPATH)/$*.cc -o $@

$(BINPATH)/CosmosGPP: $(FILES)
	$(CC) $(OPTIONS) -L/usr/lib/ -lexpat $^ -o $@

clean:
	rm $(OBJPATH)/Eval/*.o
	rm $(OBJPATH)/GspnParser/*.o
	rm $(OBJPATH)/LhaParser/*.o
	rm $(OBJPATH)/*.o
	rm $(BINPATH)/CosmosGPP	
	rm $(BINPATH)/ClientSim	