#include "spn.hpp"
#include <iomanip>
using namespace std;
#define PL_int0_LP 0
#define PL_ploadm0_LP 1
#define PL_pf0_LP 2
#define PL_ph1m0_LP 3
#define PL_pb1_LP 4
#define PL_readym1_LP 5
#define PL_int1_LP 6
#define PL_block1_LP 7
#define TR_unload1_RT 0
#define TR_fin0m_RT 1
#define TR_pend1_RT 2
#define TR_bin1m_RT 3
#define TR_predo2_RT 4
#define TR_fin0p_RT 5
#define TR_pend2_RT 6
#define TR_bin1p_RT 7
#define TR_bex0_RT 8
#define TR_fex1_RT 9

const double bt=0.5;
const double fl=1;
const double fr=1;
const int _nb_Place_int0=0;
const int _nb_Place_ploadm0=1;
const int _nb_Place_pf0=2;
const int _nb_Place_ph1m0=3;
const int _nb_Place_pb1=4;
const int _nb_Place_readym1=5;
const int _nb_Place_int1=6;
const int _nb_Place_block1=7;
namespace hybridVar {
}
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include "marking.hpp"
#include "markingImpl.hpp"
proc_Domain operator + (const proc_Token& t1 ,const proc_Token& t2 ){
	proc_Domain d; d += t1; d+=t2 ;
	return d;
}
std::ostream& operator << (std::ostream& out, const proc_Domain& x) {
	stringstream outprintloot;
	for(size_t c0 = 0 ; c0< Color_proc_Total; c0++ )
		if(x.mult[c0])
					outprintloot << x.mult[c0]<< "<" << Color_proc_names[c0]<< ">,";
	out << "(" << outprintloot.str() << ")";
	return out;
}
inline bool contains(const proc_Domain& d1, const proc_Domain& d2){	return (d1-d2) > -1;
}
inline bool contains(const proc_Domain& d1, const proc_Token& tok){	return d1 >= tok;
}
mach1_Domain operator + (const mach1_Token& t1 ,const mach1_Token& t2 ){
	mach1_Domain d; d += t1; d+=t2 ;
	return d;
}
std::ostream& operator << (std::ostream& out, const mach1_Domain& x) {
	stringstream outprintloot;
	for(size_t c0 = 0 ; c0< Color_mach1_Total; c0++ )
		if(x.mult[c0])
					outprintloot << x.mult[c0]<< "<" << Color_mach1_names[c0]<< ">,";
	out << "(" << outprintloot.str() << ")";
	return out;
}
inline bool contains(const mach1_Domain& d1, const mach1_Domain& d2){	return (d1-d2) > -1;
}
inline bool contains(const mach1_Domain& d1, const mach1_Token& tok){	return d1 >= tok;
}
Block_Domain operator + (const Block_Token& t1 ,const Block_Token& t2 ){
	Block_Domain d; d += t1; d+=t2 ;
	return d;
}
std::ostream& operator << (std::ostream& out, const Block_Domain& x) {
	stringstream outprintloot;
	for(size_t c0 = 0 ; c0< Color_proc_Total; c0++ )
	for(size_t c1 = 0 ; c1< Color_mach1_Total; c1++ )
		if(x.mult[c0][c1])
					outprintloot << x.mult[c0][c1]<< "<" << Color_proc_names[c0] << "," << Color_mach1_names[c1]<< ">,";
	out << "(" << outprintloot.str() << ")";
	return out;
}
inline bool contains(const Block_Domain& d1, const Block_Domain& d2){	return (d1-d2) > -1;
}
inline bool contains(const Block_Domain& d1, const Block_Token& tok){	return d1 >= tok;
}

void abstractMarking::resetToInitMarking(){
	P->_PL_int0 =((proc_Domain(Color_proc_All) * (1 ))) ;
	P->_PL_ploadm0 =0  ;
	P->_PL_pf0 =0  ;
	P->_PL_ph1m0 =0  ;
	P->_PL_pb1 =0  ;
	P->_PL_readym1 =0  ;
	P->_PL_int1 =0  ;
	P->_PL_block1 =((mach1_Domain(Color_mach1_All) * (1 ))) ;
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
s <<  setw(7) << "int0 ";
s <<  setw(7) << "ploadm0 ";
s <<  setw(7) << "pf0 ";
s <<  setw(7) << "ph1m0 ";
s <<  setw(7) << "pb1 ";
s <<  setw(7) << "readym1 ";
s <<  setw(7) << "int1 ";
s <<  setw(7) << "block1 ";
}

