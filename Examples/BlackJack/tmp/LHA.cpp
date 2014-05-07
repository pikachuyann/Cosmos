#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "markingImpl.hpp"
#include <math.h>
#include <float.h>
#include "LHA.hpp"
struct Variables {
	double BANK;
	double result;
	double hiddenBANK;
	double player;
};
void LHA::resetVariables(){
	Vars->BANK= 0;
	Vars->result= 0;
	Vars->hiddenBANK= 0;
	Vars->player= 0;
};
void LHA::printHeader(ostream &s)const{
	s << "	Location\t";
};
void LHA::printState(ostream &s)const{
	s << "\t" << LocLabel[CurrentLocation] << "\t";
};
LHA::LHA(){
    NbLoc =11;
    NbVar =4;
    InitLoc.insert(10);
    FinalLoc.insert(3);
    FinalLoc.insert(4);
    FinalLoc.insert(8);
    Edge= vector<LhaEdge>(14);
    Edge[0] = LhaEdge(0, 7, 6,Auto);
    Edge[1] = LhaEdge(1, 7, 3,Auto);
    Edge[2] = LhaEdge(2, 0, 6,Synch);
    Edge[3] = LhaEdge(3, 6, 0,Auto);
    Edge[4] = LhaEdge(4, 6, 4,Synch);
    Edge[5] = LhaEdge(5, 6, 9,Auto);
    Edge[6] = LhaEdge(6, 9, 8,Auto);
    Edge[7] = LhaEdge(7, 9, 8,Auto);
    Edge[8] = LhaEdge(8, 2, 1,Synch);
    Edge[9] = LhaEdge(9, 9, 8,Auto);
    Edge[10] = LhaEdge(10, 1, 5,Synch);
    Edge[11] = LhaEdge(11, 10, 2,Synch);
    Edge[12] = LhaEdge(12, 7, 5,Auto);
    Edge[13] = LhaEdge(13, 5, 7,Synch);
	Vars = new Variables;
	tempVars = new Variables;
	resetVariables();
    Out_S_Edges =vector< set < int > >(NbLoc);
    Out_A_Edges =vector< set < int > >(NbLoc);
{
    Out_A_Edges[7].insert(0);
    Out_A_Edges[7].insert(1);
    Out_S_Edges[0].insert(2);
    Out_A_Edges[6].insert(3);
    Out_S_Edges[6].insert(4);
    Out_A_Edges[6].insert(5);
    Out_A_Edges[9].insert(6);
    Out_A_Edges[9].insert(7);
    Out_S_Edges[2].insert(8);
    Out_A_Edges[9].insert(9);
    Out_S_Edges[1].insert(10);
    Out_S_Edges[10].insert(11);
    Out_A_Edges[7].insert(12);
    Out_S_Edges[5].insert(13);
}
    ActionEdges=vector < vector < set <int> > >(NbLoc,vector< set<int> >(10));
{
}
{
}
{
    ActionEdges[0][8].insert(2);
    ActionEdges[0][0].insert(2);
    ActionEdges[0][1].insert(2);
    ActionEdges[0][5].insert(2);
    ActionEdges[0][3].insert(2);
    ActionEdges[0][7].insert(2);
    ActionEdges[0][2].insert(2);
    ActionEdges[0][9].insert(2);
    ActionEdges[0][4].insert(2);
    ActionEdges[0][6].insert(2);
}
{
}
{
    ActionEdges[6][8].insert(4);
    ActionEdges[6][0].insert(4);
    ActionEdges[6][1].insert(4);
    ActionEdges[6][5].insert(4);
    ActionEdges[6][3].insert(4);
    ActionEdges[6][7].insert(4);
    ActionEdges[6][2].insert(4);
    ActionEdges[6][9].insert(4);
    ActionEdges[6][4].insert(4);
    ActionEdges[6][6].insert(4);
}
{
}
{
}
{
}
{
    ActionEdges[2][8].insert(8);
    ActionEdges[2][0].insert(8);
    ActionEdges[2][1].insert(8);
    ActionEdges[2][5].insert(8);
    ActionEdges[2][3].insert(8);
    ActionEdges[2][7].insert(8);
    ActionEdges[2][2].insert(8);
    ActionEdges[2][9].insert(8);
    ActionEdges[2][4].insert(8);
    ActionEdges[2][6].insert(8);
}
{
}
{
    ActionEdges[1][8].insert(10);
    ActionEdges[1][0].insert(10);
    ActionEdges[1][1].insert(10);
    ActionEdges[1][5].insert(10);
    ActionEdges[1][3].insert(10);
    ActionEdges[1][7].insert(10);
    ActionEdges[1][2].insert(10);
    ActionEdges[1][9].insert(10);
    ActionEdges[1][4].insert(10);
    ActionEdges[1][6].insert(10);
}
{
    ActionEdges[10][8].insert(11);
    ActionEdges[10][0].insert(11);
    ActionEdges[10][1].insert(11);
    ActionEdges[10][5].insert(11);
    ActionEdges[10][3].insert(11);
    ActionEdges[10][7].insert(11);
    ActionEdges[10][2].insert(11);
    ActionEdges[10][9].insert(11);
    ActionEdges[10][4].insert(11);
    ActionEdges[10][6].insert(11);
}
{
}
{
    ActionEdges[5][8].insert(13);
    ActionEdges[5][0].insert(13);
    ActionEdges[5][1].insert(13);
    ActionEdges[5][5].insert(13);
    ActionEdges[5][3].insert(13);
    ActionEdges[5][7].insert(13);
    ActionEdges[5][2].insert(13);
    ActionEdges[5][9].insert(13);
    ActionEdges[5][4].insert(13);
    ActionEdges[5][6].insert(13);
}
    LinForm= vector<double>(1,0.0);
    OldLinForm=vector<double>(1,0.0);
    LhaFunc=vector<double>(1,0.0);
    FormulaVal = vector<double>(1,0.0);
}

