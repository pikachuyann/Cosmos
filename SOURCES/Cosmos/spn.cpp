#include "spn.hpp" 

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <utility>
#include <stdlib.h>
#include <time.h>
#include <set>
#include <vector>
#include <math.h>
#include <float.h>
#include <limits.h> 
#include "RareEvent.hpp"

SPN::SPN() {
}

SPN::~SPN() {
}

SPN::SPN(const SPN & orig) {

}

set<int, less <int> > SPN::enabledTrans() {
    set<int, less<int> > eTrans;
    for (int i = 0; i < (this->tr); i++) {
        if (IsEnabled(i)) {
            eTrans.insert(i);
        }
    }
    this->enTrans = eTrans;
    return eTrans;
}

void SPN::reset() {
    Marking = initMarking;
}

void SPN::setMarking(vector<int>& M) {
    Marking = M;
}

void SPN::EnabledDisabledTr() {

    PossiblyEnabled = new Dim2;
    PossiblyDisabled = new Dim2;
    //-------------- Rare Event -----------------
    vector<int> AllEnabled;
    for (int i =0; i< tr; i++){ AllEnabled.push_back(i); };
    //------------- /Rare Event -----------------

    for (int t1 = 0; t1 < tr; t1++) {
        Dim1 V;
        Dim1 Vinhib;
        set<int> INt1;
        for (int p = 0; p < pl; p++) {
            if (inArcs[t1][p] > 0) {
                INt1.insert(p);
            }
        }
        for (int t2 = 0; t2 < tr; t2++)
            if (t1 != t2) {
                int size = INt1.size();
                set<int> INt1t2 = INt1;
                bool B = true;
                int p = 0;
                while (B && p < pl) {
                    if (inArcs[t2][p] > 0) {
                        INt1t2.insert(p);
                        if (size == INt1t2.size()) {
                            B = false;
                            V.push_back(t2);
                        } else size = INt1t2.size();
                    }
                    p++;
                }

                size = INt1.size();
                set<int> INt1t2Inhib = INt1;
                B = true;
                p = 0;
                while (B && p < pl) {
                    if (inhibArcs[t2][p] > 0) {
                        INt1t2Inhib.insert(p);
                        if (size == INt1t2Inhib.size()) {
                            B = false;
                            Vinhib.push_back(t2);
                        } else size = INt1t2Inhib.size();
                    }
                    p++;
                }

            }


        (*PossiblyDisabled).push_back(V);
        (*PossiblyEnabled).push_back(Vinhib);
    }
    for (int t1 = 0; t1 < tr; t1++) {
        Dim1 V = (*PossiblyEnabled)[t1];
        set<int> OUTt1;
        for (int p = 0; p < pl; p++)
            if (outArcs[t1][p] > 0)
                OUTt1.insert(p);
        for (int t2 = 0; t2 < tr; t2++)
            if (t1 != t2) {
                int size = OUTt1.size();
                set<int> OUTt1INt2 = OUTt1;
                bool B = true;
                int p = 0;
                while (B && p < pl) {
                    if (inArcs[t2][p] > 0) {
                        OUTt1INt2.insert(p);
                        if (size == OUTt1INt2.size()) {
                            B = false;
                            V.push_back(t2);
                        } else size = OUTt1INt2.size();
                    }
                    p++;
                }
            }
	//-------------- Rare Event -----------------
	//  (*PossiblyEnabled)[t1] = V;    Ligne original
	(*PossiblyEnabled)[t1]=AllEnabled;
	//------------- /Rare Event -----------------
    }


}

Dim1 SPN::PossiblyEn(int t) {
    return (*PossiblyEnabled)[t];
}

Dim1 SPN::PossiblyDis(int t) {
    return (*PossiblyDisabled)[t];
}

vector<int> SPN::getMarking() {
    return Marking;
}

double SPN::min(double x1, double x2) {
    if (x1 < x2) return x1;
    else return x2;
}

double SPN::max(double x1, double x2) {
    if (x1 > x2) return x1;
    else return x2;
}


