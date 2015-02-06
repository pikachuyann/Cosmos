#include "spnLight.hpp"
#define PL_SIG_AP_LP 0
#define PL_SIG_APOut_LP 1
#define PL_SIG_AS_LP 2
#define PL_SIG_Aget_LP 3
#define PL_SIG_AgetOut_LP 4
#define PL_SIG_NextVtrBeat_LP 5
#define PL_SIG_RLRI_LP 6
#define PL_SIG_VP_LP 7
#define PL_SIG_VPOut_LP 8
#define PL_SIG_VS_LP 9
#define PL_SIG_Vbeat_LP 10
#define PL_SIG_Vget_LP 11
#define PL_SIG_VgetOut_LP 12
#define PL_Atrium_LP 13
#define PL_RAConductor_LP 14
#define PL_Ventricle_LP 15
#define PL_AVJOut_LP 16
#define PL_AVJ_LP 17
#define PL_A_dV_LP 18
#define PL_RVConductor_LP 19
#define PL_SANodeEctopic_LP 20
#define PL_SANode_LP 21
#define PL_TAVIcmp_LP 22
#define PL_AVI_LP 23
#define PL_URI_LP 24
#define PL_PVARP_LP 25
#define PL_VRP_LP 26
#define PL_LRI_LP 27
#define PL_VRG_LP 28
#define PL_VtrNoiseGenerator_LP 29
#define PL_VRGEctopic_LP 30
#define PL_AtrNoiseGenerator_LP 31
#define TR_EMPTY_AP_RT 0
#define TR_EMPTY_APOut_RT 1
#define TR_EMPTY_AS_RT 2
#define TR_EMPTY_Aget_RT 3
#define TR_EMPTY_AgetOut_RT 4
#define TR_EMPTY_NextVtrBeat_RT 5
#define TR_EMPTY_RLRI_RT 6
#define TR_EMPTY_VP_RT 7
#define TR_EMPTY_VPOut_RT 8
#define TR_EMPTY_VS_RT 9
#define TR_EMPTY_Vbeat_RT 10
#define TR_EMPTY_Vget_RT 11
#define TR_EMPTY_VgetOut_RT 12
#define TR_D10_q0_RT 13
#define TR_I818_q0_RT 14
#define TR_D279_q0_RT 15
#define TR_I808_q0_RT 16
#define TR_D276_q0_RT 17
#define TR_I802_q0_RT 18
#define TR_D266_Wait4VBeat_RT 19
#define TR_I796_Wait4VBeat_RT 20
#define TR_RNextVtrBeat267__RT 21
#define TR_I987_Wait4VSynch_RT 22
#define TR_RNextVtrBeat491__RT 23
#define TR_I985_NextVtrBeat_RT 24
#define TR_I794_Wait4VBeat_RT 25
#define TR_D723_LRI_RT 26
#define TR_I782_LRI_RT 27
#define TR_RAS724__RT 28
#define TR_I983_LRI_RT 29
#define TR_RRLRI713__RT 30
#define TR_I981_ASensed_RT 31
#define TR_RRLRI714__RT 32
#define TR_I979_RLRI_RT 33
#define TR_I780_LRI_RT 34
#define TR_D717_VRP_RT 35
#define TR_RVP758__RT 36
#define TR_I977_Idle_RT 37
#define TR_I759_Vsig_RT 38
#define TR_RVget760__RT 39
#define TR_I975_Idle_RT 40
#define TR_RVP768__RT 41
#define TR_I973_Idle_RT 42
#define TR_RVS769__RT 43
#define TR_I971_Idle_RT 44
#define TR_D771_PVARP_RT 45
#define TR_I772_Asig_RT 46
#define TR_RAget773__RT 47
#define TR_I969_Idle_RT 48
#define TR_D774_PVAB_RT 49
#define TR_I778_URI_RT 50
#define TR_D735_URI_RT 51
#define TR_I902_IncrClk_RT 52
#define TR_I903_IncrClk_RT 53
#define TR_I904_IncrClk_RT 54
#define TR_RVS905_RURI_RT 55
#define TR_RVS907_RURI_RT 56
#define TR_RVS908_RURI_RT 57
#define TR_I909_IncrClk_RT 58
#define TR_I910_IncrClk_RT 59
#define TR_D726_q0_RT 60
#define TR_RAS912_RTAVI_RT 61
#define TR_RAP913_RTAVI_RT 62
#define TR_RAS914_RTAVI_RT 63
#define TR_RAP915_RTAVI_RT 64
#define TR_I916_TAVI_RT 65
#define TR_I917_TAVI_RT 66
#define TR_I918_TAVI_RT 67
#define TR_I919_TAVI_RT 68
#define TR_I920_TAVI_RT 69
#define TR_RAS921_RTAVI_RT 70
#define TR_RAP922_RTAVI_RT 71
#define TR_RAS923_RTAVI_RT 72
#define TR_RAP924_RTAVI_RT 73
#define TR_D16_Wait4ABeat_RT 74
#define TR_I798_Wait4ABeat_RT 75
#define TR_D86_q0_RT 76
#define TR_D160_Ante_RT 77
#define TR_D161_Retro_RT 78
#define TR_I792_init_RT 79
#define TR_D651_Ante_RT 80
#define TR_D634_Refractory_RT 81
#define TR_D636_Recovery_RT 82
#define TR_I788_Refractory_RT 83
#define TR_I786_Refractory_RT 84
#define TR_I784_Refractory_RT 85
#define TR_D177_Ante_RT 86
#define TR_D179_Retro_RT 87
#define TR_I875_AVJRetroExit_RT 88
#define TR_I876_AVJAnteExit_RT 89
#define TR_I877_AVJAnteExit_RT 90
#define TR_I878_AVJRetroExit_RT 91
#define TR_I879_AVJAnteExit_RT 92
#define TR_I880_AVJRetroExit_RT 93
#define TR_I882_AVJAnteReached_RT 94
#define TR_I883_AVJAnteReachedHigh_RT 95
#define TR_I884_AVJAnteReachedHigh_RT 96
#define TR_I885_AVJAnteReached_RT 97
#define TR_I886_AVJAnteReached_RT 98
#define TR_I887_AVJAnteReachedHigh_RT 99
#define TR_I889_anteAVJ_RT 100
#define TR_I890_anteAVJ_RT 101
#define TR_I891_anteAVJ_RT 102
#define TR_I892_AVJRetroReached_RT 103
#define TR_I893_AVJRetroReached_RT 104
#define TR_I894_AVJRetroReached_RT 105
#define TR_D248_Refractory_RT 106
#define TR_RVbeat249__RT 107
#define TR_I967_Excitable_RT 108
#define TR_I251_VSynch_RT 109
#define TR_RVP252__RT 110
#define TR_I965_Excitable_RT 111
#define TR_I311_VsenseAnte_RT 112
#define TR_I309_Vsense_RT 113
#define TR_I926_vrg_RT 114
#define TR_I927_vrg_RT 115
#define TR_I928_vrg_RT 116
#define TR_I929_VtrAnteReached_RT 117
#define TR_I930_VtrAnteReached_RT 118
#define TR_D58_Retro_RT 119
#define TR_D56_Ante_RT 120
#define TR_D40_Refractory_RT 121
#define TR_RAP39__RT 122
#define TR_I963_Excitable_RT 123
#define TR_I307_AsenseRetro_RT 124
#define TR_I616_Asense_RT 125
#define TR_I896_arg_RT 126
#define TR_I897_arg_RT 127
#define TR_I898_arg_RT 128
#define TR_I899_AtrRetroReached_RT 129
#define TR_I900_AtrRetroReached_RT 130
#define TR_I938_NextAtrBeat_RT 131
#define TR_I939_NextAtrBeat_RT 132
#define TR_I940_Abeat_RT 133
#define TR_I941_Abeat_RT 134
#define TR_I942_Abeat_RT 135
#define TR_I943_Abeat_RT 136
#define TR_I944_Abeat_RT 137
#define TR_I945_Abeat_RT 138
#define TR_I946_Abeat_RT 139
#define TR_I947_Abeat_RT 140
#define TR_I948_tr_AVJ_RT 141
#define TR_I949_tr_AVJ_RT 142
#define TR_I950_retroAVJ_RT 143
#define TR_I951_retroAVJ_RT 144
#define TR_I952_retroAVJ_RT 145

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
	const int _nb_Place_SIG_APOut=1;
	const int _nb_Place_SIG_AS=2;
	const int _nb_Place_SIG_Aget=3;
	const int _nb_Place_SIG_AgetOut=4;
	const int _nb_Place_SIG_NextVtrBeat=5;
	const int _nb_Place_SIG_RLRI=6;
	const int _nb_Place_SIG_VP=7;
	const int _nb_Place_SIG_VPOut=8;
	const int _nb_Place_SIG_VS=9;
	const int _nb_Place_SIG_Vbeat=10;
	const int _nb_Place_SIG_Vget=11;
	const int _nb_Place_SIG_VgetOut=12;
	const int _nb_Place_Atrium=13;
	const int _nb_Place_RAConductor=14;
	const int _nb_Place_Ventricle=15;
	const int _nb_Place_AVJOut=16;
	const int _nb_Place_AVJ=17;
	const int _nb_Place_A_dV=18;
	const int _nb_Place_RVConductor=19;
	const int _nb_Place_SANodeEctopic=20;
	const int _nb_Place_SANode=21;
	const int _nb_Place_TAVIcmp=22;
	const int _nb_Place_AVI=23;
	const int _nb_Place_URI=24;
	const int _nb_Place_PVARP=25;
	const int _nb_Place_VRP=26;
	const int _nb_Place_LRI=27;
	const int _nb_Place_VRG=28;
	const int _nb_Place_VtrNoiseGenerator=29;
	const int _nb_Place_VRGEctopic=30;
	const int _nb_Place_AtrNoiseGenerator=31;
