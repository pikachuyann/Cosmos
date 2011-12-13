%skeleton "lalr1.cc"                          /*  -*- C++ -*- */
%require "2.4"
%defines
%define parser_class_name "Gspn_parser"

%code requires {
#include <math.h>
#include <limits.h>
# include <string>

#include <fstream>
#include <sstream>
#include <set>
#include "../Eval/Eval.hpp"
class Gspn_Reader;


}


%parse-param { Gspn_Reader& Reader }
%lex-param   { Gspn_Reader& Reader }

%locations

%debug
%error-verbose

// Symbols.
%union
{
  double       RealVal;
  int 	       IntVal;
  
  std::string *name;
  char CharVal[100];
  char expression[1000];
};

%code {
#include "Gspn-Reader.hpp"
#include <set>
#include <vector>

vector<string> Par;
std::string distrib;
Eval Evaluate;


int NbServers;
bool SingleService;
bool MarkingDependent;
bool AgeMemory;

}

%token        END      0 "end of file"

%token <name>        str
%token <CharVal>   chr
%token <RealVal>     rval
%token <IntVal>      ival
    
%token <name>     SEMICOLON
%token <name>     COMMA
%token <name>     LB
%token <name>     RB
%token <name>     EQ
%token <name>     DIV
%token <name>     MUL
%token <name>     PLUS
%token <name>     MINUS
%token <name>     POWER 
%token <name>     GspnName
%token <name>     NbPl
%token <name>     NbTr
%token <name>     PList
%token <name>     TList

%token <name>     in
%token <name>     out
%token <name>     marking
%token <name>     transitions
%token <name>     Const
%token <name>     INT
%token <name>     DOUBLE
%token <name>     inhibitor
%token <name>     MIN
%token <name>     MAX
%token <name>	  FLOOR
%token <name>	  ABS

%token <name>	  SINGLE
%token <name>	  INFINITE
%token <name>     MULTIPLE

%token <name>	  ENABLINGMEMORY
%token <name>	  AGEMEMORY

%token <name>     IMDT
%token <name>     EXPO

%type<expression> IntStringFormula
%type<expression> RealStringFormula
%type<expression> WEIGHT
%type<expression> PRIORITY




%printer    { debug_stream () << *$$; } str
%destructor { delete $$; } str 

%printer    { debug_stream () << $$; } <IntVal>
%printer    { debug_stream () << $$; } <RealVal>

%%


%left PLUS MINUS;
%left MUL  DIV;
%left POWER;


%start GSPN;

IntStringFormula: ival {sprintf($$,"%d",$1);}
			| str {
				   if(Reader.MyGspn.PlacesList.find(*$1)!=Reader.MyGspn.PlacesList.end()) 
						{std::ostringstream s; s<<" Marking[ "<<Reader.MyGspn.PlacesId[*$1]<<" ] ";
						 sprintf($$, "%s",(s.str()).c_str());						 
						}
					else if(Reader.MyGspn.IntConstant.find(*$1)!=Reader.MyGspn.IntConstant.end())
						{std::ostringstream s; s<<Reader.MyGspn.IntConstant[*$1];
						 sprintf($$, "%s",(s.str()).c_str());
						
						 }
					else{cout<<"'"<<*$1<<"' has not been declared"<<endl;YYABORT;}}
			| LB IntStringFormula RB{sprintf($$,"( %s )", $2);       }
			| IntStringFormula PLUS  IntStringFormula   {sprintf($$,"%s + %s", $1, $3);  }
			| IntStringFormula MINUS IntStringFormula   {sprintf($$,"%s - %s", $1, $3);  }
			| IntStringFormula MUL   IntStringFormula   {sprintf($$,"%s * %s", $1, $3);  }
			| IntStringFormula POWER IntStringFormula   {sprintf($$,"pow(%s , %s)", $1, $3);  }
			| ABS LB IntStringFormula RB {sprintf($$,"fabs( %s )", $3);  }
			| FLOOR LB IntStringFormula RB {sprintf($$,"floor( %s )", $3);  }
			| FLOOR LB IntStringFormula DIV IntStringFormula RB {sprintf($$,"floor( %s /double(%s)", $3,$5);  }
			| MIN LB IntStringFormula COMMA IntStringFormula RB {sprintf($$,"min(%s , %s)", $3, $5);  }
			| MAX LB IntStringFormula COMMA IntStringFormula RB {sprintf($$,"max(%s , %s)", $3, $5);  };
			

