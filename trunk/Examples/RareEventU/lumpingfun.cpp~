
#include "markingImpl.hpp"

const int reducePL_RE_Queue1 = 0;
const int reducePL_RE_Queue2 = 1;

void SPN::lumpingFun(const abstractMarking &Marking,vector<int> &vect){
	
	vect[reducePL_RE_Queue1] = Marking.P->_PL_RE_Queue1+ fmax(0,Marking.P->_PL_RE_Queue2-r); //To Complete
	
	vect[reducePL_RE_Queue2] = fmin(r,Marking.P->_PL_RE_Queue2); //To Complete
}

/*

void SPN::lumpingFun(vector<int>* vect){
    int reste =0;
    for (int i=vect->size()-1; i>0; i--) {
        if((*vect)[i]>r){
            reste += (*vect)[i]-r ;
            (*vect)[i]=r;
        } else if((*vect)[i]+reste>r){
            reste -= (r -(*vect)[i]);
            (*vect)[i]=r;
        } else {
            (*vect)[i] += reste;
            reste =0;
        }
    }
    (*vect)[0] += reste;
    
}
*/