#include "spnLight.hpp"
#define PL_SIG_AP_LP 0
#define PL_SIG_AS_LP 1
#define PL_SIG_RLRI_LP 2
#define PL_SIG_SREC_LP 3
#define PL_SIG_VP_LP 4
#define PL_SIG_VS_LP 5
#define PL_SIG_Vget_LP 6
#define PL_TAVIcmp_LP 7
#define PL_AVI_LP 8
#define PL_URI_LP 9
#define PL_PVARP_LP 10
#define PL_SerialPort_LP 11
#define PL_PaceLedVentricle_LP 12
#define PL_PaceLedAtrium_LP 13
#define PL_VRP_LP 14
#define PL_LRI_LP 15
#define TR_EMPTY_AP_RT 0
#define TR_EMPTY_AS_RT 1
#define TR_EMPTY_RLRI_RT 2
#define TR_EMPTY_SREC_RT 3
#define TR_EMPTY_VP_RT 4
#define TR_EMPTY_VS_RT 5
#define TR_EMPTY_Vget_RT 6
#define TR_INCOMING_SREC_RT 7
#define TR_D888_LRI_RT 8
#define TR_I1004_L_LRI_RT 9
#define TR_RAS891__RT 10
#define TR_I1115_L_LRI_RT 11
#define TR_RRLRI892__RT 12
#define TR_I1113_L_ASensed_RT 13
#define TR_RRLRI893__RT 14
#define TR_I1111_RLRI_RT 15
#define TR_I1002_L_LRI_RT 16
#define TR_I1000_init_RT 17
#define TR_D923_L_VRP_RT 18
#define TR_I994_init_RT 19
#define TR_RVP926__RT 20
#define TR_I1109_L_Idle_RT 21
#define TR_I927_L_Vsig_RT 22
#define TR_RVget928__RT 23
#define TR_I1107_L_Idle_RT 24
#define TR_I984_init_RT 25
#define TR_D969_L_On_RT 26
#define TR_RAP964__RT 27
#define TR_I1105_L_Off_RT 28
#define TR_I982_init_RT 29
#define TR_D974_L_On_RT 30
#define TR_RVP975__RT 31
#define TR_I1103_L_Off_RT 32
#define TR_C1065_S_Aget_L_Receive_RT 33
#define TR_C1064_S_Aget_L_Receive_RT 34
#define TR_C1063_S_Aget_L_Idle_L_Receive_RT 35
#define TR_I986_init_RT 36
#define TR_C956_L_Receive_RT 37
#define TR_RSREC959__RT 38
#define TR_I1101_L_NoData_RT 39
#define TR_RVP938__RT 40
#define TR_I1099_L_Idle_RT 41
#define TR_RVS939__RT 42
#define TR_I1097_L_Idle_RT 43
#define TR_I988_init_RT 44
#define TR_D941_L_PVARP_RT 45
#define TR_I942_L_Asig_RT 46
#define TR_D944_L_PVAB_RT 47
#define TR_RAP1089_S_RTAVI_L_Idle0_RT 48
#define TR_RAS1088_S_RTAVI_L_Idle0_RT 49
#define TR_RAP1087_S_RTAVI_L_Idle1_RT 50
#define TR_RAS1086_S_RTAVI_L_Idle1_RT 51
#define TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT 52
#define TR_I1084_S_TAVI_L_q0_RT 53
#define TR_I1083_S_TAVI_L_q0_RT 54
#define TR_I1082_S_TAVI_L_q0_RT 55
#define TR_I1081_S_TAVI_L_q0_L_AVI0_RT 56
#define TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT 57
#define TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT 58
#define TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT 59
#define TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT 60
#define TR_I1075_S_IncrClk_L_q1_RT 61
#define TR_I1074_S_IncrClk_L_q1_RT 62
#define TR_RVS1073_S_RURI_L_WaitURI_RURI_RT 63
#define TR_RVS1072_S_RURI_L_AVI0_RURI_RT 64
#define TR_RVS1070_S_RURI_L_AVI1_RURI_RT 65
#define TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT 66
#define TR_I1068_S_IncrClk_L_AVI0_L_q1_RT 67
#define TR_I1067_S_IncrClk_L_Idle0_L_q1_RT 68
#define TR_I998_L_URI_RT 69
#define TR_D900_L_URI_RT 70
#define TR_I996_init_RT 71
#define TR_D931_q0_RT 72
#define TR_I990_init_RT 73

	const int _nb_Place_SIG_AP=0;
	const int _nb_Place_SIG_AS=1;
	const int _nb_Place_SIG_RLRI=2;
	const int _nb_Place_SIG_SREC=3;
	const int _nb_Place_SIG_VP=4;
	const int _nb_Place_SIG_VS=5;
	const int _nb_Place_SIG_Vget=6;
	const int _nb_Place_TAVIcmp=7;
	const int _nb_Place_AVI=8;
	const int _nb_Place_URI=9;
	const int _nb_Place_PVARP=10;
	const int _nb_Place_SerialPort=11;
	const int _nb_Place_PaceLedVentricle=12;
	const int _nb_Place_PaceLedAtrium=13;
	const int _nb_Place_VRP=14;
	const int _nb_Place_LRI=15;
#include "magicLight.hpp"
#include "markingImplLight.hpp"