RealStringFormula:  rval {sprintf($$, "%f",$1);}	
			| ival {sprintf($$,"%d",$1);}
			| str {
				   if(Reader.MyGspn.PlacesList.find(*$1)!=Reader.MyGspn.PlacesList.end()) 
						{std::ostringstream s; s<<" Marking[ "<<Reader.MyGspn.PlacesId[*$1]<<" ] ";
						 sprintf($$, "%s",(s.str()).c_str());						
						}
					else if(Reader.MyGspn.RealConstant.find(*$1)!=Reader.MyGspn.RealConstant.end())
						{std::ostringstream s; s<<Reader.MyGspn.RealConstant[*$1];
						 sprintf($$, "%s",(s.str()).c_str()); 
						 }
					else{cout<<"'"<<*$1<<"' has not been declared"<<endl;YYABORT;}}
			| LB RealStringFormula RB              {sprintf($$,"( %s )", $2);       }	
			| RealStringFormula DIV  RealStringFormula   {sprintf($$,"%s /double(%s)", $1, $3);  }
			| RealStringFormula PLUS  RealStringFormula   {sprintf($$,"%s + %s", $1, $3);  }
			| RealStringFormula MINUS RealStringFormula   {sprintf($$,"%s - %s", $1, $3);  }
			| RealStringFormula MUL   RealStringFormula   {sprintf($$,"%s * %s", $1, $3);  }
			| RealStringFormula POWER RealStringFormula   {sprintf($$,"pow(%s , %s)", $1, $3);  }
			| ABS LB RealStringFormula RB {sprintf($$,"fabs( %s )", $3);  }			
			| FLOOR LB RealStringFormula RB {sprintf($$,"floor( %s )", $3);  }			
			| MIN LB RealStringFormula COMMA RealStringFormula RB {sprintf($$,"min(%s , %s)", $3, $5);  }
			| MAX LB RealStringFormula COMMA RealStringFormula RB {sprintf($$,"max(%s , %s)", $3, $5);  };
			


GSPN: declarations definitions
	 |declarations definitions redifinitions;

declarations:  Constants Sizes  Lists
	    | Sizes  Lists; 



Constants: Constant
	  |Constant Constants;

Sizes: NbPlaces NbTransitions
       |NbTransitions NbPlaces;

Constant: Const INT str EQ IntStringFormula SEMICOLON 
						{if(Reader.MyGspn.RealConstant.find(*$3)!=Reader.MyGspn.RealConstant.end()) 
							{cout<<"Constant "<<*$3<<" already defined."<<endl; YYABORT;}
					    else {string st=$5;
							  Evaluate.parse(st);
							  Reader.MyGspn.IntConstant[*$3]=Evaluate.IntResult;Reader.MyGspn.RealConstant[*$3]=Evaluate.RealResult;}
						}
		| Const DOUBLE str EQ RealStringFormula SEMICOLON 
						{if(Reader.MyGspn.RealConstant.find(*$3)!=Reader.MyGspn.RealConstant.end()) 
							{cout<<"Constant "<<*$3<<" already defined."<<endl; YYABORT;}
					    else {string st=$5;
							  Evaluate.parse(st);
							  Reader.MyGspn.RealConstant[*$3]=Evaluate.RealResult;}
						};

Lists: PlacesList TransitionsList
       |TransitionsList PlacesList;

NbPlaces: NbPl EQ ival SEMICOLON {Reader.MyGspn.pl=$3;
                                    
}
	|NbPl EQ str SEMICOLON {if(Reader.MyGspn.IntConstant.find(*$3)==Reader.MyGspn.IntConstant.end())
					    {
					    std::cout<<*$3<<" was not declared"<<std::endl;
					    YYABORT;
					    }
						Reader.MyGspn.pl=Reader.MyGspn.IntConstant[*$3];
                                    
};

