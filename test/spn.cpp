#include "spn.hpp"
#include <iomanip>
using namespace std;
#define PL_selfVehicle_LP 0
#define PL_simstep1_LP 1
#define PL_simstep2_LP 2
#define PL_simstep3_LP 3
#define PL_simstep4_LP 4
#define PL_initGenere_LP 5
#define PL_inProcess_LP 6
#define PL_otherVehicles_LP 7
#define PL_PosFinale_LP 8
#define PL_PositionMax_LP 9
#define TR_updateSelf_RT 0
#define TR_lightController_RT 1
#define TR_simstepA_RT 2
#define TR_simstepB_RT 3
#define TR_simstepC_RT 4
#define TR_randOther_RT 5
#define TR_updOther_RT 6
#define TR_generationInitiale_RT 7
#define TR_exit_RT 8
#define TR_end_RT 9
#define TR_collision_RT 10
#define TR_enter_RT 11

const int _nb_Place_selfVehicle=0;
const int _nb_Place_simstep1=1;
const int _nb_Place_simstep2=2;
const int _nb_Place_simstep3=3;
const int _nb_Place_simstep4=4;
const int _nb_Place_initGenere=5;
const int _nb_Place_inProcess=6;
const int _nb_Place_otherVehicles=7;
const int _nb_Place_PosFinale=8;
const int _nb_Place_PositionMax=9;
namespace hybridVar {
}
#include "magic.hpp"
void REHandling::print_state(const vector<int> &vect){}
void REHandling::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool REHandling::precondition(const abstractMarking &M){return true;}
#include "marking.hpp"
#include "markingImpl.hpp"
inline bool contains(const PosX_Domain& d1, const PosX_Domain& d2){	return not (d1 < d2);
}
inline bool contains(const PosX_Domain& d1, const PosX_Token& tok){	return d1 >= tok;
}
inline bool contains(const PosY_Domain& d1, const PosY_Domain& d2){	return not (d1 < d2);
}
inline bool contains(const PosY_Domain& d1, const PosY_Token& tok){	return d1 >= tok;
}
inline bool contains(const VitX_Domain& d1, const VitX_Domain& d2){	return not (d1 < d2);
}
inline bool contains(const VitX_Domain& d1, const VitX_Token& tok){	return d1 >= tok;
}
inline bool contains(const VitY_Domain& d1, const VitY_Domain& d2){	return not (d1 < d2);
}
inline bool contains(const VitY_Domain& d1, const VitY_Token& tok){	return d1 >= tok;
}
inline bool contains(const AccX_Domain& d1, const AccX_Domain& d2){	return not (d1 < d2);
}
inline bool contains(const AccX_Domain& d1, const AccX_Token& tok){	return d1 >= tok;
}
inline bool contains(const AccY_Domain& d1, const AccY_Domain& d2){	return not (d1 < d2);
}
inline bool contains(const AccY_Domain& d1, const AccY_Token& tok){	return d1 >= tok;
}
inline bool contains(const Jeton_Domain& d1, const Jeton_Domain& d2){	return not (d1 < d2);
}
inline bool contains(const Jeton_Domain& d1, const Jeton_Token& tok){	return d1 >= tok;
}
inline bool contains(const Vehicle_Domain& d1, const Vehicle_Domain& d2){	return not (d1 < d2);
}
inline bool contains(const Vehicle_Domain& d1, const Vehicle_Token& tok){	return d1 >= tok;
}
inline bool contains(const SelfVehicle_Domain& d1, const SelfVehicle_Domain& d2){	return not (d1 < d2);
}
inline bool contains(const SelfVehicle_Domain& d1, const SelfVehicle_Token& tok){	return d1 >= tok;
}

