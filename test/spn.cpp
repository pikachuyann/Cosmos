#include "spn.hpp"
#include <iomanip>
	const double K=5;
	const double N=6;
	const double N2=3;
	const double Nm=5;
	const double ac=1;
	const double ac2=0.5;
	const double bc=10;
	const double cc=0.5;
	const int _nb_Place_Critic=0;
	const int _nb_Place_RE_p1=1;
	const int _nb_Place_RE_p4bis=2;
	const int _nb_Place_RE_p2=3;
	const int _nb_Place_RE_p3=4;
	const int _nb_Place_RE_p4=5;
	const int _nb_Place_RE_p5=6;
	const int _nb_Place_RE_p6=7;
	const int _nb_Place_bguard=8;
	const int _nb_Place_RE_p6bis=9;
	const int _nb_Place_RE_p1bis=10;
	const int _nb_Place_RE_p2bis=11;
	const int _nb_Place_Puit=12;
#include "lumpingfun.cpp"
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_Critic =1;
	P->_PL_RE_p1 =3;
	P->_PL_RE_p4bis =0;
	P->_PL_RE_p2 =0;
	P->_PL_RE_p3 =0;
	P->_PL_RE_p4 =0;
	P->_PL_RE_p5 =0;
	P->_PL_RE_p6 =0;
	P->_PL_bguard =0;
	P->_PL_RE_p6bis =0;
	P->_PL_RE_p1bis =3;
	P->_PL_RE_p2bis =0;
	P->_PL_Puit =0;
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
	s  << setw(13) << "Critic" << setw(13) << "RE_p1" << setw(13) << "RE_p4bis" << setw(13) << "RE_p2" << setw(13) << "RE_p3" << setw(13) << "RE_p4" << setw(13) << "RE_p5" << setw(13) << "RE_p6" << setw(13) << "bguard" << setw(13) << "RE_p6bis" << setw(13) << "RE_p1bis" << setw(13) << "RE_p2bis" << setw(13) << "Puit";}

