%skeleton "lalr1.cc"                          /*  -*- C++ -*- */
%require "2.4"
%defines
%define parser_class_name "Lha_parser"

%code requires {
	#include <math.h>
	#include <limits.h>
	# include <string>
	
	#include <fstream>
	#include <sstream>
	#include <set>
	#include "../Eval/Eval.hpp"
	#include "../HaslFormula.hpp"
	
	class Lha_Reader;
	
	
}

// The parsing context.
%parse-param { Lha_Reader& Reader }
%lex-param   { Lha_Reader& Reader }

%locations

%debug
%error-verbose

// Symbols.
%union
{
	double       RealVal;
	int 	       IntVal;
	std::string *name;
	char expression[1000];
	HaslFormulasTop *TOPHASL;
};

%code {
	#include "../HaslFormula.hpp"
	#include "Lha-Reader.hpp"
	#include <set>
	#include <vector>
	
	Eval LhaEvaluate;
	
	
	
	vector<string> StrFlowVector;
	vector<string> FuncFlowVector;
	
	vector<string> FuncUpdateVector;
	
	set <string> PetriTransitions;
	set <string> SubSet;
	
	
	
	vector < string > CoeffsVector;
	vector < vector <string> > CoeffsMatrix;
	vector <string> CST;
	vector <string> comp;
	
	
	
	
	
	
}

%token        END      0 "end of file"

%token <name>     str
%token <RealVal>  rval
%token <IntVal>  ival

%token <name>     SEMICOLON
%token <name>     COLON
%token <name>     COMMA
%token <name>     LB
%token <name>     RB

%token <name>     SHARP
%token <name>     ALL
%token <name>     BackSlash

%token <name>     EQ
%token <name>     GEQ
%token <name>     LEQ
%token <name>     LL
%token <name>     GG

%token <name>     AND
%token <name>     OR
%token <name>     NOT

%token <name>     TRUE
%token <name>     FALSE

%token <name>     DOUBLE
%token <name>     INT

%token <name>     DIV
%token <name>     MUL
%token <name>     PLUS
%token <name>     MINUS
%token <name>     POWER
%token <name>     FLOOR

%token <name>     MIN
%token <name>     MAX

%token <name>     LhaMIN
%token <name>     LhaMAX
%token <name> 	  AVG
%token <name>	  PROB
%token <name>     LAST
%token <name> 	  INTEGRAL

%token <name>     LhaName

%token <name>     Const

%token <name>     NbLoc
%token <name>     NbVar

%token <name>     VList
%token <name>     LList

%token <name>     Iloc
%token <name>     Floc

%token <name>     locations
%token <name>     edges

%token <name>     PDF
%token <namd>	  CDF

%type<expression> IntMarkingFormula
%type<expression> RealMarkingFormula
%type<expression> RealVarMarkingFormula
%type<expression> LogExpr
%type<expression> CompExpr

%type<expression> AlgExpr
%type<expression> LhaFunc
%type<expression> LinForm
%type<expression> VarTerm

%type<TOPHASL> TopHaslExp
%type<RealVal> rorival

%printer    { debug_stream () << *$$; } str
%destructor { delete $$; } str

%printer    { debug_stream () << $$; } <IntVal>
%printer    { debug_stream () << $$; } <RealVal>

%%
%left OR;
%left AND;
%left NOT;
%left LEQ GEQ LL GG EQ;
%left PLUS MINUS;
%left NEG;
%left MUL  DIV;
%left POWER;
%left LB RB;


%start LHA;
LHA: declarations InitFinal definitions;


declarations:  Sizes Constants Lists HaslExps
| Sizes  Lists HaslExps ;





IntMarkingFormula: ival {sprintf($$,"%d",$1);}
| str {
	if(Reader.MyLha.PlaceIndex.find(*$1)!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking[ "<<Reader.MyLha.PlaceIndex[*$1]<<" ] ";
		sprintf($$, "%s",(s.str()).c_str());
	}
	else if(Reader.MyLha.LhaIntConstant.find(*$1)!=Reader.MyLha.LhaIntConstant.end())
	{std::ostringstream s; s<<Reader.MyLha.LhaIntConstant[*$1];
		sprintf($$, "%s",(s.str()).c_str());
	}
	else{cout<<"'"<<*$1<<"' is not a place label or a defined constant"<<endl;YYABORT;}}