NbTransitions: NbTr EQ ival SEMICOLON {Reader.MyGspn.tr=$3;
                                       
}
			|NbTr EQ str SEMICOLON {if(Reader.MyGspn.IntConstant.find(*$3)==Reader.MyGspn.IntConstant.end())
					    {
					    std::cout<<*$3<<" was not declared"<<std::endl;
					    YYABORT;
					    }
					  Reader.MyGspn.tr=Reader.MyGspn.IntConstant[*$3];
                                      
};

PlacesList: PList EQ '{' PLabels '}' SEMICOLON {
						if(Reader.MyGspn.PlacesId.size()!=Reader.MyGspn.pl){
						std::cout<<"Place label missing or redeclared, please check your places list"<<std::endl;
						YYABORT;
						}
                                                

                                                if(true){
                                                vector<int> v(Reader.MyGspn.pl,0);
						vector<string> vStr(Reader.MyGspn.pl, " ");

                                                Reader.MyGspn.Marking=v;
                                                vector< vector<int> > m1(Reader.MyGspn.tr,v);  
					        vector< vector<string> > m1Str(Reader.MyGspn.tr,vStr);
                                               
                                                Reader.MyGspn.outArcs=m1;
						Reader.MyGspn.inArcs=m1;
						Reader.MyGspn.inhibArcs=m1;

						Reader.MyGspn.outArcsStr=m1Str;
						Reader.MyGspn.inArcsStr=m1Str;
						Reader.MyGspn.inhibArcsStr=m1Str;
}


                                                if(true){vector<TransType> v(Reader.MyGspn.tr);
                                                Reader.MyGspn.tType=v;
                                                    }
                                                if(true){
                                                    vector<Distribution> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.Dist=d;
                                                    }
                                                if(true){
                                                    vector<string> d(Reader.MyGspn.tr,"");
                                                    Reader.MyGspn.Priority=d;
                                                    }
												if(true){
                                                    vector<string> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.Weight=d;
                                                    }
											  if(true){
												vector<bool> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.MarkingDependent=d;
													Reader.MyGspn.AgeMemory=d;

														}
											  if(true){
												vector<bool> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.SingleService=d;
											  }
												if(true){
												vector<int> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.NbServers=d;
											  }

											MarkingDependent=false;
											AgeMemory=false;
                           
                                                   


};

PLabels : str {
              
                Reader.MyGspn.PlacesList.insert(*$1);
                int sz=Reader.MyGspn.PlacesId.size();
                Reader.MyGspn.PlacesId[*$1]=sz;
}
	|PLabels COMMA str {Reader.MyGspn.PlacesList.insert(*$3);
                            int sz=Reader.MyGspn.PlacesId.size();
                            Reader.MyGspn.PlacesId[*$3]=sz;
                         
};

TransitionsList: TList EQ '{' TLabels '}' SEMICOLON {
						      if(Reader.MyGspn.TransId.size()!=Reader.MyGspn.tr){
						      std::cout<<"Transition label missing or redeclared, please check your transitions list"<<std::endl;
						      YYABORT;
						    }
                                                 
                                                    };

TLabels : str {Reader.MyGspn.TransList.insert(*$1);
               int sz=Reader.MyGspn.TransId.size();
               Reader.MyGspn.TransId[*$1]=sz;
               
                }
	|TLabels COMMA str {Reader.MyGspn.TransList.insert(*$3);
                            int sz=Reader.MyGspn.TransId.size();
                            Reader.MyGspn.TransId[*$3]=sz;
                           
                            };


definitions: PlacesDef TransitionsDef InArcs OutArcs
	    |PlacesDef TransitionsDef InArcs OutArcs Inhibitors;

PlacesDef: marking EQ '{' PLACES '}' SEMICOLON {};

PLACES: PLACE
	|PLACES  PLACE;

PLACE: LB str COMMA IntStringFormula RB SEMICOLON 
				{ if(Reader.MyGspn.PlacesList.find(*$2)==Reader.MyGspn.PlacesList.end())
					    {cout<<"'"<<*$2<<"' has not been declared"<<endl;
					    YYABORT;
					    }
				  string st=$4;
				  if(Evaluate.parse(st)){
					    std::cout<<"Initial Marking is not marking dependent"<<std::endl;
					    YYABORT;
					    }				
				Reader.MyGspn.Marking[Reader.MyGspn.PlacesId[*$2]]=Evaluate.IntResult;
				};
	

