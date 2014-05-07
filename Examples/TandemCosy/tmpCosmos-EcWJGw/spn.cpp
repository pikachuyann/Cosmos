#include "spn.hpp"
#include <iomanip>
	const double r=200;
	const double rho0=0.32;
	const double rho1=0.34;
	const int _nb_Place_RE_Queue1=0;
	const int _nb_Place_RE_Queue2=1;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_RE_Queue1 =1;
	P->_PL_RE_Queue2 =0;
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
	s  << setw(14) << "RE_Queue1" << setw(14) << "RE_Queue2";}

void abstractMarking::print(ostream &s)const{
	s << setw(14) << P->_PL_RE_Queue1;
	s << setw(14) << P->_PL_RE_Queue2;
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_RE_Queue1;
		case 1: return P->_PL_RE_Queue2;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(2);
	v[0] = P->_PL_RE_Queue1;
	v[1] = P->_PL_RE_Queue2;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_RE_Queue1 = v[0];
	P->_PL_RE_Queue2 = v[1];
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
pl(2), tr(3), Place(2),Transition(3),ParamDistr(3), TransitionConditions(3,0){
    Path ="tandemPrism.grml";
