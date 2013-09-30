#include "spn.hpp"
	const double N=1;
	const double k1=1;
	const double k10=3.3;
	const double k11=0.4;
	const double k12=0.1;
	const double k13=10;
	const double k14=0.8;
	const double k15=0.1;
	const double k16=10;
	const double k17=0.8;
	const double k18=0.1;
	const double k19=20;
	const double k2=0.4;
	const double k20=0.6;
	const double k21=0.1;
	const double k22=20;
	const double k23=0.6;
	const double k24=0.1;
	const double k25=5;
	const double k26=0.4;
	const double k27=0.1;
	const double k28=5;
	const double k29=0.4;
	const double k3=0.1;
	const double k30=0.1;
	const double k4=0.5;
	const double k5=0.5;
	const double k6=0.1;
	const double k7=3.3;
	const double k8=0.42;
	const double k9=0.1;
	const int _nb_Place_RE_ERK=0;
	const int _nb_Place_ERKPP_Phase3=1;
	const int _nb_Place_RasGTP=2;
	const int _nb_Place_RE_ERK_MEKPF=3;
	const int _nb_Place_RE_Raf=4;
	const int _nb_Place_RE_Raf_RasGTP=5;
	const int _nb_Place_RE_ERKPP=6;
	const int _nb_Place_RE_RafP=7;
	const int _nb_Place_RafP_Phase1=8;
	const int _nb_Place_Phase1=9;
	const int _nb_Place_Phase3=10;
	const int _nb_Place_RE_ERKP=11;
	const int _nb_Place_RE_MEK=12;
	const int _nb_Place_ERKP_Phase3=13;
	const int _nb_Place_RE_ERKP_MEKPP=14;
	const int _nb_Place_RE_MEK_RafP=15;
	const int _nb_Place_MEKP_Phase2=16;
	const int _nb_Place_RE_MEKP=17;
	const int _nb_Place_MEKPP_Phase2=18;
	const int _nb_Place_RE_MEKPP=19;
	const int _nb_Place_Phase2=20;
	const int _nb_Place_RE_MEKP_RafP=21;
	const int _nb_Place_Puit=22;
#include "lumpingfun.cpp"
#include <iostream>
#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_RE_ERK =3;
	P->_PL_ERKPP_Phase3 =0;
	P->_PL_RasGTP =1;
	P->_PL_RE_ERK_MEKPF =0;
	P->_PL_RE_Raf =4;
	P->_PL_RE_Raf_RasGTP =0;
	P->_PL_RE_ERKPP =0;
	P->_PL_RE_RafP =0;
	P->_PL_RafP_Phase1 =0;
	P->_PL_Phase1 =3;
	P->_PL_Phase3 =3;
	P->_PL_RE_ERKP =0;
	P->_PL_RE_MEK =2;
	P->_PL_ERKP_Phase3 =0;
	P->_PL_RE_ERKP_MEKPP =0;
	P->_PL_RE_MEK_RafP =0;
	P->_PL_MEKP_Phase2 =0;
	P->_PL_RE_MEKP =0;
	P->_PL_MEKPP_Phase2 =0;
	P->_PL_RE_MEKPP =0;
	P->_PL_Phase2 =2;
	P->_PL_RE_MEKP_RafP =0;
	P->_PL_Puit =0;
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

void abstractMarking::printHeader(ostream &s)const{
	s << "RE_ERK	ERKPP_Phase3	RasGTP	RE_ERK_MEKPF	RE_Raf	RE_Raf_RasGTP	RE_ERKPP	RE_RafP	RafP_Phase1	Phase1	Phase3	RE_ERKP	RE_MEK	ERKP_Phase3	RE_ERKP_MEKPP	RE_MEK_RafP	MEKP_Phase2	RE_MEKP	MEKPP_Phase2	RE_MEKPP	Phase2	RE_MEKP_RafP	Puit	";}

void abstractMarking::print(ostream &s)const{
	s << P->_PL_RE_ERK << "\t" ;
	s << P->_PL_ERKPP_Phase3 << "\t" ;
	s << P->_PL_RasGTP << "\t" ;
	s << P->_PL_RE_ERK_MEKPF << "\t" ;
	s << P->_PL_RE_Raf << "\t" ;
	s << P->_PL_RE_Raf_RasGTP << "\t" ;
	s << P->_PL_RE_ERKPP << "\t" ;
	s << P->_PL_RE_RafP << "\t" ;
	s << P->_PL_RafP_Phase1 << "\t" ;
	s << P->_PL_Phase1 << "\t" ;
	s << P->_PL_Phase3 << "\t" ;
	s << P->_PL_RE_ERKP << "\t" ;
	s << P->_PL_RE_MEK << "\t" ;
	s << P->_PL_ERKP_Phase3 << "\t" ;
	s << P->_PL_RE_ERKP_MEKPP << "\t" ;
	s << P->_PL_RE_MEK_RafP << "\t" ;
	s << P->_PL_MEKP_Phase2 << "\t" ;
	s << P->_PL_RE_MEKP << "\t" ;
	s << P->_PL_MEKPP_Phase2 << "\t" ;
	s << P->_PL_RE_MEKPP << "\t" ;
	s << P->_PL_Phase2 << "\t" ;
	s << P->_PL_RE_MEKP_RafP << "\t" ;
	s << P->_PL_Puit << "\t" ;
}

int abstractMarking::getNbOfTokens(int p)const {
	switch (p) {
		case 0: return P->_PL_RE_ERK;
		case 1: return P->_PL_ERKPP_Phase3;
		case 2: return P->_PL_RasGTP;
		case 3: return P->_PL_RE_ERK_MEKPF;
		case 4: return P->_PL_RE_Raf;
		case 5: return P->_PL_RE_Raf_RasGTP;
		case 6: return P->_PL_RE_ERKPP;
		case 7: return P->_PL_RE_RafP;
		case 8: return P->_PL_RafP_Phase1;
		case 9: return P->_PL_Phase1;
		case 10: return P->_PL_Phase3;
		case 11: return P->_PL_RE_ERKP;
		case 12: return P->_PL_RE_MEK;
		case 13: return P->_PL_ERKP_Phase3;
		case 14: return P->_PL_RE_ERKP_MEKPP;
		case 15: return P->_PL_RE_MEK_RafP;
		case 16: return P->_PL_MEKP_Phase2;
		case 17: return P->_PL_RE_MEKP;
		case 18: return P->_PL_MEKPP_Phase2;
		case 19: return P->_PL_RE_MEKPP;
		case 20: return P->_PL_Phase2;
		case 21: return P->_PL_RE_MEKP_RafP;
		case 22: return P->_PL_Puit;
     }
}