void abstractMarking::print(ostream &s)const{
	s << setw(13) << P->_PL_Critic;
	s << setw(13) << P->_PL_RE_p1;
	s << setw(13) << P->_PL_RE_p4bis;
	s << setw(13) << P->_PL_RE_p2;
	s << setw(13) << P->_PL_RE_p3;
	s << setw(13) << P->_PL_RE_p4;
	s << setw(13) << P->_PL_RE_p5;
	s << setw(13) << P->_PL_RE_p6;
	s << setw(13) << P->_PL_bguard;
	s << setw(13) << P->_PL_RE_p6bis;
	s << setw(13) << P->_PL_RE_p1bis;
	s << setw(13) << P->_PL_RE_p2bis;
	s << setw(13) << P->_PL_Puit;
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_Critic;
		case 1: return P->_PL_RE_p1;
		case 2: return P->_PL_RE_p4bis;
		case 3: return P->_PL_RE_p2;
		case 4: return P->_PL_RE_p3;
		case 5: return P->_PL_RE_p4;
		case 6: return P->_PL_RE_p5;
		case 7: return P->_PL_RE_p6;
		case 8: return P->_PL_bguard;
		case 9: return P->_PL_RE_p6bis;
		case 10: return P->_PL_RE_p1bis;
		case 11: return P->_PL_RE_p2bis;
		case 12: return P->_PL_Puit;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(13);
	v[0] = P->_PL_Critic;
	v[1] = P->_PL_RE_p1;
	v[2] = P->_PL_RE_p4bis;
	v[3] = P->_PL_RE_p2;
	v[4] = P->_PL_RE_p3;
	v[5] = P->_PL_RE_p4;
	v[6] = P->_PL_RE_p5;
	v[7] = P->_PL_RE_p6;
	v[8] = P->_PL_bguard;
	v[9] = P->_PL_RE_p6bis;
	v[10] = P->_PL_RE_p1bis;
	v[11] = P->_PL_RE_p2bis;
	v[12] = P->_PL_Puit;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_Critic = v[0];
	P->_PL_RE_p1 = v[1];
	P->_PL_RE_p4bis = v[2];
	P->_PL_RE_p2 = v[3];
	P->_PL_RE_p3 = v[4];
	P->_PL_RE_p4 = v[5];
	P->_PL_RE_p5 = v[6];
	P->_PL_RE_p6 = v[7];
	P->_PL_bguard = v[8];
	P->_PL_RE_p6bis = v[9];
	P->_PL_RE_p1bis = v[10];
	P->_PL_RE_p2bis = v[11];
	P->_PL_Puit = v[12];
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
pl(13), tr(18), Transition(18),Place(13),ParamDistr(3), TransitionConditions(18,0){
    Path ="DatabaseInit3RE.grml";
	PossiblyEnabled = vector< set<int> >(18);
	{
		int PE[]= {1, 3, 4, 6, 9, 10, 13, 15};
		PossiblyEnabled[0] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {0, 3, 4, 6, 9, 10, 13, 15};
		PossiblyEnabled[1] = set<int>(PE,PE+8);
	}
	PossiblyEnabled[2].insert( 11 );
	PossiblyEnabled[2].insert( 12 );
	{
		int PE[]= {0, 1, 4, 6, 8, 9, 10, 13, 15};
		PossiblyEnabled[3] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 3, 6, 9, 10, 13, 15};
		PossiblyEnabled[4] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {0, 1, 3, 4, 8, 9, 10, 13, 15};
		PossiblyEnabled[6] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 6, 10};
		PossiblyEnabled[7] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {0, 3, 4, 6, 9};
		PossiblyEnabled[8] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {2, 10, 11, 12, 15};
		PossiblyEnabled[9] = set<int>(PE,PE+5);
	}
	PossiblyEnabled[10].insert( 7 );
	PossiblyEnabled[10].insert( 13 );
	PossiblyEnabled[11].insert( 5 );
	PossiblyEnabled[11].insert( 12 );
	PossiblyEnabled[12].insert( 11 );
	{
		int PE[]= {0, 1, 3, 4, 6, 9, 10, 15};
		PossiblyEnabled[13] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {3, 4, 15};
		PossiblyEnabled[14] = set<int>(PE,PE+3);
	}
	PossiblyEnabled[15].insert( 1 );
	PossiblyEnabled[15].insert( 14 );

	PossiblyDisabled = vector< set<int> >(18);
	{
		int PE[]= {1, 3, 4, 6, 9, 10, 13, 15};
		PossiblyDisabled[0] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {0, 3, 4, 6, 9, 10, 13, 14, 15};
		PossiblyDisabled[1] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 4, 6, 9, 10, 13, 15};
		PossiblyDisabled[3] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {0, 1, 3, 6, 9, 10, 13, 15};
		PossiblyDisabled[4] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {0, 1, 3, 4, 9, 10, 13, 15};
		PossiblyDisabled[6] = set<int>(PE,PE+8);
	}
	PossiblyDisabled[7].insert( 13 );
	{
		int PE[]= {0, 1, 3, 4, 6, 13};
		PossiblyDisabled[9] = set<int>(PE,PE+6);
	}
	PossiblyDisabled[10].insert( 0 );
	PossiblyDisabled[10].insert( 6 );
	PossiblyDisabled[11].insert( 12 );
	PossiblyDisabled[12].insert( 11 );
	{
		int PE[]= {0, 1, 3, 4, 6, 7, 9, 10, 15};
		PossiblyDisabled[13] = set<int>(PE,PE+9);
	}
	PossiblyDisabled[14].insert( 1 );
	PossiblyDisabled[15].insert( 3 );
	PossiblyDisabled[15].insert( 4 );

	FreeMarkDepT = vector< set<int> >(18);
	{
		int PE[]= {0, 2, 7, 8, 11, 12, 14, 16, 17};
		FreeMarkDepT[0] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {1, 2, 7, 8, 11, 12, 16, 17};
		FreeMarkDepT[1] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 13, 14, 15, 16, 17};
		FreeMarkDepT[2] = set<int>(PE,PE+15);
	}
	{
		int PE[]= {2, 3, 7, 11, 12, 14, 16, 17};
		FreeMarkDepT[3] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {2, 4, 7, 8, 11, 12, 14, 16, 17};
		FreeMarkDepT[4] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
		FreeMarkDepT[5] = set<int>(PE,PE+17);
	}
	{
		int PE[]= {2, 6, 7, 11, 12, 14, 16, 17};
		FreeMarkDepT[6] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {1, 2, 3, 4, 7, 8, 9, 11, 12, 14, 15, 16, 17};
		FreeMarkDepT[7] = set<int>(PE,PE+13);
	}
	{
		int PE[]= {1, 2, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17};
		FreeMarkDepT[8] = set<int>(PE,PE+12);
	}
	{
		int PE[]= {7, 8, 9, 14, 16, 17};
		FreeMarkDepT[9] = set<int>(PE,PE+6);
	}
	{
		int PE[]= {1, 2, 3, 4, 8, 9, 10, 11, 12, 14, 15, 16, 17};
		FreeMarkDepT[10] = set<int>(PE,PE+13);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
		FreeMarkDepT[11] = set<int>(PE,PE+16);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17};
		FreeMarkDepT[12] = set<int>(PE,PE+16);
	}
	{
		int PE[]= {2, 8, 11, 12, 13, 14, 16, 17};
		FreeMarkDepT[13] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {0, 2, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17};
		FreeMarkDepT[14] = set<int>(PE,PE+13);
	}
	{
		int PE[]= {0, 2, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17};
		FreeMarkDepT[15] = set<int>(PE,PE+13);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
		FreeMarkDepT[16] = set<int>(PE,PE+17);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
		FreeMarkDepT[17] = set<int>(PE,PE+17);
	}

    Place[0].label =" Critic";
    Place[0].isTraced = 1;
    Place[1].label =" RE_p1";
    Place[1].isTraced = 1;
    Place[2].label =" RE_p4bis";
    Place[2].isTraced = 1;
    Place[3].label =" RE_p2";
    Place[3].isTraced = 1;
    Place[4].label =" RE_p3";
    Place[4].isTraced = 1;
    Place[5].label =" RE_p4";
    Place[5].isTraced = 1;
    Place[6].label =" RE_p5";
    Place[6].isTraced = 1;
    Place[7].label =" RE_p6";
    Place[7].isTraced = 1;
    Place[8].label =" bguard";
    Place[8].isTraced = 1;
    Place[9].label =" RE_p6bis";
    Place[9].isTraced = 1;
    Place[10].label =" RE_p1bis";
    Place[10].isTraced = 1;
    Place[11].label =" RE_p2bis";
    Place[11].isTraced = 1;
    Place[12].label =" Puit";
    Place[12].isTraced = 1;
	Transition[0] = _trans(0,Timed,EXPONENTIAL,1,1);
	Transition[0].label = "b24";
	Transition[1] = _trans(1,Timed,EXPONENTIAL,1,1);
	Transition[1].label = "b12bis";
	Transition[2] = _trans(2,Timed,EXPONENTIAL,1,1);
	Transition[2].label = "a45bis";
	Transition[3] = _trans(3,Timed,EXPONENTIAL,1,1);
	Transition[3].label = "a23bis";
	Transition[4] = _trans(4,Timed,EXPONENTIAL,1,1);
	Transition[4].label = "b24bis";
	Transition[5] = _trans(5,Timed,EXPONENTIAL,0,1);
	Transition[5].label = "sl";
	Transition[6] = _trans(6,Timed,EXPONENTIAL,1,1);
	Transition[6].label = "a23";
	Transition[7] = _trans(7,Timed,EXPONENTIAL,1,1);
	Transition[7].label = "a12";
	Transition[8] = _trans(8,Timed,EXPONENTIAL,1,1);
	Transition[8].label = "b34";
	Transition[9] = _trans(9,Timed,EXPONENTIAL,1,1);
	Transition[9].label = "a45";
	Transition[10] = _trans(10,Timed,EXPONENTIAL,1,1);
	Transition[10].label = "c";
	Transition[11] = _trans(11,Timed,EXPONENTIAL,1,1);
	Transition[11].label = "a56bis";
	Transition[12] = _trans(12,Timed,EXPONENTIAL,1,1);
	Transition[12].label = "a56";
	Transition[13] = _trans(13,Timed,EXPONENTIAL,1,1);
	Transition[13].label = "b12";
	Transition[14] = _trans(14,Timed,EXPONENTIAL,1,1);
	Transition[14].label = "A12bis";
	Transition[15] = _trans(15,Timed,EXPONENTIAL,1,1);
	Transition[15].label = "cbis";
	Transition[16] = _trans(16,Timed,EXPONENTIAL,1,1);
	Transition[16].label = "selfloop";
	Transition[17] = _trans(17,Timed,EXPONENTIAL,1,1);
	Transition[17].label = "Puittrans";
    Msimple();
