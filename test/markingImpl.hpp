#ifndef _MarkingImpl_HPP
#define    _MarkingImpl_HPP
#include <string.h>
enum site_Color_Classe {
	Color_site_site_IC_1,
	Color_site_site_IC_2,
	Color_site_Total,
	Color_site_All
};
extern const char *Color_site_names[];
enum file_Color_Classe {
	Color_file_file_IC_1,
	Color_file_file_IC_2,
	Color_file_file_IC_3,
	Color_file_Total,
	Color_file_All
};
extern const char *Color_file_names[];

struct site_Token{
	site_Color_Classe c0;
	int mult;
	site_Token(  site_Color_Classe cv0 = (site_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	site_Token( const site_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	site_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (site_Color_Classe)(Color_site_Total - 1) ){ c0 = (site_Color_Classe)(c0+ 1); return;};
c0 = (site_Color_Classe)(0);
	}
	void print(){
		std::cerr << mult << "<" << Color_site_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (site_Color_Classe)(Color_site_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
};
struct site_Domain {
	int mult[ Color_site_Total ];
	site_Domain(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}
	site_Domain(site_Color_Classe c0) {
		memset(&mult,0 , sizeof(mult));
		if(c0 != Color_site_All)
			mult[c0] = 1 ;
		else{
			for( int i0= ( c0 == Color_site_All ? 0 : c0);i0< ( c0 == Color_site_All ? Color_site_Total : c0+1);i0++)
				mult[i0] = 1 ;
		}
	}
	site_Domain& operator = (const site_Domain& x){
		copy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);
		return *this;
	}
	bool operator == (const site_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);
	}
	bool operator < (const site_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());
	}
	bool operator > (const site_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());
	}
	site_Domain operator * (int v){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;
		return *this;
	}
	site_Domain& operator += (const site_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]+= ((int*)x.mult)[count] ;
		return *this;
	}
	site_Domain& operator += (const site_Token& x){
		mult[ x.c0 ] += x.mult;
		return *this;
	}
	site_Domain operator + (const site_Token& x){
		site_Domain d(*this);
		d+=x;
 		return d;
}
	site_Domain& operator -= (const site_Token& x){
		mult[ x.c0 ] -= x.mult;
		return *this;
	}
	bool operator < (const site_Token& x)const{
		return mult[ x.c0 ] < x.mult;
	}
	bool operator >= (const site_Token& x)const{
		return mult[ x.c0 ] >= x.mult;
	}
	site_Domain operator + (const site_Domain& x)const{
		site_Domain returnval = *this; returnval+= x;
		return returnval;
	}
	site_Domain& operator -= (const site_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]-= ((int*)x.mult)[count] ;
		return *this;
	}
	site_Domain operator - (const site_Domain& x)const{
		site_Domain returnval = *this; returnval-= x;
		return returnval;
	}
	int card (void){
	int acc=0;
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			acc += ((int*)mult)[count] ;
		return acc;
	}
};
site_Domain operator + (const site_Token& t1 ,const site_Token& t2 )

;
struct file_Token{
	file_Color_Classe c0;
	int mult;
	file_Token(  file_Color_Classe cv0 = (file_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	file_Token( const file_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	file_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (file_Color_Classe)(Color_file_Total - 1) ){ c0 = (file_Color_Classe)(c0+ 1); return;};
c0 = (file_Color_Classe)(0);
	}
	void print(){
		std::cerr << mult << "<" << Color_file_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (file_Color_Classe)(Color_file_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
};
struct file_Domain {
	int mult[ Color_file_Total ];
	file_Domain(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}
	file_Domain(file_Color_Classe c0) {
		memset(&mult,0 , sizeof(mult));
		if(c0 != Color_file_All)
			mult[c0] = 1 ;
		else{
			for( int i0= ( c0 == Color_file_All ? 0 : c0);i0< ( c0 == Color_file_All ? Color_file_Total : c0+1);i0++)
				mult[i0] = 1 ;
		}
	}
	file_Domain& operator = (const file_Domain& x){
		copy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);
		return *this;
	}
	bool operator == (const file_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);
	}
	bool operator < (const file_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());
	}
	bool operator > (const file_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());
	}
	file_Domain operator * (int v){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;
		return *this;
	}
	file_Domain& operator += (const file_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]+= ((int*)x.mult)[count] ;
		return *this;
	}
	file_Domain& operator += (const file_Token& x){
		mult[ x.c0 ] += x.mult;
		return *this;
	}
	file_Domain operator + (const file_Token& x){
		file_Domain d(*this);
		d+=x;
 		return d;
}
	file_Domain& operator -= (const file_Token& x){
		mult[ x.c0 ] -= x.mult;
		return *this;
	}
	bool operator < (const file_Token& x)const{
		return mult[ x.c0 ] < x.mult;
	}
	bool operator >= (const file_Token& x)const{
		return mult[ x.c0 ] >= x.mult;
	}
	file_Domain operator + (const file_Domain& x)const{
		file_Domain returnval = *this; returnval+= x;
		return returnval;
	}
	file_Domain& operator -= (const file_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]-= ((int*)x.mult)[count] ;
		return *this;
	}
	file_Domain operator - (const file_Domain& x)const{
		file_Domain returnval = *this; returnval-= x;
		return returnval;
	}
	int card (void){
	int acc=0;
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			acc += ((int*)mult)[count] ;
		return acc;
	}
};
file_Domain operator + (const file_Token& t1 ,const file_Token& t2 )

