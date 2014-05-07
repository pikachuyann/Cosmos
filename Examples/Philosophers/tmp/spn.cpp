#include "spn.hpp"
#include <iomanip>
	const int _nb_Place_Think_p1=0;
	const int _nb_Place_Think_p2=1;
	const int _nb_Place_Think_p3=2;
	const int _nb_Place_Think_p4=3;
	const int _nb_Place_Think_p5=4;
	const int _nb_Place_Wait_p1=5;
	const int _nb_Place_Wait_p2=6;
	const int _nb_Place_Wait_p3=7;
	const int _nb_Place_Wait_p4=8;
	const int _nb_Place_Wait_p5=9;
	const int _nb_Place_Eat_p1=10;
	const int _nb_Place_Eat_p2=11;
	const int _nb_Place_Eat_p3=12;
	const int _nb_Place_Eat_p4=13;
	const int _nb_Place_Eat_p5=14;
	const int _nb_Place_Fork_p1=15;
	const int _nb_Place_Fork_p2=16;
	const int _nb_Place_Fork_p3=17;
	const int _nb_Place_Fork_p4=18;
	const int _nb_Place_Fork_p5=19;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_Think_p1 =1;
	P->_PL_Think_p2 =1;
	P->_PL_Think_p3 =1;
	P->_PL_Think_p4 =1;
	P->_PL_Think_p5 =1;
	P->_PL_Wait_p1 =0;
	P->_PL_Wait_p2 =0;
	P->_PL_Wait_p3 =0;
	P->_PL_Wait_p4 =0;
	P->_PL_Wait_p5 =0;
	P->_PL_Eat_p1 =0;
	P->_PL_Eat_p2 =0;
	P->_PL_Eat_p3 =0;
	P->_PL_Eat_p4 =0;
	P->_PL_Eat_p5 =0;
	P->_PL_Fork_p1 =1;
	P->_PL_Fork_p2 =1;
	P->_PL_Fork_p3 =1;
	P->_PL_Fork_p4 =1;
	P->_PL_Fork_p5 =1;
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
	s  << setw(13) << "Think_p1" << setw(13) << "Think_p2" << setw(13) << "Think_p3" << setw(13) << "Think_p4" << setw(13) << "Think_p5" << setw(13) << "Wait_p1" << setw(13) << "Wait_p2" << setw(13) << "Wait_p3" << setw(13) << "Wait_p4" << setw(13) << "Wait_p5" << setw(13) << "Eat_p1" << setw(13) << "Eat_p2" << setw(13) << "Eat_p3" << setw(13) << "Eat_p4" << setw(13) << "Eat_p5" << setw(13) << "Fork_p1" << setw(13) << "Fork_p2" << setw(13) << "Fork_p3" << setw(13) << "Fork_p4" << setw(13) << "Fork_p5";}

