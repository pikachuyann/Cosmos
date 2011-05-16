#include "spn.hpp"
#include "LHA.hpp"
#include "Simulator.hpp"

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <set>

#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"
#include <float.h>
#include <time.h>
#include <math.h>

double StrToDbl(string st) {

    std::istringstream iss(st);
    double x;
    iss >> x;
    return x;
}

int StrToInt(string st) {

    std::istringstream iss(st);
    int x;
    iss >> x;
    return x;
}

long int StrToLongInt(string st) {

    std::istringstream iss(st);
    long int x;
    iss >> x;
    return x;
}



using namespace std;

int main(int argc, char** argv) {



    Simulator mySim;
    mySim.Load();

    string str = argv[1];
    mySim.SetConfLevel(StrToDbl(str));

    str = argv[2];
    mySim.SetConfWidth(StrToDbl(str));

    str = argv[3];
    mySim.SetBatchSize(StrToDbl(str));

    str = argv[4];
    mySim.SetMaxRuns(StrToLongInt(str));

    mySim.RunSimulation();

    return (EXIT_SUCCESS);
}







