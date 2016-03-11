#include "spn.hpp"
#include <iomanip>
using namespace std;
#define PL_TargetState_LP 0
#define PL_s_0__LP 1
#define PL_s_0_0_LP 2
#define PL_s_0_1_LP 3
#define PL_s_0_2_LP 4
#define PL_s_1__LP 5
#define PL_s_1_0_LP 6
#define PL_s_1_1_LP 7
#define PL_s_1_2_LP 8
#define PL_s_2__LP 9
#define PL_s_2_0_LP 10
#define PL_s_2_1_LP 11
#define PL_s_2_2_LP 12
#define PL_s_3__LP 13
#define PL_s_3_0_LP 14
#define PL_s_3_1_LP 15
#define PL_s_a__LP 16
#define PL_s_b__LP 17
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

const int _nb_Place_TargetState=0;
const int _nb_Place_s_0_=1;
const int _nb_Place_s_0_0=2;
const int _nb_Place_s_0_1=3;
const int _nb_Place_s_0_2=4;
const int _nb_Place_s_1_=5;
const int _nb_Place_s_1_0=6;
const int _nb_Place_s_1_1=7;
const int _nb_Place_s_1_2=8;
const int _nb_Place_s_2_=9;
const int _nb_Place_s_2_0=10;
const int _nb_Place_s_2_1=11;
const int _nb_Place_s_2_2=12;
const int _nb_Place_s_3_=13;
const int _nb_Place_s_3_0=14;
const int _nb_Place_s_3_1=15;
const int _nb_Place_s_a_=16;
const int _nb_Place_s_b_=17;
namespace hybridVar {
	double x_1=0;
	double x_2=0;
}
void REHandling::print_state(const vector<int> &vect){}
void REHandling::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool REHandling::precondition(const abstractMarking &M){return true;}
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
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
}

void abstractMarking::print(ostream &s,double eTime)const{
}
void abstractMarking::printSedCmd(ostream &s)const{
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_TargetState;
		case 1: return P->_PL_s_0_;
		case 2: return P->_PL_s_0_0;
		case 3: return P->_PL_s_0_1;
		case 4: return P->_PL_s_0_2;
		case 5: return P->_PL_s_1_;
		case 6: return P->_PL_s_1_0;
		case 7: return P->_PL_s_1_1;
		case 8: return P->_PL_s_1_2;
		case 9: return P->_PL_s_2_;
		case 10: return P->_PL_s_2_0;
		case 11: return P->_PL_s_2_1;
		case 12: return P->_PL_s_2_2;
		case 13: return P->_PL_s_3_;
		case 14: return P->_PL_s_3_0;
		case 15: return P->_PL_s_3_1;
		case 16: return P->_PL_s_a_;
		case 17: return P->_PL_s_b_;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(18);
	v.reserve(19);
	size_t i = 0;
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
		ptable = parse<3>("data.data");
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

};
const int CustomDistrPoly::poly_table[]= { 
3,4,2,0,1,8,9,7,5,6,13,14,12,10,11,18,19,17,15,16,23,24,22,20,21,28,29,27,25,26,33,34,32,30,31,38,39,37,35,36,43,44,42,40,41,48,49,47,45,46,53,54,52,50,51,};
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