void abstractMarking::print(ostream &s,double eTime)const{
	s <<  setw(6) << P->_PL_int0<<" ";
	s <<  setw(6) << P->_PL_ploadm0<<" ";
	s <<  setw(6) << P->_PL_pf0<<" ";
	s <<  setw(6) << P->_PL_ph1m0<<" ";
	s <<  setw(6) << P->_PL_pb1<<" ";
	s <<  setw(6) << P->_PL_readym1<<" ";
	s <<  setw(6) << P->_PL_int1<<" ";
	s <<  setw(6) << P->_PL_block1<<" ";
}
void abstractMarking::printSedCmd(ostream &s)const{
	s << "-e 's/\\$int0\\$/";
	s << P->_PL_int0;
	s <<"/g' ";
	s << "-e 's/\\$ploadm0\\$/";
	s << P->_PL_ploadm0;
	s <<"/g' ";
	s << "-e 's/\\$pf0\\$/";
	s << P->_PL_pf0;
	s <<"/g' ";
	s << "-e 's/\\$ph1m0\\$/";
	s << P->_PL_ph1m0;
	s <<"/g' ";
	s << "-e 's/\\$pb1\\$/";
	s << P->_PL_pb1;
	s <<"/g' ";
	s << "-e 's/\\$readym1\\$/";
	s << P->_PL_readym1;
	s <<"/g' ";
	s << "-e 's/\\$int1\\$/";
	s << P->_PL_int1;
	s <<"/g' ";
	s << "-e 's/\\$block1\\$/";
	s << P->_PL_block1;
	s <<"/g' ";
}

int abstractMarking::getNbOfTokens(int p)const {
	exit(EXIT_FAILURE);
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(52);
	v.reserve(53);
	copy((int*) P,(int*)P + 52,v.data() );
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	copy((int*)v.data(),(int*)v.data() + v.size(), (int*)P );
};

bool abstractBinding::next() {
	idcount++;
	if(P->x.mult >= 0){
		if (! P->x.islast()){	P->x.iter(); return true; };
		P->x = proc_Token();
	}
	if(P->y.mult >= 0){
		if (! P->y.islast()){	P->y.iter(); return true; };
		P->y = proc_Token();
	}
	if(P->b.mult >= 0){
		if (! P->b.islast()){	P->b.iter(); return true; };
		P->b = mach1_Token();
	}
	return false;
};


void abstractMarking::Symmetrize(){
    
}


abstractBinding::abstractBinding() {
 P= new abstractBindingImpl;
       idcount=0;
}
abstractBinding::abstractBinding(const abstractBinding& m) {
 P= new abstractBindingImpl;
 *P = *m.P;
	idcount = m.idcount;
}
abstractBinding::~abstractBinding() {
 delete P;
}
abstractBinding& abstractBinding::operator = (const abstractBinding& m) {
 *P = *m.P;
	idcount = m.idcount;
       return *this;
}
void abstractBinding::print()const{
	std::cerr << "\tx: ";P->x.print();
	std::cerr << "\ty: ";P->y.print();
	std::cerr << "\tb: ";P->b.print();
}
int abstractBinding::id()const{
	return idcount;
}
int abstractBinding::idTotal()const{
	 return P->x.c0 + Color_proc_Total *(P->y.c0 + Color_proc_Total *(P->b.c0 + Color_mach1_Total *(0)));
}
const char *Color_proc_names[Color_proc_Total] = {
"p1","p2","p3","p4","p5",
};
const char *Color_mach1_names[Color_mach1_Total] = {
"B1","B2",
};
static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_0[3]= {TR_pend1_RT, TR_bex0_RT, -1 }; /* unload1*/
static const int PE_PossiblyEnabled_1[4]= {TR_bin1m_RT, TR_fin0p_RT, TR_bin1p_RT, -1 }; /* fin0m*/
static const int PE_PossiblyEnabled_2[3]= {TR_unload1_RT, TR_pend2_RT, -1 }; /* pend1*/
static const int PE_PossiblyEnabled_3[4]= {TR_fin0m_RT, TR_fin0p_RT, TR_bin1p_RT, -1 }; /* bin1m*/
static const int PE_PossiblyEnabled_4[3]= {TR_pend1_RT, TR_bex0_RT, -1 }; /* predo2*/
static const int PE_PossiblyEnabled_5[3]= {TR_pend1_RT, TR_bex0_RT, -1 }; /* fin0p*/
static const int PE_PossiblyEnabled_6[3]= {TR_predo2_RT, TR_fex1_RT, -1 }; /* pend2*/
static const int PE_PossiblyEnabled_7[3]= {TR_pend1_RT, TR_bex0_RT, -1 }; /* bin1p*/
static const int PE_PossiblyEnabled_8[5]= {TR_fin0m_RT, TR_bin1m_RT, TR_fin0p_RT, TR_bin1p_RT, -1 }; /* bex0*/
static const int PE_PossiblyEnabled_9[5]= {TR_fin0m_RT, TR_bin1m_RT, TR_fin0p_RT, TR_bin1p_RT, -1 }; /* fex1*/
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, PE_PossiblyEnabled_2, PE_PossiblyEnabled_3, PE_PossiblyEnabled_4, PE_PossiblyEnabled_5, PE_PossiblyEnabled_6, PE_PossiblyEnabled_7, PE_PossiblyEnabled_8, PE_PossiblyEnabled_9};