std::vector<int> abstractMarking::getVector()const {
	std::vector<int> v(23);
	v[0] = P->_PL_RE_ERK;
	v[1] = P->_PL_ERKPP_Phase3;
	v[2] = P->_PL_RasGTP;
	v[3] = P->_PL_RE_ERK_MEKPF;
	v[4] = P->_PL_RE_Raf;
	v[5] = P->_PL_RE_Raf_RasGTP;
	v[6] = P->_PL_RE_ERKPP;
	v[7] = P->_PL_RE_RafP;
	v[8] = P->_PL_RafP_Phase1;
	v[9] = P->_PL_Phase1;
	v[10] = P->_PL_Phase3;
	v[11] = P->_PL_RE_ERKP;
	v[12] = P->_PL_RE_MEK;
	v[13] = P->_PL_ERKP_Phase3;
	v[14] = P->_PL_RE_ERKP_MEKPP;
	v[15] = P->_PL_RE_MEK_RafP;
	v[16] = P->_PL_MEKP_Phase2;
	v[17] = P->_PL_RE_MEKP;
	v[18] = P->_PL_MEKPP_Phase2;
	v[19] = P->_PL_RE_MEKPP;
	v[20] = P->_PL_Phase2;
	v[21] = P->_PL_RE_MEKP_RafP;
	v[22] = P->_PL_Puit;
     return v;
}

void abstractMarking::setVector(const std::vector<int>&v) {
	P->_PL_RE_ERK = v[0];
	P->_PL_ERKPP_Phase3 = v[1];
	P->_PL_RasGTP = v[2];
	P->_PL_RE_ERK_MEKPF = v[3];
	P->_PL_RE_Raf = v[4];
	P->_PL_RE_Raf_RasGTP = v[5];
	P->_PL_RE_ERKPP = v[6];
	P->_PL_RE_RafP = v[7];
	P->_PL_RafP_Phase1 = v[8];
	P->_PL_Phase1 = v[9];
	P->_PL_Phase3 = v[10];
	P->_PL_RE_ERKP = v[11];
	P->_PL_RE_MEK = v[12];
	P->_PL_ERKP_Phase3 = v[13];
	P->_PL_RE_ERKP_MEKPP = v[14];
	P->_PL_RE_MEK_RafP = v[15];
	P->_PL_MEKP_Phase2 = v[16];
	P->_PL_RE_MEKP = v[17];
	P->_PL_MEKPP_Phase2 = v[18];
	P->_PL_RE_MEKPP = v[19];
	P->_PL_Phase2 = v[20];
	P->_PL_RE_MEKP_RafP = v[21];
	P->_PL_Puit = v[22];
};

