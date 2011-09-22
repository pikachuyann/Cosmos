
void Simulator::InitialEventsQueueRE() {

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
    GenerateEventRE(E, (*it));
    (*EQ).insert(E);

  }
}

void Simulator::SimulateSinglePathRE() {
  

  bool QueueIsEmpty;
  AutEdge AE;
  
  t_interval EmptyInterval(DBL_MAX, -2);
  double D = 0.0;
  A.CurrentLocation = A.EnabledInitLocation(N.Marking);
  //A.Likelihood = 1.0;
  A.CurrentTime = 0;
  simTime = 0;
  Event F;
  
  //cout << "new trajectory" << endl;
  
  Simulator::InitialEventsQueueRE();
  
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
	  //----------------- Rare Event ----------------------------------
	  Result.second = A.Likelihood * A.FormulaVal;
	  //-----------------/Rare Event ----------------------------------
	  return;
		    
	} else {
	  AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
	}
      }
      //----------------- Rare Event ----------------------------------
      Result.first = true;
      Result.second = 0;
      //-----------------/Rare Event ----------------------------------
      return;
    } else {
      Event E1 = (*EQ).InPosition(0);
      double E1_time = E1.time;
      int E1_transitionNum = E1.transition;
      if(doubleIS_mode){
	A.Likelihood = A.Likelihood * 
	  (N.Origine_Rate_Table[E1_transitionNum] / N.Origine_Rate_Sum) * 
	  ((N.Rate_Sum-N.Rate_Table[N.tr-1]) / N.Rate_Table[E1_transitionNum]);
      }else{
	A.Likelihood = A.Likelihood * 
        (N.Origine_Rate_Table[E1_transitionNum] / N.Origine_Rate_Sum) *
        (N.Rate_Sum / N.Rate_Table[E1_transitionNum]);
      }
      
      logvalue <<"Location:"<< A.CurrentLocation <<"\tTransition: "<< E1_transitionNum<<"\trate: " <<N.Rate_Table[E1_transitionNum] <<"\tsum rate: "<< N.Rate_Sum <<"\torigine rate: "<< N.Origine_Rate_Table[E1_transitionNum] << "\torigine sum: " <<N.Origine_Rate_Sum << "\tLikelihood: " << A.Likelihood << endl << //"\tMarking:" << N.Marking[0]<<":"<< N.Marking[1]<<":"<< N.Marking[6]<< 
	endl << endl << endl;
      
      
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
	  //----------------- Rare Event ----------------------------------
	  Result.second = A.Likelihood * A.FormulaVal;
	  //-----------------/Rare Event ----------------------------------
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
	//----------------- Rare Event ----------------------------------
	Result.first = true; // no transition => trajectory fail
	Result.second = A.Likelihood * A.FormulaVal;
	//-----------------/Rare Event ----------------------------------
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
	  //----------------- Rare Event ----------------------------------
	  Result.second = A.Likelihood * A.FormulaVal;
	  //-----------------/Rare Event ----------------------------------
	  
	  return;
	  
	} else {

	  
	   if(N.IsEnabled(E1_transitionNum)) {//check if the current transition is still enabled 
	    //------------- Rare Event -------------------
	    //GenerateEvent(F, E1_transitionNum);
	    //(*EQ).replace(F, 0); //replace the transition with the new generated time
	    } else (*EQ).remove(0);
	  
	  // Possibly adding Events corresponding to newly enabled-transitions
	  
	   //[ Dim1 V;
	   //[ V = (N.PossiblyEn(E1_transitionNum)); //list of transitions that may enabled after firing TR
	  
	  for (set<int>::iterator it = N.PossiblyEnabled[E1_transitionNum].begin(); it != N.PossiblyEnabled[E1_transitionNum].end(); it++) {
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
	  //V = (N.PossiblyDis(E1_transitionNum)); //list of transitions that may disabled after firing TR
	  
	  for (set<int>::iterator it = N.PossiblyDisabled[E1_transitionNum].begin(); it != N.PossiblyDisabled[E1_transitionNum].end(); it++) {
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
		GenerateEventRE(F, (*it));
		(*EQ).replace(F, (*EQ).TransTabValue(*it));
	      }else {
		(*EQ).remove((*EQ).TransTabValue(*it));
	      }
	    }; 
	  };
	  GenerateEventRE(F, (N.tr-1));
	  if(!doubleIS_mode){
	    (*EQ).replace(F, (*EQ).TransTabValue(N.tr-1));
	  }
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

void Simulator::GenerateEventRE(Event& E, int Id) {

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

