#include "LHA.hpp"

#include <map>
#include <float.h>
#include <math.h>

LHA::LHA() {
}

LHA::~LHA() {
}

LHA::LHA(const LHA & orig) {
}

int LHA::EnabledInitLocation(vector<int>& Marking) {

    for (set<int>::iterator l = InitLoc.begin(); l != InitLoc.end(); l++) {
        if (CheckLocation((*l), Marking))
            return (*l);
    }
    return (-1);
}

int LHA::GetEnabled_S_Edges(int cl, int PetriNetTransition, double DeltaT, vector<int>& Marking, vector<int>& NextMarking) {
    for (set<int>::iterator it = ActionEdges[cl][PetriNetTransition].begin(); it != ActionEdges[cl][PetriNetTransition].end(); it++) {
        if ((CheckLocation(Edge[(*it)].Target, NextMarking))) {
            if (CheckEdgeContraints((*it), DeltaT, Marking)) return (*it);
        }
    }

    return (-1);

}

AutEdge LHA::GetEnabled_A_Edges(unsigned int cl, vector<int>& Marking) {
    AutEdge Ed;
    Ed.Index = -1;
    Ed.FiringTime = DBL_MAX;
    for (set<int>::iterator it = Out_A_Edges[cl].begin(); it != Out_A_Edges[cl].end(); it++) {
        if ((CheckLocation(Edge[(*it)].Target, Marking))) {
            t_interval I = GetEdgeEnablingTime((*it), Marking);
            if (I.first <= I.second) {
                if (I.first < Ed.FiringTime) {
                    Ed.Index = (*it);
                    Ed.FiringTime = I.first;
                }

            }
        }
    }

    return Ed;


}

void LHA::DoElapsedTimeUpdate(double DeltaT, vector<int>& Marking) {

    for (int v = 0; v < NbVar; v++) {
        Var[v] += GetFlow(v, CurrentLocation, Marking) * DeltaT;
    }

}

void LHA::resetVarsTable() {
    for (int v = 0; v < NbVar; v++)
        Var[v] = 0;
    for (int i = 0; i < LinForm.size(); i++) {
        LinForm[i] = 0;
        OldLinForm[i] = 0;
    }
    for (int i = 0; i < LhaFunc.size(); i++)
        LhaFunc[i] = 0;
}

void LHA::reset(vector<int>& Marking) {
  Likelihood = 1.0;
  LHA::resetVarsTable();
  CurrentLocation = EnabledInitLocation(Marking);
  CurrentTime = 0;
}

void LHA::setCurrentLocation(unsigned int loc) {
    CurrentLocation = loc;
}

bool LHA::isFinal(unsigned int l) {
    return ( (FinalLoc.find(l) != FinalLoc.end()) ? true : false);
}

double LHA::min(double& a, double& b) {
    if (a <= b)return a;
    else return b;
}

double LHA::max(double& a, double& b) {
    if (a >= b)return a;
    else return b;
}

double LHA::Min(double& a, double& b, double& c) {
    double x = min(b, c);
    return min(a, x);
}

double LHA::Max(double& a, double& b, double& c) {
    double x = max(b, c);
    return max(a, x);
}

double LHA::Integral(double& OldInt, double& t, double& Delta, double& x, double& y) {
    if (x * y >= 0) return (OldInt + Delta * (x + y) / 2);
    double a = (y - x) / Delta;
    double b = x - a*t;
    double t0 = -b / a;
    return (OldInt + (t0 - t) * x / 2 + (t + Delta - t0) * y / 2);
}





