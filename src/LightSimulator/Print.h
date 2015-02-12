//
//  Print.h
//  Cosmos
//
//  Created by Alexandru Mereacre on 12/02/2015.
//
//

#ifndef Cosmos_Print_h
#define Cosmos_Print_h

#include <iostream>
#include "spnLight.hpp"

void print(const char * s){
    std::cerr << s;
}

void print(TR_PL_ID i){
    std::cerr << (int)i;
}

void print(REAL_TYPE r){
    std::cerr << r;
}

#endif
