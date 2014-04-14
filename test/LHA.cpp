#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
struct Variables {
	double x;
	double y;
	double r;
	double OK;
};
void LHA::resetVariables(){
	Vars->x= 0;
	Vars->y= 0;
	Vars->r= 0;
	Vars->OK= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\tx\ty\tr\tOK\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->x << "\t";
	s << Vars->y << "\t";
	s << Vars->r << "\t";
	s << Vars->OK << "\t";
};
const int LHA::ActionEdgesAr[] = {
	1 ,1 ,1 ,1 ,1 ,1 ,2 ,2 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,1 ,1 ,1 ,2 ,2 ,2 ,-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,3 ,3 ,3 ,-1,-1,-1,-1,-1,-1,};
LHA::LHA():NbLoc(5),NbVar(4),NbTrans(3),FinalLoc(5,false){
    InitLoc.insert(0);
    FinalLoc[3]=true;
    Edge= vector<LhaEdge>(4);

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    LocLabel[0]="l0";
    LocLabel[1]="l1";
    LocLabel[2]="l2";
    LocLabel[3]="lp";
    LocLabel[4]="lm";
    VarLabel= vector<string>(NbVar);
    VarLabel[0]="x";
    VarLabel[1]="y";
    VarLabel[2]="r";
    VarLabel[3]="OK";
    Edge[0] = LhaEdge(0, 0, 1,Synch);
    Edge[1] = LhaEdge(1, 1, 2,Synch);
    Edge[2] = LhaEdge(2, 2, 3,Synch);
    Edge[3] = LhaEdge(3, 2, 4,Synch);
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
	Vars->y += GetFlow(1, Marking) * DeltaT;
	Vars->OK += GetFlow(3, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
switch (v){
	case 3:	//OK
		return 0.0;


		break;
	case 0:	//x
switch (CurrentLocation){
	case 0:	//l0
			return 1;

		break;
	case 4:	//lm
		return 0.0;

		break;
	default:	//l1,l2,lp,
			return 0;

}

		break;
	case 1:	//y
switch (CurrentLocation){
	case 1:	//l1
			return 1;

		break;
	case 4:	//lm
		return 0.0;

		break;
	default:	//l0,l2,lp,
			return 0;

}

		break;
}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
switch (ed){
	case 2:	//
{
         if(!( +(1)*Vars->r<=1)) return false;
		return (true);
     }

		break;
	case 3:	//
{
         if(!( +(1)*Vars->r>=1)) return false;
		return (true);
     }

		break;
	default:	//,,
	return true;

}
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
	case 3:	//
         {
		Vars->OK=0;
         }

		break;
	case 2:	//
         {
		Vars->OK=4;
         }

		break;
	case 1:	//
         {
		Vars->r=Vars->x * Vars->x + Vars->y * Vars->y;
         }

		break;
}
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]= Vars->r;

    }

void LHA::UpdateFormulaVal(){

    FormulaVal[0]=LhaFunc[0];
}