void LHA::Load(){
    NbLoc =3;
    NbVar =2;
    InitLoc.insert(0);
    FinalLoc.insert(1);
    FinalLoc.insert(2);
    LocIndex["l0"]=0;
    LocIndex["l1"]=1;
    LocIndex["l2"]=2;

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    StrLocProperty= vlstr;

    vector < vector <string> >  vestr(3);
    ConstraintsRelOp= vestr;
    ConstraintsConstants= vestr;
    vector < vector< vector <string> > > mvestr(3);
    ConstraintsCoeffs= mvestr;

    vector<LhaEdge> ve(3);
    Edge= ve;

    LocLabel[0]="l0";
    LocLabel[1]="l1";
    LocLabel[2]="l2";
    StrLocProperty[0]="! (  Marking[ 1 ]  == 5 &&  Marking[ 4 ]  == 5 )";
    StrLocProperty[1]="(  Marking[ 1 ]  == 5 &&  Marking[ 4 ]  == 5 )";
    StrLocProperty[2]="! (  Marking[ 1 ]  == 5 &&  Marking[ 4 ]  == 5 )";
    Edge[0].Index=0;
    Edge[0].Source=0;
    Edge[0].Target=0;
    Edge[0].Type= Synch;
    Edge[1].Index=1;
    Edge[1].Source=0;
    Edge[1].Target=1;
    Edge[1].Type= Synch;
    Edge[2].Index=2;
    Edge[2].Source=0;
    Edge[2].Target=2;
    Edge[2].Type= Auto ;

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[0]=vcstr;
    ConstraintsConstants[0]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[0]=v2cvstr;
    }
    ConstraintsRelOp[0][0]="<=";
    ConstraintsConstants[0][0]="10";
    ConstraintsCoeffs[0][0][0]="1";
    ConstraintsCoeffs[0][0][1]="";

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[1]=vcstr;
    ConstraintsConstants[1]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[1]=v2cvstr;
    }
    ConstraintsRelOp[1][0]="<=";
    ConstraintsConstants[1][0]="10";
    ConstraintsCoeffs[1][0][0]="1";
    ConstraintsCoeffs[1][0][1]="";

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[2]=vcstr;
    ConstraintsConstants[2]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[2]=v2cvstr;
    }
    ConstraintsRelOp[2][0]="==";
    ConstraintsConstants[2][0]="10";
    ConstraintsCoeffs[2][0][0]="1";
    ConstraintsCoeffs[2][0][1]="";

    vector<double> vdouble(NbVar);
    vector<string> VarStr(NbVar);
    Var=vdouble;
    VarLabel=VarStr;
    Var[0]=0;
    VarLabel[0]="x1";
    VarIndex["x1"]=0;
    Var[1]=0;
    VarLabel[1]="OK";
    VarIndex["OK"]=1;

    vector<string> vStr(NbVar);
    vector< vector <string > > vvStr(NbLoc,vStr);
    StrFlow=vvStr;
    StrFlow[0][0]="";
    StrFlow[0][1]="";
    StrFlow[1][0]="";
    StrFlow[1][1]="";
    StrFlow[2][0]="";
    StrFlow[2][1]="";

    vector< set < int > > vset(NbLoc);
    Out_S_Edges =vset;
    Out_A_Edges =vset;
    Out_S_Edges[0].insert(0);
    Out_S_Edges[0].insert(1);
    Out_A_Edges[0].insert(2);

    vector< set <string> > vStrSet(3);
    vector< set<int> > vSetInt(5);
    vector < vector < set <int> > > vvSetInt(NbLoc,vSetInt);
    EdgeActions=vStrSet;
    ActionEdges=vvSetInt;
    EdgeActions[0].insert("Arrive");
    ActionEdges[0][0].insert(0);
    EdgeActions[0].insert("Leave");
    ActionEdges[0][4].insert(0);
    EdgeActions[0].insert("Route1");
    ActionEdges[0][2].insert(0);
    EdgeActions[0].insert("Route2");
    ActionEdges[0][3].insert(0);
    EdgeActions[0].insert("ToPhase2");
    ActionEdges[0][1].insert(0);
    EdgeActions[1].insert("Arrive");
    ActionEdges[0][0].insert(1);
    EdgeActions[1].insert("Leave");
    ActionEdges[0][4].insert(1);
    EdgeActions[1].insert("Route1");
    ActionEdges[0][2].insert(1);
    EdgeActions[1].insert("Route2");
    ActionEdges[0][3].insert(1);
    EdgeActions[1].insert("ToPhase2");
    ActionEdges[0][1].insert(1);
    if(true){
    			vector<double> vL(1,0);
    			LinForm=vL;
    			OldLinForm=vL;
    			vector<double> vF(1,0);
    			LhaFunc=vF;
    }
}

double LHA::GetFlow(int v, int loc, vector<int>& Marking){
    switch(v){
    case 0:
         switch(loc){
         case 0:
             return 1;
             break;
         case 1:
             return 1;
             break;
         case 2:
             return 1;
             break;
       }
       break;
    case 1:
         switch(loc){
         case 0:
             return 0;
             break;
         case 1:
             return 0;
             break;
         case 2:
             return 0;
             break;
       }
       break;
	}

}

