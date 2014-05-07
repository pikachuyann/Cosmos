#include "spn.hpp"
#include <iomanip>
	const int _nb_Place_Server_1=0;
	const int _nb_Place_Q1_Idle=1;
	const int _nb_Place_Q1_wait=2;
	const int _nb_Place_Server_2=3;
	const int _nb_Place_Q2_Idle=4;
	const int _nb_Place_Q2_wait=5;
	const int _nb_Place_Server_3=6;
	const int _nb_Place_Q3_Idle=7;
	const int _nb_Place_Q3_wait=8;
	const int _nb_Place_Server_4=9;
	const int _nb_Place_Q4_Idle=10;
	const int _nb_Place_Q4_wait=11;
	const int _nb_Place_Action_0=12;
	const int _nb_Place_Action_1=13;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_Server_1 =1;
	P->_PL_Q1_Idle =1;
	P->_PL_Q1_wait =0;
	P->_PL_Server_2 =0;
	P->_PL_Q2_Idle =1;
	P->_PL_Q2_wait =0;
	P->_PL_Server_3 =0;
	P->_PL_Q3_Idle =1;
	P->_PL_Q3_wait =0;
	P->_PL_Server_4 =0;
	P->_PL_Q4_Idle =1;
	P->_PL_Q4_wait =0;
	P->_PL_Action_0 =1;
	P->_PL_Action_1 =0;
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
		case 0: return P->_PL_Server_1;
		case 1: return P->_PL_Q1_Idle;
		case 2: return P->_PL_Q1_wait;
		case 3: return P->_PL_Server_2;
		case 4: return P->_PL_Q2_Idle;
		case 5: return P->_PL_Q2_wait;
		case 6: return P->_PL_Server_3;
		case 7: return P->_PL_Q3_Idle;
		case 8: return P->_PL_Q3_wait;
		case 9: return P->_PL_Server_4;
		case 10: return P->_PL_Q4_Idle;
		case 11: return P->_PL_Q4_wait;
		case 12: return P->_PL_Action_0;
		case 13: return P->_PL_Action_1;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(14);
	v[0] = P->_PL_Server_1;
	v[1] = P->_PL_Q1_Idle;
	v[2] = P->_PL_Q1_wait;
	v[3] = P->_PL_Server_2;
	v[4] = P->_PL_Q2_Idle;
	v[5] = P->_PL_Q2_wait;
	v[6] = P->_PL_Server_3;
	v[7] = P->_PL_Q3_Idle;
	v[8] = P->_PL_Q3_wait;
	v[9] = P->_PL_Server_4;
	v[10] = P->_PL_Q4_Idle;
	v[11] = P->_PL_Q4_wait;
	v[12] = P->_PL_Action_0;
	v[13] = P->_PL_Action_1;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_Server_1 = v[0];
	P->_PL_Q1_Idle = v[1];
	P->_PL_Q1_wait = v[2];
	P->_PL_Server_2 = v[3];
	P->_PL_Q2_Idle = v[4];
	P->_PL_Q2_wait = v[5];
	P->_PL_Server_3 = v[6];
	P->_PL_Q3_Idle = v[7];
	P->_PL_Q3_wait = v[8];
	P->_PL_Server_4 = v[9];
	P->_PL_Q4_Idle = v[10];
	P->_PL_Q4_wait = v[11];
	P->_PL_Action_0 = v[12];
	P->_PL_Action_1 = v[13];
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
pl(14), tr(16), Place(14),Transition(16),ParamDistr(3), TransitionConditions(16,0){
    Path ="ps.gspn";
	PossiblyEnabled = vector< set<int> >(16);
	{
		int PE[]= {1, 3, 4, 5, 6, 8, 9, 12, 13};
		PossiblyEnabled[0] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 2, 6, 10, 14};
		PossiblyEnabled[1] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {0, 1, 3, 4, 5, 6, 8, 9, 12, 13};
		PossiblyEnabled[2] = set<int>(PE,PE+10);
	}
	PossiblyEnabled[3].insert( 1 );
	PossiblyEnabled[3].insert( 2 );
	{
		int PE[]= {0, 1, 5, 7, 8, 9, 10, 12, 13};
		PossiblyEnabled[4] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {2, 4, 6, 10, 14};
		PossiblyEnabled[5] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {0, 1, 4, 5, 7, 8, 9, 10, 12, 13};
		PossiblyEnabled[6] = set<int>(PE,PE+10);
	}
	PossiblyEnabled[7].insert( 5 );
	PossiblyEnabled[7].insert( 6 );
	{
		int PE[]= {0, 1, 4, 5, 9, 11, 12, 13, 14};
		PossiblyEnabled[8] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {2, 6, 8, 10, 14};
		PossiblyEnabled[9] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {0, 1, 4, 5, 8, 9, 11, 12, 13, 14};
		PossiblyEnabled[10] = set<int>(PE,PE+10);
	}
	PossiblyEnabled[11].insert( 9 );
	PossiblyEnabled[11].insert( 10 );
	{
		int PE[]= {0, 1, 2, 4, 5, 8, 9, 13, 15};
		PossiblyEnabled[12] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {2, 6, 10, 12, 14};
		PossiblyEnabled[13] = set<int>(PE,PE+5);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 8, 9, 12, 13, 15};
		PossiblyEnabled[14] = set<int>(PE,PE+10);
	}
	PossiblyEnabled[15].insert( 13 );
	PossiblyEnabled[15].insert( 14 );

	PossiblyDisabled = vector< set<int> >(16);
	{
		int PE[]= {1, 2, 3, 4, 5, 8, 9, 12, 13};
		PossiblyDisabled[0] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 2, 4, 5, 8, 9, 12, 13};
		PossiblyDisabled[1] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {0, 1, 6, 10, 14};
		PossiblyDisabled[2] = set<int>(PE,PE+5);
	}
	PossiblyDisabled[3].insert( 0 );
	{
		int PE[]= {0, 1, 5, 6, 7, 8, 9, 12, 13};
		PossiblyDisabled[4] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 4, 6, 8, 9, 12, 13};
		PossiblyDisabled[5] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {2, 4, 5, 10, 14};
		PossiblyDisabled[6] = set<int>(PE,PE+5);
	}
	PossiblyDisabled[7].insert( 4 );
	{
		int PE[]= {0, 1, 4, 5, 9, 10, 11, 12, 13};
		PossiblyDisabled[8] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 4, 5, 8, 10, 12, 13};
		PossiblyDisabled[9] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {2, 6, 8, 9, 14};
		PossiblyDisabled[10] = set<int>(PE,PE+5);
	}
	PossiblyDisabled[11].insert( 8 );
	{
		int PE[]= {0, 1, 4, 5, 8, 9, 13, 14, 15};
		PossiblyDisabled[12] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 4, 5, 8, 9, 12, 14};
		PossiblyDisabled[13] = set<int>(PE,PE+8);
	}
	{
		int PE[]= {2, 6, 10, 12, 13};
		PossiblyDisabled[14] = set<int>(PE,PE+5);
	}
	PossiblyDisabled[15].insert( 12 );

	FreeMarkDepT = vector< set<int> >(16);

	Transition[0] = _trans(0,Timed,EXPONENTIAL,0,1);
	Transition[1] = _trans(1,Timed,EXPONENTIAL,0,1);
	Transition[2] = _trans(2,Timed,EXPONENTIAL,0,1);
	Transition[3] = _trans(3,Timed,EXPONENTIAL,0,1);
	Transition[4] = _trans(4,Timed,EXPONENTIAL,0,1);
	Transition[5] = _trans(5,Timed,EXPONENTIAL,0,1);
	Transition[6] = _trans(6,Timed,EXPONENTIAL,0,1);
	Transition[7] = _trans(7,Timed,EXPONENTIAL,0,1);
	Transition[8] = _trans(8,Timed,EXPONENTIAL,0,1);
	Transition[9] = _trans(9,Timed,EXPONENTIAL,0,1);
	Transition[10] = _trans(10,Timed,EXPONENTIAL,0,1);
	Transition[11] = _trans(11,Timed,EXPONENTIAL,0,1);
	Transition[12] = _trans(12,Timed,EXPONENTIAL,0,1);
	Transition[13] = _trans(13,Timed,EXPONENTIAL,0,1);
	Transition[14] = _trans(14,Timed,EXPONENTIAL,0,1);
	Transition[15] = _trans(15,Timed,EXPONENTIAL,0,1);
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 7:	//request2
    if (!(contains(Marking.P->_PL_Q2_Idle , 1))) return false;
    return true;

		break;
	case 11:	//request3
    if (!(contains(Marking.P->_PL_Q3_Idle , 1))) return false;
    return true;

		break;
	case 15:	//request4
    if (!(contains(Marking.P->_PL_Q4_Idle , 1))) return false;
    return true;

		break;
	case 0:	//Loop1a
    if (!(contains(Marking.P->_PL_Server_1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q1_Idle , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_0 , 1))) return false;
    return true;

		break;
	case 1:	//Loop1b
    if (!(contains(Marking.P->_PL_Server_1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q1_wait , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_0 , 1))) return false;
    return true;

		break;
	case 2:	//serve1
    if (!(contains(Marking.P->_PL_Server_1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q1_wait , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_1 , 1))) return false;
    return true;

		break;
	case 4:	//Loop2a
    if (!(contains(Marking.P->_PL_Server_2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q2_Idle , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_0 , 1))) return false;
    return true;

		break;
	case 5:	//Loop2b
    if (!(contains(Marking.P->_PL_Server_2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q2_wait , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_0 , 1))) return false;
    return true;

		break;
	case 6:	//serve2
    if (!(contains(Marking.P->_PL_Server_2 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q2_wait , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_1 , 1))) return false;
    return true;

		break;
	case 8:	//Loop3a
    if (!(contains(Marking.P->_PL_Server_3 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q3_Idle , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_0 , 1))) return false;
    return true;

		break;
	case 9:	//Loop3b
    if (!(contains(Marking.P->_PL_Server_3 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q3_wait , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_0 , 1))) return false;
    return true;

		break;
	case 10:	//serve3
    if (!(contains(Marking.P->_PL_Server_3 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q3_wait , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_1 , 1))) return false;
    return true;

		break;
	case 12:	//Loop4a
    if (!(contains(Marking.P->_PL_Server_4 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q4_Idle , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_0 , 1))) return false;
    return true;

		break;
	case 13:	//Loop4b
    if (!(contains(Marking.P->_PL_Server_4 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q4_wait , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_0 , 1))) return false;
    return true;

		break;
	case 14:	//serve4
    if (!(contains(Marking.P->_PL_Server_4 , 1))) return false;
    if (!(contains(Marking.P->_PL_Q4_wait , 1))) return false;
    if (!(contains(Marking.P->_PL_Action_1 , 1))) return false;
    return true;

		break;
	default:	//request1,
    if (!(contains(Marking.P->_PL_Q1_Idle , 1))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b){
	lastTransition = t;
	switch(t){
		case 0: {  //Loop1a
			Marking.P->_PL_Server_1 -= 1;
			Marking.P->_PL_Q1_Idle -= 1;
			Marking.P->_PL_Q1_Idle += 1;
			Marking.P->_PL_Server_2 += 1;
			Marking.P->_PL_Action_0 -= 1;
			Marking.P->_PL_Action_0 += 1;
       break;
     } 
		case 1: {  //Loop1b
			Marking.P->_PL_Server_1 -= 1;
			Marking.P->_PL_Server_1 += 1;
			Marking.P->_PL_Q1_wait -= 1;
			Marking.P->_PL_Q1_wait += 1;
			Marking.P->_PL_Action_0 -= 1;
			Marking.P->_PL_Action_1 += 1;
       break;
     } 
		case 2: {  //serve1
			Marking.P->_PL_Server_1 -= 1;
			Marking.P->_PL_Q1_Idle += 1;
			Marking.P->_PL_Q1_wait -= 1;
			Marking.P->_PL_Server_2 += 1;
			Marking.P->_PL_Action_0 += 1;
			Marking.P->_PL_Action_1 -= 1;
       break;
     } 
		case 3: {  //request1
			Marking.P->_PL_Q1_Idle -= 1;
			Marking.P->_PL_Q1_wait += 1;
       break;
     } 
		case 4: {  //Loop2a
			Marking.P->_PL_Server_2 -= 1;
			Marking.P->_PL_Q2_Idle -= 1;
			Marking.P->_PL_Q2_Idle += 1;
			Marking.P->_PL_Server_3 += 1;
			Marking.P->_PL_Action_0 -= 1;
			Marking.P->_PL_Action_0 += 1;
       break;
     } 
		case 5: {  //Loop2b
			Marking.P->_PL_Server_2 -= 1;
			Marking.P->_PL_Server_2 += 1;
			Marking.P->_PL_Q2_wait -= 1;
			Marking.P->_PL_Q2_wait += 1;
			Marking.P->_PL_Action_0 -= 1;
			Marking.P->_PL_Action_1 += 1;
       break;
     } 
		case 6: {  //serve2
			Marking.P->_PL_Server_2 -= 1;
			Marking.P->_PL_Q2_Idle += 1;
			Marking.P->_PL_Q2_wait -= 1;
			Marking.P->_PL_Server_3 += 1;
			Marking.P->_PL_Action_0 += 1;
			Marking.P->_PL_Action_1 -= 1;
       break;
     } 
		case 7: {  //request2
			Marking.P->_PL_Q2_Idle -= 1;
			Marking.P->_PL_Q2_wait += 1;
       break;
     } 
		case 8: {  //Loop3a
			Marking.P->_PL_Server_3 -= 1;
			Marking.P->_PL_Q3_Idle -= 1;
			Marking.P->_PL_Q3_Idle += 1;
			Marking.P->_PL_Server_4 += 1;
			Marking.P->_PL_Action_0 -= 1;
			Marking.P->_PL_Action_0 += 1;
       break;
     } 
		case 9: {  //Loop3b
			Marking.P->_PL_Server_3 -= 1;
			Marking.P->_PL_Server_3 += 1;
			Marking.P->_PL_Q3_wait -= 1;
			Marking.P->_PL_Q3_wait += 1;
			Marking.P->_PL_Action_0 -= 1;
			Marking.P->_PL_Action_1 += 1;
       break;
     } 
		case 10: {  //serve3
			Marking.P->_PL_Server_3 -= 1;
			Marking.P->_PL_Q3_Idle += 1;
			Marking.P->_PL_Q3_wait -= 1;
			Marking.P->_PL_Server_4 += 1;
			Marking.P->_PL_Action_0 += 1;
			Marking.P->_PL_Action_1 -= 1;
       break;
     } 
		case 11: {  //request3
			Marking.P->_PL_Q3_Idle -= 1;
			Marking.P->_PL_Q3_wait += 1;
       break;
     } 
		case 12: {  //Loop4a
			Marking.P->_PL_Server_1 += 1;
			Marking.P->_PL_Server_4 -= 1;
			Marking.P->_PL_Q4_Idle -= 1;
			Marking.P->_PL_Q4_Idle += 1;
			Marking.P->_PL_Action_0 -= 1;
			Marking.P->_PL_Action_0 += 1;
       break;
     } 
		case 13: {  //Loop4b
			Marking.P->_PL_Server_4 -= 1;
			Marking.P->_PL_Server_4 += 1;
			Marking.P->_PL_Q4_wait -= 1;
			Marking.P->_PL_Q4_wait += 1;
			Marking.P->_PL_Action_0 -= 1;
			Marking.P->_PL_Action_1 += 1;
       break;
     } 
		case 14: {  //serve4
			Marking.P->_PL_Server_1 += 1;
			Marking.P->_PL_Server_4 -= 1;
			Marking.P->_PL_Q4_Idle += 1;
			Marking.P->_PL_Q4_wait -= 1;
			Marking.P->_PL_Action_0 += 1;
			Marking.P->_PL_Action_1 -= 1;
       break;
     } 
		case 15: {  //request4
			Marking.P->_PL_Q4_Idle -= 1;
			Marking.P->_PL_Q4_wait += 1;
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
	case 3:	//request1
	case 7:	//request2
	case 11:	//request3
	case 15:	//request4
	{
		ParamDistr[0]= ( double ) 0.25;
	}

		break;
	case 2:	//serve1
	case 6:	//serve2
	case 10:	//serve3
	case 14:	//serve4
	{
		ParamDistr[0]= ( double ) 1;
	}

		break;
	default:	//Loop1a,Loop1b,Loop2a,Loop2b,Loop3a,Loop3b,Loop4a,Loop4b,
	{
		ParamDistr[0]= ( double ) 200;
	}

}
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

