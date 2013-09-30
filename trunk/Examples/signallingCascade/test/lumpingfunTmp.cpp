#include "markingImpl.hpp"

const int reducePL_RE_ERK = 0;
const int reducePL_RE_ERKP = 1;
const int reducePL_RE_ERKPP = 2;
const int reducePL_RE_ERKP_MEKPP = 3;
const int reducePL_RE_ERK_MEKPF = 4;
const int reducePL_RE_MEK = 5;
const int reducePL_RE_MEKP = 6;
const int reducePL_RE_MEKPP = 7;
const int reducePL_RE_MEKP_RafP = 8;
const int reducePL_RE_MEK_RafP = 9;
const int reducePL_RE_Raf = 10;
const int reducePL_RE_RafP = 11;
const int reducePL_RE_Raf_RasGTP = 12;

void SPN::lumpingFun(abstractMarking &Marking,vector<int> &vect){
	vect[reducePL_RE_ERK] = Marking.P->_PL_RE_ERK; //To Complete
	vect[reducePL_RE_ERKP] = Marking.P->_PL_RE_ERKP; //To Complete
	vect[reducePL_RE_ERKPP] = Marking.P->_PL_RE_ERKPP; //To Complete
	vect[reducePL_RE_ERKP_MEKPP] = Marking.P->_PL_RE_ERKP_MEKPP; //To Complete
	vect[reducePL_RE_ERK_MEKPF] = Marking.P->_PL_RE_ERK_MEKPF; //To Complete
	vect[reducePL_RE_MEK] = Marking.P->_PL_RE_MEK; //To Complete
	vect[reducePL_RE_MEKP] = Marking.P->_PL_RE_MEKP; //To Complete
	vect[reducePL_RE_MEKPP] = Marking.P->_PL_RE_MEKPP; //To Complete
	vect[reducePL_RE_MEKP_RafP] = Marking.P->_PL_RE_MEKP_RafP; //To Complete
	vect[reducePL_RE_MEK_RafP] = Marking.P->_PL_RE_MEK_RafP; //To Complete
	vect[reducePL_RE_Raf] = Marking.P->_PL_RE_Raf; //To Complete
	vect[reducePL_RE_RafP] = Marking.P->_PL_RE_RafP; //To Complete
	vect[reducePL_RE_Raf_RasGTP] = Marking.P->_PL_RE_Raf_RasGTP; //To Complete
}
