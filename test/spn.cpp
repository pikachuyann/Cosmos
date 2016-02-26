#include "spn.hpp"
#include <iomanip>
using namespace std;
#define PL_i_LP 0
#define TR_ln_RT 0

const int _nb_Place_i=0;
namespace hybridVar {
}
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_i =0  ;
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
s <<  setw(5) << "i ";
}

void abstractMarking::print(ostream &s,double eTime)const{
	s <<  setw(4) << P->_PL_i<<" ";
}
void abstractMarking::printSedCmd(ostream &s)const{
	s << "-e 's/\\$i\\$/";
	s << P->_PL_i;
	s <<"/g' ";
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_i;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(1);
	v.reserve(2);
	size_t i = 0;
	v[i++]= P->_PL_i;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	size_t i = 0;
	P->_PL_i = v[i++];
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
class CustomDistrOverride: public CustomDistr {
public:
    
    CustomDistrOverride(){
        std::cerr << "test" << std::endl;
    }
    
double virtual userDefineCDF(vector<double> const& param, double funvar)const override{
    
std::cerr << "test" << std::endl;
	{
		double t = funvar;
		return (0.125 * t);
	}

}

virtual double userDefinePDF(vector<double> const& param, double funvar)const override{
	{
		double t = funvar;
		return (0.125);
	}

}

virtual double userDefineLowerBound(vector<double> const& param)const override{
		return (0.0);

}

virtual double userDefineUpperBound(vector<double> const& param)const override{
		return (8.0);

}

double virtual userDefineDiscreteDistr(vector<double> const& param,unsigned int i)const override{
	return (0.0);
}

};
static const int EMPTY_array[1]={-1};
const int* SPN::PossiblyEnabled[] = {EMPTY_array};

const int* SPN::PossiblyDisabled[] = {EMPTY_array};

const int* SPN::FreeMarkDepT[] = {EMPTY_array};

static spn_trans TransArray[1] = { _trans(0,USERDEFINE,0,1, 0, "ln"),  }; 
SPN::SPN():
customDistr(CustomDistrOverride()),pl(1), tr(1) ,Transition(TransArray,TransArray +1),Place(1),ParamDistr(10),TransitionConditions(1,0){
    Path ="testuserdefine.grml";
    Place[0].label =" i";
    Place[0].isTraced = 1;
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{


		return true;
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;

{
			Marking.P->_PL_i += 1;
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

	{
		ParamDistr[0]= ( double ) 0 ;
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
	Msimpletab = tab;
}
void SPN::reset() {
	lastTransitionTime = 0;
	Marking.resetToInitMarking();
}

