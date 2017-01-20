#include "spn.hpp"
#include <iomanip>
using namespace std;
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
namespace hybridVar {
}
void REHandling::print_state(const vector<int> &vect){}
void REHandling::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool REHandling::precondition(const abstractMarking &M){return true;}
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
	P->_PL_ReadyT =0  ;
	P->_PL_Healthy =((patient_Domain(Color_patient_All))) ;
	P->_PL_Ill =0  ;
	P->_PL_Arrival =0  ;
	P->_PL_ThreatedByDocH =0  ;
	P->_PL_ThreatedByDocL =0  ;
	P->_PL_WaitingRoom =0  ;
	P->_PL_OperatingRoom =2  ;
	P->_PL_ArrivalUrgence =0  ;
	P->_PL_USurgery =0  ;
	P->_PL_TraumaTeam =2  ;
	P->_PL_Ustab =0  ;
	P->_PL_WSurgery =0  ;
	P->_PL_WBloodEx =0  ;
	P->_PL_WXRayEx =0  ;
	P->_PL_CountDoctor =0  ;
	P->_PL_MonitoredRoom =0  ;
	P->_PL_Doctor =4  ;
	P->_PL_PatientRecovered =0  ;
	P->_PL_UBloodEx =0  ;
	P->_PL_ResB =2  ;
	P->_PL_Waiting =0  ;
	P->_PL_ResX =2  ;
	P->_PL_UXRayEx =0  ;
	P->_PL_FXRay =0  ;
	P->_PL_FBloodEx =0  ;
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

void abstractMarking::print(ostream &s,double eTime)const{
}
void abstractMarking::printSedCmd(ostream &s)const{
}

int abstractMarking::getNbOfTokens(int p)const {
	exit(EXIT_FAILURE);
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(406);
	v.reserve(407);
	size_t i = 0;
	i= P->_PL_ReadyT.copyVector(v,i);
	i= P->_PL_Healthy.copyVector(v,i);
	i= P->_PL_Ill.copyVector(v,i);
	i= P->_PL_Arrival.copyVector(v,i);
	i= P->_PL_ThreatedByDocH.copyVector(v,i);
	i= P->_PL_ThreatedByDocL.copyVector(v,i);
	i= P->_PL_WaitingRoom.copyVector(v,i);
	v[i++]= P->_PL_OperatingRoom;
	i= P->_PL_ArrivalUrgence.copyVector(v,i);
	i= P->_PL_USurgery.copyVector(v,i);
	v[i++]= P->_PL_TraumaTeam;
	i= P->_PL_Ustab.copyVector(v,i);
	i= P->_PL_WSurgery.copyVector(v,i);
	i= P->_PL_WBloodEx.copyVector(v,i);
	i= P->_PL_WXRayEx.copyVector(v,i);
	v[i++]= P->_PL_CountDoctor;
	i= P->_PL_MonitoredRoom.copyVector(v,i);
	v[i++]= P->_PL_Doctor;
	i= P->_PL_PatientRecovered.copyVector(v,i);
	i= P->_PL_UBloodEx.copyVector(v,i);
	v[i++]= P->_PL_ResB;
	i= P->_PL_Waiting.copyVector(v,i);
	v[i++]= P->_PL_ResX;
	i= P->_PL_UXRayEx.copyVector(v,i);
	i= P->_PL_FXRay.copyVector(v,i);
	i= P->_PL_FBloodEx.copyVector(v,i);
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	size_t i = 0;
	i= P->_PL_ReadyT.setVector(v,i);
	i= P->_PL_Healthy.setVector(v,i);
	i= P->_PL_Ill.setVector(v,i);
	i= P->_PL_Arrival.setVector(v,i);
	i= P->_PL_ThreatedByDocH.setVector(v,i);
	i= P->_PL_ThreatedByDocL.setVector(v,i);
	i= P->_PL_WaitingRoom.setVector(v,i);
	P->_PL_OperatingRoom = v[i++];
	i= P->_PL_ArrivalUrgence.setVector(v,i);
	i= P->_PL_USurgery.setVector(v,i);
	P->_PL_TraumaTeam = v[i++];
	i= P->_PL_Ustab.setVector(v,i);
	i= P->_PL_WSurgery.setVector(v,i);
	i= P->_PL_WBloodEx.setVector(v,i);
	i= P->_PL_WXRayEx.setVector(v,i);
	P->_PL_CountDoctor = v[i++];
	i= P->_PL_MonitoredRoom.setVector(v,i);
	P->_PL_Doctor = v[i++];
	i= P->_PL_PatientRecovered.setVector(v,i);
	i= P->_PL_UBloodEx.setVector(v,i);
	P->_PL_ResB = v[i++];
	i= P->_PL_Waiting.setVector(v,i);
	P->_PL_ResX = v[i++];
	i= P->_PL_UXRayEx.setVector(v,i);
	i= P->_PL_FXRay.setVector(v,i);
	i= P->_PL_FBloodEx.setVector(v,i);
};