| LB IntMarkingFormula RB{sprintf($$,"( %s )", $2);       }
| MINUS IntMarkingFormula %prec NEG {sprintf($$,"-%s",$2);}
| IntMarkingFormula PLUS  IntMarkingFormula   {sprintf($$,"%s + %s", $1, $3);  }
| IntMarkingFormula MINUS IntMarkingFormula   {sprintf($$,"%s - %s", $1, $3);  }
| IntMarkingFormula MUL   IntMarkingFormula   {sprintf($$,"%s * %s", $1, $3);  }
| IntMarkingFormula POWER IntMarkingFormula   {sprintf($$,"pow(%s , %s)", $1, $3);  }
| FLOOR LB IntMarkingFormula RB {sprintf($$,"floor( %s )", $3);  }
| FLOOR LB IntMarkingFormula DIV IntMarkingFormula RB {sprintf($$,"floor( %s /double(%s))", $3,$5);  }
| MIN LB IntMarkingFormula COMMA IntMarkingFormula RB {sprintf($$,"min(%s , %s)", $3, $5);  }
| MAX LB IntMarkingFormula COMMA IntMarkingFormula RB {sprintf($$,"max(%s , %s)", $3, $5);  };


RealMarkingFormula:  rval {sprintf($$, "%f",$1);}
| ival {sprintf($$,"%d",$1);}
| str {
	if(Reader.MyLha.PlaceIndex.find(*$1)!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking[ "<<Reader.MyLha.PlaceIndex[*$1]<<" ] ";
		sprintf($$, "%s",(s.str()).c_str());
	}
	else if(Reader.MyLha.LhaRealConstant.find(*$1)!=Reader.MyLha.LhaRealConstant.end())
	{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*$1];
		sprintf($$, "%s",(s.str()).c_str());
	}
	
	else{cout<<"'"<<*$1<<"' is not a place label or a defined constant"<<endl;YYABORT;}}
| LB RealMarkingFormula RB              {sprintf($$,"( %s )", $2);       }
| MINUS RealMarkingFormula %prec NEG {sprintf($$,"-%s",$2);}
| RealMarkingFormula DIV  RealMarkingFormula   {sprintf($$,"%s /double(%s)", $1, $3);  }
| RealMarkingFormula PLUS  RealMarkingFormula   {sprintf($$,"%s + %s", $1, $3);  }
| RealMarkingFormula MINUS RealMarkingFormula   {sprintf($$,"%s - %s", $1, $3);  }
| RealMarkingFormula MUL   RealMarkingFormula   {sprintf($$,"%s * %s", $1, $3);  }
| RealMarkingFormula POWER RealMarkingFormula   {sprintf($$,"pow(%s , %s)", $1, $3);  }
| FLOOR LB RealMarkingFormula RB {sprintf($$,"floor( %s )", $3);  }
| MIN LB RealMarkingFormula COMMA RealMarkingFormula RB {sprintf($$,"min(%s , %s)", $3, $5);  }
| MAX LB RealMarkingFormula COMMA RealMarkingFormula RB {sprintf($$,"max(%s , %s)", $3, $5);  };

RealVarMarkingFormula:  rval {sprintf($$, "%f",$1);}
| ival {sprintf($$,"%d",$1);}
| str {
	if(Reader.MyLha.PlaceIndex.find(*$1)!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking[ "<<Reader.MyLha.PlaceIndex[*$1]<<" ] ";
		sprintf($$, "%s",(s.str()).c_str());
	}
	else{ if(Reader.MyLha.LhaRealConstant.find(*$1)!=Reader.MyLha.LhaRealConstant.end())
		{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*$1];
			sprintf($$, "%s",(s.str()).c_str());
		}
		else {if(Reader.MyLha.VarIndex.find(*$1)!=Reader.MyLha.VarIndex.end())
			{
				std::ostringstream s; s<<"Var["<<Reader.MyLha.VarIndex[*$1]<<"]";
				sprintf($$, "%s",(s.str()).c_str());
			}
			else {cout<<"'"<<*$1<<"' is not a place label, a lha variable or a defined constant"<<endl;YYABORT;}
		}
	}
}
| LB RealVarMarkingFormula RB              {sprintf($$,"( %s )", $2);       }
| MINUS RealVarMarkingFormula %prec NEG {sprintf($$,"-%s",$2);}
| RealVarMarkingFormula DIV  RealVarMarkingFormula    {sprintf($$,"%s /double(%s)", $1, $3);  }
| RealVarMarkingFormula PLUS  RealVarMarkingFormula   {sprintf($$,"%s + %s", $1, $3);  }
| RealVarMarkingFormula MINUS RealVarMarkingFormula   {sprintf($$,"%s - %s", $1, $3);  }
| RealVarMarkingFormula MUL   RealVarMarkingFormula   {sprintf($$,"%s * %s", $1, $3);  }
| RealVarMarkingFormula POWER RealVarMarkingFormula   {sprintf($$,"pow(%s , %s)", $1, $3);  }
| FLOOR LB RealVarMarkingFormula RB {sprintf($$,"floor( %s )", $3);  }
| MIN LB RealVarMarkingFormula COMMA RealVarMarkingFormula RB {sprintf($$,"min(%s , %s)", $3, $5);  }
| MAX LB RealVarMarkingFormula COMMA RealVarMarkingFormula RB {sprintf($$,"max(%s , %s)", $3, $5);  };


