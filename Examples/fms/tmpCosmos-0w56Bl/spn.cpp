#include "spn.hpp"
#include <iomanip>
	const double Tunit=0.5;
	const double alpha1=0.45;
	const double alpha2=0.55;
	const double failrate=0;
	const double l1=3;
	const double l2=3;
	const double mu1=0.68305;
	const double mu2=0.68305;
	const double sigma1=0.83255;
	const double sigma2=0.83255;
	const int _nb_Place_Products=0;
	const int _nb_Place_InConv1=1;
	const int _nb_Place_Buffer1=2;
	const int _nb_Place_Pos1_1=3;
	const int _nb_Place_Ready1=4;
	const int _nb_Place_Waiting1=5;
	const int _nb_Place_Down2=6;
	const int _nb_Place_Up2=7;
	const int _nb_Place_Q1=8;
	const int _nb_Place_Pos1_4=9;
	const int _nb_Place_Pos1_3=10;
	const int _nb_Place_Pos1_2=11;
	const int _nb_Place_Ready2=12;
	const int _nb_Place_Waiting2=13;
	const int _nb_Place_InConv2=14;
	const int _nb_Place_Buffer2=15;
	const int _nb_Place_Pos2_1=16;
	const int _nb_Place_Pos2_4=17;
	const int _nb_Place_Q2=18;
	const int _nb_Place_Pos2_2=19;
	const int _nb_Place_Pos2_3=20;
	const int _nb_Place_Up1=21;
	const int _nb_Place_Down1=22;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_Products =0;
	P->_PL_InConv1 =0;
	P->_PL_Buffer1 =0;
	P->_PL_Pos1_1 =0;
	P->_PL_Ready1 =1;
	P->_PL_Waiting1 =0;
	P->_PL_Down2 =0;
	P->_PL_Up2 =1;
	P->_PL_Q1 =0;
	P->_PL_Pos1_4 =0;
	P->_PL_Pos1_3 =0;
	P->_PL_Pos1_2 =0;
	P->_PL_Ready2 =1;
	P->_PL_Waiting2 =0;
	P->_PL_InConv2 =0;
	P->_PL_Buffer2 =0;
	P->_PL_Pos2_1 =0;
	P->_PL_Pos2_4 =0;
	P->_PL_Q2 =0;
	P->_PL_Pos2_2 =0;
	P->_PL_Pos2_3 =0;
	P->_PL_Up1 =1;
	P->_PL_Down1 =0;
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
		case 1: return P->_PL_InConv1;
		case 2: return P->_PL_Buffer1;
		case 3: return P->_PL_Pos1_1;
		case 4: return P->_PL_Ready1;
		case 5: return P->_PL_Waiting1;
		case 6: return P->_PL_Down2;
		case 7: return P->_PL_Up2;
		case 8: return P->_PL_Q1;
		case 9: return P->_PL_Pos1_4;
		case 10: return P->_PL_Pos1_3;
		case 11: return P->_PL_Pos1_2;
		case 12: return P->_PL_Ready2;
		case 13: return P->_PL_Waiting2;
		case 14: return P->_PL_InConv2;
		case 15: return P->_PL_Buffer2;
		case 16: return P->_PL_Pos2_1;
		case 17: return P->_PL_Pos2_4;
		case 18: return P->_PL_Q2;
		case 19: return P->_PL_Pos2_2;
		case 20: return P->_PL_Pos2_3;
		case 21: return P->_PL_Up1;
		case 22: return P->_PL_Down1;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(23);
	v[0] = P->_PL_Products;
	v[1] = P->_PL_InConv1;
	v[2] = P->_PL_Buffer1;
	v[3] = P->_PL_Pos1_1;
	v[4] = P->_PL_Ready1;
	v[5] = P->_PL_Waiting1;
	v[6] = P->_PL_Down2;
	v[7] = P->_PL_Up2;
	v[8] = P->_PL_Q1;
	v[9] = P->_PL_Pos1_4;
	v[10] = P->_PL_Pos1_3;
	v[11] = P->_PL_Pos1_2;
	v[12] = P->_PL_Ready2;
	v[13] = P->_PL_Waiting2;
	v[14] = P->_PL_InConv2;
	v[15] = P->_PL_Buffer2;
	v[16] = P->_PL_Pos2_1;
	v[17] = P->_PL_Pos2_4;
	v[18] = P->_PL_Q2;
	v[19] = P->_PL_Pos2_2;
	v[20] = P->_PL_Pos2_3;
	v[21] = P->_PL_Up1;
	v[22] = P->_PL_Down1;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_Products = v[0];
	P->_PL_InConv1 = v[1];
	P->_PL_Buffer1 = v[2];
	P->_PL_Pos1_1 = v[3];
	P->_PL_Ready1 = v[4];
	P->_PL_Waiting1 = v[5];
	P->_PL_Down2 = v[6];
	P->_PL_Up2 = v[7];
	P->_PL_Q1 = v[8];
	P->_PL_Pos1_4 = v[9];
	P->_PL_Pos1_3 = v[10];
	P->_PL_Pos1_2 = v[11];
	P->_PL_Ready2 = v[12];
	P->_PL_Waiting2 = v[13];
	P->_PL_InConv2 = v[14];
	P->_PL_Buffer2 = v[15];
	P->_PL_Pos2_1 = v[16];
	P->_PL_Pos2_4 = v[17];
	P->_PL_Q2 = v[18];
	P->_PL_Pos2_2 = v[19];
	P->_PL_Pos2_3 = v[20];
	P->_PL_Up1 = v[21];
	P->_PL_Down1 = v[22];
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
pl(23), tr(27), Place(23),Transition(27),ParamDistr(3), TransitionConditions(27,0){
    Path ="Policy1.grml";
	PossiblyEnabled = vector< set<int> >(27);
	{
		int PE[]= {3, 4, 5, 14, 15, 21};
		PossiblyEnabled[0] = set<int>(PE,PE+6);
	}
	PossiblyEnabled[1].insert( 2 );
	PossiblyEnabled[2].insert( 1 );
	PossiblyEnabled[2].insert( 24 );
	PossiblyEnabled[3].insert( 8 );
	PossiblyEnabled[3].insert( 9 );
	PossiblyEnabled[4].insert( 8 );
	PossiblyEnabled[4].insert( 9 );
	{
		int PE[]= {8, 9, 16, 17, 18, 19, 20, 21, 24};
		PossiblyEnabled[5] = set<int>(PE,PE+9);
	}
	PossiblyEnabled[6].insert( 7 );
	PossiblyEnabled[6].insert( 8 );
	PossiblyEnabled[7].insert( 6 );
	PossiblyEnabled[8].insert( 6 );
	PossiblyEnabled[8].insert( 12 );
	{
		int PE[]= {3, 13, 21};
		PossiblyEnabled[9] = set<int>(PE,PE+3);
	}
	PossiblyEnabled[10].insert( 9 );
	PossiblyEnabled[11].insert( 10 );
	PossiblyEnabled[12].insert( 11 );
	{
		int PE[]= {5, 6, 9, 10, 11, 12, 26};
		PossiblyEnabled[13] = set<int>(PE,PE+7);
	}
	PossiblyEnabled[14].insert( 17 );
	PossiblyEnabled[14].insert( 22 );
	PossiblyEnabled[15].insert( 17 );
	PossiblyEnabled[15].insert( 22 );
	PossiblyEnabled[16].insert( 17 );
	{
		int PE[]= {5, 14, 24};
		PossiblyEnabled[17] = set<int>(PE,PE+3);
	}
	PossiblyEnabled[18].insert( 19 );
	PossiblyEnabled[19].insert( 16 );
	PossiblyEnabled[20].insert( 22 );
	PossiblyEnabled[20].insert( 23 );
	{
		int PE[]= {5, 6, 9, 10, 11, 12, 13, 17, 22};
		PossiblyEnabled[21] = set<int>(PE,PE+9);
	}
	PossiblyEnabled[22].insert( 18 );
	PossiblyEnabled[22].insert( 20 );
	PossiblyEnabled[23].insert( 20 );
	{
		int PE[]= {1, 16, 17, 18, 19, 20, 21};
		PossiblyEnabled[24] = set<int>(PE,PE+7);
	}
	PossiblyEnabled[25].insert( 13 );
	PossiblyEnabled[25].insert( 26 );
	PossiblyEnabled[26].insert( 25 );

	PossiblyDisabled = vector< set<int> >(27);
	PossiblyDisabled[1].insert( 24 );
	{
		int PE[]= {4, 5, 14, 15, 21};
		PossiblyDisabled[3] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {3, 5, 14, 15, 21};
		PossiblyDisabled[4] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {3, 4, 14, 15, 16, 17, 18, 19, 20, 21, 24};
		PossiblyDisabled[5] = set<int>(PE,PE+11);
	}
	PossiblyDisabled[7].insert( 8 );
	PossiblyDisabled[8].insert( 7 );
	{
		int PE[]= {5, 6, 10, 11, 12};
		PossiblyDisabled[9] = set<int>(PE,PE+5);
	}
	PossiblyDisabled[13].insert( 21 );
	PossiblyDisabled[13].insert( 26 );
	{
		int PE[]= {3, 4, 5, 15, 21};
		PossiblyDisabled[14] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {3, 4, 5, 14, 21};
		PossiblyDisabled[15] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {16, 18, 19, 20, 21};
		PossiblyDisabled[17] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15};
		PossiblyDisabled[21] = set<int>(PE,PE+11);
	}
	PossiblyDisabled[22].insert( 23 );
	PossiblyDisabled[23].insert( 22 );
	PossiblyDisabled[24].insert( 1 );
	PossiblyDisabled[24].insert( 5 );
	PossiblyDisabled[26].insert( 13 );

	FreeMarkDepT = vector< set<int> >(27);

	Transition[0] = _trans(0,Timed,UNIFORM,0,1);
	Transition[1] = _trans(1,Timed,ERLANG,0,1);
	Transition[2] = _trans(2,Timed,UNIFORM,0,1);
	Transition[3] = _trans(3,Timed,DETERMINISTIC,0,1);
	Transition[4] = _trans(4,Timed,DETERMINISTIC,0,1);
	Transition[5] = _trans(5,Timed,DETERMINISTIC,0,1);
	Transition[6] = _trans(6,Timed,DETERMINISTIC,0,1);
	Transition[7] = _trans(7,Timed,DETERMINISTIC,0,1);
	Transition[8] = _trans(8,Timed,DETERMINISTIC,0,1);
	Transition[9] = _trans(9,Timed,DETERMINISTIC,0,1);
	Transition[10] = _trans(10,Timed,DETERMINISTIC,0,1);
	Transition[11] = _trans(11,Timed,DETERMINISTIC,0,1);
	Transition[12] = _trans(12,Timed,DETERMINISTIC,0,1);
	Transition[13] = _trans(13,Timed,LOGNORMAL,0,1);
	Transition[14] = _trans(14,Timed,DETERMINISTIC,0,1);
	Transition[15] = _trans(15,Timed,DETERMINISTIC,0,1);
	Transition[16] = _trans(16,Timed,DETERMINISTIC,0,1);
	Transition[17] = _trans(17,Timed,DETERMINISTIC,0,1);
	Transition[18] = _trans(18,Timed,DETERMINISTIC,0,1);
	Transition[19] = _trans(19,Timed,DETERMINISTIC,0,1);
	Transition[20] = _trans(20,Timed,DETERMINISTIC,0,1);
	Transition[21] = _trans(21,Timed,DETERMINISTIC,0,1);
	Transition[22] = _trans(22,Timed,DETERMINISTIC,0,1);
	Transition[23] = _trans(23,Timed,DETERMINISTIC,0,1);
	Transition[24] = _trans(24,Timed,LOGNORMAL,0,1);
	Transition[25] = _trans(25,Timed,UNIFORM,0,1);
	Transition[26] = _trans(26,Timed,ERLANG,0,1);
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 8:	//Mv1_1
    if (!(contains(Marking.P->_PL_Buffer1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Ready1 , 1))) return false;
    return true;

		break;
	case 25:	//Repair1
    if (!(contains(Marking.P->_PL_Down1 , 1))) return false;
    return true;

		break;
	case 2:	//Repair2
    if (!(contains(Marking.P->_PL_Down2 , 1))) return false;
    return true;

		break;
	case 9:	//Mv1_5
    if (!(contains(Marking.P->_PL_InConv1 , 1))) return false;
    if (Marking.P->_PL_Q1 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos1_4 , 1))) return false;
    return true;

		break;
	case 17:	//Mv2_5
    if (!(contains(Marking.P->_PL_InConv2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Pos2_4 , 1))) return false;
    if (Marking.P->_PL_Q2 >= 2) return false;
    return true;

		break;
	case 12:	//Mv1_2
    if (!(contains(Marking.P->_PL_Pos1_1 , 1))) return false;
    if (Marking.P->_PL_Q1 >= 2) return false;
    return true;

		break;
	case 18:	//Mv2_2
    if (!(contains(Marking.P->_PL_Pos2_1 , 1))) return false;
    if (Marking.P->_PL_Q2 >= 2) return false;
    return true;

		break;
	case 3:	//In1_2
    if (!(contains(Marking.P->_PL_Products , 1))) return false;
    if ( !((l1) < 1) ) 
        if (contains(Marking.P->_PL_InConv1 , (l1))) return false;
    return true;

		break;
	case 14:	//In2_2
    if (!(contains(Marking.P->_PL_Products , 1))) return false;
    if ( !((l2) < 1) ) 
        if (contains(Marking.P->_PL_InConv2 , (l2))) return false;
    return true;

		break;
	case 21:	//In2_1
    if (!(contains(Marking.P->_PL_Products , 1))) return false;
    if (!(contains(Marking.P->_PL_Q1 , 2))) return false;
    if (Marking.P->_PL_Q2 >= 2) return false;
    return true;

		break;
	case 5:	//In1_1
    if (!(contains(Marking.P->_PL_Products , 1))) return false;
    if (Marking.P->_PL_Q1 >= 2) return false;
    if (!(contains(Marking.P->_PL_Q2 , 2))) return false;
    return true;

		break;
	case 13:	//Serve1
    if (!(contains(Marking.P->_PL_Q1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Up1 , 1))) return false;
    return true;

		break;
	case 7:	//Finish_1
    if (!(contains(Marking.P->_PL_Ready1 , 1))) return false;
    return true;

		break;
	case 22:	//Mv2_1
    if (!(contains(Marking.P->_PL_Ready2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Buffer2 , 1))) return false;
    return true;

		break;
	case 23:	//Finish_2
    if (!(contains(Marking.P->_PL_Ready2 , 1))) return false;
    return true;

		break;
	case 26:	//Fail1
    if (!(contains(Marking.P->_PL_Up1 , 1))) return false;
    return true;

		break;
	case 24:	//Serve2
    if (!(contains(Marking.P->_PL_Up2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q2 , 1))) return false;
    return true;

		break;
	case 1:	//Fail2
    if (!(contains(Marking.P->_PL_Up2 , 1))) return false;
    return true;

		break;
	case 6:	//Start_1
    if (!(contains(Marking.P->_PL_Waiting1 , 1))) return false;
    if (Marking.P->_PL_Q1 >= 2) return false;
    return true;

		break;
	case 20:	//Start_2
    if (!(contains(Marking.P->_PL_Waiting2 , 1))) return false;
    if (Marking.P->_PL_Q2 >= 2) return false;
    return true;

		break;
	case 11:	//Mv1_3
    if (Marking.P->_PL_Q1 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos1_2 , 1))) return false;
    return true;

		break;
	case 10:	//Mv1_4
    if (Marking.P->_PL_Q1 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos1_3 , 1))) return false;
    return true;

		break;
	case 19:	//Mv2_3
    if (Marking.P->_PL_Q2 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos2_2 , 1))) return false;
    return true;

		break;
	case 16:	//Mv2_4
    if (Marking.P->_PL_Q2 >= 2) return false;
    if (!(contains(Marking.P->_PL_Pos2_3 , 1))) return false;
    return true;

		break;
	case 0:	//Arrive
    return true;

		break;
	default:	//In1_3,In2_3,
    if (!(contains(Marking.P->_PL_Products , 1))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b){
	lastTransition = t;
	switch(t){
		case 0: {  //Arrive
			Marking.P->_PL_Products += 1;
       break;
     } 
		case 1: {  //Fail2
			Marking.P->_PL_Down2 += 1;
			Marking.P->_PL_Up2 -= 1;
       break;
     } 
		case 2: {  //Repair2
			Marking.P->_PL_Down2 -= 1;
			Marking.P->_PL_Up2 += 1;
       break;
     } 
		case 3: {  //In1_2
			Marking.P->_PL_Products -= 1;
			Marking.P->_PL_InConv1 += 1;
			Marking.P->_PL_Buffer1 += 1;
       break;
     } 
		case 4: {  //In1_3
			Marking.P->_PL_Products -= 1;
			Marking.P->_PL_InConv1 += 1;
			Marking.P->_PL_Buffer1 += 1;
       break;
     } 
		case 5: {  //In1_1
			Marking.P->_PL_Products -= 1;
			Marking.P->_PL_InConv1 += 1;
			Marking.P->_PL_Buffer1 += 1;
			Marking.P->_PL_Q2 -= 2;
			Marking.P->_PL_Q2 += 2;
       break;
     } 
		case 6: {  //Start_1
			Marking.P->_PL_Ready1 += 1;
			Marking.P->_PL_Waiting1 -= 1;
       break;
     } 
		case 7: {  //Finish_1
			Marking.P->_PL_Ready1 -= 1;
			Marking.P->_PL_Waiting1 += 1;
       break;
     } 
		case 8: {  //Mv1_1
			Marking.P->_PL_Buffer1 -= 1;
			Marking.P->_PL_Pos1_1 += 1;
			Marking.P->_PL_Ready1 -= 1;
			Marking.P->_PL_Waiting1 += 1;
       break;
     } 
		case 9: {  //Mv1_5
			Marking.P->_PL_InConv1 -= 1;
			Marking.P->_PL_Q1 += 1;
			Marking.P->_PL_Pos1_4 -= 1;
       break;
     } 
		case 10: {  //Mv1_4
			Marking.P->_PL_Pos1_4 += 1;
			Marking.P->_PL_Pos1_3 -= 1;
       break;
     } 
		case 11: {  //Mv1_3
			Marking.P->_PL_Pos1_3 += 1;
			Marking.P->_PL_Pos1_2 -= 1;
       break;
     } 
		case 12: {  //Mv1_2
			Marking.P->_PL_Pos1_1 -= 1;
			Marking.P->_PL_Pos1_2 += 1;
       break;
     } 
		case 13: {  //Serve1
			Marking.P->_PL_Q1 -= 1;
			Marking.P->_PL_Up1 -= 1;
			Marking.P->_PL_Up1 += 1;
       break;
     } 
		case 14: {  //In2_2
			Marking.P->_PL_Products -= 1;
			Marking.P->_PL_InConv2 += 1;
			Marking.P->_PL_Buffer2 += 1;
       break;
     } 
		case 15: {  //In2_3
			Marking.P->_PL_Products -= 1;
			Marking.P->_PL_InConv2 += 1;
			Marking.P->_PL_Buffer2 += 1;
       break;
     } 
		case 16: {  //Mv2_4
			Marking.P->_PL_Pos2_4 += 1;
			Marking.P->_PL_Pos2_3 -= 1;
       break;
     } 
		case 17: {  //Mv2_5
			Marking.P->_PL_InConv2 -= 1;
			Marking.P->_PL_Pos2_4 -= 1;
			Marking.P->_PL_Q2 += 1;
       break;
     } 
		case 18: {  //Mv2_2
			Marking.P->_PL_Pos2_1 -= 1;
			Marking.P->_PL_Pos2_2 += 1;
       break;
     } 
		case 19: {  //Mv2_3
			Marking.P->_PL_Pos2_2 -= 1;
			Marking.P->_PL_Pos2_3 += 1;
       break;
     } 
		case 20: {  //Start_2
			Marking.P->_PL_Ready2 += 1;
			Marking.P->_PL_Waiting2 -= 1;
       break;
     } 
		case 21: {  //In2_1
			Marking.P->_PL_Products -= 1;
			Marking.P->_PL_Q1 -= 2;
			Marking.P->_PL_Q1 += 2;
			Marking.P->_PL_InConv2 += 1;
			Marking.P->_PL_Buffer2 += 1;
       break;
     } 
		case 22: {  //Mv2_1
			Marking.P->_PL_Ready2 -= 1;
			Marking.P->_PL_Waiting2 += 1;
			Marking.P->_PL_Buffer2 -= 1;
			Marking.P->_PL_Pos2_1 += 1;
       break;
     } 
		case 23: {  //Finish_2
			Marking.P->_PL_Ready2 -= 1;
			Marking.P->_PL_Waiting2 += 1;
       break;
     } 
		case 24: {  //Serve2
			Marking.P->_PL_Up2 -= 1;
			Marking.P->_PL_Up2 += 1;
			Marking.P->_PL_Q2 -= 1;
       break;
     } 
		case 25: {  //Repair1
			Marking.P->_PL_Up1 += 1;
			Marking.P->_PL_Down1 -= 1;
       break;
     } 
		case 26: {  //Fail1
			Marking.P->_PL_Up1 -= 1;
			Marking.P->_PL_Down1 += 1;
       break;
     } 
	}
}
void SPN::unfire(size_t t ,const abstractBinding& b){
}

