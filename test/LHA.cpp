#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double C=5;
    const double N=5;
    const double T=10;
struct Variables {
	double x1;
};
bool varOrder(const Variables &v1,const Variables &v2){
	if(v1.x1<v2.x1)return true;
	return false;
};
void LHA::resetVariables(){
	Vars->x1= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\t";
};
void LHA::printState(ostream &s){
	s << "\t" << LocLabel[CurrentLocation] << "\t";
};
const int LHA::ActionEdgesAr[] = {
	2 ,2 ,2 ,2 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,0 ,0 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	1 ,1 ,1 ,1 ,1 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
LHA::LHA():NbLoc(3),NbTrans(5),NbVar(1),FinalLoc( 3,false){
    InitLoc.insert(0);
    FinalLoc[1]=true;
    Edge= vector<LhaEdge>(3);
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 1,Synch);
    Edge[2] = LhaEdge(2, 0, 2,Auto);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges[0].insert(2);
    LinForm= vector<double>(0,0.0);
    OldLinForm=vector<double>(0,0.0);
    LhaFunc=vector<double>(0,0.0);
    FormulaVal = vector<double>(0,0.0);
    FormulaValQual = vector<bool>(0,false);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->x1 += GetFlow(0, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
			return 1;


}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
	switch (loc){
		case 1:	//l1
         return (  Marking.P->_PL_Queue1  == 5 &&  Marking.P->_PL_Queue2  == 5 );

		break;
		default:	//l0,l2,
         return ! (  Marking.P->_PL_Queue1  == 5 &&  Marking.P->_PL_Queue2  == 5 );

		break;
	}
}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
	switch (ed){
		case 2:	//
	return true;

		break;
		default:	//,,
{
         if(!( +(1)*Vars->x1<=10)) return false;
		return (true);
     }

		break;
	}
}

t_interval LHA::GetEdgeEnablingTime(int ed,const abstractMarking& Marking)const{
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
             SumAX=+(1)*Vars->x1;

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

void LHA::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){

}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateFormulaVal(){

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

