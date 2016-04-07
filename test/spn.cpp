#include "spn.hpp"
#include <iomanip>
using namespace std;
#define PL_Counter_LP 0
#define PL_TargetState_LP 1
#define PL_s_0__LP 2
#define PL_s_0_0_LP 3
#define PL_s_0_1_LP 4
#define PL_s_0_2_LP 5
#define PL_s_1__LP 6
#define PL_s_1_0_LP 7
#define PL_s_1_1_LP 8
#define PL_s_1_2_LP 9
#define PL_s_2__LP 10
#define PL_s_2_0_LP 11
#define PL_s_2_1_LP 12
#define PL_s_2_2_LP 13
#define PL_s_3__LP 14
#define PL_s_3_0_LP 15
#define PL_s_3_1_LP 16
#define PL_s_a__LP 17
#define PL_s_b__LP 18
#define TR_t_a_RT 0
#define TR_t_b_RT 1
#define TR_t_0_0_a_RT 2
#define TR_t_0_1_b_RT 3
#define TR_t_0_2_a_RT 4
#define TR_t_1_0_a_RT 5
#define TR_t_1_1_b_RT 6
#define TR_t_1_2_a_RT 7
#define TR_t_2_0_a_RT 8
#define TR_t_2_1_b_RT 9
#define TR_t_2_2_a_RT 10
#define TR_t_3_0_b_RT 11
#define TR_t_3_1_a_RT 12
#define TR_tt_0_0_RT 13
#define TR_tt_0_1_RT 14
#define TR_tt_0_2_RT 15
#define TR_tt_1_0_RT 16
#define TR_tt_1_1_RT 17
#define TR_tt_1_2_RT 18
#define TR_tt_2_0_RT 19
#define TR_tt_2_1_RT 20
#define TR_tt_2_2_RT 21
#define TR_tt_3_0_RT 22
#define TR_tt_3_1_RT 23

const double Dline=10;
const int _nb_Place_Counter=0;
const int _nb_Place_TargetState=1;
const int _nb_Place_s_0_=2;
const int _nb_Place_s_0_0=3;
const int _nb_Place_s_0_1=4;
const int _nb_Place_s_0_2=5;
const int _nb_Place_s_1_=6;
const int _nb_Place_s_1_0=7;
const int _nb_Place_s_1_1=8;
const int _nb_Place_s_1_2=9;
const int _nb_Place_s_2_=10;
const int _nb_Place_s_2_0=11;
const int _nb_Place_s_2_1=12;
const int _nb_Place_s_2_2=13;
const int _nb_Place_s_3_=14;
const int _nb_Place_s_3_0=15;
const int _nb_Place_s_3_1=16;
const int _nb_Place_s_a_=17;
const int _nb_Place_s_b_=18;
namespace hybridVar {
	double x_1=0;
	double x_2=0;
}
#include "magic.hpp"
void REHandling::print_state(const vector<int> &vect){}
void REHandling::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool REHandling::precondition(const abstractMarking &M){return true;}
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	magicReset();
	P->_PL_Counter =0  ;
	P->_PL_TargetState =0  ;
	P->_PL_s_0_ =1  ;
	P->_PL_s_0_0 =0  ;
	P->_PL_s_0_1 =0  ;
	P->_PL_s_0_2 =0  ;
	P->_PL_s_1_ =0  ;
	P->_PL_s_1_0 =0  ;
	P->_PL_s_1_1 =0  ;
	P->_PL_s_1_2 =0  ;
	P->_PL_s_2_ =0  ;
	P->_PL_s_2_0 =0  ;
	P->_PL_s_2_1 =0  ;
	P->_PL_s_2_2 =0  ;
	P->_PL_s_3_ =0  ;
	P->_PL_s_3_0 =0  ;
	P->_PL_s_3_1 =0  ;
	P->_PL_s_a_ =0  ;
	P->_PL_s_b_ =0  ;
	hybridVar::x_1=0;
	hybridVar::x_2=0;
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
s <<  setw(11) << "Counter ";
s <<  setw(11) << "TargetState ";
s <<  setw(11) << "s_0_ ";
s <<  setw(11) << "s_0_0 ";
s <<  setw(11) << "s_0_1 ";
s <<  setw(11) << "s_0_2 ";
s <<  setw(11) << "s_1_ ";
s <<  setw(11) << "s_1_0 ";
s <<  setw(11) << "s_1_1 ";
s <<  setw(11) << "s_1_2 ";
s <<  setw(11) << "s_2_ ";
s <<  setw(11) << "s_2_0 ";
s <<  setw(11) << "s_2_1 ";
s <<  setw(11) << "s_2_2 ";
s <<  setw(11) << "s_3_ ";
s <<  setw(11) << "s_3_0 ";
s <<  setw(11) << "s_3_1 ";
s <<  setw(11) << "s_a_ ";
s <<  setw(11) << "s_b_ ";
s <<  setw(11) << "x_1";
s <<  setw(11) << "x_2";
}

