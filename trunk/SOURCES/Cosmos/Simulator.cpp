#include "Simulator.hpp"
//#include "SimulatorRE.h"
#include <iostream>
#include <set>
#include <math.h>
#include <float.h>
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <time.h>


using namespace std;

Simulator::Simulator() {
	N.Load();//load the GSPN
	A.Load(); //load the LHA
	int n = N.tr; //n his the number of transition
	EQ = new EventsQueue(n); //initialization of the event queue
	simTime = 0; //initialization of the time
	Initialized = false;
	IndexDist["UNIFORM"] = 1;
	IndexDist["EXPONENTIAL"] = 2;
	IndexDist["DETERMINISTIC"] = 3;
	IndexDist["LOGNORMAL"] = 4;
	IndexDist["TRIANGLE"] = 5;
	IndexDist["GEOMETRIC"] = 6;
	
	//logvalue.open("outcosmos",fstream::out);
	
	//Initialize random generator
	RandomNumber.seed(time(NULL));
	srand(time(NULL));
	
	BatchSize = 1000;
}

Simulator::Simulator(const Simulator& orig) {
}

Simulator::~Simulator() {
}

void Simulator::SetBatchSize(int RI) {
	BatchSize = RI;
}

double Simulator::max(double a, double b) {
	if (a >= b) return a;
	else return b;
}

void Simulator::InitialEventsQueue() {
	Initialized = true;
	
	set<int, less <int> > ent;
	ent = N.enabledTrans();
	set<int>::iterator it;
	Event E;
	for (it = ent.begin(); it != ent.end(); it++) {
		GenerateEvent(E, (*it));
		(*EQ).insert(E);
	}
}

void Simulator::reset() {
	//cerr << "test" << endl;
	N.reset();
	A.reset(N.initMarking);
	simTime = 0;
	(*EQ).reset();
	
	RandomNumber.seed(RandomNumber());
	RandomNumber.seed(rand());
	
}

void Simulator::returnResultTrue(vector<int>marking, double D){
	A.UpdateLinForm(marking);
	A.UpdateLhaFunc(A.CurrentTime, D);
	A.UpdateFormulaVal();
	Result.first = true;
	Result.second = A.FormulaVal;
	return;
}
void Simulator::returnResultFalse(){
	Result.first = false;
	return;
}


void Simulator::updateLHA(int EdgeIndex, double DeltaT,vector<int> marking){
	A.DoElapsedTimeUpdate(DeltaT, marking);
	A.UpdateLinForm(marking);
	A.UpdateLhaFunc(A.CurrentTime, DeltaT);
	A.DoEdgeUpdates(EdgeIndex, marking);
	A.CurrentTime += DeltaT;
	simTime = A.CurrentTime;
	A.CurrentLocation = A.Edge[EdgeIndex].Target;
}