void abstractMarking::resetToInitMarking(){
	magicReset();
	P->_PL_selfVehicle =0  ;
	P->_PL_simstep1 =0  ;
	P->_PL_simstep2 =0  ;
	P->_PL_simstep3 =0  ;
	P->_PL_simstep4 =0  ;
	P->_PL_initGenere =0  ;
	P->_PL_inProcess =0  ;
	P->_PL_otherVehicles =0  ;
	P->_PL_PosFinale =0  ;
	P->_PL_PositionMax =0  ;
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
	exit(EXIT_FAILURE);
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(1539);
	v.reserve(1540);
	size_t i = 0;
	i= P->_PL_selfVehicle.copyVector(v,i);
	i= P->_PL_simstep1.copyVector(v,i);
	i= P->_PL_simstep2.copyVector(v,i);
	i= P->_PL_simstep3.copyVector(v,i);
	i= P->_PL_simstep4.copyVector(v,i);
	i= P->_PL_initGenere.copyVector(v,i);
	i= P->_PL_inProcess.copyVector(v,i);
	i= P->_PL_otherVehicles.copyVector(v,i);
	v[i++]= P->_PL_PosFinale;
	i= P->_PL_PositionMax.copyVector(v,i);
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	size_t i = 0;
	i= P->_PL_selfVehicle.setVector(v,i);
	i= P->_PL_simstep1.setVector(v,i);
	i= P->_PL_simstep2.setVector(v,i);
	i= P->_PL_simstep3.setVector(v,i);
	i= P->_PL_simstep4.setVector(v,i);
	i= P->_PL_initGenere.setVector(v,i);
	i= P->_PL_inProcess.setVector(v,i);
	i= P->_PL_otherVehicles.setVector(v,i);
	P->_PL_PosFinale = v[i++];
	i= P->_PL_PositionMax.setVector(v,i);
};

