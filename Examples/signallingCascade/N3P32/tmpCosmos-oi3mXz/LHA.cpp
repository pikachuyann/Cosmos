#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double L=3;
    const double N1=1;
    const double N2=3;
    const double N3=0;
    const double k1=1;
    const double k10=3.3;
    const double k11=0.4;
    const double k12=0.1;
    const double k13=10;
    const double k14=0.8;
    const double k15=0.1;
    const double k16=10;
    const double k17=0.8;
    const double k18=0.1;
    const double k19=20;
    const double k2=0.4;
    const double k20=0.6;
    const double k21=0.1;
    const double k22=20;
    const double k23=0.6;
    const double k24=0.1;
    const double k25=5;
    const double k26=0.4;
    const double k27=0.1;
    const double k28=5;
    const double k29=0.4;
    const double k3=0.1;
    const double k30=0.1;
    const double k4=0.5;
    const double k5=0.5;
    const double k6=0.1;
    const double k7=3.3;
    const double k8=0.42;
    const double k9=0.1;
struct Variables {
	double vc0;
};
void LHA::resetVariables(){
	Vars->vc0= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\tvc0\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->vc0 << "\t";
};
LHA::LHA(){
    NbLoc =3;
    NbVar =1;
    InitLoc.insert(0);
    FinalLoc.insert(1);
    vector<LhaEdge> ve(5);
    Edge= ve;

    LocIndex["l0"]=0;
    LocIndex["l1"]=1;
    LocIndex["l2"]=2;

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    StrLocProperty= vlstr;

    vector < vector <string> >  vestr(5);
    ConstraintsRelOp= vestr;
    ConstraintsConstants= vestr;
    vector < vector< vector <string> > > mvestr(5);
    ConstraintsCoeffs= mvestr;

    LocLabel[0]="l0";
    LocLabel[1]="l1";
    LocLabel[2]="l2";
    StrLocProperty[0]="( (  Marking.P->_PL_RE_MEKPP  == 0 &&  Marking.P->_PL_RE_ERKPP  == 0 ) && ! (  Marking.P->_PL_RE_RafP  > 3 ) )";
    StrLocProperty[1]=" Marking.P->_PL_RE_RafP  > 3";
    StrLocProperty[2]="(  Marking.P->_PL_RE_MEKPP  > 0 ||  Marking.P->_PL_RE_ERKPP  > 0 )";
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
    Edge[3].Index=3;
    Edge[3].Source=1;
    Edge[3].Target=1;
    Edge[3].Type= Synch;
    Edge[4].Index=4;
    Edge[4].Source=2;
    Edge[4].Target=2;
    Edge[4].Type= Synch;

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

    {
    vector <string> vcstr(0);
    ConstraintsRelOp[3]=vcstr;
    ConstraintsConstants[3]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(0,vcvstr);
    ConstraintsCoeffs[3]=v2cvstr;
    }

    {
    vector <string> vcstr(0);
    ConstraintsRelOp[4]=vcstr;
    ConstraintsConstants[4]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(0,vcvstr);
    ConstraintsCoeffs[4]=v2cvstr;
    }
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    vector<string> VarStr(NbVar);
    VarLabel=VarStr;
    VarLabel[0]="vc0";
    VarIndex["vc0"]=0;

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
    Out_S_Edges[1].insert(3);
    Out_S_Edges[2].insert(4);

    vector< set <string> > vStrSet(5);
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
    EdgeActions[3].insert("r1");
    ActionEdges[1][4].insert(3);
    EdgeActions[3].insert("r10");
    ActionEdges[1][27].insert(3);
    EdgeActions[3].insert("r11");
    ActionEdges[1][25].insert(3);
    EdgeActions[3].insert("r12");
    ActionEdges[1][26].insert(3);
    EdgeActions[3].insert("r13");
    ActionEdges[1][28].insert(3);
    EdgeActions[3].insert("r14");
    ActionEdges[1][29].insert(3);
    EdgeActions[3].insert("r15");
    ActionEdges[1][24].insert(3);
    EdgeActions[3].insert("r16");
    ActionEdges[1][23].insert(3);
    EdgeActions[3].insert("r17");
    ActionEdges[1][20].insert(3);
    EdgeActions[3].insert("r18");
    ActionEdges[1][18].insert(3);
    EdgeActions[3].insert("r19");
    ActionEdges[1][13].insert(3);
    EdgeActions[3].insert("r2");
    ActionEdges[1][6].insert(3);
    EdgeActions[3].insert("r20");
    ActionEdges[1][14].insert(3);
    EdgeActions[3].insert("r21");
    ActionEdges[1][15].insert(3);
    EdgeActions[3].insert("r22");
    ActionEdges[1][3].insert(3);
    EdgeActions[3].insert("r23");
    ActionEdges[1][11].insert(3);
    EdgeActions[3].insert("r24");
    ActionEdges[1][2].insert(3);
    EdgeActions[3].insert("r25");
    ActionEdges[1][8].insert(3);
    EdgeActions[3].insert("r26");
    ActionEdges[1][17].insert(3);
    EdgeActions[3].insert("r27");
    ActionEdges[1][16].insert(3);
    EdgeActions[3].insert("r28");
    ActionEdges[1][7].insert(3);
    EdgeActions[3].insert("r29");
    ActionEdges[1][0].insert(3);
    EdgeActions[3].insert("r3");
    ActionEdges[1][5].insert(3);
    EdgeActions[3].insert("r30");
    ActionEdges[1][1].insert(3);
    EdgeActions[3].insert("r4");
    ActionEdges[1][12].insert(3);
    EdgeActions[3].insert("r5");
    ActionEdges[1][10].insert(3);
    EdgeActions[3].insert("r6");
    ActionEdges[1][9].insert(3);
    EdgeActions[3].insert("r7");
    ActionEdges[1][21].insert(3);
    EdgeActions[3].insert("r8");
    ActionEdges[1][19].insert(3);
    EdgeActions[3].insert("r9");
    ActionEdges[1][22].insert(3);
    EdgeActions[4].insert("r1");
    ActionEdges[2][4].insert(4);
    EdgeActions[4].insert("r10");
    ActionEdges[2][27].insert(4);
    EdgeActions[4].insert("r11");
    ActionEdges[2][25].insert(4);
    EdgeActions[4].insert("r12");
    ActionEdges[2][26].insert(4);
    EdgeActions[4].insert("r13");
    ActionEdges[2][28].insert(4);
    EdgeActions[4].insert("r14");
    ActionEdges[2][29].insert(4);
    EdgeActions[4].insert("r15");
    ActionEdges[2][24].insert(4);
    EdgeActions[4].insert("r16");
    ActionEdges[2][23].insert(4);
    EdgeActions[4].insert("r17");
    ActionEdges[2][20].insert(4);
    EdgeActions[4].insert("r18");
    ActionEdges[2][18].insert(4);
    EdgeActions[4].insert("r19");
    ActionEdges[2][13].insert(4);
    EdgeActions[4].insert("r2");
    ActionEdges[2][6].insert(4);
    EdgeActions[4].insert("r20");
    ActionEdges[2][14].insert(4);
    EdgeActions[4].insert("r21");
    ActionEdges[2][15].insert(4);
    EdgeActions[4].insert("r22");
    ActionEdges[2][3].insert(4);
    EdgeActions[4].insert("r23");
    ActionEdges[2][11].insert(4);
    EdgeActions[4].insert("r24");
    ActionEdges[2][2].insert(4);
    EdgeActions[4].insert("r25");
    ActionEdges[2][8].insert(4);
    EdgeActions[4].insert("r26");
    ActionEdges[2][17].insert(4);
    EdgeActions[4].insert("r27");
    ActionEdges[2][16].insert(4);
    EdgeActions[4].insert("r28");
    ActionEdges[2][7].insert(4);
    EdgeActions[4].insert("r29");
    ActionEdges[2][0].insert(4);
    EdgeActions[4].insert("r3");
    ActionEdges[2][5].insert(4);
    EdgeActions[4].insert("r30");
    ActionEdges[2][1].insert(4);
    EdgeActions[4].insert("r4");
    ActionEdges[2][12].insert(4);
    EdgeActions[4].insert("r5");
    ActionEdges[2][10].insert(4);
    EdgeActions[4].insert("r6");
    ActionEdges[2][9].insert(4);
    EdgeActions[4].insert("r7");
    ActionEdges[2][21].insert(4);
    EdgeActions[4].insert("r8");
    ActionEdges[2][19].insert(4);
    EdgeActions[4].insert("r9");
    ActionEdges[2][22].insert(4);
    if(true){
    			vector<double> vL(0,0);
    			LinForm=vL;
    			OldLinForm=vL;
    			vector<double> vF(0,0);
    			LhaFunc=vF;
    			vector<double> vA(0,0);
    			FormulaVal=vA;
    }
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->vc0 += GetFlow(0, CurrentLocation, Marking) * DeltaT;
}
double LHA::GetFlow(int v, int loc,const abstractMarking& Marking)const{
		return 0.0;


}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
switch (loc){
	case 2:	//l2
         return (  Marking.P->_PL_RE_MEKPP  > 0 ||  Marking.P->_PL_RE_ERKPP  > 0 );

		break;
	case 0:	//l0
         return ( (  Marking.P->_PL_RE_MEKPP  == 0 &&  Marking.P->_PL_RE_ERKPP  == 0 ) && ! (  Marking.P->_PL_RE_RafP  > 3 ) );

		break;
	default:	//l1,
         return  Marking.P->_PL_RE_RafP  > 3;

}
}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
	return true;

}

t_interval LHA::GetEdgeEnablingTime(int ed,const abstractMarking& Marking)const{
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             return EnablingT;
         }

}

void LHA::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){

}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){

    }

void LHA::UpdateFormulaVal(){

}

