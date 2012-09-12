

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
//#include <unistd.h>

using namespace std;

void generateLHAfun(double,double,int N,vector<int>&, vector< vector<double> >&, double H);
#include "generateLHA.cpp"

void generateSPNfun(int N,vector< vector<double> >&);
#include "generateSPN.cpp"

void readPlastfun(int N,string , vector< vector<double> >&);
#include "readPlast.cpp"

int main(int argc, char** argv) {
    int N =5;
    double H=10; //simulation horizon
    vector< vector<double> > M(N,vector<double>(N,0) );
    vector< vector<double> > Plast(N,vector<double>(N,1.0) );
    vector<int>  W(N,0);//sensor satatus
    
    
    M[0][1]=1;
    M[1][1]=0.3;
    M[1][2]=0.4;
    M[1][3]=0.3;
    M[2][0]=0.5;
    M[2][3]=0.5;
    M[3][3]=0.3;
    M[3][4]=0.7;
    M[4][2]=1;
    
    if (argc>1) {
        readPlastfun(N, argv[1], Plast);
    }
    
    generateLHAfun(-0.1,0.3,N,W,Plast,H);
    generateSPNfun(M);
    
    return(EXIT_SUCCESS);
}