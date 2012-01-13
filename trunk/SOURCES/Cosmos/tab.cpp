#include "tab.hpp"
#include <vector>
#include <math.h>
#include <float.h>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
using namespace __gnu_cxx;


TAB::TAB(){
}

void TAB::Load(){
	//cout << "load table"<< endl;
	string line;
	int poseq;
	string pos;
	string prob;
	ifstream myfile ("mu_table");
	if (myfile.is_open())
	{ 
		while ( myfile.good() )
		{
			getline (myfile,line);
			poseq = line.find("=");
			
			if(poseq > 0){
				pos = line.substr(1,poseq-2);
				prob = line.substr(poseq+1,line.size());
				
				vector<int> vect;
				int it = 0;
				while(it < pos.length()){
					int it2 = pos.find(",",it);
					if(it2 == -1) it2 = pos.length();
					//cout << "test:" << it<< ":" << it2 << endl;
					vect.push_back(atoi((pos.substr(it,it2-it)).c_str() ));
					it = it2+1;
				}
				
				M[new vector<int>(vect)] = (double)atof(prob.c_str());
				
				
			}
		}
		myfile.close();
		
		
    }
	
	else cerr << "Unable to open file "<< "mu_table" << endl ; 
	
};
