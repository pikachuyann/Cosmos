#include <string>
using namespace std;
#define temporalCount(msec) 0
#include "markingImplLight.hpp"
#define DATA_AVAILABLE 952
const void print_magic(int v){
	switch(v){
		case 1066: print("PostRead_AS");break;
		case 1064: print("PostRead_RLRI");break;
		case 1062: print("PostRead_RLRI");break;
		case 1060: print("PostRead_VP");break;
		case 1058: print("PostRead_Vget");break;
		case 1056: print("PostRead_SREC");break;
		case 1054: print("PostRead_VP");break;
		case 1052: print("PostRead_VS");break;
		case 965: print("931_Pre_q1");break;
		case 963: print("933_Pre_q1");break;
		case 930: print("q1");break;
		case 929: print("q0");break;
		case 911: print("AVI1");break;
		case 895: print("Idle1");break;
		case 909: print("WaitURI");break;
		case 908: print("AVI0");break;
		case 907: print("Idle0");break;
		case 971: print("899_Pre_URI");break;
		case 969: print("901_Pre_URI");break;
		case 898: print("q1");break;
		case 897: print("URI");break;
		case 961: print("940_Pre_Idle");break;
		case 937: print("PVARP");break;
		case 936: print("Asig");break;
		case 935: print("PVAB");break;
		case 934: print("Idle");break;
		case 959: print("953_Pre_NoData");break;
		case 952: print("DataAvailable");break;
		case 955: print("Receive");break;
		case 949: print("NoData");break;
		case 967: print("910_Pre_Idle");break;
		case 925: print("Vsig");break;
		case 924: print("VRP");break;
		case 906: print("Idle");break;
		case 977: print("888_Pre_LRI");break;
		case 975: print("893_Pre_LRI");break;
		case 973: print("889_Pre_LRI");break;
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

void SWrite(unsigned char h);

unsigned char SReceive(void);
void magicUpdate(int t,double ctime){
  switch(t){
	case TR_I978_L_LRI_RT:
		SWrite(0x33);
	break;
	case TR_I974_init_RT:
		PM_TLRI=1000;
	break;
	case TR_I968_init_RT:
		PM_TVRP=320;
	break;
	case TR_I954_L_DataAvailable_RT:
		bufs1=SReceive();
	break;
	case TR_I960_init_RT:
		BAUDRATE=57600;
	break;
	case TR_I962_init_RT:
		PM_TPVARP=250;
		PM_TPVAB=50;
	break;
	case TR_I970_init_RT:
		PM_TURI=500;
	break;
	case TR_I1027_S_IncrClk_L_WaitURI_L_q1_RT:
		SWrite(0x34);
	break;
	case TR_I964_init_RT:
		PM_TAVI=150;
	break;
	case TR_I1039_S_TAVI_L_q0_S_RURI_L_AVI1_RURI_RT:
		SWrite(0x34);
	break;
	default: break; 
	}
}
bool magicConditional(int t){
  switch(t){
	case TR_C956_L_Receive_RT:
		return bufs1==0x32;
	case TR_C1021_S_Aget_L_Idle_L_Receive_RT:
		return bufs1==0x31;
	case TR_C1022_S_Aget_L_Receive_RT:
		return bufs1==0x31;
	case TR_C1023_S_Aget_L_Receive_RT:
		return bufs1==0x31;
	default: return true; 
	}
}
void abstractMarking::moveSerialState(){ P->_PL_SerialPort = DATA_AVAILABLE;};
