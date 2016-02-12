#ifndef _MarkingImpl_HPP
#define    _MarkingImpl_HPP
using namespace std;
#include <string.h>
enum proc_Color_Classe {
	Color_proc_p1,
	Color_proc_p2,
	Color_proc_p3,
	Color_proc_Total,
	Color_proc_All
};
extern const char *Color_proc_names[];
struct contains_proc_Color_Classe{
	virtual void apply_perm(proc_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(proc_Color_Classe,int,int) const =0;
};
enum mach1_Color_Classe {
	Color_mach1_B1,
	Color_mach1_B2,
	Color_mach1_Total,
	Color_mach1_All
};
extern const char *Color_mach1_names[];
struct contains_mach1_Color_Classe{
	virtual void apply_perm(mach1_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(mach1_Color_Classe,int,int) const =0;
};

struct proc_Token{
	proc_Color_Classe c0;
	int mult;
	proc_Token(  proc_Color_Classe cv0 = (proc_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	proc_Token( const proc_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	proc_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (proc_Color_Classe)(Color_proc_Total - 1) ){ c0 = (proc_Color_Classe)(c0+ 1); return;};
c0 = (proc_Color_Classe)(0);
	}
	void print(){
		std::cerr << mult << "<" << Color_proc_names[c0] << ">";
	}
	proc_Token next(int i)const {
		proc_Token x((proc_Color_Classe)((c0 +i) % Color_proc_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (proc_Color_Classe)(Color_proc_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
};
struct proc_Domain: contains_proc_Color_Classe {
	int mult[ Color_proc_Total ];
	proc_Domain(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}
	proc_Domain(proc_Color_Classe c0) {
		fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), 0 );
		if(c0 != Color_proc_All)
			mult[c0] = 1 ;
		else{
			for( int i0= ( c0 == Color_proc_All ? 0 : c0);i0< ( c0 == Color_proc_All ? Color_proc_Total : c0+1);i0++)
				mult[i0] = 1 ;
		}
	}
	size_t copyVector(vector<int> &v ,size_t s)const{
		copy((int*)mult,(int*)mult + sizeof(mult)/sizeof(int), v.begin() + s );
		return s+sizeof(mult)/sizeof(int);
	}
	size_t setVector(const vector<int> &v ,size_t s){
		copy(v.begin() + s, v.begin() + s + sizeof(mult)/sizeof(int), (int*)mult );
		return s+sizeof(mult)/sizeof(int);
	}
	proc_Domain& operator = (const proc_Domain& x){
		copy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);
		return *this;
	}
	bool operator == (const proc_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);
	}
	bool operator < (const proc_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());
	}
	bool operator > (const proc_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());
	}
	proc_Domain operator * (int v){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;
		return *this;
	}
	proc_Domain& operator += (const proc_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]+= ((int*)x.mult)[count] ;
		return *this;
	}
	proc_Domain& operator += (const proc_Token& x){
		mult[ x.c0 ] += x.mult;
		return *this;
	}
	proc_Domain operator + (const proc_Token& x){
		proc_Domain d(*this);
		d+=x;
 		return d;
	}
	proc_Domain& operator -= (const proc_Token& x){
		mult[ x.c0 ] -= x.mult;
		return *this;
	}
	bool operator < (const proc_Token& x)const{
		return mult[ x.c0 ] < x.mult;
	}
	bool operator >= (const proc_Token& x)const{
		return mult[ x.c0 ] >= x.mult;
	}
	proc_Domain operator + (const proc_Domain& x)const{
		proc_Domain returnval = *this; returnval+= x;
		return returnval;
	}
	proc_Domain& operator -= (const proc_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]-= ((int*)x.mult)[count] ;
		return *this;
	}
	proc_Domain operator - (const proc_Domain& x)const{
		proc_Domain returnval = *this; returnval-= x;
		return returnval;
	}
	int card (void){
	int acc=0;
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			acc += ((int*)mult)[count] ;
		return acc;
	}
	virtual void apply_perm(proc_Color_Classe,const std::vector<size_t> &index){
		proc_Domain temp = *this ;
		for( int i0= 0 ; i0< Color_proc_Total ;i0++)
			mult[i0] = temp.mult[ index[i0] ];
	}
	virtual int compare(proc_Color_Classe,int cci,int ccj)const{
		{
			if(mult[ cci ] > mult[ ccj ])return 1;
			if(mult[ cci ] < mult[ ccj ])return -1;
		}
		return 0;
	}
};
proc_Domain operator + (const proc_Token& t1 ,const proc_Token& t2 )

;std::ostream& operator << (std::ostream& out, const proc_Domain& x);