bool LHA::CheckLocation(int loc, vector<int>& Marking){
    switch(loc){
     case 0:
         return ! (  Marking[ 1 ]  == 5 &&  Marking[ 4 ]  == 5 );
         break;
     case 1:
         return (  Marking[ 1 ]  == 5 &&  Marking[ 4 ]  == 5 );
         break;
     case 2:
         return ! (  Marking[ 1 ]  == 5 &&  Marking[ 4 ]  == 5 );
         break;
    }
}

bool LHA::CheckEdgeContraints(int ed, double DeltaT, vector<int>& Marking){
    switch(ed){
    case 0: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,0, Marking))<=10)) return false;
         return true; 
         break;
     }
    case 1: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,0, Marking))<=10)) return false;
         return true; 
         break;
     }
    case 2: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,0, Marking))==10)) return false;
         return true; 
         break;
     }
    }
}

t_interval LHA::GetEdgeEnablingTime(int ed, vector<int>& Marking){
    switch(ed){
     case 0:
         return GetEdgeEnablingTime_0( Marking);
         break;
     case 1:
         return GetEdgeEnablingTime_1( Marking);
         break;
     case 2:
         return GetEdgeEnablingTime_2( Marking);
         break;
    }
}

t_interval LHA::GetEdgeEnablingTime_0(vector<int>& Marking){
    t_interval EnablingT;

    EnablingT.first=CurrentTime;
    EnablingT.second=DBL_MAX;

    t_interval EmptyInterval;

    EmptyInterval.first=0;
    EmptyInterval.second=-1;

    double SumAF;
    double SumAX;


    SumAF=+(1)*GetFlow(0,0, Marking);
    SumAX=+(1)*Var[0];

    if(SumAF==0){
         if(!(SumAX<=10))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(10-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.second>t) EnablingT.second=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
    }
    return EnablingT;
}

t_interval LHA::GetEdgeEnablingTime_1(vector<int>& Marking){
    t_interval EnablingT;

    EnablingT.first=CurrentTime;
    EnablingT.second=DBL_MAX;

    t_interval EmptyInterval;

    EmptyInterval.first=0;
    EmptyInterval.second=-1;

    double SumAF;
    double SumAX;


    SumAF=+(1)*GetFlow(0,0, Marking);
    SumAX=+(1)*Var[0];

    if(SumAF==0){
         if(!(SumAX<=10))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(10-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.second>t) EnablingT.second=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
    }
    return EnablingT;
}

t_interval LHA::GetEdgeEnablingTime_2(vector<int>& Marking){
    t_interval EnablingT;

    EnablingT.first=CurrentTime;
    EnablingT.second=DBL_MAX;

    t_interval EmptyInterval;

    EmptyInterval.first=0;
    EmptyInterval.second=-1;

    double SumAF;
    double SumAX;


    SumAF=+(1)*GetFlow(0,0, Marking);
    SumAX=+(1)*Var[0];

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

void LHA::DoEdgeUpdates(int ed, vector<int>& Marking){
    switch(ed){
     case 0:
         DoEdgeUpdates_0( Marking);
         break;
     case 1:
         DoEdgeUpdates_1( Marking);
         break;
     case 2:
         DoEdgeUpdates_2( Marking);
         break;
    }
}

void LHA::DoEdgeUpdates_0(vector<int>& Marking){

    OldLinForm[0]=LinForm[0];
    }

void LHA::DoEdgeUpdates_1(vector<int>& Marking){
    vector<double> TempVar(NbVar);
    TempVar[1]=1;
    Var[1]=TempVar[1];

    OldLinForm[0]=LinForm[0];
    }

void LHA::DoEdgeUpdates_2(vector<int>& Marking){
    vector<double> TempVar(NbVar);
    TempVar[1]=0;
    Var[1]=TempVar[1];

    OldLinForm[0]=LinForm[0];
    }

void LHA::UpdateLinForm(vector<int>& Marking){
    LinForm[0]=Var[1];
    }

void LHA::UpdateLhaFunc(double& t, double& Delta ){
    LhaFunc[0]=LinForm[0];

    }

void LHA::UpdateFormulaVal(){

    OldFormulaVal=FormulaVal;
    FormulaVal=LhaFunc[0];

    }

