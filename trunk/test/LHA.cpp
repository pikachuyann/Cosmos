#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double N=5;
    const double T=10;
struct Variables {
	double x1;
	double OK;
};
void LHA::resetVariables(){
	Vars->x1= 0;
	Vars->OK= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "Location\tx1\tOK\t";
};
void LHA::printState(ostream &s)const{
	s <<  LocLabel[CurrentLocation] << "\t";
	s << Vars->x1 << "\t";
	s << Vars->OK << "\t";
};
LHA::LHA(){
    NbLoc =3;
    NbVar =2;
    InitLoc.insert(0);
    FinalLoc.insert(1);
    FinalLoc.insert(2);
    vector<LhaEdge> ve(3);
    Edge= ve;

    Edge[0].Index=0;
    Edge[0].Source=0;
    Edge[0].Target=0;
    Edge[0].Type= Synch;
    Edge[1].Index=1;
    Edge[1].Source=0;
    Edge[1].Target=1;
    Edge[1].Type= Synch;
    Edge[2].Index=2;
    Edge[2].Source=0;
    Edge[2].Target=2;
    Edge[2].Type= Auto ;
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();

    vector< set < int > > vset(NbLoc);
    Out_S_Edges =vset;
    Out_A_Edges =vset;
    Out_S_Edges[0].insert(0);
    Out_S_Edges[0].insert(1);
    Out_A_Edges[0].insert(2);
    vector< set<int> > vSetInt(5);
    vector < vector < set <int> > > vvSetInt(NbLoc,vSetInt);
    ActionEdges=vvSetInt;
    ActionEdges[0][0].insert(0);
    ActionEdges[0][4].insert(0);
    ActionEdges[0][2].insert(0);
    ActionEdges[0][3].insert(0);
    ActionEdges[0][1].insert(0);
    ActionEdges[0][0].insert(1);
    ActionEdges[0][4].insert(1);
    ActionEdges[0][2].insert(1);
    ActionEdges[0][3].insert(1);
    ActionEdges[0][1].insert(1);
    if(true){
    			vector<double> vL(1,0);
    			LinForm=vL;
    			OldLinForm=vL;
    			vector<double> vF(1,0);
    			LhaFunc=vF;
    			vector<double> vA(1,0);
    			FormulaVal=vA;
    }
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->x1 += GetFlow(0, CurrentLocation, Marking) * DeltaT;
	Vars->OK += GetFlow(1, CurrentLocation, Marking) * DeltaT;
}
double LHA::GetFlow(int v, int loc,const abstractMarking& Marking)const{
switch (v){
	case 1:	//OK
		return 0.0;


		break;
	default:	//x1,
			return 1;


}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
switch (loc){
	case 1:	//l1
         return (  Marking.P->_PL_Queue1  == 5 &&  Marking.P->_PL_Queue2  == 5 );

		break;
	default:	//l0,l2,
         return ! (  Marking.P->_PL_Queue1  == 5 &&  Marking.P->_PL_Queue2  == 5 );

}
}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
switch (ed){
	case 2:	//
	return true;

		break;
	default:	//,,
{
         if(!( +(1)*Vars->x1<=10)) return false;
         return true; 
     }

}
}

t_interval LHA::GetEdgeEnablingTime(int ed,const abstractMarking& Marking)const{
switch (ed){
	case 2:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(0,0, Marking);
             SumAX=+(1)*Vars->x1;

             if(SumAF==0){
                  if(!(SumAX==10))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(10-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
	default:	//,,
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             return EnablingT;
         }

}
}

void LHA::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){
switch (ed){
	case 2:	//
         {
         tempVars->x1=Vars->x1;
         tempVars->OK=0;
		std::swap(Vars,tempVars);
         }

		break;
	case 1:	//
         {
         tempVars->x1=Vars->x1;
         tempVars->OK=1;
		std::swap(Vars,tempVars);
         }

		break;
}
    OldLinForm[0]=LinForm[0];
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    LinForm[0]=Vars->OK;
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]=LinForm[0];

    }

void LHA::UpdateFormulaVal(){

    OldFormulaVal=FormulaVal[0];
    FormulaVal[0]=LhaFunc[0];

}

