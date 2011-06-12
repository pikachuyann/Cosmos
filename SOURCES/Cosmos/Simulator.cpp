#include "Simulator.hpp"
#include "spn.hpp"
#include "LHA.hpp"
#include "EventsQueue.hpp"
#include "StandardNormalDist.hpp"
#include <iostream>
#include <set>
#include <math.h>
#include <float.h>
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

using namespace std;

Simulator::Simulator() {
}

void Simulator::Load() {
    N.Load();
    A.Load();
    int n = N.tr;
    EQ = new EventsQueue(n);
    simTime = 0;
    Initialized = false;
    IndexDist["UNIFORM"] = 1;
    IndexDist["EXPONENTIAL"] = 2;
    IndexDist["DETERMINISTIC"] = 3;
    IndexDist["LOGNORMAL"] = 4;
    IndexDist["TRIANGLE"] = 5;
    IndexDist["GEOMETRIC"] = 6;


    RandomNumber.seed((int)time(NULL));
    srand(time(NULL));

    BatchSize = 1000;
    MaxRuns =   1000000;

    ConfWidth = 0.001;
    ConfLevel = 0.99;

 

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


    set<int, less <int> > ent;
    ent = N.enabledTrans();
    set<int>::iterator it;
    Event E;
    //----------- Rare Event --------------
    N.Rate_Sum = 0;
    N.Origine_Rate_Sum = 0;
    //----------- /Rare Event -------------
    for (it = ent.begin(); it != ent.end(); it++) {
        GenerateEvent(E, (*it));
        (*EQ).insert(E);

    }
}

void Simulator::reset() {

    N.reset();
    A.reset(N.initMarking);
    simTime = 0;
    (*EQ).reset();
    RandomNumber.seed(RandomNumber());

    boost::mt19937 r(rand); //added 15/07/10   
    RandomNumber = r;

}

void Simulator::SimulateSinglePath() {
  

  bool QueueIsEmpty;
  AutEdge AE;
  
  t_interval EmptyInterval(DBL_MAX, -2);
  double D = 0.0;
  A.CurrentLocation = A.EnabledInitLocation(N.Marking);
  A.CurrentTime = 0;
  simTime = 0;
  Event F;
  
  //cout << "new trajectory" << endl;
  
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
      double E1_time = E1.time;
      int E1_transitionNum = E1.transition;
      
      //-------------- Rare Event -----------------
      /*N.Rate_Sum = 0;
      N.Origine_Rate_Sum = 0;
      
      for(int i=0; i< (*EQ).getSize(); i++){
	N.Origine_Rate_Sum = N.Origine_Rate_Sum + N.Origine_Rate_Table[(*EQ).InPosition(i).transition];
	N.Rate_Sum = N.Rate_Sum + N.Rate_Table[(*EQ).InPosition(i).transition];
	}*/
      A.Likelihood = (N.Origine_Rate_Table[E1_transitionNum] 
		      / N.Origine_Rate_Sum) * 
	(N.Rate_Sum / N.Rate_Table[E1_transitionNum]);
      //cout <<"Transition: "<< E1_transitionNum<<"\trate: " <<N.Rate_Table[E1_transitionNum] <<"\tsum rate: "<< N.Rate_Sum <<"\torigine rate: "<< N.Origine_Rate_Table[E1_transitionNum] << "\torigine sum: " <<N.Origine_Rate_Sum << "\tLikelihood: " << A.Likelihood << endl << endl << endl << endl;
      
      //-------------- /Rare Event ----------------
      
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
      int SE = A.GetEnabled_S_Edges(A.CurrentLocation, E1_transitionNum, DeltaT, OldMarking, N.Marking);  // get a valid transition in the automata
      
      if (SE < 0) {
	Result.first = false; // no transition => trajectory fail
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

	  
	   if(N.IsEnabled(E1_transitionNum)) {//check if the current transition is still enabled 
	    //------------- Rare Event -------------------
	    //GenerateEvent(F, E1_transitionNum);
	    //(*EQ).replace(F, 0); //replace the transition with the new generated time
	    } else (*EQ).remove(0);
	  
	  // Possibly adding Events corresponding to newly enabled-transitions
	  Dim1 V;
	  V = (N.PossiblyEn(E1_transitionNum)); //list of transitions that may enabled after firing TR
	  
	  for (vector<int>::iterator it = V.begin(); it != V.end(); it++) {
	    if (N.IsEnabled(*it)) {
	      if ((*EQ).TransTabValue(*it) < 0) {
		//--------- Rare Event ---------------
		//GenerateEvent(F, (*it));
		GenerateDummyEvent(F, (*it));
		//--------- /Rare Event ---------------
		(*EQ).insert(F);
	      } else {
		//--------- Rare Event ---------------
		/*if (N.Transition[(*it)].MarkingDependent) {
		  GenerateEvent(F, (*it));
		  (*EQ).remove((*EQ).TransTabValue(*it));
		  (*EQ).insert(F);
		  //(*EQ).replace(F, (*EQ).TransTabValue(*it)); 
		  }*/	
		//--------- /Rare Event ---------------
	      }
	    }
	  }
	  
	  // Possibly removing Events corresponding to newly disabled-transitions
	  V = (N.PossiblyDis(E1_transitionNum)); //list of transitions that may disabled after firing TR
	  
	  for (vector<int>::iterator it = V.begin(); it != V.end(); it++) {
	    if ((*EQ).TransTabValue(*it)>-1) {
	      if (!N.IsEnabled(*it))
		(*EQ).remove((*EQ).TransTabValue(*it));
	      else {
		//--------- Rare Event ---------------
		/*if (N.Transition[(*it)].MarkingDependent) {
		  GenerateEvent(F, (*it));
		  (*EQ).remove((*EQ).TransTabValue(*it));
		  (*EQ).insert(F);
		  //(*EQ).replace(F, (*EQ).TransTabValue(*it));
		  
		  }*/
	      //--------- /Rare Event ---------------
	      }
	    }
	  }

	  //--------- Rare Event ---------------
	  N.Rate_Sum = 0;
	  N.Origine_Rate_Sum = 0;
	  vector<int> Enabled_trans ((*EQ).getSize());
	  for(int i=0; i< (*EQ).getSize(); i++){ 
	    Enabled_trans[i] = (*EQ).InPosition(i).transition; 
	  };
	  for (vector<int>::iterator it = Enabled_trans.begin(); it != Enabled_trans.end(); it++) {
	    if(*it != N.tr-1){
	      if(N.IsEnabled(*it)){
		GenerateEvent(F, (*it));
		(*EQ).replace(F, (*EQ).TransTabValue(*it));
	      }else {
		(*EQ).remove((*EQ).TransTabValue(*it));
	      }
	    }; 
	  };
	  GenerateEvent(F, (N.tr-1));
	  (*EQ).replace(F, (*EQ).TransTabValue(N.tr-1));
	  //--------- /Rare Event ---------------
	  
	  //(*EQ).view();
	  /*for(int i =0; i< N.Marking.size();i++){
	    cout << N.Place[i].label <<" = "<< N.Marking[i] << " ; ";
	  };
	  cout << endl;*/

	  AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
	  QueueIsEmpty = (*EQ).isEmpty();
	}
      }
    }
  }
}