TransitionsDef: transitions EQ '{' TRANSITIONS '}' SEMICOLON {
				  for(int i=0; i<Reader.MyGspn.Priority.size();i++){
					  if(Reader.MyGspn.Priority[i]=="")
							  {cout<<"Some transitions were not defined. All declared transitions must be defined"<<endl;
								YYABORT;
								  
							}
}
  };

TRANSITIONS: TRANSITION {}
	  |TRANSITIONS TRANSITION {};

TRANSITION: LB str COMMA dist COMMA PRIORITY COMMA WEIGHT RB SEMICOLON {
					    if(Reader.MyGspn.TransList.find(*$2)==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*$2<<" was not declared"<<std::endl;
						YYABORT;
						}
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*$2]]=Timed;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*$2]].name=distrib;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*$2]].Param=Par;
                        vector<string> v;
                        Par=v;					    
					    Reader.MyGspn.Priority[Reader.MyGspn.TransId[*$2]]=$6;
					    Reader.MyGspn.Weight[Reader.MyGspn.TransId[*$2]]=$8; 
						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*$2]]=true;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*$2]]=false;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*$2]]=false;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*$2]]=1;
                        }
| LB str COMMA dist COMMA PRIORITY COMMA WEIGHT COMMA MEMORY RB SEMICOLON {
					    if(Reader.MyGspn.TransList.find(*$2)==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*$2<<" was not declared"<<std::endl;
						YYABORT;
						}
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*$2]]=Timed;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*$2]].name=distrib;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*$2]].Param=Par;
                        vector<string> v;
                        Par=v;					    
					    Reader.MyGspn.Priority[Reader.MyGspn.TransId[*$2]]=$6;
					    Reader.MyGspn.Weight[Reader.MyGspn.TransId[*$2]]=$8; 
						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*$2]]=true;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*$2]]=false;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*$2]]=AgeMemory;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*$2]]=1;
						AgeMemory=false;
                        }
| LB str COMMA EXPO LB RealStringFormula RB COMMA PRIORITY COMMA WEIGHT COMMA SERVICE RB SEMICOLON {
					    if(Reader.MyGspn.TransList.find(*$2)==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*$2<<" was not declared"<<std::endl;
						YYABORT;
						}
						
						if(!SingleService) MarkingDependent=true;
						string st=$6;
						vector<string> v(1);
						if(Evaluate.parse(st)) 
							  {MarkingDependent=true;v[0]=st;
							   }
						else{ if (Evaluate.RealResult<= 0 ) {
							  cout << "In exponential distribution Lambda > 0" << endl;
							  YYABORT;
							  }
						std::ostringstream s;s<<Evaluate.RealResult;
						v[0]=s.str();
						}
						Reader.MyGspn.Dist[Reader.MyGspn.TransId[*$2]].Param=v;
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*$2]]=Timed;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*$2]].name="EXPONENTIAL";                       
						
						Reader.MyGspn.Priority[Reader.MyGspn.TransId[*$2]]=$9;
						Reader.MyGspn.Weight[Reader.MyGspn.TransId[*$2]]=$11;
						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*$2]]=SingleService;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*$2]]=MarkingDependent;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*$2]]=false;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*$2]]=NbServers;
						MarkingDependent=false;
						
						}

| LB str COMMA EXPO LB RealStringFormula RB COMMA PRIORITY COMMA WEIGHT COMMA SERVICE COMMA MEMORY RB SEMICOLON {
					    if(Reader.MyGspn.TransList.find(*$2)==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*$2<<" was not declared"<<std::endl;
						YYABORT;
						}
						
						if(!SingleService) MarkingDependent=true;
						string st=$6;
						vector<string> v(1);
						if(Evaluate.parse(st)) 
							  {MarkingDependent=true;v[0]=st;
							   }
						else{ if (Evaluate.RealResult<= 0 ) {
							  cout << "In exponential distribution Lambda > 0" << endl;
							  YYABORT;
							  }
						std::ostringstream s;s<<Evaluate.RealResult;
						v[0]=s.str();
						}
						Reader.MyGspn.Dist[Reader.MyGspn.TransId[*$2]].Param=v;
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*$2]]=Timed;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*$2]].name="EXPONENTIAL";                       
						
						Reader.MyGspn.Priority[Reader.MyGspn.TransId[*$2]]=$9;
						Reader.MyGspn.Weight[Reader.MyGspn.TransId[*$2]]=$11;
						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*$2]]=SingleService;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*$2]]=MarkingDependent;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*$2]]=AgeMemory;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*$2]]=NbServers;
						MarkingDependent=false;
						AgeMemory=false;
						}
                                            
