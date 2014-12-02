#include "spn.hpp"
#include <iomanip>
	const double bt=0.5;
	const double fl=1;
	const double fr=1;
	const int _nb_Place_Think=0;
	const int _nb_Place_Wait=1;
	const int _nb_Place_Eat=2;
	const int _nb_Place_Fork=3;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"
philo_Domain operator + (const philo_Token& t1 ,const philo_Token& t2 ){
	philo_Domain d; d += t1; d+=t2 ;
	return d;
}
std::ostream& operator << (std::ostream& out, const philo_Domain& x) {
	stringstream outprintloot;
	for(size_t c0 = 0 ; c0< Color_philo_Total; c0++ )
		if(x.mult[c0])
					outprintloot << x.mult[c0]<< "<" << Color_philo_names[c0]<< ">,";
	out << "(" << outprintloot.str() << ")";
	return out;
}
inline bool contains(const philo_Domain& d1, const philo_Domain& d2){	return (d1-d2) > -1;
}
inline bool contains(const philo_Domain& d1, const philo_Token& tok){	return d1 >= tok;
}

void abstractMarking::resetToInitMarking(){
	P->_PL_Think =((philo_Domain(Color_philo_All) * (1 )));
	P->_PL_Wait =0;
	P->_PL_Eat =0;
	P->_PL_Fork =((philo_Domain(Color_philo_All) * (1 )));
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
	s  << setw(10) << "Think" << setw(10) << "Wait" << setw(10) << "Eat" << setw(10) << "Fork";}

void abstractMarking::printSedCmd(ostream &s)const{
	s << "-e 's/\\$Think\\$/";
	if(P->_PL_Think> 0){s<< P->_PL_Think;};
s <<"/g' ";
	s << "-e 's/\\$Wait\\$/";
	if(P->_PL_Wait> 0){s<< P->_PL_Wait;};
s <<"/g' ";
	s << "-e 's/\\$Eat\\$/";
	if(P->_PL_Eat> 0){s<< P->_PL_Eat;};
s <<"/g' ";
	s << "-e 's/\\$Fork\\$/";
	if(P->_PL_Fork> 0){s<< P->_PL_Fork;};
s <<"/g' ";
}
void abstractMarking::print(ostream &s)const{
	s << setw(10) << P->_PL_Think;
	s << setw(10) << P->_PL_Wait;
	s << setw(10) << P->_PL_Eat;
	s << setw(10) << P->_PL_Fork;
}

int abstractMarking::getNbOfTokens(int p)const {
	exit(EXIT_FAILURE);
}

std::vector<int> abstractMarking::getVector()const {
	exit(EXIT_FAILURE);
}

void abstractMarking::setVector(const std::vector<int>&v) {
	exit(EXIT_FAILURE);
};