void abstractMarking::Symmetrize(){
}bool abstractBinding::next() {
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
	std::cerr << "\tx: ";P->x.print(std::cerr);
}
int abstractBinding::id()const{
	return idcount;
}
int abstractBinding::idTotal()const{
	 return P->x.c0 + Color_patient_Total *(0);
}

void abstractBindingIteratorImpl::reset(abstractMarkingImpl& m) { };
bool abstractBindingIteratorImpl::next(size_t& t, abstractMarkingImpl& m) { return false; };
size_t abstractBindingIteratorImpl::getIndex() { return 0; };
abstractBinding abstractBindingIteratorImpl::getBinding() {
	abstractBinding newBind;
	return newBind;
};
void abstractBindingIterator::reset(abstractMarking& m) {
	P->reset(*(m.P));
};
abstractBindingIterator::abstractBindingIterator(abstractMarking& m) {
	P = new abstractBindingIteratorImpl;
	reset(m);
};
bool abstractBindingIterator::next(size_t& t,abstractMarking& m) {
	return P->next(t,*(m.P));
};
abstractBindingIterator::~abstractBindingIterator() {
	delete(P);
};
size_t abstractBindingIterator::getIndex() {
	return P->getIndex();
};
abstractBinding abstractBindingIterator::getBinding() {
	return P->getBinding();
};
const char *Color_patient_names[Color_patient_Total] = {
"p1","p2","p3","p4","p5","p6","p7","p8","p9","p10","p11","p12","p13","p14","p15","p16","p17","p18","p19","p20",
};
static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_0[4]= {TR_ToPhase2_RT, TR_Route1_RT, TR_Route2_RT, -1 }; /* Arrive*/
static const int PE_PossiblyEnabled_1[3]= {TR_Route1_RT, TR_Route2_RT, -1 }; /* ToPhase2*/
static const int PE_PossiblyEnabled_2[4]= {TR_Arrive_RT, TR_ToPhase2_RT, TR_Leave_RT, -1 }; /* Route1*/
static const int PE_PossiblyEnabled_3[5]= {TR_Arrive_RT, TR_ToPhase2_RT, TR_Route1_RT, TR_Leave_RT, -1 }; /* Route2*/
static const int PE_PossiblyEnabled_4[3]= {TR_Route1_RT, TR_Route2_RT, -1 }; /* Leave*/
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, PE_PossiblyEnabled_2, PE_PossiblyEnabled_3, PE_PossiblyEnabled_4};

