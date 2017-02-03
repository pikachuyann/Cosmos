#include "spn.hpp"
#include <iomanip>
using namespace std;
#define PL_selfVehicle_LP 0
#define PL_simstep1_LP 1
#define PL_simstep2_LP 2
#define PL_simstep3_LP 3
#define PL_simstep4_LP 4
#define PL_initGenere_LP 5
#define PL_inProcess_LP 6
#define PL_otherVehicles_LP 7
#define PL_PosFinale_LP 8
#define PL_PositionMax_LP 9
#define TR_updateSelf_RT 0
#define TR_lightController_RT 1
#define TR_simstepA_RT 2
#define TR_simstepB_RT 3
#define TR_simstepC_RT 4
#define TR_randOther_RT 5
#define TR_updOther_RT 6
#define TR_generationInitiale_RT 7
#define TR_exit_RT 8
#define TR_end_RT 9
#define TR_collision_RT 10
#define TR_enter_RT 11

const double MakeNew=0;
const double Ncases=500;
const double Nveh=10;
const double Nvoies=1;
const double Vmax=2;
const int _nb_Place_selfVehicle=0;
const int _nb_Place_simstep1=1;
const int _nb_Place_simstep2=2;
const int _nb_Place_simstep3=3;
const int _nb_Place_simstep4=4;
const int _nb_Place_initGenere=5;
const int _nb_Place_inProcess=6;
const int _nb_Place_otherVehicles=7;
const int _nb_Place_PosFinale=8;
const int _nb_Place_PositionMax=9;
namespace hybridVar {
}
#include "magic.hpp"
void REHandling::print_state(const vector<int> &vect){}
void REHandling::lumpingFun(const abstractMarking &M,vector<int> &vect){}
bool REHandling::precondition(const abstractMarking &M){return true;}
#include "marking.hpp"
#include "markingImpl.hpp"
inline bool contains(const PosX_Domain& d1, const PosX_Domain& d2){	return d1 >= d2;
}
inline bool contains(const PosX_Domain& d1, const PosX_Token& tok){	return d1 >= tok;
}
inline bool contains(const PosY_Domain& d1, const PosY_Domain& d2){	return d1 >= d2;
}
inline bool contains(const PosY_Domain& d1, const PosY_Token& tok){	return d1 >= tok;
}
inline bool contains(const VitX_Domain& d1, const VitX_Domain& d2){	return d1 >= d2;
}
inline bool contains(const VitX_Domain& d1, const VitX_Token& tok){	return d1 >= tok;
}
inline bool contains(const VitY_Domain& d1, const VitY_Domain& d2){	return d1 >= d2;
}
inline bool contains(const VitY_Domain& d1, const VitY_Token& tok){	return d1 >= tok;
}
inline bool contains(const AccX_Domain& d1, const AccX_Domain& d2){	return d1 >= d2;
}
inline bool contains(const AccX_Domain& d1, const AccX_Token& tok){	return d1 >= tok;
}
inline bool contains(const AccY_Domain& d1, const AccY_Domain& d2){	return d1 >= d2;
}
inline bool contains(const AccY_Domain& d1, const AccY_Token& tok){	return d1 >= tok;
}
inline bool contains(const Jeton_Domain& d1, const Jeton_Domain& d2){	return d1 >= d2;
}
inline bool contains(const Jeton_Domain& d1, const Jeton_Token& tok){	return d1 >= tok;
}
inline bool contains(const Vehicle_Domain& d1, const Vehicle_Domain& d2){	return d1 >= d2;
}
inline bool contains(const Vehicle_Domain& d1, const Vehicle_Token& tok){	return d1 >= tok;
}
inline bool contains(const SelfVehicle_Domain& d1, const SelfVehicle_Domain& d2){	return d1 >= d2;
}
inline bool contains(const SelfVehicle_Domain& d1, const SelfVehicle_Token& tok){	return d1 >= tok;
}

void abstractMarking::resetToInitMarking(){
	magicReset();
	P->_PL_selfVehicle =0  ;
	P->_PL_simstep1 =0  ;
	P->_PL_simstep2 =0  ;
	P->_PL_simstep3 =0  ;
	P->_PL_simstep4 =0  ;
	P->_PL_initGenere =0  ;
	P->_PL_inProcess =0  ;
	P->_PL_otherVehicles =0  ;
	P->_PL_PosFinale =0  ;
	P->_PL_PositionMax =0  ;
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
	exit(EXIT_FAILURE);
}

void abstractMarking::setVector(const std::vector<int>&v) {
	size_t i = 0;
	i= P->_PL_selfVehicle.setVector(v,i);
	i= P->_PL_simstep1.setVector(v,i);
	i= P->_PL_simstep2.setVector(v,i);
	i= P->_PL_simstep3.setVector(v,i);
	i= P->_PL_simstep4.setVector(v,i);
	i= P->_PL_initGenere.setVector(v,i);
	i= P->_PL_inProcess.setVector(v,i);
	i= P->_PL_otherVehicles.setVector(v,i);
	P->_PL_PosFinale = v[i++];
	i= P->_PL_PositionMax.setVector(v,i);
};

