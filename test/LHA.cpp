#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double MakeNew=0;
    const double Ncases=500;
    const double Nveh=10;
    const double Nvoies=1;
    const double Vmax=2;
struct Variables {
	double t;
	double x;
};
bool varOrder(const Variables &v1,const Variables &v2){
	if(v1.t<v2.t)return true;
	if(v1.x<v2.x)return true;
	return false;
};
template<class DEDState>
void LHA<DEDState>::resetVariables(){
	Vars->t= 0;
	Vars->x= 0;
};
template<class DEDState>
void LHA<DEDState>::printHeader(ostream &s)const{
	s << "	Location\t";
};
template<class DEDState>
void LHA<DEDState>::printState(ostream &s){
	s << "\t" << LocLabel[CurrentLocation] << "\t";
};
template<class DEDState>
const int LHA<DEDState>::ActionEdgesAr[] = {
	1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
template<class DEDState>
 LHA<DEDState>::LHA():NbLoc(3),NbTrans(12),NbVar(2),FinalLoc( 3,false){
    InitLoc.insert(0);
    FinalLoc[1]=true;
    FinalLoc[2]=true;
    Edge= vector<LhaEdge>(3);
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 1,Synch);
    Edge[2] = LhaEdge(2, 0, 2,Auto);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges[0].insert(2);
    LinForm= vector<double>(1,0.0);
    OldLinForm=vector<double>(1,0.0);
    LhaFunc=vector<double>(1,0.0);
    FormulaVal = vector<double>(1,0.0);
    FormulaValQual = vector<bool>(0,false);
}

template<class DEDState>
void LHA<DEDState>::DoElapsedTimeUpdate(double DeltaT,const DEDState& Marking) {
	Vars->t += GetFlow(0, Marking) * DeltaT;
	Vars->x += GetFlow(1, Marking) * DeltaT;
}
template<class DEDState>
double LHA<DEDState>::GetFlow(int v, const DEDState& Marking)const{
	switch (v){
		case 1:	//x
		return 0.0;


		break;
		case 0:	//t
	switch (CurrentLocation){
		case 0:	//l0
			return 1;

		break;
		default:	//l1,l2,
		return 0.0;

		break;
	}

		break;
	}
}

template<class DEDState>
bool LHA<DEDState>::CheckLocation(int loc,const DEDState& Marking)const{
         return true;

}

template<class DEDState>
bool LHA<DEDState>::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const DEDState& Marking)const{
	switch (ed){
		case 2:	//
	return true;

		break;
		default:	//,,
{
         if(!( +(1)*Vars->t<=100000)) return false;
		return (true);
     }

		break;
	}
}

template<class DEDState>
t_interval LHA<DEDState>::GetEdgeEnablingTime(int ed,const DEDState& Marking)const{
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


             SumAF=+(1)*GetFlow(0, Marking);
             SumAX=+(1)*Vars->t;

             if(SumAF==0){
                  if(!(SumAX==100000))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(100000-SumAX)/(double)SumAF;
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

		break;
	}
}

template<class DEDState>
void LHA<DEDState>::DoEdgeUpdates(int ed,const DEDState& Marking, const abstractBinding& b){
	switch (ed){
		case 0:	//

		break;
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

template<class DEDState>
void LHA<DEDState>::UpdateLinForm(const DEDState& Marking){
    }

template<class DEDState>
void LHA<DEDState>::UpdateLhaFunc(double& Delta ){

    }

template<class DEDState>
void LHA<DEDState>::UpdateFormulaVal(){

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

template class LHA<abstractMarking>;