void abstractMarking::print(ostream &s)const{
	s << setw(13) << P->_PL_Think_p1;
	s << setw(13) << P->_PL_Think_p2;
	s << setw(13) << P->_PL_Think_p3;
	s << setw(13) << P->_PL_Think_p4;
	s << setw(13) << P->_PL_Think_p5;
	s << setw(13) << P->_PL_Wait_p1;
	s << setw(13) << P->_PL_Wait_p2;
	s << setw(13) << P->_PL_Wait_p3;
	s << setw(13) << P->_PL_Wait_p4;
	s << setw(13) << P->_PL_Wait_p5;
	s << setw(13) << P->_PL_Eat_p1;
	s << setw(13) << P->_PL_Eat_p2;
	s << setw(13) << P->_PL_Eat_p3;
	s << setw(13) << P->_PL_Eat_p4;
	s << setw(13) << P->_PL_Eat_p5;
	s << setw(13) << P->_PL_Fork_p1;
	s << setw(13) << P->_PL_Fork_p2;
	s << setw(13) << P->_PL_Fork_p3;
	s << setw(13) << P->_PL_Fork_p4;
	s << setw(13) << P->_PL_Fork_p5;
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_Think_p1;
		case 1: return P->_PL_Think_p2;
		case 2: return P->_PL_Think_p3;
		case 3: return P->_PL_Think_p4;
		case 4: return P->_PL_Think_p5;
		case 5: return P->_PL_Wait_p1;
		case 6: return P->_PL_Wait_p2;
		case 7: return P->_PL_Wait_p3;
		case 8: return P->_PL_Wait_p4;
		case 9: return P->_PL_Wait_p5;
		case 10: return P->_PL_Eat_p1;
		case 11: return P->_PL_Eat_p2;
		case 12: return P->_PL_Eat_p3;
		case 13: return P->_PL_Eat_p4;
		case 14: return P->_PL_Eat_p5;
		case 15: return P->_PL_Fork_p1;
		case 16: return P->_PL_Fork_p2;
		case 17: return P->_PL_Fork_p3;
		case 18: return P->_PL_Fork_p4;
		case 19: return P->_PL_Fork_p5;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(20);
	v[0] = P->_PL_Think_p1;
	v[1] = P->_PL_Think_p2;
	v[2] = P->_PL_Think_p3;
	v[3] = P->_PL_Think_p4;
	v[4] = P->_PL_Think_p5;
	v[5] = P->_PL_Wait_p1;
	v[6] = P->_PL_Wait_p2;
	v[7] = P->_PL_Wait_p3;
	v[8] = P->_PL_Wait_p4;
	v[9] = P->_PL_Wait_p5;
	v[10] = P->_PL_Eat_p1;
	v[11] = P->_PL_Eat_p2;
	v[12] = P->_PL_Eat_p3;
	v[13] = P->_PL_Eat_p4;
	v[14] = P->_PL_Eat_p5;
	v[15] = P->_PL_Fork_p1;
	v[16] = P->_PL_Fork_p2;
	v[17] = P->_PL_Fork_p3;
	v[18] = P->_PL_Fork_p4;
	v[19] = P->_PL_Fork_p5;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_Think_p1 = v[0];
	P->_PL_Think_p2 = v[1];
	P->_PL_Think_p3 = v[2];
	P->_PL_Think_p4 = v[3];
	P->_PL_Think_p5 = v[4];
	P->_PL_Wait_p1 = v[5];
	P->_PL_Wait_p2 = v[6];
	P->_PL_Wait_p3 = v[7];
	P->_PL_Wait_p4 = v[8];
	P->_PL_Wait_p5 = v[9];
	P->_PL_Eat_p1 = v[10];
	P->_PL_Eat_p2 = v[11];
	P->_PL_Eat_p3 = v[12];
	P->_PL_Eat_p4 = v[13];
	P->_PL_Eat_p5 = v[14];
	P->_PL_Fork_p1 = v[15];
	P->_PL_Fork_p2 = v[16];
	P->_PL_Fork_p3 = v[17];
	P->_PL_Fork_p4 = v[18];
	P->_PL_Fork_p5 = v[19];
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
pl(20), tr(15), Place(20),Transition(15),ParamDistr(3), TransitionConditions(15,0){
    Path ="testunfold.grml";
	PossiblyEnabled = vector< set<int> >(15);
	PossiblyEnabled[0].insert( 5 );
	PossiblyEnabled[1].insert( 6 );
	PossiblyEnabled[2].insert( 7 );
	PossiblyEnabled[3].insert( 8 );
	PossiblyEnabled[4].insert( 9 );
	PossiblyEnabled[5].insert( 10 );
	PossiblyEnabled[6].insert( 11 );
	PossiblyEnabled[7].insert( 12 );
	PossiblyEnabled[8].insert( 13 );
	PossiblyEnabled[9].insert( 14 );
	PossiblyEnabled[10].insert( 0 );
	PossiblyEnabled[10].insert( 5 );
	PossiblyEnabled[11].insert( 1 );
	PossiblyEnabled[11].insert( 6 );
	PossiblyEnabled[12].insert( 2 );
	PossiblyEnabled[12].insert( 7 );
	PossiblyEnabled[13].insert( 3 );
	PossiblyEnabled[13].insert( 8 );
	PossiblyEnabled[14].insert( 4 );
	PossiblyEnabled[14].insert( 9 );

	PossiblyDisabled = vector< set<int> >(15);
	PossiblyDisabled[0].insert( 5 );
	PossiblyDisabled[1].insert( 6 );
	PossiblyDisabled[2].insert( 7 );
	PossiblyDisabled[3].insert( 8 );
	PossiblyDisabled[4].insert( 9 );
	PossiblyDisabled[5].insert( 0 );
	PossiblyDisabled[6].insert( 1 );
	PossiblyDisabled[7].insert( 2 );
	PossiblyDisabled[8].insert( 3 );
	PossiblyDisabled[9].insert( 4 );

	FreeMarkDepT = vector< set<int> >(15);

    Place[0].label =" Think_p1";
    Place[0].isTraced = 1;
    Place[1].label =" Think_p2";
    Place[1].isTraced = 1;
    Place[2].label =" Think_p3";
    Place[2].isTraced = 1;
    Place[3].label =" Think_p4";
    Place[3].isTraced = 1;
    Place[4].label =" Think_p5";
    Place[4].isTraced = 1;
    Place[5].label =" Wait_p1";
    Place[5].isTraced = 1;
    Place[6].label =" Wait_p2";
    Place[6].isTraced = 1;
    Place[7].label =" Wait_p3";
    Place[7].isTraced = 1;
    Place[8].label =" Wait_p4";
    Place[8].isTraced = 1;
    Place[9].label =" Wait_p5";
    Place[9].isTraced = 1;
    Place[10].label =" Eat_p1";
    Place[10].isTraced = 1;
    Place[11].label =" Eat_p2";
    Place[11].isTraced = 1;
    Place[12].label =" Eat_p3";
    Place[12].isTraced = 1;
    Place[13].label =" Eat_p4";
    Place[13].isTraced = 1;
    Place[14].label =" Eat_p5";
    Place[14].isTraced = 1;
    Place[15].label =" Fork_p1";
    Place[15].isTraced = 1;
    Place[16].label =" Fork_p2";
    Place[16].isTraced = 1;
    Place[17].label =" Fork_p3";
    Place[17].isTraced = 1;
    Place[18].label =" Fork_p4";
    Place[18].isTraced = 1;
    Place[19].label =" Fork_p5";
    Place[19].isTraced = 1;
	Transition[0] = _trans(0,unTimed,DETERMINISTIC,0,1);
	Transition[0].label = "takeLeft_p1";
	Transition[0].priority = "1";
	Transition[0].weight = "1";
	Transition[1] = _trans(1,unTimed,DETERMINISTIC,0,1);
	Transition[1].label = "takeLeft_p2";
	Transition[1].priority = "1";
	Transition[1].weight = "1";
	Transition[2] = _trans(2,unTimed,DETERMINISTIC,0,1);
	Transition[2].label = "takeLeft_p3";
	Transition[2].priority = "1";
	Transition[2].weight = "1";
	Transition[3] = _trans(3,unTimed,DETERMINISTIC,0,1);
	Transition[3].label = "takeLeft_p4";
	Transition[3].priority = "1";
	Transition[3].weight = "1";
	Transition[4] = _trans(4,unTimed,DETERMINISTIC,0,1);
	Transition[4].label = "takeLeft_p5";
	Transition[4].priority = "1";
	Transition[4].weight = "1";
	Transition[5] = _trans(5,unTimed,DETERMINISTIC,0,1);
	Transition[5].label = "takeRight_p1";
	Transition[5].priority = "1";
	Transition[5].weight = "1";
	Transition[6] = _trans(6,unTimed,DETERMINISTIC,0,1);
	Transition[6].label = "takeRight_p2";
	Transition[6].priority = "1";
	Transition[6].weight = "1";
	Transition[7] = _trans(7,unTimed,DETERMINISTIC,0,1);
	Transition[7].label = "takeRight_p3";
	Transition[7].priority = "1";
	Transition[7].weight = "1";
	Transition[8] = _trans(8,unTimed,DETERMINISTIC,0,1);
	Transition[8].label = "takeRight_p4";
	Transition[8].priority = "1";
	Transition[8].weight = "1";
	Transition[9] = _trans(9,unTimed,DETERMINISTIC,0,1);
	Transition[9].label = "takeRight_p5";
	Transition[9].priority = "1";
	Transition[9].weight = "1";
	Transition[10] = _trans(10,unTimed,DETERMINISTIC,0,1);
	Transition[10].label = "backToThink_p1";
	Transition[10].priority = "1";
	Transition[10].weight = "1";
	Transition[11] = _trans(11,unTimed,DETERMINISTIC,0,1);
	Transition[11].label = "backToThink_p2";
	Transition[11].priority = "1";
	Transition[11].weight = "1";
	Transition[12] = _trans(12,unTimed,DETERMINISTIC,0,1);
	Transition[12].label = "backToThink_p3";
	Transition[12].priority = "1";
	Transition[12].weight = "1";
	Transition[13] = _trans(13,unTimed,DETERMINISTIC,0,1);
	Transition[13].label = "backToThink_p4";
	Transition[13].priority = "1";
	Transition[13].weight = "1";
	Transition[14] = _trans(14,unTimed,DETERMINISTIC,0,1);
	Transition[14].label = "backToThink_p5";
	Transition[14].priority = "1";
	Transition[14].weight = "1";
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 11:	//backToThink_p2
    if (!(contains(Marking.P->_PL_Eat_p2 , 1))) return false;
    return true;

		break;
	case 12:	//backToThink_p3
    if (!(contains(Marking.P->_PL_Eat_p3 , 1))) return false;
    return true;

		break;
	case 13:	//backToThink_p4
    if (!(contains(Marking.P->_PL_Eat_p4 , 1))) return false;
    return true;

		break;
	case 14:	//backToThink_p5
    if (!(contains(Marking.P->_PL_Eat_p5 , 1))) return false;
    return true;

		break;
	case 0:	//takeLeft_p1
    if (!(contains(Marking.P->_PL_Think_p1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p1 , 1))) return false;
    return true;

		break;
	case 1:	//takeLeft_p2
    if (!(contains(Marking.P->_PL_Think_p2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p2 , 1))) return false;
    return true;

		break;
	case 2:	//takeLeft_p3
    if (!(contains(Marking.P->_PL_Think_p3 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p3 , 1))) return false;
    return true;

		break;
	case 3:	//takeLeft_p4
    if (!(contains(Marking.P->_PL_Think_p4 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p4 , 1))) return false;
    return true;

		break;
	case 4:	//takeLeft_p5
    if (!(contains(Marking.P->_PL_Think_p5 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p5 , 1))) return false;
    return true;

		break;
	case 5:	//takeRight_p1
    if (!(contains(Marking.P->_PL_Wait_p1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p1 , 1))) return false;
    return true;

		break;
	case 6:	//takeRight_p2
    if (!(contains(Marking.P->_PL_Wait_p2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p2 , 1))) return false;
    return true;

		break;
	case 7:	//takeRight_p3
    if (!(contains(Marking.P->_PL_Wait_p3 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p3 , 1))) return false;
    return true;

		break;
	case 8:	//takeRight_p4
    if (!(contains(Marking.P->_PL_Wait_p4 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p4 , 1))) return false;
    return true;

		break;
	case 9:	//takeRight_p5
    if (!(contains(Marking.P->_PL_Wait_p5 , 1))) return false;
    if (!(contains(Marking.P->_PL_Fork_p5 , 1))) return false;
    return true;

		break;
	default:	//backToThink_p1,
    if (!(contains(Marking.P->_PL_Eat_p1 , 1))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b){
	lastTransition = t;
	switch(t){
		case 0: {  //takeLeft_p1
			Marking.P->_PL_Think_p1 -= 1;
			Marking.P->_PL_Wait_p1 += 1;
			Marking.P->_PL_Fork_p1 -= 1;
       break;
     } 
		case 1: {  //takeLeft_p2
			Marking.P->_PL_Think_p2 -= 1;
			Marking.P->_PL_Wait_p2 += 1;
			Marking.P->_PL_Fork_p2 -= 1;
       break;
     } 
		case 2: {  //takeLeft_p3
			Marking.P->_PL_Think_p3 -= 1;
			Marking.P->_PL_Wait_p3 += 1;
			Marking.P->_PL_Fork_p3 -= 1;
       break;
     } 
		case 3: {  //takeLeft_p4
			Marking.P->_PL_Think_p4 -= 1;
			Marking.P->_PL_Wait_p4 += 1;
			Marking.P->_PL_Fork_p4 -= 1;
       break;
     } 
		case 4: {  //takeLeft_p5
			Marking.P->_PL_Think_p5 -= 1;
			Marking.P->_PL_Wait_p5 += 1;
			Marking.P->_PL_Fork_p5 -= 1;
       break;
     } 
		case 5: {  //takeRight_p1
			Marking.P->_PL_Wait_p1 -= 1;
			Marking.P->_PL_Eat_p1 += 1;
			Marking.P->_PL_Fork_p1 -= 1;
       break;
     } 
		case 6: {  //takeRight_p2
			Marking.P->_PL_Wait_p2 -= 1;
			Marking.P->_PL_Eat_p2 += 1;
			Marking.P->_PL_Fork_p2 -= 1;
       break;
     } 
		case 7: {  //takeRight_p3
			Marking.P->_PL_Wait_p3 -= 1;
			Marking.P->_PL_Eat_p3 += 1;
			Marking.P->_PL_Fork_p3 -= 1;
       break;
     } 
		case 8: {  //takeRight_p4
			Marking.P->_PL_Wait_p4 -= 1;
			Marking.P->_PL_Eat_p4 += 1;
			Marking.P->_PL_Fork_p4 -= 1;
       break;
     } 
		case 9: {  //takeRight_p5
			Marking.P->_PL_Wait_p5 -= 1;
			Marking.P->_PL_Eat_p5 += 1;
			Marking.P->_PL_Fork_p5 -= 1;
       break;
     } 
		case 10: {  //backToThink_p1
			Marking.P->_PL_Think_p1 += 1;
			Marking.P->_PL_Eat_p1 -= 1;
			Marking.P->_PL_Fork_p1 += 1;
       break;
     } 
		case 11: {  //backToThink_p2
			Marking.P->_PL_Think_p2 += 1;
			Marking.P->_PL_Eat_p2 -= 1;
			Marking.P->_PL_Fork_p2 += 1;
       break;
     } 
		case 12: {  //backToThink_p3
			Marking.P->_PL_Think_p3 += 1;
			Marking.P->_PL_Eat_p3 -= 1;
			Marking.P->_PL_Fork_p3 += 1;
       break;
     } 
		case 13: {  //backToThink_p4
			Marking.P->_PL_Think_p4 += 1;
			Marking.P->_PL_Eat_p4 -= 1;
			Marking.P->_PL_Fork_p4 += 1;
       break;
     } 
		case 14: {  //backToThink_p5
			Marking.P->_PL_Think_p5 += 1;
			Marking.P->_PL_Eat_p5 -= 1;
			Marking.P->_PL_Fork_p5 += 1;
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

}

double SPN::GetPriority(size_t t)const {
		return (double)1;

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

