all: exec


generator: generateLHA.cpp generateSPN.cpp readPlast.cpp main.cpp
	g++ -o swn main.cpp
	g++ -o linear linear.cpp
	g++ -o grid grid.cpp

generate: generator
	./generator

exec: generator
	./generator
	Cosmos generated.gspn generated.lha -d test --max-run 100000 --batch 10000
	tail -n 1 test > test2


loop:
	./generator test2
	Cosmos generated.gspn generated.lha -d test --max-run 100000 --batch 10000
	tail -n 1 test > test2