#include "magicLight.hpp"
#include "markingImplLight.hpp"

void abstractMarking::resetToInitMarking(){
	magicReset();
	P->_PL_SIG_AP =0;
	P->_PL_SIG_APOut =0;
	P->_PL_SIG_AS =0;
	P->_PL_SIG_Aget =0;
	P->_PL_SIG_AgetOut =0;
	P->_PL_SIG_NextVtrBeat =0;
	P->_PL_SIG_RLRI =0;
	P->_PL_SIG_VP =0;
	P->_PL_SIG_VPOut =0;
	P->_PL_SIG_VS =0;
	P->_PL_SIG_Vbeat =0;
	P->_PL_SIG_Vget =0;
	P->_PL_SIG_VgetOut =0;
	P->_PL_Atrium =26;
	P->_PL_RAConductor =69;
	P->_PL_Ventricle =32;
	P->_PL_AVJOut =64;
	P->_PL_AVJ =34;
	P->_PL_A_dV =77;
	P->_PL_RVConductor =57;
	P->_PL_SANodeEctopic =73;
	P->_PL_SANode =50;
	P->_PL_TAVIcmp =5;
	P->_PL_AVI =14;
	P->_PL_URI =17;
	P->_PL_PVARP =3;
	P->_PL_VRP =9;
	P->_PL_LRI =21;
	P->_PL_VRG =46;
	P->_PL_VtrNoiseGenerator =52;
	P->_PL_VRGEctopic =59;
	P->_PL_AtrNoiseGenerator =71;
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
::print("SIG_APOut	");
::print("SIG_AS	");
::print("SIG_Aget	");
::print("SIG_AgetOut	");
::print("SIG_NextVtrBeat	");
::print("SIG_RLRI	");
::print("SIG_VP	");
::print("SIG_VPOut	");
::print("SIG_VS	");
::print("SIG_Vbeat	");
::print("SIG_Vget	");
::print("SIG_VgetOut	");
::print("Atrium	");
::print("RAConductor	");
::print("Ventricle	");
::print("AVJOut	");
::print("AVJ	");
::print("A_dV	");
::print("RVConductor	");
::print("SANodeEctopic	");
::print("SANode	");
::print("TAVIcmp	");
::print("AVI	");
::print("URI	");
::print("PVARP	");
::print("VRP	");
::print("LRI	");
::print("VRG	");
::print("VtrNoiseGenerator	");
::print("VRGEctopic	");
::print("AtrNoiseGenerator	");
}

void abstractMarking::print()const{
print_magic(P->_PL_SIG_AP);
::print("	");
print_magic(P->_PL_SIG_APOut);
::print("	");
print_magic(P->_PL_SIG_AS);
::print("	");
print_magic(P->_PL_SIG_Aget);
::print("	");
print_magic(P->_PL_SIG_AgetOut);
::print("	");
print_magic(P->_PL_SIG_NextVtrBeat);
::print("	");
print_magic(P->_PL_SIG_RLRI);
::print("	");
print_magic(P->_PL_SIG_VP);
::print("	");
print_magic(P->_PL_SIG_VPOut);
::print("	");
print_magic(P->_PL_SIG_VS);
::print("	");
print_magic(P->_PL_SIG_Vbeat);
::print("	");
print_magic(P->_PL_SIG_Vget);
::print("	");
print_magic(P->_PL_SIG_VgetOut);
::print("	");
print_magic(P->_PL_Atrium);
::print("	");
print_magic(P->_PL_RAConductor);
::print("	");
print_magic(P->_PL_Ventricle);
::print("	");
print_magic(P->_PL_AVJOut);
::print("	");
print_magic(P->_PL_AVJ);
::print("	");
print_magic(P->_PL_A_dV);
::print("	");
print_magic(P->_PL_RVConductor);
::print("	");
print_magic(P->_PL_SANodeEctopic);
::print("	");
print_magic(P->_PL_SANode);
::print("	");
print_magic(P->_PL_TAVIcmp);
::print("	");
print_magic(P->_PL_AVI);
::print("	");
print_magic(P->_PL_URI);
::print("	");
print_magic(P->_PL_PVARP);
::print("	");
print_magic(P->_PL_VRP);
::print("	");
print_magic(P->_PL_LRI);
::print("	");
print_magic(P->_PL_VRG);
::print("	");
print_magic(P->_PL_VtrNoiseGenerator);
::print("	");
print_magic(P->_PL_VRGEctopic);
::print("	");
print_magic(P->_PL_AtrNoiseGenerator);
::print("	");
}
SPN::SPN():
pl(32), tr(146) {
}

