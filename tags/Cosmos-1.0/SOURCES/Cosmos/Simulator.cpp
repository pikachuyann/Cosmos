/*******************************************************************************
 *									       *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)dels (S)tochastique *
 *									       *
 * Copyright (C) 2009-2011 LSV, ENS Cachan & CNRS & INRIA                      *
 * Author: Paolo Ballarini & Hilal Djafri                                      *
 * Website: http://www.lsv.ens-cachan.fr/Software/Cosmos                       *
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
 *                                                                             *
 *******************************************************************************
 */



#include "Simulator.hpp"
#include "spn.hpp"
#include "LHA.hpp"
#include "EventsQueue.hpp"
#include <iostream>
#include <set>
#include <math.h>
#include <float.h>
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/math/distributions/normal.hpp>
#include <time.h>


using namespace std;

Simulator::Simulator() {
}

void Simulator::Load() {
    N.Load();
    A.Load();
  
    EQ = new EventsQueue(N.tr);
    simTime = 0;
    Initialized = false;
    IndexDist["UNIFORM"] = 1;
    IndexDist["EXPONENTIAL"] = 2;
    IndexDist["DETERMINISTIC"] = 3;
    IndexDist["LOGNORMAL"] = 4;
    IndexDist["TRIANGLE"] = 5;
    IndexDist["GEOMETRIC"] = 6;
    IndexDist["ERLANG"] = 7;
    IndexDist["GAMMA"] = 8;


    RandomNumber.seed(time(NULL));
    srand(time(NULL));
    
    Krand=0;
    

    BatchSize = 1000;
    MaxRuns = 100000000;

    ConfWidth = 0.001;
    ConfLevel = 0.99;
	
    ResidualTime=new vector<double> (N.tr); 
    ActDate=new vector<double> (N.tr);
}

Simulator::Simulator(const Simulator& orig) {
}

Simulator::~Simulator() {
}

void Simulator::SetConfWidth(double w) {
    ConfWidth = w;
}

void Simulator::SetConfLevel(double l) {
    ConfLevel = l;
}

void Simulator::SetBatchSize(int RI) {
    BatchSize = RI;
}

void Simulator::SetMaxRuns(long int RX) {
    MaxRuns = RX;
}

void Simulator::ViewParameters() {
    cout << "Confidence interval width:      " << ConfWidth << endl;
    cout << "Confidence interval level:      " << ConfLevel << endl;
    cout << "Maximum number of trajectories: " << MaxRuns << endl;
    cout << "Batch size:                     " << BatchSize << endl;
}

double Simulator::max(double a, double b) {
    if (a >= b) return a;
    else return b;
}

void Simulator::InitialEventsQueue() {
    Initialized = true;
	
     for(int t=0;t<N.tr;t++){
	 (*ResidualTime)[t]=0;
	 (*ActDate)[t]=-1;
	}
    set<int, less <int> > ent;
    ent = N.enabledTrans();
    set<int>::iterator it;
    Event E;
    for (it = ent.begin(); it != ent.end(); it++) {
        GenerateEvent(E, (*it));
        (*EQ).insert(E);
		
		if(N.Transition[(*it)].AgeMemory){
		  (*ResidualTime)[(*it)]=E.time;
		  (*ActDate)[(*it)]=E.time;
		}		
    }
}

void Simulator::reset() {

    N.reset();
    A.reset(N.initMarking);
    simTime = 0;
    (*EQ).reset();  
    
    if(Krand>=10000)
    {
      Krand=0;
      srand(RandomNumber());      
    }
    else
      Krand++;   
    
    RandomNumber.seed(rand());
}