void abstractMarking::Symmetrize(){
}bool abstractBinding::next() {
	idcount++;
	if(P->xs.mult >= 0){
		if (! P->xs.islast()){	P->xs.iter(); return true; };
		P->xs = PosX_Token();
	}
	if(P->x.mult >= 0){
		if (! P->x.islast()){	P->x.iter(); return true; };
		P->x = PosX_Token();
	}
	if(P->ys.mult >= 0){
		if (! P->ys.islast()){	P->ys.iter(); return true; };
		P->ys = PosY_Token();
	}
	if(P->y.mult >= 0){
		if (! P->y.islast()){	P->y.iter(); return true; };
		P->y = PosY_Token();
	}
	if(P->dxs.mult >= 0){
		if (! P->dxs.islast()){	P->dxs.iter(); return true; };
		P->dxs = VitX_Token();
	}
	if(P->dx.mult >= 0){
		if (! P->dx.islast()){	P->dx.iter(); return true; };
		P->dx = VitX_Token();
	}
	if(P->dys.mult >= 0){
		if (! P->dys.islast()){	P->dys.iter(); return true; };
		P->dys = VitY_Token();
	}
	if(P->dy.mult >= 0){
		if (! P->dy.islast()){	P->dy.iter(); return true; };
		P->dy = VitY_Token();
	}
	if(P->ddx.mult >= 0){
		if (! P->ddx.islast()){	P->ddx.iter(); return true; };
		P->ddx = AccX_Token();
	}
	if(P->ddy.mult >= 0){
		if (! P->ddy.islast()){	P->ddy.iter(); return true; };
		P->ddy = AccY_Token();
	}
	if(P->j.mult >= 0){
		if (! P->j.islast()){	P->j.iter(); return true; };
		P->j = Jeton_Token();
	}
	return false;
};
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
	std::cerr << "\txs: ";P->xs.print(std::cerr);
	std::cerr << "\tx: ";P->x.print(std::cerr);
	std::cerr << "\tys: ";P->ys.print(std::cerr);
	std::cerr << "\ty: ";P->y.print(std::cerr);
	std::cerr << "\tdxs: ";P->dxs.print(std::cerr);
	std::cerr << "\tdx: ";P->dx.print(std::cerr);
	std::cerr << "\tdys: ";P->dys.print(std::cerr);
	std::cerr << "\tdy: ";P->dy.print(std::cerr);
	std::cerr << "\tddx: ";P->ddx.print(std::cerr);
	std::cerr << "\tddy: ";P->ddy.print(std::cerr);
	std::cerr << "\tj: ";P->j.print(std::cerr);
}
int abstractBinding::id()const{
	return idcount;
}
int abstractBinding::idTotal()const{
	 return P->xs.c0 + Color_PosX_Total *(P->x.c0 + Color_PosX_Total *(P->ys.c0 + Color_PosY_Total *(P->y.c0 + Color_PosY_Total *(P->dxs.c0 + Color_VitX_Total *(P->dx.c0 + Color_VitX_Total *(P->dys.c0 + Color_VitY_Total *(P->dy.c0 + Color_VitY_Total *(P->ddx.c0 + Color_AccX_Total *(P->ddy.c0 + Color_AccY_Total *(P->j.c0 + Color_Jeton_Total *(0)))))))))));
}
const char *Color_PosX_names[Color_PosX_Total] = {
"PosX_IC_0","PosX_IC_1","PosX_IC_2","PosX_IC_3","PosX_IC_4","PosX_IC_5","PosX_IC_6","PosX_IC_7","PosX_IC_8","PosX_IC_9","PosX_IC_10","PosX_IC_11","PosX_IC_12","PosX_IC_13","PosX_IC_14","PosX_IC_15","PosX_IC_16","PosX_IC_17","PosX_IC_18","PosX_IC_19","PosX_IC_20",
};
const char *Color_PosY_names[Color_PosY_Total] = {
"PosY_IC_0","PosY_IC_1",
};
const char *Color_VitX_names[Color_VitX_Total] = {
"VitX_IC_0","VitX_IC_1","VitX_IC_2",
};
const char *Color_VitY_names[Color_VitY_Total] = {
"VitY_IC_0","VitY_IC_1",
};
const char *Color_AccX_names[Color_AccX_Total] = {
"AccX_IC_0","AccX_IC_1",
};
const char *Color_AccY_names[Color_AccY_Total] = {
"AccY_IC_0","AccY_IC_1",
};
const char *Color_Jeton_names[Color_Jeton_Total] = {
"Jeton_IC_1",
};
static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_0[4]= {TR_lightController_RT, TR_end_RT, TR_collision_RT, -1 }; /* updateSelf*/
static const int PE_PossiblyEnabled_1[4]= {TR_updateSelf_RT, TR_end_RT, TR_collision_RT, -1 }; /* lightController*/
static const int PE_PossiblyEnabled_2[4]= {TR_simstepB_RT, TR_randOther_RT, TR_generationInitiale_RT, -1 }; /* simstepA*/
static const int PE_PossiblyEnabled_3[3]= {TR_simstepC_RT, TR_updOther_RT, -1 }; /* simstepB*/
static const int PE_PossiblyEnabled_4[2]= {TR_updateSelf_RT, -1 }; /* simstepC*/
static const int PE_PossiblyEnabled_5[3]= {TR_simstepB_RT, TR_updOther_RT, -1 }; /* randOther*/
static const int PE_PossiblyEnabled_6[5]= {TR_simstepC_RT, TR_randOther_RT, TR_exit_RT, TR_collision_RT, -1 }; /* updOther*/
static const int PE_PossiblyEnabled_7[2]= {TR_simstepA_RT, -1 }; /* generationInitiale*/
static const int PE_PossiblyEnabled_11[4]= {TR_randOther_RT, TR_exit_RT, TR_collision_RT, -1 }; /* enter*/
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, PE_PossiblyEnabled_2, PE_PossiblyEnabled_3, PE_PossiblyEnabled_4, PE_PossiblyEnabled_5, PE_PossiblyEnabled_6, PE_PossiblyEnabled_7, EMPTY_array, EMPTY_array, EMPTY_array, PE_PossiblyEnabled_11};