static const int PE_PossiblyDisabled_0[2]= {TR_pend2_RT, -1 }; /* unload1*/
static const int PE_PossiblyDisabled_1[4]= {TR_bin1m_RT, TR_fin0p_RT, TR_bin1p_RT, -1 }; /* fin0m*/
static const int PE_PossiblyDisabled_2[2]= {TR_bex0_RT, -1 }; /* pend1*/
static const int PE_PossiblyDisabled_3[4]= {TR_fin0m_RT, TR_fin0p_RT, TR_bin1p_RT, -1 }; /* bin1m*/
static const int PE_PossiblyDisabled_4[2]= {TR_fex1_RT, -1 }; /* predo2*/
static const int PE_PossiblyDisabled_5[4]= {TR_fin0m_RT, TR_bin1m_RT, TR_bin1p_RT, -1 }; /* fin0p*/
static const int PE_PossiblyDisabled_6[2]= {TR_unload1_RT, -1 }; /* pend2*/
static const int PE_PossiblyDisabled_7[4]= {TR_fin0m_RT, TR_bin1m_RT, TR_fin0p_RT, -1 }; /* bin1p*/
static const int PE_PossiblyDisabled_8[2]= {TR_pend1_RT, -1 }; /* bex0*/
static const int PE_PossiblyDisabled_9[2]= {TR_predo2_RT, -1 }; /* fex1*/
const int* SPN::PossiblyDisabled[] = {PE_PossiblyDisabled_0, PE_PossiblyDisabled_1, PE_PossiblyDisabled_2, PE_PossiblyDisabled_3, PE_PossiblyDisabled_4, PE_PossiblyDisabled_5, PE_PossiblyDisabled_6, PE_PossiblyDisabled_7, PE_PossiblyDisabled_8, PE_PossiblyDisabled_9};

