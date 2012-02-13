//
//  SimulatorContinuousBounded.h
//  Cosmos
//
//  Created by Benoit Barbot on 31/01/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Cosmos_SimulatorContinuousBounded_h
#define Cosmos_SimulatorContinuousBounded_h

#include "SimulatorBoundedRE.hpp"
#include "foxglynn.h"

class SimulatorContinuousBounded: public SimulatorBoundedRE{
public:
	SimulatorContinuousBounded(int m,double e);
    void initVectCo(double t);
    double epsilon;
    BatchR* RunBatch();
    
protected:
    FoxGlynn* fg;
	
};



#endif