void Simulator::SimulateSinglePath() {


    bool QueueIsEmpty;
    AutEdge AE;   
    double D = 0.0;
    A.CurrentLocation = A.EnabledInitLocation(N.Marking);
    A.CurrentTime = 0;
    simTime = 0;
    Event F;
    
    Simulator::InitialEventsQueue();
    QueueIsEmpty = (*EQ).isEmpty();
    AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);


    while (!QueueIsEmpty || AE.Index > -1) {

        if (QueueIsEmpty) {
            while (AE.Index>-1) {

                double DeltaT = AE.FiringTime - A.CurrentTime;
                A.DoElapsedTimeUpdate(DeltaT, N.Marking);
                A.UpdateLinForm(N.Marking);
                A.UpdateLhaFunc(A.CurrentTime, DeltaT);
                A.DoEdgeUpdates(AE.Index, N.Marking);
                A.CurrentTime += DeltaT;
                simTime = A.CurrentTime;
                A.CurrentLocation = A.Edge[AE.Index].Target;

                if (A.isFinal(A.CurrentLocation)) {
                    A.UpdateLinForm(N.Marking);
                    A.UpdateLhaFunc(A.CurrentTime, D);
                    A.UpdateFormulaVal();
                    Result.first = true;
                    Result.second = A.FormulaVal;

                    return;

                } else {
                    AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);

                }
            }
            Result.first = false;

            return;
        } else {
            Event E1 = (*EQ).InPosition(0);
            
            int E1_transitionNum = E1.transition;

            while (E1.time >= AE.FiringTime) {
	      
                double DeltaT = AE.FiringTime - A.CurrentTime;
                A.DoElapsedTimeUpdate(DeltaT, N.Marking);
                A.UpdateLinForm(N.Marking);
                A.UpdateLhaFunc(A.CurrentTime, DeltaT);
                A.DoEdgeUpdates(AE.Index, N.Marking);
                A.CurrentTime += DeltaT;
                simTime = A.CurrentTime;
                A.CurrentLocation = A.Edge[AE.Index].Target;
		
                if (A.isFinal(A.CurrentLocation)) {
                    A.UpdateLinForm(N.Marking);
                    A.UpdateLhaFunc(A.CurrentTime, D);
                    A.UpdateFormulaVal();
                    Result.first = true;
                    Result.second = A.FormulaVal;

                    return;

                } else {
                    AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);

                }


            }

            vector<int> OldMarking = N.Marking;
            N.fire(E1_transitionNum);
            double DeltaT = E1.time - A.CurrentTime;
            int SE = A.GetEnabled_S_Edges(A.CurrentLocation, E1_transitionNum, DeltaT, OldMarking, N.Marking);

            if (SE < 0) {
                Result.first = false;

                return;
            } else {
                A.DoElapsedTimeUpdate(DeltaT, OldMarking);
                A.UpdateLinForm(OldMarking);
                A.UpdateLhaFunc(A.CurrentTime, DeltaT);
                A.DoEdgeUpdates(SE, OldMarking);
                A.CurrentTime += DeltaT;
                simTime = A.CurrentTime;
                A.CurrentLocation = A.Edge[SE].Target;

                if (A.isFinal(A.CurrentLocation)) {
                    A.UpdateLinForm(OldMarking);
                    A.UpdateLhaFunc(A.CurrentTime, D);
                    A.UpdateFormulaVal();
                    Result.first = true;
                    Result.second = A.FormulaVal;

                    return;

                } else {
                    if (N.IsEnabled(E1_transitionNum)) {//check if the current transition is still enabled
                        GenerateEvent(F, E1_transitionNum);
                        (*EQ).replace(F, 0); //replace the transition with the new generated time
						if(N.Transition[E1_transitionNum].AgeMemory){
						  (*ActDate)[E1_transitionNum]=A.CurrentTime;
						  (*ResidualTime)[E1_transitionNum]=F.time-A.CurrentTime;
						}

                    } else {
					  (*EQ).remove(0);
					  if(N.Transition[E1_transitionNum].AgeMemory){
						  (*ActDate)[E1_transitionNum]=-1;						  
						}
					}

                    // Possibly adding Events corresponding to newly enabled-transitions

                    for (set<int>::iterator it = N.PossiblyEnabled[E1_transitionNum].begin(); it != N.PossiblyEnabled[E1_transitionNum].end(); it++) {
                        if (N.IsEnabled(*it)) {
                            if ((*EQ).TransTabValue(*it) < 0) {
								if(N.Transition[(*it)].AgeMemory){
								  if((*ActDate)[(*it)]==-1){
									GenerateEvent(F, (*it));
									(*EQ).insert(F);
									(*ResidualTime)[(*it)]=F.time-A.CurrentTime;
								  }
								  else{
									GenerateEvent(F, (*it));
									F.time=A.CurrentTime+(*ResidualTime)[(*it)];
									(*EQ).insert(F);
									
								  }
								  (*ActDate)[(*it)]=A.CurrentTime;								 						  
								}
								else{									
								    GenerateEvent(F, (*it));									
									(*EQ).insert(F);
								}


                            } else {
                                if (N.Transition[(*it)].MarkingDependent) {
                                    GenerateEvent(F, (*it));
                                    (*EQ).replace(F, (*EQ).TransTabValue(*it));

                                }

                            }
                        }

                    }

                    // Possibly removing Events corresponding to newly disabled-transitions


                    for (set<int>::iterator it = N.PossiblyDisabled[E1_transitionNum].begin(); it != N.PossiblyDisabled[E1_transitionNum].end(); it++) {
                        if ((*EQ).TransTabValue(*it)>-1) {
                            if (!N.IsEnabled(*it)){
							  (*EQ).remove((*EQ).TransTabValue(*it));
							  if(N.Transition[(*it)].AgeMemory)
								(*ResidualTime)[(*it)]=A.CurrentTime-(*ActDate)[(*it)];
							}
                            else {
                                if (N.Transition[(*it)].MarkingDependent) {
                                    GenerateEvent(F, (*it));
                                    (*EQ).replace(F, (*EQ).TransTabValue(*it));

                                }
                            }
                        }
                    }

                    //
                    for (set<int>::iterator it = N.FreeMarkDepT[E1_transitionNum].begin(); it != N.FreeMarkDepT[E1_transitionNum].end(); it++) {

                        if (N.IsEnabled(*it)) {
                            if ((*EQ).TransTabValue(*it) < 0) {
                                GenerateEvent(F, (*it));
                                (*EQ).insert(F);


                            } else {
                                GenerateEvent(F, (*it));
                                (*EQ).replace(F, (*EQ).TransTabValue(*it));
                            }
                        }

                    }
                    AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
                    QueueIsEmpty = (*EQ).isEmpty();
                }
            }
        }
    }
}

