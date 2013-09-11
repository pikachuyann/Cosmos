OBJPATH=../../Obj/ModelGenerator
#OBJPATH= ./
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
	$(OBJPATH)/modelwriter.o \
	$(OBJPATH)/casesWriter.o

SRCS= $(SRCPATH)/parameters.cpp \
	$(SRCPATH)/server.cpp \
	$(SRCPATH)/result.cpp \
	$(SRCPATH)/HaslFormula.cpp \
	$(SRCPATH)/Cosmos.cpp \
	$(SRCPATH)/casesWriter.cpp \
	$(SRCPATH)/Eval/Eval-parser.tab.cc \
	$(SRCPATH)/Eval/Eval.cpp


depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CC) -I$(SRCPATH)/../libgml/ $(OPTIONS) -MM $^>>./.depend;

$(OBJPATH)/%.o: %.cpp
	$(CXX) -I$(abspath ../libgml/) -I$(BOOSTPATH) $(OPTIONS) -c $(abspath $*.cpp) -o $(abspath $@)
$(OBJPATH)/%.o: %.cc
	$(CXX) -I$(abspath ../libgml/) $(OPTIONS) -c $(abspath $*.cc) -o $(abspath $@)
$(OBJPATH)/%.o: $(LIBGMLPATH)/%.cc
	$(CXX) $(OPTIONS) -c $(abspath $(LIBGMLPATH)/$*.cc ) -o $(abspath $@)

$(BINPATH)/Cosmos: $(FILES) 
	$(CXX) $(OPTIONS) $(abspath $^) -lexpat -o $(abspath $@)

parser:
	@(cd LhaParser && $(MAKE))
	@(cd GspnParser && $(MAKE))
	@(cd Eval && $(MAKE))

cleanparser:
	@(cd LhaParser && $(MAKE) clean)
	@(cd GspnParser && $(MAKE) clean)
	@(cd Eval && $(MAKE) clean)


clean:
	rm -rf $(OBJPATH)
	rm $(BINPATH)/Cosmos