Sizes: NbLocations NbVariables
|NbVariables NbLocations;

Constants: Constant
|Constant Constants;

Constant: Const INT str EQ IntMarkingFormula SEMICOLON
{if(Reader.MyLha.LhaRealConstant.find(*$3)!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*$3<<" already defined."<<endl; YYABORT;}
	else {string st=$5;
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaIntConstant[*$3]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*$3]=LhaEvaluate.RealResult;}
}
| Const DOUBLE str EQ RealMarkingFormula SEMICOLON
{if(Reader.MyLha.LhaRealConstant.find(*$3)!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*$3<<" already defined."<<endl; YYABORT;}
	else {string st=$5;
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaRealConstant[*$3]=LhaEvaluate.RealResult;}
};



NbVariables: NbVar EQ ival SEMICOLON {Reader.MyLha.NbVar=$3;
	
};

NbLocations: NbLoc EQ ival SEMICOLON {Reader.MyLha.NbLoc=$3;
	
};

Lists: VariablesList LocationsList
|LocationsList VariablesList;

VariablesList: VList EQ '{' VLabels '}' SEMICOLON {
	if(Reader.MyLha.VarIndex.size()!=Reader.MyLha.NbVar){
		std::cout<<"Variable label missing or redeclared, please check your variables list"<<std::endl;
		YYABORT;
	}
	
	
	if(true){
		vector<string> v1(Reader.MyLha.NbVar,"");
		
		vector< vector<string> > vv(Reader.MyLha.NbLoc,v1);
		
		StrFlowVector=v1;
		FuncFlowVector=v1;
		FuncUpdateVector=v1;
		CoeffsVector=v1;
		Reader.MyLha.FuncFlow=vv;
		Reader.MyLha.StrFlow=vv;
		vector<string> v2(Reader.MyLha.NbLoc,"");
		Reader.MyLha.StrLocProperty=v2;
		Reader.MyLha.FuncLocProperty=v2;
		set <string> Pt;
		PetriTransitions=Pt;
		for(map<string, int>::iterator it=Reader.MyLha.TransitionIndex.begin();it!=Reader.MyLha.TransitionIndex.end();it++)
		PetriTransitions.insert((*it).first);
		vector < set<int> > vi(Reader.MyLha.NbLoc);
		Reader.MyLha.Out_S_Edges=vi;
		Reader.MyLha.Out_A_Edges=vi;
	}
	
	
};

VLabels : str {
	
	Reader.MyLha.VarLabel.push_back(*$1);
	Reader.MyLha.VarIndex[*$1]=Reader.MyLha.VarLabel.size()-1;
	
}
|VLabels COMMA str {Reader.MyLha.VarLabel.push_back(*$3);
	Reader.MyLha.VarIndex[*$3]=Reader.MyLha.VarLabel.size()-1;
};

LocationsList: LList EQ '{' LLabels '}' SEMICOLON {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
	std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
	YYABORT;
}
	
};

LLabels : str {
	
	Reader.MyLha.LocLabel.push_back(*$1);
	Reader.MyLha.LocIndex[*$1]=Reader.MyLha.LocLabel.size()-1;
	
}
|LLabels COMMA str {Reader.MyLha.LocLabel.push_back(*$3);
	Reader.MyLha.LocIndex[*$3]=Reader.MyLha.LocLabel.size()-1;
};


InitFinal: init final
|final init;

init: Iloc EQ '{' iLLabels '}' SEMICOLON;

iLLabels : str {
	
	if(Reader.MyLha.LocIndex.find(*$1)!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*$1]);
	else cout<<"Unknown location"<<endl;
	
	
}
|iLLabels COMMA str {if(Reader.MyLha.LocIndex.find(*$3)!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*$3]);
	else cout<<"Unknown location"<<endl;
};

