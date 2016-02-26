#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
struct Variables {
	double vc0;
};
bool varOrder(const Variables &v1,const Variables &v2){
	if(v1.vc0<v2.vc0)return true;
	return false;
};
void LHA::resetVariables(){
	Vars->vc0= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\tvc0\t";
};
void LHA::printState(ostream &s){
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->vc0 << "\t";
};
const int LHA::ActionEdgesAr[] = {
	1 ,0 ,
	0 ,-1,};
LHA::LHA():NbLoc(2),NbTrans(1),NbVar(1),FinalLoc( 2,false){
    InitLoc.insert(0);
    FinalLoc[1]=true;
    Edge= vector<LhaEdge>(1);

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    LocLabel[0]="l0";
    LocLabel[1]="l1";
    VarLabel= vector<string>(NbVar);
    VarLabel[0]="vc0";
    Edge[0] = LhaEdge(0, 0, 1,Synch);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    LinForm= vector<double>(1,0.0);
    OldLinForm=vector<double>(1,0.0);
    LhaFunc=vector<double>(2,0.0);
    FormulaVal = vector<double>(3,0.0);
    FormulaValQual = vector<bool>(0,false);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->vc0 += GetFlow(0, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
	switch (CurrentLocation){
		case 0:	//l0
			return 1;

		break;
		case 1:	//l1
		return 0.0;

		break;
	}

}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

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

}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateFormulaVal(){

    LhaFunc[0]= Vars->vc0;
    LhaFunc[1]= Vars->vc0;
    FormulaVal[0]=LhaFunc[0];
    FormulaVal[1]=LhaFunc[0];
    FormulaVal[2]=(LhaFunc[0] * LhaFunc[0]);
}

bool IsLHADeterministic = 1;
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