;
struct SF_Token{
	site_Color_Classe c0;
	file_Color_Classe c1;
	int mult;
	SF_Token(  site_Color_Classe cv0 = (site_Color_Classe)0,  file_Color_Classe cv1 = (file_Color_Classe)0, int v =1) {
		c0= cv0;
		c1= cv1;
		mult = v;
	}
	SF_Token( const site_Token& cv0, const file_Token& cv1, int v =1) {
		c0= cv0.c0;
		c1= cv1.c0;
		mult = v;
	}
	SF_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (site_Color_Classe)(Color_site_Total - 1) ){ c0 = (site_Color_Classe)(c0+ 1); return;};
c0 = (site_Color_Classe)(0);
		if( c1< (file_Color_Classe)(Color_file_Total - 1) ){ c1 = (file_Color_Classe)(c1+ 1); return;};
c1 = (file_Color_Classe)(0);
	}
	void print(){
		std::cerr << mult << "<" << Color_site_names[c0]<< " , " <<  Color_file_names[c1] << ">";
	}
	bool islast()const {
		return ( c0== (site_Color_Classe)(Color_site_Total -1)  &&  c1== (file_Color_Classe)(Color_file_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
};
struct SF_Domain {
	int mult[ Color_site_Total ][ Color_file_Total ];
	SF_Domain(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}
	SF_Domain(site_Color_Classe c0,file_Color_Classe c1) {
		memset(&mult,0 , sizeof(mult));
		if(c0 != Color_site_All && c1 != Color_file_All)
			mult[c0][c1] = 1 ;
		else{
			for( int i0= ( c0 == Color_site_All ? 0 : c0);i0< ( c0 == Color_site_All ? Color_site_Total : c0+1);i0++)
			for( int i1= ( c1 == Color_file_All ? 0 : c1);i1< ( c1 == Color_file_All ? Color_file_Total : c1+1);i1++)
				mult[i0][i1] = 1 ;
		}
	}
	SF_Domain& operator = (const SF_Domain& x){
		copy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);
		return *this;
	}
	bool operator == (const SF_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);
	}
	bool operator < (const SF_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());
	}
	bool operator > (const SF_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());
	}
	SF_Domain operator * (int v){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;
		return *this;
	}
	SF_Domain& operator += (const SF_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]+= ((int*)x.mult)[count] ;
		return *this;
	}
	SF_Domain& operator += (const SF_Token& x){
		mult[ x.c0 ][ x.c1 ] += x.mult;
		return *this;
	}
	SF_Domain operator + (const SF_Token& x){
		SF_Domain d(*this);
		d+=x;
 		return d;
}
	SF_Domain& operator -= (const SF_Token& x){
		mult[ x.c0 ][ x.c1 ] -= x.mult;
		return *this;
	}
	bool operator < (const SF_Token& x)const{
		return mult[ x.c0 ][ x.c1 ] < x.mult;
	}
	bool operator >= (const SF_Token& x)const{
		return mult[ x.c0 ][ x.c1 ] >= x.mult;
	}
	SF_Domain operator + (const SF_Domain& x)const{
		SF_Domain returnval = *this; returnval+= x;
		return returnval;
	}
	SF_Domain& operator -= (const SF_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]-= ((int*)x.mult)[count] ;
		return *this;
	}
	SF_Domain operator - (const SF_Domain& x)const{
		SF_Domain returnval = *this; returnval-= x;
		return returnval;
	}
	int card (void){
	int acc=0;
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			acc += ((int*)mult)[count] ;
		return acc;
	}
};
SF_Domain operator + (const SF_Token& t1 ,const SF_Token& t2 )

;class abstractBindingImpl {
public:
	site_Token s;
	file_Token f;
};
class abstractMarkingImpl {
public:
	SF_Domain _PL_RecBuff;
	site_Domain _PL_all_active;
	SF_Domain _PL_Active;
	file_Domain _PL_Mutex;
	SF_Domain _PL_Message;
	SF_Domain _PL_Modify;
	SF_Domain _PL_MesBuffReply;
	SF_Domain _PL_Acknowledge;
	site_Domain _PL_all_passive;
	SF_Domain _PL_updating;
	SF_Domain _PL_WaitMutex;
	site_Domain s;
	file_Domain f;
};
#endif