struct mach1_Token{
	mach1_Color_Classe c0;
	int mult;
	mach1_Token(  mach1_Color_Classe cv0 = (mach1_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	mach1_Token( const mach1_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	mach1_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (mach1_Color_Classe)(Color_mach1_Total - 1) ){ c0 = (mach1_Color_Classe)(c0+ 1); return;};
c0 = (mach1_Color_Classe)(0);
	}
	void print(){
		std::cerr << mult << "<" << Color_mach1_names[c0] << ">";
	}
	mach1_Token next(int i)const {
		mach1_Token x((mach1_Color_Classe)((c0 +i) % Color_mach1_Total),  mult);
		return x;}
	bool islast()const {
		return ( c0== (mach1_Color_Classe)(Color_mach1_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
};
struct mach1_Domain: contains_mach1_Color_Classe {
	int mult[ Color_mach1_Total ];
	mach1_Domain(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}
	mach1_Domain(mach1_Color_Classe c0) {
		fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), 0 );
		if(c0 != Color_mach1_All)
			mult[c0] = 1 ;
		else{
			for( int i0= ( c0 == Color_mach1_All ? 0 : c0);i0< ( c0 == Color_mach1_All ? Color_mach1_Total : c0+1);i0++)
				mult[i0] = 1 ;
		}
	}
	size_t copyVector(vector<int> &v ,size_t s)const{
		copy((int*)mult,(int*)mult + sizeof(mult)/sizeof(int), v.begin() + s );
		return s+sizeof(mult)/sizeof(int);
	}
	size_t setVector(const vector<int> &v ,size_t s){
		copy(v.begin() + s, v.begin() + s + sizeof(mult)/sizeof(int), (int*)mult );
		return s+sizeof(mult)/sizeof(int);
	}
	mach1_Domain& operator = (const mach1_Domain& x){
		copy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);
		return *this;
	}
	bool operator == (const mach1_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);
	}
	bool operator < (const mach1_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());
	}
	bool operator > (const mach1_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());
	}
	mach1_Domain operator * (int v){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;
		return *this;
	}
	mach1_Domain& operator += (const mach1_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]+= ((int*)x.mult)[count] ;
		return *this;
	}
	mach1_Domain& operator += (const mach1_Token& x){
		mult[ x.c0 ] += x.mult;
		return *this;
	}
	mach1_Domain operator + (const mach1_Token& x){
		mach1_Domain d(*this);
		d+=x;
 		return d;
	}
	mach1_Domain& operator -= (const mach1_Token& x){
		mult[ x.c0 ] -= x.mult;
		return *this;
	}
	bool operator < (const mach1_Token& x)const{
		return mult[ x.c0 ] < x.mult;
	}
	bool operator >= (const mach1_Token& x)const{
		return mult[ x.c0 ] >= x.mult;
	}
	mach1_Domain operator + (const mach1_Domain& x)const{
		mach1_Domain returnval = *this; returnval+= x;
		return returnval;
	}
	mach1_Domain& operator -= (const mach1_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]-= ((int*)x.mult)[count] ;
		return *this;
	}
	mach1_Domain operator - (const mach1_Domain& x)const{
		mach1_Domain returnval = *this; returnval-= x;
		return returnval;
	}
	int card (void){
	int acc=0;
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			acc += ((int*)mult)[count] ;
		return acc;
	}
	virtual void apply_perm(mach1_Color_Classe,const std::vector<size_t> &index){
		mach1_Domain temp = *this ;
		for( int i0= 0 ; i0< Color_mach1_Total ;i0++)
			mult[i0] = temp.mult[ index[i0] ];
	}
	virtual int compare(mach1_Color_Classe,int cci,int ccj)const{
		{
			if(mult[ cci ] > mult[ ccj ])return 1;
			if(mult[ cci ] < mult[ ccj ])return -1;
		}
		return 0;
	}
};
mach1_Domain operator + (const mach1_Token& t1 ,const mach1_Token& t2 )

;std::ostream& operator << (std::ostream& out, const mach1_Domain& x);

struct Block_Token{
	proc_Color_Classe c0;
	mach1_Color_Classe c1;
	int mult;
	Block_Token(  proc_Color_Classe cv0 = (proc_Color_Classe)0,  mach1_Color_Classe cv1 = (mach1_Color_Classe)0, int v =1) {
		c0= cv0;
		c1= cv1;
		mult = v;
	}
	Block_Token( const proc_Token& cv0, const mach1_Token& cv1, int v =1) {
		c0= cv0.c0;
		c1= cv1.c0;
		mult = v;
	}
	Block_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (proc_Color_Classe)(Color_proc_Total - 1) ){ c0 = (proc_Color_Classe)(c0+ 1); return;};
c0 = (proc_Color_Classe)(0);
		if( c1< (mach1_Color_Classe)(Color_mach1_Total - 1) ){ c1 = (mach1_Color_Classe)(c1+ 1); return;};