const set<int>& SPN::PossiblyEn()const {
	return PossiblyEnabled[lastTransition];
}
const set<int>& SPN::PossiblyDis()const {
	return PossiblyDisabled[lastTransition];
}
const set<int>& SPN::FreeMarkingDependant()const {
	return FreeMarkDepT[lastTransition];
}
abstractBinding* SPN::nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum){
	switch(lastTransition*(tr+1) + targettr){
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum){
	switch(lastTransition*(tr+1) + targettr){
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(size_t t, const abstractBinding&)const {
switch (t){
	case 2:	//Repair2
	case 25:	//Repair1
	{
		ParamDistr[0]= ( double ) 30;
		ParamDistr[1]= ( double ) 50;
	}

		break;
	case 1:	//Fail2
	case 26:	//Fail1
	{
		ParamDistr[0]= ( double ) 4;
		ParamDistr[1]= ( double ) failrate;
	}

		break;
	case 6:	//Start_1
	case 9:	//Mv1_5
	case 10:	//Mv1_4
	case 11:	//Mv1_3
	case 12:	//Mv1_2
	case 16:	//Mv2_4
	case 17:	//Mv2_5
	case 18:	//Mv2_2
	case 19:	//Mv2_3
	case 20:	//Start_2
	{
		ParamDistr[0]= ( double ) Tunit;
	}

		break;
	case 0:	//Arrive
	{
		ParamDistr[0]= ( double ) alpha1;
		ParamDistr[1]= ( double ) alpha2;
	}

		break;
	case 13:	//Serve1
	{
		ParamDistr[0]= ( double ) mu1;
		ParamDistr[1]= ( double ) sigma1;
	}

		break;
	case 24:	//Serve2
	{
		ParamDistr[0]= ( double ) mu2;
		ParamDistr[1]= ( double ) sigma2;
	}

		break;
	default:	//In1_2,In1_3,In1_1,Finish_1,Mv1_1,In2_2,In2_3,In2_1,Mv2_1,Finish_2,
	{
		ParamDistr[0]= ( double ) 0;
	}

}
}

double SPN::GetPriority(size_t t)const {
switch (t){
	case 5:	//In1_1
	case 21:	//In2_1
		return (double)10;

		break;
	case 9:	//Mv1_5
	case 17:	//Mv2_5
		return (double)2;

		break;
	case 10:	//Mv1_4
	case 16:	//Mv2_4
		return (double)3;

		break;
	case 11:	//Mv1_3
	case 19:	//Mv2_3
		return (double)4;

		break;
	case 7:	//Finish_1
	case 12:	//Mv1_2
	case 18:	//Mv2_2
	case 23:	//Finish_2
		return (double)5;

		break;
	case 8:	//Mv1_1
	case 22:	//Mv2_1
		return (double)6;

		break;
	case 6:	//Start_1
	case 20:	//Start_2
		return (double)7;

		break;
	case 4:	//In1_3
	case 13:	//Serve1
	case 15:	//In2_3
	case 24:	//Serve2
		return (double)8;

		break;
	case 3:	//In1_2
	case 14:	//In2_2
		return (double)9;

		break;
	default:	//Arrive,Fail2,Repair2,Repair1,Fail1,
		return (double)1;

}
}

double SPN::GetWeight(size_t t)const{
		return (double)1;

}

void SPN::Msimple(){
	vector<int> tab;
	Msimpletab = tab;
}
void SPN::reset() {
	Marking.resetToInitMarking();
	TransitionConditions = initTransitionConditions;
}

