#include "spnLight.hpp"

#define PL_SIG_AP_LP 0
#define PL_SIG_AS_LP 1
#define PL_SIG_Aget_LP 2
#define PL_SIG_RLRI_LP 3
#define PL_SIG_VP_LP 4
#define PL_SIG_VS_LP 5
#define PL_SIG_Vget_LP 6
#define PL_TAVIcmp_LP 7
#define PL_AVI_LP 8
#define PL_URI_LP 9
#define PL_PVARP_LP 10
#define PL_VRP_LP 11
#define PL_LRI_LP 12
#define TR_EMPTY_AP_RT 0
#define TR_EMPTY_AS_RT 1
#define TR_EMPTY_Aget_RT 2
#define TR_EMPTY_RLRI_RT 3
#define TR_EMPTY_VP_RT 4
#define TR_EMPTY_VS_RT 5
#define TR_EMPTY_Vget_RT 6
#define TR_D723_LRI_RT 7
#define TR_I782_LRI_RT 8
#define TR_RAS724__RT 9
#define TR_I856_LRI_RT 10
#define TR_RRLRI713__RT 11
#define TR_I854_ASensed_RT 12
#define TR_RRLRI714__RT 13
#define TR_I852_RLRI_RT 14
#define TR_I780_LRI_RT 15
#define TR_D717_VRP_RT 16
#define TR_RVP758__RT 17
#define TR_I850_Idle_RT 18
#define TR_I759_Vsig_RT 19
#define TR_RVget760__RT 20
#define TR_I848_Idle_RT 21
#define TR_RVP768__RT 22
#define TR_I846_Idle_RT 23
#define TR_RVS769__RT 24
#define TR_I844_Idle_RT 25
#define TR_D771_PVARP_RT 26
#define TR_I772_Asig_RT 27
#define TR_RAget773__RT 28
#define TR_I842_Idle_RT 29
#define TR_D774_PVAB_RT 30
#define TR_I778_URI_RT 31
#define TR_D735_URI_RT 32
#define TR_I814_IncrClk_RT 33
#define TR_I815_IncrClk_RT 34
#define TR_I816_IncrClk_RT 35
#define TR_RVS817_RURI_RT 36
#define TR_RVS819_RURI_RT 37
#define TR_RVS820_RURI_RT 38
#define TR_I821_IncrClk_RT 39
#define TR_I822_IncrClk_RT 40
#define TR_D726_q0_RT 41
#define TR_RAS824_RTAVI_RT 42
#define TR_RAP825_RTAVI_RT 43
#define TR_RAS826_RTAVI_RT 44
#define TR_RAP827_RTAVI_RT 45
#define TR_I828_TAVI_RT 46
#define TR_I829_TAVI_RT 47
#define TR_I830_TAVI_RT 48
#define TR_I831_TAVI_RT 49
#define TR_I832_TAVI_RT 50
#define TR_RAS833_RTAVI_RT 51
#define TR_RAP834_RTAVI_RT 52
#define TR_RAS835_RTAVI_RT 53
#define TR_RAP836_RTAVI_RT 54

	const double AV_Vr=-90;
	const double AV_Vt=-40;
	const double AV_alpha=150;
	const double AV_anteDMin=50;
	const double AV_beta=250;
	const double AV_delta=10;
	const double AV_k4=0.03;
	const double AV_refrDMin=50;
	const double AV_retroDMin=100;
	const double AV_tauC=100;
	const double AV_theta=10;
	const double AV_tr=500;
	const double Atr_refrD=50;
	const double PM_TAVI=150;
	const double PM_TLRI=1000;
	const double PM_TPVAB=50;
	const double PM_TPVARP=250;
	const double PM_TURI=500;
	const double PM_TVRP=320;
	const double RA_anteD=30;
	const double RA_retroD=30;
	const double RV_anteD=50;
	const double RV_retroD=50;
	const double Reduce_TimeToDep=1666.7;
	const double SA_d=850;
	const double SA_dV=50;
	const double SA_ectopD=10400;
	const double SA_ectopdV=50;
	const double SA_noiseD=1e+06;
	const double Skrewness=0.2;
	const double VRG_d=3000;
	const double VRG_ectopD=30450;
	const double VRG_noiseD=1e+06;
	const double Vtr_refrD=200;
	const int _nb_Place_SIG_AP=0;
	const int _nb_Place_SIG_AS=1;
	const int _nb_Place_SIG_Aget=2;
	const int _nb_Place_SIG_RLRI=3;
	const int _nb_Place_SIG_VP=4;
	const int _nb_Place_SIG_VS=5;
	const int _nb_Place_SIG_Vget=6;
	const int _nb_Place_TAVIcmp=7;
	const int _nb_Place_AVI=8;
	const int _nb_Place_URI=9;
	const int _nb_Place_PVARP=10;
	const int _nb_Place_VRP=11;
	const int _nb_Place_LRI=12;
