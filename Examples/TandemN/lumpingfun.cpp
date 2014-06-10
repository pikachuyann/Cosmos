#include "markingImpl.hpp"
void SPN::print_state(const vector<int> &vect){
}
bool SPN::precondition(const abstractMarking &Marking){return true;}

void SPN::lumpingFun(const abstractMarking &Marking,vector<int> &vect){
	vect[0] = Marking.P->_PL_RE_Queue1;
	vect[1] = Marking.P->_PL_RE_Queue2;
	vect[2] = Marking.P->_PL_RE_Queue3;
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