

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
//#include <cstdlib>
#include <sstream>
//#include <unistd.h>

using namespace std;

#include "generateLHA.cpp"
#include "generateSPN.cpp"

int main(int argc, char** argv) {
    int N =5;
    vector< vector<double> > M(N,vector<double>(N,0) );
    vector< vector<double> > Plast(N,vector<double>(N,0) );
    
    M[0][1]=1;
    M[1][1]=0.3;
    M[1][2]=0.4;
    M[1][3]=0.3;
    M[2][0]=0.5;
    M[2][3]=0.5;
    M[3][3]=0.3;
    M[3][4]=0.7;
    M[4][2]=1;
    
    
    generateLHAfun(N,Plast);
    generateSPNfun(M);
    
    return 0;
}