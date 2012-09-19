

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
//#include <unistd.h>

using namespace std;

void generateLHAfun(double,double,int N, vector< vector< vector<double> > >&, double H,vector< vector<double> >& M);
#include "generateLHA.cpp"

void generateSPNfun(int N,vector< vector<double> >&);
#include "generateSPN.cpp"

double readPlastfun(int N,string , vector< vector< vector<double> > >&);
#include "readPlast.cpp"

vector< vector<double> > generateMatrix(int n);
#include "exPapier.cpp"

int main(int argc, char** argv) {
    int Memory = 2;
    double H=100; //simulation horizon

    
//    vector<int>  W(N,0);//sensor satatus
    
    
    vector< vector<double> > M = generateMatrix(0);
    int N = M.size();
    
    vector< vector< vector<double> > > Plast(N,vector< vector<double> >(Memory, vector<double>(N,1.0)) );
    
    
    

    if (argc>1) {
        double reward = readPlastfun(N, argv[1], Plast);
        cout << "reward: "<< reward << endl;
    }
    
    generateLHAfun(-0.1,0.4,N,Plast,H,M);
    generateSPNfun(M);
    
    
    
    return(EXIT_SUCCESS);
}