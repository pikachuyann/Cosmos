OBJPATH=../../Obj/ModelGenerator
BINPATH=../../bin

FILES=$(OBJPATH)/server.o \
	$(OBJPATH)/mainGPP.o \
	$(OBJPATH)/Eval/Eval-parser.tab.o \
	$(OBJPATH)/Eval/Eval.o \
	$(OBJPATH)/GspnParser/Gspn-parser.tab.o \
	$(OBJPATH)/GspnParser/Gspn-Reader.o \
	$(OBJPATH)/LhaParser/Lha-Reader.o \
	$(OBJPATH)/LhaParser/Lha-parser.tab.o  \
	$(OBJPATH)/../Cosmos/BatchR.o \

$(OBJPATH)/%.o: %.cpp
	$(CC) $(OPTIONS) -c $*.cpp -o $@	
$(OBJPATH)/%.o: %.cc
	$(CC) $(OPTIONS) -c $*.cc -o $@

$(BINPATH)/CosmosGPP: $(FILES)
	$(CC) $(OPTIONS) $^ -o $@

clean:
	rm $(OBJPATH)/Eval/*.o
	rm $(OBJPATH)/GspnParser/*.o
	rm $(OBJPATH)/LhaParser/*.o
	rm $(OBJPATH)/*.o
	rm $(BINPATH)/CosmosGPP	
	rm $(BINPATH)/ClientSim	