static const int PE_PossiblyDisabled_0[2]= {TR_ToDoctorL_RT, -1 }; /* EXRayBlood*/
static const int PE_PossiblyDisabled_5[3]= {TR_MediumPrio_RT, TR_LowPrio_RT, -1 }; /* HighPrio*/
static const int PE_PossiblyDisabled_6[3]= {TR_HighPrio_RT, TR_LowPrio_RT, -1 }; /* MediumPrio*/
static const int PE_PossiblyDisabled_8[3]= {TR_HighPrio_RT, TR_MediumPrio_RT, -1 }; /* LowPrio*/
static const int PE_PossiblyDisabled_10[3]= {TR_ToDoctor_RT, TR_ToDoctorL_RT, -1 }; /* ToSurgery*/
static const int PE_PossiblyDisabled_11[3]= {TR_ToSurgery_RT, TR_ToDoctorL_RT, -1 }; /* ToDoctor*/
static const int PE_PossiblyDisabled_12[3]= {TR_ToSurgery_RT, TR_ToDoctor_RT, -1 }; /* ToDoctorL*/
const int* SPN::PossiblyDisabled[] = {PE_PossiblyDisabled_0, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, PE_PossiblyDisabled_5, PE_PossiblyDisabled_6, EMPTY_array, PE_PossiblyDisabled_8, EMPTY_array, PE_PossiblyDisabled_10, PE_PossiblyDisabled_11, PE_PossiblyDisabled_12, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

const int* SPN::FreeMarkDepT[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

static spn_trans TransArray[21] = { _trans(0,DETERMINISTIC,0,20, 0), _trans(1,EXPONENTIAL,0,20, 0), _trans(2,EXPONENTIAL,0,20, 0), _trans(3,EXPONENTIAL,0,20, 0), _trans(4,EXPONENTIAL,0,20, 0), _trans(5,DETERMINISTIC,0,20, 0), _trans(6,DETERMINISTIC,0,20, 0), _trans(7,EXPONENTIAL,0,20, 0), _trans(8,DETERMINISTIC,0,20, 0), _trans(9,DETERMINISTIC,0,20, 0), _trans(10,DETERMINISTIC,0,20, 0), _trans(11,DETERMINISTIC,0,20, 0), _trans(12,EXPONENTIAL,0,20, 0), _trans(13,EXPONENTIAL,0,20, 0), _trans(14,EXPONENTIAL,0,20, 0), _trans(15,EXPONENTIAL,0,20, 0), _trans(16,DETERMINISTIC,0,20, 0), _trans(17,DETERMINISTIC,0,20, 0), _trans(18,EXPONENTIAL,0,20, 0), _trans(19,EXPONENTIAL,0,20, 0), _trans(20,EXPONENTIAL,0,20, 0),  }; 
SPN::SPN():
customDistr(*(new CustomDistr())),pl(6), tr(5) ,Transition(TransArray,TransArray +5),Place(6),ParamDistr(),TransitionConditions(5,0){
    Path ="tqn.gspn";
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{

	switch (t){
		case 13:	//BToStabilize

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_ArrivalUrgence , ((patient_Token(b.P->x)))))) return false;
			if (!(contains(Marking.P->_PL_TraumaTeam , 1))) return false;
		return true;
		break;
		case 1:	//FallIll

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_Healthy , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 2:	//HospitalArrival

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_Ill , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 0:	//EXRayBlood

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_MonitoredRoom , ((patient_Token(b.P->x)))))) return false;
			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_FXRay , ((patient_Token(b.P->x)))))) return false;
			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_FBloodEx , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 15:	//DischargeRec

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_PatientRecovered , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 10:	//ToSurgery
		case 11:	//ToDoctor

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_ReadyT , ((patient_Token(b.P->x)))))) return false;
			if (!(contains(Marking.P->_PL_CountDoctor , 1))) return false;
			if (!(contains(Marking.P->_PL_Doctor , 1))) return false;
		return true;
		break;
		case 3:	//EToThreat

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_ThreatedByDocH , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 7:	//DischargeL

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_ThreatedByDocL , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 19:	//EBloodEx

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_UBloodEx , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 4:	//EToSurgery

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_USurgery , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 20:	//EXRay

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_UXRayEx , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 14:	//EToStabilize

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_Ustab , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 16:	//BBlood

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_WBloodEx , ((patient_Token(b.P->x)))))) return false;
			if (!(contains(Marking.P->_PL_ResB , 1))) return false;
		return true;
		break;
		case 17:	//BXRay

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_WXRayEx , ((patient_Token(b.P->x)))))) return false;
			if (!(contains(Marking.P->_PL_ResX , 1))) return false;
		return true;
		break;
		case 18:	//DischargeM

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_Waiting , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		case 12:	//ToDoctorL

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_WaitingRoom , ((patient_Token(b.P->x)))))) return false;
    if (Marking.P->_PL_CountDoctor >= 1) return false;
			if (!(contains(Marking.P->_PL_Doctor , 1))) return false;
		return true;
		break;
		case 9:	//BSurgery

			if (!(contains(Marking.P->_PL_OperatingRoom , 1))) return false;
			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_WSurgery , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
		default:	//HighPrio,MediumPrio,LowPrio,

			if ( !(((patient_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_Arrival , ((patient_Token(b.P->x)))))) return false;
		return true;
		break;
	}
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;

	switch (t){
		case 4:	//EToSurgery
{
			int tmpMark_OperatingRoom = Marking.P->_PL_OperatingRoom;
			patient_Domain tmpMark_USurgery = Marking.P->_PL_USurgery;
			int tmpMark_Doctor = Marking.P->_PL_Doctor;
			patient_Domain tmpMark_PatientRecovered = Marking.P->_PL_PatientRecovered;
			Marking.P->_PL_OperatingRoom += 1;
			Marking.P->_PL_USurgery -= ((patient_Token(b.P->x)));
			Marking.P->_PL_Doctor += 1;
			Marking.P->_PL_PatientRecovered += ((patient_Token(b.P->x)));
	}
		break;
		case 9:	//BSurgery
{
			int tmpMark_OperatingRoom = Marking.P->_PL_OperatingRoom;
			patient_Domain tmpMark_USurgery = Marking.P->_PL_USurgery;
			patient_Domain tmpMark_WSurgery = Marking.P->_PL_WSurgery;
			Marking.P->_PL_OperatingRoom -= 1;
			Marking.P->_PL_USurgery += ((patient_Token(b.P->x)));
			Marking.P->_PL_WSurgery -= ((patient_Token(b.P->x)));
	}
		break;
		case 20:	//EXRay
{
			int tmpMark_ResX = Marking.P->_PL_ResX;
			patient_Domain tmpMark_UXRayEx = Marking.P->_PL_UXRayEx;
			patient_Domain tmpMark_FXRay = Marking.P->_PL_FXRay;
			Marking.P->_PL_ResX += 1;
			Marking.P->_PL_UXRayEx -= ((patient_Token(b.P->x)));
			Marking.P->_PL_FXRay += ((patient_Token(b.P->x)));
	}
		break;
		case 14:	//EToStabilize
{
			int tmpMark_TraumaTeam = Marking.P->_PL_TraumaTeam;
			patient_Domain tmpMark_Ustab = Marking.P->_PL_Ustab;
			patient_Domain tmpMark_WBloodEx = Marking.P->_PL_WBloodEx;
			patient_Domain tmpMark_WXRayEx = Marking.P->_PL_WXRayEx;
			patient_Domain tmpMark_MonitoredRoom = Marking.P->_PL_MonitoredRoom;
			Marking.P->_PL_TraumaTeam += 1;
			Marking.P->_PL_Ustab -= ((patient_Token(b.P->x)));
			Marking.P->_PL_WBloodEx += ((patient_Token(b.P->x)));
			Marking.P->_PL_WXRayEx += ((patient_Token(b.P->x)));
			Marking.P->_PL_MonitoredRoom += ((patient_Token(b.P->x)));
	}
		break;
		case 5:	//HighPrio
{
			patient_Domain tmpMark_Arrival = Marking.P->_PL_Arrival;
			patient_Domain tmpMark_ArrivalUrgence = Marking.P->_PL_ArrivalUrgence;
			Marking.P->_PL_Arrival -= ((patient_Token(b.P->x)));
			Marking.P->_PL_ArrivalUrgence += ((patient_Token(b.P->x)));
	}
		break;
		case 6:	//MediumPrio
{
			patient_Domain tmpMark_Arrival = Marking.P->_PL_Arrival;
			patient_Domain tmpMark_WBloodEx = Marking.P->_PL_WBloodEx;
			patient_Domain tmpMark_WXRayEx = Marking.P->_PL_WXRayEx;
			patient_Domain tmpMark_MonitoredRoom = Marking.P->_PL_MonitoredRoom;
			Marking.P->_PL_Arrival -= ((patient_Token(b.P->x)));
			Marking.P->_PL_WBloodEx += ((patient_Token(b.P->x)));
			Marking.P->_PL_WXRayEx += ((patient_Token(b.P->x)));
			Marking.P->_PL_MonitoredRoom += ((patient_Token(b.P->x)));
	}
		break;
		case 8:	//LowPrio
{
			patient_Domain tmpMark_Arrival = Marking.P->_PL_Arrival;
			patient_Domain tmpMark_WaitingRoom = Marking.P->_PL_WaitingRoom;
			Marking.P->_PL_Arrival -= ((patient_Token(b.P->x)));
			Marking.P->_PL_WaitingRoom += ((patient_Token(b.P->x)));
	}
		break;
		case 13:	//BToStabilize
{
			patient_Domain tmpMark_ArrivalUrgence = Marking.P->_PL_ArrivalUrgence;
			int tmpMark_TraumaTeam = Marking.P->_PL_TraumaTeam;
			patient_Domain tmpMark_Ustab = Marking.P->_PL_Ustab;
			Marking.P->_PL_ArrivalUrgence -= ((patient_Token(b.P->x)));
			Marking.P->_PL_TraumaTeam -= 1;
			Marking.P->_PL_Ustab += ((patient_Token(b.P->x)));
	}
		break;
		case 1:	//FallIll
{
			patient_Domain tmpMark_Healthy = Marking.P->_PL_Healthy;
			patient_Domain tmpMark_Ill = Marking.P->_PL_Ill;
			Marking.P->_PL_Healthy -= ((patient_Token(b.P->x)));
			Marking.P->_PL_Ill += ((patient_Token(b.P->x)));
	}
		break;
		case 15:	//DischargeRec
{
			patient_Domain tmpMark_Healthy = Marking.P->_PL_Healthy;
			patient_Domain tmpMark_PatientRecovered = Marking.P->_PL_PatientRecovered;
			Marking.P->_PL_Healthy += ((patient_Token(b.P->x)));
			Marking.P->_PL_PatientRecovered -= ((patient_Token(b.P->x)));
	}
		break;
		case 7:	//DischargeL
{
			patient_Domain tmpMark_Healthy = Marking.P->_PL_Healthy;
			patient_Domain tmpMark_ThreatedByDocL = Marking.P->_PL_ThreatedByDocL;
			int tmpMark_Doctor = Marking.P->_PL_Doctor;
			Marking.P->_PL_Healthy += ((patient_Token(b.P->x)));
			Marking.P->_PL_ThreatedByDocL -= ((patient_Token(b.P->x)));
			Marking.P->_PL_Doctor += 1;
	}
		break;
		case 18:	//DischargeM
{
			patient_Domain tmpMark_Healthy = Marking.P->_PL_Healthy;
			patient_Domain tmpMark_Waiting = Marking.P->_PL_Waiting;
			Marking.P->_PL_Healthy += ((patient_Token(b.P->x)));
			Marking.P->_PL_Waiting -= ((patient_Token(b.P->x)));
	}
		break;
		case 2:	//HospitalArrival
{
			patient_Domain tmpMark_Ill = Marking.P->_PL_Ill;
			patient_Domain tmpMark_Arrival = Marking.P->_PL_Arrival;
			Marking.P->_PL_Ill -= ((patient_Token(b.P->x)));
			Marking.P->_PL_Arrival += ((patient_Token(b.P->x)));
	}
		break;
		case 0:	//EXRayBlood
{
			patient_Domain tmpMark_ReadyT = Marking.P->_PL_ReadyT;
			int tmpMark_CountDoctor = Marking.P->_PL_CountDoctor;
			patient_Domain tmpMark_MonitoredRoom = Marking.P->_PL_MonitoredRoom;
			patient_Domain tmpMark_FXRay = Marking.P->_PL_FXRay;
			patient_Domain tmpMark_FBloodEx = Marking.P->_PL_FBloodEx;
			Marking.P->_PL_ReadyT += ((patient_Token(b.P->x)));
			Marking.P->_PL_CountDoctor += 1;
			Marking.P->_PL_MonitoredRoom -= ((patient_Token(b.P->x)));
			Marking.P->_PL_FXRay -= ((patient_Token(b.P->x)));
			Marking.P->_PL_FBloodEx -= ((patient_Token(b.P->x)));
	}
		break;
		case 11:	//ToDoctor
{
			patient_Domain tmpMark_ReadyT = Marking.P->_PL_ReadyT;
			patient_Domain tmpMark_ThreatedByDocH = Marking.P->_PL_ThreatedByDocH;
			int tmpMark_CountDoctor = Marking.P->_PL_CountDoctor;
			int tmpMark_Doctor = Marking.P->_PL_Doctor;
			Marking.P->_PL_ReadyT -= ((patient_Token(b.P->x)));
			Marking.P->_PL_ThreatedByDocH += ((patient_Token(b.P->x)));
			Marking.P->_PL_CountDoctor -= 1;
			Marking.P->_PL_Doctor -= 1;
	}
		break;
		case 10:	//ToSurgery
{
			patient_Domain tmpMark_ReadyT = Marking.P->_PL_ReadyT;
			patient_Domain tmpMark_WSurgery = Marking.P->_PL_WSurgery;
			int tmpMark_CountDoctor = Marking.P->_PL_CountDoctor;
			int tmpMark_Doctor = Marking.P->_PL_Doctor;
			Marking.P->_PL_ReadyT -= ((patient_Token(b.P->x)));
			Marking.P->_PL_WSurgery += ((patient_Token(b.P->x)));
			Marking.P->_PL_CountDoctor -= 1;
			Marking.P->_PL_Doctor -= 1;
	}
		break;
		case 3:	//EToThreat
{
			patient_Domain tmpMark_ThreatedByDocH = Marking.P->_PL_ThreatedByDocH;
			int tmpMark_Doctor = Marking.P->_PL_Doctor;
			patient_Domain tmpMark_Waiting = Marking.P->_PL_Waiting;
			Marking.P->_PL_ThreatedByDocH -= ((patient_Token(b.P->x)));
			Marking.P->_PL_Doctor += 1;
			Marking.P->_PL_Waiting += ((patient_Token(b.P->x)));
	}
		break;
		case 12:	//ToDoctorL
{
			patient_Domain tmpMark_ThreatedByDocL = Marking.P->_PL_ThreatedByDocL;
			patient_Domain tmpMark_WaitingRoom = Marking.P->_PL_WaitingRoom;
			int tmpMark_Doctor = Marking.P->_PL_Doctor;
			Marking.P->_PL_ThreatedByDocL += ((patient_Token(b.P->x)));
			Marking.P->_PL_WaitingRoom -= ((patient_Token(b.P->x)));
			Marking.P->_PL_Doctor -= 1;
	}
		break;
		case 19:	//EBloodEx
{
			patient_Domain tmpMark_UBloodEx = Marking.P->_PL_UBloodEx;
			int tmpMark_ResB = Marking.P->_PL_ResB;
			patient_Domain tmpMark_FBloodEx = Marking.P->_PL_FBloodEx;
			Marking.P->_PL_UBloodEx -= ((patient_Token(b.P->x)));
			Marking.P->_PL_ResB += 1;
			Marking.P->_PL_FBloodEx += ((patient_Token(b.P->x)));
	}
		break;
		case 16:	//BBlood
{
			patient_Domain tmpMark_WBloodEx = Marking.P->_PL_WBloodEx;
			patient_Domain tmpMark_UBloodEx = Marking.P->_PL_UBloodEx;
			int tmpMark_ResB = Marking.P->_PL_ResB;
			Marking.P->_PL_WBloodEx -= ((patient_Token(b.P->x)));
			Marking.P->_PL_UBloodEx += ((patient_Token(b.P->x)));
			Marking.P->_PL_ResB -= 1;
	}
		break;
		case 17:	//BXRay
{
			patient_Domain tmpMark_WXRayEx = Marking.P->_PL_WXRayEx;
			int tmpMark_ResX = Marking.P->_PL_ResX;
			patient_Domain tmpMark_UXRayEx = Marking.P->_PL_UXRayEx;
			Marking.P->_PL_WXRayEx -= ((patient_Token(b.P->x)));
			Marking.P->_PL_ResX -= 1;
			Marking.P->_PL_UXRayEx += ((patient_Token(b.P->x)));
	}
		break;
	}
}

void SPN::unfire(TR_PL_ID t, const abstractBinding &b){
}

const abstractBinding* SPN::nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
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
const abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
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
void SPN::GetDistParameters(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

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

		break;
	}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

		return (double)1 ;
}

REAL_TYPE SPN::GetWeight(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

		return (double)1 ;
}

void SPN::Msimple(){
	vector<int> tab;
	Msimpletab = tab;
}
void SPN::reset() {
	lastTransitionTime = 0;
	Marking.resetToInitMarking();
}