bool SPN::IsEnabled(TR_PL_ID t)const {
switch (t){
	case 62:	//RAP913_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 5) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

		break;
	case 64:	//RAP915_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 5) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 71:	//RAP922_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

		break;
	case 73:	//RAP924_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 0:	//EMPTY_AP
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    return true;

		break;
	case 1:	//EMPTY_APOut
    if (!(contains(Marking.P->_PL_SIG_APOut , 1))) return false;
    return true;

		break;
	case 28:	//RAS724_
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_LRI != 21) return false;
    return true;

		break;
	case 61:	//RAS912_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 5) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

		break;
	case 63:	//RAS914_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 5) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 70:	//RAS921_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

		break;
	case 72:	//RAS923_RTAVI
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 2:	//EMPTY_AS
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    return true;

		break;
	case 47:	//RAget773_
    if (!(contains(Marking.P->_PL_SIG_Aget , 1))) return false;
    if( Marking.P->_PL_PVARP != 3) return false;
    return true;

		break;
	case 3:	//EMPTY_Aget
    if (!(contains(Marking.P->_PL_SIG_Aget , 1))) return false;
    return true;

		break;
	case 4:	//EMPTY_AgetOut
    if (!(contains(Marking.P->_PL_SIG_AgetOut , 1))) return false;
    return true;

		break;
	case 21:	//RNextVtrBeat267_
    if (!(contains(Marking.P->_PL_SIG_NextVtrBeat , 1))) return false;
    if( Marking.P->_PL_VRG != 45) return false;
    return true;

		break;
	case 23:	//RNextVtrBeat491_
    if (!(contains(Marking.P->_PL_SIG_NextVtrBeat , 1))) return false;
    if( Marking.P->_PL_VRG != 46) return false;
    return true;

		break;
	case 5:	//EMPTY_NextVtrBeat
    if (!(contains(Marking.P->_PL_SIG_NextVtrBeat , 1))) return false;
    return true;

		break;
	case 30:	//RRLRI713_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 20) return false;
    return true;

		break;
	case 32:	//RRLRI714_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 21) return false;
    return true;

		break;
	case 6:	//EMPTY_RLRI
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    return true;

		break;
	case 41:	//RVP768_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_PVARP != 3) return false;
    return true;

		break;
	case 36:	//RVP758_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_VRP != 9) return false;
    return true;

		break;
	case 110:	//RVP252_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_Ventricle != 33) return false;
    return true;

		break;
	case 7:	//EMPTY_VP
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    return true;

		break;
	case 8:	//EMPTY_VPOut
    if (!(contains(Marking.P->_PL_SIG_VPOut , 1))) return false;
    return true;

		break;
	case 55:	//RVS905_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 10) return false;
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 57:	//RVS908_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 12) return false;
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 56:	//RVS907_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 13) return false;
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 43:	//RVS769_
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_PVARP != 3) return false;
    return true;

		break;
	case 9:	//EMPTY_VS
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    return true;

		break;
	case 107:	//RVbeat249_
    if (!(contains(Marking.P->_PL_SIG_Vbeat , 1))) return false;
    if( Marking.P->_PL_Ventricle != 33) return false;
    return true;

		break;
	case 10:	//EMPTY_Vbeat
    if (!(contains(Marking.P->_PL_SIG_Vbeat , 1))) return false;
    return true;

		break;
	case 39:	//RVget760_
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    if( Marking.P->_PL_VRP != 9) return false;
    return true;

		break;
	case 11:	//EMPTY_Vget
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    return true;

		break;
	case 12:	//EMPTY_VgetOut
    if (!(contains(Marking.P->_PL_SIG_VgetOut , 1))) return false;
    return true;

		break;
	case 27:	//I782_LRI
    if (Marking.P->_PL_SIG_AP >= 1) return false;
    if( Marking.P->_PL_LRI != 18) return false;
    return true;

		break;
	case 123:	//I963_Excitable
    if (Marking.P->_PL_SIG_APOut >= 1) return false;
    if( Marking.P->_PL_Atrium != 962) return false;
    return true;

		break;
	case 46:	//I772_Asig
    if (Marking.P->_PL_SIG_AS >= 1) return false;
    if( Marking.P->_PL_PVARP != 1) return false;
    return true;

		break;
	case 14:	//I818_q0
    if (Marking.P->_PL_SIG_Aget >= 1) return false;
    if( Marking.P->_PL_AtrNoiseGenerator != 70) return false;
    return true;

		break;
	case 125:	//I616_Asense
    if (Marking.P->_PL_SIG_Aget >= 1) return false;
    if( Marking.P->_PL_Atrium != 23) return false;
    return true;

		break;
	case 124:	//I307_AsenseRetro
    if (Marking.P->_PL_SIG_Aget >= 1) return false;
    if( Marking.P->_PL_Atrium != 24) return false;
    return true;

		break;
	case 134:	//I941_Abeat
    if (Marking.P->_PL_SIG_AgetOut >= 1) return false;
    if( Marking.P->_PL_Atrium != 27) return false;
    if( Marking.P->_PL_A_dV != 76) return false;
    if( Marking.P->_PL_SANode != 47) return false;
    return true;

		break;
	case 135:	//I942_Abeat
    if (Marking.P->_PL_SIG_AgetOut >= 1) return false;
    if( Marking.P->_PL_Atrium != 27) return false;
    if( Marking.P->_PL_A_dV != 76) return false;
    if( Marking.P->_PL_SANodeEctopic != 72) return false;
    return true;

		break;
	case 133:	//I940_Abeat
    if (Marking.P->_PL_SIG_AgetOut >= 1) return false;
    if( Marking.P->_PL_Atrium != 27) return false;
    if( Marking.P->_PL_A_dV != 77) return false;
    if( Marking.P->_PL_SANode != 47) return false;
    return true;

		break;
	case 136:	//I943_Abeat
    if (Marking.P->_PL_SIG_AgetOut >= 1) return false;
    if( Marking.P->_PL_Atrium != 27) return false;
    if( Marking.P->_PL_A_dV != 77) return false;
    if( Marking.P->_PL_SANodeEctopic != 72) return false;
    return true;

		break;
	case 129:	//I899_AtrRetroReached
    if (Marking.P->_PL_SIG_AgetOut >= 1) return false;
    if( Marking.P->_PL_Atrium != 27) return false;
    if( Marking.P->_PL_RAConductor != 65) return false;
    return true;

		break;
	case 109:	//I251_VSynch
    if (Marking.P->_PL_SIG_NextVtrBeat >= 1) return false;
    if( Marking.P->_PL_Ventricle != 30) return false;
    return true;

		break;
	case 54:	//I904_IncrClk
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_AVI != 12) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 65:	//I916_TAVI
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 10) return false;
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 38:	//I759_Vsig
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VS >= 1) return false;
    if( Marking.P->_PL_VRP != 7) return false;
    return true;

		break;
	case 111:	//I965_Excitable
    if (Marking.P->_PL_SIG_VPOut >= 1) return false;
    if( Marking.P->_PL_Ventricle != 964) return false;
    return true;

		break;
	case 20:	//I796_Wait4VBeat
    if (Marking.P->_PL_SIG_Vbeat >= 1) return false;
    if( Marking.P->_PL_VRG != 43) return false;
    return true;

		break;
	case 16:	//I808_q0
    if (Marking.P->_PL_SIG_Vbeat >= 1) return false;
    if( Marking.P->_PL_VRGEctopic != 58) return false;
    return true;

		break;
	case 113:	//I309_Vsense
    if (Marking.P->_PL_SIG_Vget >= 1) return false;
    if( Marking.P->_PL_Ventricle != 29) return false;
    return true;

		break;
	case 112:	//I311_VsenseAnte
    if (Marking.P->_PL_SIG_Vget >= 1) return false;
    if( Marking.P->_PL_Ventricle != 31) return false;
    return true;

		break;
	case 18:	//I802_q0
    if (Marking.P->_PL_SIG_Vget >= 1) return false;
    if( Marking.P->_PL_VtrNoiseGenerator != 51) return false;
    return true;

		break;
	case 117:	//I929_VtrAnteReached
    if (Marking.P->_PL_SIG_VgetOut >= 1) return false;
    if( Marking.P->_PL_Ventricle != 33) return false;
    if( Marking.P->_PL_RVConductor != 53) return false;
    return true;

		break;
	case 108:	//I967_Excitable
    if (Marking.P->_PL_SIG_VgetOut >= 1) return false;
    if( Marking.P->_PL_Ventricle != 966) return false;
    return true;

		break;
	case 58:	//I909_IncrClk
    if( Marking.P->_PL_AVI != 10) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 59:	//I910_IncrClk
    if( Marking.P->_PL_AVI != 11) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 53:	//I903_IncrClk
    if( Marking.P->_PL_AVI != 13) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 52:	//I902_IncrClk
    if( Marking.P->_PL_AVI != 14) return false;
    if( Marking.P->_PL_URI != 16) return false;
    return true;

		break;
	case 79:	//I792_init
    if( Marking.P->_PL_AVJ != 34) return false;
    return true;

		break;
	case 83:	//I788_Refractory
    if( Marking.P->_PL_AVJ != 36) return false;
    return true;

		break;
	case 84:	//I786_Refractory
    if( Marking.P->_PL_AVJ != 37) return false;
    return true;

		break;
	case 85:	//I784_Refractory
    if( Marking.P->_PL_AVJ != 38) return false;
    return true;

		break;
	case 94:	//I882_AVJAnteReached
    if( Marking.P->_PL_AVJ != 40) return false;
    if( Marking.P->_PL_A_dV != 74) return false;
    return true;

		break;
	case 95:	//I883_AVJAnteReachedHigh
    if( Marking.P->_PL_AVJ != 40) return false;
    if( Marking.P->_PL_A_dV != 75) return false;
    return true;

		break;
	case 103:	//I892_AVJRetroReached
    if( Marking.P->_PL_AVJ != 40) return false;
    if( Marking.P->_PL_RVConductor != 54) return false;
    return true;

		break;
	case 81:	//D634_Refractory
    if( Marking.P->_PL_AVJ != 40) return false;
    return true;

		break;
	case 98:	//I886_AVJAnteReached
    if( Marking.P->_PL_AVJ != 41) return false;
    if( Marking.P->_PL_A_dV != 74) return false;
    return true;

		break;
	case 99:	//I887_AVJAnteReachedHigh
    if( Marking.P->_PL_AVJ != 41) return false;
    if( Marking.P->_PL_A_dV != 75) return false;
    return true;

		break;
	case 105:	//I894_AVJRetroReached
    if( Marking.P->_PL_AVJ != 41) return false;
    if( Marking.P->_PL_RVConductor != 54) return false;
    return true;

		break;
	case 80:	//D651_Ante
    if( Marking.P->_PL_AVJ != 41) return false;
    return true;

		break;
	case 97:	//I885_AVJAnteReached
    if( Marking.P->_PL_AVJ != 42) return false;
    if( Marking.P->_PL_A_dV != 74) return false;
    return true;

		break;
	case 96:	//I884_AVJAnteReachedHigh
    if( Marking.P->_PL_AVJ != 42) return false;
    if( Marking.P->_PL_A_dV != 75) return false;
    return true;

		break;
	case 104:	//I893_AVJRetroReached
    if( Marking.P->_PL_AVJ != 42) return false;
    if( Marking.P->_PL_RVConductor != 54) return false;
    return true;

		break;
	case 82:	//D636_Recovery
    if( Marking.P->_PL_AVJ != 42) return false;
    return true;

		break;
	case 100:	//I889_anteAVJ
    if( Marking.P->_PL_AVJOut != 60) return false;
    if( Marking.P->_PL_RVConductor != 55) return false;
    return true;

		break;
	case 102:	//I891_anteAVJ
    if( Marking.P->_PL_AVJOut != 60) return false;
    if( Marking.P->_PL_RVConductor != 56) return false;
    return true;

		break;
	case 101:	//I890_anteAVJ
    if( Marking.P->_PL_AVJOut != 60) return false;
    if( Marking.P->_PL_RVConductor != 57) return false;
    return true;

		break;
	case 90:	//I877_AVJAnteExit
    if( Marking.P->_PL_AVJOut != 62) return false;
    if( Marking.P->_PL_AVJ != 35) return false;
    return true;

		break;
	case 91:	//I878_AVJRetroExit
    if( Marking.P->_PL_AVJOut != 62) return false;
    if( Marking.P->_PL_AVJ != 39) return false;
    return true;

		break;
	case 87:	//D179_Retro
    if( Marking.P->_PL_AVJOut != 62) return false;
    return true;

		break;
	case 92:	//I879_AVJAnteExit
    if( Marking.P->_PL_AVJOut != 63) return false;
    if( Marking.P->_PL_AVJ != 35) return false;
    return true;

		break;
	case 93:	//I880_AVJRetroExit
    if( Marking.P->_PL_AVJOut != 63) return false;
    if( Marking.P->_PL_AVJ != 39) return false;
    return true;

		break;
	case 86:	//D177_Ante
    if( Marking.P->_PL_AVJOut != 63) return false;
    return true;

		break;
	case 89:	//I876_AVJAnteExit
    if( Marking.P->_PL_AVJOut != 64) return false;
    if( Marking.P->_PL_AVJ != 35) return false;
    return true;

		break;
	case 88:	//I875_AVJRetroExit
    if( Marking.P->_PL_AVJOut != 64) return false;
    if( Marking.P->_PL_AVJ != 39) return false;
    return true;

		break;
	case 13:	//D10_q0
    if( Marking.P->_PL_AtrNoiseGenerator != 71) return false;
    return true;

		break;
	case 126:	//I896_arg
    if( Marking.P->_PL_Atrium != 22) return false;
    if( Marking.P->_PL_RAConductor != 67) return false;
    return true;

		break;
	case 128:	//I898_arg
    if( Marking.P->_PL_Atrium != 22) return false;
    if( Marking.P->_PL_RAConductor != 68) return false;
    return true;

		break;
	case 127:	//I897_arg
    if( Marking.P->_PL_Atrium != 22) return false;
    if( Marking.P->_PL_RAConductor != 69) return false;
    return true;

		break;
	case 131:	//I938_NextAtrBeat
    if( Marking.P->_PL_Atrium != 25) return false;
    if( Marking.P->_PL_SANode != 49) return false;
    return true;

		break;
	case 132:	//I939_NextAtrBeat
    if( Marking.P->_PL_Atrium != 25) return false;
    if( Marking.P->_PL_SANode != 50) return false;
    return true;

		break;
	case 138:	//I945_Abeat
    if( Marking.P->_PL_Atrium != 26) return false;
    if( Marking.P->_PL_A_dV != 76) return false;
    if( Marking.P->_PL_SANode != 47) return false;
    return true;

		break;
	case 139:	//I946_Abeat
    if( Marking.P->_PL_Atrium != 26) return false;
    if( Marking.P->_PL_A_dV != 76) return false;
    if( Marking.P->_PL_SANodeEctopic != 72) return false;
    return true;

		break;
	case 137:	//I944_Abeat
    if( Marking.P->_PL_Atrium != 26) return false;
    if( Marking.P->_PL_A_dV != 77) return false;
    if( Marking.P->_PL_SANode != 47) return false;
    return true;

		break;
	case 140:	//I947_Abeat
    if( Marking.P->_PL_Atrium != 26) return false;
    if( Marking.P->_PL_A_dV != 77) return false;
    if( Marking.P->_PL_SANodeEctopic != 72) return false;
    return true;

		break;
	case 130:	//I900_AtrRetroReached
    if( Marking.P->_PL_Atrium != 26) return false;
    if( Marking.P->_PL_RAConductor != 65) return false;
    return true;

		break;
	case 121:	//D40_Refractory
    if( Marking.P->_PL_Atrium != 26) return false;
    return true;

		break;
	case 34:	//I780_LRI
    if( Marking.P->_PL_LRI != 19) return false;
    return true;

		break;
	case 26:	//D723_LRI
    if( Marking.P->_PL_LRI != 21) return false;
    return true;

		break;
	case 33:	//I979_RLRI
    if( Marking.P->_PL_LRI != 978) return false;
    return true;

		break;
	case 31:	//I981_ASensed
    if( Marking.P->_PL_LRI != 980) return false;
    return true;

		break;
	case 29:	//I983_LRI
    if( Marking.P->_PL_LRI != 982) return false;
    return true;

		break;
	case 45:	//D771_PVARP
    if( Marking.P->_PL_PVARP != 0) return false;
    return true;

		break;
	case 49:	//D774_PVAB
    if( Marking.P->_PL_PVARP != 2) return false;
    return true;

		break;
	case 48:	//I969_Idle
    if( Marking.P->_PL_PVARP != 968) return false;
    return true;

		break;
	case 44:	//I971_Idle
    if( Marking.P->_PL_PVARP != 970) return false;
    return true;

		break;
	case 42:	//I973_Idle
    if( Marking.P->_PL_PVARP != 972) return false;
    return true;

		break;
	case 141:	//I948_tr_AVJ
    if( Marking.P->_PL_RAConductor != 66) return false;
    if( Marking.P->_PL_A_dV != 76) return false;
    return true;

		break;
	case 142:	//I949_tr_AVJ
    if( Marking.P->_PL_RAConductor != 66) return false;
    if( Marking.P->_PL_A_dV != 77) return false;
    return true;

		break;
	case 145:	//I952_retroAVJ
    if( Marking.P->_PL_RAConductor != 67) return false;
    if( Marking.P->_PL_AVJOut != 61) return false;
    return true;

		break;
	case 119:	//D58_Retro
    if( Marking.P->_PL_RAConductor != 67) return false;
    return true;

		break;
	case 144:	//I951_retroAVJ
    if( Marking.P->_PL_RAConductor != 68) return false;
    if( Marking.P->_PL_AVJOut != 61) return false;
    return true;

		break;
	case 120:	//D56_Ante
    if( Marking.P->_PL_RAConductor != 68) return false;
    return true;

		break;
	case 143:	//I950_retroAVJ
    if( Marking.P->_PL_RAConductor != 69) return false;
    if( Marking.P->_PL_AVJOut != 61) return false;
    return true;

		break;
	case 78:	//D161_Retro
    if( Marking.P->_PL_RVConductor != 55) return false;
    return true;

		break;
	case 77:	//D160_Ante
    if( Marking.P->_PL_RVConductor != 56) return false;
    return true;

		break;
	case 75:	//I798_Wait4ABeat
    if( Marking.P->_PL_SANode != 48) return false;
    return true;

		break;
	case 74:	//D16_Wait4ABeat
    if( Marking.P->_PL_SANode != 50) return false;
    return true;

		break;
	case 76:	//D86_q0
    if( Marking.P->_PL_SANodeEctopic != 73) return false;
    return true;

		break;
	case 67:	//I918_TAVI
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 11) return false;
    return true;

		break;
	case 68:	//I919_TAVI
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 12) return false;
    return true;

		break;
	case 66:	//I917_TAVI
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 13) return false;
    return true;

		break;
	case 69:	//I920_TAVI
    if( Marking.P->_PL_TAVIcmp != 4) return false;
    if( Marking.P->_PL_AVI != 14) return false;
    return true;

		break;
	case 60:	//D726_q0
    if( Marking.P->_PL_TAVIcmp != 6) return false;
    return true;

		break;
	case 50:	//I778_URI
    if( Marking.P->_PL_URI != 15) return false;
    return true;

		break;
	case 51:	//D735_URI
    if( Marking.P->_PL_URI != 17) return false;
    return true;

		break;
	case 25:	//I794_Wait4VBeat
    if( Marking.P->_PL_VRG != 44) return false;
    return true;

		break;
	case 19:	//D266_Wait4VBeat
    if( Marking.P->_PL_VRG != 46) return false;
    return true;

		break;
	case 24:	//I985_NextVtrBeat
    if( Marking.P->_PL_VRG != 984) return false;
    return true;

		break;
	case 22:	//I987_Wait4VSynch
    if( Marking.P->_PL_VRG != 986) return false;
    return true;

		break;
	case 15:	//D279_q0
    if( Marking.P->_PL_VRGEctopic != 59) return false;
    return true;

		break;
	case 35:	//D717_VRP
    if( Marking.P->_PL_VRP != 8) return false;
    return true;

		break;
	case 40:	//I975_Idle
    if( Marking.P->_PL_VRP != 974) return false;
    return true;

		break;
	case 37:	//I977_Idle
    if( Marking.P->_PL_VRP != 976) return false;
    return true;

		break;
	case 116:	//I928_vrg
    if( Marking.P->_PL_Ventricle != 28) return false;
    if( Marking.P->_PL_RVConductor != 55) return false;
    return true;

		break;
	case 114:	//I926_vrg
    if( Marking.P->_PL_Ventricle != 28) return false;
    if( Marking.P->_PL_RVConductor != 56) return false;
    return true;

		break;
	case 115:	//I927_vrg
    if( Marking.P->_PL_Ventricle != 28) return false;
    if( Marking.P->_PL_RVConductor != 57) return false;
    return true;

		break;
	case 118:	//I930_VtrAnteReached
    if( Marking.P->_PL_Ventricle != 32) return false;
    if( Marking.P->_PL_RVConductor != 53) return false;
    return true;

		break;
	case 106:	//D248_Refractory
    if( Marking.P->_PL_Ventricle != 32) return false;
    return true;

		break;
	case 17:	//D276_q0
    if( Marking.P->_PL_VtrNoiseGenerator != 52) return false;
    return true;

		break;
	default:	//RAP39_,
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_Atrium != 27) return false;
    return true;

}
}

