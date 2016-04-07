#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double Dline=10;
    const double c1=1;
    const double c2=3;
struct Variables {
	double countT;
	double t1;
	double t2;
	double time;
};
bool varOrder(const Variables &v1,const Variables &v2){
	if(v1.countT<v2.countT)return true;
	if(v1.t1<v2.t1)return true;
	if(v1.t2<v2.t2)return true;
	if(v1.time<v2.time)return true;
	return false;
};
void LHA::resetVariables(){
	Vars->countT= 0;
	Vars->t1= 0;
	Vars->t2= 0;
	Vars->time= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\tcountT\tt1\tt2\ttime\t";
};
void LHA::printState(ostream &s){
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->countT << "\t";
	s << Vars->t1 << "\t";
	s << Vars->t2 << "\t";
	s << Vars->time << "\t";
};
const int LHA::ActionEdgesAr[] = {
	2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,
	4 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,6 ,6 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,8 ,8 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,10 ,10 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,
	5 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
LHA::LHA():NbLoc(4),NbTrans(24),NbVar(4),FinalLoc( 4,false){
    InitLoc.insert(0);
    FinalLoc[3]=true;
    Edge= vector<LhaEdge>(11);

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    LocLabel[0]="li";
    LocLabel[1]="l1";
    LocLabel[2]="l2";
    LocLabel[3]="lf";
    VarLabel= vector<string>(NbVar);
    VarLabel[0]="countT";
    VarLabel[1]="t1";
    VarLabel[2]="t2";
    VarLabel[3]="time";
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 1, 1,Synch);
    Edge[2] = LhaEdge(2, 2, 2,Synch);
    Edge[3] = LhaEdge(3, 3, 3,Synch);
    Edge[4] = LhaEdge(4, 0, 0,Synch);
    Edge[5] = LhaEdge(5, 0, 1,Synch);
    Edge[6] = LhaEdge(6, 1, 1,Synch);
    Edge[7] = LhaEdge(7, 1, 2,Synch);
    Edge[8] = LhaEdge(8, 2, 2,Synch);
    Edge[9] = LhaEdge(9, 2, 3,Synch);
    Edge[10] = LhaEdge(10, 3, 3,Synch);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    LinForm= vector<double>(0,0.0);
    OldLinForm=vector<double>(0,0.0);
    LhaFunc=vector<double>(0,0.0);
    FormulaVal = vector<double>(0,0.0);
    FormulaValQual = vector<bool>(0,false);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->t1 += GetFlow(1, Marking) * DeltaT;
	Vars->t2 += GetFlow(2, Marking) * DeltaT;
	Vars->time += GetFlow(3, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
	switch (v){
		case 0:	//countT

		break;
		default:	//t1,t2,time,
			return 1;


		break;
	}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
	switch (ed){
		case 0:	//
		case 3:	//
{
         if(!( +(1)*Vars->countT<=10)) return false;
		return (true);
     }

		break;
		case 1:	//
		case 2:	//
{
         if(!( +(1)*Vars->countT<=10)) return false;
         if(!( +(1)*Vars->t1<=3)) return false;
		return (true);
     }

		break;
		case 6:	//
		case 8:	//
{
         if(!( +(1)*Vars->t1<=3)) return false;
		return (true);
     }

		break;
		case 7:	//
{
         if(!( +(1)*Vars->t1>=1)) return false;
         if(!( +(1)*Vars->t1<=3)) return false;
		return (true);
     }

		break;
		case 9:	//
{
         if(!( +(1)*Vars->t2>=1)) return false;
         if(!( +(1)*Vars->t1<=3)) return false;
		return (true);
     }

		break;
		default:	//,,,
	return true;

		break;
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
		case 0:	//
		case 1:	//
		case 2:	//
		case 3:	//

		break;
		case 5:	//
         {
		tempVars->countT=Vars->countT + 1;
		tempVars->t1=0;
		Vars->countT = tempVars->countT;
		Vars->t1 = tempVars->t1;
         }

		break;
		case 7:	//
         {
		tempVars->countT=Vars->countT + 1;
		tempVars->t2=0;
		Vars->countT = tempVars->countT;
		Vars->t2 = tempVars->t2;
         }

		break;
		default:	//,,,,,
         {
		Vars->countT=Vars->countT + 1;
         }

		break;
	}
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateFormulaVal(){

}

bool IsLHADeterministic = 0;
fullState::fullState():loc(0){
	var= new Variables;
}

fullState::fullState(int l,const Variables &v):loc(l){
	var= new Variables(v);
}

fullState::fullState(const fullState &fs):loc(fs.loc){
	var= new Variables(*(fs.var));
}

fullState::~fullState(){delete var;}

