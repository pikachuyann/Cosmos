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
    NbLoc =6;
    NbVar =4;
    InitLoc.insert(0);
    FinalLoc.insert(3);
    LocIndex["l0"]=1;
    LocIndex["l1"]=2;
    LocIndex["l2"]=3;
    LocIndex["lf"]=4;
    LocIndex["lf2"]=5;
    LocIndex["li"]=0;

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    StrLocProperty= vlstr;

    vector < vector <string> >  vestr(8);
    ConstraintsRelOp= vestr;
    ConstraintsConstants= vestr;
    vector < vector< vector <string> > > mvestr(8);
    ConstraintsCoeffs= mvestr;

    vector<LhaEdge> ve(8);
    Edge= ve;

    LocLabel[0]="li";
    LocLabel[1]="l0";
    LocLabel[2]="l1";
    LocLabel[3]="l2";
    LocLabel[4]="lf";
    LocLabel[5]="lf2";
    StrLocProperty[0]="true";
    StrLocProperty[1]="true";
    StrLocProperty[2]="(  Marking[ 150 ]  +  Marking[ 164 ]  == 5 ) && (  Marking[ 150 ]  <  Marking[ 164 ]  ) && (  Marking[ 165 ]  == 0 )";
    StrLocProperty[3]="true";
    StrLocProperty[4]="(  Marking[ 150 ]  +  Marking[ 164 ]  == 5 ) && (  Marking[ 150 ]  >=  Marking[ 164 ]  ) && (  Marking[ 165 ]  == 0 )";
    StrLocProperty[5]="(  Marking[ 165 ]  > 0 )";
    Edge[0].Index=0;
    Edge[0].Source=0;
    Edge[0].Target=1;
    Edge[0].Type= Auto ;
    Edge[1].Index=1;
    Edge[1].Source=1;
    Edge[1].Target=1;
    Edge[1].Type= Synch;
    Edge[2].Index=2;
    Edge[2].Source=1;
    Edge[2].Target=2;
    Edge[2].Type= Auto ;
    Edge[3].Index=3;
    Edge[3].Source=2;
    Edge[3].Target=3;
    Edge[3].Type= Auto ;
    Edge[4].Index=4;
    Edge[4].Source=1;
    Edge[4].Target=4;
    Edge[4].Type= Auto ;
    Edge[5].Index=5;
    Edge[5].Source=1;
    Edge[5].Target=5;
    Edge[5].Type= Auto ;
    Edge[6].Index=6;
    Edge[6].Source=4;
    Edge[6].Target=3;
    Edge[6].Type= Auto ;
    Edge[7].Index=7;
    Edge[7].Source=5;
    Edge[7].Target=3;
    Edge[7].Type= Auto ;

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[0]=vcstr;
    ConstraintsConstants[0]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[0]=v2cvstr;
    }
    ConstraintsRelOp[0][0]=">=";
    ConstraintsConstants[0][0]="0";
    ConstraintsCoeffs[0][0][0]="1";
    ConstraintsCoeffs[0][0][1]="";
    ConstraintsCoeffs[0][0][2]="";
    ConstraintsCoeffs[0][0][3]="";

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[1]=vcstr;
    ConstraintsConstants[1]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[1]=v2cvstr;
    }
    ConstraintsRelOp[1][0]=">=";
    ConstraintsConstants[1][0]="0";
    ConstraintsCoeffs[1][0][0]="1";
    ConstraintsCoeffs[1][0][1]="";
    ConstraintsCoeffs[1][0][2]="";
    ConstraintsCoeffs[1][0][3]="";

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[2]=vcstr;
    ConstraintsConstants[2]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[2]=v2cvstr;
    }
    ConstraintsRelOp[2][0]=">=";
    ConstraintsConstants[2][0]="0";
    ConstraintsCoeffs[2][0][0]="1";
    ConstraintsCoeffs[2][0][1]="";
    ConstraintsCoeffs[2][0][2]="";
    ConstraintsCoeffs[2][0][3]="";

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[3]=vcstr;
    ConstraintsConstants[3]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[3]=v2cvstr;
    }
    ConstraintsRelOp[3][0]=">=";
    ConstraintsConstants[3][0]="0";
    ConstraintsCoeffs[3][0][0]="1";
    ConstraintsCoeffs[3][0][1]="";
    ConstraintsCoeffs[3][0][2]="";
    ConstraintsCoeffs[3][0][3]="";

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[4]=vcstr;
    ConstraintsConstants[4]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[4]=v2cvstr;
    }
    ConstraintsRelOp[4][0]=">=";
    ConstraintsConstants[4][0]="0";
    ConstraintsCoeffs[4][0][0]="1";
    ConstraintsCoeffs[4][0][1]="";
    ConstraintsCoeffs[4][0][2]="";
    ConstraintsCoeffs[4][0][3]="";

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[5]=vcstr;
    ConstraintsConstants[5]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[5]=v2cvstr;
    }
    ConstraintsRelOp[5][0]=">=";
    ConstraintsConstants[5][0]="0";
    ConstraintsCoeffs[5][0][0]="1";
    ConstraintsCoeffs[5][0][1]="";
    ConstraintsCoeffs[5][0][2]="";
    ConstraintsCoeffs[5][0][3]="";

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[6]=vcstr;
    ConstraintsConstants[6]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[6]=v2cvstr;
    }
    ConstraintsRelOp[6][0]=">=";
    ConstraintsConstants[6][0]="0";
    ConstraintsCoeffs[6][0][0]="1";
    ConstraintsCoeffs[6][0][1]="";
    ConstraintsCoeffs[6][0][2]="";
    ConstraintsCoeffs[6][0][3]="";

    if (true){
    vector <string> vcstr(1);
    ConstraintsRelOp[7]=vcstr;
    ConstraintsConstants[7]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[7]=v2cvstr;
    }
    ConstraintsRelOp[7][0]=">=";
    ConstraintsConstants[7][0]="0";
    ConstraintsCoeffs[7][0][0]="1";
    ConstraintsCoeffs[7][0][1]="";
    ConstraintsCoeffs[7][0][2]="";
    ConstraintsCoeffs[7][0][3]="";

    vector<double> vdouble(NbVar);
    vector<string> VarStr(NbVar);
    Var=vdouble;
    VarLabel=VarStr;
    Var[0]=0;
    VarLabel[0]="t";
    VarIndex["t"]=0;
    Var[1]=0;
    VarLabel[1]="x";
    VarIndex["x"]=1;
    Var[2]=0;
    VarLabel[2]="y";
    VarIndex["y"]=2;
    Var[3]=0;
    VarLabel[3]="r";
    VarIndex["r"]=3;

    vector<string> vStr(NbVar);
    vector< vector <string > > vvStr(NbLoc,vStr);
    StrFlow=vvStr;
    StrFlow[0][0]="";
    StrFlow[0][1]="";
    StrFlow[0][2]="";
    StrFlow[0][3]="";
    StrFlow[1][0]="";
    StrFlow[1][1]="";
    StrFlow[1][2]="";
    StrFlow[1][3]="";
    StrFlow[2][0]="";
    StrFlow[2][1]="";
    StrFlow[2][2]="";
    StrFlow[2][3]="";
    StrFlow[3][0]="";
    StrFlow[3][1]="";
    StrFlow[3][2]="";
    StrFlow[3][3]="";
    StrFlow[4][0]="";
    StrFlow[4][1]="";
    StrFlow[4][2]="";
    StrFlow[4][3]="";
    StrFlow[5][0]="";
    StrFlow[5][1]="";
    StrFlow[5][2]="";
    StrFlow[5][3]="";

    vector< set < int > > vset(NbLoc);
    Out_S_Edges =vset;
    Out_A_Edges =vset;
    Out_A_Edges[0].insert(0);
    Out_S_Edges[1].insert(1);
    Out_A_Edges[1].insert(2);
    Out_A_Edges[2].insert(3);
    Out_A_Edges[1].insert(4);
    Out_A_Edges[1].insert(5);
    Out_A_Edges[4].insert(6);
    Out_A_Edges[5].insert(7);

    vector< set <string> > vStrSet(8);
    vector< set<int> > vSetInt(141);
    vector < vector < set <int> > > vvSetInt(NbLoc,vSetInt);
    EdgeActions=vStrSet;
    ActionEdges=vvSetInt;
    EdgeActions[1].insert("Avance1_1");
    ActionEdges[1][0].insert(1);
    EdgeActions[1].insert("Avance1_10");
    ActionEdges[1][18].insert(1);
    EdgeActions[1].insert("Avance1_11");
    ActionEdges[1][20].insert(1);
    EdgeActions[1].insert("Avance1_12");
    ActionEdges[1][22].insert(1);
    EdgeActions[1].insert("Avance1_13");
    ActionEdges[1][24].insert(1);
    EdgeActions[1].insert("Avance1_14");
    ActionEdges[1][26].insert(1);
    EdgeActions[1].insert("Avance1_2");
    ActionEdges[1][2].insert(1);
    EdgeActions[1].insert("Avance1_3");
    ActionEdges[1][4].insert(1);
    EdgeActions[1].insert("Avance1_4");
    ActionEdges[1][6].insert(1);
    EdgeActions[1].insert("Avance1_5");
    ActionEdges[1][8].insert(1);
    EdgeActions[1].insert("Avance1_6");
    ActionEdges[1][10].insert(1);
    EdgeActions[1].insert("Avance1_7");
    ActionEdges[1][12].insert(1);
    EdgeActions[1].insert("Avance1_8");
    ActionEdges[1][14].insert(1);
    EdgeActions[1].insert("Avance1_9");
    ActionEdges[1][16].insert(1);
    EdgeActions[1].insert("Avance2_1");
    ActionEdges[1][28].insert(1);
    EdgeActions[1].insert("Avance2_10");
    ActionEdges[1][46].insert(1);
    EdgeActions[1].insert("Avance2_11");
    ActionEdges[1][48].insert(1);
    EdgeActions[1].insert("Avance2_12");
    ActionEdges[1][50].insert(1);
    EdgeActions[1].insert("Avance2_13");
    ActionEdges[1][52].insert(1);
    EdgeActions[1].insert("Avance2_14");
    ActionEdges[1][54].insert(1);
    EdgeActions[1].insert("Avance2_2");
    ActionEdges[1][30].insert(1);
    EdgeActions[1].insert("Avance2_3");
    ActionEdges[1][32].insert(1);
    EdgeActions[1].insert("Avance2_4");
    ActionEdges[1][34].insert(1);
    EdgeActions[1].insert("Avance2_5");
    ActionEdges[1][36].insert(1);
    EdgeActions[1].insert("Avance2_6");
    ActionEdges[1][38].insert(1);
    EdgeActions[1].insert("Avance2_7");
    ActionEdges[1][40].insert(1);
    EdgeActions[1].insert("Avance2_8");
    ActionEdges[1][42].insert(1);
    EdgeActions[1].insert("Avance2_9");
    ActionEdges[1][44].insert(1);
    EdgeActions[1].insert("Avance3_1");
    ActionEdges[1][56].insert(1);
    EdgeActions[1].insert("Avance3_10");
    ActionEdges[1][74].insert(1);
    EdgeActions[1].insert("Avance3_11");
    ActionEdges[1][76].insert(1);
    EdgeActions[1].insert("Avance3_12");
    ActionEdges[1][78].insert(1);
    EdgeActions[1].insert("Avance3_13");
    ActionEdges[1][80].insert(1);
    EdgeActions[1].insert("Avance3_14");
    ActionEdges[1][82].insert(1);
    EdgeActions[1].insert("Avance3_2");
    ActionEdges[1][58].insert(1);
    EdgeActions[1].insert("Avance3_3");
    ActionEdges[1][60].insert(1);
    EdgeActions[1].insert("Avance3_4");
    ActionEdges[1][62].insert(1);
    EdgeActions[1].insert("Avance3_5");
    ActionEdges[1][64].insert(1);
    EdgeActions[1].insert("Avance3_6");
    ActionEdges[1][66].insert(1);
    EdgeActions[1].insert("Avance3_7");
    ActionEdges[1][68].insert(1);
    EdgeActions[1].insert("Avance3_8");
    ActionEdges[1][70].insert(1);
    EdgeActions[1].insert("Avance3_9");
    ActionEdges[1][72].insert(1);
    EdgeActions[1].insert("Avance4_1");
    ActionEdges[1][84].insert(1);
    EdgeActions[1].insert("Avance4_10");
    ActionEdges[1][102].insert(1);
    EdgeActions[1].insert("Avance4_11");
    ActionEdges[1][104].insert(1);
    EdgeActions[1].insert("Avance4_12");
    ActionEdges[1][106].insert(1);
    EdgeActions[1].insert("Avance4_13");
    ActionEdges[1][108].insert(1);
    EdgeActions[1].insert("Avance4_14");
    ActionEdges[1][110].insert(1);
    EdgeActions[1].insert("Avance4_2");
    ActionEdges[1][86].insert(1);
    EdgeActions[1].insert("Avance4_3");
    ActionEdges[1][88].insert(1);
    EdgeActions[1].insert("Avance4_4");
    ActionEdges[1][90].insert(1);
    EdgeActions[1].insert("Avance4_5");
    ActionEdges[1][92].insert(1);
    EdgeActions[1].insert("Avance4_6");
    ActionEdges[1][94].insert(1);
    EdgeActions[1].insert("Avance4_7");
    ActionEdges[1][96].insert(1);
    EdgeActions[1].insert("Avance4_8");
    ActionEdges[1][98].insert(1);
    EdgeActions[1].insert("Avance4_9");
    ActionEdges[1][100].insert(1);
    EdgeActions[1].insert("Avance5_1");
    ActionEdges[1][112].insert(1);
    EdgeActions[1].insert("Avance5_10");
    ActionEdges[1][130].insert(1);
    EdgeActions[1].insert("Avance5_11");
    ActionEdges[1][132].insert(1);
    EdgeActions[1].insert("Avance5_12");
    ActionEdges[1][134].insert(1);
    EdgeActions[1].insert("Avance5_13");
    ActionEdges[1][136].insert(1);
    EdgeActions[1].insert("Avance5_14");
    ActionEdges[1][138].insert(1);
    EdgeActions[1].insert("Avance5_2");
    ActionEdges[1][114].insert(1);
    EdgeActions[1].insert("Avance5_3");
    ActionEdges[1][116].insert(1);
    EdgeActions[1].insert("Avance5_4");
    ActionEdges[1][118].insert(1);
    EdgeActions[1].insert("Avance5_5");
    ActionEdges[1][120].insert(1);
    EdgeActions[1].insert("Avance5_6");
    ActionEdges[1][122].insert(1);
    EdgeActions[1].insert("Avance5_7");
    ActionEdges[1][124].insert(1);
    EdgeActions[1].insert("Avance5_8");
    ActionEdges[1][126].insert(1);
    EdgeActions[1].insert("Avance5_9");
    ActionEdges[1][128].insert(1);
    EdgeActions[1].insert("Puittrans");
    ActionEdges[1][140].insert(1);
    EdgeActions[1].insert("Recule1_1");
    ActionEdges[1][1].insert(1);
    EdgeActions[1].insert("Recule1_10");
    ActionEdges[1][19].insert(1);
    EdgeActions[1].insert("Recule1_11");
    ActionEdges[1][21].insert(1);
    EdgeActions[1].insert("Recule1_12");
    ActionEdges[1][23].insert(1);
    EdgeActions[1].insert("Recule1_13");
    ActionEdges[1][25].insert(1);
    EdgeActions[1].insert("Recule1_14");
    ActionEdges[1][27].insert(1);
    EdgeActions[1].insert("Recule1_2");
    ActionEdges[1][3].insert(1);
    EdgeActions[1].insert("Recule1_3");
    ActionEdges[1][5].insert(1);
    EdgeActions[1].insert("Recule1_4");
    ActionEdges[1][7].insert(1);
    EdgeActions[1].insert("Recule1_5");
    ActionEdges[1][9].insert(1);
    EdgeActions[1].insert("Recule1_6");
    ActionEdges[1][11].insert(1);
    EdgeActions[1].insert("Recule1_7");
    ActionEdges[1][13].insert(1);
    EdgeActions[1].insert("Recule1_8");
    ActionEdges[1][15].insert(1);
    EdgeActions[1].insert("Recule1_9");
    ActionEdges[1][17].insert(1);
    EdgeActions[1].insert("Recule2_1");
    ActionEdges[1][29].insert(1);
    EdgeActions[1].insert("Recule2_10");
    ActionEdges[1][47].insert(1);
    EdgeActions[1].insert("Recule2_11");
    ActionEdges[1][49].insert(1);
    EdgeActions[1].insert("Recule2_12");
    ActionEdges[1][51].insert(1);
    EdgeActions[1].insert("Recule2_13");
    ActionEdges[1][53].insert(1);
    EdgeActions[1].insert("Recule2_14");
    ActionEdges[1][55].insert(1);
    EdgeActions[1].insert("Recule2_2");
    ActionEdges[1][31].insert(1);
    EdgeActions[1].insert("Recule2_3");
    ActionEdges[1][33].insert(1);
    EdgeActions[1].insert("Recule2_4");
    ActionEdges[1][35].insert(1);
    EdgeActions[1].insert("Recule2_5");
    ActionEdges[1][37].insert(1);
    EdgeActions[1].insert("Recule2_6");
    ActionEdges[1][39].insert(1);
    EdgeActions[1].insert("Recule2_7");
    ActionEdges[1][41].insert(1);
    EdgeActions[1].insert("Recule2_8");
    ActionEdges[1][43].insert(1);
    EdgeActions[1].insert("Recule2_9");
    ActionEdges[1][45].insert(1);
    EdgeActions[1].insert("Recule3_1");
    ActionEdges[1][57].insert(1);
    EdgeActions[1].insert("Recule3_10");
    ActionEdges[1][75].insert(1);
    EdgeActions[1].insert("Recule3_11");
    ActionEdges[1][77].insert(1);
    EdgeActions[1].insert("Recule3_12");
    ActionEdges[1][79].insert(1);
    EdgeActions[1].insert("Recule3_13");
    ActionEdges[1][81].insert(1);
    EdgeActions[1].insert("Recule3_14");
    ActionEdges[1][83].insert(1);
    EdgeActions[1].insert("Recule3_2");
    ActionEdges[1][59].insert(1);
    EdgeActions[1].insert("Recule3_3");
    ActionEdges[1][61].insert(1);
    EdgeActions[1].insert("Recule3_4");
    ActionEdges[1][63].insert(1);
    EdgeActions[1].insert("Recule3_5");
    ActionEdges[1][65].insert(1);
    EdgeActions[1].insert("Recule3_6");
    ActionEdges[1][67].insert(1);
    EdgeActions[1].insert("Recule3_7");
    ActionEdges[1][69].insert(1);
    EdgeActions[1].insert("Recule3_8");
    ActionEdges[1][71].insert(1);
    EdgeActions[1].insert("Recule3_9");
    ActionEdges[1][73].insert(1);
    EdgeActions[1].insert("Recule4_1");
    ActionEdges[1][85].insert(1);
    EdgeActions[1].insert("Recule4_10");
    ActionEdges[1][103].insert(1);
    EdgeActions[1].insert("Recule4_11");
    ActionEdges[1][105].insert(1);
    EdgeActions[1].insert("Recule4_12");
    ActionEdges[1][107].insert(1);
    EdgeActions[1].insert("Recule4_13");
    ActionEdges[1][109].insert(1);
    EdgeActions[1].insert("Recule4_14");
    ActionEdges[1][111].insert(1);
    EdgeActions[1].insert("Recule4_2");
    ActionEdges[1][87].insert(1);
    EdgeActions[1].insert("Recule4_3");
    ActionEdges[1][89].insert(1);
    EdgeActions[1].insert("Recule4_4");
    ActionEdges[1][91].insert(1);
    EdgeActions[1].insert("Recule4_5");
    ActionEdges[1][93].insert(1);
    EdgeActions[1].insert("Recule4_6");
    ActionEdges[1][95].insert(1);
    EdgeActions[1].insert("Recule4_7");
    ActionEdges[1][97].insert(1);
    EdgeActions[1].insert("Recule4_8");
    ActionEdges[1][99].insert(1);
    EdgeActions[1].insert("Recule4_9");
    ActionEdges[1][101].insert(1);
    EdgeActions[1].insert("Recule5_1");
    ActionEdges[1][113].insert(1);
    EdgeActions[1].insert("Recule5_10");
    ActionEdges[1][131].insert(1);
    EdgeActions[1].insert("Recule5_11");
    ActionEdges[1][133].insert(1);
    EdgeActions[1].insert("Recule5_12");
    ActionEdges[1][135].insert(1);
    EdgeActions[1].insert("Recule5_13");
    ActionEdges[1][137].insert(1);
    EdgeActions[1].insert("Recule5_14");
    ActionEdges[1][139].insert(1);
    EdgeActions[1].insert("Recule5_2");
    ActionEdges[1][115].insert(1);
    EdgeActions[1].insert("Recule5_3");
    ActionEdges[1][117].insert(1);
    EdgeActions[1].insert("Recule5_4");
    ActionEdges[1][119].insert(1);
    EdgeActions[1].insert("Recule5_5");
    ActionEdges[1][121].insert(1);
    EdgeActions[1].insert("Recule5_6");
    ActionEdges[1][123].insert(1);
    EdgeActions[1].insert("Recule5_7");
    ActionEdges[1][125].insert(1);
    EdgeActions[1].insert("Recule5_8");
    ActionEdges[1][127].insert(1);
    EdgeActions[1].insert("Recule5_9");
    ActionEdges[1][129].insert(1);
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
         case 3:
             return 1;
             break;
         case 4:
             return 1;
             break;
         case 5:
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
         case 3:
             return 0;
             break;
         case 4:
             return 0;
             break;
         case 5:
             return 0;
             break;
       }
       break;
    case 2:
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
         case 3:
             return 0;
             break;
         case 4:
             return 0;
             break;
         case 5:
             return 0;
             break;
       }
       break;
    case 3:
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
         case 3:
             return 0;
             break;
         case 4:
             return 0;
             break;
         case 5:
             return 0;
             break;
       }
       break;
	}

}