bool abstractBinding::next() {
	idcount++;
	return false;
};
abstractBinding::abstractBinding() {
       idcount=0;
}
abstractBinding::abstractBinding(const abstractBinding& m) {
	idcount = m.idcount;
}
abstractBinding::~abstractBinding() {
}
abstractBinding& abstractBinding::operator = (const abstractBinding& m) {
	idcount = m.idcount;
       return *this;
}
void abstractBinding::print()const{
}
int abstractBinding::id()const{
	return idcount;
}
int abstractBinding::idTotal()const{
	 return 0;
}
SPN::SPN():
pl(23), tr(32), Place(23),Transition(32),ParamDistr(3), TransitionConditions(32,0){
    Path ="MAPK_RE";
	PossiblyEnabled = vector< set<int> >(32);
	{
		int PE[]= {3, 7, 8};
		PossiblyEnabled[0] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {7, 8, 13};
		PossiblyEnabled[1] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {3, 8, 13, 28};
		PossiblyEnabled[2] = set<int>(PE,PE+4);
	}
	PossiblyEnabled[3].insert( 2 );
	PossiblyEnabled[3].insert( 11 );
	PossiblyEnabled[4].insert( 5 );
	PossiblyEnabled[4].insert( 6 );
	{
		int PE[]= {4, 12, 21, 27};
		PossiblyEnabled[5] = set<int>(PE,PE+4);
	}
	PossiblyEnabled[6].insert( 4 );
	PossiblyEnabled[7].insert( 0 );
	PossiblyEnabled[7].insert( 1 );
	PossiblyEnabled[8].insert( 16 );
	PossiblyEnabled[8].insert( 17 );
	PossiblyEnabled[9].insert( 4 );
	PossiblyEnabled[9].insert( 12 );
	{
		int PE[]= {12, 21, 27};
		PossiblyEnabled[10] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {3, 7, 13, 28};
		PossiblyEnabled[11] = set<int>(PE,PE+4);
	}
	PossiblyEnabled[12].insert( 9 );
	PossiblyEnabled[12].insert( 10 );
	PossiblyEnabled[13].insert( 14 );
	PossiblyEnabled[13].insert( 15 );
	{
		int PE[]= {3, 13, 28};
		PossiblyEnabled[14] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {3, 7, 13, 28};
		PossiblyEnabled[15] = set<int>(PE,PE+4);
	}
	{
		int PE[]= {3, 7, 8};
		PossiblyEnabled[16] = set<int>(PE,PE+3);
	}
	PossiblyEnabled[17].insert( 7 );
	PossiblyEnabled[17].insert( 8 );
	{
		int PE[]= {21, 23, 28};
		PossiblyEnabled[18] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {12, 21, 27};
		PossiblyEnabled[19] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {23, 27, 28};
		PossiblyEnabled[20] = set<int>(PE,PE+3);
	}
	PossiblyEnabled[21].insert( 19 );
	PossiblyEnabled[21].insert( 22 );
	{
		int PE[]= {12, 21, 23, 27};
		PossiblyEnabled[22] = set<int>(PE,PE+4);
	}
	PossiblyEnabled[23].insert( 18 );
	PossiblyEnabled[23].insert( 20 );
	{
		int PE[]= {23, 27, 28};
		PossiblyEnabled[24] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {12, 21, 23, 27};
		PossiblyEnabled[25] = set<int>(PE,PE+4);
	}
	{
		int PE[]= {3, 12, 13, 21, 27, 28};
		PossiblyEnabled[26] = set<int>(PE,PE+6);
	}
	PossiblyEnabled[27].insert( 25 );
	PossiblyEnabled[27].insert( 26 );
	PossiblyEnabled[28].insert( 24 );
	PossiblyEnabled[28].insert( 29 );
	{
		int PE[]= {3, 13, 23, 28};
		PossiblyEnabled[29] = set<int>(PE,PE+4);
	}

	PossiblyDisabled = vector< set<int> >(32);
	PossiblyDisabled[0].insert( 1 );
	PossiblyDisabled[1].insert( 0 );
	PossiblyDisabled[2].insert( 11 );
	{
		int PE[]= {7, 13, 28};
		PossiblyDisabled[3] = set<int>(PE,PE+3);
	}
	PossiblyDisabled[5].insert( 6 );
	PossiblyDisabled[6].insert( 5 );
	PossiblyDisabled[7].insert( 3 );
	PossiblyDisabled[7].insert( 8 );
	PossiblyDisabled[8].insert( 7 );
	PossiblyDisabled[9].insert( 10 );
	PossiblyDisabled[10].insert( 9 );
	PossiblyDisabled[11].insert( 2 );
	PossiblyDisabled[12].insert( 21 );
	PossiblyDisabled[12].insert( 27 );
	PossiblyDisabled[13].insert( 3 );
	PossiblyDisabled[13].insert( 28 );
	PossiblyDisabled[14].insert( 15 );
	PossiblyDisabled[15].insert( 14 );
	PossiblyDisabled[16].insert( 17 );
	PossiblyDisabled[17].insert( 16 );
	PossiblyDisabled[18].insert( 20 );
	PossiblyDisabled[19].insert( 22 );
	PossiblyDisabled[20].insert( 18 );
	PossiblyDisabled[21].insert( 12 );
	PossiblyDisabled[21].insert( 27 );
	PossiblyDisabled[22].insert( 19 );
	PossiblyDisabled[23].insert( 27 );
	PossiblyDisabled[23].insert( 28 );
	PossiblyDisabled[24].insert( 29 );
	PossiblyDisabled[25].insert( 26 );
	PossiblyDisabled[26].insert( 25 );
	{
		int PE[]= {12, 21, 23};
		PossiblyDisabled[27] = set<int>(PE,PE+3);
	}
	{
		int PE[]= {3, 13, 23};
		PossiblyDisabled[28] = set<int>(PE,PE+3);
	}
	PossiblyDisabled[29].insert( 24 );

	FreeMarkDepT = vector< set<int> >(32);
	{
		int PE[]= {0, 2, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[0] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[1] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 7, 9, 10, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31};
		FreeMarkDepT[2] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 3, 4, 5, 6, 8, 9, 10, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31};
		FreeMarkDepT[3] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[4] = set<int>(PE,PE+30);
	}
	{
		int PE[]= {0, 1, 2, 3, 5, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25, 26, 28, 29, 30, 31};
		FreeMarkDepT[5] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 2, 3, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[6] = set<int>(PE,PE+30);
	}
	{
		int PE[]= {2, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[7] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[8] = set<int>(PE,PE+29);
	}
	{
		int PE[]= {0, 1, 2, 3, 5, 6, 7, 8, 9, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[9] = set<int>(PE,PE+29);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25, 26, 28, 29, 30, 31};
		FreeMarkDepT[10] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 4, 5, 6, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31};
		FreeMarkDepT[11] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25, 26, 28, 29, 30, 31};
		FreeMarkDepT[12] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31};
		FreeMarkDepT[13] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31};
		FreeMarkDepT[14] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 8, 9, 10, 11, 12, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31};
		FreeMarkDepT[15] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[16] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[17] = set<int>(PE,PE+29);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 22, 24, 25, 26, 27, 29, 30, 31};
		FreeMarkDepT[18] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 23, 24, 25, 26, 28, 29, 30, 31};
		FreeMarkDepT[19] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 20, 21, 22, 24, 25, 26, 29, 30, 31};
		FreeMarkDepT[20] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 20, 21, 23, 24, 25, 26, 28, 29, 30, 31};
		FreeMarkDepT[21] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 20, 22, 24, 25, 26, 28, 29, 30, 31};
		FreeMarkDepT[22] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 21, 22, 23, 24, 25, 26, 29, 30, 31};
		FreeMarkDepT[23] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 30, 31};
		FreeMarkDepT[24] = set<int>(PE,PE+28);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 22, 24, 25, 28, 29, 30, 31};
		FreeMarkDepT[25] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 26, 29, 30, 31};
		FreeMarkDepT[26] = set<int>(PE,PE+25);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 22, 24, 27, 28, 29, 30, 31};
		FreeMarkDepT[27] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 25, 26, 27, 28, 30, 31};
		FreeMarkDepT[28] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 25, 26, 27, 29, 30, 31};
		FreeMarkDepT[29] = set<int>(PE,PE+27);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[30] = set<int>(PE,PE+32);
	}
	{
		int PE[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
		FreeMarkDepT[31] = set<int>(PE,PE+32);
	}

    Place[0].label =" RE_ERK";
    Place[0].isTraced = 1;
    Place[1].label =" ERKPP_Phase3";
    Place[1].isTraced = 1;
    Place[2].label =" RasGTP";
    Place[2].isTraced = 1;
    Place[3].label =" RE_ERK_MEKPF";
    Place[3].isTraced = 1;
    Place[4].label =" RE_Raf";
    Place[4].isTraced = 1;
    Place[5].label =" RE_Raf_RasGTP";
    Place[5].isTraced = 1;
    Place[6].label =" RE_ERKPP";
    Place[6].isTraced = 1;
    Place[7].label =" RE_RafP";
    Place[7].isTraced = 1;
    Place[8].label =" RafP_Phase1";
    Place[8].isTraced = 1;
    Place[9].label =" Phase1";
    Place[9].isTraced = 1;
    Place[10].label =" Phase3";
    Place[10].isTraced = 1;
    Place[11].label =" RE_ERKP";
    Place[11].isTraced = 1;
    Place[12].label =" RE_MEK";
    Place[12].isTraced = 1;
    Place[13].label =" ERKP_Phase3";
    Place[13].isTraced = 1;
    Place[14].label =" RE_ERKP_MEKPP";
    Place[14].isTraced = 1;
    Place[15].label =" RE_MEK_RafP";
    Place[15].isTraced = 1;
    Place[16].label =" MEKP_Phase2";
    Place[16].isTraced = 1;
    Place[17].label =" RE_MEKP";
    Place[17].isTraced = 1;
    Place[18].label =" MEKPP_Phase2";
    Place[18].isTraced = 1;
    Place[19].label =" RE_MEKPP";
    Place[19].isTraced = 1;
    Place[20].label =" Phase2";
    Place[20].isTraced = 1;
    Place[21].label =" RE_MEKP_RafP";
    Place[21].isTraced = 1;
    Place[22].label =" Puit";
    Place[22].isTraced = 1;
	Transition[0] = _trans(0,Timed,MASSACTION,1,1);
	Transition[0].DistParams.push_back(" k29 * (Marking.P->_PL_ERKP_Phase3)" );
	Transition[0].label = "r29";
	Transition[0].priority = "1";
	Transition[0].weight = "1";
	Transition[1] = _trans(1,Timed,MASSACTION,1,1);
	Transition[1].DistParams.push_back(" k30 * (Marking.P->_PL_ERKP_Phase3)" );
	Transition[1].label = "r30";
	Transition[1].priority = "1";
	Transition[1].weight = "1";
	Transition[2] = _trans(2,Timed,MASSACTION,1,1);
	Transition[2].DistParams.push_back(" k24 * (Marking.P->_PL_RE_ERKP_MEKPP)" );
	Transition[2].label = "r24";
	Transition[2].priority = "1";
	Transition[2].weight = "1";
	Transition[3] = _trans(3,Timed,MASSACTION,1,1);
	Transition[3].DistParams.push_back(" (k22/N) * (Marking.P->_PL_RE_ERKP) * (Marking.P->_PL_RE_MEKPP)" );
	Transition[3].label = "r22";
	Transition[3].priority = "1";
	Transition[3].weight = "1";
	Transition[4] = _trans(4,Timed,MASSACTION,1,1);
	Transition[4].DistParams.push_back(" (k1/N) * (Marking.P->_PL_RasGTP) * (Marking.P->_PL_RE_Raf)" );
	Transition[4].label = "r1";
	Transition[4].priority = "1";
	Transition[4].weight = "1";
	Transition[5] = _trans(5,Timed,MASSACTION,1,1);
	Transition[5].DistParams.push_back(" k3 * (Marking.P->_PL_RE_Raf_RasGTP)" );
	Transition[5].label = "r3";
	Transition[5].priority = "1";
	Transition[5].weight = "1";
	Transition[6] = _trans(6,Timed,MASSACTION,1,1);
	Transition[6].DistParams.push_back(" k2 * (Marking.P->_PL_RE_Raf_RasGTP)" );
	Transition[6].label = "r2";
	Transition[6].priority = "1";
	Transition[6].weight = "1";
	Transition[7] = _trans(7,Timed,MASSACTION,1,1);
	Transition[7].DistParams.push_back(" (k28/N) * (Marking.P->_PL_Phase3) * (Marking.P->_PL_RE_ERKP)" );
	Transition[7].label = "r28";
	Transition[7].priority = "1";
	Transition[7].weight = "1";
	Transition[8] = _trans(8,Timed,MASSACTION,1,1);
	Transition[8].DistParams.push_back(" (k25/N) * (Marking.P->_PL_RE_ERKPP) * (Marking.P->_PL_Phase3)" );
	Transition[8].label = "r25";
	Transition[8].priority = "1";
	Transition[8].weight = "1";
	Transition[9] = _trans(9,Timed,MASSACTION,1,1);
	Transition[9].DistParams.push_back(" k6 * (Marking.P->_PL_RafP_Phase1)" );
	Transition[9].label = "r6";
	Transition[9].priority = "1";
	Transition[9].weight = "1";
	Transition[10] = _trans(10,Timed,MASSACTION,1,1);
	Transition[10].DistParams.push_back(" k5 * (Marking.P->_PL_RafP_Phase1)" );
	Transition[10].label = "r5";
	Transition[10].priority = "1";
	Transition[10].weight = "1";
	Transition[11] = _trans(11,Timed,MASSACTION,1,1);
	Transition[11].DistParams.push_back(" k23 * (Marking.P->_PL_RE_ERKP_MEKPP)" );
	Transition[11].label = "r23";
	Transition[11].priority = "1";
	Transition[11].weight = "1";
	Transition[12] = _trans(12,Timed,MASSACTION,1,1);
	Transition[12].DistParams.push_back(" (k4/N) * (Marking.P->_PL_RE_RafP) * (Marking.P->_PL_Phase1)" );
	Transition[12].label = "r4";
	Transition[12].priority = "1";
	Transition[12].weight = "1";
	Transition[13] = _trans(13,Timed,MASSACTION,1,1);
	Transition[13].DistParams.push_back(" (k19/N) * (Marking.P->_PL_RE_ERK) * (Marking.P->_PL_RE_MEKPP)" );
	Transition[13].label = "r19";
	Transition[13].priority = "1";
	Transition[13].weight = "1";
	Transition[14] = _trans(14,Timed,MASSACTION,1,1);
	Transition[14].DistParams.push_back(" k20 * (Marking.P->_PL_RE_ERK_MEKPF)" );
	Transition[14].label = "r20";
	Transition[14].priority = "1";
	Transition[14].weight = "1";
	Transition[15] = _trans(15,Timed,MASSACTION,1,1);
	Transition[15].DistParams.push_back(" k21 * (Marking.P->_PL_RE_ERK_MEKPF)" );
	Transition[15].label = "r21";
	Transition[15].priority = "1";
	Transition[15].weight = "1";
	Transition[16] = _trans(16,Timed,MASSACTION,1,1);
	Transition[16].DistParams.push_back(" k27 * (Marking.P->_PL_ERKPP_Phase3)" );
	Transition[16].label = "r27";
	Transition[16].priority = "1";
	Transition[16].weight = "1";
	Transition[17] = _trans(17,Timed,MASSACTION,1,1);
	Transition[17].DistParams.push_back(" k26 * (Marking.P->_PL_ERKPP_Phase3)" );
	Transition[17].label = "r26";
	Transition[17].priority = "1";
	Transition[17].weight = "1";
	Transition[18] = _trans(18,Timed,MASSACTION,1,1);
	Transition[18].DistParams.push_back(" k18 * (Marking.P->_PL_MEKP_Phase2)" );
	Transition[18].label = "r18";
	Transition[18].priority = "1";
	Transition[18].weight = "1";
	Transition[19] = _trans(19,Timed,MASSACTION,1,1);
	Transition[19].DistParams.push_back(" k8 * (Marking.P->_PL_RE_MEK_RafP)" );
	Transition[19].label = "r8";
	Transition[19].priority = "1";
	Transition[19].weight = "1";
	Transition[20] = _trans(20,Timed,MASSACTION,1,1);
	Transition[20].DistParams.push_back(" k17 * (Marking.P->_PL_MEKP_Phase2)" );
	Transition[20].label = "r17";
	Transition[20].priority = "1";
	Transition[20].weight = "1";
	Transition[21] = _trans(21,Timed,MASSACTION,1,1);
	Transition[21].DistParams.push_back(" (k7/N) * (Marking.P->_PL_RE_RafP) * (Marking.P->_PL_RE_MEK)" );
	Transition[21].label = "r7";
	Transition[21].priority = "1";
	Transition[21].weight = "1";
	Transition[22] = _trans(22,Timed,MASSACTION,1,1);
	Transition[22].DistParams.push_back(" k9 * (Marking.P->_PL_RE_MEK_RafP)" );
	Transition[22].label = "r9";
	Transition[22].priority = "1";
	Transition[22].weight = "1";
	Transition[23] = _trans(23,Timed,MASSACTION,1,1);
	Transition[23].DistParams.push_back(" (k16/N) * (Marking.P->_PL_RE_MEKP) * (Marking.P->_PL_Phase2)" );
	Transition[23].label = "r16";
	Transition[23].priority = "1";
	Transition[23].weight = "1";
	Transition[24] = _trans(24,Timed,MASSACTION,1,1);
	Transition[24].DistParams.push_back(" k15 * (Marking.P->_PL_MEKPP_Phase2)" );
	Transition[24].label = "r15";
	Transition[24].priority = "1";
	Transition[24].weight = "1";
	Transition[25] = _trans(25,Timed,MASSACTION,1,1);
	Transition[25].DistParams.push_back(" k11 * (Marking.P->_PL_RE_MEKP_RafP)" );
	Transition[25].label = "r11";
	Transition[25].priority = "1";
	Transition[25].weight = "1";
	Transition[26] = _trans(26,Timed,MASSACTION,1,1);
	Transition[26].DistParams.push_back(" k12 * (Marking.P->_PL_RE_MEKP_RafP)" );
	Transition[26].label = "r12";
	Transition[26].priority = "1";
	Transition[26].weight = "1";
	Transition[27] = _trans(27,Timed,MASSACTION,1,1);
	Transition[27].DistParams.push_back(" (k10/N) * (Marking.P->_PL_RE_RafP) * (Marking.P->_PL_RE_MEKP)" );
	Transition[27].label = "r10";
	Transition[27].priority = "1";
	Transition[27].weight = "1";
	Transition[28] = _trans(28,Timed,MASSACTION,1,1);
	Transition[28].DistParams.push_back(" (k13/N) * (Marking.P->_PL_RE_MEKPP) * (Marking.P->_PL_Phase2)" );
	Transition[28].label = "r13";
	Transition[28].priority = "1";
	Transition[28].weight = "1";
	Transition[29] = _trans(29,Timed,MASSACTION,1,1);
	Transition[29].DistParams.push_back(" k14 * (Marking.P->_PL_MEKPP_Phase2)" );
	Transition[29].label = "r14";
	Transition[29].priority = "1";
	Transition[29].weight = "1";
	Transition[30] = _trans(30,Timed,EXPONENTIAL,1,1);
	Transition[30].DistParams.push_back(" 0" );
	Transition[30].label = "selfloop";
	Transition[30].priority = "1";
	Transition[30].weight = "1";
	Transition[31] = _trans(31,Timed,EXPONENTIAL,1,1);
	Transition[31].DistParams.push_back(" 0" );
	Transition[31].label = "Puittrans";
	Transition[31].priority = "1";
	Transition[31].weight = "1";
    Msimple();
vector <double> Rate_Table_init (tr);
Rate_Table = Rate_Table_init;
Origine_Rate_Table = Rate_Table_init;
}