#include <iostream>
#include "markingImplLight.hpp"

void abstractMarking::resetToInitMarking(){
	P->_PL_SIG_AP =0;
	P->_PL_SIG_AS =0;
	P->_PL_SIG_Aget =0;
	P->_PL_SIG_RLRI =0;
	P->_PL_SIG_VP =0;
	P->_PL_SIG_VS =0;
	P->_PL_SIG_Vget =0;
	P->_PL_TAVIcmp =5;
	P->_PL_AVI =14;
	P->_PL_URI =17;
	P->_PL_PVARP =3;
	P->_PL_VRP =9;
	P->_PL_LRI =21;
}


abstractMarking::abstractMarking() {
	P= new abstractMarkingImpl;
	resetToInitMarking();
}

abstractMarking::~abstractMarking() {
	delete(P);
}


void abstractMarking::printHeader()const{
}

void abstractMarking::print()const{
}
SPN::SPN():
pl(13), tr(55) {
}

bool SPN::IsEnabled(size_t t)const {
switch (t){
	case 45:	//RAP827_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 5) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 52:	//RAP834_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

		break;
	case 54:	//RAP836_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 0:	//EMPTY_AP
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    return true;

		break;
	case 9:	//RAS724_
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_LRI != 21) return false;
    return true;

		break;
	case 42:	//RAS824_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 5) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

		break;
	case 44:	//RAS826_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 5) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 51:	//RAS833_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

		break;
	case 53:	//RAS835_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 1:	//EMPTY_AS
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    return true;

		break;
	case 28:	//RAget773_
    if (!(contains(Marking.P->_PL_SIG_Aget , 1))) return false;
    if( Marking.P->_PL_PVARP != 3) return false;
    return true;

		break;
	case 2:	//EMPTY_Aget
    if (!(contains(Marking.P->_PL_SIG_Aget , 1))) return false;
    return true;

		break;
	case 11:	//RRLRI713_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 20) return false;
    return true;

		break;
	case 13:	//RRLRI714_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 21) return false;
    return true;

		break;
	case 3:	//EMPTY_RLRI
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    return true;

		break;
	case 22:	//RVP768_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_PVARP != 3) return false;
    return true;

		break;
	case 17:	//RVP758_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_VRP != 9) return false;
    return true;

		break;
	case 4:	//EMPTY_VP
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    return true;

		break;
	case 36:	//RVS817_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 10) return false;
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 38:	//RVS820_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 12) return false;
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 37:	//RVS819_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 13) return false;
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 24:	//RVS769_
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_PVARP != 3) return false;
    return true;

		break;
	case 5:	//EMPTY_VS
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    return true;

		break;
	case 20:	//RVget760_
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    if( Marking.P->_PL_VRP != 9) return false;
    return true;

		break;
	case 6:	//EMPTY_Vget
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    return true;

		break;
	case 8:	//I782_LRI
    if (Marking.P->_PL_SIG_AP >= 1) return false;
    if( Marking.P->_PL_LRI != 18) return false;
    return true;

		break;
	case 27:	//I772_Asig
    if (Marking.P->_PL_SIG_AS >= 1) return false;
    if( Marking.P->_PL_PVARP != 1) return false;
    return true;

		break;
	case 35:	//I816_IncrClk
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_AVI != 12) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 46:	//I828_TAVI
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 10) return false;
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 19:	//I759_Vsig
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VS >= 1) return false;
    if( Marking.P->_PL_VRP != 7) return false;
    return true;

		break;
	case 39:	//I821_IncrClk
    if( Marking.P->_PL_AVI != 10) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 40:	//I822_IncrClk
    if( Marking.P->_PL_AVI != 11) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 34:	//I815_IncrClk
    if( Marking.P->_PL_AVI != 13) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 33:	//I814_IncrClk
    if( Marking.P->_PL_AVI != 14) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 15:	//I780_LRI
    if( Marking.P->_PL_LRI != 19) return false;
    return true;

		break;
	case 7:	//D723_LRI
    if( Marking.P->_PL_LRI != 21) return false;
    return true;

		break;
	case 14:	//I852_RLRI
    if( Marking.P->_PL_LRI != 851) return false;
    return true;

		break;
	case 12:	//I854_ASensed
    if( Marking.P->_PL_LRI != 853) return false;
    return true;

		break;
	case 10:	//I856_LRI
    if( Marking.P->_PL_LRI != 855) return false;
    return true;

		break;
	case 26:	//D771_PVARP
    if( Marking.P->_PL_PVARP != 0) return false;
    return true;

		break;
	case 30:	//D774_PVAB
    if( Marking.P->_PL_PVARP != 2) return false;
    return true;

		break;
	case 29:	//I842_Idle
    if( Marking.P->_PL_PVARP != 841) return false;
    return true;

		break;
	case 25:	//I844_Idle
    if( Marking.P->_PL_PVARP != 843) return false;
    return true;

		break;
	case 23:	//I846_Idle
    if( Marking.P->_PL_PVARP != 845) return false;
    return true;

		break;
	case 48:	//I830_TAVI
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

		break;
	case 49:	//I831_TAVI
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 12) return false;
    return true;

		break;
	case 47:	//I829_TAVI
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 13) return false;
    return true;

		break;
	case 50:	//I832_TAVI
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 41:	//D726_q0
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    return true;

		break;
	case 31:	//I778_URI
    if( Marking.P->_PL_URI != 15) return false;
    return true;

		break;
	case 32:	//D735_URI
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 16:	//D717_VRP
    if( Marking.P->_PL_VRP != 8) return false;
    return true;

		break;
	case 21:	//I848_Idle
    if( Marking.P->_PL_VRP != 847) return false;
    return true;

		break;
	case 18:	//I850_Idle
    if( Marking.P->_PL_VRP != 849) return false;
    return true;

		break;
	default:	//RAP825_RTAVI,
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 5) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

}
}

