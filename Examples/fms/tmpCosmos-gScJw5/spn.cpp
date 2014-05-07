#include "spn.hpp"
#include <iomanip>
	const double Tunit=0.5;
	const double alpha1=0.45;
	const double alpha2=0.55;
	const double failrate=0;
	const double mu1=0.68305;
	const double mu2=0.68305;
	const double sigma1=0.83255;
	const double sigma2=0.83255;
	const int _nb_Place_Products=0;
	const int _nb_Place_Buffer1=1;
	const int _nb_Place_Pos1_1=2;
	const int _nb_Place_Ready1=3;
	const int _nb_Place_Waiting1=4;
	const int _nb_Place_Q1=5;
	const int _nb_Place_Pos1_4=6;
	const int _nb_Place_Pos1_3=7;
	const int _nb_Place_Pos1_2=8;
	const int _nb_Place_Ready2=9;
	const int _nb_Place_Waiting2=10;
	const int _nb_Place_Buffer2=11;
	const int _nb_Place_Pos2_1=12;
	const int _nb_Place_Pos2_2=13;
	const int _nb_Place_Q2=14;
	const int _nb_Place_Pos2_4=15;
	const int _nb_Place_OccPos2=16;
	const int _nb_Place_Up1=17;
	const int _nb_Place_Pos2_3=18;
	const int _nb_Place_OccPos1=19;
	const int _nb_Place_Down1=20;
	const int _nb_Place_Up2=21;
	const int _nb_Place_Down2=22;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_Products =0;
	P->_PL_Buffer1 =0;
	P->_PL_Pos1_1 =0;
	P->_PL_Ready1 =1;
	P->_PL_Waiting1 =0;
	P->_PL_Q1 =0;
	P->_PL_Pos1_4 =0;
	P->_PL_Pos1_3 =0;
	P->_PL_Pos1_2 =0;
	P->_PL_Ready2 =1;
	P->_PL_Waiting2 =0;
	P->_PL_Buffer2 =0;
	P->_PL_Pos2_1 =0;
	P->_PL_Pos2_2 =0;
	P->_PL_Q2 =0;
	P->_PL_Pos2_4 =0;
	P->_PL_OccPos2 =0;
	P->_PL_Up1 =1;
	P->_PL_Pos2_3 =0;
	P->_PL_OccPos1 =0;
	P->_PL_Down1 =0;
	P->_PL_Up2 =1;
	P->_PL_Down2 =0;
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

void abstractMarking::print(ostream &s)const{
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_Products;
		case 1: return P->_PL_Buffer1;
		case 2: return P->_PL_Pos1_1;
		case 3: return P->_PL_Ready1;
		case 4: return P->_PL_Waiting1;
		case 5: return P->_PL_Q1;
		case 6: return P->_PL_Pos1_4;
		case 7: return P->_PL_Pos1_3;
		case 8: return P->_PL_Pos1_2;
		case 9: return P->_PL_Ready2;
		case 10: return P->_PL_Waiting2;
		case 11: return P->_PL_Buffer2;
		case 12: return P->_PL_Pos2_1;
		case 13: return P->_PL_Pos2_2;
		case 14: return P->_PL_Q2;
		case 15: return P->_PL_Pos2_4;
		case 16: return P->_PL_OccPos2;
		case 17: return P->_PL_Up1;
		case 18: return P->_PL_Pos2_3;
		case 19: return P->_PL_OccPos1;
		case 20: return P->_PL_Down1;
		case 21: return P->_PL_Up2;
		case 22: return P->_PL_Down2;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(23);
	v[0] = P->_PL_Products;
	v[1] = P->_PL_Buffer1;
	v[2] = P->_PL_Pos1_1;
	v[3] = P->_PL_Ready1;
	v[4] = P->_PL_Waiting1;
	v[5] = P->_PL_Q1;
	v[6] = P->_PL_Pos1_4;
	v[7] = P->_PL_Pos1_3;
	v[8] = P->_PL_Pos1_2;
	v[9] = P->_PL_Ready2;
	v[10] = P->_PL_Waiting2;
	v[11] = P->_PL_Buffer2;
	v[12] = P->_PL_Pos2_1;
	v[13] = P->_PL_Pos2_2;
	v[14] = P->_PL_Q2;
	v[15] = P->_PL_Pos2_4;
	v[16] = P->_PL_OccPos2;
	v[17] = P->_PL_Up1;
	v[18] = P->_PL_Pos2_3;
	v[19] = P->_PL_OccPos1;
	v[20] = P->_PL_Down1;
	v[21] = P->_PL_Up2;
	v[22] = P->_PL_Down2;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_Products = v[0];
	P->_PL_Buffer1 = v[1];
	P->_PL_Pos1_1 = v[2];
	P->_PL_Ready1 = v[3];
	P->_PL_Waiting1 = v[4];
	P->_PL_Q1 = v[5];
	P->_PL_Pos1_4 = v[6];
	P->_PL_Pos1_3 = v[7];
	P->_PL_Pos1_2 = v[8];
	P->_PL_Ready2 = v[9];
	P->_PL_Waiting2 = v[10];
	P->_PL_Buffer2 = v[11];
	P->_PL_Pos2_1 = v[12];
	P->_PL_Pos2_2 = v[13];
	P->_PL_Q2 = v[14];
	P->_PL_Pos2_4 = v[15];
	P->_PL_OccPos2 = v[16];
	P->_PL_Up1 = v[17];
	P->_PL_Pos2_3 = v[18];
	P->_PL_OccPos1 = v[19];
	P->_PL_Down1 = v[20];
	P->_PL_Up2 = v[21];
	P->_PL_Down2 = v[22];
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
pl(23), tr(23), Place(23),Transition(23),ParamDistr(3), TransitionConditions(23,0){
    Path ="Policy2.grml";
