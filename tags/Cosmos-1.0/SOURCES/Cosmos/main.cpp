/*******************************************************************************
 *									       *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)dels (S)tochastique *
 *									       *
 * Copyright (C) 2009-2011 LSV, ENS Cachan & CNRS & INRIA                      *
 * Author: Paolo Ballarini & Hilal Djafri                                      *
 * Website: http://www.lsv.ens-cachan.fr/Software/Cosmos                       *
 *                                                                             *
 * This program is free software; you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation; either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License along     *
 * with this program; if not, write to the Free Software Foundation, Inc.,     *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                 *
 *                                                                             *
 *******************************************************************************
 */



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