void SPN::fire(size_t t,  double time){
	lastTransition = t;
	switch(t){
		case 0: {  //EMPTY_AP
			Marking.P->_PL_SIG_AP -= 1;
       break;
     } 
		case 1: {  //EMPTY_AS
			Marking.P->_PL_SIG_AS -= 1;
       break;
     } 
		case 2: {  //EMPTY_Aget
			Marking.P->_PL_SIG_Aget -= 1;
       break;
     } 
		case 3: {  //EMPTY_RLRI
			Marking.P->_PL_SIG_RLRI -= 1;
       break;
     } 
		case 4: {  //EMPTY_VP
			Marking.P->_PL_SIG_VP -= 1;
       break;
     } 
		case 5: {  //EMPTY_VS
			Marking.P->_PL_SIG_VS -= 1;
       break;
     } 
		case 6: {  //EMPTY_Vget
			Marking.P->_PL_SIG_Vget -= 1;
       break;
     } 
		case 7: {  //D723_LRI
			Marking.P->_PL_LRI -= 21;
			Marking.P->_PL_LRI += 18;
       break;
     } 
		case 8: {  //I782_LRI
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_LRI -= 18;
			Marking.P->_PL_LRI += 21;
       break;
     } 
		case 9: {  //RAS724_
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_LRI -= 21;
			Marking.P->_PL_LRI += 855;
       break;
     } 
		case 10: {  //I856_LRI
			Marking.P->_PL_LRI -= 855;
			Marking.P->_PL_LRI += 20;
       break;
     } 
		case 11: {  //RRLRI713_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 20;
			Marking.P->_PL_LRI += 853;
       break;
     } 
		case 12: {  //I854_ASensed
			Marking.P->_PL_LRI -= 853;
			Marking.P->_PL_LRI += 21;
       break;
     } 
		case 13: {  //RRLRI714_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 21;
			Marking.P->_PL_LRI += 851;
       break;
     } 
		case 14: {  //I852_RLRI
			Marking.P->_PL_LRI -= 851;
			Marking.P->_PL_LRI += 19;
       break;
     } 
		case 15: {  //I780_LRI
			Marking.P->_PL_LRI -= 19;
			Marking.P->_PL_LRI += 21;
       break;
     } 
		case 16: {  //D717_VRP
			Marking.P->_PL_VRP -= 8;
			Marking.P->_PL_VRP += 9;
       break;
     } 
		case 17: {  //RVP758_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_VRP -= 9;
			Marking.P->_PL_VRP += 849;
       break;
     } 
		case 18: {  //I850_Idle
			Marking.P->_PL_VRP -= 849;
			Marking.P->_PL_VRP += 8;
       break;
     } 
		case 19: {  //I759_Vsig
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_VRP -= 7;
			Marking.P->_PL_VRP += 9;
       break;
     } 
		case 20: {  //RVget760_
			Marking.P->_PL_SIG_Vget -= 1;
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_VRP -= 9;
			Marking.P->_PL_VRP += 847;
       break;
     } 
		case 21: {  //I848_Idle
			Marking.P->_PL_VRP -= 847;
			Marking.P->_PL_VRP += 7;
       break;
     } 
		case 22: {  //RVP768_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_PVARP -= 3;
			Marking.P->_PL_PVARP += 845;
       break;
     } 
		case 23: {  //I846_Idle
			Marking.P->_PL_PVARP -= 845;
			Marking.P->_PL_PVARP += 2;
       break;
     } 
		case 24: {  //RVS769_
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_PVARP -= 3;
			Marking.P->_PL_PVARP += 843;
       break;
     } 
		case 25: {  //I844_Idle
			Marking.P->_PL_PVARP -= 843;
			Marking.P->_PL_PVARP += 2;
       break;
     } 
		case 26: {  //D771_PVARP
			Marking.P->_PL_PVARP -= 0;
			Marking.P->_PL_PVARP += 3;
       break;
     } 
		case 27: {  //I772_Asig
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_PVARP -= 1;
			Marking.P->_PL_PVARP += 3;
       break;
     } 
		case 28: {  //RAget773_
			Marking.P->_PL_SIG_Aget -= 1;
			Marking.P->_PL_SIG_Aget += 1;
			Marking.P->_PL_PVARP -= 3;
			Marking.P->_PL_PVARP += 841;
       break;
     } 
		case 29: {  //I842_Idle
			Marking.P->_PL_PVARP -= 841;
			Marking.P->_PL_PVARP += 1;
       break;
     } 
		case 30: {  //D774_PVAB
			Marking.P->_PL_PVARP -= 2;
			Marking.P->_PL_PVARP += 0;
       break;
     } 
		case 31: {  //I778_URI
			Marking.P->_PL_URI -= 15;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 32: {  //D735_URI
			Marking.P->_PL_URI -= 17;
			Marking.P->_PL_URI += 16;
       break;
     } 
		case 33: {  //I814_IncrClk
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 11;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 34: {  //I815_IncrClk
			Marking.P->_PL_AVI -= 13;
			Marking.P->_PL_AVI += 10;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 35: {  //I816_IncrClk
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_AVI -= 12;
			Marking.P->_PL_AVI += 14;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 36: {  //RVS817_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 10;
			Marking.P->_PL_AVI += 14;
			Marking.P->_PL_URI -= 17;
			Marking.P->_PL_URI += 15;
       break;
     } 
		case 37: {  //RVS819_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 13;
			Marking.P->_PL_AVI += 14;
			Marking.P->_PL_URI -= 17;
			Marking.P->_PL_URI += 15;
       break;
     } 
		case 38: {  //RVS820_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 12;
			Marking.P->_PL_AVI += 14;
			Marking.P->_PL_URI -= 17;
			Marking.P->_PL_URI += 15;
       break;
     } 
		case 39: {  //I821_IncrClk
			Marking.P->_PL_AVI -= 10;
			Marking.P->_PL_AVI += 10;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 40: {  //I822_IncrClk
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 11;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 41: {  //D726_q0
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 4;
       break;
     } 
		case 42: {  //RAS824_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 5;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 10;
       break;
     } 
		case 43: {  //RAP825_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 5;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 10;
       break;
     } 
		case 44: {  //RAS826_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 5;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 13;
       break;
     } 
		case 45: {  //RAP827_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 5;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 13;
       break;
     } 
		case 46: {  //I828_TAVI
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_TAVIcmp -= 4;
			Marking.P->_PL_TAVIcmp += 5;
			Marking.P->_PL_AVI -= 10;
			Marking.P->_PL_AVI += 14;
			Marking.P->_PL_URI -= 17;
			Marking.P->_PL_URI += 15;
       break;
     } 
		case 47: {  //I829_TAVI
			Marking.P->_PL_TAVIcmp -= 4;
			Marking.P->_PL_TAVIcmp += 5;
			Marking.P->_PL_AVI -= 13;
			Marking.P->_PL_AVI += 12;
       break;
     } 
		case 48: {  //I830_TAVI
			Marking.P->_PL_TAVIcmp -= 4;
			Marking.P->_PL_TAVIcmp += 5;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 11;
       break;
     } 
		case 49: {  //I831_TAVI
			Marking.P->_PL_TAVIcmp -= 4;
			Marking.P->_PL_TAVIcmp += 5;
			Marking.P->_PL_AVI -= 12;
			Marking.P->_PL_AVI += 12;
       break;
     } 
		case 50: {  //I832_TAVI
			Marking.P->_PL_TAVIcmp -= 4;
			Marking.P->_PL_TAVIcmp += 5;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 14;
       break;
     } 
		case 51: {  //RAS833_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 10;
       break;
     } 
		case 52: {  //RAP834_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 10;
       break;
     } 
		case 53: {  //RAS835_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 13;
       break;
     } 
		case 54: {  //RAP836_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 13;
       break;
     } 
	}
}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(size_t t )const {
switch (t){
	case 7:	//D723_LRI
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double)  (PM_TLRI  - PM_TAVI ) ) ;
	}

		break;
	case 26:	//D771_PVARP
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double)  (PM_TPVARP  - PM_TPVAB ) ) ;
	}

		break;
	case 41:	//D726_q0
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) PM_TAVI ) ;
	}

		break;
	case 30:	//D774_PVAB
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) PM_TPVAB ) ;
	}

		break;
	case 32:	//D735_URI
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) PM_TURI ) ;
	}

		break;
	case 16:	//D717_VRP
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) PM_TVRP ) ;
	}

		break;
	default:	//EMPTY_AP,EMPTY_AS,EMPTY_Aget,EMPTY_RLRI,EMPTY_VP,EMPTY_VS,EMPTY_Vget,I782_LRI,RAS724_,I856_LRI,RRLRI713_,I854_ASensed,RRLRI714_,I852_RLRI,I780_LRI,RVP758_,I850_Idle,I759_Vsig,RVget760_,I848_Idle,RVP768_,I846_Idle,RVS769_,I844_Idle,I772_Asig,RAget773_,I842_Idle,I778_URI,I814_IncrClk,I815_IncrClk,I816_IncrClk,RVS817_RURI,RVS819_RURI,RVS820_RURI,I821_IncrClk,I822_IncrClk,RAS824_RTAVI,RAP825_RTAVI,RAS826_RTAVI,RAP827_RTAVI,I828_TAVI,I829_TAVI,I830_TAVI,I831_TAVI,I832_TAVI,RAS833_RTAVI,RAP834_RTAVI,RAS835_RTAVI,RAP836_RTAVI,
	{
		ParamDistr[0]= ( double ) 0 ;
	}

}
}

