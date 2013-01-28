OBJPATH=../../Obj/ModelGenerator
SRCPATH=../../SOURCES/ModelGenerator
BINPATH=../../bin
LIBGMLPATH=../libgml/

FILES= $(OBJPATH)/parameters.o \
    $(OBJPATH)/server.o \
    $(OBJPATH)/result.o \
	$(OBJPATH)/HaslFormula.o \
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

SRCS= $(SRCPATH)/parameters.cpp \
	$(SRCPATH)/server.cpp \
	$(SRCPATH)/result.cpp \
	$(SRCPATH)/HaslFormula.cpp \
	$(SRCPATH)/Cosmos.cpp \
	$(SRCPATH)/Eval/Eval-parser.tab.cc \
	$(SRCPATH)/Eval/Eval.cpp


depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CC) -I$(SRCPATH)/../libgml/ $(OPTIONS) -MM $^>>./.depend;

$(OBJPATH)/%.o: %.cpp
	$(CXX) -I../libgml/ -I$(BOOSTPATH) $(OPTIONS) -c $*.cpp -o $@
$(OBJPATH)/%.o: %.cc
	$(CXX) -I../libgml/ $(OPTIONS) -c $*.cc -o $@
$(OBJPATH)/%.o: $(LIBGMLPATH)/%.cc
	$(CXX) $(OPTIONS) -c $(LIBGMLPATH)/$*.cc -o $@

$(BINPATH)/Cosmos: $(FILES) 
	$(CXX) $(OPTIONS) -L/usr/lib/ -lexpat $^ -o $@

parser:
	@(cd LhaParser && $(MAKE))
	@(cd GspnParser && $(MAKE))
	@(cd Eval && $(MAKE))

cleanparser:
	@(cd LhaParser && $(MAKE) clean)
	@(cd GspnParser && $(MAKE) clean)
	@(cd Eval && $(MAKE) clean)


clean:
	rm $(OBJPATH)/Eval/*.o
	rm $(OBJPATH)/GspnParser/*.o
	rm $(OBJPATH)/LhaParser/*.o
	rm $(OBJPATH)/*.o
	rm $(BINPATH)/Cosmos