const int* SPN::FreeMarkDepT[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

static spn_trans TransArray[10] = { _trans(0,EXPONENTIAL,0,50, 0, "unload1"), _trans(1,EXPONENTIAL,0,50, 0, "fin0m"), _trans(2,EXPONENTIAL,0,50, 0, "pend1"), _trans(3,EXPONENTIAL,0,50, 0, "bin1m"), _trans(4,EXPONENTIAL,0,50, 0, "predo2"), _trans(5,IMMEDIATE,0,50, 0, "fin0p"), _trans(6,EXPONENTIAL,0,50, 0, "pend2"), _trans(7,IMMEDIATE,0,50, 0, "bin1p"), _trans(8,EXPONENTIAL,0,50, 0, "bex0"), _trans(9,EXPONENTIAL,0,50, 0, "fex1"),  }; 
SPN::SPN():
pl(8), tr(10) ,Transition(TransArray,TransArray +10),Place(8),ParamDistr(10),TransitionConditions(10,0){
    Path ="FMS.grml";
    Place[0].label =" int0";
    Place[0].isTraced = 1;
    Place[1].label =" ploadm0";
    Place[1].isTraced = 1;
    Place[2].label =" pf0";
    Place[2].isTraced = 1;
    Place[3].label =" ph1m0";
    Place[3].isTraced = 1;
    Place[4].label =" pb1";
    Place[4].isTraced = 1;
    Place[5].label =" readym1";
    Place[5].isTraced = 1;
    Place[6].label =" int1";
    Place[6].isTraced = 1;
    Place[7].label =" block1";
    Place[7].isTraced = 1;
	{abstractBinding bl = Transition[0].bindingList[0];
	bl.P->y.mult = -1;
	while(bl.next()){
		{
			bl.idcount = Transition[0].bindingList.size();
			Transition[0].bindingList.push_back( bl );
			Transition[0].bindingLinkTable[bl.idTotal()]= Transition[0].bindingList.size()-1; 
		}
	}}
	{abstractBinding bl = Transition[1].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[1].bindingList.size();
			Transition[1].bindingList.push_back( bl );
			Transition[1].bindingLinkTable[bl.idTotal()]= Transition[1].bindingList.size()-1; 
		}
	}}
	{abstractBinding bl = Transition[2].bindingList[0];
	bl.P->y.mult = -1;
	while(bl.next()){
		{
			bl.idcount = Transition[2].bindingList.size();
			Transition[2].bindingList.push_back( bl );
			Transition[2].bindingLinkTable[bl.idTotal()]= Transition[2].bindingList.size()-1; 
		}
	}}
	{abstractBinding bl = Transition[3].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[3].bindingList.size();
			Transition[3].bindingList.push_back( bl );
			Transition[3].bindingLinkTable[bl.idTotal()]= Transition[3].bindingList.size()-1; 
		}
	}}
	{abstractBinding bl = Transition[4].bindingList[0];
	bl.P->y.mult = -1;
	while(bl.next()){
		{
			bl.idcount = Transition[4].bindingList.size();
			Transition[4].bindingList.push_back( bl );
			Transition[4].bindingLinkTable[bl.idTotal()]= Transition[4].bindingList.size()-1; 
		}
	}}
	{abstractBinding bl = Transition[5].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[5].bindingList.size();
			Transition[5].bindingList.push_back( bl );
			Transition[5].bindingLinkTable[bl.idTotal()]= Transition[5].bindingList.size()-1; 
		}
	}}
	{abstractBinding bl = Transition[6].bindingList[0];
	bl.P->y.mult = -1;
	while(bl.next()){
		{
			bl.idcount = Transition[6].bindingList.size();
			Transition[6].bindingList.push_back( bl );
			Transition[6].bindingLinkTable[bl.idTotal()]= Transition[6].bindingList.size()-1; 
		}
	}}
	{abstractBinding bl = Transition[7].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[7].bindingList.size();
			Transition[7].bindingList.push_back( bl );
			Transition[7].bindingLinkTable[bl.idTotal()]= Transition[7].bindingList.size()-1; 
		}
	}}
	{abstractBinding bl = Transition[8].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[8].bindingList.size();
			Transition[8].bindingList.push_back( bl );
			Transition[8].bindingLinkTable[bl.idTotal()]= Transition[8].bindingList.size()-1; 
		}
	}}
	{abstractBinding bl = Transition[9].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[9].bindingList.size();
			Transition[9].bindingList.push_back( bl );
			Transition[9].bindingLinkTable[bl.idTotal()]= Transition[9].bindingList.size()-1; 
		}
	}}
    Msimple();