void abstractMarking::Symmetrize(){
}bool abstractBinding::next() {
	idcount++;
	if(P->xs.mult >= 0){
		if (! P->xs.islast()){	P->xs.iter(); return true; };
		P->xs = PosX_Token();
	}
	if(P->x.mult >= 0){
		if (! P->x.islast()){	P->x.iter(); return true; };
		P->x = PosX_Token();
	}
	if(P->ys.mult >= 0){
		if (! P->ys.islast()){	P->ys.iter(); return true; };
		P->ys = PosY_Token();
	}
	if(P->y.mult >= 0){
		if (! P->y.islast()){	P->y.iter(); return true; };
		P->y = PosY_Token();
	}
	if(P->dxs.mult >= 0){
		if (! P->dxs.islast()){	P->dxs.iter(); return true; };
		P->dxs = VitX_Token();
	}
	if(P->dx.mult >= 0){
		if (! P->dx.islast()){	P->dx.iter(); return true; };
		P->dx = VitX_Token();
	}
	if(P->dys.mult >= 0){
		if (! P->dys.islast()){	P->dys.iter(); return true; };
		P->dys = VitY_Token();
	}
	if(P->dy.mult >= 0){
		if (! P->dy.islast()){	P->dy.iter(); return true; };
		P->dy = VitY_Token();
	}
	if(P->ddx.mult >= 0){
		if (! P->ddx.islast()){	P->ddx.iter(); return true; };
		P->ddx = AccX_Token();
	}
	if(P->ddy.mult >= 0){
		if (! P->ddy.islast()){	P->ddy.iter(); return true; };
		P->ddy = AccY_Token();
	}
	if(P->j.mult >= 0){
		if (! P->j.islast()){	P->j.iter(); return true; };
		P->j = Jeton_Token();
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
	std::cerr << "\txs: ";P->xs.print(std::cerr);
	std::cerr << "\tx: ";P->x.print(std::cerr);
	std::cerr << "\tys: ";P->ys.print(std::cerr);
	std::cerr << "\ty: ";P->y.print(std::cerr);
	std::cerr << "\tdxs: ";P->dxs.print(std::cerr);
	std::cerr << "\tdx: ";P->dx.print(std::cerr);
	std::cerr << "\tdys: ";P->dys.print(std::cerr);
	std::cerr << "\tdy: ";P->dy.print(std::cerr);
	std::cerr << "\tddx: ";P->ddx.print(std::cerr);
	std::cerr << "\tddy: ";P->ddy.print(std::cerr);
	std::cerr << "\tj: ";P->j.print(std::cerr);
}
int abstractBinding::id()const{
	return idcount;
}
int abstractBinding::idTotal()const{
	 return P->xs.c0 + Color_PosX_Total *(P->x.c0 + Color_PosX_Total *(P->ys.c0 + Color_PosY_Total *(P->y.c0 + Color_PosY_Total *(P->dxs.c0 + Color_VitX_Total *(P->dx.c0 + Color_VitX_Total *(P->dys.c0 + Color_VitY_Total *(P->dy.c0 + Color_VitY_Total *(P->ddx.c0 + Color_AccX_Total *(P->ddy.c0 + Color_AccY_Total *(P->j.c0 + Color_Jeton_Total *(0)))))))))));
}

void abstractBindingIteratorImpl::reset(abstractMarkingImpl& m) {

	ItPl_selfVehicle = m._PL_selfVehicle.tokens.begin();
	ItPl_simstep1 = m._PL_simstep1.tokens.begin();
	ItPl_simstep2 = m._PL_simstep2.tokens.begin();
	ItPl_simstep3 = m._PL_simstep3.tokens.begin();
	ItPl_simstep4 = m._PL_simstep4.tokens.begin();
	ItPl_initGenere = m._PL_initGenere.tokens.begin();
	ItPl_inProcess = m._PL_inProcess.tokens.begin();
	ItPl_otherVehicles = m._PL_otherVehicles.tokens.begin();
	ItPl_PositionMax = m._PL_PositionMax.tokens.begin();
	ItVar_xs = 0;
	IsDefItVar_xs = false;
	ItVar_x = 0;
	IsDefItVar_x = false;
	ItVar_ys = 0;
	IsDefItVar_ys = false;
	ItVar_y = 0;
	IsDefItVar_y = false;
	ItVar_dxs = 0;
	IsDefItVar_dxs = false;
	ItVar_dx = 0;
	IsDefItVar_dx = false;
	ItVar_dys = 0;
	IsDefItVar_dys = false;
	ItVar_dy = 0;
	IsDefItVar_dy = false;
	ItVar_ddx = 0;
	IsDefItVar_ddx = false;
	ItVar_ddy = 0;
	IsDefItVar_ddy = false;
	ItVar_j = 0;
	IsDefItVar_j = false;
	foundnint = true;
}

bool abstractBindingIteratorImpl::next(size_t& t, abstractMarkingImpl& m) {
	bool estCoherent = false;
	while ((not estCoherent) and foundnint) {
		foundnint = nextInterieur(t,m);
		estCoherent = isCoherent(t,m);
	}
	return estCoherent;	}
size_t abstractBindingIteratorImpl::getIndex() {
	size_t accum = 0;
	accum = ItVar_xs + ((size_t) Color_PosX_Total) * accum;
	accum = ItVar_x + ((size_t) Color_PosX_Total) * accum;
	accum = ItVar_ys + ((size_t) Color_PosY_Total) * accum;
	accum = ItVar_y + ((size_t) Color_PosY_Total) * accum;
	accum = ItVar_dxs + ((size_t) Color_VitX_Total) * accum;
	accum = ItVar_dx + ((size_t) Color_VitX_Total) * accum;
	accum = ItVar_dys + ((size_t) Color_VitY_Total) * accum;
	accum = ItVar_dy + ((size_t) Color_VitY_Total) * accum;
	accum = ItVar_ddx + ((size_t) Color_AccX_Total) * accum;
	accum = ItVar_ddy + ((size_t) Color_AccY_Total) * accum;
	accum = ItVar_j + ((size_t) Color_Jeton_Total) * accum;
return accum;
	}abstractBinding abstractBindingIteratorImpl::getBinding() {
abstractBinding newBind;
newBind.P->xs.c0 = (PosX_Color_Classe) ItVar_xs;
newBind.P->x.c0 = (PosX_Color_Classe) ItVar_x;
newBind.P->ys.c0 = (PosY_Color_Classe) ItVar_ys;
newBind.P->y.c0 = (PosY_Color_Classe) ItVar_y;
newBind.P->dxs.c0 = (VitX_Color_Classe) ItVar_dxs;
newBind.P->dx.c0 = (VitX_Color_Classe) ItVar_dx;
newBind.P->dys.c0 = (VitY_Color_Classe) ItVar_dys;
newBind.P->dy.c0 = (VitY_Color_Classe) ItVar_dy;
newBind.P->ddx.c0 = (AccX_Color_Classe) ItVar_ddx;
newBind.P->ddy.c0 = (AccY_Color_Classe) ItVar_ddy;
newBind.P->j.c0 = (Jeton_Color_Classe) ItVar_j;
	newBind.idcount = getIndex();
	return newBind;
}
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
const char *Color_PosX_names[Color_PosX_Total] = {
"PosX_IC_0","PosX_IC_1","PosX_IC_2","PosX_IC_3","PosX_IC_4","PosX_IC_5","PosX_IC_6","PosX_IC_7","PosX_IC_8","PosX_IC_9","PosX_IC_10","PosX_IC_11","PosX_IC_12","PosX_IC_13","PosX_IC_14","PosX_IC_15","PosX_IC_16","PosX_IC_17","PosX_IC_18","PosX_IC_19","PosX_IC_20","PosX_IC_21","PosX_IC_22","PosX_IC_23","PosX_IC_24","PosX_IC_25","PosX_IC_26","PosX_IC_27","PosX_IC_28","PosX_IC_29","PosX_IC_30","PosX_IC_31","PosX_IC_32","PosX_IC_33","PosX_IC_34","PosX_IC_35","PosX_IC_36","PosX_IC_37","PosX_IC_38","PosX_IC_39","PosX_IC_40","PosX_IC_41","PosX_IC_42","PosX_IC_43","PosX_IC_44","PosX_IC_45","PosX_IC_46","PosX_IC_47","PosX_IC_48","PosX_IC_49","PosX_IC_50","PosX_IC_51","PosX_IC_52","PosX_IC_53","PosX_IC_54","PosX_IC_55","PosX_IC_56","PosX_IC_57","PosX_IC_58","PosX_IC_59","PosX_IC_60","PosX_IC_61","PosX_IC_62","PosX_IC_63","PosX_IC_64","PosX_IC_65","PosX_IC_66","PosX_IC_67","PosX_IC_68","PosX_IC_69","PosX_IC_70","PosX_IC_71","PosX_IC_72","PosX_IC_73","PosX_IC_74","PosX_IC_75","PosX_IC_76","PosX_IC_77","PosX_IC_78","PosX_IC_79","PosX_IC_80","PosX_IC_81","PosX_IC_82","PosX_IC_83","PosX_IC_84","PosX_IC_85","PosX_IC_86","PosX_IC_87","PosX_IC_88","PosX_IC_89","PosX_IC_90","PosX_IC_91","PosX_IC_92","PosX_IC_93","PosX_IC_94","PosX_IC_95","PosX_IC_96","PosX_IC_97","PosX_IC_98","PosX_IC_99","PosX_IC_100","PosX_IC_101","PosX_IC_102","PosX_IC_103","PosX_IC_104","PosX_IC_105","PosX_IC_106","PosX_IC_107","PosX_IC_108","PosX_IC_109","PosX_IC_110","PosX_IC_111","PosX_IC_112","PosX_IC_113","PosX_IC_114","PosX_IC_115","PosX_IC_116","PosX_IC_117","PosX_IC_118","PosX_IC_119","PosX_IC_120","PosX_IC_121","PosX_IC_122","PosX_IC_123","PosX_IC_124","PosX_IC_125","PosX_IC_126","PosX_IC_127","PosX_IC_128","PosX_IC_129","PosX_IC_130","PosX_IC_131","PosX_IC_132","PosX_IC_133","PosX_IC_134","PosX_IC_135","PosX_IC_136","PosX_IC_137","PosX_IC_138","PosX_IC_139","PosX_IC_140","PosX_IC_141","PosX_IC_142","PosX_IC_143","PosX_IC_144","PosX_IC_145","PosX_IC_146","PosX_IC_147","PosX_IC_148","PosX_IC_149","PosX_IC_150","PosX_IC_151","PosX_IC_152","PosX_IC_153","PosX_IC_154","PosX_IC_155","PosX_IC_156","PosX_IC_157","PosX_IC_158","PosX_IC_159","PosX_IC_160","PosX_IC_161","PosX_IC_162","PosX_IC_163","PosX_IC_164","PosX_IC_165","PosX_IC_166","PosX_IC_167","PosX_IC_168","PosX_IC_169","PosX_IC_170","PosX_IC_171","PosX_IC_172","PosX_IC_173","PosX_IC_174","PosX_IC_175","PosX_IC_176","PosX_IC_177","PosX_IC_178","PosX_IC_179","PosX_IC_180","PosX_IC_181","PosX_IC_182","PosX_IC_183","PosX_IC_184","PosX_IC_185","PosX_IC_186","PosX_IC_187","PosX_IC_188","PosX_IC_189","PosX_IC_190","PosX_IC_191","PosX_IC_192","PosX_IC_193","PosX_IC_194","PosX_IC_195","PosX_IC_196","PosX_IC_197","PosX_IC_198","PosX_IC_199","PosX_IC_200","PosX_IC_201","PosX_IC_202","PosX_IC_203","PosX_IC_204","PosX_IC_205","PosX_IC_206","PosX_IC_207","PosX_IC_208","PosX_IC_209","PosX_IC_210","PosX_IC_211","PosX_IC_212","PosX_IC_213","PosX_IC_214","PosX_IC_215","PosX_IC_216","PosX_IC_217","PosX_IC_218","PosX_IC_219","PosX_IC_220","PosX_IC_221","PosX_IC_222","PosX_IC_223","PosX_IC_224","PosX_IC_225","PosX_IC_226","PosX_IC_227","PosX_IC_228","PosX_IC_229","PosX_IC_230","PosX_IC_231","PosX_IC_232","PosX_IC_233","PosX_IC_234","PosX_IC_235","PosX_IC_236","PosX_IC_237","PosX_IC_238","PosX_IC_239","PosX_IC_240","PosX_IC_241","PosX_IC_242","PosX_IC_243","PosX_IC_244","PosX_IC_245","PosX_IC_246","PosX_IC_247","PosX_IC_248","PosX_IC_249","PosX_IC_250","PosX_IC_251","PosX_IC_252","PosX_IC_253","PosX_IC_254","PosX_IC_255","PosX_IC_256","PosX_IC_257","PosX_IC_258","PosX_IC_259","PosX_IC_260","PosX_IC_261","PosX_IC_262","PosX_IC_263","PosX_IC_264","PosX_IC_265","PosX_IC_266","PosX_IC_267","PosX_IC_268","PosX_IC_269","PosX_IC_270","PosX_IC_271","PosX_IC_272","PosX_IC_273","PosX_IC_274","PosX_IC_275","PosX_IC_276","PosX_IC_277","PosX_IC_278","PosX_IC_279","PosX_IC_280","PosX_IC_281","PosX_IC_282","PosX_IC_283","PosX_IC_284","PosX_IC_285","PosX_IC_286","PosX_IC_287","PosX_IC_288","PosX_IC_289","PosX_IC_290","PosX_IC_291","PosX_IC_292","PosX_IC_293","PosX_IC_294","PosX_IC_295","PosX_IC_296","PosX_IC_297","PosX_IC_298","PosX_IC_299","PosX_IC_300","PosX_IC_301","PosX_IC_302","PosX_IC_303","PosX_IC_304","PosX_IC_305","PosX_IC_306","PosX_IC_307","PosX_IC_308","PosX_IC_309","PosX_IC_310","PosX_IC_311","PosX_IC_312","PosX_IC_313","PosX_IC_314","PosX_IC_315","PosX_IC_316","PosX_IC_317","PosX_IC_318","PosX_IC_319","PosX_IC_320","PosX_IC_321","PosX_IC_322","PosX_IC_323","PosX_IC_324","PosX_IC_325","PosX_IC_326","PosX_IC_327","PosX_IC_328","PosX_IC_329","PosX_IC_330","PosX_IC_331","PosX_IC_332","PosX_IC_333","PosX_IC_334","PosX_IC_335","PosX_IC_336","PosX_IC_337","PosX_IC_338","PosX_IC_339","PosX_IC_340","PosX_IC_341","PosX_IC_342","PosX_IC_343","PosX_IC_344","PosX_IC_345","PosX_IC_346","PosX_IC_347","PosX_IC_348","PosX_IC_349","PosX_IC_350","PosX_IC_351","PosX_IC_352","PosX_IC_353","PosX_IC_354","PosX_IC_355","PosX_IC_356","PosX_IC_357","PosX_IC_358","PosX_IC_359","PosX_IC_360","PosX_IC_361","PosX_IC_362","PosX_IC_363","PosX_IC_364","PosX_IC_365","PosX_IC_366","PosX_IC_367","PosX_IC_368","PosX_IC_369","PosX_IC_370","PosX_IC_371","PosX_IC_372","PosX_IC_373","PosX_IC_374","PosX_IC_375","PosX_IC_376","PosX_IC_377","PosX_IC_378","PosX_IC_379","PosX_IC_380","PosX_IC_381","PosX_IC_382","PosX_IC_383","PosX_IC_384","PosX_IC_385","PosX_IC_386","PosX_IC_387","PosX_IC_388","PosX_IC_389","PosX_IC_390","PosX_IC_391","PosX_IC_392","PosX_IC_393","PosX_IC_394","PosX_IC_395","PosX_IC_396","PosX_IC_397","PosX_IC_398","PosX_IC_399","PosX_IC_400","PosX_IC_401","PosX_IC_402","PosX_IC_403","PosX_IC_404","PosX_IC_405","PosX_IC_406","PosX_IC_407","PosX_IC_408","PosX_IC_409","PosX_IC_410","PosX_IC_411","PosX_IC_412","PosX_IC_413","PosX_IC_414","PosX_IC_415","PosX_IC_416","PosX_IC_417","PosX_IC_418","PosX_IC_419","PosX_IC_420","PosX_IC_421","PosX_IC_422","PosX_IC_423","PosX_IC_424","PosX_IC_425","PosX_IC_426","PosX_IC_427","PosX_IC_428","PosX_IC_429","PosX_IC_430","PosX_IC_431","PosX_IC_432","PosX_IC_433","PosX_IC_434","PosX_IC_435","PosX_IC_436","PosX_IC_437","PosX_IC_438","PosX_IC_439","PosX_IC_440","PosX_IC_441","PosX_IC_442","PosX_IC_443","PosX_IC_444","PosX_IC_445","PosX_IC_446","PosX_IC_447","PosX_IC_448","PosX_IC_449","PosX_IC_450","PosX_IC_451","PosX_IC_452","PosX_IC_453","PosX_IC_454","PosX_IC_455","PosX_IC_456","PosX_IC_457","PosX_IC_458","PosX_IC_459","PosX_IC_460","PosX_IC_461","PosX_IC_462","PosX_IC_463","PosX_IC_464","PosX_IC_465","PosX_IC_466","PosX_IC_467","PosX_IC_468","PosX_IC_469","PosX_IC_470","PosX_IC_471","PosX_IC_472","PosX_IC_473","PosX_IC_474","PosX_IC_475","PosX_IC_476","PosX_IC_477","PosX_IC_478","PosX_IC_479","PosX_IC_480","PosX_IC_481","PosX_IC_482","PosX_IC_483","PosX_IC_484","PosX_IC_485","PosX_IC_486","PosX_IC_487","PosX_IC_488","PosX_IC_489","PosX_IC_490","PosX_IC_491","PosX_IC_492","PosX_IC_493","PosX_IC_494","PosX_IC_495","PosX_IC_496","PosX_IC_497","PosX_IC_498","PosX_IC_499","PosX_IC_500",
};
const char *Color_PosY_names[Color_PosY_Total] = {
"PosY_IC_0","PosY_IC_1",
};
const char *Color_VitX_names[Color_VitX_Total] = {
"VitX_IC_0","VitX_IC_1","VitX_IC_2",
};
const char *Color_VitY_names[Color_VitY_Total] = {
"VitY_IC_0","VitY_IC_1",
};
const char *Color_AccX_names[Color_AccX_Total] = {
"AccX_IC_0","AccX_IC_1",
};
const char *Color_AccY_names[Color_AccY_Total] = {
"AccY_IC_0","AccY_IC_1",
};
const char *Color_Jeton_names[Color_Jeton_Total] = {
"Jeton_IC_1",
};
static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_0[4]= {TR_lightController_RT, TR_end_RT, TR_collision_RT, -1 }; /* updateSelf*/
static const int PE_PossiblyEnabled_1[4]= {TR_updateSelf_RT, TR_end_RT, TR_collision_RT, -1 }; /* lightController*/
static const int PE_PossiblyEnabled_2[4]= {TR_simstepB_RT, TR_randOther_RT, TR_generationInitiale_RT, -1 }; /* simstepA*/
static const int PE_PossiblyEnabled_3[3]= {TR_simstepC_RT, TR_updOther_RT, -1 }; /* simstepB*/
static const int PE_PossiblyEnabled_4[2]= {TR_updateSelf_RT, -1 }; /* simstepC*/
static const int PE_PossiblyEnabled_5[3]= {TR_simstepB_RT, TR_updOther_RT, -1 }; /* randOther*/
static const int PE_PossiblyEnabled_6[5]= {TR_simstepC_RT, TR_randOther_RT, TR_exit_RT, TR_collision_RT, -1 }; /* updOther*/
static const int PE_PossiblyEnabled_7[2]= {TR_simstepA_RT, -1 }; /* generationInitiale*/
static const int PE_PossiblyEnabled_11[4]= {TR_randOther_RT, TR_exit_RT, TR_collision_RT, -1 }; /* enter*/
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, PE_PossiblyEnabled_2, PE_PossiblyEnabled_3, PE_PossiblyEnabled_4, PE_PossiblyEnabled_5, PE_PossiblyEnabled_6, PE_PossiblyEnabled_7, EMPTY_array, EMPTY_array, EMPTY_array, PE_PossiblyEnabled_11};