final: Floc EQ '{' fLLabels '}' SEMICOLON;

fLLabels : str {
	
	if(Reader.MyLha.LocIndex.find(*$1)!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*$1]);
	else cout<<"Unknown location"<<endl;
	
	
}
|fLLabels COMMA str {if(Reader.MyLha.LocIndex.find(*$3)!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*$3]);
	else {cout<<"Unknown location"<<endl;YYABORT;}
};





definitions: LocationsDef EdgesDef
|EdgesDef LocationsDef;



LocationsDef: locations EQ '{' LOCATIONS '}' SEMICOLON {
	for(size_t l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
	if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
		YYABORT;}
};

LOCATIONS: LOCATION
|LOCATIONS  LOCATION;

LOCATION: LB str COMMA LogExpr COMMA LB FLOWS RB RB SEMICOLON
{ int l;
	if(Reader.MyLha.LocIndex.find(*$2)!=Reader.MyLha.LocIndex.end()){
		l=Reader.MyLha.LocIndex[*$2];
		
		Reader.MyLha.StrLocProperty[l]=$4;
		Reader.MyLha.FuncLocProperty[l]=$4;
		Reader.MyLha.FuncFlow[l]=FuncFlowVector;
		Reader.MyLha.StrFlow[l]=StrFlowVector;
		
		if(true){
			vector<string> v(Reader.MyLha.NbVar,"");
			StrFlowVector=v;
			FuncFlowVector=v;}
	}
	else {cout<<"Unknown location"<<endl;YYABORT;}
	
	
}
|LB str COMMA LogExpr RB SEMICOLON


{ int l;
	if(Reader.MyLha.LocIndex.find(*$2)!=Reader.MyLha.LocIndex.end()){
		l=Reader.MyLha.LocIndex[*$2];
		
		Reader.MyLha.StrLocProperty[l]=$4;
		Reader.MyLha.FuncLocProperty[l]=$4;
		if(true){
			vector<string> v(Reader.MyLha.NbVar,"");
			StrFlowVector=v;
			FuncFlowVector=v;}
		Reader.MyLha.FuncFlow[l]=FuncFlowVector;
		Reader.MyLha.StrFlow[l]=StrFlowVector;
		
	}
	else {cout<<"Unknown location"<<endl;YYABORT;}
	
	
};

FLOWS: FLOW
|FLOWS COMMA FLOW;
FLOW: str COLON RealMarkingFormula {if(Reader.MyLha.VarIndex.find(*$1)!=Reader.MyLha.VarIndex.end())
	FuncFlowVector[Reader.MyLha.VarIndex[*$1]]=$3;
	else{ cout<<"'"<<*$1<<"' is not a Lha variable"<<endl;
		YYABORT;}
};

LogExpr: TRUE 				  {sprintf($$,"true");}
|FALSE				  {sprintf($$,"false");}
|CompExpr			  {sprintf($$,"%s", $1);}
|LogExpr AND LogExpr {sprintf($$,"%s && %s", $1, $3);}
|LogExpr OR LogExpr  {sprintf($$,"%s || %s", $1, $3);}
|LB LogExpr RB       {sprintf($$,"( %s )", $2);}
|NOT LogExpr         {sprintf($$,"! %s", $2);};

CompExpr: RealMarkingFormula EQ RealMarkingFormula  {sprintf($$,"%s == %s", $1, $3);}
|RealMarkingFormula LEQ RealMarkingFormula {sprintf($$,"%s <= %s", $1, $3);}
|RealMarkingFormula GEQ RealMarkingFormula {sprintf($$,"%s >= %s", $1, $3);}
|RealMarkingFormula LL RealMarkingFormula  {sprintf($$,"%s < %s", $1, $3);}
|RealMarkingFormula GG RealMarkingFormula  {sprintf($$,"%s > %s", $1, $3);};




EdgesDef: edges EQ '{' EDGES '}' SEMICOLON{
	
} ;

EDGES: EDGE
|EDGE EDGES;