void Simulator::GenerateDummyEvent(Event& E, int Id) {
    E.transition = Id;
    E.time = 0.0;
    E.priority = N.GetPriority(Id);
    E.weight = 0.0;
}

void Simulator::GenerateEvent(Event& E, int Id) {

    double t = simTime;
    if (N.Transition[Id].transType == Timed) {
        vector<double> Param = N.GetDistParameters(Id);
        t += GenerateTime(N.Transition[Id].DistType, Param);
	//-------------- Rare Event -----------------
	N.Rate_Table[Id] = Param[0];
	N.Origine_Rate_Table[Id] = Param[1];
	N.Rate_Sum = N.Rate_Sum + Param[0];
	N.Origine_Rate_Sum = N.Origine_Rate_Sum + Param[1];
	//------------- /Rare Event -----------------
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
        
	//

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

void Simulator::RunSimulation() {
  
  clock_t start, end;
  double cpu_time_used;
  
  
  
  start = clock();
  normaldistr nd;

  
  double K = 0; //counter of generated paths
  double Ksucc = 0; //counter of succesfull generated paths
  double Ksucc_sqrt; //square root of Ksucc
  double Isucc;
  double Var = 0; //variance   
  double stdev = 0; //standard deviation
  
  double CurrentWidth = 1;
  double RelErr = 1;
  
  double Mean = 0;
  double OldMean = 0;
  double z_percentile = nd.invnormaldistribution(ConfLevel);
  double M2 = 0;
  double low, up;
  bool IsBernoulli = true;
  double Dif;
  
  //------------------ Rare Event -----------------
  ofstream logvalue("logvalue.dat",ios::out | ios::trunc);
  //----------------- /Rare Event -----------------

  cout << "START SIMULATION ..." << endl;
  do {
    Isucc = 0;
    while ((Isucc < BatchSize) && (K <= MaxRuns)) {
      
      SimulateSinglePath();
      
      
      if (Result.first) {
	//------------------ Rare Event -----------------
	logvalue << Result.second << endl ;
	//cout << "result:" << Result.second << endl;
	//----------------- /Rare Event -----------------
	Ksucc++;
	Isucc++;
	if (Result.second * (1 - Result.second) != 0) IsBernoulli = false;
	OldMean = Mean;
	Dif = Result.second - Mean;
	
	Mean = Mean + Dif / Ksucc;
	M2 = M2 + pow(Result.second, 2.0);
	if (Ksucc > 1) {
	  Var = M2 / (Ksucc - 1)-(Ksucc / (Ksucc - 1)) * pow(Mean, 2);
	}
	
      }
      
      reset();
      K++;
      
    }
    
    stdev = sqrt(Var);
    Ksucc_sqrt = sqrt(Ksucc);
    CurrentWidth = 2 * z_percentile * stdev / Ksucc_sqrt;
    //-------------- Rare Event -----------------
      cout << "\033[A\033[2K" << "Total paths: " << K << "\t accepted paths: " << Ksucc << "\t Mean" << "=" << Mean << "\t stdev=" << stdev << "\t  width=" << CurrentWidth << endl;

    //RelErr = CurrentWidth / max(1, abs(Mean)); <- ligne original
      RelErr = CurrentWidth /  abs(Mean);
    //------------- /Rare Event -----------------

    
    
  } while ((RelErr > ConfWidth) && (K < MaxRuns));
  
  
  
  low = Mean - CurrentWidth / 2;
  up = Mean + CurrentWidth / 2;
  if (IsBernoulli) {
    low = (0 > low) ? 0.0 : low;
    up = (1 < up) ? 1.0 : up;
    
  }
  cout << "\nEstimated value: " << Mean << endl;
  cout << "Confidence interval: [" << low << "," << up << "]" << endl;
  cout << "Standard deviation: " << stdev << "\tWidth: " << CurrentWidth << endl;
  cout << "Total paths: " << K << "\tAccepted paths: " << Ksucc << endl;
  
  

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  
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