void SPN::fire(TR_PL_ID t,  double time){
	lastTransition = t;
	magicUpdate(t,time);
	switch(t){
		case 0: {  //EMPTY_AP
			Marking.P->_PL_SIG_AP -= 1;
       break;
     } 
		case 1: {  //EMPTY_APOut
			Marking.P->_PL_SIG_APOut -= 1;
       break;
     } 
		case 2: {  //EMPTY_AS
			Marking.P->_PL_SIG_AS -= 1;
       break;
     } 
		case 3: {  //EMPTY_Aget
			Marking.P->_PL_SIG_Aget -= 1;
       break;
     } 
		case 4: {  //EMPTY_AgetOut
			Marking.P->_PL_SIG_AgetOut -= 1;
       break;
     } 
		case 5: {  //EMPTY_NextVtrBeat
			Marking.P->_PL_SIG_NextVtrBeat -= 1;
       break;
     } 
		case 6: {  //EMPTY_RLRI
			Marking.P->_PL_SIG_RLRI -= 1;
       break;
     } 
		case 7: {  //EMPTY_VP
			Marking.P->_PL_SIG_VP -= 1;
       break;
     } 
		case 8: {  //EMPTY_VPOut
			Marking.P->_PL_SIG_VPOut -= 1;
       break;
     } 
		case 9: {  //EMPTY_VS
			Marking.P->_PL_SIG_VS -= 1;
       break;
     } 
		case 10: {  //EMPTY_Vbeat
			Marking.P->_PL_SIG_Vbeat -= 1;
       break;
     } 
		case 11: {  //EMPTY_Vget
			Marking.P->_PL_SIG_Vget -= 1;
       break;
     } 
		case 12: {  //EMPTY_VgetOut
			Marking.P->_PL_SIG_VgetOut -= 1;
       break;
     } 
		case 13: {  //D10_q0
			Marking.P->_PL_AtrNoiseGenerator -= 71;
			Marking.P->_PL_AtrNoiseGenerator += 70;
       break;
     } 
		case 14: {  //I818_q0
			Marking.P->_PL_SIG_Aget += 1;
			Marking.P->_PL_AtrNoiseGenerator -= 70;
			Marking.P->_PL_AtrNoiseGenerator += 71;
       break;
     } 
		case 15: {  //D279_q0
			Marking.P->_PL_VRGEctopic -= 59;
			Marking.P->_PL_VRGEctopic += 58;
       break;
     } 
		case 16: {  //I808_q0
			Marking.P->_PL_SIG_Vbeat += 1;
			Marking.P->_PL_VRGEctopic -= 58;
			Marking.P->_PL_VRGEctopic += 59;
       break;
     } 
		case 17: {  //D276_q0
			Marking.P->_PL_VtrNoiseGenerator -= 52;
			Marking.P->_PL_VtrNoiseGenerator += 51;
       break;
     } 
		case 18: {  //I802_q0
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_VtrNoiseGenerator -= 51;
			Marking.P->_PL_VtrNoiseGenerator += 52;
       break;
     } 
		case 19: {  //D266_Wait4VBeat
			Marking.P->_PL_VRG -= 46;
			Marking.P->_PL_VRG += 43;
       break;
     } 
		case 20: {  //I796_Wait4VBeat
			Marking.P->_PL_SIG_Vbeat += 1;
			Marking.P->_PL_VRG -= 43;
			Marking.P->_PL_VRG += 45;
       break;
     } 
		case 21: {  //RNextVtrBeat267_
			Marking.P->_PL_SIG_NextVtrBeat -= 1;
			Marking.P->_PL_SIG_NextVtrBeat += 1;
			Marking.P->_PL_VRG -= 45;
			Marking.P->_PL_VRG += 986;
       break;
     } 
		case 22: {  //I987_Wait4VSynch
			Marking.P->_PL_VRG -= 986;
			Marking.P->_PL_VRG += 46;
       break;
     } 
		case 23: {  //RNextVtrBeat491_
			Marking.P->_PL_SIG_NextVtrBeat -= 1;
			Marking.P->_PL_SIG_NextVtrBeat += 1;
			Marking.P->_PL_VRG -= 46;
			Marking.P->_PL_VRG += 984;
       break;
     } 
		case 24: {  //I985_NextVtrBeat
			Marking.P->_PL_VRG -= 984;
			Marking.P->_PL_VRG += 44;
       break;
     } 
		case 25: {  //I794_Wait4VBeat
			Marking.P->_PL_VRG -= 44;
			Marking.P->_PL_VRG += 46;
       break;
     } 
		case 26: {  //D723_LRI
			Marking.P->_PL_LRI -= 21;
			Marking.P->_PL_LRI += 18;
       break;
     } 
		case 27: {  //I782_LRI
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_LRI -= 18;
			Marking.P->_PL_LRI += 21;
       break;
     } 
		case 28: {  //RAS724_
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_LRI -= 21;
			Marking.P->_PL_LRI += 982;
       break;
     } 
		case 29: {  //I983_LRI
			Marking.P->_PL_LRI -= 982;
			Marking.P->_PL_LRI += 20;
       break;
     } 
		case 30: {  //RRLRI713_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 20;
			Marking.P->_PL_LRI += 980;
       break;
     } 
		case 31: {  //I981_ASensed
			Marking.P->_PL_LRI -= 980;
			Marking.P->_PL_LRI += 21;
       break;
     } 
		case 32: {  //RRLRI714_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 21;
			Marking.P->_PL_LRI += 978;
       break;
     } 
		case 33: {  //I979_RLRI
			Marking.P->_PL_LRI -= 978;
			Marking.P->_PL_LRI += 19;
       break;
     } 
		case 34: {  //I780_LRI
			Marking.P->_PL_LRI -= 19;
			Marking.P->_PL_LRI += 21;
       break;
     } 
		case 35: {  //D717_VRP
			Marking.P->_PL_VRP -= 8;
			Marking.P->_PL_VRP += 9;
       break;
     } 
		case 36: {  //RVP758_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_VRP -= 9;
			Marking.P->_PL_VRP += 976;
       break;
     } 
		case 37: {  //I977_Idle
			Marking.P->_PL_VRP -= 976;
			Marking.P->_PL_VRP += 8;
       break;
     } 
		case 38: {  //I759_Vsig
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_VRP -= 7;
			Marking.P->_PL_VRP += 9;
       break;
     } 
		case 39: {  //RVget760_
			Marking.P->_PL_SIG_Vget -= 1;
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_VRP -= 9;
			Marking.P->_PL_VRP += 974;
       break;
     } 
		case 40: {  //I975_Idle
			Marking.P->_PL_VRP -= 974;
			Marking.P->_PL_VRP += 7;
       break;
     } 
		case 41: {  //RVP768_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_PVARP -= 3;
			Marking.P->_PL_PVARP += 972;
       break;
     } 
		case 42: {  //I973_Idle
			Marking.P->_PL_PVARP -= 972;
			Marking.P->_PL_PVARP += 2;
       break;
     } 
		case 43: {  //RVS769_
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_PVARP -= 3;
			Marking.P->_PL_PVARP += 970;
       break;
     } 
		case 44: {  //I971_Idle
			Marking.P->_PL_PVARP -= 970;
			Marking.P->_PL_PVARP += 2;
       break;
     } 
		case 45: {  //D771_PVARP
			Marking.P->_PL_PVARP -= 0;
			Marking.P->_PL_PVARP += 3;
       break;
     } 
		case 46: {  //I772_Asig
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_PVARP -= 1;
			Marking.P->_PL_PVARP += 3;
       break;
     } 
		case 47: {  //RAget773_
			Marking.P->_PL_SIG_Aget -= 1;
			Marking.P->_PL_SIG_Aget += 1;
			Marking.P->_PL_PVARP -= 3;
			Marking.P->_PL_PVARP += 968;
       break;
     } 
		case 48: {  //I969_Idle
			Marking.P->_PL_PVARP -= 968;
			Marking.P->_PL_PVARP += 1;
       break;
     } 
		case 49: {  //D774_PVAB
			Marking.P->_PL_PVARP -= 2;
			Marking.P->_PL_PVARP += 0;
       break;
     } 
		case 50: {  //I778_URI
			Marking.P->_PL_URI -= 15;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 51: {  //D735_URI
			Marking.P->_PL_URI -= 17;
			Marking.P->_PL_URI += 16;
       break;
     } 
		case 52: {  //I902_IncrClk
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 11;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 53: {  //I903_IncrClk
			Marking.P->_PL_AVI -= 13;
			Marking.P->_PL_AVI += 10;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 54: {  //I904_IncrClk
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_AVI -= 12;
			Marking.P->_PL_AVI += 14;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 55: {  //RVS905_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 10;
			Marking.P->_PL_AVI += 14;
			Marking.P->_PL_URI -= 17;
			Marking.P->_PL_URI += 15;
       break;
     } 
		case 56: {  //RVS907_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 13;
			Marking.P->_PL_AVI += 14;
			Marking.P->_PL_URI -= 17;
			Marking.P->_PL_URI += 15;
       break;
     } 
		case 57: {  //RVS908_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 12;
			Marking.P->_PL_AVI += 14;
			Marking.P->_PL_URI -= 17;
			Marking.P->_PL_URI += 15;
       break;
     } 
		case 58: {  //I909_IncrClk
			Marking.P->_PL_AVI -= 10;
			Marking.P->_PL_AVI += 10;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 59: {  //I910_IncrClk
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 11;
			Marking.P->_PL_URI -= 16;
			Marking.P->_PL_URI += 17;
       break;
     } 
		case 60: {  //D726_q0
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 4;
       break;
     } 
		case 61: {  //RAS912_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 5;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 10;
       break;
     } 
		case 62: {  //RAP913_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 5;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 10;
       break;
     } 
		case 63: {  //RAS914_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 5;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 13;
       break;
     } 
		case 64: {  //RAP915_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 5;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 13;
       break;
     } 
		case 65: {  //I916_TAVI
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
		case 66: {  //I917_TAVI
			Marking.P->_PL_TAVIcmp -= 4;
			Marking.P->_PL_TAVIcmp += 5;
			Marking.P->_PL_AVI -= 13;
			Marking.P->_PL_AVI += 12;
       break;
     } 
		case 67: {  //I918_TAVI
			Marking.P->_PL_TAVIcmp -= 4;
			Marking.P->_PL_TAVIcmp += 5;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 11;
       break;
     } 
		case 68: {  //I919_TAVI
			Marking.P->_PL_TAVIcmp -= 4;
			Marking.P->_PL_TAVIcmp += 5;
			Marking.P->_PL_AVI -= 12;
			Marking.P->_PL_AVI += 12;
       break;
     } 
		case 69: {  //I920_TAVI
			Marking.P->_PL_TAVIcmp -= 4;
			Marking.P->_PL_TAVIcmp += 5;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 14;
       break;
     } 
		case 70: {  //RAS921_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 10;
       break;
     } 
		case 71: {  //RAP922_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 11;
			Marking.P->_PL_AVI += 10;
       break;
     } 
		case 72: {  //RAS923_RTAVI
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 13;
       break;
     } 
		case 73: {  //RAP924_RTAVI
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 6;
			Marking.P->_PL_TAVIcmp += 6;
			Marking.P->_PL_AVI -= 14;
			Marking.P->_PL_AVI += 13;
       break;
     } 
		case 74: {  //D16_Wait4ABeat
			Marking.P->_PL_SANode -= 50;
			Marking.P->_PL_SANode += 47;
       break;
     } 
		case 75: {  //I798_Wait4ABeat
			Marking.P->_PL_SANode -= 48;
			Marking.P->_PL_SANode += 50;
       break;
     } 
		case 76: {  //D86_q0
			Marking.P->_PL_SANodeEctopic -= 73;
			Marking.P->_PL_SANodeEctopic += 72;
       break;
     } 
		case 77: {  //D160_Ante
			Marking.P->_PL_RVConductor -= 56;
			Marking.P->_PL_RVConductor += 53;
       break;
     } 
		case 78: {  //D161_Retro
			Marking.P->_PL_RVConductor -= 55;
			Marking.P->_PL_RVConductor += 54;
       break;
     } 
		case 79: {  //I792_init
			Marking.P->_PL_AVJ -= 34;
			Marking.P->_PL_AVJ += 42;
       break;
     } 
		case 80: {  //D651_Ante
			Marking.P->_PL_AVJ -= 41;
			Marking.P->_PL_AVJ += 35;
       break;
     } 
		case 81: {  //D634_Refractory
			Marking.P->_PL_AVJ -= 40;
			Marking.P->_PL_AVJ += 42;
       break;
     } 
		case 82: {  //D636_Recovery
			Marking.P->_PL_AVJ -= 42;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 83: {  //I788_Refractory
			Marking.P->_PL_AVJ -= 36;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 84: {  //I786_Refractory
			Marking.P->_PL_AVJ -= 37;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 85: {  //I784_Refractory
			Marking.P->_PL_AVJ -= 38;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 86: {  //D177_Ante
			Marking.P->_PL_AVJOut -= 63;
			Marking.P->_PL_AVJOut += 60;
       break;
     } 
		case 87: {  //D179_Retro
			Marking.P->_PL_AVJOut -= 62;
			Marking.P->_PL_AVJOut += 61;
       break;
     } 
		case 88: {  //I875_AVJRetroExit
			Marking.P->_PL_AVJOut -= 64;
			Marking.P->_PL_AVJOut += 62;
			Marking.P->_PL_AVJ -= 39;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 89: {  //I876_AVJAnteExit
			Marking.P->_PL_AVJOut -= 64;
			Marking.P->_PL_AVJOut += 63;
			Marking.P->_PL_AVJ -= 35;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 90: {  //I877_AVJAnteExit
			Marking.P->_PL_AVJOut -= 62;
			Marking.P->_PL_AVJOut += 62;
			Marking.P->_PL_AVJ -= 35;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 91: {  //I878_AVJRetroExit
			Marking.P->_PL_AVJOut -= 62;
			Marking.P->_PL_AVJOut += 62;
			Marking.P->_PL_AVJ -= 39;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 92: {  //I879_AVJAnteExit
			Marking.P->_PL_AVJOut -= 63;
			Marking.P->_PL_AVJOut += 63;
			Marking.P->_PL_AVJ -= 35;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 93: {  //I880_AVJRetroExit
			Marking.P->_PL_AVJOut -= 63;
			Marking.P->_PL_AVJOut += 63;
			Marking.P->_PL_AVJ -= 39;
			Marking.P->_PL_AVJ += 40;
       break;
     } 
		case 94: {  //I882_AVJAnteReached
			Marking.P->_PL_AVJ -= 40;
			Marking.P->_PL_AVJ += 37;
			Marking.P->_PL_A_dV -= 74;
			Marking.P->_PL_A_dV += 77;
       break;
     } 
		case 95: {  //I883_AVJAnteReachedHigh
			Marking.P->_PL_AVJ -= 40;
			Marking.P->_PL_AVJ += 36;
			Marking.P->_PL_A_dV -= 75;
			Marking.P->_PL_A_dV += 76;
       break;
     } 
		case 96: {  //I884_AVJAnteReachedHigh
			Marking.P->_PL_AVJ -= 42;
			Marking.P->_PL_AVJ += 41;
			Marking.P->_PL_A_dV -= 75;
			Marking.P->_PL_A_dV += 76;
       break;
     } 
		case 97: {  //I885_AVJAnteReached
			Marking.P->_PL_AVJ -= 42;
			Marking.P->_PL_AVJ += 41;
			Marking.P->_PL_A_dV -= 74;
			Marking.P->_PL_A_dV += 77;
       break;
     } 
		case 98: {  //I886_AVJAnteReached
			Marking.P->_PL_AVJ -= 41;
			Marking.P->_PL_AVJ += 41;
			Marking.P->_PL_A_dV -= 74;
			Marking.P->_PL_A_dV += 77;
       break;
     } 
		case 99: {  //I887_AVJAnteReachedHigh
			Marking.P->_PL_AVJ -= 41;
			Marking.P->_PL_AVJ += 41;
			Marking.P->_PL_A_dV -= 75;
			Marking.P->_PL_A_dV += 76;
       break;
     } 
		case 100: {  //I889_anteAVJ
			Marking.P->_PL_AVJOut -= 60;
			Marking.P->_PL_AVJOut += 64;
			Marking.P->_PL_RVConductor -= 55;
			Marking.P->_PL_RVConductor += 57;
       break;
     } 
		case 101: {  //I890_anteAVJ
			Marking.P->_PL_AVJOut -= 60;
			Marking.P->_PL_AVJOut += 64;
			Marking.P->_PL_RVConductor -= 57;
			Marking.P->_PL_RVConductor += 56;
       break;
     } 
		case 102: {  //I891_anteAVJ
			Marking.P->_PL_AVJOut -= 60;
			Marking.P->_PL_AVJOut += 64;
			Marking.P->_PL_RVConductor -= 56;
			Marking.P->_PL_RVConductor += 56;
       break;
     } 
		case 103: {  //I892_AVJRetroReached
			Marking.P->_PL_AVJ -= 40;
			Marking.P->_PL_AVJ += 38;
			Marking.P->_PL_RVConductor -= 54;
			Marking.P->_PL_RVConductor += 57;
       break;
     } 
		case 104: {  //I893_AVJRetroReached
			Marking.P->_PL_AVJ -= 42;
			Marking.P->_PL_AVJ += 39;
			Marking.P->_PL_RVConductor -= 54;
			Marking.P->_PL_RVConductor += 57;
       break;
     } 
		case 105: {  //I894_AVJRetroReached
			Marking.P->_PL_AVJ -= 41;
			Marking.P->_PL_AVJ += 41;
			Marking.P->_PL_RVConductor -= 54;
			Marking.P->_PL_RVConductor += 57;
       break;
     } 
		case 106: {  //D248_Refractory
			Marking.P->_PL_Ventricle -= 32;
			Marking.P->_PL_Ventricle += 33;
       break;
     } 
		case 107: {  //RVbeat249_
			Marking.P->_PL_SIG_Vbeat -= 1;
			Marking.P->_PL_SIG_Vbeat += 1;
			Marking.P->_PL_Ventricle -= 33;
			Marking.P->_PL_Ventricle += 966;
       break;
     } 
		case 108: {  //I967_Excitable
			Marking.P->_PL_SIG_VgetOut += 1;
			Marking.P->_PL_Ventricle -= 966;
			Marking.P->_PL_Ventricle += 29;
       break;
     } 
		case 109: {  //I251_VSynch
			Marking.P->_PL_SIG_NextVtrBeat += 1;
			Marking.P->_PL_Ventricle -= 30;
			Marking.P->_PL_Ventricle += 32;
       break;
     } 
		case 110: {  //RVP252_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_Ventricle -= 33;
			Marking.P->_PL_Ventricle += 964;
       break;
     } 
		case 111: {  //I965_Excitable
			Marking.P->_PL_SIG_VPOut += 1;
			Marking.P->_PL_Ventricle -= 964;
			Marking.P->_PL_Ventricle += 29;
       break;
     } 
		case 112: {  //I311_VsenseAnte
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_Ventricle -= 31;
			Marking.P->_PL_Ventricle += 30;
       break;
     } 
		case 113: {  //I309_Vsense
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_Ventricle -= 29;
			Marking.P->_PL_Ventricle += 28;
       break;
     } 
		case 114: {  //I926_vrg
			Marking.P->_PL_Ventricle -= 28;
			Marking.P->_PL_Ventricle += 30;
			Marking.P->_PL_RVConductor -= 56;
			Marking.P->_PL_RVConductor += 57;
       break;
     } 
		case 115: {  //I927_vrg
			Marking.P->_PL_Ventricle -= 28;
			Marking.P->_PL_Ventricle += 30;
			Marking.P->_PL_RVConductor -= 57;
			Marking.P->_PL_RVConductor += 55;
       break;
     } 
		case 116: {  //I928_vrg
			Marking.P->_PL_Ventricle -= 28;
			Marking.P->_PL_Ventricle += 30;
			Marking.P->_PL_RVConductor -= 55;
			Marking.P->_PL_RVConductor += 55;
       break;
     } 
		case 117: {  //I929_VtrAnteReached
			Marking.P->_PL_SIG_VgetOut += 1;
			Marking.P->_PL_Ventricle -= 33;
			Marking.P->_PL_Ventricle += 31;
			Marking.P->_PL_RVConductor -= 53;
			Marking.P->_PL_RVConductor += 57;
       break;
     } 
		case 118: {  //I930_VtrAnteReached
			Marking.P->_PL_Ventricle -= 32;
			Marking.P->_PL_Ventricle += 32;
			Marking.P->_PL_RVConductor -= 53;
			Marking.P->_PL_RVConductor += 57;
       break;
     } 
		case 119: {  //D58_Retro
			Marking.P->_PL_RAConductor -= 67;
			Marking.P->_PL_RAConductor += 65;
       break;
     } 
		case 120: {  //D56_Ante
			Marking.P->_PL_RAConductor -= 68;
			Marking.P->_PL_RAConductor += 66;
       break;
     } 
		case 121: {  //D40_Refractory
			Marking.P->_PL_Atrium -= 26;
			Marking.P->_PL_Atrium += 27;
       break;
     } 
		case 122: {  //RAP39_
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_Atrium -= 27;
			Marking.P->_PL_Atrium += 962;
       break;
     } 
		case 123: {  //I963_Excitable
			Marking.P->_PL_SIG_APOut += 1;
			Marking.P->_PL_Atrium -= 962;
			Marking.P->_PL_Atrium += 23;
       break;
     } 
		case 124: {  //I307_AsenseRetro
			Marking.P->_PL_SIG_Aget += 1;
			Marking.P->_PL_Atrium -= 24;
			Marking.P->_PL_Atrium += 25;
       break;
     } 
		case 125: {  //I616_Asense
			Marking.P->_PL_SIG_Aget += 1;
			Marking.P->_PL_Atrium -= 23;
			Marking.P->_PL_Atrium += 22;
       break;
     } 
		case 126: {  //I896_arg
			Marking.P->_PL_Atrium -= 22;
			Marking.P->_PL_Atrium += 25;
			Marking.P->_PL_RAConductor -= 67;
			Marking.P->_PL_RAConductor += 69;
       break;
     } 
		case 127: {  //I897_arg
			Marking.P->_PL_Atrium -= 22;
			Marking.P->_PL_Atrium += 25;
			Marking.P->_PL_RAConductor -= 69;
			Marking.P->_PL_RAConductor += 68;
       break;
     } 
		case 128: {  //I898_arg
			Marking.P->_PL_Atrium -= 22;
			Marking.P->_PL_Atrium += 25;
			Marking.P->_PL_RAConductor -= 68;
			Marking.P->_PL_RAConductor += 68;
       break;
     } 
		case 129: {  //I899_AtrRetroReached
			Marking.P->_PL_SIG_AgetOut += 1;
			Marking.P->_PL_Atrium -= 27;
			Marking.P->_PL_Atrium += 24;
			Marking.P->_PL_RAConductor -= 65;
			Marking.P->_PL_RAConductor += 69;
       break;
     } 
		case 130: {  //I900_AtrRetroReached
			Marking.P->_PL_Atrium -= 26;
			Marking.P->_PL_Atrium += 26;
			Marking.P->_PL_RAConductor -= 65;
			Marking.P->_PL_RAConductor += 69;
       break;
     } 
		case 131: {  //I938_NextAtrBeat
			Marking.P->_PL_Atrium -= 25;
			Marking.P->_PL_Atrium += 26;
			Marking.P->_PL_SANode -= 49;
			Marking.P->_PL_SANode += 50;
       break;
     } 
		case 132: {  //I939_NextAtrBeat
			Marking.P->_PL_Atrium -= 25;
			Marking.P->_PL_Atrium += 26;
			Marking.P->_PL_SANode -= 50;
			Marking.P->_PL_SANode += 48;
       break;
     } 
		case 133: {  //I940_Abeat
			Marking.P->_PL_SIG_AgetOut += 1;
			Marking.P->_PL_Atrium -= 27;
			Marking.P->_PL_Atrium += 23;
			Marking.P->_PL_A_dV -= 77;
			Marking.P->_PL_A_dV += 77;
			Marking.P->_PL_SANode -= 47;
			Marking.P->_PL_SANode += 49;
       break;
     } 
		case 134: {  //I941_Abeat
			Marking.P->_PL_SIG_AgetOut += 1;
			Marking.P->_PL_Atrium -= 27;
			Marking.P->_PL_Atrium += 23;
			Marking.P->_PL_A_dV -= 76;
			Marking.P->_PL_A_dV += 77;
			Marking.P->_PL_SANode -= 47;
			Marking.P->_PL_SANode += 49;
       break;
     } 
		case 135: {  //I942_Abeat
			Marking.P->_PL_SIG_AgetOut += 1;
			Marking.P->_PL_Atrium -= 27;
			Marking.P->_PL_Atrium += 23;
			Marking.P->_PL_A_dV -= 76;
			Marking.P->_PL_A_dV += 76;
			Marking.P->_PL_SANodeEctopic -= 72;
			Marking.P->_PL_SANodeEctopic += 73;
       break;
     } 
		case 136: {  //I943_Abeat
			Marking.P->_PL_SIG_AgetOut += 1;
			Marking.P->_PL_Atrium -= 27;
			Marking.P->_PL_Atrium += 23;
			Marking.P->_PL_A_dV -= 77;
			Marking.P->_PL_A_dV += 76;
			Marking.P->_PL_SANodeEctopic -= 72;
			Marking.P->_PL_SANodeEctopic += 73;
       break;
     } 
		case 137: {  //I944_Abeat
			Marking.P->_PL_Atrium -= 26;
			Marking.P->_PL_Atrium += 26;
			Marking.P->_PL_A_dV -= 77;
			Marking.P->_PL_A_dV += 77;
			Marking.P->_PL_SANode -= 47;
			Marking.P->_PL_SANode += 49;
       break;
     } 
		case 138: {  //I945_Abeat
			Marking.P->_PL_Atrium -= 26;
			Marking.P->_PL_Atrium += 26;
			Marking.P->_PL_A_dV -= 76;
			Marking.P->_PL_A_dV += 77;
			Marking.P->_PL_SANode -= 47;
			Marking.P->_PL_SANode += 49;
       break;
     } 
		case 139: {  //I946_Abeat
			Marking.P->_PL_Atrium -= 26;
			Marking.P->_PL_Atrium += 26;
			Marking.P->_PL_A_dV -= 76;
			Marking.P->_PL_A_dV += 76;
			Marking.P->_PL_SANodeEctopic -= 72;
			Marking.P->_PL_SANodeEctopic += 73;
       break;
     } 
		case 140: {  //I947_Abeat
			Marking.P->_PL_Atrium -= 26;
			Marking.P->_PL_Atrium += 26;
			Marking.P->_PL_A_dV -= 77;
			Marking.P->_PL_A_dV += 76;
			Marking.P->_PL_SANodeEctopic -= 72;
			Marking.P->_PL_SANodeEctopic += 73;
       break;
     } 
		case 141: {  //I948_tr_AVJ
			Marking.P->_PL_RAConductor -= 66;
			Marking.P->_PL_RAConductor += 69;
			Marking.P->_PL_A_dV -= 76;
			Marking.P->_PL_A_dV += 75;
       break;
     } 
		case 142: {  //I949_tr_AVJ
			Marking.P->_PL_RAConductor -= 66;
			Marking.P->_PL_RAConductor += 69;
			Marking.P->_PL_A_dV -= 77;
			Marking.P->_PL_A_dV += 74;
       break;
     } 
		case 143: {  //I950_retroAVJ
			Marking.P->_PL_RAConductor -= 69;
			Marking.P->_PL_RAConductor += 67;
			Marking.P->_PL_AVJOut -= 61;
			Marking.P->_PL_AVJOut += 64;
       break;
     } 
		case 144: {  //I951_retroAVJ
			Marking.P->_PL_RAConductor -= 68;
			Marking.P->_PL_RAConductor += 69;
			Marking.P->_PL_AVJOut -= 61;
			Marking.P->_PL_AVJOut += 64;
       break;
     } 
		case 145: {  //I952_retroAVJ
			Marking.P->_PL_RAConductor -= 67;
			Marking.P->_PL_RAConductor += 67;
			Marking.P->_PL_AVJOut -= 61;
			Marking.P->_PL_AVJOut += 64;
       break;
     } 
	}
}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(TR_PL_ID t )const {
switch (t){
	case 26:	//D723_LRI
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double)  (PM_TLRI  - PM_TAVI ) ) ;
	}

		break;
	case 45:	//D771_PVARP
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double)  (PM_TPVARP  - PM_TPVAB ) ) ;
	}

		break;
	case 86:	//D177_Ante
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) (AVJDelay (avj_tRec  , AV_anteDMin ))) ;
	}

		break;
	case 87:	//D179_Retro
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) (AVJDelay (avj_tRec  , AV_retroDMin ))) ;
	}

		break;
	case 121:	//D40_Refractory
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) Atr_refrD ) ;
	}

		break;
	case 60:	//D726_q0
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) PM_TAVI ) ;
	}

		break;
	case 49:	//D774_PVAB
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) PM_TPVAB ) ;
	}

		break;
	case 51:	//D735_URI
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) PM_TURI ) ;
	}

		break;
	case 35:	//D717_VRP
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) PM_TVRP ) ;
	}

		break;
	case 120:	//D56_Ante
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) RA_anteD ) ;
	}

		break;
	case 119:	//D58_Retro
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) RA_retroD ) ;
	}

		break;
	case 77:	//D160_Ante
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) RV_anteD ) ;
	}

		break;
	case 78:	//D161_Retro
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) RV_retroD ) ;
	}

		break;
	case 74:	//D16_Wait4ABeat
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) SA_d ) ;
	}

		break;
	case 76:	//D86_q0
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) SA_ectopD ) ;
	}

		break;
	case 13:	//D10_q0
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) SA_noiseD ) ;
	}

		break;
	case 19:	//D266_Wait4VBeat
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) VRG_d ) ;
	}

		break;
	case 15:	//D279_q0
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) VRG_ectopD ) ;
	}

		break;
	case 17:	//D276_q0
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) VRG_noiseD ) ;
	}

		break;
	case 106:	//D248_Refractory
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) Vtr_refrD ) ;
	}

		break;
	case 81:	//D634_Refractory
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) avj_refr ) ;
	}

		break;
	case 80:	//D651_Ante
	case 82:	//D636_Recovery
	{
		ParamDistr[0]= ( double ) 200 ;
		ParamDistr[1]= ( double )  (200  / (double) avj_t4 ) ;
	}

		break;
	default:	//EMPTY_AP,EMPTY_APOut,EMPTY_AS,EMPTY_Aget,EMPTY_AgetOut,EMPTY_NextVtrBeat,EMPTY_RLRI,EMPTY_VP,EMPTY_VPOut,EMPTY_VS,EMPTY_Vbeat,EMPTY_Vget,EMPTY_VgetOut,I818_q0,I808_q0,I802_q0,I796_Wait4VBeat,RNextVtrBeat267_,I987_Wait4VSynch,RNextVtrBeat491_,I985_NextVtrBeat,I794_Wait4VBeat,I782_LRI,RAS724_,I983_LRI,RRLRI713_,I981_ASensed,RRLRI714_,I979_RLRI,I780_LRI,RVP758_,I977_Idle,I759_Vsig,RVget760_,I975_Idle,RVP768_,I973_Idle,RVS769_,I971_Idle,I772_Asig,RAget773_,I969_Idle,I778_URI,I902_IncrClk,I903_IncrClk,I904_IncrClk,RVS905_RURI,RVS907_RURI,RVS908_RURI,I909_IncrClk,I910_IncrClk,RAS912_RTAVI,RAP913_RTAVI,RAS914_RTAVI,RAP915_RTAVI,I916_TAVI,I917_TAVI,I918_TAVI,I919_TAVI,I920_TAVI,RAS921_RTAVI,RAP922_RTAVI,RAS923_RTAVI,RAP924_RTAVI,I798_Wait4ABeat,I792_init,I788_Refractory,I786_Refractory,I784_Refractory,I875_AVJRetroExit,I876_AVJAnteExit,I877_AVJAnteExit,I878_AVJRetroExit,I879_AVJAnteExit,I880_AVJRetroExit,I882_AVJAnteReached,I883_AVJAnteReachedHigh,I884_AVJAnteReachedHigh,I885_AVJAnteReached,I886_AVJAnteReached,I887_AVJAnteReachedHigh,I889_anteAVJ,I890_anteAVJ,I891_anteAVJ,I892_AVJRetroReached,I893_AVJRetroReached,I894_AVJRetroReached,RVbeat249_,I967_Excitable,I251_VSynch,RVP252_,I965_Excitable,I311_VsenseAnte,I309_Vsense,I926_vrg,I927_vrg,I928_vrg,I929_VtrAnteReached,I930_VtrAnteReached,RAP39_,I963_Excitable,I307_AsenseRetro,I616_Asense,I896_arg,I897_arg,I898_arg,I899_AtrRetroReached,I900_AtrRetroReached,I938_NextAtrBeat,I939_NextAtrBeat,I940_Abeat,I941_Abeat,I942_Abeat,I943_Abeat,I944_Abeat,I945_Abeat,I946_Abeat,I947_Abeat,I948_tr_AVJ,I949_tr_AVJ,I950_retroAVJ,I951_retroAVJ,I952_retroAVJ,
	{
		ParamDistr[0]= ( double ) 0 ;
	}

}
}

