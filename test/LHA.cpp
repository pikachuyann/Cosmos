#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double K=5;
    const double N=6;
    const double N2=3;
    const double Nm=5;
    const double ac=1;
    const double ac2=0.5;
    const double bc=10;
    const double cc=0.5;
struct Variables {
	double succ;
};
void LHA::resetVariables(){
	Vars->succ= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\tsucc\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->succ << "\t";
};
const int LHA::ActionEdgesAr[] = {
	2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
LHA::LHA():NbLoc(2),FinalLoc(2,false),NbTrans(17),NbVar(1){
    InitLoc.insert(0);
    FinalLoc[1]=true;
    Edge= vector<LhaEdge>(2);

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    LocLabel[0]="i";
    LocLabel[1]="f";
    VarLabel= vector<string>(NbVar);
    VarLabel[0]="succ";
    Edge[0] = LhaEdge(0, 0, 1,Synch);
    Edge[1] = LhaEdge(1, 0, 0,Synch);
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
	Vars->succ += GetFlow(0, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
		return 0.0;


}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
switch (loc){
	case 1:	//f
         return (Marking.P->_PL_RE_p6bis >=N);

		break;
	default:	//i,
         return (Marking.P->_PL_RE_p6bis <N);

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
	case 0:	//
         {
		Vars->succ=1;
         }

		break;
}
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]= Vars->succ;

    }

void LHA::UpdateFormulaVal(){

    FormulaVal[0]=LhaFunc[0];
}

