#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double C=5;
    const double TDiscr=100;
    const double Ttrans=0;
    const double invT=1;
struct Variables {
	double time;
	double countT;
};
bool varOrder(const Variables &v1,const Variables &v2){
	if(v1.time<v2.time)return true;
	if(v1.countT<v2.countT)return true;
	return false;
};
template<class DEDState>
void LHA<DEDState>::resetVariables(){
	Vars->time= 0;
	Vars->countT= 0;
};
template<class DEDState>
void LHA<DEDState>::printHeader(ostream &s)const{
	s << "	Location\t";
};

template<class DEDState>
void LHA<DEDState>::printState(ostream &s){
	s << "\t" << LocLabel[CurrentLocation] << "\t";
};
template<class D>
const int LHA<D>::ActionEdgesAr[] = {
	1 ,1 ,1 ,1 ,1 ,2 ,2 ,2 ,2 ,2 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,0 ,0 ,2 ,2 ,2 ,2 ,2 ,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,3 ,3 ,3 ,3 ,3 ,-1,-1,-1,-1,-1,};
template<class D>
LHA<D>::LHA():NbLoc(3),NbTrans(5),NbVar(2),FinalLoc( 3,false){
    InitLoc.insert(0);
    FinalLoc[2]=true;
    Edge= vector<LhaEdge>(4);
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 1,Auto);
    Edge[2] = LhaEdge(2, 1, 1,Synch);
    Edge[3] = LhaEdge(3, 1, 2,Synch);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges[0].insert(1);
    LinForm= vector<double>(0,0.0);
    OldLinForm=vector<double>(0,0.0);
    LhaFunc=vector<double>(0,0.0);
    FormulaVal = vector<double>(0,0.0);
    FormulaValQual = vector<bool>(0,false);
}

template<class D>
void LHA<D>::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->time += GetFlow(0, Marking) * DeltaT;
}

template<class D>
double LHA<D>::GetFlow(int v, const abstractMarking& Marking)const{
	switch (v){
		case 1:	//countT

		break;
		case 0:	//time
	switch (CurrentLocation){
		case 2:	//l2
		return 0.0;

		break;
		default:	//l0,l1,
			return 1;

		break;
	}

		break;
	}
}

template<class D>
bool LHA<D>::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

template<class D>
bool LHA<D>::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
	switch (ed){
		case 1:	//
	return true;

		break;
		case 2:	//
{
         if(!( +(1)*Vars->countT<=100 - 1)) return false;
		return (true);
     }

		break;
		case 3:	//
{
         if(!( +(1)*Vars->countT==100)) return false;
		return (true);
     }

		break;
		case 0:	//
{
         if(!( +(1)*Vars->time<=0)) return false;
		return (true);
     }

		break;
	}
}

template<class D>
t_interval LHA<D>::GetEdgeEnablingTime(int ed,const abstractMarking& Marking)const{
	switch (ed){
		case 1:	//
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
                  if(!(SumAX==0))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(0-SumAX)/(double)SumAF;
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

template<class D>
void LHA<D>::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){
	switch (ed){
		case 2:	//
         {
		Vars->countT=Vars->countT + 1;
         }

		break;
		case 1:	//
         {
		Vars->time=0;
         }

		break;
	}
}

template<class D>
void LHA<D>::UpdateLinForm(const abstractMarking& Marking){
    }

template<class D>
void LHA<D>::UpdateLhaFunc(double& Delta ){

    }

template<class D>
void LHA<D>::UpdateFormulaVal(){

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

