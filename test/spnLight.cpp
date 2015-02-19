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
#define PL_VRP_LP 12
#define PL_LRI_LP 13
#define TR_EMPTY_AP_RT 0
#define TR_EMPTY_AS_RT 1
#define TR_EMPTY_RLRI_RT 2
#define TR_EMPTY_SREC_RT 3
#define TR_EMPTY_VP_RT 4
#define TR_EMPTY_VS_RT 5
#define TR_EMPTY_Vget_RT 6
#define TR_D888_LRI_RT 7
#define TR_I978_L_LRI_RT 8
#define TR_RAS891__RT 9
#define TR_I1067_L_LRI_RT 10
#define TR_RRLRI892__RT 11
#define TR_I1065_L_ASensed_RT 12
#define TR_RRLRI893__RT 13
#define TR_I1063_RLRI_RT 14
#define TR_I976_L_LRI_RT 15
#define TR_I974_init_RT 16
#define TR_D923_L_VRP_RT 17
#define TR_I968_init_RT 18
#define TR_RVP926__RT 19
#define TR_I1061_L_Idle_RT 20
#define TR_I927_L_Vsig_RT 21
#define TR_RVget928__RT 22
#define TR_I1059_L_Idle_RT 23
#define TR_I954_L_DataAvailable_RT 24
#define TR_I960_init_RT 25
#define TR_C956_L_Receive_RT 26
#define TR_RSREC958__RT 27
#define TR_I1057_L_NoData_RT 28
#define TR_RVP938__RT 29
#define TR_I1055_L_Idle_RT 30
#define TR_RVS939__RT 31
#define TR_I1053_L_Idle_RT 32
#define TR_I962_init_RT 33
#define TR_D941_L_PVARP_RT 34
#define TR_I942_L_Asig_RT 35
#define TR_D944_L_PVAB_RT 36
#define TR_C1021_S_Aget_L_Idle_L_Receive_RT 37
#define TR_C1022_S_Aget_L_Receive_RT 38
#define TR_C1023_S_Aget_L_Receive_RT 39
#define TR_I972_L_URI_RT 40
#define TR_D900_L_URI_RT 41
#define TR_I970_init_RT 42
#define TR_I1025_S_IncrClk_L_Idle0_L_q1_RT 43
#define TR_I1026_S_IncrClk_L_AVI0_L_q1_RT 44
#define TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT 45
#define TR_RVS1028_S_RURI_L_AVI1_RURI_RT 46
#define TR_RVS1030_S_RURI_L_AVI0_RURI_RT 47
#define TR_RVS1031_S_RURI_L_WaitURI_RURI_RT 48
#define TR_I1032_S_IncrClk_L_q1_RT 49
#define TR_I1033_S_IncrClk_L_q1_RT 50
#define TR_D931_q0_RT 51
#define TR_I964_init_RT 52
#define TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT 53
#define TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT 54
#define TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT 55
#define TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT 56
#define TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT 57
#define TR_I1040_S_TAVI_L_q0_L_AVI0_RT 58
#define TR_I1041_S_TAVI_L_q0_RT 59
#define TR_I1042_S_TAVI_L_q0_RT 60
#define TR_I1043_S_TAVI_L_q0_RT 61
#define TR_RAS1044_S_RTAVI_L_Idle1_RT 62
#define TR_RAP1045_S_RTAVI_L_Idle1_RT 63
#define TR_RAS1046_S_RTAVI_L_Idle0_RT 64
#define TR_RAP1047_S_RTAVI_L_Idle0_RT 65

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
	const int _nb_Place_VRP=12;
	const int _nb_Place_LRI=13;
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
	P->_PL_TAVIcmp =963;
	P->_PL_AVI =907;
	P->_PL_URI =969;
	P->_PL_PVARP =961;
	P->_PL_SerialPort =959;
	P->_PL_VRP =967;
	P->_PL_LRI =973;
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
print_magic(P->_PL_VRP);
::print("	");
print_magic(P->_PL_LRI);
::print("	");
}
static const int EMPTY_array[1]={-1};
static const int PE_PossiblyEnabled_0[2]= {TR_I978_L_LRI_RT, -1 }; /* EMPTY_AP*/
static const int PE_PossiblyEnabled_1[2]= {TR_I942_L_Asig_RT, -1 }; /* EMPTY_AS*/
static const int PE_PossiblyEnabled_2[4]= {TR_I927_L_Vsig_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* EMPTY_RLRI*/
static const int PE_PossiblyEnabled_4[3]= {TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* EMPTY_VP*/
static const int PE_PossiblyEnabled_5[2]= {TR_I927_L_Vsig_RT, -1 }; /* EMPTY_VS*/
static const int PE_PossiblyEnabled_6[2]= {TR_C956_L_Receive_RT, -1 }; /* EMPTY_Vget*/
static const int PE_PossiblyEnabled_7[2]= {TR_I978_L_LRI_RT, -1 }; /* D888_LRI*/
static const int PE_PossiblyEnabled_8[9]= {TR_EMPTY_AP_RT, TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI893__RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* I978_L_LRI*/
static const int PE_PossiblyEnabled_9[8]= {TR_EMPTY_AS_RT, TR_I1067_L_LRI_RT, TR_I942_L_Asig_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* RAS891_*/
static const int PE_PossiblyEnabled_10[2]= {TR_RRLRI892__RT, -1 }; /* I1067_L_LRI*/
static const int PE_PossiblyEnabled_11[7]= {TR_EMPTY_RLRI_RT, TR_I1065_L_ASensed_RT, TR_RRLRI893__RT, TR_I927_L_Vsig_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* RRLRI892_*/
static const int PE_PossiblyEnabled_12[4]= {TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI893__RT, -1 }; /* I1065_L_ASensed*/
static const int PE_PossiblyEnabled_13[7]= {TR_EMPTY_RLRI_RT, TR_RRLRI892__RT, TR_I1063_RLRI_RT, TR_I927_L_Vsig_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* RRLRI893_*/
static const int PE_PossiblyEnabled_14[2]= {TR_I976_L_LRI_RT, -1 }; /* I1063_RLRI*/
static const int PE_PossiblyEnabled_15[4]= {TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI893__RT, -1 }; /* I976_L_LRI*/
static const int PE_PossiblyEnabled_16[4]= {TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI893__RT, -1 }; /* I974_init*/
static const int PE_PossiblyEnabled_17[3]= {TR_RVP926__RT, TR_RVget928__RT, -1 }; /* D923_L_VRP*/
static const int PE_PossiblyEnabled_18[3]= {TR_RVP926__RT, TR_RVget928__RT, -1 }; /* I968_init*/
static const int PE_PossiblyEnabled_19[6]= {TR_EMPTY_VP_RT, TR_I1061_L_Idle_RT, TR_RVP938__RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* RVP926_*/
static const int PE_PossiblyEnabled_20[2]= {TR_D923_L_VRP_RT, -1 }; /* I1061_L_Idle*/
static const int PE_PossiblyEnabled_21[11]= {TR_EMPTY_RLRI_RT, TR_EMPTY_VS_RT, TR_RRLRI892__RT, TR_RRLRI893__RT, TR_RVP926__RT, TR_RVget928__RT, TR_RVS939__RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, -1 }; /* I927_L_Vsig*/
static const int PE_PossiblyEnabled_22[4]= {TR_EMPTY_Vget_RT, TR_I1059_L_Idle_RT, TR_C956_L_Receive_RT, -1 }; /* RVget928_*/
static const int PE_PossiblyEnabled_23[2]= {TR_I927_L_Vsig_RT, -1 }; /* I1059_L_Idle*/
static const int PE_PossiblyEnabled_24[5]= {TR_C956_L_Receive_RT, TR_C1021_S_Aget_L_Idle_L_Receive_RT, TR_C1022_S_Aget_L_Receive_RT, TR_C1023_S_Aget_L_Receive_RT, -1 }; /* I954_L_DataAvailable*/
static const int PE_PossiblyEnabled_25[2]= {TR_RSREC958__RT, -1 }; /* I960_init*/
static const int PE_PossiblyEnabled_26[4]= {TR_EMPTY_Vget_RT, TR_RVget928__RT, TR_RSREC958__RT, -1 }; /* C956_L_Receive*/
static const int PE_PossiblyEnabled_27[3]= {TR_EMPTY_SREC_RT, TR_I1057_L_NoData_RT, -1 }; /* RSREC958_*/
static const int PE_PossiblyEnabled_28[2]= {TR_I954_L_DataAvailable_RT, -1 }; /* I1057_L_NoData*/
static const int PE_PossiblyEnabled_29[6]= {TR_EMPTY_VP_RT, TR_RVP926__RT, TR_I1055_L_Idle_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* RVP938_*/
static const int PE_PossiblyEnabled_30[3]= {TR_D944_L_PVAB_RT, TR_C1023_S_Aget_L_Receive_RT, -1 }; /* I1055_L_Idle*/
static const int PE_PossiblyEnabled_31[7]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_I1053_L_Idle_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, -1 }; /* RVS939_*/
static const int PE_PossiblyEnabled_32[3]= {TR_D944_L_PVAB_RT, TR_C1023_S_Aget_L_Receive_RT, -1 }; /* I1053_L_Idle*/
static const int PE_PossiblyEnabled_33[4]= {TR_RVP938__RT, TR_RVS939__RT, TR_C1021_S_Aget_L_Idle_L_Receive_RT, -1 }; /* I962_init*/
static const int PE_PossiblyEnabled_34[4]= {TR_RVP938__RT, TR_RVS939__RT, TR_C1021_S_Aget_L_Idle_L_Receive_RT, -1 }; /* D941_L_PVARP*/
static const int PE_PossiblyEnabled_35[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_RVP938__RT, TR_RVS939__RT, TR_C1021_S_Aget_L_Idle_L_Receive_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* I942_L_Asig*/
static const int PE_PossiblyEnabled_36[3]= {TR_D941_L_PVARP_RT, TR_C1022_S_Aget_L_Receive_RT, -1 }; /* D944_L_PVAB*/
static const int PE_PossiblyEnabled_37[3]= {TR_RSREC958__RT, TR_I942_L_Asig_RT, -1 }; /* C1021_S_Aget_L_Idle_L_Receive*/
static const int PE_PossiblyEnabled_38[3]= {TR_RSREC958__RT, TR_D941_L_PVARP_RT, -1 }; /* C1022_S_Aget_L_Receive*/
static const int PE_PossiblyEnabled_39[3]= {TR_RSREC958__RT, TR_D944_L_PVAB_RT, -1 }; /* C1023_S_Aget_L_Receive*/
static const int PE_PossiblyEnabled_40[6]= {TR_D900_L_URI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* I972_L_URI*/
static const int PE_PossiblyEnabled_41[6]= {TR_I1025_S_IncrClk_L_Idle0_L_q1_RT, TR_I1026_S_IncrClk_L_AVI0_L_q1_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1032_S_IncrClk_L_q1_RT, TR_I1033_S_IncrClk_L_q1_RT, -1 }; /* D900_L_URI*/
static const int PE_PossiblyEnabled_42[6]= {TR_D900_L_URI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* I970_init*/
static const int PE_PossiblyEnabled_43[7]= {TR_D900_L_URI_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_I1041_S_TAVI_L_q0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, -1 }; /* I1025_S_IncrClk_L_Idle0_L_q1*/
static const int PE_PossiblyEnabled_44[4]= {TR_D900_L_URI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* I1026_S_IncrClk_L_AVI0_L_q1*/
static const int PE_PossiblyEnabled_45[14]= {TR_EMPTY_RLRI_RT, TR_EMPTY_VP_RT, TR_RRLRI892__RT, TR_RRLRI893__RT, TR_RVP926__RT, TR_RVP938__RT, TR_D900_L_URI_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1043_S_TAVI_L_q0_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* I1027_S_IncrClk_L_WaitURI_L_q1*/
static const int PE_PossiblyEnabled_46[12]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_I972_L_URI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_I1043_S_TAVI_L_q0_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RVS1028_S_RURI_L_AVI1_RURI*/
static const int PE_PossiblyEnabled_47[12]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_I972_L_URI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_I1043_S_TAVI_L_q0_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RVS1030_S_RURI_L_AVI0_RURI*/
static const int PE_PossiblyEnabled_48[12]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_I972_L_URI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_I1043_S_TAVI_L_q0_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RVS1031_S_RURI_L_WaitURI_RURI*/
static const int PE_PossiblyEnabled_49[4]= {TR_D900_L_URI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* I1032_S_IncrClk_L_q1*/
static const int PE_PossiblyEnabled_50[7]= {TR_D900_L_URI_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_I1041_S_TAVI_L_q0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, -1 }; /* I1033_S_IncrClk_L_q1*/
static const int PE_PossiblyEnabled_51[6]= {TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1040_S_TAVI_L_q0_L_AVI0_RT, TR_I1041_S_TAVI_L_q0_RT, TR_I1042_S_TAVI_L_q0_RT, TR_I1043_S_TAVI_L_q0_RT, -1 }; /* D931_q0*/
static const int PE_PossiblyEnabled_52[5]= {TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, -1 }; /* I964_init*/
static const int PE_PossiblyEnabled_53[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_I1032_S_IncrClk_L_q1_RT, TR_D931_q0_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* RAS1035_S_RTAVI_L_q1_L_Idle1*/
static const int PE_PossiblyEnabled_54[9]= {TR_EMPTY_AP_RT, TR_I978_L_LRI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_I1032_S_IncrClk_L_q1_RT, TR_D931_q0_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RAP1036_S_RTAVI_L_q1_L_Idle1*/
static const int PE_PossiblyEnabled_55[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_I1026_S_IncrClk_L_AVI0_L_q1_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_D931_q0_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* RAS1037_S_RTAVI_L_q1_L_Idle0*/
static const int PE_PossiblyEnabled_56[9]= {TR_EMPTY_AP_RT, TR_I978_L_LRI_RT, TR_I1026_S_IncrClk_L_AVI0_L_q1_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_D931_q0_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RAP1038_S_RTAVI_L_q1_L_Idle0*/
static const int PE_PossiblyEnabled_57[11]= {TR_EMPTY_RLRI_RT, TR_EMPTY_VP_RT, TR_RRLRI892__RT, TR_RRLRI893__RT, TR_RVP926__RT, TR_RVP938__RT, TR_I972_L_URI_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, -1 }; /* I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI*/
static const int PE_PossiblyEnabled_58[3]= {TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, -1 }; /* I1040_S_TAVI_L_q0_L_AVI0*/
static const int PE_PossiblyEnabled_59[4]= {TR_I1033_S_IncrClk_L_q1_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, -1 }; /* I1041_S_TAVI_L_q0*/
static const int PE_PossiblyEnabled_60[3]= {TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, -1 }; /* I1042_S_TAVI_L_q0*/
static const int PE_PossiblyEnabled_61[4]= {TR_I1025_S_IncrClk_L_Idle0_L_q1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, -1 }; /* I1043_S_TAVI_L_q0*/
static const int PE_PossiblyEnabled_62[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_I1032_S_IncrClk_L_q1_RT, TR_D931_q0_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* RAS1044_S_RTAVI_L_Idle1*/
static const int PE_PossiblyEnabled_63[9]= {TR_EMPTY_AP_RT, TR_I978_L_LRI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_I1032_S_IncrClk_L_q1_RT, TR_D931_q0_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RAP1045_S_RTAVI_L_Idle1*/
static const int PE_PossiblyEnabled_64[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_I1026_S_IncrClk_L_AVI0_L_q1_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_D931_q0_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, -1 }; /* RAS1046_S_RTAVI_L_Idle0*/
static const int PE_PossiblyEnabled_65[9]= {TR_EMPTY_AP_RT, TR_I978_L_LRI_RT, TR_I1026_S_IncrClk_L_AVI0_L_q1_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_D931_q0_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, -1 }; /* RAP1047_S_RTAVI_L_Idle0*/
const int* SPN::PossiblyEnabled[] = {PE_PossiblyEnabled_0, PE_PossiblyEnabled_1, PE_PossiblyEnabled_2, EMPTY_array, PE_PossiblyEnabled_4, PE_PossiblyEnabled_5, PE_PossiblyEnabled_6, PE_PossiblyEnabled_7, PE_PossiblyEnabled_8, PE_PossiblyEnabled_9, PE_PossiblyEnabled_10, PE_PossiblyEnabled_11, PE_PossiblyEnabled_12, PE_PossiblyEnabled_13, PE_PossiblyEnabled_14, PE_PossiblyEnabled_15, PE_PossiblyEnabled_16, PE_PossiblyEnabled_17, PE_PossiblyEnabled_18, PE_PossiblyEnabled_19, PE_PossiblyEnabled_20, PE_PossiblyEnabled_21, PE_PossiblyEnabled_22, PE_PossiblyEnabled_23, PE_PossiblyEnabled_24, PE_PossiblyEnabled_25, PE_PossiblyEnabled_26, PE_PossiblyEnabled_27, PE_PossiblyEnabled_28, PE_PossiblyEnabled_29, PE_PossiblyEnabled_30, PE_PossiblyEnabled_31, PE_PossiblyEnabled_32, PE_PossiblyEnabled_33, PE_PossiblyEnabled_34, PE_PossiblyEnabled_35, PE_PossiblyEnabled_36, PE_PossiblyEnabled_37, PE_PossiblyEnabled_38, PE_PossiblyEnabled_39, PE_PossiblyEnabled_40, PE_PossiblyEnabled_41, PE_PossiblyEnabled_42, PE_PossiblyEnabled_43, PE_PossiblyEnabled_44, PE_PossiblyEnabled_45, PE_PossiblyEnabled_46, PE_PossiblyEnabled_47, PE_PossiblyEnabled_48, PE_PossiblyEnabled_49, PE_PossiblyEnabled_50, PE_PossiblyEnabled_51, PE_PossiblyEnabled_52, PE_PossiblyEnabled_53, PE_PossiblyEnabled_54, PE_PossiblyEnabled_55, PE_PossiblyEnabled_56, PE_PossiblyEnabled_57, PE_PossiblyEnabled_58, PE_PossiblyEnabled_59, PE_PossiblyEnabled_60, PE_PossiblyEnabled_61, PE_PossiblyEnabled_62, PE_PossiblyEnabled_63, PE_PossiblyEnabled_64, PE_PossiblyEnabled_65};

static const int PE_PossiblyDisabled_0[5]= {TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* EMPTY_AP*/
static const int PE_PossiblyDisabled_1[6]= {TR_RAS891__RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* EMPTY_AS*/
static const int PE_PossiblyDisabled_2[3]= {TR_RRLRI892__RT, TR_RRLRI893__RT, -1 }; /* EMPTY_RLRI*/
static const int PE_PossiblyDisabled_3[2]= {TR_RSREC958__RT, -1 }; /* EMPTY_SREC*/
static const int PE_PossiblyDisabled_4[3]= {TR_RVP926__RT, TR_RVP938__RT, -1 }; /* EMPTY_VP*/
static const int PE_PossiblyDisabled_5[5]= {TR_RVS939__RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, -1 }; /* EMPTY_VS*/
static const int PE_PossiblyDisabled_6[2]= {TR_RVget928__RT, -1 }; /* EMPTY_Vget*/
static const int PE_PossiblyDisabled_7[3]= {TR_RAS891__RT, TR_RRLRI893__RT, -1 }; /* D888_LRI*/
static const int PE_PossiblyDisabled_9[9]= {TR_EMPTY_AS_RT, TR_D888_LRI_RT, TR_RRLRI893__RT, TR_I942_L_Asig_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* RAS891_*/
static const int PE_PossiblyDisabled_11[6]= {TR_EMPTY_RLRI_RT, TR_RRLRI893__RT, TR_I927_L_Vsig_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* RRLRI892_*/
static const int PE_PossiblyDisabled_13[8]= {TR_EMPTY_RLRI_RT, TR_D888_LRI_RT, TR_RAS891__RT, TR_RRLRI892__RT, TR_I927_L_Vsig_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* RRLRI893_*/
static const int PE_PossiblyDisabled_19[6]= {TR_EMPTY_VP_RT, TR_RVget928__RT, TR_RVP938__RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* RVP926_*/
static const int PE_PossiblyDisabled_21[3]= {TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* I927_L_Vsig*/
static const int PE_PossiblyDisabled_22[4]= {TR_EMPTY_Vget_RT, TR_RVP926__RT, TR_C956_L_Receive_RT, -1 }; /* RVget928_*/
static const int PE_PossiblyDisabled_26[4]= {TR_C1021_S_Aget_L_Idle_L_Receive_RT, TR_C1022_S_Aget_L_Receive_RT, TR_C1023_S_Aget_L_Receive_RT, -1 }; /* C956_L_Receive*/
static const int PE_PossiblyDisabled_27[2]= {TR_EMPTY_SREC_RT, -1 }; /* RSREC958_*/
static const int PE_PossiblyDisabled_29[7]= {TR_EMPTY_VP_RT, TR_RVP926__RT, TR_RVS939__RT, TR_C1021_S_Aget_L_Idle_L_Receive_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* RVP938_*/
static const int PE_PossiblyDisabled_31[8]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVP938__RT, TR_C1021_S_Aget_L_Idle_L_Receive_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, -1 }; /* RVS939_*/
static const int PE_PossiblyDisabled_34[2]= {TR_C1022_S_Aget_L_Receive_RT, -1 }; /* D941_L_PVARP*/
static const int PE_PossiblyDisabled_36[2]= {TR_C1023_S_Aget_L_Receive_RT, -1 }; /* D944_L_PVAB*/
static const int PE_PossiblyDisabled_37[4]= {TR_C956_L_Receive_RT, TR_RVP938__RT, TR_RVS939__RT, -1 }; /* C1021_S_Aget_L_Idle_L_Receive*/
static const int PE_PossiblyDisabled_38[3]= {TR_C956_L_Receive_RT, TR_D941_L_PVARP_RT, -1 }; /* C1022_S_Aget_L_Receive*/
static const int PE_PossiblyDisabled_39[3]= {TR_C956_L_Receive_RT, TR_D944_L_PVAB_RT, -1 }; /* C1023_S_Aget_L_Receive*/
static const int PE_PossiblyDisabled_41[5]= {TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* D900_L_URI*/
static const int PE_PossiblyDisabled_43[6]= {TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_I1043_S_TAVI_L_q0_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* I1025_S_IncrClk_L_Idle0_L_q1*/
static const int PE_PossiblyDisabled_44[2]= {TR_I1040_S_TAVI_L_q0_L_AVI0_RT, -1 }; /* I1026_S_IncrClk_L_AVI0_L_q1*/
static const int PE_PossiblyDisabled_45[4]= {TR_I927_L_Vsig_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, TR_I1042_S_TAVI_L_q0_RT, -1 }; /* I1027_S_IncrClk_L_WaitURI_L_q1*/
static const int PE_PossiblyDisabled_46[8]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_D900_L_URI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT, -1 }; /* RVS1028_S_RURI_L_AVI1_RURI*/
static const int PE_PossiblyDisabled_47[8]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_D900_L_URI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, TR_I1040_S_TAVI_L_q0_L_AVI0_RT, -1 }; /* RVS1030_S_RURI_L_AVI0_RURI*/
static const int PE_PossiblyDisabled_48[8]= {TR_EMPTY_VS_RT, TR_I927_L_Vsig_RT, TR_RVS939__RT, TR_D900_L_URI_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, TR_I1042_S_TAVI_L_q0_RT, -1 }; /* RVS1031_S_RURI_L_WaitURI_RURI*/
static const int PE_PossiblyDisabled_50[6]= {TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_I1041_S_TAVI_L_q0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, -1 }; /* I1033_S_IncrClk_L_q1*/
static const int PE_PossiblyDisabled_51[5]= {TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* D931_q0*/
static const int PE_PossiblyDisabled_53[9]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_I1033_S_IncrClk_L_q1_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* RAS1035_S_RTAVI_L_q1_L_Idle1*/
static const int PE_PossiblyDisabled_54[8]= {TR_EMPTY_AP_RT, TR_I978_L_LRI_RT, TR_I1033_S_IncrClk_L_q1_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RAP1036_S_RTAVI_L_q1_L_Idle1*/
static const int PE_PossiblyDisabled_55[9]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_I1025_S_IncrClk_L_Idle0_L_q1_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* RAS1037_S_RTAVI_L_q1_L_Idle0*/
static const int PE_PossiblyDisabled_56[8]= {TR_EMPTY_AP_RT, TR_I978_L_LRI_RT, TR_I1025_S_IncrClk_L_Idle0_L_q1_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RAP1038_S_RTAVI_L_q1_L_Idle0*/
static const int PE_PossiblyDisabled_57[5]= {TR_I927_L_Vsig_RT, TR_D900_L_URI_RT, TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_RVS1028_S_RURI_L_AVI1_RURI_RT, -1 }; /* I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI*/
static const int PE_PossiblyDisabled_58[3]= {TR_I1026_S_IncrClk_L_AVI0_L_q1_RT, TR_RVS1030_S_RURI_L_AVI0_RURI_RT, -1 }; /* I1040_S_TAVI_L_q0_L_AVI0*/
static const int PE_PossiblyDisabled_59[2]= {TR_I1033_S_IncrClk_L_q1_RT, -1 }; /* I1041_S_TAVI_L_q0*/
static const int PE_PossiblyDisabled_60[3]= {TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT, TR_RVS1031_S_RURI_L_WaitURI_RURI_RT, -1 }; /* I1042_S_TAVI_L_q0*/
static const int PE_PossiblyDisabled_61[2]= {TR_I1025_S_IncrClk_L_Idle0_L_q1_RT, -1 }; /* I1043_S_TAVI_L_q0*/
static const int PE_PossiblyDisabled_62[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_I1033_S_IncrClk_L_q1_RT, TR_D931_q0_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* RAS1044_S_RTAVI_L_Idle1*/
static const int PE_PossiblyDisabled_63[9]= {TR_EMPTY_AP_RT, TR_I978_L_LRI_RT, TR_I1033_S_IncrClk_L_q1_RT, TR_D931_q0_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RAP1045_S_RTAVI_L_Idle1*/
static const int PE_PossiblyDisabled_64[10]= {TR_EMPTY_AS_RT, TR_RAS891__RT, TR_I942_L_Asig_RT, TR_I1025_S_IncrClk_L_Idle0_L_q1_RT, TR_D931_q0_RT, TR_RAS1035_S_RTAVI_L_q1_L_Idle1_RT, TR_RAS1037_S_RTAVI_L_q1_L_Idle0_RT, TR_RAS1044_S_RTAVI_L_Idle1_RT, TR_RAP1047_S_RTAVI_L_Idle0_RT, -1 }; /* RAS1046_S_RTAVI_L_Idle0*/
static const int PE_PossiblyDisabled_65[9]= {TR_EMPTY_AP_RT, TR_I978_L_LRI_RT, TR_I1025_S_IncrClk_L_Idle0_L_q1_RT, TR_D931_q0_RT, TR_RAP1036_S_RTAVI_L_q1_L_Idle1_RT, TR_RAP1038_S_RTAVI_L_q1_L_Idle0_RT, TR_RAP1045_S_RTAVI_L_Idle1_RT, TR_RAS1046_S_RTAVI_L_Idle0_RT, -1 }; /* RAP1047_S_RTAVI_L_Idle0*/
const int* SPN::PossiblyDisabled[] = {PE_PossiblyDisabled_0, PE_PossiblyDisabled_1, PE_PossiblyDisabled_2, PE_PossiblyDisabled_3, PE_PossiblyDisabled_4, PE_PossiblyDisabled_5, PE_PossiblyDisabled_6, PE_PossiblyDisabled_7, EMPTY_array, PE_PossiblyDisabled_9, EMPTY_array, PE_PossiblyDisabled_11, EMPTY_array, PE_PossiblyDisabled_13, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, PE_PossiblyDisabled_19, EMPTY_array, PE_PossiblyDisabled_21, PE_PossiblyDisabled_22, EMPTY_array, EMPTY_array, EMPTY_array, PE_PossiblyDisabled_26, PE_PossiblyDisabled_27, EMPTY_array, PE_PossiblyDisabled_29, EMPTY_array, PE_PossiblyDisabled_31, EMPTY_array, EMPTY_array, PE_PossiblyDisabled_34, EMPTY_array, PE_PossiblyDisabled_36, PE_PossiblyDisabled_37, PE_PossiblyDisabled_38, PE_PossiblyDisabled_39, EMPTY_array, PE_PossiblyDisabled_41, EMPTY_array, PE_PossiblyDisabled_43, PE_PossiblyDisabled_44, PE_PossiblyDisabled_45, PE_PossiblyDisabled_46, PE_PossiblyDisabled_47, PE_PossiblyDisabled_48, EMPTY_array, PE_PossiblyDisabled_50, PE_PossiblyDisabled_51, EMPTY_array, PE_PossiblyDisabled_53, PE_PossiblyDisabled_54, PE_PossiblyDisabled_55, PE_PossiblyDisabled_56, PE_PossiblyDisabled_57, PE_PossiblyDisabled_58, PE_PossiblyDisabled_59, PE_PossiblyDisabled_60, PE_PossiblyDisabled_61, PE_PossiblyDisabled_62, PE_PossiblyDisabled_63, PE_PossiblyDisabled_64, PE_PossiblyDisabled_65};

const int* SPN::FreeMarkDepT[] = {EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array, EMPTY_array};

SPN::SPN():
pl(14), tr(66) {
}

bool SPN::IsEnabled(TR_PL_ID t)const {
	if(!magicConditional(t))return false;
switch (t){
	case 65:	//RAP1047_S_RTAVI_L_Idle0
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 54:	//RAP1036_S_RTAVI_L_q1_L_Idle1
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 930) return false;
    if( Marking.P->_PL_AVI != 895) return false;
    return true;

		break;
	case 56:	//RAP1038_S_RTAVI_L_q1_L_Idle0
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 930) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 0:	//EMPTY_AP
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    return true;

		break;
	case 9:	//RAS891_
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_LRI != 886) return false;
    return true;

		break;
	case 62:	//RAS1044_S_RTAVI_L_Idle1
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    if( Marking.P->_PL_AVI != 895) return false;
    return true;

		break;
	case 64:	//RAS1046_S_RTAVI_L_Idle0
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 53:	//RAS1035_S_RTAVI_L_q1_L_Idle1
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 930) return false;
    if( Marking.P->_PL_AVI != 895) return false;
    return true;

		break;
	case 55:	//RAS1037_S_RTAVI_L_q1_L_Idle0
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 930) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 1:	//EMPTY_AS
    if (!(contains(Marking.P->_PL_SIG_AS , 1))) return false;
    return true;

		break;
	case 13:	//RRLRI893_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 886) return false;
    return true;

		break;
	case 11:	//RRLRI892_
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    if( Marking.P->_PL_LRI != 887) return false;
    return true;

		break;
	case 2:	//EMPTY_RLRI
    if (!(contains(Marking.P->_PL_SIG_RLRI , 1))) return false;
    return true;

		break;
	case 27:	//RSREC958_
    if (!(contains(Marking.P->_PL_SIG_SREC , 1))) return false;
    if( Marking.P->_PL_SerialPort != 949) return false;
    return true;

		break;
	case 3:	//EMPTY_SREC
    if (!(contains(Marking.P->_PL_SIG_SREC , 1))) return false;
    return true;

		break;
	case 29:	//RVP938_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_PVARP != 934) return false;
    return true;

		break;
	case 19:	//RVP926_
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    if( Marking.P->_PL_VRP != 906) return false;
    return true;

		break;
	case 4:	//EMPTY_VP
    if (!(contains(Marking.P->_PL_SIG_VP , 1))) return false;
    return true;

		break;
	case 47:	//RVS1030_S_RURI_L_AVI0_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 908) return false;
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 48:	//RVS1031_S_RURI_L_WaitURI_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 909) return false;
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 46:	//RVS1028_S_RURI_L_AVI1_RURI
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_AVI != 911) return false;
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 31:	//RVS939_
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    if( Marking.P->_PL_PVARP != 934) return false;
    return true;

		break;
	case 5:	//EMPTY_VS
    if (!(contains(Marking.P->_PL_SIG_VS , 1))) return false;
    return true;

		break;
	case 22:	//RVget928_
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    if( Marking.P->_PL_VRP != 906) return false;
    return true;

		break;
	case 6:	//EMPTY_Vget
    if (!(contains(Marking.P->_PL_SIG_Vget , 1))) return false;
    return true;

		break;
	case 8:	//I978_L_LRI
    if (Marking.P->_PL_SIG_AP >= 1) return false;
    if( Marking.P->_PL_LRI != 977) return false;
    return true;

		break;
	case 35:	//I942_L_Asig
    if (Marking.P->_PL_SIG_AS >= 1) return false;
    if( Marking.P->_PL_PVARP != 936) return false;
    return true;

		break;
	case 45:	//I1027_S_IncrClk_L_WaitURI_L_q1
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_AVI != 909) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 57:	//I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VP >= 1) return false;
    if( Marking.P->_PL_TAVIcmp != 965) return false;
    if( Marking.P->_PL_AVI != 911) return false;
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 21:	//I927_L_Vsig
    if (Marking.P->_PL_SIG_RLRI >= 1) return false;
    if (Marking.P->_PL_SIG_VS >= 1) return false;
    if( Marking.P->_PL_VRP != 925) return false;
    return true;

		break;
	case 26:	//C956_L_Receive
    if (Marking.P->_PL_SIG_Vget >= 1) return false;
    if( Marking.P->_PL_SerialPort != 955) return false;
    return true;

		break;
	case 50:	//I1033_S_IncrClk_L_q1
    if( Marking.P->_PL_AVI != 895) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 43:	//I1025_S_IncrClk_L_Idle0_L_q1
    if( Marking.P->_PL_AVI != 907) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 44:	//I1026_S_IncrClk_L_AVI0_L_q1
    if( Marking.P->_PL_AVI != 908) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 49:	//I1032_S_IncrClk_L_q1
    if( Marking.P->_PL_AVI != 911) return false;
    if( Marking.P->_PL_URI != 898) return false;
    return true;

		break;
	case 14:	//I1063_RLRI
    if( Marking.P->_PL_LRI != 1062) return false;
    return true;

		break;
	case 12:	//I1065_L_ASensed
    if( Marking.P->_PL_LRI != 1064) return false;
    return true;

		break;
	case 10:	//I1067_L_LRI
    if( Marking.P->_PL_LRI != 1066) return false;
    return true;

		break;
	case 7:	//D888_LRI
    if( Marking.P->_PL_LRI != 886) return false;
    return true;

		break;
	case 16:	//I974_init
    if( Marking.P->_PL_LRI != 973) return false;
    return true;

		break;
	case 15:	//I976_L_LRI
    if( Marking.P->_PL_LRI != 975) return false;
    return true;

		break;
	case 32:	//I1053_L_Idle
    if( Marking.P->_PL_PVARP != 1052) return false;
    return true;

		break;
	case 30:	//I1055_L_Idle
    if( Marking.P->_PL_PVARP != 1054) return false;
    return true;

		break;
	case 37:	//C1021_S_Aget_L_Idle_L_Receive
    if( Marking.P->_PL_PVARP != 934) return false;
    if( Marking.P->_PL_SerialPort != 955) return false;
    return true;

		break;
	case 39:	//C1023_S_Aget_L_Receive
    if( Marking.P->_PL_PVARP != 935) return false;
    if( Marking.P->_PL_SerialPort != 955) return false;
    return true;

		break;
	case 36:	//D944_L_PVAB
    if( Marking.P->_PL_PVARP != 935) return false;
    return true;

		break;
	case 38:	//C1022_S_Aget_L_Receive
    if( Marking.P->_PL_PVARP != 937) return false;
    if( Marking.P->_PL_SerialPort != 955) return false;
    return true;

		break;
	case 34:	//D941_L_PVARP
    if( Marking.P->_PL_PVARP != 937) return false;
    return true;

		break;
	case 33:	//I962_init
    if( Marking.P->_PL_PVARP != 961) return false;
    return true;

		break;
	case 28:	//I1057_L_NoData
    if( Marking.P->_PL_SerialPort != 1056) return false;
    return true;

		break;
	case 24:	//I954_L_DataAvailable
    if( Marking.P->_PL_SerialPort != 952) return false;
    return true;

		break;
	case 25:	//I960_init
    if( Marking.P->_PL_SerialPort != 959) return false;
    return true;

		break;
	case 51:	//D931_q0
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    return true;

		break;
	case 52:	//I964_init
    if( Marking.P->_PL_TAVIcmp != 963) return false;
    return true;

		break;
	case 59:	//I1041_S_TAVI_L_q0
    if( Marking.P->_PL_TAVIcmp != 965) return false;
    if( Marking.P->_PL_AVI != 895) return false;
    return true;

		break;
	case 61:	//I1043_S_TAVI_L_q0
    if( Marking.P->_PL_TAVIcmp != 965) return false;
    if( Marking.P->_PL_AVI != 907) return false;
    return true;

		break;
	case 58:	//I1040_S_TAVI_L_q0_L_AVI0
    if( Marking.P->_PL_TAVIcmp != 965) return false;
    if( Marking.P->_PL_AVI != 908) return false;
    return true;

		break;
	case 60:	//I1042_S_TAVI_L_q0
    if( Marking.P->_PL_TAVIcmp != 965) return false;
    if( Marking.P->_PL_AVI != 909) return false;
    return true;

		break;
	case 41:	//D900_L_URI
    if( Marking.P->_PL_URI != 897) return false;
    return true;

		break;
	case 42:	//I970_init
    if( Marking.P->_PL_URI != 969) return false;
    return true;

		break;
	case 40:	//I972_L_URI
    if( Marking.P->_PL_URI != 971) return false;
    return true;

		break;
	case 23:	//I1059_L_Idle
    if( Marking.P->_PL_VRP != 1058) return false;
    return true;

		break;
	case 20:	//I1061_L_Idle
    if( Marking.P->_PL_VRP != 1060) return false;
    return true;

		break;
	case 17:	//D923_L_VRP
    if( Marking.P->_PL_VRP != 924) return false;
    return true;

		break;
	case 18:	//I968_init
    if( Marking.P->_PL_VRP != 967) return false;
    return true;

		break;
	default:	//RAP1045_S_RTAVI_L_Idle1,
    if (!(contains(Marking.P->_PL_SIG_AP , 1))) return false;
    if( Marking.P->_PL_TAVIcmp != 929) return false;
    if( Marking.P->_PL_AVI != 895) return false;
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
		case 7: {  //D888_LRI
			Marking.P->_PL_LRI -= 886;
			Marking.P->_PL_LRI += 977;
       break;
     } 
		case 8: {  //I978_L_LRI
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_LRI -= 977;
			Marking.P->_PL_LRI += 886;
       break;
     } 
		case 9: {  //RAS891_
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_LRI -= 886;
			Marking.P->_PL_LRI += 1066;
       break;
     } 
		case 10: {  //I1067_L_LRI
			Marking.P->_PL_LRI -= 1066;
			Marking.P->_PL_LRI += 887;
       break;
     } 
		case 11: {  //RRLRI892_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 887;
			Marking.P->_PL_LRI += 1064;
       break;
     } 
		case 12: {  //I1065_L_ASensed
			Marking.P->_PL_LRI -= 1064;
			Marking.P->_PL_LRI += 886;
       break;
     } 
		case 13: {  //RRLRI893_
			Marking.P->_PL_SIG_RLRI -= 1;
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_LRI -= 886;
			Marking.P->_PL_LRI += 1062;
       break;
     } 
		case 14: {  //I1063_RLRI
			Marking.P->_PL_LRI -= 1062;
			Marking.P->_PL_LRI += 975;
       break;
     } 
		case 15: {  //I976_L_LRI
			Marking.P->_PL_LRI -= 975;
			Marking.P->_PL_LRI += 886;
       break;
     } 
		case 16: {  //I974_init
			Marking.P->_PL_LRI -= 973;
			Marking.P->_PL_LRI += 886;
       break;
     } 
		case 17: {  //D923_L_VRP
			Marking.P->_PL_VRP -= 924;
			Marking.P->_PL_VRP += 906;
       break;
     } 
		case 18: {  //I968_init
			Marking.P->_PL_VRP -= 967;
			Marking.P->_PL_VRP += 906;
       break;
     } 
		case 19: {  //RVP926_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_VRP -= 906;
			Marking.P->_PL_VRP += 1060;
       break;
     } 
		case 20: {  //I1061_L_Idle
			Marking.P->_PL_VRP -= 1060;
			Marking.P->_PL_VRP += 924;
       break;
     } 
		case 21: {  //I927_L_Vsig
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_VRP -= 925;
			Marking.P->_PL_VRP += 906;
       break;
     } 
		case 22: {  //RVget928_
			Marking.P->_PL_SIG_Vget -= 1;
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_VRP -= 906;
			Marking.P->_PL_VRP += 1058;
       break;
     } 
		case 23: {  //I1059_L_Idle
			Marking.P->_PL_VRP -= 1058;
			Marking.P->_PL_VRP += 925;
       break;
     } 
		case 24: {  //I954_L_DataAvailable
			Marking.P->_PL_SerialPort -= 952;
			Marking.P->_PL_SerialPort += 955;
       break;
     } 
		case 25: {  //I960_init
			Marking.P->_PL_SerialPort -= 959;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 26: {  //C956_L_Receive
			Marking.P->_PL_SIG_Vget += 1;
			Marking.P->_PL_SerialPort -= 955;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 27: {  //RSREC958_
			Marking.P->_PL_SIG_SREC -= 1;
			Marking.P->_PL_SIG_SREC += 1;
			Marking.P->_PL_SerialPort -= 949;
			Marking.P->_PL_SerialPort += 1056;
       break;
     } 
		case 28: {  //I1057_L_NoData
			Marking.P->_PL_SerialPort -= 1056;
			Marking.P->_PL_SerialPort += 952;
       break;
     } 
		case 29: {  //RVP938_
			Marking.P->_PL_SIG_VP -= 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_PVARP -= 934;
			Marking.P->_PL_PVARP += 1054;
       break;
     } 
		case 30: {  //I1055_L_Idle
			Marking.P->_PL_PVARP -= 1054;
			Marking.P->_PL_PVARP += 935;
       break;
     } 
		case 31: {  //RVS939_
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_PVARP -= 934;
			Marking.P->_PL_PVARP += 1052;
       break;
     } 
		case 32: {  //I1053_L_Idle
			Marking.P->_PL_PVARP -= 1052;
			Marking.P->_PL_PVARP += 935;
       break;
     } 
		case 33: {  //I962_init
			Marking.P->_PL_PVARP -= 961;
			Marking.P->_PL_PVARP += 934;
       break;
     } 
		case 34: {  //D941_L_PVARP
			Marking.P->_PL_PVARP -= 937;
			Marking.P->_PL_PVARP += 934;
       break;
     } 
		case 35: {  //I942_L_Asig
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_PVARP -= 936;
			Marking.P->_PL_PVARP += 934;
       break;
     } 
		case 36: {  //D944_L_PVAB
			Marking.P->_PL_PVARP -= 935;
			Marking.P->_PL_PVARP += 937;
       break;
     } 
		case 37: {  //C1021_S_Aget_L_Idle_L_Receive
			Marking.P->_PL_PVARP -= 934;
			Marking.P->_PL_PVARP += 936;
			Marking.P->_PL_SerialPort -= 955;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 38: {  //C1022_S_Aget_L_Receive
			Marking.P->_PL_PVARP -= 937;
			Marking.P->_PL_PVARP += 937;
			Marking.P->_PL_SerialPort -= 955;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 39: {  //C1023_S_Aget_L_Receive
			Marking.P->_PL_PVARP -= 935;
			Marking.P->_PL_PVARP += 935;
			Marking.P->_PL_SerialPort -= 955;
			Marking.P->_PL_SerialPort += 949;
       break;
     } 
		case 40: {  //I972_L_URI
			Marking.P->_PL_URI -= 971;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 41: {  //D900_L_URI
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 898;
       break;
     } 
		case 42: {  //I970_init
			Marking.P->_PL_URI -= 969;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 43: {  //I1025_S_IncrClk_L_Idle0_L_q1
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 895;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 44: {  //I1026_S_IncrClk_L_AVI0_L_q1
			Marking.P->_PL_AVI -= 908;
			Marking.P->_PL_AVI += 911;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 45: {  //I1027_S_IncrClk_L_WaitURI_L_q1
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_AVI -= 909;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 46: {  //RVS1028_S_RURI_L_AVI1_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 911;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 971;
       break;
     } 
		case 47: {  //RVS1030_S_RURI_L_AVI0_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 908;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 971;
       break;
     } 
		case 48: {  //RVS1031_S_RURI_L_WaitURI_RURI
			Marking.P->_PL_SIG_VS -= 1;
			Marking.P->_PL_SIG_VS += 1;
			Marking.P->_PL_AVI -= 909;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 971;
       break;
     } 
		case 49: {  //I1032_S_IncrClk_L_q1
			Marking.P->_PL_AVI -= 911;
			Marking.P->_PL_AVI += 911;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 50: {  //I1033_S_IncrClk_L_q1
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 895;
			Marking.P->_PL_URI -= 898;
			Marking.P->_PL_URI += 897;
       break;
     } 
		case 51: {  //D931_q0
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 965;
       break;
     } 
		case 52: {  //I964_init
			Marking.P->_PL_TAVIcmp -= 963;
			Marking.P->_PL_TAVIcmp += 930;
       break;
     } 
		case 53: {  //RAS1035_S_RTAVI_L_q1_L_Idle1
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 930;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 911;
       break;
     } 
		case 54: {  //RAP1036_S_RTAVI_L_q1_L_Idle1
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 930;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 911;
       break;
     } 
		case 55: {  //RAS1037_S_RTAVI_L_q1_L_Idle0
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 930;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 908;
       break;
     } 
		case 56: {  //RAP1038_S_RTAVI_L_q1_L_Idle0
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 930;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 908;
       break;
     } 
		case 57: {  //I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI
			Marking.P->_PL_SIG_RLRI += 1;
			Marking.P->_PL_SIG_VP += 1;
			Marking.P->_PL_TAVIcmp -= 965;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 911;
			Marking.P->_PL_AVI += 907;
			Marking.P->_PL_URI -= 897;
			Marking.P->_PL_URI += 971;
       break;
     } 
		case 58: {  //I1040_S_TAVI_L_q0_L_AVI0
			Marking.P->_PL_TAVIcmp -= 965;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 908;
			Marking.P->_PL_AVI += 909;
       break;
     } 
		case 59: {  //I1041_S_TAVI_L_q0
			Marking.P->_PL_TAVIcmp -= 965;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 895;
       break;
     } 
		case 60: {  //I1042_S_TAVI_L_q0
			Marking.P->_PL_TAVIcmp -= 965;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 909;
			Marking.P->_PL_AVI += 909;
       break;
     } 
		case 61: {  //I1043_S_TAVI_L_q0
			Marking.P->_PL_TAVIcmp -= 965;
			Marking.P->_PL_TAVIcmp += 930;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 907;
       break;
     } 
		case 62: {  //RAS1044_S_RTAVI_L_Idle1
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 911;
       break;
     } 
		case 63: {  //RAP1045_S_RTAVI_L_Idle1
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 895;
			Marking.P->_PL_AVI += 911;
       break;
     } 
		case 64: {  //RAS1046_S_RTAVI_L_Idle0
			Marking.P->_PL_SIG_AS -= 1;
			Marking.P->_PL_SIG_AS += 1;
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 908;
       break;
     } 
		case 65: {  //RAP1047_S_RTAVI_L_Idle0
			Marking.P->_PL_SIG_AP -= 1;
			Marking.P->_PL_SIG_AP += 1;
			Marking.P->_PL_TAVIcmp -= 929;
			Marking.P->_PL_TAVIcmp += 929;
			Marking.P->_PL_AVI -= 907;
			Marking.P->_PL_AVI += 908;
       break;
     } 
	}
}
void SPN::setConditionsVector(){
}
void SPN::GetDistParameters(TR_PL_ID t )const {
switch (t){
	case 7:	//D888_LRI
	{
		ParamDistr[0]= ( double )  (PM_TLRI  - PM_TAVI ) ;
	}

		break;
	case 34:	//D941_L_PVARP
	{
		ParamDistr[0]= ( double )  (PM_TPVARP  - PM_TPVAB ) ;
	}

		break;
	case 51:	//D931_q0
	{
		ParamDistr[0]= ( double ) PM_TAVI ;
	}

		break;
	case 36:	//D944_L_PVAB
	{
		ParamDistr[0]= ( double ) PM_TPVAB ;
	}

		break;
	case 41:	//D900_L_URI
	{
		ParamDistr[0]= ( double ) PM_TURI ;
	}

		break;
	case 17:	//D923_L_VRP
	{
		ParamDistr[0]= ( double ) PM_TVRP ;
	}

		break;
	default:	//EMPTY_AP,EMPTY_AS,EMPTY_RLRI,EMPTY_SREC,EMPTY_VP,EMPTY_VS,EMPTY_Vget,I978_L_LRI,RAS891_,I1067_L_LRI,RRLRI892_,I1065_L_ASensed,RRLRI893_,I1063_RLRI,I976_L_LRI,I974_init,I968_init,RVP926_,I1061_L_Idle,I927_L_Vsig,RVget928_,I1059_L_Idle,I954_L_DataAvailable,I960_init,C956_L_Receive,RSREC958_,I1057_L_NoData,RVP938_,I1055_L_Idle,RVS939_,I1053_L_Idle,I962_init,I942_L_Asig,C1021_S_Aget_L_Idle_L_Receive,C1022_S_Aget_L_Receive,C1023_S_Aget_L_Receive,I972_L_URI,I970_init,I1025_S_IncrClk_L_Idle0_L_q1,I1026_S_IncrClk_L_AVI0_L_q1,I1027_S_IncrClk_L_WaitURI_L_q1,RVS1028_S_RURI_L_AVI1_RURI,RVS1030_S_RURI_L_AVI0_RURI,RVS1031_S_RURI_L_WaitURI_RURI,I1032_S_IncrClk_L_q1,I1033_S_IncrClk_L_q1,I964_init,RAS1035_S_RTAVI_L_q1_L_Idle1,RAP1036_S_RTAVI_L_q1_L_Idle1,RAS1037_S_RTAVI_L_q1_L_Idle0,RAP1038_S_RTAVI_L_q1_L_Idle0,I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI,I1040_S_TAVI_L_q0_L_AVI0,I1041_S_TAVI_L_q0,I1042_S_TAVI_L_q0,I1043_S_TAVI_L_q0,RAS1044_S_RTAVI_L_Idle1,RAP1045_S_RTAVI_L_Idle1,RAS1046_S_RTAVI_L_Idle0,RAP1047_S_RTAVI_L_Idle0,
	{
		ParamDistr[0]= ( double ) 0 ;
	}

}
}

REAL_TYPE SPN::GetPriority(TR_PL_ID t)const {
switch (t){
	case 51:	//D931_q0
		return (double)0.94 ;

		break;
	case 41:	//D900_L_URI
		return (double)0.95 ;

		break;
	case 7:	//D888_LRI
		return (double)0.96 ;

		break;
	case 34:	//D941_L_PVARP
	case 36:	//D944_L_PVAB
		return (double)0.97 ;

		break;
	case 17:	//D923_L_VRP
		return (double)0.98 ;

		break;
	case 24:	//I954_L_DataAvailable
	case 25:	//I960_init
	case 26:	//C956_L_Receive
	case 28:	//I1057_L_NoData
	case 37:	//C1021_S_Aget_L_Idle_L_Receive
	case 38:	//C1022_S_Aget_L_Receive
	case 39:	//C1023_S_Aget_L_Receive
		return (double)1.93 ;

		break;
	case 52:	//I964_init
	case 57:	//I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI
	case 58:	//I1040_S_TAVI_L_q0_L_AVI0
	case 59:	//I1041_S_TAVI_L_q0
	case 60:	//I1042_S_TAVI_L_q0
	case 61:	//I1043_S_TAVI_L_q0
		return (double)1.94 ;

		break;
	case 40:	//I972_L_URI
	case 42:	//I970_init
	case 43:	//I1025_S_IncrClk_L_Idle0_L_q1
	case 44:	//I1026_S_IncrClk_L_AVI0_L_q1
	case 45:	//I1027_S_IncrClk_L_WaitURI_L_q1
	case 49:	//I1032_S_IncrClk_L_q1
	case 50:	//I1033_S_IncrClk_L_q1
		return (double)1.95 ;

		break;
	case 8:	//I978_L_LRI
	case 10:	//I1067_L_LRI
	case 12:	//I1065_L_ASensed
	case 14:	//I1063_RLRI
	case 15:	//I976_L_LRI
	case 16:	//I974_init
		return (double)1.96 ;

		break;
	case 30:	//I1055_L_Idle
	case 32:	//I1053_L_Idle
	case 33:	//I962_init
	case 35:	//I942_L_Asig
		return (double)1.97 ;

		break;
	case 18:	//I968_init
	case 20:	//I1061_L_Idle
	case 21:	//I927_L_Vsig
	case 23:	//I1059_L_Idle
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
	default:	//RAS891_,RRLRI892_,RRLRI893_,RVP926_,RVget928_,RSREC958_,RVP938_,RVS939_,RVS1028_S_RURI_L_AVI1_RURI,RVS1030_S_RURI_L_AVI0_RURI,RVS1031_S_RURI_L_WaitURI_RURI,RAS1035_S_RTAVI_L_q1_L_Idle1,RAP1036_S_RTAVI_L_q1_L_Idle1,RAS1037_S_RTAVI_L_q1_L_Idle0,RAP1038_S_RTAVI_L_q1_L_Idle0,RAS1044_S_RTAVI_L_Idle1,RAP1045_S_RTAVI_L_Idle1,RAS1046_S_RTAVI_L_Idle0,RAP1047_S_RTAVI_L_Idle0,
		return (double)3.99 ;

}
}

REAL_TYPE SPN::GetWeight(TR_PL_ID t)const{
		return (double)1 ;

}

void SPN::reset() {
	Marking.resetToInitMarking();
}

