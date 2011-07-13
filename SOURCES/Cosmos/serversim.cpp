#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sys/select.h>
//#include "Simulator.hpp"
//#include "spn.hpp"
//#include "LHA.hpp"
//#include "EventsQueue.hpp"
//#include "SimulatorRE.h"
#include <iostream>
#include <fstream>
//#include <set>
//#include <math.h>
//#include <float.h>
//#include <boost/random.hpp>
//#include <boost/generator_iterator.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <time.h>
//#include <unistd.h>


using namespace std;

class BatchResult {
public:
  bool IsBernoulli;
  double I;
  double Isucc;
  double Mean;
  double M2;
  };

double StrToDbl(string st) {

  std::istringstream iss(st);
  double x;
  iss >> x;
  return x;
}

int StrToInt(string st) {

  std::istringstream iss(st);
  int x;
  iss >> x;
  return x;
}

long int StrToLongInt(string st) {

  std::istringstream iss(st);
  long int x;
  iss >> x;
  return x;
}


fd_set client_list;
int Njob = 2;
vector<FILE*> clientstream;
int max_client=0 ;

string cmd = "./ClientSim 1000";

double BatchSize = 1000;
double MaxRuns = 100000000;
double ConfWidth = 0.001;
double ConfLevel = 0.99;
bool RareEvent_mode = false;

void lauch_clients(){
  for(int i = 0;i<Njob;i++){
    FILE* stream = popen(cmd.c_str(), "r");
    clientstream.push_back(stream);
    int streamfd = fileno(stream);
    if(streamfd >max_client)max_client = streamfd;

  }

}

void makeselectlist(){
  FD_ZERO(&client_list);
  for(int it = 0;it<Njob;it++){
    int fl = fileno(clientstream[it]);
    FD_SET(fl,&client_list);
  }

}

