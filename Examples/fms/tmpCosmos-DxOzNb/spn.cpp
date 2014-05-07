#include "spn.hpp"
#include <iomanip>
	const double Tunit=0.5;
	const double alpha1=0.45;
	const double alpha2=0.55;
	const double failrate=0;
	const double mu1=0.68305;
	const double mu2=0.68305;
	const double sigma1=0.83255;
	const double sigma2=0.83255;
	const int _nb_Place_Products=0;
	const int _nb_Place_Buffer1=1;
	const int _nb_Place_Pos1_1=2;
	const int _nb_Place_Ready1=3;
	const int _nb_Place_Waiting1=4;
	const int _nb_Place_Q1=5;
	const int _nb_Place_Pos1_4=6;
	const int _nb_Place_Pos1_3=7;
	const int _nb_Place_Pos1_2=8;
	const int _nb_Place_Ready2=9;
	const int _nb_Place_Waiting2=10;
	const int _nb_Place_Buffer2=11;
	const int _nb_Place_Pos2_1=12;
	const int _nb_Place_Pos2_2=13;
	const int _nb_Place_Q2=14;
	const int _nb_Place_Pos2_4=15;
	const int _nb_Place_OccPos2=16;
	const int _nb_Place_Up1=17;
	const int _nb_Place_Pos2_3=18;
	const int _nb_Place_OccPos1=19;
	const int _nb_Place_Down1=20;
	const int _nb_Place_Up2=21;
	const int _nb_Place_Down2=22;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_Products =0;
	P->_PL_Buffer1 =0;
	P->_PL_Pos1_1 =0;
	P->_PL_Ready1 =1;
	P->_PL_Waiting1 =0;
	P->_PL_Q1 =0;
	P->_PL_Pos1_4 =0;
	P->_PL_Pos1_3 =0;
	P->_PL_Pos1_2 =0;
	P->_PL_Ready2 =1;
	P->_PL_Waiting2 =0;
	P->_PL_Buffer2 =0;
	P->_PL_Pos2_1 =0;
	P->_PL_Pos2_2 =0;
	P->_PL_Q2 =0;
	P->_PL_Pos2_4 =0;
	P->_PL_OccPos2 =0;
	P->_PL_Up1 =1;
	P->_PL_Pos2_3 =0;
	P->_PL_OccPos1 =0;
	P->_PL_Down1 =0;
	P->_PL_Up2 =1;
	P->_PL_Down2 =0;
}


abstractMarking::abstractMarking() {
	P= new abstractMarkingImpl;
	resetToInitMarking();
}

abstractMarking::abstractMarking(const std::vector<int>& m) {
	P = new abstractMarkingImpl;
	setVector(m);
}
abstractMarking::abstractMarking(const abstractMarking& m) {
	P= new abstractMarkingImpl;
	*this = m;
};

abstractMarking& abstractMarking::operator = (const abstractMarking& m) {
	*P = *(m.P);
	return *this;
}

abstractMarking::~abstractMarking() {
	delete(P);
}


void abstractMarking::swap(abstractMarking& m) {
	abstractMarkingImpl* tmp = m.P;
	m.P = P;
	P = tmp;
}
void abstractMarking::printHeader(ostream &s)const{
}