static const int PE_PossiblyDisabled_0[4]= {TR_lightController_RT, TR_end_RT, TR_collision_RT, -1 }; /* updateSelf*/
static const int PE_PossiblyDisabled_1[4]= {TR_updateSelf_RT, TR_end_RT, TR_collision_RT, -1 }; /* lightController*/
static const int PE_PossiblyDisabled_2[2]= {TR_generationInitiale_RT, -1 }; /* simstepA*/
static const int PE_PossiblyDisabled_3[2]= {TR_randOther_RT, -1 }; /* simstepB*/
static const int PE_PossiblyDisabled_4[2]= {TR_updOther_RT, -1 }; /* simstepC*/
static const int PE_PossiblyDisabled_5[4]= {TR_simstepB_RT, TR_exit_RT, TR_collision_RT, -1 }; /* randOther*/
static const int PE_PossiblyDisabled_6[2]= {TR_simstepC_RT, -1 }; /* updOther*/
static const int PE_PossiblyDisabled_8[4]= {TR_randOther_RT, TR_end_RT, TR_collision_RT, -1 }; /* exit*/
static const int PE_PossiblyDisabled_9[5]= {TR_updateSelf_RT, TR_lightController_RT, TR_exit_RT, TR_collision_RT, -1 }; /* end*/
static const int PE_PossiblyDisabled_10[6]= {TR_updateSelf_RT, TR_lightController_RT, TR_randOther_RT, TR_exit_RT, TR_end_RT, -1 }; /* collision*/
const int* SPN::PossiblyDisabled[] = {PE_PossiblyDisabled_0, PE_PossiblyDisabled_1, PE_PossiblyDisabled_2, PE_PossiblyDisabled_3, PE_PossiblyDisabled_4, PE_PossiblyDisabled_5, PE_PossiblyDisabled_6, EMPTY_array, PE_PossiblyDisabled_8, PE_PossiblyDisabled_9, PE_PossiblyDisabled_10, EMPTY_array};

