#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double N=50;
    const double mu=0.23;
    const double r=5;
    const double rho=0.385;
struct Variables {
	double x;
};
void LHA::resetVariables(){
	Vars->x= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\tx\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->x << "\t";
};
const int LHA::ActionEdgesAr[] = {
	3 ,3 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,-1,-1,-1,-1,-1,-1,
	1 ,1 ,1 ,-1,-1,-1,-1,-1,-1,
	2 ,2 ,2 ,-1,-1,-1,-1,-1,-1,};
LHA::LHA():NbLoc(3),NbVar(1),NbTrans(3){
    InitLoc.insert(0);
    FinalLoc.insert(1);
    Edge= vector<LhaEdge>(3);

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    LocLabel[0]="l1";
    LocLabel[1]="lp";
    LocLabel[2]="lm";
    VarLabel= vector<string>(NbVar);
    VarLabel[0]="x";
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 1,Synch);
    Edge[2] = LhaEdge(2, 0, 2,Synch);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    LinForm= vector<double>(1,0.0);
    OldLinForm=vector<double>(1,0.0);
    LhaFunc=vector<double>(1,0.0);
    FormulaVal = vector<double>(1,0.0);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->x += GetFlow(0, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
		return 0.0;


}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
switch (loc){
	case 1:	//lp
         return (  Marking.P->_PL_RE_Queue1  +  Marking.P->_PL_RE_Queue2  == 50 );

		break;
	case 0:	//l1
         return (  Marking.P->_PL_RE_Queue1  +  Marking.P->_PL_RE_Queue2  > 0 ) && (  Marking.P->_PL_RE_Queue1  +  Marking.P->_PL_RE_Queue2  < 50 );

		break;
	default:	//lm,
         return (  Marking.P->_PL_RE_Queue1  +  Marking.P->_PL_RE_Queue2  == 0 );

}
}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
	return true;

}

t_interval LHA::GetEdgeEnablingTime(int ed,const abstractMarking& Marking)const{
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             return EnablingT;
         }

}

void LHA::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){
switch (ed){
	case 2:	//
         {
		Vars->x=0;
         }

		break;
	case 1:	//
         {
		Vars->x=1;
         }

		break;
}
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]= Vars->x;

    }

void LHA::UpdateFormulaVal(){

    FormulaVal[0]=LhaFunc[0];
}

