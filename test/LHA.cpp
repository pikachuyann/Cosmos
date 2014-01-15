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
    const double invT=0.01;
struct Variables {
	double time;
	double Acquire;
	double Change;
	double Release;
	double SendMsg;
	double SendReply;
	double Start;
	double Update;
	double end_update;
	double PLVAR_Acknowledge;
	double PLVAR_Active;
	double PLVAR_MesBuffReply;
	double PLVAR_Message;
	double PLVAR_Modify;
	double PLVAR_Mutex;
	double PLVAR_RecBuff;
	double PLVAR_WaitMutex;
	double PLVAR_all_active;
	double PLVAR_all_passive;
	double PLVAR_updating;
};
void LHA::resetVariables(){
	Vars->time= 0;
	Vars->Acquire= 0;
	Vars->Change= 0;
	Vars->Release= 0;
	Vars->SendMsg= 0;
	Vars->SendReply= 0;
	Vars->Start= 0;
	Vars->Update= 0;
	Vars->end_update= 0;
	Vars->PLVAR_Acknowledge= 0;
	Vars->PLVAR_Active= 0;
	Vars->PLVAR_MesBuffReply= 0;
	Vars->PLVAR_Message= 0;
	Vars->PLVAR_Modify= 0;
	Vars->PLVAR_Mutex= 0;
	Vars->PLVAR_RecBuff= 0;
	Vars->PLVAR_WaitMutex= 0;
	Vars->PLVAR_all_active= 0;
	Vars->PLVAR_all_passive= 0;
	Vars->PLVAR_updating= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\ttime\tAcquire\tChange\tRelease\tSendMsg\tSendReply\tStart\tUpdate\tend_update\tPLVAR_Acknowledge\tPLVAR_Active\tPLVAR_MesBuffReply\tPLVAR_Message\tPLVAR_Modify\tPLVAR_Mutex\tPLVAR_RecBuff\tPLVAR_WaitMutex\tPLVAR_all_active\tPLVAR_all_passive\tPLVAR_updating\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->time << "\t";
	s << Vars->Acquire << "\t";
	s << Vars->Change << "\t";
	s << Vars->Release << "\t";
	s << Vars->SendMsg << "\t";
	s << Vars->SendReply << "\t";
	s << Vars->Start << "\t";
	s << Vars->Update << "\t";
	s << Vars->end_update << "\t";
	s << Vars->PLVAR_Acknowledge << "\t";
	s << Vars->PLVAR_Active << "\t";
	s << Vars->PLVAR_MesBuffReply << "\t";
	s << Vars->PLVAR_Message << "\t";
	s << Vars->PLVAR_Modify << "\t";
	s << Vars->PLVAR_Mutex << "\t";
	s << Vars->PLVAR_RecBuff << "\t";
	s << Vars->PLVAR_WaitMutex << "\t";
	s << Vars->PLVAR_all_active << "\t";
	s << Vars->PLVAR_all_passive << "\t";
	s << Vars->PLVAR_updating << "\t";
};
LHA::LHA(){
    NbLoc =3;
    NbVar =20;
    InitLoc.insert(0);
    FinalLoc.insert(2);
    vector<LhaEdge> ve(11);
    Edge= ve;

    Edge[0].Index=0;
    Edge[0].Source=0;
    Edge[0].Target=0;
    Edge[0].Type= Synch;
    Edge[1].Index=1;
    Edge[1].Source=0;
    Edge[1].Target=1;
    Edge[1].Type= Auto ;
    Edge[2].Index=2;
    Edge[2].Source=1;
    Edge[2].Target=1;
    Edge[2].Type= Synch;
    Edge[3].Index=3;
    Edge[3].Source=1;
    Edge[3].Target=1;
    Edge[3].Type= Synch;
    Edge[4].Index=4;
    Edge[4].Source=1;
    Edge[4].Target=1;
    Edge[4].Type= Synch;
    Edge[5].Index=5;
    Edge[5].Source=1;
    Edge[5].Target=1;
    Edge[5].Type= Synch;
    Edge[6].Index=6;
    Edge[6].Source=1;
    Edge[6].Target=1;
    Edge[6].Type= Synch;
    Edge[7].Index=7;
    Edge[7].Source=1;
    Edge[7].Target=1;
    Edge[7].Type= Synch;
    Edge[8].Index=8;
    Edge[8].Source=1;
    Edge[8].Target=1;
    Edge[8].Type= Synch;
    Edge[9].Index=9;
    Edge[9].Source=1;
    Edge[9].Target=1;
    Edge[9].Type= Synch;
    Edge[10].Index=10;
    Edge[10].Source=1;
    Edge[10].Target=2;
    Edge[10].Type= Auto ;
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();

    vector< set < int > > vset(NbLoc);
    Out_S_Edges =vset;
    Out_A_Edges =vset;
    Out_S_Edges[0].insert(0);
    Out_A_Edges[0].insert(1);
    Out_S_Edges[1].insert(2);
    Out_S_Edges[1].insert(3);
    Out_S_Edges[1].insert(4);
    Out_S_Edges[1].insert(5);
    Out_S_Edges[1].insert(6);
    Out_S_Edges[1].insert(7);
    Out_S_Edges[1].insert(8);
    Out_S_Edges[1].insert(9);
    Out_A_Edges[1].insert(10);
    vector< set<int> > vSetInt(8);
    vector < vector < set <int> > > vvSetInt(NbLoc,vSetInt);
    ActionEdges=vvSetInt;
    ActionEdges[0][4].insert(0);
    ActionEdges[0][2].insert(0);
    ActionEdges[0][3].insert(0);
    ActionEdges[0][0].insert(0);
    ActionEdges[0][1].insert(0);
    ActionEdges[0][7].insert(0);
    ActionEdges[0][6].insert(0);
    ActionEdges[0][5].insert(0);
    ActionEdges[1][4].insert(2);
    ActionEdges[1][2].insert(3);
    ActionEdges[1][3].insert(4);
    ActionEdges[1][0].insert(5);
    ActionEdges[1][1].insert(6);
    ActionEdges[1][7].insert(7);
    ActionEdges[1][6].insert(8);
    ActionEdges[1][5].insert(9);
    if(true){
    			vector<double> vL(19,0);
    			LinForm=vL;
    			OldLinForm=vL;
    			vector<double> vF(19,0);
    			LhaFunc=vF;
    			vector<double> vA(19,0);
    			FormulaVal=vA;
    }
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->time += GetFlow(0, CurrentLocation, Marking) * DeltaT;
	Vars->Acquire += GetFlow(1, CurrentLocation, Marking) * DeltaT;
	Vars->Change += GetFlow(2, CurrentLocation, Marking) * DeltaT;
	Vars->Release += GetFlow(3, CurrentLocation, Marking) * DeltaT;
	Vars->SendMsg += GetFlow(4, CurrentLocation, Marking) * DeltaT;
	Vars->SendReply += GetFlow(5, CurrentLocation, Marking) * DeltaT;
	Vars->Start += GetFlow(6, CurrentLocation, Marking) * DeltaT;
	Vars->Update += GetFlow(7, CurrentLocation, Marking) * DeltaT;
	Vars->end_update += GetFlow(8, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Acknowledge += GetFlow(9, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Active += GetFlow(10, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_MesBuffReply += GetFlow(11, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Message += GetFlow(12, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Modify += GetFlow(13, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Mutex += GetFlow(14, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_RecBuff += GetFlow(15, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_WaitMutex += GetFlow(16, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_all_active += GetFlow(17, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_all_passive += GetFlow(18, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_updating += GetFlow(19, CurrentLocation, Marking) * DeltaT;
}
double LHA::GetFlow(int v, int loc,const abstractMarking& Marking)const{
switch (v){
	case 9:	//PLVAR_Acknowledge
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Acknowledge.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 10:	//PLVAR_Active
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Active.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 11:	//PLVAR_MesBuffReply
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_MesBuffReply.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 12:	//PLVAR_Message
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Message.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 13:	//PLVAR_Modify
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Modify.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 14:	//PLVAR_Mutex
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Mutex.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 15:	//PLVAR_RecBuff
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_RecBuff.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 16:	//PLVAR_WaitMutex
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_WaitMutex.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 17:	//PLVAR_all_active
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_all_active.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 18:	//PLVAR_all_passive
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_all_passive.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 19:	//PLVAR_updating
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_updating.card()  * 0.01;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 0:	//time
switch (loc){
	case 2:	//l2
		return 0.0;

		break;
	default:	//l0,l1,
			return 1;

}

		break;
	default:	//Acquire,Change,Release,SendMsg,SendReply,Start,Update,end_update,
		return 0.0;


}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
switch (ed){
	case 1:	//
	case 10:	//
	return true;

		break;
	case 0:	//
{
         if(!( +(1)*Vars->time<=0)) return false;
         return true; 
     }

		break;
	default:	//,,,,,,,,
{
         if(!( +(1)*Vars->time<=100)) return false;
         return true; 
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


             SumAF=+(1)*GetFlow(0,0, Marking);
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
	case 10:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             SumAF=+(1)*GetFlow(0,1, Marking);
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
	default:	//,,,,,,,,,
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
	case 1:	//
         {
         tempVars->time=0;
         tempVars->Acquire=Vars->Acquire;
         tempVars->Change=Vars->Change;
         tempVars->Release=Vars->Release;
         tempVars->SendMsg=Vars->SendMsg;
         tempVars->SendReply=Vars->SendReply;
         tempVars->Start=Vars->Start;
         tempVars->Update=Vars->Update;
         tempVars->end_update=Vars->end_update;
         tempVars->PLVAR_Acknowledge=Vars->PLVAR_Acknowledge;
         tempVars->PLVAR_Active=Vars->PLVAR_Active;
         tempVars->PLVAR_MesBuffReply=Vars->PLVAR_MesBuffReply;
         tempVars->PLVAR_Message=Vars->PLVAR_Message;
         tempVars->PLVAR_Modify=Vars->PLVAR_Modify;
         tempVars->PLVAR_Mutex=Vars->PLVAR_Mutex;
         tempVars->PLVAR_RecBuff=Vars->PLVAR_RecBuff;
         tempVars->PLVAR_WaitMutex=Vars->PLVAR_WaitMutex;
         tempVars->PLVAR_all_active=Vars->PLVAR_all_active;
         tempVars->PLVAR_all_passive=Vars->PLVAR_all_passive;
         tempVars->PLVAR_updating=Vars->PLVAR_updating;
		std::swap(Vars,tempVars);
         }

		break;
	case 2:	//
         {
         tempVars->time=Vars->time;
         tempVars->Acquire=Vars->Acquire + 0.010000;
         tempVars->Change=Vars->Change;
         tempVars->Release=Vars->Release;
         tempVars->SendMsg=Vars->SendMsg;
         tempVars->SendReply=Vars->SendReply;
         tempVars->Start=Vars->Start;
         tempVars->Update=Vars->Update;
         tempVars->end_update=Vars->end_update;
         tempVars->PLVAR_Acknowledge=Vars->PLVAR_Acknowledge;
         tempVars->PLVAR_Active=Vars->PLVAR_Active;
         tempVars->PLVAR_MesBuffReply=Vars->PLVAR_MesBuffReply;
         tempVars->PLVAR_Message=Vars->PLVAR_Message;
         tempVars->PLVAR_Modify=Vars->PLVAR_Modify;
         tempVars->PLVAR_Mutex=Vars->PLVAR_Mutex;
         tempVars->PLVAR_RecBuff=Vars->PLVAR_RecBuff;
         tempVars->PLVAR_WaitMutex=Vars->PLVAR_WaitMutex;
         tempVars->PLVAR_all_active=Vars->PLVAR_all_active;
         tempVars->PLVAR_all_passive=Vars->PLVAR_all_passive;
         tempVars->PLVAR_updating=Vars->PLVAR_updating;
		std::swap(Vars,tempVars);
         }

		break;
	case 3:	//
         {
         tempVars->time=Vars->time;
         tempVars->Acquire=Vars->Acquire;
         tempVars->Change=Vars->Change + 0.010000;
         tempVars->Release=Vars->Release;
         tempVars->SendMsg=Vars->SendMsg;
         tempVars->SendReply=Vars->SendReply;
         tempVars->Start=Vars->Start;
         tempVars->Update=Vars->Update;
         tempVars->end_update=Vars->end_update;
         tempVars->PLVAR_Acknowledge=Vars->PLVAR_Acknowledge;
         tempVars->PLVAR_Active=Vars->PLVAR_Active;
         tempVars->PLVAR_MesBuffReply=Vars->PLVAR_MesBuffReply;
         tempVars->PLVAR_Message=Vars->PLVAR_Message;
         tempVars->PLVAR_Modify=Vars->PLVAR_Modify;
         tempVars->PLVAR_Mutex=Vars->PLVAR_Mutex;
         tempVars->PLVAR_RecBuff=Vars->PLVAR_RecBuff;
         tempVars->PLVAR_WaitMutex=Vars->PLVAR_WaitMutex;
         tempVars->PLVAR_all_active=Vars->PLVAR_all_active;
         tempVars->PLVAR_all_passive=Vars->PLVAR_all_passive;
         tempVars->PLVAR_updating=Vars->PLVAR_updating;
		std::swap(Vars,tempVars);
         }

		break;
	case 4:	//
         {
         tempVars->time=Vars->time;
         tempVars->Acquire=Vars->Acquire;
         tempVars->Change=Vars->Change;
         tempVars->Release=Vars->Release + 0.010000;
         tempVars->SendMsg=Vars->SendMsg;
         tempVars->SendReply=Vars->SendReply;
         tempVars->Start=Vars->Start;
         tempVars->Update=Vars->Update;
         tempVars->end_update=Vars->end_update;
         tempVars->PLVAR_Acknowledge=Vars->PLVAR_Acknowledge;
         tempVars->PLVAR_Active=Vars->PLVAR_Active;
         tempVars->PLVAR_MesBuffReply=Vars->PLVAR_MesBuffReply;
         tempVars->PLVAR_Message=Vars->PLVAR_Message;
         tempVars->PLVAR_Modify=Vars->PLVAR_Modify;
         tempVars->PLVAR_Mutex=Vars->PLVAR_Mutex;
         tempVars->PLVAR_RecBuff=Vars->PLVAR_RecBuff;
         tempVars->PLVAR_WaitMutex=Vars->PLVAR_WaitMutex;
         tempVars->PLVAR_all_active=Vars->PLVAR_all_active;
         tempVars->PLVAR_all_passive=Vars->PLVAR_all_passive;
         tempVars->PLVAR_updating=Vars->PLVAR_updating;
		std::swap(Vars,tempVars);
         }

		break;
	case 5:	//
         {
         tempVars->time=Vars->time;
         tempVars->Acquire=Vars->Acquire;
         tempVars->Change=Vars->Change;
         tempVars->Release=Vars->Release;
         tempVars->SendMsg=Vars->SendMsg + 0.010000;
         tempVars->SendReply=Vars->SendReply;
         tempVars->Start=Vars->Start;
         tempVars->Update=Vars->Update;
         tempVars->end_update=Vars->end_update;
         tempVars->PLVAR_Acknowledge=Vars->PLVAR_Acknowledge;
         tempVars->PLVAR_Active=Vars->PLVAR_Active;
         tempVars->PLVAR_MesBuffReply=Vars->PLVAR_MesBuffReply;
         tempVars->PLVAR_Message=Vars->PLVAR_Message;
         tempVars->PLVAR_Modify=Vars->PLVAR_Modify;
         tempVars->PLVAR_Mutex=Vars->PLVAR_Mutex;
         tempVars->PLVAR_RecBuff=Vars->PLVAR_RecBuff;
         tempVars->PLVAR_WaitMutex=Vars->PLVAR_WaitMutex;
         tempVars->PLVAR_all_active=Vars->PLVAR_all_active;
         tempVars->PLVAR_all_passive=Vars->PLVAR_all_passive;
         tempVars->PLVAR_updating=Vars->PLVAR_updating;
		std::swap(Vars,tempVars);
         }

		break;
	case 6:	//
         {
         tempVars->time=Vars->time;
         tempVars->Acquire=Vars->Acquire;
         tempVars->Change=Vars->Change;
         tempVars->Release=Vars->Release;
         tempVars->SendMsg=Vars->SendMsg;
         tempVars->SendReply=Vars->SendReply + 0.010000;
         tempVars->Start=Vars->Start;
         tempVars->Update=Vars->Update;
         tempVars->end_update=Vars->end_update;
         tempVars->PLVAR_Acknowledge=Vars->PLVAR_Acknowledge;
         tempVars->PLVAR_Active=Vars->PLVAR_Active;
         tempVars->PLVAR_MesBuffReply=Vars->PLVAR_MesBuffReply;
         tempVars->PLVAR_Message=Vars->PLVAR_Message;
         tempVars->PLVAR_Modify=Vars->PLVAR_Modify;
         tempVars->PLVAR_Mutex=Vars->PLVAR_Mutex;
         tempVars->PLVAR_RecBuff=Vars->PLVAR_RecBuff;
         tempVars->PLVAR_WaitMutex=Vars->PLVAR_WaitMutex;
         tempVars->PLVAR_all_active=Vars->PLVAR_all_active;
         tempVars->PLVAR_all_passive=Vars->PLVAR_all_passive;
         tempVars->PLVAR_updating=Vars->PLVAR_updating;
		std::swap(Vars,tempVars);
         }

		break;
	case 7:	//
         {
         tempVars->time=Vars->time;
         tempVars->Acquire=Vars->Acquire;
         tempVars->Change=Vars->Change;
         tempVars->Release=Vars->Release;
         tempVars->SendMsg=Vars->SendMsg;
         tempVars->SendReply=Vars->SendReply;
         tempVars->Start=Vars->Start + 0.010000;
         tempVars->Update=Vars->Update;
         tempVars->end_update=Vars->end_update;
         tempVars->PLVAR_Acknowledge=Vars->PLVAR_Acknowledge;
         tempVars->PLVAR_Active=Vars->PLVAR_Active;
         tempVars->PLVAR_MesBuffReply=Vars->PLVAR_MesBuffReply;
         tempVars->PLVAR_Message=Vars->PLVAR_Message;
         tempVars->PLVAR_Modify=Vars->PLVAR_Modify;
         tempVars->PLVAR_Mutex=Vars->PLVAR_Mutex;
         tempVars->PLVAR_RecBuff=Vars->PLVAR_RecBuff;
         tempVars->PLVAR_WaitMutex=Vars->PLVAR_WaitMutex;
         tempVars->PLVAR_all_active=Vars->PLVAR_all_active;
         tempVars->PLVAR_all_passive=Vars->PLVAR_all_passive;
         tempVars->PLVAR_updating=Vars->PLVAR_updating;
		std::swap(Vars,tempVars);
         }

		break;
	case 8:	//
         {
         tempVars->time=Vars->time;
         tempVars->Acquire=Vars->Acquire;
         tempVars->Change=Vars->Change;
         tempVars->Release=Vars->Release;
         tempVars->SendMsg=Vars->SendMsg;
         tempVars->SendReply=Vars->SendReply;
         tempVars->Start=Vars->Start;
         tempVars->Update=Vars->Update + 0.010000;
         tempVars->end_update=Vars->end_update;
         tempVars->PLVAR_Acknowledge=Vars->PLVAR_Acknowledge;
         tempVars->PLVAR_Active=Vars->PLVAR_Active;
         tempVars->PLVAR_MesBuffReply=Vars->PLVAR_MesBuffReply;
         tempVars->PLVAR_Message=Vars->PLVAR_Message;
         tempVars->PLVAR_Modify=Vars->PLVAR_Modify;
         tempVars->PLVAR_Mutex=Vars->PLVAR_Mutex;
         tempVars->PLVAR_RecBuff=Vars->PLVAR_RecBuff;
         tempVars->PLVAR_WaitMutex=Vars->PLVAR_WaitMutex;
         tempVars->PLVAR_all_active=Vars->PLVAR_all_active;
         tempVars->PLVAR_all_passive=Vars->PLVAR_all_passive;
         tempVars->PLVAR_updating=Vars->PLVAR_updating;
		std::swap(Vars,tempVars);
         }

		break;
	case 9:	//
         {
         tempVars->time=Vars->time;
         tempVars->Acquire=Vars->Acquire;
         tempVars->Change=Vars->Change;
         tempVars->Release=Vars->Release;
         tempVars->SendMsg=Vars->SendMsg;
         tempVars->SendReply=Vars->SendReply;
         tempVars->Start=Vars->Start;
         tempVars->Update=Vars->Update;
         tempVars->end_update=Vars->end_update + 0.010000;
         tempVars->PLVAR_Acknowledge=Vars->PLVAR_Acknowledge;
         tempVars->PLVAR_Active=Vars->PLVAR_Active;
         tempVars->PLVAR_MesBuffReply=Vars->PLVAR_MesBuffReply;
         tempVars->PLVAR_Message=Vars->PLVAR_Message;
         tempVars->PLVAR_Modify=Vars->PLVAR_Modify;
         tempVars->PLVAR_Mutex=Vars->PLVAR_Mutex;
         tempVars->PLVAR_RecBuff=Vars->PLVAR_RecBuff;
         tempVars->PLVAR_WaitMutex=Vars->PLVAR_WaitMutex;
         tempVars->PLVAR_all_active=Vars->PLVAR_all_active;
         tempVars->PLVAR_all_passive=Vars->PLVAR_all_passive;
         tempVars->PLVAR_updating=Vars->PLVAR_updating;
		std::swap(Vars,tempVars);
         }

		break;
}
    OldLinForm[0]=LinForm[0];
    OldLinForm[1]=LinForm[1];
    OldLinForm[8]=LinForm[8];
    OldLinForm[9]=LinForm[9];
    OldLinForm[10]=LinForm[10];
    OldLinForm[11]=LinForm[11];
    OldLinForm[12]=LinForm[12];
    OldLinForm[13]=LinForm[13];
    OldLinForm[14]=LinForm[14];
    OldLinForm[15]=LinForm[15];
    OldLinForm[16]=LinForm[16];
    OldLinForm[17]=LinForm[17];
    OldLinForm[18]=LinForm[18];
    OldLinForm[2]=LinForm[2];
    OldLinForm[3]=LinForm[3];
    OldLinForm[4]=LinForm[4];
    OldLinForm[5]=LinForm[5];
    OldLinForm[6]=LinForm[6];
    OldLinForm[7]=LinForm[7];
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    LinForm[0]=Vars->Acquire;
    LinForm[1]=Vars->Change;
    LinForm[8]=Vars->PLVAR_Acknowledge;
    LinForm[9]=Vars->PLVAR_Active;
    LinForm[10]=Vars->PLVAR_MesBuffReply;
    LinForm[11]=Vars->PLVAR_Message;
    LinForm[12]=Vars->PLVAR_Modify;
    LinForm[13]=Vars->PLVAR_Mutex;
    LinForm[14]=Vars->PLVAR_RecBuff;
    LinForm[15]=Vars->PLVAR_WaitMutex;
    LinForm[16]=Vars->PLVAR_all_active;
    LinForm[17]=Vars->PLVAR_all_passive;
    LinForm[18]=Vars->PLVAR_updating;
    LinForm[2]=Vars->Release;
    LinForm[3]=Vars->SendMsg;
    LinForm[4]=Vars->SendReply;
    LinForm[5]=Vars->Start;
    LinForm[6]=Vars->Update;
    LinForm[7]=Vars->end_update;
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]=LinForm[0];
    LhaFunc[1]=LinForm[1];
    LhaFunc[2]=LinForm[2];
    LhaFunc[3]=LinForm[3];
    LhaFunc[4]=LinForm[4];
    LhaFunc[5]=LinForm[5];
    LhaFunc[6]=LinForm[6];
    LhaFunc[7]=LinForm[7];
    LhaFunc[8]=LinForm[8];
    LhaFunc[9]=LinForm[9];
    LhaFunc[10]=LinForm[10];
    LhaFunc[11]=LinForm[11];
    LhaFunc[12]=LinForm[12];
    LhaFunc[13]=LinForm[13];
    LhaFunc[14]=LinForm[14];
    LhaFunc[15]=LinForm[15];
    LhaFunc[16]=LinForm[16];
    LhaFunc[17]=LinForm[17];
    LhaFunc[18]=LinForm[18];

    }

void LHA::UpdateFormulaVal(){

    OldFormulaVal=FormulaVal[0];
    FormulaVal[0]=LhaFunc[0];

    OldFormulaVal=FormulaVal[1];
    FormulaVal[1]=LhaFunc[1];

    OldFormulaVal=FormulaVal[2];
    FormulaVal[2]=LhaFunc[2];

    OldFormulaVal=FormulaVal[3];
    FormulaVal[3]=LhaFunc[3];

    OldFormulaVal=FormulaVal[4];
    FormulaVal[4]=LhaFunc[4];

    OldFormulaVal=FormulaVal[5];
    FormulaVal[5]=LhaFunc[5];

    OldFormulaVal=FormulaVal[6];
    FormulaVal[6]=LhaFunc[6];

    OldFormulaVal=FormulaVal[7];
    FormulaVal[7]=LhaFunc[7];

    OldFormulaVal=FormulaVal[8];
    FormulaVal[8]=LhaFunc[8];

    OldFormulaVal=FormulaVal[9];
    FormulaVal[9]=LhaFunc[9];

    OldFormulaVal=FormulaVal[10];
    FormulaVal[10]=LhaFunc[10];

    OldFormulaVal=FormulaVal[11];
    FormulaVal[11]=LhaFunc[11];

    OldFormulaVal=FormulaVal[12];
    FormulaVal[12]=LhaFunc[12];

    OldFormulaVal=FormulaVal[13];
    FormulaVal[13]=LhaFunc[13];

    OldFormulaVal=FormulaVal[14];
    FormulaVal[14]=LhaFunc[14];

    OldFormulaVal=FormulaVal[15];
    FormulaVal[15]=LhaFunc[15];

    OldFormulaVal=FormulaVal[16];
    FormulaVal[16]=LhaFunc[16];

    OldFormulaVal=FormulaVal[17];
    FormulaVal[17]=LhaFunc[17];

    OldFormulaVal=FormulaVal[18];
    FormulaVal[18]=LhaFunc[18];

}

