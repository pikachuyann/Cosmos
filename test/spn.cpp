#include "spn.hpp"
#include <iomanip>
#define PL_ReadyT_LP 0
#define PL_Healthy_LP 1
#define PL_Ill_LP 2
#define PL_Arrival_LP 3
#define PL_ThreatedByDocH_LP 4
#define PL_ThreatedByDocL_LP 5
#define PL_WaitingRoom_LP 6
#define PL_OperatingRoom_LP 7
#define PL_ArrivalUrgence_LP 8
#define PL_USurgery_LP 9
#define PL_TraumaTeam_LP 10
#define PL_Ustab_LP 11
#define PL_WSurgery_LP 12
#define PL_WBloodEx_LP 13
#define PL_WXRayEx_LP 14
#define PL_CountDoctor_LP 15
#define PL_MonitoredRoom_LP 16
#define PL_Doctor_LP 17
#define PL_PatientRecovered_LP 18
#define PL_UBloodEx_LP 19
#define PL_ResB_LP 20
#define PL_Waiting_LP 21
#define PL_ResX_LP 22
#define PL_UXRayEx_LP 23
#define PL_FXRay_LP 24
#define PL_FBloodEx_LP 25
#define TR_EXRayBlood_RT 0
#define TR_FallIll_RT 1
#define TR_HospitalArrival_RT 2
#define TR_EToThreat_RT 3
#define TR_EToSurgery_RT 4
#define TR_HighPrio_RT 5
#define TR_MediumPrio_RT 6
#define TR_DischargeL_RT 7
#define TR_LowPrio_RT 8
#define TR_BSurgery_RT 9
#define TR_ToSurgery_RT 10
#define TR_ToDoctor_RT 11
#define TR_ToDoctorL_RT 12
#define TR_BToStabilize_RT 13
#define TR_EToStabilize_RT 14
#define TR_DischargeRec_RT 15
#define TR_BBlood_RT 16
#define TR_BXRay_RT 17
#define TR_DischargeM_RT 18
#define TR_EBloodEx_RT 19
#define TR_EXRay_RT 20

	const int _nb_Place_ReadyT=0;
	const int _nb_Place_Healthy=1;
	const int _nb_Place_Ill=2;
	const int _nb_Place_Arrival=3;
	const int _nb_Place_ThreatedByDocH=4;
	const int _nb_Place_ThreatedByDocL=5;
	const int _nb_Place_WaitingRoom=6;
	const int _nb_Place_OperatingRoom=7;
	const int _nb_Place_ArrivalUrgence=8;
	const int _nb_Place_USurgery=9;
	const int _nb_Place_TraumaTeam=10;
	const int _nb_Place_Ustab=11;
	const int _nb_Place_WSurgery=12;
	const int _nb_Place_WBloodEx=13;
	const int _nb_Place_WXRayEx=14;
	const int _nb_Place_CountDoctor=15;
	const int _nb_Place_MonitoredRoom=16;
	const int _nb_Place_Doctor=17;
	const int _nb_Place_PatientRecovered=18;
	const int _nb_Place_UBloodEx=19;
	const int _nb_Place_ResB=20;
	const int _nb_Place_Waiting=21;
	const int _nb_Place_ResX=22;
	const int _nb_Place_UXRayEx=23;
	const int _nb_Place_FXRay=24;
	const int _nb_Place_FBloodEx=25;
void SPN::print_state(const vector<int> &vect){}
void SPN::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool SPN::precondition(const abstractMarking &M){return true;}
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"
patient_Domain operator + (const patient_Token& t1 ,const patient_Token& t2 ){
	patient_Domain d; d += t1; d+=t2 ;
	return d;
}
std::ostream& operator << (std::ostream& out, const patient_Domain& x) {
	stringstream outprintloot;
	for(size_t c0 = 0 ; c0< Color_patient_Total; c0++ )
		if(x.mult[c0])
					outprintloot << x.mult[c0]<< "<" << Color_patient_names[c0]<< ">,";
	out << "(" << outprintloot.str() << ")";
	return out;
}
inline bool contains(const patient_Domain& d1, const patient_Domain& d2){	return (d1-d2) > -1;
}
inline bool contains(const patient_Domain& d1, const patient_Token& tok){	return d1 >= tok;
}

