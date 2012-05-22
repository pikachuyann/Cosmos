//
//  Result.cpp
//  Cosmos
//
//  Created by Benoit Barbot on 22/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "result.hpp"


#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
boost::math::normal norma;

result::result(parameters &Q){
    P= Q;
    K = 0;
    Ksucc = 0; //counter of succesfull generated paths
    Ksucc_sqrt =0 ; //square root of Ksucc
    
    CurrentWidth = 1;
    RelErr = 1;
    
    Mean = 0;
    Var = 0; //variance
    stdev = 0; //standard deviation
    M2 = 0;
    Normal_quantile = quantile(norma, 0.5 + P.Level / 2.0);
    
    low=0;
    up=0;
    IsBernoulli = true;
    Dif=0;
}

