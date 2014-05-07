#include "markingImpl.hpp"
void SPN::print_state(const vector<int> &vect){
}
bool SPN::precondition(const abstractMarking &Marking){return true;}

void SPN::lumpingFun(const abstractMarking &Marking,vector<int> &vect){
	vect[0] = Marking.P->_PL_RE_Queue1;
	vect[1] = Marking.P->_PL_RE_Queue2;
	vect[2] = Marking.P->_PL_RE_Queue3;
	vect[3] = Marking.P->_PL_RE_Queue4;
	vect[4] = Marking.P->_PL_RE_Queue5;
	vect[5] = Marking.P->_PL_RE_Queue6;
	vect[6] = Marking.P->_PL_RE_Queue7;
	vect[7] = Marking.P->_PL_RE_Queue8;
	vect[8] = Marking.P->_PL_RE_Queue9;
	int reste =0;
    for (int i=vect.size()-1; i>0; i--) {
        if(vect[i]>r){
            reste += vect[i]-r ;
            vect[i]=r;
        } else if(vect[i]+reste>r){
            reste -= (r - vect[i]);
            vect[i]=r;
        } else {
            vect[i] += reste;
            reste =0;
        }
    }
    vect[0] += reste;
}