void abstractMarking::print(ostream &s,double eTime)const{
	s <<  setw(10) << print_magic(P->_PL_Counter)<<" ";
	s <<  setw(10) << print_magic(P->_PL_TargetState)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_0_)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_0_0)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_0_1)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_0_2)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_1_)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_1_0)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_1_1)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_1_2)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_2_)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_2_0)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_2_1)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_2_2)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_3_)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_3_0)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_3_1)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_a_)<<" ";
	s <<  setw(10) << print_magic(P->_PL_s_b_)<<" ";
s <<  setw(10)  << hybridVar::x_1+ eTime <<" ";
s <<  setw(10)  << hybridVar::x_2+ eTime <<" ";
}
void abstractMarking::printSedCmd(ostream &s)const{
	s << "-e 's/\\$Counter\\$/";
	s << print_magic(P->_PL_Counter);
	s <<"/g' ";
	s << "-e 's/\\$TargetState\\$/";
	s << print_magic(P->_PL_TargetState);
	s <<"/g' ";
	s << "-e 's/\\$s_0_\\$/";
	s << print_magic(P->_PL_s_0_);
	s <<"/g' ";
	s << "-e 's/\\$s_0_0\\$/";
	s << print_magic(P->_PL_s_0_0);
	s <<"/g' ";
	s << "-e 's/\\$s_0_1\\$/";
	s << print_magic(P->_PL_s_0_1);
	s <<"/g' ";
	s << "-e 's/\\$s_0_2\\$/";
	s << print_magic(P->_PL_s_0_2);
	s <<"/g' ";
	s << "-e 's/\\$s_1_\\$/";
	s << print_magic(P->_PL_s_1_);
	s <<"/g' ";
	s << "-e 's/\\$s_1_0\\$/";
	s << print_magic(P->_PL_s_1_0);
	s <<"/g' ";
	s << "-e 's/\\$s_1_1\\$/";
	s << print_magic(P->_PL_s_1_1);
	s <<"/g' ";
	s << "-e 's/\\$s_1_2\\$/";
	s << print_magic(P->_PL_s_1_2);
	s <<"/g' ";
	s << "-e 's/\\$s_2_\\$/";
	s << print_magic(P->_PL_s_2_);
	s <<"/g' ";
	s << "-e 's/\\$s_2_0\\$/";
	s << print_magic(P->_PL_s_2_0);
	s <<"/g' ";
	s << "-e 's/\\$s_2_1\\$/";
	s << print_magic(P->_PL_s_2_1);
	s <<"/g' ";
	s << "-e 's/\\$s_2_2\\$/";
	s << print_magic(P->_PL_s_2_2);
	s <<"/g' ";
	s << "-e 's/\\$s_3_\\$/";
	s << print_magic(P->_PL_s_3_);
	s <<"/g' ";
	s << "-e 's/\\$s_3_0\\$/";
	s << print_magic(P->_PL_s_3_0);
	s <<"/g' ";
	s << "-e 's/\\$s_3_1\\$/";
	s << print_magic(P->_PL_s_3_1);
	s <<"/g' ";
	s << "-e 's/\\$s_a_\\$/";
	s << print_magic(P->_PL_s_a_);
	s <<"/g' ";
	s << "-e 's/\\$s_b_\\$/";
	s << print_magic(P->_PL_s_b_);
	s <<"/g' ";
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_Counter;
		case 1: return P->_PL_TargetState;
		case 2: return P->_PL_s_0_;
		case 3: return P->_PL_s_0_0;
		case 4: return P->_PL_s_0_1;
		case 5: return P->_PL_s_0_2;
		case 6: return P->_PL_s_1_;
		case 7: return P->_PL_s_1_0;
		case 8: return P->_PL_s_1_1;
		case 9: return P->_PL_s_1_2;
		case 10: return P->_PL_s_2_;
		case 11: return P->_PL_s_2_0;
		case 12: return P->_PL_s_2_1;
		case 13: return P->_PL_s_2_2;
		case 14: return P->_PL_s_3_;
		case 15: return P->_PL_s_3_0;
		case 16: return P->_PL_s_3_1;
		case 17: return P->_PL_s_a_;
		case 18: return P->_PL_s_b_;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(19);
	v.reserve(20);
	size_t i = 0;
	v[i++]= P->_PL_Counter;
	v[i++]= P->_PL_TargetState;
	v[i++]= P->_PL_s_0_;
	v[i++]= P->_PL_s_0_0;
	v[i++]= P->_PL_s_0_1;
	v[i++]= P->_PL_s_0_2;
	v[i++]= P->_PL_s_1_;
	v[i++]= P->_PL_s_1_0;
	v[i++]= P->_PL_s_1_1;
	v[i++]= P->_PL_s_1_2;
	v[i++]= P->_PL_s_2_;
	v[i++]= P->_PL_s_2_0;
	v[i++]= P->_PL_s_2_1;
	v[i++]= P->_PL_s_2_2;
	v[i++]= P->_PL_s_3_;
	v[i++]= P->_PL_s_3_0;
	v[i++]= P->_PL_s_3_1;
	v[i++]= P->_PL_s_a_;
	v[i++]= P->_PL_s_b_;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	size_t i = 0;
	P->_PL_Counter = v[i++];
	P->_PL_TargetState = v[i++];
	P->_PL_s_0_ = v[i++];
	P->_PL_s_0_0 = v[i++];
	P->_PL_s_0_1 = v[i++];
	P->_PL_s_0_2 = v[i++];
	P->_PL_s_1_ = v[i++];
	P->_PL_s_1_0 = v[i++];
	P->_PL_s_1_1 = v[i++];
	P->_PL_s_1_2 = v[i++];
	P->_PL_s_2_ = v[i++];
	P->_PL_s_2_0 = v[i++];
	P->_PL_s_2_1 = v[i++];
	P->_PL_s_2_2 = v[i++];
	P->_PL_s_3_ = v[i++];
	P->_PL_s_3_0 = v[i++];
	P->_PL_s_3_1 = v[i++];
	P->_PL_s_a_ = v[i++];
	P->_PL_s_b_ = v[i++];
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
};
const int CustomDistrPoly::poly_table[]= { 
3,4,2,0,1,8,9,7,5,6,13,14,12,10,11,18,19,17,15,16,23,24,22,20,21,28,29,27,25,26,33,34,32,30,31,38,39,37,35,36,43,44,42,40,41,48,49,47,45,46,53,54,52,50,51,58,59,57,55,56,63,64,62,60,61,68,69,67,65,66,73,74,72,70,71,78,79,77,75,76,83,84,82,80,81,88,89,87,85,86,93,94,92,90,91,98,99,97,95,96,103,104,102,100,101,108,109,107,105,106,113,114,112,110,111,118,119,117,115,116,123,124,122,120,121,128,129,127,125,126,133,134,132,130,131,138,139,137,135,136,143,144,142,140,141,148,149,147,145,146,153,154,152,150,151,158,159,157,155,156,163,164,162,160,161,168,169,167,165,166,173,174,172,170,171,178,179,177,175,176,183,184,182,180,181,188,189,187,185,186,193,194,192,190,191,198,199,197,195,196,203,204,202,200,201,208,209,207,205,206,213,214,212,210,211,218,219,217,215,216,};
static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_2[2]= {TR_tt_0_0_RT, -1 }; /* t_0_0_a*/
static const int PE_PossiblyEnabled_3[2]= {TR_tt_0_1_RT, -1 }; /* t_0_1_b*/
static const int PE_PossiblyEnabled_4[2]= {TR_tt_0_2_RT, -1 }; /* t_0_2_a*/
static const int PE_PossiblyEnabled_5[2]= {TR_tt_1_0_RT, -1 }; /* t_1_0_a*/
static const int PE_PossiblyEnabled_6[2]= {TR_tt_1_1_RT, -1 }; /* t_1_1_b*/
static const int PE_PossiblyEnabled_7[2]= {TR_tt_1_2_RT, -1 }; /* t_1_2_a*/
static const int PE_PossiblyEnabled_8[2]= {TR_tt_2_0_RT, -1 }; /* t_2_0_a*/
static const int PE_PossiblyEnabled_9[2]= {TR_tt_2_1_RT, -1 }; /* t_2_1_b*/
static const int PE_PossiblyEnabled_10[2]= {TR_tt_2_2_RT, -1 }; /* t_2_2_a*/
static const int PE_PossiblyEnabled_11[2]= {TR_tt_3_0_RT, -1 }; /* t_3_0_b*/
static const int PE_PossiblyEnabled_12[2]= {TR_tt_3_1_RT, -1 }; /* t_3_1_a*/
static const int PE_PossiblyEnabled_13[5]= {TR_t_a_RT, TR_t_1_0_a_RT, TR_t_1_1_b_RT, TR_t_1_2_a_RT, -1 }; /* tt_0_0*/
static const int PE_PossiblyEnabled_14[5]= {TR_t_b_RT, TR_t_2_0_a_RT, TR_t_2_1_b_RT, TR_t_2_2_a_RT, -1 }; /* tt_0_1*/
static const int PE_PossiblyEnabled_15[4]= {TR_t_a_RT, TR_t_3_0_b_RT, TR_t_3_1_a_RT, -1 }; /* tt_0_2*/
static const int PE_PossiblyEnabled_16[5]= {TR_t_a_RT, TR_t_1_0_a_RT, TR_t_1_1_b_RT, TR_t_1_2_a_RT, -1 }; /* tt_1_0*/
static const int PE_PossiblyEnabled_17[5]= {TR_t_b_RT, TR_t_2_0_a_RT, TR_t_2_1_b_RT, TR_t_2_2_a_RT, -1 }; /* tt_1_1*/
static const int PE_PossiblyEnabled_18[4]= {TR_t_a_RT, TR_t_3_0_b_RT, TR_t_3_1_a_RT, -1 }; /* tt_1_2*/
static const int PE_PossiblyEnabled_19[5]= {TR_t_a_RT, TR_t_1_0_a_RT, TR_t_1_1_b_RT, TR_t_1_2_a_RT, -1 }; /* tt_2_0*/
static const int PE_PossiblyEnabled_20[5]= {TR_t_b_RT, TR_t_2_0_a_RT, TR_t_2_1_b_RT, TR_t_2_2_a_RT, -1 }; /* tt_2_1*/
static const int PE_PossiblyEnabled_21[4]= {TR_t_a_RT, TR_t_3_0_b_RT, TR_t_3_1_a_RT, -1 }; /* tt_2_2*/
static const int PE_PossiblyEnabled_22[5]= {TR_t_b_RT, TR_t_2_0_a_RT, TR_t_2_1_b_RT, TR_t_2_2_a_RT, -1 }; /* tt_3_0*/
static const int PE_PossiblyEnabled_23[4]= {TR_t_a_RT, TR_t_3_0_b_RT, TR_t_3_1_a_RT, -1 }; /* tt_3_1*/
const int* SPN::PossiblyEnabled[] = {EMPTY_array, EMPTY_array, PE_PossiblyEnabled_2, PE_PossiblyEnabled_3, PE_PossiblyEnabled_4, PE_PossiblyEnabled_5, PE_PossiblyEnabled_6, PE_PossiblyEnabled_7, PE_PossiblyEnabled_8, PE_PossiblyEnabled_9, PE_PossiblyEnabled_10, PE_PossiblyEnabled_11, PE_PossiblyEnabled_12, PE_PossiblyEnabled_13, PE_PossiblyEnabled_14, PE_PossiblyEnabled_15, PE_PossiblyEnabled_16, PE_PossiblyEnabled_17, PE_PossiblyEnabled_18, PE_PossiblyEnabled_19, PE_PossiblyEnabled_20, PE_PossiblyEnabled_21, PE_PossiblyEnabled_22, PE_PossiblyEnabled_23};

