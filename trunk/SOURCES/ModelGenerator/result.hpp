//
//  result.h
//  Cosmos
//
//  Created by Benoit Barbot on 22/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "parameters.hpp"
#include "../Cosmos/BatchR.hpp"

#ifndef Cosmos_result_h
#define Cosmos_result_h

class result {
public:
    result(parameters &Q);
    ~result();
    parameters P;
    int K; //counter of generated paths
    int Ksucc; //counter of succesfull generated paths
    double Ksucc_sqrt; //square root of Ksucc
    
    double CurrentWidth;
    double RelErr;
    
    double Mean;
    double Var; //variance
    double stdev; //standard deviation
    double M2;
    double Normal_quantile;
    
    double low, up;
    bool IsBernoulli;
    double Dif;
};


#endif
