#include "spn.hpp"
#include <iomanip>
using namespace std;
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
namespace hybridVar {
}
void REHandling::print_state(const vector<int> &vect){}
void REHandling::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool REHandling::precondition(const abstractMarking &M){return true;}
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_N_Queue1 =5  ;
	P->_PL_Queue1 =0  ;
	P->_PL_Phase1 =1  ;
	P->_PL_Phase2 =0  ;
	P->_PL_Queue2 =0  ;
	P->_PL_N_Queue2 =5  ;
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

void abstractMarking::print(ostream &s,double eTime)const{
}
void abstractMarking::printSedCmd(ostream &s)const{
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
	v.reserve(7);
	size_t i = 0;
	v[i++]= P->_PL_N_Queue1;
	v[i++]= P->_PL_Queue1;
	v[i++]= P->_PL_Phase1;
	v[i++]= P->_PL_Phase2;
	v[i++]= P->_PL_Queue2;
	v[i++]= P->_PL_N_Queue2;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	size_t i = 0;
	P->_PL_N_Queue1 = v[i++];
	P->_PL_Queue1 = v[i++];
	P->_PL_Phase1 = v[i++];
	P->_PL_Phase2 = v[i++];
	P->_PL_Queue2 = v[i++];
	P->_PL_N_Queue2 = v[i++];
};

void abstractMarking::Symmetrize(){
}bool abstractBinding::next() {
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
#include "Polynome.hpp"
class CustomDistrPoly: public CustomDistr {
	const static int poly_table[];
	vector<Poly<3>> ptable;
public:
	CustomDistrPoly(){
		ptable = parse<3>("twoears.grml.data");
	}
	double virtual userDefineCDF(vector<double> const& param, double funvar)const{
		return (eval(ptable[poly_table[ 5*((int)param[0]) ]],param,funvar)/eval(ptable[poly_table[ 5*((int)param[0])+2 ]],param,funvar))  ;
	}
	double  virtual userDefinePDF(vector<double> const& param, double funvar)const{
		return (eval(ptable[poly_table[ 5*((int)param[0])+1 ]],param,funvar)/eval(ptable[poly_table[ 5*((int)param[0])+2 ]],param,funvar))  ;
	}
	double virtual userDefineLowerBound(vector<double> const& param)const{
		return eval(ptable[poly_table[ 5*((int)param[0])+3 ]],param);
	}

	double virtual userDefineUpperBound(vector<double> const& param)const{
		return eval(ptable[poly_table[ 5*((int)param[0])+4] ],param);
	}

	double virtual userDefineDiscreteDistr(vector<double> const& param,unsigned int i)const{
		return (0.0);
	}
	double virtual evalPoly(unsigned long i,vector<double> const & param)const {
		return eval(ptable[i],param);
	}
    const string virtual print_poly(unsigned long i)const{
        stringstream s;
        s << ptable[poly_table[ 5*(i) ]];
        s << "/" << ptable[poly_table[ 5*(i)+2 ]];
        return s.str();
    }

};
abstractBindingIterator::abstractBindingIterator(abstractMarking& m) {
	P = new abstractBindingIteratorImpl;
	reset(m);
};
bool abstractBindingIterator::next(size_t& t,abstractMarking& m) {
	return P->next(t,*(m.P));
};
abstractBindingIterator::~abstractBindingIterator() {
	delete(P);
};
size_t abstractBindingIterator::getIndex() {
	return P->getIndex();
};
abstractBinding abstractBindingIterator::getBinding() {
	return P->getBinding();
};static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_0[4]= {TR_ToPhase2_RT, TR_Route1_RT, TR_Route2_RT, -1 }; /* Arrive*/
static const int PE_PossiblyEnabled_1[3]= {TR_Route1_RT, TR_Route2_RT, -1 }; /* ToPhase2*/
static const int PE_PossiblyEnabled_2[4]= {TR_Arrive_RT, TR_ToPhase2_RT, TR_Leave_RT, -1 }; /* Route1*/
static const int PE_PossiblyEnabled_3[5]= {TR_Arrive_RT, TR_ToPhase2_RT, TR_Route1_RT, TR_Leave_RT, -1 }; /* Route2*/
static const int PE_PossiblyEnabled_4[3]= {TR_Route1_RT, TR_Route2_RT, -1 }; /* Leave*/
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, PE_PossiblyEnabled_2, PE_PossiblyEnabled_3, PE_PossiblyEnabled_4};

