

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <math.h>
#include <time.h>
//#include <unistd.h>

using namespace std;

void generateLHAfun(double ron ,int N, vector< vector< vector<double> > >& Plast,vector<double>& reward, double H,vector< vector<double> >& M);
void generateLHAfromStrat(double ron,int N, vector< pair<int, vector<int> > >& strat, vector<double>& reward, double H,vector< vector<double> >& M);
#include "generateLHA.cpp"

void generateSPNfun(int N,vector< vector<double> >&);
#include "generateSPN.cpp"

double readPlastfun(int N,string , vector< vector< vector<double> > >&,double);
void fillMemory( vector< vector< vector<double> > >&,int);
void printPlast(vector< vector< vector<double> > >&);
void readStrat(int N,string, vector< pair<int, vector<int> > >&);
void printStrat(vector< pair<int, vector<int> > >&);
#include "readPlast.cpp"

vector< vector<double> > generateMatrix(int n);
vector< vector<double> > generateLinearMatrix(int n, double p, double q);
vector<double > generateLinearReward(int n,double Rmax);
vector< vector<double> > generateGridMatrix(int n, int m, double u, double r, double d, double l);
vector<double > generateGridReward(int n,int m);

#include "exPapier.cpp"

int main(int argc, char** argv) {
    int Memory = 2;
    double H=10000; //simulation horizon
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
	
	
    string Cosmoscmd = "Cosmos generated.gspn generated.lha --njob 11 -d test --max-run 10000 --batch 100 --count-transition --width 0.01 -v 1 --gppcmd clang++ --gppflags -Wno-return-type --tmp-status 2";
	
	// initial iteration
	
	
	int N = (int)M.size();
    vector< vector< vector<double> > > Plast(N,vector< vector<double> >(Memory, vector<double>(N,1.0)) );
	
	vector< pair<int, vector<int> > > ImportedStrat(0,make_pair(0,vector<int>(N,0)) );
	readStrat(N, argv[4], ImportedStrat);
	printStrat(ImportedStrat);
	generateLHAfromStrat(ron, N, ImportedStrat, RewardArray, H, M);
	
	for (int i=0; i<N; i++){
		double out = 0.0;
		for (int j=0; j<N; j++)out += M[i][j];
		for (int j=0; j<N; j++)
			Plast[i][0][j]=M[i][j]/out;
	}
	
	/*generateLHAfun(ron,N,Plast,RewardArray,H,M);
	generateSPNfun(M);
	system(Cosmoscmd.c_str());*/
	//
	//loop
	double Prec=1e-3; //precision
	double Reward,OldReward,maxReward=0;
	double RelDiff=100; // actual relative difference = abs((Reward-OldReward)/OldReward);
	int MaxIteration=5;
	int It=0;
	time_t start,end,maxRewardtime;
	
	
	/*system("head -n 1 test > test2");
	system("tail -n 1 test >> test2");
	Reward = readPlastfun(N, "test2", Plast);
	fillMemory(Plast,1);
	cout <<"Iteration:" <<It<< " reward: "<< Reward << endl;
	RewardFile<<It<<" "<<Reward<<endl;*/
	generateSPNfun(M);
	time(&start);
	while(RelDiff>Prec && It<MaxIteration){
		It++;    
		//printPlast(Plast);
		generateLHAfun(ron,N,Plast,RewardArray,H,M);
		system(Cosmoscmd.c_str());
		OldReward=Reward;
		system("head -n 1 test > test2");
		system("tail -n 1 test >> test2");
		Reward = readPlastfun(N, "test2", Plast,H);
		cout <<"Iteration:" <<It<< " reward: "<< Reward <<" RelDiff: "<<RelDiff<< endl;
		printPlast(Plast);
		fillMemory(Plast,It+1);
		if(It==1){
			
		}else{
			RelDiff=fabs((Reward-OldReward)/OldReward);
		}
		time(&end);
		if(Reward>maxReward){
			maxReward=Reward;
			maxRewardtime=end;
		}
		RewardFile<<It<<" "<<Reward<< "\t time: "<< 
			difftime(end, start) << "s"<< endl;
	}
    st=argv[1];
	if(st=="linear"){
		ExpFile << "n="<<argv[3]<<" ";
    }
    else if(st=="grid"){
		ExpFile << "n="<<argv[3]<<" "<< "m="<<argv[4]<<" ";
    }
    ExpFile <<Reward<<endl;
    
	RewardFile<< "Max: "<< maxReward<<"\t time: "<< difftime(maxRewardtime,start)<<endl;
    RewardFile.close();
    ExpFile.close();
    return(EXIT_SUCCESS);
}