bool SPN::IsEnabled(size_t t, const abstractBinding& b)const {
switch (t){
	case 0:	//r29
	case 1:	//r30
    if (!(contains(Marking.P->_PL_ERKP_Phase3 , 1))) return false;
    return true;

		break;
	case 24:	//r15
	case 29:	//r14
    if (!(contains(Marking.P->_PL_MEKPP_Phase2 , 1))) return false;
    return true;

		break;
	case 18:	//r18
	case 20:	//r17
    if (!(contains(Marking.P->_PL_MEKP_Phase2 , 1))) return false;
    return true;

		break;
	case 7:	//r28
    if (!(contains(Marking.P->_PL_Phase3 , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_ERKP , 1))) return false;
    return true;

		break;
	case 13:	//r19
    if (!(contains(Marking.P->_PL_RE_ERK , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_MEKPP , 1))) return false;
    return true;

		break;
	case 3:	//r22
    if (!(contains(Marking.P->_PL_RE_ERKP , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_MEKPP , 1))) return false;
    return true;

		break;
	case 8:	//r25
    if (!(contains(Marking.P->_PL_RE_ERKPP , 1))) return false;
    if (!(contains(Marking.P->_PL_Phase3 , 1))) return false;
    return true;

		break;
	case 2:	//r24
	case 11:	//r23
    if (!(contains(Marking.P->_PL_RE_ERKP_MEKPP , 1))) return false;
    return true;

		break;
	case 14:	//r20
	case 15:	//r21
    if (!(contains(Marking.P->_PL_RE_ERK_MEKPF , 1))) return false;
    return true;

		break;
	case 23:	//r16
    if (!(contains(Marking.P->_PL_RE_MEKP , 1))) return false;
    if (!(contains(Marking.P->_PL_Phase2 , 1))) return false;
    return true;

		break;
	case 28:	//r13
    if (!(contains(Marking.P->_PL_RE_MEKPP , 1))) return false;
    if (!(contains(Marking.P->_PL_Phase2 , 1))) return false;
    return true;

		break;
	case 25:	//r11
	case 26:	//r12
    if (!(contains(Marking.P->_PL_RE_MEKP_RafP , 1))) return false;
    return true;

		break;
	case 19:	//r8
	case 22:	//r9
    if (!(contains(Marking.P->_PL_RE_MEK_RafP , 1))) return false;
    return true;

		break;
	case 12:	//r4
    if (!(contains(Marking.P->_PL_RE_RafP , 1))) return false;
    if (!(contains(Marking.P->_PL_Phase1 , 1))) return false;
    return true;

		break;
	case 21:	//r7
    if (!(contains(Marking.P->_PL_RE_RafP , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_MEK , 1))) return false;
    return true;

		break;
	case 27:	//r10
    if (!(contains(Marking.P->_PL_RE_RafP , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_MEKP , 1))) return false;
    return true;

		break;
	case 5:	//r3
	case 6:	//r2
    if (!(contains(Marking.P->_PL_RE_Raf_RasGTP , 1))) return false;
    return true;

		break;
	case 9:	//r6
	case 10:	//r5
    if (!(contains(Marking.P->_PL_RafP_Phase1 , 1))) return false;
    return true;

		break;
	case 4:	//r1
    if (!(contains(Marking.P->_PL_RasGTP , 1))) return false;
    if (!(contains(Marking.P->_PL_RE_Raf , 1))) return false;
    return true;

		break;
	case 30:	//selfloop
	case 31:	//Puittrans
    return true;

		break;
	default:	//r27,r26,
    if (!(contains(Marking.P->_PL_ERKPP_Phase3 , 1))) return false;
    return true;

}
}