|LB str COMMA IMDT COMMA PRIORITY COMMA WEIGHT  RB SEMICOLON {
					    if(Reader.MyGspn.TransList.find(*$2)==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*$2<<" was not declared"<<std::endl;
						YYABORT;
						}
					    
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*$2]]=unTimed;
						Reader.MyGspn.Dist[Reader.MyGspn.TransId[*$2]].name="IMMEDIATE";
                        Reader.MyGspn.Priority[Reader.MyGspn.TransId[*$2]]=$6;
					    Reader.MyGspn.Weight[Reader.MyGspn.TransId[*$2]]=$8;

						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*$2]]=true;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*$2]]=false;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*$2]]=false;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*$2]]=1;						
						
                        };



  

WEIGHT: RealStringFormula
				{string st=$1;
				 if(Evaluate.parse(st)) 
					{cout<<"Weight is not marking dependent: '"<<st<<"'"<<endl;YYABORT; }
				else{ if(Evaluate.RealResult<0)
						{cout<<"Weight is a positive value: '"<<st<<"'"<<endl; YYABORT;}
					   else{std::ostringstream s;s<<Evaluate.RealResult;
							sprintf($$, "%s",(s.str()).c_str());
							} 
					}			    
			  };
PRIORITY: RealStringFormula 
				{string st=$1;
				 if(Evaluate.parse(st)) 
					{cout<<"Priority is not marking dependent: '"<<st<<"'"<<endl;YYABORT; }
				else{ if(Evaluate.RealResult<0)
						{cout<<"Priority is a positive value: '"<<st<<"'"<<endl; YYABORT;}
					   else{std::ostringstream s;s<<Evaluate.RealResult;
							sprintf($$, "%s",(s.str()).c_str());
							} 
					}			    
			  };

SERVICE: SINGLE {SingleService=true; NbServers=1;}
| INFINITE {SingleService=false;NbServers=INT_MAX;}
| MULTIPLE LB ival RB {NbServers= $3;
					  if(NbServers<1) 
					  { cout<<"Number of servers should be at least one"<<endl;
						YYABORT;
					  }
					  if(NbServers==1) SingleService=true;
					  else {SingleService=false;}
					  

}
| MULTIPLE LB str RB {
					   if(Reader.MyGspn.IntConstant.find(*$3)!=Reader.MyGspn.IntConstant.end()){
					   NbServers=Reader.MyGspn.IntConstant[*$3];
					   if(NbServers<1) 
					  { cout<<"Number of servers should be at least one"<<endl;
						YYABORT;
					  }
					  if(NbServers==1) SingleService=true;
					  else {SingleService=false;}
						}
				  else{cout<<*$3<<" not defined or not defined like an integer constant "<<endl;}
				  
};

MEMORY: AGEMEMORY{AgeMemory=true;}
	| ENABLINGMEMORY{AgeMemory=false;};
		