void LHA::DoElapsedTimeUpdate(double DeltaT,const abstractMarking& Marking) {
}
double LHA::GetFlow(int v, const abstractMarking& Marking)const{

}

bool LHA::CheckLocation(int loc,const abstractMarking& Marking)const{
         return true;

}

bool LHA::CheckEdgeContraints(int ed,size_t ptt,const abstractBinding& b,const abstractMarking& Marking)const{
switch (ed){
	case 4:	//
{
		return ((Vars->BANK>=22));
     }

		break;
	case 3:	//
{
		return (true&& (+1* Vars->BANK <=16));
     }

		break;
	case 7:	//
{
		return (true&& (+1* Vars->BANK ==Vars->player));
     }

		break;
	case 9:	//
{
		return (true&& (+1* Vars->BANK >=(Vars->player+1)));
     }

		break;
	case 5:	//
{
		return (true&& (+1* Vars->BANK >=17)&& (+1* Vars->BANK <=21));
     }

		break;
	case 12:	//
{
		return (true&& (+1* Vars->player <=16));
     }

		break;
	case 0:	//
{
		return (true&& (+1* Vars->player >=17)&& (+1* Vars->player <=21));
     }

		break;
	case 1:	//
{
		return (true&& (+1* Vars->player >=22));
     }

		break;
	default:	//,,,,,,
	return true;

}
}

t_interval LHA::GetEdgeEnablingTime(int ed,const abstractMarking& Marking)const{
switch (ed){
	case 2:	//
	case 4:	//
	case 8:	//
	case 10:	//
	case 11:	//
	case 13:	//
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             return EnablingT;
         }

		break;
	default:	//,,,,,,,,
         {
             t_interval EnablingT;

             EnablingT.first=CurrentTime;
             EnablingT.second=DBL_MAX;

             t_interval EmptyInterval;

             EmptyInterval.first=0;
             EmptyInterval.second=-1;

             double SumAF;
             double SumAX;


             return EnablingT;
         }

}
}

void LHA::DoEdgeUpdates(int ed,const abstractMarking& Marking, const abstractBinding& b){
switch (ed){
	case 2:	//
         {
		Vars->BANK=(Vars->BANK+Marking.P->_PL_LastDraw );
         }

		break;
	case 0:	//
         {
		Vars->BANK=(Vars->BANK+Vars->hiddenBANK);
         }

		break;
	case 11:	//
         {
		Vars->BANK=Marking.P->_PL_LastDraw ;
         }

		break;
	case 10:	//
         {
		Vars->hiddenBANK=Marking.P->_PL_LastDraw ;
         }

		break;
	case 13:	//
         {
		Vars->player=(Vars->player+Marking.P->_PL_LastDraw );
         }

		break;
	case 8:	//
         {
		Vars->player=Marking.P->_PL_LastDraw ;
         }

		break;
	case 1:	//
	case 9:	//
         {
		Vars->result=-1;
         }

		break;
	case 7:	//
         {
		Vars->result=0;
         }

		break;
	case 4:	//
	case 6:	//
         {
		Vars->result=1;
         }

		break;
}
}

void LHA::UpdateLinForm(const abstractMarking& Marking){
    }

void LHA::UpdateLhaFunc(double& Delta ){

    }

void LHA::UpdateLhaFuncLast(){
    LhaFunc[0]= Vars->result;

    }

void LHA::UpdateFormulaVal(){

    FormulaVal[0]=LhaFunc[0];
}