static const int PE_PossiblyDisabled_2[3]= {TR_t_0_1_b_RT, TR_t_0_2_a_RT, -1 }; /* t_0_0_a*/
static const int PE_PossiblyDisabled_3[3]= {TR_t_0_0_a_RT, TR_t_0_2_a_RT, -1 }; /* t_0_1_b*/
static const int PE_PossiblyDisabled_4[3]= {TR_t_0_0_a_RT, TR_t_0_1_b_RT, -1 }; /* t_0_2_a*/
static const int PE_PossiblyDisabled_5[3]= {TR_t_1_1_b_RT, TR_t_1_2_a_RT, -1 }; /* t_1_0_a*/
static const int PE_PossiblyDisabled_6[3]= {TR_t_1_0_a_RT, TR_t_1_2_a_RT, -1 }; /* t_1_1_b*/
static const int PE_PossiblyDisabled_7[3]= {TR_t_1_0_a_RT, TR_t_1_1_b_RT, -1 }; /* t_1_2_a*/
static const int PE_PossiblyDisabled_8[3]= {TR_t_2_1_b_RT, TR_t_2_2_a_RT, -1 }; /* t_2_0_a*/
static const int PE_PossiblyDisabled_9[3]= {TR_t_2_0_a_RT, TR_t_2_2_a_RT, -1 }; /* t_2_1_b*/
static const int PE_PossiblyDisabled_10[3]= {TR_t_2_0_a_RT, TR_t_2_1_b_RT, -1 }; /* t_2_2_a*/
static const int PE_PossiblyDisabled_11[2]= {TR_t_3_1_a_RT, -1 }; /* t_3_0_b*/
static const int PE_PossiblyDisabled_12[2]= {TR_t_3_0_b_RT, -1 }; /* t_3_1_a*/
const int* SPN::PossiblyDisabled[] = {EMPTY_array, EMPTY_array, PE_PossiblyDisabled_2, PE_PossiblyDisabled_3, PE_PossiblyDisabled_4, PE_PossiblyDisabled_5, PE_PossiblyDisabled_6, PE_PossiblyDisabled_7, PE_PossiblyDisabled_8, PE_PossiblyDisabled_9, PE_PossiblyDisabled_10, PE_PossiblyDisabled_11, PE_PossiblyDisabled_12, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

const int* SPN::FreeMarkDepT[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

static spn_trans TransArray[24] = { _trans(0,IMMEDIATE,0,1, 0, "t_a"), _trans(1,IMMEDIATE,0,1, 0, "t_b"), _trans(2,IMMEDIATE,0,1, 0, "t_0_0_a"), _trans(3,IMMEDIATE,0,1, 0, "t_0_1_b"), _trans(4,IMMEDIATE,0,1, 0, "t_0_2_a"), _trans(5,IMMEDIATE,0,1, 0, "t_1_0_a"), _trans(6,IMMEDIATE,0,1, 0, "t_1_1_b"), _trans(7,IMMEDIATE,0,1, 0, "t_1_2_a"), _trans(8,IMMEDIATE,0,1, 0, "t_2_0_a"), _trans(9,IMMEDIATE,0,1, 0, "t_2_1_b"), _trans(10,IMMEDIATE,0,1, 0, "t_2_2_a"), _trans(11,IMMEDIATE,0,1, 0, "t_3_0_b"), _trans(12,IMMEDIATE,0,1, 0, "t_3_1_a"), _trans(13,USERDEFINE,0,1, 0, "tt_0_0"), _trans(14,USERDEFINE,0,1, 0, "tt_0_1"), _trans(15,USERDEFINE,0,1, 0, "tt_0_2"), _trans(16,USERDEFINE,0,1, 0, "tt_1_0"), _trans(17,USERDEFINE,0,1, 0, "tt_1_1"), _trans(18,USERDEFINE,0,1, 0, "tt_1_2"), _trans(19,USERDEFINE,0,1, 0, "tt_2_0"), _trans(20,USERDEFINE,0,1, 0, "tt_2_1"), _trans(21,USERDEFINE,0,1, 0, "tt_2_2"), _trans(22,USERDEFINE,0,1, 0, "tt_3_0"), _trans(23,USERDEFINE,0,1, 0, "tt_3_1"),  }; 
SPN::SPN():
customDistr(*(new CustomDistrPoly())),pl(19), tr(24) ,Transition(TransArray,TransArray +24),Place(19),ParamDistr(10),TransitionConditions(24,0){
    Path ="twoears.grml";
    Place[0].label =" Counter";
    Place[0].isTraced = 1;
    Place[1].label =" TargetState";
    Place[1].isTraced = 1;
    Place[2].label =" s_0_";
    Place[2].isTraced = 1;
    Place[3].label =" s_0_0";
    Place[3].isTraced = 1;
    Place[4].label =" s_0_1";
    Place[4].isTraced = 1;
    Place[5].label =" s_0_2";
    Place[5].isTraced = 1;
    Place[6].label =" s_1_";
    Place[6].isTraced = 1;
    Place[7].label =" s_1_0";
    Place[7].isTraced = 1;
    Place[8].label =" s_1_1";
    Place[8].isTraced = 1;
    Place[9].label =" s_1_2";
    Place[9].isTraced = 1;
    Place[10].label =" s_2_";
    Place[10].isTraced = 1;
    Place[11].label =" s_2_0";
    Place[11].isTraced = 1;
    Place[12].label =" s_2_1";
    Place[12].isTraced = 1;
    Place[13].label =" s_2_2";
    Place[13].isTraced = 1;
    Place[14].label =" s_3_";
    Place[14].isTraced = 1;
    Place[15].label =" s_3_0";
    Place[15].isTraced = 1;
    Place[16].label =" s_3_1";
    Place[16].isTraced = 1;
    Place[17].label =" s_a_";
    Place[17].isTraced = 1;
    Place[18].label =" s_b_";
    Place[18].isTraced = 1;
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{
	if(!magicConditional(t))return false;

	switch (t){
		case 13:	//tt_0_0

			if (!(contains(Marking.P->_PL_s_0_0 , 1))) return false;
		return true;
		break;
		case 14:	//tt_0_1

			if (!(contains(Marking.P->_PL_s_0_1 , 1))) return false;
		return true;
		break;
		case 15:	//tt_0_2

			if (!(contains(Marking.P->_PL_s_0_2 , 1))) return false;
		return true;
		break;
		case 5:	//t_1_0_a
		case 6:	//t_1_1_b
		case 7:	//t_1_2_a

			if (!(contains(Marking.P->_PL_s_1_ , 1))) return false;
		return true;
		break;
		case 16:	//tt_1_0

			if (!(contains(Marking.P->_PL_s_1_0 , 1))) return false;
		return true;
		break;
		case 17:	//tt_1_1

			if (!(contains(Marking.P->_PL_s_1_1 , 1))) return false;
		return true;
		break;
		case 18:	//tt_1_2

			if (!(contains(Marking.P->_PL_s_1_2 , 1))) return false;
		return true;
		break;
		case 8:	//t_2_0_a
		case 9:	//t_2_1_b
		case 10:	//t_2_2_a

			if (!(contains(Marking.P->_PL_s_2_ , 1))) return false;
		return true;
		break;
		case 19:	//tt_2_0

			if (!(contains(Marking.P->_PL_s_2_0 , 1))) return false;
		return true;
		break;
		case 20:	//tt_2_1

			if (!(contains(Marking.P->_PL_s_2_1 , 1))) return false;
		return true;
		break;
		case 21:	//tt_2_2

			if (!(contains(Marking.P->_PL_s_2_2 , 1))) return false;
		return true;
		break;
		case 11:	//t_3_0_b
		case 12:	//t_3_1_a

			if (!(contains(Marking.P->_PL_s_3_ , 1))) return false;
		return true;
		break;
		case 22:	//tt_3_0

			if (!(contains(Marking.P->_PL_s_3_0 , 1))) return false;
		return true;
		break;
		case 23:	//tt_3_1

			if (!(contains(Marking.P->_PL_s_3_1 , 1))) return false;
		return true;
		break;
		case 0:	//t_a

			if (!(contains(Marking.P->_PL_s_a_ , 1))) return false;
		return true;
		break;
		case 1:	//t_b

			if (!(contains(Marking.P->_PL_s_b_ , 1))) return false;
		return true;
		break;
		default:	//t_0_0_a,t_0_1_b,t_0_2_a,

			if (!(contains(Marking.P->_PL_s_0_ , 1))) return false;
		return true;
		break;
	}
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;
	magicUpdate(t,time);
	double incrtime = time - lastTransitionTime;
	lastTransitionTime = time;
	hybridVar::x_1+= incrtime;
	hybridVar::x_2+= incrtime;

	switch (t){
		case 13:	//tt_0_0
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_0_0 -= 1;
			Marking.P->_PL_s_1_ += 1;
			Marking.P->_PL_s_a_ += 1;
{using namespace hybridVar;
x_2=0;}
	}
		break;
		case 14:	//tt_0_1
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_0_1 -= 1;
			Marking.P->_PL_s_2_ += 1;
			Marking.P->_PL_s_b_ += 1;
{using namespace hybridVar;
x_1=0;}
	}
		break;
		case 15:	//tt_0_2
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_0_2 -= 1;
			Marking.P->_PL_s_3_ += 1;
			Marking.P->_PL_s_a_ += 1;
{using namespace hybridVar;
x_2=0;}
	}
		break;
		case 16:	//tt_1_0
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_1_ += 1;
			Marking.P->_PL_s_1_0 -= 1;
			Marking.P->_PL_s_a_ += 1;
{using namespace hybridVar;
x_2=0;}
	}
		break;
		case 19:	//tt_2_0
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_1_ += 1;
			Marking.P->_PL_s_2_0 -= 1;
			Marking.P->_PL_s_a_ += 1;
{using namespace hybridVar;
x_2=0;}
	}
		break;
		case 17:	//tt_1_1
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_1_1 -= 1;
			Marking.P->_PL_s_2_ += 1;
			Marking.P->_PL_s_b_ += 1;
{using namespace hybridVar;
x_1=0;}
	}
		break;
		case 18:	//tt_1_2
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_1_2 -= 1;
			Marking.P->_PL_s_3_ += 1;
			Marking.P->_PL_s_a_ += 1;
{using namespace hybridVar;
x_2=0;}
	}
		break;
		case 20:	//tt_2_1
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_2_ += 1;
			Marking.P->_PL_s_2_1 -= 1;
			Marking.P->_PL_s_b_ += 1;
{using namespace hybridVar;
x_1=0;}
	}
		break;
		case 22:	//tt_3_0
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_2_ += 1;
			Marking.P->_PL_s_3_0 -= 1;
			Marking.P->_PL_s_b_ += 1;
{using namespace hybridVar;
x_1=0;}
	}
		break;
		case 21:	//tt_2_2
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_2_2 -= 1;
			Marking.P->_PL_s_3_ += 1;
			Marking.P->_PL_s_a_ += 1;
{using namespace hybridVar;
x_2=0;}
	}
		break;
		case 23:	//tt_3_1
{
			Marking.P->_PL_Counter += 1;
			Marking.P->_PL_TargetState += 1;
			Marking.P->_PL_s_3_ += 1;
			Marking.P->_PL_s_3_1 -= 1;
			Marking.P->_PL_s_a_ += 1;
{using namespace hybridVar;
x_2=0;}
	}
		break;
		case 2:	//t_0_0_a
{
			Marking.P->_PL_s_0_ -= 1;
			Marking.P->_PL_s_0_0 += 1;
	}
		break;
		case 3:	//t_0_1_b
{
			Marking.P->_PL_s_0_ -= 1;
			Marking.P->_PL_s_0_1 += 1;
	}
		break;
		case 4:	//t_0_2_a
{
			Marking.P->_PL_s_0_ -= 1;
			Marking.P->_PL_s_0_2 += 1;
	}
		break;
		case 5:	//t_1_0_a
{
			Marking.P->_PL_s_1_ -= 1;
			Marking.P->_PL_s_1_0 += 1;
	}
		break;
		case 6:	//t_1_1_b
{
			Marking.P->_PL_s_1_ -= 1;
			Marking.P->_PL_s_1_1 += 1;
	}
		break;
		case 7:	//t_1_2_a
{
			Marking.P->_PL_s_1_ -= 1;
			Marking.P->_PL_s_1_2 += 1;
	}
		break;
		case 8:	//t_2_0_a
{
			Marking.P->_PL_s_2_ -= 1;
			Marking.P->_PL_s_2_0 += 1;
	}
		break;
		case 9:	//t_2_1_b
{
			Marking.P->_PL_s_2_ -= 1;
			Marking.P->_PL_s_2_1 += 1;
	}
		break;
		case 10:	//t_2_2_a
{
			Marking.P->_PL_s_2_ -= 1;
			Marking.P->_PL_s_2_2 += 1;
	}
		break;
		case 11:	//t_3_0_b
{
			Marking.P->_PL_s_3_ -= 1;
			Marking.P->_PL_s_3_0 += 1;
	}
		break;
		case 12:	//t_3_1_a
{
			Marking.P->_PL_s_3_ -= 1;
			Marking.P->_PL_s_3_1 += 1;
	}
		break;
		case 0:	//t_a
{
			Marking.P->_PL_s_a_ -= 1;
	}
		break;
		case 1:	//t_b
{
			Marking.P->_PL_s_b_ -= 1;
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
		case 13:	//tt_0_0
	{
		ParamDistr[0]= ( double ) transDistrTab[0][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 23:	//tt_3_1
	{
		ParamDistr[0]= ( double ) transDistrTab[10][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 14:	//tt_0_1
	{
		ParamDistr[0]= ( double ) transDistrTab[1][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 15:	//tt_0_2
	{
		ParamDistr[0]= ( double ) transDistrTab[2][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 16:	//tt_1_0
	{
		ParamDistr[0]= ( double ) transDistrTab[3][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 17:	//tt_1_1
	{
		ParamDistr[0]= ( double ) transDistrTab[4][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 18:	//tt_1_2
	{
		ParamDistr[0]= ( double ) transDistrTab[5][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 19:	//tt_2_0
	{
		ParamDistr[0]= ( double ) transDistrTab[6][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 20:	//tt_2_1
	{
		ParamDistr[0]= ( double ) transDistrTab[7][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 21:	//tt_2_2
	{
		ParamDistr[0]= ( double ) transDistrTab[8][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 22:	//tt_3_0
	{
		ParamDistr[0]= ( double ) transDistrTab[9][min( 10-Marking.P->_PL_Counter, 4 )] ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
	}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

	switch (t){
		case 0:	//t_a
		case 1:	//t_b
		return (double)2 ;
		break;
		default:	//t_0_0_a,t_0_1_b,t_0_2_a,t_1_0_a,t_1_1_b,t_1_2_a,t_2_0_a,t_2_1_b,t_2_2_a,t_3_0_b,t_3_1_a,tt_0_0,tt_0_1,tt_0_2,tt_1_0,tt_1_1,tt_1_2,tt_2_0,tt_2_1,tt_2_2,tt_3_0,tt_3_1,
		return (double)1 ;
		break;
	}
}

REAL_TYPE SPN::GetWeight(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

	switch (t){
		case 2:	//t_0_0_a
		return (double)customDistr.evalPoly(219 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 3:	//t_0_1_b
		return (double)customDistr.evalPoly(223 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 4:	//t_0_2_a
		return (double)customDistr.evalPoly(227 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 5:	//t_1_0_a
		return (double)customDistr.evalPoly(231 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 6:	//t_1_1_b
		return (double)customDistr.evalPoly(235 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 7:	//t_1_2_a
		return (double)customDistr.evalPoly(239 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 8:	//t_2_0_a
		return (double)customDistr.evalPoly(243 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 9:	//t_2_1_b
		return (double)customDistr.evalPoly(247 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 10:	//t_2_2_a
		return (double)customDistr.evalPoly(251 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 11:	//t_3_0_b
		return (double)customDistr.evalPoly(255 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		case 12:	//t_3_1_a
		return (double)customDistr.evalPoly(259 + min( 10 -Marking.P->_PL_Counter, 4 ), {0.0,x_1,x_2,0.0}) ;
		break;
		default:	//t_a,t_b,tt_0_0,tt_0_1,tt_0_2,tt_1_0,tt_1_1,tt_1_2,tt_2_0,tt_2_1,tt_2_2,tt_3_0,tt_3_1,
		return (double)1 ;
		break;
	}
}

void SPN::Msimple(){
	vector<int> tab;
	Msimpletab = tab;
}
void SPN::reset() {
	lastTransitionTime = 0;
	Marking.resetToInitMarking();
}

