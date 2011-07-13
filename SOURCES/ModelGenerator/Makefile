OBJPATH=../../Obj/ModelGenerator
BINPATH=../../bin

Generator:
	$(CC) $(OPTIONS) -c Eval/Eval-parser.tab.cc -o $(OBJPATH)/Eval/Eval-parser.tab.o
	$(CC) $(OPTIONS) -c Eval/Eval.cpp -o $(OBJPATH)/Eval/Eval.o
	$(CC) $(OPTIONS) -c GspnParser/Gspn-parser.tab.cc -o $(OBJPATH)/GspnParser/Gspn-parser.tab.o
	$(CC) $(OPTIONS) -c GspnParser/Gspn-Reader.cpp -o $(OBJPATH)/GspnParser/Gspn-Reader.o	
	$(CC) $(OPTIONS) -c LhaParser/Lha-parser.tab.cc -o $(OBJPATH)/LhaParser/Lha-parser.tab.o
	$(CC) $(OPTIONS) -c LhaParser/Lha-Reader.cpp -o $(OBJPATH)/LhaParser/Lha-Reader.o
	$(CC) $(OPTIONS) -c server.cpp -o $(OBJPATH)/server.o	
	$(CC) $(OPTIONS) -c mainGPP.cpp -o $(OBJPATH)/mainGPP.o	

	$(CC) $(OPTIONS) \
		$(OBJPATH)/server.o \
		$(OBJPATH)/mainGPP.o \
		$(OBJPATH)/Eval/Eval-parser.tab.o \
		$(OBJPATH)/Eval/Eval.o \
		$(OBJPATH)/GspnParser/Gspn-parser.tab.o \
		$(OBJPATH)/GspnParser/Gspn-Reader.o \
		$(OBJPATH)/LhaParser/Lha-Reader.o \
		$(OBJPATH)/LhaParser/Lha-parser.tab.o  \
		$(OBJPATH)/../Cosmos/Event.o \
		$(OBJPATH)/../Cosmos/EventsQueue.o  \
	 -o $(BINPATH)/CosmosGPP

clean:
	rm $(OBJPATH)/Eval/*.o
	rm $(OBJPATH)/GspnParser/*.o
	rm $(OBJPATH)/LhaParser/*.o
	rm $(OBJPATH)/*.o
	rm $(BINPATH)/CosmosGPP	
	rm $(BINPATH)/ClientSim	