EDGE: LB LB str COMMA str RB COMMA ACTIONS COMMA CONSTRAINTS COMMA UPDATES RB SEMICOLON{
	
	if(Reader.MyLha.LocIndex.find(*$3)!=Reader.MyLha.LocIndex.end())
	if(Reader.MyLha.LocIndex.find(*$5)!=Reader.MyLha.LocIndex.end())
	{ int ne=Reader.MyLha.Edge.size();
		Reader.MyLha.AnEdge.Index=ne;
		Reader.MyLha.AnEdge.Source=Reader.MyLha.LocIndex[*$3];
		Reader.MyLha.AnEdge.Target=Reader.MyLha.LocIndex[*$5];
		Reader.MyLha.Edge.push_back(Reader.MyLha.AnEdge);
		Reader.MyLha.EdgeActions.push_back(SubSet);
		if(SubSet.size()>0) Reader.MyLha.Out_S_Edges[Reader.MyLha.AnEdge.Source].insert(ne);
		else Reader.MyLha.Out_A_Edges[Reader.MyLha.AnEdge.Source].insert(ne);
		SubSet.erase(SubSet.begin(),SubSet.end());
		Reader.MyLha.ConstraintsCoeffs.push_back(CoeffsMatrix);Reader.MyLha.ConstraintsConstants.push_back(CST);
		Reader.MyLha.ConstraintsRelOp.push_back(comp);
		vector<string> vs;comp=vs;CST=vs;
		vector <vector <string> > ms;CoeffsMatrix=ms;
		
	}
	else {cout<<*$5<<" is not a location label"<<endl;YYABORT;}
	else  {cout<<*$3<<" is not a location label"<<endl;YYABORT;}
};

ACTIONS: SHARP
| ALL {SubSet=PetriTransitions;}
| ALL BackSlash SetOfActions {set<string> temp=PetriTransitions;
	for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
	temp.erase((*it));
	SubSet=temp;}
| SetOfActions;

SetOfActions: '{' Actions '}';

Actions: str {if(Reader.MyLha.TransitionIndex.find(*$1)!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*$1);
	else {cout<<*$1<<" is not a Petri-net transition "<<endl;YYABORT;}
}
|Actions COMMA str {if(Reader.MyLha.TransitionIndex.find(*$3)!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*$3);
	else {cout<<*$3<<" is not a Petri-net transition "<<endl;YYABORT;}};


CONSTRAINTS: CONSTRAINT {}
|CONSTRAINT AND CONSTRAINTS {}
|SHARP;

CONSTRAINT:  LinearExp EQ RealMarkingFormula
{CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("==");
	CST.push_back($3);
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
|LinearExp LEQ RealMarkingFormula
{CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("<=");
	CST.push_back($3);
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
|LinearExp GEQ RealMarkingFormula
{CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back(">=");
	CST.push_back($3);
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;};

LinearExp: term
|LinearExp MINUS term
|LinearExp PLUS  term;

term:   str
{ if(Reader.MyLha.VarIndex.find(*$1)!=Reader.MyLha.VarIndex.end())
	{CoeffsVector[Reader.MyLha.VarIndex[*$1]]="1";}
	else {cout<<*$1<<" is not a Lha variable"<<endl;YYABORT;}}
| LB RealMarkingFormula RB MUL str
{ if(Reader.MyLha.VarIndex.find(*$5)!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<"("<<$2<<")";
		CoeffsVector[Reader.MyLha.VarIndex[*$5]]=s.str();}
	else {cout<<*$5<<" is not a Lha variable"<<endl;YYABORT;}}
| ival MUL str
{ if(Reader.MyLha.VarIndex.find(*$3)!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<$1;
		CoeffsVector[Reader.MyLha.VarIndex[*$3]]=s.str();}
	else {cout<<*$3<<" is not a Lha variable"<<endl;YYABORT;}}
| rval MUL str
{ if(Reader.MyLha.VarIndex.find(*$3)!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<$1;
		CoeffsVector[Reader.MyLha.VarIndex[*$3]]=s.str();}
	else {cout<<*$3<<" is not a Lha variable"<<endl;YYABORT;}}
| str  MUL str
{ if(Reader.MyLha.VarIndex.find(*$3)!=Reader.MyLha.VarIndex.end())
	{if(Reader.MyLha.LhaRealConstant.find(*$1)!=Reader.MyLha.LhaRealConstant.end())
		{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*$1];
			CoeffsVector[Reader.MyLha.VarIndex[*$3]]=s.str();
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*$1)!=Reader.MyLha.PlaceIndex.end())
			{std::ostringstream s; s<<"Marking["<<Reader.MyLha.PlaceIndex[*$1]<<"]";
				CoeffsVector[Reader.MyLha.VarIndex[*$3]]=s.str();
			}
			else
			{
				cout<<*$1<<" is not Petri-net Place or a definded constant "<<endl;
				YYABORT;
			}
		}
	}
	else {cout<<*$3<<" is not a Lha variable"<<endl;YYABORT;}
}
| MINUS str %prec NEG
{ if(Reader.MyLha.VarIndex.find(*$2)!=Reader.MyLha.VarIndex.end())
	{CoeffsVector[Reader.MyLha.VarIndex[*$2]]="-1";}
	else {cout<<*$2<<" is not a Lha variable"<<endl;YYABORT;}}