vector <double> Rate_Table_init (tr);
Rate_Table = Rate_Table_init;
Origine_Rate_Table = Rate_Table_init;
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 9:	//a45
    if ( !(N  < 1)) 
        if (!(contains(Marking.P->_PL_RE_p4 , N ))) return false;
    if ( !( Marking.P->_PL_bguard  < 1)) 
        if (!(contains(Marking.P->_PL_bguard ,  Marking.P->_PL_bguard ))) return false;
    return true;

		break;
	case 3:	//a23bis
    if (!(contains(Marking.P->_PL_Critic , 1))) return false;
    if ( !( Marking.P->_PL_bguard  < 1)) 
        if (!(contains(Marking.P->_PL_bguard ,  Marking.P->_PL_bguard ))) return false;
    if (!(contains(Marking.P->_PL_RE_p2bis , 1))) return false;
    return true;

		break;
	case 6:	//a23
    if (!(contains(Marking.P->_PL_Critic , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_p2 , 1))) return false;
    if ( !( Marking.P->_PL_bguard  < 1)) 
        if (!(contains(Marking.P->_PL_bguard ,  Marking.P->_PL_bguard ))) return false;
    return true;

		break;
	case 0:	//b24
    if (!(contains(Marking.P->_PL_Critic , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_p2 , 1))) return false;
    if (!(contains(Marking.P->_PL_bguard , 1))) return false;
    return true;

		break;
	case 4:	//b24bis
    if (!(contains(Marking.P->_PL_Critic , 1))) return false;
    if (!(contains(Marking.P->_PL_bguard , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_p2bis , 1))) return false;
    return true;

		break;
	case 13:	//b12
    if (!(contains(Marking.P->_PL_RE_p1 , 1))) return false;
    if (!(contains(Marking.P->_PL_bguard , 1))) return false;
    return true;

		break;
	case 7:	//a12
    if (!(contains(Marking.P->_PL_RE_p1 , 1))) return false;
    return true;

		break;
	case 14:	//A12bis
    if (!(contains(Marking.P->_PL_RE_p1bis , 1))) return false;
    return true;

		break;
	case 10:	//c
    if (!(contains(Marking.P->_PL_RE_p2 , 1))) return false;
    if (Marking.P->_PL_bguard >= 1) return false;
    return true;

		break;
	case 8:	//b34
    if (!(contains(Marking.P->_PL_RE_p3 , 1))) return false;
    return true;

		break;
	case 2:	//a45bis
    if (!(contains(Marking.P->_PL_RE_p4bis , 1))) return false;
    return true;

		break;
	case 12:	//a56
    if (!(contains(Marking.P->_PL_RE_p5 , 1))) return false;
    if ( !(Nm  < 1) ) 
        if (contains(Marking.P->_PL_RE_p6 , Nm )) return false;
    return true;

		break;
	case 11:	//a56bis
    if (!(contains(Marking.P->_PL_RE_p5 , 1))) return false;
    if ( !(Nm  < 1)) 
        if (!(contains(Marking.P->_PL_RE_p6 , Nm ))) return false;
    return true;

		break;
	case 5:	//sl
    if (!(contains(Marking.P->_PL_RE_p6bis , 1))) return false;
    return true;

		break;
	case 1:	//b12bis
    if (!(contains(Marking.P->_PL_bguard , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_p1bis , 1))) return false;
    return true;

		break;
	case 15:	//cbis
    if (Marking.P->_PL_bguard >= 1) return false;
    if (!(contains(Marking.P->_PL_RE_p2bis , 1))) return false;
    return true;

		break;
	default:	//selfloop,Puittrans,
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b){
	lastTransition = t;
	switch(t){
		case 0: {  //b24
			Marking.P->_PL_Critic -= 1;
			Marking.P->_PL_Critic += 1;
			Marking.P->_PL_RE_p2 -= 1;
			Marking.P->_PL_RE_p4 += 1;
			Marking.P->_PL_bguard -= 1;
			Marking.P->_PL_bguard += 1;
       break;
     } 
		case 1: {  //b12bis
			Marking.P->_PL_bguard -= 1;
			Marking.P->_PL_bguard += 1;
			Marking.P->_PL_RE_p1bis -= 1;
			Marking.P->_PL_RE_p2bis += 1;
       break;
     } 
		case 2: {  //a45bis
			Marking.P->_PL_RE_p4bis -= 1;
			Marking.P->_PL_RE_p5 += 1;
       break;
     } 
		case 3: {  //a23bis
			int tmpMark_bguard = Marking.P->_PL_bguard;
			Marking.P->_PL_Critic -= 1;
			Marking.P->_PL_RE_p3 += 1;
			Marking.P->_PL_bguard -=  tmpMark_bguard ;
			Marking.P->_PL_bguard += 1;
			Marking.P->_PL_RE_p2bis -= 1;
       break;
     } 
		case 4: {  //b24bis
			Marking.P->_PL_Critic -= 1;
			Marking.P->_PL_Critic += 1;
			Marking.P->_PL_RE_p4 += 1;
			Marking.P->_PL_bguard -= 1;
			Marking.P->_PL_bguard += 1;
			Marking.P->_PL_RE_p2bis -= 1;
       break;
     } 
		case 5: {  //sl
			Marking.P->_PL_RE_p6bis -= 1;
			Marking.P->_PL_RE_p6bis += 1;
       break;
     } 
		case 6: {  //a23
			int tmpMark_bguard = Marking.P->_PL_bguard;
			Marking.P->_PL_Critic -= 1;
			Marking.P->_PL_RE_p2 -= 1;
			Marking.P->_PL_RE_p3 += 1;
			Marking.P->_PL_bguard -=  tmpMark_bguard ;
			Marking.P->_PL_bguard += 1;
       break;
     } 
		case 7: {  //a12
			Marking.P->_PL_RE_p1 -= 1;
			Marking.P->_PL_RE_p2 += 1;
       break;
     } 
		case 8: {  //b34
			Marking.P->_PL_Critic += 1;
			Marking.P->_PL_RE_p3 -= 1;
			Marking.P->_PL_RE_p4 += 1;
       break;
     } 
		case 9: {  //a45
			int tmpMark_RE_p4bis = Marking.P->_PL_RE_p4bis;
			int tmpMark_RE_p4 = Marking.P->_PL_RE_p4;
			int tmpMark_bguard = Marking.P->_PL_bguard;
			Marking.P->_PL_RE_p4bis += Nm ;
			Marking.P->_PL_RE_p4 -= N ;
			Marking.P->_PL_RE_p5 += 1;
			Marking.P->_PL_bguard -=  tmpMark_bguard ;
       break;
     } 
		case 10: {  //c
			Marking.P->_PL_RE_p1 += 1;
			Marking.P->_PL_RE_p2 -= 1;
       break;
     } 
		case 11: {  //a56bis
			int tmpMark_RE_p6 = Marking.P->_PL_RE_p6;
			int tmpMark_RE_p6bis = Marking.P->_PL_RE_p6bis;
			Marking.P->_PL_RE_p5 -= 1;
			Marking.P->_PL_RE_p6 -= Nm ;
			Marking.P->_PL_RE_p6bis += N ;
       break;
     } 
		case 12: {  //a56
			Marking.P->_PL_RE_p5 -= 1;
			Marking.P->_PL_RE_p6 += 1;
       break;
     } 
		case 13: {  //b12
			Marking.P->_PL_RE_p1 -= 1;
			Marking.P->_PL_RE_p2 += 1;
			Marking.P->_PL_bguard -= 1;
			Marking.P->_PL_bguard += 1;
       break;
     } 
		case 14: {  //A12bis
			Marking.P->_PL_RE_p1bis -= 1;
			Marking.P->_PL_RE_p2bis += 1;
       break;
     } 
		case 15: {  //cbis
			Marking.P->_PL_RE_p1bis += 1;
			Marking.P->_PL_RE_p2bis -= 1;
       break;
     } 
		case 16: {  //selfloop
       break;
     } 
		case 17: {  //Puittrans
			Marking.P->_PL_Puit += 1;
       break;
     } 
	}
}
void SPN::unfire(size_t t ,const abstractBinding& b){
switch (t){
	case 0:	//b24
    Marking.P->_PL_Critic += 1;
    Marking.P->_PL_Critic -= 1;
    Marking.P->_PL_RE_p2 += 1;
    Marking.P->_PL_RE_p4 -= 1;
    Marking.P->_PL_bguard += 1;
    Marking.P->_PL_bguard -= 1;

		break;
	case 4:	//b24bis
    Marking.P->_PL_Critic += 1;
    Marking.P->_PL_Critic -= 1;
    Marking.P->_PL_RE_p4 -= 1;
    Marking.P->_PL_bguard += 1;
    Marking.P->_PL_bguard -= 1;
    Marking.P->_PL_RE_p2bis += 1;

		break;
	case 6:	//a23
    Marking.P->_PL_Critic += 1;
    Marking.P->_PL_RE_p2 += 1;
    Marking.P->_PL_RE_p3 -= 1;
    Marking.P->_PL_bguard +=  Marking.P->_PL_bguard ;
    Marking.P->_PL_bguard -= 1;

		break;
	case 3:	//a23bis
    Marking.P->_PL_Critic += 1;
    Marking.P->_PL_RE_p3 -= 1;
    Marking.P->_PL_bguard +=  Marking.P->_PL_bguard ;
    Marking.P->_PL_bguard -= 1;
    Marking.P->_PL_RE_p2bis += 1;

		break;
	case 8:	//b34
    Marking.P->_PL_Critic -= 1;
    Marking.P->_PL_RE_p3 += 1;
    Marking.P->_PL_RE_p4 -= 1;

		break;
	case 17:	//Puittrans
    Marking.P->_PL_Puit -= 1;

		break;
	case 7:	//a12
    Marking.P->_PL_RE_p1 += 1;
    Marking.P->_PL_RE_p2 -= 1;

		break;
	case 13:	//b12
    Marking.P->_PL_RE_p1 += 1;
    Marking.P->_PL_RE_p2 -= 1;
    Marking.P->_PL_bguard += 1;
    Marking.P->_PL_bguard -= 1;

		break;
	case 10:	//c
    Marking.P->_PL_RE_p1 -= 1;
    Marking.P->_PL_RE_p2 += 1;

		break;
	case 14:	//A12bis
    Marking.P->_PL_RE_p1bis += 1;
    Marking.P->_PL_RE_p2bis -= 1;

		break;
	case 15:	//cbis
    Marking.P->_PL_RE_p1bis -= 1;
    Marking.P->_PL_RE_p2bis += 1;

		break;
	case 2:	//a45bis
    Marking.P->_PL_RE_p4bis += 1;
    Marking.P->_PL_RE_p5 -= 1;

		break;
	case 9:	//a45
    Marking.P->_PL_RE_p4bis -= Nm ;
    Marking.P->_PL_RE_p4 += N ;
    Marking.P->_PL_RE_p5 -= 1;
    Marking.P->_PL_bguard +=  Marking.P->_PL_bguard ;

		break;
	case 11:	//a56bis
    Marking.P->_PL_RE_p5 += 1;
    Marking.P->_PL_RE_p6 += Nm ;
    Marking.P->_PL_RE_p6bis -= N ;

		break;
	case 12:	//a56
    Marking.P->_PL_RE_p5 += 1;
    Marking.P->_PL_RE_p6 -= 1;

		break;
	case 5:	//sl
    Marking.P->_PL_RE_p6bis += 1;
    Marking.P->_PL_RE_p6bis -= 1;

		break;
	case 1:	//b12bis
    Marking.P->_PL_bguard += 1;
    Marking.P->_PL_bguard -= 1;
    Marking.P->_PL_RE_p1bis += 1;
    Marking.P->_PL_RE_p2bis -= 1;

		break;
}
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
	case 1:	//b12bis
	{
		ParamDistr[0]= ( double )  ( Marking.P->_PL_RE_p1bis  * bc ) ;
	}

		break;
	case 7:	//a12
	{
		ParamDistr[0]= ( double )  (ac  *  Marking.P->_PL_RE_p1 ) ;
	}

		break;
	case 6:	//a23
	{
		ParamDistr[0]= ( double )  (ac  *  Marking.P->_PL_RE_p2 ) ;
	}

		break;
	case 3:	//a23bis
	{
		ParamDistr[0]= ( double )  (ac  *  Marking.P->_PL_RE_p2bis ) ;
	}

		break;
	case 9:	//a45
	{
		ParamDistr[0]= ( double )  (ac  *  Marking.P->_PL_RE_p4 ) ;
	}

		break;
	case 2:	//a45bis
	{
		ParamDistr[0]= ( double )  (ac  *  Marking.P->_PL_RE_p4bis ) ;
	}

		break;
	case 14:	//A12bis
	{
		ParamDistr[0]= ( double )  (ac2  *  Marking.P->_PL_RE_p1bis ) ;
	}

		break;
	case 13:	//b12
	{
		ParamDistr[0]= ( double )  (bc  *  Marking.P->_PL_RE_p1 ) ;
	}

		break;
	case 0:	//b24
	{
		ParamDistr[0]= ( double )  (bc  *  Marking.P->_PL_RE_p2 ) ;
	}

		break;
	case 4:	//b24bis
	{
		ParamDistr[0]= ( double )  (bc  *  Marking.P->_PL_RE_p2bis ) ;
	}

		break;
	case 8:	//b34
	{
		ParamDistr[0]= ( double )  (bc  *  Marking.P->_PL_RE_p3 ) ;
	}

		break;
	case 10:	//c
	{
		ParamDistr[0]= ( double )  (cc  *  Marking.P->_PL_RE_p2 ) ;
	}

		break;
	case 15:	//cbis
	{
		ParamDistr[0]= ( double )  (cc  *  Marking.P->_PL_RE_p2bis ) ;
	}

		break;
	case 16:	//selfloop
	case 17:	//Puittrans
	{
		ParamDistr[0]= ( double ) 0 ;
	}

		break;
	case 5:	//sl
	{
		ParamDistr[0]= ( double ) 1 ;
	}

		break;
	default:	//a56bis,a56,
	{
		ParamDistr[0]= ( double )  (ac  *  Marking.P->_PL_RE_p5 ) ;
	}

}
}

double SPN::GetPriority(size_t t)const {
		return (double)1 ;

}

double SPN::GetWeight(size_t t)const{
		return (double)1 ;

}

void SPN::Msimple(){
	vector<int> tab;
		tab.push_back(1);
		tab.push_back(2);
		tab.push_back(3);
		tab.push_back(4);
		tab.push_back(5);
		tab.push_back(6);
		tab.push_back(7);
		tab.push_back(9);
		tab.push_back(10);
		tab.push_back(11);
	Msimpletab = tab;
}
void SPN::reset() {
	Marking.resetToInitMarking();
	TransitionConditions = initTransitionConditions;
}

