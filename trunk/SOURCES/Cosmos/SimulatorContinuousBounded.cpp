//
//  SimulatorContinuousBounded.cpp
//  Cosmos
//
//  Created by Benoit Barbot on 31/01/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SimulatorContinuousBounded.hpp"
#include "float.h"
#include "math.h"


SimulatorContinuousBounded::SimulatorContinuousBounded(int m,double e):SimulatorBoundedRE(m){
    epsilon = e;
}

void SimulatorContinuousBounded::initVectCo(double t){
    double lambda = numSolv->maxRate();
    cerr << "lambda:" << lambda<< endl;
    if (fox_glynn(lambda * t, DBL_MIN, DBL_MAX,epsilon, &fg)){
        cerr << "fox_glyn:" << fg->left << "," << fg->right << endl;
    }
    initVect(fg->right);
    
}