| MINUS LB RealMarkingFormula RB MUL str %prec NEG
{ if(Reader.MyLha.VarIndex.find(*$6)!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<"-("<<$3<<")";
		CoeffsVector[Reader.MyLha.VarIndex[*$6]]=s.str();}
	else {cout<<*$6<<" is not a Lha variable"<<endl;YYABORT;}}
| MINUS ival MUL str %prec NEG
{ if(Reader.MyLha.VarIndex.find(*$4)!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<"-"<<$2;
		CoeffsVector[Reader.MyLha.VarIndex[*$4]]=s.str();}
	else {cout<<*$4<<" is not a Lha variable"<<endl;YYABORT;}}
| MINUS rval MUL str %prec NEG
{ if(Reader.MyLha.VarIndex.find(*$4)!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<"-"<<$2;
		CoeffsVector[Reader.MyLha.VarIndex[*$4]]=s.str();}
	else {cout<<*$4<<" is not a Lha variable"<<endl;YYABORT;}}
| MINUS str MUL str %prec NEG
{ if(Reader.MyLha.VarIndex.find(*$4)!=Reader.MyLha.VarIndex.end())
	{if(Reader.MyLha.LhaRealConstant.find(*$2)!=Reader.MyLha.LhaRealConstant.end())
		{std::ostringstream s; s<<"-"<<Reader.MyLha.LhaRealConstant[*$2];
			CoeffsVector[Reader.MyLha.VarIndex[*$4]]=s.str();
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*$2)!=Reader.MyLha.PlaceIndex.end())
			{std::ostringstream s; s<<"-Marking["<<Reader.MyLha.PlaceIndex[*$2]<<"]";
				CoeffsVector[Reader.MyLha.VarIndex[*$4]]=s.str();
			}
			else
			{
				cout<<*$2<<" is not Petri-net Place or a definded constant "<<endl;
				YYABORT;
			}
		}
	}
	else {cout<<*$4<<" is not a Lha variable"<<endl;YYABORT;}
}	;


UPDATES: '{' Updates '}' {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
| SHARP {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);};

Updates: Update
|Updates COMMA Update ;

Update: str EQ RealVarMarkingFormula {
	if(Reader.MyLha.VarIndex.find(*$1)!=Reader.MyLha.VarIndex.end())
    {FuncUpdateVector[Reader.MyLha.VarIndex[*$1]]= $3;}
	else{cout<<*$1<<" is not  variable label"<<endl;YYABORT;}
}


HaslExps: HaslExp | HaslExp HaslExps;

HaslExp: str EQ TopHaslExp SEMICOLON {
	if($3 != NULL){
		Reader.MyLha.HASLname.push_back(*$1);
		Reader.MyLha.HASLtop.push_back($3);
	}else{
		for(vector<string>::iterator it = Reader.MyLha.HASLname.begin(); it <Reader.MyLha.HASLname.end() ; it++){
			if( it->find("$_$") == 0)
				it->replace(0,3,*$1);
		}
	}
}
| TopHaslExp SEMICOLON {
	if($1 != NULL){
		Reader.MyLha.HASLname.push_back("");
		Reader.MyLha.HASLtop.push_back($1);
	}
}

rorival:
rval {$$=$1;}
| ival {$$=(double)$1;}