void Simulator::updateSPN(int E1_transitionNum){
	Event F;
	if (N.IsEnabled(E1_transitionNum)) {//check if the current transition is still enabled
		
		GenerateEvent(F, E1_transitionNum);
		(*EQ).replace(F, 0); //replace the transition with the new generated time
		
	} else (*EQ).remove(0);
	
	// Possibly adding Events corresponding to newly enabled-transitions
	
	for (set<int>::iterator it = N.PossiblyEnabled[E1_transitionNum].begin(); it != N.PossiblyEnabled[E1_transitionNum].end(); it++) {
		if (N.IsEnabled(*it)) {
			if ((*EQ).TransTabValue(*it) < 0) {
                GenerateEvent(F, (*it));
                (*EQ).insert(F);
				
				
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
			if (!N.IsEnabled(*it))
                (*EQ).remove((*EQ).TransTabValue(*it));
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
}

void Simulator::updateLikelihood(int i){
	return;
}

bool Simulator::SimulateOneStep(AutEdge* AEref){
	AutEdge AE = *AEref;
	if ((*EQ).isEmpty()) {
		while (AE.Index>-1) {
			updateLHA(AE.Index,AE.FiringTime - A.CurrentTime, N.Marking);
			if (A.isFinal(A.CurrentLocation)) {
				returnResultTrue(N.Marking,0.0);
				return false;
			} else AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
		}
		returnResultFalse();
		return false;
	} else {
		Event E1 = (*EQ).InPosition(0);
		
		int E1_transitionNum = E1.transition;
		updateLikelihood(E1_transitionNum);
		
		while (E1.time >= AE.FiringTime) {
			updateLHA(AE.Index,AE.FiringTime - A.CurrentTime, N.Marking);
			if (A.isFinal(A.CurrentLocation)) {
				returnResultTrue(N.Marking, 0.0);
				return false;
			} else AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
		}
		
		vector<int> OldMarking = N.Marking;
		N.fire(E1_transitionNum);
		
		double DeltaT = E1.time - A.CurrentTime;
		int SE = A.GetEnabled_S_Edges(A.CurrentLocation, E1_transitionNum, DeltaT, OldMarking, N.Marking);
		
		if (SE < 0) {
			returnResultFalse();
			return false;
		} else {
			updateLHA(SE, DeltaT, OldMarking);
			if (A.isFinal(A.CurrentLocation)) {
				returnResultTrue(OldMarking, 0.0);					
				return false;
			} else {
				updateSPN(E1_transitionNum);
				AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
			}
		}
	}
	return true;
}

void Simulator::SimulateSinglePath() {
	
	AutEdge AE;
	A.CurrentLocation = A.EnabledInitLocation(N.Marking);
	A.CurrentTime = 0;
	simTime = 0;
	
	Simulator::InitialEventsQueue();
	AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
	
	bool continueb = true;
	while ((!(*EQ).isEmpty() || AE.Index > -1) && continueb ) {
		continueb = SimulateOneStep(&AE);
	}
}

void Simulator::GenerateEvent(Event& E, int Id) {
	
	double t = simTime;
	if (N.Transition[Id].transType == Timed) {
		vector<double> Param = getParams(Id); //N.GetDistParameters(Id);
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

vector<double> Simulator::getParams(int Id){
	return N.GetDistParameters(Id);
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
			
			//-------------- Rare Event -----------------
			//cout << "rate:" << param[0] << endl;
			if(param[0] == 0) { return 1e200; };
			//------------- /Rare Event -----------------
			
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
		{//GOEMETRIC
			boost::uniform_real<> UNIF(0, 1);
			boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
			double p = gen();
			if (p >= param[0]) return param[1];
			else return param[1] * ceil(log(p / param[0]) / log(1 - param[0]) + 1);
		}
			
		default: cout << "\nUnknown distribution !" << endl;
			break;
	}
	return DBL_MIN;
	
}


BatchR* Simulator::RunBatch(){
	double Dif=0;
	//double Y = 0;
	BatchR* batchResult = new BatchR();
	
	while (batchResult->Isucc < BatchSize) {
		
		
		SimulateSinglePath();
		
		
		if (Result.first) {
			//------------------ Rare Event -----------------
			//logvalue << Result.second << endl ;
			//----------------- /Rare Event -----------------
			batchResult->Isucc++;
			
			if (Result.second * (1 - Result.second) != 0) batchResult->IsBernoulli = false;
			
			
			Dif = Result.second - batchResult->Mean;
			batchResult->Mean += Dif / batchResult->Isucc;
			
			Dif = pow(Result.second, 2) - batchResult->M2;
			batchResult->M2 += Dif / batchResult->Isucc;
			
			/*if (Isucc > 1) {
			 Dif = pow(Result.second, 2) - Y;
			 Y = Y + Dif / (Isucc - 1);
			 } else x1sqr = pow(Result.second, 2);*/
		}
		
		reset();
		batchResult->I++;
		
	}
	
	return (batchResult);
	
}