static const int PE_PossiblyDisabled_1[3]= {TR_Route1_RT, TR_Route2_RT, -1 }; /* ToPhase2*/
static const int PE_PossiblyDisabled_2[3]= {TR_ToPhase2_RT, TR_Route2_RT, -1 }; /* Route1*/
static const int PE_PossiblyDisabled_3[3]= {TR_ToPhase2_RT, TR_Route1_RT, -1 }; /* Route2*/
const int* SPN::PossiblyDisabled[] = {EMPTY_array, PE_PossiblyDisabled_1, PE_PossiblyDisabled_2, PE_PossiblyDisabled_3, EMPTY_array};

const int* SPN::FreeMarkDepT[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

static spn_trans TransArray[5] = { _trans(0,EXPONENTIAL,0,1, 0), _trans(1,EXPONENTIAL,0,1, 0), _trans(2,EXPONENTIAL,0,1, 0), _trans(3,EXPONENTIAL,0,1, 0), _trans(4,EXPONENTIAL,0,1, 0),  }; 
SPN::SPN():
customDistr(*(new CustomDistr())),pl(6), tr(5) ,Transition(TransArray,TransArray +5),Place(6),ParamDistr(10),TransitionConditions(5,0){
    Path ="tqn.gspn";
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{

	switch (t){
		case 0:	//Arrive

			if (!(contains(Marking.P->_PL_N_Queue1 , 1))) return false;
		return true;
		break;
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
	}
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;

	switch (t){
		case 3:	//Route2
{
			Marking.P->_PL_N_Queue1 += 1;
			Marking.P->_PL_Queue1 -= 1;
			Marking.P->_PL_Phase1 += 1;
			Marking.P->_PL_Phase2 -= 1;
			Marking.P->_PL_Queue2 += 1;
			Marking.P->_PL_N_Queue2 -= 1;
	}
		break;
		case 2:	//Route1
{
			Marking.P->_PL_N_Queue1 += 1;
			Marking.P->_PL_Queue1 -= 1;
			Marking.P->_PL_Phase1 -= 1;
			Marking.P->_PL_Phase1 += 1;
			Marking.P->_PL_Queue2 += 1;
			Marking.P->_PL_N_Queue2 -= 1;
	}
		break;
		case 0:	//Arrive
{
			Marking.P->_PL_N_Queue1 -= 1;
			Marking.P->_PL_Queue1 += 1;
	}
		break;
		case 1:	//ToPhase2
{
			Marking.P->_PL_Queue1 -= 1;
			Marking.P->_PL_Queue1 += 1;
			Marking.P->_PL_Phase1 -= 1;
			Marking.P->_PL_Phase2 += 1;
	}
		break;
		case 4:	//Leave
{
			Marking.P->_PL_Queue2 -= 1;
			Marking.P->_PL_N_Queue2 += 1;
	}
		break;
	}
}

void SPN::unfire(TR_PL_ID t, const abstractBinding &b){


}

const abstractBinding* SPN::nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
	switch(lastTransition*(tr+1) + targettr){
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
const abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
	switch(lastTransition*(tr+1) + targettr){
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

	switch (t){
		case 1:	//ToPhase2
	{
		ParamDistr[0]= ( double ) 0.2 ;
	}

		break;
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
	}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

		return (double)49 ;
}

REAL_TYPE SPN::GetWeight(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

		return (double)49 ;
}

void SPN::Msimple(){
	vector<int> tab;
	Msimpletab = tab;
}
void SPN::reset() {
	lastTransitionTime = 0;
	Marking.resetToInitMarking();
}