TopHaslExp:
AVG LB AlgExpr RB {
	Reader.MyLha.Algebraic.push_back($3);
	$$ = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel);
}
| PROB {
	$$ = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel);
}
| PDF LB AlgExpr COMMA rorival COMMA rorival COMMA rorival RB {
	
	for(double bucket = $7 ; bucket < $9 ; bucket+= $5){
		std::ostringstream algPDF;
		algPDF << "(("<<$3<<" >= "<<bucket<<"&& "<<$3<<"<"<<bucket+$5<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algPDF.str());
		Reader.MyLha.HASLtop.push_back(
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
								Reader.MyLha.ConfidenceLevel));
		Reader.MyLha.HASLtop.back()->TypeOp = PDF_PART;
		std::ostringstream s; s<<"$_$: Value in ["<< bucket<< " , "<<bucket+$5<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	$$ = NULL;
}
| CDF LB AlgExpr COMMA rorival COMMA rorival COMMA rorival RB {
	
	for(double bucket = $7 ; bucket < $9 ; bucket+= $5){
		std::ostringstream algCDF;
		algCDF << "(("<<$3<<" <= "<<bucket<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algCDF.str());
		Reader.MyLha.HASLtop.push_back(
		new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
		Reader.MyLha.ConfidenceLevel));
		Reader.MyLha.HASLtop.back()->TypeOp = CDF_PART;
		std::ostringstream s; s<<"$_$: Value in [-infinity , "<< bucket<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	$$ = NULL;
}

| LB TopHaslExp RB {
	$$ = $2;
}
| TopHaslExp PLUS TopHaslExp {
	$$ = new HaslFormulasTop(HASL_PLUS, $1,$3);
}
| TopHaslExp MUL TopHaslExp {
	$$ = new HaslFormulasTop(HASL_TIME, $1, $3);
}
| TopHaslExp DIV TopHaslExp {
	$$ = new HaslFormulasTop(HASL_DIV, $1,$3);
}
| ival {
	$$ = new HaslFormulasTop(0.0,(double)$1);
}
| rval {
	$$ = new HaslFormulasTop(0.0,(double)$1);
}

AlgExpr:LhaFunc {string ss=$1;
	sprintf($$,"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
|MIN LB AlgExpr COMMA AlgExpr  RB {sprintf($$,"min(%s,%s)", $3,$5);}
|MAX LB AlgExpr COMMA AlgExpr  RB {sprintf($$,"max(%s,%s)", $3,$5);}
|MINUS AlgExpr %prec NEG {sprintf($$,"-%s", $2);}
|FLOOR LB AlgExpr RB {sprintf($$,"floor(%s)", $3);}
|LB AlgExpr RB {sprintf($$,"(%s)", $2);}
|AlgExpr POWER AlgExpr {sprintf($$,"pow(%s , %s)", $1,$3);}
|AlgExpr PLUS AlgExpr {sprintf($$,"(%s + %s)", $1,$3);}
|AlgExpr MINUS AlgExpr {sprintf($$,"(%s - %s)", $1,$3);}
|AlgExpr MUL AlgExpr {sprintf($$,"(%s * %s)", $1,$3);}
|AlgExpr DIV AlgExpr {sprintf($$,"(%s / %s)", $1,$3);};

LhaFunc:  LAST     LB LinForm RB {std::ostringstream s; s<<$3;
	if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end())
	{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
	Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
	Reader.MyLha.LhaFuncType.push_back("Last");
	string ss="Last("; ss.append(s.str()); ss.append(")");
	if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end())
	{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
	sprintf($$,"%s", ss.c_str());
}
|LhaMIN   LB LinForm RB {std::ostringstream s; s<<$3;
	if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end())
	{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
	Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
	Reader.MyLha.LhaFuncType.push_back("Min");
	string ss="Min("; ss.append(s.str()); ss.append(")");
	if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end())
	{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
	sprintf($$,"%s", ss.c_str());
}
|LhaMAX   LB LinForm RB{std::ostringstream s; s<<$3;
	if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end())
	{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
	Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
	Reader.MyLha.LhaFuncType.push_back("Max");
	string ss="Max("; ss.append(s.str()); ss.append(")");
	if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end())
	{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
	sprintf($$,"%s", ss.c_str());
}
|INTEGRAL LB LinForm RB{std::ostringstream s; s<<$3;
	if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end())
	{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
	Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
	Reader.MyLha.LhaFuncType.push_back("Integral");
	string ss="Integral("; ss.append(s.str()); ss.append(")");
	if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end())
	{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
	sprintf($$,"%s", ss.c_str());
};

LinForm: VarTerm {sprintf($$,"%s", $1);  }
|LinForm MINUS VarTerm {sprintf($$,"%s - %s", $1, $3);  }
|LinForm PLUS  VarTerm {sprintf($$,"%s + %s", $1, $3);  };

VarTerm:   str
{ if(Reader.MyLha.VarIndex.find(*$1)!=Reader.MyLha.VarIndex.end())
	{sprintf($$,"Var[%d]", Reader.MyLha.VarIndex[*$1]);}
	else {cout<<*$1<<" is not a Lha variable"<<endl;YYABORT;}}
| LB RealMarkingFormula RB MUL str
{ if(Reader.MyLha.VarIndex.find(*$5)!=Reader.MyLha.VarIndex.end())
	{sprintf($$,"(%s) * Var[%d]", $2, Reader.MyLha.VarIndex[*$5]);
	}
	else {cout<<*$5<<" is not a Lha variable"<<endl;YYABORT;}}
| ival MUL str
{ if(Reader.MyLha.VarIndex.find(*$3)!=Reader.MyLha.VarIndex.end())
	{sprintf($$,"%d * Var[%d]", $1, Reader.MyLha.VarIndex[*$3]);
	}
	else {cout<<*$3<<" is not a Lha variable"<<endl;YYABORT;}}
| rval MUL str
{ if(Reader.MyLha.VarIndex.find(*$3)!=Reader.MyLha.VarIndex.end())
	{sprintf($$,"%f * Var[%d]", $1, Reader.MyLha.VarIndex[*$3]);
	}
	else {cout<<*$3<<" is not a Lha variable"<<endl;YYABORT;}}
| str  MUL str
{ if(Reader.MyLha.VarIndex.find(*$3)!=Reader.MyLha.VarIndex.end())
	{if(Reader.MyLha.LhaRealConstant.find(*$1)!=Reader.MyLha.LhaRealConstant.end())
		{sprintf($$,"%f * Var[%d]", Reader.MyLha.LhaRealConstant[*$1],Reader.MyLha.VarIndex[*$3]);
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*$1)!=Reader.MyLha.PlaceIndex.end())
			{sprintf($$,"Marking[%d] * Var[%d]", Reader.MyLha.PlaceIndex[*$1],Reader.MyLha.VarIndex[*$3]);
			}
			else
			{
				cout<<*$1<<" is not Petri-net Place or a definded constant "<<endl;
				YYABORT;
			}
		}
	}
	else {cout<<*$3<<" is not a Lha variable"<<endl;YYABORT;}
}
|MINUS str %prec NEG
{ if(Reader.MyLha.VarIndex.find(*$2)!=Reader.MyLha.VarIndex.end())
	{sprintf($$,"-Var[%d]", Reader.MyLha.VarIndex[*$2]);}
	else {cout<<*$2<<" is not a Lha variable"<<endl;YYABORT;}}