void SPN::fire(size_t t, const abstractBinding& b){
	lastTransition = t;
	switch(t){
		case 0: {  //r29
			Marking.P->_PL_Phase3 += 1;
			Marking.P->_PL_RE_ERKP += 1;
			Marking.P->_PL_ERKP_Phase3 -= 1;
       break;
     } 
		case 1: {  //r30
			Marking.P->_PL_RE_ERK += 1;
			Marking.P->_PL_Phase3 += 1;
			Marking.P->_PL_ERKP_Phase3 -= 1;
       break;
     } 
		case 2: {  //r24
			Marking.P->_PL_RE_ERKPP += 1;
			Marking.P->_PL_RE_ERKP_MEKPP -= 1;
			Marking.P->_PL_RE_MEKPP += 1;
       break;
     } 
		case 3: {  //r22
			Marking.P->_PL_RE_ERKP -= 1;
			Marking.P->_PL_RE_ERKP_MEKPP += 1;
			Marking.P->_PL_RE_MEKPP -= 1;
       break;
     } 
		case 4: {  //r1
			Marking.P->_PL_RasGTP -= 1;
			Marking.P->_PL_RE_Raf -= 1;
			Marking.P->_PL_RE_Raf_RasGTP += 1;
       break;
     } 
		case 5: {  //r3
			Marking.P->_PL_RasGTP += 1;
			Marking.P->_PL_RE_Raf_RasGTP -= 1;
			Marking.P->_PL_RE_RafP += 1;
       break;
     } 
		case 6: {  //r2
			Marking.P->_PL_RasGTP += 1;
			Marking.P->_PL_RE_Raf += 1;
			Marking.P->_PL_RE_Raf_RasGTP -= 1;
       break;
     } 
		case 7: {  //r28
			Marking.P->_PL_Phase3 -= 1;
			Marking.P->_PL_RE_ERKP -= 1;
			Marking.P->_PL_ERKP_Phase3 += 1;
       break;
     } 
		case 8: {  //r25
			Marking.P->_PL_ERKPP_Phase3 += 1;
			Marking.P->_PL_RE_ERKPP -= 1;
			Marking.P->_PL_Phase3 -= 1;
       break;
     } 
		case 9: {  //r6
			Marking.P->_PL_RE_Raf += 1;
			Marking.P->_PL_RafP_Phase1 -= 1;
			Marking.P->_PL_Phase1 += 1;
       break;
     } 
		case 10: {  //r5
			Marking.P->_PL_RE_RafP += 1;
			Marking.P->_PL_RafP_Phase1 -= 1;
			Marking.P->_PL_Phase1 += 1;
       break;
     } 
		case 11: {  //r23
			Marking.P->_PL_RE_ERKP += 1;
			Marking.P->_PL_RE_ERKP_MEKPP -= 1;
			Marking.P->_PL_RE_MEKPP += 1;
       break;
     } 
		case 12: {  //r4
			Marking.P->_PL_RE_RafP -= 1;
			Marking.P->_PL_RafP_Phase1 += 1;
			Marking.P->_PL_Phase1 -= 1;
       break;
     } 
		case 13: {  //r19
			Marking.P->_PL_RE_ERK -= 1;
			Marking.P->_PL_RE_ERK_MEKPF += 1;
			Marking.P->_PL_RE_MEKPP -= 1;
       break;
     } 
		case 14: {  //r20
			Marking.P->_PL_RE_ERK += 1;
			Marking.P->_PL_RE_ERK_MEKPF -= 1;
			Marking.P->_PL_RE_MEKPP += 1;
       break;
     } 
		case 15: {  //r21
			Marking.P->_PL_RE_ERK_MEKPF -= 1;
			Marking.P->_PL_RE_ERKP += 1;
			Marking.P->_PL_RE_MEKPP += 1;
       break;
     } 
		case 16: {  //r27
			Marking.P->_PL_ERKPP_Phase3 -= 1;
			Marking.P->_PL_Phase3 += 1;
			Marking.P->_PL_RE_ERKP += 1;
       break;
     } 
		case 17: {  //r26
			Marking.P->_PL_ERKPP_Phase3 -= 1;
			Marking.P->_PL_RE_ERKPP += 1;
			Marking.P->_PL_Phase3 += 1;
       break;
     } 
		case 18: {  //r18
			Marking.P->_PL_RE_MEK += 1;
			Marking.P->_PL_MEKP_Phase2 -= 1;
			Marking.P->_PL_Phase2 += 1;
       break;
     } 
		case 19: {  //r8
			Marking.P->_PL_RE_RafP += 1;
			Marking.P->_PL_RE_MEK += 1;
			Marking.P->_PL_RE_MEK_RafP -= 1;
       break;
     } 
		case 20: {  //r17
			Marking.P->_PL_MEKP_Phase2 -= 1;
			Marking.P->_PL_RE_MEKP += 1;
			Marking.P->_PL_Phase2 += 1;
       break;
     } 
		case 21: {  //r7
			Marking.P->_PL_RE_RafP -= 1;
			Marking.P->_PL_RE_MEK -= 1;
			Marking.P->_PL_RE_MEK_RafP += 1;
       break;
     } 
		case 22: {  //r9
			Marking.P->_PL_RE_RafP += 1;
			Marking.P->_PL_RE_MEK_RafP -= 1;
			Marking.P->_PL_RE_MEKP += 1;
       break;
     } 
		case 23: {  //r16
			Marking.P->_PL_MEKP_Phase2 += 1;
			Marking.P->_PL_RE_MEKP -= 1;
			Marking.P->_PL_Phase2 -= 1;
       break;
     } 
		case 24: {  //r15
			Marking.P->_PL_RE_MEKP += 1;
			Marking.P->_PL_MEKPP_Phase2 -= 1;
			Marking.P->_PL_Phase2 += 1;
       break;
     } 
		case 25: {  //r11
			Marking.P->_PL_RE_RafP += 1;
			Marking.P->_PL_RE_MEKP += 1;
			Marking.P->_PL_RE_MEKP_RafP -= 1;
       break;
     } 
		case 26: {  //r12
			Marking.P->_PL_RE_RafP += 1;
			Marking.P->_PL_RE_MEKPP += 1;
			Marking.P->_PL_RE_MEKP_RafP -= 1;
       break;
     } 
		case 27: {  //r10
			Marking.P->_PL_RE_RafP -= 1;
			Marking.P->_PL_RE_MEKP -= 1;
			Marking.P->_PL_RE_MEKP_RafP += 1;
       break;
     } 
		case 28: {  //r13
			Marking.P->_PL_MEKPP_Phase2 += 1;
			Marking.P->_PL_RE_MEKPP -= 1;
			Marking.P->_PL_Phase2 -= 1;
       break;
     } 
		case 29: {  //r14
			Marking.P->_PL_MEKPP_Phase2 -= 1;
			Marking.P->_PL_RE_MEKPP += 1;
			Marking.P->_PL_Phase2 += 1;
       break;
     } 
		case 30: {  //selfloop
       break;
     } 
		case 31: {  //Puittrans
			Marking.P->_PL_Puit += 1;
       break;
     } 
	}
}
void SPN::unfire(size_t t ,const abstractBinding& b){
switch (t){
	case 16:	//r27
    Marking.P->_PL_ERKPP_Phase3 += 1;
    Marking.P->_PL_Phase3 -= 1;
    Marking.P->_PL_RE_ERKP -= 1;

		break;
	case 17:	//r26
    Marking.P->_PL_ERKPP_Phase3 += 1;
    Marking.P->_PL_RE_ERKPP -= 1;
    Marking.P->_PL_Phase3 -= 1;

		break;
	case 8:	//r25
    Marking.P->_PL_ERKPP_Phase3 -= 1;
    Marking.P->_PL_RE_ERKPP += 1;
    Marking.P->_PL_Phase3 += 1;

		break;
	case 29:	//r14
    Marking.P->_PL_MEKPP_Phase2 += 1;
    Marking.P->_PL_RE_MEKPP -= 1;
    Marking.P->_PL_Phase2 -= 1;

		break;
	case 28:	//r13
    Marking.P->_PL_MEKPP_Phase2 -= 1;
    Marking.P->_PL_RE_MEKPP += 1;
    Marking.P->_PL_Phase2 += 1;

		break;
	case 20:	//r17
    Marking.P->_PL_MEKP_Phase2 += 1;
    Marking.P->_PL_RE_MEKP -= 1;
    Marking.P->_PL_Phase2 -= 1;

		break;
	case 23:	//r16
    Marking.P->_PL_MEKP_Phase2 -= 1;
    Marking.P->_PL_RE_MEKP += 1;
    Marking.P->_PL_Phase2 += 1;

		break;
	case 7:	//r28
    Marking.P->_PL_Phase3 += 1;
    Marking.P->_PL_RE_ERKP += 1;
    Marking.P->_PL_ERKP_Phase3 -= 1;

		break;
	case 0:	//r29
    Marking.P->_PL_Phase3 -= 1;
    Marking.P->_PL_RE_ERKP -= 1;
    Marking.P->_PL_ERKP_Phase3 += 1;

		break;
	case 31:	//Puittrans
    Marking.P->_PL_Puit -= 1;

		break;
	case 13:	//r19
    Marking.P->_PL_RE_ERK += 1;
    Marking.P->_PL_RE_ERK_MEKPF -= 1;
    Marking.P->_PL_RE_MEKPP += 1;

		break;
	case 1:	//r30
    Marking.P->_PL_RE_ERK -= 1;
    Marking.P->_PL_Phase3 -= 1;
    Marking.P->_PL_ERKP_Phase3 += 1;

		break;
	case 14:	//r20
    Marking.P->_PL_RE_ERK -= 1;
    Marking.P->_PL_RE_ERK_MEKPF += 1;
    Marking.P->_PL_RE_MEKPP -= 1;

		break;
	case 3:	//r22
    Marking.P->_PL_RE_ERKP += 1;
    Marking.P->_PL_RE_ERKP_MEKPP -= 1;
    Marking.P->_PL_RE_MEKPP += 1;

		break;
	case 11:	//r23
    Marking.P->_PL_RE_ERKP -= 1;
    Marking.P->_PL_RE_ERKP_MEKPP += 1;
    Marking.P->_PL_RE_MEKPP -= 1;

		break;
	case 2:	//r24
    Marking.P->_PL_RE_ERKPP -= 1;
    Marking.P->_PL_RE_ERKP_MEKPP += 1;
    Marking.P->_PL_RE_MEKPP -= 1;

		break;
	case 15:	//r21
    Marking.P->_PL_RE_ERK_MEKPF += 1;
    Marking.P->_PL_RE_ERKP -= 1;
    Marking.P->_PL_RE_MEKPP -= 1;

		break;
	case 18:	//r18
    Marking.P->_PL_RE_MEK -= 1;
    Marking.P->_PL_MEKP_Phase2 += 1;
    Marking.P->_PL_Phase2 -= 1;

		break;
	case 24:	//r15
    Marking.P->_PL_RE_MEKP -= 1;
    Marking.P->_PL_MEKPP_Phase2 += 1;
    Marking.P->_PL_Phase2 -= 1;

		break;
	case 9:	//r6
    Marking.P->_PL_RE_Raf -= 1;
    Marking.P->_PL_RafP_Phase1 += 1;
    Marking.P->_PL_Phase1 -= 1;

		break;
	case 21:	//r7
    Marking.P->_PL_RE_RafP += 1;
    Marking.P->_PL_RE_MEK += 1;
    Marking.P->_PL_RE_MEK_RafP -= 1;

		break;
	case 27:	//r10
    Marking.P->_PL_RE_RafP += 1;
    Marking.P->_PL_RE_MEKP += 1;
    Marking.P->_PL_RE_MEKP_RafP -= 1;

		break;
	case 12:	//r4
    Marking.P->_PL_RE_RafP += 1;
    Marking.P->_PL_RafP_Phase1 -= 1;
    Marking.P->_PL_Phase1 += 1;

		break;
	case 19:	//r8
    Marking.P->_PL_RE_RafP -= 1;
    Marking.P->_PL_RE_MEK -= 1;
    Marking.P->_PL_RE_MEK_RafP += 1;

		break;
	case 25:	//r11
    Marking.P->_PL_RE_RafP -= 1;
    Marking.P->_PL_RE_MEKP -= 1;
    Marking.P->_PL_RE_MEKP_RafP += 1;

		break;
	case 26:	//r12
    Marking.P->_PL_RE_RafP -= 1;
    Marking.P->_PL_RE_MEKPP -= 1;
    Marking.P->_PL_RE_MEKP_RafP += 1;

		break;
	case 22:	//r9
    Marking.P->_PL_RE_RafP -= 1;
    Marking.P->_PL_RE_MEK_RafP += 1;
    Marking.P->_PL_RE_MEKP -= 1;

		break;
	case 10:	//r5
    Marking.P->_PL_RE_RafP -= 1;
    Marking.P->_PL_RafP_Phase1 += 1;
    Marking.P->_PL_Phase1 -= 1;

		break;
	case 4:	//r1
    Marking.P->_PL_RasGTP += 1;
    Marking.P->_PL_RE_Raf += 1;
    Marking.P->_PL_RE_Raf_RasGTP -= 1;

		break;
	case 6:	//r2
    Marking.P->_PL_RasGTP -= 1;
    Marking.P->_PL_RE_Raf -= 1;
    Marking.P->_PL_RE_Raf_RasGTP += 1;

		break;
	case 5:	//r3
    Marking.P->_PL_RasGTP -= 1;
    Marking.P->_PL_RE_Raf_RasGTP += 1;
    Marking.P->_PL_RE_RafP -= 1;

		break;
}
}

