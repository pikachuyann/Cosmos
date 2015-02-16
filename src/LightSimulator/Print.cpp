//
//  Print.cpp
//  Cosmos
//
//  Created by Alexandru Mereacre on 13/02/2015.
//
//

#include "Print.h"
#include <iostream>

void print(const char * s){
    std::cerr << s;
}

void print(TR_PL_ID i){
    std::cerr << (int)i;
}

void print(REAL_TYPE r){
    std::cerr << r;
}