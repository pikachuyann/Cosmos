#include "spn.hpp"
#include <iomanip>
	const double mu=0.23;
	const double r=5;
	const double rho=0.385;
	const int _nb_Place_RE_Queue1=0;
	const int _nb_Place_RE_Queue2=1;
	const int _nb_Place_Puit=2;
#include "lumpingfun.cpp"
#include <iostream>
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
	s  << setw(14) << "RE_Queue1" << setw(14) << "RE_Queue2" << setw(14) << "Puit";}

void abstractMarking::print(ostream &s)const{
	s << setw(14) << P->_PL_RE_Queue1;
	s << setw(14) << P->_PL_RE_Queue2;
	s << setw(14) << P->_PL_Puit;
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
SPN::SPN():
pl(3), tr(5), Place(3),Transition(5),ParamDistr(3), TransitionConditions(5,0){
    Path ="tandem.gspn";
