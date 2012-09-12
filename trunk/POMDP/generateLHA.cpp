

/*void generateStrat(vector< vector<double> >& Plast,int N,int x,int y,double ron,double rdet,ostream f){
    //f<< "{";
    for (int i =0;i<N;i++){
        //if (i>0)f<<" , ";
        f << "W" << i << "=";
        if (ron + Plast[y][i]*rdet<0)f<<"0";
        else f<<"1";
    }
    f<<",Plast"<<x<<"_"<<y<<"=Plast"<<x<<"_"<<y<<"+1, Out"<<x<<"=Out"<<x<<"+1";
    
    //f<< "}";
    
}*/

void generateLHAfun(double ron,double rdet,int N, vector<int>  &W,vector< vector<double> >& Plast , double H ){
    
    int Xlastmax = 1;
    
    cout << "generate LHA" << endl;
    
    
    ofstream LhaFile("generated.lha", ios::out | ios::trunc);
    ofstream StrategieFile("Strat",ios::out | ios::trunc);
    
    
    LhaFile << "NbVariables = " << N*N+1 << ";" << endl; 
    LhaFile << "NbLocations = "<< N*(Xlastmax+1)+1 << ";" << endl; 

    LhaFile << "const double H = "<< H << ";" << endl; 
    

    /* time record the elapsed time;
        Xlast is equal to 0 if the drone is currently detected and 1 otherwise
     */
    
    LhaFile << "VariablesList = {time";
    /*for(int i=0;i<N;i++)
      LhaFile << ", W"<<i;*/
    /*for(int i=0;i<N;i++)
      LhaFile << ", Out"<<i;*/
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            LhaFile << ", Plast"<<i<<"_"<<j;	
    LhaFile << "} ;"<< endl; 
    
    
    LhaFile << "LocationsList = { lf";
    for(int i=0;i<N;i++){
        for(int Xlast=0;Xlast<=Xlastmax;Xlast++){
            LhaFile << ", lp"<<i<<"_"<<Xlast;
        }
    }
    LhaFile << "} ;"<< endl; 
    
    
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
	LhaFile << "AVG(Last(Plast"<<i<<"_"<<j<<"));"<<endl;    
   

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
            if (ron + Plast[i][j]*rdet>=0){
                StrategieFile << " on" << endl;
            }else{
                StrategieFile << " off" << endl;
            }
        }

        for(int Xlast=1;Xlast<=Xlastmax;Xlast++){
            LhaFile << "(lp"<<i<<"_"<<Xlast<< ", (TRUE";
            StrategieFile << "Strategy for drone last located in "<< i;
            StrategieFile <<", "<< Xlast << " round ago" << endl;
            //The drone must not be in a activate sensor location
            for (int j =1;j<N;j++){ 
                StrategieFile << "\tSensor " << j;
                //j start at 1 because 0 is the bottom position no sensor
                if (ron + Plast[i][j]*rdet>=0){
                    LhaFile<<"& V"<<j<<"=0";
                    StrategieFile << " on" << endl;
                }else{
                    StrategieFile << " off" << endl;
                }
            }

            LhaFile << ") , (time:1));"<< endl;     
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
        //Drone undetected => Xlast+1
        for(int Xlast=0;Xlast<=Xlastmax;Xlast++){
            LhaFile << "((lp"<<v<<"_"<< Xlast <<",lp"<<v<<"_"<< min(Xlast+1,Xlastmax) <<"),";
            LhaFile << "ALL, time <=H ";
            /*LhaFile << "& (";
             //The Drone is in location i where the sensor is turn off
             for (int i =0;i<N;i++){
             if(i>0)LhaFile<< " | ";
            if (ron + Plast[v][i]*rdet<0)LhaFile<<"V"<<i<<"=1";
             }
             LhaFile << ")";*/
            LhaFile << ", #);"<< endl;
        }
            
        //Drone detected
        for (int x=1 ; x<N; x++) {
            //x start in 1 because there is no sensor in 0les
            if (ron + Plast[v][x]*rdet>=0){
                for(int Xlast=0;Xlast<=Xlastmax;Xlast++){
                    LhaFile << "((lp"<<v<<"_"<< Xlast <<",lp"<<x<<"_0),";
                    LhaFile << "ALL, time <=H, { ";
                    LhaFile <<"Plast"<<v<<"_"<<x<<"=Plast"<<v<<"_"<<x<<"+1";
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