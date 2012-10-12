

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <math.h>
//#include <unistd.h>

using namespace std;

void generateLHAfun(double,int N, vector< vector< vector<double> > >&,vector<double>&, double H,vector< vector<double> >& M);
#include "generateLHA.cpp"

void generateSPNfun(int N,vector< vector<double> >&);
#include "generateSPN.cpp"

double readPlastfun(int N,string , vector< vector< vector<double> > >&);
void fillMemory( vector< vector< vector<double> > >&,int);
void printPlast(vector< vector< vector<double> > >&);
#include "readPlast.cpp"

vector< vector<double> > generateMatrix(int n);
vector< vector<double> > generateLinearMatrix(int n, double p, double q);
vector<double > generateLinearReward(int n,double Rmax);
vector< vector<double> > generateGridMatrix(int n, int m, double u, double r, double d, double l);
vector<double > generateGridReward(int n,int m);

#include "exPapier.cpp"

int main(int argc, char** argv) {
    int Memory = 2;
    double H=1000; //simulation horizon
    double ron, rdet;
    string ExpFileName;
    string RewardTrace;
    string st;
    int n,m;
	//    vector<int>  W(N,0);//sensor satatus
    
    
    //vector< vector<double> > M = generateMatrix(0);
    
    vector< vector<double> > M;
    vector< double > RewardArray;
	
    st=argv[1];
    if(st=="linear"){
		double p=0.3;
		double q=0.2;   
		
		
		std::istringstream st( argv[3]);
		st >> n;
		
		M = generateLinearMatrix(n,p,q);
		RewardArray = generateLinearReward(n,3);
		ron=-1;
		rdet=10;
		ExpFileName="linear.txt";
		RewardTrace="linear";
		
    }
    else if(st=="grid"){
		
		
		double u=0.4;
		double r=0.4;
		double d=0.1;
		double l=0.05;
		
		std::istringstream st1( argv[3]);
		st1 >> n;
		std::istringstream st2( argv[4]);
		st2 >> m;
		
		M = generateGridMatrix(n,m,u,r,d,l);
		RewardArray = generateGridReward(n,m);
		ron=-5;
		rdet=100;
		
		ExpFileName="grid.txt";
		RewardTrace="grid";
		
		
    }
    
    else{
		M = generateMatrix(0);
		RewardArray = vector<double>(M.size(),4);
		ExpFileName="default.txt";
		RewardTrace="default";
		ron=-1;
		rdet=4;
		
    }
	
    
    RewardTrace=RewardTrace+argv[2]+".txt";
    ofstream RewardFile(RewardTrace.c_str(), ios::out | ios::trunc);
    ofstream ExpFile(ExpFileName.c_str(), ios::out | ios::app);
	
	
    string Cosmoscmd = "Cosmos generated.gspn generated.lha --njob 11 -d test --max-run 10000 --batch 100 --count-transition --width 0.01 -v 1";
	
	// initial iteration
	
	
	int N = (int)M.size();
    vector< vector< vector<double> > > Plast(N,vector< vector<double> >(Memory, vector<double>(N,1.0)) );
	
	/*generateLHAfun(ron,N,Plast,RewardArray,H,M);
	generateSPNfun(M);
	system(Cosmoscmd.c_str());*/
	//
	//loop
	double Prec=1e-2; //precision
	double Reward,OldReward;
	double RelDiff=100; // actual relative difference = abs((Reward-OldReward)/OldReward);
	int MaxIteration=6;
	int It=0;
	
	/*system("head -n 1 test > test2");
	system("tail -n 1 test >> test2");
	Reward = readPlastfun(N, "test2", Plast);
	fillMemory(Plast,1);
	cout <<"Iteration:" <<It<< " reward: "<< Reward << endl;
	RewardFile<<It<<" "<<Reward<<endl;*/
	generateSPNfun(M);
	while(RelDiff>Prec && It<MaxIteration){
		It++;    
		generateLHAfun(ron,N,Plast,RewardArray,H,M);
		system(Cosmoscmd.c_str());
		OldReward=Reward;
		system("head -n 1 test > test2");
		system("tail -n 1 test >> test2");
		Reward = readPlastfun(N, "test2", Plast)/H;
		printPlast(Plast);
		if(It==1){
			fillMemory(Plast,1);
		}else{
			RelDiff=fabs((Reward-OldReward)/OldReward);
		}
		cout <<"Iteration:" <<It<< " reward: "<< Reward <<" RelDiff: "<<RelDiff<< endl;
		RewardFile<<It<<" "<<Reward<<endl;
	}
    st=argv[1];
	if(st=="linear"){
		ExpFile << "n="<<argv[3]<<" ";
    }
    else if(st=="grid"){
		ExpFile << "n="<<argv[3]<<" "<< "m="<<argv[4]<<" ";
    }
    ExpFile <<Reward<<endl;
    
    RewardFile.close();
    ExpFile.close();
    return(EXIT_SUCCESS);
}
