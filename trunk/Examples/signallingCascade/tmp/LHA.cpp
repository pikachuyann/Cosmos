#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double c=3;
struct Variables {
	double x;
};
void LHA::resetVariables(){
	Vars->x= 0;
};
void LHA::printHeader(ostream &s){
	s << "Location\tx\t";
};
void LHA::printState(ostream &s){
	s <<  LocLabel[CurrentLocation] << "\t";
	s << Vars->x << "\t";
};
LHA::LHA(){
    NbLoc =3;
    NbVar =1;
    InitLoc.insert(0);
    FinalLoc.insert(1);
    FinalLoc.insert(2);
    vector<LhaEdge> ve(3);
    Edge= ve;

    LocIndex["l1"]=0;
    LocIndex["lm"]=2;
    LocIndex["lp"]=1;

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    StrLocProperty= vlstr;

    vector < vector <string> >  vestr(3);
    ConstraintsRelOp= vestr;
    ConstraintsConstants= vestr;
    vector < vector< vector <string> > > mvestr(3);
    ConstraintsCoeffs= mvestr;

    LocLabel[0]="l1";
    LocLabel[1]="lp";
    LocLabel[2]="lm";
    StrLocProperty[0]="(  Marking.P->_PL_RE_ERKPP  < 3 ) && (  Marking.P->_PL_Puit  == 0 )";
    StrLocProperty[1]="(  Marking.P->_PL_RE_ERKPP  == 3 ) && (  Marking.P->_PL_Puit  == 0 )";
    StrLocProperty[2]="(  Marking.P->_PL_RE_ERKPP  < 3 ) || (  Marking.P->_PL_Puit  > 1 )";
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
    Edge[2].Type= Synch;

    {
    vector <string> vcstr(0);
    ConstraintsRelOp[0]=vcstr;
    ConstraintsConstants[0]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(0,vcvstr);
    ConstraintsCoeffs[0]=v2cvstr;
    }

    {
    vector <string> vcstr(0);
    ConstraintsRelOp[1]=vcstr;
    ConstraintsConstants[1]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(0,vcvstr);
    ConstraintsCoeffs[1]=v2cvstr;
    }

    {
    vector <string> vcstr(0);
    ConstraintsRelOp[2]=vcstr;
    ConstraintsConstants[2]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(0,vcvstr);
    ConstraintsCoeffs[2]=v2cvstr;
    }
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    vector<string> VarStr(NbVar);
    VarLabel=VarStr;
    VarLabel[0]="x";
    VarIndex["x"]=0;

    vector<string> vStr(NbVar);
    vector< vector <string > > vvStr(NbLoc,vStr);
    StrFlow=vvStr;
    StrFlow[0][0]="";
    StrFlow[1][0]="";
    StrFlow[2][0]="";

    vector< set < int > > vset(NbLoc);
    Out_S_Edges =vset;
    Out_A_Edges =vset;
    Out_S_Edges[0].insert(0);
    Out_S_Edges[0].insert(1);
    Out_S_Edges[0].insert(2);

    vector< set <string> > vStrSet(3);
    EdgeActions=vStrSet;
    vector< set<int> > vSetInt(30);
    vector < vector < set <int> > > vvSetInt(NbLoc,vSetInt);
    ActionEdges=vvSetInt;
    EdgeActions[0].insert("r1");
    ActionEdges[0][4].insert(0);
    EdgeActions[0].insert("r10");
    ActionEdges[0][27].insert(0);
    EdgeActions[0].insert("r11");
    ActionEdges[0][25].insert(0);
    EdgeActions[0].insert("r12");
    ActionEdges[0][26].insert(0);
    EdgeActions[0].insert("r13");
    ActionEdges[0][28].insert(0);
    EdgeActions[0].insert("r14");
    ActionEdges[0][29].insert(0);
    EdgeActions[0].insert("r15");
    ActionEdges[0][24].insert(0);
    EdgeActions[0].insert("r16");
    ActionEdges[0][23].insert(0);
    EdgeActions[0].insert("r17");
    ActionEdges[0][20].insert(0);
    EdgeActions[0].insert("r18");
    ActionEdges[0][18].insert(0);
    EdgeActions[0].insert("r19");
    ActionEdges[0][13].insert(0);
    EdgeActions[0].insert("r2");
    ActionEdges[0][6].insert(0);
    EdgeActions[0].insert("r20");
    ActionEdges[0][14].insert(0);
    EdgeActions[0].insert("r21");
    ActionEdges[0][15].insert(0);
    EdgeActions[0].insert("r22");
    ActionEdges[0][3].insert(0);
    EdgeActions[0].insert("r23");
    ActionEdges[0][11].insert(0);
    EdgeActions[0].insert("r24");
    ActionEdges[0][2].insert(0);
    EdgeActions[0].insert("r25");
    ActionEdges[0][8].insert(0);
    EdgeActions[0].insert("r26");
    ActionEdges[0][17].insert(0);
    EdgeActions[0].insert("r27");
    ActionEdges[0][16].insert(0);
    EdgeActions[0].insert("r28");
    ActionEdges[0][7].insert(0);
    EdgeActions[0].insert("r29");
    ActionEdges[0][0].insert(0);
    EdgeActions[0].insert("r3");
    ActionEdges[0][5].insert(0);
    EdgeActions[0].insert("r30");
    ActionEdges[0][1].insert(0);
    EdgeActions[0].insert("r4");
    ActionEdges[0][12].insert(0);
    EdgeActions[0].insert("r5");
    ActionEdges[0][10].insert(0);
    EdgeActions[0].insert("r6");
    ActionEdges[0][9].insert(0);
    EdgeActions[0].insert("r7");
    ActionEdges[0][21].insert(0);
    EdgeActions[0].insert("r8");
    ActionEdges[0][19].insert(0);
    EdgeActions[0].insert("r9");
    ActionEdges[0][22].insert(0);
    EdgeActions[1].insert("r1");
    ActionEdges[0][4].insert(1);
    EdgeActions[1].insert("r10");
    ActionEdges[0][27].insert(1);
    EdgeActions[1].insert("r11");
    ActionEdges[0][25].insert(1);
    EdgeActions[1].insert("r12");
    ActionEdges[0][26].insert(1);
    EdgeActions[1].insert("r13");
    ActionEdges[0][28].insert(1);
    EdgeActions[1].insert("r14");
    ActionEdges[0][29].insert(1);
    EdgeActions[1].insert("r15");
    ActionEdges[0][24].insert(1);
    EdgeActions[1].insert("r16");
    ActionEdges[0][23].insert(1);
    EdgeActions[1].insert("r17");
    ActionEdges[0][20].insert(1);
    EdgeActions[1].insert("r18");
    ActionEdges[0][18].insert(1);
    EdgeActions[1].insert("r19");
    ActionEdges[0][13].insert(1);
    EdgeActions[1].insert("r2");
    ActionEdges[0][6].insert(1);
    EdgeActions[1].insert("r20");
    ActionEdges[0][14].insert(1);
    EdgeActions[1].insert("r21");
    ActionEdges[0][15].insert(1);
    EdgeActions[1].insert("r22");
    ActionEdges[0][3].insert(1);
    EdgeActions[1].insert("r23");
    ActionEdges[0][11].insert(1);
    EdgeActions[1].insert("r24");
    ActionEdges[0][2].insert(1);
    EdgeActions[1].insert("r25");
    ActionEdges[0][8].insert(1);
    EdgeActions[1].insert("r26");
    ActionEdges[0][17].insert(1);
    EdgeActions[1].insert("r27");
    ActionEdges[0][16].insert(1);
    EdgeActions[1].insert("r28");
    ActionEdges[0][7].insert(1);
    EdgeActions[1].insert("r29");
    ActionEdges[0][0].insert(1);
    EdgeActions[1].insert("r3");
    ActionEdges[0][5].insert(1);
    EdgeActions[1].insert("r30");
    ActionEdges[0][1].insert(1);
    EdgeActions[1].insert("r4");
    ActionEdges[0][12].insert(1);
    EdgeActions[1].insert("r5");
    ActionEdges[0][10].insert(1);
    EdgeActions[1].insert("r6");
    ActionEdges[0][9].insert(1);
    EdgeActions[1].insert("r7");
    ActionEdges[0][21].insert(1);
    EdgeActions[1].insert("r8");
    ActionEdges[0][19].insert(1);
    EdgeActions[1].insert("r9");
    ActionEdges[0][22].insert(1);
    EdgeActions[2].insert("r1");
    ActionEdges[0][4].insert(2);
    EdgeActions[2].insert("r10");
    ActionEdges[0][27].insert(2);
    EdgeActions[2].insert("r11");
    ActionEdges[0][25].insert(2);
    EdgeActions[2].insert("r12");
    ActionEdges[0][26].insert(2);
    EdgeActions[2].insert("r13");
    ActionEdges[0][28].insert(2);
    EdgeActions[2].insert("r14");
    ActionEdges[0][29].insert(2);
    EdgeActions[2].insert("r15");
    ActionEdges[0][24].insert(2);
    EdgeActions[2].insert("r16");
    ActionEdges[0][23].insert(2);
    EdgeActions[2].insert("r17");
    ActionEdges[0][20].insert(2);
    EdgeActions[2].insert("r18");
    ActionEdges[0][18].insert(2);
    EdgeActions[2].insert("r19");
    ActionEdges[0][13].insert(2);
    EdgeActions[2].insert("r2");
    ActionEdges[0][6].insert(2);
    EdgeActions[2].insert("r20");
    ActionEdges[0][14].insert(2);
    EdgeActions[2].insert("r21");
    ActionEdges[0][15].insert(2);
    EdgeActions[2].insert("r22");
    ActionEdges[0][3].insert(2);
    EdgeActions[2].insert("r23");
    ActionEdges[0][11].insert(2);
    EdgeActions[2].insert("r24");
    ActionEdges[0][2].insert(2);
    EdgeActions[2].insert("r25");
    ActionEdges[0][8].insert(2);
    EdgeActions[2].insert("r26");
    ActionEdges[0][17].insert(2);
    EdgeActions[2].insert("r27");
    ActionEdges[0][16].insert(2);
    EdgeActions[2].insert("r28");
    ActionEdges[0][7].insert(2);
    EdgeActions[2].insert("r29");
    ActionEdges[0][0].insert(2);
    EdgeActions[2].insert("r3");
    ActionEdges[0][5].insert(2);
    EdgeActions[2].insert("r30");
    ActionEdges[0][1].insert(2);
    EdgeActions[2].insert("r4");
    ActionEdges[0][12].insert(2);
    EdgeActions[2].insert("r5");
    ActionEdges[0][10].insert(2);
    EdgeActions[2].insert("r6");
    ActionEdges[0][9].insert(2);
    EdgeActions[2].insert("r7");
    ActionEdges[0][21].insert(2);
    EdgeActions[2].insert("r8");
    ActionEdges[0][19].insert(2);
    EdgeActions[2].insert("r9");
    ActionEdges[0][22].insert(2);
    if(true){
    			vector<double> vL(1,0);
    			LinForm=vL;
    			OldLinForm=vL;
    			vector<double> vF(1,0);
    			LhaFunc=vF;
    			vector<double> vA(1,0);
    			FormulaVal=vA;
    }
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->x += GetFlow(0, CurrentLocation, Marking) * DeltaT;
}
double LHA::GetFlow(int v, int loc,const abstractMarking& Marking){
		return 0.0;


}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking){
switch (loc){
	case 2:	//lm
         return (  Marking.P->_PL_RE_ERKPP  < 3 ) || (  Marking.P->_PL_Puit  > 1 );

		break;
	case 1:	//lp
         return (  Marking.P->_PL_RE_ERKPP  == 3 ) && (  Marking.P->_PL_Puit  == 0 );

		break;
	default:	//l1,
         return (  Marking.P->_PL_RE_ERKPP  < 3 ) && (  Marking.P->_PL_Puit  == 0 );

}
}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking){
	return true;

}

t_interval LHA::GetEdgeEnablingTime(int ed,const abstractMarking& Marking){
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             return EnablingT;
         }

}

void LHA::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){
switch (ed){
	case 2:	//
         {
         tempVars->x=0;
		std::swap(Vars,tempVars);
         }

		break;
	case 1:	//
         {
         tempVars->x=1;
		std::swap(Vars,tempVars);
         }

		break;
}
    OldLinForm[0]=LinForm[0];
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    LinForm[0]=Vars->x;
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]=LinForm[0];

    }

void LHA::UpdateFormulaVal(){

    OldFormulaVal=FormulaVal[0];
    FormulaVal[0]=LhaFunc[0];

}

