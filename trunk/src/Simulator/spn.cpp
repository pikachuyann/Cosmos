#include "spn.hpp"
#include <iomanip>
	const double mu=0.23;
	const double r=5;
	const double rho=0.385;
	const int _nb_Place_RE_Queue1=0;
	const int _nb_Place_RE_Queue2=1;
	const int _nb_Place_Puit=2;
#include "lumpingfun.cpp"
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_RE_Queue1 =1;
	P->_PL_RE_Queue2 =0;
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
	s  << setw(14) << "RE_Queue1" << setw(14) << "RE_Queue2" << setw(14) << "Puit";}

void abstractMarking::print(ostream &s)const{
	s << setw(14) << P->_PL_RE_Queue1;
	s << setw(14) << P->_PL_RE_Queue2;
	s << setw(14) << P->_PL_Puit;
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_RE_Queue1;
		case 1: return P->_PL_RE_Queue2;
		case 2: return P->_PL_Puit;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(3);
	v[0] = P->_PL_RE_Queue1;
	v[1] = P->_PL_RE_Queue2;
	v[2] = P->_PL_Puit;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_RE_Queue1 = v[0];
	P->_PL_RE_Queue2 = v[1];
	P->_PL_Puit = v[2];
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
pl(3), tr(5), Place(3),Transition(5),ParamDistr(3), TransitionConditions(5,0){
    Path ="tandem";
	PossiblyEnabled = vector< set<int> >(5);
	PossiblyEnabled[0].insert( 1 );
	PossiblyEnabled[1].insert( 2 );

	PossiblyDisabled = vector< set<int> >(5);

	FreeMarkDepT = vector< set<int> >(5);
	FreeMarkDepT[0].insert( 3 );
	FreeMarkDepT[0].insert( 4 );
	FreeMarkDepT[1].insert( 3 );
	FreeMarkDepT[1].insert( 4 );
	FreeMarkDepT[2].insert( 3 );
	FreeMarkDepT[2].insert( 4 );
	FreeMarkDepT[3].insert( 3 );
	FreeMarkDepT[3].insert( 4 );
	FreeMarkDepT[4].insert( 3 );
	FreeMarkDepT[4].insert( 4 );

    Place[0].label =" RE_Queue1";
    Place[0].isTraced = 1;
    Place[1].label =" RE_Queue2";
    Place[1].isTraced = 1;
    Place[2].label =" Puit";
    Place[2].isTraced = 1;
	Transition[0] = _trans(0,Timed,EXPONENTIAL,0,1);
	Transition[0].DistParams.push_back(" 0.23" );
	Transition[0].label = "mu";
	Transition[0].priority = "1";
	Transition[0].weight = "1";
	Transition[1] = _trans(1,Timed,EXPONENTIAL,0,1);
	Transition[1].DistParams.push_back(" 0.385" );
	Transition[1].label = "rho1";
	Transition[1].priority = "1";
	Transition[1].weight = "1";
	Transition[2] = _trans(2,Timed,EXPONENTIAL,0,1);
	Transition[2].DistParams.push_back(" 0.385" );
	Transition[2].label = "rho2";
	Transition[2].priority = "1";
	Transition[2].weight = "1";
	Transition[3] = _trans(3,Timed,EXPONENTIAL,1,1);
	Transition[3].DistParams.push_back(" 0 *  Marking.P->_PL_RE_Queue1 " );
	Transition[3].label = "selfloop";
	Transition[3].priority = "1";
	Transition[3].weight = "1";
	Transition[4] = _trans(4,Timed,EXPONENTIAL,1,1);
	Transition[4].DistParams.push_back(" 0 *  Marking.P->_PL_RE_Queue1 " );
	Transition[4].label = "Puittrans";
	Transition[4].priority = "1";
	Transition[4].weight = "1";
    Msimple();
vector <double> Rate_Table_init (tr);
Rate_Table = Rate_Table_init;
Origine_Rate_Table = Rate_Table_init;
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 1:	//rho1
    if (!(contains(Marking.P->_PL_RE_Queue1 , 1))) return false;
    return true;

		break;
	case 2:	//rho2
    if (!(contains(Marking.P->_PL_RE_Queue2 , 1))) return false;
    return true;

		break;
	default:	//mu,selfloop,Puittrans,
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
       break;
     } 
		case 2: {  //rho2
			Marking.P->_PL_RE_Queue2 -= 1;
       break;
     } 
		case 3: {  //selfloop
       break;
     } 
		case 4: {  //Puittrans
			Marking.P->_PL_Puit += 1;
       break;
     } 
	}
}
void SPN::unfire(size_t t ,const abstractBinding& b){
switch (t){
	case 4:	//Puittrans
    Marking.P->_PL_Puit -= 1;

		break;
	case 1:	//rho1
    Marking.P->_PL_RE_Queue1 += 1;
    Marking.P->_PL_RE_Queue2 -= 1;

		break;
	case 0:	//mu
    Marking.P->_PL_RE_Queue1 -= 1;

		break;
	case 2:	//rho2
    Marking.P->_PL_RE_Queue2 += 1;

		break;
}
}

const set<int>* SPN::PossiblyEn()const {
	return &(PossiblyEnabled[lastTransition]);
}
const set<int>* SPN::PossiblyDis()const {
	return &(PossiblyDisabled[lastTransition]);
}
const set<int>* SPN::FreeMarkingDependant()const {
	return &(FreeMarkDepT[lastTransition]);
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
	case 1:	//rho1
	case 2:	//rho2
	{
		ParamDistr[0]= ( double ) 0.385;
	}

		break;
	default:	//selfloop,Puittrans,
	{
		ParamDistr[0]= ( double ) 0 *  Marking.P->_PL_RE_Queue1 ;
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

