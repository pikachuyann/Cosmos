#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
struct Variables {
	double t;
	double x;
};
bool varOrder(const Variables &v1,const Variables &v2){
	if(v1.t<v2.t)return true;
	if(v1.x<v2.x)return true;
	return false;
};
void LHA::resetVariables(){
	Vars->t= 0;
	Vars->x= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\t";
};
void LHA::printState(ostream &s){
	s << "\t" << LocLabel[CurrentLocation] << "\t";
};
const int LHA::ActionEdgesAr[] = {
	1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,1 ,0 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
LHA::LHA():NbLoc(4),NbTrans(12),NbVar(2),FinalLoc( 4,false){
    InitLoc.insert(0);
    FinalLoc[1]=true;
    FinalLoc[2]=true;
    FinalLoc[3]=true;
    Edge= vector<LhaEdge>(4);
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 1,Synch);
    Edge[2] = LhaEdge(2, 0, 2,Synch);
    Edge[3] = LhaEdge(3, 0, 3,Auto);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges[0].insert(3);
    LinForm= vector<double>(1,0.0);
    OldLinForm=vector<double>(1,0.0);
    LhaFunc=vector<double>(1,0.0);
    FormulaVal = vector<double>(1,0.0);
    FormulaValQual = vector<bool>(0,false);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->t += GetFlow(0, Marking) * DeltaT;
	Vars->x += GetFlow(1, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
	switch (v){
		case 1:	//x
		return 0.0;


		break;
		case 0:	//t
	switch (CurrentLocation){
		case 0:	//l0
			return 1;

		break;
		default:	//l1,l2,l3,
		return 0.0;

		break;
	}

		break;
	}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
	switch (ed){
		case 0:	//
{
         if(!( +(1)*Vars->t<=300)) return false;
		return (true);
     }

		break;
		default:	//,,,
	return true;

		break;
	}
}

t_interval LHA::GetEdgeEnablingTime(int ed,const abstractMarking& Marking)const{
	switch (ed){
		case 3:	//
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
             SumAX=+(1)*Vars->t;

             if(SumAF==0){
                  if(!(SumAX==300))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(300-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
		default:	//,,,
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             return EnablingT;
         }

		break;
	}
}

void LHA::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){
	switch (ed){
		case 1:	//
		case 2:	//
         {
		Vars->x= Marking.P->_PL_PosFinale ;
         }

		break;
	}
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateFormulaVal(){

    LhaFunc[0]= Vars->x;
    FormulaVal[0]=LhaFunc[0];
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