const set<int>* SPN::PossiblyEn()const {
	return &(PossiblyEnabled[lastTransition]);
}
const set<int>* SPN::PossiblyDis()const {
	return &(PossiblyDisabled[lastTransition]);
}
const set<int>* SPN::FreeMarkingDependant()const {
	return &(FreeMarkDepT[lastTransition]);
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
	case 4:	//r1
	{
		ParamDistr[0]= ( double ) (k1/N) * (Marking.P->_PL_RasGTP) * (Marking.P->_PL_RE_Raf);
	}

		break;
	case 27:	//r10
	{
		ParamDistr[0]= ( double ) (k10/N) * (Marking.P->_PL_RE_RafP) * (Marking.P->_PL_RE_MEKP);
	}

		break;
	case 28:	//r13
	{
		ParamDistr[0]= ( double ) (k13/N) * (Marking.P->_PL_RE_MEKPP) * (Marking.P->_PL_Phase2);
	}

		break;
	case 23:	//r16
	{
		ParamDistr[0]= ( double ) (k16/N) * (Marking.P->_PL_RE_MEKP) * (Marking.P->_PL_Phase2);
	}

		break;
	case 13:	//r19
	{
		ParamDistr[0]= ( double ) (k19/N) * (Marking.P->_PL_RE_ERK) * (Marking.P->_PL_RE_MEKPP);
	}

		break;
	case 3:	//r22
	{
		ParamDistr[0]= ( double ) (k22/N) * (Marking.P->_PL_RE_ERKP) * (Marking.P->_PL_RE_MEKPP);
	}

		break;
	case 8:	//r25
	{
		ParamDistr[0]= ( double ) (k25/N) * (Marking.P->_PL_RE_ERKPP) * (Marking.P->_PL_Phase3);
	}

		break;
	case 7:	//r28
	{
		ParamDistr[0]= ( double ) (k28/N) * (Marking.P->_PL_Phase3) * (Marking.P->_PL_RE_ERKP);
	}

		break;
	case 12:	//r4
	{
		ParamDistr[0]= ( double ) (k4/N) * (Marking.P->_PL_RE_RafP) * (Marking.P->_PL_Phase1);
	}

		break;
	case 21:	//r7
	{
		ParamDistr[0]= ( double ) (k7/N) * (Marking.P->_PL_RE_RafP) * (Marking.P->_PL_RE_MEK);
	}

		break;
	case 25:	//r11
	{
		ParamDistr[0]= ( double ) k11 * (Marking.P->_PL_RE_MEKP_RafP);
	}

		break;
	case 26:	//r12
	{
		ParamDistr[0]= ( double ) k12 * (Marking.P->_PL_RE_MEKP_RafP);
	}

		break;
	case 29:	//r14
	{
		ParamDistr[0]= ( double ) k14 * (Marking.P->_PL_MEKPP_Phase2);
	}

		break;
	case 24:	//r15
	{
		ParamDistr[0]= ( double ) k15 * (Marking.P->_PL_MEKPP_Phase2);
	}

		break;
	case 20:	//r17
	{
		ParamDistr[0]= ( double ) k17 * (Marking.P->_PL_MEKP_Phase2);
	}

		break;
	case 18:	//r18
	{
		ParamDistr[0]= ( double ) k18 * (Marking.P->_PL_MEKP_Phase2);
	}

		break;
	case 6:	//r2
	{
		ParamDistr[0]= ( double ) k2 * (Marking.P->_PL_RE_Raf_RasGTP);
	}

		break;
	case 14:	//r20
	{
		ParamDistr[0]= ( double ) k20 * (Marking.P->_PL_RE_ERK_MEKPF);
	}

		break;
	case 15:	//r21
	{
		ParamDistr[0]= ( double ) k21 * (Marking.P->_PL_RE_ERK_MEKPF);
	}

		break;
	case 11:	//r23
	{
		ParamDistr[0]= ( double ) k23 * (Marking.P->_PL_RE_ERKP_MEKPP);
	}

		break;
	case 2:	//r24
	{
		ParamDistr[0]= ( double ) k24 * (Marking.P->_PL_RE_ERKP_MEKPP);
	}

		break;
	case 17:	//r26
	{
		ParamDistr[0]= ( double ) k26 * (Marking.P->_PL_ERKPP_Phase3);
	}

		break;
	case 16:	//r27
	{
		ParamDistr[0]= ( double ) k27 * (Marking.P->_PL_ERKPP_Phase3);
	}

		break;
	case 0:	//r29
	{
		ParamDistr[0]= ( double ) k29 * (Marking.P->_PL_ERKP_Phase3);
	}

		break;
	case 5:	//r3
	{
		ParamDistr[0]= ( double ) k3 * (Marking.P->_PL_RE_Raf_RasGTP);
	}

		break;
	case 1:	//r30
	{
		ParamDistr[0]= ( double ) k30 * (Marking.P->_PL_ERKP_Phase3);
	}

		break;
	case 10:	//r5
	{
		ParamDistr[0]= ( double ) k5 * (Marking.P->_PL_RafP_Phase1);
	}

		break;
	case 9:	//r6
	{
		ParamDistr[0]= ( double ) k6 * (Marking.P->_PL_RafP_Phase1);
	}

		break;
	case 19:	//r8
	{
		ParamDistr[0]= ( double ) k8 * (Marking.P->_PL_RE_MEK_RafP);
	}

		break;
	case 22:	//r9
	{
		ParamDistr[0]= ( double ) k9 * (Marking.P->_PL_RE_MEK_RafP);
	}

		break;
	default:	//selfloop,Puittrans,
	{
		ParamDistr[0]= ( double ) 0;
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
		tab.push_back(0);
		tab.push_back(11);
		tab.push_back(6);
		tab.push_back(14);
		tab.push_back(3);
		tab.push_back(12);
		tab.push_back(17);
		tab.push_back(19);
		tab.push_back(21);
		tab.push_back(15);
		tab.push_back(4);
		tab.push_back(7);
		tab.push_back(5);
	Msimpletab = tab;
}
void SPN::reset() {
	Marking.resetToInitMarking();
	TransitionConditions = initTransitionConditions;
}

