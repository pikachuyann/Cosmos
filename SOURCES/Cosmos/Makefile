OBJPATH=../../Obj/Cosmos
BINPATH=../../bin
OPTIONS2=-std=gnu++0x $(OPTIONS) 

init:
	cat ../ModelGenerator/LHA_orig.hpp end.cpp > LHA.hpp
	cat ../ModelGenerator/spn_orig.hpp end.cpp > spn.hpp

classes: init
	$(CC) $(OPTIONS2) -c Event.cpp -o $(OBJPATH)/Event.o
	$(CC) $(OPTIONS2) -c EventsQueue.cpp -o  $(OBJPATH)/EventsQueue.o
	$(CC) $(OPTIONS2) -c tab.cpp -o $(OBJPATH)/tab.o
	$(CC) $(OPTIONS2) -c RareEvent.cpp -o $(OBJPATH)/RareEvent.o
	$(CC) $(OPTIONS2) -c StandardNormalDist.cpp -o $(OBJPATH)/StandardNormalDist.o
	$(CC) $(OPTIONS2) -c ap.cpp -o $(OBJPATH)/ap.o
	$(CC) $(OPTIONS2) -c Simulator.cpp -o $(OBJPATH)/Simulator.o
	$(CC) $(OPTIONS2) -c main.cpp -o $(OBJPATH)/main.o

clean:
	rm spn.cpp
	rm spn.hpp
	rm LHA.cpp
	rm LHA.hpp
	rm $(OBJPATH)/*.o

sim:
	$(CC) $(OPTIONS2) -c spn.cpp -o $(OBJPATH)/spn.o
	$(CC) $(OPTIONS2) -c LHA.cpp -o $(OBJPATH)/LHA.o
	$(CC) $(OPTIONS2) \
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
