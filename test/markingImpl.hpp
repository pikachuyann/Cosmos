#ifndef _MarkingImpl_HPP
#define    _MarkingImpl_HPP
using namespace std;
#include <string.h>
enum PosX_Color_Classe {
	Color_PosX_PosX_IC_0,
	Color_PosX_PosX_IC_1,
	Color_PosX_PosX_IC_2,
	Color_PosX_PosX_IC_3,
	Color_PosX_PosX_IC_4,
	Color_PosX_PosX_IC_5,
	Color_PosX_PosX_IC_6,
	Color_PosX_PosX_IC_7,
	Color_PosX_PosX_IC_8,
	Color_PosX_PosX_IC_9,
	Color_PosX_PosX_IC_10,
	Color_PosX_PosX_IC_11,
	Color_PosX_PosX_IC_12,
	Color_PosX_PosX_IC_13,
	Color_PosX_PosX_IC_14,
	Color_PosX_PosX_IC_15,
	Color_PosX_PosX_IC_16,
	Color_PosX_PosX_IC_17,
	Color_PosX_PosX_IC_18,
	Color_PosX_PosX_IC_19,
	Color_PosX_PosX_IC_20,
	Color_PosX_Total,
	Color_PosX_All
};
extern const char *Color_PosX_names[];
struct contains_PosX_Color_Classe{
	virtual void apply_perm(PosX_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(PosX_Color_Classe,int,int) const =0;
};
enum PosY_Color_Classe {
	Color_PosY_PosY_IC_0,
	Color_PosY_PosY_IC_1,
	Color_PosY_Total,
	Color_PosY_All
};
extern const char *Color_PosY_names[];
struct contains_PosY_Color_Classe{
	virtual void apply_perm(PosY_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(PosY_Color_Classe,int,int) const =0;
};
enum VitX_Color_Classe {
	Color_VitX_VitX_IC_0,
	Color_VitX_VitX_IC_1,
	Color_VitX_VitX_IC_2,
	Color_VitX_Total,
	Color_VitX_All
};
extern const char *Color_VitX_names[];
struct contains_VitX_Color_Classe{
	virtual void apply_perm(VitX_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(VitX_Color_Classe,int,int) const =0;
};
enum VitY_Color_Classe {
	Color_VitY_VitY_IC_0,
	Color_VitY_VitY_IC_1,
	Color_VitY_Total,
	Color_VitY_All
};
extern const char *Color_VitY_names[];
struct contains_VitY_Color_Classe{
	virtual void apply_perm(VitY_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(VitY_Color_Classe,int,int) const =0;
};
enum AccX_Color_Classe {
	Color_AccX_AccX_IC_0,
	Color_AccX_AccX_IC_1,
	Color_AccX_Total,
	Color_AccX_All
};
extern const char *Color_AccX_names[];
struct contains_AccX_Color_Classe{
	virtual void apply_perm(AccX_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(AccX_Color_Classe,int,int) const =0;
};
enum AccY_Color_Classe {
	Color_AccY_AccY_IC_0,
	Color_AccY_AccY_IC_1,
	Color_AccY_Total,
	Color_AccY_All
};
extern const char *Color_AccY_names[];
struct contains_AccY_Color_Classe{
	virtual void apply_perm(AccY_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(AccY_Color_Classe,int,int) const =0;
};
enum Jeton_Color_Classe {
	Color_Jeton_Jeton_IC_1,
	Color_Jeton_Total,
	Color_Jeton_All
};
extern const char *Color_Jeton_names[];
struct contains_Jeton_Color_Classe{
	virtual void apply_perm(Jeton_Color_Classe,const std::vector<size_t> &index)=0;
	virtual int compare(Jeton_Color_Classe,int,int) const =0;
};
#include "marking.hpp"
#include "markingTemplate.hpp"

struct PosX_Token{
	PosX_Color_Classe c0;
	int mult;
	PosX_Token(  PosX_Color_Classe cv0 = (PosX_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	PosX_Token( const PosX_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	PosX_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (PosX_Color_Classe)(Color_PosX_Total - 1) ){ c0 = (PosX_Color_Classe)(c0+ 1); return;};
c0 = (PosX_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_PosX_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (PosX_Color_Classe)(Color_PosX_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const PosX_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< PosX_Token> PosX_Domain;

struct PosY_Token{
	PosY_Color_Classe c0;
	int mult;
	PosY_Token(  PosY_Color_Classe cv0 = (PosY_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	PosY_Token( const PosY_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	PosY_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (PosY_Color_Classe)(Color_PosY_Total - 1) ){ c0 = (PosY_Color_Classe)(c0+ 1); return;};
c0 = (PosY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_PosY_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (PosY_Color_Classe)(Color_PosY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const PosY_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< PosY_Token> PosY_Domain;

struct VitX_Token{
	VitX_Color_Classe c0;
	int mult;
	VitX_Token(  VitX_Color_Classe cv0 = (VitX_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	VitX_Token( const VitX_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	VitX_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (VitX_Color_Classe)(Color_VitX_Total - 1) ){ c0 = (VitX_Color_Classe)(c0+ 1); return;};
c0 = (VitX_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_VitX_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (VitX_Color_Classe)(Color_VitX_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const VitX_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< VitX_Token> VitX_Domain;

struct VitY_Token{
	VitY_Color_Classe c0;
	int mult;
	VitY_Token(  VitY_Color_Classe cv0 = (VitY_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	VitY_Token( const VitY_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	VitY_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (VitY_Color_Classe)(Color_VitY_Total - 1) ){ c0 = (VitY_Color_Classe)(c0+ 1); return;};
c0 = (VitY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_VitY_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (VitY_Color_Classe)(Color_VitY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const VitY_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< VitY_Token> VitY_Domain;

struct AccX_Token{
	AccX_Color_Classe c0;
	int mult;
	AccX_Token(  AccX_Color_Classe cv0 = (AccX_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	AccX_Token( const AccX_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	AccX_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (AccX_Color_Classe)(Color_AccX_Total - 1) ){ c0 = (AccX_Color_Classe)(c0+ 1); return;};
c0 = (AccX_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_AccX_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (AccX_Color_Classe)(Color_AccX_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const AccX_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< AccX_Token> AccX_Domain;

struct AccY_Token{
	AccY_Color_Classe c0;
	int mult;
	AccY_Token(  AccY_Color_Classe cv0 = (AccY_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	AccY_Token( const AccY_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	AccY_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (AccY_Color_Classe)(Color_AccY_Total - 1) ){ c0 = (AccY_Color_Classe)(c0+ 1); return;};
c0 = (AccY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_AccY_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (AccY_Color_Classe)(Color_AccY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const AccY_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< AccY_Token> AccY_Domain;

struct Jeton_Token{
	Jeton_Color_Classe c0;
	int mult;
	Jeton_Token(  Jeton_Color_Classe cv0 = (Jeton_Color_Classe)0, int v =1) {
		c0= cv0;
		mult = v;
	}
	Jeton_Token( const Jeton_Token& cv0, int v =1) {
		c0= cv0.c0;
		mult = v;
	}
	Jeton_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (Jeton_Color_Classe)(Color_Jeton_Total - 1) ){ c0 = (Jeton_Color_Classe)(c0+ 1); return;};
c0 = (Jeton_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_Jeton_names[c0] << ">";
	}
	bool islast()const {
		return ( c0== (Jeton_Color_Classe)(Color_Jeton_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const Jeton_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		return false;
	}
};
typedef DomainGen< Jeton_Token> Jeton_Domain;

struct Vehicle_Token{
	PosX_Color_Classe c0;
	PosY_Color_Classe c1;
	VitX_Color_Classe c2;
	VitY_Color_Classe c3;
	int mult;
	Vehicle_Token(  PosX_Color_Classe cv0 = (PosX_Color_Classe)0,  PosY_Color_Classe cv1 = (PosY_Color_Classe)0,  VitX_Color_Classe cv2 = (VitX_Color_Classe)0,  VitY_Color_Classe cv3 = (VitY_Color_Classe)0, int v =1) {
		c0= cv0;
		c1= cv1;
		c2= cv2;
		c3= cv3;
		mult = v;
	}
	Vehicle_Token( const PosX_Token& cv0, const PosY_Token& cv1, const VitX_Token& cv2, const VitY_Token& cv3, int v =1) {
		c0= cv0.c0;
		c1= cv1.c0;
		c2= cv2.c0;
		c3= cv3.c0;
		mult = v;
	}
	Vehicle_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (PosX_Color_Classe)(Color_PosX_Total - 1) ){ c0 = (PosX_Color_Classe)(c0+ 1); return;};
c0 = (PosX_Color_Classe)(0);
		if( c1< (PosY_Color_Classe)(Color_PosY_Total - 1) ){ c1 = (PosY_Color_Classe)(c1+ 1); return;};
c1 = (PosY_Color_Classe)(0);
		if( c2< (VitX_Color_Classe)(Color_VitX_Total - 1) ){ c2 = (VitX_Color_Classe)(c2+ 1); return;};
c2 = (VitX_Color_Classe)(0);
		if( c3< (VitY_Color_Classe)(Color_VitY_Total - 1) ){ c3 = (VitY_Color_Classe)(c3+ 1); return;};
c3 = (VitY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_PosX_names[c0]<< " , " <<  Color_PosY_names[c1]<< " , " <<  Color_VitX_names[c2]<< " , " <<  Color_VitY_names[c3] << ">";
	}
	bool islast()const {
		return ( c0== (PosX_Color_Classe)(Color_PosX_Total -1)  &&  c1== (PosY_Color_Classe)(Color_PosY_Total -1)  &&  c2== (VitX_Color_Classe)(Color_VitX_Total -1)  &&  c3== (VitY_Color_Classe)(Color_VitY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const Vehicle_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		if (c1 < tok.c1) { return true; }
		if (c1 > tok.c1) { return false; }
		if (c2 < tok.c2) { return true; }
		if (c2 > tok.c2) { return false; }
		if (c3 < tok.c3) { return true; }
		if (c3 > tok.c3) { return false; }
		return false;
	}
};
typedef DomainGen< Vehicle_Token> Vehicle_Domain;

struct SelfVehicle_Token{
	PosX_Color_Classe c0;
	PosY_Color_Classe c1;
	VitX_Color_Classe c2;
	VitY_Color_Classe c3;
	AccX_Color_Classe c4;
	AccY_Color_Classe c5;
	int mult;
	SelfVehicle_Token(  PosX_Color_Classe cv0 = (PosX_Color_Classe)0,  PosY_Color_Classe cv1 = (PosY_Color_Classe)0,  VitX_Color_Classe cv2 = (VitX_Color_Classe)0,  VitY_Color_Classe cv3 = (VitY_Color_Classe)0,  AccX_Color_Classe cv4 = (AccX_Color_Classe)0,  AccY_Color_Classe cv5 = (AccY_Color_Classe)0, int v =1) {
		c0= cv0;
		c1= cv1;
		c2= cv2;
		c3= cv3;
		c4= cv4;
		c5= cv5;
		mult = v;
	}
	SelfVehicle_Token( const PosX_Token& cv0, const PosY_Token& cv1, const VitX_Token& cv2, const VitY_Token& cv3, const AccX_Token& cv4, const AccY_Token& cv5, int v =1) {
		c0= cv0.c0;
		c1= cv1.c0;
		c2= cv2.c0;
		c3= cv3.c0;
		c4= cv4.c0;
		c5= cv5.c0;
		mult = v;
	}
	SelfVehicle_Token operator * (size_t v){
		mult *= v;
		return *this;
	}
	void iter() {
		if( c0< (PosX_Color_Classe)(Color_PosX_Total - 1) ){ c0 = (PosX_Color_Classe)(c0+ 1); return;};
c0 = (PosX_Color_Classe)(0);
		if( c1< (PosY_Color_Classe)(Color_PosY_Total - 1) ){ c1 = (PosY_Color_Classe)(c1+ 1); return;};
c1 = (PosY_Color_Classe)(0);
		if( c2< (VitX_Color_Classe)(Color_VitX_Total - 1) ){ c2 = (VitX_Color_Classe)(c2+ 1); return;};
c2 = (VitX_Color_Classe)(0);
		if( c3< (VitY_Color_Classe)(Color_VitY_Total - 1) ){ c3 = (VitY_Color_Classe)(c3+ 1); return;};
c3 = (VitY_Color_Classe)(0);
		if( c4< (AccX_Color_Classe)(Color_AccX_Total - 1) ){ c4 = (AccX_Color_Classe)(c4+ 1); return;};
c4 = (AccX_Color_Classe)(0);
		if( c5< (AccY_Color_Classe)(Color_AccY_Total - 1) ){ c5 = (AccY_Color_Classe)(c5+ 1); return;};
c5 = (AccY_Color_Classe)(0);
	}
	void print(std::ostream& out) const {
		out << mult << "<" << Color_PosX_names[c0]<< " , " <<  Color_PosY_names[c1]<< " , " <<  Color_VitX_names[c2]<< " , " <<  Color_VitY_names[c3]<< " , " <<  Color_AccX_names[c4]<< " , " <<  Color_AccY_names[c5] << ">";
	}
	bool islast()const {
		return ( c0== (PosX_Color_Classe)(Color_PosX_Total -1)  &&  c1== (PosY_Color_Classe)(Color_PosY_Total -1)  &&  c2== (VitX_Color_Classe)(Color_VitX_Total -1)  &&  c3== (VitY_Color_Classe)(Color_VitY_Total -1)  &&  c4== (AccX_Color_Classe)(Color_AccX_Total -1)  &&  c5== (AccY_Color_Classe)(Color_AccY_Total -1)  );
	}
	bool operator > (const int x){
		return mult > x ;
	}
	bool operator < (const int x){
		return mult < x ;
	}
	bool operator < (const SelfVehicle_Token &tok) const {
		if (c0 < tok.c0) { return true; }
		if (c0 > tok.c0) { return false; }
		if (c1 < tok.c1) { return true; }
		if (c1 > tok.c1) { return false; }
		if (c2 < tok.c2) { return true; }
		if (c2 > tok.c2) { return false; }
		if (c3 < tok.c3) { return true; }
		if (c3 > tok.c3) { return false; }
		if (c4 < tok.c4) { return true; }
		if (c4 > tok.c4) { return false; }
		if (c5 < tok.c5) { return true; }
		if (c5 > tok.c5) { return false; }
		return false;
	}
};
typedef DomainGen< SelfVehicle_Token> SelfVehicle_Domain;
class abstractBindingImpl {
public:
	PosX_Token xs;
	PosX_Token x;
	PosY_Token ys;
	PosY_Token y;
	VitX_Token dxs;
	VitX_Token dx;
	VitY_Token dys;
	VitY_Token dy;
	AccX_Token ddx;
	AccY_Token ddy;
	Jeton_Token j;
};
class abstractMarkingImpl {
public:
	SelfVehicle_Domain _PL_selfVehicle;
	Jeton_Domain _PL_simstep1;
	Jeton_Domain _PL_simstep2;
	Jeton_Domain _PL_simstep3;
	Jeton_Domain _PL_simstep4;
	Jeton_Domain _PL_initGenere;
	Vehicle_Domain _PL_inProcess;
	Vehicle_Domain _PL_otherVehicles;
	int _PL_PosFinale;
	PosX_Domain _PL_PositionMax;
	PosX_Domain xs;
	PosX_Domain x;
	PosY_Domain ys;
	PosY_Domain y;
	VitX_Domain dxs;
	VitX_Domain dx;
	VitY_Domain dys;
	VitY_Domain dy;
	AccX_Domain ddx;
	AccY_Domain ddy;
	Jeton_Domain j;
};
class abstractMarkingIterator {
public:
	std::map<SelfVehicle_Token, unsigned int>::const_iterator _IT_selfVehicle;
	std::map<Jeton_Token, unsigned int>::const_iterator _IT_simstep1;
	std::map<Jeton_Token, unsigned int>::const_iterator _IT_simstep2;
	std::map<Jeton_Token, unsigned int>::const_iterator _IT_simstep3;
	std::map<Jeton_Token, unsigned int>::const_iterator _IT_simstep4;
	std::map<Jeton_Token, unsigned int>::const_iterator _IT_initGenere;
	std::map<Vehicle_Token, unsigned int>::const_iterator _IT_inProcess;
	std::map<Vehicle_Token, unsigned int>::const_iterator _IT_otherVehicles;
	std::map<PosX_Token, unsigned int>::const_iterator _IT_PositionMax;
	size_t _ITVAR_xs;
	size_t _ITVAR_x;
	size_t _ITVAR_ys;
	size_t _ITVAR_y;
	size_t _ITVAR_dxs;
	size_t _ITVAR_dx;
	size_t _ITVAR_dys;
	size_t _ITVAR_dy;
	size_t _ITVAR_ddx;
	size_t _ITVAR_ddy;
	size_t _ITVAR_j;

	void reset(abstractMarkingImpl& m) {
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		_IT_simstep1 = m._PL_simstep1.tokens.begin();
		_IT_simstep2 = m._PL_simstep2.tokens.begin();
		_IT_simstep3 = m._PL_simstep3.tokens.begin();
		_IT_simstep4 = m._PL_simstep4.tokens.begin();
		_IT_initGenere = m._PL_initGenere.tokens.begin();
		_IT_inProcess = m._PL_inProcess.tokens.begin();
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		_IT_PositionMax = m._PL_PositionMax.tokens.begin();

	}
public:

	bool nextInterieur(size_t& t, abstractMarkingImpl& m) {
	switch (t){
		case 6:	//updOther
		if (not (_IT_inProcess == m._PL_inProcess.tokens.end())) { _IT_inProcess++; return true; }
		_IT_inProcess = m._PL_inProcess.tokens.begin();
		if (not (_IT_inProcess == m._PL_inProcess.tokens.end())) { _IT_inProcess++; return true; }
		_IT_inProcess = m._PL_inProcess.tokens.begin();
		if (not (_IT_inProcess == m._PL_inProcess.tokens.end())) { _IT_inProcess++; return true; }
		_IT_inProcess = m._PL_inProcess.tokens.begin();
		if (not (_IT_inProcess == m._PL_inProcess.tokens.end())) { _IT_inProcess++; return true; }
		_IT_inProcess = m._PL_inProcess.tokens.begin();
		if (not (_IT_simstep2 == m._PL_simstep2.tokens.end())) { _IT_simstep2++; return true; }
		_IT_simstep2 = m._PL_simstep2.tokens.begin();
		return false;

		break;
		case 2:	//simstepA
		if (not (_IT_initGenere == m._PL_initGenere.tokens.end())) { _IT_initGenere++; return true; }
		_IT_initGenere = m._PL_initGenere.tokens.begin();
		return false;

		break;
		case 5:	//randOther
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_simstep1 == m._PL_simstep1.tokens.end())) { _IT_simstep1++; return true; }
		_IT_simstep1 = m._PL_simstep1.tokens.begin();
		return false;

		break;
		case 8:	//exit
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		return false;

		break;
		case 9:	//end
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_PositionMax == m._PL_PositionMax.tokens.end())) { _IT_PositionMax++; return true; }
		_IT_PositionMax = m._PL_PositionMax.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		return false;

		break;
		case 10:	//collision
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_otherVehicles == m._PL_otherVehicles.tokens.end())) { _IT_otherVehicles++; return true; }
		_IT_otherVehicles = m._PL_otherVehicles.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		return false;

		break;
		case 0:	//updateSelf
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_simstep3 == m._PL_simstep3.tokens.end())) { _IT_simstep3++; return true; }
		_IT_simstep3 = m._PL_simstep3.tokens.begin();
		return false;

		break;
		case 1:	//lightController
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_selfVehicle == m._PL_selfVehicle.tokens.end())) { _IT_selfVehicle++; return true; }
		_IT_selfVehicle = m._PL_selfVehicle.tokens.begin();
		if (not (_IT_simstep4 == m._PL_simstep4.tokens.end())) { _IT_simstep4++; return true; }
		_IT_simstep4 = m._PL_simstep4.tokens.begin();
		return false;

		break;
		case 3:	//simstepB
		if (not (_IT_simstep1 == m._PL_simstep1.tokens.end())) { _IT_simstep1++; return true; }
		_IT_simstep1 = m._PL_simstep1.tokens.begin();
		return false;

		break;
		case 4:	//simstepC
		if (not (_IT_simstep2 == m._PL_simstep2.tokens.end())) { _IT_simstep2++; return true; }
		_IT_simstep2 = m._PL_simstep2.tokens.begin();
		return false;

		break;
		default:	//generationInitiale,enter,
		return false;

		break;
	}

	}
private:

	bool isCoherent(size_t& t,abstractMarkingImpl& m) {

	}
public:
};
#endif
