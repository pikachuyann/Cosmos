#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double T=100;
    const double Ttrans=0;
    const double bt=0.5;
    const double fl=1;
    const double fr=1;
    const double invT=0.01;
struct Variables {
	double time;
};
bool varOrder(const Variables &v1,const Variables &v2){
	if(v1.time<v2.time)return true;
	return false;
};
void LHA::resetVariables(){
	Vars->time= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\ttime\t";
};
void LHA::printState(ostream &s){
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->time << "\t";
};
const int LHA::ActionEdgesAr[] = {
	1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
LHA::LHA():NbLoc(3),NbTrans(10),NbVar(1),FinalLoc( 3,false){
    InitLoc.insert(0);
    FinalLoc[2]=true;
    Edge= vector<LhaEdge>(4);

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    LocLabel[0]="l0";
    LocLabel[1]="l1";
    LocLabel[2]="l2";
    VarLabel= vector<string>(NbVar);
    VarLabel[0]="time";
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 1,Auto);
    Edge[2] = LhaEdge(2, 1, 1,Synch);
    Edge[3] = LhaEdge(3, 1, 2,Auto);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges[0].insert(1);
    Out_A_Edges[1].insert(3);
    LinForm= vector<double>(0,0.0);
    OldLinForm=vector<double>(0,0.0);
    LhaFunc=vector<double>(0,0.0);
    FormulaVal = vector<double>(0,0.0);
    FormulaValQual = vector<bool>(0,false);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->time += GetFlow(0, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
	switch (CurrentLocation){
		case 2:	//l2
		return 0.0;

		break;
		default:	//l0,l1,
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
{
         if(!( +(1)*Vars->time<=0)) return false;
		return (true);
     }

		break;
		case 2:	//
{
         if(!( +(1)*Vars->time<=100)) return false;
		return (true);
     }

		break;
		default:	//,,
	return true;

		break;
	}
}

t_interval LHA::GetEdgeEnablingTime(int ed,const abstractMarking& Marking)const{
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
             SumAX=+(1)*Vars->time;

             if(SumAF==0){
                  if(!(SumAX==100))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(100-SumAX)/(double)SumAF;
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
	switch (ed){
		case 1:	//
         {
		Vars->time=0;
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

