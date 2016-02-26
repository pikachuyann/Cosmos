#include "spn.hpp"
#include <iomanip>
using namespace std;
#define PL_RE_Queue1_LP 0
#define PL_RE_Queue2_LP 1
#define PL_Puit_LP 2
#define TR_rho0_RT 0
#define TR_rho1_RT 1
#define TR_rho2_RT 2
#define TR_Puittrans_RT 3

const double r=5;
const double rho0=0.1;
const double rho1=0.45;
const int _nb_Place_RE_Queue1=0;
const int _nb_Place_RE_Queue2=1;
const int _nb_Place_Puit=2;
namespace hybridVar {
}
#include "lumpingfun.cpp"
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_RE_Queue1 =1  ;
	P->_PL_RE_Queue2 =0  ;
	P->_PL_Puit =0  ;
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
s <<  setw(9) << "RE_Queue1 ";
s <<  setw(9) << "RE_Queue2 ";
s <<  setw(9) << "Puit ";
}

void abstractMarking::print(ostream &s,double eTime)const{
	s <<  setw(8) << P->_PL_RE_Queue1<<" ";
	s <<  setw(8) << P->_PL_RE_Queue2<<" ";
	s <<  setw(8) << P->_PL_Puit<<" ";
}
void abstractMarking::printSedCmd(ostream &s)const{
	s << "-e 's/\\$RE_Queue1\\$/";
	s << P->_PL_RE_Queue1;
	s <<"/g' ";
	s << "-e 's/\\$RE_Queue2\\$/";
	s << P->_PL_RE_Queue2;
	s <<"/g' ";
	s << "-e 's/\\$Puit\\$/";
	s << P->_PL_Puit;
	s <<"/g' ";
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
	v.reserve(4);
	size_t i = 0;
	v[i++]= P->_PL_RE_Queue1;
	v[i++]= P->_PL_RE_Queue2;
	v[i++]= P->_PL_Puit;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	size_t i = 0;
	P->_PL_RE_Queue1 = v[i++];
	P->_PL_RE_Queue2 = v[i++];
	P->_PL_Puit = v[i++];
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
static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_0[2]= {TR_rho1_RT, -1 }; /* rho0*/
static const int PE_PossiblyEnabled_1[2]= {TR_rho2_RT, -1 }; /* rho1*/
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, EMPTY_array, EMPTY_array};

const int* SPN::PossiblyDisabled[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

static const int PE_FreeMarkDepT_0[2]= {TR_Puittrans_RT, -1 }; /* rho0*/
static const int PE_FreeMarkDepT_1[2]= {TR_Puittrans_RT, -1 }; /* rho1*/
static const int PE_FreeMarkDepT_2[2]= {TR_Puittrans_RT, -1 }; /* rho2*/
static const int PE_FreeMarkDepT_3[2]= {TR_Puittrans_RT, -1 }; /* Puittrans*/
const int* SPN::FreeMarkDepT[] = {PE_FreeMarkDepT_0, PE_FreeMarkDepT_1, PE_FreeMarkDepT_2, PE_FreeMarkDepT_3};

static spn_trans TransArray[4] = { _trans(0,EXPONENTIAL,0,1, 0, "rho0"), _trans(1,EXPONENTIAL,0,1, 0, "rho1"), _trans(2,EXPONENTIAL,0,1, 0, "rho2"), _trans(3,EXPONENTIAL,1,1, 0, "Puittrans"),  }; 
SPN::SPN():
customDistr(*(new CustomDistr())),pl(3), tr(4) ,Transition(TransArray,TransArray +4),Place(3),ParamDistr(10),TransitionConditions(4,0){
    Path ="tandemRE.grml";
    Place[0].label =" RE_Queue1";
    Place[0].isTraced = 1;
    Place[1].label =" RE_Queue2";
    Place[1].isTraced = 1;
    Place[2].label =" Puit";
    Place[2].isTraced = 1;
	Msimple();
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{

	switch (t){
		case 1:	//rho1

			if (!(contains(Marking.P->_PL_RE_Queue1 , 1))) return false;
		return true;
		break;
		case 2:	//rho2

			if (!(contains(Marking.P->_PL_RE_Queue2 , 1))) return false;
		return true;
		break;
		default:	//rho0,Puittrans,

		return true;
		break;
	}
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;

	switch (t){
		case 3:	//Puittrans
{
			Marking.P->_PL_Puit += 1;
	}
		break;
		case 0:	//rho0
{
			Marking.P->_PL_RE_Queue1 += 1;
	}
		break;
		case 1:	//rho1
{
			Marking.P->_PL_RE_Queue1 -= 1;
			Marking.P->_PL_RE_Queue2 += 1;
	}
		break;
		case 2:	//rho2
{
			Marking.P->_PL_RE_Queue2 -= 1;
	}
		break;
	}
}

void SPN::unfire(TR_PL_ID t, const abstractBinding &b){

	switch (t){
		case 3:	//Puittrans
			Marking.P->_PL_Puit -= 1;

		break;
		case 1:	//rho1
			Marking.P->_PL_RE_Queue1 += 1;
			Marking.P->_PL_RE_Queue2 -= 1;

		break;
		case 0:	//rho0
			Marking.P->_PL_RE_Queue1 -= 1;

		break;
		case 2:	//rho2
			Marking.P->_PL_RE_Queue2 += 1;

		break;
	}
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
		case 3:	//Puittrans
	{
		ParamDistr[0]= ( double ) 0 ;
	}

		break;
		case 0:	//rho0
	{
		ParamDistr[0]= ( double ) rho0 ;
	}

		break;
		default:	//rho1,rho2,
	{
		ParamDistr[0]= ( double ) rho1 ;
	}

		break;
	}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

		return (double)1 ;
}

REAL_TYPE SPN::GetWeight(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

		return (double)1 ;
}

void SPN::Msimple(){
	vector<int> tab;
		tab.push_back(0);
		tab.push_back(1);
	Msimpletab = tab;
}
void SPN::reset() {
	lastTransitionTime = 0;
	Marking.resetToInitMarking();
}