static const int PE_PossiblyDisabled_0[4]= {TR_lightController_RT, TR_end_RT, TR_collision_RT, -1 }; /* updateSelf*/
static const int PE_PossiblyDisabled_1[4]= {TR_updateSelf_RT, TR_end_RT, TR_collision_RT, -1 }; /* lightController*/
static const int PE_PossiblyDisabled_2[2]= {TR_generationInitiale_RT, -1 }; /* simstepA*/
static const int PE_PossiblyDisabled_3[2]= {TR_randOther_RT, -1 }; /* simstepB*/
static const int PE_PossiblyDisabled_4[2]= {TR_updOther_RT, -1 }; /* simstepC*/
static const int PE_PossiblyDisabled_5[4]= {TR_simstepB_RT, TR_exit_RT, TR_collision_RT, -1 }; /* randOther*/
static const int PE_PossiblyDisabled_6[2]= {TR_simstepC_RT, -1 }; /* updOther*/
static const int PE_PossiblyDisabled_8[3]= {TR_randOther_RT, TR_collision_RT, -1 }; /* exit*/
static const int PE_PossiblyDisabled_9[4]= {TR_updateSelf_RT, TR_lightController_RT, TR_collision_RT, -1 }; /* end*/
static const int PE_PossiblyDisabled_10[6]= {TR_updateSelf_RT, TR_lightController_RT, TR_randOther_RT, TR_exit_RT, TR_end_RT, -1 }; /* collision*/
const int* SPN::PossiblyDisabled[] = {PE_PossiblyDisabled_0, PE_PossiblyDisabled_1, PE_PossiblyDisabled_2, PE_PossiblyDisabled_3, PE_PossiblyDisabled_4, PE_PossiblyDisabled_5, PE_PossiblyDisabled_6, EMPTY_array, PE_PossiblyDisabled_8, PE_PossiblyDisabled_9, PE_PossiblyDisabled_10, EMPTY_array};

