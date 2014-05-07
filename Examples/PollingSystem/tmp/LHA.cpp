#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double T=10;
struct Variables {
	double time;
	double waiting;
};
void LHA::resetVariables(){
	Vars->time= 0;
	Vars->waiting= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
};
const int LHA::ActionEdgesAr[] = {
	3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
LHA::LHA():NbLoc(4),NbVar(2),NbTrans(16){
    InitLoc.insert(0);
    FinalLoc.insert(3);
    Edge= vector<LhaEdge>(12);
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 1,Synch);
    Edge[2] = LhaEdge(2, 0, 2,Synch);
    Edge[3] = LhaEdge(3, 0, 3,Auto);
    Edge[4] = LhaEdge(4, 1, 0,Synch);
    Edge[5] = LhaEdge(5, 1, 1,Synch);
    Edge[6] = LhaEdge(6, 1, 2,Synch);
    Edge[7] = LhaEdge(7, 1, 3,Auto);
    Edge[8] = LhaEdge(8, 2, 0,Synch);
    Edge[9] = LhaEdge(9, 2, 1,Synch);
    Edge[10] = LhaEdge(10, 2, 2,Synch);
    Edge[11] = LhaEdge(11, 2, 3,Auto);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges[0].insert(3);
    Out_A_Edges[1].insert(7);
    Out_A_Edges[2].insert(11);
    LinForm= vector<double>(1,0.0);
    OldLinForm=vector<double>(1,0.0);
    LhaFunc=vector<double>(1,0.0);
    FormulaVal = vector<double>(1,0.0);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->time += GetFlow(0, Marking) * DeltaT;
	Vars->waiting += GetFlow(1, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
switch (v){
	case 1:	//waiting
switch (CurrentLocation){
	case 1:	//l1
			return 1;

		break;
	default:	//l0,l2,l3,
		return 0.0;

}

		break;
	default:	//time,
			return 1;


}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
switch (loc){
	case 2:	//l2
         return (  Marking.P->_PL_Server_1  +  Marking.P->_PL_Action_1  >= 2 );

		break;
	case 1:	//l1
         return ( (  Marking.P->_PL_Q1_wait  == 1 ) && (  Marking.P->_PL_Server_1  +  Marking.P->_PL_Action_1  <= 1 ) );

		break;
	case 3:	//l3
         return true;

		break;
	default:	//l0,
         return (  Marking.P->_PL_Q1_wait  <= 0 );

}
}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
switch (ed){
	case 3:	//
	case 7:	//
	case 11:	//
	return true;

		break;
	default:	//,,,,,,,,,
{
		return (true);
     }

}
}

t_interval LHA::GetEdgeEnablingTime(int ed,const abstractMarking& Marking)const{
switch (ed){
	case 3:	//
	case 7:	//
	case 11:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(0, Marking);
             SumAX=+(1)*Vars->time;

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
	default:	//,,,,,,,,,
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             return EnablingT;
         }

}
}

void LHA::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){

}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]= Vars->waiting;

    }

void LHA::UpdateFormulaVal(){

    FormulaVal[0]=LhaFunc[0];
}

