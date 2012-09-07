//
//  readPlast.cpp
//  Cosmos
//
//  Created by Benoit Barbot on 06/09/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include <iostream>
#include <fstream>

using namespace std;


void readPlastfun(int N,string PlastPath, vector< vector<double> >&Plast){
    ifstream PlastFile(PlastPath.c_str(), ios::in);
    
    int dumbint;
    double dumbdouble;
    string line;
    
    if (PlastFile.is_open()) {
    
        /*PlastFile>> line;
        cout << line << endl;
        */
        
        PlastFile >> dumbint >> dumbint;
        
        for (int i=0; i < N ; i++) {
            for (int j=0; j<N; j++) {
                double val;
                PlastFile >> val;
                Plast[i][j] = val;
                PlastFile >> dumbdouble >> dumbdouble >> dumbdouble;                
                cout << "Plast("<<i<<","<< j<<") = "<< Plast[i][j]<< endl;
                
            }
        }
    }else{
        cout << "Fail to open Plast file:"<< PlastPath << endl;
    }
    
    
}

