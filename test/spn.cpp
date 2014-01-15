#include "spn.hpp"
#include <iomanip>
	const int _nb_Place_RecBuff=0;
	const int _nb_Place_all_active=1;
	const int _nb_Place_Active=2;
	const int _nb_Place_Mutex=3;
	const int _nb_Place_Message=4;
	const int _nb_Place_Modify=5;
	const int _nb_Place_MesBuffReply=6;
	const int _nb_Place_Acknowledge=7;
	const int _nb_Place_all_passive=8;
	const int _nb_Place_updating=9;
	const int _nb_Place_WaitMutex=10;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"
site_Domain operator + (const site_Token& t1 ,const site_Token& t2 ){
	site_Domain d; d += t1; d+=t2 ;
	return d;
}
std::ostream& operator << (std::ostream& out, const site_Domain& x) {
	stringstream outprintloot;
	for(size_t c0 = 0 ; c0< Color_site_Total; c0++ )
		if(x.mult[c0])
					outprintloot << x.mult[c0]<< "<" << Color_site_names[c0]<< "> ";
	out << outprintloot.str();
	return out;
}
inline bool contains(const site_Domain& d1, const site_Domain& d2){	return (d1-d2) > -1;
}
inline bool contains(const site_Domain& d1, const site_Token& tok){	return d1 >= tok;
}
file_Domain operator + (const file_Token& t1 ,const file_Token& t2 ){
	file_Domain d; d += t1; d+=t2 ;
	return d;
}
std::ostream& operator << (std::ostream& out, const file_Domain& x) {
	stringstream outprintloot;
	for(size_t c0 = 0 ; c0< Color_file_Total; c0++ )
		if(x.mult[c0])
					outprintloot << x.mult[c0]<< "<" << Color_file_names[c0]<< "> ";
	out << outprintloot.str();
	return out;
}
inline bool contains(const file_Domain& d1, const file_Domain& d2){	return (d1-d2) > -1;
}
inline bool contains(const file_Domain& d1, const file_Token& tok){	return d1 >= tok;
}
SF_Domain operator + (const SF_Token& t1 ,const SF_Token& t2 ){
	SF_Domain d; d += t1; d+=t2 ;
	return d;
}
std::ostream& operator << (std::ostream& out, const SF_Domain& x) {
	stringstream outprintloot;
	for(size_t c0 = 0 ; c0< Color_site_Total; c0++ )
	for(size_t c1 = 0 ; c1< Color_file_Total; c1++ )
		if(x.mult[c0][c1])
					outprintloot << x.mult[c0][c1]<< "<" << Color_site_names[c0] << "," << Color_file_names[c1]<< "> ";
	out << outprintloot.str();
	return out;
}
inline bool contains(const SF_Domain& d1, const SF_Domain& d2){	return (d1-d2) > -1;
}
inline bool contains(const SF_Domain& d1, const SF_Token& tok){	return d1 >= tok;
}