void SPN::Load(){
    Path ="../philosophe";
    gammaprob.load();
    pl =64;
    tr =46;
    IntVector Null_Pl_Vector(pl, 0);
    IntMatrix Null_PlxTr_Matrix(tr, Null_Pl_Vector);
    inArcs = Null_PlxTr_Matrix;
    outArcs = Null_PlxTr_Matrix;
    inhibArcs = Null_PlxTr_Matrix;
    Marking = Null_Pl_Vector;;
    inArcs[0][0]=1;
    inArcs[0][3]=1;
    inArcs[0][60]=1;

    inArcs[1][1]=1;
    inArcs[1][59]=1;
    inArcs[1][61]=1;

    inArcs[2][2]=1;

    inArcs[3][4]=1;
    inArcs[3][7]=1;
    inArcs[3][60]=1;

    inArcs[4][3]=1;
    inArcs[4][5]=1;
    inArcs[4][61]=1;

    inArcs[5][6]=1;

    inArcs[6][8]=1;
    inArcs[6][11]=1;
    inArcs[6][60]=1;

    inArcs[7][7]=1;
    inArcs[7][9]=1;
    inArcs[7][61]=1;

    inArcs[8][10]=1;

    inArcs[9][12]=1;
    inArcs[9][15]=1;
    inArcs[9][60]=1;

    inArcs[10][11]=1;
    inArcs[10][13]=1;
    inArcs[10][61]=1;

    inArcs[11][14]=1;

    inArcs[12][16]=1;
    inArcs[12][19]=1;
    inArcs[12][60]=1;

    inArcs[13][15]=1;
    inArcs[13][17]=1;
    inArcs[13][61]=1;

    inArcs[14][18]=1;

    inArcs[15][20]=1;
    inArcs[15][23]=1;
    inArcs[15][60]=1;

    inArcs[16][19]=1;
    inArcs[16][21]=1;
    inArcs[16][61]=1;

    inArcs[17][22]=1;

    inArcs[18][24]=1;
    inArcs[18][27]=1;
    inArcs[18][60]=1;

    inArcs[19][23]=1;
    inArcs[19][25]=1;
    inArcs[19][61]=1;

    inArcs[20][26]=1;

    inArcs[21][28]=1;
    inArcs[21][31]=1;
    inArcs[21][60]=1;

    inArcs[22][27]=1;
    inArcs[22][29]=1;
    inArcs[22][61]=1;

    inArcs[23][30]=1;

    inArcs[24][32]=1;
    inArcs[24][35]=1;
    inArcs[24][60]=1;

    inArcs[25][31]=1;
    inArcs[25][33]=1;
    inArcs[25][61]=1;

    inArcs[26][34]=1;

    inArcs[27][36]=1;
    inArcs[27][39]=1;
    inArcs[27][60]=1;

    inArcs[28][35]=1;
    inArcs[28][37]=1;
    inArcs[28][61]=1;

    inArcs[29][38]=1;

    inArcs[30][40]=1;
    inArcs[30][43]=1;
    inArcs[30][60]=1;

    inArcs[31][39]=1;
    inArcs[31][41]=1;
    inArcs[31][61]=1;

    inArcs[32][42]=1;

    inArcs[33][44]=1;
    inArcs[33][47]=1;
    inArcs[33][60]=1;

    inArcs[34][43]=1;
    inArcs[34][45]=1;
    inArcs[34][61]=1;

    inArcs[35][46]=1;

    inArcs[36][48]=1;
    inArcs[36][51]=1;
    inArcs[36][60]=1;

    inArcs[37][47]=1;
    inArcs[37][49]=1;
    inArcs[37][61]=1;

    inArcs[38][50]=1;

    inArcs[39][52]=1;
    inArcs[39][55]=1;
    inArcs[39][60]=1;

    inArcs[40][51]=1;
    inArcs[40][53]=1;
    inArcs[40][61]=1;

    inArcs[41][54]=1;

    inArcs[42][56]=1;
    inArcs[42][59]=1;
    inArcs[42][60]=1;

    inArcs[43][55]=1;
    inArcs[43][57]=1;
    inArcs[43][61]=1;

    inArcs[44][58]=1;


    outArcs[0][1]=1;
    outArcs[0][61]=1;

    outArcs[1][2]=1;

    outArcs[2][0]=1;
    outArcs[2][3]=1;
    outArcs[2][59]=1;
    outArcs[2][60]=1;
    outArcs[2][62]=1;

    outArcs[3][5]=1;
    outArcs[3][61]=1;

    outArcs[4][6]=1;

    outArcs[5][3]=1;
    outArcs[5][4]=1;
    outArcs[5][7]=1;
    outArcs[5][60]=1;
    outArcs[5][62]=1;

    outArcs[6][9]=1;
    outArcs[6][61]=1;

    outArcs[7][10]=1;

    outArcs[8][7]=1;
    outArcs[8][8]=1;
    outArcs[8][11]=1;
    outArcs[8][60]=1;
    outArcs[8][62]=1;

    outArcs[9][13]=1;
    outArcs[9][61]=1;

    outArcs[10][14]=1;

    outArcs[11][11]=1;
    outArcs[11][12]=1;
    outArcs[11][15]=1;
    outArcs[11][60]=1;
    outArcs[11][62]=1;

    outArcs[12][17]=1;
    outArcs[12][61]=1;

    outArcs[13][18]=1;

    outArcs[14][15]=1;
    outArcs[14][16]=1;
    outArcs[14][19]=1;
    outArcs[14][60]=1;
    outArcs[14][62]=1;

    outArcs[15][21]=1;
    outArcs[15][61]=1;

    outArcs[16][22]=1;

    outArcs[17][19]=1;
    outArcs[17][20]=1;
    outArcs[17][23]=1;
    outArcs[17][60]=1;
    outArcs[17][62]=1;

    outArcs[18][25]=1;
    outArcs[18][61]=1;

    outArcs[19][26]=1;

    outArcs[20][23]=1;
    outArcs[20][24]=1;
    outArcs[20][27]=1;
    outArcs[20][60]=1;
    outArcs[20][62]=1;

    outArcs[21][29]=1;
    outArcs[21][61]=1;

    outArcs[22][30]=1;

    outArcs[23][27]=1;
    outArcs[23][28]=1;
    outArcs[23][31]=1;
    outArcs[23][60]=1;
    outArcs[23][62]=1;

    outArcs[24][33]=1;
    outArcs[24][61]=1;

    outArcs[25][34]=1;

    outArcs[26][31]=1;
    outArcs[26][32]=1;
    outArcs[26][35]=1;
    outArcs[26][60]=1;
    outArcs[26][62]=1;

    outArcs[27][37]=1;
    outArcs[27][61]=1;

    outArcs[28][38]=1;

    outArcs[29][35]=1;
    outArcs[29][36]=1;
    outArcs[29][39]=1;
    outArcs[29][60]=1;
    outArcs[29][62]=1;

    outArcs[30][41]=1;
    outArcs[30][61]=1;

    outArcs[31][42]=1;

    outArcs[32][39]=1;
    outArcs[32][40]=1;
    outArcs[32][43]=1;
    outArcs[32][60]=1;
    outArcs[32][62]=1;

    outArcs[33][45]=1;
    outArcs[33][61]=1;

    outArcs[34][46]=1;

    outArcs[35][43]=1;
    outArcs[35][44]=1;
    outArcs[35][47]=1;
    outArcs[35][60]=1;
    outArcs[35][62]=1;

    outArcs[36][49]=1;
    outArcs[36][61]=1;

    outArcs[37][50]=1;

    outArcs[38][47]=1;
    outArcs[38][48]=1;
    outArcs[38][51]=1;
    outArcs[38][60]=1;
    outArcs[38][62]=1;

    outArcs[39][53]=1;
    outArcs[39][61]=1;

    outArcs[40][54]=1;

    outArcs[41][51]=1;
    outArcs[41][52]=1;
    outArcs[41][55]=1;
    outArcs[41][60]=1;
    outArcs[41][62]=1;

    outArcs[42][57]=1;
    outArcs[42][61]=1;

    outArcs[43][58]=1;

    outArcs[44][55]=1;
    outArcs[44][56]=1;
    outArcs[44][59]=1;
    outArcs[44][60]=1;
    outArcs[44][62]=1;

    outArcs[45][63]=1;















































    Marking[0]=1;
    Marking[3]=1;
    Marking[4]=1;
    Marking[7]=1;
    Marking[8]=1;
    Marking[11]=1;
    Marking[12]=1;
    Marking[15]=1;
    Marking[16]=1;
    Marking[19]=1;
    Marking[20]=1;
    Marking[23]=1;
    Marking[24]=1;
    Marking[27]=1;
    Marking[28]=1;
    Marking[31]=1;
    Marking[32]=1;
    Marking[35]=1;
    Marking[36]=1;
    Marking[39]=1;
    Marking[40]=1;
    Marking[43]=1;
    Marking[44]=1;
    Marking[47]=1;
    Marking[48]=1;
    Marking[51]=1;
    Marking[52]=1;
    Marking[55]=1;
    Marking[56]=1;
    Marking[59]=1;
    Marking[60]=15;

   initMarking = Marking;

    vector <spn_trans> t(46);
    Transition = t;
    vector <spn_place> p(64);
    Place = p;
    Place[3].Id =3;
    Place[3].label =" Fork1";
    PlaceIndex[" Fork1"] =3;
    Place[39].Id =39;
    Place[39].label =" Fork10";
    PlaceIndex[" Fork10"] =39;
    Place[43].Id =43;
    Place[43].label =" Fork11";
    PlaceIndex[" Fork11"] =43;
    Place[47].Id =47;
    Place[47].label =" Fork12";
    PlaceIndex[" Fork12"] =47;
    Place[51].Id =51;
    Place[51].label =" Fork13";
    PlaceIndex[" Fork13"] =51;
    Place[55].Id =55;
    Place[55].label =" Fork14";
    PlaceIndex[" Fork14"] =55;
    Place[59].Id =59;
    Place[59].label =" Fork15";
    PlaceIndex[" Fork15"] =59;
    Place[7].Id =7;
    Place[7].label =" Fork2";
    PlaceIndex[" Fork2"] =7;
    Place[11].Id =11;
    Place[11].label =" Fork3";
    PlaceIndex[" Fork3"] =11;
    Place[15].Id =15;
    Place[15].label =" Fork4";
    PlaceIndex[" Fork4"] =15;
    Place[19].Id =19;
    Place[19].label =" Fork5";
    PlaceIndex[" Fork5"] =19;
    Place[23].Id =23;
    Place[23].label =" Fork6";
    PlaceIndex[" Fork6"] =23;
    Place[27].Id =27;
    Place[27].label =" Fork7";
    PlaceIndex[" Fork7"] =27;
    Place[31].Id =31;
    Place[31].label =" Fork8";
    PlaceIndex[" Fork8"] =31;
    Place[35].Id =35;
    Place[35].label =" Fork9";
    PlaceIndex[" Fork9"] =35;
    Place[36].Id =36;
    Place[36].label =" Philo10_Think";
    PlaceIndex[" Philo10_Think"] =36;
    Place[38].Id =38;
    Place[38].label =" Philo10_eat";
    PlaceIndex[" Philo10_eat"] =38;
    Place[37].Id =37;
    Place[37].label =" Philo10_fork";
    PlaceIndex[" Philo10_fork"] =37;
    Place[40].Id =40;
    Place[40].label =" Philo11_Think";
    PlaceIndex[" Philo11_Think"] =40;
    Place[42].Id =42;
    Place[42].label =" Philo11_eat";
    PlaceIndex[" Philo11_eat"] =42;
    Place[41].Id =41;
    Place[41].label =" Philo11_fork";
    PlaceIndex[" Philo11_fork"] =41;
    Place[44].Id =44;
    Place[44].label =" Philo12_Think";
    PlaceIndex[" Philo12_Think"] =44;
    Place[46].Id =46;
    Place[46].label =" Philo12_eat";
    PlaceIndex[" Philo12_eat"] =46;
    Place[45].Id =45;
    Place[45].label =" Philo12_fork";
    PlaceIndex[" Philo12_fork"] =45;
    Place[48].Id =48;
    Place[48].label =" Philo13_Think";
    PlaceIndex[" Philo13_Think"] =48;
    Place[50].Id =50;
    Place[50].label =" Philo13_eat";
    PlaceIndex[" Philo13_eat"] =50;
    Place[49].Id =49;
    Place[49].label =" Philo13_fork";
    PlaceIndex[" Philo13_fork"] =49;
    Place[52].Id =52;
    Place[52].label =" Philo14_Think";
    PlaceIndex[" Philo14_Think"] =52;
    Place[54].Id =54;
    Place[54].label =" Philo14_eat";
    PlaceIndex[" Philo14_eat"] =54;
    Place[53].Id =53;
    Place[53].label =" Philo14_fork";
    PlaceIndex[" Philo14_fork"] =53;
    Place[56].Id =56;
    Place[56].label =" Philo15_Think";
    PlaceIndex[" Philo15_Think"] =56;
    Place[58].Id =58;
    Place[58].label =" Philo15_eat";
    PlaceIndex[" Philo15_eat"] =58;
    Place[57].Id =57;
    Place[57].label =" Philo15_fork";
    PlaceIndex[" Philo15_fork"] =57;
    Place[0].Id =0;
    Place[0].label =" Philo1_Think";
    PlaceIndex[" Philo1_Think"] =0;
    Place[2].Id =2;
    Place[2].label =" Philo1_eat";
    PlaceIndex[" Philo1_eat"] =2;
    Place[1].Id =1;
    Place[1].label =" Philo1_fork";
    PlaceIndex[" Philo1_fork"] =1;
    Place[4].Id =4;
    Place[4].label =" Philo2_Think";
    PlaceIndex[" Philo2_Think"] =4;
    Place[6].Id =6;
    Place[6].label =" Philo2_eat";
    PlaceIndex[" Philo2_eat"] =6;
    Place[5].Id =5;
    Place[5].label =" Philo2_fork";
    PlaceIndex[" Philo2_fork"] =5;
    Place[8].Id =8;
    Place[8].label =" Philo3_Think";
    PlaceIndex[" Philo3_Think"] =8;
    Place[10].Id =10;
    Place[10].label =" Philo3_eat";
    PlaceIndex[" Philo3_eat"] =10;
    Place[9].Id =9;
    Place[9].label =" Philo3_fork";
    PlaceIndex[" Philo3_fork"] =9;
    Place[12].Id =12;
    Place[12].label =" Philo4_Think";
    PlaceIndex[" Philo4_Think"] =12;
    Place[14].Id =14;
    Place[14].label =" Philo4_eat";
    PlaceIndex[" Philo4_eat"] =14;
    Place[13].Id =13;
    Place[13].label =" Philo4_fork";
    PlaceIndex[" Philo4_fork"] =13;
    Place[16].Id =16;
    Place[16].label =" Philo5_Think";
    PlaceIndex[" Philo5_Think"] =16;
    Place[18].Id =18;
    Place[18].label =" Philo5_eat";
    PlaceIndex[" Philo5_eat"] =18;
    Place[17].Id =17;
    Place[17].label =" Philo5_fork";
    PlaceIndex[" Philo5_fork"] =17;
    Place[20].Id =20;
    Place[20].label =" Philo6_Think";
    PlaceIndex[" Philo6_Think"] =20;
    Place[22].Id =22;
    Place[22].label =" Philo6_eat";
    PlaceIndex[" Philo6_eat"] =22;
    Place[21].Id =21;
    Place[21].label =" Philo6_fork";
    PlaceIndex[" Philo6_fork"] =21;
    Place[24].Id =24;
    Place[24].label =" Philo7_Think";
    PlaceIndex[" Philo7_Think"] =24;
    Place[26].Id =26;
    Place[26].label =" Philo7_eat";
    PlaceIndex[" Philo7_eat"] =26;
    Place[25].Id =25;
    Place[25].label =" Philo7_fork";
    PlaceIndex[" Philo7_fork"] =25;
    Place[28].Id =28;
    Place[28].label =" Philo8_Think";
    PlaceIndex[" Philo8_Think"] =28;
    Place[30].Id =30;
    Place[30].label =" Philo8_eat";
    PlaceIndex[" Philo8_eat"] =30;
    Place[29].Id =29;
    Place[29].label =" Philo8_fork";
    PlaceIndex[" Philo8_fork"] =29;
    Place[32].Id =32;
    Place[32].label =" Philo9_Think";
    PlaceIndex[" Philo9_Think"] =32;
    Place[34].Id =34;
    Place[34].label =" Philo9_eat";
    PlaceIndex[" Philo9_eat"] =34;
    Place[33].Id =33;
    Place[33].label =" Philo9_fork";
    PlaceIndex[" Philo9_fork"] =33;
    Place[63].Id =63;
    Place[63].label =" Puit";
    PlaceIndex[" Puit"] =63;
    Place[62].Id =62;
    Place[62].label =" nServ";
    PlaceIndex[" nServ"] =62;
    Place[60].Id =60;
    Place[60].label =" nThink";
    PlaceIndex[" nThink"] =60;
    Place[61].Id =61;
    Place[61].label =" nWait";
    PlaceIndex[" nWait"] =61;
    Transition[29].Id =29;
    Transition[29].label ="Philo10_eat";
    TransitionIndex["Philo10_eat"]=29;
    Transition[27].Id =27;
    Transition[27].label ="Philo10_fork1";
    TransitionIndex["Philo10_fork1"]=27;
    Transition[28].Id =28;
    Transition[28].label ="Philo10_fork2";
    TransitionIndex["Philo10_fork2"]=28;
    Transition[32].Id =32;
    Transition[32].label ="Philo11_eat";
    TransitionIndex["Philo11_eat"]=32;
    Transition[30].Id =30;
    Transition[30].label ="Philo11_fork1";
    TransitionIndex["Philo11_fork1"]=30;
    Transition[31].Id =31;
    Transition[31].label ="Philo11_fork2";
    TransitionIndex["Philo11_fork2"]=31;
    Transition[35].Id =35;
    Transition[35].label ="Philo12_eat";
    TransitionIndex["Philo12_eat"]=35;
    Transition[33].Id =33;
    Transition[33].label ="Philo12_fork1";
    TransitionIndex["Philo12_fork1"]=33;
    Transition[34].Id =34;
    Transition[34].label ="Philo12_fork2";
    TransitionIndex["Philo12_fork2"]=34;
    Transition[38].Id =38;
    Transition[38].label ="Philo13_eat";
    TransitionIndex["Philo13_eat"]=38;
    Transition[36].Id =36;
    Transition[36].label ="Philo13_fork1";
    TransitionIndex["Philo13_fork1"]=36;
    Transition[37].Id =37;
    Transition[37].label ="Philo13_fork2";
    TransitionIndex["Philo13_fork2"]=37;
    Transition[41].Id =41;
    Transition[41].label ="Philo14_eat";
    TransitionIndex["Philo14_eat"]=41;
    Transition[39].Id =39;
    Transition[39].label ="Philo14_fork1";
    TransitionIndex["Philo14_fork1"]=39;
    Transition[40].Id =40;
    Transition[40].label ="Philo14_fork2";
    TransitionIndex["Philo14_fork2"]=40;
    Transition[44].Id =44;
    Transition[44].label ="Philo15_eat";
    TransitionIndex["Philo15_eat"]=44;
    Transition[42].Id =42;
    Transition[42].label ="Philo15_fork1";
    TransitionIndex["Philo15_fork1"]=42;
    Transition[43].Id =43;
    Transition[43].label ="Philo15_fork2";
    TransitionIndex["Philo15_fork2"]=43;
    Transition[2].Id =2;
    Transition[2].label ="Philo1_eat";
    TransitionIndex["Philo1_eat"]=2;
    Transition[0].Id =0;
    Transition[0].label ="Philo1_fork1";
    TransitionIndex["Philo1_fork1"]=0;
    Transition[1].Id =1;
    Transition[1].label ="Philo1_fork2";
    TransitionIndex["Philo1_fork2"]=1;
    Transition[5].Id =5;
    Transition[5].label ="Philo2_eat";
    TransitionIndex["Philo2_eat"]=5;
    Transition[3].Id =3;
    Transition[3].label ="Philo2_fork1";
    TransitionIndex["Philo2_fork1"]=3;
    Transition[4].Id =4;
    Transition[4].label ="Philo2_fork2";
    TransitionIndex["Philo2_fork2"]=4;
    Transition[8].Id =8;
    Transition[8].label ="Philo3_eat";
    TransitionIndex["Philo3_eat"]=8;
    Transition[6].Id =6;
    Transition[6].label ="Philo3_fork1";
    TransitionIndex["Philo3_fork1"]=6;
    Transition[7].Id =7;
    Transition[7].label ="Philo3_fork2";
    TransitionIndex["Philo3_fork2"]=7;
    Transition[11].Id =11;
    Transition[11].label ="Philo4_eat";
    TransitionIndex["Philo4_eat"]=11;
    Transition[9].Id =9;
    Transition[9].label ="Philo4_fork1";
    TransitionIndex["Philo4_fork1"]=9;
    Transition[10].Id =10;
    Transition[10].label ="Philo4_fork2";
    TransitionIndex["Philo4_fork2"]=10;
    Transition[14].Id =14;
    Transition[14].label ="Philo5_eat";
    TransitionIndex["Philo5_eat"]=14;
    Transition[12].Id =12;
    Transition[12].label ="Philo5_fork1";
    TransitionIndex["Philo5_fork1"]=12;
    Transition[13].Id =13;
    Transition[13].label ="Philo5_fork2";
    TransitionIndex["Philo5_fork2"]=13;
    Transition[17].Id =17;
    Transition[17].label ="Philo6_eat";
    TransitionIndex["Philo6_eat"]=17;
    Transition[15].Id =15;
    Transition[15].label ="Philo6_fork1";
    TransitionIndex["Philo6_fork1"]=15;
    Transition[16].Id =16;
    Transition[16].label ="Philo6_fork2";
    TransitionIndex["Philo6_fork2"]=16;
    Transition[20].Id =20;
    Transition[20].label ="Philo7_eat";
    TransitionIndex["Philo7_eat"]=20;
    Transition[18].Id =18;
    Transition[18].label ="Philo7_fork1";
    TransitionIndex["Philo7_fork1"]=18;
    Transition[19].Id =19;
    Transition[19].label ="Philo7_fork2";
    TransitionIndex["Philo7_fork2"]=19;
    Transition[23].Id =23;
    Transition[23].label ="Philo8_eat";
    TransitionIndex["Philo8_eat"]=23;
    Transition[21].Id =21;
    Transition[21].label ="Philo8_fork1";
    TransitionIndex["Philo8_fork1"]=21;
    Transition[22].Id =22;
    Transition[22].label ="Philo8_fork2";
    TransitionIndex["Philo8_fork2"]=22;
    Transition[26].Id =26;
    Transition[26].label ="Philo9_eat";
    TransitionIndex["Philo9_eat"]=26;
    Transition[24].Id =24;
    Transition[24].label ="Philo9_fork1";
    TransitionIndex["Philo9_fork1"]=24;
    Transition[25].Id =25;
    Transition[25].label ="Philo9_fork2";
    TransitionIndex["Philo9_fork2"]=25;
    Transition[45].Id =45;
    Transition[45].label ="Puittrans";
    TransitionIndex["Puittrans"]=45;
    Transition[0].transType = Timed;
    Transition[0].DistType = "EXPONENTIAL";
    Transition[0].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[0].priority = "1";
    Transition[0].MarkingDependent = 1;
    Transition[0].weight = "1 ";

    Transition[1].transType = Timed;
    Transition[1].DistType = "EXPONENTIAL";
    Transition[1].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[1].priority = "1";
    Transition[1].MarkingDependent = 1;
    Transition[1].weight = "1 ";

    Transition[2].transType = Timed;
    Transition[2].DistType = "EXPONENTIAL";
    Transition[2].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[2].priority = "1";
    Transition[2].MarkingDependent = 1;
    Transition[2].weight = "1 ";

    Transition[3].transType = Timed;
    Transition[3].DistType = "EXPONENTIAL";
    Transition[3].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[3].priority = "1";
    Transition[3].MarkingDependent = 1;
    Transition[3].weight = "1 ";

    Transition[4].transType = Timed;
    Transition[4].DistType = "EXPONENTIAL";
    Transition[4].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[4].priority = "1";
    Transition[4].MarkingDependent = 1;
    Transition[4].weight = "1 ";

    Transition[5].transType = Timed;
    Transition[5].DistType = "EXPONENTIAL";
    Transition[5].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[5].priority = "1";
    Transition[5].MarkingDependent = 1;
    Transition[5].weight = "1 ";

    Transition[6].transType = Timed;
    Transition[6].DistType = "EXPONENTIAL";
    Transition[6].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[6].priority = "1";
    Transition[6].MarkingDependent = 1;
    Transition[6].weight = "1 ";

    Transition[7].transType = Timed;
    Transition[7].DistType = "EXPONENTIAL";
    Transition[7].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[7].priority = "1";
    Transition[7].MarkingDependent = 1;
    Transition[7].weight = "1 ";

    Transition[8].transType = Timed;
    Transition[8].DistType = "EXPONENTIAL";
    Transition[8].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[8].priority = "1";
    Transition[8].MarkingDependent = 1;
    Transition[8].weight = "1 ";

    Transition[9].transType = Timed;
    Transition[9].DistType = "EXPONENTIAL";
    Transition[9].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[9].priority = "1";
    Transition[9].MarkingDependent = 1;
    Transition[9].weight = "1 ";

    Transition[10].transType = Timed;
    Transition[10].DistType = "EXPONENTIAL";
    Transition[10].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[10].priority = "1";
    Transition[10].MarkingDependent = 1;
    Transition[10].weight = "1 ";

    Transition[11].transType = Timed;
    Transition[11].DistType = "EXPONENTIAL";
    Transition[11].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[11].priority = "1";
    Transition[11].MarkingDependent = 1;
    Transition[11].weight = "1 ";

    Transition[12].transType = Timed;
    Transition[12].DistType = "EXPONENTIAL";
    Transition[12].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[12].priority = "1";
    Transition[12].MarkingDependent = 1;
    Transition[12].weight = "1 ";

    Transition[13].transType = Timed;
    Transition[13].DistType = "EXPONENTIAL";
    Transition[13].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[13].priority = "1";
    Transition[13].MarkingDependent = 1;
    Transition[13].weight = "1 ";

    Transition[14].transType = Timed;
    Transition[14].DistType = "EXPONENTIAL";
    Transition[14].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[14].priority = "1";
    Transition[14].MarkingDependent = 1;
    Transition[14].weight = "1 ";

    Transition[15].transType = Timed;
    Transition[15].DistType = "EXPONENTIAL";
    Transition[15].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[15].priority = "1";
    Transition[15].MarkingDependent = 1;
    Transition[15].weight = "1 ";

    Transition[16].transType = Timed;
    Transition[16].DistType = "EXPONENTIAL";
    Transition[16].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[16].priority = "1";
    Transition[16].MarkingDependent = 1;
    Transition[16].weight = "1 ";

    Transition[17].transType = Timed;
    Transition[17].DistType = "EXPONENTIAL";
    Transition[17].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[17].priority = "1";
    Transition[17].MarkingDependent = 1;
    Transition[17].weight = "1 ";

    Transition[18].transType = Timed;
    Transition[18].DistType = "EXPONENTIAL";
    Transition[18].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[18].priority = "1";
    Transition[18].MarkingDependent = 1;
    Transition[18].weight = "1 ";

    Transition[19].transType = Timed;
    Transition[19].DistType = "EXPONENTIAL";
    Transition[19].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[19].priority = "1";
    Transition[19].MarkingDependent = 1;
    Transition[19].weight = "1 ";

    Transition[20].transType = Timed;
    Transition[20].DistType = "EXPONENTIAL";
    Transition[20].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[20].priority = "1";
    Transition[20].MarkingDependent = 1;
    Transition[20].weight = "1 ";

    Transition[21].transType = Timed;
    Transition[21].DistType = "EXPONENTIAL";
    Transition[21].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[21].priority = "1";
    Transition[21].MarkingDependent = 1;
    Transition[21].weight = "1 ";

    Transition[22].transType = Timed;
    Transition[22].DistType = "EXPONENTIAL";
    Transition[22].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[22].priority = "1";
    Transition[22].MarkingDependent = 1;
    Transition[22].weight = "1 ";

    Transition[23].transType = Timed;
    Transition[23].DistType = "EXPONENTIAL";
    Transition[23].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[23].priority = "1";
    Transition[23].MarkingDependent = 1;
    Transition[23].weight = "1 ";

    Transition[24].transType = Timed;
    Transition[24].DistType = "EXPONENTIAL";
    Transition[24].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[24].priority = "1";
    Transition[24].MarkingDependent = 1;
    Transition[24].weight = "1 ";

    Transition[25].transType = Timed;
    Transition[25].DistType = "EXPONENTIAL";
    Transition[25].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[25].priority = "1";
    Transition[25].MarkingDependent = 1;
    Transition[25].weight = "1 ";

    Transition[26].transType = Timed;
    Transition[26].DistType = "EXPONENTIAL";
    Transition[26].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[26].priority = "1";
    Transition[26].MarkingDependent = 1;
    Transition[26].weight = "1 ";

    Transition[27].transType = Timed;
    Transition[27].DistType = "EXPONENTIAL";
    Transition[27].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[27].priority = "1";
    Transition[27].MarkingDependent = 1;
    Transition[27].weight = "1 ";

    Transition[28].transType = Timed;
    Transition[28].DistType = "EXPONENTIAL";
    Transition[28].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[28].priority = "1";
    Transition[28].MarkingDependent = 1;
    Transition[28].weight = "1 ";

    Transition[29].transType = Timed;
    Transition[29].DistType = "EXPONENTIAL";
    Transition[29].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[29].priority = "1";
    Transition[29].MarkingDependent = 1;
    Transition[29].weight = "1 ";

    Transition[30].transType = Timed;
    Transition[30].DistType = "EXPONENTIAL";
    Transition[30].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[30].priority = "1";
    Transition[30].MarkingDependent = 1;
    Transition[30].weight = "1 ";

    Transition[31].transType = Timed;
    Transition[31].DistType = "EXPONENTIAL";
    Transition[31].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[31].priority = "1";
    Transition[31].MarkingDependent = 1;
    Transition[31].weight = "1 ";

    Transition[32].transType = Timed;
    Transition[32].DistType = "EXPONENTIAL";
    Transition[32].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[32].priority = "1";
    Transition[32].MarkingDependent = 1;
    Transition[32].weight = "1 ";

    Transition[33].transType = Timed;
    Transition[33].DistType = "EXPONENTIAL";
    Transition[33].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[33].priority = "1";
    Transition[33].MarkingDependent = 1;
    Transition[33].weight = "1 ";

    Transition[34].transType = Timed;
    Transition[34].DistType = "EXPONENTIAL";
    Transition[34].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[34].priority = "1";
    Transition[34].MarkingDependent = 1;
    Transition[34].weight = "1 ";

    Transition[35].transType = Timed;
    Transition[35].DistType = "EXPONENTIAL";
    Transition[35].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[35].priority = "1";
    Transition[35].MarkingDependent = 1;
    Transition[35].weight = "1 ";

    Transition[36].transType = Timed;
    Transition[36].DistType = "EXPONENTIAL";
    Transition[36].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[36].priority = "1";
    Transition[36].MarkingDependent = 1;
    Transition[36].weight = "1 ";

    Transition[37].transType = Timed;
    Transition[37].DistType = "EXPONENTIAL";
    Transition[37].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[37].priority = "1";
    Transition[37].MarkingDependent = 1;
    Transition[37].weight = "1 ";

    Transition[38].transType = Timed;
    Transition[38].DistType = "EXPONENTIAL";
    Transition[38].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[38].priority = "1";
    Transition[38].MarkingDependent = 1;
    Transition[38].weight = "1 ";

    Transition[39].transType = Timed;
    Transition[39].DistType = "EXPONENTIAL";
    Transition[39].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[39].priority = "1";
    Transition[39].MarkingDependent = 1;
    Transition[39].weight = "1 ";

    Transition[40].transType = Timed;
    Transition[40].DistType = "EXPONENTIAL";
    Transition[40].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[40].priority = "1";
    Transition[40].MarkingDependent = 1;
    Transition[40].weight = "1 ";

    Transition[41].transType = Timed;
    Transition[41].DistType = "EXPONENTIAL";
    Transition[41].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[41].priority = "1";
    Transition[41].MarkingDependent = 1;
    Transition[41].weight = "1 ";

    Transition[42].transType = Timed;
    Transition[42].DistType = "EXPONENTIAL";
    Transition[42].DistParams.push_back(" 1 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[42].priority = "1";
    Transition[42].MarkingDependent = 1;
    Transition[42].weight = "1 ";

    Transition[43].transType = Timed;
    Transition[43].DistType = "EXPONENTIAL";
    Transition[43].DistParams.push_back(" 100 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[43].priority = "1";
    Transition[43].MarkingDependent = 1;
    Transition[43].weight = "1 ";

    Transition[44].transType = Timed;
    Transition[44].DistType = "EXPONENTIAL";
    Transition[44].DistParams.push_back(" 10 * ( 1 + 0 *  Marking[ 0 ]  )" );
    Transition[44].priority = "1";
    Transition[44].MarkingDependent = 1;
    Transition[44].weight = "1 ";

    Transition[45].transType = Timed;
    Transition[45].DistType = "EXPONENTIAL";
    Transition[45].DistParams.push_back(" 0 *  Marking[ 0 ] " );
    Transition[45].priority = "1";
    Transition[45].MarkingDependent = 1;
    Transition[45].weight = "1 ";

    vector < vector <int> > vec(46);
    PredT = vec;
    PredT[0].push_back(0);
    PredT[0].push_back(3);
    PredT[0].push_back(60);
    PredT[1].push_back(1);
    PredT[1].push_back(59);
    PredT[1].push_back(61);
    PredT[2].push_back(2);
    PredT[3].push_back(4);
    PredT[3].push_back(7);
    PredT[3].push_back(60);
    PredT[4].push_back(3);
    PredT[4].push_back(5);
    PredT[4].push_back(61);
    PredT[5].push_back(6);
    PredT[6].push_back(8);
    PredT[6].push_back(11);
    PredT[6].push_back(60);
    PredT[7].push_back(7);
    PredT[7].push_back(9);
    PredT[7].push_back(61);
    PredT[8].push_back(10);
    PredT[9].push_back(12);
    PredT[9].push_back(15);
    PredT[9].push_back(60);
    PredT[10].push_back(11);
    PredT[10].push_back(13);
    PredT[10].push_back(61);
    PredT[11].push_back(14);
    PredT[12].push_back(16);
    PredT[12].push_back(19);
    PredT[12].push_back(60);
    PredT[13].push_back(15);
    PredT[13].push_back(17);
    PredT[13].push_back(61);
    PredT[14].push_back(18);
    PredT[15].push_back(20);
    PredT[15].push_back(23);
    PredT[15].push_back(60);
    PredT[16].push_back(19);
    PredT[16].push_back(21);
    PredT[16].push_back(61);
    PredT[17].push_back(22);
    PredT[18].push_back(24);
    PredT[18].push_back(27);
    PredT[18].push_back(60);
    PredT[19].push_back(23);
    PredT[19].push_back(25);
    PredT[19].push_back(61);
    PredT[20].push_back(26);
    PredT[21].push_back(28);
    PredT[21].push_back(31);
    PredT[21].push_back(60);
    PredT[22].push_back(27);
    PredT[22].push_back(29);
    PredT[22].push_back(61);
    PredT[23].push_back(30);
    PredT[24].push_back(32);
    PredT[24].push_back(35);
    PredT[24].push_back(60);
    PredT[25].push_back(31);
    PredT[25].push_back(33);
    PredT[25].push_back(61);
    PredT[26].push_back(34);
    PredT[27].push_back(36);
    PredT[27].push_back(39);
    PredT[27].push_back(60);
    PredT[28].push_back(35);
    PredT[28].push_back(37);
    PredT[28].push_back(61);
    PredT[29].push_back(38);
    PredT[30].push_back(40);
    PredT[30].push_back(43);
    PredT[30].push_back(60);
    PredT[31].push_back(39);
    PredT[31].push_back(41);
    PredT[31].push_back(61);
    PredT[32].push_back(42);
    PredT[33].push_back(44);
    PredT[33].push_back(47);
    PredT[33].push_back(60);
    PredT[34].push_back(43);
    PredT[34].push_back(45);
    PredT[34].push_back(61);
    PredT[35].push_back(46);
    PredT[36].push_back(48);
    PredT[36].push_back(51);
    PredT[36].push_back(60);
    PredT[37].push_back(47);
    PredT[37].push_back(49);
    PredT[37].push_back(61);
    PredT[38].push_back(50);
    PredT[39].push_back(52);
    PredT[39].push_back(55);
    PredT[39].push_back(60);
    PredT[40].push_back(51);
    PredT[40].push_back(53);
    PredT[40].push_back(61);
    PredT[41].push_back(54);
    PredT[42].push_back(56);
    PredT[42].push_back(59);
    PredT[42].push_back(60);
    PredT[43].push_back(55);
    PredT[43].push_back(57);
    PredT[43].push_back(61);
    PredT[44].push_back(58);
    EnabledDisabledTr();
vector <double> Rate_Table_init (tr);
Rate_Table = Rate_Table_init;
Origine_Rate_Table = Rate_Table_init;
}

bool SPN::IsEnabled(int t){
    switch(t){
     case 0:
       return IsEnabled_t0();
       break;
     case 1:
       return IsEnabled_t1();
       break;
     case 2:
       return IsEnabled_t2();
       break;
     case 3:
       return IsEnabled_t3();
       break;
     case 4:
       return IsEnabled_t4();
       break;
     case 5:
       return IsEnabled_t5();
       break;
     case 6:
       return IsEnabled_t6();
       break;
     case 7:
       return IsEnabled_t7();
       break;
     case 8:
       return IsEnabled_t8();
       break;
     case 9:
       return IsEnabled_t9();
       break;
     case 10:
       return IsEnabled_t10();
       break;
     case 11:
       return IsEnabled_t11();
       break;
     case 12:
       return IsEnabled_t12();
       break;
     case 13:
       return IsEnabled_t13();
       break;
     case 14:
       return IsEnabled_t14();
       break;
     case 15:
       return IsEnabled_t15();
       break;
     case 16:
       return IsEnabled_t16();
       break;
     case 17:
       return IsEnabled_t17();
       break;
     case 18:
       return IsEnabled_t18();
       break;
     case 19:
       return IsEnabled_t19();
       break;
     case 20:
       return IsEnabled_t20();
       break;
     case 21:
       return IsEnabled_t21();
       break;
     case 22:
       return IsEnabled_t22();
       break;
     case 23:
       return IsEnabled_t23();
       break;
     case 24:
       return IsEnabled_t24();
       break;
     case 25:
       return IsEnabled_t25();
       break;
     case 26:
       return IsEnabled_t26();
       break;
     case 27:
       return IsEnabled_t27();
       break;
     case 28:
       return IsEnabled_t28();
       break;
     case 29:
       return IsEnabled_t29();
       break;
     case 30:
       return IsEnabled_t30();
       break;
     case 31:
       return IsEnabled_t31();
       break;
     case 32:
       return IsEnabled_t32();
       break;
     case 33:
       return IsEnabled_t33();
       break;
     case 34:
       return IsEnabled_t34();
       break;
     case 35:
       return IsEnabled_t35();
       break;
     case 36:
       return IsEnabled_t36();
       break;
     case 37:
       return IsEnabled_t37();
       break;
     case 38:
       return IsEnabled_t38();
       break;
     case 39:
       return IsEnabled_t39();
       break;
     case 40:
       return IsEnabled_t40();
       break;
     case 41:
       return IsEnabled_t41();
       break;
     case 42:
       return IsEnabled_t42();
       break;
     case 43:
       return IsEnabled_t43();
       break;
     case 44:
       return IsEnabled_t44();
       break;
     case 45:
       return IsEnabled_t45();
       break;
   }
}

bool SPN::IsEnabled_t0() {
    if (Marking[0] < 1) return false;
    if (Marking[3] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t1() {
    if (Marking[1] < 1) return false;
    if (Marking[59] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t2() {
    if (Marking[2] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t3() {
    if (Marking[4] < 1) return false;
    if (Marking[7] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t4() {
    if (Marking[3] < 1) return false;
    if (Marking[5] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t5() {
    if (Marking[6] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t6() {
    if (Marking[8] < 1) return false;
    if (Marking[11] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t7() {
    if (Marking[7] < 1) return false;
    if (Marking[9] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t8() {
    if (Marking[10] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t9() {
    if (Marking[12] < 1) return false;
    if (Marking[15] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t10() {
    if (Marking[11] < 1) return false;
    if (Marking[13] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t11() {
    if (Marking[14] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t12() {
    if (Marking[16] < 1) return false;
    if (Marking[19] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t13() {
    if (Marking[15] < 1) return false;
    if (Marking[17] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t14() {
    if (Marking[18] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t15() {
    if (Marking[20] < 1) return false;
    if (Marking[23] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t16() {
    if (Marking[19] < 1) return false;
    if (Marking[21] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t17() {
    if (Marking[22] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t18() {
    if (Marking[24] < 1) return false;
    if (Marking[27] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t19() {
    if (Marking[23] < 1) return false;
    if (Marking[25] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t20() {
    if (Marking[26] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t21() {
    if (Marking[28] < 1) return false;
    if (Marking[31] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t22() {
    if (Marking[27] < 1) return false;
    if (Marking[29] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t23() {
    if (Marking[30] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t24() {
    if (Marking[32] < 1) return false;
    if (Marking[35] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t25() {
    if (Marking[31] < 1) return false;
    if (Marking[33] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t26() {
    if (Marking[34] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t27() {
    if (Marking[36] < 1) return false;
    if (Marking[39] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t28() {
    if (Marking[35] < 1) return false;
    if (Marking[37] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t29() {
    if (Marking[38] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t30() {
    if (Marking[40] < 1) return false;
    if (Marking[43] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t31() {
    if (Marking[39] < 1) return false;
    if (Marking[41] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t32() {
    if (Marking[42] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t33() {
    if (Marking[44] < 1) return false;
    if (Marking[47] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t34() {
    if (Marking[43] < 1) return false;
    if (Marking[45] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t35() {
    if (Marking[46] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t36() {
    if (Marking[48] < 1) return false;
    if (Marking[51] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t37() {
    if (Marking[47] < 1) return false;
    if (Marking[49] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t38() {
    if (Marking[50] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t39() {
    if (Marking[52] < 1) return false;
    if (Marking[55] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t40() {
    if (Marking[51] < 1) return false;
    if (Marking[53] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t41() {
    if (Marking[54] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t42() {
    if (Marking[56] < 1) return false;
    if (Marking[59] < 1) return false;
    if (Marking[60] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t43() {
    if (Marking[55] < 1) return false;
    if (Marking[57] < 1) return false;
    if (Marking[61] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t44() {
    if (Marking[58] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t45() {
    return true;
}

void SPN::fire(int t){
   switch(t){
     case 0: {
       fire_t0();
       break;
     } 
     case 1: {
       fire_t1();
       break;
     } 
     case 2: {
       fire_t2();
       break;
     } 
     case 3: {
       fire_t3();
       break;
     } 
     case 4: {
       fire_t4();
       break;
     } 
     case 5: {
       fire_t5();
       break;
     } 
     case 6: {
       fire_t6();
       break;
     } 
     case 7: {
       fire_t7();
       break;
     } 
     case 8: {
       fire_t8();
       break;
     } 
     case 9: {
       fire_t9();
       break;
     } 
     case 10: {
       fire_t10();
       break;
     } 
     case 11: {
       fire_t11();
       break;
     } 
     case 12: {
       fire_t12();
       break;
     } 
     case 13: {
       fire_t13();
       break;
     } 
     case 14: {
       fire_t14();
       break;
     } 
     case 15: {
       fire_t15();
       break;
     } 
     case 16: {
       fire_t16();
       break;
     } 
     case 17: {
       fire_t17();
       break;
     } 
     case 18: {
       fire_t18();
       break;
     } 
     case 19: {
       fire_t19();
       break;
     } 
     case 20: {
       fire_t20();
       break;
     } 
     case 21: {
       fire_t21();
       break;
     } 
     case 22: {
       fire_t22();
       break;
     } 
     case 23: {
       fire_t23();
       break;
     } 
     case 24: {
       fire_t24();
       break;
     } 
     case 25: {
       fire_t25();
       break;
     } 
     case 26: {
       fire_t26();
       break;
     } 
     case 27: {
       fire_t27();
       break;
     } 
     case 28: {
       fire_t28();
       break;
     } 
     case 29: {
       fire_t29();
       break;
     } 
     case 30: {
       fire_t30();
       break;
     } 
     case 31: {
       fire_t31();
       break;
     } 
     case 32: {
       fire_t32();
       break;
     } 
     case 33: {
       fire_t33();
       break;
     } 
     case 34: {
       fire_t34();
       break;
     } 
     case 35: {
       fire_t35();
       break;
     } 
     case 36: {
       fire_t36();
       break;
     } 
     case 37: {
       fire_t37();
       break;
     } 
     case 38: {
       fire_t38();
       break;
     } 
     case 39: {
       fire_t39();
       break;
     } 
     case 40: {
       fire_t40();
       break;
     } 
     case 41: {
       fire_t41();
       break;
     } 
     case 42: {
       fire_t42();
       break;
     } 
     case 43: {
       fire_t43();
       break;
     } 
     case 44: {
       fire_t44();
       break;
     } 
     case 45: {
       fire_t45();
       break;
     } 
   }
}

void SPN::fire_t0() {
    Marking[0] -= 1;
    Marking[1] += 1;
    Marking[3] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t1() {
    Marking[1] -= 1;
    Marking[2] += 1;
    Marking[59] -= 1;
    Marking[61] -= 1;
}

void SPN::fire_t2() {
    Marking[0] += 1;
    Marking[2] -= 1;
    Marking[3] += 1;
    Marking[59] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t3() {
    Marking[4] -= 1;
    Marking[5] += 1;
    Marking[7] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t4() {
    Marking[3] -= 1;
    Marking[5] -= 1;
    Marking[6] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t5() {
    Marking[3] += 1;
    Marking[4] += 1;
    Marking[6] -= 1;
    Marking[7] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t6() {
    Marking[8] -= 1;
    Marking[9] += 1;
    Marking[11] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t7() {
    Marking[7] -= 1;
    Marking[9] -= 1;
    Marking[10] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t8() {
    Marking[7] += 1;
    Marking[8] += 1;
    Marking[10] -= 1;
    Marking[11] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t9() {
    Marking[12] -= 1;
    Marking[13] += 1;
    Marking[15] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t10() {
    Marking[11] -= 1;
    Marking[13] -= 1;
    Marking[14] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t11() {
    Marking[11] += 1;
    Marking[12] += 1;
    Marking[14] -= 1;
    Marking[15] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t12() {
    Marking[16] -= 1;
    Marking[17] += 1;
    Marking[19] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t13() {
    Marking[15] -= 1;
    Marking[17] -= 1;
    Marking[18] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t14() {
    Marking[15] += 1;
    Marking[16] += 1;
    Marking[18] -= 1;
    Marking[19] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t15() {
    Marking[20] -= 1;
    Marking[21] += 1;
    Marking[23] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t16() {
    Marking[19] -= 1;
    Marking[21] -= 1;
    Marking[22] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t17() {
    Marking[19] += 1;
    Marking[20] += 1;
    Marking[22] -= 1;
    Marking[23] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t18() {
    Marking[24] -= 1;
    Marking[25] += 1;
    Marking[27] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t19() {
    Marking[23] -= 1;
    Marking[25] -= 1;
    Marking[26] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t20() {
    Marking[23] += 1;
    Marking[24] += 1;
    Marking[26] -= 1;
    Marking[27] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t21() {
    Marking[28] -= 1;
    Marking[29] += 1;
    Marking[31] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t22() {
    Marking[27] -= 1;
    Marking[29] -= 1;
    Marking[30] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t23() {
    Marking[27] += 1;
    Marking[28] += 1;
    Marking[30] -= 1;
    Marking[31] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t24() {
    Marking[32] -= 1;
    Marking[33] += 1;
    Marking[35] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t25() {
    Marking[31] -= 1;
    Marking[33] -= 1;
    Marking[34] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t26() {
    Marking[31] += 1;
    Marking[32] += 1;
    Marking[34] -= 1;
    Marking[35] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t27() {
    Marking[36] -= 1;
    Marking[37] += 1;
    Marking[39] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t28() {
    Marking[35] -= 1;
    Marking[37] -= 1;
    Marking[38] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t29() {
    Marking[35] += 1;
    Marking[36] += 1;
    Marking[38] -= 1;
    Marking[39] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t30() {
    Marking[40] -= 1;
    Marking[41] += 1;
    Marking[43] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t31() {
    Marking[39] -= 1;
    Marking[41] -= 1;
    Marking[42] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t32() {
    Marking[39] += 1;
    Marking[40] += 1;
    Marking[42] -= 1;
    Marking[43] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t33() {
    Marking[44] -= 1;
    Marking[45] += 1;
    Marking[47] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t34() {
    Marking[43] -= 1;
    Marking[45] -= 1;
    Marking[46] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t35() {
    Marking[43] += 1;
    Marking[44] += 1;
    Marking[46] -= 1;
    Marking[47] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t36() {
    Marking[48] -= 1;
    Marking[49] += 1;
    Marking[51] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t37() {
    Marking[47] -= 1;
    Marking[49] -= 1;
    Marking[50] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t38() {
    Marking[47] += 1;
    Marking[48] += 1;
    Marking[50] -= 1;
    Marking[51] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t39() {
    Marking[52] -= 1;
    Marking[53] += 1;
    Marking[55] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t40() {
    Marking[51] -= 1;
    Marking[53] -= 1;
    Marking[54] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t41() {
    Marking[51] += 1;
    Marking[52] += 1;
    Marking[54] -= 1;
    Marking[55] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t42() {
    Marking[56] -= 1;
    Marking[57] += 1;
    Marking[59] -= 1;
    Marking[60] -= 1;
    Marking[61] += 1;
}

void SPN::fire_t43() {
    Marking[55] -= 1;
    Marking[57] -= 1;
    Marking[58] += 1;
    Marking[61] -= 1;
}

void SPN::fire_t44() {
    Marking[55] += 1;
    Marking[56] += 1;
    Marking[58] -= 1;
    Marking[59] += 1;
    Marking[60] += 1;
    Marking[62] += 1;
}

void SPN::fire_t45() {
    Marking[63] += 1;
}

vector<double> SPN::GetDistParameters(int t){
   vector<double> P(2);
   double origin_rate = (SPN::GetDistParametersOrigin(t))[0];
   P[0]= ComputeDistr(Marking,t,gammaprob,origin_rate,Origine_Rate_Sum);
   P[1]= origin_rate;
   return P;
}
 
vector<double> SPN::GetDistParametersOrigin(int t){
   switch(t){
     case 0: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 1: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 2: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 3: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 4: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 5: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 6: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 7: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 8: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 9: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 10: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 11: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 12: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 13: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 14: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 15: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 16: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 17: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 18: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 19: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 20: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 21: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 22: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 23: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 24: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 25: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 26: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 27: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 28: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 29: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 30: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 31: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 32: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 33: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 34: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 35: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 36: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 37: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 38: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 39: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 40: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 41: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 42: {
       vector<double> P(1);
       P[0]= ( double ) 1 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 43: {
       vector<double> P(1);
       P[0]= ( double ) 100 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 44: {
       vector<double> P(1);
       P[0]= ( double ) 10 * ( 1 + 0 *  Marking[ 0 ]  );
       return P;
       break;
     }
     case 45: {
       vector<double> P(1);
       P[0]= ( double ) 0 *  Marking[ 0 ] ;
       return P;
       break;
     }
   }
}

double SPN::GetPriority(int t){
   switch(t){
     case 0: {
       return (double)1;
       break;
     } 
     case 1: {
       return (double)1;
       break;
     } 
     case 2: {
       return (double)1;
       break;
     } 
     case 3: {
       return (double)1;
       break;
     } 
     case 4: {
       return (double)1;
       break;
     } 
     case 5: {
       return (double)1;
       break;
     } 
     case 6: {
       return (double)1;
       break;
     } 
     case 7: {
       return (double)1;
       break;
     } 
     case 8: {
       return (double)1;
       break;
     } 
     case 9: {
       return (double)1;
       break;
     } 
     case 10: {
       return (double)1;
       break;
     } 
     case 11: {
       return (double)1;
       break;
     } 
     case 12: {
       return (double)1;
       break;
     } 
     case 13: {
       return (double)1;
       break;
     } 
     case 14: {
       return (double)1;
       break;
     } 
     case 15: {
       return (double)1;
       break;
     } 
     case 16: {
       return (double)1;
       break;
     } 
     case 17: {
       return (double)1;
       break;
     } 
     case 18: {
       return (double)1;
       break;
     } 
     case 19: {
       return (double)1;
       break;
     } 
     case 20: {
       return (double)1;
       break;
     } 
     case 21: {
       return (double)1;
       break;
     } 
     case 22: {
       return (double)1;
       break;
     } 
     case 23: {
       return (double)1;
       break;
     } 
     case 24: {
       return (double)1;
       break;
     } 
     case 25: {
       return (double)1;
       break;
     } 
     case 26: {
       return (double)1;
       break;
     } 
     case 27: {
       return (double)1;
       break;
     } 
     case 28: {
       return (double)1;
       break;
     } 
     case 29: {
       return (double)1;
       break;
     } 
     case 30: {
       return (double)1;
       break;
     } 
     case 31: {
       return (double)1;
       break;
     } 
     case 32: {
       return (double)1;
       break;
     } 
     case 33: {
       return (double)1;
       break;
     } 
     case 34: {
       return (double)1;
       break;
     } 
     case 35: {
       return (double)1;
       break;
     } 
     case 36: {
       return (double)1;
       break;
     } 
     case 37: {
       return (double)1;
       break;
     } 
     case 38: {
       return (double)1;
       break;
     } 
     case 39: {
       return (double)1;
       break;
     } 
     case 40: {
       return (double)1;
       break;
     } 
     case 41: {
       return (double)1;
       break;
     } 
     case 42: {
       return (double)1;
       break;
     } 
     case 43: {
       return (double)1;
       break;
     } 
     case 44: {
       return (double)1;
       break;
     } 
     case 45: {
       return (double)1;
       break;
     } 
   }
}

double SPN::GetWeight(int t){
   switch(t){
     case 0:
       return (double)1;
       break;
     case 1:
       return (double)1;
       break;
     case 2:
       return (double)1;
       break;
     case 3:
       return (double)1;
       break;
     case 4:
       return (double)1;
       break;
     case 5:
       return (double)1;
       break;
     case 6:
       return (double)1;
       break;
     case 7:
       return (double)1;
       break;
     case 8:
       return (double)1;
       break;
     case 9:
       return (double)1;
       break;
     case 10:
       return (double)1;
       break;
     case 11:
       return (double)1;
       break;
     case 12:
       return (double)1;
       break;
     case 13:
       return (double)1;
       break;
     case 14:
       return (double)1;
       break;
     case 15:
       return (double)1;
       break;
     case 16:
       return (double)1;
       break;
     case 17:
       return (double)1;
       break;
     case 18:
       return (double)1;
       break;
     case 19:
       return (double)1;
       break;
     case 20:
       return (double)1;
       break;
     case 21:
       return (double)1;
       break;
     case 22:
       return (double)1;
       break;
     case 23:
       return (double)1;
       break;
     case 24:
       return (double)1;
       break;
     case 25:
       return (double)1;
       break;
     case 26:
       return (double)1;
       break;
     case 27:
       return (double)1;
       break;
     case 28:
       return (double)1;
       break;
     case 29:
       return (double)1;
       break;
     case 30:
       return (double)1;
       break;
     case 31:
       return (double)1;
       break;
     case 32:
       return (double)1;
       break;
     case 33:
       return (double)1;
       break;
     case 34:
       return (double)1;
       break;
     case 35:
       return (double)1;
       break;
     case 36:
       return (double)1;
       break;
     case 37:
       return (double)1;
       break;
     case 38:
       return (double)1;
       break;
     case 39:
       return (double)1;
       break;
     case 40:
       return (double)1;
       break;
     case 41:
       return (double)1;
       break;
     case 42:
       return (double)1;
       break;
     case 43:
       return (double)1;
       break;
     case 44:
       return (double)1;
       break;
     case 45:
       return (double)1;
       break;
   }
}

