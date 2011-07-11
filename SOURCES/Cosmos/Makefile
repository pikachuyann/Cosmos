CC=g++
OPTIONS=-std=gnu++0x
OBJPATH=../../Obj/Cosmos
BINPATH=../../bin

init:
	cat ../ModelGenerator/LHA_orig.hpp end.cpp > LHA.hpp
	cat ../ModelGenerator/spn_orig.hpp end.cpp > spn.hpp

classes: init
	$(CC) $(OPTIONS) -c Event.cpp -o $(OBJPATH)/Event.o
	$(CC) $(OPTIONS) -c EventsQueue.cpp -o  $(OBJPATH)/EventsQueue.o
	$(CC) $(OPTIONS) -c tab.cpp -o $(OBJPATH)/tab.o
	$(CC) $(OPTIONS) -c RareEvent.cpp -o $(OBJPATH)/RareEvent.o
	$(CC) $(OPTIONS) -c StandardNormalDist.cpp -o $(OBJPATH)/StandardNormalDist.o
	$(CC) $(OPTIONS) -c ap.cpp -o $(OBJPATH)/ap.o
	$(CC) $(OPTIONS) -c Simulator.cpp -o $(OBJPATH)/Simulator.o
	$(CC) $(OPTIONS) -c main.cpp -o $(OBJPATH)/main.o

clean:
	rm spn.cpp
	rm spn.hpp
	rm LHA.cpp
	rm LHA.hpp
	rm $(OBJPATH)/*.o

sim:
	$(CC) $(OPTIONS) -c spn.cpp -o $(OBJPATH)/spn.o
	$(CC) $(OPTIONS) -c LHA.cpp -o $(OBJPATH)/LHA.o
	$(CC) $(OPTIONS) \
		$(OBJPATH)/main.o \
		$(OBJPATH)/Event.o \
		$(OBJPATH)/EventsQueue.o \
		$(OBJPATH)/tab.o \
		$(OBJPATH)/RareEvent.o \
		$(OBJPATH)/StandardNormalDist.o \
		$(OBJPATH)/ap.o \
		$(OBJPATH)/Simulator.o \
		$(OBJPATH)/spn.o \
		$(OBJPATH)/LHA.o \
	-o $(BINPATH)/SimGPP