bool abstractBinding::next() {
	idcount++;
	if(P->x.mult >= 0){
		if (! P->x.islast()){	P->x.iter(); return true; };
		P->x = philo_Token();
	}
	return false;
};
abstractBinding::abstractBinding() {
 P= new abstractBindingImpl;
       idcount=0;
}
abstractBinding::abstractBinding(const abstractBinding& m) {
 P= new abstractBindingImpl;
 *P = *m.P;
	idcount = m.idcount;
}
abstractBinding::~abstractBinding() {
 delete P;
}
abstractBinding& abstractBinding::operator = (const abstractBinding& m) {
 *P = *m.P;
	idcount = m.idcount;
       return *this;
}
void abstractBinding::print()const{
	std::cerr << "\tx: ";P->x.print();
	cerr << endl;
}
int abstractBinding::id()const{
	return idcount;
}
int abstractBinding::idTotal()const{
	 return P->x.c0 + Color_philo_Total *(0);
}
const char *Color_philo_names[Color_philo_Total] = {
"p1","p2","p3","p4","p5",
};
SPN::SPN():
pl(4), tr(3), Transition(3),Place(4),ParamDistr(3), TransitionConditions(3,0){
    Path ="philo.grml";
	PossiblyEnabled = vector< set<int> >(3);
	PossiblyEnabled[0].insert( 1 );
	PossiblyEnabled[1].insert( 2 );
	PossiblyEnabled[2].insert( 0 );
	PossiblyEnabled[2].insert( 1 );

	PossiblyDisabled = vector< set<int> >(3);
	PossiblyDisabled[0].insert( 1 );
	PossiblyDisabled[1].insert( 0 );

	FreeMarkDepT = vector< set<int> >(3);

    Place[0].label =" Think";
    Place[0].isTraced = 1;
    Place[1].label =" Wait";
    Place[1].isTraced = 1;
    Place[2].label =" Eat";
    Place[2].isTraced = 1;
    Place[3].label =" Fork";
    Place[3].isTraced = 1;
	Transition[0] = _trans(0,Timed,EXPONENTIAL,0,5);
	Transition[0].label = "takeLeft";
	{abstractBinding bl = Transition[0].bindingList[0];
	bl.P->x.mult = -1;
	while(bl.next()){
		{
			bl.idcount = Transition[0].bindingList.size();
			Transition[0].bindingList.push_back( bl );
			Transition[0].bindingLinkTable[bl.idTotal()]= Transition[0].bindingList.size()-1; 
		}
	}}
	Transition[1] = _trans(1,Timed,EXPONENTIAL,0,5);
	Transition[1].label = "takeRight";
	{abstractBinding bl = Transition[1].bindingList[0];
	bl.P->x.mult = -1;
	while(bl.next()){
		{
			bl.idcount = Transition[1].bindingList.size();
			Transition[1].bindingList.push_back( bl );
			Transition[1].bindingLinkTable[bl.idTotal()]= Transition[1].bindingList.size()-1; 
		}
	}}
	Transition[2] = _trans(2,Timed,EXPONENTIAL,0,5);
	Transition[2].label = "backToThink";
	{abstractBinding bl = Transition[2].bindingList[0];
	bl.P->x.mult = -1;
	while(bl.next()){
		{
			bl.idcount = Transition[2].bindingList.size();
			Transition[2].bindingList.push_back( bl );
			Transition[2].bindingLinkTable[bl.idTotal()]= Transition[2].bindingList.size()-1; 
		}
	}}
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 0:	//takeLeft
    if ( !(((philo_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Think , ((philo_Token(b.P->x) * (1 )))))) return false;
    if ( !(((philo_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Fork , ((philo_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 1:	//takeRight
    if ( !(((philo_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Wait , ((philo_Token(b.P->x) * (1 )))))) return false;
    if ( !(((philo_Token(b.P->x.next(1)) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Fork , ((philo_Token(b.P->x.next(1)) * (1 )))))) return false;
    return true;

		break;
	default:	//backToThink,
    if ( !(((philo_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Eat , ((philo_Token(b.P->x) * (1 )))))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b,double time){
	lastTransition = t;
	switch(t){
		case 0: {  //takeLeft
			philo_Domain tmpMark_Think = Marking.P->_PL_Think;
			philo_Domain tmpMark_Wait = Marking.P->_PL_Wait;
			philo_Domain tmpMark_Fork = Marking.P->_PL_Fork;
			Marking.P->_PL_Think -= ((philo_Token(b.P->x) * (1 )));
			Marking.P->_PL_Wait += ((philo_Token(b.P->x) * (1 )));
			Marking.P->_PL_Fork -= ((philo_Token(b.P->x) * (1 )));
       break;
     } 
		case 1: {  //takeRight
			philo_Domain tmpMark_Wait = Marking.P->_PL_Wait;
			philo_Domain tmpMark_Eat = Marking.P->_PL_Eat;
			philo_Domain tmpMark_Fork = Marking.P->_PL_Fork;
			Marking.P->_PL_Wait -= ((philo_Token(b.P->x) * (1 )));
			Marking.P->_PL_Eat += ((philo_Token(b.P->x) * (1 )));
			Marking.P->_PL_Fork -= ((philo_Token(b.P->x.next(1)) * (1 )));
       break;
     } 
		case 2: {  //backToThink
			philo_Domain tmpMark_Think = Marking.P->_PL_Think;
			philo_Domain tmpMark_Eat = Marking.P->_PL_Eat;
			philo_Domain tmpMark_Fork = Marking.P->_PL_Fork;
			Marking.P->_PL_Think += ((philo_Token(b.P->x) * (1 )));
			Marking.P->_PL_Eat -= ((philo_Token(b.P->x) * (1 )));
			Marking.P->_PL_Fork += ((philo_Token(b.P->x) * (1 )) + (philo_Token(b.P->x.next(1)) * (1 )));
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
	case 0:	//takeLeft
	{
		ParamDistr[0]= ( double ) fl ;
	}

		break;
	case 1:	//takeRight
	{
		ParamDistr[0]= ( double ) fr ;
	}

		break;
	default:	//backToThink,
	{
		ParamDistr[0]= ( double ) bt ;
	}

}
}

double SPN::GetPriority(size_t t)const {
		return (double)1 ;

}

double SPN::GetWeight(size_t t)const{
		return (double)1 ;

}

void SPN::Msimple(){
	vector<int> tab;
	Msimpletab = tab;
}
void SPN::reset() {
	Marking.resetToInitMarking();
	TransitionConditions = initTransitionConditions;
}

