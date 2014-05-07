#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double Tinit=100;
    const double maxsndtime=100;
    const double threshold=100;
struct Variables {
	double transient;
	double tupdate;
	double tsend;
	file_Color_Classe modf;
	site_Color_Classe mods;
};
void LHA::resetVariables(){
	Vars->transient= 0;
	Vars->tupdate= 0;
	Vars->tsend= 0;
	Vars->modf= Color_file_Total ;
	Vars->mods= Color_site_Total ;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
};
const int LHA::ActionEdgesAr[] = {
	1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,3 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
	0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,3 ,4 ,4 ,4 ,4 ,5 ,4 ,4 ,4 ,6 ,6 ,8 ,6 ,6 ,6 ,6 ,6 ,10 ,11 ,11 ,11 ,11 ,11 ,11 ,11 ,15 ,15 ,15 ,14 ,15 ,15 ,15 ,15 ,-1,-1,-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7 ,-1,-1,-1,-1,-1,9 ,-1,-1,-1,-1,-1,12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,-1,-1,-1,16 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,13 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
LHA::LHA():NbLoc(7),FinalLoc(7,false),NbTrans(8),NbVar(5){
    InitLoc.insert(0);
    FinalLoc[6]=true;
    Edge= vector<LhaEdge>(17);
    Edge[0] = LhaEdge(0, 0, 0,Synch);
    Edge[1] = LhaEdge(1, 0, 1,Auto);
    Edge[2] = LhaEdge(2, 1, 1,Synch);
    Edge[3] = LhaEdge(3, 1, 2,Synch);
    Edge[4] = LhaEdge(4, 2, 2,Synch);
    Edge[5] = LhaEdge(5, 2, 2,Synch);
    Edge[6] = LhaEdge(6, 3, 3,Synch);
    Edge[7] = LhaEdge(7, 2, 3,Synch);
    Edge[8] = LhaEdge(8, 3, 4,Synch);
    Edge[9] = LhaEdge(9, 3, 3,Synch);
    Edge[10] = LhaEdge(10, 4, 4,Synch);
    Edge[11] = LhaEdge(11, 4, 4,Synch);
    Edge[12] = LhaEdge(12, 4, 5,Synch);
    Edge[13] = LhaEdge(13, 4, 4,Synch);
    Edge[14] = LhaEdge(14, 5, 5,Synch);
    Edge[15] = LhaEdge(15, 5, 5,Synch);
    Edge[16] = LhaEdge(16, 5, 6,Synch);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_A_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges[0].insert(1);
    LinForm= vector<double>(1,0.0);
    OldLinForm=vector<double>(1,0.0);
    LhaFunc=vector<double>(1,0.0);
    FormulaVal = vector<double>(1,0.0);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->transient += GetFlow(0, Marking) * DeltaT;
	Vars->tupdate += GetFlow(1, Marking) * DeltaT;
	Vars->tsend += GetFlow(2, Marking) * DeltaT;
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{
switch (v){
	case 0:	//transient
switch (CurrentLocation){
	case 0:	//InitialTransientPeriod
			return 1;

		break;
	default:	//WaitModify,WaitGetMutex,WaitStartSndMsg,WaitSend,WaitEndUpdate,Final,
		return 0.0;

}

		break;
	case 1:	//tupdate
switch (CurrentLocation){
	case 0:	//InitialTransientPeriod
	case 1:	//WaitModify
	case 6:	//Final
		return 0.0;

		break;
	default:	//WaitGetMutex,WaitStartSndMsg,WaitSend,WaitEndUpdate,
			return 1;

}

		break;
	case 2:	//tsend
switch (CurrentLocation){
	case 4:	//WaitSend
			return 1;

		break;
	default:	//InitialTransientPeriod,WaitModify,WaitGetMutex,WaitStartSndMsg,WaitEndUpdate,Final,
		return 0.0;

}

		break;
}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
switch (ed){
	case 10:	//
{
		return (((Vars->modf !=b.P->f.c0) && (Vars->tsend<=maxsndtime)));
     }

		break;
	case 9:	//
	case 14:	//
{
		return (((Vars->modf !=b.P->f.c0) || (Vars->mods !=b.P->s.c0)));
     }

		break;
	case 12:	//
{
		return (((Vars->modf==b.P->f.c0) && ((Vars->tsend<=maxsndtime) && (Marking.P->_PL_Message.card() ==0))));
     }

		break;
	case 13:	//
{
		return (((Vars->modf==b.P->f.c0) && ((Vars->tsend<=maxsndtime) && (Marking.P->_PL_Message.card() >0))));
     }

		break;
	case 8:	//
	case 16:	//
{
		return (((Vars->modf==b.P->f.c0) && (Vars->mods==b.P->s.c0)));
     }

		break;
	case 5:	//
{
		return (((Vars->mods !=b.P->s.c0) || (Vars->modf !=b.P->f.c0)));
     }

		break;
	case 7:	//
{
		return (((Vars->mods==b.P->s.c0) && ((Vars->modf==b.P->f.c0) && (Vars->tupdate<=threshold))));
     }

		break;
	case 11:	//
{
		return ((Vars->tsend<=maxsndtime));
     }

		break;
	default:	//,,,,,,,
	return true;

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
             SumAX=+(1)*Vars->transient;

             if(SumAF==0){
                  if(!(SumAX==Tinit))
                      return EmptyInterval;
             }
             else{
                  double t=CurrentTime+(Tinit-SumAX)/(double)SumAF;
                  if(t>=EnablingT.first && t<=EnablingT.second){
                      EnablingT.first=t; EnablingT.second=t;
                  }
                  else return EmptyInterval;
             }
             return EnablingT;
         }

		break;
	default:	//,,,,,,,,,,,,,,,,
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
	case 8:	//
         {
		Vars->tsend=0;
         }

		break;
	case 3:	//
         {
		tempVars->tupdate=0;
		tempVars->modf=b.P->f.c0;
		tempVars->mods=b.P->s.c0;
		Vars->tupdate = tempVars->tupdate;
		Vars->modf = tempVars->modf;
		Vars->mods = tempVars->mods;
         }

		break;
}
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]= Vars->tupdate;

    }

void LHA::UpdateFormulaVal(){

    FormulaVal[0]=LhaFunc[0];
}

