#include "spn.hpp"
#include <iomanip>
	const int _nb_Place_P1=0;
	const int _nb_Place_P2=1;
	const int _nb_Place_P3=2;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_P1 =1;
	P->_PL_P2 =0;
	P->_PL_P3 =0;
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
		case 0: return P->_PL_P1;
		case 1: return P->_PL_P2;
		case 2: return P->_PL_P3;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(3);
	v[0] = P->_PL_P1;
	v[1] = P->_PL_P2;
	v[2] = P->_PL_P3;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_P1 = v[0];
	P->_PL_P2 = v[1];
	P->_PL_P3 = v[2];
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
pl(3), tr(3), Place(3),Transition(3),ParamDistr(3), TransitionConditions(3,0){
    Path ="pi.grml";
