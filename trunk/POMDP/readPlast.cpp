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
		vector<pair<pair<int, int>, int> > bij;
		
		cout << "Parse first line" << endl;
		getline(PlastFile,line);
		unsigned long pos = 0;
		int nbfield=0;
		while(pos != string::npos){
			pos = line.find("Mean[", pos+1);
			unsigned long pos2 = line.find("]", pos);
			if(pos != string::npos){
				string transname = line.substr(pos+5,pos2-pos-5);
				cout<< transname;
				unsigned long posXlast = transname.find("_", 4);
				unsigned long posArrow = transname.find("->l", posXlast+1);
				unsigned long posXlast2 = transname.find("_",posArrow+4);
				
				int source = atoi(transname.substr(4,posXlast-4).c_str());
				int Xlast = atoi(transname.substr(posXlast+1,posArrow-posXlast-1).c_str());
				
				cout << "\t source: "<< source;
				cout << "\t Xlast: "<< Xlast;
				if (posXlast2!= string::npos) {
					int cible = atoi(transname.substr(posArrow+4,posXlast2-posArrow-4).c_str());
					int Xlast2= atoi(transname.substr(posXlast2+1,transname.length()-1-posXlast2).c_str());
					
					cout << "\t cible: "<< cible;
					cout << "\t Xlast2: "<< transname.substr(posXlast2+1,transname.length()-1-posXlast2);
					
				}
				cout << endl;
				
				nbfield++;
			}
			//if(line.find("\n",0)>=0)rendofline=true;
		}
		
		PlastFile >> dumbint >> dumbint;
		
        double reward;
        PlastFile >> reward;
        PlastFile >> dumbdouble >> dumbdouble >> dumbdouble; 
		
		//Dump transition to lf
		for (int i=0; i<N*Plast[i].size(); i++) {
			PlastFile >> dumbdouble >> dumbdouble >> dumbdouble >> dumbdouble;
		}
		
        for (int i=0; i < N ; i++) {
            for (int Xlast=0; Xlast < Plast[i].size(); Xlast++) {
                double outi = 0.0;
                for (int j=0; j<N; j++) {
                    
					//Dump transition to li_Xlast2 where Xlast2 > 0
					for (int Xlast2=Plast[i].size()-1; Xlast2 > 0; Xlast2--) {
						PlastFile >> dumbdouble >> dumbdouble >> dumbdouble >> dumbdouble;
					}
						
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
		return reward;
        
    }else{
        cout << "Fail to open Plast file:"<< PlastPath << endl;
        exit(EXIT_FAILURE);
    }
    
    
}