c1 = (mach1_Color_Classe)(0);
	}
	void print(){
		std::cerr << mult << "<" << Color_proc_names[c0]<< " , " <<  Color_mach1_names[c1] << ">";
	}
	bool islast()const {
		return ( c0== (proc_Color_Classe)(Color_proc_Total -1)  &&  c1== (mach1_Color_Classe)(Color_mach1_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
};
struct Block_Domain: contains_proc_Color_Classe, contains_mach1_Color_Classe {
	int mult[ Color_proc_Total ][ Color_mach1_Total ];
	Block_Domain(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}
	Block_Domain(proc_Color_Classe c0,mach1_Color_Classe c1) {
		fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), 0 );
		if(c0 != Color_proc_All && c1 != Color_mach1_All)
			mult[c0][c1] = 1 ;
		else{
			for( int i0= ( c0 == Color_proc_All ? 0 : c0);i0< ( c0 == Color_proc_All ? Color_proc_Total : c0+1);i0++)
			for( int i1= ( c1 == Color_mach1_All ? 0 : c1);i1< ( c1 == Color_mach1_All ? Color_mach1_Total : c1+1);i1++)
				mult[i0][i1] = 1 ;
		}
	}
	size_t copyVector(vector<int> &v ,size_t s)const{
		copy((int*)mult,(int*)mult + sizeof(mult)/sizeof(int), v.begin() + s );
		return s+sizeof(mult)/sizeof(int);
	}
	size_t setVector(const vector<int> &v ,size_t s){
		copy(v.begin() + s, v.begin() + s + sizeof(mult)/sizeof(int), (int*)mult );
		return s+sizeof(mult)/sizeof(int);
	}
	Block_Domain& operator = (const Block_Domain& x){
		copy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);
		return *this;
	}
	bool operator == (const Block_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);
	}
	bool operator < (const Block_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());
	}
	bool operator > (const Block_Domain& x){
		return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());
	}
	Block_Domain operator * (int v){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;
		return *this;
	}
	Block_Domain& operator += (const Block_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]+= ((int*)x.mult)[count] ;
		return *this;
	}
	Block_Domain& operator += (const Block_Token& x){
		mult[ x.c0 ][ x.c1 ] += x.mult;
		return *this;
	}
	Block_Domain operator + (const Block_Token& x){
		Block_Domain d(*this);
		d+=x;
 		return d;
	}
	Block_Domain& operator -= (const Block_Token& x){
		mult[ x.c0 ][ x.c1 ] -= x.mult;
		return *this;
	}
	bool operator < (const Block_Token& x)const{
		return mult[ x.c0 ][ x.c1 ] < x.mult;
	}
	bool operator >= (const Block_Token& x)const{
		return mult[ x.c0 ][ x.c1 ] >= x.mult;
	}
	Block_Domain operator + (const Block_Domain& x)const{
		Block_Domain returnval = *this; returnval+= x;
		return returnval;
	}
	Block_Domain& operator -= (const Block_Domain& x){
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			((int*)mult)[count]-= ((int*)x.mult)[count] ;
		return *this;
	}
	Block_Domain operator - (const Block_Domain& x)const{
		Block_Domain returnval = *this; returnval-= x;
		return returnval;
	}
	int card (void){
	int acc=0;
		for(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)
			acc += ((int*)mult)[count] ;
		return acc;
	}
	virtual void apply_perm(proc_Color_Classe,const std::vector<size_t> &index){
		Block_Domain temp = *this ;
		for( int i0= 0 ; i0< Color_proc_Total ;i0++)
		for( int i1= 0 ; i1< Color_mach1_Total ;i1++)
			mult[i0][i1] = temp.mult[ index[i0] ][ i1 ];
	}
	virtual void apply_perm(mach1_Color_Classe,const std::vector<size_t> &index){
		Block_Domain temp = *this ;
		for( int i0= 0 ; i0< Color_proc_Total ;i0++)
		for( int i1= 0 ; i1< Color_mach1_Total ;i1++)
			mult[i0][i1] = temp.mult[ i0 ][ index[i1] ];
	}
	virtual int compare(proc_Color_Classe,int cci,int ccj)const{
		for( int i1= 0 ; i1< Color_mach1_Total ;i1++)
		{
			if(mult[ cci ][ i1 ] > mult[ ccj ][ i1 ])return 1;
			if(mult[ cci ][ i1 ] < mult[ ccj ][ i1 ])return -1;
		}
		return 0;
	}
	virtual int compare(mach1_Color_Classe,int cci,int ccj)const{
		for( int i0= 0 ; i0< Color_proc_Total ;i0++)
		{
			if(mult[ i0 ][ cci ] > mult[ i0 ][ ccj ])return 1;
			if(mult[ i0 ][ cci ] < mult[ i0 ][ ccj ])return -1;
		}
		return 0;
	}
};
Block_Domain operator + (const Block_Token& t1 ,const Block_Token& t2 )

;std::ostream& operator << (std::ostream& out, const Block_Domain& x);
class abstractBindingImpl {
public:
	proc_Token x;
	proc_Token y;
	mach1_Token b;
};
class abstractMarkingImpl {
public:
	proc_Domain _PL_int0;
	Block_Domain _PL_ploadm0;
	proc_Domain _PL_pf0;
	Block_Domain _PL_ph1m0;
	proc_Domain _PL_pb1;
	Block_Domain _PL_readym1;
	proc_Domain _PL_int1;
	mach1_Domain _PL_block1;
	proc_Domain x;
	proc_Domain y;
	mach1_Domain b;
};
#endif