dist:str LB params RB {
		distrib=*$1;
		int np=Par.size();

		switch (Reader.IndexDist[distrib]) {
        case 1:
		{
            if (np != 2){
                cout << "Uniform distribution has two parameters: min and max where 0<=min<max" << endl;
                YYABORT;
            }
			double p1,p2;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
            if ((p1>=p2) || (p1<0)) {
               cout << "In uniform distribution 0 <= min< max " << endl;
               YYABORT;
            }
	   break;
	  }

        case 2:
		{ 
            if (np != 1) {
                cout << "Exponential distribution has one parameter: Lambda > 0" << endl;
                YYABORT;
            } 
                
			double p1;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;			
            if (p1<= 0 ) {
               cout << "In exponential distribution Lambda > 0" << endl;
               YYABORT;
            }
	    break;
	  }
                    
        case 3:
		{
            if (np != 1) {
                cout << "Deterministic distribution has one parameter:  T >= 0" << endl;
                YYABORT;
            }
            
            double p1;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;			
            if (p1<0 ) {
               cout << "In Deterministic distribution T > 0" << endl;
               YYABORT;
            } 
	    break;
	  }
            
        case 4:
		{
            if (np != 2) {
                cout << "Lognormal distribution has two parameters: mu and sigma^2, with sigma^2 > 0" << endl;
                YYABORT;
            }
            
            double p1,p2;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
            if (p2<=0) {
               cout << "In Lognormal distribution sigma^2 > 0" << endl;
               YYABORT;
            }
			double x;	      
			stringstream os;
			x=sqrt(p2);
			os << x;	    
			Par[1]=os.str();
            break;
	  }

        case 5:
		{
            if (np != 3) {
                cout << "Triangle distribution has three parameters: 0 <= b <= c <= a" << endl;
                YYABORT;
            }
            double p1,p2,p3;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
			st=Par[2];
			Evaluate.parse(st);p3=Evaluate.RealResult;
            if ((p1<0) || (p2<p1) || (p3<p2)) {
               cout << "In Triangle distribution: 0 <= b <= c<= a" << endl;
               YYABORT;
            }

          
	    break;
	  }

	  case 6:
		{
            if (np != 2) {
                cout << "Geometric distribution has two parameters: 0 <= p <= 1 (probability of success) and T > 0 (duration of one step)" << endl;
                YYABORT;
            }
			double p1,p2;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
            if ((p1<0) || (p1>1) || p2<=0) {
               cout << "In Geometric distribution 0 <= p <= 1 (probability of success) and T > 0 (duration of one step)" << endl;
               YYABORT;
            }            
	    break;
	  }
        case 7:
		{
            if (np != 2) {
                cout << "Erlang distribution has two parameters: Shape and Rate, where Shape is a positive integer and Rate > 0" << endl;
                YYABORT;
            }
            
            
			string st=Par[0];
			Evaluate.parse(st);
			if(Evaluate.RealResult != Evaluate.IntResult || Evaluate.IntResult < 1){
               cout << "In Erlang distribution Shape is a positive integer" << endl;
               YYABORT;
            } 
			
			st=Par[1];
			Evaluate.parse(st);
            if (Evaluate.RealResult<=0) {
               cout << "In Erlang distribution Rate > 0" << endl;
               YYABORT;
            } 
            break;
	  }
	  case 8:
		{
            if (np != 2) {
                cout << "Gamma distribution has two parameters: Shape>0 and Scale>0" << endl;
                YYABORT;
            }
            
            
			string st=Par[0];
			Evaluate.parse(st);
			if(Evaluate.RealResult<=0){
               cout << "In Gamma distribution Shape > 0" << endl;
               YYABORT;
            } 
			
			st=Par[1];
			Evaluate.parse(st);
            if (Evaluate.RealResult<=0) {
               cout << "In Gamma distribution Scale > 0" << endl;
               YYABORT;
            } 
            break;
	  }

        default: cout << "\nUnknown distribution !" << endl;
            YYABORT;

    }
};



params:param
     |params COMMA param;



param:RealStringFormula {string st=$1;
				 if(Evaluate.parse(st)) 
					{cout<<"The exponential distribution is the only marking dependent distribution: '"<<st<<"'"<<endl;YYABORT; }
				 else{std::ostringstream s;s<<Evaluate.RealResult;
				 Par.push_back(s.str());
					} 
				};
			  

InArcs: in EQ '{' incells '}' SEMICOLON {};

incells: incell {}
       |incells incell {};

