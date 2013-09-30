#include "markingImpl.hpp"

const int reducePL_RE_Queue1 = 0;
const int reducePL_RE_Queue2 = 1;
void SPN::print_state(const vector<int> &vect){
	cerr << "RE_Queue1 = " << vect[reducePL_RE_Queue1] << endl;
	cerr << "RE_Queue2 = " << vect[reducePL_RE_Queue2] << endl;
}

void SPN::lumpingFun(const abstractMarking &Marking,vector<int> &vect){
	vect[reducePL_RE_Queue1] = Marking.P->_PL_RE_Queue1; //To Complete
	vect[reducePL_RE_Queue2] = Marking.P->_PL_RE_Queue2; //To Complete
}
