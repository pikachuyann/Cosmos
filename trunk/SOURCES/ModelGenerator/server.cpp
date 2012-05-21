/*******************************************************************************
 *									                                           *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *			                                    						       *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini Benoît Barbot & Hilal Djafri                       *
 * Website: http://www.lsv.ens-cachan.fr/Software/cosmos                       *
 *                                                                             *
 * This program is free software; you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation; either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License along     *
 * with this program; if not, write to the Free Software Foundation, Inc.,     *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                 *
 *******************************************************************************
 */

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/resource.h>
#include <fstream>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>

#include "../Cosmos/BatchR.hpp"
#include "server.hpp"

using namespace std;

// Straightforward conversion function:
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
vector<FILE*> clientstream;
vector<pid_t> clientPID;
int max_client=0 ;

// Handler for crash of the simulator
void signalHandler( int signum )
{
    cout << "Simulator Crash" << endl;
    exit(EXIT_FAILURE);  
}

void signalHandlerOK(int signum){};


// Launch the P.Njob copy of the simulator with the parameters define in P
void launch_clients(parameters& P){
    signal(SIGCHLD , signalHandler); 
	ostringstream os;
	pid_t readpid;
	int size;
	if (P.Path == "") os << "./ClientSim " << P.Batch << " " << P.verbose;
    else os <<  P.Path << "ClientSim " << P.Batch << " " << P.verbose;
    
    if(P.DoubleIS){ 
        os << " " << "-RE2"; 
    } else if(P.RareEvent){
        os << " " << "-RE";
    } else if(P.BoundedContinuous){
        os << " " << "-COBURE" << " " << P.BoundedRE << " " << P.horizon << " " << P.epsilon;
    } else if(P.BoundedRE>0){
        os << " " << "-BURE" << " " << P.BoundedRE << " " << P.horizon;
    } 
    //cout << os.str() << endl;
    
    for(int i = 0;i<P.Njob;i++){
        FILE* stream = popen((os.str()).c_str(), "r");
        clientstream.push_back(stream);
        int streamfd = fileno(stream);
        if(streamfd >max_client)max_client = streamfd;
        
        size = fread(reinterpret_cast<char*>( &readpid ), sizeof(readpid) ,1, stream);
        clientPID.push_back(readpid);
        //cout << "pid:" << readpid << endl<<endl;
        
    }
    
}

//Kill all the copy of the simulators at the end of the computation
void kill_client(){    
    /*rusage ruse;
    getrusage(RUSAGE_CHILDREN, &ruse);
    cout <<endl << "Total Time: "
        << ruse.ru_utime.tv_sec + ruse.ru_utime.tv_usec / 1000000.
    << "\tTotal Memory: " << ruse.ru_maxrss << "ko" << endl; */
    
    //Discard signal of child terminating
    signal(SIGCHLD , signalHandlerOK);
    
    while (!clientPID.empty())
    {
        
        kill(clientPID.back(),9);
        clientstream.pop_back();
        clientPID.pop_back();
    }
    
}

// Build a list of input files of all the simulators to collect results
// This list is made to be used with the function <sys/select.h>/select
void makeselectlist(int Njob){
    FD_ZERO(&client_list);
    for(int it = 0;it<Njob;it++){
        int fl = fileno(clientstream[it]);
        FD_SET(fl,&client_list);
    }
    
}

void launchExport(parameters& P){
    
    ostringstream os;
	if (P.Path == "") os << "./ClientSim 1 " << P.verbose;
    else os <<  P.Path << "ClientSim 1 " << P.verbose;
    os << " " << "-STSP " << P.prismPath;
    
    if(P.verbose >1)cout << os.str() << endl;
    
    if (system(os.str().c_str()) == 0){
        cout << "Export Finish" << endl;
    }else{
        cout << "Export Fail" << endl;
    }    
}

void printProgress(int i, int j){
    int t = 100;
    int u = (t * i)/j; 
    cout << "[";
    for(int k = 1;k<u;k++)cout<<"|";
    for(int k = u;k<t;k++)cout<<" ";
    cout << "]"<< endl;
}