double SPN::GetPriority(TR_PL_ID t)const {
switch (t){
	case 45:	//D771_PVARP
	case 49:	//D774_PVAB
		return (double)0.81 ;

		break;
	case 60:	//D726_q0
		return (double)0.82 ;

		break;
	case 35:	//D717_VRP
		return (double)0.83 ;

		break;
	case 51:	//D735_URI
		return (double)0.85 ;

		break;
	case 26:	//D723_LRI
		return (double)0.86 ;

		break;
	case 80:	//D651_Ante
	case 81:	//D634_Refractory
	case 82:	//D636_Recovery
		return (double)0.88 ;

		break;
	case 19:	//D266_Wait4VBeat
		return (double)0.89 ;

		break;
	case 15:	//D279_q0
		return (double)0.9 ;

		break;
	case 121:	//D40_Refractory
		return (double)0.91 ;

		break;
	case 106:	//D248_Refractory
		return (double)0.92 ;

		break;
	case 74:	//D16_Wait4ABeat
		return (double)0.93 ;

		break;
	case 119:	//D58_Retro
	case 120:	//D56_Ante
		return (double)0.94 ;

		break;
	case 77:	//D160_Ante
	case 78:	//D161_Retro
		return (double)0.95 ;

		break;
	case 86:	//D177_Ante
	case 87:	//D179_Retro
		return (double)0.96 ;

		break;
	case 17:	//D276_q0
		return (double)0.97 ;

		break;
	case 76:	//D86_q0
		return (double)0.98 ;

		break;
	case 13:	//D10_q0
		return (double)0.99 ;

		break;
	case 42:	//I973_Idle
	case 44:	//I971_Idle
	case 46:	//I772_Asig
	case 48:	//I969_Idle
		return (double)1.81 ;

		break;
	case 65:	//I916_TAVI
	case 66:	//I917_TAVI
	case 67:	//I918_TAVI
	case 68:	//I919_TAVI
	case 69:	//I920_TAVI
		return (double)1.82 ;

		break;
	case 37:	//I977_Idle
	case 38:	//I759_Vsig
	case 40:	//I975_Idle
		return (double)1.83 ;

		break;
	case 50:	//I778_URI
	case 52:	//I902_IncrClk
	case 53:	//I903_IncrClk
	case 54:	//I904_IncrClk
	case 58:	//I909_IncrClk
	case 59:	//I910_IncrClk
		return (double)1.85 ;

		break;
	case 27:	//I782_LRI
	case 29:	//I983_LRI
	case 31:	//I981_ASensed
	case 33:	//I979_RLRI
	case 34:	//I780_LRI
		return (double)1.86 ;

		break;
	case 94:	//I882_AVJAnteReached
	case 95:	//I883_AVJAnteReachedHigh
	case 96:	//I884_AVJAnteReachedHigh
	case 97:	//I885_AVJAnteReached
	case 98:	//I886_AVJAnteReached
	case 99:	//I887_AVJAnteReachedHigh
		return (double)1.87 ;

		break;
	case 79:	//I792_init
	case 83:	//I788_Refractory
	case 84:	//I786_Refractory
	case 85:	//I784_Refractory
	case 88:	//I875_AVJRetroExit
	case 89:	//I876_AVJAnteExit
	case 90:	//I877_AVJAnteExit
	case 91:	//I878_AVJRetroExit
	case 92:	//I879_AVJAnteExit
	case 93:	//I880_AVJRetroExit
		return (double)1.88 ;

		break;
	case 20:	//I796_Wait4VBeat
	case 22:	//I987_Wait4VSynch
	case 24:	//I985_NextVtrBeat
	case 25:	//I794_Wait4VBeat
		return (double)1.89 ;

		break;
	case 16:	//I808_q0
		return (double)1.9 ;

		break;
	case 123:	//I963_Excitable
	case 124:	//I307_AsenseRetro
	case 125:	//I616_Asense
	case 126:	//I896_arg
	case 127:	//I897_arg
	case 128:	//I898_arg
	case 131:	//I938_NextAtrBeat
	case 132:	//I939_NextAtrBeat
		return (double)1.91 ;

		break;
	case 108:	//I967_Excitable
	case 109:	//I251_VSynch
	case 111:	//I965_Excitable
	case 112:	//I311_VsenseAnte
	case 113:	//I309_Vsense
	case 114:	//I926_vrg
	case 115:	//I927_vrg
	case 116:	//I928_vrg
		return (double)1.92 ;

		break;
	case 75:	//I798_Wait4ABeat
	case 133:	//I940_Abeat
	case 134:	//I941_Abeat
	case 137:	//I944_Abeat
	case 138:	//I945_Abeat
		return (double)1.93 ;

		break;
	case 129:	//I899_AtrRetroReached
	case 130:	//I900_AtrRetroReached
	case 141:	//I948_tr_AVJ
	case 142:	//I949_tr_AVJ
		return (double)1.94 ;

		break;
	case 103:	//I892_AVJRetroReached
	case 104:	//I893_AVJRetroReached
	case 105:	//I894_AVJRetroReached
	case 117:	//I929_VtrAnteReached
	case 118:	//I930_VtrAnteReached
		return (double)1.95 ;

		break;
	case 100:	//I889_anteAVJ
	case 101:	//I890_anteAVJ
	case 102:	//I891_anteAVJ
	case 143:	//I950_retroAVJ
	case 144:	//I951_retroAVJ
	case 145:	//I952_retroAVJ
		return (double)1.96 ;

		break;
	case 18:	//I802_q0
		return (double)1.97 ;

		break;
	case 135:	//I942_Abeat
	case 136:	//I943_Abeat
	case 139:	//I946_Abeat
	case 140:	//I947_Abeat
		return (double)1.98 ;

		break;
	case 14:	//I818_q0
		return (double)1.99 ;

		break;
	case 55:	//RVS905_RURI
	case 56:	//RVS907_RURI
	case 57:	//RVS908_RURI
	case 61:	//RAS912_RTAVI
	case 62:	//RAP913_RTAVI
	case 63:	//RAS914_RTAVI
	case 64:	//RAP915_RTAVI
	case 70:	//RAS921_RTAVI
	case 71:	//RAP922_RTAVI
	case 72:	//RAS923_RTAVI
	case 73:	//RAP924_RTAVI
		return (double)3.84 ;

		break;
	case 21:	//RNextVtrBeat267_
	case 23:	//RNextVtrBeat491_
	case 28:	//RAS724_
	case 30:	//RRLRI713_
	case 32:	//RRLRI714_
	case 36:	//RVP758_
	case 39:	//RVget760_
	case 41:	//RVP768_
	case 43:	//RVS769_
	case 47:	//RAget773_
	case 107:	//RVbeat249_
	case 110:	//RVP252_
	case 122:	//RAP39_
		return (double)3.99 ;

		break;
	default:	//EMPTY_AP,EMPTY_APOut,EMPTY_AS,EMPTY_Aget,EMPTY_AgetOut,EMPTY_NextVtrBeat,EMPTY_RLRI,EMPTY_VP,EMPTY_VPOut,EMPTY_VS,EMPTY_Vbeat,EMPTY_Vget,EMPTY_VgetOut,
		return (double)3 ;

}
}

double SPN::GetWeight(TR_PL_ID t)const{
		return (double)1 ;

}

void SPN::reset() {
	Marking.resetToInitMarking();
}

