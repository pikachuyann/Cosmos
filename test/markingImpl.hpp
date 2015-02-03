#ifndef _MarkingImpl_HPP
#define    _MarkingImpl_HPP
#include <string.h>

using namespace std;

enum patient_Color_Classe {
	Color_patient_p1,
	Color_patient_p2,
	Color_patient_p3,
	Color_patient_p4,
	Color_patient_p5,
	Color_patient_p6,
	Color_patient_p7,
	Color_patient_p8,
	Color_patient_p9,
	Color_patient_p10,
	Color_patient_p11,
	Color_patient_p12,
	Color_patient_p13,
	Color_patient_p14,
	Color_patient_p15,
	Color_patient_p16,
	Color_patient_p17,
	Color_patient_p18,
	Color_patient_p19,
	Color_patient_p20,
	Color_patient_Total,
	Color_patient_All
};
extern const char *Color_patient_names[];

struct patient_Token{
	patient_Color_Classe c0;
	int mult;
	patient_Token(  patient_Color_Classe cv0 = (patient_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	patient_Token( const patient_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	patient_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (patient_Color_Classe)(Color_patient_Total - 1) ){ c0 = (patient_Color_Classe)(c0+ 1); return;};
c0 = (patient_Color_Classe)(0);
	}
	void print(){
		std::cerr << mult << "<" << Color_patient_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (patient_Color_Classe)(Color_patient_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
};
struct patient_Domain {
	int mult[ Color_patient_Total ];
	patient_Domain(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}
	patient_Domain(patient_Color_Classe c0) {
		fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), 0 );
		if(c0 != Color_patient_All)
			mult[c0] = 1 ;
		else{
			for( int i0= ( c0 == Color_patient_All ? 0 : c0);i0< ( c0 == Color_patient_All ? Color_patient_Total : c0+1);i0++)
				mult[i0] = 1 ;
		}
	}
	patient_Domain& operator = (const patient_Domain& x){
		copy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);
		return *this;
	}
	bool operator == (const patient_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);
	}
	bool operator < (const patient_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());
	}
	bool operator > (const patient_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());
	}
	patient_Domain operator * (int v){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;
		return *this;
	}
	patient_Domain& operator += (const patient_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]+= ((int*)x.mult)[count] ;
		return *this;
	}
	patient_Domain& operator += (const patient_Token& x){
		mult[ x.c0 ] += x.mult;
		return *this;
	}
	patient_Domain operator + (const patient_Token& x){
		patient_Domain d(*this);
		d+=x;
 		return d;
}
	patient_Domain& operator -= (const patient_Token& x){
		mult[ x.c0 ] -= x.mult;
		return *this;
	}
	bool operator < (const patient_Token& x)const{
		return mult[ x.c0 ] < x.mult;
	}
	bool operator >= (const patient_Token& x)const{
		return mult[ x.c0 ] >= x.mult;
	}
	patient_Domain operator + (const patient_Domain& x)const{
		patient_Domain returnval = *this; returnval+= x;
		return returnval;
	}
	patient_Domain& operator -= (const patient_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]-= ((int*)x.mult)[count] ;
		return *this;
	}
	patient_Domain operator - (const patient_Domain& x)const{
		patient_Domain returnval = *this; returnval-= x;
		return returnval;
	}
	int card (void){
	int acc=0;
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			acc += ((int*)mult)[count] ;
		return acc;
	}
};
patient_Domain operator + (const patient_Token& t1 ,const patient_Token& t2 )

;class abstractBindingImpl {
public:
	patient_Token x;
};
class abstractMarkingImpl {
public:
	patient_Domain _PL_ReadyT;
	patient_Domain _PL_Healthy;
	patient_Domain _PL_Ill;
	patient_Domain _PL_Arrival;
	patient_Domain _PL_ThreatedByDocH;
	patient_Domain _PL_ThreatedByDocL;
	patient_Domain _PL_WaitingRoom;
	int _PL_OperatingRoom;
	patient_Domain _PL_ArrivalUrgence;
	patient_Domain _PL_USurgery;
	int _PL_TraumaTeam;
	patient_Domain _PL_Ustab;
	patient_Domain _PL_WSurgery;
	patient_Domain _PL_WBloodEx;
	patient_Domain _PL_WXRayEx;
	int _PL_CountDoctor;
	patient_Domain _PL_MonitoredRoom;
	int _PL_Doctor;
	patient_Domain _PL_PatientRecovered;
	patient_Domain _PL_UBloodEx;
	int _PL_ResB;
	patient_Domain _PL_Waiting;
	int _PL_ResX;
	patient_Domain _PL_UXRayEx;
	patient_Domain _PL_FXRay;
	patient_Domain _PL_FBloodEx;
	patient_Domain x;
};
#endif