static spn_trans TransArray[24] = { _trans(0,IMMEDIATE,0,1, 0), _trans(1,IMMEDIATE,0,1, 0), _trans(2,IMMEDIATE,0,1, 0), _trans(3,IMMEDIATE,0,1, 0), _trans(4,IMMEDIATE,0,1, 0), _trans(5,IMMEDIATE,0,1, 0), _trans(6,IMMEDIATE,0,1, 0), _trans(7,IMMEDIATE,0,1, 0), _trans(8,IMMEDIATE,0,1, 0), _trans(9,IMMEDIATE,0,1, 0), _trans(10,IMMEDIATE,0,1, 0), _trans(11,IMMEDIATE,0,1, 0), _trans(12,IMMEDIATE,0,1, 0), _trans(13,USERDEFINE,0,1, 0), _trans(14,USERDEFINE,0,1, 0), _trans(15,USERDEFINE,0,1, 0), _trans(16,USERDEFINE,0,1, 0), _trans(17,USERDEFINE,0,1, 0), _trans(18,USERDEFINE,0,1, 0), _trans(19,USERDEFINE,0,1, 0), _trans(20,USERDEFINE,0,1, 0), _trans(21,USERDEFINE,0,1, 0), _trans(22,USERDEFINE,0,1, 0), _trans(23,USERDEFINE,0,1, 0),  }; 
SPN::SPN():
customDistr(*(new CustomDistrPoly())),pl(18), tr(24) ,Transition(TransArray,TransArray +24),Place(18),ParamDistr(10),TransitionConditions(24,0){
    Path ="twoears.prism.grml";
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{

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
	double incrtime = time - lastTransitionTime;
	lastTransitionTime = time;
	hybridVar::x_1+= incrtime;
	hybridVar::x_2+= incrtime;

	switch (t){
		case 13:	//tt_0_0
{
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
		ParamDistr[0]= ( double ) 0 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 14:	//tt_0_1
	{
		ParamDistr[0]= ( double ) 1 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 23:	//tt_3_1
	{
		ParamDistr[0]= ( double ) 10 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 15:	//tt_0_2
	{
		ParamDistr[0]= ( double ) 2 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 16:	//tt_1_0
	{
		ParamDistr[0]= ( double ) 3 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 17:	//tt_1_1
	{
		ParamDistr[0]= ( double ) 4 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 18:	//tt_1_2
	{
		ParamDistr[0]= ( double ) 5 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 19:	//tt_2_0
	{
		ParamDistr[0]= ( double ) 6 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 20:	//tt_2_1
	{
		ParamDistr[0]= ( double ) 7 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 21:	//tt_2_2
	{
		ParamDistr[0]= ( double ) 8 ;
		ParamDistr[1]= ( double ) x_1 ;
		ParamDistr[2]= ( double ) x_2 ;
	}

		break;
		case 22:	//tt_3_0
	{
		ParamDistr[0]= ( double ) 9 ;
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
		case 11:	//t_3_0_b
		return (double)0.0+(-0.00138888888888889)*pow(x_1,6)+(-0.00833333333333335)*pow(x_1,5)+(-0.166666666666666)*pow(x_1,4)+(-1.77777777777778)*pow(x_1,3)+(-14.6666666666667)*pow(x_1,2)+(-80.8833333333334)*x_1+(439.187500000000) ;
		break;
		case 5:	//t_1_0_a
		return (double)0.0+(0.00138888888888889)*pow(x_1,6)+(-0.0333333333333333)*pow(x_1,5)+(0.479166666666666)*pow(x_1,4)+(-5.27777777777778)*pow(x_1,3)+(43.6041666666667)*pow(x_1,2)+(-240.283333333333)*x_1+(201.509722222222) ;
		break;
		case 9:	//t_2_1_b
		return (double)0.0+(0.00138888888888889)*pow(x_2,6)+(-0.0333333333333333)*pow(x_2,5)+(0.479166666666666)*pow(x_2,4)+(-5.27777777777778)*pow(x_2,3)+(43.6041666666666)*pow(x_2,2)+(-240.283333333333)*x_2+(341.683333333333) ;
		break;
		case 12:	//t_3_1_a
		return (double)0.0+(0.00277777777777778)*pow(x_1,6)+(-0.0416666666666666)*pow(x_1,5)+(0.729166666666666)*pow(x_1,4)+(-6.22222222222222)*pow(x_1,3)+(66.1041666666667)*pow(x_1,2)+(-283.416666666667)*x_1+(341.683333333333) ;
		break;
		case 4:	//t_0_2_a
		case 10:	//t_2_2_a
		return (double)0.0+(118.838888888889) ;
		break;
		case 2:	//t_0_0_a
		case 8:	//t_2_0_a
		return (double)0.0+(201.509722222222) ;
		break;
		case 3:	//t_0_1_b
		case 6:	//t_1_1_b
		return (double)0.0+(341.683333333333) ;
		break;
		case 7:	//t_1_2_a
		return (double)0.0+(5.55111512312578e-17)*pow(x_1,5)+(4.44089209850063e-16)*pow(x_1,4)+(8.88178419700125e-16)*pow(x_1,3)+(5.68434188608080e-14)*x_1+(118.838888888889) ;
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

