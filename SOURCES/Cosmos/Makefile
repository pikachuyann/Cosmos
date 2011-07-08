C=g++
OPTIONS=-Wno-deprecated
OBJPATH=../../Obj/Cosmos
BINPATH=../../bin

init:
	cp ../ModelGenerator/LHA_orig.hpp LHA.hpp
	echo "};\n#endif\n" >> LHA.hpp
	cp ../ModelGenerator/spn_orig.hpp spn.hpp
	echo "};\n#endif\n" >> spn.hpp

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