// This function is the main function.
// This function launch a set of simulator and stop them once
// The precision criterion is reach.
void launchServer(parameters& P){
    
    //Simulator mySim;
    string str;
    
    //mySim.Load();
    
    time_t start, end;
    double cpu_time_used;
    
    time(&start);
    
    int K = 0; //counter of generated paths
    int Ksucc = 0; //counter of succesfull generated paths
    double Ksucc_sqrt; //square root of Ksucc
    
    double CurrentWidth = 1;
    double RelErr = 1;
    
    double Mean = 0;
    double Var = 0; //variance
    double stdev = 0; //standard deviation
    double M2 = 0;
    double Normal_quantile;
    
    double low, up;
    bool IsBernoulli = true;
    double Dif;
    
    //------------------ Rare Event -----------------
    //ofstream logvalue("logvalue.dat",ios::out | ios::trunc);
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
    
    launch_clients(P);
    makeselectlist(P.Njob);
    
    boost::math::normal norm;
    Normal_quantile = quantile(norm, 0.5 + P.Level / 2.0);

    
    do{
        fd_set cs_cp = client_list;
        //cout << "start select" << endl;
        if(select(max_client+1, &cs_cp, NULL, NULL, NULL) == -1)
        {
            perror("Server-select() error!");
            exit(1);
        }
        //cout << "stop select" << endl;
        for(int it = 0;it<P.Njob;it++){
            if(FD_ISSET(fileno(clientstream[it]), &cs_cp)){
                BatchR* batchResult = new BatchR;
                batchResult->inputR(clientstream[it]);
                
                //cout << "client: " << it << " :"<< read << endl;
                
                IsBernoulli = IsBernoulli && batchResult->IsBernoulli;
                
                K = K + batchResult->I;
                Ksucc = Ksucc + batchResult->Isucc;
                
                Dif = batchResult->Mean - Mean;
                Mean = Mean + batchResult->Isucc * Dif / Ksucc;
                
                Dif = batchResult->M2 - M2;
                M2 = M2 + batchResult->Isucc * Dif / Ksucc;
                
                Var = M2 - pow(Mean, 2);
                
                
                stdev = sqrt(Var);
                Ksucc_sqrt = sqrt(Ksucc);
                CurrentWidth = 2 * Normal_quantile * stdev / Ksucc_sqrt;
                
                low = Mean - CurrentWidth / 2.0;
                up = Mean + CurrentWidth / 2.0;
                
                if(P.BoundedContinuous){
                    low = low * (1 - P.epsilon);
                    CurrentWidth = up - low;
                }
                
                delete batchResult;
                if(!P.alligatorMode){
                    cout << "\033[A\033[2K"<< "\033[A\033[2K" << "\033[A\033[2K" << "Total paths: " << K << "\t accepted paths: " << Ksucc << "\t Mean" << "=" << Mean << "\t stdev=" << stdev << "\t  width=" << CurrentWidth << endl;
                    cout << "% of run:\t";
                    printProgress(Ksucc, P.MaxRuns);
                    cout << "% of width:\t";
                    printProgress(1000*pow(-log(CurrentWidth),0.5), 1000*pow(-log(P.Width),0.5));
                }
                
                if(P.RareEvent || P.BoundedRE>0){
                    RelErr = CurrentWidth /  abs(Mean);
                }else RelErr = CurrentWidth / max(1.0, abs(Mean)); 
                
            }
        }
    }while ((RelErr > P.Width) && (K < P.MaxRuns));
    
    
    kill_client();
    
    //low = Mean - CurrentWidth / 2.0;
    //up = Mean + CurrentWidth / 2.0;
    
    cout << endl;
    
    if (IsBernoulli) {
        low = (0 > low) ? 0.0 : low;
        up = (1 < up) ? 1.0 : up;
        CurrentWidth = up - low;
        
    }
    
    
    time(&end);
    cpu_time_used = difftime(end, start);
    
	if(P.alligatorMode){
		cout << "alligatorResult" << endl;
		cout << Mean << endl;
		cout << "[" << low << "," << up << "]" << endl;
		cout << stdev << endl;
		cout << CurrentWidth << endl;
		cout << K << endl;
		cout << Ksucc << endl;
        cout << cpu_time_used << endl;
	} else{
        cout << "Estimated value: " << Mean << endl;
        cout << "Confidence interval: [" << low << "," << up << "]" << endl;
        if(IsBernoulli){
            cout << "The distribution look like a binomial!" << endl;
            using namespace boost::math;
            double successes = Ksucc * Mean;
            double l = binomial_distribution<>::find_lower_bound_on_p(
                    Ksucc, successes, (1-P.Level)/2);
            double u = binomial_distribution<>::find_upper_bound_on_p(
                    Ksucc, successes, (1-P.Level)/2);
            // Print Clopper Pearson Limits:
            cout << "Binomiale Confidence Interval: [" << l << "," << u << "]"<< endl;
            cout << "Binomiale Width: "<< u-l << endl;
            
        }
        
        cout << "Standard deviation: " << stdev << "\tWidth: " << CurrentWidth << endl;
        cout << "Total paths: " << K << "\tAccepted paths: " << Ksucc << endl;
	}
    
       
    
    if(P.verbose>0)cout << "\nSimulation Time: " << cpu_time_used << endl;
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
        
        ResultsFile << "\nConfidence level:\t" << P.Level << endl;
        cout << "Results are saved in '" << fn << "'" << endl;
        ResultsFile.close();
        
        
    }
}
