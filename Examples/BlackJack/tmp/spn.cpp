#include "spn.hpp"
#include <iomanip>
	const int _nb_Place_LastDraw=0;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_LastDraw =0;
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
		case 0: return P->_PL_LastDraw;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(1);
	v[0] = P->_PL_LastDraw;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_LastDraw = v[0];
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
pl(1), tr(10), Place(1),Transition(10),ParamDistr(3), TransitionConditions(10,0){
    Path ="DeckInfiny.grml";
	PossiblyEnabled = vector< set<int> >(10);
	{
		int PE[]= {1, 2, 3, 4, 5, 6, 7, 8, 9};
		PossiblyEnabled[0] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 2, 3, 4, 5, 6, 7, 8, 9};
		PossiblyEnabled[1] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 3, 4, 5, 6, 7, 8, 9};
		PossiblyEnabled[2] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 7, 8, 9};
		PossiblyEnabled[3] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 5, 6, 7, 8, 9};
		PossiblyEnabled[4] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 6, 7, 8, 9};
		PossiblyEnabled[5] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 7, 8, 9};
		PossiblyEnabled[6] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 8, 9};
		PossiblyEnabled[7] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 9};
		PossiblyEnabled[8] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8};
		PossiblyEnabled[9] = set<int>(PE,PE+9);
	}

	PossiblyDisabled = vector< set<int> >(10);
	{
		int PE[]= {1, 2, 3, 4, 5, 6, 7, 8, 9};
		PossiblyDisabled[0] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 2, 3, 4, 5, 6, 7, 8, 9};
		PossiblyDisabled[1] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 3, 4, 5, 6, 7, 8, 9};
		PossiblyDisabled[2] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 7, 8, 9};
		PossiblyDisabled[3] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 5, 6, 7, 8, 9};
		PossiblyDisabled[4] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 6, 7, 8, 9};
		PossiblyDisabled[5] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 7, 8, 9};
		PossiblyDisabled[6] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 8, 9};
		PossiblyDisabled[7] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 9};
		PossiblyDisabled[8] = set<int>(PE,PE+9);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8};
		PossiblyDisabled[9] = set<int>(PE,PE+9);
	}

	FreeMarkDepT = vector< set<int> >(10);

	Transition[0] = _trans(0,Timed,EXPONENTIAL,0,1);
	Transition[1] = _trans(1,Timed,EXPONENTIAL,0,1);
	Transition[2] = _trans(2,Timed,EXPONENTIAL,0,1);
	Transition[3] = _trans(3,Timed,EXPONENTIAL,0,1);
	Transition[4] = _trans(4,Timed,EXPONENTIAL,0,1);
	Transition[5] = _trans(5,Timed,EXPONENTIAL,0,1);
	Transition[6] = _trans(6,Timed,EXPONENTIAL,0,1);
	Transition[7] = _trans(7,Timed,EXPONENTIAL,0,1);
	Transition[8] = _trans(8,Timed,EXPONENTIAL,0,1);
	Transition[9] = _trans(9,Timed,EXPONENTIAL,0,1);
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
    if ( !((Marking.P->_PL_LastDraw) < 1)) 
        if (!(contains(Marking.P->_PL_LastDraw , (Marking.P->_PL_LastDraw)))) return false;
    return true;

}

void SPN::fire(size_t t, const abstractBinding& b){
	lastTransition = t;
	switch(t){
		case 0: {  //Draw2
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 2;
       break;
     } 
		case 1: {  //Draw3
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 3;
       break;
     } 
		case 2: {  //Draw7
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 7;
       break;
     } 
		case 3: {  //Draw5
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 5;
       break;
     } 
		case 4: {  //Draw9
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 9;
       break;
     } 
		case 5: {  //Draw4
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 4;
       break;
     } 
		case 6: {  //DrawAs
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 11;
       break;
     } 
		case 7: {  //Draw6
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 6;
       break;
     } 
		case 8: {  //Draw10
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 10;
       break;
     } 
		case 9: {  //Draw8
			int tmpMark_LastDraw = Marking.P->_PL_LastDraw;
			Marking.P->_PL_LastDraw -= (tmpMark_LastDraw);
			Marking.P->_PL_LastDraw += 8;
       break;
     } 
	}
}
void SPN::unfire(size_t t ,const abstractBinding& b){
}

const set<int>& SPN::PossiblyEn()const {
	return PossiblyEnabled[lastTransition];
}
const set<int>& SPN::PossiblyDis()const {
	return PossiblyDisabled[lastTransition];
}
const set<int>& SPN::FreeMarkingDependant()const {
	return FreeMarkDepT[lastTransition];
}
abstractBinding* SPN::nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum){
	switch(lastTransition*(tr+1) + targettr){
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum){
	switch(lastTransition*(tr+1) + targettr){
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(size_t t, const abstractBinding&)const {
switch (t){
	case 8:	//Draw10
	{
		ParamDistr[0]= ( double ) 4;
	}

		break;
	default:	//Draw2,Draw3,Draw7,Draw5,Draw9,Draw4,DrawAs,Draw6,Draw8,
	{
		ParamDistr[0]= ( double ) 1;
	}

}
}

double SPN::GetPriority(size_t t)const {
		return (double)1;

}

double SPN::GetWeight(size_t t)const{
		return (double)1;

}

void SPN::Msimple(){
	vector<int> tab;
	Msimpletab = tab;
}
void SPN::reset() {
	Marking.resetToInitMarking();
	TransitionConditions = initTransitionConditions;
}

