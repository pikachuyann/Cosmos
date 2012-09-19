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


double readPlastfun(int N,string PlastPath, vector< vector< vector<double> > >&Plast){
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
            for (int Xlast=0; Xlast < Plast[i].size(); Xlast++) {
                double outi = 0.0;
                for (int j=0; j<N; j++) {
                    
                    double val;
                    PlastFile >> val;
                    Plast[i][Xlast][j] = val;
                    outi += val;
                    PlastFile >> dumbdouble >> dumbdouble >> dumbdouble;                
                    
                }
                for (int j=0; j<N; j++) {
                    if(outi>0)
                        Plast[i][Xlast][j] /= outi;
                    cout << "Plast("<<i<<","<< Xlast << ","<< j<<") = "<< Plast[i][Xlast][j]<< endl;
                }
            }
            
        }
        
        double reward;
        PlastFile >> reward;
        return reward;
        
        
    }else{
        cout << "Fail to open Plast file:"<< PlastPath << endl;
        exit(EXIT_FAILURE);
    }
    
    
}