incell: LB str COMMA str COMMA IntStringFormula RB SEMICOLON {
						  if(Reader.MyGspn.PlacesList.find(*$2)==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*$2<<" was not declared"<<std::endl;
							YYABORT;
							}
						  if(Reader.MyGspn.TransList.find(*$4)==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*$4<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						  string st=$6;
						  
						  if(Evaluate.parse(st)){
							  Reader.MyGspn.inArcs[Reader.MyGspn.TransId[*$4]][Reader.MyGspn.PlacesId[*$2]]=1;
						 	  Reader.MyGspn.inArcsStr[Reader.MyGspn.TransId[*$4]][Reader.MyGspn.PlacesId[*$2]]=st;
						  }
						  else Reader.MyGspn.inArcs[Reader.MyGspn.TransId[*$4]][Reader.MyGspn.PlacesId[*$2]]=Evaluate.IntResult;
						  		 
						  }
|LB str COMMA str   RB SEMICOLON {
						  if(Reader.MyGspn.PlacesList.find(*$2)==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*$2<<" was not declared"<<std::endl;
							YYABORT;
							}
						  if(Reader.MyGspn.TransList.find(*$4)==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*$4<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						  Reader.MyGspn.inArcs[Reader.MyGspn.TransId[*$4]][Reader.MyGspn.PlacesId[*$2]]=1;						 

						  };

OutArcs: out EQ '{' outcells '}' SEMICOLON {};

outcells: outcell {}
       |outcells outcell {};

outcell: LB str COMMA str COMMA IntStringFormula RB SEMICOLON {
						   if(Reader.MyGspn.TransList.find(*$2)==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*$2<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						   if(Reader.MyGspn.PlacesList.find(*$4)==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*$4<<" was not declared"<<std::endl;
							YYABORT;
						      }
						  string st=$6;
						  
						  if(Evaluate.parse(st)){
							  Reader.MyGspn.outArcs[Reader.MyGspn.TransId[*$2]][Reader.MyGspn.PlacesId[*$4]]=1;
						 	  Reader.MyGspn.outArcsStr[Reader.MyGspn.TransId[*$2]][Reader.MyGspn.PlacesId[*$4]]=st;
						  }
						  else Reader.MyGspn.outArcs[Reader.MyGspn.TransId[*$2]][Reader.MyGspn.PlacesId[*$4]]=Evaluate.IntResult;
						 
						  }	
|LB str COMMA str   RB SEMICOLON {
						   if(Reader.MyGspn.TransList.find(*$2)==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*$2<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						   if(Reader.MyGspn.PlacesList.find(*$4)==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*$4<<" was not declared"<<std::endl;
							YYABORT;
						      }
						  Reader.MyGspn.outArcs[Reader.MyGspn.TransId[*$2]][Reader.MyGspn.PlacesId[*$4]]=1;						 
						    };



Inhibitors: inhibitor EQ '{' inhibcells '}' SEMICOLON {};

inhibcells: inhibcell {}
       |inhibcells inhibcell {};

inhibcell: LB str COMMA str COMMA IntStringFormula RB SEMICOLON {
						  if(Reader.MyGspn.PlacesList.find(*$2)==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*$2<<" was not declared"<<std::endl;
							YYABORT;
							}
						  if(Reader.MyGspn.TransList.find(*$4)==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*$4<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						 string st=$6;
						  
						  if(Evaluate.parse(st)){
							  Reader.MyGspn.inhibArcs[Reader.MyGspn.TransId[*$4]][Reader.MyGspn.PlacesId[*$2]]=1;
						 	  Reader.MyGspn.inhibArcsStr[Reader.MyGspn.TransId[*$4]][Reader.MyGspn.PlacesId[*$2]]=st;
						  }
						  else Reader.MyGspn.inhibArcs[Reader.MyGspn.TransId[*$4]][Reader.MyGspn.PlacesId[*$2]]=Evaluate.IntResult;
							 
						  }
	
|LB str COMMA str   RB SEMICOLON {
						  if(Reader.MyGspn.PlacesList.find(*$2)==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*$2<<" was not declared"<<std::endl;
							YYABORT;
							}
						  if(Reader.MyGspn.TransList.find(*$4)==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*$4<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						  Reader.MyGspn.inhibArcs[Reader.MyGspn.TransId[*$4]][Reader.MyGspn.PlacesId[*$2]]=1;
						 
						  };



redifinitions: TransitionsDef;

%%

void
gspn::Gspn_parser::error (const gspn::Gspn_parser::location_type& l,
                          const std::string& m)
{
  Reader.error (l, m);
}