bool LHA::CheckLocation(int loc, vector<int>& Marking){
    switch(loc){
     case 0:
         return true;
         break;
     case 1:
         return true;
         break;
     case 2:
         return (  Marking[ 150 ]  +  Marking[ 164 ]  == 5 ) && (  Marking[ 150 ]  <  Marking[ 164 ]  ) && (  Marking[ 165 ]  == 0 );
         break;
     case 3:
         return true;
         break;
     case 4:
         return (  Marking[ 150 ]  +  Marking[ 164 ]  == 5 ) && (  Marking[ 150 ]  >=  Marking[ 164 ]  ) && (  Marking[ 165 ]  == 0 );
         break;
     case 5:
         return (  Marking[ 165 ]  > 0 );
         break;
    }
}

bool LHA::CheckEdgeContraints(int ed, double DeltaT, vector<int>& Marking){
    switch(ed){
    case 0: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,0, Marking))>=0)) return false;
         return true; 
         break;
     }
    case 1: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,1, Marking))>=0)) return false;
         return true; 
         break;
     }
    case 2: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,1, Marking))>=0)) return false;
         return true; 
         break;
     }
    case 3: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,2, Marking))>=0)) return false;
         return true; 
         break;
     }
    case 4: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,1, Marking))>=0)) return false;
         return true; 
         break;
     }
    case 5: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,1, Marking))>=0)) return false;
         return true; 
         break;
     }
    case 6: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,4, Marking))>=0)) return false;
         return true; 
         break;
     }
    case 7: {
         if(!( +(1)*(Var[0]+DeltaT*GetFlow(0,5, Marking))>=0)) return false;
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
     case 3:
         return GetEdgeEnablingTime_3( Marking);
         break;
     case 4:
         return GetEdgeEnablingTime_4( Marking);
         break;
     case 5:
         return GetEdgeEnablingTime_5( Marking);
         break;
     case 6:
         return GetEdgeEnablingTime_6( Marking);
         break;
     case 7:
         return GetEdgeEnablingTime_7( Marking);
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
         if(!(SumAX>=0))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(0-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.second>t) EnablingT.second=t;
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


    SumAF=+(1)*GetFlow(0,1, Marking);
    SumAX=+(1)*Var[0];

    if(SumAF==0){
         if(!(SumAX>=0))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(0-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.second>t) EnablingT.second=t;
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


    SumAF=+(1)*GetFlow(0,1, Marking);
    SumAX=+(1)*Var[0];

    if(SumAF==0){
         if(!(SumAX>=0))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(0-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.second>t) EnablingT.second=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
    }
    return EnablingT;
}

t_interval LHA::GetEdgeEnablingTime_3(vector<int>& Marking){
    t_interval EnablingT;

    EnablingT.first=CurrentTime;
    EnablingT.second=DBL_MAX;

    t_interval EmptyInterval;

    EmptyInterval.first=0;
    EmptyInterval.second=-1;

    double SumAF;
    double SumAX;


    SumAF=+(1)*GetFlow(0,2, Marking);
    SumAX=+(1)*Var[0];

    if(SumAF==0){
         if(!(SumAX>=0))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(0-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.second>t) EnablingT.second=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
    }
    return EnablingT;
}

t_interval LHA::GetEdgeEnablingTime_4(vector<int>& Marking){
    t_interval EnablingT;

    EnablingT.first=CurrentTime;
    EnablingT.second=DBL_MAX;

    t_interval EmptyInterval;

    EmptyInterval.first=0;
    EmptyInterval.second=-1;

    double SumAF;
    double SumAX;


    SumAF=+(1)*GetFlow(0,1, Marking);
    SumAX=+(1)*Var[0];

    if(SumAF==0){
         if(!(SumAX>=0))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(0-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.second>t) EnablingT.second=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
    }
    return EnablingT;
}

t_interval LHA::GetEdgeEnablingTime_5(vector<int>& Marking){
    t_interval EnablingT;

    EnablingT.first=CurrentTime;
    EnablingT.second=DBL_MAX;

    t_interval EmptyInterval;

    EmptyInterval.first=0;
    EmptyInterval.second=-1;

    double SumAF;
    double SumAX;


    SumAF=+(1)*GetFlow(0,1, Marking);
    SumAX=+(1)*Var[0];

    if(SumAF==0){
         if(!(SumAX>=0))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(0-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.second>t) EnablingT.second=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
    }
    return EnablingT;
}

t_interval LHA::GetEdgeEnablingTime_6(vector<int>& Marking){
    t_interval EnablingT;

    EnablingT.first=CurrentTime;
    EnablingT.second=DBL_MAX;

    t_interval EmptyInterval;

    EmptyInterval.first=0;
    EmptyInterval.second=-1;

    double SumAF;
    double SumAX;


    SumAF=+(1)*GetFlow(0,4, Marking);
    SumAX=+(1)*Var[0];

    if(SumAF==0){
         if(!(SumAX>=0))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(0-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.second>t) EnablingT.second=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
    }
    return EnablingT;
}

t_interval LHA::GetEdgeEnablingTime_7(vector<int>& Marking){
    t_interval EnablingT;

    EnablingT.first=CurrentTime;
    EnablingT.second=DBL_MAX;

    t_interval EmptyInterval;

    EmptyInterval.first=0;
    EmptyInterval.second=-1;

    double SumAF;
    double SumAX;


    SumAF=+(1)*GetFlow(0,5, Marking);
    SumAX=+(1)*Var[0];

    if(SumAF==0){
         if(!(SumAX>=0))
             return EmptyInterval;
    }
    else{
         double t=CurrentTime+(0-SumAX)/(double)SumAF;
         if(SumAF>0){
            if(EnablingT.first<t) EnablingT.first=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
         else{
            if(EnablingT.second>t) EnablingT.second=t;
            if(EnablingT.second<EnablingT.first) return EmptyInterval;
             }
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
     case 3:
         DoEdgeUpdates_3( Marking);
         break;
     case 4:
         DoEdgeUpdates_4( Marking);
         break;
     case 5:
         DoEdgeUpdates_5( Marking);
         break;
     case 6:
         DoEdgeUpdates_6( Marking);
         break;
     case 7:
         DoEdgeUpdates_7( Marking);
         break;
    }
}

void LHA::DoEdgeUpdates_0(vector<int>& Marking){
    vector<double> TempVar(NbVar);
    TempVar[1]=1;
    TempVar[2]=1;
    Var[1]=TempVar[1];
    Var[2]=TempVar[2];

    OldLinForm[0]=LinForm[0];
    }

void LHA::DoEdgeUpdates_1(vector<int>& Marking){
    vector<double> TempVar(NbVar);
    TempVar[1]=Var [1] * Likelihood;
    Var[1]=TempVar[1];

    OldLinForm[0]=LinForm[0];
    }

void LHA::DoEdgeUpdates_2(vector<int>& Marking){

    OldLinForm[0]=LinForm[0];
    }

void LHA::DoEdgeUpdates_3(vector<int>& Marking){
    vector<double> TempVar(NbVar);
    TempVar[3]=0;
    Var[3]=TempVar[3];

    OldLinForm[0]=LinForm[0];
    }

void LHA::DoEdgeUpdates_4(vector<int>& Marking){
    vector<double> TempVar(NbVar);
    TempVar[1]=0;
    TempVar[2]=0;
    TempVar[3]=Var[1];
    Var[1]=TempVar[1];
    Var[2]=TempVar[2];
    Var[3]=TempVar[3];

    OldLinForm[0]=LinForm[0];
    }

void LHA::DoEdgeUpdates_5(vector<int>& Marking){
    vector<double> TempVar(NbVar);
    TempVar[1]=0;
    TempVar[2]=0;
    TempVar[3]=Var[1];
    Var[1]=TempVar[1];
    Var[2]=TempVar[2];
    Var[3]=TempVar[3];

    OldLinForm[0]=LinForm[0];
    }

void LHA::DoEdgeUpdates_6(vector<int>& Marking){

    OldLinForm[0]=LinForm[0];
    }

void LHA::DoEdgeUpdates_7(vector<int>& Marking){

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

