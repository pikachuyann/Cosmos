//
//  parameters.h
//  Cosmos
//
//  Created by Benoit Barbot on 08/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Cosmos_parameters_h
#define Cosmos_parameters_h

#include <string>

using namespace std;

struct parameters {
	int Njob;
	double Level;
	double Width;
	int Batch;
	long int MaxRuns;
	string Path;
	string PathGspn;
	string PathLha;
	bool RareEvent;
	bool DoubleIS;
	int BoundedRE;
    int horizon;
    bool BoundedContinuous;
    
	bool GMLinput;
    bool computeStateSpace;
	bool alligatorMode;
    
    parameters();
    void View();
    void parseCommandLine(int argc, char** argv);
};

#endif