vector <double> Rate_Table_init (tr);
Rate_Table = Rate_Table_init;
Origine_Rate_Table = Rate_Table_init;
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{

	switch (t){
		case 8:	//bex0

			if ( !(((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_ploadm0 , ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )))))) return false;
		return true;
		break;
		case 9:	//fex1

			if ( !(((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_readym1 , ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )))))) return false;
		return true;
		break;
		case 2:	//pend1

			if ( !(((Block_Token(b.P->x, b.P->b) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_ploadm0 , ((Block_Token(b.P->x, b.P->b) * (1 )))))) return false;
		return true;
		break;
		case 4:	//predo2

			if ( !(((Block_Token(b.P->x, b.P->b) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_readym1 , ((Block_Token(b.P->x, b.P->b) * (1 )))))) return false;
		return true;
		break;
		case 1:	//fin0m

			if ( !(((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_int0 , ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )))))) return false;
			if ( !(((mach1_Token(b.P->b) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_block1 , ((mach1_Token(b.P->b) * (1 )))))) return false;
		return true;
		break;
		case 5:	//fin0p

			if ( !(((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_int0 , ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )))))) return false;
			if ( !(((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_pf0 , ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )))))) return false;
			if ( !(((mach1_Token(b.P->b) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_block1 , ((mach1_Token(b.P->b) * (1 )))))) return false;
		return true;
		break;
		case 3:	//bin1m

			if ( !(((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_int1 , ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )))))) return false;
			if ( !(((mach1_Token(b.P->b) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_block1 , ((mach1_Token(b.P->b) * (1 )))))) return false;
		return true;
		break;
		case 7:	//bin1p

			if ( !(((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_pb1 , ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )))))) return false;
			if ( !(((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_int1 , ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )))))) return false;
			if ( !(((mach1_Token(b.P->b) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_block1 , ((mach1_Token(b.P->b) * (1 )))))) return false;
		return true;
		break;
		default:	//unload1,pend2,

			if ( !(((Block_Token(b.P->x, b.P->b) * (1 ))) < 1)) 
			if (!(contains(Marking.P->_PL_ph1m0 , ((Block_Token(b.P->x, b.P->b) * (1 )))))) return false;
		return true;
		break;
	}
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;

	switch (t){
		case 6:	//pend2
{
			Block_Domain tmpMark_ph1m0 = Marking.P->_PL_ph1m0;
			Block_Domain tmpMark_readym1 = Marking.P->_PL_readym1;
			Marking.P->_PL_ph1m0 -= ((Block_Token(b.P->x, b.P->b) * (1 )));
			Marking.P->_PL_readym1 += ((Block_Token(b.P->x, b.P->b) * (1 )));
	}
		break;
		case 0:	//unload1
{
			Block_Domain tmpMark_ploadm0 = Marking.P->_PL_ploadm0;
			Block_Domain tmpMark_ph1m0 = Marking.P->_PL_ph1m0;
			Marking.P->_PL_ploadm0 += ((Block_Token(b.P->x, b.P->b) * (1 )));
			Marking.P->_PL_ph1m0 -= ((Block_Token(b.P->x, b.P->b) * (1 )));
	}
		break;
		case 2:	//pend1
{
			Block_Domain tmpMark_ploadm0 = Marking.P->_PL_ploadm0;
			Block_Domain tmpMark_ph1m0 = Marking.P->_PL_ph1m0;
			Marking.P->_PL_ploadm0 -= ((Block_Token(b.P->x, b.P->b) * (1 )));
			Marking.P->_PL_ph1m0 += ((Block_Token(b.P->x, b.P->b) * (1 )));
	}
		break;
		case 4:	//predo2
{
			Block_Domain tmpMark_ploadm0 = Marking.P->_PL_ploadm0;
			Block_Domain tmpMark_readym1 = Marking.P->_PL_readym1;
			Marking.P->_PL_ploadm0 += ((Block_Token(b.P->x, b.P->b) * (1 )));
			Marking.P->_PL_readym1 -= ((Block_Token(b.P->x, b.P->b) * (1 )));
	}
		break;
		case 7:	//bin1p
{
			Block_Domain tmpMark_ploadm0 = Marking.P->_PL_ploadm0;
			proc_Domain tmpMark_pb1 = Marking.P->_PL_pb1;
			proc_Domain tmpMark_int1 = Marking.P->_PL_int1;
			mach1_Domain tmpMark_block1 = Marking.P->_PL_block1;
			Marking.P->_PL_ploadm0 += ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )));
			Marking.P->_PL_pb1 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_int1 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 -= ((mach1_Token(b.P->b) * (1 )));
	}
		break;
		case 9:	//fex1
{
			Block_Domain tmpMark_readym1 = Marking.P->_PL_readym1;
			proc_Domain tmpMark_int1 = Marking.P->_PL_int1;
			mach1_Domain tmpMark_block1 = Marking.P->_PL_block1;
			Marking.P->_PL_readym1 -= ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )));
			Marking.P->_PL_int1 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 += ((mach1_Token(b.P->b) * (1 )));
	}
		break;
		case 8:	//bex0
{
			proc_Domain tmpMark_int0 = Marking.P->_PL_int0;
			Block_Domain tmpMark_ploadm0 = Marking.P->_PL_ploadm0;
			mach1_Domain tmpMark_block1 = Marking.P->_PL_block1;
			Marking.P->_PL_int0 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_ploadm0 -= ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )));
			Marking.P->_PL_block1 += ((mach1_Token(b.P->b) * (1 )));
	}
		break;
		case 5:	//fin0p
{
			proc_Domain tmpMark_int0 = Marking.P->_PL_int0;
			Block_Domain tmpMark_ploadm0 = Marking.P->_PL_ploadm0;
			proc_Domain tmpMark_pf0 = Marking.P->_PL_pf0;
			mach1_Domain tmpMark_block1 = Marking.P->_PL_block1;
			Marking.P->_PL_int0 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_ploadm0 += ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )));
			Marking.P->_PL_pf0 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 -= ((mach1_Token(b.P->b) * (1 )));
	}
		break;
		case 1:	//fin0m
{
			proc_Domain tmpMark_int0 = Marking.P->_PL_int0;
			proc_Domain tmpMark_pf0 = Marking.P->_PL_pf0;
			mach1_Domain tmpMark_block1 = Marking.P->_PL_block1;
			Marking.P->_PL_int0 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_int0 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_pf0 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 -= ((mach1_Token(b.P->b) * (1 )));
			Marking.P->_PL_block1 += ((mach1_Token(b.P->b) * (1 )));
	}
		break;
		case 3:	//bin1m
{
			proc_Domain tmpMark_pb1 = Marking.P->_PL_pb1;
			proc_Domain tmpMark_int1 = Marking.P->_PL_int1;
			mach1_Domain tmpMark_block1 = Marking.P->_PL_block1;
			Marking.P->_PL_pb1 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_int1 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_int1 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 -= ((mach1_Token(b.P->b) * (1 )));
			Marking.P->_PL_block1 += ((mach1_Token(b.P->b) * (1 )));
	}
		break;
	}
}