void Simulator::GenerateEvent(Event& E, int Id) {

    double t = simTime;
    if (N.Transition[Id].transType == Timed) {
        vector<double> Param = N.GetDistParameters(Id);
        t += GenerateTime(N.Transition[Id].DistType, Param);
    }
    double w;
    vector<double> wParam(1, N.GetWeight(Id));
    string dist = "EXPONENTIAL";
    w = GenerateTime(dist, wParam);
    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id);
    E.weight = w;

}

double Simulator::GenerateTime(string& distribution, vector<double> &param) {

    switch (IndexDist[distribution]) {
        case 1:
        {//UNIF			
            boost::uniform_real<> UNIF(param[0], param[1]);
            boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
            return gen();
            break;
        }

        case 2:
        {//EXP        
            //Exponential distribution is the only marking dependent parameters. Check of validity is required
            if (param[0] <= 0) {
                cout << "Exponential ditribution should be with rate > 0\n End of Simulation" << endl;
                exit(1);
            }

            boost::exponential_distribution<> EXP(param[0]);            
            boost::variate_generator<boost::mt19937&, boost::exponential_distribution<> > gen(RandomNumber, EXP);
            return gen();

        }

        case 3:
        {//DETERMINISTIC
            return param[0];
        }

        case 4:
        {//LogNormal
            boost::lognormal_distribution<> LOGNORMAL(param[0], param[1]);
            boost::variate_generator<boost::mt19937&, boost::lognormal_distribution<> > gen(RandomNumber, LOGNORMAL);
            return gen();
        }

        case 5:
        {//Triangle
            boost::triangle_distribution<> TRIANGLE(param[0], param[1], param[2]);
            boost::variate_generator<boost::mt19937&, boost::triangle_distribution<> > gen(RandomNumber, TRIANGLE);
            return gen();
        }
        
        case 6:
        {//GEOMETRIC           
            boost::geometric_distribution<> GEO(1-param[0]);
            boost::variate_generator<boost::mt19937&, boost::geometric_distribution<> > gen(RandomNumber, GEO);            
	    return param[1]*gen();
            
        }
        
        case 7:
        {//ERLANG           
            boost::uniform_real<> UNIF(0, 1);
            boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
	    double prod=1;
	    for(int i=0;i<param[0];i++)
	      prod=prod*gen();
	    return -log(prod)/param[1];
            
        }
        case 8:
        {//GAMMA      
        boost::gamma_distribution<> GAMMA(param[0]);        
        boost::variate_generator<boost::mt19937&, boost::gamma_distribution<> > gen(RandomNumber, GAMMA);
	return param[1]*gen();            
        }

        default: cout << "\nUnknown distribution ' "<<distribution<<" ' ! " << endl;
            break;
    }
    return DBL_MIN;

}

void Simulator::RunSimulation() {

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
   
    double Normal_quantile;

    double low, up;
    bool IsBernoulli = true;
   


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

    boost::math::normal norm;
    Normal_quantile = quantile(norm, 0.5 + ConfLevel / 2.0);


    do {
        Isucc = 0;
        while ((Isucc < BatchSize) && (K <= MaxRuns)) {

            SimulateSinglePath();


            if (Result.first) {
                Ksucc++;
                Isucc++;
                if (Result.second * (1 - Result.second) != 0) IsBernoulli = false;
		Mean=((Ksucc-1)*Mean+Result.second)/Ksucc;
		M2=((Ksucc-1)*M2+pow(Result.second,2.0))/Ksucc;   
		reset();
		K++;
	    }
        
	}
        Var=M2-pow(Mean,2.0);
        if (Ksucc > 1) {            
            Var = Ksucc * Var / (Ksucc-1); //non biased variance;
        }
        stdev = sqrt(Var);
        Ksucc_sqrt = sqrt(Ksucc);
        CurrentWidth = 2 * Normal_quantile * stdev / Ksucc_sqrt;
        cout << "\r Total paths: " << K << "\t accepted paths: " << Ksucc << "\t Mean" << "=" << Mean << "\t stdev=" << stdev << "\t  width=" << CurrentWidth;


        RelErr = CurrentWidth / max(1, abs(Mean));

    } while ((RelErr > ConfWidth) && (K < MaxRuns));



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
    string fn = N.Path;
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
