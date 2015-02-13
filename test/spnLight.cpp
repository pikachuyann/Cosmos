#include "spnLight.hpp"
#define PL_SIG_AP_LP 0
#define PL_SIG_AS_LP 1
#define PL_SIG_RLRI_LP 2
#define PL_SIG_VP_LP 3
#define PL_SIG_VS_LP 4
#define PL_SIG_Vget_LP 5
#define PL_PVARP_LP 6
#define PL_Parameter_Serial_LP 7
#define PL_SerialPort_LP 8
#define PL_TAVIcmp_LP 9
#define PL_AVI_LP 10
#define PL_URI_LP 11
#define PL_VRP_LP 12
#define PL_LRI_LP 13
#define TR_EMPTY_AP_RT 0
#define TR_EMPTY_AS_RT 1
#define TR_EMPTY_RLRI_RT 2
#define TR_EMPTY_VP_RT 3
#define TR_EMPTY_VS_RT 4
#define TR_EMPTY_Vget_RT 5
#define TR_D723_LRI_RT 6
#define TR_I858_LRI_RT 7
#define TR_RAS724__RT 8
#define TR_I956_LRI_RT 9
#define TR_RRLRI713__RT 10
#define TR_I954_ASensed_RT 11
#define TR_RRLRI714__RT 12
#define TR_I952_RLRI_RT 13
#define TR_I856_LRI_RT 14
#define TR_D717_VRP_RT 15
#define TR_RVP758__RT 16
#define TR_I950_Idle_RT 17
#define TR_I759_Vsig_RT 18
#define TR_RVget760__RT 19
#define TR_I948_Idle_RT 20
#define TR_I854_URI_RT 21
#define TR_D735_URI_RT 22
#define TR_I852_init_RT 23
#define TR_I905_IncrClk_RT 24
#define TR_I906_IncrClk_RT 25
#define TR_I907_IncrClk_RT 26
#define TR_RVS908_RURI_RT 27
#define TR_RVS910_RURI_RT 28
#define TR_RVS911_RURI_RT 29
#define TR_I912_IncrClk_RT 30
#define TR_I913_IncrClk_RT 31
#define TR_D726_q0_RT 32
#define TR_RAS915_RTAVI_RT 33
#define TR_RAP916_RTAVI_RT 34
#define TR_RAS917_RTAVI_RT 35
#define TR_RAP918_RTAVI_RT 36
#define TR_I919_TAVI_RT 37
#define TR_I920_TAVI_RT 38
#define TR_I921_TAVI_RT 39
#define TR_I922_TAVI_RT 40
#define TR_I923_TAVI_RT 41
#define TR_RAS924_RTAVI_RT 42
#define TR_RAP925_RTAVI_RT 43
#define TR_RAS926_RTAVI_RT 44
#define TR_RAP927_RTAVI_RT 45
#define TR_C809_OkHeader_RT 46
#define TR_C796_DataReceived_RT 47
#define TR_C808_EndHeader_RT 48
#define TR_C795_DataReceived_RT 49
#define TR_I848_init_RT 50
#define TR_C837_EndHeaderPar_RT 51
#define TR_C805_EndHeader_RT 52
#define TR_C835_EndHeaderPar_RT 53
#define TR_C821_DataReceived_RT 54
#define TR_RVP768__RT 55
#define TR_I946_Idle_RT 56
#define TR_RVS769__RT 57
#define TR_I944_Idle_RT 58
#define TR_D771_PVARP_RT 59
#define TR_I772_Asig_RT 60
#define TR_D774_PVAB_RT 61
#define TR_C901_Aget_RT 62
#define TR_C902_Aget_RT 63
#define TR_C903_Aget_RT 64
#define TR_I929_SREC_RT 65
#define TR_I930_SREC_RT 66
#define TR_I931_SREC_RT 67
#define TR_I932_SREC_RT 68
#define TR_I933_SREC_RT 69
#define TR_I934_SREC_RT 70
#define TR_I935_SREC_RT 71
#define TR_I936_SREC_RT 72
#define TR_I937_SREC_RT 73
#define TR_I938_SREC_RT 74

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
	const int _nb_Place_SIG_RLRI=2;
	const int _nb_Place_SIG_VP=3;
	const int _nb_Place_SIG_VS=4;
	const int _nb_Place_SIG_Vget=5;
	const int _nb_Place_PVARP=6;
	const int _nb_Place_Parameter_Serial=7;
	const int _nb_Place_SerialPort=8;
	const int _nb_Place_TAVIcmp=9;
	const int _nb_Place_AVI=10;
	const int _nb_Place_URI=11;
	const int _nb_Place_VRP=12;
	const int _nb_Place_LRI=13;