void abstractMarking::print(ostream &s)const{
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_Products;
		case 1: return P->_PL_Buffer1;
		case 2: return P->_PL_Pos1_1;
		case 3: return P->_PL_Ready1;
		case 4: return P->_PL_Waiting1;
		case 5: return P->_PL_Q1;
		case 6: return P->_PL_Pos1_4;
		case 7: return P->_PL_Pos1_3;
		case 8: return P->_PL_Pos1_2;
		case 9: return P->_PL_Ready2;
		case 10: return P->_PL_Waiting2;
		case 11: return P->_PL_Buffer2;
		case 12: return P->_PL_Pos2_1;
		case 13: return P->_PL_Pos2_2;
		case 14: return P->_PL_Q2;
		case 15: return P->_PL_Pos2_4;
		case 16: return P->_PL_OccPos2;
		case 17: return P->_PL_Up1;
		case 18: return P->_PL_Pos2_3;
		case 19: return P->_PL_OccPos1;
		case 20: return P->_PL_Down1;
		case 21: return P->_PL_Up2;
		case 22: return P->_PL_Down2;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(23);
	v[0] = P->_PL_Products;
	v[1] = P->_PL_Buffer1;
	v[2] = P->_PL_Pos1_1;
	v[3] = P->_PL_Ready1;
	v[4] = P->_PL_Waiting1;
	v[5] = P->_PL_Q1;
	v[6] = P->_PL_Pos1_4;
	v[7] = P->_PL_Pos1_3;
	v[8] = P->_PL_Pos1_2;
	v[9] = P->_PL_Ready2;
	v[10] = P->_PL_Waiting2;
	v[11] = P->_PL_Buffer2;
	v[12] = P->_PL_Pos2_1;
	v[13] = P->_PL_Pos2_2;
	v[14] = P->_PL_Q2;
	v[15] = P->_PL_Pos2_4;
	v[16] = P->_PL_OccPos2;
	v[17] = P->_PL_Up1;
	v[18] = P->_PL_Pos2_3;
	v[19] = P->_PL_OccPos1;
	v[20] = P->_PL_Down1;
	v[21] = P->_PL_Up2;
	v[22] = P->_PL_Down2;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_Products = v[0];
	P->_PL_Buffer1 = v[1];
	P->_PL_Pos1_1 = v[2];
	P->_PL_Ready1 = v[3];
	P->_PL_Waiting1 = v[4];
	P->_PL_Q1 = v[5];
	P->_PL_Pos1_4 = v[6];
	P->_PL_Pos1_3 = v[7];
	P->_PL_Pos1_2 = v[8];
	P->_PL_Ready2 = v[9];
	P->_PL_Waiting2 = v[10];
	P->_PL_Buffer2 = v[11];
	P->_PL_Pos2_1 = v[12];
	P->_PL_Pos2_2 = v[13];
	P->_PL_Q2 = v[14];
	P->_PL_Pos2_4 = v[15];
	P->_PL_OccPos2 = v[16];
	P->_PL_Up1 = v[17];
	P->_PL_Pos2_3 = v[18];
	P->_PL_OccPos1 = v[19];
	P->_PL_Down1 = v[20];
	P->_PL_Up2 = v[21];
	P->_PL_Down2 = v[22];
};

