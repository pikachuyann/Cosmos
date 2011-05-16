#include "tab.hpp"
#include <vector>
#include <math.h>
#include <float.h>
#include <iostream>
#include <fstream>
#include <hash_map>
#include <cstring>

using namespace std;
using namespace __gnu_cxx;
 

TAB::TAB(){
}

void TAB::load(){
  string line;
  int poseq;
  string pos;
  string prob;
  ifstream myfile ("philoapprox");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      poseq = line.find("=");
      if(poseq > 0){
	pos = line.substr(0,poseq);
	prob = line.substr(poseq+1,line.size());
	
	//M[(const char*)(pos.c_str())]= (double)atof(prob.c_str());
	M[(const char*)((new string(pos))->c_str())]= (double)atof(prob.c_str());


	//cout << pos.c_str() << ":" << atof(prob.c_str()) << "-" << strlen(pos.c_str())<< endl;
      }
    }
    myfile.close();

    /*for (hash_prob::iterator it = M.begin(); it != M.end(); it++)
      cout << "--"<<* new string (it->first) << " " << it->second << endl ;*/

    }

  else cout << "Unable to open file"; 

};