#include "magicLight.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking(){
	magicReset();
	P->_PL_SIG_AP =0;
	P->_PL_SIG_AS =0;
	P->_PL_SIG_RLRI =0;
	P->_PL_SIG_VP =0;
	P->_PL_SIG_VS =0;
	P->_PL_SIG_Vget =0;
	P->_PL_PVARP =16;
	P->_PL_Parameter_Serial =2;
	P->_PL_SerialPort =1;
	P->_PL_TAVIcmp =18;
	P->_PL_AVI =27;
	P->_PL_URI =29;
	P->_PL_VRP =22;
	P->_PL_LRI =35;
}


abstractMarking::abstractMarking() {
	P= new abstractMarkingImpl;
	resetToInitMarking();
}

abstractMarking::~abstractMarking() {
	delete(P);
}


void abstractMarking::printHeader()const{
::print("SIG_AP	");
::print("SIG_AS	");
::print("SIG_RLRI	");
::print("SIG_VP	");
::print("SIG_VS	");
::print("SIG_Vget	");
::print("PVARP	");
::print("Parameter_Serial	");
::print("SerialPort	");
::print("TAVIcmp	");
::print("AVI	");
::print("URI	");
::print("VRP	");
::print("LRI	");
}

void abstractMarking::print()const{
print_magic(P->_PL_SIG_AP);
::print("	");
print_magic(P->_PL_SIG_AS);
::print("	");
print_magic(P->_PL_SIG_RLRI);
::print("	");
print_magic(P->_PL_SIG_VP);
::print("	");
print_magic(P->_PL_SIG_VS);
::print("	");
print_magic(P->_PL_SIG_Vget);
::print("	");
print_magic(P->_PL_PVARP);
::print("	");
print_magic(P->_PL_Parameter_Serial);
::print("	");
print_magic(P->_PL_SerialPort);
::print("	");
print_magic(P->_PL_TAVIcmp);
::print("	");
print_magic(P->_PL_AVI);
::print("	");
print_magic(P->_PL_URI);
::print("	");
print_magic(P->_PL_VRP);
::print("	");
print_magic(P->_PL_LRI);
::print("	");
}
SPN::SPN():
pl(14), tr(75) {
}