const int* SPN::FreeMarkDepT[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

static spn_trans TransArray[12] = { _trans(0,DETERMINISTIC,0,1, 0), _trans(1,DETERMINISTIC,0,1, 0), _trans(2,UNIFORM,0,1, 0), _trans(3,DETERMINISTIC,0,1, 0), _trans(4,DETERMINISTIC,0,1, 0), _trans(5,DETERMINISTIC,0,1, 0), _trans(6,DETERMINISTIC,0,1, 0), _trans(7,DETERMINISTIC,0,1, 0), _trans(8,DETERMINISTIC,0,1, 0), _trans(9,DETERMINISTIC,0,1, 0), _trans(10,DETERMINISTIC,0,1, 0), _trans(11,UNIFORM,0,1, 0),  }; 
SPN::SPN():
customDistr(*(new CustomDistr())),pl(10), tr(12) ,Transition(TransArray,TransArray +12),Place(10),ParamDistr(),TransitionConditions(12,0){
    Path ="moded_CoSimulation.grml";
}

bool SPN::IsEnabled(TR_PL_ID t, const abstractBinding &b)const{
	if(!magicConditional(t))return false;

	switch (t){
		case 2:	//simstepA

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_initGenere , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 5:	//randOther

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep1 , ((Jeton_Token(b.P->j)))))) return false;
			if ( !(((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy))) < 1)) 
			if (!(contains(Marking.P->_PL_otherVehicles , ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)))))) return false;
		return true;
		break;
		case 3:	//simstepB

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep1 , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 6:	//updOther

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep2 , ((Jeton_Token(b.P->j)))))) return false;
			if ( !(((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy))) < 1)) 
			if (!(contains(Marking.P->_PL_inProcess , ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)))))) return false;
		return true;
		break;
		case 4:	//simstepC

			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep2 , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 0:	//updateSelf

			if ( !(((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy))) < 1)) 
			if (!(contains(Marking.P->_PL_selfVehicle , ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)))))) return false;
			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep3 , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 1:	//lightController

			if ( !(((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy))) < 1)) 
			if (!(contains(Marking.P->_PL_selfVehicle , ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)))))) return false;
			if ( !(((Jeton_Token(b.P->j))) < 1)) 
			if (!(contains(Marking.P->_PL_simstep4 , ((Jeton_Token(b.P->j)))))) return false;
		return true;
		break;
		case 9:	//end

			if ( !(((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy))) < 1)) 
			if (!(contains(Marking.P->_PL_selfVehicle , ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)))))) return false;
			if ( !(((PosX_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_PositionMax , ((PosX_Token(b.P->x)))))) return false;
		return true;
		break;
		case 10:	//collision

			if ( !(((SelfVehicle_Token(b.P->x, b.P->y, b.P->dxs, b.P->dys, b.P->ddx, b.P->ddy))) < 1)) 
			if (!(contains(Marking.P->_PL_selfVehicle , ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dxs, b.P->dys, b.P->ddx, b.P->ddy)))))) return false;
			if ( !(((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy))) < 1)) 
			if (!(contains(Marking.P->_PL_otherVehicles , ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)))))) return false;
		return true;
		break;
		case 8:	//exit

			if ( !(((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy))) < 1)) 
			if (!(contains(Marking.P->_PL_otherVehicles , ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)))))) return false;
			if ( !(((PosX_Token(b.P->x))) < 1)) 
			if (!(contains(Marking.P->_PL_PositionMax , ((PosX_Token(b.P->x)))))) return false;
		return true;
		break;
		case 11:	//enter

		return true;
		break;
		case 7:	//generationInitiale

    if ( !(((Jeton_Token(b.P->j))) < 1) ) 
        if (contains(Marking.P->_PL_initGenere , ((Jeton_Token(b.P->j))))) return false;
		return true;
		break;
	}
}

