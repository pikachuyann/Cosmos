#ifndef _MarkingImpl_HPP
#define    _MarkingImpl_HPP
#include <string.h>
enum philo_Color_Classe {
	Color_philo_p1,
	Color_philo_p2,
	Color_philo_p3,
	Color_philo_p4,
	Color_philo_p5,
	Color_philo_Total,
	Color_philo_All
};
extern const char *Color_philo_names[];

struct philo_Token{
	philo_Color_Classe c0;
	int mult;
	philo_Token(  philo_Color_Classe cv0 = (philo_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	philo_Token( const philo_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	philo_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (philo_Color_Classe)(Color_philo_Total - 1) ){ c0 = (philo_Color_Classe)(c0+ 1); return;};
c0 = (philo_Color_Classe)(0);
	}
	void print(){
		std::cerr << mult << "<" << Color_philo_names[c0] << ">";
	}
	philo_Token next(int i)const {
		philo_Token x((philo_Color_Classe)((c0 +i) % Color_philo_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (philo_Color_Classe)(Color_philo_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
};
struct philo_Domain {
	int mult[ Color_philo_Total ];
	philo_Domain(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}
	philo_Domain(philo_Color_Classe c0) {
		fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), 0 );
		if(c0 != Color_philo_All)
			mult[c0] = 1 ;
		else{
			for( int i0= ( c0 == Color_philo_All ? 0 : c0);i0< ( c0 == Color_philo_All ? Color_philo_Total : c0+1);i0++)
				mult[i0] = 1 ;
		}
	}
	philo_Domain& operator = (const philo_Domain& x){
		copy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);
		return *this;
	}
	bool operator == (const philo_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);
	}
	bool operator < (const philo_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());
	}
	bool operator > (const philo_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());
	}
	philo_Domain operator * (int v){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;
		return *this;
	}
	philo_Domain& operator += (const philo_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]+= ((int*)x.mult)[count] ;
		return *this;
	}
	philo_Domain& operator += (const philo_Token& x){
		mult[ x.c0 ] += x.mult;
		return *this;
	}
	philo_Domain operator + (const philo_Token& x){
		philo_Domain d(*this);
		d+=x;
 		return d;
}
	philo_Domain& operator -= (const philo_Token& x){
		mult[ x.c0 ] -= x.mult;
		return *this;
	}
	bool operator < (const philo_Token& x)const{
		return mult[ x.c0 ] < x.mult;
	}
	bool operator >= (const philo_Token& x)const{
		return mult[ x.c0 ] >= x.mult;
	}
	philo_Domain operator + (const philo_Domain& x)const{
		philo_Domain returnval = *this; returnval+= x;
		return returnval;
	}
	philo_Domain& operator -= (const philo_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]-= ((int*)x.mult)[count] ;
		return *this;
	}
	philo_Domain operator - (const philo_Domain& x)const{
		philo_Domain returnval = *this; returnval-= x;
		return returnval;
	}
	int card (void){
	int acc=0;
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			acc += ((int*)mult)[count] ;
		return acc;
	}
};
philo_Domain operator + (const philo_Token& t1 ,const philo_Token& t2 )

;class abstractBindingImpl {
public:
	philo_Token x;
};
class abstractMarkingImpl {
public:
	philo_Domain _PL_Think;
	philo_Domain _PL_Wait;
	philo_Domain _PL_Eat;
	philo_Domain _PL_Fork;
	philo_Domain x;
};
#endif
