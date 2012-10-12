#include <iomanip>


void generateLHAfun(double ron,int N,vector< vector< vector<double> > >& Plast ,vector<double>& RewardArray, double H, vector< vector<double> >& M){
    
    unsigned long Xlastmax = Plast[0].size()-1;
    
    cout << "generate LHA" << endl;
    
    
    ofstream LhaFile("generated.lha", ios::out | ios::trunc);
    ofstream StrategieFile("Strat",ios::out | ios::trunc);
    
    
    LhaFile << "NbVariables = " << /*N*N*(Xlastmax+1)+*/ 2 << ";" << endl; 
    LhaFile << "NbLocations = "<< N*(Xlastmax+1)+1 << ";" << endl; 

    LhaFile << "const double H = "<< H << ";" << endl; 
    

    /* time record the elapsed time;
        Xlast is equal to 0 if the drone is currently detected and 1 otherwise
     */
    
    LhaFile << "VariablesList = {time, Reward";
    /*for(int i=0;i<N;i++)
      LhaFile << ", W"<<i;*/
    /*for(int i=0;i<N;i++)
      LhaFile << ", Out"<<i;*/
    /*for(int i=0;i<N;i++)
        for(int Xlast=0;Xlast<=Xlastmax;Xlast++)
            for(int j=0;j<N;j++)
                LhaFile << ", Plast"<<i<<"_"<< Xlast <<"_"<<j;	*/
    LhaFile << "} ;"<< endl; 
    
    
    LhaFile << "LocationsList = { lf";
    for(int i=0;i<N;i++){
        for(int Xlast=0;Xlast<=Xlastmax;Xlast++){
            LhaFile << ", lp"<<i<<"_"<<Xlast;
        }
    }
    LhaFile << "} ;"<< endl; 
    
    
    /*for(int i=0;i<N;i++)
        for(int Xlast=0;Xlast<=Xlastmax;Xlast++)
            for(int j=0;j<N;j++){
				LhaFile << "Plast"<<i<<"_"<<Xlast<<"_"<<j<<" =";
                LhaFile << "AVG(Last(Plast"<<i<<"_"<<Xlast<<"_"<<j<<"));"<<endl;   
			}*/
    
    LhaFile << "Reward=AVG(Last(Reward));"<<endl;
    
    LhaFile << "InitialLocations = {lp0_0};"<< endl; 

    LhaFile << "FinalLocations = {lf};"<< endl; 

    LhaFile << "Locations={"<< endl; 
    //LhaFile << "(li, TRUE, (time:1));"<< endl; 
    LhaFile << "(lf, TRUE, (time:1));"<< endl; 
    //LhaFile << "(la, TRUE, (time:1));"<< endl; 
    for(int i=0;i<N;i++){
        LhaFile << "(lp"<<i<<"_0, V"<<i<<"=1 , (time:1));"<< endl;
        
        StrategieFile << "Strategy for drone last located in "<<i;
        
        //Print strategy
        StrategieFile << ", "<< 0 << " round ago" << endl;
        //The drone must not be in a activate sensor location
        for (int j =1;j<N;j++){ 
            StrategieFile << "\tSensor " << j;
            //j start at 1 because 0 is the bottom position no sensor
            if (ron + Plast[i][0][j]*RewardArray[j] >=0){
                StrategieFile << " on" << endl;
            }else{
                StrategieFile << " off" << endl;
            }
        }
        
		cout <<setw(4)<< i<< "[";
		for (int j=0; j< Plast[0][0].size(); j++){
			cout << "->"<<setw(3)<<j<<"[";
			for (int Xlast=0; Xlast<Plast[0].size(); Xlast++){
				if (ron + Plast[i][Xlast][j]*RewardArray[j] >=0){
					cout << " on ";
				}else{
					cout << " off";
				}
				
			}
			cout << "]";
		}
		cout << "]"<< endl;
		
        for(int Xlast=1;Xlast<=Xlastmax;Xlast++){
            
            /*
            
            for(int Xlast=1;Xlast<=Xlastmax;Xlast++){*/
                LhaFile << "(lp"<<i<<"_"<<Xlast<< ", (TRUE";
                StrategieFile << "Strategy for drone last located in "<< i;
                StrategieFile <<", "<< Xlast << " round ago" << endl;
                //The drone must not be in a activate sensor location
                for (int j =1;j<N;j++){ 
                    StrategieFile << "\tSensor " << j;
                    //j start at 1 because 0 is the bottom position no sensor
                    if (ron + Plast[i][Xlast][j]*RewardArray[j] >=0 ){
                        //LhaFile<<"& V"<<j<<"=0";
                        StrategieFile << " on" << endl;
                    }else{
                        StrategieFile << " off" << endl;
                    }
                }
                
                LhaFile << ") , (time:1));"<< endl;     
            //}
        }
    }
        
     
    LhaFile << "};"<<endl; 

    LhaFile << "Edges={"<< endl; 
    
    //Edges to the final state.
    for (int v=0 ; v<N; v++) {
        for(int Xlast=0;Xlast<=Xlastmax;Xlast++)
            LhaFile << "((lp"<<v<<"_"<< Xlast <<",lf),ALL, time>=H,#);"<<endl;
    }
    
    for (int v=0 ; v<N; v++) {
        
        for(int Xlast=0;Xlast<=Xlastmax;Xlast++){
            
            //count the number of on sensor
            int nbSensorOn = 0;
            for(int x=1;x<N;x++)
                if (ron + Plast[v][Xlast][x]*RewardArray[x] >=0)nbSensorOn++;
            
            //Drone undetected => Xlast++ 
            LhaFile << "((lp"<<v<<"_"<< Xlast <<",lp"<<v<<"_";
            LhaFile << min(Xlast+1,(int)Xlastmax) <<"),ALL";
            int compt = 0;
            for (int x=0 ; x<N; x++) {
                if ((M[v][x]>0) & ((ron + Plast[v][Xlast][x]*RewardArray[x] >=0) & (x>0))){
                    if(compt >0){LhaFile << " ,";}
                    else LhaFile << "\\{";
                    compt++;
					for(int xnb=0 ; xnb<N; xnb++)
						LhaFile << "Tr" << xnb << "_" << x << " ";
                }
            }
            if(compt>0)LhaFile << "}";
            LhaFile << ", time <=H,";
			if(nbSensorOn>0){
				LhaFile << "{Reward = Reward " << ron * nbSensorOn << " }";
			} else LhaFile << "#";
            LhaFile << ");"<< endl;
            
            //Drone detected in location x_0
            for (int x=1 ; x<N; x++) {
                //x start in 1 because there is no sensor in 0
                if ((ron + Plast[v][Xlast][x]*RewardArray[x]>=0) &(Xlast>0 | M[v][x]>0) ){
                    LhaFile << "((lp"<<v<<"_"<< Xlast <<",lp"<<x<<"_0),";
                    LhaFile << "ALL, time <=H, { ";
                    LhaFile << "Reward = Reward + " << RewardArray[x] << "+"<< ron * nbSensorOn;
                    //LhaFile <<", Plast"<<v<<"_"<<Xlast<<"_"<<x<<"=Plast"<<v<<"_"<< Xlast <<"_"<<x<<"+1";
                    //LhaFile << ", Out"<<v<<"=Out"<<v<<"+1";
                    LhaFile << "});"<<endl;
                }
            }
        }
    }
    
    
    
    /*LhaFile << "((li,la),ALL,  time <= H,#);"<< endl; 
    LhaFile << "((li,lf),#,  time = H,{Plast0_0=Plast0_0/Out0";
    for(int i=0; i<N;i++)
      for(int j=0; j<N; j++)
	if(i!=0 && j!=0)
	  LhaFile <<", Plast"<<i<<"_"<<j<<"=Plast"<<i<<"_"<<j<<"/Out"<<j;
    LhaFile <<"});"<< endl; 
    
    for(int i=0; i< N;i++)      
      for(int j=0; j<N; j++){
	 LhaFile << "((la,lp"<<i<<"),#, Xlast="<<j<<"& W"<<i<<"=0,{Plast"<<j<<"_"<<0<<"=Plast"<<j<<"_"<<0<<"+1, Out"<<j<<"=Out"<<j<<"+1});"<< endl;
	 LhaFile << "((la,lp"<<i<<"),#, Xlast="<<j<<"& W"<<i<<"=1,{Plast"<<j<<"_"<<i<<"=Plast"<<j<<"_"<<i<<"+1, Out"<<j<<"=Out"<<j<<"+1,Xlast="<<i<<"});"<< endl;
	
      }
      
   for(int i=0; i< N;i++)    
      LhaFile << "((lp"<<i<<", li),#, #, #);"<< endl;
      
   */
    LhaFile << "};"<< endl; 
    
    LhaFile.close();
    StrategieFile.close();
    
    
}