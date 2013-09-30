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
	vect[reducePL_RE_ERK] = Marking.P->_PL_RE_ERK;
	vect[reducePL_RE_ERKP] = Marking.P->_PL_RE_ERKP + Marking.P->_PL_ERKP_Phase3; //To Complete
	vect[reducePL_RE_ERKPP] = Marking.P->_PL_RE_ERKPP + Marking.P->_PL_ERKPP_Phase3;//To Complete
	vect[reducePL_RE_ERKP_MEKPP] = Marking.P->_PL_RE_ERKP_MEKPP;
	vect[reducePL_RE_ERK_MEKPF] = Marking.P->_PL_RE_ERK_MEKPF;
	vect[reducePL_RE_MEK] = Marking.P->_PL_RE_MEK;
	vect[reducePL_RE_MEKP] = Marking.P->_PL_RE_MEKP + Marking.P->_PL_MEKP_Phase2;//To Complete
	vect[reducePL_RE_MEKPP] = Marking.P->_PL_RE_MEKPP + Marking.P->_PL_MEKPP_Phase2;//To Complete
	vect[reducePL_RE_MEKP_RafP] = Marking.P->_PL_RE_MEKP_RafP;
	vect[reducePL_RE_MEK_RafP] = Marking.P->_PL_RE_MEK_RafP;
	vect[reducePL_RE_Raf] = Marking.P->_PL_RE_Raf;
	vect[reducePL_RE_RafP] = Marking.P->_PL_RE_RafP + Marking.P->_PL_RafP_Phase1;//To Complete
	vect[reducePL_RE_Raf_RasGTP] = Marking.P->_PL_RE_Raf_RasGTP;
}

/*
void SPN::lumpingFun(abstractMarking &Marking,vector<int> &vect){
	vect[reducePL_RE_ERK] = Marking.P->_PL_RE_ERK;
	vect[reducePL_RE_ERKP] = Marking.P->_PL_RE_ERKP + Marking.P->_PL_ERKP_Phase3;
	vect[reducePL_RE_ERKPP] = Marking.P->_PL_RE_ERKPP + Marking.P->_PL_ERKPP_Phase3;
	vect[reducePL_RE_ERKP_MEKPP] = Marking.P->_PL_RE_ERKP_MEKPP; //+ Marking.P->_PL_ERKPP_Phase3;
	vect[reducePL_RE_ERK_MEKPF] = Marking.P->_PL_RE_ERK_MEKPF; //+ Marking.P->_PL_ERKP_Phase3;
	vect[reducePL_RE_MEK] = Marking.P->_PL_RE_MEK;
	vect[reducePL_RE_MEKP] = Marking.P->_PL_RE_MEKP + Marking.P->_PL_MEKP_Phase2;
	vect[reducePL_RE_MEKPP] = Marking.P->_PL_RE_MEKPP + Marking.P->_PL_MEKPP_Phase2;
	vect[reducePL_RE_MEKP_RafP] = Marking.P->_PL_RE_MEKP_RafP;// + Marking.P->_PL_MEKPP_Phase2;
	vect[reducePL_RE_MEK_RafP] = Marking.P->_PL_RE_MEK_RafP;// + Marking.P->_PL_MEKP_Phase2;
	vect[reducePL_RE_Raf] =  Marking.P->_PL_RE_Raf;
	vect[reducePL_RE_RafP] = Marking.P->_PL_RE_RafP+ Marking.P->_PL_RafP_Phase1;
	vect[reducePL_RE_Raf_RasGTP] = Marking.P->_PL_RE_Raf_RasGTP;// + Marking.P->_PL_RafP_Phase1;
}*/