int main(int argc, char** argv){

  //Simulator mySim;
  RareEvent_mode = false;
  string str;

  if(argc > 5){
    str = argv[5];
    if(str== "-RE")RareEvent_mode=true;
  };

  //mySim.Load();

  str = argv[1];
  ConfLevel=StrToDbl(str);

  str = argv[2];
  ConfWidth=StrToDbl(str);

  str = argv[3];
  BatchSize=StrToDbl(str);

  str = argv[4];
  MaxRuns=StrToLongInt(str);


  //stream = popen(cmd.c_str(), "r");

  time_t start, end;
  double cpu_time_used;



  time(&start);



  double K = 0; //counter of generated paths
  double Ksucc = 0; //counter of succesfull generated paths
  double Ksucc_sqrt; //square root of Ksucc
  double Isucc;


  double CurrentWidth = 1;
  double RelErr = 1;

  double Mean = 0;
  double Var = 0; //variance
  double stdev = 0; //standard deviation
  double M2 = 0;
  double Y = 0;
  double x1sqr;
  double Normal_quantile;

  double low, up;
  bool IsBernoulli = true;
  double Dif;

  //------------------ Rare Event -----------------
  ofstream logvalue("logvalue.dat",ios::out | ios::trunc);
  //----------------- /Rare Event -----------------

  cout << "START SIMULATION ..." << endl;

  /////////////////////////////////////////////////////////////////////////////
  // Some remarks about the estimation of the confidence interval adopted here
  // Let l=ConfLevel, the confidence level
  // l=1-alpha
  // Let w=ConfWidth, the size of the confidence interval

  // Let mu the value to estimate, and x the estimation of mu
  // then Prob(x-w/2 <= mu <= x+w/2) = 1-alpha

  // The confidence interval is given by :
  // [x-z(1-alpha/2) * StandardDeviation / sqrt(NumberOfObservations) ,  x+z(1-alpha/2) * StandardDeviation / sqrt(NumberOfObservations)]

  // z(1-alpha/2)=z(1-(1-l)/2) = z(0.5+l/2)
  ////////////////////////////////////////////////////////////////////////////

  lauch_clients();
  makeselectlist();

  boost::math::normal norm;
  Normal_quantile = quantile(norm, 0.5 + ConfLevel / 2.0);

  do{
    fd_set cs_cp = client_list;
    //cout << "start select" << endl;
    if(select(max_client+1, &cs_cp, NULL, NULL, NULL) == -1)
      {
        perror("Server-select() error!");
        exit(1);
      }
    //cout << "stop select" << endl;
    for(int it = 0;it<Njob;it++){
      if(FD_ISSET(fileno(clientstream[it]), &cs_cp)){
	bool readb;
	double read;
        BatchResult* batchR = new BatchResult;
	fread(reinterpret_cast<char*>( &readb ), sizeof readb ,1, clientstream[it]);
	IsBernoulli= IsBernoulli && readb;
	fread(reinterpret_cast<char*>( &read ), sizeof read ,1, clientstream[it]);
	batchR->I=read;
	fread(reinterpret_cast<char*>( &read ), sizeof read ,1, clientstream[it]);
	batchR->Isucc=read;
	fread(reinterpret_cast<char*>( &read ), sizeof read ,1, clientstream[it]);
	batchR->Mean=read;
	fread(reinterpret_cast<char*>( &read ), sizeof read ,1, clientstream[it]);
	batchR->M2=read;

	//cout << "client: " << it << " :"<< read << endl;


        K = K + batchR->I;
        Ksucc = Ksucc + batchR->Isucc;

        Dif = batchR->Mean - Mean;
        Mean = Mean + batchR->Isucc * Dif / Ksucc;

        Dif = batchR->M2 - M2;
        M2 = M2 + batchR->Isucc * Dif / Ksucc;


        Var = M2 - pow(Mean, 2);


        stdev = sqrt(Var);
        Ksucc_sqrt = sqrt(Ksucc);
        CurrentWidth = 2 * Normal_quantile * stdev / Ksucc_sqrt;

	delete batchR;
        //-------------- Rare Event -----------------
        cout << "\033[A\033[2K" << "Total paths: " << K << "\t accepted paths: " << Ksucc << "\t Mean" << "=" << Mean << "\t stdev=" << stdev << "\t  width=" << CurrentWidth << endl;

        //RelErr = CurrentWidth / max(1, abs(Mean)); <- ligne original
        RelErr = CurrentWidth /  abs(Mean);
        //------------- /Rare Event -----------------

      }
    }

  }while ((RelErr > ConfWidth) && (K < MaxRuns));



    low = Mean - CurrentWidth / 2.0;
    up = Mean + CurrentWidth / 2.0;
    if (IsBernoulli) {
      low = (0 > low) ? 0.0 : low;
      up = (1 < up) ? 1.0 : up;
      CurrentWidth = up - low;

    }

    cout << "\nEstimated value: " << Mean << endl;
    cout << "Confidence interval: [" << low << "," << up << "]" << endl;
    cout << "Standard deviation: " << stdev << "\tWidth: " << CurrentWidth << endl;
    cout << "Total paths: " << K << "\tAccepted paths: " << Ksucc << endl;



    time(&end);
    cpu_time_used = difftime(end, start);


    cout << "\nSimulation Time: " << cpu_time_used << endl;
    string fn = "Result";  //N.Path;
    fn.append(".res");
    ofstream ResultsFile(fn.c_str(), ios::out | ios::trunc);


    if (!ResultsFile) cout << "File '" << fn << "' not Created" << endl;
    else {
      ResultsFile << "Estimated Value:\t" << Mean << endl;
      ResultsFile << "Standard Deviation:\t" << stdev << endl;
      ResultsFile << "Confidence interval:\t[";
      ResultsFile << low << " , " << up << "]\n" << endl;
      ResultsFile << "Width=\t" << CurrentWidth << endl;

      ResultsFile << "Total paths:\t" << K << endl;
      ResultsFile << "Accepted paths:\t" << Ksucc << endl;
      ResultsFile << "Simulation time :\t" << cpu_time_used << endl;

      ResultsFile << "\nConfidence level:\t" << ConfLevel << endl;
      cout << "Results are saved in '" << fn << "'" << endl;
      ResultsFile.close();


    }
}