const int* SPN::FreeMarkDepT[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

static spn_trans TransArray[12] = { _trans(0,DETERMINISTIC,0,254016, 0), _trans(1,DETERMINISTIC,0,254016, 0), _trans(2,UNIFORM,0,254016, 0), _trans(3,DETERMINISTIC,0,254016, 0), _trans(4,DETERMINISTIC,0,254016, 0), _trans(5,DETERMINISTIC,0,254016, 0), _trans(6,DETERMINISTIC,0,254016, 0), _trans(7,DETERMINISTIC,0,254016, 0), _trans(8,DETERMINISTIC,0,254016, 0), _trans(9,DETERMINISTIC,0,254016, 0), _trans(10,DETERMINISTIC,0,254016, 0), _trans(11,DETERMINISTIC,0,254016, 0),  }; 
SPN::SPN():
customDistr(*(new CustomDistr())),pl(10), tr(12) ,Transition(TransArray,TransArray +12),Place(10),ParamDistr(10),TransitionConditions(12,0){
    Path ="moded_CoSimulation.grml";
	{ //updateSelf
	abstractBinding bl = Transition[0].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dys.mult = -1;
			Transition[0].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[0].bindingList.size();
			Transition[0].bindingList.push_back( bl );
			Transition[0].bindingLinkTable[bl.idTotal()]= Transition[0].bindingList.size()-1; 
		}
	}}
	{ //lightController
	abstractBinding bl = Transition[1].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dys.mult = -1;
			Transition[1].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[1].bindingList.size();
			Transition[1].bindingList.push_back( bl );
			Transition[1].bindingLinkTable[bl.idTotal()]= Transition[1].bindingList.size()-1; 
		}
	}}
	{ //simstepA
	abstractBinding bl = Transition[2].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->x.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->y.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dx.mult = -1;
	bl.P->dys.mult = -1;
	bl.P->dy.mult = -1;
	bl.P->ddx.mult = -1;
	bl.P->ddy.mult = -1;
			Transition[2].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[2].bindingList.size();
			Transition[2].bindingList.push_back( bl );
			Transition[2].bindingLinkTable[bl.idTotal()]= Transition[2].bindingList.size()-1; 
		}
	}}
	{ //simstepB
	abstractBinding bl = Transition[3].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->x.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->y.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dx.mult = -1;
	bl.P->dys.mult = -1;
	bl.P->dy.mult = -1;
	bl.P->ddx.mult = -1;
	bl.P->ddy.mult = -1;
			Transition[3].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[3].bindingList.size();
			Transition[3].bindingList.push_back( bl );
			Transition[3].bindingLinkTable[bl.idTotal()]= Transition[3].bindingList.size()-1; 
		}
	}}
	{ //simstepC
	abstractBinding bl = Transition[4].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->x.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->y.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dx.mult = -1;
	bl.P->dys.mult = -1;
	bl.P->dy.mult = -1;
	bl.P->ddx.mult = -1;
	bl.P->ddy.mult = -1;
			Transition[4].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[4].bindingList.size();
			Transition[4].bindingList.push_back( bl );
			Transition[4].bindingLinkTable[bl.idTotal()]= Transition[4].bindingList.size()-1; 
		}
	}}
	{ //randOther
	abstractBinding bl = Transition[5].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dys.mult = -1;
	bl.P->ddx.mult = -1;
	bl.P->ddy.mult = -1;
			Transition[5].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[5].bindingList.size();
			Transition[5].bindingList.push_back( bl );
			Transition[5].bindingLinkTable[bl.idTotal()]= Transition[5].bindingList.size()-1; 
		}
	}}
	{ //updOther
	abstractBinding bl = Transition[6].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dys.mult = -1;
	bl.P->ddx.mult = -1;
	bl.P->ddy.mult = -1;
			Transition[6].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[6].bindingList.size();
			Transition[6].bindingList.push_back( bl );
			Transition[6].bindingLinkTable[bl.idTotal()]= Transition[6].bindingList.size()-1; 
		}
	}}
	{ //generationInitiale
	abstractBinding bl = Transition[7].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->x.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->y.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dx.mult = -1;
	bl.P->dys.mult = -1;
	bl.P->dy.mult = -1;
	bl.P->ddx.mult = -1;
	bl.P->ddy.mult = -1;
			Transition[7].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[7].bindingList.size();
			Transition[7].bindingList.push_back( bl );
			Transition[7].bindingLinkTable[bl.idTotal()]= Transition[7].bindingList.size()-1; 
		}
	}}
	{ //exit
	abstractBinding bl = Transition[8].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dys.mult = -1;
	bl.P->ddx.mult = -1;
	bl.P->ddy.mult = -1;
	bl.P->j.mult = -1;
			Transition[8].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[8].bindingList.size();
			Transition[8].bindingList.push_back( bl );
			Transition[8].bindingLinkTable[bl.idTotal()]= Transition[8].bindingList.size()-1; 
		}
	}}
	{ //end
	abstractBinding bl = Transition[9].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dys.mult = -1;
	bl.P->j.mult = -1;
			Transition[9].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[9].bindingList.size();
			Transition[9].bindingList.push_back( bl );
			Transition[9].bindingLinkTable[bl.idTotal()]= Transition[9].bindingList.size()-1; 
		}
	}}
	{ //collision
	abstractBinding bl = Transition[10].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->j.mult = -1;
			Transition[10].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[10].bindingList.size();
			Transition[10].bindingList.push_back( bl );
			Transition[10].bindingLinkTable[bl.idTotal()]= Transition[10].bindingList.size()-1; 
		}
	}}
	{ //enter
	abstractBinding bl = Transition[11].bindingList[0];
	bl.P->xs.mult = -1;
	bl.P->x.mult = -1;
	bl.P->ys.mult = -1;
	bl.P->y.mult = -1;
	bl.P->dxs.mult = -1;
	bl.P->dx.mult = -1;
	bl.P->dys.mult = -1;
	bl.P->dy.mult = -1;
	bl.P->ddx.mult = -1;
	bl.P->ddy.mult = -1;
	bl.P->j.mult = -1;
			Transition[11].bindingList[0] = bl;
	while(bl.next()){
		{
			bl.idcount = Transition[11].bindingList.size();
			Transition[11].bindingList.push_back( bl );
			Transition[11].bindingLinkTable[bl.idTotal()]= Transition[11].bindingList.size()-1; 
		}
	}}
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{
	if(!magicConditional(t))return false;

	switch (t){
		case 2:	//simstepA

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_initGenere , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 5:	//randOther

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep1 , ((Jeton_Token(b.P->j)))))) return false;
			if ( !(((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy))) < 1)) 
			if (!(contains(Marking.P->_PL_otherVehicles , ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)))))) return false;
		return true;
		break;
		case 3:	//simstepB

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep1 , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 6:	//updOther

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep2 , ((Jeton_Token(b.P->j)))))) return false;
			if ( !(((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy))) < 1)) 
			if (!(contains(Marking.P->_PL_inProcess , ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)))))) return false;
		return true;
		break;
		case 4:	//simstepC

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep2 , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 0:	//updateSelf

			if ( !(((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy))) < 1)) 
			if (!(contains(Marking.P->_PL_selfVehicle , ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)))))) return false;
			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep3 , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 1:	//lightController

			if ( !(((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy))) < 1)) 
			if (!(contains(Marking.P->_PL_selfVehicle , ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)))))) return false;
			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep4 , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 9:	//end

			if ( !(((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy))) < 1)) 
			if (!(contains(Marking.P->_PL_selfVehicle , ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)))))) return false;
			if ( !(((PosX_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_PositionMax , ((PosX_Token(b.P->x)))))) return false;
		return true;
		break;
		case 10:	//collision

			if ( !(((SelfVehicle_Token(b.P->x, b.P->y, b.P->dxs, b.P->dys, b.P->ddx, b.P->ddy))) < 1)) 
			if (!(contains(Marking.P->_PL_selfVehicle , ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dxs, b.P->dys, b.P->ddx, b.P->ddy)))))) return false;
			if ( !(((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy))) < 1)) 
			if (!(contains(Marking.P->_PL_otherVehicles , ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)))))) return false;
		return true;
		break;
		case 8:	//exit

			if ( !(((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy))) < 1)) 
			if (!(contains(Marking.P->_PL_otherVehicles , ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)))))) return false;
		return true;
		break;
		case 11:	//enter

		return true;
		break;
		case 7:	//generationInitiale

    if ( !(((Jeton_Token(b.P->j))) < 1) ) 
        if (contains(Marking.P->_PL_initGenere , ((Jeton_Token(b.P->j))))) return false;
		return true;
		break;
	}
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;
	magicUpdate(t,time);

	switch (t){
		case 7:	//generationInitiale
{
			Jeton_Domain tmpMark_initGenere = Marking.P->_PL_initGenere;
			Marking.P->_PL_initGenere += ((Jeton_Token(b.P->j)));
{using namespace hybridVar;
int vit; int pos;
       Marking.P->_PL_selfVehicle += (( SelfVehicle_Token( (PosX_Color_Classe) 0, (PosY_Color_Classe) 0, (VitX_Color_Classe) 1, (VitY_Color_Classe) 0, (AccX_Color_Classe) 0, (AccY_Color_Classe) 0) * (1)));
       for (int i=0;i < 2;i++) {
       vit = rand() % 2; pos = (rand() % 4)+1;
       Marking.P->_PL_otherVehicles += (( Vehicle_Token( (PosX_Color_Classe) pos, (PosY_Color_Classe) 0, (VitX_Color_Classe) vit, (VitY_Color_Classe) 0) * (1)));
       }
       Marking.P->_PL_PositionMax += ( PosX_Token( (PosX_Color_Classe) (Color_PosX_Total - 1)));}
	}
		break;
		case 2:	//simstepA
{
			Jeton_Domain tmpMark_simstep1 = Marking.P->_PL_simstep1;
			Jeton_Domain tmpMark_initGenere = Marking.P->_PL_initGenere;
			Marking.P->_PL_simstep1 += ((Jeton_Token(b.P->j)));
			Marking.P->_PL_initGenere -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_initGenere += ((Jeton_Token(b.P->j)));
	}
		break;
		case 3:	//simstepB
{
			Jeton_Domain tmpMark_simstep1 = Marking.P->_PL_simstep1;
			Jeton_Domain tmpMark_simstep2 = Marking.P->_PL_simstep2;
			Marking.P->_PL_simstep1 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep2 += ((Jeton_Token(b.P->j)));
	}
		break;
		case 5:	//randOther
{
			Jeton_Domain tmpMark_simstep1 = Marking.P->_PL_simstep1;
			Vehicle_Domain tmpMark_inProcess = Marking.P->_PL_inProcess;
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			Marking.P->_PL_simstep1 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep1 += ((Jeton_Token(b.P->j)));
			Marking.P->_PL_inProcess += ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
			Marking.P->_PL_otherVehicles -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
{using namespace hybridVar;
int position = (int) (b.P->x).c0;
      int vitesse = (int) (b.P->dx).c0;
/*      int random = rand() % 3; */
      position = position + vitesse;
      Marking.P->_PL_inProcess -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy) * (1 )));;
      Marking.P->_PL_inProcess += ((Vehicle_Token( (PosX_Color_Classe) position, b.P->y, b.P->dx, b.P->dy) * (1 )));}
	}
		break;
		case 4:	//simstepC
{
			Jeton_Domain tmpMark_simstep2 = Marking.P->_PL_simstep2;
			Jeton_Domain tmpMark_simstep3 = Marking.P->_PL_simstep3;
			Marking.P->_PL_simstep2 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep3 += ((Jeton_Token(b.P->j)));
	}
		break;
		case 6:	//updOther
{
			Jeton_Domain tmpMark_simstep2 = Marking.P->_PL_simstep2;
			Vehicle_Domain tmpMark_inProcess = Marking.P->_PL_inProcess;
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			Marking.P->_PL_simstep2 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep2 += ((Jeton_Token(b.P->j)));
			Marking.P->_PL_inProcess -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
			Marking.P->_PL_otherVehicles += ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
	}
		break;
		case 0:	//updateSelf
{
			SelfVehicle_Domain tmpMark_selfVehicle = Marking.P->_PL_selfVehicle;
			Jeton_Domain tmpMark_simstep3 = Marking.P->_PL_simstep3;
			Jeton_Domain tmpMark_simstep4 = Marking.P->_PL_simstep4;
			Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_selfVehicle += ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_simstep3 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep4 += ((Jeton_Token(b.P->j)));
{using namespace hybridVar;
int position = (int) (b.P->x).c0;
      int vitesse = (int) (b.P->dx).c0;
      position = min(position + vitesse,(Color_PosX_Total - 1));
      Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy) * (1 )));
      Marking.P->_PL_selfVehicle += ((SelfVehicle_Token( (PosX_Color_Classe) position, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy) * (1 )));}
	}
		break;
		case 1:	//lightController
{
			SelfVehicle_Domain tmpMark_selfVehicle = Marking.P->_PL_selfVehicle;
			Jeton_Domain tmpMark_simstep4 = Marking.P->_PL_simstep4;
			Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_selfVehicle += ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_simstep4 -= ((Jeton_Token(b.P->j)));
{using namespace hybridVar;
SelfVehicle_Token monvehicule;
      monvehicule = (SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy));
      int px = (int) (b.P->x).c0;
      int py = (int) (b.P->y).c0;
      int vx = (int) (b.P->dx).c0;
      int vy = (int) (b.P->dy).c0;
      int ax = (int) (b.P->ddx).c0;
      int ay = (int) (b.P->ddy).c0;

      int i1 = py; bool devant = false;
      int posdev = Color_PosX_Total; int vitdev = 0;

      for(int i0=px+1;i0 < Color_PosX_Total;i0++) {
      for( int i2= 0;i2 < Color_VitX_Total;i2++) {
      for( int i3= 0;i3 < Color_VitY_Total;i3++) {

         if (contains(Marking.P->_PL_otherVehicles, ((Vehicle_Token( (PosX_Color_Classe) i0, (PosY_Color_Classe) i1, (VitX_Color_Classe) i2, (VitY_Color_Classe) i3) * (1))))) {
          devant=true; posdev=i0; vitdev=i2;
          goto sortieBoucle;
      }

      }
      }
      }
      sortieBoucle:

      int6tuple nouvpos = controlleur(px,py,vx,vy,ax,ay,devant,posdev,vitdev);
      Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy) * (1 )));
      Marking.P->_PL_selfVehicle += ((SelfVehicle_Token( (PosX_Color_Classe) nouvpos.px, (PosY_Color_Classe) nouvpos.py, (VitX_Color_Classe) nouvpos.vx, (VitY_Color_Classe) nouvpos.vy, (AccX_Color_Classe) nouvpos.ax, (AccY_Color_Classe) nouvpos.ay) * (1)));}
	}
		break;
		case 10:	//collision
{
			SelfVehicle_Domain tmpMark_selfVehicle = Marking.P->_PL_selfVehicle;
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			int tmpMark_PosFinale = Marking.P->_PL_PosFinale;
			Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dxs, b.P->dys, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_otherVehicles -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
			Marking.P->_PL_PosFinale += 1 ;
{using namespace hybridVar;
Marking.P->_PL_PosFinale -= 1;
      int position = (int) (b.P->x).c0;
      Marking.P->_PL_PosFinale += position;}
	}
		break;
		case 9:	//end
{
			SelfVehicle_Domain tmpMark_selfVehicle = Marking.P->_PL_selfVehicle;
			int tmpMark_PosFinale = Marking.P->_PL_PosFinale;
			PosX_Domain tmpMark_PositionMax = Marking.P->_PL_PositionMax;
			Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_PosFinale += 1 ;
			Marking.P->_PL_PositionMax -= ((PosX_Token(b.P->x)));
{using namespace hybridVar;
Marking.P->_PL_PosFinale -= 1;
      int position = (int) (b.P->x).c0;
      Marking.P->_PL_PosFinale += position;}
	}
		break;
		case 11:	//enter
{
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			Marking.P->_PL_otherVehicles += 1 ;
	}
		break;
		case 8:	//exit
{
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			Marking.P->_PL_otherVehicles -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
	}
		break;
	}
}

void SPN::unfire(TR_PL_ID t, const abstractBinding &b){


}

const abstractBinding* SPN::nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}
const abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

	switch (t){
		case 2:	//simstepA
	{
		ParamDistr[0]= ( double ) 1 ;
		ParamDistr[1]= ( double ) 1 ;
	}

		break;
		case 11:	//enter
	{
		ParamDistr[0]= ( double ) 100 ;
	}

		break;
		case 8:	//exit
	{
		ParamDistr[0]= ( double ) 1500 ;
	}

		break;
		default:	//updateSelf,lightController,simstepB,simstepC,randOther,updOther,generationInitiale,end,collision,
	{
		ParamDistr[0]= ( double ) 0 ;
	}

		break;
	}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

	switch (t){
		case 9:	//end
		case 10:	//collision
		return (double)10 ;
		break;
		case 0:	//updateSelf
		case 5:	//randOther
		case 6:	//updOther
		case 8:	//exit
		return (double)2 ;
		break;
		default:	//lightController,simstepA,simstepB,simstepC,generationInitiale,enter,
		return (double)1 ;
		break;
	}
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