void SPN::unfire(TR_PL_ID t, const abstractBinding &b){

	switch (t){
		case 1:	//fin0m
			Marking.P->_PL_int0 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_int0 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_pf0 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 += ((mach1_Token(b.P->b) * (1 )));
			Marking.P->_PL_block1 -= ((mach1_Token(b.P->b) * (1 )));

		break;
		case 5:	//fin0p
			Marking.P->_PL_int0 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_ploadm0 -= ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )));
			Marking.P->_PL_pf0 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 += ((mach1_Token(b.P->b) * (1 )));

		break;
		case 8:	//bex0
			Marking.P->_PL_int0 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_ploadm0 += ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )));
			Marking.P->_PL_block1 -= ((mach1_Token(b.P->b) * (1 )));

		break;
		case 3:	//bin1m
			Marking.P->_PL_pb1 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_int1 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_int1 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 += ((mach1_Token(b.P->b) * (1 )));
			Marking.P->_PL_block1 -= ((mach1_Token(b.P->b) * (1 )));

		break;
		case 6:	//pend2
			Marking.P->_PL_ph1m0 += ((Block_Token(b.P->x, b.P->b) * (1 )));
			Marking.P->_PL_readym1 -= ((Block_Token(b.P->x, b.P->b) * (1 )));

		break;
		case 2:	//pend1
			Marking.P->_PL_ploadm0 += ((Block_Token(b.P->x, b.P->b) * (1 )));
			Marking.P->_PL_ph1m0 -= ((Block_Token(b.P->x, b.P->b) * (1 )));

		break;
		case 7:	//bin1p
			Marking.P->_PL_ploadm0 -= ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )));
			Marking.P->_PL_pb1 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_int1 += ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 += ((mach1_Token(b.P->b) * (1 )));

		break;
		case 0:	//unload1
			Marking.P->_PL_ploadm0 -= ((Block_Token(b.P->x, b.P->b) * (1 )));
			Marking.P->_PL_ph1m0 += ((Block_Token(b.P->x, b.P->b) * (1 )));

		break;
		case 4:	//predo2
			Marking.P->_PL_ploadm0 -= ((Block_Token(b.P->x, b.P->b) * (1 )));
			Marking.P->_PL_readym1 += ((Block_Token(b.P->x, b.P->b) * (1 )));

		break;
		case 9:	//fex1
			Marking.P->_PL_readym1 += ((Block_Token(b.P->x, b.P->b) * (1 )) + (Block_Token(b.P->y, b.P->b) * (1 )));
			Marking.P->_PL_int1 -= ((proc_Token(b.P->x) * (1 )) + (proc_Token(b.P->y) * (1 )));
			Marking.P->_PL_block1 -= ((mach1_Token(b.P->b) * (1 )));

		break;
	}
}

