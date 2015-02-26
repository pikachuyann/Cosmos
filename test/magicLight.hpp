#include <string>
using namespace std;
#define temporalCount(msec) 0
#include "markingImplLight.hpp"
const void print_magic(int v){
	switch(v){
		case 1114: print("PostRead_AS");break;
		case 1112: print("PostRead_RLRI");break;
		case 1110: print("PostRead_RLRI");break;
		case 1108: print("PostRead_VP");break;
		case 1106: print("PostRead_Vget");break;
		case 1104: print("PostRead_AP");break;
		case 1102: print("PostRead_VP");break;
		case 1100: print("PostRead_SREC");break;
		case 1098: print("PostRead_VP");break;
		case 1096: print("PostRead_VS");break;
		case 991: print("931_Pre_q1");break;
		case 989: print("933_Pre_q1");break;
		case 930: print("q1");break;
		case 929: print("q0");break;
		case 911: print("AVI1");break;
		case 895: print("Idle1");break;
		case 909: print("WaitURI");break;
		case 908: print("AVI0");break;
		case 907: print("Idle0");break;
		case 997: print("899_Pre_URI");break;
		case 995: print("901_Pre_URI");break;
		case 898: print("q1");break;
		case 897: print("URI");break;
		case 987: print("940_Pre_Idle");break;
		case 937: print("PVARP");break;
		case 936: print("Asig");break;
		case 935: print("PVAB");break;
		case 934: print("Idle");break;
		case 985: print("953_Pre_NoData");break;
		case 955: print("Receive");break;
		case 949: print("NoData");break;
		case 981: print("970_Pre_Off");break;
		case 971: print("On");break;
		case 973: print("Off");break;
		case 983: print("962_Pre_Off");break;
		case 963: print("On");break;
		case 961: print("Off");break;
		case 993: print("910_Pre_Idle");break;
		case 925: print("Vsig");break;
		case 924: print("VRP");break;
		case 906: print("Idle");break;
		case 1003: print("888_Pre_LRI");break;
		case 1001: print("893_Pre_LRI");break;
		case 999: print("889_Pre_LRI");break;
		case 887: print("ASensed");break;
		case 886: print("LRI");break;
		default: print((TR_PL_ID)v);break;;
	}
}
uint32 value=0;
uint32 tmp32=0;
uint16 tmp16=0;
uint32 PM_TVRP=0;
uint32 PM_TURI=0;
uint32 PM_TPVARP=0;
uint32 PM_TPVAB=0;
uint32 PM_TLRI=0;
uint32 PM_TAVI=0;
uint8 bufs5=0;
uint8 bufs4=0;
uint8 bufs3=0;
uint8 bufs1=0;
uint8 bufs2=0;
double parval=0;
uint16 parid=0;
uint32 BAUDRATE=0;
double power(double x,double y){return pow(x,y);}

double min(double x,double y){return fmin(x,y);}

double max(double x,double y){return fmax(x,y);}

void magicReset(){}

unsigned char SReceive(void);

void dW(uint8 port, uint8 value);
void SetParameters(unsigned char c, double value){
  switch(c){
    case 0: PM_TURI=value; break;
    case 1: PM_TAVI=value; break;
    case 2: PM_TLRI=value; break;
  }
}

void SWrite(unsigned char h);
void magicUpdate(int t,double ctime){
  switch(t){
	case TR_I1004_L_LRI_RT:
		SWrite(0x33);
	break;
	case TR_I1000_init_RT:
		PM_TLRI=1000;
	break;
	case TR_I994_init_RT:
		PM_TVRP=320;
	break;
	case TR_I984_init_RT:
		dW(12,0);
	break;
	case TR_D969_L_On_RT:
		dW(12,0);
	break;
	case TR_I1105_L_Off_RT:
		dW(12,1);
	break;
	case TR_I982_init_RT:
		dW(11,0);
	break;
	case TR_D974_L_On_RT:
		dW(11,0);
	break;
	case TR_I1103_L_Off_RT:
		dW(11,1);
	break;
	case TR_I986_init_RT:
		BAUDRATE=57600;
	break;
	case TR_I1101_L_NoData_RT:
		bufs1=SReceive();
	break;
	case TR_I988_init_RT:
		PM_TPVARP=250;
		PM_TPVAB=50;
	break;
	case TR_I1085_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT:
		SWrite(0x34);
	break;
	case TR_I1069_S_IncrClk_L_WaitURI_L_q1_RT:
		SWrite(0x34);
	break;
	case TR_I996_init_RT:
		PM_TURI=500;
	break;
	case TR_I990_init_RT:
		PM_TAVI=150;
	break;
	default: break; 
	}
}
bool magicConditional(int t){
  switch(t){
	case TR_C1065_S_Aget_L_Receive_RT:
		return bufs1==0x31;
	case TR_C1064_S_Aget_L_Receive_RT:
		return bufs1==0x31;
	case TR_C1063_S_Aget_L_Idle_L_Receive_RT:
		return bufs1==0x31;
	case TR_C956_L_Receive_RT:
		return bufs1==0x32;
	default: return true; 
	}
}