double SPN::GetPriority(size_t t)const {
switch (t){
	case 26:	//D771_PVARP
	case 30:	//D774_PVAB
		return (double)0.94 ;

		break;
	case 41:	//D726_q0
		return (double)0.95 ;

		break;
	case 16:	//D717_VRP
		return (double)0.96 ;

		break;
	case 32:	//D735_URI
		return (double)0.98 ;

		break;
	case 7:	//D723_LRI
		return (double)0.99 ;

		break;
	case 23:	//I846_Idle
	case 25:	//I844_Idle
	case 27:	//I772_Asig
	case 29:	//I842_Idle
		return (double)1.94 ;

		break;
	case 46:	//I828_TAVI
	case 47:	//I829_TAVI
	case 48:	//I830_TAVI
	case 49:	//I831_TAVI
	case 50:	//I832_TAVI
		return (double)1.95 ;

		break;
	case 18:	//I850_Idle
	case 19:	//I759_Vsig
	case 21:	//I848_Idle
		return (double)1.96 ;

		break;
	case 31:	//I778_URI
	case 33:	//I814_IncrClk
	case 34:	//I815_IncrClk
	case 35:	//I816_IncrClk
	case 39:	//I821_IncrClk
	case 40:	//I822_IncrClk
		return (double)1.98 ;

		break;
	case 8:	//I782_LRI
	case 10:	//I856_LRI
	case 12:	//I854_ASensed
	case 14:	//I852_RLRI
	case 15:	//I780_LRI
		return (double)1.99 ;

		break;
	case 0:	//EMPTY_AP
	case 1:	//EMPTY_AS
	case 2:	//EMPTY_Aget
	case 3:	//EMPTY_RLRI
	case 4:	//EMPTY_VP
	case 5:	//EMPTY_VS
	case 6:	//EMPTY_Vget
		return (double)3 ;

		break;
	case 9:	//RAS724_
	case 11:	//RRLRI713_
	case 13:	//RRLRI714_
	case 17:	//RVP758_
	case 20:	//RVget760_
	case 22:	//RVP768_
	case 24:	//RVS769_
	case 28:	//RAget773_
		return (double)3.99 ;

		break;
	default:	//RVS817_RURI,RVS819_RURI,RVS820_RURI,RAS824_RTAVI,RAP825_RTAVI,RAS826_RTAVI,RAP827_RTAVI,RAS833_RTAVI,RAP834_RTAVI,RAS835_RTAVI,RAP836_RTAVI,
		return (double)3.97 ;

}
}

double SPN::GetWeight(size_t t)const{
		return (double)1 ;

}

void SPN::reset() {
	Marking.resetToInitMarking();
}

