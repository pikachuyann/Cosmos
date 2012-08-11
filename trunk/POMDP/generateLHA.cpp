

void generateLHAfun(int N, vector<int>  &W, double H ){
    
    cout << "generate LHA" << endl;
    
    ofstream LhaFile("generated.lha", ios::out | ios::trunc);
    
    
    LhaFile << "NbVariables = " << N*N+2*N+2 << ";" << endl; 
    LhaFile << "NbLocations = "<< N+3 << ";" << endl; 

    LhaFile << "const double H = "<< H << ";" << endl; 
    

    LhaFile << "VariablesList = {time,Xlast";
    for(int i=0;i<N;i++)
      LhaFile << ", W"<<i;
    for(int i=0;i<N;i++)
      LhaFile << ", Out"<<i;
    for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	  LhaFile << ", Plast"<<i<<j;	
    LhaFile << "} ;"<< endl; 
    
    
    LhaFile << "LocationsList = {li, lf, la";
    for(int i=0;i<N;i++)
      LhaFile << ", lp"<<i;    
    LhaFile << "} ;"<< endl; 
    
    
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
	LhaFile << "AVG(Last(Plast"<<i<<j<<"));"<<endl;    
   

    LhaFile << "InitialLocations = {l0};"<< endl; 

    LhaFile << "FinalLocations = {lf};"<< endl; 

    LhaFile << "Locations={"<< endl; 
    LhaFile << "(li, TRUE, (time:1));"<< endl; 
    LhaFile << "(lf, TRUE, (time:1));"<< endl; 
    LhaFile << "(la, TRUE, (time:1));"<< endl; 
    for(int i=0;i<N;i++)
       LhaFile << "(lp"<<i<<", V"<<i<<"=1, (time:1));"<< endl;     
    LhaFile << "};"<<endl; 

    LhaFile << "Edges={"<< endl; 
    LhaFile << "((li,la),ALL,  time <= H,#);"<< endl; 
    LhaFile << "((li,lf),#,  time = H,{Plast00=Plast00/Out0";
    for(int i=0; i<N;i++)
      for(int j=0; j<N; j++)
	if(i!=0 && j!=0)
	  LhaFile <<", Plast"<<i<<j<<"=Plast"<<i<<j<<"/Out"<<j;
    LhaFile <<"});"<< endl; 
    
    for(int i=0; i< N;i++)      
      for(int j=0; j<N; j++){
	 LhaFile << "((la,lp"<<i<<"),#, Xlast="<<j<<"& W"<<i<<"=0,{Plast"<<j<<0<<"=Plast"<<j<<0<<"+1, Out"<<j<<"=Out"<<j<<"+1});"<< endl;
	 LhaFile << "((la,lp"<<i<<"),#, Xlast="<<j<<"& W"<<i<<"=1,{Plast"<<j<<i<<"=Plast"<<j<<i<<"+1, Out"<<j<<"=Out"<<j<<"+1,Xlast="<<i<<"});"<< endl;
	
      }
      
   for(int i=0; i< N;i++)    
      LhaFile << "((lp"<<i<<", li),#, #, #);"<< endl;
      
   
    LhaFile << "};"<< endl; 
    
    LhaFile.close();
    
    
}