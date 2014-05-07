#include "spn.hpp"
#include <iomanip>
	const double mu=0.23;
	const double r=5;
	const double rho=0.385;
	const int _nb_Place_RE_Queue1=0;
	const int _nb_Place_RE_Queue2=1;
	const int _nb_Place_AQueue2=2;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_RE_Queue1 =1;
	P->_PL_RE_Queue2 =0;
	P->_PL_AQueue2 =5;
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
	s  << setw(14) << "RE_Queue1" << setw(14) << "RE_Queue2" << setw(14) << "AQueue2";}

void abstractMarking::print(ostream &s)const{
	s << setw(14) << P->_PL_RE_Queue1;
	s << setw(14) << P->_PL_RE_Queue2;
	s << setw(14) << P->_PL_AQueue2;
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_RE_Queue1;
		case 1: return P->_PL_RE_Queue2;
		case 2: return P->_PL_AQueue2;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(3);
	v[0] = P->_PL_RE_Queue1;
	v[1] = P->_PL_RE_Queue2;
	v[2] = P->_PL_AQueue2;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_RE_Queue1 = v[0];
	P->_PL_RE_Queue2 = v[1];
	P->_PL_AQueue2 = v[2];
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
pl(3), tr(3), Place(3),Transition(3),ParamDistr(3), TransitionConditions(3,0){
    Path ="tandem_agr.gspn";
	PossiblyEnabled = vector< set<int> >(3);
	PossiblyEnabled[0].insert( 1 );
	PossiblyEnabled[1].insert( 2 );
	PossiblyEnabled[2].insert( 1 );

	PossiblyDisabled = vector< set<int> >(3);

	FreeMarkDepT = vector< set<int> >(3);

    Place[0].label =" RE_Queue1";
    Place[0].isTraced = 1;
    Place[1].label =" RE_Queue2";
    Place[1].isTraced = 1;
    Place[2].label =" AQueue2";
    Place[2].isTraced = 1;
	Transition[0] = _trans(0,Timed,EXPONENTIAL,0,1);
	Transition[0].label = "mu";
	Transition[1] = _trans(1,Timed,EXPONENTIAL,0,1);
	Transition[1].label = "rho1";
	Transition[2] = _trans(2,Timed,EXPONENTIAL,0,1);
	Transition[2].label = "rho2";
    Msimple();
vector <double> Rate_Table_init (tr);
Rate_Table = Rate_Table_init;
Origine_Rate_Table = Rate_Table_init;
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 2:	//rho2
    if (!(contains(Marking.P->_PL_RE_Queue2 , 1))) return false;
    return true;

		break;
	case 0:	//mu
    return true;

		break;
	default:	//rho1,
    if (!(contains(Marking.P->_PL_RE_Queue1 , 1))) return false;
    if (!(contains(Marking.P->_PL_AQueue2 , 1))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b){
	lastTransition = t;
	switch(t){
		case 0: {  //mu
			Marking.P->_PL_RE_Queue1 += 1;
       break;
     } 
		case 1: {  //rho1
			Marking.P->_PL_RE_Queue1 -= 1;
			Marking.P->_PL_RE_Queue2 += 1;
			Marking.P->_PL_AQueue2 -= 1;
       break;
     } 
		case 2: {  //rho2
			Marking.P->_PL_RE_Queue2 -= 1;
			Marking.P->_PL_AQueue2 += 1;
       break;
     } 
	}
}
void SPN::unfire(size_t t ,const abstractBinding& b){
switch (t){
	case 0:	//mu
    Marking.P->_PL_RE_Queue1 -= 1;

		break;
	case 2:	//rho2
    Marking.P->_PL_RE_Queue2 += 1;
    Marking.P->_PL_AQueue2 -= 1;

		break;
	default:	//rho1,
    Marking.P->_PL_RE_Queue1 += 1;
    Marking.P->_PL_RE_Queue2 -= 1;
    Marking.P->_PL_AQueue2 += 1;

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
	case 0:	//mu
	{
		ParamDistr[0]= ( double ) 0.23;
	}

		break;
	default:	//rho1,rho2,
	{
		ParamDistr[0]= ( double ) 0.385;
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
		tab.push_back(0);
		tab.push_back(1);
	Msimpletab = tab;
}
void SPN::reset() {
	Marking.resetToInitMarking();
	TransitionConditions = initTransitionConditions;
}