void abstractMarking::resetToInitMarking(){
	P->_PL_ReadyT =0;
	P->_PL_Healthy =((patient_Domain(Color_patient_All) * (1 )));
	P->_PL_Ill =0;
	P->_PL_Arrival =0;
	P->_PL_ThreatedByDocH =0;
	P->_PL_ThreatedByDocL =0;
	P->_PL_WaitingRoom =0;
	P->_PL_OperatingRoom =2;
	P->_PL_ArrivalUrgence =0;
	P->_PL_USurgery =0;
	P->_PL_TraumaTeam =2;
	P->_PL_Ustab =0;
	P->_PL_WSurgery =0;
	P->_PL_WBloodEx =0;
	P->_PL_WXRayEx =0;
	P->_PL_CountDoctor =0;
	P->_PL_MonitoredRoom =0;
	P->_PL_Doctor =4;
	P->_PL_PatientRecovered =0;
	P->_PL_UBloodEx =0;
	P->_PL_ResB =2;
	P->_PL_Waiting =0;
	P->_PL_ResX =2;
	P->_PL_UXRayEx =0;
	P->_PL_FXRay =0;
	P->_PL_FBloodEx =0;
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

void abstractMarking::printSedCmd(ostream &s)const{
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
	if(P->x.mult >= 0){
		if (! P->x.islast()){	P->x.iter(); return true; };
		P->x = patient_Token();
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
	 return P->x.c0 + Color_patient_Total *(0);
}
const char *Color_patient_names[Color_patient_Total] = {
"p1","p2","p3","p4","p5","p6","p7","p8","p9","p10","p11","p12","p13","p14","p15","p16","p17","p18","p19","p20",
};
SPN::SPN():
pl(26), tr(21), Transition(21),Place(26),ParamDistr(3), TransitionConditions(21,0){
    Path ="Hospital.grml";
	PossiblyEnabled = vector< vector<int> >(21);
	PossiblyEnabled[0].push_back( 10 );
	PossiblyEnabled[0].push_back( 11 );
	PossiblyEnabled[1].push_back( 2 );
	{
		int PE[]= {5, 6, 8};
		PossiblyEnabled[2] = vector<int>(PE,PE+3);
	}
	{
		int PE[]= {10, 11, 12, 18};
		PossiblyEnabled[3] = vector<int>(PE,PE+4);
	}
	{
		int PE[]= {9, 10, 11, 12, 15};
		PossiblyEnabled[4] = vector<int>(PE,PE+5);
	}
	PossiblyEnabled[5].push_back( 13 );
	{
		int PE[]= {0, 16, 17};
		PossiblyEnabled[6] = vector<int>(PE,PE+3);
	}
	{
		int PE[]= {1, 10, 11, 12};
		PossiblyEnabled[7] = vector<int>(PE,PE+4);
	}
	PossiblyEnabled[8].push_back( 12 );
	PossiblyEnabled[9].push_back( 4 );
	PossiblyEnabled[10].push_back( 9 );
	PossiblyEnabled[10].push_back( 12 );
	PossiblyEnabled[11].push_back( 3 );
	PossiblyEnabled[11].push_back( 12 );
	PossiblyEnabled[12].push_back( 7 );
	PossiblyEnabled[13].push_back( 14 );
	{
		int PE[]= {0, 13, 16, 17};
		PossiblyEnabled[14] = vector<int>(PE,PE+4);
	}
	PossiblyEnabled[15].push_back( 1 );
	PossiblyEnabled[16].push_back( 19 );
	PossiblyEnabled[17].push_back( 20 );
	PossiblyEnabled[18].push_back( 1 );
	PossiblyEnabled[19].push_back( 0 );
	PossiblyEnabled[19].push_back( 16 );
	PossiblyEnabled[20].push_back( 0 );
	PossiblyEnabled[20].push_back( 17 );

	PossiblyDisabled = vector< vector<int> >(21);
	PossiblyDisabled[0].push_back( 12 );
	PossiblyDisabled[5].push_back( 6 );
	PossiblyDisabled[5].push_back( 8 );
	PossiblyDisabled[6].push_back( 5 );
	PossiblyDisabled[6].push_back( 8 );
	PossiblyDisabled[8].push_back( 5 );
	PossiblyDisabled[8].push_back( 6 );
	PossiblyDisabled[10].push_back( 11 );
	PossiblyDisabled[10].push_back( 12 );
	PossiblyDisabled[11].push_back( 10 );
	PossiblyDisabled[11].push_back( 12 );
	PossiblyDisabled[12].push_back( 10 );
	PossiblyDisabled[12].push_back( 11 );

	FreeMarkDepT = vector< vector<int> >(21);

	Transition[0] = _trans(0,Timed,DETERMINISTIC,0,20);
	{abstractBinding bl = Transition[0].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[0].bindingList.size();
			Transition[0].bindingList.push_back( bl );
			Transition[0].bindingLinkTable[bl.idTotal()]= Transition[0].bindingList.size()-1; 
		}
	}}
	Transition[1] = _trans(1,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[1].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[1].bindingList.size();
			Transition[1].bindingList.push_back( bl );
			Transition[1].bindingLinkTable[bl.idTotal()]= Transition[1].bindingList.size()-1; 
		}
	}}
	Transition[2] = _trans(2,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[2].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[2].bindingList.size();
			Transition[2].bindingList.push_back( bl );
			Transition[2].bindingLinkTable[bl.idTotal()]= Transition[2].bindingList.size()-1; 
		}
	}}
	Transition[3] = _trans(3,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[3].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[3].bindingList.size();
			Transition[3].bindingList.push_back( bl );
			Transition[3].bindingLinkTable[bl.idTotal()]= Transition[3].bindingList.size()-1; 
		}
	}}
	Transition[4] = _trans(4,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[4].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[4].bindingList.size();
			Transition[4].bindingList.push_back( bl );
			Transition[4].bindingLinkTable[bl.idTotal()]= Transition[4].bindingList.size()-1; 
		}
	}}
	Transition[5] = _trans(5,Timed,DETERMINISTIC,0,20);
	{abstractBinding bl = Transition[5].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[5].bindingList.size();
			Transition[5].bindingList.push_back( bl );
			Transition[5].bindingLinkTable[bl.idTotal()]= Transition[5].bindingList.size()-1; 
		}
	}}
	Transition[6] = _trans(6,Timed,DETERMINISTIC,0,20);
	{abstractBinding bl = Transition[6].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[6].bindingList.size();
			Transition[6].bindingList.push_back( bl );
			Transition[6].bindingLinkTable[bl.idTotal()]= Transition[6].bindingList.size()-1; 
		}
	}}
	Transition[7] = _trans(7,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[7].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[7].bindingList.size();
			Transition[7].bindingList.push_back( bl );
			Transition[7].bindingLinkTable[bl.idTotal()]= Transition[7].bindingList.size()-1; 
		}
	}}
	Transition[8] = _trans(8,Timed,DETERMINISTIC,0,20);
	{abstractBinding bl = Transition[8].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[8].bindingList.size();
			Transition[8].bindingList.push_back( bl );
			Transition[8].bindingLinkTable[bl.idTotal()]= Transition[8].bindingList.size()-1; 
		}
	}}
	Transition[9] = _trans(9,Timed,DETERMINISTIC,0,20);
	{abstractBinding bl = Transition[9].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[9].bindingList.size();
			Transition[9].bindingList.push_back( bl );
			Transition[9].bindingLinkTable[bl.idTotal()]= Transition[9].bindingList.size()-1; 
		}
	}}
	Transition[10] = _trans(10,Timed,DETERMINISTIC,0,20);
	{abstractBinding bl = Transition[10].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[10].bindingList.size();
			Transition[10].bindingList.push_back( bl );
			Transition[10].bindingLinkTable[bl.idTotal()]= Transition[10].bindingList.size()-1; 
		}
	}}
	Transition[11] = _trans(11,Timed,DETERMINISTIC,0,20);
	{abstractBinding bl = Transition[11].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[11].bindingList.size();
			Transition[11].bindingList.push_back( bl );
			Transition[11].bindingLinkTable[bl.idTotal()]= Transition[11].bindingList.size()-1; 
		}
	}}
	Transition[12] = _trans(12,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[12].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[12].bindingList.size();
			Transition[12].bindingList.push_back( bl );
			Transition[12].bindingLinkTable[bl.idTotal()]= Transition[12].bindingList.size()-1; 
		}
	}}
	Transition[13] = _trans(13,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[13].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[13].bindingList.size();
			Transition[13].bindingList.push_back( bl );
			Transition[13].bindingLinkTable[bl.idTotal()]= Transition[13].bindingList.size()-1; 
		}
	}}
	Transition[14] = _trans(14,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[14].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[14].bindingList.size();
			Transition[14].bindingList.push_back( bl );
			Transition[14].bindingLinkTable[bl.idTotal()]= Transition[14].bindingList.size()-1; 
		}
	}}
	Transition[15] = _trans(15,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[15].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[15].bindingList.size();
			Transition[15].bindingList.push_back( bl );
			Transition[15].bindingLinkTable[bl.idTotal()]= Transition[15].bindingList.size()-1; 
		}
	}}
	Transition[16] = _trans(16,Timed,DETERMINISTIC,0,20);
	{abstractBinding bl = Transition[16].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[16].bindingList.size();
			Transition[16].bindingList.push_back( bl );
			Transition[16].bindingLinkTable[bl.idTotal()]= Transition[16].bindingList.size()-1; 
		}
	}}
	Transition[17] = _trans(17,Timed,DETERMINISTIC,0,20);
	{abstractBinding bl = Transition[17].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[17].bindingList.size();
			Transition[17].bindingList.push_back( bl );
			Transition[17].bindingLinkTable[bl.idTotal()]= Transition[17].bindingList.size()-1; 
		}
	}}
	Transition[18] = _trans(18,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[18].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[18].bindingList.size();
			Transition[18].bindingList.push_back( bl );
			Transition[18].bindingLinkTable[bl.idTotal()]= Transition[18].bindingList.size()-1; 
		}
	}}
	Transition[19] = _trans(19,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[19].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[19].bindingList.size();
			Transition[19].bindingList.push_back( bl );
			Transition[19].bindingLinkTable[bl.idTotal()]= Transition[19].bindingList.size()-1; 
		}
	}}
	Transition[20] = _trans(20,Timed,EXPONENTIAL,0,20);
	{abstractBinding bl = Transition[20].bindingList[0];
	while(bl.next()){
		{
			bl.idcount = Transition[20].bindingList.size();
			Transition[20].bindingList.push_back( bl );
			Transition[20].bindingLinkTable[bl.idTotal()]= Transition[20].bindingList.size()-1; 
		}
	}}
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 13:	//BToStabilize
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_ArrivalUrgence , ((patient_Token(b.P->x) * (1 )))))) return false;
    if (!(contains(Marking.P->_PL_TraumaTeam , 1))) return false;
    return true;

		break;
	case 1:	//FallIll
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Healthy , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 2:	//HospitalArrival
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Ill , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 0:	//EXRayBlood
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_MonitoredRoom , ((patient_Token(b.P->x) * (1 )))))) return false;
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_FXRay , ((patient_Token(b.P->x) * (1 )))))) return false;
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_FBloodEx , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 15:	//DischargeRec
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_PatientRecovered , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 10:	//ToSurgery
	case 11:	//ToDoctor
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_ReadyT , ((patient_Token(b.P->x) * (1 )))))) return false;
    if (!(contains(Marking.P->_PL_CountDoctor , 1))) return false;
    if (!(contains(Marking.P->_PL_Doctor , 1))) return false;
    return true;

		break;
	case 3:	//EToThreat
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_ThreatedByDocH , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 7:	//DischargeL
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_ThreatedByDocL , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 19:	//EBloodEx
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_UBloodEx , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 4:	//EToSurgery
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_USurgery , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 20:	//EXRay
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_UXRayEx , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 14:	//EToStabilize
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Ustab , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 16:	//BBlood
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_WBloodEx , ((patient_Token(b.P->x) * (1 )))))) return false;
    if (!(contains(Marking.P->_PL_ResB , 1))) return false;
    return true;

		break;
	case 17:	//BXRay
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_WXRayEx , ((patient_Token(b.P->x) * (1 )))))) return false;
    if (!(contains(Marking.P->_PL_ResX , 1))) return false;
    return true;

		break;
	case 18:	//DischargeM
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Waiting , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	case 12:	//ToDoctorL
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_WaitingRoom , ((patient_Token(b.P->x) * (1 )))))) return false;
    if (Marking.P->_PL_CountDoctor >= 1) return false;
    if (!(contains(Marking.P->_PL_Doctor , 1))) return false;
    return true;

		break;
	case 9:	//BSurgery
    if (!(contains(Marking.P->_PL_OperatingRoom , 1))) return false;
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_WSurgery , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

		break;
	default:	//HighPrio,MediumPrio,LowPrio,
    if ( !(((patient_Token(b.P->x) * (1 ))) < 1)) 
        if (!(contains(Marking.P->_PL_Arrival , ((patient_Token(b.P->x) * (1 )))))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b, double time){
	lastTransition = t;
	switch(t){
		case 0: {  //EXRayBlood
			patient_Domain tmpMark_ReadyT = Marking.P->_PL_ReadyT;
			patient_Domain tmpMark_MonitoredRoom = Marking.P->_PL_MonitoredRoom;
			patient_Domain tmpMark_FXRay = Marking.P->_PL_FXRay;
			patient_Domain tmpMark_FBloodEx = Marking.P->_PL_FBloodEx;
			Marking.P->_PL_ReadyT += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_CountDoctor += 1;
			Marking.P->_PL_MonitoredRoom -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_FXRay -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_FBloodEx -= ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 1: {  //FallIll
			patient_Domain tmpMark_Healthy = Marking.P->_PL_Healthy;
			patient_Domain tmpMark_Ill = Marking.P->_PL_Ill;
			Marking.P->_PL_Healthy -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_Ill += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 2: {  //HospitalArrival
			patient_Domain tmpMark_Ill = Marking.P->_PL_Ill;
			patient_Domain tmpMark_Arrival = Marking.P->_PL_Arrival;
			Marking.P->_PL_Ill -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_Arrival += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 3: {  //EToThreat
			patient_Domain tmpMark_ThreatedByDocH = Marking.P->_PL_ThreatedByDocH;
			patient_Domain tmpMark_Waiting = Marking.P->_PL_Waiting;
			Marking.P->_PL_ThreatedByDocH -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_Doctor += 1;
			Marking.P->_PL_Waiting += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 4: {  //EToSurgery
			patient_Domain tmpMark_USurgery = Marking.P->_PL_USurgery;
			patient_Domain tmpMark_PatientRecovered = Marking.P->_PL_PatientRecovered;
			Marking.P->_PL_OperatingRoom += 1;
			Marking.P->_PL_USurgery -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_Doctor += 1;
			Marking.P->_PL_PatientRecovered += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 5: {  //HighPrio
			patient_Domain tmpMark_Arrival = Marking.P->_PL_Arrival;
			patient_Domain tmpMark_ArrivalUrgence = Marking.P->_PL_ArrivalUrgence;
			Marking.P->_PL_Arrival -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_ArrivalUrgence += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 6: {  //MediumPrio
			patient_Domain tmpMark_Arrival = Marking.P->_PL_Arrival;
			patient_Domain tmpMark_WBloodEx = Marking.P->_PL_WBloodEx;
			patient_Domain tmpMark_WXRayEx = Marking.P->_PL_WXRayEx;
			patient_Domain tmpMark_MonitoredRoom = Marking.P->_PL_MonitoredRoom;
			Marking.P->_PL_Arrival -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_WBloodEx += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_WXRayEx += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_MonitoredRoom += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 7: {  //DischargeL
			patient_Domain tmpMark_Healthy = Marking.P->_PL_Healthy;
			patient_Domain tmpMark_ThreatedByDocL = Marking.P->_PL_ThreatedByDocL;
			Marking.P->_PL_Healthy += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_ThreatedByDocL -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_Doctor += 1;
       break;
     } 
		case 8: {  //LowPrio
			patient_Domain tmpMark_Arrival = Marking.P->_PL_Arrival;
			patient_Domain tmpMark_WaitingRoom = Marking.P->_PL_WaitingRoom;
			Marking.P->_PL_Arrival -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_WaitingRoom += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 9: {  //BSurgery
			patient_Domain tmpMark_USurgery = Marking.P->_PL_USurgery;
			patient_Domain tmpMark_WSurgery = Marking.P->_PL_WSurgery;
			Marking.P->_PL_OperatingRoom -= 1;
			Marking.P->_PL_USurgery += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_WSurgery -= ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 10: {  //ToSurgery
			patient_Domain tmpMark_ReadyT = Marking.P->_PL_ReadyT;
			patient_Domain tmpMark_WSurgery = Marking.P->_PL_WSurgery;
			Marking.P->_PL_ReadyT -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_WSurgery += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_CountDoctor -= 1;
			Marking.P->_PL_Doctor -= 1;
       break;
     } 
		case 11: {  //ToDoctor
			patient_Domain tmpMark_ReadyT = Marking.P->_PL_ReadyT;
			patient_Domain tmpMark_ThreatedByDocH = Marking.P->_PL_ThreatedByDocH;
			Marking.P->_PL_ReadyT -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_ThreatedByDocH += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_CountDoctor -= 1;
			Marking.P->_PL_Doctor -= 1;
       break;
     } 
		case 12: {  //ToDoctorL
			patient_Domain tmpMark_ThreatedByDocL = Marking.P->_PL_ThreatedByDocL;
			patient_Domain tmpMark_WaitingRoom = Marking.P->_PL_WaitingRoom;
			Marking.P->_PL_ThreatedByDocL += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_WaitingRoom -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_Doctor -= 1;
       break;
     } 
		case 13: {  //BToStabilize
			patient_Domain tmpMark_ArrivalUrgence = Marking.P->_PL_ArrivalUrgence;
			patient_Domain tmpMark_Ustab = Marking.P->_PL_Ustab;
			Marking.P->_PL_ArrivalUrgence -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_TraumaTeam -= 1;
			Marking.P->_PL_Ustab += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 14: {  //EToStabilize
			patient_Domain tmpMark_Ustab = Marking.P->_PL_Ustab;
			patient_Domain tmpMark_WBloodEx = Marking.P->_PL_WBloodEx;
			patient_Domain tmpMark_WXRayEx = Marking.P->_PL_WXRayEx;
			patient_Domain tmpMark_MonitoredRoom = Marking.P->_PL_MonitoredRoom;
			Marking.P->_PL_TraumaTeam += 1;
			Marking.P->_PL_Ustab -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_WBloodEx += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_WXRayEx += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_MonitoredRoom += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 15: {  //DischargeRec
			patient_Domain tmpMark_Healthy = Marking.P->_PL_Healthy;
			patient_Domain tmpMark_PatientRecovered = Marking.P->_PL_PatientRecovered;
			Marking.P->_PL_Healthy += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_PatientRecovered -= ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 16: {  //BBlood
			patient_Domain tmpMark_WBloodEx = Marking.P->_PL_WBloodEx;
			patient_Domain tmpMark_UBloodEx = Marking.P->_PL_UBloodEx;
			Marking.P->_PL_WBloodEx -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_UBloodEx += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_ResB -= 1;
       break;
     } 
		case 17: {  //BXRay
			patient_Domain tmpMark_WXRayEx = Marking.P->_PL_WXRayEx;
			patient_Domain tmpMark_UXRayEx = Marking.P->_PL_UXRayEx;
			Marking.P->_PL_WXRayEx -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_ResX -= 1;
			Marking.P->_PL_UXRayEx += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 18: {  //DischargeM
			patient_Domain tmpMark_Healthy = Marking.P->_PL_Healthy;
			patient_Domain tmpMark_Waiting = Marking.P->_PL_Waiting;
			Marking.P->_PL_Healthy += ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_Waiting -= ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 19: {  //EBloodEx
			patient_Domain tmpMark_UBloodEx = Marking.P->_PL_UBloodEx;
			patient_Domain tmpMark_FBloodEx = Marking.P->_PL_FBloodEx;
			Marking.P->_PL_UBloodEx -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_ResB += 1;
			Marking.P->_PL_FBloodEx += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
		case 20: {  //EXRay
			patient_Domain tmpMark_UXRayEx = Marking.P->_PL_UXRayEx;
			patient_Domain tmpMark_FXRay = Marking.P->_PL_FXRay;
			Marking.P->_PL_ResX += 1;
			Marking.P->_PL_UXRayEx -= ((patient_Token(b.P->x) * (1 )));
			Marking.P->_PL_FXRay += ((patient_Token(b.P->x) * (1 )));
       break;
     } 
	}
}
void SPN::unfire(size_t t ,const abstractBinding& b){
}

const vector<int>& SPN::PossiblyEn()const {
	return PossiblyEnabled[lastTransition];
}
const vector<int>& SPN::PossiblyDis()const {
	return PossiblyDisabled[lastTransition];
}
const vector<int>& SPN::FreeMarkingDependant()const {
	return FreeMarkDepT[lastTransition];
}
abstractBinding* SPN::nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum){
	switch(lastTransition*(tr+1) + targettr){
		//Partial synch over variable: EXRayBlood->ToSurgery var Not set
		//Partial synch over variable: EXRayBlood->ToDoctor var Not set
		//Partial synch over variable: FallIll->HospitalArrival var Not set
		//Partial synch over variable: HospitalArrival->HighPrio var Not set
		//Partial synch over variable: HospitalArrival->MediumPrio var Not set
		//Partial synch over variable: HospitalArrival->LowPrio var Not set
		//Partial synch over variable: EToThreat->DischargeM var Not set
		//Partial synch over variable: EToSurgery->DischargeRec var Not set
		//Partial synch over variable: HighPrio->BToStabilize var Not set
		//Partial synch over variable: MediumPrio->EXRayBlood var Not set
		//Partial synch over variable: MediumPrio->BBlood var Not set
		//Partial synch over variable: MediumPrio->BXRay var Not set
		//Partial synch over variable: DischargeL->FallIll var Not set
		//Partial synch over variable: LowPrio->ToDoctorL var Not set
		//Partial synch over variable: BSurgery->EToSurgery var Not set
		//Partial synch over variable: ToSurgery->BSurgery var Not set
		//Partial synch over variable: ToDoctor->EToThreat var Not set
		//Partial synch over variable: ToDoctorL->DischargeL var Not set
		//Partial synch over variable: BToStabilize->EToStabilize var Not set
		//Partial synch over variable: EToStabilize->EXRayBlood var Not set
		//Partial synch over variable: EToStabilize->BBlood var Not set
		//Partial synch over variable: EToStabilize->BXRay var Not set
		//Partial synch over variable: DischargeRec->FallIll var Not set
		//Partial synch over variable: BBlood->EBloodEx var Not set
		//Partial synch over variable: BXRay->EXRay var Not set
		//Partial synch over variable: DischargeM->FallIll var Not set
		//Partial synch over variable: EBloodEx->EXRayBlood var Not set
		//Partial synch over variable: EXRay->EXRayBlood var Not set
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum){
	switch(lastTransition*(tr+1) + targettr){
		//Partial synch over variable: EXRayBlood->EXRayBlood var Not set
		//Partial synch over variable: FallIll->FallIll var Not set
		//Partial synch over variable: HospitalArrival->HospitalArrival var Not set
		//Partial synch over variable: EToThreat->EToThreat var Not set
		//Partial synch over variable: EToSurgery->EToSurgery var Not set
		//Partial synch over variable: HighPrio->HighPrio var Not set
		//Partial synch over variable: HighPrio->MediumPrio var Not set
		//Partial synch over variable: HighPrio->LowPrio var Not set
		//Partial synch over variable: MediumPrio->HighPrio var Not set
		//Partial synch over variable: MediumPrio->MediumPrio var Not set
		//Partial synch over variable: MediumPrio->LowPrio var Not set
		//Partial synch over variable: DischargeL->DischargeL var Not set
		//Partial synch over variable: LowPrio->HighPrio var Not set
		//Partial synch over variable: LowPrio->MediumPrio var Not set
		//Partial synch over variable: LowPrio->LowPrio var Not set
		//Partial synch over variable: BSurgery->BSurgery var Not set
		//Partial synch over variable: ToSurgery->ToSurgery var Not set
		//Partial synch over variable: ToSurgery->ToDoctor var Not set
		//Partial synch over variable: ToDoctor->ToSurgery var Not set
		//Partial synch over variable: ToDoctor->ToDoctor var Not set
		//Partial synch over variable: ToDoctorL->ToDoctorL var Not set
		//Partial synch over variable: BToStabilize->BToStabilize var Not set
		//Partial synch over variable: EToStabilize->EToStabilize var Not set
		//Partial synch over variable: DischargeRec->DischargeRec var Not set
		//Partial synch over variable: BBlood->BBlood var Not set
		//Partial synch over variable: BXRay->BXRay var Not set
		//Partial synch over variable: DischargeM->DischargeM var Not set
		//Partial synch over variable: EBloodEx->EBloodEx var Not set
		//Partial synch over variable: EXRay->EXRay var Not set
	default:
		if(*bindingNum==Transition[targettr].bindingList.size())return NULL;
		*bindingNum = *bindingNum +1;
		return &(Transition[targettr].bindingList[*bindingNum-1]);
}}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(size_t t, const abstractBinding&)const {
switch (t){
	case 0:	//EXRayBlood
	case 5:	//HighPrio
	case 6:	//MediumPrio
	case 8:	//LowPrio
	case 9:	//BSurgery
	case 10:	//ToSurgery
	case 11:	//ToDoctor
	case 16:	//BBlood
	case 17:	//BXRay
	{
		ParamDistr[0]= ( double ) 0 ;
	}

		break;
	case 1:	//FallIll
	{
		ParamDistr[0]= ( double ) 0.1 ;
	}

		break;
	default:	//HospitalArrival,EToThreat,EToSurgery,DischargeL,ToDoctorL,BToStabilize,EToStabilize,DischargeRec,DischargeM,EBloodEx,EXRay,
	{
		ParamDistr[0]= ( double ) 1 ;
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

