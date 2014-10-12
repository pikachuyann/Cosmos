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
	double takeLeft;
	double takeRight;
	double backToThink;
	double PLVAR_Think;
	double PLVAR_Wait;
	double PLVAR_Eat;
	double PLVAR_Fork;
};
void LHA::resetVariables(){
	Vars->time= 0;
	Vars->takeLeft= 0;
	Vars->takeRight= 0;
	Vars->backToThink= 0;
	Vars->PLVAR_Think= 0;
	Vars->PLVAR_Wait= 0;
	Vars->PLVAR_Eat= 0;
	Vars->PLVAR_Fork= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\ttime\ttakeLeft\ttakeRight\tbackToThink\tPLVAR_Think\tPLVAR_Wait\tPLVAR_Eat\tPLVAR_Fork\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->time << "\t";
	s << Vars->takeLeft << "\t";
	s << Vars->takeRight << "\t";
	s << Vars->backToThink << "\t";
	s << Vars->PLVAR_Think << "\t";
	s << Vars->PLVAR_Wait << "\t";
	s << Vars->PLVAR_Eat << "\t";
	s << Vars->PLVAR_Fork << "\t";
};
const int LHA::ActionEdgesAr[] = {
	1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,
	0 ,0 ,0 ,2 ,3 ,4 ,-1,-1,-1,};
LHA::LHA():NbLoc(3),FinalLoc(3,false),NbTrans(3),NbVar(8){
    InitLoc.insert(0);
    FinalLoc[2]=true;
    Edge= vector<LhaEdge>(6);

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    LocLabel[0]="l0";
    LocLabel[1]="l1";
    LocLabel[2]="l2";
    VarLabel= vector<string>(NbVar);
    VarLabel[0]="time";
    VarLabel[1]="takeLeft";
    VarLabel[2]="takeRight";
    VarLabel[3]="backToThink";
    VarLabel[4]="PLVAR_Think";
    VarLabel[5]="PLVAR_Wait";
    VarLabel[6]="PLVAR_Eat";
    VarLabel[7]="PLVAR_Fork";
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 1,Auto);
    Edge[2] = LhaEdge(2, 1, 1,Synch);
    Edge[3] = LhaEdge(3, 1, 1,Synch);
    Edge[4] = LhaEdge(4, 1, 1,Synch);
    Edge[5] = LhaEdge(5, 1, 2,Auto);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges[0].insert(1);
    Out_A_Edges[1].insert(5);
    LinForm= vector<double>(7,0.0);
    OldLinForm=vector<double>(7,0.0);
    LhaFunc=vector<double>(7,0.0);
    FormulaVal = vector<double>(7,0.0);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->time += GetFlow(0, Marking) * DeltaT;
	Vars->takeLeft += GetFlow(1, Marking) * DeltaT;
	Vars->takeRight += GetFlow(2, Marking) * DeltaT;
	Vars->backToThink += GetFlow(3, Marking) * DeltaT;
	Vars->PLVAR_Think += GetFlow(4, Marking) * DeltaT;
	Vars->PLVAR_Wait += GetFlow(5, Marking) * DeltaT;
	Vars->PLVAR_Eat += GetFlow(6, Marking) * DeltaT;
	Vars->PLVAR_Fork += GetFlow(7, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
switch (v){
	case 6:	//PLVAR_Eat
switch (CurrentLocation){
	case 1:	//l1
			return  Marking.P->_PL_Eat.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 7:	//PLVAR_Fork
switch (CurrentLocation){
	case 1:	//l1
			return  Marking.P->_PL_Fork.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 4:	//PLVAR_Think
switch (CurrentLocation){
	case 1:	//l1
			return  Marking.P->_PL_Think.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 5:	//PLVAR_Wait
switch (CurrentLocation){
	case 1:	//l1
			return  Marking.P->_PL_Wait.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 0:	//time
switch (CurrentLocation){
	case 2:	//l2
		return 0.0;

		break;
	default:	//l0,l1,
			return 1;

}

		break;
	default:	//takeLeft,takeRight,backToThink,
		return 0.0;


}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
switch (ed){
	case 1:	//
	case 5:	//
	return true;

		break;
	case 0:	//
{
         if(!( +(1)*Vars->time<=0)) return false;
		return (true);
     }

		break;
	default:	//,,,
{
         if(!( +(1)*Vars->time<=100)) return false;
		return (true);
     }

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
	case 5:	//
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
	default:	//,,,,
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             return EnablingT;
         }

}
}

void LHA::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){
switch (ed){
	case 4:	//
         {
		Vars->backToThink=Vars->backToThink + 0.010000;
         }

		break;
	case 2:	//
         {
		Vars->takeLeft=Vars->takeLeft + 0.010000;
         }

		break;
	case 3:	//
         {
		Vars->takeRight=Vars->takeRight + 0.010000;
         }

		break;
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

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]= Vars->takeLeft;
    LhaFunc[1]= Vars->takeRight;
    LhaFunc[2]= Vars->backToThink;
    LhaFunc[3]= Vars->PLVAR_Think;
    LhaFunc[4]= Vars->PLVAR_Wait;
    LhaFunc[5]= Vars->PLVAR_Eat;
    LhaFunc[6]= Vars->PLVAR_Fork;

    }

void LHA::UpdateFormulaVal(){

    FormulaVal[0]=LhaFunc[0];
    FormulaVal[1]=LhaFunc[1];
    FormulaVal[2]=LhaFunc[2];
    FormulaVal[3]=LhaFunc[3];
    FormulaVal[4]=LhaFunc[4];
    FormulaVal[5]=LhaFunc[5];
    FormulaVal[6]=LhaFunc[6];
}

