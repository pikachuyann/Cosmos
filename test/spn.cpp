#include "spn.hpp"
#include <iomanip>
using namespace std;
#define PL_RE_Queue1_LP 0
#define PL_RE_Queue2_LP 1
#define PL_Puit_LP 2
#define TR_mu_RT 0
#define TR_rho1_RT 1
#define TR_rho2_RT 2
#define TR_selfloop_RT 3
#define TR_Puittrans_RT 4

const double mu=0.23;
const double r=5;
const double rho=0.385;
const int _nb_Place_RE_Queue1=0;
const int _nb_Place_RE_Queue2=1;
const int _nb_Place_Puit=2;
namespace hybridVar {
}
#include "lumpingfun.cpp"
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
static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_0[2]= {TR_rho1_RT, -1 }; /* mu*/
static const int PE_PossiblyEnabled_1[2]= {TR_rho2_RT, -1 }; /* rho1*/
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, EMPTY_array, EMPTY_array, EMPTY_array};

const int* SPN::PossiblyDisabled[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

static const int PE_FreeMarkDepT_0[3]= {TR_selfloop_RT, TR_Puittrans_RT, -1 }; /* mu*/
static const int PE_FreeMarkDepT_1[3]= {TR_selfloop_RT, TR_Puittrans_RT, -1 }; /* rho1*/
static const int PE_FreeMarkDepT_2[3]= {TR_selfloop_RT, TR_Puittrans_RT, -1 }; /* rho2*/
static const int PE_FreeMarkDepT_3[3]= {TR_selfloop_RT, TR_Puittrans_RT, -1 }; /* selfloop*/
static const int PE_FreeMarkDepT_4[3]= {TR_selfloop_RT, TR_Puittrans_RT, -1 }; /* Puittrans*/
const int* SPN::FreeMarkDepT[] = {PE_FreeMarkDepT_0, PE_FreeMarkDepT_1, PE_FreeMarkDepT_2, PE_FreeMarkDepT_3, PE_FreeMarkDepT_4};

static spn_trans TransArray[5] = { _trans(0,EXPONENTIAL,0,1, 0, "mu"), _trans(1,EXPONENTIAL,0,1, 0, "rho1"), _trans(2,EXPONENTIAL,0,1, 0, "rho2"), _trans(3,EXPONENTIAL,1,1, 0, "selfloop"), _trans(4,EXPONENTIAL,1,1, 0, "Puittrans"),  }; 
SPN::SPN():
pl(3), tr(5) ,Transition(TransArray,TransArray +5),Place(3),ParamDistr(10),TransitionConditions(5,0){
    Path ="tandem.gspn";
    Place[0].label =" RE_Queue1";
    Place[0].isTraced = 1;
    Place[1].label =" RE_Queue2";
    Place[1].isTraced = 1;
    Place[2].label =" Puit";
    Place[2].isTraced = 1;
    Msimple();
vector <double> Rate_Table_init (tr);
Rate_Table = Rate_Table_init;
Origine_Rate_Table = Rate_Table_init;
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
		default:	//mu,selfloop,Puittrans,

		return true;
		break;
	}
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;

	switch (t){
		case 4:	//Puittrans
{
			Marking.P->_PL_Puit += 1;
	}
		break;
		case 0:	//mu
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
		case 3:	//selfloop
{
	}
		break;
	}
}

void SPN::unfire(TR_PL_ID t, const abstractBinding &b){

	switch (t){
		case 3:	//selfloop

		break;
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
		case 0:	//mu
	{
		ParamDistr[0]= ( double ) 0.23 ;
	}

		break;
		case 1:	//rho1
		case 2:	//rho2
	{
		ParamDistr[0]= ( double ) 0.385 ;
	}

		break;
		default:	//selfloop,Puittrans,
	{
		ParamDistr[0]= ( double ) 0 *  Marking.P->_PL_RE_Queue1  ;
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
		tab.push_back(0);
		tab.push_back(1);
	Msimpletab = tab;
}
void SPN::reset() {
	lastTransitionTime = 0;
	Marking.resetToInitMarking();
}

double userDefineCDF(vector<double> const& param, double funvar){
}

double userDefinePDF(vector<double> const& param, double funvar){
}

double userDefineLowerBound(vector<double> const& param){
}

double userDefineUpperBound(vector<double> const& param){
}

double userDefineDiscreteDistr(vector<double> const& param,unsigned int i){
	return (0.0);
}