| MINUS LB RealMarkingFormula RB MUL str
{ if(Reader.MyLha.VarIndex.find(*$6)!=Reader.MyLha.VarIndex.end())
	{sprintf($$,"-(%s) * Var[%d]", $3, Reader.MyLha.VarIndex[*$6]);
	}
	else {cout<<*$5<<" is not a Lha variable"<<endl;YYABORT;}}
| MINUS ival MUL str %prec NEG
{ if(Reader.MyLha.VarIndex.find(*$4)!=Reader.MyLha.VarIndex.end())
	{sprintf($$,"-%d * Var[%d]", $2, Reader.MyLha.VarIndex[*$4]);
	}
	else {cout<<*$4<<" is not a Lha variable"<<endl;YYABORT;}}
| MINUS rval MUL str %prec NEG
{ if(Reader.MyLha.VarIndex.find(*$4)!=Reader.MyLha.VarIndex.end())
	{sprintf($$,"-%f * Var[%d]", $2, Reader.MyLha.VarIndex[*$4]);
	}
	else {cout<<*$4<<" is not a Lha variable"<<endl;YYABORT;}}
| MINUS str  MUL str %prec NEG
{ if(Reader.MyLha.VarIndex.find(*$4)!=Reader.MyLha.VarIndex.end())
	{if(Reader.MyLha.LhaRealConstant.find(*$2)!=Reader.MyLha.LhaRealConstant.end())
		{sprintf($$,"-%f * Var[%d]", Reader.MyLha.LhaRealConstant[*$2],Reader.MyLha.VarIndex[*$4]);
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*$2)!=Reader.MyLha.PlaceIndex.end())
			{sprintf($$,"-Marking[%d] * Var[%d]", Reader.MyLha.PlaceIndex[*$2],Reader.MyLha.VarIndex[*$4]);
			}
			else
			{
				cout<<*$2<<" is not Petri-net Place or a definded constant "<<endl;
				YYABORT;
			}
		}
	}
	else {cout<<*$4<<" is not a Lha variable"<<endl;YYABORT;}
};





%%

void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