void abstractMarking::resetToInitMarking(){
	P->_PL_RecBuff =0;
	P->_PL_all_active =((site_Domain(1)) * 1);
	P->_PL_Active =0;
	P->_PL_Mutex =((file_Domain(1)) * 1);
	P->_PL_Message =0;
	P->_PL_Modify =0;
	P->_PL_MesBuffReply =0;
	P->_PL_Acknowledge =0;
	P->_PL_all_passive =((site_Domain(1)) * 1);
	P->_PL_updating =0;
	P->_PL_WaitMutex =0;
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
	if(P->s.mult >= 0){
		if (! P->s.islast()){	P->s.iter(); return true; };
		P->s = site_Token();
	}
	if(P->f.mult >= 0){
		if (! P->f.islast()){	P->f.iter(); return true; };
		P->f = file_Token();
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
	std::cerr << "\ts: ";P->s.print();
	cerr << endl;
	std::cerr << "\tf: ";P->f.print();
	cerr << endl;
}
int abstractBinding::id()const{
	return idcount;
}
int abstractBinding::idTotal()const{
	 return P->s.c0 + Color_site_Total *(P->f.c0 + Color_file_Total *(0));
}
const char *Color_site_names[Color_site_Total] = {
"s1","s2","s3","s4",
};
const char *Color_file_names[Color_file_Total] = {
"f1","f2",
};
SPN::SPN():
pl(11), tr(8), Place(11),Transition(8),ParamDistr(3), TransitionConditions(8,0){
    Path ="database";
	PossiblyEnabled = vector< set<int> >(8);
	PossiblyEnabled[0].insert( 6 );
	PossiblyEnabled[1].insert( 3 );
	PossiblyEnabled[2].insert( 0 );
	PossiblyEnabled[2].insert( 3 );
	PossiblyEnabled[3].insert( 4 );
	PossiblyEnabled[3].insert( 7 );
	PossiblyEnabled[4].insert( 2 );
	PossiblyEnabled[5].insert( 1 );
	PossiblyEnabled[5].insert( 6 );
	PossiblyEnabled[6].insert( 5 );
	PossiblyEnabled[7].insert( 4 );

	PossiblyDisabled = vector< set<int> >(8);

	FreeMarkDepT = vector< set<int> >(8);

	Transition[0] = _trans(0,Timed,EXPONENTIAL,0,8);
	{abstractBinding bl = Transition[0].bindingList[0];
	while(bl.next()){
		if( true ){
			bl.idcount = Transition[0].bindingList.size();
			Transition[0].bindingList.push_back( bl );
			Transition[0].bindingLinkTable[bl.idTotal()]= Transition[0].bindingList.size()-1; 
		}
	}}
	Transition[1] = _trans(1,Timed,EXPONENTIAL,0,8);
	{abstractBinding bl = Transition[1].bindingList[0];
	while(bl.next()){
		if( true ){
			bl.idcount = Transition[1].bindingList.size();
			Transition[1].bindingList.push_back( bl );
			Transition[1].bindingLinkTable[bl.idTotal()]= Transition[1].bindingList.size()-1; 
		}
	}}
	Transition[2] = _trans(2,Timed,EXPONENTIAL,0,8);
	{abstractBinding bl = Transition[2].bindingList[0];
	while(bl.next()){
		if( true ){
			bl.idcount = Transition[2].bindingList.size();
			Transition[2].bindingList.push_back( bl );
			Transition[2].bindingLinkTable[bl.idTotal()]= Transition[2].bindingList.size()-1; 
		}
	}}
	Transition[3] = _trans(3,Timed,DETERMINISTIC,0,8);
	{abstractBinding bl = Transition[3].bindingList[0];
	while(bl.next()){
		if( true ){
			bl.idcount = Transition[3].bindingList.size();
			Transition[3].bindingList.push_back( bl );
			Transition[3].bindingLinkTable[bl.idTotal()]= Transition[3].bindingList.size()-1; 
		}
	}}
	Transition[4] = _trans(4,Timed,DETERMINISTIC,0,8);
	{abstractBinding bl = Transition[4].bindingList[0];
	while(bl.next()){
		if( true ){
			bl.idcount = Transition[4].bindingList.size();
			Transition[4].bindingList.push_back( bl );
			Transition[4].bindingLinkTable[bl.idTotal()]= Transition[4].bindingList.size()-1; 
		}
	}}
	Transition[5] = _trans(5,Timed,EXPONENTIAL,0,8);
	{abstractBinding bl = Transition[5].bindingList[0];
	while(bl.next()){
		if( true ){
			bl.idcount = Transition[5].bindingList.size();
			Transition[5].bindingList.push_back( bl );
			Transition[5].bindingLinkTable[bl.idTotal()]= Transition[5].bindingList.size()-1; 
		}
	}}
	Transition[6] = _trans(6,Timed,DETERMINISTIC,0,8);
	{abstractBinding bl = Transition[6].bindingList[0];
	while(bl.next()){
		if( true ){
			bl.idcount = Transition[6].bindingList.size();
			Transition[6].bindingList.push_back( bl );
			Transition[6].bindingLinkTable[bl.idTotal()]= Transition[6].bindingList.size()-1; 
		}
	}}
	Transition[7] = _trans(7,Timed,EXPONENTIAL,0,8);
	{abstractBinding bl = Transition[7].bindingList[0];
	while(bl.next()){
		if( true ){
			bl.idcount = Transition[7].bindingList.size();
			Transition[7].bindingList.push_back( bl );
			Transition[7].bindingLinkTable[bl.idTotal()]= Transition[7].bindingList.size()-1; 
		}
	}}
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 1:	//SendReply
    if ( !(((SF_Token(b.P->s, b.P->f) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_MesBuffReply , ((SF_Token(b.P->s, b.P->f) * (1)))))) return false;
    return true;

		break;
	case 0:	//SendMsg
    if ( !(((SF_Token(b.P->s, b.P->f) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_Message , ((SF_Token(b.P->s, b.P->f) * (1)))))) return false;
    return true;

		break;
	case 2:	//Change
    if ( !(((SF_Token(b.P->s, b.P->f) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_Modify , ((SF_Token(b.P->s, b.P->f) * (1)))))) return false;
    return true;

		break;
	case 6:	//Update
    if ( !(((SF_Token(b.P->s, b.P->f) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_RecBuff , ((SF_Token(b.P->s, b.P->f) * (1)))))) return false;
    if ( !(((site_Token(b.P->s) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_all_passive , ((site_Token(b.P->s) * (1)))))) return false;
    return true;

		break;
	case 5:	//end_update
    if ( !(((SF_Token(b.P->s, b.P->f) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_updating , ((SF_Token(b.P->s, b.P->f) * (1)))))) return false;
    return true;

		break;
	case 4:	//Acquire
    if ( !(((file_Token(b.P->f) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_Mutex , ((file_Token(b.P->f) * (1)))))) return false;
    if ( !(((SF_Token(b.P->s, b.P->f) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_WaitMutex , ((SF_Token(b.P->s, b.P->f) * (1)))))) return false;
    return true;

		break;
	case 7:	//Start
    if ( !(((site_Token(b.P->s) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_all_active , ((site_Token(b.P->s) * (1)))))) return false;
    return true;

		break;
	default:	//Release,
    if ( !(((SF_Token(b.P->s, b.P->f) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_Active , ((SF_Token(b.P->s, b.P->f) * (1)))))) return false;
    if ( !(((SF_Domain(Color_site_All, b.P->f.c0) * (1))) < 1)) 
        if (!(contains(Marking.P->_PL_Acknowledge , ((SF_Domain(Color_site_All, b.P->f.c0) * (1)))))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b){
	lastTransition = t;
	switch(t){
		case 0: {  //SendMsg
			SF_Domain tmpMark_RecBuff = Marking.P->_PL_RecBuff;
			SF_Domain tmpMark_Message = Marking.P->_PL_Message;
			Marking.P->_PL_RecBuff += ((SF_Token(b.P->s, b.P->f) * (1)));
			Marking.P->_PL_Message -= ((SF_Token(b.P->s, b.P->f) * (1)));
       break;
     } 
		case 1: {  //SendReply
			SF_Domain tmpMark_MesBuffReply = Marking.P->_PL_MesBuffReply;
			SF_Domain tmpMark_Acknowledge = Marking.P->_PL_Acknowledge;
			Marking.P->_PL_MesBuffReply -= ((SF_Token(b.P->s, b.P->f) * (1)));
			Marking.P->_PL_Acknowledge += ((SF_Token(b.P->s, b.P->f) * (1)));
       break;
     } 
		case 2: {  //Change
			SF_Domain tmpMark_Active = Marking.P->_PL_Active;
			SF_Domain tmpMark_Message = Marking.P->_PL_Message;
			SF_Domain tmpMark_Modify = Marking.P->_PL_Modify;
			Marking.P->_PL_Active += ((SF_Token(b.P->s, b.P->f) * (1)));
			Marking.P->_PL_Message += ((SF_Domain(Color_site_All, b.P->f.c0) * (1)));
			Marking.P->_PL_Modify -= ((SF_Token(b.P->s, b.P->f) * (1)));
       break;
     } 
		case 3: {  //Release
			site_Domain tmpMark_all_active = Marking.P->_PL_all_active;
			SF_Domain tmpMark_Active = Marking.P->_PL_Active;
			file_Domain tmpMark_Mutex = Marking.P->_PL_Mutex;
			SF_Domain tmpMark_Acknowledge = Marking.P->_PL_Acknowledge;
			Marking.P->_PL_all_active += ((site_Token(b.P->s) * (1)));
			Marking.P->_PL_Active -= ((SF_Token(b.P->s, b.P->f) * (1)));
			Marking.P->_PL_Mutex += ((file_Token(b.P->f) * (1)));
			Marking.P->_PL_Acknowledge -= ((SF_Domain(Color_site_All, b.P->f.c0) * (1)));
       break;
     } 
		case 4: {  //Acquire
			file_Domain tmpMark_Mutex = Marking.P->_PL_Mutex;
			SF_Domain tmpMark_Modify = Marking.P->_PL_Modify;
			SF_Domain tmpMark_WaitMutex = Marking.P->_PL_WaitMutex;
			Marking.P->_PL_Mutex -= ((file_Token(b.P->f) * (1)));
			Marking.P->_PL_Modify += ((SF_Token(b.P->s, b.P->f) * (1)));
			Marking.P->_PL_WaitMutex -= ((SF_Token(b.P->s, b.P->f) * (1)));
       break;
     } 
		case 5: {  //end_update
			SF_Domain tmpMark_MesBuffReply = Marking.P->_PL_MesBuffReply;
			site_Domain tmpMark_all_passive = Marking.P->_PL_all_passive;
			SF_Domain tmpMark_updating = Marking.P->_PL_updating;
			Marking.P->_PL_MesBuffReply += ((SF_Token(b.P->s, b.P->f) * (1)));
			Marking.P->_PL_all_passive += ((site_Token(b.P->s) * (1)));
			Marking.P->_PL_updating -= ((SF_Token(b.P->s, b.P->f) * (1)));
       break;
     } 
		case 6: {  //Update
			SF_Domain tmpMark_RecBuff = Marking.P->_PL_RecBuff;
			site_Domain tmpMark_all_passive = Marking.P->_PL_all_passive;
			SF_Domain tmpMark_updating = Marking.P->_PL_updating;
			Marking.P->_PL_RecBuff -= ((SF_Token(b.P->s, b.P->f) * (1)));
			Marking.P->_PL_all_passive -= ((site_Token(b.P->s) * (1)));
			Marking.P->_PL_updating += ((SF_Token(b.P->s, b.P->f) * (1)));
       break;
     } 
		case 7: {  //Start
			site_Domain tmpMark_all_active = Marking.P->_PL_all_active;
			SF_Domain tmpMark_WaitMutex = Marking.P->_PL_WaitMutex;
			Marking.P->_PL_all_active -= ((site_Token(b.P->s) * (1)));
			Marking.P->_PL_WaitMutex += ((SF_Token(b.P->s, b.P->f) * (1)));
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
		//Partial synch over variable: SendMsg->Update var Not set
		//Fallback:SendReply->Release
		//Fallback:Change->SendMsg
		//Partial synch over variable: Change->Release var Not set
		//Partial synch over variable: Release->Acquire var s, Not set
		//Partial synch over variable: Release->Start var f, Not set
		//Partial synch over variable: Acquire->Change var Not set
		//Partial synch over variable: end_update->SendReply var Not set
		//Partial synch over variable: end_update->Update var f, Not set
		//Partial synch over variable: Update->end_update var Not set
		//Partial synch over variable: Start->Acquire var Not set
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum){
	switch(lastTransition*(tr+1) + targettr){
		//Partial synch over variable: SendMsg->SendMsg var Not set
		//Partial synch over variable: SendReply->SendReply var Not set
		//Partial synch over variable: Change->Change var Not set
		//Fallback:Release->Release
		//Partial synch over variable: Acquire->Acquire var Not set
		//Partial synch over variable: end_update->end_update var Not set
		//Partial synch over variable: Update->Update var Not set
		//Partial synch over variable: Start->Start var f, Not set
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(size_t t, const abstractBinding&)const {
switch (t){
	case 2:	//Change
	case 5:	//end_update
	{
		ParamDistr[0]= ( double ) 0.2;
	}

		break;
	case 0:	//SendMsg
	case 1:	//SendReply
	case 7:	//Start
	{
		ParamDistr[0]= ( double ) 5.0;
	}

		break;
	default:	//Release,Acquire,Update,
	{
		ParamDistr[0]= ( double ) 0.0;
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

