#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
    const double T=10;
    const double Ttrans=0;
    const double invT=0.1;
struct Variables {
	double time;
	double backToThink_p1;
	double backToThink_p2;
	double backToThink_p3;
	double backToThink_p4;
	double backToThink_p5;
	double takeLeft_p1;
	double takeLeft_p2;
	double takeLeft_p3;
	double takeLeft_p4;
	double takeLeft_p5;
	double takeRight_p1;
	double takeRight_p2;
	double takeRight_p3;
	double takeRight_p4;
	double takeRight_p5;
	double PLVAR_Think_p1;
	double PLVAR_Think_p2;
	double PLVAR_Think_p3;
	double PLVAR_Think_p4;
	double PLVAR_Think_p5;
	double PLVAR_Wait_p1;
	double PLVAR_Wait_p2;
	double PLVAR_Wait_p3;
	double PLVAR_Wait_p4;
	double PLVAR_Wait_p5;
	double PLVAR_Eat_p1;
	double PLVAR_Eat_p2;
	double PLVAR_Eat_p3;
	double PLVAR_Eat_p4;
	double PLVAR_Eat_p5;
	double PLVAR_Fork_p1;
	double PLVAR_Fork_p2;
	double PLVAR_Fork_p3;
	double PLVAR_Fork_p4;
	double PLVAR_Fork_p5;
};
void LHA::resetVariables(){
	Vars->time= 0;
	Vars->backToThink_p1= 0;
	Vars->backToThink_p2= 0;
	Vars->backToThink_p3= 0;
	Vars->backToThink_p4= 0;
	Vars->backToThink_p5= 0;
	Vars->takeLeft_p1= 0;
	Vars->takeLeft_p2= 0;
	Vars->takeLeft_p3= 0;
	Vars->takeLeft_p4= 0;
	Vars->takeLeft_p5= 0;
	Vars->takeRight_p1= 0;
	Vars->takeRight_p2= 0;
	Vars->takeRight_p3= 0;
	Vars->takeRight_p4= 0;
	Vars->takeRight_p5= 0;
	Vars->PLVAR_Think_p1= 0;
	Vars->PLVAR_Think_p2= 0;
	Vars->PLVAR_Think_p3= 0;
	Vars->PLVAR_Think_p4= 0;
	Vars->PLVAR_Think_p5= 0;
	Vars->PLVAR_Wait_p1= 0;
	Vars->PLVAR_Wait_p2= 0;
	Vars->PLVAR_Wait_p3= 0;
	Vars->PLVAR_Wait_p4= 0;
	Vars->PLVAR_Wait_p5= 0;
	Vars->PLVAR_Eat_p1= 0;
	Vars->PLVAR_Eat_p2= 0;
	Vars->PLVAR_Eat_p3= 0;
	Vars->PLVAR_Eat_p4= 0;
	Vars->PLVAR_Eat_p5= 0;
	Vars->PLVAR_Fork_p1= 0;
	Vars->PLVAR_Fork_p2= 0;
	Vars->PLVAR_Fork_p3= 0;
	Vars->PLVAR_Fork_p4= 0;
	Vars->PLVAR_Fork_p5= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\ttime\tbackToThink_p1\tbackToThink_p2\tbackToThink_p3\tbackToThink_p4\tbackToThink_p5\ttakeLeft_p1\ttakeLeft_p2\ttakeLeft_p3\ttakeLeft_p4\ttakeLeft_p5\ttakeRight_p1\ttakeRight_p2\ttakeRight_p3\ttakeRight_p4\ttakeRight_p5\tPLVAR_Think_p1\tPLVAR_Think_p2\tPLVAR_Think_p3\tPLVAR_Think_p4\tPLVAR_Think_p5\tPLVAR_Wait_p1\tPLVAR_Wait_p2\tPLVAR_Wait_p3\tPLVAR_Wait_p4\tPLVAR_Wait_p5\tPLVAR_Eat_p1\tPLVAR_Eat_p2\tPLVAR_Eat_p3\tPLVAR_Eat_p4\tPLVAR_Eat_p5\tPLVAR_Fork_p1\tPLVAR_Fork_p2\tPLVAR_Fork_p3\tPLVAR_Fork_p4\tPLVAR_Fork_p5\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
	s << Vars->time << "\t";
	s << Vars->backToThink_p1 << "\t";
	s << Vars->backToThink_p2 << "\t";
	s << Vars->backToThink_p3 << "\t";
	s << Vars->backToThink_p4 << "\t";
	s << Vars->backToThink_p5 << "\t";
	s << Vars->takeLeft_p1 << "\t";
	s << Vars->takeLeft_p2 << "\t";
	s << Vars->takeLeft_p3 << "\t";
	s << Vars->takeLeft_p4 << "\t";
	s << Vars->takeLeft_p5 << "\t";
	s << Vars->takeRight_p1 << "\t";
	s << Vars->takeRight_p2 << "\t";
	s << Vars->takeRight_p3 << "\t";
	s << Vars->takeRight_p4 << "\t";
	s << Vars->takeRight_p5 << "\t";
	s << Vars->PLVAR_Think_p1 << "\t";
	s << Vars->PLVAR_Think_p2 << "\t";
	s << Vars->PLVAR_Think_p3 << "\t";
	s << Vars->PLVAR_Think_p4 << "\t";
	s << Vars->PLVAR_Think_p5 << "\t";
	s << Vars->PLVAR_Wait_p1 << "\t";
	s << Vars->PLVAR_Wait_p2 << "\t";
	s << Vars->PLVAR_Wait_p3 << "\t";
	s << Vars->PLVAR_Wait_p4 << "\t";
	s << Vars->PLVAR_Wait_p5 << "\t";
	s << Vars->PLVAR_Eat_p1 << "\t";
	s << Vars->PLVAR_Eat_p2 << "\t";
	s << Vars->PLVAR_Eat_p3 << "\t";
	s << Vars->PLVAR_Eat_p4 << "\t";
	s << Vars->PLVAR_Eat_p5 << "\t";
	s << Vars->PLVAR_Fork_p1 << "\t";
	s << Vars->PLVAR_Fork_p2 << "\t";
	s << Vars->PLVAR_Fork_p3 << "\t";
	s << Vars->PLVAR_Fork_p4 << "\t";
	s << Vars->PLVAR_Fork_p5 << "\t";
};
LHA::LHA(){
    NbLoc =3;
    NbVar =36;
    InitLoc.insert(0);
    FinalLoc.insert(2);
    vector<LhaEdge> ve(18);
    Edge= ve;

    LocIndex["l0"]=0;
    LocIndex["l1"]=1;
    LocIndex["l2"]=2;

    vector<string> vlstr(NbLoc);
    LocLabel= vlstr;
    StrLocProperty= vlstr;

    vector < vector <string> >  vestr(18);
    ConstraintsRelOp= vestr;
    ConstraintsConstants= vestr;
    vector < vector< vector <string> > > mvestr(18);
    ConstraintsCoeffs= mvestr;

    LocLabel[0]="l0";
    LocLabel[1]="l1";
    LocLabel[2]="l2";
    StrLocProperty[0]="true";
    StrLocProperty[1]="true";
    StrLocProperty[2]="true";
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
    Edge[10].Target=1;
    Edge[10].Type= Synch;
    Edge[11].Index=11;
    Edge[11].Source=1;
    Edge[11].Target=1;
    Edge[11].Type= Synch;
    Edge[12].Index=12;
    Edge[12].Source=1;
    Edge[12].Target=1;
    Edge[12].Type= Synch;
    Edge[13].Index=13;
    Edge[13].Source=1;
    Edge[13].Target=1;
    Edge[13].Type= Synch;
    Edge[14].Index=14;
    Edge[14].Source=1;
    Edge[14].Target=1;
    Edge[14].Type= Synch;
    Edge[15].Index=15;
    Edge[15].Source=1;
    Edge[15].Target=1;
    Edge[15].Type= Synch;
    Edge[16].Index=16;
    Edge[16].Source=1;
    Edge[16].Target=1;
    Edge[16].Type= Synch;
    Edge[17].Index=17;
    Edge[17].Source=1;
    Edge[17].Target=2;
    Edge[17].Type= Auto ;

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[0]=vcstr;
    ConstraintsConstants[0]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[0]=v2cvstr;
    }
    ConstraintsRelOp[0][0]="<=";
    ConstraintsConstants[0][0]="0";
    ConstraintsCoeffs[0][0][0]="1";
    ConstraintsCoeffs[0][0][1]="";
    ConstraintsCoeffs[0][0][2]="";
    ConstraintsCoeffs[0][0][3]="";
    ConstraintsCoeffs[0][0][4]="";
    ConstraintsCoeffs[0][0][5]="";
    ConstraintsCoeffs[0][0][6]="";
    ConstraintsCoeffs[0][0][7]="";
    ConstraintsCoeffs[0][0][8]="";
    ConstraintsCoeffs[0][0][9]="";
    ConstraintsCoeffs[0][0][10]="";
    ConstraintsCoeffs[0][0][11]="";
    ConstraintsCoeffs[0][0][12]="";
    ConstraintsCoeffs[0][0][13]="";
    ConstraintsCoeffs[0][0][14]="";
    ConstraintsCoeffs[0][0][15]="";
    ConstraintsCoeffs[0][0][16]="";
    ConstraintsCoeffs[0][0][17]="";
    ConstraintsCoeffs[0][0][18]="";
    ConstraintsCoeffs[0][0][19]="";
    ConstraintsCoeffs[0][0][20]="";
    ConstraintsCoeffs[0][0][21]="";
    ConstraintsCoeffs[0][0][22]="";
    ConstraintsCoeffs[0][0][23]="";
    ConstraintsCoeffs[0][0][24]="";
    ConstraintsCoeffs[0][0][25]="";
    ConstraintsCoeffs[0][0][26]="";
    ConstraintsCoeffs[0][0][27]="";
    ConstraintsCoeffs[0][0][28]="";
    ConstraintsCoeffs[0][0][29]="";
    ConstraintsCoeffs[0][0][30]="";
    ConstraintsCoeffs[0][0][31]="";
    ConstraintsCoeffs[0][0][32]="";
    ConstraintsCoeffs[0][0][33]="";
    ConstraintsCoeffs[0][0][34]="";
    ConstraintsCoeffs[0][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[1]=vcstr;
    ConstraintsConstants[1]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[1]=v2cvstr;
    }
    ConstraintsRelOp[1][0]="==";
    ConstraintsConstants[1][0]="0";
    ConstraintsCoeffs[1][0][0]="1";
    ConstraintsCoeffs[1][0][1]="";
    ConstraintsCoeffs[1][0][2]="";
    ConstraintsCoeffs[1][0][3]="";
    ConstraintsCoeffs[1][0][4]="";
    ConstraintsCoeffs[1][0][5]="";
    ConstraintsCoeffs[1][0][6]="";
    ConstraintsCoeffs[1][0][7]="";
    ConstraintsCoeffs[1][0][8]="";
    ConstraintsCoeffs[1][0][9]="";
    ConstraintsCoeffs[1][0][10]="";
    ConstraintsCoeffs[1][0][11]="";
    ConstraintsCoeffs[1][0][12]="";
    ConstraintsCoeffs[1][0][13]="";
    ConstraintsCoeffs[1][0][14]="";
    ConstraintsCoeffs[1][0][15]="";
    ConstraintsCoeffs[1][0][16]="";
    ConstraintsCoeffs[1][0][17]="";
    ConstraintsCoeffs[1][0][18]="";
    ConstraintsCoeffs[1][0][19]="";
    ConstraintsCoeffs[1][0][20]="";
    ConstraintsCoeffs[1][0][21]="";
    ConstraintsCoeffs[1][0][22]="";
    ConstraintsCoeffs[1][0][23]="";
    ConstraintsCoeffs[1][0][24]="";
    ConstraintsCoeffs[1][0][25]="";
    ConstraintsCoeffs[1][0][26]="";
    ConstraintsCoeffs[1][0][27]="";
    ConstraintsCoeffs[1][0][28]="";
    ConstraintsCoeffs[1][0][29]="";
    ConstraintsCoeffs[1][0][30]="";
    ConstraintsCoeffs[1][0][31]="";
    ConstraintsCoeffs[1][0][32]="";
    ConstraintsCoeffs[1][0][33]="";
    ConstraintsCoeffs[1][0][34]="";
    ConstraintsCoeffs[1][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[2]=vcstr;
    ConstraintsConstants[2]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[2]=v2cvstr;
    }
    ConstraintsRelOp[2][0]="<=";
    ConstraintsConstants[2][0]="10";
    ConstraintsCoeffs[2][0][0]="1";
    ConstraintsCoeffs[2][0][1]="";
    ConstraintsCoeffs[2][0][2]="";
    ConstraintsCoeffs[2][0][3]="";
    ConstraintsCoeffs[2][0][4]="";
    ConstraintsCoeffs[2][0][5]="";
    ConstraintsCoeffs[2][0][6]="";
    ConstraintsCoeffs[2][0][7]="";
    ConstraintsCoeffs[2][0][8]="";
    ConstraintsCoeffs[2][0][9]="";
    ConstraintsCoeffs[2][0][10]="";
    ConstraintsCoeffs[2][0][11]="";
    ConstraintsCoeffs[2][0][12]="";
    ConstraintsCoeffs[2][0][13]="";
    ConstraintsCoeffs[2][0][14]="";
    ConstraintsCoeffs[2][0][15]="";
    ConstraintsCoeffs[2][0][16]="";
    ConstraintsCoeffs[2][0][17]="";
    ConstraintsCoeffs[2][0][18]="";
    ConstraintsCoeffs[2][0][19]="";
    ConstraintsCoeffs[2][0][20]="";
    ConstraintsCoeffs[2][0][21]="";
    ConstraintsCoeffs[2][0][22]="";
    ConstraintsCoeffs[2][0][23]="";
    ConstraintsCoeffs[2][0][24]="";
    ConstraintsCoeffs[2][0][25]="";
    ConstraintsCoeffs[2][0][26]="";
    ConstraintsCoeffs[2][0][27]="";
    ConstraintsCoeffs[2][0][28]="";
    ConstraintsCoeffs[2][0][29]="";
    ConstraintsCoeffs[2][0][30]="";
    ConstraintsCoeffs[2][0][31]="";
    ConstraintsCoeffs[2][0][32]="";
    ConstraintsCoeffs[2][0][33]="";
    ConstraintsCoeffs[2][0][34]="";
    ConstraintsCoeffs[2][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[3]=vcstr;
    ConstraintsConstants[3]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[3]=v2cvstr;
    }
    ConstraintsRelOp[3][0]="<=";
    ConstraintsConstants[3][0]="10";
    ConstraintsCoeffs[3][0][0]="1";
    ConstraintsCoeffs[3][0][1]="";
    ConstraintsCoeffs[3][0][2]="";
    ConstraintsCoeffs[3][0][3]="";
    ConstraintsCoeffs[3][0][4]="";
    ConstraintsCoeffs[3][0][5]="";
    ConstraintsCoeffs[3][0][6]="";
    ConstraintsCoeffs[3][0][7]="";
    ConstraintsCoeffs[3][0][8]="";
    ConstraintsCoeffs[3][0][9]="";
    ConstraintsCoeffs[3][0][10]="";
    ConstraintsCoeffs[3][0][11]="";
    ConstraintsCoeffs[3][0][12]="";
    ConstraintsCoeffs[3][0][13]="";
    ConstraintsCoeffs[3][0][14]="";
    ConstraintsCoeffs[3][0][15]="";
    ConstraintsCoeffs[3][0][16]="";
    ConstraintsCoeffs[3][0][17]="";
    ConstraintsCoeffs[3][0][18]="";
    ConstraintsCoeffs[3][0][19]="";
    ConstraintsCoeffs[3][0][20]="";
    ConstraintsCoeffs[3][0][21]="";
    ConstraintsCoeffs[3][0][22]="";
    ConstraintsCoeffs[3][0][23]="";
    ConstraintsCoeffs[3][0][24]="";
    ConstraintsCoeffs[3][0][25]="";
    ConstraintsCoeffs[3][0][26]="";
    ConstraintsCoeffs[3][0][27]="";
    ConstraintsCoeffs[3][0][28]="";
    ConstraintsCoeffs[3][0][29]="";
    ConstraintsCoeffs[3][0][30]="";
    ConstraintsCoeffs[3][0][31]="";
    ConstraintsCoeffs[3][0][32]="";
    ConstraintsCoeffs[3][0][33]="";
    ConstraintsCoeffs[3][0][34]="";
    ConstraintsCoeffs[3][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[4]=vcstr;
    ConstraintsConstants[4]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[4]=v2cvstr;
    }
    ConstraintsRelOp[4][0]="<=";
    ConstraintsConstants[4][0]="10";
    ConstraintsCoeffs[4][0][0]="1";
    ConstraintsCoeffs[4][0][1]="";
    ConstraintsCoeffs[4][0][2]="";
    ConstraintsCoeffs[4][0][3]="";
    ConstraintsCoeffs[4][0][4]="";
    ConstraintsCoeffs[4][0][5]="";
    ConstraintsCoeffs[4][0][6]="";
    ConstraintsCoeffs[4][0][7]="";
    ConstraintsCoeffs[4][0][8]="";
    ConstraintsCoeffs[4][0][9]="";
    ConstraintsCoeffs[4][0][10]="";
    ConstraintsCoeffs[4][0][11]="";
    ConstraintsCoeffs[4][0][12]="";
    ConstraintsCoeffs[4][0][13]="";
    ConstraintsCoeffs[4][0][14]="";
    ConstraintsCoeffs[4][0][15]="";
    ConstraintsCoeffs[4][0][16]="";
    ConstraintsCoeffs[4][0][17]="";
    ConstraintsCoeffs[4][0][18]="";
    ConstraintsCoeffs[4][0][19]="";
    ConstraintsCoeffs[4][0][20]="";
    ConstraintsCoeffs[4][0][21]="";
    ConstraintsCoeffs[4][0][22]="";
    ConstraintsCoeffs[4][0][23]="";
    ConstraintsCoeffs[4][0][24]="";
    ConstraintsCoeffs[4][0][25]="";
    ConstraintsCoeffs[4][0][26]="";
    ConstraintsCoeffs[4][0][27]="";
    ConstraintsCoeffs[4][0][28]="";
    ConstraintsCoeffs[4][0][29]="";
    ConstraintsCoeffs[4][0][30]="";
    ConstraintsCoeffs[4][0][31]="";
    ConstraintsCoeffs[4][0][32]="";
    ConstraintsCoeffs[4][0][33]="";
    ConstraintsCoeffs[4][0][34]="";
    ConstraintsCoeffs[4][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[5]=vcstr;
    ConstraintsConstants[5]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[5]=v2cvstr;
    }
    ConstraintsRelOp[5][0]="<=";
    ConstraintsConstants[5][0]="10";
    ConstraintsCoeffs[5][0][0]="1";
    ConstraintsCoeffs[5][0][1]="";
    ConstraintsCoeffs[5][0][2]="";
    ConstraintsCoeffs[5][0][3]="";
    ConstraintsCoeffs[5][0][4]="";
    ConstraintsCoeffs[5][0][5]="";
    ConstraintsCoeffs[5][0][6]="";
    ConstraintsCoeffs[5][0][7]="";
    ConstraintsCoeffs[5][0][8]="";
    ConstraintsCoeffs[5][0][9]="";
    ConstraintsCoeffs[5][0][10]="";
    ConstraintsCoeffs[5][0][11]="";
    ConstraintsCoeffs[5][0][12]="";
    ConstraintsCoeffs[5][0][13]="";
    ConstraintsCoeffs[5][0][14]="";
    ConstraintsCoeffs[5][0][15]="";
    ConstraintsCoeffs[5][0][16]="";
    ConstraintsCoeffs[5][0][17]="";
    ConstraintsCoeffs[5][0][18]="";
    ConstraintsCoeffs[5][0][19]="";
    ConstraintsCoeffs[5][0][20]="";
    ConstraintsCoeffs[5][0][21]="";
    ConstraintsCoeffs[5][0][22]="";
    ConstraintsCoeffs[5][0][23]="";
    ConstraintsCoeffs[5][0][24]="";
    ConstraintsCoeffs[5][0][25]="";
    ConstraintsCoeffs[5][0][26]="";
    ConstraintsCoeffs[5][0][27]="";
    ConstraintsCoeffs[5][0][28]="";
    ConstraintsCoeffs[5][0][29]="";
    ConstraintsCoeffs[5][0][30]="";
    ConstraintsCoeffs[5][0][31]="";
    ConstraintsCoeffs[5][0][32]="";
    ConstraintsCoeffs[5][0][33]="";
    ConstraintsCoeffs[5][0][34]="";
    ConstraintsCoeffs[5][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[6]=vcstr;
    ConstraintsConstants[6]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[6]=v2cvstr;
    }
    ConstraintsRelOp[6][0]="<=";
    ConstraintsConstants[6][0]="10";
    ConstraintsCoeffs[6][0][0]="1";
    ConstraintsCoeffs[6][0][1]="";
    ConstraintsCoeffs[6][0][2]="";
    ConstraintsCoeffs[6][0][3]="";
    ConstraintsCoeffs[6][0][4]="";
    ConstraintsCoeffs[6][0][5]="";
    ConstraintsCoeffs[6][0][6]="";
    ConstraintsCoeffs[6][0][7]="";
    ConstraintsCoeffs[6][0][8]="";
    ConstraintsCoeffs[6][0][9]="";
    ConstraintsCoeffs[6][0][10]="";
    ConstraintsCoeffs[6][0][11]="";
    ConstraintsCoeffs[6][0][12]="";
    ConstraintsCoeffs[6][0][13]="";
    ConstraintsCoeffs[6][0][14]="";
    ConstraintsCoeffs[6][0][15]="";
    ConstraintsCoeffs[6][0][16]="";
    ConstraintsCoeffs[6][0][17]="";
    ConstraintsCoeffs[6][0][18]="";
    ConstraintsCoeffs[6][0][19]="";
    ConstraintsCoeffs[6][0][20]="";
    ConstraintsCoeffs[6][0][21]="";
    ConstraintsCoeffs[6][0][22]="";
    ConstraintsCoeffs[6][0][23]="";
    ConstraintsCoeffs[6][0][24]="";
    ConstraintsCoeffs[6][0][25]="";
    ConstraintsCoeffs[6][0][26]="";
    ConstraintsCoeffs[6][0][27]="";
    ConstraintsCoeffs[6][0][28]="";
    ConstraintsCoeffs[6][0][29]="";
    ConstraintsCoeffs[6][0][30]="";
    ConstraintsCoeffs[6][0][31]="";
    ConstraintsCoeffs[6][0][32]="";
    ConstraintsCoeffs[6][0][33]="";
    ConstraintsCoeffs[6][0][34]="";
    ConstraintsCoeffs[6][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[7]=vcstr;
    ConstraintsConstants[7]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[7]=v2cvstr;
    }
    ConstraintsRelOp[7][0]="<=";
    ConstraintsConstants[7][0]="10";
    ConstraintsCoeffs[7][0][0]="1";
    ConstraintsCoeffs[7][0][1]="";
    ConstraintsCoeffs[7][0][2]="";
    ConstraintsCoeffs[7][0][3]="";
    ConstraintsCoeffs[7][0][4]="";
    ConstraintsCoeffs[7][0][5]="";
    ConstraintsCoeffs[7][0][6]="";
    ConstraintsCoeffs[7][0][7]="";
    ConstraintsCoeffs[7][0][8]="";
    ConstraintsCoeffs[7][0][9]="";
    ConstraintsCoeffs[7][0][10]="";
    ConstraintsCoeffs[7][0][11]="";
    ConstraintsCoeffs[7][0][12]="";
    ConstraintsCoeffs[7][0][13]="";
    ConstraintsCoeffs[7][0][14]="";
    ConstraintsCoeffs[7][0][15]="";
    ConstraintsCoeffs[7][0][16]="";
    ConstraintsCoeffs[7][0][17]="";
    ConstraintsCoeffs[7][0][18]="";
    ConstraintsCoeffs[7][0][19]="";
    ConstraintsCoeffs[7][0][20]="";
    ConstraintsCoeffs[7][0][21]="";
    ConstraintsCoeffs[7][0][22]="";
    ConstraintsCoeffs[7][0][23]="";
    ConstraintsCoeffs[7][0][24]="";
    ConstraintsCoeffs[7][0][25]="";
    ConstraintsCoeffs[7][0][26]="";
    ConstraintsCoeffs[7][0][27]="";
    ConstraintsCoeffs[7][0][28]="";
    ConstraintsCoeffs[7][0][29]="";
    ConstraintsCoeffs[7][0][30]="";
    ConstraintsCoeffs[7][0][31]="";
    ConstraintsCoeffs[7][0][32]="";
    ConstraintsCoeffs[7][0][33]="";
    ConstraintsCoeffs[7][0][34]="";
    ConstraintsCoeffs[7][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[8]=vcstr;
    ConstraintsConstants[8]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[8]=v2cvstr;
    }
    ConstraintsRelOp[8][0]="<=";
    ConstraintsConstants[8][0]="10";
    ConstraintsCoeffs[8][0][0]="1";
    ConstraintsCoeffs[8][0][1]="";
    ConstraintsCoeffs[8][0][2]="";
    ConstraintsCoeffs[8][0][3]="";
    ConstraintsCoeffs[8][0][4]="";
    ConstraintsCoeffs[8][0][5]="";
    ConstraintsCoeffs[8][0][6]="";
    ConstraintsCoeffs[8][0][7]="";
    ConstraintsCoeffs[8][0][8]="";
    ConstraintsCoeffs[8][0][9]="";
    ConstraintsCoeffs[8][0][10]="";
    ConstraintsCoeffs[8][0][11]="";
    ConstraintsCoeffs[8][0][12]="";
    ConstraintsCoeffs[8][0][13]="";
    ConstraintsCoeffs[8][0][14]="";
    ConstraintsCoeffs[8][0][15]="";
    ConstraintsCoeffs[8][0][16]="";
    ConstraintsCoeffs[8][0][17]="";
    ConstraintsCoeffs[8][0][18]="";
    ConstraintsCoeffs[8][0][19]="";
    ConstraintsCoeffs[8][0][20]="";
    ConstraintsCoeffs[8][0][21]="";
    ConstraintsCoeffs[8][0][22]="";
    ConstraintsCoeffs[8][0][23]="";
    ConstraintsCoeffs[8][0][24]="";
    ConstraintsCoeffs[8][0][25]="";
    ConstraintsCoeffs[8][0][26]="";
    ConstraintsCoeffs[8][0][27]="";
    ConstraintsCoeffs[8][0][28]="";
    ConstraintsCoeffs[8][0][29]="";
    ConstraintsCoeffs[8][0][30]="";
    ConstraintsCoeffs[8][0][31]="";
    ConstraintsCoeffs[8][0][32]="";
    ConstraintsCoeffs[8][0][33]="";
    ConstraintsCoeffs[8][0][34]="";
    ConstraintsCoeffs[8][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[9]=vcstr;
    ConstraintsConstants[9]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[9]=v2cvstr;
    }
    ConstraintsRelOp[9][0]="<=";
    ConstraintsConstants[9][0]="10";
    ConstraintsCoeffs[9][0][0]="1";
    ConstraintsCoeffs[9][0][1]="";
    ConstraintsCoeffs[9][0][2]="";
    ConstraintsCoeffs[9][0][3]="";
    ConstraintsCoeffs[9][0][4]="";
    ConstraintsCoeffs[9][0][5]="";
    ConstraintsCoeffs[9][0][6]="";
    ConstraintsCoeffs[9][0][7]="";
    ConstraintsCoeffs[9][0][8]="";
    ConstraintsCoeffs[9][0][9]="";
    ConstraintsCoeffs[9][0][10]="";
    ConstraintsCoeffs[9][0][11]="";
    ConstraintsCoeffs[9][0][12]="";
    ConstraintsCoeffs[9][0][13]="";
    ConstraintsCoeffs[9][0][14]="";
    ConstraintsCoeffs[9][0][15]="";
    ConstraintsCoeffs[9][0][16]="";
    ConstraintsCoeffs[9][0][17]="";
    ConstraintsCoeffs[9][0][18]="";
    ConstraintsCoeffs[9][0][19]="";
    ConstraintsCoeffs[9][0][20]="";
    ConstraintsCoeffs[9][0][21]="";
    ConstraintsCoeffs[9][0][22]="";
    ConstraintsCoeffs[9][0][23]="";
    ConstraintsCoeffs[9][0][24]="";
    ConstraintsCoeffs[9][0][25]="";
    ConstraintsCoeffs[9][0][26]="";
    ConstraintsCoeffs[9][0][27]="";
    ConstraintsCoeffs[9][0][28]="";
    ConstraintsCoeffs[9][0][29]="";
    ConstraintsCoeffs[9][0][30]="";
    ConstraintsCoeffs[9][0][31]="";
    ConstraintsCoeffs[9][0][32]="";
    ConstraintsCoeffs[9][0][33]="";
    ConstraintsCoeffs[9][0][34]="";
    ConstraintsCoeffs[9][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[10]=vcstr;
    ConstraintsConstants[10]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[10]=v2cvstr;
    }
    ConstraintsRelOp[10][0]="<=";
    ConstraintsConstants[10][0]="10";
    ConstraintsCoeffs[10][0][0]="1";
    ConstraintsCoeffs[10][0][1]="";
    ConstraintsCoeffs[10][0][2]="";
    ConstraintsCoeffs[10][0][3]="";
    ConstraintsCoeffs[10][0][4]="";
    ConstraintsCoeffs[10][0][5]="";
    ConstraintsCoeffs[10][0][6]="";
    ConstraintsCoeffs[10][0][7]="";
    ConstraintsCoeffs[10][0][8]="";
    ConstraintsCoeffs[10][0][9]="";
    ConstraintsCoeffs[10][0][10]="";
    ConstraintsCoeffs[10][0][11]="";
    ConstraintsCoeffs[10][0][12]="";
    ConstraintsCoeffs[10][0][13]="";
    ConstraintsCoeffs[10][0][14]="";
    ConstraintsCoeffs[10][0][15]="";
    ConstraintsCoeffs[10][0][16]="";
    ConstraintsCoeffs[10][0][17]="";
    ConstraintsCoeffs[10][0][18]="";
    ConstraintsCoeffs[10][0][19]="";
    ConstraintsCoeffs[10][0][20]="";
    ConstraintsCoeffs[10][0][21]="";
    ConstraintsCoeffs[10][0][22]="";
    ConstraintsCoeffs[10][0][23]="";
    ConstraintsCoeffs[10][0][24]="";
    ConstraintsCoeffs[10][0][25]="";
    ConstraintsCoeffs[10][0][26]="";
    ConstraintsCoeffs[10][0][27]="";
    ConstraintsCoeffs[10][0][28]="";
    ConstraintsCoeffs[10][0][29]="";
    ConstraintsCoeffs[10][0][30]="";
    ConstraintsCoeffs[10][0][31]="";
    ConstraintsCoeffs[10][0][32]="";
    ConstraintsCoeffs[10][0][33]="";
    ConstraintsCoeffs[10][0][34]="";
    ConstraintsCoeffs[10][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[11]=vcstr;
    ConstraintsConstants[11]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[11]=v2cvstr;
    }
    ConstraintsRelOp[11][0]="<=";
    ConstraintsConstants[11][0]="10";
    ConstraintsCoeffs[11][0][0]="1";
    ConstraintsCoeffs[11][0][1]="";
    ConstraintsCoeffs[11][0][2]="";
    ConstraintsCoeffs[11][0][3]="";
    ConstraintsCoeffs[11][0][4]="";
    ConstraintsCoeffs[11][0][5]="";
    ConstraintsCoeffs[11][0][6]="";
    ConstraintsCoeffs[11][0][7]="";
    ConstraintsCoeffs[11][0][8]="";
    ConstraintsCoeffs[11][0][9]="";
    ConstraintsCoeffs[11][0][10]="";
    ConstraintsCoeffs[11][0][11]="";
    ConstraintsCoeffs[11][0][12]="";
    ConstraintsCoeffs[11][0][13]="";
    ConstraintsCoeffs[11][0][14]="";
    ConstraintsCoeffs[11][0][15]="";
    ConstraintsCoeffs[11][0][16]="";
    ConstraintsCoeffs[11][0][17]="";
    ConstraintsCoeffs[11][0][18]="";
    ConstraintsCoeffs[11][0][19]="";
    ConstraintsCoeffs[11][0][20]="";
    ConstraintsCoeffs[11][0][21]="";
    ConstraintsCoeffs[11][0][22]="";
    ConstraintsCoeffs[11][0][23]="";
    ConstraintsCoeffs[11][0][24]="";
    ConstraintsCoeffs[11][0][25]="";
    ConstraintsCoeffs[11][0][26]="";
    ConstraintsCoeffs[11][0][27]="";
    ConstraintsCoeffs[11][0][28]="";
    ConstraintsCoeffs[11][0][29]="";
    ConstraintsCoeffs[11][0][30]="";
    ConstraintsCoeffs[11][0][31]="";
    ConstraintsCoeffs[11][0][32]="";
    ConstraintsCoeffs[11][0][33]="";
    ConstraintsCoeffs[11][0][34]="";
    ConstraintsCoeffs[11][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[12]=vcstr;
    ConstraintsConstants[12]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[12]=v2cvstr;
    }
    ConstraintsRelOp[12][0]="<=";
    ConstraintsConstants[12][0]="10";
    ConstraintsCoeffs[12][0][0]="1";
    ConstraintsCoeffs[12][0][1]="";
    ConstraintsCoeffs[12][0][2]="";
    ConstraintsCoeffs[12][0][3]="";
    ConstraintsCoeffs[12][0][4]="";
    ConstraintsCoeffs[12][0][5]="";
    ConstraintsCoeffs[12][0][6]="";
    ConstraintsCoeffs[12][0][7]="";
    ConstraintsCoeffs[12][0][8]="";
    ConstraintsCoeffs[12][0][9]="";
    ConstraintsCoeffs[12][0][10]="";
    ConstraintsCoeffs[12][0][11]="";
    ConstraintsCoeffs[12][0][12]="";
    ConstraintsCoeffs[12][0][13]="";
    ConstraintsCoeffs[12][0][14]="";
    ConstraintsCoeffs[12][0][15]="";
    ConstraintsCoeffs[12][0][16]="";
    ConstraintsCoeffs[12][0][17]="";
    ConstraintsCoeffs[12][0][18]="";
    ConstraintsCoeffs[12][0][19]="";
    ConstraintsCoeffs[12][0][20]="";
    ConstraintsCoeffs[12][0][21]="";
    ConstraintsCoeffs[12][0][22]="";
    ConstraintsCoeffs[12][0][23]="";
    ConstraintsCoeffs[12][0][24]="";
    ConstraintsCoeffs[12][0][25]="";
    ConstraintsCoeffs[12][0][26]="";
    ConstraintsCoeffs[12][0][27]="";
    ConstraintsCoeffs[12][0][28]="";
    ConstraintsCoeffs[12][0][29]="";
    ConstraintsCoeffs[12][0][30]="";
    ConstraintsCoeffs[12][0][31]="";
    ConstraintsCoeffs[12][0][32]="";
    ConstraintsCoeffs[12][0][33]="";
    ConstraintsCoeffs[12][0][34]="";
    ConstraintsCoeffs[12][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[13]=vcstr;
    ConstraintsConstants[13]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[13]=v2cvstr;
    }
    ConstraintsRelOp[13][0]="<=";
    ConstraintsConstants[13][0]="10";
    ConstraintsCoeffs[13][0][0]="1";
    ConstraintsCoeffs[13][0][1]="";
    ConstraintsCoeffs[13][0][2]="";
    ConstraintsCoeffs[13][0][3]="";
    ConstraintsCoeffs[13][0][4]="";
    ConstraintsCoeffs[13][0][5]="";
    ConstraintsCoeffs[13][0][6]="";
    ConstraintsCoeffs[13][0][7]="";
    ConstraintsCoeffs[13][0][8]="";
    ConstraintsCoeffs[13][0][9]="";
    ConstraintsCoeffs[13][0][10]="";
    ConstraintsCoeffs[13][0][11]="";
    ConstraintsCoeffs[13][0][12]="";
    ConstraintsCoeffs[13][0][13]="";
    ConstraintsCoeffs[13][0][14]="";
    ConstraintsCoeffs[13][0][15]="";
    ConstraintsCoeffs[13][0][16]="";
    ConstraintsCoeffs[13][0][17]="";
    ConstraintsCoeffs[13][0][18]="";
    ConstraintsCoeffs[13][0][19]="";
    ConstraintsCoeffs[13][0][20]="";
    ConstraintsCoeffs[13][0][21]="";
    ConstraintsCoeffs[13][0][22]="";
    ConstraintsCoeffs[13][0][23]="";
    ConstraintsCoeffs[13][0][24]="";
    ConstraintsCoeffs[13][0][25]="";
    ConstraintsCoeffs[13][0][26]="";
    ConstraintsCoeffs[13][0][27]="";
    ConstraintsCoeffs[13][0][28]="";
    ConstraintsCoeffs[13][0][29]="";
    ConstraintsCoeffs[13][0][30]="";
    ConstraintsCoeffs[13][0][31]="";
    ConstraintsCoeffs[13][0][32]="";
    ConstraintsCoeffs[13][0][33]="";
    ConstraintsCoeffs[13][0][34]="";
    ConstraintsCoeffs[13][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[14]=vcstr;
    ConstraintsConstants[14]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[14]=v2cvstr;
    }
    ConstraintsRelOp[14][0]="<=";
    ConstraintsConstants[14][0]="10";
    ConstraintsCoeffs[14][0][0]="1";
    ConstraintsCoeffs[14][0][1]="";
    ConstraintsCoeffs[14][0][2]="";
    ConstraintsCoeffs[14][0][3]="";
    ConstraintsCoeffs[14][0][4]="";
    ConstraintsCoeffs[14][0][5]="";
    ConstraintsCoeffs[14][0][6]="";
    ConstraintsCoeffs[14][0][7]="";
    ConstraintsCoeffs[14][0][8]="";
    ConstraintsCoeffs[14][0][9]="";
    ConstraintsCoeffs[14][0][10]="";
    ConstraintsCoeffs[14][0][11]="";
    ConstraintsCoeffs[14][0][12]="";
    ConstraintsCoeffs[14][0][13]="";
    ConstraintsCoeffs[14][0][14]="";
    ConstraintsCoeffs[14][0][15]="";
    ConstraintsCoeffs[14][0][16]="";
    ConstraintsCoeffs[14][0][17]="";
    ConstraintsCoeffs[14][0][18]="";
    ConstraintsCoeffs[14][0][19]="";
    ConstraintsCoeffs[14][0][20]="";
    ConstraintsCoeffs[14][0][21]="";
    ConstraintsCoeffs[14][0][22]="";
    ConstraintsCoeffs[14][0][23]="";
    ConstraintsCoeffs[14][0][24]="";
    ConstraintsCoeffs[14][0][25]="";
    ConstraintsCoeffs[14][0][26]="";
    ConstraintsCoeffs[14][0][27]="";
    ConstraintsCoeffs[14][0][28]="";
    ConstraintsCoeffs[14][0][29]="";
    ConstraintsCoeffs[14][0][30]="";
    ConstraintsCoeffs[14][0][31]="";
    ConstraintsCoeffs[14][0][32]="";
    ConstraintsCoeffs[14][0][33]="";
    ConstraintsCoeffs[14][0][34]="";
    ConstraintsCoeffs[14][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[15]=vcstr;
    ConstraintsConstants[15]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[15]=v2cvstr;
    }
    ConstraintsRelOp[15][0]="<=";
    ConstraintsConstants[15][0]="10";
    ConstraintsCoeffs[15][0][0]="1";
    ConstraintsCoeffs[15][0][1]="";
    ConstraintsCoeffs[15][0][2]="";
    ConstraintsCoeffs[15][0][3]="";
    ConstraintsCoeffs[15][0][4]="";
    ConstraintsCoeffs[15][0][5]="";
    ConstraintsCoeffs[15][0][6]="";
    ConstraintsCoeffs[15][0][7]="";
    ConstraintsCoeffs[15][0][8]="";
    ConstraintsCoeffs[15][0][9]="";
    ConstraintsCoeffs[15][0][10]="";
    ConstraintsCoeffs[15][0][11]="";
    ConstraintsCoeffs[15][0][12]="";
    ConstraintsCoeffs[15][0][13]="";
    ConstraintsCoeffs[15][0][14]="";
    ConstraintsCoeffs[15][0][15]="";
    ConstraintsCoeffs[15][0][16]="";
    ConstraintsCoeffs[15][0][17]="";
    ConstraintsCoeffs[15][0][18]="";
    ConstraintsCoeffs[15][0][19]="";
    ConstraintsCoeffs[15][0][20]="";
    ConstraintsCoeffs[15][0][21]="";
    ConstraintsCoeffs[15][0][22]="";
    ConstraintsCoeffs[15][0][23]="";
    ConstraintsCoeffs[15][0][24]="";
    ConstraintsCoeffs[15][0][25]="";
    ConstraintsCoeffs[15][0][26]="";
    ConstraintsCoeffs[15][0][27]="";
    ConstraintsCoeffs[15][0][28]="";
    ConstraintsCoeffs[15][0][29]="";
    ConstraintsCoeffs[15][0][30]="";
    ConstraintsCoeffs[15][0][31]="";
    ConstraintsCoeffs[15][0][32]="";
    ConstraintsCoeffs[15][0][33]="";
    ConstraintsCoeffs[15][0][34]="";
    ConstraintsCoeffs[15][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[16]=vcstr;
    ConstraintsConstants[16]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[16]=v2cvstr;
    }
    ConstraintsRelOp[16][0]="<=";
    ConstraintsConstants[16][0]="10";
    ConstraintsCoeffs[16][0][0]="1";
    ConstraintsCoeffs[16][0][1]="";
    ConstraintsCoeffs[16][0][2]="";
    ConstraintsCoeffs[16][0][3]="";
    ConstraintsCoeffs[16][0][4]="";
    ConstraintsCoeffs[16][0][5]="";
    ConstraintsCoeffs[16][0][6]="";
    ConstraintsCoeffs[16][0][7]="";
    ConstraintsCoeffs[16][0][8]="";
    ConstraintsCoeffs[16][0][9]="";
    ConstraintsCoeffs[16][0][10]="";
    ConstraintsCoeffs[16][0][11]="";
    ConstraintsCoeffs[16][0][12]="";
    ConstraintsCoeffs[16][0][13]="";
    ConstraintsCoeffs[16][0][14]="";
    ConstraintsCoeffs[16][0][15]="";
    ConstraintsCoeffs[16][0][16]="";
    ConstraintsCoeffs[16][0][17]="";
    ConstraintsCoeffs[16][0][18]="";
    ConstraintsCoeffs[16][0][19]="";
    ConstraintsCoeffs[16][0][20]="";
    ConstraintsCoeffs[16][0][21]="";
    ConstraintsCoeffs[16][0][22]="";
    ConstraintsCoeffs[16][0][23]="";
    ConstraintsCoeffs[16][0][24]="";
    ConstraintsCoeffs[16][0][25]="";
    ConstraintsCoeffs[16][0][26]="";
    ConstraintsCoeffs[16][0][27]="";
    ConstraintsCoeffs[16][0][28]="";
    ConstraintsCoeffs[16][0][29]="";
    ConstraintsCoeffs[16][0][30]="";
    ConstraintsCoeffs[16][0][31]="";
    ConstraintsCoeffs[16][0][32]="";
    ConstraintsCoeffs[16][0][33]="";
    ConstraintsCoeffs[16][0][34]="";
    ConstraintsCoeffs[16][0][35]="";

    {
    vector <string> vcstr(1);
    ConstraintsRelOp[17]=vcstr;
    ConstraintsConstants[17]=vcstr;
    vector <string>  vcvstr(NbVar, "");
    vector < vector <string> > v2cvstr(1,vcvstr);
    ConstraintsCoeffs[17]=v2cvstr;
    }
    ConstraintsRelOp[17][0]="==";
    ConstraintsConstants[17][0]="10";
    ConstraintsCoeffs[17][0][0]="1";
    ConstraintsCoeffs[17][0][1]="";
    ConstraintsCoeffs[17][0][2]="";
    ConstraintsCoeffs[17][0][3]="";
    ConstraintsCoeffs[17][0][4]="";
    ConstraintsCoeffs[17][0][5]="";
    ConstraintsCoeffs[17][0][6]="";
    ConstraintsCoeffs[17][0][7]="";
    ConstraintsCoeffs[17][0][8]="";
    ConstraintsCoeffs[17][0][9]="";
    ConstraintsCoeffs[17][0][10]="";
    ConstraintsCoeffs[17][0][11]="";
    ConstraintsCoeffs[17][0][12]="";
    ConstraintsCoeffs[17][0][13]="";
    ConstraintsCoeffs[17][0][14]="";
    ConstraintsCoeffs[17][0][15]="";
    ConstraintsCoeffs[17][0][16]="";
    ConstraintsCoeffs[17][0][17]="";
    ConstraintsCoeffs[17][0][18]="";
    ConstraintsCoeffs[17][0][19]="";
    ConstraintsCoeffs[17][0][20]="";
    ConstraintsCoeffs[17][0][21]="";
    ConstraintsCoeffs[17][0][22]="";
    ConstraintsCoeffs[17][0][23]="";
    ConstraintsCoeffs[17][0][24]="";
    ConstraintsCoeffs[17][0][25]="";
    ConstraintsCoeffs[17][0][26]="";
    ConstraintsCoeffs[17][0][27]="";
    ConstraintsCoeffs[17][0][28]="";
    ConstraintsCoeffs[17][0][29]="";
    ConstraintsCoeffs[17][0][30]="";
    ConstraintsCoeffs[17][0][31]="";
    ConstraintsCoeffs[17][0][32]="";
    ConstraintsCoeffs[17][0][33]="";
    ConstraintsCoeffs[17][0][34]="";
    ConstraintsCoeffs[17][0][35]="";
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    vector<string> VarStr(NbVar);
    VarLabel=VarStr;
    VarLabel[0]="time";
    VarIndex["time"]=0;
    VarLabel[1]="backToThink_p1";
    VarIndex["backToThink_p1"]=1;
    VarLabel[2]="backToThink_p2";
    VarIndex["backToThink_p2"]=2;
    VarLabel[3]="backToThink_p3";
    VarIndex["backToThink_p3"]=3;
    VarLabel[4]="backToThink_p4";
    VarIndex["backToThink_p4"]=4;
    VarLabel[5]="backToThink_p5";
    VarIndex["backToThink_p5"]=5;
    VarLabel[6]="takeLeft_p1";
    VarIndex["takeLeft_p1"]=6;
    VarLabel[7]="takeLeft_p2";
    VarIndex["takeLeft_p2"]=7;
    VarLabel[8]="takeLeft_p3";
    VarIndex["takeLeft_p3"]=8;
    VarLabel[9]="takeLeft_p4";
    VarIndex["takeLeft_p4"]=9;
    VarLabel[10]="takeLeft_p5";
    VarIndex["takeLeft_p5"]=10;
    VarLabel[11]="takeRight_p1";
    VarIndex["takeRight_p1"]=11;
    VarLabel[12]="takeRight_p2";
    VarIndex["takeRight_p2"]=12;
    VarLabel[13]="takeRight_p3";
    VarIndex["takeRight_p3"]=13;
    VarLabel[14]="takeRight_p4";
    VarIndex["takeRight_p4"]=14;
    VarLabel[15]="takeRight_p5";
    VarIndex["takeRight_p5"]=15;
    VarLabel[16]="PLVAR_Think_p1";
    VarIndex["PLVAR_Think_p1"]=16;
    VarLabel[17]="PLVAR_Think_p2";
    VarIndex["PLVAR_Think_p2"]=17;
    VarLabel[18]="PLVAR_Think_p3";
    VarIndex["PLVAR_Think_p3"]=18;
    VarLabel[19]="PLVAR_Think_p4";
    VarIndex["PLVAR_Think_p4"]=19;
    VarLabel[20]="PLVAR_Think_p5";
    VarIndex["PLVAR_Think_p5"]=20;
    VarLabel[21]="PLVAR_Wait_p1";
    VarIndex["PLVAR_Wait_p1"]=21;
    VarLabel[22]="PLVAR_Wait_p2";
    VarIndex["PLVAR_Wait_p2"]=22;
    VarLabel[23]="PLVAR_Wait_p3";
    VarIndex["PLVAR_Wait_p3"]=23;
    VarLabel[24]="PLVAR_Wait_p4";
    VarIndex["PLVAR_Wait_p4"]=24;
    VarLabel[25]="PLVAR_Wait_p5";
    VarIndex["PLVAR_Wait_p5"]=25;
    VarLabel[26]="PLVAR_Eat_p1";
    VarIndex["PLVAR_Eat_p1"]=26;
    VarLabel[27]="PLVAR_Eat_p2";
    VarIndex["PLVAR_Eat_p2"]=27;
    VarLabel[28]="PLVAR_Eat_p3";
    VarIndex["PLVAR_Eat_p3"]=28;
    VarLabel[29]="PLVAR_Eat_p4";
    VarIndex["PLVAR_Eat_p4"]=29;
    VarLabel[30]="PLVAR_Eat_p5";
    VarIndex["PLVAR_Eat_p5"]=30;
    VarLabel[31]="PLVAR_Fork_p1";
    VarIndex["PLVAR_Fork_p1"]=31;
    VarLabel[32]="PLVAR_Fork_p2";
    VarIndex["PLVAR_Fork_p2"]=32;
    VarLabel[33]="PLVAR_Fork_p3";
    VarIndex["PLVAR_Fork_p3"]=33;
    VarLabel[34]="PLVAR_Fork_p4";
    VarIndex["PLVAR_Fork_p4"]=34;
    VarLabel[35]="PLVAR_Fork_p5";
    VarIndex["PLVAR_Fork_p5"]=35;

    vector<string> vStr(NbVar);
    vector< vector <string > > vvStr(NbLoc,vStr);
    StrFlow=vvStr;
    StrFlow[0][0]="";
    StrFlow[0][1]="";
    StrFlow[0][2]="";
    StrFlow[0][3]="";
    StrFlow[0][4]="";
    StrFlow[0][5]="";
    StrFlow[0][6]="";
    StrFlow[0][7]="";
    StrFlow[0][8]="";
    StrFlow[0][9]="";
    StrFlow[0][10]="";
    StrFlow[0][11]="";
    StrFlow[0][12]="";
    StrFlow[0][13]="";
    StrFlow[0][14]="";
    StrFlow[0][15]="";
    StrFlow[0][16]="";
    StrFlow[0][17]="";
    StrFlow[0][18]="";
    StrFlow[0][19]="";
    StrFlow[0][20]="";
    StrFlow[0][21]="";
    StrFlow[0][22]="";
    StrFlow[0][23]="";
    StrFlow[0][24]="";
    StrFlow[0][25]="";
    StrFlow[0][26]="";
    StrFlow[0][27]="";
    StrFlow[0][28]="";
    StrFlow[0][29]="";
    StrFlow[0][30]="";
    StrFlow[0][31]="";
    StrFlow[0][32]="";
    StrFlow[0][33]="";
    StrFlow[0][34]="";
    StrFlow[0][35]="";
    StrFlow[1][0]="";
    StrFlow[1][1]="";
    StrFlow[1][2]="";
    StrFlow[1][3]="";
    StrFlow[1][4]="";
    StrFlow[1][5]="";
    StrFlow[1][6]="";
    StrFlow[1][7]="";
    StrFlow[1][8]="";
    StrFlow[1][9]="";
    StrFlow[1][10]="";
    StrFlow[1][11]="";
    StrFlow[1][12]="";
    StrFlow[1][13]="";
    StrFlow[1][14]="";
    StrFlow[1][15]="";
    StrFlow[1][16]="";
    StrFlow[1][17]="";
    StrFlow[1][18]="";
    StrFlow[1][19]="";
    StrFlow[1][20]="";
    StrFlow[1][21]="";
    StrFlow[1][22]="";
    StrFlow[1][23]="";
    StrFlow[1][24]="";
    StrFlow[1][25]="";
    StrFlow[1][26]="";
    StrFlow[1][27]="";
    StrFlow[1][28]="";
    StrFlow[1][29]="";
    StrFlow[1][30]="";
    StrFlow[1][31]="";
    StrFlow[1][32]="";
    StrFlow[1][33]="";
    StrFlow[1][34]="";
    StrFlow[1][35]="";
    StrFlow[2][0]="";
    StrFlow[2][1]="";
    StrFlow[2][2]="";
    StrFlow[2][3]="";
    StrFlow[2][4]="";
    StrFlow[2][5]="";
    StrFlow[2][6]="";
    StrFlow[2][7]="";
    StrFlow[2][8]="";
    StrFlow[2][9]="";
    StrFlow[2][10]="";
    StrFlow[2][11]="";
    StrFlow[2][12]="";
    StrFlow[2][13]="";
    StrFlow[2][14]="";
    StrFlow[2][15]="";
    StrFlow[2][16]="";
    StrFlow[2][17]="";
    StrFlow[2][18]="";
    StrFlow[2][19]="";
    StrFlow[2][20]="";
    StrFlow[2][21]="";
    StrFlow[2][22]="";
    StrFlow[2][23]="";
    StrFlow[2][24]="";
    StrFlow[2][25]="";
    StrFlow[2][26]="";
    StrFlow[2][27]="";
    StrFlow[2][28]="";
    StrFlow[2][29]="";
    StrFlow[2][30]="";
    StrFlow[2][31]="";
    StrFlow[2][32]="";
    StrFlow[2][33]="";
    StrFlow[2][34]="";
    StrFlow[2][35]="";

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
    Out_S_Edges[1].insert(10);
    Out_S_Edges[1].insert(11);
    Out_S_Edges[1].insert(12);
    Out_S_Edges[1].insert(13);
    Out_S_Edges[1].insert(14);
    Out_S_Edges[1].insert(15);
    Out_S_Edges[1].insert(16);
    Out_A_Edges[1].insert(17);

    vector< set <string> > vStrSet(18);
    EdgeActions=vStrSet;
    vector< set<int> > vSetInt(15);
    vector < vector < set <int> > > vvSetInt(NbLoc,vSetInt);
    ActionEdges=vvSetInt;
    EdgeActions[0].insert("backToThink_p1");
    ActionEdges[0][10].insert(0);
    EdgeActions[0].insert("backToThink_p2");
    ActionEdges[0][11].insert(0);
    EdgeActions[0].insert("backToThink_p3");
    ActionEdges[0][12].insert(0);
    EdgeActions[0].insert("backToThink_p4");
    ActionEdges[0][13].insert(0);
    EdgeActions[0].insert("backToThink_p5");
    ActionEdges[0][14].insert(0);
    EdgeActions[0].insert("takeLeft_p1");
    ActionEdges[0][0].insert(0);
    EdgeActions[0].insert("takeLeft_p2");
    ActionEdges[0][1].insert(0);
    EdgeActions[0].insert("takeLeft_p3");
    ActionEdges[0][2].insert(0);
    EdgeActions[0].insert("takeLeft_p4");
    ActionEdges[0][3].insert(0);
    EdgeActions[0].insert("takeLeft_p5");
    ActionEdges[0][4].insert(0);
    EdgeActions[0].insert("takeRight_p1");
    ActionEdges[0][5].insert(0);
    EdgeActions[0].insert("takeRight_p2");
    ActionEdges[0][6].insert(0);
    EdgeActions[0].insert("takeRight_p3");
    ActionEdges[0][7].insert(0);
    EdgeActions[0].insert("takeRight_p4");
    ActionEdges[0][8].insert(0);
    EdgeActions[0].insert("takeRight_p5");
    ActionEdges[0][9].insert(0);
    EdgeActions[2].insert("backToThink_p1");
    ActionEdges[1][10].insert(2);
    EdgeActions[3].insert("backToThink_p2");
    ActionEdges[1][11].insert(3);
    EdgeActions[4].insert("backToThink_p3");
    ActionEdges[1][12].insert(4);
    EdgeActions[5].insert("backToThink_p4");
    ActionEdges[1][13].insert(5);
    EdgeActions[6].insert("backToThink_p5");
    ActionEdges[1][14].insert(6);
    EdgeActions[7].insert("takeLeft_p1");
    ActionEdges[1][0].insert(7);
    EdgeActions[8].insert("takeLeft_p2");
    ActionEdges[1][1].insert(8);
    EdgeActions[9].insert("takeLeft_p3");
    ActionEdges[1][2].insert(9);
    EdgeActions[10].insert("takeLeft_p4");
    ActionEdges[1][3].insert(10);
    EdgeActions[11].insert("takeLeft_p5");
    ActionEdges[1][4].insert(11);
    EdgeActions[12].insert("takeRight_p1");
    ActionEdges[1][5].insert(12);
    EdgeActions[13].insert("takeRight_p2");
    ActionEdges[1][6].insert(13);
    EdgeActions[14].insert("takeRight_p3");
    ActionEdges[1][7].insert(14);
    EdgeActions[15].insert("takeRight_p4");
    ActionEdges[1][8].insert(15);
    EdgeActions[16].insert("takeRight_p5");
    ActionEdges[1][9].insert(16);
    if(true){
    			vector<double> vL(35,0);
    			LinForm=vL;
    			OldLinForm=vL;
    			vector<double> vF(35,0);
    			LhaFunc=vF;
    			vector<double> vA(35,0);
    			FormulaVal=vA;
    }
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
	Vars->time += GetFlow(0, CurrentLocation, Marking) * DeltaT;
	Vars->backToThink_p1 += GetFlow(1, CurrentLocation, Marking) * DeltaT;
	Vars->backToThink_p2 += GetFlow(2, CurrentLocation, Marking) * DeltaT;
	Vars->backToThink_p3 += GetFlow(3, CurrentLocation, Marking) * DeltaT;
	Vars->backToThink_p4 += GetFlow(4, CurrentLocation, Marking) * DeltaT;
	Vars->backToThink_p5 += GetFlow(5, CurrentLocation, Marking) * DeltaT;
	Vars->takeLeft_p1 += GetFlow(6, CurrentLocation, Marking) * DeltaT;
	Vars->takeLeft_p2 += GetFlow(7, CurrentLocation, Marking) * DeltaT;
	Vars->takeLeft_p3 += GetFlow(8, CurrentLocation, Marking) * DeltaT;
	Vars->takeLeft_p4 += GetFlow(9, CurrentLocation, Marking) * DeltaT;
	Vars->takeLeft_p5 += GetFlow(10, CurrentLocation, Marking) * DeltaT;
	Vars->takeRight_p1 += GetFlow(11, CurrentLocation, Marking) * DeltaT;
	Vars->takeRight_p2 += GetFlow(12, CurrentLocation, Marking) * DeltaT;
	Vars->takeRight_p3 += GetFlow(13, CurrentLocation, Marking) * DeltaT;
	Vars->takeRight_p4 += GetFlow(14, CurrentLocation, Marking) * DeltaT;
	Vars->takeRight_p5 += GetFlow(15, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Think_p1 += GetFlow(16, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Think_p2 += GetFlow(17, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Think_p3 += GetFlow(18, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Think_p4 += GetFlow(19, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Think_p5 += GetFlow(20, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Wait_p1 += GetFlow(21, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Wait_p2 += GetFlow(22, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Wait_p3 += GetFlow(23, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Wait_p4 += GetFlow(24, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Wait_p5 += GetFlow(25, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Eat_p1 += GetFlow(26, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Eat_p2 += GetFlow(27, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Eat_p3 += GetFlow(28, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Eat_p4 += GetFlow(29, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Eat_p5 += GetFlow(30, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Fork_p1 += GetFlow(31, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Fork_p2 += GetFlow(32, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Fork_p3 += GetFlow(33, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Fork_p4 += GetFlow(34, CurrentLocation, Marking) * DeltaT;
	Vars->PLVAR_Fork_p5 += GetFlow(35, CurrentLocation, Marking) * DeltaT;
}
double LHA::GetFlow(int v, int loc,const abstractMarking& Marking)const{
switch (v){
	case 26:	//PLVAR_Eat_p1
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Eat_p1  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 27:	//PLVAR_Eat_p2
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Eat_p2  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 28:	//PLVAR_Eat_p3
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Eat_p3  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 29:	//PLVAR_Eat_p4
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Eat_p4  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 30:	//PLVAR_Eat_p5
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Eat_p5  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 31:	//PLVAR_Fork_p1
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Fork_p1  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 32:	//PLVAR_Fork_p2
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Fork_p2  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 33:	//PLVAR_Fork_p3
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Fork_p3  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 34:	//PLVAR_Fork_p4
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Fork_p4  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 35:	//PLVAR_Fork_p5
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Fork_p5  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 16:	//PLVAR_Think_p1
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Think_p1  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 17:	//PLVAR_Think_p2
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Think_p2  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 18:	//PLVAR_Think_p3
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Think_p3  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 19:	//PLVAR_Think_p4
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Think_p4  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 20:	//PLVAR_Think_p5
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Think_p5  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 21:	//PLVAR_Wait_p1
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Wait_p1  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 22:	//PLVAR_Wait_p2
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Wait_p2  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 23:	//PLVAR_Wait_p3
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Wait_p3  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 24:	//PLVAR_Wait_p4
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Wait_p4  * 0.1;

		break;
	default:	//l0,l2,
		return 0.0;

}

		break;
	case 25:	//PLVAR_Wait_p5
switch (loc){
	case 1:	//l1
			return  Marking.P->_PL_Wait_p5  * 0.1;

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
	default:	//backToThink_p1,backToThink_p2,backToThink_p3,backToThink_p4,backToThink_p5,takeLeft_p1,takeLeft_p2,takeLeft_p3,takeLeft_p4,takeLeft_p5,takeRight_p1,takeRight_p2,takeRight_p3,takeRight_p4,takeRight_p5,
		return 0.0;


}
}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
switch (ed){
	case 1:	//
	case 17:	//
	return true;

		break;
	case 0:	//
{
         if(!( +(1)*Vars->time<=0)) return false;
         return true; 
     }

		break;
	default:	//,,,,,,,,,,,,,,,
{
         if(!( +(1)*Vars->time<=10)) return false;
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
	case 17:	//
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
	case 1:	//
         {
         tempVars->time=0;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 2:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1 + 0.100000;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 3:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2 + 0.100000;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 4:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3 + 0.100000;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 5:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4 + 0.100000;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 6:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5 + 0.100000;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 7:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1 + 0.100000;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 8:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2 + 0.100000;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 9:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3 + 0.100000;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 10:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4 + 0.100000;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 11:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5 + 0.100000;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 12:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1 + 0.100000;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 13:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2 + 0.100000;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 14:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3 + 0.100000;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 15:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4 + 0.100000;
         tempVars->takeRight_p5=Vars->takeRight_p5;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
	case 16:	//
         {
         tempVars->time=Vars->time;
         tempVars->backToThink_p1=Vars->backToThink_p1;
         tempVars->backToThink_p2=Vars->backToThink_p2;
         tempVars->backToThink_p3=Vars->backToThink_p3;
         tempVars->backToThink_p4=Vars->backToThink_p4;
         tempVars->backToThink_p5=Vars->backToThink_p5;
         tempVars->takeLeft_p1=Vars->takeLeft_p1;
         tempVars->takeLeft_p2=Vars->takeLeft_p2;
         tempVars->takeLeft_p3=Vars->takeLeft_p3;
         tempVars->takeLeft_p4=Vars->takeLeft_p4;
         tempVars->takeLeft_p5=Vars->takeLeft_p5;
         tempVars->takeRight_p1=Vars->takeRight_p1;
         tempVars->takeRight_p2=Vars->takeRight_p2;
         tempVars->takeRight_p3=Vars->takeRight_p3;
         tempVars->takeRight_p4=Vars->takeRight_p4;
         tempVars->takeRight_p5=Vars->takeRight_p5 + 0.100000;
         tempVars->PLVAR_Think_p1=Vars->PLVAR_Think_p1;
         tempVars->PLVAR_Think_p2=Vars->PLVAR_Think_p2;
         tempVars->PLVAR_Think_p3=Vars->PLVAR_Think_p3;
         tempVars->PLVAR_Think_p4=Vars->PLVAR_Think_p4;
         tempVars->PLVAR_Think_p5=Vars->PLVAR_Think_p5;
         tempVars->PLVAR_Wait_p1=Vars->PLVAR_Wait_p1;
         tempVars->PLVAR_Wait_p2=Vars->PLVAR_Wait_p2;
         tempVars->PLVAR_Wait_p3=Vars->PLVAR_Wait_p3;
         tempVars->PLVAR_Wait_p4=Vars->PLVAR_Wait_p4;
         tempVars->PLVAR_Wait_p5=Vars->PLVAR_Wait_p5;
         tempVars->PLVAR_Eat_p1=Vars->PLVAR_Eat_p1;
         tempVars->PLVAR_Eat_p2=Vars->PLVAR_Eat_p2;
         tempVars->PLVAR_Eat_p3=Vars->PLVAR_Eat_p3;
         tempVars->PLVAR_Eat_p4=Vars->PLVAR_Eat_p4;
         tempVars->PLVAR_Eat_p5=Vars->PLVAR_Eat_p5;
         tempVars->PLVAR_Fork_p1=Vars->PLVAR_Fork_p1;
         tempVars->PLVAR_Fork_p2=Vars->PLVAR_Fork_p2;
         tempVars->PLVAR_Fork_p3=Vars->PLVAR_Fork_p3;
         tempVars->PLVAR_Fork_p4=Vars->PLVAR_Fork_p4;
         tempVars->PLVAR_Fork_p5=Vars->PLVAR_Fork_p5;
		std::swap(Vars,tempVars);
         }

		break;
}
    OldLinForm[25]=LinForm[25];
    OldLinForm[26]=LinForm[26];
    OldLinForm[27]=LinForm[27];
    OldLinForm[28]=LinForm[28];
    OldLinForm[29]=LinForm[29];
    OldLinForm[30]=LinForm[30];
    OldLinForm[31]=LinForm[31];
    OldLinForm[32]=LinForm[32];
    OldLinForm[33]=LinForm[33];
    OldLinForm[34]=LinForm[34];
    OldLinForm[15]=LinForm[15];
    OldLinForm[16]=LinForm[16];
    OldLinForm[17]=LinForm[17];
    OldLinForm[18]=LinForm[18];
    OldLinForm[19]=LinForm[19];
    OldLinForm[20]=LinForm[20];
    OldLinForm[21]=LinForm[21];
    OldLinForm[22]=LinForm[22];
    OldLinForm[23]=LinForm[23];
    OldLinForm[24]=LinForm[24];
    OldLinForm[0]=LinForm[0];
    OldLinForm[1]=LinForm[1];
    OldLinForm[2]=LinForm[2];
    OldLinForm[3]=LinForm[3];
    OldLinForm[4]=LinForm[4];
    OldLinForm[5]=LinForm[5];
    OldLinForm[6]=LinForm[6];
    OldLinForm[7]=LinForm[7];
    OldLinForm[8]=LinForm[8];
    OldLinForm[9]=LinForm[9];
    OldLinForm[10]=LinForm[10];
    OldLinForm[11]=LinForm[11];
    OldLinForm[12]=LinForm[12];
    OldLinForm[13]=LinForm[13];
    OldLinForm[14]=LinForm[14];
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    LinForm[25]=Vars->PLVAR_Eat_p1;
    LinForm[26]=Vars->PLVAR_Eat_p2;
    LinForm[27]=Vars->PLVAR_Eat_p3;
    LinForm[28]=Vars->PLVAR_Eat_p4;
    LinForm[29]=Vars->PLVAR_Eat_p5;
    LinForm[30]=Vars->PLVAR_Fork_p1;
    LinForm[31]=Vars->PLVAR_Fork_p2;
    LinForm[32]=Vars->PLVAR_Fork_p3;
    LinForm[33]=Vars->PLVAR_Fork_p4;
    LinForm[34]=Vars->PLVAR_Fork_p5;
    LinForm[15]=Vars->PLVAR_Think_p1;
    LinForm[16]=Vars->PLVAR_Think_p2;
    LinForm[17]=Vars->PLVAR_Think_p3;
    LinForm[18]=Vars->PLVAR_Think_p4;
    LinForm[19]=Vars->PLVAR_Think_p5;
    LinForm[20]=Vars->PLVAR_Wait_p1;
    LinForm[21]=Vars->PLVAR_Wait_p2;
    LinForm[22]=Vars->PLVAR_Wait_p3;
    LinForm[23]=Vars->PLVAR_Wait_p4;
    LinForm[24]=Vars->PLVAR_Wait_p5;
    LinForm[0]=Vars->backToThink_p1;
    LinForm[1]=Vars->backToThink_p2;
    LinForm[2]=Vars->backToThink_p3;
    LinForm[3]=Vars->backToThink_p4;
    LinForm[4]=Vars->backToThink_p5;
    LinForm[5]=Vars->takeLeft_p1;
    LinForm[6]=Vars->takeLeft_p2;
    LinForm[7]=Vars->takeLeft_p3;
    LinForm[8]=Vars->takeLeft_p4;
    LinForm[9]=Vars->takeLeft_p5;
    LinForm[10]=Vars->takeRight_p1;
    LinForm[11]=Vars->takeRight_p2;
    LinForm[12]=Vars->takeRight_p3;
    LinForm[13]=Vars->takeRight_p4;
    LinForm[14]=Vars->takeRight_p5;
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
    LhaFunc[19]=LinForm[19];
    LhaFunc[20]=LinForm[20];
    LhaFunc[21]=LinForm[21];
    LhaFunc[22]=LinForm[22];
    LhaFunc[23]=LinForm[23];
    LhaFunc[24]=LinForm[24];
    LhaFunc[25]=LinForm[25];
    LhaFunc[26]=LinForm[26];
    LhaFunc[27]=LinForm[27];
    LhaFunc[28]=LinForm[28];
    LhaFunc[29]=LinForm[29];
    LhaFunc[30]=LinForm[30];
    LhaFunc[31]=LinForm[31];
    LhaFunc[32]=LinForm[32];
    LhaFunc[33]=LinForm[33];
    LhaFunc[34]=LinForm[34];

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

    OldFormulaVal=FormulaVal[19];
    FormulaVal[19]=LhaFunc[19];

    OldFormulaVal=FormulaVal[20];
    FormulaVal[20]=LhaFunc[20];

    OldFormulaVal=FormulaVal[21];
    FormulaVal[21]=LhaFunc[21];

    OldFormulaVal=FormulaVal[22];
    FormulaVal[22]=LhaFunc[22];

    OldFormulaVal=FormulaVal[23];
    FormulaVal[23]=LhaFunc[23];

    OldFormulaVal=FormulaVal[24];
    FormulaVal[24]=LhaFunc[24];

    OldFormulaVal=FormulaVal[25];
    FormulaVal[25]=LhaFunc[25];

    OldFormulaVal=FormulaVal[26];
    FormulaVal[26]=LhaFunc[26];

    OldFormulaVal=FormulaVal[27];
    FormulaVal[27]=LhaFunc[27];

    OldFormulaVal=FormulaVal[28];
    FormulaVal[28]=LhaFunc[28];

    OldFormulaVal=FormulaVal[29];
    FormulaVal[29]=LhaFunc[29];

    OldFormulaVal=FormulaVal[30];
    FormulaVal[30]=LhaFunc[30];

    OldFormulaVal=FormulaVal[31];
    FormulaVal[31]=LhaFunc[31];

    OldFormulaVal=FormulaVal[32];
    FormulaVal[32]=LhaFunc[32];

    OldFormulaVal=FormulaVal[33];
    FormulaVal[33]=LhaFunc[33];

    OldFormulaVal=FormulaVal[34];
    FormulaVal[34]=LhaFunc[34];

}