void SPN::fire(TR_PL_ID t, const abstractBinding &b,REAL_TYPE time){
	lastTransition = t;
	magicUpdate(t,time);

	switch (t){
		case 7:	//generationInitiale
{
			Jeton_Domain tmpMark_initGenere = Marking.P->_PL_initGenere;
			Marking.P->_PL_initGenere += ((Jeton_Token(b.P->j)));
{using namespace hybridVar;
int vit; int pos; int voie;
       Marking.P->_PL_selfVehicle += (( SelfVehicle_Token( (PosX_Color_Classe) 0, (PosY_Color_Classe) 0, (VitX_Color_Classe) 1, (VitY_Color_Classe) 0, (AccX_Color_Classe) 0, (AccY_Color_Classe) 0) * (1)));
       for (int i=0;i < nVeh;i++) {
       vit = rand() % vMax; pos = (rand() % 15)+1; voie = rand() % nVoies;
       Marking.P->_PL_otherVehicles += (( Vehicle_Token( (PosX_Color_Classe) pos, (PosY_Color_Classe) voie, (VitX_Color_Classe) vit, (VitY_Color_Classe) 0) * (1)));
       }
       for (int i=1;i <4;i++) { // le 4 est temporaire et doit être remplacé par VitX _ max
          Marking.P->_PL_PositionMax += ( PosX_Token( (PosX_Color_Classe) (Color_PosX_Total - i)));
       }}
	}
		break;
		case 2:	//simstepA
{
			Jeton_Domain tmpMark_simstep1 = Marking.P->_PL_simstep1;
			Jeton_Domain tmpMark_initGenere = Marking.P->_PL_initGenere;
			Marking.P->_PL_simstep1 += ((Jeton_Token(b.P->j)));
			Marking.P->_PL_initGenere -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_initGenere += ((Jeton_Token(b.P->j)));
	}
		break;
		case 3:	//simstepB
{
			Jeton_Domain tmpMark_simstep1 = Marking.P->_PL_simstep1;
			Jeton_Domain tmpMark_simstep2 = Marking.P->_PL_simstep2;
			Marking.P->_PL_simstep1 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep2 += ((Jeton_Token(b.P->j)));
	}
		break;
		case 5:	//randOther
{
			Jeton_Domain tmpMark_simstep1 = Marking.P->_PL_simstep1;
			Vehicle_Domain tmpMark_inProcess = Marking.P->_PL_inProcess;
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			Marking.P->_PL_simstep1 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep1 += ((Jeton_Token(b.P->j)));
			Marking.P->_PL_inProcess += ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
			Marking.P->_PL_otherVehicles -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
{using namespace hybridVar;
int position = (int) (b.P->x).c0;
      int vitesse = (int) (b.P->dx).c0;
      int chgtvoie = rand() % 30;
      int voie = (int) (b.P->y).c0;
      if (chgtvoie == 1) { voie = 1 - voie; }
      position = position + vitesse;
      Marking.P->_PL_inProcess -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy) * (1 )));;
      Marking.P->_PL_inProcess += ((Vehicle_Token( (PosX_Color_Classe) position, (PosY_Color_Classe) voie, b.P->dx, b.P->dy) * (1 )));}
	}
		break;
		case 4:	//simstepC
{
			Jeton_Domain tmpMark_simstep2 = Marking.P->_PL_simstep2;
			Jeton_Domain tmpMark_simstep3 = Marking.P->_PL_simstep3;
			Marking.P->_PL_simstep2 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep3 += ((Jeton_Token(b.P->j)));
	}
		break;
		case 6:	//updOther
{
			Jeton_Domain tmpMark_simstep2 = Marking.P->_PL_simstep2;
			Vehicle_Domain tmpMark_inProcess = Marking.P->_PL_inProcess;
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			Marking.P->_PL_simstep2 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep2 += ((Jeton_Token(b.P->j)));
			Marking.P->_PL_inProcess -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
			Marking.P->_PL_otherVehicles += ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
	}
		break;
		case 0:	//updateSelf
{
			SelfVehicle_Domain tmpMark_selfVehicle = Marking.P->_PL_selfVehicle;
			Jeton_Domain tmpMark_simstep3 = Marking.P->_PL_simstep3;
			Jeton_Domain tmpMark_simstep4 = Marking.P->_PL_simstep4;
			Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_selfVehicle += ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_simstep3 -= ((Jeton_Token(b.P->j)));
			Marking.P->_PL_simstep4 += ((Jeton_Token(b.P->j)));
{using namespace hybridVar;
int position = (int) (b.P->x).c0;
      int vitesse = (int) (b.P->dx).c0;
      position = min(position + vitesse,(Color_PosX_Total - 1));
      Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy) * (1 )));
      Marking.P->_PL_selfVehicle += ((SelfVehicle_Token( (PosX_Color_Classe) position, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy) * (1 )));}
	}
		break;
		case 1:	//lightController
{
			SelfVehicle_Domain tmpMark_selfVehicle = Marking.P->_PL_selfVehicle;
			Jeton_Domain tmpMark_simstep4 = Marking.P->_PL_simstep4;
			Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_selfVehicle += ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_simstep4 -= ((Jeton_Token(b.P->j)));
{using namespace hybridVar;
SelfVehicle_Token monvehicule;
      monvehicule = (SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy));
      int px = (int) (b.P->x).c0;
      int py = (int) (b.P->y).c0;
      int vx = (int) (b.P->dx).c0;
      int vy = (int) (b.P->dy).c0;
      int ax = (int) (b.P->ddx).c0;
      int ay = (int) (b.P->ddy).c0;

      int vehMax = (Vmax + 2)*(Nvoies + 1) + Vmax;
      int vehVus = 0;
      radarData donnees = new othVehicle[vehMax];

      bool devant = false;
      int posdev = Color_PosX_Total; int vitdev = 0;

      // Ancienne version de la boucle :

      int dbx=max(0,px-1); int fbx=max((int) px+2*vMax,(int) Color_PosX_Total);
      int dby=max(0,py-1); int fby=max((int) py+1,(int) Color_PosY_Total);
      for (int i0=dbx;i0 < fbx;i0++) {
        if (i0>px+vMax) { dby=py; fby=py; }
        for (int i1=dby;i1 < fby;i1++) {
          for (int i2=0;i2 < (int) Color_VitX_Total;i2++) {
            for (int i3=0;i3 < (int) Color_VitY_Total;i3++) {
              if (contains(Marking.P->_PL_otherVehicles, ((Vehicle_Token( (PosX_Color_Classe) i0, (PosY_Color_Classe) i1, (VitX_Color_Classe) i2, (VitY_Color_Classe) i3) * (1))))) {
                othVehicle vehiculevu = {i0, i1, i2, i3};
                donnees[vehVus] = vehiculevu;
                vehVus++;
              }
            }
          }
        }
      }


      egoVehicle ego = {px, py, vx, vy, ax, ay};
      egoVehicle nouvpos = controller(vehVus, donnees, ego);

      Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy) * (1 )));
      Marking.P->_PL_selfVehicle += ((SelfVehicle_Token( (PosX_Color_Classe) nouvpos.px, (PosY_Color_Classe) nouvpos.py, (VitX_Color_Classe) nouvpos.vx, (VitY_Color_Classe) nouvpos.vy, (AccX_Color_Classe) nouvpos.ax, (AccY_Color_Classe) nouvpos.ay) * (1)));}
	}
		break;
		case 10:	//collision
{
			SelfVehicle_Domain tmpMark_selfVehicle = Marking.P->_PL_selfVehicle;
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			int tmpMark_PosFinale = Marking.P->_PL_PosFinale;
			Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dxs, b.P->dys, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_otherVehicles -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
			Marking.P->_PL_PosFinale += 1 ;
{using namespace hybridVar;
Marking.P->_PL_PosFinale -= 1;
      int position = (int) (b.P->x).c0;
      Marking.P->_PL_PosFinale += position;}
	}
		break;
		case 9:	//end
{
			SelfVehicle_Domain tmpMark_selfVehicle = Marking.P->_PL_selfVehicle;
			int tmpMark_PosFinale = Marking.P->_PL_PosFinale;
			PosX_Domain tmpMark_PositionMax = Marking.P->_PL_PositionMax;
			Marking.P->_PL_selfVehicle -= ((SelfVehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy, b.P->ddx, b.P->ddy)));
			Marking.P->_PL_PosFinale += 1 ;
			Marking.P->_PL_PositionMax -= ((PosX_Token(b.P->x)));
{using namespace hybridVar;
Marking.P->_PL_PosFinale -= 1;
      int position = (int) (b.P->x).c0;
      Marking.P->_PL_PosFinale += position;}
	}
		break;
		case 11:	//enter
{
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			Marking.P->_PL_otherVehicles += 1 ;
{using namespace hybridVar;
/* Marking.P->_PL_otherVehicles -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy) * (1 )));; */
       int vit; int pos; int voie;
       vit = rand() % 2; pos = (rand() % 2)+1; voie = rand() % 2;
       if (mkNew > 0) { // On ne génère de nouveaux véhicules que si … on a le droit d'en générer !
       Marking.P->_PL_otherVehicles += (( Vehicle_Token( (PosX_Color_Classe) pos, (PosY_Color_Classe) voie, (VitX_Color_Classe) vit, (VitY_Color_Classe) 0) * (1)));
       }}
	}
		break;
		case 8:	//exit
{
			Vehicle_Domain tmpMark_otherVehicles = Marking.P->_PL_otherVehicles;
			PosX_Domain tmpMark_PositionMax = Marking.P->_PL_PositionMax;
			Marking.P->_PL_otherVehicles -= ((Vehicle_Token(b.P->x, b.P->y, b.P->dx, b.P->dy)));
			Marking.P->_PL_PositionMax -= ((PosX_Token(b.P->x)));
{using namespace hybridVar;
int position = (int) (b.P->x).c0;
      Marking.P->_PL_PositionMax += ( PosX_Token( (PosX_Color_Classe) position ) );}
	}
		break;
	}
}

void SPN::unfire(TR_PL_ID t, const abstractBinding &b){


}

const abstractBinding* SPN::nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
		assert(false);
}
const abstractBinding* SPN::nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {
		assert(false);
}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

	switch (t){
		case 2:	//simstepA
	{
		ParamDistr[0]= ( double ) 1 ;
		ParamDistr[1]= ( double ) 1 ;
	}

		break;
		case 11:	//enter
	{
		ParamDistr[0]= ( double ) 50 ;
		ParamDistr[1]= ( double ) 100 ;
	}

		break;
		default:	//updateSelf,lightController,simstepB,simstepC,randOther,updOther,generationInitiale,exit,end,collision,
	{
		ParamDistr[0]= ( double ) 0 ;
	}

		break;
	}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t, const abstractBinding &b)const{
using namespace hybridVar;

	switch (t){
		case 9:	//end
		case 10:	//collision
		return (double)10 ;
		break;
		case 0:	//updateSelf
		case 5:	//randOther
		case 6:	//updOther
		case 8:	//exit
		return (double)2 ;
		break;
		default:	//lightController,simstepA,simstepB,simstepC,generationInitiale,enter,
		return (double)1 ;
		break;
	}
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

