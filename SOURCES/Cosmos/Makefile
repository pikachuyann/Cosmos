CC=g++
OBJPATH=../../Obj/Cosmos
BINPATH=../../bin
OPTIONS2= -Wno-deprecated $(OPTIONS) 

init:
	cat ../ModelGenerator/LHA_orig.hpp end.cpp > LHA.hpp
	cat ../ModelGenerator/spn_orig.hpp end.cpp > spn.hpp

classes: init
	$(CC) $(OPTIONS2) -c Event.cpp -o $(OBJPATH)/Event.o
	$(CC) $(OPTIONS2) -c EventsQueue.cpp -o  $(OBJPATH)/EventsQueue.o
	$(CC) $(OPTIONS2) -c tab.cpp -o $(OBJPATH)/tab.o
	$(CC) $(OPTIONS2) -c RareEvent.cpp -o $(OBJPATH)/RareEvent.o
	$(CC) $(OPTIONS2) -c Simulator.cpp -o $(OBJPATH)/Simulator.o
	$(CC) $(OPTIONS2) -c clientsim.cpp -o $(OBJPATH)/clientsim.o
	$(CC) $(OPTIONS2) -c main.cpp -o $(OBJPATH)/main.o

clean:
	rm $(OBJPATH)/*.o
	rm spn.hpp
	rm LHA.hpp
	rm LHA.cpp
	rm spn.cpp

simsauv:
	$(CC) $(OPTIONS2) -c spn.cpp -o $(OBJPATH)/spn.o
	$(CC) $(OPTIONS2) -c LHA.cpp -o $(OBJPATH)/LHA.o
	$(CC) $(OPTIONS2) \
		$(OBJPATH)/main.o \
		$(OBJPATH)/Event.o \
		$(OBJPATH)/EventsQueue.o \
		$(OBJPATH)/tab.o \
		$(OBJPATH)/RareEvent.o \
		$(OBJPATH)/Simulator.o \
		$(OBJPATH)/spn.o \
		$(OBJPATH)/LHA.o \
	-o $(BINPATH)/SimGPP

sim: 
	$(CC) $(OPTIONS2) -c spn.cpp -o $(OBJPATH)/spn.o
	$(CC) $(OPTIONS2) -c LHA.cpp -o $(OBJPATH)/LHA.o
	$(CC) $(OPTIONS2) \
		$(OBJPATH)/clientsim.o \
		$(OBJPATH)/Event.o \
		$(OBJPATH)/EventsQueue.o \
		$(OBJPATH)/tab.o \
		$(OBJPATH)/RareEvent.o \
		$(OBJPATH)/Simulator.o \
		$(OBJPATH)/spn.o \
		$(OBJPATH)/LHA.o \
	-o $(BINPATH)/ClientSim

server:
	$(CC) $(OPTIONS2) -c serversim.cpp -o $(OBJPATH)/serversim.o
	$(CC) $(OPTIONS2) $(OBJPATH)/serversim.o \
	-o $(BINPATH)/ServerSim