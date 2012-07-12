

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <unistd.h>

using namespace std;

#include "generateLHA.cpp"
#include "generateSPN.cpp"

int main(int argc, char** argv) {
    int N =1;
    vector< vector<double> > M(N,vector<double>(N,0) );
    vector< vector<double> > Plast(N,vector<double>(N,0) );
    
    
    generateLHAfun(N,Plast);
    generateSPNfun(M);
    
    return 0;
}