const abstractBinding* SPN::nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
	switch(lastTransition*(tr+1) + targettr){
		//Partial synch over variable: unload1->pend1 var Not set
		//Fallback:unload1->bex0
		//Fallback:fin0m->fin0m
		//Partial synch over variable: fin0m->bin1m var x, y, Not set
		//Fallback:fin0m->fin0p
		//Partial synch over variable: fin0m->bin1p var x, y, Not set
		//Partial synch over variable: pend1->unload1 var Not set
		//Partial synch over variable: pend1->pend2 var Not set
		//Partial synch over variable: bin1m->fin0m var x, y, Not set
		//Fallback:bin1m->bin1m
		//Partial synch over variable: bin1m->fin0p var x, y, Not set
		//Fallback:bin1m->bin1p
		//Partial synch over variable: predo2->pend1 var Not set
		//Fallback:predo2->bex0
		//Fallback:fin0p->pend1
		//Fallback:fin0p->bex0
		//Partial synch over variable: pend2->predo2 var Not set
		//Fallback:pend2->fex1
		//Fallback:bin1p->pend1
		//Fallback:bin1p->bex0
		//Fallback:bex0->fin0m
		//Partial synch over variable: bex0->bin1m var x, y, Not set
		//Fallback:bex0->fin0p
		//Partial synch over variable: bex0->bin1p var x, y, Not set
		//Partial synch over variable: fex1->fin0m var x, y, Not set
		//Fallback:fex1->bin1m
		//Partial synch over variable: fex1->fin0p var x, y, Not set
		//Fallback:fex1->bin1p
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
const abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
	switch(lastTransition*(tr+1) + targettr){
		//Partial synch over variable: unload1->unload1 var Not set
		//Partial synch over variable: unload1->pend2 var Not set
		//Fallback:fin0m->fin0m
		//Partial synch over variable: fin0m->bin1m var x, y, Not set
		//Fallback:fin0m->fin0p
		//Partial synch over variable: fin0m->bin1p var x, y, Not set
		//Partial synch over variable: pend1->pend1 var Not set
		//Fallback:pend1->bex0
		//Partial synch over variable: bin1m->fin0m var x, y, Not set
		//Fallback:bin1m->bin1m
		//Partial synch over variable: bin1m->fin0p var x, y, Not set
		//Fallback:bin1m->bin1p
		//Partial synch over variable: predo2->predo2 var Not set
		//Fallback:predo2->fex1
		//Fallback:fin0p->fin0m
		//Partial synch over variable: fin0p->bin1m var x, y, Not set
		//Fallback:fin0p->fin0p
		//Partial synch over variable: fin0p->bin1p var x, y, Not set
		//Partial synch over variable: pend2->unload1 var Not set
		//Partial synch over variable: pend2->pend2 var Not set
		//Partial synch over variable: bin1p->fin0m var x, y, Not set
		//Fallback:bin1p->bin1m
		//Partial synch over variable: bin1p->fin0p var x, y, Not set
		//Fallback:bin1p->bin1p
		//Fallback:bex0->pend1
		//Fallback:bex0->bex0
		//Fallback:fex1->predo2
		//Fallback:fex1->fex1
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
		case 5:	//fin0p
		case 7:	//bin1p
	{
	}

		break;
		default:	//unload1,fin0m,pend1,bin1m,predo2,pend2,bex0,fex1,
	{
		ParamDistr[0]= ( double ) 1 ;
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