void abstractMarking::resetToInitMarking(){
	magicReset();
	P->_PL_SIG_AP =0;
	P->_PL_SIG_AS =0;
	P->_PL_SIG_RLRI =0;
	P->_PL_SIG_SREC =0;
	P->_PL_SIG_VP =0;
	P->_PL_SIG_VS =0;
	P->_PL_SIG_Vget =0;
	P->_PL_TAVIcmp =989;
	P->_PL_AVI =907;
	P->_PL_URI =995;
	P->_PL_PVARP =987;
	P->_PL_SerialPort =985;
	P->_PL_PaceLedVentricle =981;
	P->_PL_PaceLedAtrium =983;
	P->_PL_VRP =993;
	P->_PL_LRI =999;
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
::print("SIG_SREC	");
::print("SIG_VP	");
::print("SIG_VS	");
::print("SIG_Vget	");
::print("TAVIcmp	");
::print("AVI	");
::print("URI	");
::print("PVARP	");
::print("SerialPort	");
::print("PaceLedVentricle	");
::print("PaceLedAtrium	");
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
print_magic(P->_PL_SIG_SREC);
::print("	");
print_magic(P->_PL_SIG_VP);
::print("	");
print_magic(P->_PL_SIG_VS);
::print("	");
print_magic(P->_PL_SIG_Vget);
::print("	");
print_magic(P->_PL_TAVIcmp);
::print("	");
print_magic(P->_PL_AVI);
::print("	");
print_magic(P->_PL_URI);
::print("	");
print_magic(P->_PL_PVARP);
::print("	");
print_magic(P->_PL_SerialPort);
::print("	");
print_magic(P->_PL_PaceLedVentricle);
::print("	");
print_magic(P->_PL_PaceLedAtrium);
::print("	");
print_magic(P->_PL_VRP);
::print("	");
print_magic(P->_PL_LRI);
::print("	");
}
static const TR_PL_ID EMPTY_array[1]={UNSET_TRANS};
static const TR_PL_ID PE_PossiblyEnabled_0[2]= {TR_I1004_L_LRI_RT, -1 }; /* EMPTY_AP*/
static const TR_PL_ID PE_PossiblyEnabled_1[2]= {TR_I942_L_Asig_RT, -1 }; /* EMPTY_AS*/
static const TR_PL_ID PE_PossiblyEnabled_2[4]= {TR_I927_L_Vsig_RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* EMPTY_RLRI*/
static const TR_PL_ID PE_PossiblyEnabled_3[2]= {TR_INCOMING_SREC_RT, -1 }; /* EMPTY_SREC*/
static const TR_PL_ID PE_PossiblyEnabled_4[3]= {TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* EMPTY_VP*/
static const TR_PL_ID PE_PossiblyEnabled_5[2]= {TR_I927_L_Vsig_RT, -1 }; /* EMPTY_VS*/
static const TR_PL_ID PE_PossiblyEnabled_6[2]= {TR_C956_L_Receive_RT, -1 }; /* EMPTY_Vget*/
static const TR_PL_ID PE_PossiblyEnabled_7[3]= {TR_EMPTY_SREC_RT, TR_RSREC959__RT, -1 }; /* INCOMING_SREC*/
static const TR_PL_ID PE_PossiblyEnabled_8[2]= {TR_I1004_L_LRI_RT, -1 }; /* D888_LRI*/
static const TR_PL_ID PE_PossiblyEnabled_9[10]= {TR_EMPTY_AP_RT, TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI893__RT, TR_RAP964__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* I1004_L_LRI*/
static const TR_PL_ID PE_PossiblyEnabled_10[8]= {TR_EMPTY_AS_RT, TR_I1115_L_LRI_RT, TR_I942_L_Asig_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* RAS891_*/
static const TR_PL_ID PE_PossiblyEnabled_11[2]= {TR_RRLRI892__RT, -1 }; /* I1115_L_LRI*/
static const TR_PL_ID PE_PossiblyEnabled_12[7]= {TR_EMPTY_RLRI_RT, TR_I1113_L_ASensed_RT, TR_RRLRI893__RT, TR_I927_L_Vsig_RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RRLRI892_*/
static const TR_PL_ID PE_PossiblyEnabled_13[4]= {TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI893__RT, -1 }; /* I1113_L_ASensed*/
static const TR_PL_ID PE_PossiblyEnabled_14[7]= {TR_EMPTY_RLRI_RT, TR_RRLRI892__RT, TR_I1111_RLRI_RT, TR_I927_L_Vsig_RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RRLRI893_*/
static const TR_PL_ID PE_PossiblyEnabled_15[2]= {TR_I1002_L_LRI_RT, -1 }; /* I1111_RLRI*/
static const TR_PL_ID PE_PossiblyEnabled_16[4]= {TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI893__RT, -1 }; /* I1002_L_LRI*/
static const TR_PL_ID PE_PossiblyEnabled_17[4]= {TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI893__RT, -1 }; /* I1000_init*/
static const TR_PL_ID PE_PossiblyEnabled_18[3]= {TR_RVP926__RT, TR_RVget928__RT, -1 }; /* D923_L_VRP*/
static const TR_PL_ID PE_PossiblyEnabled_19[3]= {TR_RVP926__RT, TR_RVget928__RT, -1 }; /* I994_init*/
static const TR_PL_ID PE_PossiblyEnabled_20[7]= {TR_EMPTY_VP_RT, TR_I1109_L_Idle_RT, TR_RVP975__RT, TR_RVP938__RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RVP926_*/
static const TR_PL_ID PE_PossiblyEnabled_21[2]= {TR_D923_L_VRP_RT, -1 }; /* I1109_L_Idle*/
static const TR_PL_ID PE_PossiblyEnabled_22[11]= {TR_EMPTY_RLRI_RT, TR_EMPTY_VS_RT, TR_RRLRI892__RT, TR_RRLRI893__RT, TR_RVP926__RT, TR_RVget928__RT, TR_RVS939__RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, -1 }; /* I927_L_Vsig*/
static const TR_PL_ID PE_PossiblyEnabled_23[4]= {TR_EMPTY_Vget_RT, TR_I1107_L_Idle_RT, TR_C956_L_Receive_RT, -1 }; /* RVget928_*/
static const TR_PL_ID PE_PossiblyEnabled_24[2]= {TR_I927_L_Vsig_RT, -1 }; /* I1107_L_Idle*/
static const TR_PL_ID PE_PossiblyEnabled_25[2]= {TR_RAP964__RT, -1 }; /* I984_init*/
static const TR_PL_ID PE_PossiblyEnabled_26[2]= {TR_RAP964__RT, -1 }; /* D969_L_On*/
static const TR_PL_ID PE_PossiblyEnabled_27[8]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_I1105_L_Off_RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* RAP964_*/
static const TR_PL_ID PE_PossiblyEnabled_28[2]= {TR_D969_L_On_RT, -1 }; /* I1105_L_Off*/
static const TR_PL_ID PE_PossiblyEnabled_29[2]= {TR_RVP975__RT, -1 }; /* I982_init*/
static const TR_PL_ID PE_PossiblyEnabled_30[2]= {TR_RVP975__RT, -1 }; /* D974_L_On*/
static const TR_PL_ID PE_PossiblyEnabled_31[7]= {TR_EMPTY_VP_RT, TR_RVP926__RT, TR_I1103_L_Off_RT, TR_RVP938__RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RVP975_*/
static const TR_PL_ID PE_PossiblyEnabled_32[2]= {TR_D974_L_On_RT, -1 }; /* I1103_L_Off*/
static const TR_PL_ID PE_PossiblyEnabled_33[3]= {TR_RSREC959__RT, TR_D944_L_PVAB_RT, -1 }; /* C1065_S_Aget_L_Receive*/
static const TR_PL_ID PE_PossiblyEnabled_34[3]= {TR_RSREC959__RT, TR_D941_L_PVARP_RT, -1 }; /* C1064_S_Aget_L_Receive*/
static const TR_PL_ID PE_PossiblyEnabled_35[3]= {TR_RSREC959__RT, TR_I942_L_Asig_RT, -1 }; /* C1063_S_Aget_L_Idle_L_Receive*/
static const TR_PL_ID PE_PossiblyEnabled_36[2]= {TR_RSREC959__RT, -1 }; /* I986_init*/
static const TR_PL_ID PE_PossiblyEnabled_37[4]= {TR_EMPTY_Vget_RT, TR_RVget928__RT, TR_RSREC959__RT, -1 }; /* C956_L_Receive*/
static const TR_PL_ID PE_PossiblyEnabled_38[4]= {TR_EMPTY_SREC_RT, TR_INCOMING_SREC_RT, TR_I1101_L_NoData_RT, -1 }; /* RSREC959_*/
static const TR_PL_ID PE_PossiblyEnabled_39[5]= {TR_C1065_S_Aget_L_Receive_RT, TR_C1064_S_Aget_L_Receive_RT, TR_C1063_S_Aget_L_Idle_L_Receive_RT, TR_C956_L_Receive_RT, -1 }; /* I1101_L_NoData*/
static const TR_PL_ID PE_PossiblyEnabled_40[7]= {TR_EMPTY_VP_RT, TR_RVP926__RT, TR_RVP975__RT, TR_I1099_L_Idle_RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RVP938_*/
static const TR_PL_ID PE_PossiblyEnabled_41[3]= {TR_C1065_S_Aget_L_Receive_RT, TR_D944_L_PVAB_RT, -1 }; /* I1099_L_Idle*/
static const TR_PL_ID PE_PossiblyEnabled_42[7]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_I1097_L_Idle_RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, -1 }; /* RVS939_*/
static const TR_PL_ID PE_PossiblyEnabled_43[3]= {TR_C1065_S_Aget_L_Receive_RT, TR_D944_L_PVAB_RT, -1 }; /* I1097_L_Idle*/
static const TR_PL_ID PE_PossiblyEnabled_44[4]= {TR_C1063_S_Aget_L_Idle_L_Receive_RT, TR_RVP938__RT, TR_RVS939__RT, -1 }; /* I988_init*/
static const TR_PL_ID PE_PossiblyEnabled_45[4]= {TR_C1063_S_Aget_L_Idle_L_Receive_RT, TR_RVP938__RT, TR_RVS939__RT, -1 }; /* D941_L_PVARP*/
static const TR_PL_ID PE_PossiblyEnabled_46[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_C1063_S_Aget_L_Idle_L_Receive_RT, TR_RVP938__RT, TR_RVS939__RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* I942_L_Asig*/
static const TR_PL_ID PE_PossiblyEnabled_47[3]= {TR_C1064_S_Aget_L_Receive_RT, TR_D941_L_PVARP_RT, -1 }; /* D944_L_PVAB*/
static const TR_PL_ID PE_PossiblyEnabled_48[10]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_RAP964__RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_I1068_S_IncrClk_L_AVI0_L_q1_RT, TR_D931_q0_RT, -1 }; /* RAP1089_S_RTAVI_L_Idle0*/
static const TR_PL_ID PE_PossiblyEnabled_49[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_I1068_S_IncrClk_L_AVI0_L_q1_RT, TR_D931_q0_RT, -1 }; /* RAS1088_S_RTAVI_L_Idle0*/
static const TR_PL_ID PE_PossiblyEnabled_50[10]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_RAP964__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_I1074_S_IncrClk_L_q1_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D931_q0_RT, -1 }; /* RAP1087_S_RTAVI_L_Idle1*/
static const TR_PL_ID PE_PossiblyEnabled_51[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_I1074_S_IncrClk_L_q1_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D931_q0_RT, -1 }; /* RAS1086_S_RTAVI_L_Idle1*/
static const TR_PL_ID PE_PossiblyEnabled_52[12]= {TR_EMPTY_RLRI_RT, TR_EMPTY_VP_RT, TR_RRLRI892__RT, TR_RRLRI893__RT, TR_RVP926__RT, TR_RVP975__RT, TR_RVP938__RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, TR_I998_L_URI_RT, -1 }; /* I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI*/
static const TR_PL_ID PE_PossiblyEnabled_53[4]= {TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_I1067_S_IncrClk_L_Idle0_L_q1_RT, -1 }; /* I1084_S_TAVI_L_q0*/
static const TR_PL_ID PE_PossiblyEnabled_54[3]= {TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* I1083_S_TAVI_L_q0*/
static const TR_PL_ID PE_PossiblyEnabled_55[4]= {TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_I1075_S_IncrClk_L_q1_RT, -1 }; /* I1082_S_TAVI_L_q0*/
static const TR_PL_ID PE_PossiblyEnabled_56[3]= {TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* I1081_S_TAVI_L_q0_L_AVI0*/
static const TR_PL_ID PE_PossiblyEnabled_57[10]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_RAP964__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_I1068_S_IncrClk_L_AVI0_L_q1_RT, TR_D931_q0_RT, -1 }; /* RAP1080_S_RTAVI_L_q1_L_Idle0*/
static const TR_PL_ID PE_PossiblyEnabled_58[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_I1068_S_IncrClk_L_AVI0_L_q1_RT, TR_D931_q0_RT, -1 }; /* RAS1079_S_RTAVI_L_q1_L_Idle0*/
static const TR_PL_ID PE_PossiblyEnabled_59[10]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_RAP964__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_I1074_S_IncrClk_L_q1_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D931_q0_RT, -1 }; /* RAP1078_S_RTAVI_L_q1_L_Idle1*/
static const TR_PL_ID PE_PossiblyEnabled_60[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_I1074_S_IncrClk_L_q1_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D931_q0_RT, -1 }; /* RAS1077_S_RTAVI_L_q1_L_Idle1*/
static const TR_PL_ID PE_PossiblyEnabled_61[7]= {TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_I1082_S_TAVI_L_q0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_D900_L_URI_RT, -1 }; /* I1075_S_IncrClk_L_q1*/
static const TR_PL_ID PE_PossiblyEnabled_62[4]= {TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D900_L_URI_RT, -1 }; /* I1074_S_IncrClk_L_q1*/
static const TR_PL_ID PE_PossiblyEnabled_63[12]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_I1084_S_TAVI_L_q0_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_I998_L_URI_RT, -1 }; /* RVS1073_S_RURI_L_WaitURI_RURI*/
static const TR_PL_ID PE_PossiblyEnabled_64[12]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_I1084_S_TAVI_L_q0_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_I998_L_URI_RT, -1 }; /* RVS1072_S_RURI_L_AVI0_RURI*/
static const TR_PL_ID PE_PossiblyEnabled_65[12]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_I1084_S_TAVI_L_q0_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_I998_L_URI_RT, -1 }; /* RVS1070_S_RURI_L_AVI1_RURI*/
static const TR_PL_ID PE_PossiblyEnabled_66[15]= {TR_EMPTY_RLRI_RT, TR_EMPTY_VP_RT, TR_RRLRI892__RT, TR_RRLRI893__RT, TR_RVP926__RT, TR_RVP975__RT, TR_RVP938__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1084_S_TAVI_L_q0_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_D900_L_URI_RT, -1 }; /* I1069_S_IncrClk_L_WaitURI_L_q1*/
static const TR_PL_ID PE_PossiblyEnabled_67[4]= {TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D900_L_URI_RT, -1 }; /* I1068_S_IncrClk_L_AVI0_L_q1*/
static const TR_PL_ID PE_PossiblyEnabled_68[7]= {TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_I1082_S_TAVI_L_q0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_D900_L_URI_RT, -1 }; /* I1067_S_IncrClk_L_Idle0_L_q1*/
static const TR_PL_ID PE_PossiblyEnabled_69[6]= {TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D900_L_URI_RT, -1 }; /* I998_L_URI*/
static const TR_PL_ID PE_PossiblyEnabled_70[6]= {TR_I1075_S_IncrClk_L_q1_RT, TR_I1074_S_IncrClk_L_q1_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1068_S_IncrClk_L_AVI0_L_q1_RT, TR_I1067_S_IncrClk_L_Idle0_L_q1_RT, -1 }; /* D900_L_URI*/
static const TR_PL_ID PE_PossiblyEnabled_71[6]= {TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D900_L_URI_RT, -1 }; /* I996_init*/
static const TR_PL_ID PE_PossiblyEnabled_72[6]= {TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1084_S_TAVI_L_q0_RT, TR_I1083_S_TAVI_L_q0_RT, TR_I1082_S_TAVI_L_q0_RT, TR_I1081_S_TAVI_L_q0_L_AVI0_RT, -1 }; /* D931_q0*/
static const TR_PL_ID PE_PossiblyEnabled_73[5]= {TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* I990_init*/
const TR_PL_ID* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, PE_PossiblyEnabled_2, PE_PossiblyEnabled_3, PE_PossiblyEnabled_4, PE_PossiblyEnabled_5, PE_PossiblyEnabled_6, PE_PossiblyEnabled_7, PE_PossiblyEnabled_8, PE_PossiblyEnabled_9, PE_PossiblyEnabled_10, PE_PossiblyEnabled_11, PE_PossiblyEnabled_12, PE_PossiblyEnabled_13, PE_PossiblyEnabled_14, PE_PossiblyEnabled_15, PE_PossiblyEnabled_16, PE_PossiblyEnabled_17, PE_PossiblyEnabled_18, PE_PossiblyEnabled_19, PE_PossiblyEnabled_20, PE_PossiblyEnabled_21, PE_PossiblyEnabled_22, PE_PossiblyEnabled_23, PE_PossiblyEnabled_24, PE_PossiblyEnabled_25, PE_PossiblyEnabled_26, PE_PossiblyEnabled_27, PE_PossiblyEnabled_28, PE_PossiblyEnabled_29, PE_PossiblyEnabled_30, PE_PossiblyEnabled_31, PE_PossiblyEnabled_32, PE_PossiblyEnabled_33, PE_PossiblyEnabled_34, PE_PossiblyEnabled_35, PE_PossiblyEnabled_36, PE_PossiblyEnabled_37, PE_PossiblyEnabled_38, PE_PossiblyEnabled_39, PE_PossiblyEnabled_40, PE_PossiblyEnabled_41, PE_PossiblyEnabled_42, PE_PossiblyEnabled_43, PE_PossiblyEnabled_44, PE_PossiblyEnabled_45, PE_PossiblyEnabled_46, PE_PossiblyEnabled_47, PE_PossiblyEnabled_48, PE_PossiblyEnabled_49, PE_PossiblyEnabled_50, PE_PossiblyEnabled_51, PE_PossiblyEnabled_52, PE_PossiblyEnabled_53, PE_PossiblyEnabled_54, PE_PossiblyEnabled_55, PE_PossiblyEnabled_56, PE_PossiblyEnabled_57, PE_PossiblyEnabled_58, PE_PossiblyEnabled_59, PE_PossiblyEnabled_60, PE_PossiblyEnabled_61, PE_PossiblyEnabled_62, PE_PossiblyEnabled_63, PE_PossiblyEnabled_64, PE_PossiblyEnabled_65, PE_PossiblyEnabled_66, PE_PossiblyEnabled_67, PE_PossiblyEnabled_68, PE_PossiblyEnabled_69, PE_PossiblyEnabled_70, PE_PossiblyEnabled_71, PE_PossiblyEnabled_72, PE_PossiblyEnabled_73};

static const TR_PL_ID PE_PossiblyDisabled_0[6]= {TR_RAP964__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* EMPTY_AP*/
static const TR_PL_ID PE_PossiblyDisabled_1[6]= {TR_RAS891__RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* EMPTY_AS*/
static const TR_PL_ID PE_PossiblyDisabled_2[3]= {TR_RRLRI892__RT, TR_RRLRI893__RT, -1 }; /* EMPTY_RLRI*/
static const TR_PL_ID PE_PossiblyDisabled_3[2]= {TR_RSREC959__RT, -1 }; /* EMPTY_SREC*/
static const TR_PL_ID PE_PossiblyDisabled_4[4]= {TR_RVP926__RT, TR_RVP975__RT, TR_RVP938__RT, -1 }; /* EMPTY_VP*/
static const TR_PL_ID PE_PossiblyDisabled_5[5]= {TR_RVS939__RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, -1 }; /* EMPTY_VS*/
static const TR_PL_ID PE_PossiblyDisabled_6[2]= {TR_RVget928__RT, -1 }; /* EMPTY_Vget*/
static const TR_PL_ID PE_PossiblyDisabled_8[3]= {TR_RAS891__RT, TR_RRLRI893__RT, -1 }; /* D888_LRI*/
static const TR_PL_ID PE_PossiblyDisabled_10[9]= {TR_EMPTY_AS_RT, TR_D888_LRI_RT, TR_RRLRI893__RT, TR_I942_L_Asig_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* RAS891_*/
static const TR_PL_ID PE_PossiblyDisabled_12[6]= {TR_EMPTY_RLRI_RT, TR_RRLRI893__RT, TR_I927_L_Vsig_RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RRLRI892_*/
static const TR_PL_ID PE_PossiblyDisabled_14[8]= {TR_EMPTY_RLRI_RT, TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI892__RT, TR_I927_L_Vsig_RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RRLRI893_*/
static const TR_PL_ID PE_PossiblyDisabled_20[7]= {TR_EMPTY_VP_RT, TR_RVget928__RT, TR_RVP975__RT, TR_RVP938__RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RVP926_*/
static const TR_PL_ID PE_PossiblyDisabled_22[3]= {TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* I927_L_Vsig*/
static const TR_PL_ID PE_PossiblyDisabled_23[4]= {TR_EMPTY_Vget_RT, TR_RVP926__RT, TR_C956_L_Receive_RT, -1 }; /* RVget928_*/
static const TR_PL_ID PE_PossiblyDisabled_27[7]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* RAP964_*/
static const TR_PL_ID PE_PossiblyDisabled_31[6]= {TR_EMPTY_VP_RT, TR_RVP926__RT, TR_RVP938__RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RVP975_*/
static const TR_PL_ID PE_PossiblyDisabled_33[3]= {TR_C956_L_Receive_RT, TR_D944_L_PVAB_RT, -1 }; /* C1065_S_Aget_L_Receive*/
static const TR_PL_ID PE_PossiblyDisabled_34[3]= {TR_C956_L_Receive_RT, TR_D941_L_PVARP_RT, -1 }; /* C1064_S_Aget_L_Receive*/
static const TR_PL_ID PE_PossiblyDisabled_35[4]= {TR_C956_L_Receive_RT, TR_RVP938__RT, TR_RVS939__RT, -1 }; /* C1063_S_Aget_L_Idle_L_Receive*/
static const TR_PL_ID PE_PossiblyDisabled_37[4]= {TR_C1065_S_Aget_L_Receive_RT, TR_C1064_S_Aget_L_Receive_RT, TR_C1063_S_Aget_L_Idle_L_Receive_RT, -1 }; /* C956_L_Receive*/
static const TR_PL_ID PE_PossiblyDisabled_38[3]= {TR_EMPTY_SREC_RT, TR_INCOMING_SREC_RT, -1 }; /* RSREC959_*/
static const TR_PL_ID PE_PossiblyDisabled_40[8]= {TR_EMPTY_VP_RT, TR_RVP926__RT, TR_RVP975__RT, TR_C1063_S_Aget_L_Idle_L_Receive_RT, TR_RVS939__RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* RVP938_*/
static const TR_PL_ID PE_PossiblyDisabled_42[8]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_C1063_S_Aget_L_Idle_L_Receive_RT, TR_RVP938__RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, -1 }; /* RVS939_*/
static const TR_PL_ID PE_PossiblyDisabled_45[2]= {TR_C1064_S_Aget_L_Receive_RT, -1 }; /* D941_L_PVARP*/
static const TR_PL_ID PE_PossiblyDisabled_47[2]= {TR_C1065_S_Aget_L_Receive_RT, -1 }; /* D944_L_PVAB*/
static const TR_PL_ID PE_PossiblyDisabled_48[10]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_RAP964__RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_I1067_S_IncrClk_L_Idle0_L_q1_RT, TR_D931_q0_RT, -1 }; /* RAP1089_S_RTAVI_L_Idle0*/
static const TR_PL_ID PE_PossiblyDisabled_49[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_I1067_S_IncrClk_L_Idle0_L_q1_RT, TR_D931_q0_RT, -1 }; /* RAS1088_S_RTAVI_L_Idle0*/
static const TR_PL_ID PE_PossiblyDisabled_50[10]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_RAP964__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_I1075_S_IncrClk_L_q1_RT, TR_D931_q0_RT, -1 }; /* RAP1087_S_RTAVI_L_Idle1*/
static const TR_PL_ID PE_PossiblyDisabled_51[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_I1075_S_IncrClk_L_q1_RT, TR_D931_q0_RT, -1 }; /* RAS1086_S_RTAVI_L_Idle1*/
static const TR_PL_ID PE_PossiblyDisabled_52[5]= {TR_I927_L_Vsig_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, TR_D900_L_URI_RT, -1 }; /* I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI*/
static const TR_PL_ID PE_PossiblyDisabled_53[2]= {TR_I1067_S_IncrClk_L_Idle0_L_q1_RT, -1 }; /* I1084_S_TAVI_L_q0*/
static const TR_PL_ID PE_PossiblyDisabled_54[3]= {TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT, -1 }; /* I1083_S_TAVI_L_q0*/
static const TR_PL_ID PE_PossiblyDisabled_55[2]= {TR_I1075_S_IncrClk_L_q1_RT, -1 }; /* I1082_S_TAVI_L_q0*/
static const TR_PL_ID PE_PossiblyDisabled_56[3]= {TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_I1068_S_IncrClk_L_AVI0_L_q1_RT, -1 }; /* I1081_S_TAVI_L_q0_L_AVI0*/
static const TR_PL_ID PE_PossiblyDisabled_57[9]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_RAP964__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_I1067_S_IncrClk_L_Idle0_L_q1_RT, -1 }; /* RAP1080_S_RTAVI_L_q1_L_Idle0*/
static const TR_PL_ID PE_PossiblyDisabled_58[9]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_I1067_S_IncrClk_L_Idle0_L_q1_RT, -1 }; /* RAS1079_S_RTAVI_L_q1_L_Idle0*/
static const TR_PL_ID PE_PossiblyDisabled_59[9]= {TR_EMPTY_AP_RT, TR_I1004_L_LRI_RT, TR_RAP964__RT, TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, TR_I1075_S_IncrClk_L_q1_RT, -1 }; /* RAP1078_S_RTAVI_L_q1_L_Idle1*/
static const TR_PL_ID PE_PossiblyDisabled_60[9]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_I1075_S_IncrClk_L_q1_RT, -1 }; /* RAS1077_S_RTAVI_L_q1_L_Idle1*/
static const TR_PL_ID PE_PossiblyDisabled_61[6]= {TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, TR_I1082_S_TAVI_L_q0_RT, TR_RAP1078_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1077_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* I1075_S_IncrClk_L_q1*/
static const TR_PL_ID PE_PossiblyDisabled_63[8]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_I1083_S_TAVI_L_q0_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D900_L_URI_RT, -1 }; /* RVS1073_S_RURI_L_WaitURI_RURI*/
static const TR_PL_ID PE_PossiblyDisabled_64[8]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_I1081_S_TAVI_L_q0_L_AVI0_RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, TR_D900_L_URI_RT, -1 }; /* RVS1072_S_RURI_L_AVI0_RURI*/
static const TR_PL_ID PE_PossiblyDisabled_65[8]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_D900_L_URI_RT, -1 }; /* RVS1070_S_RURI_L_AVI1_RURI*/
static const TR_PL_ID PE_PossiblyDisabled_66[4]= {TR_I927_L_Vsig_RT, TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1083_S_TAVI_L_q0_RT, -1 }; /* I1069_S_IncrClk_L_WaitURI_L_q1*/
static const TR_PL_ID PE_PossiblyDisabled_67[2]= {TR_I1081_S_TAVI_L_q0_L_AVI0_RT, -1 }; /* I1068_S_IncrClk_L_AVI0_L_q1*/
static const TR_PL_ID PE_PossiblyDisabled_68[6]= {TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_I1084_S_TAVI_L_q0_RT, TR_RAP1080_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1079_S_RTAVI_L_q1_L_Idle0_RT, -1 }; /* I1067_S_IncrClk_L_Idle0_L_q1*/
static const TR_PL_ID PE_PossiblyDisabled_70[5]= {TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_RVS1073_S_RURI_L_WaitURI_RURI_RT, TR_RVS1072_S_RURI_L_AVI0_RURI_RT, TR_RVS1070_S_RURI_L_AVI1_RURI_RT, -1 }; /* D900_L_URI*/
static const TR_PL_ID PE_PossiblyDisabled_72[5]= {TR_RAP1089_S_RTAVI_L_Idle0_RT, TR_RAS1088_S_RTAVI_L_Idle0_RT, TR_RAP1087_S_RTAVI_L_Idle1_RT, TR_RAS1086_S_RTAVI_L_Idle1_RT, -1 }; /* D931_q0*/
const TR_PL_ID* SPN::PossiblyDisabled[] = {PE_PossiblyDisabled_0, PE_PossiblyDisabled_1, PE_PossiblyDisabled_2, PE_PossiblyDisabled_3, PE_PossiblyDisabled_4, PE_PossiblyDisabled_5, PE_PossiblyDisabled_6, EMPTY_array, PE_PossiblyDisabled_8, EMPTY_array, PE_PossiblyDisabled_10, EMPTY_array, PE_PossiblyDisabled_12, EMPTY_array, PE_PossiblyDisabled_14, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, PE_PossiblyDisabled_20, EMPTY_array, PE_PossiblyDisabled_22, PE_PossiblyDisabled_23, EMPTY_array, EMPTY_array, EMPTY_array, PE_PossiblyDisabled_27, EMPTY_array, EMPTY_array, EMPTY_array, PE_PossiblyDisabled_31, EMPTY_array, PE_PossiblyDisabled_33, PE_PossiblyDisabled_34, PE_PossiblyDisabled_35, EMPTY_array, PE_PossiblyDisabled_37, PE_PossiblyDisabled_38, EMPTY_array, PE_PossiblyDisabled_40, EMPTY_array, PE_PossiblyDisabled_42, EMPTY_array, EMPTY_array, PE_PossiblyDisabled_45, EMPTY_array, PE_PossiblyDisabled_47, PE_PossiblyDisabled_48, PE_PossiblyDisabled_49, PE_PossiblyDisabled_50, PE_PossiblyDisabled_51, PE_PossiblyDisabled_52, PE_PossiblyDisabled_53, PE_PossiblyDisabled_54, PE_PossiblyDisabled_55, PE_PossiblyDisabled_56, PE_PossiblyDisabled_57, PE_PossiblyDisabled_58, PE_PossiblyDisabled_59, PE_PossiblyDisabled_60, PE_PossiblyDisabled_61, EMPTY_array, PE_PossiblyDisabled_63, PE_PossiblyDisabled_64, PE_PossiblyDisabled_65, PE_PossiblyDisabled_66, PE_PossiblyDisabled_67, PE_PossiblyDisabled_68, EMPTY_array, PE_PossiblyDisabled_70, EMPTY_array, PE_PossiblyDisabled_72, EMPTY_array};

const TR_PL_ID* SPN::FreeMarkDepT[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

SPN::SPN():
pl(16), tr(74) {
}

TR_PL_ID SPN::getIncomingTrans(){ return TR_INCOMING_SREC_RT;};

bool SPN::IsEnabled(TR_PL_ID t)const {
	if(!magicConditional(t))return false;
switch (t){
	case 50:	//RAP1087_S_RTAVI_L_Idle1
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    if( Marking.P->_PL_AVI != 895) return false;
    return true;

		break;
	case 48:	//RAP1089_S_RTAVI_L_Idle0
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 59:	//RAP1078_S_RTAVI_L_q1_L_Idle1
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 930) return false;
    if( Marking.P->_PL_AVI != 895) return false;
    return true;

		break;
	case 57:	//RAP1080_S_RTAVI_L_q1_L_Idle0
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 930) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 0:	//EMPTY_AP
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    return true;

		break;
	case 10:	//RAS891_
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_LRI != 886) return false;
    return true;

		break;
	case 51:	//RAS1086_S_RTAVI_L_Idle1
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    if( Marking.P->_PL_AVI != 895) return false;
    return true;

		break;
	case 49:	//RAS1088_S_RTAVI_L_Idle0
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 60:	//RAS1077_S_RTAVI_L_q1_L_Idle1
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 930) return false;
    if( Marking.P->_PL_AVI != 895) return false;
    return true;

		break;
	case 58:	//RAS1079_S_RTAVI_L_q1_L_Idle0
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 930) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 1:	//EMPTY_AS
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    return true;

		break;
	case 14:	//RRLRI893_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 886) return false;
    return true;

		break;
	case 12:	//RRLRI892_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 887) return false;
    return true;

		break;
	case 2:	//EMPTY_RLRI
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    return true;

		break;
	case 38:	//RSREC959_
    if (!(contains(Marking.P->_PL_SIG_SREC , 1))) return false;
    if( Marking.P->_PL_SerialPort != 949) return false;
    return true;

		break;
	case 3:	//EMPTY_SREC
    if (!(contains(Marking.P->_PL_SIG_SREC , 1))) return false;
    return true;

		break;
	case 40:	//RVP938_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_PVARP != 934) return false;
    return true;

		break;
	case 31:	//RVP975_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_PaceLedVentricle != 973) return false;
    return true;

		break;
	case 20:	//RVP926_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_VRP != 906) return false;
    return true;

		break;
	case 4:	//EMPTY_VP
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    return true;

		break;
	case 64:	//RVS1072_S_RURI_L_AVI0_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 908) return false;
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 63:	//RVS1073_S_RURI_L_WaitURI_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 909) return false;
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 65:	//RVS1070_S_RURI_L_AVI1_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 911) return false;
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 42:	//RVS939_
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_PVARP != 934) return false;
    return true;

		break;
	case 5:	//EMPTY_VS
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    return true;

		break;
	case 23:	//RVget928_
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    if( Marking.P->_PL_VRP != 906) return false;
    return true;

		break;
	case 6:	//EMPTY_Vget
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    return true;

		break;
	case 9:	//I1004_L_LRI
    if (Marking.P->_PL_SIG_AP >= 1) return false;
    if( Marking.P->_PL_LRI != 1003) return false;
    return true;

		break;
	case 46:	//I942_L_Asig
    if (Marking.P->_PL_SIG_AS >= 1) return false;
    if( Marking.P->_PL_PVARP != 936) return false;
    return true;

		break;
	case 66:	//I1069_S_IncrClk_L_WaitURI_L_q1
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_AVI != 909) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 52:	//I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_TAVIcmp != 991) return false;
    if( Marking.P->_PL_AVI != 911) return false;
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 22:	//I927_L_Vsig
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VS >= 1) return false;
    if( Marking.P->_PL_VRP != 925) return false;
    return true;

		break;
	case 7:	//INCOMING_SREC
    if (Marking.P->_PL_SIG_SREC >= 0) return false;
    return true;

		break;
	case 37:	//C956_L_Receive
    if (Marking.P->_PL_SIG_Vget >= 1) return false;
    if( Marking.P->_PL_SerialPort != 955) return false;
    return true;

		break;
	case 61:	//I1075_S_IncrClk_L_q1
    if( Marking.P->_PL_AVI != 895) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 68:	//I1067_S_IncrClk_L_Idle0_L_q1
    if( Marking.P->_PL_AVI != 907) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 67:	//I1068_S_IncrClk_L_AVI0_L_q1
    if( Marking.P->_PL_AVI != 908) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 62:	//I1074_S_IncrClk_L_q1
    if( Marking.P->_PL_AVI != 911) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 16:	//I1002_L_LRI
    if( Marking.P->_PL_LRI != 1001) return false;
    return true;

		break;
	case 15:	//I1111_RLRI
    if( Marking.P->_PL_LRI != 1110) return false;
    return true;

		break;
	case 13:	//I1113_L_ASensed
    if( Marking.P->_PL_LRI != 1112) return false;
    return true;

		break;
	case 11:	//I1115_L_LRI
    if( Marking.P->_PL_LRI != 1114) return false;
    return true;

		break;
	case 8:	//D888_LRI
    if( Marking.P->_PL_LRI != 886) return false;
    return true;

		break;
	case 17:	//I1000_init
    if( Marking.P->_PL_LRI != 999) return false;
    return true;

		break;
	case 43:	//I1097_L_Idle
    if( Marking.P->_PL_PVARP != 1096) return false;
    return true;

		break;
	case 41:	//I1099_L_Idle
    if( Marking.P->_PL_PVARP != 1098) return false;
    return true;

		break;
	case 35:	//C1063_S_Aget_L_Idle_L_Receive
    if( Marking.P->_PL_PVARP != 934) return false;
    if( Marking.P->_PL_SerialPort != 955) return false;
    return true;

		break;
	case 33:	//C1065_S_Aget_L_Receive
    if( Marking.P->_PL_PVARP != 935) return false;
    if( Marking.P->_PL_SerialPort != 955) return false;
    return true;

		break;
	case 47:	//D944_L_PVAB
    if( Marking.P->_PL_PVARP != 935) return false;
    return true;

		break;
	case 34:	//C1064_S_Aget_L_Receive
    if( Marking.P->_PL_PVARP != 937) return false;
    if( Marking.P->_PL_SerialPort != 955) return false;
    return true;

		break;
	case 45:	//D941_L_PVARP
    if( Marking.P->_PL_PVARP != 937) return false;
    return true;

		break;
	case 44:	//I988_init
    if( Marking.P->_PL_PVARP != 987) return false;
    return true;

		break;
	case 28:	//I1105_L_Off
    if( Marking.P->_PL_PaceLedAtrium != 1104) return false;
    return true;

		break;
	case 26:	//D969_L_On
    if( Marking.P->_PL_PaceLedAtrium != 963) return false;
    return true;

		break;
	case 25:	//I984_init
    if( Marking.P->_PL_PaceLedAtrium != 983) return false;
    return true;

		break;
	case 32:	//I1103_L_Off
    if( Marking.P->_PL_PaceLedVentricle != 1102) return false;
    return true;

		break;
	case 30:	//D974_L_On
    if( Marking.P->_PL_PaceLedVentricle != 971) return false;
    return true;

		break;
	case 29:	//I982_init
    if( Marking.P->_PL_PaceLedVentricle != 981) return false;
    return true;

		break;
	case 39:	//I1101_L_NoData
    if( Marking.P->_PL_SerialPort != 1100) return false;
    return true;

		break;
	case 36:	//I986_init
    if( Marking.P->_PL_SerialPort != 985) return false;
    return true;

		break;
	case 72:	//D931_q0
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    return true;

		break;
	case 73:	//I990_init
    if( Marking.P->_PL_TAVIcmp != 989) return false;
    return true;

		break;
	case 55:	//I1082_S_TAVI_L_q0
    if( Marking.P->_PL_TAVIcmp != 991) return false;
    if( Marking.P->_PL_AVI != 895) return false;
    return true;

		break;
	case 53:	//I1084_S_TAVI_L_q0
    if( Marking.P->_PL_TAVIcmp != 991) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 56:	//I1081_S_TAVI_L_q0_L_AVI0
    if( Marking.P->_PL_TAVIcmp != 991) return false;
    if( Marking.P->_PL_AVI != 908) return false;
    return true;

		break;
	case 54:	//I1083_S_TAVI_L_q0
    if( Marking.P->_PL_TAVIcmp != 991) return false;
    if( Marking.P->_PL_AVI != 909) return false;
    return true;

		break;
	case 70:	//D900_L_URI
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 71:	//I996_init
    if( Marking.P->_PL_URI != 995) return false;
    return true;

		break;
	case 69:	//I998_L_URI
    if( Marking.P->_PL_URI != 997) return false;
    return true;

		break;
	case 24:	//I1107_L_Idle
    if( Marking.P->_PL_VRP != 1106) return false;
    return true;

		break;
	case 21:	//I1109_L_Idle
    if( Marking.P->_PL_VRP != 1108) return false;
    return true;

		break;
	case 18:	//D923_L_VRP
    if( Marking.P->_PL_VRP != 924) return false;
    return true;

		break;
	case 19:	//I994_init
    if( Marking.P->_PL_VRP != 993) return false;
    return true;

		break;
	default:	//RAP964_,
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_PaceLedAtrium != 961) return false;
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
		case 3: {  //EMPTY_SREC
			Marking.P->_PL_SIG_SREC -= 1;
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
		case 7: {  //INCOMING_SREC
			Marking.P->_PL_SIG_SREC += 1;
       break;
     } 
		case 8: {  //D888_LRI
			Marking.P->_PL_LRI -= 886;
			Marking.P->_PL_LRI += 1003;
       break;
     } 
		case 9: {  //I1004_L_LRI
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_LRI -= 1003;
			Marking.P->_PL_LRI += 886;
       break;
     } 
		case 10: {  //RAS891_
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_LRI -= 886;
			Marking.P->_PL_LRI += 1114;
       break;
     } 
		case 11: {  //I1115_L_LRI
			Marking.P->_PL_LRI -= 1114;
			Marking.P->_PL_LRI += 887;
       break;
     } 
		case 12: {  //RRLRI892_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 887;
			Marking.P->_PL_LRI += 1112;
       break;
     } 
		case 13: {  //I1113_L_ASensed
			Marking.P->_PL_LRI -= 1112;
			Marking.P->_PL_LRI += 886;
       break;
     } 
		case 14: {  //RRLRI893_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 886;
			Marking.P->_PL_LRI += 1110;
       break;
     } 
		case 15: {  //I1111_RLRI
			Marking.P->_PL_LRI -= 1110;
			Marking.P->_PL_LRI += 1001;
       break;
     } 
		case 16: {  //I1002_L_LRI
			Marking.P->_PL_LRI -= 1001;
			Marking.P->_PL_LRI += 886;
       break;
     } 
		case 17: {  //I1000_init
			Marking.P->_PL_LRI -= 999;
			Marking.P->_PL_LRI += 886;
       break;
     } 
		case 18: {  //D923_L_VRP
			Marking.P->_PL_VRP -= 924;
			Marking.P->_PL_VRP += 906;
       break;
     } 
		case 19: {  //I994_init
			Marking.P->_PL_VRP -= 993;
			Marking.P->_PL_VRP += 906;
       break;
     } 
		case 20: {  //RVP926_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_VRP -= 906;
			Marking.P->_PL_VRP += 1108;
       break;
     } 
		case 21: {  //I1109_L_Idle
			Marking.P->_PL_VRP -= 1108;
			Marking.P->_PL_VRP += 924;
       break;
     } 
		case 22: {  //I927_L_Vsig
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_VRP -= 925;
			Marking.P->_PL_VRP += 906;
       break;
     } 
		case 23: {  //RVget928_
			Marking.P->_PL_SIG_Vget -= 1;
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_VRP -= 906;
			Marking.P->_PL_VRP += 1106;
       break;
     } 
		case 24: {  //I1107_L_Idle
			Marking.P->_PL_VRP -= 1106;
			Marking.P->_PL_VRP += 925;
       break;
     } 
		case 25: {  //I984_init
			Marking.P->_PL_PaceLedAtrium -= 983;
			Marking.P->_PL_PaceLedAtrium += 961;
       break;
     } 
		case 26: {  //D969_L_On
			Marking.P->_PL_PaceLedAtrium -= 963;
			Marking.P->_PL_PaceLedAtrium += 961;
       break;
     } 
		case 27: {  //RAP964_
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_PaceLedAtrium -= 961;
			Marking.P->_PL_PaceLedAtrium += 1104;
       break;
     } 
		case 28: {  //I1105_L_Off
			Marking.P->_PL_PaceLedAtrium -= 1104;
			Marking.P->_PL_PaceLedAtrium += 963;
       break;
     } 
		case 29: {  //I982_init
			Marking.P->_PL_PaceLedVentricle -= 981;
			Marking.P->_PL_PaceLedVentricle += 973;
       break;
     } 
		case 30: {  //D974_L_On
			Marking.P->_PL_PaceLedVentricle -= 971;
			Marking.P->_PL_PaceLedVentricle += 973;
       break;
     } 
		case 31: {  //RVP975_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_PaceLedVentricle -= 973;
			Marking.P->_PL_PaceLedVentricle += 1102;
       break;
     } 
		case 32: {  //I1103_L_Off
			Marking.P->_PL_PaceLedVentricle -= 1102;
			Marking.P->_PL_PaceLedVentricle += 971;
       break;
     } 
		case 33: {  //C1065_S_Aget_L_Receive
			Marking.P->_PL_PVARP -= 935;
			Marking.P->_PL_PVARP += 935;
			Marking.P->_PL_SerialPort -= 955;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 34: {  //C1064_S_Aget_L_Receive
			Marking.P->_PL_PVARP -= 937;
			Marking.P->_PL_PVARP += 937;
			Marking.P->_PL_SerialPort -= 955;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 35: {  //C1063_S_Aget_L_Idle_L_Receive
			Marking.P->_PL_PVARP -= 934;
			Marking.P->_PL_PVARP += 936;
			Marking.P->_PL_SerialPort -= 955;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 36: {  //I986_init
			Marking.P->_PL_SerialPort -= 985;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 37: {  //C956_L_Receive
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_SerialPort -= 955;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 38: {  //RSREC959_
			Marking.P->_PL_SIG_SREC -= 1;
			Marking.P->_PL_SIG_SREC += 1;
			Marking.P->_PL_SerialPort -= 949;
			Marking.P->_PL_SerialPort += 1100;
       break;
     } 
		case 39: {  //I1101_L_NoData
			Marking.P->_PL_SerialPort -= 1100;
			Marking.P->_PL_SerialPort += 955;
       break;
     } 
		case 40: {  //RVP938_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_PVARP -= 934;
			Marking.P->_PL_PVARP += 1098;
       break;
     } 
		case 41: {  //I1099_L_Idle
			Marking.P->_PL_PVARP -= 1098;
			Marking.P->_PL_PVARP += 935;
       break;
     } 
		case 42: {  //RVS939_
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_PVARP -= 934;
			Marking.P->_PL_PVARP += 1096;
       break;
     } 
		case 43: {  //I1097_L_Idle
			Marking.P->_PL_PVARP -= 1096;
			Marking.P->_PL_PVARP += 935;
       break;
     } 
		case 44: {  //I988_init
			Marking.P->_PL_PVARP -= 987;
			Marking.P->_PL_PVARP += 934;
       break;
     } 
		case 45: {  //D941_L_PVARP
			Marking.P->_PL_PVARP -= 937;
			Marking.P->_PL_PVARP += 934;
       break;
     } 
		case 46: {  //I942_L_Asig
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_PVARP -= 936;
			Marking.P->_PL_PVARP += 934;
       break;
     } 
		case 47: {  //D944_L_PVAB
			Marking.P->_PL_PVARP -= 935;
			Marking.P->_PL_PVARP += 937;
       break;
     } 
		case 48: {  //RAP1089_S_RTAVI_L_Idle0
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 908;
       break;
     } 
		case 49: {  //RAS1088_S_RTAVI_L_Idle0
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 908;
       break;
     } 
		case 50: {  //RAP1087_S_RTAVI_L_Idle1
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 911;
       break;
     } 
		case 51: {  //RAS1086_S_RTAVI_L_Idle1
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 911;
       break;
     } 
		case 52: {  //I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_TAVIcmp -= 991;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 911;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 997;
       break;
     } 
		case 53: {  //I1084_S_TAVI_L_q0
			Marking.P->_PL_TAVIcmp -= 991;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 907;
       break;
     } 
		case 54: {  //I1083_S_TAVI_L_q0
			Marking.P->_PL_TAVIcmp -= 991;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 909;
			Marking.P->_PL_AVI += 909;
       break;
     } 
		case 55: {  //I1082_S_TAVI_L_q0
			Marking.P->_PL_TAVIcmp -= 991;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 895;
       break;
     } 
		case 56: {  //I1081_S_TAVI_L_q0_L_AVI0
			Marking.P->_PL_TAVIcmp -= 991;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 908;
			Marking.P->_PL_AVI += 909;
       break;
     } 
		case 57: {  //RAP1080_S_RTAVI_L_q1_L_Idle0
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 930;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 908;
       break;
     } 
		case 58: {  //RAS1079_S_RTAVI_L_q1_L_Idle0
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 930;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 908;
       break;
     } 
		case 59: {  //RAP1078_S_RTAVI_L_q1_L_Idle1
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 930;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 911;
       break;
     } 
		case 60: {  //RAS1077_S_RTAVI_L_q1_L_Idle1
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 930;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 911;
       break;
     } 
		case 61: {  //I1075_S_IncrClk_L_q1
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 895;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 62: {  //I1074_S_IncrClk_L_q1
			Marking.P->_PL_AVI -= 911;
			Marking.P->_PL_AVI += 911;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 63: {  //RVS1073_S_RURI_L_WaitURI_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 909;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 997;
       break;
     } 
		case 64: {  //RVS1072_S_RURI_L_AVI0_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 908;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 997;
       break;
     } 
		case 65: {  //RVS1070_S_RURI_L_AVI1_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 911;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 997;
       break;
     } 
		case 66: {  //I1069_S_IncrClk_L_WaitURI_L_q1
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_AVI -= 909;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 67: {  //I1068_S_IncrClk_L_AVI0_L_q1
			Marking.P->_PL_AVI -= 908;
			Marking.P->_PL_AVI += 911;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 68: {  //I1067_S_IncrClk_L_Idle0_L_q1
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 895;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 69: {  //I998_L_URI
			Marking.P->_PL_URI -= 997;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 70: {  //D900_L_URI
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 898;
       break;
     } 
		case 71: {  //I996_init
			Marking.P->_PL_URI -= 995;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 72: {  //D931_q0
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 991;
       break;
     } 
		case 73: {  //I990_init
			Marking.P->_PL_TAVIcmp -= 989;
			Marking.P->_PL_TAVIcmp += 930;
       break;
     } 
	}
}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(TR_PL_ID t )const {
switch (t){
	case 8:	//D888_LRI
	{
		ParamDistr[0]= ( double )  (PM_TLRI  - PM_TAVI ) ;
	}

		break;
	case 45:	//D941_L_PVARP
	{
		ParamDistr[0]= ( double )  (PM_TPVARP  - PM_TPVAB ) ;
	}

		break;
	case 26:	//D969_L_On
	case 30:	//D974_L_On
	{
		ParamDistr[0]= ( double ) 2 ;
	}

		break;
	case 72:	//D931_q0
	{
		ParamDistr[0]= ( double ) PM_TAVI ;
	}

		break;
	case 47:	//D944_L_PVAB
	{
		ParamDistr[0]= ( double ) PM_TPVAB ;
	}

		break;
	case 70:	//D900_L_URI
	{
		ParamDistr[0]= ( double ) PM_TURI ;
	}

		break;
	case 18:	//D923_L_VRP
	{
		ParamDistr[0]= ( double ) PM_TVRP ;
	}

		break;
	default:	//EMPTY_AP,EMPTY_AS,EMPTY_RLRI,EMPTY_SREC,EMPTY_VP,EMPTY_VS,EMPTY_Vget,INCOMING_SREC,I1004_L_LRI,RAS891_,I1115_L_LRI,RRLRI892_,I1113_L_ASensed,RRLRI893_,I1111_RLRI,I1002_L_LRI,I1000_init,I994_init,RVP926_,I1109_L_Idle,I927_L_Vsig,RVget928_,I1107_L_Idle,I984_init,RAP964_,I1105_L_Off,I982_init,RVP975_,I1103_L_Off,C1065_S_Aget_L_Receive,C1064_S_Aget_L_Receive,C1063_S_Aget_L_Idle_L_Receive,I986_init,C956_L_Receive,RSREC959_,I1101_L_NoData,RVP938_,I1099_L_Idle,RVS939_,I1097_L_Idle,I988_init,I942_L_Asig,RAP1089_S_RTAVI_L_Idle0,RAS1088_S_RTAVI_L_Idle0,RAP1087_S_RTAVI_L_Idle1,RAS1086_S_RTAVI_L_Idle1,I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI,I1084_S_TAVI_L_q0,I1083_S_TAVI_L_q0,I1082_S_TAVI_L_q0,I1081_S_TAVI_L_q0_L_AVI0,RAP1080_S_RTAVI_L_q1_L_Idle0,RAS1079_S_RTAVI_L_q1_L_Idle0,RAP1078_S_RTAVI_L_q1_L_Idle1,RAS1077_S_RTAVI_L_q1_L_Idle1,I1075_S_IncrClk_L_q1,I1074_S_IncrClk_L_q1,RVS1073_S_RURI_L_WaitURI_RURI,RVS1072_S_RURI_L_AVI0_RURI,RVS1070_S_RURI_L_AVI1_RURI,I1069_S_IncrClk_L_WaitURI_L_q1,I1068_S_IncrClk_L_AVI0_L_q1,I1067_S_IncrClk_L_Idle0_L_q1,I998_L_URI,I996_init,I990_init,
	{
		ParamDistr[0]= ( double ) 0 ;
	}

}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t)const {
switch (t){
	case 30:	//D974_L_On
		return (double)0.91 ;

		break;
	case 26:	//D969_L_On
		return (double)0.92 ;

		break;
	case 72:	//D931_q0
		return (double)0.94 ;

		break;
	case 70:	//D900_L_URI
		return (double)0.95 ;

		break;
	case 8:	//D888_LRI
		return (double)0.96 ;

		break;
	case 45:	//D941_L_PVARP
	case 47:	//D944_L_PVAB
		return (double)0.97 ;

		break;
	case 18:	//D923_L_VRP
		return (double)0.98 ;

		break;
	case 29:	//I982_init
	case 32:	//I1103_L_Off
		return (double)1.91 ;

		break;
	case 25:	//I984_init
	case 28:	//I1105_L_Off
		return (double)1.92 ;

		break;
	case 33:	//C1065_S_Aget_L_Receive
	case 34:	//C1064_S_Aget_L_Receive
	case 35:	//C1063_S_Aget_L_Idle_L_Receive
	case 36:	//I986_init
	case 37:	//C956_L_Receive
	case 39:	//I1101_L_NoData
		return (double)1.93 ;

		break;
	case 52:	//I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI
	case 53:	//I1084_S_TAVI_L_q0
	case 54:	//I1083_S_TAVI_L_q0
	case 55:	//I1082_S_TAVI_L_q0
	case 56:	//I1081_S_TAVI_L_q0_L_AVI0
	case 73:	//I990_init
		return (double)1.94 ;

		break;
	case 61:	//I1075_S_IncrClk_L_q1
	case 62:	//I1074_S_IncrClk_L_q1
	case 66:	//I1069_S_IncrClk_L_WaitURI_L_q1
	case 67:	//I1068_S_IncrClk_L_AVI0_L_q1
	case 68:	//I1067_S_IncrClk_L_Idle0_L_q1
	case 69:	//I998_L_URI
	case 71:	//I996_init
		return (double)1.95 ;

		break;
	case 9:	//I1004_L_LRI
	case 11:	//I1115_L_LRI
	case 13:	//I1113_L_ASensed
	case 15:	//I1111_RLRI
	case 16:	//I1002_L_LRI
	case 17:	//I1000_init
		return (double)1.96 ;

		break;
	case 41:	//I1099_L_Idle
	case 43:	//I1097_L_Idle
	case 44:	//I988_init
	case 46:	//I942_L_Asig
		return (double)1.97 ;

		break;
	case 19:	//I994_init
	case 21:	//I1109_L_Idle
	case 22:	//I927_L_Vsig
	case 24:	//I1107_L_Idle
		return (double)1.98 ;

		break;
	case 0:	//EMPTY_AP
	case 1:	//EMPTY_AS
	case 2:	//EMPTY_RLRI
	case 3:	//EMPTY_SREC
	case 4:	//EMPTY_VP
	case 5:	//EMPTY_VS
	case 6:	//EMPTY_Vget
		return (double)3 ;

		break;
	case 7:	//INCOMING_SREC
		return (double)5 ;

		break;
	default:	//RAS891_,RRLRI892_,RRLRI893_,RVP926_,RVget928_,RAP964_,RVP975_,RSREC959_,RVP938_,RVS939_,RAP1089_S_RTAVI_L_Idle0,RAS1088_S_RTAVI_L_Idle0,RAP1087_S_RTAVI_L_Idle1,RAS1086_S_RTAVI_L_Idle1,RAP1080_S_RTAVI_L_q1_L_Idle0,RAS1079_S_RTAVI_L_q1_L_Idle0,RAP1078_S_RTAVI_L_q1_L_Idle1,RAS1077_S_RTAVI_L_q1_L_Idle1,RVS1073_S_RURI_L_WaitURI_RURI,RVS1072_S_RURI_L_AVI0_RURI,RVS1070_S_RURI_L_AVI1_RURI,
		return (double)3.99 ;

}
}

REAL_TYPE SPN::GetWeight(TR_PL_ID t)const{
		return (double)1 ;

}

void SPN::reset() {
	Marking.resetToInitMarking();
}

