#include "spn.hpp"
#include <iomanip>
#define PL_N_Queue1_LP 0
#define PL_Queue1_LP 1
#define PL_Phase1_LP 2
#define PL_Phase2_LP 3
#define PL_Queue2_LP 4
#define PL_N_Queue2_LP 5
#define TR_Arrive_RT 0
#define TR_ToPhase2_RT 1
#define TR_Route1_RT 2
#define TR_Route2_RT 3
#define TR_Leave_RT 4

	const double C=5;
	const int _nb_Place_N_Queue1=0;
	const int _nb_Place_Queue1=1;
	const int _nb_Place_Phase1=2;
	const int _nb_Place_Phase2=3;
	const int _nb_Place_Queue2=4;
	const int _nb_Place_N_Queue2=5;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_N_Queue1 =5;
	P->_PL_Queue1 =0;
	P->_PL_Phase1 =1;
	P->_PL_Phase2 =0;
	P->_PL_Queue2 =0;
	P->_PL_N_Queue2 =5;
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

void abstractMarking::printSedCmd(ostream &s)const{
}
void abstractMarking::print(ostream &s)const{
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_N_Queue1;
		case 1: return P->_PL_Queue1;
		case 2: return P->_PL_Phase1;
		case 3: return P->_PL_Phase2;
		case 4: return P->_PL_Queue2;
		case 5: return P->_PL_N_Queue2;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(6);
	v[0] = P->_PL_N_Queue1;
	v[1] = P->_PL_Queue1;
	v[2] = P->_PL_Phase1;
	v[3] = P->_PL_Phase2;
	v[4] = P->_PL_Queue2;
	v[5] = P->_PL_N_Queue2;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_N_Queue1 = v[0];
	P->_PL_Queue1 = v[1];
	P->_PL_Phase1 = v[2];
	P->_PL_Phase2 = v[3];
	P->_PL_Queue2 = v[4];
	P->_PL_N_Queue2 = v[5];
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
const int PE_PossiblyEnabled_0[3]= {1, 2, 3};
const int PE_PossiblyEnabled_1[2]= {2, 3};
const int PE_PossiblyEnabled_2[3]= {0, 1, 4};
const int PE_PossiblyEnabled_3[4]= {0, 1, 2, 4};
const int PE_PossiblyEnabled_4[2]= {2, 3};
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, PE_PossiblyEnabled_2, PE_PossiblyEnabled_3, PE_PossiblyEnabled_4};

const int PE_PossiblyDisabled_0[0]= {};
const int PE_PossiblyDisabled_1[2]= {2, 3};
const int PE_PossiblyDisabled_2[2]= {1, 3};
const int PE_PossiblyDisabled_3[2]= {1, 2};
const int PE_PossiblyDisabled_4[0]= {};
const int* SPN::PossiblyDisabled[] = {PE_PossiblyDisabled_0, PE_PossiblyDisabled_1, PE_PossiblyDisabled_2, PE_PossiblyDisabled_3, PE_PossiblyDisabled_4};

const int PE_FreeMarkDepT_0[0]= {};
const int PE_FreeMarkDepT_1[0]= {};
const int PE_FreeMarkDepT_2[0]= {};
const int PE_FreeMarkDepT_3[0]= {};
const int PE_FreeMarkDepT_4[0]= {};
const int* SPN::FreeMarkDepT[] = {PE_FreeMarkDepT_0, PE_FreeMarkDepT_1, PE_FreeMarkDepT_2, PE_FreeMarkDepT_3, PE_FreeMarkDepT_4};

SPN::SPN():
pl(6), tr(5), Transition(5),Place(6),ParamDistr(3), TransitionConditions(5,0){
    Path ="tqn.gspn";
	Transition[0] = _trans(0,Timed,EXPONENTIAL,0,1);
	Transition[1] = _trans(1,Timed,EXPONENTIAL,0,1);
	Transition[2] = _trans(2,Timed,EXPONENTIAL,0,1);
	Transition[3] = _trans(3,Timed,EXPONENTIAL,0,1);
	Transition[4] = _trans(4,Timed,EXPONENTIAL,0,1);
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 2:	//Route1
    if (!(contains(Marking.P->_PL_Queue1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Phase1 , 1))) return false;
    if (!(contains(Marking.P->_PL_N_Queue2 , 1))) return false;
    return true;

		break;
	case 1:	//ToPhase2
    if (!(contains(Marking.P->_PL_Queue1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Phase1 , 1))) return false;
    return true;

		break;
	case 3:	//Route2
    if (!(contains(Marking.P->_PL_Queue1 , 1))) return false;
    if (!(contains(Marking.P->_PL_Phase2 , 1))) return false;
    if (!(contains(Marking.P->_PL_N_Queue2 , 1))) return false;
    return true;

		break;
	case 4:	//Leave
    if (!(contains(Marking.P->_PL_Queue2 , 1))) return false;
    return true;

		break;
	default:	//Arrive,
    if (!(contains(Marking.P->_PL_N_Queue1 , 1))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b, double time){
	lastTransition = t;
	switch(t){
		case 0: {  //Arrive
			Marking.P->_PL_N_Queue1 -= 1;
			Marking.P->_PL_Queue1 += 1;
       break;
     } 
		case 1: {  //ToPhase2
			Marking.P->_PL_Queue1 -= 1;
			Marking.P->_PL_Queue1 += 1;
			Marking.P->_PL_Phase1 -= 1;
			Marking.P->_PL_Phase2 += 1;
       break;
     } 
		case 2: {  //Route1
			Marking.P->_PL_N_Queue1 += 1;
			Marking.P->_PL_Queue1 -= 1;
			Marking.P->_PL_Phase1 -= 1;
			Marking.P->_PL_Phase1 += 1;
			Marking.P->_PL_Queue2 += 1;
			Marking.P->_PL_N_Queue2 -= 1;
       break;
     } 
		case 3: {  //Route2
			Marking.P->_PL_N_Queue1 += 1;
			Marking.P->_PL_Queue1 -= 1;
			Marking.P->_PL_Phase1 += 1;
			Marking.P->_PL_Phase2 -= 1;
			Marking.P->_PL_Queue2 += 1;
			Marking.P->_PL_N_Queue2 -= 1;
       break;
     } 
		case 4: {  //Leave
			Marking.P->_PL_Queue2 -= 1;
			Marking.P->_PL_N_Queue2 += 1;
       break;
     } 
	}
}
void SPN::unfire(size_t t ,const abstractBinding& b){
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
	case 2:	//Route1
	{
		ParamDistr[0]= ( double ) 1.8 ;
	}

		break;
	case 3:	//Route2
	{
		ParamDistr[0]= ( double ) 2 ;
	}

		break;
	case 0:	//Arrive
	{
		ParamDistr[0]= ( double ) 20 ;
	}

		break;
	case 4:	//Leave
	{
		ParamDistr[0]= ( double ) 4 ;
	}

		break;
	default:	//ToPhase2,
	{
		ParamDistr[0]= ( double ) 0.2 ;
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
	Msimpletab = tab;
}
void SPN::reset() {
	Marking.resetToInitMarking();
	TransitionConditions = initTransitionConditions;
}