bool SPN::IsEnabled(TR_PL_ID t)const {
	if(!magicConditional(t))return false;
switch (t){
	case 34:	//RAP916_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 18) return false;
    if( Marking.P->_PL_AVI != 24) return false;
    return true;

		break;
	case 36:	//RAP918_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 18) return false;
    if( Marking.P->_PL_AVI != 27) return false;
    return true;

		break;
	case 43:	//RAP925_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 19) return false;
    if( Marking.P->_PL_AVI != 24) return false;
    return true;

		break;
	case 45:	//RAP927_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 19) return false;
    if( Marking.P->_PL_AVI != 27) return false;
    return true;

		break;
	case 0:	//EMPTY_AP
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    return true;

		break;
	case 8:	//RAS724_
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_LRI != 35) return false;
    return true;

		break;
	case 33:	//RAS915_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 18) return false;
    if( Marking.P->_PL_AVI != 24) return false;
    return true;

		break;
	case 35:	//RAS917_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 18) return false;
    if( Marking.P->_PL_AVI != 27) return false;
    return true;

		break;
	case 42:	//RAS924_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 19) return false;
    if( Marking.P->_PL_AVI != 24) return false;
    return true;

		break;
	case 44:	//RAS926_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 19) return false;
    if( Marking.P->_PL_AVI != 27) return false;
    return true;

		break;
	case 1:	//EMPTY_AS
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    return true;

		break;
	case 10:	//RRLRI713_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 34) return false;
    return true;

		break;
	case 12:	//RRLRI714_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 35) return false;
    return true;

		break;
	case 2:	//EMPTY_RLRI
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    return true;

		break;
	case 55:	//RVP768_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_PVARP != 16) return false;
    return true;

		break;
	case 16:	//RVP758_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_VRP != 22) return false;
    return true;

		break;
	case 3:	//EMPTY_VP
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    return true;

		break;
	case 27:	//RVS908_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 23) return false;
    if( Marking.P->_PL_URI != 31) return false;
    return true;

		break;
	case 29:	//RVS911_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 25) return false;
    if( Marking.P->_PL_URI != 31) return false;
    return true;

		break;
	case 28:	//RVS910_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 26) return false;
    if( Marking.P->_PL_URI != 31) return false;
    return true;

		break;
	case 57:	//RVS769_
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_PVARP != 16) return false;
    return true;

		break;
	case 4:	//EMPTY_VS
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    return true;

		break;
	case 19:	//RVget760_
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    if( Marking.P->_PL_VRP != 22) return false;
    return true;

		break;
	case 5:	//EMPTY_Vget
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    return true;

		break;
	case 7:	//I858_LRI
    if (Marking.P->_PL_SIG_AP >= 1) return false;
    if( Marking.P->_PL_LRI != 32) return false;
    return true;

		break;
	case 60:	//I772_Asig
    if (Marking.P->_PL_SIG_AS >= 1) return false;
    if( Marking.P->_PL_PVARP != 14) return false;
    return true;

		break;
	case 26:	//I907_IncrClk
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_AVI != 25) return false;
    if( Marking.P->_PL_URI != 30) return false;
    return true;

		break;
	case 37:	//I919_TAVI
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_TAVIcmp != 17) return false;
    if( Marking.P->_PL_AVI != 23) return false;
    if( Marking.P->_PL_URI != 31) return false;
    return true;

		break;
	case 18:	//I759_Vsig
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VS >= 1) return false;
    if( Marking.P->_PL_VRP != 20) return false;
    return true;

		break;
	case 46:	//C809_OkHeader
    if (Marking.P->_PL_SIG_Vget >= 1) return false;
    if( Marking.P->_PL_Parameter_Serial != 7) return false;
    return true;

		break;
	case 30:	//I912_IncrClk
    if( Marking.P->_PL_AVI != 23) return false;
    if( Marking.P->_PL_URI != 30) return false;
    return true;

		break;
	case 31:	//I913_IncrClk
    if( Marking.P->_PL_AVI != 24) return false;
    if( Marking.P->_PL_URI != 30) return false;
    return true;

		break;
	case 25:	//I906_IncrClk
    if( Marking.P->_PL_AVI != 26) return false;
    if( Marking.P->_PL_URI != 30) return false;
    return true;

		break;
	case 24:	//I905_IncrClk
    if( Marking.P->_PL_AVI != 27) return false;
    if( Marking.P->_PL_URI != 30) return false;
    return true;

		break;
	case 14:	//I856_LRI
    if( Marking.P->_PL_LRI != 33) return false;
    return true;

		break;
	case 6:	//D723_LRI
    if( Marking.P->_PL_LRI != 35) return false;
    return true;

		break;
	case 13:	//I952_RLRI
    if( Marking.P->_PL_LRI != 951) return false;
    return true;

		break;
	case 11:	//I954_ASensed
    if( Marking.P->_PL_LRI != 953) return false;
    return true;

		break;
	case 9:	//I956_LRI
    if( Marking.P->_PL_LRI != 955) return false;
    return true;

		break;
	case 63:	//C902_Aget
    if( Marking.P->_PL_PVARP != 13) return false;
    if( Marking.P->_PL_Parameter_Serial != 7) return false;
    return true;

		break;
	case 59:	//D771_PVARP
    if( Marking.P->_PL_PVARP != 13) return false;
    return true;

		break;
	case 64:	//C903_Aget
    if( Marking.P->_PL_PVARP != 15) return false;
    if( Marking.P->_PL_Parameter_Serial != 7) return false;
    return true;

		break;
	case 61:	//D774_PVAB
    if( Marking.P->_PL_PVARP != 15) return false;
    return true;

		break;
	case 62:	//C901_Aget
    if( Marking.P->_PL_PVARP != 16) return false;
    if( Marking.P->_PL_Parameter_Serial != 7) return false;
    return true;

		break;
	case 58:	//I944_Idle
    if( Marking.P->_PL_PVARP != 943) return false;
    return true;

		break;
	case 56:	//I946_Idle
    if( Marking.P->_PL_PVARP != 945) return false;
    return true;

		break;
	case 68:	//I932_SREC
    if( Marking.P->_PL_Parameter_Serial != 10) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 74:	//I938_SREC
    if( Marking.P->_PL_Parameter_Serial != 11) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 69:	//I933_SREC
    if( Marking.P->_PL_Parameter_Serial != 12) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 50:	//I848_init
    if( Marking.P->_PL_Parameter_Serial != 2) return false;
    return true;

		break;
	case 71:	//I935_SREC
    if( Marking.P->_PL_Parameter_Serial != 3) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 51:	//C837_EndHeaderPar
	case 53:	//C835_EndHeaderPar
    if( Marking.P->_PL_Parameter_Serial != 3) return false;
    return true;

		break;
	case 65:	//I929_SREC
    if( Marking.P->_PL_Parameter_Serial != 4) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 66:	//I930_SREC
    if( Marking.P->_PL_Parameter_Serial != 5) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 67:	//I931_SREC
    if( Marking.P->_PL_Parameter_Serial != 6) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 72:	//I936_SREC
    if( Marking.P->_PL_Parameter_Serial != 7) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 73:	//I937_SREC
    if( Marking.P->_PL_Parameter_Serial != 8) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 48:	//C808_EndHeader
	case 52:	//C805_EndHeader
    if( Marking.P->_PL_Parameter_Serial != 8) return false;
    return true;

		break;
	case 70:	//I934_SREC
    if( Marking.P->_PL_Parameter_Serial != 9) return false;
    if( Marking.P->_PL_SerialPort != 0) return false;
    return true;

		break;
	case 39:	//I921_TAVI
    if( Marking.P->_PL_TAVIcmp != 17) return false;
    if( Marking.P->_PL_AVI != 24) return false;
    return true;

		break;
	case 40:	//I922_TAVI
    if( Marking.P->_PL_TAVIcmp != 17) return false;
    if( Marking.P->_PL_AVI != 25) return false;
    return true;

		break;
	case 38:	//I920_TAVI
    if( Marking.P->_PL_TAVIcmp != 17) return false;
    if( Marking.P->_PL_AVI != 26) return false;
    return true;

		break;
	case 41:	//I923_TAVI
    if( Marking.P->_PL_TAVIcmp != 17) return false;
    if( Marking.P->_PL_AVI != 27) return false;
    return true;

		break;
	case 32:	//D726_q0
    if( Marking.P->_PL_TAVIcmp != 19) return false;
    return true;

		break;
	case 21:	//I854_URI
    if( Marking.P->_PL_URI != 28) return false;
    return true;

		break;
	case 23:	//I852_init
    if( Marking.P->_PL_URI != 29) return false;
    return true;

		break;
	case 22:	//D735_URI
    if( Marking.P->_PL_URI != 31) return false;
    return true;

		break;
	case 15:	//D717_VRP
    if( Marking.P->_PL_VRP != 21) return false;
    return true;

		break;
	case 20:	//I948_Idle
    if( Marking.P->_PL_VRP != 947) return false;
    return true;

		break;
	case 17:	//I950_Idle
    if( Marking.P->_PL_VRP != 949) return false;
    return true;

		break;
	default:	//C796_DataReceived,C795_DataReceived,C821_DataReceived,
    if( Marking.P->_PL_Parameter_Serial != 11) return false;
    return true;

}
}

