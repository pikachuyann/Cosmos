#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
struct Variables {
	double OK;
	double r;
	double y;
	double x;
};
void LHA::resetVariables(){
	Vars->OK= 0;
	Vars->r= 0;
	Vars->y= 0;
	Vars->x= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
};
const int LHA::ActionEdgesAr[] = {
	1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,2 ,2 ,
	0 ,0 ,0 ,1 ,1 ,1 ,-1,-1,-1,-1,-1,-1,2 ,2 ,2 ,
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3 ,3 ,3 ,};
LHA::LHA():NbLoc(5),FinalLoc(5,false),NbTrans(3),NbVar(4){
    InitLoc.insert(0);
    FinalLoc[2]=true;
    FinalLoc[3]=true;
    Edge= vector<LhaEdge>(4);
    Edge[0] = LhaEdge(0, 0, 1,Synch);
    Edge[1] = LhaEdge(1, 1, 4,Synch);
    Edge[2] = LhaEdge(2, 4, 2,Synch);
    Edge[3] = LhaEdge(3, 4, 3,Synch);
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
	Vars->OK += GetFlow(0, Marking) * DeltaT;
	Vars->r += GetFlow(1, Marking) * DeltaT;
	Vars->y += GetFlow(2, Marking) * DeltaT;
	Vars->x += GetFlow(3, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
switch (v){
	case 3:	//x
switch (CurrentLocation){
	case 0:	//l0
			return 1;

		break;
	default:	//l1,lp,lm,l2,
		return 0.0;

}

		break;
	case 2:	//y
switch (CurrentLocation){
	case 1:	//l1
			return 1;

		break;
	default:	//l0,lp,lm,l2,
		return 0.0;

}

		break;
	default:	//OK,r,
		return 0.0;


}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
switch (ed){
	case 2:	//
{
		return ((Vars->r<=1));
     }

		break;
	case 3:	//
{
		return ((Vars->r>=1));
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
		Vars->r=((Vars->x*Vars->x)+(Vars->y*Vars->y));
         }

		break;
}
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]= Vars->OK;

    }

void LHA::UpdateFormulaVal(){

    FormulaVal[0]=LhaFunc[0];
}