bool abstractBinding::next() {
	idcount++;
	return false;
};
abstractBinding::abstractBinding() {
       idcount=0;
}
abstractBinding::abstractBinding(const abstractBinding& m) {
	idcount = m.idcount;
}
abstractBinding::~abstractBinding() {
}
abstractBinding& abstractBinding::operator = (const abstractBinding& m) {
	idcount = m.idcount;
       return *this;
}
void abstractBinding::print()const{
}
int abstractBinding::id()const{
	return idcount;
}
int abstractBinding::idTotal()const{
	 return 0;
}
SPN::SPN():
pl(23), tr(23), Place(23),Transition(23),ParamDistr(3), TransitionConditions(23,0){
    Path ="Policy2.grml";
	PossiblyEnabled = vector< set<int> >(23);
	PossiblyEnabled[0].insert( 18 );
	PossiblyEnabled[0].insert( 19 );
	PossiblyEnabled[1].insert( 2 );
	PossiblyEnabled[1].insert( 3 );
	PossiblyEnabled[2].insert( 1 );
	{
		int PE[]= {1, 4, 7, 18, 19};
		PossiblyEnabled[3] = set<int>(PE,PE+5);
	}
	PossiblyEnabled[4].insert( 8 );
	PossiblyEnabled[5].insert( 4 );
	PossiblyEnabled[6].insert( 5 );
	PossiblyEnabled[7].insert( 6 );
	{
		int PE[]= {1, 4, 5, 6, 7, 16};
		PossiblyEnabled[8] = set<int>(PE,PE+6);
	}
	PossiblyEnabled[9].insert( 10 );
	PossiblyEnabled[10].insert( 20 );
	PossiblyEnabled[11].insert( 12 );
	PossiblyEnabled[12].insert( 9 );
	PossiblyEnabled[13].insert( 14 );
	PossiblyEnabled[13].insert( 15 );
	{
		int PE[]= {10, 11, 13, 18, 19};
		PossiblyEnabled[14] = set<int>(PE,PE+5);
	}
	PossiblyEnabled[15].insert( 13 );
	PossiblyEnabled[16].insert( 17 );
	PossiblyEnabled[17].insert( 8 );
	PossiblyEnabled[17].insert( 16 );
	{
		int PE[]= {4, 10, 14, 19};
		PossiblyEnabled[18] = set<int>(PE,PE+4);
	}
	{
		int PE[]= {3, 4, 10, 18};
		PossiblyEnabled[19] = set<int>(PE,PE+4);
	}
	{
		int PE[]= {9, 10, 11, 12, 13, 22};
		PossiblyEnabled[20] = set<int>(PE,PE+6);
	}
	PossiblyEnabled[21].insert( 20 );
	PossiblyEnabled[21].insert( 22 );
	PossiblyEnabled[22].insert( 21 );

	PossiblyDisabled = vector< set<int> >(23);
	PossiblyDisabled[2].insert( 3 );
	PossiblyDisabled[3].insert( 2 );
	{
		int PE[]= {1, 5, 6, 7, 18, 19};
		PossiblyDisabled[4] = set<int>(PE,PE+6);
	}
	PossiblyDisabled[8].insert( 16 );
	{
		int PE[]= {9, 11, 12, 13, 18, 19};
		PossiblyDisabled[10] = set<int>(PE,PE+6);
	}
	PossiblyDisabled[14].insert( 15 );
	PossiblyDisabled[15].insert( 14 );
	PossiblyDisabled[16].insert( 8 );
	{
		int PE[]= {4, 10, 19};
		PossiblyDisabled[18] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {4, 10, 18};
		PossiblyDisabled[19] = set<int>(PE,PE+3);
	}
	PossiblyDisabled[20].insert( 22 );
	PossiblyDisabled[22].insert( 20 );

	FreeMarkDepT = vector< set<int> >(23);

	Transition[0] = _trans(0,Timed,UNIFORM,0,1);
	Transition[1] = _trans(1,Timed,DETERMINISTIC,0,1);
	Transition[2] = _trans(2,Timed,DETERMINISTIC,0,1);
	Transition[3] = _trans(3,Timed,DETERMINISTIC,0,1);
	Transition[4] = _trans(4,Timed,DETERMINISTIC,0,1);
	Transition[5] = _trans(5,Timed,DETERMINISTIC,0,1);
	Transition[6] = _trans(6,Timed,DETERMINISTIC,0,1);
	Transition[7] = _trans(7,Timed,DETERMINISTIC,0,1);
	Transition[8] = _trans(8,Timed,LOGNORMAL,0,1);
	Transition[9] = _trans(9,Timed,DETERMINISTIC,0,1);
	Transition[10] = _trans(10,Timed,DETERMINISTIC,0,1);
	Transition[11] = _trans(11,Timed,DETERMINISTIC,0,1);
	Transition[12] = _trans(12,Timed,DETERMINISTIC,0,1);
	Transition[13] = _trans(13,Timed,DETERMINISTIC,0,1);
	Transition[14] = _trans(14,Timed,DETERMINISTIC,0,1);
	Transition[15] = _trans(15,Timed,DETERMINISTIC,0,1);
	Transition[16] = _trans(16,Timed,ERLANG,0,1);
	Transition[17] = _trans(17,Timed,UNIFORM,0,1);
	Transition[18] = _trans(18,Timed,DETERMINISTIC,0,1);
	Transition[19] = _trans(19,Timed,DETERMINISTIC,0,1);
	Transition[20] = _trans(20,Timed,LOGNORMAL,0,1);
	Transition[21] = _trans(21,Timed,UNIFORM,0,1);
	Transition[22] = _trans(22,Timed,ERLANG,0,1);
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 17:	//Repair1
    if (!(contains(Marking.P->_PL_Down1 , 1))) return false;
    return true;

		break;
	case 21:	//Repair2
    if (!(contains(Marking.P->_PL_Down2 , 1))) return false;
    return true;

		break;
	case 7:	//Mv1_2
    if (!(contains(Marking.P->_PL_Pos1_1 , 1))) return false;
    if (Marking.P->_PL_Q1 >= 2) return false;
    return true;

		break;
	case 11:	//Mv2_2
    if (!(contains(Marking.P->_PL_Pos2_1 , 1))) return false;
    if (Marking.P->_PL_Q2 >= 2) return false;
    return true;

		break;
	case 12:	//Mv2_3
    if (!(contains(Marking.P->_PL_Pos2_2 , 1))) return false;
    if (Marking.P->_PL_Q2 >= 2) return false;
    return true;

		break;
	case 19:	//choose1
    if (!(contains(Marking.P->_PL_Products , 1))) return false;
    if ( !((Marking.P->_PL_OccPos1) < 1)) 
        if (!(contains(Marking.P->_PL_OccPos2 , (Marking.P->_PL_OccPos1)))) return false;
    if ( !((Marking.P->_PL_OccPos1) < 1)) 
        if (!(contains(Marking.P->_PL_OccPos1 , (Marking.P->_PL_OccPos1)))) return false;
    return true;

		break;
	case 18:	//Choose2
    if (!(contains(Marking.P->_PL_Products , 1))) return false;
    if ( !((Marking.P->_PL_OccPos2) < 1)) 
        if (!(contains(Marking.P->_PL_OccPos2 , (Marking.P->_PL_OccPos2)))) return false;
    if ( !((Marking.P->_PL_OccPos2) < 1)) 
        if (!(contains(Marking.P->_PL_OccPos1 , (Marking.P->_PL_OccPos2)))) return false;
    return true;

		break;
	case 8:	//Serve1
    if (!(contains(Marking.P->_PL_Q1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Up1 , 1))) return false;
    return true;

		break;
	case 20:	//Serve2
    if (!(contains(Marking.P->_PL_Q2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Up2 , 1))) return false;
    return true;

		break;
	case 2:	//Finish_1
    if (!(contains(Marking.P->_PL_Ready1 , 1))) return false;
    return true;

		break;
	case 14:	//Mv2_1
    if (!(contains(Marking.P->_PL_Ready2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Buffer2 , 1))) return false;
    return true;

		break;
	case 15:	//Finish_2
    if (!(contains(Marking.P->_PL_Ready2 , 1))) return false;
    return true;

		break;
	case 16:	//Fail1
    if (!(contains(Marking.P->_PL_Up1 , 1))) return false;
    return true;

		break;
	case 22:	//Fail2
    if (!(contains(Marking.P->_PL_Up2 , 1))) return false;
    return true;

		break;
	case 1:	//Start_1
    if (!(contains(Marking.P->_PL_Waiting1 , 1))) return false;
    if (Marking.P->_PL_Q1 >= 2) return false;
    return true;

		break;
	case 13:	//Start_2
    if (!(contains(Marking.P->_PL_Waiting2 , 1))) return false;
    if (Marking.P->_PL_Q2 >= 2) return false;
    return true;

		break;
	case 6:	//Mv1_3
    if (Marking.P->_PL_Q1 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos1_2 , 1))) return false;
    return true;

		break;
	case 5:	//Mv1_4
    if (Marking.P->_PL_Q1 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos1_3 , 1))) return false;
    return true;

		break;
	case 4:	//Mv1_5
    if (Marking.P->_PL_Q1 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos1_4 , 1))) return false;
    if (!(contains(Marking.P->_PL_OccPos1 , 1))) return false;
    return true;

		break;
	case 9:	//Mv2_4
    if (Marking.P->_PL_Q2 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos2_3 , 1))) return false;
    return true;

		break;
	case 10:	//Mv2_5
    if (Marking.P->_PL_Q2 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos2_4 , 1))) return false;
    if (!(contains(Marking.P->_PL_OccPos2 , 1))) return false;
    return true;

		break;
	case 0:	//Arrive
    return true;

		break;
	default:	//Mv1_1,
    if (!(contains(Marking.P->_PL_Buffer1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Ready1 , 1))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b){
	lastTransition = t;
	switch(t){
		case 0: {  //Arrive