void SPN::fire(TR_PL_ID t,  REAL_TYPE time){
	lastTransition = t;
	magicUpdate(t,time);
	switch(t){
		case 0: {  //EMPTY_AP
			Marking.P->_PL_SIG_AP -= 1;
       break;
     } 
		case 1: {  //EMPTY_AS
			Marking.P->_PL_SIG_AS -= 1;
       break;
     } 
		case 2: {  //EMPTY_RLRI
			Marking.P->_PL_SIG_RLRI -= 1;
       break;
     } 
		case 3: {  //EMPTY_VP
			Marking.P->_PL_SIG_VP -= 1;
       break;
     } 
		case 4: {  //EMPTY_VS
			Marking.P->_PL_SIG_VS -= 1;
       break;
     } 
		case 5: {  //EMPTY_Vget
			Marking.P->_PL_SIG_Vget -= 1;
       break;
     } 
		case 6: {  //D723_LRI
			Marking.P->_PL_LRI -= 35;
			Marking.P->_PL_LRI += 32;
       break;
     } 
		case 7: {  //I858_LRI
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_LRI -= 32;
			Marking.P->_PL_LRI += 35;
       break;
     } 
		case 8: {  //RAS724_
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_LRI -= 35;
			Marking.P->_PL_LRI += 955;
       break;
     } 
		case 9: {  //I956_LRI
			Marking.P->_PL_LRI -= 955;
			Marking.P->_PL_LRI += 34;
       break;
     } 
		case 10: {  //RRLRI713_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 34;
			Marking.P->_PL_LRI += 953;
       break;
     } 
		case 11: {  //I954_ASensed
			Marking.P->_PL_LRI -= 953;
			Marking.P->_PL_LRI += 35;
       break;
     } 
		case 12: {  //RRLRI714_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 35;
			Marking.P->_PL_LRI += 951;
       break;
     } 
		case 13: {  //I952_RLRI
			Marking.P->_PL_LRI -= 951;
			Marking.P->_PL_LRI += 33;
       break;
     } 
		case 14: {  //I856_LRI
			Marking.P->_PL_LRI -= 33;
			Marking.P->_PL_LRI += 35;
       break;
     } 
		case 15: {  //D717_VRP
			Marking.P->_PL_VRP -= 21;
			Marking.P->_PL_VRP += 22;
       break;
     } 
		case 16: {  //RVP758_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_VRP -= 22;
			Marking.P->_PL_VRP += 949;
       break;
     } 
		case 17: {  //I950_Idle
			Marking.P->_PL_VRP -= 949;
			Marking.P->_PL_VRP += 21;
       break;
     } 
		case 18: {  //I759_Vsig
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_VRP -= 20;
			Marking.P->_PL_VRP += 22;
       break;
     } 
		case 19: {  //RVget760_
			Marking.P->_PL_SIG_Vget -= 1;
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_VRP -= 22;
			Marking.P->_PL_VRP += 947;
       break;
     } 
		case 20: {  //I948_Idle
			Marking.P->_PL_VRP -= 947;
			Marking.P->_PL_VRP += 20;
       break;
     } 
		case 21: {  //I854_URI
			Marking.P->_PL_URI -= 28;
			Marking.P->_PL_URI += 31;
       break;
     } 
		case 22: {  //D735_URI
			Marking.P->_PL_URI -= 31;
			Marking.P->_PL_URI += 30;
       break;
     } 
		case 23: {  //I852_init
			Marking.P->_PL_URI -= 29;
			Marking.P->_PL_URI += 31;
       break;
     } 
		case 24: {  //I905_IncrClk
			Marking.P->_PL_AVI -= 27;
			Marking.P->_PL_AVI += 24;
			Marking.P->_PL_URI -= 30;
			Marking.P->_PL_URI += 31;
       break;
     } 
		case 25: {  //I906_IncrClk
			Marking.P->_PL_AVI -= 26;
			Marking.P->_PL_AVI += 23;
			Marking.P->_PL_URI -= 30;
			Marking.P->_PL_URI += 31;
       break;
     } 
		case 26: {  //I907_IncrClk
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_AVI -= 25;
			Marking.P->_PL_AVI += 27;
			Marking.P->_PL_URI -= 30;
			Marking.P->_PL_URI += 31;
       break;
     } 
		case 27: {  //RVS908_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 23;
			Marking.P->_PL_AVI += 27;
			Marking.P->_PL_URI -= 31;
			Marking.P->_PL_URI += 28;
       break;
     } 
		case 28: {  //RVS910_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 26;
			Marking.P->_PL_AVI += 27;
			Marking.P->_PL_URI -= 31;
			Marking.P->_PL_URI += 28;
       break;
     } 
		case 29: {  //RVS911_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 25;
			Marking.P->_PL_AVI += 27;
			Marking.P->_PL_URI -= 31;
			Marking.P->_PL_URI += 28;
       break;
     } 
		case 30: {  //I912_IncrClk
			Marking.P->_PL_AVI -= 23;
			Marking.P->_PL_AVI += 23;
			Marking.P->_PL_URI -= 30;
			Marking.P->_PL_URI += 31;
       break;
     } 
		case 31: {  //I913_IncrClk
			Marking.P->_PL_AVI -= 24;
			Marking.P->_PL_AVI += 24;
			Marking.P->_PL_URI -= 30;
			Marking.P->_PL_URI += 31;
       break;
     } 
		case 32: {  //D726_q0
			Marking.P->_PL_TAVIcmp -= 19;
			Marking.P->_PL_TAVIcmp += 17;
       break;
     } 
		case 33: {  //RAS915_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 18;
			Marking.P->_PL_TAVIcmp += 19;
			Marking.P->_PL_AVI -= 24;
			Marking.P->_PL_AVI += 23;
       break;
     } 
		case 34: {  //RAP916_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 18;
			Marking.P->_PL_TAVIcmp += 19;
			Marking.P->_PL_AVI -= 24;
			Marking.P->_PL_AVI += 23;
       break;
     } 
		case 35: {  //RAS917_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 18;
			Marking.P->_PL_TAVIcmp += 19;
			Marking.P->_PL_AVI -= 27;
			Marking.P->_PL_AVI += 26;
       break;
     } 
		case 36: {  //RAP918_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 18;
			Marking.P->_PL_TAVIcmp += 19;
			Marking.P->_PL_AVI -= 27;
			Marking.P->_PL_AVI += 26;
       break;
     } 
		case 37: {  //I919_TAVI
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_TAVIcmp -= 17;
			Marking.P->_PL_TAVIcmp += 18;
			Marking.P->_PL_AVI -= 23;
			Marking.P->_PL_AVI += 27;
			Marking.P->_PL_URI -= 31;
			Marking.P->_PL_URI += 28;
       break;
     } 
		case 38: {  //I920_TAVI
			Marking.P->_PL_TAVIcmp -= 17;
			Marking.P->_PL_TAVIcmp += 18;
			Marking.P->_PL_AVI -= 26;
			Marking.P->_PL_AVI += 25;
       break;
     } 
		case 39: {  //I921_TAVI
			Marking.P->_PL_TAVIcmp -= 17;
			Marking.P->_PL_TAVIcmp += 18;
			Marking.P->_PL_AVI -= 24;
			Marking.P->_PL_AVI += 24;
       break;
     } 
		case 40: {  //I922_TAVI
			Marking.P->_PL_TAVIcmp -= 17;
			Marking.P->_PL_TAVIcmp += 18;
			Marking.P->_PL_AVI -= 25;
			Marking.P->_PL_AVI += 25;
       break;
     } 
		case 41: {  //I923_TAVI
			Marking.P->_PL_TAVIcmp -= 17;
			Marking.P->_PL_TAVIcmp += 18;
			Marking.P->_PL_AVI -= 27;
			Marking.P->_PL_AVI += 27;
       break;
     } 
		case 42: {  //RAS924_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 19;
			Marking.P->_PL_TAVIcmp += 19;
			Marking.P->_PL_AVI -= 24;
			Marking.P->_PL_AVI += 23;
       break;
     } 
		case 43: {  //RAP925_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 19;
			Marking.P->_PL_TAVIcmp += 19;
			Marking.P->_PL_AVI -= 24;
			Marking.P->_PL_AVI += 23;
       break;
     } 
		case 44: {  //RAS926_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 19;
			Marking.P->_PL_TAVIcmp += 19;
			Marking.P->_PL_AVI -= 27;
			Marking.P->_PL_AVI += 26;
       break;
     } 
		case 45: {  //RAP927_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 19;
			Marking.P->_PL_TAVIcmp += 19;
			Marking.P->_PL_AVI -= 27;
			Marking.P->_PL_AVI += 26;
       break;
     } 
		case 46: {  //C809_OkHeader
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_Parameter_Serial -= 7;
			Marking.P->_PL_Parameter_Serial += 12;
       break;
     } 
		case 47: {  //C796_DataReceived
			Marking.P->_PL_Parameter_Serial -= 11;
			Marking.P->_PL_Parameter_Serial += 12;
       break;
     } 
		case 48: {  //C808_EndHeader
			Marking.P->_PL_Parameter_Serial -= 8;
			Marking.P->_PL_Parameter_Serial += 7;
       break;
     } 
		case 49: {  //C795_DataReceived
			Marking.P->_PL_Parameter_Serial -= 11;
			Marking.P->_PL_Parameter_Serial += 10;
       break;
     } 
		case 50: {  //I848_init
			Marking.P->_PL_Parameter_Serial -= 2;
			Marking.P->_PL_Parameter_Serial += 12;
       break;
     } 
		case 51: {  //C837_EndHeaderPar
			Marking.P->_PL_Parameter_Serial -= 3;
			Marking.P->_PL_Parameter_Serial += 12;
       break;
     } 
		case 52: {  //C805_EndHeader
			Marking.P->_PL_Parameter_Serial -= 8;
			Marking.P->_PL_Parameter_Serial += 12;
       break;
     } 
		case 53: {  //C835_EndHeaderPar
			Marking.P->_PL_Parameter_Serial -= 3;
			Marking.P->_PL_Parameter_Serial += 12;
       break;
     } 
		case 54: {  //C821_DataReceived
			Marking.P->_PL_Parameter_Serial -= 11;
			Marking.P->_PL_Parameter_Serial += 6;
       break;
     } 
		case 55: {  //RVP768_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_PVARP -= 16;
			Marking.P->_PL_PVARP += 945;
       break;
     } 
		case 56: {  //I946_Idle
			Marking.P->_PL_PVARP -= 945;
			Marking.P->_PL_PVARP += 15;
       break;
     } 
		case 57: {  //RVS769_
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_PVARP -= 16;
			Marking.P->_PL_PVARP += 943;
       break;
     } 
		case 58: {  //I944_Idle
			Marking.P->_PL_PVARP -= 943;
			Marking.P->_PL_PVARP += 15;
       break;
     } 
		case 59: {  //D771_PVARP
			Marking.P->_PL_PVARP -= 13;
			Marking.P->_PL_PVARP += 16;
       break;
     } 
		case 60: {  //I772_Asig
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_PVARP -= 14;
			Marking.P->_PL_PVARP += 16;
       break;
     } 
		case 61: {  //D774_PVAB
			Marking.P->_PL_PVARP -= 15;
			Marking.P->_PL_PVARP += 13;
       break;
     } 
		case 62: {  //C901_Aget
			Marking.P->_PL_PVARP -= 16;
			Marking.P->_PL_PVARP += 14;
			Marking.P->_PL_Parameter_Serial -= 7;
			Marking.P->_PL_Parameter_Serial += 12;
       break;
     } 
		case 63: {  //C902_Aget
			Marking.P->_PL_PVARP -= 13;
			Marking.P->_PL_PVARP += 13;
			Marking.P->_PL_Parameter_Serial -= 7;
			Marking.P->_PL_Parameter_Serial += 12;
       break;
     } 
		case 64: {  //C903_Aget
			Marking.P->_PL_PVARP -= 15;
			Marking.P->_PL_PVARP += 15;
			Marking.P->_PL_Parameter_Serial -= 7;
			Marking.P->_PL_Parameter_Serial += 12;
       break;
     } 
		case 65: {  //I929_SREC
			Marking.P->_PL_Parameter_Serial -= 4;
			Marking.P->_PL_Parameter_Serial += 3;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
		case 66: {  //I930_SREC
			Marking.P->_PL_Parameter_Serial -= 5;
			Marking.P->_PL_Parameter_Serial += 4;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
		case 67: {  //I931_SREC
			Marking.P->_PL_Parameter_Serial -= 6;
			Marking.P->_PL_Parameter_Serial += 5;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
		case 68: {  //I932_SREC
			Marking.P->_PL_Parameter_Serial -= 10;
			Marking.P->_PL_Parameter_Serial += 9;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
		case 69: {  //I933_SREC
			Marking.P->_PL_Parameter_Serial -= 12;
			Marking.P->_PL_Parameter_Serial += 11;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
		case 70: {  //I934_SREC
			Marking.P->_PL_Parameter_Serial -= 9;
			Marking.P->_PL_Parameter_Serial += 8;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
		case 71: {  //I935_SREC
			Marking.P->_PL_Parameter_Serial -= 3;
			Marking.P->_PL_Parameter_Serial += 3;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
		case 72: {  //I936_SREC
			Marking.P->_PL_Parameter_Serial -= 7;
			Marking.P->_PL_Parameter_Serial += 7;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
		case 73: {  //I937_SREC
			Marking.P->_PL_Parameter_Serial -= 8;
			Marking.P->_PL_Parameter_Serial += 8;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
		case 74: {  //I938_SREC
			Marking.P->_PL_Parameter_Serial -= 11;
			Marking.P->_PL_Parameter_Serial += 11;
			Marking.P->_PL_SerialPort -= 0;
			Marking.P->_PL_SerialPort += 1;
       break;
     } 
	}
}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(TR_PL_ID t )const {
switch (t){
	case 6:	//D723_LRI
	{
		ParamDistr[0]= ( double )  (PM_TLRI  - PM_TAVI ) ;
	}

		break;
	case 59:	//D771_PVARP
	{
		ParamDistr[0]= ( double )  (PM_TPVARP  - PM_TPVAB ) ;
	}

		break;
	case 32:	//D726_q0
	{
		ParamDistr[0]= ( double ) PM_TAVI ;
	}

		break;
	case 61:	//D774_PVAB
	{
		ParamDistr[0]= ( double ) PM_TPVAB ;
	}

		break;
	case 22:	//D735_URI
	{
		ParamDistr[0]= ( double ) PM_TURI ;
	}

		break;
	case 15:	//D717_VRP
	{
		ParamDistr[0]= ( double ) PM_TVRP ;
	}

		break;
	default:	//EMPTY_AP,EMPTY_AS,EMPTY_RLRI,EMPTY_VP,EMPTY_VS,EMPTY_Vget,I858_LRI,RAS724_,I956_LRI,RRLRI713_,I954_ASensed,RRLRI714_,I952_RLRI,I856_LRI,RVP758_,I950_Idle,I759_Vsig,RVget760_,I948_Idle,I854_URI,I852_init,I905_IncrClk,I906_IncrClk,I907_IncrClk,RVS908_RURI,RVS910_RURI,RVS911_RURI,I912_IncrClk,I913_IncrClk,RAS915_RTAVI,RAP916_RTAVI,RAS917_RTAVI,RAP918_RTAVI,I919_TAVI,I920_TAVI,I921_TAVI,I922_TAVI,I923_TAVI,RAS924_RTAVI,RAP925_RTAVI,RAS926_RTAVI,RAP927_RTAVI,C809_OkHeader,C796_DataReceived,C808_EndHeader,C795_DataReceived,I848_init,C837_EndHeaderPar,C805_EndHeader,C835_EndHeaderPar,C821_DataReceived,RVP768_,I946_Idle,RVS769_,I944_Idle,I772_Asig,C901_Aget,C902_Aget,C903_Aget,I929_SREC,I930_SREC,I931_SREC,I932_SREC,I933_SREC,I934_SREC,I935_SREC,I936_SREC,I937_SREC,I938_SREC,
	{
		ParamDistr[0]= ( double ) 0 ;
	}

}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t)const {
switch (t){
	case 59:	//D771_PVARP
	case 61:	//D774_PVAB
		return (double)0.94 ;

		break;
	case 32:	//D726_q0
		return (double)0.95 ;

		break;
	case 15:	//D717_VRP
		return (double)0.96 ;

		break;
	case 22:	//D735_URI
		return (double)0.98 ;

		break;
	case 6:	//D723_LRI
		return (double)0.99 ;

		break;
	case 65:	//I929_SREC
	case 66:	//I930_SREC
	case 67:	//I931_SREC
	case 68:	//I932_SREC
	case 69:	//I933_SREC
	case 70:	//I934_SREC
	case 71:	//I935_SREC
	case 72:	//I936_SREC
	case 73:	//I937_SREC
	case 74:	//I938_SREC
		return (double)1.92 ;

		break;
	case 56:	//I946_Idle
	case 58:	//I944_Idle
	case 60:	//I772_Asig
		return (double)1.94 ;

		break;
	case 37:	//I919_TAVI
	case 38:	//I920_TAVI
	case 39:	//I921_TAVI
	case 40:	//I922_TAVI
	case 41:	//I923_TAVI
		return (double)1.95 ;

		break;
	case 17:	//I950_Idle
	case 18:	//I759_Vsig
	case 20:	//I948_Idle
		return (double)1.96 ;

		break;
	case 21:	//I854_URI
	case 23:	//I852_init
	case 24:	//I905_IncrClk
	case 25:	//I906_IncrClk
	case 26:	//I907_IncrClk
	case 30:	//I912_IncrClk
	case 31:	//I913_IncrClk
		return (double)1.98 ;

		break;
	case 7:	//I858_LRI
	case 9:	//I956_LRI
	case 11:	//I954_ASensed
	case 13:	//I952_RLRI
	case 14:	//I856_LRI
		return (double)1.99 ;

		break;
	case 0:	//EMPTY_AP
	case 1:	//EMPTY_AS
	case 2:	//EMPTY_RLRI
	case 3:	//EMPTY_VP
	case 4:	//EMPTY_VS
	case 5:	//EMPTY_Vget
		return (double)3 ;

		break;
	case 27:	//RVS908_RURI
	case 28:	//RVS910_RURI
	case 29:	//RVS911_RURI
	case 33:	//RAS915_RTAVI
	case 34:	//RAP916_RTAVI
	case 35:	//RAS917_RTAVI
	case 36:	//RAP918_RTAVI
	case 42:	//RAS924_RTAVI
	case 43:	//RAP925_RTAVI
	case 44:	//RAS926_RTAVI
	case 45:	//RAP927_RTAVI
		return (double)3.97 ;

		break;
	case 8:	//RAS724_
	case 10:	//RRLRI713_
	case 12:	//RRLRI714_
	case 16:	//RVP758_
	case 19:	//RVget760_
	case 55:	//RVP768_
	case 57:	//RVS769_
		return (double)3.99 ;

		break;
	default:	//C809_OkHeader,C796_DataReceived,C808_EndHeader,C795_DataReceived,I848_init,C837_EndHeaderPar,C805_EndHeader,C835_EndHeaderPar,C821_DataReceived,C901_Aget,C902_Aget,C903_Aget,
		return (double)1.93 ;

}
}

REAL_TYPE SPN::GetWeight(TR_PL_ID t)const{
		return (double)1 ;

}

void SPN::reset() {
	Marking.resetToInitMarking();
}

