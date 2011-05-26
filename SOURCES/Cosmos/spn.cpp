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
	(*PossiblyEnabled)[t1] = V;    //Ligne original
	//(*PossiblyEnabled)[t1]=AllEnabled;
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
    Path ="ruine";
    gammaprob.load();
    pl =166;
    tr =141;
    IntVector Null_Pl_Vector(pl, 0);
    IntMatrix Null_PlxTr_Matrix(tr, Null_Pl_Vector);
    inArcs = Null_PlxTr_Matrix;
    outArcs = Null_PlxTr_Matrix;
    inhibArcs = Null_PlxTr_Matrix;
    Marking = Null_Pl_Vector;;
    inArcs[0][0]=1;
    inArcs[0][3]=1;
    inArcs[0][31]=1;
    inArcs[0][150]=1;

    inArcs[1][1]=1;
    inArcs[1][2]=1;
    inArcs[1][151]=1;

    inArcs[2][2]=1;
    inArcs[2][5]=1;
    inArcs[2][33]=1;
    inArcs[2][151]=1;

    inArcs[3][3]=1;
    inArcs[3][4]=1;
    inArcs[3][152]=1;

    inArcs[4][4]=1;
    inArcs[4][7]=1;
    inArcs[4][35]=1;
    inArcs[4][152]=1;

    inArcs[5][5]=1;
    inArcs[5][6]=1;
    inArcs[5][153]=1;

    inArcs[6][6]=1;
    inArcs[6][9]=1;
    inArcs[6][37]=1;
    inArcs[6][153]=1;

    inArcs[7][7]=1;
    inArcs[7][8]=1;
    inArcs[7][154]=1;

    inArcs[8][8]=1;
    inArcs[8][11]=1;
    inArcs[8][39]=1;
    inArcs[8][154]=1;

    inArcs[9][9]=1;
    inArcs[9][10]=1;
    inArcs[9][155]=1;

    inArcs[10][10]=1;
    inArcs[10][13]=1;
    inArcs[10][41]=1;
    inArcs[10][155]=1;

    inArcs[11][11]=1;
    inArcs[11][12]=1;
    inArcs[11][156]=1;

    inArcs[12][12]=1;
    inArcs[12][15]=1;
    inArcs[12][43]=1;
    inArcs[12][156]=1;

    inArcs[13][13]=1;
    inArcs[13][14]=1;
    inArcs[13][157]=1;

    inArcs[14][14]=1;
    inArcs[14][17]=1;
    inArcs[14][45]=1;
    inArcs[14][157]=1;

    inArcs[15][15]=1;
    inArcs[15][16]=1;
    inArcs[15][158]=1;

    inArcs[16][16]=1;
    inArcs[16][19]=1;
    inArcs[16][47]=1;
    inArcs[16][158]=1;

    inArcs[17][17]=1;
    inArcs[17][18]=1;
    inArcs[17][159]=1;

    inArcs[18][18]=1;
    inArcs[18][21]=1;
    inArcs[18][49]=1;
    inArcs[18][159]=1;

    inArcs[19][19]=1;
    inArcs[19][20]=1;
    inArcs[19][160]=1;

    inArcs[20][20]=1;
    inArcs[20][23]=1;
    inArcs[20][51]=1;
    inArcs[20][160]=1;

    inArcs[21][21]=1;
    inArcs[21][22]=1;
    inArcs[21][161]=1;

    inArcs[22][22]=1;
    inArcs[22][25]=1;
    inArcs[22][53]=1;
    inArcs[22][161]=1;

    inArcs[23][23]=1;
    inArcs[23][24]=1;
    inArcs[23][162]=1;

    inArcs[24][24]=1;
    inArcs[24][27]=1;
    inArcs[24][55]=1;
    inArcs[24][162]=1;

    inArcs[25][25]=1;
    inArcs[25][26]=1;
    inArcs[25][163]=1;

    inArcs[26][26]=1;
    inArcs[26][29]=1;
    inArcs[26][57]=1;
    inArcs[26][163]=1;

    inArcs[27][27]=1;
    inArcs[27][28]=1;
    inArcs[27][164]=1;

    inArcs[28][30]=1;
    inArcs[28][33]=1;
    inArcs[28][61]=1;
    inArcs[28][150]=1;

    inArcs[29][31]=1;
    inArcs[29][32]=1;
    inArcs[29][151]=1;

    inArcs[30][32]=1;
    inArcs[30][35]=1;
    inArcs[30][63]=1;
    inArcs[30][151]=1;

    inArcs[31][33]=1;
    inArcs[31][34]=1;
    inArcs[31][152]=1;

    inArcs[32][34]=1;
    inArcs[32][37]=1;
    inArcs[32][65]=1;
    inArcs[32][152]=1;

    inArcs[33][35]=1;
    inArcs[33][36]=1;
    inArcs[33][153]=1;

    inArcs[34][36]=1;
    inArcs[34][39]=1;
    inArcs[34][67]=1;
    inArcs[34][153]=1;

    inArcs[35][37]=1;
    inArcs[35][38]=1;
    inArcs[35][154]=1;

    inArcs[36][38]=1;
    inArcs[36][41]=1;
    inArcs[36][69]=1;
    inArcs[36][154]=1;

    inArcs[37][39]=1;
    inArcs[37][40]=1;
    inArcs[37][155]=1;

    inArcs[38][40]=1;
    inArcs[38][43]=1;
    inArcs[38][71]=1;
    inArcs[38][155]=1;

    inArcs[39][41]=1;
    inArcs[39][42]=1;
    inArcs[39][156]=1;

    inArcs[40][42]=1;
    inArcs[40][45]=1;
    inArcs[40][73]=1;
    inArcs[40][156]=1;

    inArcs[41][43]=1;
    inArcs[41][44]=1;
    inArcs[41][157]=1;

    inArcs[42][44]=1;
    inArcs[42][47]=1;
    inArcs[42][75]=1;
    inArcs[42][157]=1;

    inArcs[43][45]=1;
    inArcs[43][46]=1;
    inArcs[43][158]=1;

    inArcs[44][46]=1;
    inArcs[44][49]=1;
    inArcs[44][77]=1;
    inArcs[44][158]=1;

    inArcs[45][47]=1;
    inArcs[45][48]=1;
    inArcs[45][159]=1;

    inArcs[46][48]=1;
    inArcs[46][51]=1;
    inArcs[46][79]=1;
    inArcs[46][159]=1;

    inArcs[47][49]=1;
    inArcs[47][50]=1;
    inArcs[47][160]=1;

    inArcs[48][50]=1;
    inArcs[48][53]=1;
    inArcs[48][81]=1;
    inArcs[48][160]=1;

    inArcs[49][51]=1;
    inArcs[49][52]=1;
    inArcs[49][161]=1;

    inArcs[50][52]=1;
    inArcs[50][55]=1;
    inArcs[50][83]=1;
    inArcs[50][161]=1;

    inArcs[51][53]=1;
    inArcs[51][54]=1;
    inArcs[51][162]=1;

    inArcs[52][54]=1;
    inArcs[52][57]=1;
    inArcs[52][85]=1;
    inArcs[52][162]=1;

    inArcs[53][55]=1;
    inArcs[53][56]=1;
    inArcs[53][163]=1;

    inArcs[54][56]=1;
    inArcs[54][59]=1;
    inArcs[54][87]=1;
    inArcs[54][163]=1;

    inArcs[55][57]=1;
    inArcs[55][58]=1;
    inArcs[55][164]=1;

    inArcs[56][60]=1;
    inArcs[56][63]=1;
    inArcs[56][91]=1;
    inArcs[56][150]=1;

    inArcs[57][61]=1;
    inArcs[57][62]=1;
    inArcs[57][151]=1;

    inArcs[58][62]=1;
    inArcs[58][65]=1;
    inArcs[58][93]=1;
    inArcs[58][151]=1;

    inArcs[59][63]=1;
    inArcs[59][64]=1;
    inArcs[59][152]=1;

    inArcs[60][64]=1;
    inArcs[60][67]=1;
    inArcs[60][95]=1;
    inArcs[60][152]=1;

    inArcs[61][65]=1;
    inArcs[61][66]=1;
    inArcs[61][153]=1;

    inArcs[62][66]=1;
    inArcs[62][69]=1;
    inArcs[62][97]=1;
    inArcs[62][153]=1;

    inArcs[63][67]=1;
    inArcs[63][68]=1;
    inArcs[63][154]=1;

    inArcs[64][68]=1;
    inArcs[64][71]=1;
    inArcs[64][99]=1;
    inArcs[64][154]=1;

    inArcs[65][69]=1;
    inArcs[65][70]=1;
    inArcs[65][155]=1;

    inArcs[66][70]=1;
    inArcs[66][73]=1;
    inArcs[66][101]=1;
    inArcs[66][155]=1;

    inArcs[67][71]=1;
    inArcs[67][72]=1;
    inArcs[67][156]=1;

    inArcs[68][72]=1;
    inArcs[68][75]=1;
    inArcs[68][103]=1;
    inArcs[68][156]=1;

    inArcs[69][73]=1;
    inArcs[69][74]=1;
    inArcs[69][157]=1;

    inArcs[70][74]=1;
    inArcs[70][77]=1;
    inArcs[70][105]=1;
    inArcs[70][157]=1;

    inArcs[71][75]=1;
    inArcs[71][76]=1;
    inArcs[71][158]=1;

    inArcs[72][76]=1;
    inArcs[72][79]=1;
    inArcs[72][107]=1;
    inArcs[72][158]=1;

    inArcs[73][77]=1;
    inArcs[73][78]=1;
    inArcs[73][159]=1;

    inArcs[74][78]=1;
    inArcs[74][81]=1;
    inArcs[74][109]=1;
    inArcs[74][159]=1;

    inArcs[75][79]=1;
    inArcs[75][80]=1;
    inArcs[75][160]=1;

    inArcs[76][80]=1;
    inArcs[76][83]=1;
    inArcs[76][111]=1;
    inArcs[76][160]=1;

    inArcs[77][81]=1;
    inArcs[77][82]=1;
    inArcs[77][161]=1;

    inArcs[78][82]=1;
    inArcs[78][85]=1;
    inArcs[78][113]=1;
    inArcs[78][161]=1;

    inArcs[79][83]=1;
    inArcs[79][84]=1;
    inArcs[79][162]=1;

    inArcs[80][84]=1;
    inArcs[80][87]=1;
    inArcs[80][115]=1;
    inArcs[80][162]=1;

    inArcs[81][85]=1;
    inArcs[81][86]=1;
    inArcs[81][163]=1;

    inArcs[82][86]=1;
    inArcs[82][89]=1;
    inArcs[82][117]=1;
    inArcs[82][163]=1;

    inArcs[83][87]=1;
    inArcs[83][88]=1;
    inArcs[83][164]=1;

    inArcs[84][90]=1;
    inArcs[84][93]=1;
    inArcs[84][121]=1;
    inArcs[84][150]=1;

    inArcs[85][91]=1;
    inArcs[85][92]=1;
    inArcs[85][151]=1;

    inArcs[86][92]=1;
    inArcs[86][95]=1;
    inArcs[86][123]=1;
    inArcs[86][151]=1;

    inArcs[87][93]=1;
    inArcs[87][94]=1;
    inArcs[87][152]=1;

    inArcs[88][94]=1;
    inArcs[88][97]=1;
    inArcs[88][125]=1;
    inArcs[88][152]=1;

    inArcs[89][95]=1;
    inArcs[89][96]=1;
    inArcs[89][153]=1;

    inArcs[90][96]=1;
    inArcs[90][99]=1;
    inArcs[90][127]=1;
    inArcs[90][153]=1;

    inArcs[91][97]=1;
    inArcs[91][98]=1;
    inArcs[91][154]=1;

    inArcs[92][98]=1;
    inArcs[92][101]=1;
    inArcs[92][129]=1;
    inArcs[92][154]=1;

    inArcs[93][99]=1;
    inArcs[93][100]=1;
    inArcs[93][155]=1;

    inArcs[94][100]=1;
    inArcs[94][103]=1;
    inArcs[94][131]=1;
    inArcs[94][155]=1;

    inArcs[95][101]=1;
    inArcs[95][102]=1;
    inArcs[95][156]=1;

    inArcs[96][102]=1;
    inArcs[96][105]=1;
    inArcs[96][133]=1;
    inArcs[96][156]=1;

    inArcs[97][103]=1;
    inArcs[97][104]=1;
    inArcs[97][157]=1;

    inArcs[98][104]=1;
    inArcs[98][107]=1;
    inArcs[98][135]=1;
    inArcs[98][157]=1;

    inArcs[99][105]=1;
    inArcs[99][106]=1;
    inArcs[99][158]=1;

    inArcs[100][106]=1;
    inArcs[100][109]=1;
    inArcs[100][137]=1;
    inArcs[100][158]=1;

    inArcs[101][107]=1;
    inArcs[101][108]=1;
    inArcs[101][159]=1;

    inArcs[102][108]=1;
    inArcs[102][111]=1;
    inArcs[102][139]=1;
    inArcs[102][159]=1;

    inArcs[103][109]=1;
    inArcs[103][110]=1;
    inArcs[103][160]=1;

    inArcs[104][110]=1;
    inArcs[104][113]=1;
    inArcs[104][141]=1;
    inArcs[104][160]=1;

    inArcs[105][111]=1;
    inArcs[105][112]=1;
    inArcs[105][161]=1;

    inArcs[106][112]=1;
    inArcs[106][115]=1;
    inArcs[106][143]=1;
    inArcs[106][161]=1;

    inArcs[107][113]=1;
    inArcs[107][114]=1;
    inArcs[107][162]=1;

    inArcs[108][114]=1;
    inArcs[108][117]=1;
    inArcs[108][145]=1;
    inArcs[108][162]=1;

    inArcs[109][115]=1;
    inArcs[109][116]=1;
    inArcs[109][163]=1;

    inArcs[110][116]=1;
    inArcs[110][119]=1;
    inArcs[110][147]=1;
    inArcs[110][163]=1;

    inArcs[111][117]=1;
    inArcs[111][118]=1;
    inArcs[111][164]=1;

    inArcs[112][120]=1;
    inArcs[112][123]=1;
    inArcs[112][150]=1;

    inArcs[113][121]=1;
    inArcs[113][122]=1;
    inArcs[113][151]=1;

    inArcs[114][122]=1;
    inArcs[114][125]=1;
    inArcs[114][151]=1;

    inArcs[115][123]=1;
    inArcs[115][124]=1;
    inArcs[115][152]=1;

    inArcs[116][124]=1;
    inArcs[116][127]=1;
    inArcs[116][152]=1;

    inArcs[117][125]=1;
    inArcs[117][126]=1;
    inArcs[117][153]=1;

    inArcs[118][126]=1;
    inArcs[118][129]=1;
    inArcs[118][153]=1;

    inArcs[119][127]=1;
    inArcs[119][128]=1;
    inArcs[119][154]=1;

    inArcs[120][128]=1;
    inArcs[120][131]=1;
    inArcs[120][154]=1;

    inArcs[121][129]=1;
    inArcs[121][130]=1;
    inArcs[121][155]=1;

    inArcs[122][130]=1;
    inArcs[122][133]=1;
    inArcs[122][155]=1;

    inArcs[123][131]=1;
    inArcs[123][132]=1;
    inArcs[123][156]=1;

    inArcs[124][132]=1;
    inArcs[124][135]=1;
    inArcs[124][156]=1;

    inArcs[125][133]=1;
    inArcs[125][134]=1;
    inArcs[125][157]=1;

    inArcs[126][134]=1;
    inArcs[126][137]=1;
    inArcs[126][157]=1;

    inArcs[127][135]=1;
    inArcs[127][136]=1;
    inArcs[127][158]=1;

    inArcs[128][136]=1;
    inArcs[128][139]=1;
    inArcs[128][158]=1;

    inArcs[129][137]=1;
    inArcs[129][138]=1;
    inArcs[129][159]=1;

    inArcs[130][138]=1;
    inArcs[130][141]=1;
    inArcs[130][159]=1;

    inArcs[131][139]=1;
    inArcs[131][140]=1;
    inArcs[131][160]=1;

    inArcs[132][140]=1;
    inArcs[132][143]=1;
    inArcs[132][160]=1;

    inArcs[133][141]=1;
    inArcs[133][142]=1;
    inArcs[133][161]=1;

    inArcs[134][142]=1;
    inArcs[134][145]=1;
    inArcs[134][161]=1;

    inArcs[135][143]=1;
    inArcs[135][144]=1;
    inArcs[135][162]=1;

    inArcs[136][144]=1;
    inArcs[136][147]=1;
    inArcs[136][162]=1;

    inArcs[137][145]=1;
    inArcs[137][146]=1;
    inArcs[137][163]=1;

    inArcs[138][146]=1;
    inArcs[138][149]=1;
    inArcs[138][163]=1;

    inArcs[139][147]=1;
    inArcs[139][148]=1;
    inArcs[139][164]=1;


    outArcs[0][1]=1;
    outArcs[0][2]=1;
    outArcs[0][31]=1;
    outArcs[0][151]=1;

    outArcs[1][3]=1;
    outArcs[1][150]=1;

    outArcs[2][3]=1;
    outArcs[2][4]=1;
    outArcs[2][33]=1;
    outArcs[2][152]=1;

    outArcs[3][2]=1;
    outArcs[3][5]=1;
    outArcs[3][151]=1;

    outArcs[4][5]=1;
    outArcs[4][6]=1;
    outArcs[4][35]=1;
    outArcs[4][153]=1;

    outArcs[5][4]=1;
    outArcs[5][7]=1;
    outArcs[5][152]=1;

    outArcs[6][7]=1;
    outArcs[6][8]=1;
    outArcs[6][37]=1;
    outArcs[6][154]=1;

    outArcs[7][6]=1;
    outArcs[7][9]=1;
    outArcs[7][153]=1;

    outArcs[8][9]=1;
    outArcs[8][10]=1;
    outArcs[8][39]=1;
    outArcs[8][155]=1;

    outArcs[9][8]=1;
    outArcs[9][11]=1;
    outArcs[9][154]=1;

    outArcs[10][11]=1;
    outArcs[10][12]=1;
    outArcs[10][41]=1;
    outArcs[10][156]=1;

    outArcs[11][10]=1;
    outArcs[11][13]=1;
    outArcs[11][155]=1;

    outArcs[12][13]=1;
    outArcs[12][14]=1;
    outArcs[12][43]=1;
    outArcs[12][157]=1;

    outArcs[13][12]=1;
    outArcs[13][15]=1;
    outArcs[13][156]=1;

    outArcs[14][15]=1;
    outArcs[14][16]=1;
    outArcs[14][45]=1;
    outArcs[14][158]=1;

    outArcs[15][14]=1;
    outArcs[15][17]=1;
    outArcs[15][157]=1;

    outArcs[16][17]=1;
    outArcs[16][18]=1;
    outArcs[16][47]=1;
    outArcs[16][159]=1;

    outArcs[17][16]=1;
    outArcs[17][19]=1;
    outArcs[17][158]=1;

    outArcs[18][19]=1;
    outArcs[18][20]=1;
    outArcs[18][49]=1;
    outArcs[18][160]=1;

    outArcs[19][18]=1;
    outArcs[19][21]=1;
    outArcs[19][159]=1;

    outArcs[20][21]=1;
    outArcs[20][22]=1;
    outArcs[20][51]=1;
    outArcs[20][161]=1;

    outArcs[21][20]=1;
    outArcs[21][23]=1;
    outArcs[21][160]=1;

    outArcs[22][23]=1;
    outArcs[22][24]=1;
    outArcs[22][53]=1;
    outArcs[22][162]=1;

    outArcs[23][22]=1;
    outArcs[23][25]=1;
    outArcs[23][161]=1;

    outArcs[24][25]=1;
    outArcs[24][26]=1;
    outArcs[24][55]=1;
    outArcs[24][163]=1;

    outArcs[25][24]=1;
    outArcs[25][27]=1;
    outArcs[25][162]=1;

    outArcs[26][27]=1;
    outArcs[26][57]=1;
    outArcs[26][164]=1;

    outArcs[27][26]=1;
    outArcs[27][29]=1;
    outArcs[27][163]=1;

    outArcs[28][31]=1;
    outArcs[28][32]=1;
    outArcs[28][61]=1;
    outArcs[28][151]=1;

    outArcs[29][33]=1;
    outArcs[29][150]=1;

    outArcs[30][33]=1;
    outArcs[30][34]=1;
    outArcs[30][63]=1;
    outArcs[30][152]=1;

    outArcs[31][32]=1;
    outArcs[31][35]=1;
    outArcs[31][151]=1;

    outArcs[32][35]=1;
    outArcs[32][36]=1;
    outArcs[32][65]=1;
    outArcs[32][153]=1;

    outArcs[33][34]=1;
    outArcs[33][37]=1;
    outArcs[33][152]=1;

    outArcs[34][37]=1;
    outArcs[34][38]=1;
    outArcs[34][67]=1;
    outArcs[34][154]=1;

    outArcs[35][36]=1;
    outArcs[35][39]=1;
    outArcs[35][153]=1;

    outArcs[36][39]=1;
    outArcs[36][40]=1;
    outArcs[36][69]=1;
    outArcs[36][155]=1;

    outArcs[37][38]=1;
    outArcs[37][41]=1;
    outArcs[37][154]=1;

    outArcs[38][41]=1;
    outArcs[38][42]=1;
    outArcs[38][71]=1;
    outArcs[38][156]=1;

    outArcs[39][40]=1;
    outArcs[39][43]=1;
    outArcs[39][155]=1;

    outArcs[40][43]=1;
    outArcs[40][44]=1;
    outArcs[40][73]=1;
    outArcs[40][157]=1;

    outArcs[41][42]=1;
    outArcs[41][45]=1;
    outArcs[41][156]=1;

    outArcs[42][45]=1;
    outArcs[42][46]=1;
    outArcs[42][75]=1;
    outArcs[42][158]=1;

    outArcs[43][44]=1;
    outArcs[43][47]=1;
    outArcs[43][157]=1;

    outArcs[44][47]=1;
    outArcs[44][48]=1;
    outArcs[44][77]=1;
    outArcs[44][159]=1;

    outArcs[45][46]=1;
    outArcs[45][49]=1;
    outArcs[45][158]=1;

    outArcs[46][49]=1;
    outArcs[46][50]=1;
    outArcs[46][79]=1;
    outArcs[46][160]=1;

    outArcs[47][48]=1;
    outArcs[47][51]=1;
    outArcs[47][159]=1;

    outArcs[48][51]=1;
    outArcs[48][52]=1;
    outArcs[48][81]=1;
    outArcs[48][161]=1;

    outArcs[49][50]=1;
    outArcs[49][53]=1;
    outArcs[49][160]=1;

    outArcs[50][53]=1;
    outArcs[50][54]=1;
    outArcs[50][83]=1;
    outArcs[50][162]=1;

    outArcs[51][52]=1;
    outArcs[51][55]=1;
    outArcs[51][161]=1;

    outArcs[52][55]=1;
    outArcs[52][56]=1;
    outArcs[52][85]=1;
    outArcs[52][163]=1;

    outArcs[53][54]=1;
    outArcs[53][57]=1;
    outArcs[53][162]=1;

    outArcs[54][57]=1;
    outArcs[54][87]=1;
    outArcs[54][164]=1;

    outArcs[55][56]=1;
    outArcs[55][59]=1;
    outArcs[55][163]=1;

    outArcs[56][61]=1;
    outArcs[56][62]=1;
    outArcs[56][91]=1;
    outArcs[56][151]=1;

    outArcs[57][63]=1;
    outArcs[57][150]=1;

    outArcs[58][63]=1;
    outArcs[58][64]=1;
    outArcs[58][93]=1;
    outArcs[58][152]=1;

    outArcs[59][62]=1;
    outArcs[59][65]=1;
    outArcs[59][151]=1;

    outArcs[60][65]=1;
    outArcs[60][66]=1;
    outArcs[60][95]=1;
    outArcs[60][153]=1;

    outArcs[61][64]=1;
    outArcs[61][67]=1;
    outArcs[61][152]=1;

    outArcs[62][67]=1;
    outArcs[62][68]=1;
    outArcs[62][97]=1;
    outArcs[62][154]=1;

    outArcs[63][66]=1;
    outArcs[63][69]=1;
    outArcs[63][153]=1;

    outArcs[64][69]=1;
    outArcs[64][70]=1;
    outArcs[64][99]=1;
    outArcs[64][155]=1;

    outArcs[65][68]=1;
    outArcs[65][71]=1;
    outArcs[65][154]=1;

    outArcs[66][71]=1;
    outArcs[66][72]=1;
    outArcs[66][101]=1;
    outArcs[66][156]=1;

    outArcs[67][70]=1;
    outArcs[67][73]=1;
    outArcs[67][155]=1;

    outArcs[68][73]=1;
    outArcs[68][74]=1;
    outArcs[68][103]=1;
    outArcs[68][157]=1;

    outArcs[69][72]=1;
    outArcs[69][75]=1;
    outArcs[69][156]=1;

    outArcs[70][75]=1;
    outArcs[70][76]=1;
    outArcs[70][105]=1;
    outArcs[70][158]=1;

    outArcs[71][74]=1;
    outArcs[71][77]=1;
    outArcs[71][157]=1;

    outArcs[72][77]=1;
    outArcs[72][78]=1;
    outArcs[72][107]=1;
    outArcs[72][159]=1;

    outArcs[73][76]=1;
    outArcs[73][79]=1;
    outArcs[73][158]=1;

    outArcs[74][79]=1;
    outArcs[74][80]=1;
    outArcs[74][109]=1;
    outArcs[74][160]=1;

    outArcs[75][78]=1;
    outArcs[75][81]=1;
    outArcs[75][159]=1;

    outArcs[76][81]=1;
    outArcs[76][82]=1;
    outArcs[76][111]=1;
    outArcs[76][161]=1;

    outArcs[77][80]=1;
    outArcs[77][83]=1;
    outArcs[77][160]=1;

    outArcs[78][83]=1;
    outArcs[78][84]=1;
    outArcs[78][113]=1;
    outArcs[78][162]=1;

    outArcs[79][82]=1;
    outArcs[79][85]=1;
    outArcs[79][161]=1;

    outArcs[80][85]=1;
    outArcs[80][86]=1;
    outArcs[80][115]=1;
    outArcs[80][163]=1;

    outArcs[81][84]=1;
    outArcs[81][87]=1;
    outArcs[81][162]=1;

    outArcs[82][87]=1;
    outArcs[82][117]=1;
    outArcs[82][164]=1;

    outArcs[83][86]=1;
    outArcs[83][89]=1;
    outArcs[83][163]=1;

    outArcs[84][91]=1;
    outArcs[84][92]=1;
    outArcs[84][121]=1;
    outArcs[84][151]=1;

    outArcs[85][93]=1;
    outArcs[85][150]=1;

    outArcs[86][93]=1;
    outArcs[86][94]=1;
    outArcs[86][123]=1;
    outArcs[86][152]=1;

    outArcs[87][92]=1;
    outArcs[87][95]=1;
    outArcs[87][151]=1;

    outArcs[88][95]=1;
    outArcs[88][96]=1;
    outArcs[88][125]=1;
    outArcs[88][153]=1;

    outArcs[89][94]=1;
    outArcs[89][97]=1;
    outArcs[89][152]=1;

    outArcs[90][97]=1;
    outArcs[90][98]=1;
    outArcs[90][127]=1;
    outArcs[90][154]=1;

    outArcs[91][96]=1;
    outArcs[91][99]=1;
    outArcs[91][153]=1;

    outArcs[92][99]=1;
    outArcs[92][100]=1;
    outArcs[92][129]=1;
    outArcs[92][155]=1;

    outArcs[93][98]=1;
    outArcs[93][101]=1;
    outArcs[93][154]=1;

    outArcs[94][101]=1;
    outArcs[94][102]=1;
    outArcs[94][131]=1;
    outArcs[94][156]=1;

    outArcs[95][100]=1;
    outArcs[95][103]=1;
    outArcs[95][155]=1;

    outArcs[96][103]=1;
    outArcs[96][104]=1;
    outArcs[96][133]=1;
    outArcs[96][157]=1;

    outArcs[97][102]=1;
    outArcs[97][105]=1;
    outArcs[97][156]=1;

    outArcs[98][105]=1;
    outArcs[98][106]=1;
    outArcs[98][135]=1;
    outArcs[98][158]=1;

    outArcs[99][104]=1;
    outArcs[99][107]=1;
    outArcs[99][157]=1;

    outArcs[100][107]=1;
    outArcs[100][108]=1;
    outArcs[100][137]=1;
    outArcs[100][159]=1;

    outArcs[101][106]=1;
    outArcs[101][109]=1;
    outArcs[101][158]=1;

    outArcs[102][109]=1;
    outArcs[102][110]=1;
    outArcs[102][139]=1;
    outArcs[102][160]=1;

    outArcs[103][108]=1;
    outArcs[103][111]=1;
    outArcs[103][159]=1;

    outArcs[104][111]=1;
    outArcs[104][112]=1;
    outArcs[104][141]=1;
    outArcs[104][161]=1;

    outArcs[105][110]=1;
    outArcs[105][113]=1;
    outArcs[105][160]=1;

    outArcs[106][113]=1;
    outArcs[106][114]=1;
    outArcs[106][143]=1;
    outArcs[106][162]=1;

    outArcs[107][112]=1;
    outArcs[107][115]=1;
    outArcs[107][161]=1;

    outArcs[108][115]=1;
    outArcs[108][116]=1;
    outArcs[108][145]=1;
    outArcs[108][163]=1;

    outArcs[109][114]=1;
    outArcs[109][117]=1;
    outArcs[109][162]=1;

    outArcs[110][117]=1;
    outArcs[110][147]=1;
    outArcs[110][164]=1;

    outArcs[111][116]=1;
    outArcs[111][119]=1;
    outArcs[111][163]=1;

    outArcs[112][121]=1;
    outArcs[112][122]=1;
    outArcs[112][151]=1;

    outArcs[113][123]=1;
    outArcs[113][150]=1;

    outArcs[114][123]=1;
    outArcs[114][124]=1;
    outArcs[114][152]=1;

    outArcs[115][122]=1;
    outArcs[115][125]=1;
    outArcs[115][151]=1;

    outArcs[116][125]=1;
    outArcs[116][126]=1;
    outArcs[116][153]=1;

    outArcs[117][124]=1;
    outArcs[117][127]=1;
    outArcs[117][152]=1;

    outArcs[118][127]=1;
    outArcs[118][128]=1;
    outArcs[118][154]=1;

    outArcs[119][126]=1;
    outArcs[119][129]=1;
    outArcs[119][153]=1;

    outArcs[120][129]=1;
    outArcs[120][130]=1;
    outArcs[120][155]=1;

    outArcs[121][128]=1;
    outArcs[121][131]=1;
    outArcs[121][154]=1;

    outArcs[122][131]=1;
    outArcs[122][132]=1;
    outArcs[122][156]=1;

    outArcs[123][130]=1;
    outArcs[123][133]=1;
    outArcs[123][155]=1;

    outArcs[124][133]=1;
    outArcs[124][134]=1;
    outArcs[124][157]=1;

    outArcs[125][132]=1;
    outArcs[125][135]=1;
    outArcs[125][156]=1;

    outArcs[126][135]=1;
    outArcs[126][136]=1;
    outArcs[126][158]=1;

    outArcs[127][134]=1;
    outArcs[127][137]=1;
    outArcs[127][157]=1;

    outArcs[128][137]=1;
    outArcs[128][138]=1;
    outArcs[128][159]=1;

    outArcs[129][136]=1;
    outArcs[129][139]=1;
    outArcs[129][158]=1;

    outArcs[130][139]=1;
    outArcs[130][140]=1;
    outArcs[130][160]=1;

    outArcs[131][138]=1;
    outArcs[131][141]=1;
    outArcs[131][159]=1;

    outArcs[132][141]=1;
    outArcs[132][142]=1;
    outArcs[132][161]=1;

    outArcs[133][140]=1;
    outArcs[133][143]=1;
    outArcs[133][160]=1;

    outArcs[134][143]=1;
    outArcs[134][144]=1;
    outArcs[134][162]=1;

    outArcs[135][142]=1;
    outArcs[135][145]=1;
    outArcs[135][161]=1;

    outArcs[136][145]=1;
    outArcs[136][146]=1;
    outArcs[136][163]=1;

    outArcs[137][144]=1;
    outArcs[137][147]=1;
    outArcs[137][162]=1;

    outArcs[138][147]=1;
    outArcs[138][164]=1;

    outArcs[139][146]=1;
    outArcs[139][149]=1;
    outArcs[139][163]=1;

    outArcs[140][165]=1;














































































































































    Marking[1]=1;
    Marking[3]=1;
    Marking[5]=1;
    Marking[7]=1;
    Marking[9]=1;
    Marking[11]=1;
    Marking[12]=1;
    Marking[15]=1;
    Marking[17]=1;
    Marking[19]=1;
    Marking[21]=1;
    Marking[23]=1;
    Marking[25]=1;
    Marking[27]=1;
    Marking[29]=1;
    Marking[31]=1;
    Marking[33]=1;
    Marking[35]=1;
    Marking[37]=1;
    Marking[39]=1;
    Marking[41]=1;
    Marking[42]=1;
    Marking[45]=1;
    Marking[47]=1;
    Marking[49]=1;
    Marking[51]=1;
    Marking[53]=1;
    Marking[55]=1;
    Marking[57]=1;
    Marking[59]=1;
    Marking[61]=1;
    Marking[63]=1;
    Marking[65]=1;
    Marking[67]=1;
    Marking[69]=1;
    Marking[71]=1;
    Marking[72]=1;
    Marking[75]=1;
    Marking[77]=1;
    Marking[79]=1;
    Marking[81]=1;
    Marking[83]=1;
    Marking[85]=1;
    Marking[87]=1;
    Marking[89]=1;
    Marking[91]=1;
    Marking[93]=1;
    Marking[95]=1;
    Marking[97]=1;
    Marking[99]=1;
    Marking[101]=1;
    Marking[102]=1;
    Marking[105]=1;
    Marking[107]=1;
    Marking[109]=1;
    Marking[111]=1;
    Marking[113]=1;
    Marking[115]=1;
    Marking[117]=1;
    Marking[119]=1;
    Marking[121]=1;
    Marking[123]=1;
    Marking[125]=1;
    Marking[127]=1;
    Marking[129]=1;
    Marking[131]=1;
    Marking[132]=1;
    Marking[135]=1;
    Marking[137]=1;
    Marking[139]=1;
    Marking[141]=1;
    Marking[143]=1;
    Marking[145]=1;
    Marking[147]=1;
    Marking[149]=1;
    Marking[156]=5;

   initMarking = Marking;

    vector <spn_trans> t(141);
    Transition = t;
    vector <spn_place> p(166);
    Place = p;
    Place[1].Id =1;
    Place[1].label =" AntiPlace1_1";
    PlaceIndex[" AntiPlace1_1"] =1;
    Place[19].Id =19;
    Place[19].label =" AntiPlace1_10";
    PlaceIndex[" AntiPlace1_10"] =19;
    Place[21].Id =21;
    Place[21].label =" AntiPlace1_11";
    PlaceIndex[" AntiPlace1_11"] =21;
    Place[23].Id =23;
    Place[23].label =" AntiPlace1_12";
    PlaceIndex[" AntiPlace1_12"] =23;
    Place[25].Id =25;
    Place[25].label =" AntiPlace1_13";
    PlaceIndex[" AntiPlace1_13"] =25;
    Place[27].Id =27;
    Place[27].label =" AntiPlace1_14";
    PlaceIndex[" AntiPlace1_14"] =27;
    Place[29].Id =29;
    Place[29].label =" AntiPlace1_15";
    PlaceIndex[" AntiPlace1_15"] =29;
    Place[3].Id =3;
    Place[3].label =" AntiPlace1_2";
    PlaceIndex[" AntiPlace1_2"] =3;
    Place[5].Id =5;
    Place[5].label =" AntiPlace1_3";
    PlaceIndex[" AntiPlace1_3"] =5;
    Place[7].Id =7;
    Place[7].label =" AntiPlace1_4";
    PlaceIndex[" AntiPlace1_4"] =7;
    Place[9].Id =9;
    Place[9].label =" AntiPlace1_5";
    PlaceIndex[" AntiPlace1_5"] =9;
    Place[11].Id =11;
    Place[11].label =" AntiPlace1_6";
    PlaceIndex[" AntiPlace1_6"] =11;
    Place[13].Id =13;
    Place[13].label =" AntiPlace1_7";
    PlaceIndex[" AntiPlace1_7"] =13;
    Place[15].Id =15;
    Place[15].label =" AntiPlace1_8";
    PlaceIndex[" AntiPlace1_8"] =15;
    Place[17].Id =17;
    Place[17].label =" AntiPlace1_9";
    PlaceIndex[" AntiPlace1_9"] =17;
    Place[31].Id =31;
    Place[31].label =" AntiPlace2_1";
    PlaceIndex[" AntiPlace2_1"] =31;
    Place[49].Id =49;
    Place[49].label =" AntiPlace2_10";
    PlaceIndex[" AntiPlace2_10"] =49;
    Place[51].Id =51;
    Place[51].label =" AntiPlace2_11";
    PlaceIndex[" AntiPlace2_11"] =51;
    Place[53].Id =53;
    Place[53].label =" AntiPlace2_12";
    PlaceIndex[" AntiPlace2_12"] =53;
    Place[55].Id =55;
    Place[55].label =" AntiPlace2_13";
    PlaceIndex[" AntiPlace2_13"] =55;
    Place[57].Id =57;
    Place[57].label =" AntiPlace2_14";
    PlaceIndex[" AntiPlace2_14"] =57;
    Place[59].Id =59;
    Place[59].label =" AntiPlace2_15";
    PlaceIndex[" AntiPlace2_15"] =59;
    Place[33].Id =33;
    Place[33].label =" AntiPlace2_2";
    PlaceIndex[" AntiPlace2_2"] =33;
    Place[35].Id =35;
    Place[35].label =" AntiPlace2_3";
    PlaceIndex[" AntiPlace2_3"] =35;
    Place[37].Id =37;
    Place[37].label =" AntiPlace2_4";
    PlaceIndex[" AntiPlace2_4"] =37;
    Place[39].Id =39;
    Place[39].label =" AntiPlace2_5";
    PlaceIndex[" AntiPlace2_5"] =39;
    Place[41].Id =41;
    Place[41].label =" AntiPlace2_6";
    PlaceIndex[" AntiPlace2_6"] =41;
    Place[43].Id =43;
    Place[43].label =" AntiPlace2_7";
    PlaceIndex[" AntiPlace2_7"] =43;
    Place[45].Id =45;
    Place[45].label =" AntiPlace2_8";
    PlaceIndex[" AntiPlace2_8"] =45;
    Place[47].Id =47;
    Place[47].label =" AntiPlace2_9";
    PlaceIndex[" AntiPlace2_9"] =47;
    Place[61].Id =61;
    Place[61].label =" AntiPlace3_1";
    PlaceIndex[" AntiPlace3_1"] =61;
    Place[79].Id =79;
    Place[79].label =" AntiPlace3_10";
    PlaceIndex[" AntiPlace3_10"] =79;
    Place[81].Id =81;
    Place[81].label =" AntiPlace3_11";
    PlaceIndex[" AntiPlace3_11"] =81;
    Place[83].Id =83;
    Place[83].label =" AntiPlace3_12";
    PlaceIndex[" AntiPlace3_12"] =83;
    Place[85].Id =85;
    Place[85].label =" AntiPlace3_13";
    PlaceIndex[" AntiPlace3_13"] =85;
    Place[87].Id =87;
    Place[87].label =" AntiPlace3_14";
    PlaceIndex[" AntiPlace3_14"] =87;
    Place[89].Id =89;
    Place[89].label =" AntiPlace3_15";
    PlaceIndex[" AntiPlace3_15"] =89;
    Place[63].Id =63;
    Place[63].label =" AntiPlace3_2";
    PlaceIndex[" AntiPlace3_2"] =63;
    Place[65].Id =65;
    Place[65].label =" AntiPlace3_3";
    PlaceIndex[" AntiPlace3_3"] =65;
    Place[67].Id =67;
    Place[67].label =" AntiPlace3_4";
    PlaceIndex[" AntiPlace3_4"] =67;
    Place[69].Id =69;
    Place[69].label =" AntiPlace3_5";
    PlaceIndex[" AntiPlace3_5"] =69;
    Place[71].Id =71;
    Place[71].label =" AntiPlace3_6";
    PlaceIndex[" AntiPlace3_6"] =71;
    Place[73].Id =73;
    Place[73].label =" AntiPlace3_7";
    PlaceIndex[" AntiPlace3_7"] =73;
    Place[75].Id =75;
    Place[75].label =" AntiPlace3_8";
    PlaceIndex[" AntiPlace3_8"] =75;
    Place[77].Id =77;
    Place[77].label =" AntiPlace3_9";
    PlaceIndex[" AntiPlace3_9"] =77;
    Place[91].Id =91;
    Place[91].label =" AntiPlace4_1";
    PlaceIndex[" AntiPlace4_1"] =91;
    Place[109].Id =109;
    Place[109].label =" AntiPlace4_10";
    PlaceIndex[" AntiPlace4_10"] =109;
    Place[111].Id =111;
    Place[111].label =" AntiPlace4_11";
    PlaceIndex[" AntiPlace4_11"] =111;
    Place[113].Id =113;
    Place[113].label =" AntiPlace4_12";
    PlaceIndex[" AntiPlace4_12"] =113;
    Place[115].Id =115;
    Place[115].label =" AntiPlace4_13";
    PlaceIndex[" AntiPlace4_13"] =115;
    Place[117].Id =117;
    Place[117].label =" AntiPlace4_14";
    PlaceIndex[" AntiPlace4_14"] =117;
    Place[119].Id =119;
    Place[119].label =" AntiPlace4_15";
    PlaceIndex[" AntiPlace4_15"] =119;
    Place[93].Id =93;
    Place[93].label =" AntiPlace4_2";
    PlaceIndex[" AntiPlace4_2"] =93;
    Place[95].Id =95;
    Place[95].label =" AntiPlace4_3";
    PlaceIndex[" AntiPlace4_3"] =95;
    Place[97].Id =97;
    Place[97].label =" AntiPlace4_4";
    PlaceIndex[" AntiPlace4_4"] =97;
    Place[99].Id =99;
    Place[99].label =" AntiPlace4_5";
    PlaceIndex[" AntiPlace4_5"] =99;
    Place[101].Id =101;
    Place[101].label =" AntiPlace4_6";
    PlaceIndex[" AntiPlace4_6"] =101;
    Place[103].Id =103;
    Place[103].label =" AntiPlace4_7";
    PlaceIndex[" AntiPlace4_7"] =103;
    Place[105].Id =105;
    Place[105].label =" AntiPlace4_8";
    PlaceIndex[" AntiPlace4_8"] =105;
    Place[107].Id =107;
    Place[107].label =" AntiPlace4_9";
    PlaceIndex[" AntiPlace4_9"] =107;
    Place[121].Id =121;
    Place[121].label =" AntiPlace5_1";
    PlaceIndex[" AntiPlace5_1"] =121;
    Place[139].Id =139;
    Place[139].label =" AntiPlace5_10";
    PlaceIndex[" AntiPlace5_10"] =139;
    Place[141].Id =141;
    Place[141].label =" AntiPlace5_11";
    PlaceIndex[" AntiPlace5_11"] =141;
    Place[143].Id =143;
    Place[143].label =" AntiPlace5_12";
    PlaceIndex[" AntiPlace5_12"] =143;
    Place[145].Id =145;
    Place[145].label =" AntiPlace5_13";
    PlaceIndex[" AntiPlace5_13"] =145;
    Place[147].Id =147;
    Place[147].label =" AntiPlace5_14";
    PlaceIndex[" AntiPlace5_14"] =147;
    Place[149].Id =149;
    Place[149].label =" AntiPlace5_15";
    PlaceIndex[" AntiPlace5_15"] =149;
    Place[123].Id =123;
    Place[123].label =" AntiPlace5_2";
    PlaceIndex[" AntiPlace5_2"] =123;
    Place[125].Id =125;
    Place[125].label =" AntiPlace5_3";
    PlaceIndex[" AntiPlace5_3"] =125;
    Place[127].Id =127;
    Place[127].label =" AntiPlace5_4";
    PlaceIndex[" AntiPlace5_4"] =127;
    Place[129].Id =129;
    Place[129].label =" AntiPlace5_5";
    PlaceIndex[" AntiPlace5_5"] =129;
    Place[131].Id =131;
    Place[131].label =" AntiPlace5_6";
    PlaceIndex[" AntiPlace5_6"] =131;
    Place[133].Id =133;
    Place[133].label =" AntiPlace5_7";
    PlaceIndex[" AntiPlace5_7"] =133;
    Place[135].Id =135;
    Place[135].label =" AntiPlace5_8";
    PlaceIndex[" AntiPlace5_8"] =135;
    Place[137].Id =137;
    Place[137].label =" AntiPlace5_9";
    PlaceIndex[" AntiPlace5_9"] =137;
    Place[0].Id =0;
    Place[0].label =" Place1_1";
    PlaceIndex[" Place1_1"] =0;
    Place[18].Id =18;
    Place[18].label =" Place1_10";
    PlaceIndex[" Place1_10"] =18;
    Place[20].Id =20;
    Place[20].label =" Place1_11";
    PlaceIndex[" Place1_11"] =20;
    Place[22].Id =22;
    Place[22].label =" Place1_12";
    PlaceIndex[" Place1_12"] =22;
    Place[24].Id =24;
    Place[24].label =" Place1_13";
    PlaceIndex[" Place1_13"] =24;
    Place[26].Id =26;
    Place[26].label =" Place1_14";
    PlaceIndex[" Place1_14"] =26;
    Place[28].Id =28;
    Place[28].label =" Place1_15";
    PlaceIndex[" Place1_15"] =28;
    Place[2].Id =2;
    Place[2].label =" Place1_2";
    PlaceIndex[" Place1_2"] =2;
    Place[4].Id =4;
    Place[4].label =" Place1_3";
    PlaceIndex[" Place1_3"] =4;
    Place[6].Id =6;
    Place[6].label =" Place1_4";
    PlaceIndex[" Place1_4"] =6;
    Place[8].Id =8;
    Place[8].label =" Place1_5";
    PlaceIndex[" Place1_5"] =8;
    Place[10].Id =10;
    Place[10].label =" Place1_6";
    PlaceIndex[" Place1_6"] =10;
    Place[12].Id =12;
    Place[12].label =" Place1_7";
    PlaceIndex[" Place1_7"] =12;
    Place[14].Id =14;
    Place[14].label =" Place1_8";
    PlaceIndex[" Place1_8"] =14;
    Place[16].Id =16;
    Place[16].label =" Place1_9";
    PlaceIndex[" Place1_9"] =16;
    Place[30].Id =30;
    Place[30].label =" Place2_1";
    PlaceIndex[" Place2_1"] =30;
    Place[48].Id =48;
    Place[48].label =" Place2_10";
    PlaceIndex[" Place2_10"] =48;
    Place[50].Id =50;
    Place[50].label =" Place2_11";
    PlaceIndex[" Place2_11"] =50;
    Place[52].Id =52;
    Place[52].label =" Place2_12";
    PlaceIndex[" Place2_12"] =52;
    Place[54].Id =54;
    Place[54].label =" Place2_13";
    PlaceIndex[" Place2_13"] =54;
    Place[56].Id =56;
    Place[56].label =" Place2_14";
    PlaceIndex[" Place2_14"] =56;
    Place[58].Id =58;
    Place[58].label =" Place2_15";
    PlaceIndex[" Place2_15"] =58;
    Place[32].Id =32;
    Place[32].label =" Place2_2";
    PlaceIndex[" Place2_2"] =32;
    Place[34].Id =34;
    Place[34].label =" Place2_3";
    PlaceIndex[" Place2_3"] =34;
    Place[36].Id =36;
    Place[36].label =" Place2_4";
    PlaceIndex[" Place2_4"] =36;
    Place[38].Id =38;
    Place[38].label =" Place2_5";
    PlaceIndex[" Place2_5"] =38;
    Place[40].Id =40;
    Place[40].label =" Place2_6";
    PlaceIndex[" Place2_6"] =40;
    Place[42].Id =42;
    Place[42].label =" Place2_7";
    PlaceIndex[" Place2_7"] =42;
    Place[44].Id =44;
    Place[44].label =" Place2_8";
    PlaceIndex[" Place2_8"] =44;
    Place[46].Id =46;
    Place[46].label =" Place2_9";
    PlaceIndex[" Place2_9"] =46;
    Place[60].Id =60;
    Place[60].label =" Place3_1";
    PlaceIndex[" Place3_1"] =60;
    Place[78].Id =78;
    Place[78].label =" Place3_10";
    PlaceIndex[" Place3_10"] =78;
    Place[80].Id =80;
    Place[80].label =" Place3_11";
    PlaceIndex[" Place3_11"] =80;
    Place[82].Id =82;
    Place[82].label =" Place3_12";
    PlaceIndex[" Place3_12"] =82;
    Place[84].Id =84;
    Place[84].label =" Place3_13";
    PlaceIndex[" Place3_13"] =84;
    Place[86].Id =86;
    Place[86].label =" Place3_14";
    PlaceIndex[" Place3_14"] =86;
    Place[88].Id =88;
    Place[88].label =" Place3_15";
    PlaceIndex[" Place3_15"] =88;
    Place[62].Id =62;
    Place[62].label =" Place3_2";
    PlaceIndex[" Place3_2"] =62;
    Place[64].Id =64;
    Place[64].label =" Place3_3";
    PlaceIndex[" Place3_3"] =64;
    Place[66].Id =66;
    Place[66].label =" Place3_4";
    PlaceIndex[" Place3_4"] =66;
    Place[68].Id =68;
    Place[68].label =" Place3_5";
    PlaceIndex[" Place3_5"] =68;
    Place[70].Id =70;
    Place[70].label =" Place3_6";
    PlaceIndex[" Place3_6"] =70;
    Place[72].Id =72;
    Place[72].label =" Place3_7";
    PlaceIndex[" Place3_7"] =72;
    Place[74].Id =74;
    Place[74].label =" Place3_8";
    PlaceIndex[" Place3_8"] =74;
    Place[76].Id =76;
    Place[76].label =" Place3_9";
    PlaceIndex[" Place3_9"] =76;
    Place[90].Id =90;
    Place[90].label =" Place4_1";
    PlaceIndex[" Place4_1"] =90;
    Place[108].Id =108;
    Place[108].label =" Place4_10";
    PlaceIndex[" Place4_10"] =108;
    Place[110].Id =110;
    Place[110].label =" Place4_11";
    PlaceIndex[" Place4_11"] =110;
    Place[112].Id =112;
    Place[112].label =" Place4_12";
    PlaceIndex[" Place4_12"] =112;
    Place[114].Id =114;
    Place[114].label =" Place4_13";
    PlaceIndex[" Place4_13"] =114;
    Place[116].Id =116;
    Place[116].label =" Place4_14";
    PlaceIndex[" Place4_14"] =116;
    Place[118].Id =118;
    Place[118].label =" Place4_15";
    PlaceIndex[" Place4_15"] =118;
    Place[92].Id =92;
    Place[92].label =" Place4_2";
    PlaceIndex[" Place4_2"] =92;
    Place[94].Id =94;
    Place[94].label =" Place4_3";
    PlaceIndex[" Place4_3"] =94;
    Place[96].Id =96;
    Place[96].label =" Place4_4";
    PlaceIndex[" Place4_4"] =96;
    Place[98].Id =98;
    Place[98].label =" Place4_5";
    PlaceIndex[" Place4_5"] =98;
    Place[100].Id =100;
    Place[100].label =" Place4_6";
    PlaceIndex[" Place4_6"] =100;
    Place[102].Id =102;
    Place[102].label =" Place4_7";
    PlaceIndex[" Place4_7"] =102;
    Place[104].Id =104;
    Place[104].label =" Place4_8";
    PlaceIndex[" Place4_8"] =104;
    Place[106].Id =106;
    Place[106].label =" Place4_9";
    PlaceIndex[" Place4_9"] =106;
    Place[120].Id =120;
    Place[120].label =" Place5_1";
    PlaceIndex[" Place5_1"] =120;
    Place[138].Id =138;
    Place[138].label =" Place5_10";
    PlaceIndex[" Place5_10"] =138;
    Place[140].Id =140;
    Place[140].label =" Place5_11";
    PlaceIndex[" Place5_11"] =140;
    Place[142].Id =142;
    Place[142].label =" Place5_12";
    PlaceIndex[" Place5_12"] =142;
    Place[144].Id =144;
    Place[144].label =" Place5_13";
    PlaceIndex[" Place5_13"] =144;
    Place[146].Id =146;
    Place[146].label =" Place5_14";
    PlaceIndex[" Place5_14"] =146;
    Place[148].Id =148;
    Place[148].label =" Place5_15";
    PlaceIndex[" Place5_15"] =148;
    Place[122].Id =122;
    Place[122].label =" Place5_2";
    PlaceIndex[" Place5_2"] =122;
    Place[124].Id =124;
    Place[124].label =" Place5_3";
    PlaceIndex[" Place5_3"] =124;
    Place[126].Id =126;
    Place[126].label =" Place5_4";
    PlaceIndex[" Place5_4"] =126;
    Place[128].Id =128;
    Place[128].label =" Place5_5";
    PlaceIndex[" Place5_5"] =128;
    Place[130].Id =130;
    Place[130].label =" Place5_6";
    PlaceIndex[" Place5_6"] =130;
    Place[132].Id =132;
    Place[132].label =" Place5_7";
    PlaceIndex[" Place5_7"] =132;
    Place[134].Id =134;
    Place[134].label =" Place5_8";
    PlaceIndex[" Place5_8"] =134;
    Place[136].Id =136;
    Place[136].label =" Place5_9";
    PlaceIndex[" Place5_9"] =136;
    Place[165].Id =165;
    Place[165].label =" Puit";
    PlaceIndex[" Puit"] =165;
    Place[150].Id =150;
    Place[150].label =" nPlace1";
    PlaceIndex[" nPlace1"] =150;
    Place[159].Id =159;
    Place[159].label =" nPlace10";
    PlaceIndex[" nPlace10"] =159;
    Place[160].Id =160;
    Place[160].label =" nPlace11";
    PlaceIndex[" nPlace11"] =160;
    Place[161].Id =161;
    Place[161].label =" nPlace12";
    PlaceIndex[" nPlace12"] =161;
    Place[162].Id =162;
    Place[162].label =" nPlace13";
    PlaceIndex[" nPlace13"] =162;
    Place[163].Id =163;
    Place[163].label =" nPlace14";
    PlaceIndex[" nPlace14"] =163;
    Place[164].Id =164;
    Place[164].label =" nPlace15";
    PlaceIndex[" nPlace15"] =164;
    Place[151].Id =151;
    Place[151].label =" nPlace2";
    PlaceIndex[" nPlace2"] =151;
    Place[152].Id =152;
    Place[152].label =" nPlace3";
    PlaceIndex[" nPlace3"] =152;
    Place[153].Id =153;
    Place[153].label =" nPlace4";
    PlaceIndex[" nPlace4"] =153;
    Place[154].Id =154;
    Place[154].label =" nPlace5";
    PlaceIndex[" nPlace5"] =154;
    Place[155].Id =155;
    Place[155].label =" nPlace6";
    PlaceIndex[" nPlace6"] =155;
    Place[156].Id =156;
    Place[156].label =" nPlace7";
    PlaceIndex[" nPlace7"] =156;
    Place[157].Id =157;
    Place[157].label =" nPlace8";
    PlaceIndex[" nPlace8"] =157;
    Place[158].Id =158;
    Place[158].label =" nPlace9";
    PlaceIndex[" nPlace9"] =158;
    Transition[0].Id =0;
    Transition[0].label ="Avance1_1";
    TransitionIndex["Avance1_1"]=0;
    Transition[18].Id =18;
    Transition[18].label ="Avance1_10";
    TransitionIndex["Avance1_10"]=18;
    Transition[20].Id =20;
    Transition[20].label ="Avance1_11";
    TransitionIndex["Avance1_11"]=20;
    Transition[22].Id =22;
    Transition[22].label ="Avance1_12";
    TransitionIndex["Avance1_12"]=22;
    Transition[24].Id =24;
    Transition[24].label ="Avance1_13";
    TransitionIndex["Avance1_13"]=24;
    Transition[26].Id =26;
    Transition[26].label ="Avance1_14";
    TransitionIndex["Avance1_14"]=26;
    Transition[2].Id =2;
    Transition[2].label ="Avance1_2";
    TransitionIndex["Avance1_2"]=2;
    Transition[4].Id =4;
    Transition[4].label ="Avance1_3";
    TransitionIndex["Avance1_3"]=4;
    Transition[6].Id =6;
    Transition[6].label ="Avance1_4";
    TransitionIndex["Avance1_4"]=6;
    Transition[8].Id =8;
    Transition[8].label ="Avance1_5";
    TransitionIndex["Avance1_5"]=8;
    Transition[10].Id =10;
    Transition[10].label ="Avance1_6";
    TransitionIndex["Avance1_6"]=10;
    Transition[12].Id =12;
    Transition[12].label ="Avance1_7";
    TransitionIndex["Avance1_7"]=12;
    Transition[14].Id =14;
    Transition[14].label ="Avance1_8";
    TransitionIndex["Avance1_8"]=14;
    Transition[16].Id =16;
    Transition[16].label ="Avance1_9";
    TransitionIndex["Avance1_9"]=16;
    Transition[28].Id =28;
    Transition[28].label ="Avance2_1";
    TransitionIndex["Avance2_1"]=28;
    Transition[46].Id =46;
    Transition[46].label ="Avance2_10";
    TransitionIndex["Avance2_10"]=46;
    Transition[48].Id =48;
    Transition[48].label ="Avance2_11";
    TransitionIndex["Avance2_11"]=48;
    Transition[50].Id =50;
    Transition[50].label ="Avance2_12";
    TransitionIndex["Avance2_12"]=50;
    Transition[52].Id =52;
    Transition[52].label ="Avance2_13";
    TransitionIndex["Avance2_13"]=52;
    Transition[54].Id =54;
    Transition[54].label ="Avance2_14";
    TransitionIndex["Avance2_14"]=54;
    Transition[30].Id =30;
    Transition[30].label ="Avance2_2";
    TransitionIndex["Avance2_2"]=30;
    Transition[32].Id =32;
    Transition[32].label ="Avance2_3";
    TransitionIndex["Avance2_3"]=32;
    Transition[34].Id =34;
    Transition[34].label ="Avance2_4";
    TransitionIndex["Avance2_4"]=34;
    Transition[36].Id =36;
    Transition[36].label ="Avance2_5";
    TransitionIndex["Avance2_5"]=36;
    Transition[38].Id =38;
    Transition[38].label ="Avance2_6";
    TransitionIndex["Avance2_6"]=38;
    Transition[40].Id =40;
    Transition[40].label ="Avance2_7";
    TransitionIndex["Avance2_7"]=40;
    Transition[42].Id =42;
    Transition[42].label ="Avance2_8";
    TransitionIndex["Avance2_8"]=42;
    Transition[44].Id =44;
    Transition[44].label ="Avance2_9";
    TransitionIndex["Avance2_9"]=44;
    Transition[56].Id =56;
    Transition[56].label ="Avance3_1";
    TransitionIndex["Avance3_1"]=56;
    Transition[74].Id =74;
    Transition[74].label ="Avance3_10";
    TransitionIndex["Avance3_10"]=74;
    Transition[76].Id =76;
    Transition[76].label ="Avance3_11";
    TransitionIndex["Avance3_11"]=76;
    Transition[78].Id =78;
    Transition[78].label ="Avance3_12";
    TransitionIndex["Avance3_12"]=78;
    Transition[80].Id =80;
    Transition[80].label ="Avance3_13";
    TransitionIndex["Avance3_13"]=80;
    Transition[82].Id =82;
    Transition[82].label ="Avance3_14";
    TransitionIndex["Avance3_14"]=82;
    Transition[58].Id =58;
    Transition[58].label ="Avance3_2";
    TransitionIndex["Avance3_2"]=58;
    Transition[60].Id =60;
    Transition[60].label ="Avance3_3";
    TransitionIndex["Avance3_3"]=60;
    Transition[62].Id =62;
    Transition[62].label ="Avance3_4";
    TransitionIndex["Avance3_4"]=62;
    Transition[64].Id =64;
    Transition[64].label ="Avance3_5";
    TransitionIndex["Avance3_5"]=64;
    Transition[66].Id =66;
    Transition[66].label ="Avance3_6";
    TransitionIndex["Avance3_6"]=66;
    Transition[68].Id =68;
    Transition[68].label ="Avance3_7";
    TransitionIndex["Avance3_7"]=68;
    Transition[70].Id =70;
    Transition[70].label ="Avance3_8";
    TransitionIndex["Avance3_8"]=70;
    Transition[72].Id =72;
    Transition[72].label ="Avance3_9";
    TransitionIndex["Avance3_9"]=72;
    Transition[84].Id =84;
    Transition[84].label ="Avance4_1";
    TransitionIndex["Avance4_1"]=84;
    Transition[102].Id =102;
    Transition[102].label ="Avance4_10";
    TransitionIndex["Avance4_10"]=102;
    Transition[104].Id =104;
    Transition[104].label ="Avance4_11";
    TransitionIndex["Avance4_11"]=104;
    Transition[106].Id =106;
    Transition[106].label ="Avance4_12";
    TransitionIndex["Avance4_12"]=106;
    Transition[108].Id =108;
    Transition[108].label ="Avance4_13";
    TransitionIndex["Avance4_13"]=108;
    Transition[110].Id =110;
    Transition[110].label ="Avance4_14";
    TransitionIndex["Avance4_14"]=110;
    Transition[86].Id =86;
    Transition[86].label ="Avance4_2";
    TransitionIndex["Avance4_2"]=86;
    Transition[88].Id =88;
    Transition[88].label ="Avance4_3";
    TransitionIndex["Avance4_3"]=88;
    Transition[90].Id =90;
    Transition[90].label ="Avance4_4";
    TransitionIndex["Avance4_4"]=90;
    Transition[92].Id =92;
    Transition[92].label ="Avance4_5";
    TransitionIndex["Avance4_5"]=92;
    Transition[94].Id =94;
    Transition[94].label ="Avance4_6";
    TransitionIndex["Avance4_6"]=94;
    Transition[96].Id =96;
    Transition[96].label ="Avance4_7";
    TransitionIndex["Avance4_7"]=96;
    Transition[98].Id =98;
    Transition[98].label ="Avance4_8";
    TransitionIndex["Avance4_8"]=98;
    Transition[100].Id =100;
    Transition[100].label ="Avance4_9";
    TransitionIndex["Avance4_9"]=100;
    Transition[112].Id =112;
    Transition[112].label ="Avance5_1";
    TransitionIndex["Avance5_1"]=112;
    Transition[130].Id =130;
    Transition[130].label ="Avance5_10";
    TransitionIndex["Avance5_10"]=130;
    Transition[132].Id =132;
    Transition[132].label ="Avance5_11";
    TransitionIndex["Avance5_11"]=132;
    Transition[134].Id =134;
    Transition[134].label ="Avance5_12";
    TransitionIndex["Avance5_12"]=134;
    Transition[136].Id =136;
    Transition[136].label ="Avance5_13";
    TransitionIndex["Avance5_13"]=136;
    Transition[138].Id =138;
    Transition[138].label ="Avance5_14";
    TransitionIndex["Avance5_14"]=138;
    Transition[114].Id =114;
    Transition[114].label ="Avance5_2";
    TransitionIndex["Avance5_2"]=114;
    Transition[116].Id =116;
    Transition[116].label ="Avance5_3";
    TransitionIndex["Avance5_3"]=116;
    Transition[118].Id =118;
    Transition[118].label ="Avance5_4";
    TransitionIndex["Avance5_4"]=118;
    Transition[120].Id =120;
    Transition[120].label ="Avance5_5";
    TransitionIndex["Avance5_5"]=120;
    Transition[122].Id =122;
    Transition[122].label ="Avance5_6";
    TransitionIndex["Avance5_6"]=122;
    Transition[124].Id =124;
    Transition[124].label ="Avance5_7";
    TransitionIndex["Avance5_7"]=124;
    Transition[126].Id =126;
    Transition[126].label ="Avance5_8";
    TransitionIndex["Avance5_8"]=126;
    Transition[128].Id =128;
    Transition[128].label ="Avance5_9";
    TransitionIndex["Avance5_9"]=128;
    Transition[140].Id =140;
    Transition[140].label ="Puittrans";
    TransitionIndex["Puittrans"]=140;
    Transition[1].Id =1;
    Transition[1].label ="Recule1_1";
    TransitionIndex["Recule1_1"]=1;
    Transition[19].Id =19;
    Transition[19].label ="Recule1_10";
    TransitionIndex["Recule1_10"]=19;
    Transition[21].Id =21;
    Transition[21].label ="Recule1_11";
    TransitionIndex["Recule1_11"]=21;
    Transition[23].Id =23;
    Transition[23].label ="Recule1_12";
    TransitionIndex["Recule1_12"]=23;
    Transition[25].Id =25;
    Transition[25].label ="Recule1_13";
    TransitionIndex["Recule1_13"]=25;
    Transition[27].Id =27;
    Transition[27].label ="Recule1_14";
    TransitionIndex["Recule1_14"]=27;
    Transition[3].Id =3;
    Transition[3].label ="Recule1_2";
    TransitionIndex["Recule1_2"]=3;
    Transition[5].Id =5;
    Transition[5].label ="Recule1_3";
    TransitionIndex["Recule1_3"]=5;
    Transition[7].Id =7;
    Transition[7].label ="Recule1_4";
    TransitionIndex["Recule1_4"]=7;
    Transition[9].Id =9;
    Transition[9].label ="Recule1_5";
    TransitionIndex["Recule1_5"]=9;
    Transition[11].Id =11;
    Transition[11].label ="Recule1_6";
    TransitionIndex["Recule1_6"]=11;
    Transition[13].Id =13;
    Transition[13].label ="Recule1_7";
    TransitionIndex["Recule1_7"]=13;
    Transition[15].Id =15;
    Transition[15].label ="Recule1_8";
    TransitionIndex["Recule1_8"]=15;
    Transition[17].Id =17;
    Transition[17].label ="Recule1_9";
    TransitionIndex["Recule1_9"]=17;
    Transition[29].Id =29;
    Transition[29].label ="Recule2_1";
    TransitionIndex["Recule2_1"]=29;
    Transition[47].Id =47;
    Transition[47].label ="Recule2_10";
    TransitionIndex["Recule2_10"]=47;
    Transition[49].Id =49;
    Transition[49].label ="Recule2_11";
    TransitionIndex["Recule2_11"]=49;
    Transition[51].Id =51;
    Transition[51].label ="Recule2_12";
    TransitionIndex["Recule2_12"]=51;
    Transition[53].Id =53;
    Transition[53].label ="Recule2_13";
    TransitionIndex["Recule2_13"]=53;
    Transition[55].Id =55;
    Transition[55].label ="Recule2_14";
    TransitionIndex["Recule2_14"]=55;
    Transition[31].Id =31;
    Transition[31].label ="Recule2_2";
    TransitionIndex["Recule2_2"]=31;
    Transition[33].Id =33;
    Transition[33].label ="Recule2_3";
    TransitionIndex["Recule2_3"]=33;
    Transition[35].Id =35;
    Transition[35].label ="Recule2_4";
    TransitionIndex["Recule2_4"]=35;
    Transition[37].Id =37;
    Transition[37].label ="Recule2_5";
    TransitionIndex["Recule2_5"]=37;
    Transition[39].Id =39;
    Transition[39].label ="Recule2_6";
    TransitionIndex["Recule2_6"]=39;
    Transition[41].Id =41;
    Transition[41].label ="Recule2_7";
    TransitionIndex["Recule2_7"]=41;
    Transition[43].Id =43;
    Transition[43].label ="Recule2_8";
    TransitionIndex["Recule2_8"]=43;
    Transition[45].Id =45;
    Transition[45].label ="Recule2_9";
    TransitionIndex["Recule2_9"]=45;
    Transition[57].Id =57;
    Transition[57].label ="Recule3_1";
    TransitionIndex["Recule3_1"]=57;
    Transition[75].Id =75;
    Transition[75].label ="Recule3_10";
    TransitionIndex["Recule3_10"]=75;
    Transition[77].Id =77;
    Transition[77].label ="Recule3_11";
    TransitionIndex["Recule3_11"]=77;
    Transition[79].Id =79;
    Transition[79].label ="Recule3_12";
    TransitionIndex["Recule3_12"]=79;
    Transition[81].Id =81;
    Transition[81].label ="Recule3_13";
    TransitionIndex["Recule3_13"]=81;
    Transition[83].Id =83;
    Transition[83].label ="Recule3_14";
    TransitionIndex["Recule3_14"]=83;
    Transition[59].Id =59;
    Transition[59].label ="Recule3_2";
    TransitionIndex["Recule3_2"]=59;
    Transition[61].Id =61;
    Transition[61].label ="Recule3_3";
    TransitionIndex["Recule3_3"]=61;
    Transition[63].Id =63;
    Transition[63].label ="Recule3_4";
    TransitionIndex["Recule3_4"]=63;
    Transition[65].Id =65;
    Transition[65].label ="Recule3_5";
    TransitionIndex["Recule3_5"]=65;
    Transition[67].Id =67;
    Transition[67].label ="Recule3_6";
    TransitionIndex["Recule3_6"]=67;
    Transition[69].Id =69;
    Transition[69].label ="Recule3_7";
    TransitionIndex["Recule3_7"]=69;
    Transition[71].Id =71;
    Transition[71].label ="Recule3_8";
    TransitionIndex["Recule3_8"]=71;
    Transition[73].Id =73;
    Transition[73].label ="Recule3_9";
    TransitionIndex["Recule3_9"]=73;
    Transition[85].Id =85;
    Transition[85].label ="Recule4_1";
    TransitionIndex["Recule4_1"]=85;
    Transition[103].Id =103;
    Transition[103].label ="Recule4_10";
    TransitionIndex["Recule4_10"]=103;
    Transition[105].Id =105;
    Transition[105].label ="Recule4_11";
    TransitionIndex["Recule4_11"]=105;
    Transition[107].Id =107;
    Transition[107].label ="Recule4_12";
    TransitionIndex["Recule4_12"]=107;
    Transition[109].Id =109;
    Transition[109].label ="Recule4_13";
    TransitionIndex["Recule4_13"]=109;
    Transition[111].Id =111;
    Transition[111].label ="Recule4_14";
    TransitionIndex["Recule4_14"]=111;
    Transition[87].Id =87;
    Transition[87].label ="Recule4_2";
    TransitionIndex["Recule4_2"]=87;
    Transition[89].Id =89;
    Transition[89].label ="Recule4_3";
    TransitionIndex["Recule4_3"]=89;
    Transition[91].Id =91;
    Transition[91].label ="Recule4_4";
    TransitionIndex["Recule4_4"]=91;
    Transition[93].Id =93;
    Transition[93].label ="Recule4_5";
    TransitionIndex["Recule4_5"]=93;
    Transition[95].Id =95;
    Transition[95].label ="Recule4_6";
    TransitionIndex["Recule4_6"]=95;
    Transition[97].Id =97;
    Transition[97].label ="Recule4_7";
    TransitionIndex["Recule4_7"]=97;
    Transition[99].Id =99;
    Transition[99].label ="Recule4_8";
    TransitionIndex["Recule4_8"]=99;
    Transition[101].Id =101;
    Transition[101].label ="Recule4_9";
    TransitionIndex["Recule4_9"]=101;
    Transition[113].Id =113;
    Transition[113].label ="Recule5_1";
    TransitionIndex["Recule5_1"]=113;
    Transition[131].Id =131;
    Transition[131].label ="Recule5_10";
    TransitionIndex["Recule5_10"]=131;
    Transition[133].Id =133;
    Transition[133].label ="Recule5_11";
    TransitionIndex["Recule5_11"]=133;
    Transition[135].Id =135;
    Transition[135].label ="Recule5_12";
    TransitionIndex["Recule5_12"]=135;
    Transition[137].Id =137;
    Transition[137].label ="Recule5_13";
    TransitionIndex["Recule5_13"]=137;
    Transition[139].Id =139;
    Transition[139].label ="Recule5_14";
    TransitionIndex["Recule5_14"]=139;
    Transition[115].Id =115;
    Transition[115].label ="Recule5_2";
    TransitionIndex["Recule5_2"]=115;
    Transition[117].Id =117;
    Transition[117].label ="Recule5_3";
    TransitionIndex["Recule5_3"]=117;
    Transition[119].Id =119;
    Transition[119].label ="Recule5_4";
    TransitionIndex["Recule5_4"]=119;
    Transition[121].Id =121;
    Transition[121].label ="Recule5_5";
    TransitionIndex["Recule5_5"]=121;
    Transition[123].Id =123;
    Transition[123].label ="Recule5_6";
    TransitionIndex["Recule5_6"]=123;
    Transition[125].Id =125;
    Transition[125].label ="Recule5_7";
    TransitionIndex["Recule5_7"]=125;
    Transition[127].Id =127;
    Transition[127].label ="Recule5_8";
    TransitionIndex["Recule5_8"]=127;
    Transition[129].Id =129;
    Transition[129].label ="Recule5_9";
    TransitionIndex["Recule5_9"]=129;
    Transition[0].transType = Timed;
    Transition[0].DistType = "EXPONENTIAL";
    Transition[0].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[0].priority = "1";
    Transition[0].MarkingDependent = 1;
    Transition[0].weight = "1 ";

    Transition[1].transType = Timed;
    Transition[1].DistType = "EXPONENTIAL";
    Transition[1].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[1].priority = "1";
    Transition[1].MarkingDependent = 1;
    Transition[1].weight = "1 ";

    Transition[2].transType = Timed;
    Transition[2].DistType = "EXPONENTIAL";
    Transition[2].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[2].priority = "1";
    Transition[2].MarkingDependent = 1;
    Transition[2].weight = "1 ";

    Transition[3].transType = Timed;
    Transition[3].DistType = "EXPONENTIAL";
    Transition[3].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[3].priority = "1";
    Transition[3].MarkingDependent = 1;
    Transition[3].weight = "1 ";

    Transition[4].transType = Timed;
    Transition[4].DistType = "EXPONENTIAL";
    Transition[4].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[4].priority = "1";
    Transition[4].MarkingDependent = 1;
    Transition[4].weight = "1 ";

    Transition[5].transType = Timed;
    Transition[5].DistType = "EXPONENTIAL";
    Transition[5].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[5].priority = "1";
    Transition[5].MarkingDependent = 1;
    Transition[5].weight = "1 ";

    Transition[6].transType = Timed;
    Transition[6].DistType = "EXPONENTIAL";
    Transition[6].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[6].priority = "1";
    Transition[6].MarkingDependent = 1;
    Transition[6].weight = "1 ";

    Transition[7].transType = Timed;
    Transition[7].DistType = "EXPONENTIAL";
    Transition[7].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[7].priority = "1";
    Transition[7].MarkingDependent = 1;
    Transition[7].weight = "1 ";

    Transition[8].transType = Timed;
    Transition[8].DistType = "EXPONENTIAL";
    Transition[8].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[8].priority = "1";
    Transition[8].MarkingDependent = 1;
    Transition[8].weight = "1 ";

    Transition[9].transType = Timed;
    Transition[9].DistType = "EXPONENTIAL";
    Transition[9].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[9].priority = "1";
    Transition[9].MarkingDependent = 1;
    Transition[9].weight = "1 ";

    Transition[10].transType = Timed;
    Transition[10].DistType = "EXPONENTIAL";
    Transition[10].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[10].priority = "1";
    Transition[10].MarkingDependent = 1;
    Transition[10].weight = "1 ";

    Transition[11].transType = Timed;
    Transition[11].DistType = "EXPONENTIAL";
    Transition[11].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[11].priority = "1";
    Transition[11].MarkingDependent = 1;
    Transition[11].weight = "1 ";

    Transition[12].transType = Timed;
    Transition[12].DistType = "EXPONENTIAL";
    Transition[12].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[12].priority = "1";
    Transition[12].MarkingDependent = 1;
    Transition[12].weight = "1 ";

    Transition[13].transType = Timed;
    Transition[13].DistType = "EXPONENTIAL";
    Transition[13].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[13].priority = "1";
    Transition[13].MarkingDependent = 1;
    Transition[13].weight = "1 ";

    Transition[14].transType = Timed;
    Transition[14].DistType = "EXPONENTIAL";
    Transition[14].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[14].priority = "1";
    Transition[14].MarkingDependent = 1;
    Transition[14].weight = "1 ";

    Transition[15].transType = Timed;
    Transition[15].DistType = "EXPONENTIAL";
    Transition[15].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[15].priority = "1";
    Transition[15].MarkingDependent = 1;
    Transition[15].weight = "1 ";

    Transition[16].transType = Timed;
    Transition[16].DistType = "EXPONENTIAL";
    Transition[16].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[16].priority = "1";
    Transition[16].MarkingDependent = 1;
    Transition[16].weight = "1 ";

    Transition[17].transType = Timed;
    Transition[17].DistType = "EXPONENTIAL";
    Transition[17].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[17].priority = "1";
    Transition[17].MarkingDependent = 1;
    Transition[17].weight = "1 ";

    Transition[18].transType = Timed;
    Transition[18].DistType = "EXPONENTIAL";
    Transition[18].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[18].priority = "1";
    Transition[18].MarkingDependent = 1;
    Transition[18].weight = "1 ";

    Transition[19].transType = Timed;
    Transition[19].DistType = "EXPONENTIAL";
    Transition[19].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[19].priority = "1";
    Transition[19].MarkingDependent = 1;
    Transition[19].weight = "1 ";

    Transition[20].transType = Timed;
    Transition[20].DistType = "EXPONENTIAL";
    Transition[20].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[20].priority = "1";
    Transition[20].MarkingDependent = 1;
    Transition[20].weight = "1 ";

    Transition[21].transType = Timed;
    Transition[21].DistType = "EXPONENTIAL";
    Transition[21].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[21].priority = "1";
    Transition[21].MarkingDependent = 1;
    Transition[21].weight = "1 ";

    Transition[22].transType = Timed;
    Transition[22].DistType = "EXPONENTIAL";
    Transition[22].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[22].priority = "1";
    Transition[22].MarkingDependent = 1;
    Transition[22].weight = "1 ";

    Transition[23].transType = Timed;
    Transition[23].DistType = "EXPONENTIAL";
    Transition[23].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[23].priority = "1";
    Transition[23].MarkingDependent = 1;
    Transition[23].weight = "1 ";

    Transition[24].transType = Timed;
    Transition[24].DistType = "EXPONENTIAL";
    Transition[24].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[24].priority = "1";
    Transition[24].MarkingDependent = 1;
    Transition[24].weight = "1 ";

    Transition[25].transType = Timed;
    Transition[25].DistType = "EXPONENTIAL";
    Transition[25].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[25].priority = "1";
    Transition[25].MarkingDependent = 1;
    Transition[25].weight = "1 ";

    Transition[26].transType = Timed;
    Transition[26].DistType = "EXPONENTIAL";
    Transition[26].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[26].priority = "1";
    Transition[26].MarkingDependent = 1;
    Transition[26].weight = "1 ";

    Transition[27].transType = Timed;
    Transition[27].DistType = "EXPONENTIAL";
    Transition[27].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[27].priority = "1";
    Transition[27].MarkingDependent = 1;
    Transition[27].weight = "1 ";

    Transition[28].transType = Timed;
    Transition[28].DistType = "EXPONENTIAL";
    Transition[28].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[28].priority = "1";
    Transition[28].MarkingDependent = 1;
    Transition[28].weight = "1 ";

    Transition[29].transType = Timed;
    Transition[29].DistType = "EXPONENTIAL";
    Transition[29].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[29].priority = "1";
    Transition[29].MarkingDependent = 1;
    Transition[29].weight = "1 ";

    Transition[30].transType = Timed;
    Transition[30].DistType = "EXPONENTIAL";
    Transition[30].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[30].priority = "1";
    Transition[30].MarkingDependent = 1;
    Transition[30].weight = "1 ";

    Transition[31].transType = Timed;
    Transition[31].DistType = "EXPONENTIAL";
    Transition[31].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[31].priority = "1";
    Transition[31].MarkingDependent = 1;
    Transition[31].weight = "1 ";

    Transition[32].transType = Timed;
    Transition[32].DistType = "EXPONENTIAL";
    Transition[32].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[32].priority = "1";
    Transition[32].MarkingDependent = 1;
    Transition[32].weight = "1 ";

    Transition[33].transType = Timed;
    Transition[33].DistType = "EXPONENTIAL";
    Transition[33].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[33].priority = "1";
    Transition[33].MarkingDependent = 1;
    Transition[33].weight = "1 ";

    Transition[34].transType = Timed;
    Transition[34].DistType = "EXPONENTIAL";
    Transition[34].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[34].priority = "1";
    Transition[34].MarkingDependent = 1;
    Transition[34].weight = "1 ";

    Transition[35].transType = Timed;
    Transition[35].DistType = "EXPONENTIAL";
    Transition[35].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[35].priority = "1";
    Transition[35].MarkingDependent = 1;
    Transition[35].weight = "1 ";

    Transition[36].transType = Timed;
    Transition[36].DistType = "EXPONENTIAL";
    Transition[36].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[36].priority = "1";
    Transition[36].MarkingDependent = 1;
    Transition[36].weight = "1 ";

    Transition[37].transType = Timed;
    Transition[37].DistType = "EXPONENTIAL";
    Transition[37].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[37].priority = "1";
    Transition[37].MarkingDependent = 1;
    Transition[37].weight = "1 ";

    Transition[38].transType = Timed;
    Transition[38].DistType = "EXPONENTIAL";
    Transition[38].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[38].priority = "1";
    Transition[38].MarkingDependent = 1;
    Transition[38].weight = "1 ";

    Transition[39].transType = Timed;
    Transition[39].DistType = "EXPONENTIAL";
    Transition[39].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[39].priority = "1";
    Transition[39].MarkingDependent = 1;
    Transition[39].weight = "1 ";

    Transition[40].transType = Timed;
    Transition[40].DistType = "EXPONENTIAL";
    Transition[40].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[40].priority = "1";
    Transition[40].MarkingDependent = 1;
    Transition[40].weight = "1 ";

    Transition[41].transType = Timed;
    Transition[41].DistType = "EXPONENTIAL";
    Transition[41].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[41].priority = "1";
    Transition[41].MarkingDependent = 1;
    Transition[41].weight = "1 ";

    Transition[42].transType = Timed;
    Transition[42].DistType = "EXPONENTIAL";
    Transition[42].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[42].priority = "1";
    Transition[42].MarkingDependent = 1;
    Transition[42].weight = "1 ";

    Transition[43].transType = Timed;
    Transition[43].DistType = "EXPONENTIAL";
    Transition[43].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[43].priority = "1";
    Transition[43].MarkingDependent = 1;
    Transition[43].weight = "1 ";

    Transition[44].transType = Timed;
    Transition[44].DistType = "EXPONENTIAL";
    Transition[44].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[44].priority = "1";
    Transition[44].MarkingDependent = 1;
    Transition[44].weight = "1 ";

    Transition[45].transType = Timed;
    Transition[45].DistType = "EXPONENTIAL";
    Transition[45].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[45].priority = "1";
    Transition[45].MarkingDependent = 1;
    Transition[45].weight = "1 ";

    Transition[46].transType = Timed;
    Transition[46].DistType = "EXPONENTIAL";
    Transition[46].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[46].priority = "1";
    Transition[46].MarkingDependent = 1;
    Transition[46].weight = "1 ";

    Transition[47].transType = Timed;
    Transition[47].DistType = "EXPONENTIAL";
    Transition[47].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[47].priority = "1";
    Transition[47].MarkingDependent = 1;
    Transition[47].weight = "1 ";

    Transition[48].transType = Timed;
    Transition[48].DistType = "EXPONENTIAL";
    Transition[48].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[48].priority = "1";
    Transition[48].MarkingDependent = 1;
    Transition[48].weight = "1 ";

    Transition[49].transType = Timed;
    Transition[49].DistType = "EXPONENTIAL";
    Transition[49].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[49].priority = "1";
    Transition[49].MarkingDependent = 1;
    Transition[49].weight = "1 ";

    Transition[50].transType = Timed;
    Transition[50].DistType = "EXPONENTIAL";
    Transition[50].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[50].priority = "1";
    Transition[50].MarkingDependent = 1;
    Transition[50].weight = "1 ";

    Transition[51].transType = Timed;
    Transition[51].DistType = "EXPONENTIAL";
    Transition[51].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[51].priority = "1";
    Transition[51].MarkingDependent = 1;
    Transition[51].weight = "1 ";

    Transition[52].transType = Timed;
    Transition[52].DistType = "EXPONENTIAL";
    Transition[52].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[52].priority = "1";
    Transition[52].MarkingDependent = 1;
    Transition[52].weight = "1 ";

    Transition[53].transType = Timed;
    Transition[53].DistType = "EXPONENTIAL";
    Transition[53].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[53].priority = "1";
    Transition[53].MarkingDependent = 1;
    Transition[53].weight = "1 ";

    Transition[54].transType = Timed;
    Transition[54].DistType = "EXPONENTIAL";
    Transition[54].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[54].priority = "1";
    Transition[54].MarkingDependent = 1;
    Transition[54].weight = "1 ";

    Transition[55].transType = Timed;
    Transition[55].DistType = "EXPONENTIAL";
    Transition[55].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[55].priority = "1";
    Transition[55].MarkingDependent = 1;
    Transition[55].weight = "1 ";

    Transition[56].transType = Timed;
    Transition[56].DistType = "EXPONENTIAL";
    Transition[56].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[56].priority = "1";
    Transition[56].MarkingDependent = 1;
    Transition[56].weight = "1 ";

    Transition[57].transType = Timed;
    Transition[57].DistType = "EXPONENTIAL";
    Transition[57].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[57].priority = "1";
    Transition[57].MarkingDependent = 1;
    Transition[57].weight = "1 ";

    Transition[58].transType = Timed;
    Transition[58].DistType = "EXPONENTIAL";
    Transition[58].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[58].priority = "1";
    Transition[58].MarkingDependent = 1;
    Transition[58].weight = "1 ";

    Transition[59].transType = Timed;
    Transition[59].DistType = "EXPONENTIAL";
    Transition[59].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[59].priority = "1";
    Transition[59].MarkingDependent = 1;
    Transition[59].weight = "1 ";

    Transition[60].transType = Timed;
    Transition[60].DistType = "EXPONENTIAL";
    Transition[60].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[60].priority = "1";
    Transition[60].MarkingDependent = 1;
    Transition[60].weight = "1 ";

    Transition[61].transType = Timed;
    Transition[61].DistType = "EXPONENTIAL";
    Transition[61].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[61].priority = "1";
    Transition[61].MarkingDependent = 1;
    Transition[61].weight = "1 ";

    Transition[62].transType = Timed;
    Transition[62].DistType = "EXPONENTIAL";
    Transition[62].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[62].priority = "1";
    Transition[62].MarkingDependent = 1;
    Transition[62].weight = "1 ";

    Transition[63].transType = Timed;
    Transition[63].DistType = "EXPONENTIAL";
    Transition[63].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[63].priority = "1";
    Transition[63].MarkingDependent = 1;
    Transition[63].weight = "1 ";

    Transition[64].transType = Timed;
    Transition[64].DistType = "EXPONENTIAL";
    Transition[64].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[64].priority = "1";
    Transition[64].MarkingDependent = 1;
    Transition[64].weight = "1 ";

    Transition[65].transType = Timed;
    Transition[65].DistType = "EXPONENTIAL";
    Transition[65].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[65].priority = "1";
    Transition[65].MarkingDependent = 1;
    Transition[65].weight = "1 ";

    Transition[66].transType = Timed;
    Transition[66].DistType = "EXPONENTIAL";
    Transition[66].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[66].priority = "1";
    Transition[66].MarkingDependent = 1;
    Transition[66].weight = "1 ";

    Transition[67].transType = Timed;
    Transition[67].DistType = "EXPONENTIAL";
    Transition[67].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[67].priority = "1";
    Transition[67].MarkingDependent = 1;
    Transition[67].weight = "1 ";

    Transition[68].transType = Timed;
    Transition[68].DistType = "EXPONENTIAL";
    Transition[68].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[68].priority = "1";
    Transition[68].MarkingDependent = 1;
    Transition[68].weight = "1 ";

    Transition[69].transType = Timed;
    Transition[69].DistType = "EXPONENTIAL";
    Transition[69].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[69].priority = "1";
    Transition[69].MarkingDependent = 1;
    Transition[69].weight = "1 ";

    Transition[70].transType = Timed;
    Transition[70].DistType = "EXPONENTIAL";
    Transition[70].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[70].priority = "1";
    Transition[70].MarkingDependent = 1;
    Transition[70].weight = "1 ";

    Transition[71].transType = Timed;
    Transition[71].DistType = "EXPONENTIAL";
    Transition[71].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[71].priority = "1";
    Transition[71].MarkingDependent = 1;
    Transition[71].weight = "1 ";

    Transition[72].transType = Timed;
    Transition[72].DistType = "EXPONENTIAL";
    Transition[72].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[72].priority = "1";
    Transition[72].MarkingDependent = 1;
    Transition[72].weight = "1 ";

    Transition[73].transType = Timed;
    Transition[73].DistType = "EXPONENTIAL";
    Transition[73].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[73].priority = "1";
    Transition[73].MarkingDependent = 1;
    Transition[73].weight = "1 ";

    Transition[74].transType = Timed;
    Transition[74].DistType = "EXPONENTIAL";
    Transition[74].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[74].priority = "1";
    Transition[74].MarkingDependent = 1;
    Transition[74].weight = "1 ";

    Transition[75].transType = Timed;
    Transition[75].DistType = "EXPONENTIAL";
    Transition[75].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[75].priority = "1";
    Transition[75].MarkingDependent = 1;
    Transition[75].weight = "1 ";

    Transition[76].transType = Timed;
    Transition[76].DistType = "EXPONENTIAL";
    Transition[76].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[76].priority = "1";
    Transition[76].MarkingDependent = 1;
    Transition[76].weight = "1 ";

    Transition[77].transType = Timed;
    Transition[77].DistType = "EXPONENTIAL";
    Transition[77].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[77].priority = "1";
    Transition[77].MarkingDependent = 1;
    Transition[77].weight = "1 ";

    Transition[78].transType = Timed;
    Transition[78].DistType = "EXPONENTIAL";
    Transition[78].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[78].priority = "1";
    Transition[78].MarkingDependent = 1;
    Transition[78].weight = "1 ";

    Transition[79].transType = Timed;
    Transition[79].DistType = "EXPONENTIAL";
    Transition[79].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[79].priority = "1";
    Transition[79].MarkingDependent = 1;
    Transition[79].weight = "1 ";

    Transition[80].transType = Timed;
    Transition[80].DistType = "EXPONENTIAL";
    Transition[80].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[80].priority = "1";
    Transition[80].MarkingDependent = 1;
    Transition[80].weight = "1 ";

    Transition[81].transType = Timed;
    Transition[81].DistType = "EXPONENTIAL";
    Transition[81].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[81].priority = "1";
    Transition[81].MarkingDependent = 1;
    Transition[81].weight = "1 ";

    Transition[82].transType = Timed;
    Transition[82].DistType = "EXPONENTIAL";
    Transition[82].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[82].priority = "1";
    Transition[82].MarkingDependent = 1;
    Transition[82].weight = "1 ";

    Transition[83].transType = Timed;
    Transition[83].DistType = "EXPONENTIAL";
    Transition[83].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[83].priority = "1";
    Transition[83].MarkingDependent = 1;
    Transition[83].weight = "1 ";

    Transition[84].transType = Timed;
    Transition[84].DistType = "EXPONENTIAL";
    Transition[84].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[84].priority = "1";
    Transition[84].MarkingDependent = 1;
    Transition[84].weight = "1 ";

    Transition[85].transType = Timed;
    Transition[85].DistType = "EXPONENTIAL";
    Transition[85].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[85].priority = "1";
    Transition[85].MarkingDependent = 1;
    Transition[85].weight = "1 ";

    Transition[86].transType = Timed;
    Transition[86].DistType = "EXPONENTIAL";
    Transition[86].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[86].priority = "1";
    Transition[86].MarkingDependent = 1;
    Transition[86].weight = "1 ";

    Transition[87].transType = Timed;
    Transition[87].DistType = "EXPONENTIAL";
    Transition[87].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[87].priority = "1";
    Transition[87].MarkingDependent = 1;
    Transition[87].weight = "1 ";

    Transition[88].transType = Timed;
    Transition[88].DistType = "EXPONENTIAL";
    Transition[88].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[88].priority = "1";
    Transition[88].MarkingDependent = 1;
    Transition[88].weight = "1 ";

    Transition[89].transType = Timed;
    Transition[89].DistType = "EXPONENTIAL";
    Transition[89].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[89].priority = "1";
    Transition[89].MarkingDependent = 1;
    Transition[89].weight = "1 ";

    Transition[90].transType = Timed;
    Transition[90].DistType = "EXPONENTIAL";
    Transition[90].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[90].priority = "1";
    Transition[90].MarkingDependent = 1;
    Transition[90].weight = "1 ";

    Transition[91].transType = Timed;
    Transition[91].DistType = "EXPONENTIAL";
    Transition[91].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[91].priority = "1";
    Transition[91].MarkingDependent = 1;
    Transition[91].weight = "1 ";

    Transition[92].transType = Timed;
    Transition[92].DistType = "EXPONENTIAL";
    Transition[92].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[92].priority = "1";
    Transition[92].MarkingDependent = 1;
    Transition[92].weight = "1 ";

    Transition[93].transType = Timed;
    Transition[93].DistType = "EXPONENTIAL";
    Transition[93].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[93].priority = "1";
    Transition[93].MarkingDependent = 1;
    Transition[93].weight = "1 ";

    Transition[94].transType = Timed;
    Transition[94].DistType = "EXPONENTIAL";
    Transition[94].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[94].priority = "1";
    Transition[94].MarkingDependent = 1;
    Transition[94].weight = "1 ";

    Transition[95].transType = Timed;
    Transition[95].DistType = "EXPONENTIAL";
    Transition[95].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[95].priority = "1";
    Transition[95].MarkingDependent = 1;
    Transition[95].weight = "1 ";

    Transition[96].transType = Timed;
    Transition[96].DistType = "EXPONENTIAL";
    Transition[96].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[96].priority = "1";
    Transition[96].MarkingDependent = 1;
    Transition[96].weight = "1 ";

    Transition[97].transType = Timed;
    Transition[97].DistType = "EXPONENTIAL";
    Transition[97].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[97].priority = "1";
    Transition[97].MarkingDependent = 1;
    Transition[97].weight = "1 ";

    Transition[98].transType = Timed;
    Transition[98].DistType = "EXPONENTIAL";
    Transition[98].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[98].priority = "1";
    Transition[98].MarkingDependent = 1;
    Transition[98].weight = "1 ";

    Transition[99].transType = Timed;
    Transition[99].DistType = "EXPONENTIAL";
    Transition[99].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[99].priority = "1";
    Transition[99].MarkingDependent = 1;
    Transition[99].weight = "1 ";

    Transition[100].transType = Timed;
    Transition[100].DistType = "EXPONENTIAL";
    Transition[100].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[100].priority = "1";
    Transition[100].MarkingDependent = 1;
    Transition[100].weight = "1 ";

    Transition[101].transType = Timed;
    Transition[101].DistType = "EXPONENTIAL";
    Transition[101].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[101].priority = "1";
    Transition[101].MarkingDependent = 1;
    Transition[101].weight = "1 ";

    Transition[102].transType = Timed;
    Transition[102].DistType = "EXPONENTIAL";
    Transition[102].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[102].priority = "1";
    Transition[102].MarkingDependent = 1;
    Transition[102].weight = "1 ";

    Transition[103].transType = Timed;
    Transition[103].DistType = "EXPONENTIAL";
    Transition[103].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[103].priority = "1";
    Transition[103].MarkingDependent = 1;
    Transition[103].weight = "1 ";

    Transition[104].transType = Timed;
    Transition[104].DistType = "EXPONENTIAL";
    Transition[104].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[104].priority = "1";
    Transition[104].MarkingDependent = 1;
    Transition[104].weight = "1 ";

    Transition[105].transType = Timed;
    Transition[105].DistType = "EXPONENTIAL";
    Transition[105].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[105].priority = "1";
    Transition[105].MarkingDependent = 1;
    Transition[105].weight = "1 ";

    Transition[106].transType = Timed;
    Transition[106].DistType = "EXPONENTIAL";
    Transition[106].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[106].priority = "1";
    Transition[106].MarkingDependent = 1;
    Transition[106].weight = "1 ";

    Transition[107].transType = Timed;
    Transition[107].DistType = "EXPONENTIAL";
    Transition[107].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[107].priority = "1";
    Transition[107].MarkingDependent = 1;
    Transition[107].weight = "1 ";

    Transition[108].transType = Timed;
    Transition[108].DistType = "EXPONENTIAL";
    Transition[108].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[108].priority = "1";
    Transition[108].MarkingDependent = 1;
    Transition[108].weight = "1 ";

    Transition[109].transType = Timed;
    Transition[109].DistType = "EXPONENTIAL";
    Transition[109].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[109].priority = "1";
    Transition[109].MarkingDependent = 1;
    Transition[109].weight = "1 ";

    Transition[110].transType = Timed;
    Transition[110].DistType = "EXPONENTIAL";
    Transition[110].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[110].priority = "1";
    Transition[110].MarkingDependent = 1;
    Transition[110].weight = "1 ";

    Transition[111].transType = Timed;
    Transition[111].DistType = "EXPONENTIAL";
    Transition[111].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[111].priority = "1";
    Transition[111].MarkingDependent = 1;
    Transition[111].weight = "1 ";

    Transition[112].transType = Timed;
    Transition[112].DistType = "EXPONENTIAL";
    Transition[112].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[112].priority = "1";
    Transition[112].MarkingDependent = 1;
    Transition[112].weight = "1 ";

    Transition[113].transType = Timed;
    Transition[113].DistType = "EXPONENTIAL";
    Transition[113].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[113].priority = "1";
    Transition[113].MarkingDependent = 1;
    Transition[113].weight = "1 ";

    Transition[114].transType = Timed;
    Transition[114].DistType = "EXPONENTIAL";
    Transition[114].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[114].priority = "1";
    Transition[114].MarkingDependent = 1;
    Transition[114].weight = "1 ";

    Transition[115].transType = Timed;
    Transition[115].DistType = "EXPONENTIAL";
    Transition[115].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[115].priority = "1";
    Transition[115].MarkingDependent = 1;
    Transition[115].weight = "1 ";

    Transition[116].transType = Timed;
    Transition[116].DistType = "EXPONENTIAL";
    Transition[116].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[116].priority = "1";
    Transition[116].MarkingDependent = 1;
    Transition[116].weight = "1 ";

    Transition[117].transType = Timed;
    Transition[117].DistType = "EXPONENTIAL";
    Transition[117].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[117].priority = "1";
    Transition[117].MarkingDependent = 1;
    Transition[117].weight = "1 ";

    Transition[118].transType = Timed;
    Transition[118].DistType = "EXPONENTIAL";
    Transition[118].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[118].priority = "1";
    Transition[118].MarkingDependent = 1;
    Transition[118].weight = "1 ";

    Transition[119].transType = Timed;
    Transition[119].DistType = "EXPONENTIAL";
    Transition[119].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[119].priority = "1";
    Transition[119].MarkingDependent = 1;
    Transition[119].weight = "1 ";

    Transition[120].transType = Timed;
    Transition[120].DistType = "EXPONENTIAL";
    Transition[120].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[120].priority = "1";
    Transition[120].MarkingDependent = 1;
    Transition[120].weight = "1 ";

    Transition[121].transType = Timed;
    Transition[121].DistType = "EXPONENTIAL";
    Transition[121].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[121].priority = "1";
    Transition[121].MarkingDependent = 1;
    Transition[121].weight = "1 ";

    Transition[122].transType = Timed;
    Transition[122].DistType = "EXPONENTIAL";
    Transition[122].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[122].priority = "1";
    Transition[122].MarkingDependent = 1;
    Transition[122].weight = "1 ";

    Transition[123].transType = Timed;
    Transition[123].DistType = "EXPONENTIAL";
    Transition[123].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[123].priority = "1";
    Transition[123].MarkingDependent = 1;
    Transition[123].weight = "1 ";

    Transition[124].transType = Timed;
    Transition[124].DistType = "EXPONENTIAL";
    Transition[124].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[124].priority = "1";
    Transition[124].MarkingDependent = 1;
    Transition[124].weight = "1 ";

    Transition[125].transType = Timed;
    Transition[125].DistType = "EXPONENTIAL";
    Transition[125].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[125].priority = "1";
    Transition[125].MarkingDependent = 1;
    Transition[125].weight = "1 ";

    Transition[126].transType = Timed;
    Transition[126].DistType = "EXPONENTIAL";
    Transition[126].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[126].priority = "1";
    Transition[126].MarkingDependent = 1;
    Transition[126].weight = "1 ";

    Transition[127].transType = Timed;
    Transition[127].DistType = "EXPONENTIAL";
    Transition[127].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[127].priority = "1";
    Transition[127].MarkingDependent = 1;
    Transition[127].weight = "1 ";

    Transition[128].transType = Timed;
    Transition[128].DistType = "EXPONENTIAL";
    Transition[128].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[128].priority = "1";
    Transition[128].MarkingDependent = 1;
    Transition[128].weight = "1 ";

    Transition[129].transType = Timed;
    Transition[129].DistType = "EXPONENTIAL";
    Transition[129].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[129].priority = "1";
    Transition[129].MarkingDependent = 1;
    Transition[129].weight = "1 ";

    Transition[130].transType = Timed;
    Transition[130].DistType = "EXPONENTIAL";
    Transition[130].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[130].priority = "1";
    Transition[130].MarkingDependent = 1;
    Transition[130].weight = "1 ";

    Transition[131].transType = Timed;
    Transition[131].DistType = "EXPONENTIAL";
    Transition[131].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[131].priority = "1";
    Transition[131].MarkingDependent = 1;
    Transition[131].weight = "1 ";

    Transition[132].transType = Timed;
    Transition[132].DistType = "EXPONENTIAL";
    Transition[132].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[132].priority = "1";
    Transition[132].MarkingDependent = 1;
    Transition[132].weight = "1 ";

    Transition[133].transType = Timed;
    Transition[133].DistType = "EXPONENTIAL";
    Transition[133].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[133].priority = "1";
    Transition[133].MarkingDependent = 1;
    Transition[133].weight = "1 ";

    Transition[134].transType = Timed;
    Transition[134].DistType = "EXPONENTIAL";
    Transition[134].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[134].priority = "1";
    Transition[134].MarkingDependent = 1;
    Transition[134].weight = "1 ";

    Transition[135].transType = Timed;
    Transition[135].DistType = "EXPONENTIAL";
    Transition[135].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[135].priority = "1";
    Transition[135].MarkingDependent = 1;
    Transition[135].weight = "1 ";

    Transition[136].transType = Timed;
    Transition[136].DistType = "EXPONENTIAL";
    Transition[136].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[136].priority = "1";
    Transition[136].MarkingDependent = 1;
    Transition[136].weight = "1 ";

    Transition[137].transType = Timed;
    Transition[137].DistType = "EXPONENTIAL";
    Transition[137].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[137].priority = "1";
    Transition[137].MarkingDependent = 1;
    Transition[137].weight = "1 ";

    Transition[138].transType = Timed;
    Transition[138].DistType = "EXPONENTIAL";
    Transition[138].DistParams.push_back(" 0.3 + 0 *  Marking[ 150 ] " );
    Transition[138].priority = "1";
    Transition[138].MarkingDependent = 1;
    Transition[138].weight = "1 ";

    Transition[139].transType = Timed;
    Transition[139].DistType = "EXPONENTIAL";
    Transition[139].DistParams.push_back(" 0.7 + 0 *  Marking[ 150 ] " );
    Transition[139].priority = "1";
    Transition[139].MarkingDependent = 1;
    Transition[139].weight = "1 ";

    Transition[140].transType = Timed;
    Transition[140].DistType = "EXPONENTIAL";
    Transition[140].DistParams.push_back(" 0 *  Marking[ 150 ] " );
    Transition[140].priority = "1";
    Transition[140].MarkingDependent = 1;
    Transition[140].weight = "1 ";

    vector < vector <int> > vec(141);
    PredT = vec;
    PredT[0].push_back(0);
    PredT[0].push_back(3);
    PredT[0].push_back(31);
    PredT[0].push_back(150);
    PredT[1].push_back(1);
    PredT[1].push_back(2);
    PredT[1].push_back(151);
    PredT[2].push_back(2);
    PredT[2].push_back(5);
    PredT[2].push_back(33);
    PredT[2].push_back(151);
    PredT[3].push_back(3);
    PredT[3].push_back(4);
    PredT[3].push_back(152);
    PredT[4].push_back(4);
    PredT[4].push_back(7);
    PredT[4].push_back(35);
    PredT[4].push_back(152);
    PredT[5].push_back(5);
    PredT[5].push_back(6);
    PredT[5].push_back(153);
    PredT[6].push_back(6);
    PredT[6].push_back(9);
    PredT[6].push_back(37);
    PredT[6].push_back(153);
    PredT[7].push_back(7);
    PredT[7].push_back(8);
    PredT[7].push_back(154);
    PredT[8].push_back(8);
    PredT[8].push_back(11);
    PredT[8].push_back(39);
    PredT[8].push_back(154);
    PredT[9].push_back(9);
    PredT[9].push_back(10);
    PredT[9].push_back(155);
    PredT[10].push_back(10);
    PredT[10].push_back(13);
    PredT[10].push_back(41);
    PredT[10].push_back(155);
    PredT[11].push_back(11);
    PredT[11].push_back(12);
    PredT[11].push_back(156);
    PredT[12].push_back(12);
    PredT[12].push_back(15);
    PredT[12].push_back(43);
    PredT[12].push_back(156);
    PredT[13].push_back(13);
    PredT[13].push_back(14);
    PredT[13].push_back(157);
    PredT[14].push_back(14);
    PredT[14].push_back(17);
    PredT[14].push_back(45);
    PredT[14].push_back(157);
    PredT[15].push_back(15);
    PredT[15].push_back(16);
    PredT[15].push_back(158);
    PredT[16].push_back(16);
    PredT[16].push_back(19);
    PredT[16].push_back(47);
    PredT[16].push_back(158);
    PredT[17].push_back(17);
    PredT[17].push_back(18);
    PredT[17].push_back(159);
    PredT[18].push_back(18);
    PredT[18].push_back(21);
    PredT[18].push_back(49);
    PredT[18].push_back(159);
    PredT[19].push_back(19);
    PredT[19].push_back(20);
    PredT[19].push_back(160);
    PredT[20].push_back(20);
    PredT[20].push_back(23);
    PredT[20].push_back(51);
    PredT[20].push_back(160);
    PredT[21].push_back(21);
    PredT[21].push_back(22);
    PredT[21].push_back(161);
    PredT[22].push_back(22);
    PredT[22].push_back(25);
    PredT[22].push_back(53);
    PredT[22].push_back(161);
    PredT[23].push_back(23);
    PredT[23].push_back(24);
    PredT[23].push_back(162);
    PredT[24].push_back(24);
    PredT[24].push_back(27);
    PredT[24].push_back(55);
    PredT[24].push_back(162);
    PredT[25].push_back(25);
    PredT[25].push_back(26);
    PredT[25].push_back(163);
    PredT[26].push_back(26);
    PredT[26].push_back(29);
    PredT[26].push_back(57);
    PredT[26].push_back(163);
    PredT[27].push_back(27);
    PredT[27].push_back(28);
    PredT[27].push_back(164);
    PredT[28].push_back(30);
    PredT[28].push_back(33);
    PredT[28].push_back(61);
    PredT[28].push_back(150);
    PredT[29].push_back(31);
    PredT[29].push_back(32);
    PredT[29].push_back(151);
    PredT[30].push_back(32);
    PredT[30].push_back(35);
    PredT[30].push_back(63);
    PredT[30].push_back(151);
    PredT[31].push_back(33);
    PredT[31].push_back(34);
    PredT[31].push_back(152);
    PredT[32].push_back(34);
    PredT[32].push_back(37);
    PredT[32].push_back(65);
    PredT[32].push_back(152);
    PredT[33].push_back(35);
    PredT[33].push_back(36);
    PredT[33].push_back(153);
    PredT[34].push_back(36);
    PredT[34].push_back(39);
    PredT[34].push_back(67);
    PredT[34].push_back(153);
    PredT[35].push_back(37);
    PredT[35].push_back(38);
    PredT[35].push_back(154);
    PredT[36].push_back(38);
    PredT[36].push_back(41);
    PredT[36].push_back(69);
    PredT[36].push_back(154);
    PredT[37].push_back(39);
    PredT[37].push_back(40);
    PredT[37].push_back(155);
    PredT[38].push_back(40);
    PredT[38].push_back(43);
    PredT[38].push_back(71);
    PredT[38].push_back(155);
    PredT[39].push_back(41);
    PredT[39].push_back(42);
    PredT[39].push_back(156);
    PredT[40].push_back(42);
    PredT[40].push_back(45);
    PredT[40].push_back(73);
    PredT[40].push_back(156);
    PredT[41].push_back(43);
    PredT[41].push_back(44);
    PredT[41].push_back(157);
    PredT[42].push_back(44);
    PredT[42].push_back(47);
    PredT[42].push_back(75);
    PredT[42].push_back(157);
    PredT[43].push_back(45);
    PredT[43].push_back(46);
    PredT[43].push_back(158);
    PredT[44].push_back(46);
    PredT[44].push_back(49);
    PredT[44].push_back(77);
    PredT[44].push_back(158);
    PredT[45].push_back(47);
    PredT[45].push_back(48);
    PredT[45].push_back(159);
    PredT[46].push_back(48);
    PredT[46].push_back(51);
    PredT[46].push_back(79);
    PredT[46].push_back(159);
    PredT[47].push_back(49);
    PredT[47].push_back(50);
    PredT[47].push_back(160);
    PredT[48].push_back(50);
    PredT[48].push_back(53);
    PredT[48].push_back(81);
    PredT[48].push_back(160);
    PredT[49].push_back(51);
    PredT[49].push_back(52);
    PredT[49].push_back(161);
    PredT[50].push_back(52);
    PredT[50].push_back(55);
    PredT[50].push_back(83);
    PredT[50].push_back(161);
    PredT[51].push_back(53);
    PredT[51].push_back(54);
    PredT[51].push_back(162);
    PredT[52].push_back(54);
    PredT[52].push_back(57);
    PredT[52].push_back(85);
    PredT[52].push_back(162);
    PredT[53].push_back(55);
    PredT[53].push_back(56);
    PredT[53].push_back(163);
    PredT[54].push_back(56);
    PredT[54].push_back(59);
    PredT[54].push_back(87);
    PredT[54].push_back(163);
    PredT[55].push_back(57);
    PredT[55].push_back(58);
    PredT[55].push_back(164);
    PredT[56].push_back(60);
    PredT[56].push_back(63);
    PredT[56].push_back(91);
    PredT[56].push_back(150);
    PredT[57].push_back(61);
    PredT[57].push_back(62);
    PredT[57].push_back(151);
    PredT[58].push_back(62);
    PredT[58].push_back(65);
    PredT[58].push_back(93);
    PredT[58].push_back(151);
    PredT[59].push_back(63);
    PredT[59].push_back(64);
    PredT[59].push_back(152);
    PredT[60].push_back(64);
    PredT[60].push_back(67);
    PredT[60].push_back(95);
    PredT[60].push_back(152);
    PredT[61].push_back(65);
    PredT[61].push_back(66);
    PredT[61].push_back(153);
    PredT[62].push_back(66);
    PredT[62].push_back(69);
    PredT[62].push_back(97);
    PredT[62].push_back(153);
    PredT[63].push_back(67);
    PredT[63].push_back(68);
    PredT[63].push_back(154);
    PredT[64].push_back(68);
    PredT[64].push_back(71);
    PredT[64].push_back(99);
    PredT[64].push_back(154);
    PredT[65].push_back(69);
    PredT[65].push_back(70);
    PredT[65].push_back(155);
    PredT[66].push_back(70);
    PredT[66].push_back(73);
    PredT[66].push_back(101);
    PredT[66].push_back(155);
    PredT[67].push_back(71);
    PredT[67].push_back(72);
    PredT[67].push_back(156);
    PredT[68].push_back(72);
    PredT[68].push_back(75);
    PredT[68].push_back(103);
    PredT[68].push_back(156);
    PredT[69].push_back(73);
    PredT[69].push_back(74);
    PredT[69].push_back(157);
    PredT[70].push_back(74);
    PredT[70].push_back(77);
    PredT[70].push_back(105);
    PredT[70].push_back(157);
    PredT[71].push_back(75);
    PredT[71].push_back(76);
    PredT[71].push_back(158);
    PredT[72].push_back(76);
    PredT[72].push_back(79);
    PredT[72].push_back(107);
    PredT[72].push_back(158);
    PredT[73].push_back(77);
    PredT[73].push_back(78);
    PredT[73].push_back(159);
    PredT[74].push_back(78);
    PredT[74].push_back(81);
    PredT[74].push_back(109);
    PredT[74].push_back(159);
    PredT[75].push_back(79);
    PredT[75].push_back(80);
    PredT[75].push_back(160);
    PredT[76].push_back(80);
    PredT[76].push_back(83);
    PredT[76].push_back(111);
    PredT[76].push_back(160);
    PredT[77].push_back(81);
    PredT[77].push_back(82);
    PredT[77].push_back(161);
    PredT[78].push_back(82);
    PredT[78].push_back(85);
    PredT[78].push_back(113);
    PredT[78].push_back(161);
    PredT[79].push_back(83);
    PredT[79].push_back(84);
    PredT[79].push_back(162);
    PredT[80].push_back(84);
    PredT[80].push_back(87);
    PredT[80].push_back(115);
    PredT[80].push_back(162);
    PredT[81].push_back(85);
    PredT[81].push_back(86);
    PredT[81].push_back(163);
    PredT[82].push_back(86);
    PredT[82].push_back(89);
    PredT[82].push_back(117);
    PredT[82].push_back(163);
    PredT[83].push_back(87);
    PredT[83].push_back(88);
    PredT[83].push_back(164);
    PredT[84].push_back(90);
    PredT[84].push_back(93);
    PredT[84].push_back(121);
    PredT[84].push_back(150);
    PredT[85].push_back(91);
    PredT[85].push_back(92);
    PredT[85].push_back(151);
    PredT[86].push_back(92);
    PredT[86].push_back(95);
    PredT[86].push_back(123);
    PredT[86].push_back(151);
    PredT[87].push_back(93);
    PredT[87].push_back(94);
    PredT[87].push_back(152);
    PredT[88].push_back(94);
    PredT[88].push_back(97);
    PredT[88].push_back(125);
    PredT[88].push_back(152);
    PredT[89].push_back(95);
    PredT[89].push_back(96);
    PredT[89].push_back(153);
    PredT[90].push_back(96);
    PredT[90].push_back(99);
    PredT[90].push_back(127);
    PredT[90].push_back(153);
    PredT[91].push_back(97);
    PredT[91].push_back(98);
    PredT[91].push_back(154);
    PredT[92].push_back(98);
    PredT[92].push_back(101);
    PredT[92].push_back(129);
    PredT[92].push_back(154);
    PredT[93].push_back(99);
    PredT[93].push_back(100);
    PredT[93].push_back(155);
    PredT[94].push_back(100);
    PredT[94].push_back(103);
    PredT[94].push_back(131);
    PredT[94].push_back(155);
    PredT[95].push_back(101);
    PredT[95].push_back(102);
    PredT[95].push_back(156);
    PredT[96].push_back(102);
    PredT[96].push_back(105);
    PredT[96].push_back(133);
    PredT[96].push_back(156);
    PredT[97].push_back(103);
    PredT[97].push_back(104);
    PredT[97].push_back(157);
    PredT[98].push_back(104);
    PredT[98].push_back(107);
    PredT[98].push_back(135);
    PredT[98].push_back(157);
    PredT[99].push_back(105);
    PredT[99].push_back(106);
    PredT[99].push_back(158);
    PredT[100].push_back(106);
    PredT[100].push_back(109);
    PredT[100].push_back(137);
    PredT[100].push_back(158);
    PredT[101].push_back(107);
    PredT[101].push_back(108);
    PredT[101].push_back(159);
    PredT[102].push_back(108);
    PredT[102].push_back(111);
    PredT[102].push_back(139);
    PredT[102].push_back(159);
    PredT[103].push_back(109);
    PredT[103].push_back(110);
    PredT[103].push_back(160);
    PredT[104].push_back(110);
    PredT[104].push_back(113);
    PredT[104].push_back(141);
    PredT[104].push_back(160);
    PredT[105].push_back(111);
    PredT[105].push_back(112);
    PredT[105].push_back(161);
    PredT[106].push_back(112);
    PredT[106].push_back(115);
    PredT[106].push_back(143);
    PredT[106].push_back(161);
    PredT[107].push_back(113);
    PredT[107].push_back(114);
    PredT[107].push_back(162);
    PredT[108].push_back(114);
    PredT[108].push_back(117);
    PredT[108].push_back(145);
    PredT[108].push_back(162);
    PredT[109].push_back(115);
    PredT[109].push_back(116);
    PredT[109].push_back(163);
    PredT[110].push_back(116);
    PredT[110].push_back(119);
    PredT[110].push_back(147);
    PredT[110].push_back(163);
    PredT[111].push_back(117);
    PredT[111].push_back(118);
    PredT[111].push_back(164);
    PredT[112].push_back(120);
    PredT[112].push_back(123);
    PredT[112].push_back(150);
    PredT[113].push_back(121);
    PredT[113].push_back(122);
    PredT[113].push_back(151);
    PredT[114].push_back(122);
    PredT[114].push_back(125);
    PredT[114].push_back(151);
    PredT[115].push_back(123);
    PredT[115].push_back(124);
    PredT[115].push_back(152);
    PredT[116].push_back(124);
    PredT[116].push_back(127);
    PredT[116].push_back(152);
    PredT[117].push_back(125);
    PredT[117].push_back(126);
    PredT[117].push_back(153);
    PredT[118].push_back(126);
    PredT[118].push_back(129);
    PredT[118].push_back(153);
    PredT[119].push_back(127);
    PredT[119].push_back(128);
    PredT[119].push_back(154);
    PredT[120].push_back(128);
    PredT[120].push_back(131);
    PredT[120].push_back(154);
    PredT[121].push_back(129);
    PredT[121].push_back(130);
    PredT[121].push_back(155);
    PredT[122].push_back(130);
    PredT[122].push_back(133);
    PredT[122].push_back(155);
    PredT[123].push_back(131);
    PredT[123].push_back(132);
    PredT[123].push_back(156);
    PredT[124].push_back(132);
    PredT[124].push_back(135);
    PredT[124].push_back(156);
    PredT[125].push_back(133);
    PredT[125].push_back(134);
    PredT[125].push_back(157);
    PredT[126].push_back(134);
    PredT[126].push_back(137);
    PredT[126].push_back(157);
    PredT[127].push_back(135);
    PredT[127].push_back(136);
    PredT[127].push_back(158);
    PredT[128].push_back(136);
    PredT[128].push_back(139);
    PredT[128].push_back(158);
    PredT[129].push_back(137);
    PredT[129].push_back(138);
    PredT[129].push_back(159);
    PredT[130].push_back(138);
    PredT[130].push_back(141);
    PredT[130].push_back(159);
    PredT[131].push_back(139);
    PredT[131].push_back(140);
    PredT[131].push_back(160);
    PredT[132].push_back(140);
    PredT[132].push_back(143);
    PredT[132].push_back(160);
    PredT[133].push_back(141);
    PredT[133].push_back(142);
    PredT[133].push_back(161);
    PredT[134].push_back(142);
    PredT[134].push_back(145);
    PredT[134].push_back(161);
    PredT[135].push_back(143);
    PredT[135].push_back(144);
    PredT[135].push_back(162);
    PredT[136].push_back(144);
    PredT[136].push_back(147);
    PredT[136].push_back(162);
    PredT[137].push_back(145);
    PredT[137].push_back(146);
    PredT[137].push_back(163);
    PredT[138].push_back(146);
    PredT[138].push_back(149);
    PredT[138].push_back(163);
    PredT[139].push_back(147);
    PredT[139].push_back(148);
    PredT[139].push_back(164);
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
     case 46:
       return IsEnabled_t46();
       break;
     case 47:
       return IsEnabled_t47();
       break;
     case 48:
       return IsEnabled_t48();
       break;
     case 49:
       return IsEnabled_t49();
       break;
     case 50:
       return IsEnabled_t50();
       break;
     case 51:
       return IsEnabled_t51();
       break;
     case 52:
       return IsEnabled_t52();
       break;
     case 53:
       return IsEnabled_t53();
       break;
     case 54:
       return IsEnabled_t54();
       break;
     case 55:
       return IsEnabled_t55();
       break;
     case 56:
       return IsEnabled_t56();
       break;
     case 57:
       return IsEnabled_t57();
       break;
     case 58:
       return IsEnabled_t58();
       break;
     case 59:
       return IsEnabled_t59();
       break;
     case 60:
       return IsEnabled_t60();
       break;
     case 61:
       return IsEnabled_t61();
       break;
     case 62:
       return IsEnabled_t62();
       break;
     case 63:
       return IsEnabled_t63();
       break;
     case 64:
       return IsEnabled_t64();
       break;
     case 65:
       return IsEnabled_t65();
       break;
     case 66:
       return IsEnabled_t66();
       break;
     case 67:
       return IsEnabled_t67();
       break;
     case 68:
       return IsEnabled_t68();
       break;
     case 69:
       return IsEnabled_t69();
       break;
     case 70:
       return IsEnabled_t70();
       break;
     case 71:
       return IsEnabled_t71();
       break;
     case 72:
       return IsEnabled_t72();
       break;
     case 73:
       return IsEnabled_t73();
       break;
     case 74:
       return IsEnabled_t74();
       break;
     case 75:
       return IsEnabled_t75();
       break;
     case 76:
       return IsEnabled_t76();
       break;
     case 77:
       return IsEnabled_t77();
       break;
     case 78:
       return IsEnabled_t78();
       break;
     case 79:
       return IsEnabled_t79();
       break;
     case 80:
       return IsEnabled_t80();
       break;
     case 81:
       return IsEnabled_t81();
       break;
     case 82:
       return IsEnabled_t82();
       break;
     case 83:
       return IsEnabled_t83();
       break;
     case 84:
       return IsEnabled_t84();
       break;
     case 85:
       return IsEnabled_t85();
       break;
     case 86:
       return IsEnabled_t86();
       break;
     case 87:
       return IsEnabled_t87();
       break;
     case 88:
       return IsEnabled_t88();
       break;
     case 89:
       return IsEnabled_t89();
       break;
     case 90:
       return IsEnabled_t90();
       break;
     case 91:
       return IsEnabled_t91();
       break;
     case 92:
       return IsEnabled_t92();
       break;
     case 93:
       return IsEnabled_t93();
       break;
     case 94:
       return IsEnabled_t94();
       break;
     case 95:
       return IsEnabled_t95();
       break;
     case 96:
       return IsEnabled_t96();
       break;
     case 97:
       return IsEnabled_t97();
       break;
     case 98:
       return IsEnabled_t98();
       break;
     case 99:
       return IsEnabled_t99();
       break;
     case 100:
       return IsEnabled_t100();
       break;
     case 101:
       return IsEnabled_t101();
       break;
     case 102:
       return IsEnabled_t102();
       break;
     case 103:
       return IsEnabled_t103();
       break;
     case 104:
       return IsEnabled_t104();
       break;
     case 105:
       return IsEnabled_t105();
       break;
     case 106:
       return IsEnabled_t106();
       break;
     case 107:
       return IsEnabled_t107();
       break;
     case 108:
       return IsEnabled_t108();
       break;
     case 109:
       return IsEnabled_t109();
       break;
     case 110:
       return IsEnabled_t110();
       break;
     case 111:
       return IsEnabled_t111();
       break;
     case 112:
       return IsEnabled_t112();
       break;
     case 113:
       return IsEnabled_t113();
       break;
     case 114:
       return IsEnabled_t114();
       break;
     case 115:
       return IsEnabled_t115();
       break;
     case 116:
       return IsEnabled_t116();
       break;
     case 117:
       return IsEnabled_t117();
       break;
     case 118:
       return IsEnabled_t118();
       break;
     case 119:
       return IsEnabled_t119();
       break;
     case 120:
       return IsEnabled_t120();
       break;
     case 121:
       return IsEnabled_t121();
       break;
     case 122:
       return IsEnabled_t122();
       break;
     case 123:
       return IsEnabled_t123();
       break;
     case 124:
       return IsEnabled_t124();
       break;
     case 125:
       return IsEnabled_t125();
       break;
     case 126:
       return IsEnabled_t126();
       break;
     case 127:
       return IsEnabled_t127();
       break;
     case 128:
       return IsEnabled_t128();
       break;
     case 129:
       return IsEnabled_t129();
       break;
     case 130:
       return IsEnabled_t130();
       break;
     case 131:
       return IsEnabled_t131();
       break;
     case 132:
       return IsEnabled_t132();
       break;
     case 133:
       return IsEnabled_t133();
       break;
     case 134:
       return IsEnabled_t134();
       break;
     case 135:
       return IsEnabled_t135();
       break;
     case 136:
       return IsEnabled_t136();
       break;
     case 137:
       return IsEnabled_t137();
       break;
     case 138:
       return IsEnabled_t138();
       break;
     case 139:
       return IsEnabled_t139();
       break;
     case 140:
       return IsEnabled_t140();
       break;
   }
}

bool SPN::IsEnabled_t0() {
    if (Marking[0] < 1) return false;
    if (Marking[3] < 1) return false;
    if (Marking[31] < 1) return false;
    if (Marking[150] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t1() {
    if (Marking[1] < 1) return false;
    if (Marking[2] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t2() {
    if (Marking[2] < 1) return false;
    if (Marking[5] < 1) return false;
    if (Marking[33] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t3() {
    if (Marking[3] < 1) return false;
    if (Marking[4] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t4() {
    if (Marking[4] < 1) return false;
    if (Marking[7] < 1) return false;
    if (Marking[35] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t5() {
    if (Marking[5] < 1) return false;
    if (Marking[6] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t6() {
    if (Marking[6] < 1) return false;
    if (Marking[9] < 1) return false;
    if (Marking[37] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t7() {
    if (Marking[7] < 1) return false;
    if (Marking[8] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t8() {
    if (Marking[8] < 1) return false;
    if (Marking[11] < 1) return false;
    if (Marking[39] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t9() {
    if (Marking[9] < 1) return false;
    if (Marking[10] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t10() {
    if (Marking[10] < 1) return false;
    if (Marking[13] < 1) return false;
    if (Marking[41] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t11() {
    if (Marking[11] < 1) return false;
    if (Marking[12] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t12() {
    if (Marking[12] < 1) return false;
    if (Marking[15] < 1) return false;
    if (Marking[43] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t13() {
    if (Marking[13] < 1) return false;
    if (Marking[14] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t14() {
    if (Marking[14] < 1) return false;
    if (Marking[17] < 1) return false;
    if (Marking[45] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t15() {
    if (Marking[15] < 1) return false;
    if (Marking[16] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t16() {
    if (Marking[16] < 1) return false;
    if (Marking[19] < 1) return false;
    if (Marking[47] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t17() {
    if (Marking[17] < 1) return false;
    if (Marking[18] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t18() {
    if (Marking[18] < 1) return false;
    if (Marking[21] < 1) return false;
    if (Marking[49] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t19() {
    if (Marking[19] < 1) return false;
    if (Marking[20] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t20() {
    if (Marking[20] < 1) return false;
    if (Marking[23] < 1) return false;
    if (Marking[51] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t21() {
    if (Marking[21] < 1) return false;
    if (Marking[22] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t22() {
    if (Marking[22] < 1) return false;
    if (Marking[25] < 1) return false;
    if (Marking[53] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t23() {
    if (Marking[23] < 1) return false;
    if (Marking[24] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t24() {
    if (Marking[24] < 1) return false;
    if (Marking[27] < 1) return false;
    if (Marking[55] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t25() {
    if (Marking[25] < 1) return false;
    if (Marking[26] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t26() {
    if (Marking[26] < 1) return false;
    if (Marking[29] < 1) return false;
    if (Marking[57] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t27() {
    if (Marking[27] < 1) return false;
    if (Marking[28] < 1) return false;
    if (Marking[164] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t28() {
    if (Marking[30] < 1) return false;
    if (Marking[33] < 1) return false;
    if (Marking[61] < 1) return false;
    if (Marking[150] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t29() {
    if (Marking[31] < 1) return false;
    if (Marking[32] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t30() {
    if (Marking[32] < 1) return false;
    if (Marking[35] < 1) return false;
    if (Marking[63] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t31() {
    if (Marking[33] < 1) return false;
    if (Marking[34] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t32() {
    if (Marking[34] < 1) return false;
    if (Marking[37] < 1) return false;
    if (Marking[65] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t33() {
    if (Marking[35] < 1) return false;
    if (Marking[36] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t34() {
    if (Marking[36] < 1) return false;
    if (Marking[39] < 1) return false;
    if (Marking[67] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t35() {
    if (Marking[37] < 1) return false;
    if (Marking[38] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t36() {
    if (Marking[38] < 1) return false;
    if (Marking[41] < 1) return false;
    if (Marking[69] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t37() {
    if (Marking[39] < 1) return false;
    if (Marking[40] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t38() {
    if (Marking[40] < 1) return false;
    if (Marking[43] < 1) return false;
    if (Marking[71] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t39() {
    if (Marking[41] < 1) return false;
    if (Marking[42] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t40() {
    if (Marking[42] < 1) return false;
    if (Marking[45] < 1) return false;
    if (Marking[73] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t41() {
    if (Marking[43] < 1) return false;
    if (Marking[44] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t42() {
    if (Marking[44] < 1) return false;
    if (Marking[47] < 1) return false;
    if (Marking[75] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t43() {
    if (Marking[45] < 1) return false;
    if (Marking[46] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t44() {
    if (Marking[46] < 1) return false;
    if (Marking[49] < 1) return false;
    if (Marking[77] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t45() {
    if (Marking[47] < 1) return false;
    if (Marking[48] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t46() {
    if (Marking[48] < 1) return false;
    if (Marking[51] < 1) return false;
    if (Marking[79] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t47() {
    if (Marking[49] < 1) return false;
    if (Marking[50] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t48() {
    if (Marking[50] < 1) return false;
    if (Marking[53] < 1) return false;
    if (Marking[81] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t49() {
    if (Marking[51] < 1) return false;
    if (Marking[52] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t50() {
    if (Marking[52] < 1) return false;
    if (Marking[55] < 1) return false;
    if (Marking[83] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t51() {
    if (Marking[53] < 1) return false;
    if (Marking[54] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t52() {
    if (Marking[54] < 1) return false;
    if (Marking[57] < 1) return false;
    if (Marking[85] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t53() {
    if (Marking[55] < 1) return false;
    if (Marking[56] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t54() {
    if (Marking[56] < 1) return false;
    if (Marking[59] < 1) return false;
    if (Marking[87] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t55() {
    if (Marking[57] < 1) return false;
    if (Marking[58] < 1) return false;
    if (Marking[164] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t56() {
    if (Marking[60] < 1) return false;
    if (Marking[63] < 1) return false;
    if (Marking[91] < 1) return false;
    if (Marking[150] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t57() {
    if (Marking[61] < 1) return false;
    if (Marking[62] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t58() {
    if (Marking[62] < 1) return false;
    if (Marking[65] < 1) return false;
    if (Marking[93] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t59() {
    if (Marking[63] < 1) return false;
    if (Marking[64] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t60() {
    if (Marking[64] < 1) return false;
    if (Marking[67] < 1) return false;
    if (Marking[95] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t61() {
    if (Marking[65] < 1) return false;
    if (Marking[66] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t62() {
    if (Marking[66] < 1) return false;
    if (Marking[69] < 1) return false;
    if (Marking[97] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t63() {
    if (Marking[67] < 1) return false;
    if (Marking[68] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t64() {
    if (Marking[68] < 1) return false;
    if (Marking[71] < 1) return false;
    if (Marking[99] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t65() {
    if (Marking[69] < 1) return false;
    if (Marking[70] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t66() {
    if (Marking[70] < 1) return false;
    if (Marking[73] < 1) return false;
    if (Marking[101] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t67() {
    if (Marking[71] < 1) return false;
    if (Marking[72] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t68() {
    if (Marking[72] < 1) return false;
    if (Marking[75] < 1) return false;
    if (Marking[103] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t69() {
    if (Marking[73] < 1) return false;
    if (Marking[74] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t70() {
    if (Marking[74] < 1) return false;
    if (Marking[77] < 1) return false;
    if (Marking[105] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t71() {
    if (Marking[75] < 1) return false;
    if (Marking[76] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t72() {
    if (Marking[76] < 1) return false;
    if (Marking[79] < 1) return false;
    if (Marking[107] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t73() {
    if (Marking[77] < 1) return false;
    if (Marking[78] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t74() {
    if (Marking[78] < 1) return false;
    if (Marking[81] < 1) return false;
    if (Marking[109] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t75() {
    if (Marking[79] < 1) return false;
    if (Marking[80] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t76() {
    if (Marking[80] < 1) return false;
    if (Marking[83] < 1) return false;
    if (Marking[111] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t77() {
    if (Marking[81] < 1) return false;
    if (Marking[82] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t78() {
    if (Marking[82] < 1) return false;
    if (Marking[85] < 1) return false;
    if (Marking[113] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t79() {
    if (Marking[83] < 1) return false;
    if (Marking[84] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t80() {
    if (Marking[84] < 1) return false;
    if (Marking[87] < 1) return false;
    if (Marking[115] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t81() {
    if (Marking[85] < 1) return false;
    if (Marking[86] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t82() {
    if (Marking[86] < 1) return false;
    if (Marking[89] < 1) return false;
    if (Marking[117] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t83() {
    if (Marking[87] < 1) return false;
    if (Marking[88] < 1) return false;
    if (Marking[164] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t84() {
    if (Marking[90] < 1) return false;
    if (Marking[93] < 1) return false;
    if (Marking[121] < 1) return false;
    if (Marking[150] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t85() {
    if (Marking[91] < 1) return false;
    if (Marking[92] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t86() {
    if (Marking[92] < 1) return false;
    if (Marking[95] < 1) return false;
    if (Marking[123] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t87() {
    if (Marking[93] < 1) return false;
    if (Marking[94] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t88() {
    if (Marking[94] < 1) return false;
    if (Marking[97] < 1) return false;
    if (Marking[125] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t89() {
    if (Marking[95] < 1) return false;
    if (Marking[96] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t90() {
    if (Marking[96] < 1) return false;
    if (Marking[99] < 1) return false;
    if (Marking[127] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t91() {
    if (Marking[97] < 1) return false;
    if (Marking[98] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t92() {
    if (Marking[98] < 1) return false;
    if (Marking[101] < 1) return false;
    if (Marking[129] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t93() {
    if (Marking[99] < 1) return false;
    if (Marking[100] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t94() {
    if (Marking[100] < 1) return false;
    if (Marking[103] < 1) return false;
    if (Marking[131] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t95() {
    if (Marking[101] < 1) return false;
    if (Marking[102] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t96() {
    if (Marking[102] < 1) return false;
    if (Marking[105] < 1) return false;
    if (Marking[133] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t97() {
    if (Marking[103] < 1) return false;
    if (Marking[104] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t98() {
    if (Marking[104] < 1) return false;
    if (Marking[107] < 1) return false;
    if (Marking[135] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t99() {
    if (Marking[105] < 1) return false;
    if (Marking[106] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t100() {
    if (Marking[106] < 1) return false;
    if (Marking[109] < 1) return false;
    if (Marking[137] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t101() {
    if (Marking[107] < 1) return false;
    if (Marking[108] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t102() {
    if (Marking[108] < 1) return false;
    if (Marking[111] < 1) return false;
    if (Marking[139] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t103() {
    if (Marking[109] < 1) return false;
    if (Marking[110] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t104() {
    if (Marking[110] < 1) return false;
    if (Marking[113] < 1) return false;
    if (Marking[141] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t105() {
    if (Marking[111] < 1) return false;
    if (Marking[112] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t106() {
    if (Marking[112] < 1) return false;
    if (Marking[115] < 1) return false;
    if (Marking[143] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t107() {
    if (Marking[113] < 1) return false;
    if (Marking[114] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t108() {
    if (Marking[114] < 1) return false;
    if (Marking[117] < 1) return false;
    if (Marking[145] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t109() {
    if (Marking[115] < 1) return false;
    if (Marking[116] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t110() {
    if (Marking[116] < 1) return false;
    if (Marking[119] < 1) return false;
    if (Marking[147] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t111() {
    if (Marking[117] < 1) return false;
    if (Marking[118] < 1) return false;
    if (Marking[164] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t112() {
    if (Marking[120] < 1) return false;
    if (Marking[123] < 1) return false;
    if (Marking[150] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t113() {
    if (Marking[121] < 1) return false;
    if (Marking[122] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t114() {
    if (Marking[122] < 1) return false;
    if (Marking[125] < 1) return false;
    if (Marking[151] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t115() {
    if (Marking[123] < 1) return false;
    if (Marking[124] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t116() {
    if (Marking[124] < 1) return false;
    if (Marking[127] < 1) return false;
    if (Marking[152] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t117() {
    if (Marking[125] < 1) return false;
    if (Marking[126] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t118() {
    if (Marking[126] < 1) return false;
    if (Marking[129] < 1) return false;
    if (Marking[153] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t119() {
    if (Marking[127] < 1) return false;
    if (Marking[128] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t120() {
    if (Marking[128] < 1) return false;
    if (Marking[131] < 1) return false;
    if (Marking[154] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t121() {
    if (Marking[129] < 1) return false;
    if (Marking[130] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t122() {
    if (Marking[130] < 1) return false;
    if (Marking[133] < 1) return false;
    if (Marking[155] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t123() {
    if (Marking[131] < 1) return false;
    if (Marking[132] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t124() {
    if (Marking[132] < 1) return false;
    if (Marking[135] < 1) return false;
    if (Marking[156] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t125() {
    if (Marking[133] < 1) return false;
    if (Marking[134] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t126() {
    if (Marking[134] < 1) return false;
    if (Marking[137] < 1) return false;
    if (Marking[157] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t127() {
    if (Marking[135] < 1) return false;
    if (Marking[136] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t128() {
    if (Marking[136] < 1) return false;
    if (Marking[139] < 1) return false;
    if (Marking[158] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t129() {
    if (Marking[137] < 1) return false;
    if (Marking[138] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t130() {
    if (Marking[138] < 1) return false;
    if (Marking[141] < 1) return false;
    if (Marking[159] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t131() {
    if (Marking[139] < 1) return false;
    if (Marking[140] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t132() {
    if (Marking[140] < 1) return false;
    if (Marking[143] < 1) return false;
    if (Marking[160] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t133() {
    if (Marking[141] < 1) return false;
    if (Marking[142] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t134() {
    if (Marking[142] < 1) return false;
    if (Marking[145] < 1) return false;
    if (Marking[161] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t135() {
    if (Marking[143] < 1) return false;
    if (Marking[144] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t136() {
    if (Marking[144] < 1) return false;
    if (Marking[147] < 1) return false;
    if (Marking[162] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t137() {
    if (Marking[145] < 1) return false;
    if (Marking[146] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t138() {
    if (Marking[146] < 1) return false;
    if (Marking[149] < 1) return false;
    if (Marking[163] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t139() {
    if (Marking[147] < 1) return false;
    if (Marking[148] < 1) return false;
    if (Marking[164] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t140() {
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
     case 46: {
       fire_t46();
       break;
     } 
     case 47: {
       fire_t47();
       break;
     } 
     case 48: {
       fire_t48();
       break;
     } 
     case 49: {
       fire_t49();
       break;
     } 
     case 50: {
       fire_t50();
       break;
     } 
     case 51: {
       fire_t51();
       break;
     } 
     case 52: {
       fire_t52();
       break;
     } 
     case 53: {
       fire_t53();
       break;
     } 
     case 54: {
       fire_t54();
       break;
     } 
     case 55: {
       fire_t55();
       break;
     } 
     case 56: {
       fire_t56();
       break;
     } 
     case 57: {
       fire_t57();
       break;
     } 
     case 58: {
       fire_t58();
       break;
     } 
     case 59: {
       fire_t59();
       break;
     } 
     case 60: {
       fire_t60();
       break;
     } 
     case 61: {
       fire_t61();
       break;
     } 
     case 62: {
       fire_t62();
       break;
     } 
     case 63: {
       fire_t63();
       break;
     } 
     case 64: {
       fire_t64();
       break;
     } 
     case 65: {
       fire_t65();
       break;
     } 
     case 66: {
       fire_t66();
       break;
     } 
     case 67: {
       fire_t67();
       break;
     } 
     case 68: {
       fire_t68();
       break;
     } 
     case 69: {
       fire_t69();
       break;
     } 
     case 70: {
       fire_t70();
       break;
     } 
     case 71: {
       fire_t71();
       break;
     } 
     case 72: {
       fire_t72();
       break;
     } 
     case 73: {
       fire_t73();
       break;
     } 
     case 74: {
       fire_t74();
       break;
     } 
     case 75: {
       fire_t75();
       break;
     } 
     case 76: {
       fire_t76();
       break;
     } 
     case 77: {
       fire_t77();
       break;
     } 
     case 78: {
       fire_t78();
       break;
     } 
     case 79: {
       fire_t79();
       break;
     } 
     case 80: {
       fire_t80();
       break;
     } 
     case 81: {
       fire_t81();
       break;
     } 
     case 82: {
       fire_t82();
       break;
     } 
     case 83: {
       fire_t83();
       break;
     } 
     case 84: {
       fire_t84();
       break;
     } 
     case 85: {
       fire_t85();
       break;
     } 
     case 86: {
       fire_t86();
       break;
     } 
     case 87: {
       fire_t87();
       break;
     } 
     case 88: {
       fire_t88();
       break;
     } 
     case 89: {
       fire_t89();
       break;
     } 
     case 90: {
       fire_t90();
       break;
     } 
     case 91: {
       fire_t91();
       break;
     } 
     case 92: {
       fire_t92();
       break;
     } 
     case 93: {
       fire_t93();
       break;
     } 
     case 94: {
       fire_t94();
       break;
     } 
     case 95: {
       fire_t95();
       break;
     } 
     case 96: {
       fire_t96();
       break;
     } 
     case 97: {
       fire_t97();
       break;
     } 
     case 98: {
       fire_t98();
       break;
     } 
     case 99: {
       fire_t99();
       break;
     } 
     case 100: {
       fire_t100();
       break;
     } 
     case 101: {
       fire_t101();
       break;
     } 
     case 102: {
       fire_t102();
       break;
     } 
     case 103: {
       fire_t103();
       break;
     } 
     case 104: {
       fire_t104();
       break;
     } 
     case 105: {
       fire_t105();
       break;
     } 
     case 106: {
       fire_t106();
       break;
     } 
     case 107: {
       fire_t107();
       break;
     } 
     case 108: {
       fire_t108();
       break;
     } 
     case 109: {
       fire_t109();
       break;
     } 
     case 110: {
       fire_t110();
       break;
     } 
     case 111: {
       fire_t111();
       break;
     } 
     case 112: {
       fire_t112();
       break;
     } 
     case 113: {
       fire_t113();
       break;
     } 
     case 114: {
       fire_t114();
       break;
     } 
     case 115: {
       fire_t115();
       break;
     } 
     case 116: {
       fire_t116();
       break;
     } 
     case 117: {
       fire_t117();
       break;
     } 
     case 118: {
       fire_t118();
       break;
     } 
     case 119: {
       fire_t119();
       break;
     } 
     case 120: {
       fire_t120();
       break;
     } 
     case 121: {
       fire_t121();
       break;
     } 
     case 122: {
       fire_t122();
       break;
     } 
     case 123: {
       fire_t123();
       break;
     } 
     case 124: {
       fire_t124();
       break;
     } 
     case 125: {
       fire_t125();
       break;
     } 
     case 126: {
       fire_t126();
       break;
     } 
     case 127: {
       fire_t127();
       break;
     } 
     case 128: {
       fire_t128();
       break;
     } 
     case 129: {
       fire_t129();
       break;
     } 
     case 130: {
       fire_t130();
       break;
     } 
     case 131: {
       fire_t131();
       break;
     } 
     case 132: {
       fire_t132();
       break;
     } 
     case 133: {
       fire_t133();
       break;
     } 
     case 134: {
       fire_t134();
       break;
     } 
     case 135: {
       fire_t135();
       break;
     } 
     case 136: {
       fire_t136();
       break;
     } 
     case 137: {
       fire_t137();
       break;
     } 
     case 138: {
       fire_t138();
       break;
     } 
     case 139: {
       fire_t139();
       break;
     } 
     case 140: {
       fire_t140();
       break;
     } 
   }
}

void SPN::unfire(int t){
   switch(t){
     case 0: {
       unfire_t0();
       break;
     } 
     case 1: {
       unfire_t1();
       break;
     } 
     case 2: {
       unfire_t2();
       break;
     } 
     case 3: {
       unfire_t3();
       break;
     } 
     case 4: {
       unfire_t4();
       break;
     } 
     case 5: {
       unfire_t5();
       break;
     } 
     case 6: {
       unfire_t6();
       break;
     } 
     case 7: {
       unfire_t7();
       break;
     } 
     case 8: {
       unfire_t8();
       break;
     } 
     case 9: {
       unfire_t9();
       break;
     } 
     case 10: {
       unfire_t10();
       break;
     } 
     case 11: {
       unfire_t11();
       break;
     } 
     case 12: {
       unfire_t12();
       break;
     } 
     case 13: {
       unfire_t13();
       break;
     } 
     case 14: {
       unfire_t14();
       break;
     } 
     case 15: {
       unfire_t15();
       break;
     } 
     case 16: {
       unfire_t16();
       break;
     } 
     case 17: {
       unfire_t17();
       break;
     } 
     case 18: {
       unfire_t18();
       break;
     } 
     case 19: {
       unfire_t19();
       break;
     } 
     case 20: {
       unfire_t20();
       break;
     } 
     case 21: {
       unfire_t21();
       break;
     } 
     case 22: {
       unfire_t22();
       break;
     } 
     case 23: {
       unfire_t23();
       break;
     } 
     case 24: {
       unfire_t24();
       break;
     } 
     case 25: {
       unfire_t25();
       break;
     } 
     case 26: {
       unfire_t26();
       break;
     } 
     case 27: {
       unfire_t27();
       break;
     } 
     case 28: {
       unfire_t28();
       break;
     } 
     case 29: {
       unfire_t29();
       break;
     } 
     case 30: {
       unfire_t30();
       break;
     } 
     case 31: {
       unfire_t31();
       break;
     } 
     case 32: {
       unfire_t32();
       break;
     } 
     case 33: {
       unfire_t33();
       break;
     } 
     case 34: {
       unfire_t34();
       break;
     } 
     case 35: {
       unfire_t35();
       break;
     } 
     case 36: {
       unfire_t36();
       break;
     } 
     case 37: {
       unfire_t37();
       break;
     } 
     case 38: {
       unfire_t38();
       break;
     } 
     case 39: {
       unfire_t39();
       break;
     } 
     case 40: {
       unfire_t40();
       break;
     } 
     case 41: {
       unfire_t41();
       break;
     } 
     case 42: {
       unfire_t42();
       break;
     } 
     case 43: {
       unfire_t43();
       break;
     } 
     case 44: {
       unfire_t44();
       break;
     } 
     case 45: {
       unfire_t45();
       break;
     } 
     case 46: {
       unfire_t46();
       break;
     } 
     case 47: {
       unfire_t47();
       break;
     } 
     case 48: {
       unfire_t48();
       break;
     } 
     case 49: {
       unfire_t49();
       break;
     } 
     case 50: {
       unfire_t50();
       break;
     } 
     case 51: {
       unfire_t51();
       break;
     } 
     case 52: {
       unfire_t52();
       break;
     } 
     case 53: {
       unfire_t53();
       break;
     } 
     case 54: {
       unfire_t54();
       break;
     } 
     case 55: {
       unfire_t55();
       break;
     } 
     case 56: {
       unfire_t56();
       break;
     } 
     case 57: {
       unfire_t57();
       break;
     } 
     case 58: {
       unfire_t58();
       break;
     } 
     case 59: {
       unfire_t59();
       break;
     } 
     case 60: {
       unfire_t60();
       break;
     } 
     case 61: {
       unfire_t61();
       break;
     } 
     case 62: {
       unfire_t62();
       break;
     } 
     case 63: {
       unfire_t63();
       break;
     } 
     case 64: {
       unfire_t64();
       break;
     } 
     case 65: {
       unfire_t65();
       break;
     } 
     case 66: {
       unfire_t66();
       break;
     } 
     case 67: {
       unfire_t67();
       break;
     } 
     case 68: {
       unfire_t68();
       break;
     } 
     case 69: {
       unfire_t69();
       break;
     } 
     case 70: {
       unfire_t70();
       break;
     } 
     case 71: {
       unfire_t71();
       break;
     } 
     case 72: {
       unfire_t72();
       break;
     } 
     case 73: {
       unfire_t73();
       break;
     } 
     case 74: {
       unfire_t74();
       break;
     } 
     case 75: {
       unfire_t75();
       break;
     } 
     case 76: {
       unfire_t76();
       break;
     } 
     case 77: {
       unfire_t77();
       break;
     } 
     case 78: {
       unfire_t78();
       break;
     } 
     case 79: {
       unfire_t79();
       break;
     } 
     case 80: {
       unfire_t80();
       break;
     } 
     case 81: {
       unfire_t81();
       break;
     } 
     case 82: {
       unfire_t82();
       break;
     } 
     case 83: {
       unfire_t83();
       break;
     } 
     case 84: {
       unfire_t84();
       break;
     } 
     case 85: {
       unfire_t85();
       break;
     } 
     case 86: {
       unfire_t86();
       break;
     } 
     case 87: {
       unfire_t87();
       break;
     } 
     case 88: {
       unfire_t88();
       break;
     } 
     case 89: {
       unfire_t89();
       break;
     } 
     case 90: {
       unfire_t90();
       break;
     } 
     case 91: {
       unfire_t91();
       break;
     } 
     case 92: {
       unfire_t92();
       break;
     } 
     case 93: {
       unfire_t93();
       break;
     } 
     case 94: {
       unfire_t94();
       break;
     } 
     case 95: {
       unfire_t95();
       break;
     } 
     case 96: {
       unfire_t96();
       break;
     } 
     case 97: {
       unfire_t97();
       break;
     } 
     case 98: {
       unfire_t98();
       break;
     } 
     case 99: {
       unfire_t99();
       break;
     } 
     case 100: {
       unfire_t100();
       break;
     } 
     case 101: {
       unfire_t101();
       break;
     } 
     case 102: {
       unfire_t102();
       break;
     } 
     case 103: {
       unfire_t103();
       break;
     } 
     case 104: {
       unfire_t104();
       break;
     } 
     case 105: {
       unfire_t105();
       break;
     } 
     case 106: {
       unfire_t106();
       break;
     } 
     case 107: {
       unfire_t107();
       break;
     } 
     case 108: {
       unfire_t108();
       break;
     } 
     case 109: {
       unfire_t109();
       break;
     } 
     case 110: {
       unfire_t110();
       break;
     } 
     case 111: {
       unfire_t111();
       break;
     } 
     case 112: {
       unfire_t112();
       break;
     } 
     case 113: {
       unfire_t113();
       break;
     } 
     case 114: {
       unfire_t114();
       break;
     } 
     case 115: {
       unfire_t115();
       break;
     } 
     case 116: {
       unfire_t116();
       break;
     } 
     case 117: {
       unfire_t117();
       break;
     } 
     case 118: {
       unfire_t118();
       break;
     } 
     case 119: {
       unfire_t119();
       break;
     } 
     case 120: {
       unfire_t120();
       break;
     } 
     case 121: {
       unfire_t121();
       break;
     } 
     case 122: {
       unfire_t122();
       break;
     } 
     case 123: {
       unfire_t123();
       break;
     } 
     case 124: {
       unfire_t124();
       break;
     } 
     case 125: {
       unfire_t125();
       break;
     } 
     case 126: {
       unfire_t126();
       break;
     } 
     case 127: {
       unfire_t127();
       break;
     } 
     case 128: {
       unfire_t128();
       break;
     } 
     case 129: {
       unfire_t129();
       break;
     } 
     case 130: {
       unfire_t130();
       break;
     } 
     case 131: {
       unfire_t131();
       break;
     } 
     case 132: {
       unfire_t132();
       break;
     } 
     case 133: {
       unfire_t133();
       break;
     } 
     case 134: {
       unfire_t134();
       break;
     } 
     case 135: {
       unfire_t135();
       break;
     } 
     case 136: {
       unfire_t136();
       break;
     } 
     case 137: {
       unfire_t137();
       break;
     } 
     case 138: {
       unfire_t138();
       break;
     } 
     case 139: {
       unfire_t139();
       break;
     } 
     case 140: {
       unfire_t140();
       break;
     } 
   }
}

void SPN::fire_t0() {
    Marking[0] -= 1;
    Marking[1] += 1;
    Marking[2] += 1;
    Marking[3] -= 1;
    Marking[31] -= 1;
    Marking[31] += 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::unfire_t0() {
    Marking[0] += 1;
    Marking[1] -= 1;
    Marking[2] -= 1;
    Marking[3] += 1;
    Marking[31] += 1;
    Marking[31] -= 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::fire_t1() {
    Marking[1] -= 1;
    Marking[2] -= 1;
    Marking[3] += 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::unfire_t1() {
    Marking[1] += 1;
    Marking[2] += 1;
    Marking[3] -= 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::fire_t2() {
    Marking[2] -= 1;
    Marking[3] += 1;
    Marking[4] += 1;
    Marking[5] -= 1;
    Marking[33] -= 1;
    Marking[33] += 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::unfire_t2() {
    Marking[2] += 1;
    Marking[3] -= 1;
    Marking[4] -= 1;
    Marking[5] += 1;
    Marking[33] += 1;
    Marking[33] -= 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::fire_t3() {
    Marking[2] += 1;
    Marking[3] -= 1;
    Marking[4] -= 1;
    Marking[5] += 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::unfire_t3() {
    Marking[2] -= 1;
    Marking[3] += 1;
    Marking[4] += 1;
    Marking[5] -= 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::fire_t4() {
    Marking[4] -= 1;
    Marking[5] += 1;
    Marking[6] += 1;
    Marking[7] -= 1;
    Marking[35] -= 1;
    Marking[35] += 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::unfire_t4() {
    Marking[4] += 1;
    Marking[5] -= 1;
    Marking[6] -= 1;
    Marking[7] += 1;
    Marking[35] += 1;
    Marking[35] -= 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::fire_t5() {
    Marking[4] += 1;
    Marking[5] -= 1;
    Marking[6] -= 1;
    Marking[7] += 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::unfire_t5() {
    Marking[4] -= 1;
    Marking[5] += 1;
    Marking[6] += 1;
    Marking[7] -= 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::fire_t6() {
    Marking[6] -= 1;
    Marking[7] += 1;
    Marking[8] += 1;
    Marking[9] -= 1;
    Marking[37] -= 1;
    Marking[37] += 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::unfire_t6() {
    Marking[6] += 1;
    Marking[7] -= 1;
    Marking[8] -= 1;
    Marking[9] += 1;
    Marking[37] += 1;
    Marking[37] -= 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::fire_t7() {
    Marking[6] += 1;
    Marking[7] -= 1;
    Marking[8] -= 1;
    Marking[9] += 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::unfire_t7() {
    Marking[6] -= 1;
    Marking[7] += 1;
    Marking[8] += 1;
    Marking[9] -= 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::fire_t8() {
    Marking[8] -= 1;
    Marking[9] += 1;
    Marking[10] += 1;
    Marking[11] -= 1;
    Marking[39] -= 1;
    Marking[39] += 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::unfire_t8() {
    Marking[8] += 1;
    Marking[9] -= 1;
    Marking[10] -= 1;
    Marking[11] += 1;
    Marking[39] += 1;
    Marking[39] -= 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::fire_t9() {
    Marking[8] += 1;
    Marking[9] -= 1;
    Marking[10] -= 1;
    Marking[11] += 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::unfire_t9() {
    Marking[8] -= 1;
    Marking[9] += 1;
    Marking[10] += 1;
    Marking[11] -= 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::fire_t10() {
    Marking[10] -= 1;
    Marking[11] += 1;
    Marking[12] += 1;
    Marking[13] -= 1;
    Marking[41] -= 1;
    Marking[41] += 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::unfire_t10() {
    Marking[10] += 1;
    Marking[11] -= 1;
    Marking[12] -= 1;
    Marking[13] += 1;
    Marking[41] += 1;
    Marking[41] -= 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::fire_t11() {
    Marking[10] += 1;
    Marking[11] -= 1;
    Marking[12] -= 1;
    Marking[13] += 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::unfire_t11() {
    Marking[10] -= 1;
    Marking[11] += 1;
    Marking[12] += 1;
    Marking[13] -= 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::fire_t12() {
    Marking[12] -= 1;
    Marking[13] += 1;
    Marking[14] += 1;
    Marking[15] -= 1;
    Marking[43] -= 1;
    Marking[43] += 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::unfire_t12() {
    Marking[12] += 1;
    Marking[13] -= 1;
    Marking[14] -= 1;
    Marking[15] += 1;
    Marking[43] += 1;
    Marking[43] -= 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::fire_t13() {
    Marking[12] += 1;
    Marking[13] -= 1;
    Marking[14] -= 1;
    Marking[15] += 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::unfire_t13() {
    Marking[12] -= 1;
    Marking[13] += 1;
    Marking[14] += 1;
    Marking[15] -= 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::fire_t14() {
    Marking[14] -= 1;
    Marking[15] += 1;
    Marking[16] += 1;
    Marking[17] -= 1;
    Marking[45] -= 1;
    Marking[45] += 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::unfire_t14() {
    Marking[14] += 1;
    Marking[15] -= 1;
    Marking[16] -= 1;
    Marking[17] += 1;
    Marking[45] += 1;
    Marking[45] -= 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::fire_t15() {
    Marking[14] += 1;
    Marking[15] -= 1;
    Marking[16] -= 1;
    Marking[17] += 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::unfire_t15() {
    Marking[14] -= 1;
    Marking[15] += 1;
    Marking[16] += 1;
    Marking[17] -= 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::fire_t16() {
    Marking[16] -= 1;
    Marking[17] += 1;
    Marking[18] += 1;
    Marking[19] -= 1;
    Marking[47] -= 1;
    Marking[47] += 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::unfire_t16() {
    Marking[16] += 1;
    Marking[17] -= 1;
    Marking[18] -= 1;
    Marking[19] += 1;
    Marking[47] += 1;
    Marking[47] -= 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::fire_t17() {
    Marking[16] += 1;
    Marking[17] -= 1;
    Marking[18] -= 1;
    Marking[19] += 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::unfire_t17() {
    Marking[16] -= 1;
    Marking[17] += 1;
    Marking[18] += 1;
    Marking[19] -= 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::fire_t18() {
    Marking[18] -= 1;
    Marking[19] += 1;
    Marking[20] += 1;
    Marking[21] -= 1;
    Marking[49] -= 1;
    Marking[49] += 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::unfire_t18() {
    Marking[18] += 1;
    Marking[19] -= 1;
    Marking[20] -= 1;
    Marking[21] += 1;
    Marking[49] += 1;
    Marking[49] -= 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::fire_t19() {
    Marking[18] += 1;
    Marking[19] -= 1;
    Marking[20] -= 1;
    Marking[21] += 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::unfire_t19() {
    Marking[18] -= 1;
    Marking[19] += 1;
    Marking[20] += 1;
    Marking[21] -= 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::fire_t20() {
    Marking[20] -= 1;
    Marking[21] += 1;
    Marking[22] += 1;
    Marking[23] -= 1;
    Marking[51] -= 1;
    Marking[51] += 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::unfire_t20() {
    Marking[20] += 1;
    Marking[21] -= 1;
    Marking[22] -= 1;
    Marking[23] += 1;
    Marking[51] += 1;
    Marking[51] -= 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::fire_t21() {
    Marking[20] += 1;
    Marking[21] -= 1;
    Marking[22] -= 1;
    Marking[23] += 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::unfire_t21() {
    Marking[20] -= 1;
    Marking[21] += 1;
    Marking[22] += 1;
    Marking[23] -= 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::fire_t22() {
    Marking[22] -= 1;
    Marking[23] += 1;
    Marking[24] += 1;
    Marking[25] -= 1;
    Marking[53] -= 1;
    Marking[53] += 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::unfire_t22() {
    Marking[22] += 1;
    Marking[23] -= 1;
    Marking[24] -= 1;
    Marking[25] += 1;
    Marking[53] += 1;
    Marking[53] -= 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::fire_t23() {
    Marking[22] += 1;
    Marking[23] -= 1;
    Marking[24] -= 1;
    Marking[25] += 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::unfire_t23() {
    Marking[22] -= 1;
    Marking[23] += 1;
    Marking[24] += 1;
    Marking[25] -= 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::fire_t24() {
    Marking[24] -= 1;
    Marking[25] += 1;
    Marking[26] += 1;
    Marking[27] -= 1;
    Marking[55] -= 1;
    Marking[55] += 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::unfire_t24() {
    Marking[24] += 1;
    Marking[25] -= 1;
    Marking[26] -= 1;
    Marking[27] += 1;
    Marking[55] += 1;
    Marking[55] -= 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::fire_t25() {
    Marking[24] += 1;
    Marking[25] -= 1;
    Marking[26] -= 1;
    Marking[27] += 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::unfire_t25() {
    Marking[24] -= 1;
    Marking[25] += 1;
    Marking[26] += 1;
    Marking[27] -= 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::fire_t26() {
    Marking[26] -= 1;
    Marking[27] += 1;
    Marking[29] -= 1;
    Marking[57] -= 1;
    Marking[57] += 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::unfire_t26() {
    Marking[26] += 1;
    Marking[27] -= 1;
    Marking[29] += 1;
    Marking[57] += 1;
    Marking[57] -= 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::fire_t27() {
    Marking[26] += 1;
    Marking[27] -= 1;
    Marking[28] -= 1;
    Marking[29] += 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::unfire_t27() {
    Marking[26] -= 1;
    Marking[27] += 1;
    Marking[28] += 1;
    Marking[29] -= 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::fire_t28() {
    Marking[30] -= 1;
    Marking[31] += 1;
    Marking[32] += 1;
    Marking[33] -= 1;
    Marking[61] -= 1;
    Marking[61] += 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::unfire_t28() {
    Marking[30] += 1;
    Marking[31] -= 1;
    Marking[32] -= 1;
    Marking[33] += 1;
    Marking[61] += 1;
    Marking[61] -= 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::fire_t29() {
    Marking[31] -= 1;
    Marking[32] -= 1;
    Marking[33] += 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::unfire_t29() {
    Marking[31] += 1;
    Marking[32] += 1;
    Marking[33] -= 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::fire_t30() {
    Marking[32] -= 1;
    Marking[33] += 1;
    Marking[34] += 1;
    Marking[35] -= 1;
    Marking[63] -= 1;
    Marking[63] += 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::unfire_t30() {
    Marking[32] += 1;
    Marking[33] -= 1;
    Marking[34] -= 1;
    Marking[35] += 1;
    Marking[63] += 1;
    Marking[63] -= 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::fire_t31() {
    Marking[32] += 1;
    Marking[33] -= 1;
    Marking[34] -= 1;
    Marking[35] += 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::unfire_t31() {
    Marking[32] -= 1;
    Marking[33] += 1;
    Marking[34] += 1;
    Marking[35] -= 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::fire_t32() {
    Marking[34] -= 1;
    Marking[35] += 1;
    Marking[36] += 1;
    Marking[37] -= 1;
    Marking[65] -= 1;
    Marking[65] += 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::unfire_t32() {
    Marking[34] += 1;
    Marking[35] -= 1;
    Marking[36] -= 1;
    Marking[37] += 1;
    Marking[65] += 1;
    Marking[65] -= 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::fire_t33() {
    Marking[34] += 1;
    Marking[35] -= 1;
    Marking[36] -= 1;
    Marking[37] += 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::unfire_t33() {
    Marking[34] -= 1;
    Marking[35] += 1;
    Marking[36] += 1;
    Marking[37] -= 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::fire_t34() {
    Marking[36] -= 1;
    Marking[37] += 1;
    Marking[38] += 1;
    Marking[39] -= 1;
    Marking[67] -= 1;
    Marking[67] += 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::unfire_t34() {
    Marking[36] += 1;
    Marking[37] -= 1;
    Marking[38] -= 1;
    Marking[39] += 1;
    Marking[67] += 1;
    Marking[67] -= 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::fire_t35() {
    Marking[36] += 1;
    Marking[37] -= 1;
    Marking[38] -= 1;
    Marking[39] += 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::unfire_t35() {
    Marking[36] -= 1;
    Marking[37] += 1;
    Marking[38] += 1;
    Marking[39] -= 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::fire_t36() {
    Marking[38] -= 1;
    Marking[39] += 1;
    Marking[40] += 1;
    Marking[41] -= 1;
    Marking[69] -= 1;
    Marking[69] += 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::unfire_t36() {
    Marking[38] += 1;
    Marking[39] -= 1;
    Marking[40] -= 1;
    Marking[41] += 1;
    Marking[69] += 1;
    Marking[69] -= 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::fire_t37() {
    Marking[38] += 1;
    Marking[39] -= 1;
    Marking[40] -= 1;
    Marking[41] += 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::unfire_t37() {
    Marking[38] -= 1;
    Marking[39] += 1;
    Marking[40] += 1;
    Marking[41] -= 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::fire_t38() {
    Marking[40] -= 1;
    Marking[41] += 1;
    Marking[42] += 1;
    Marking[43] -= 1;
    Marking[71] -= 1;
    Marking[71] += 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::unfire_t38() {
    Marking[40] += 1;
    Marking[41] -= 1;
    Marking[42] -= 1;
    Marking[43] += 1;
    Marking[71] += 1;
    Marking[71] -= 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::fire_t39() {
    Marking[40] += 1;
    Marking[41] -= 1;
    Marking[42] -= 1;
    Marking[43] += 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::unfire_t39() {
    Marking[40] -= 1;
    Marking[41] += 1;
    Marking[42] += 1;
    Marking[43] -= 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::fire_t40() {
    Marking[42] -= 1;
    Marking[43] += 1;
    Marking[44] += 1;
    Marking[45] -= 1;
    Marking[73] -= 1;
    Marking[73] += 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::unfire_t40() {
    Marking[42] += 1;
    Marking[43] -= 1;
    Marking[44] -= 1;
    Marking[45] += 1;
    Marking[73] += 1;
    Marking[73] -= 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::fire_t41() {
    Marking[42] += 1;
    Marking[43] -= 1;
    Marking[44] -= 1;
    Marking[45] += 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::unfire_t41() {
    Marking[42] -= 1;
    Marking[43] += 1;
    Marking[44] += 1;
    Marking[45] -= 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::fire_t42() {
    Marking[44] -= 1;
    Marking[45] += 1;
    Marking[46] += 1;
    Marking[47] -= 1;
    Marking[75] -= 1;
    Marking[75] += 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::unfire_t42() {
    Marking[44] += 1;
    Marking[45] -= 1;
    Marking[46] -= 1;
    Marking[47] += 1;
    Marking[75] += 1;
    Marking[75] -= 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::fire_t43() {
    Marking[44] += 1;
    Marking[45] -= 1;
    Marking[46] -= 1;
    Marking[47] += 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::unfire_t43() {
    Marking[44] -= 1;
    Marking[45] += 1;
    Marking[46] += 1;
    Marking[47] -= 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::fire_t44() {
    Marking[46] -= 1;
    Marking[47] += 1;
    Marking[48] += 1;
    Marking[49] -= 1;
    Marking[77] -= 1;
    Marking[77] += 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::unfire_t44() {
    Marking[46] += 1;
    Marking[47] -= 1;
    Marking[48] -= 1;
    Marking[49] += 1;
    Marking[77] += 1;
    Marking[77] -= 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::fire_t45() {
    Marking[46] += 1;
    Marking[47] -= 1;
    Marking[48] -= 1;
    Marking[49] += 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::unfire_t45() {
    Marking[46] -= 1;
    Marking[47] += 1;
    Marking[48] += 1;
    Marking[49] -= 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::fire_t46() {
    Marking[48] -= 1;
    Marking[49] += 1;
    Marking[50] += 1;
    Marking[51] -= 1;
    Marking[79] -= 1;
    Marking[79] += 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::unfire_t46() {
    Marking[48] += 1;
    Marking[49] -= 1;
    Marking[50] -= 1;
    Marking[51] += 1;
    Marking[79] += 1;
    Marking[79] -= 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::fire_t47() {
    Marking[48] += 1;
    Marking[49] -= 1;
    Marking[50] -= 1;
    Marking[51] += 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::unfire_t47() {
    Marking[48] -= 1;
    Marking[49] += 1;
    Marking[50] += 1;
    Marking[51] -= 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::fire_t48() {
    Marking[50] -= 1;
    Marking[51] += 1;
    Marking[52] += 1;
    Marking[53] -= 1;
    Marking[81] -= 1;
    Marking[81] += 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::unfire_t48() {
    Marking[50] += 1;
    Marking[51] -= 1;
    Marking[52] -= 1;
    Marking[53] += 1;
    Marking[81] += 1;
    Marking[81] -= 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::fire_t49() {
    Marking[50] += 1;
    Marking[51] -= 1;
    Marking[52] -= 1;
    Marking[53] += 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::unfire_t49() {
    Marking[50] -= 1;
    Marking[51] += 1;
    Marking[52] += 1;
    Marking[53] -= 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::fire_t50() {
    Marking[52] -= 1;
    Marking[53] += 1;
    Marking[54] += 1;
    Marking[55] -= 1;
    Marking[83] -= 1;
    Marking[83] += 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::unfire_t50() {
    Marking[52] += 1;
    Marking[53] -= 1;
    Marking[54] -= 1;
    Marking[55] += 1;
    Marking[83] += 1;
    Marking[83] -= 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::fire_t51() {
    Marking[52] += 1;
    Marking[53] -= 1;
    Marking[54] -= 1;
    Marking[55] += 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::unfire_t51() {
    Marking[52] -= 1;
    Marking[53] += 1;
    Marking[54] += 1;
    Marking[55] -= 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::fire_t52() {
    Marking[54] -= 1;
    Marking[55] += 1;
    Marking[56] += 1;
    Marking[57] -= 1;
    Marking[85] -= 1;
    Marking[85] += 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::unfire_t52() {
    Marking[54] += 1;
    Marking[55] -= 1;
    Marking[56] -= 1;
    Marking[57] += 1;
    Marking[85] += 1;
    Marking[85] -= 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::fire_t53() {
    Marking[54] += 1;
    Marking[55] -= 1;
    Marking[56] -= 1;
    Marking[57] += 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::unfire_t53() {
    Marking[54] -= 1;
    Marking[55] += 1;
    Marking[56] += 1;
    Marking[57] -= 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::fire_t54() {
    Marking[56] -= 1;
    Marking[57] += 1;
    Marking[59] -= 1;
    Marking[87] -= 1;
    Marking[87] += 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::unfire_t54() {
    Marking[56] += 1;
    Marking[57] -= 1;
    Marking[59] += 1;
    Marking[87] += 1;
    Marking[87] -= 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::fire_t55() {
    Marking[56] += 1;
    Marking[57] -= 1;
    Marking[58] -= 1;
    Marking[59] += 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::unfire_t55() {
    Marking[56] -= 1;
    Marking[57] += 1;
    Marking[58] += 1;
    Marking[59] -= 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::fire_t56() {
    Marking[60] -= 1;
    Marking[61] += 1;
    Marking[62] += 1;
    Marking[63] -= 1;
    Marking[91] -= 1;
    Marking[91] += 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::unfire_t56() {
    Marking[60] += 1;
    Marking[61] -= 1;
    Marking[62] -= 1;
    Marking[63] += 1;
    Marking[91] += 1;
    Marking[91] -= 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::fire_t57() {
    Marking[61] -= 1;
    Marking[62] -= 1;
    Marking[63] += 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::unfire_t57() {
    Marking[61] += 1;
    Marking[62] += 1;
    Marking[63] -= 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::fire_t58() {
    Marking[62] -= 1;
    Marking[63] += 1;
    Marking[64] += 1;
    Marking[65] -= 1;
    Marking[93] -= 1;
    Marking[93] += 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::unfire_t58() {
    Marking[62] += 1;
    Marking[63] -= 1;
    Marking[64] -= 1;
    Marking[65] += 1;
    Marking[93] += 1;
    Marking[93] -= 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::fire_t59() {
    Marking[62] += 1;
    Marking[63] -= 1;
    Marking[64] -= 1;
    Marking[65] += 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::unfire_t59() {
    Marking[62] -= 1;
    Marking[63] += 1;
    Marking[64] += 1;
    Marking[65] -= 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::fire_t60() {
    Marking[64] -= 1;
    Marking[65] += 1;
    Marking[66] += 1;
    Marking[67] -= 1;
    Marking[95] -= 1;
    Marking[95] += 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::unfire_t60() {
    Marking[64] += 1;
    Marking[65] -= 1;
    Marking[66] -= 1;
    Marking[67] += 1;
    Marking[95] += 1;
    Marking[95] -= 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::fire_t61() {
    Marking[64] += 1;
    Marking[65] -= 1;
    Marking[66] -= 1;
    Marking[67] += 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::unfire_t61() {
    Marking[64] -= 1;
    Marking[65] += 1;
    Marking[66] += 1;
    Marking[67] -= 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::fire_t62() {
    Marking[66] -= 1;
    Marking[67] += 1;
    Marking[68] += 1;
    Marking[69] -= 1;
    Marking[97] -= 1;
    Marking[97] += 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::unfire_t62() {
    Marking[66] += 1;
    Marking[67] -= 1;
    Marking[68] -= 1;
    Marking[69] += 1;
    Marking[97] += 1;
    Marking[97] -= 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::fire_t63() {
    Marking[66] += 1;
    Marking[67] -= 1;
    Marking[68] -= 1;
    Marking[69] += 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::unfire_t63() {
    Marking[66] -= 1;
    Marking[67] += 1;
    Marking[68] += 1;
    Marking[69] -= 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::fire_t64() {
    Marking[68] -= 1;
    Marking[69] += 1;
    Marking[70] += 1;
    Marking[71] -= 1;
    Marking[99] -= 1;
    Marking[99] += 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::unfire_t64() {
    Marking[68] += 1;
    Marking[69] -= 1;
    Marking[70] -= 1;
    Marking[71] += 1;
    Marking[99] += 1;
    Marking[99] -= 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::fire_t65() {
    Marking[68] += 1;
    Marking[69] -= 1;
    Marking[70] -= 1;
    Marking[71] += 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::unfire_t65() {
    Marking[68] -= 1;
    Marking[69] += 1;
    Marking[70] += 1;
    Marking[71] -= 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::fire_t66() {
    Marking[70] -= 1;
    Marking[71] += 1;
    Marking[72] += 1;
    Marking[73] -= 1;
    Marking[101] -= 1;
    Marking[101] += 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::unfire_t66() {
    Marking[70] += 1;
    Marking[71] -= 1;
    Marking[72] -= 1;
    Marking[73] += 1;
    Marking[101] += 1;
    Marking[101] -= 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::fire_t67() {
    Marking[70] += 1;
    Marking[71] -= 1;
    Marking[72] -= 1;
    Marking[73] += 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::unfire_t67() {
    Marking[70] -= 1;
    Marking[71] += 1;
    Marking[72] += 1;
    Marking[73] -= 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::fire_t68() {
    Marking[72] -= 1;
    Marking[73] += 1;
    Marking[74] += 1;
    Marking[75] -= 1;
    Marking[103] -= 1;
    Marking[103] += 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::unfire_t68() {
    Marking[72] += 1;
    Marking[73] -= 1;
    Marking[74] -= 1;
    Marking[75] += 1;
    Marking[103] += 1;
    Marking[103] -= 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::fire_t69() {
    Marking[72] += 1;
    Marking[73] -= 1;
    Marking[74] -= 1;
    Marking[75] += 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::unfire_t69() {
    Marking[72] -= 1;
    Marking[73] += 1;
    Marking[74] += 1;
    Marking[75] -= 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::fire_t70() {
    Marking[74] -= 1;
    Marking[75] += 1;
    Marking[76] += 1;
    Marking[77] -= 1;
    Marking[105] -= 1;
    Marking[105] += 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::unfire_t70() {
    Marking[74] += 1;
    Marking[75] -= 1;
    Marking[76] -= 1;
    Marking[77] += 1;
    Marking[105] += 1;
    Marking[105] -= 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::fire_t71() {
    Marking[74] += 1;
    Marking[75] -= 1;
    Marking[76] -= 1;
    Marking[77] += 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::unfire_t71() {
    Marking[74] -= 1;
    Marking[75] += 1;
    Marking[76] += 1;
    Marking[77] -= 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::fire_t72() {
    Marking[76] -= 1;
    Marking[77] += 1;
    Marking[78] += 1;
    Marking[79] -= 1;
    Marking[107] -= 1;
    Marking[107] += 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::unfire_t72() {
    Marking[76] += 1;
    Marking[77] -= 1;
    Marking[78] -= 1;
    Marking[79] += 1;
    Marking[107] += 1;
    Marking[107] -= 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::fire_t73() {
    Marking[76] += 1;
    Marking[77] -= 1;
    Marking[78] -= 1;
    Marking[79] += 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::unfire_t73() {
    Marking[76] -= 1;
    Marking[77] += 1;
    Marking[78] += 1;
    Marking[79] -= 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::fire_t74() {
    Marking[78] -= 1;
    Marking[79] += 1;
    Marking[80] += 1;
    Marking[81] -= 1;
    Marking[109] -= 1;
    Marking[109] += 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::unfire_t74() {
    Marking[78] += 1;
    Marking[79] -= 1;
    Marking[80] -= 1;
    Marking[81] += 1;
    Marking[109] += 1;
    Marking[109] -= 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::fire_t75() {
    Marking[78] += 1;
    Marking[79] -= 1;
    Marking[80] -= 1;
    Marking[81] += 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::unfire_t75() {
    Marking[78] -= 1;
    Marking[79] += 1;
    Marking[80] += 1;
    Marking[81] -= 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::fire_t76() {
    Marking[80] -= 1;
    Marking[81] += 1;
    Marking[82] += 1;
    Marking[83] -= 1;
    Marking[111] -= 1;
    Marking[111] += 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::unfire_t76() {
    Marking[80] += 1;
    Marking[81] -= 1;
    Marking[82] -= 1;
    Marking[83] += 1;
    Marking[111] += 1;
    Marking[111] -= 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::fire_t77() {
    Marking[80] += 1;
    Marking[81] -= 1;
    Marking[82] -= 1;
    Marking[83] += 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::unfire_t77() {
    Marking[80] -= 1;
    Marking[81] += 1;
    Marking[82] += 1;
    Marking[83] -= 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::fire_t78() {
    Marking[82] -= 1;
    Marking[83] += 1;
    Marking[84] += 1;
    Marking[85] -= 1;
    Marking[113] -= 1;
    Marking[113] += 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::unfire_t78() {
    Marking[82] += 1;
    Marking[83] -= 1;
    Marking[84] -= 1;
    Marking[85] += 1;
    Marking[113] += 1;
    Marking[113] -= 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::fire_t79() {
    Marking[82] += 1;
    Marking[83] -= 1;
    Marking[84] -= 1;
    Marking[85] += 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::unfire_t79() {
    Marking[82] -= 1;
    Marking[83] += 1;
    Marking[84] += 1;
    Marking[85] -= 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::fire_t80() {
    Marking[84] -= 1;
    Marking[85] += 1;
    Marking[86] += 1;
    Marking[87] -= 1;
    Marking[115] -= 1;
    Marking[115] += 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::unfire_t80() {
    Marking[84] += 1;
    Marking[85] -= 1;
    Marking[86] -= 1;
    Marking[87] += 1;
    Marking[115] += 1;
    Marking[115] -= 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::fire_t81() {
    Marking[84] += 1;
    Marking[85] -= 1;
    Marking[86] -= 1;
    Marking[87] += 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::unfire_t81() {
    Marking[84] -= 1;
    Marking[85] += 1;
    Marking[86] += 1;
    Marking[87] -= 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::fire_t82() {
    Marking[86] -= 1;
    Marking[87] += 1;
    Marking[89] -= 1;
    Marking[117] -= 1;
    Marking[117] += 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::unfire_t82() {
    Marking[86] += 1;
    Marking[87] -= 1;
    Marking[89] += 1;
    Marking[117] += 1;
    Marking[117] -= 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::fire_t83() {
    Marking[86] += 1;
    Marking[87] -= 1;
    Marking[88] -= 1;
    Marking[89] += 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::unfire_t83() {
    Marking[86] -= 1;
    Marking[87] += 1;
    Marking[88] += 1;
    Marking[89] -= 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::fire_t84() {
    Marking[90] -= 1;
    Marking[91] += 1;
    Marking[92] += 1;
    Marking[93] -= 1;
    Marking[121] -= 1;
    Marking[121] += 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::unfire_t84() {
    Marking[90] += 1;
    Marking[91] -= 1;
    Marking[92] -= 1;
    Marking[93] += 1;
    Marking[121] += 1;
    Marking[121] -= 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::fire_t85() {
    Marking[91] -= 1;
    Marking[92] -= 1;
    Marking[93] += 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::unfire_t85() {
    Marking[91] += 1;
    Marking[92] += 1;
    Marking[93] -= 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::fire_t86() {
    Marking[92] -= 1;
    Marking[93] += 1;
    Marking[94] += 1;
    Marking[95] -= 1;
    Marking[123] -= 1;
    Marking[123] += 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::unfire_t86() {
    Marking[92] += 1;
    Marking[93] -= 1;
    Marking[94] -= 1;
    Marking[95] += 1;
    Marking[123] += 1;
    Marking[123] -= 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::fire_t87() {
    Marking[92] += 1;
    Marking[93] -= 1;
    Marking[94] -= 1;
    Marking[95] += 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::unfire_t87() {
    Marking[92] -= 1;
    Marking[93] += 1;
    Marking[94] += 1;
    Marking[95] -= 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::fire_t88() {
    Marking[94] -= 1;
    Marking[95] += 1;
    Marking[96] += 1;
    Marking[97] -= 1;
    Marking[125] -= 1;
    Marking[125] += 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::unfire_t88() {
    Marking[94] += 1;
    Marking[95] -= 1;
    Marking[96] -= 1;
    Marking[97] += 1;
    Marking[125] += 1;
    Marking[125] -= 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::fire_t89() {
    Marking[94] += 1;
    Marking[95] -= 1;
    Marking[96] -= 1;
    Marking[97] += 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::unfire_t89() {
    Marking[94] -= 1;
    Marking[95] += 1;
    Marking[96] += 1;
    Marking[97] -= 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::fire_t90() {
    Marking[96] -= 1;
    Marking[97] += 1;
    Marking[98] += 1;
    Marking[99] -= 1;
    Marking[127] -= 1;
    Marking[127] += 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::unfire_t90() {
    Marking[96] += 1;
    Marking[97] -= 1;
    Marking[98] -= 1;
    Marking[99] += 1;
    Marking[127] += 1;
    Marking[127] -= 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::fire_t91() {
    Marking[96] += 1;
    Marking[97] -= 1;
    Marking[98] -= 1;
    Marking[99] += 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::unfire_t91() {
    Marking[96] -= 1;
    Marking[97] += 1;
    Marking[98] += 1;
    Marking[99] -= 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::fire_t92() {
    Marking[98] -= 1;
    Marking[99] += 1;
    Marking[100] += 1;
    Marking[101] -= 1;
    Marking[129] -= 1;
    Marking[129] += 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::unfire_t92() {
    Marking[98] += 1;
    Marking[99] -= 1;
    Marking[100] -= 1;
    Marking[101] += 1;
    Marking[129] += 1;
    Marking[129] -= 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::fire_t93() {
    Marking[98] += 1;
    Marking[99] -= 1;
    Marking[100] -= 1;
    Marking[101] += 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::unfire_t93() {
    Marking[98] -= 1;
    Marking[99] += 1;
    Marking[100] += 1;
    Marking[101] -= 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::fire_t94() {
    Marking[100] -= 1;
    Marking[101] += 1;
    Marking[102] += 1;
    Marking[103] -= 1;
    Marking[131] -= 1;
    Marking[131] += 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::unfire_t94() {
    Marking[100] += 1;
    Marking[101] -= 1;
    Marking[102] -= 1;
    Marking[103] += 1;
    Marking[131] += 1;
    Marking[131] -= 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::fire_t95() {
    Marking[100] += 1;
    Marking[101] -= 1;
    Marking[102] -= 1;
    Marking[103] += 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::unfire_t95() {
    Marking[100] -= 1;
    Marking[101] += 1;
    Marking[102] += 1;
    Marking[103] -= 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::fire_t96() {
    Marking[102] -= 1;
    Marking[103] += 1;
    Marking[104] += 1;
    Marking[105] -= 1;
    Marking[133] -= 1;
    Marking[133] += 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::unfire_t96() {
    Marking[102] += 1;
    Marking[103] -= 1;
    Marking[104] -= 1;
    Marking[105] += 1;
    Marking[133] += 1;
    Marking[133] -= 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::fire_t97() {
    Marking[102] += 1;
    Marking[103] -= 1;
    Marking[104] -= 1;
    Marking[105] += 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::unfire_t97() {
    Marking[102] -= 1;
    Marking[103] += 1;
    Marking[104] += 1;
    Marking[105] -= 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::fire_t98() {
    Marking[104] -= 1;
    Marking[105] += 1;
    Marking[106] += 1;
    Marking[107] -= 1;
    Marking[135] -= 1;
    Marking[135] += 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::unfire_t98() {
    Marking[104] += 1;
    Marking[105] -= 1;
    Marking[106] -= 1;
    Marking[107] += 1;
    Marking[135] += 1;
    Marking[135] -= 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::fire_t99() {
    Marking[104] += 1;
    Marking[105] -= 1;
    Marking[106] -= 1;
    Marking[107] += 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::unfire_t99() {
    Marking[104] -= 1;
    Marking[105] += 1;
    Marking[106] += 1;
    Marking[107] -= 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::fire_t100() {
    Marking[106] -= 1;
    Marking[107] += 1;
    Marking[108] += 1;
    Marking[109] -= 1;
    Marking[137] -= 1;
    Marking[137] += 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::unfire_t100() {
    Marking[106] += 1;
    Marking[107] -= 1;
    Marking[108] -= 1;
    Marking[109] += 1;
    Marking[137] += 1;
    Marking[137] -= 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::fire_t101() {
    Marking[106] += 1;
    Marking[107] -= 1;
    Marking[108] -= 1;
    Marking[109] += 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::unfire_t101() {
    Marking[106] -= 1;
    Marking[107] += 1;
    Marking[108] += 1;
    Marking[109] -= 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::fire_t102() {
    Marking[108] -= 1;
    Marking[109] += 1;
    Marking[110] += 1;
    Marking[111] -= 1;
    Marking[139] -= 1;
    Marking[139] += 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::unfire_t102() {
    Marking[108] += 1;
    Marking[109] -= 1;
    Marking[110] -= 1;
    Marking[111] += 1;
    Marking[139] += 1;
    Marking[139] -= 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::fire_t103() {
    Marking[108] += 1;
    Marking[109] -= 1;
    Marking[110] -= 1;
    Marking[111] += 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::unfire_t103() {
    Marking[108] -= 1;
    Marking[109] += 1;
    Marking[110] += 1;
    Marking[111] -= 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::fire_t104() {
    Marking[110] -= 1;
    Marking[111] += 1;
    Marking[112] += 1;
    Marking[113] -= 1;
    Marking[141] -= 1;
    Marking[141] += 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::unfire_t104() {
    Marking[110] += 1;
    Marking[111] -= 1;
    Marking[112] -= 1;
    Marking[113] += 1;
    Marking[141] += 1;
    Marking[141] -= 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::fire_t105() {
    Marking[110] += 1;
    Marking[111] -= 1;
    Marking[112] -= 1;
    Marking[113] += 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::unfire_t105() {
    Marking[110] -= 1;
    Marking[111] += 1;
    Marking[112] += 1;
    Marking[113] -= 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::fire_t106() {
    Marking[112] -= 1;
    Marking[113] += 1;
    Marking[114] += 1;
    Marking[115] -= 1;
    Marking[143] -= 1;
    Marking[143] += 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::unfire_t106() {
    Marking[112] += 1;
    Marking[113] -= 1;
    Marking[114] -= 1;
    Marking[115] += 1;
    Marking[143] += 1;
    Marking[143] -= 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::fire_t107() {
    Marking[112] += 1;
    Marking[113] -= 1;
    Marking[114] -= 1;
    Marking[115] += 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::unfire_t107() {
    Marking[112] -= 1;
    Marking[113] += 1;
    Marking[114] += 1;
    Marking[115] -= 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::fire_t108() {
    Marking[114] -= 1;
    Marking[115] += 1;
    Marking[116] += 1;
    Marking[117] -= 1;
    Marking[145] -= 1;
    Marking[145] += 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::unfire_t108() {
    Marking[114] += 1;
    Marking[115] -= 1;
    Marking[116] -= 1;
    Marking[117] += 1;
    Marking[145] += 1;
    Marking[145] -= 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::fire_t109() {
    Marking[114] += 1;
    Marking[115] -= 1;
    Marking[116] -= 1;
    Marking[117] += 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::unfire_t109() {
    Marking[114] -= 1;
    Marking[115] += 1;
    Marking[116] += 1;
    Marking[117] -= 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::fire_t110() {
    Marking[116] -= 1;
    Marking[117] += 1;
    Marking[119] -= 1;
    Marking[147] -= 1;
    Marking[147] += 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::unfire_t110() {
    Marking[116] += 1;
    Marking[117] -= 1;
    Marking[119] += 1;
    Marking[147] += 1;
    Marking[147] -= 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::fire_t111() {
    Marking[116] += 1;
    Marking[117] -= 1;
    Marking[118] -= 1;
    Marking[119] += 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::unfire_t111() {
    Marking[116] -= 1;
    Marking[117] += 1;
    Marking[118] += 1;
    Marking[119] -= 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::fire_t112() {
    Marking[120] -= 1;
    Marking[121] += 1;
    Marking[122] += 1;
    Marking[123] -= 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::unfire_t112() {
    Marking[120] += 1;
    Marking[121] -= 1;
    Marking[122] -= 1;
    Marking[123] += 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::fire_t113() {
    Marking[121] -= 1;
    Marking[122] -= 1;
    Marking[123] += 1;
    Marking[150] += 1;
    Marking[151] -= 1;
}

void SPN::unfire_t113() {
    Marking[121] += 1;
    Marking[122] += 1;
    Marking[123] -= 1;
    Marking[150] -= 1;
    Marking[151] += 1;
}

void SPN::fire_t114() {
    Marking[122] -= 1;
    Marking[123] += 1;
    Marking[124] += 1;
    Marking[125] -= 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::unfire_t114() {
    Marking[122] += 1;
    Marking[123] -= 1;
    Marking[124] -= 1;
    Marking[125] += 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::fire_t115() {
    Marking[122] += 1;
    Marking[123] -= 1;
    Marking[124] -= 1;
    Marking[125] += 1;
    Marking[151] += 1;
    Marking[152] -= 1;
}

void SPN::unfire_t115() {
    Marking[122] -= 1;
    Marking[123] += 1;
    Marking[124] += 1;
    Marking[125] -= 1;
    Marking[151] -= 1;
    Marking[152] += 1;
}

void SPN::fire_t116() {
    Marking[124] -= 1;
    Marking[125] += 1;
    Marking[126] += 1;
    Marking[127] -= 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::unfire_t116() {
    Marking[124] += 1;
    Marking[125] -= 1;
    Marking[126] -= 1;
    Marking[127] += 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::fire_t117() {
    Marking[124] += 1;
    Marking[125] -= 1;
    Marking[126] -= 1;
    Marking[127] += 1;
    Marking[152] += 1;
    Marking[153] -= 1;
}

void SPN::unfire_t117() {
    Marking[124] -= 1;
    Marking[125] += 1;
    Marking[126] += 1;
    Marking[127] -= 1;
    Marking[152] -= 1;
    Marking[153] += 1;
}

void SPN::fire_t118() {
    Marking[126] -= 1;
    Marking[127] += 1;
    Marking[128] += 1;
    Marking[129] -= 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::unfire_t118() {
    Marking[126] += 1;
    Marking[127] -= 1;
    Marking[128] -= 1;
    Marking[129] += 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::fire_t119() {
    Marking[126] += 1;
    Marking[127] -= 1;
    Marking[128] -= 1;
    Marking[129] += 1;
    Marking[153] += 1;
    Marking[154] -= 1;
}

void SPN::unfire_t119() {
    Marking[126] -= 1;
    Marking[127] += 1;
    Marking[128] += 1;
    Marking[129] -= 1;
    Marking[153] -= 1;
    Marking[154] += 1;
}

void SPN::fire_t120() {
    Marking[128] -= 1;
    Marking[129] += 1;
    Marking[130] += 1;
    Marking[131] -= 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::unfire_t120() {
    Marking[128] += 1;
    Marking[129] -= 1;
    Marking[130] -= 1;
    Marking[131] += 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::fire_t121() {
    Marking[128] += 1;
    Marking[129] -= 1;
    Marking[130] -= 1;
    Marking[131] += 1;
    Marking[154] += 1;
    Marking[155] -= 1;
}

void SPN::unfire_t121() {
    Marking[128] -= 1;
    Marking[129] += 1;
    Marking[130] += 1;
    Marking[131] -= 1;
    Marking[154] -= 1;
    Marking[155] += 1;
}

void SPN::fire_t122() {
    Marking[130] -= 1;
    Marking[131] += 1;
    Marking[132] += 1;
    Marking[133] -= 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::unfire_t122() {
    Marking[130] += 1;
    Marking[131] -= 1;
    Marking[132] -= 1;
    Marking[133] += 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::fire_t123() {
    Marking[130] += 1;
    Marking[131] -= 1;
    Marking[132] -= 1;
    Marking[133] += 1;
    Marking[155] += 1;
    Marking[156] -= 1;
}

void SPN::unfire_t123() {
    Marking[130] -= 1;
    Marking[131] += 1;
    Marking[132] += 1;
    Marking[133] -= 1;
    Marking[155] -= 1;
    Marking[156] += 1;
}

void SPN::fire_t124() {
    Marking[132] -= 1;
    Marking[133] += 1;
    Marking[134] += 1;
    Marking[135] -= 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::unfire_t124() {
    Marking[132] += 1;
    Marking[133] -= 1;
    Marking[134] -= 1;
    Marking[135] += 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::fire_t125() {
    Marking[132] += 1;
    Marking[133] -= 1;
    Marking[134] -= 1;
    Marking[135] += 1;
    Marking[156] += 1;
    Marking[157] -= 1;
}

void SPN::unfire_t125() {
    Marking[132] -= 1;
    Marking[133] += 1;
    Marking[134] += 1;
    Marking[135] -= 1;
    Marking[156] -= 1;
    Marking[157] += 1;
}

void SPN::fire_t126() {
    Marking[134] -= 1;
    Marking[135] += 1;
    Marking[136] += 1;
    Marking[137] -= 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::unfire_t126() {
    Marking[134] += 1;
    Marking[135] -= 1;
    Marking[136] -= 1;
    Marking[137] += 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::fire_t127() {
    Marking[134] += 1;
    Marking[135] -= 1;
    Marking[136] -= 1;
    Marking[137] += 1;
    Marking[157] += 1;
    Marking[158] -= 1;
}

void SPN::unfire_t127() {
    Marking[134] -= 1;
    Marking[135] += 1;
    Marking[136] += 1;
    Marking[137] -= 1;
    Marking[157] -= 1;
    Marking[158] += 1;
}

void SPN::fire_t128() {
    Marking[136] -= 1;
    Marking[137] += 1;
    Marking[138] += 1;
    Marking[139] -= 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::unfire_t128() {
    Marking[136] += 1;
    Marking[137] -= 1;
    Marking[138] -= 1;
    Marking[139] += 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::fire_t129() {
    Marking[136] += 1;
    Marking[137] -= 1;
    Marking[138] -= 1;
    Marking[139] += 1;
    Marking[158] += 1;
    Marking[159] -= 1;
}

void SPN::unfire_t129() {
    Marking[136] -= 1;
    Marking[137] += 1;
    Marking[138] += 1;
    Marking[139] -= 1;
    Marking[158] -= 1;
    Marking[159] += 1;
}

void SPN::fire_t130() {
    Marking[138] -= 1;
    Marking[139] += 1;
    Marking[140] += 1;
    Marking[141] -= 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::unfire_t130() {
    Marking[138] += 1;
    Marking[139] -= 1;
    Marking[140] -= 1;
    Marking[141] += 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::fire_t131() {
    Marking[138] += 1;
    Marking[139] -= 1;
    Marking[140] -= 1;
    Marking[141] += 1;
    Marking[159] += 1;
    Marking[160] -= 1;
}

void SPN::unfire_t131() {
    Marking[138] -= 1;
    Marking[139] += 1;
    Marking[140] += 1;
    Marking[141] -= 1;
    Marking[159] -= 1;
    Marking[160] += 1;
}

void SPN::fire_t132() {
    Marking[140] -= 1;
    Marking[141] += 1;
    Marking[142] += 1;
    Marking[143] -= 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::unfire_t132() {
    Marking[140] += 1;
    Marking[141] -= 1;
    Marking[142] -= 1;
    Marking[143] += 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::fire_t133() {
    Marking[140] += 1;
    Marking[141] -= 1;
    Marking[142] -= 1;
    Marking[143] += 1;
    Marking[160] += 1;
    Marking[161] -= 1;
}

void SPN::unfire_t133() {
    Marking[140] -= 1;
    Marking[141] += 1;
    Marking[142] += 1;
    Marking[143] -= 1;
    Marking[160] -= 1;
    Marking[161] += 1;
}

void SPN::fire_t134() {
    Marking[142] -= 1;
    Marking[143] += 1;
    Marking[144] += 1;
    Marking[145] -= 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::unfire_t134() {
    Marking[142] += 1;
    Marking[143] -= 1;
    Marking[144] -= 1;
    Marking[145] += 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::fire_t135() {
    Marking[142] += 1;
    Marking[143] -= 1;
    Marking[144] -= 1;
    Marking[145] += 1;
    Marking[161] += 1;
    Marking[162] -= 1;
}

void SPN::unfire_t135() {
    Marking[142] -= 1;
    Marking[143] += 1;
    Marking[144] += 1;
    Marking[145] -= 1;
    Marking[161] -= 1;
    Marking[162] += 1;
}

void SPN::fire_t136() {
    Marking[144] -= 1;
    Marking[145] += 1;
    Marking[146] += 1;
    Marking[147] -= 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::unfire_t136() {
    Marking[144] += 1;
    Marking[145] -= 1;
    Marking[146] -= 1;
    Marking[147] += 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::fire_t137() {
    Marking[144] += 1;
    Marking[145] -= 1;
    Marking[146] -= 1;
    Marking[147] += 1;
    Marking[162] += 1;
    Marking[163] -= 1;
}

void SPN::unfire_t137() {
    Marking[144] -= 1;
    Marking[145] += 1;
    Marking[146] += 1;
    Marking[147] -= 1;
    Marking[162] -= 1;
    Marking[163] += 1;
}

void SPN::fire_t138() {
    Marking[146] -= 1;
    Marking[147] += 1;
    Marking[149] -= 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::unfire_t138() {
    Marking[146] += 1;
    Marking[147] -= 1;
    Marking[149] += 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::fire_t139() {
    Marking[146] += 1;
    Marking[147] -= 1;
    Marking[148] -= 1;
    Marking[149] += 1;
    Marking[163] += 1;
    Marking[164] -= 1;
}

void SPN::unfire_t139() {
    Marking[146] -= 1;
    Marking[147] += 1;
    Marking[148] += 1;
    Marking[149] -= 1;
    Marking[163] -= 1;
    Marking[164] += 1;
}

void SPN::fire_t140() {
    Marking[165] += 1;
}

void SPN::unfire_t140() {
    Marking[165] -= 1;
}

vector<double> SPN::GetDistParameters(int t){
   vector<double> P(2);
   double origin_rate = (SPN::GetDistParametersOrigin(t))[0];
   P[0]= ComputeDistr( *this ,t, origin_rate);
   P[1]= origin_rate;
   return P;
}
 
vector<double> SPN::GetDistParametersOrigin(int t){
   switch(t){
     case 0: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 1: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 2: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 3: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 4: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 5: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 6: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 7: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 8: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 9: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 10: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 11: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 12: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 13: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 14: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 15: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 16: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 17: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 18: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 19: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 20: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 21: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 22: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 23: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 24: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 25: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 26: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 27: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 28: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 29: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 30: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 31: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 32: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 33: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 34: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 35: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 36: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 37: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 38: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 39: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 40: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 41: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 42: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 43: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 44: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 45: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 46: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 47: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 48: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 49: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 50: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 51: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 52: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 53: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 54: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 55: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 56: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 57: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 58: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 59: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 60: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 61: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 62: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 63: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 64: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 65: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 66: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 67: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 68: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 69: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 70: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 71: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 72: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 73: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 74: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 75: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 76: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 77: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 78: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 79: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 80: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 81: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 82: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 83: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 84: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 85: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 86: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 87: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 88: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 89: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 90: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 91: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 92: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 93: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 94: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 95: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 96: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 97: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 98: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 99: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 100: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 101: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 102: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 103: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 104: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 105: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 106: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 107: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 108: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 109: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 110: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 111: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 112: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 113: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 114: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 115: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 116: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 117: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 118: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 119: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 120: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 121: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 122: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 123: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 124: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 125: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 126: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 127: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 128: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 129: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 130: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 131: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 132: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 133: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 134: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 135: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 136: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 137: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 138: {
       vector<double> P(1);
       P[0]= ( double ) 0.3 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 139: {
       vector<double> P(1);
       P[0]= ( double ) 0.7 + 0 *  Marking[ 150 ] ;
       return P;
       break;
     }
     case 140: {
       vector<double> P(1);
       P[0]= ( double ) 0 *  Marking[ 150 ] ;
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
     case 46: {
       return (double)1;
       break;
     } 
     case 47: {
       return (double)1;
       break;
     } 
     case 48: {
       return (double)1;
       break;
     } 
     case 49: {
       return (double)1;
       break;
     } 
     case 50: {
       return (double)1;
       break;
     } 
     case 51: {
       return (double)1;
       break;
     } 
     case 52: {
       return (double)1;
       break;
     } 
     case 53: {
       return (double)1;
       break;
     } 
     case 54: {
       return (double)1;
       break;
     } 
     case 55: {
       return (double)1;
       break;
     } 
     case 56: {
       return (double)1;
       break;
     } 
     case 57: {
       return (double)1;
       break;
     } 
     case 58: {
       return (double)1;
       break;
     } 
     case 59: {
       return (double)1;
       break;
     } 
     case 60: {
       return (double)1;
       break;
     } 
     case 61: {
       return (double)1;
       break;
     } 
     case 62: {
       return (double)1;
       break;
     } 
     case 63: {
       return (double)1;
       break;
     } 
     case 64: {
       return (double)1;
       break;
     } 
     case 65: {
       return (double)1;
       break;
     } 
     case 66: {
       return (double)1;
       break;
     } 
     case 67: {
       return (double)1;
       break;
     } 
     case 68: {
       return (double)1;
       break;
     } 
     case 69: {
       return (double)1;
       break;
     } 
     case 70: {
       return (double)1;
       break;
     } 
     case 71: {
       return (double)1;
       break;
     } 
     case 72: {
       return (double)1;
       break;
     } 
     case 73: {
       return (double)1;
       break;
     } 
     case 74: {
       return (double)1;
       break;
     } 
     case 75: {
       return (double)1;
       break;
     } 
     case 76: {
       return (double)1;
       break;
     } 
     case 77: {
       return (double)1;
       break;
     } 
     case 78: {
       return (double)1;
       break;
     } 
     case 79: {
       return (double)1;
       break;
     } 
     case 80: {
       return (double)1;
       break;
     } 
     case 81: {
       return (double)1;
       break;
     } 
     case 82: {
       return (double)1;
       break;
     } 
     case 83: {
       return (double)1;
       break;
     } 
     case 84: {
       return (double)1;
       break;
     } 
     case 85: {
       return (double)1;
       break;
     } 
     case 86: {
       return (double)1;
       break;
     } 
     case 87: {
       return (double)1;
       break;
     } 
     case 88: {
       return (double)1;
       break;
     } 
     case 89: {
       return (double)1;
       break;
     } 
     case 90: {
       return (double)1;
       break;
     } 
     case 91: {
       return (double)1;
       break;
     } 
     case 92: {
       return (double)1;
       break;
     } 
     case 93: {
       return (double)1;
       break;
     } 
     case 94: {
       return (double)1;
       break;
     } 
     case 95: {
       return (double)1;
       break;
     } 
     case 96: {
       return (double)1;
       break;
     } 
     case 97: {
       return (double)1;
       break;
     } 
     case 98: {
       return (double)1;
       break;
     } 
     case 99: {
       return (double)1;
       break;
     } 
     case 100: {
       return (double)1;
       break;
     } 
     case 101: {
       return (double)1;
       break;
     } 
     case 102: {
       return (double)1;
       break;
     } 
     case 103: {
       return (double)1;
       break;
     } 
     case 104: {
       return (double)1;
       break;
     } 
     case 105: {
       return (double)1;
       break;
     } 
     case 106: {
       return (double)1;
       break;
     } 
     case 107: {
       return (double)1;
       break;
     } 
     case 108: {
       return (double)1;
       break;
     } 
     case 109: {
       return (double)1;
       break;
     } 
     case 110: {
       return (double)1;
       break;
     } 
     case 111: {
       return (double)1;
       break;
     } 
     case 112: {
       return (double)1;
       break;
     } 
     case 113: {
       return (double)1;
       break;
     } 
     case 114: {
       return (double)1;
       break;
     } 
     case 115: {
       return (double)1;
       break;
     } 
     case 116: {
       return (double)1;
       break;
     } 
     case 117: {
       return (double)1;
       break;
     } 
     case 118: {
       return (double)1;
       break;
     } 
     case 119: {
       return (double)1;
       break;
     } 
     case 120: {
       return (double)1;
       break;
     } 
     case 121: {
       return (double)1;
       break;
     } 
     case 122: {
       return (double)1;
       break;
     } 
     case 123: {
       return (double)1;
       break;
     } 
     case 124: {
       return (double)1;
       break;
     } 
     case 125: {
       return (double)1;
       break;
     } 
     case 126: {
       return (double)1;
       break;
     } 
     case 127: {
       return (double)1;
       break;
     } 
     case 128: {
       return (double)1;
       break;
     } 
     case 129: {
       return (double)1;
       break;
     } 
     case 130: {
       return (double)1;
       break;
     } 
     case 131: {
       return (double)1;
       break;
     } 
     case 132: {
       return (double)1;
       break;
     } 
     case 133: {
       return (double)1;
       break;
     } 
     case 134: {
       return (double)1;
       break;
     } 
     case 135: {
       return (double)1;
       break;
     } 
     case 136: {
       return (double)1;
       break;
     } 
     case 137: {
       return (double)1;
       break;
     } 
     case 138: {
       return (double)1;
       break;
     } 
     case 139: {
       return (double)1;
       break;
     } 
     case 140: {
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
     case 46:
       return (double)1;
       break;
     case 47:
       return (double)1;
       break;
     case 48:
       return (double)1;
       break;
     case 49:
       return (double)1;
       break;
     case 50:
       return (double)1;
       break;
     case 51:
       return (double)1;
       break;
     case 52:
       return (double)1;
       break;
     case 53:
       return (double)1;
       break;
     case 54:
       return (double)1;
       break;
     case 55:
       return (double)1;
       break;
     case 56:
       return (double)1;
       break;
     case 57:
       return (double)1;
       break;
     case 58:
       return (double)1;
       break;
     case 59:
       return (double)1;
       break;
     case 60:
       return (double)1;
       break;
     case 61:
       return (double)1;
       break;
     case 62:
       return (double)1;
       break;
     case 63:
       return (double)1;
       break;
     case 64:
       return (double)1;
       break;
     case 65:
       return (double)1;
       break;
     case 66:
       return (double)1;
       break;
     case 67:
       return (double)1;
       break;
     case 68:
       return (double)1;
       break;
     case 69:
       return (double)1;
       break;
     case 70:
       return (double)1;
       break;
     case 71:
       return (double)1;
       break;
     case 72:
       return (double)1;
       break;
     case 73:
       return (double)1;
       break;
     case 74:
       return (double)1;
       break;
     case 75:
       return (double)1;
       break;
     case 76:
       return (double)1;
       break;
     case 77:
       return (double)1;
       break;
     case 78:
       return (double)1;
       break;
     case 79:
       return (double)1;
       break;
     case 80:
       return (double)1;
       break;
     case 81:
       return (double)1;
       break;
     case 82:
       return (double)1;
       break;
     case 83:
       return (double)1;
       break;
     case 84:
       return (double)1;
       break;
     case 85:
       return (double)1;
       break;
     case 86:
       return (double)1;
       break;
     case 87:
       return (double)1;
       break;
     case 88:
       return (double)1;
       break;
     case 89:
       return (double)1;
       break;
     case 90:
       return (double)1;
       break;
     case 91:
       return (double)1;
       break;
     case 92:
       return (double)1;
       break;
     case 93:
       return (double)1;
       break;
     case 94:
       return (double)1;
       break;
     case 95:
       return (double)1;
       break;
     case 96:
       return (double)1;
       break;
     case 97:
       return (double)1;
       break;
     case 98:
       return (double)1;
       break;
     case 99:
       return (double)1;
       break;
     case 100:
       return (double)1;
       break;
     case 101:
       return (double)1;
       break;
     case 102:
       return (double)1;
       break;
     case 103:
       return (double)1;
       break;
     case 104:
       return (double)1;
       break;
     case 105:
       return (double)1;
       break;
     case 106:
       return (double)1;
       break;
     case 107:
       return (double)1;
       break;
     case 108:
       return (double)1;
       break;
     case 109:
       return (double)1;
       break;
     case 110:
       return (double)1;
       break;
     case 111:
       return (double)1;
       break;
     case 112:
       return (double)1;
       break;
     case 113:
       return (double)1;
       break;
     case 114:
       return (double)1;
       break;
     case 115:
       return (double)1;
       break;
     case 116:
       return (double)1;
       break;
     case 117:
       return (double)1;
       break;
     case 118:
       return (double)1;
       break;
     case 119:
       return (double)1;
       break;
     case 120:
       return (double)1;
       break;
     case 121:
       return (double)1;
       break;
     case 122:
       return (double)1;
       break;
     case 123:
       return (double)1;
       break;
     case 124:
       return (double)1;
       break;
     case 125:
       return (double)1;
       break;
     case 126:
       return (double)1;
       break;
     case 127:
       return (double)1;
       break;
     case 128:
       return (double)1;
       break;
     case 129:
       return (double)1;
       break;
     case 130:
       return (double)1;
       break;
     case 131:
       return (double)1;
       break;
     case 132:
       return (double)1;
       break;
     case 133:
       return (double)1;
       break;
     case 134:
       return (double)1;
       break;
     case 135:
       return (double)1;
       break;
     case 136:
       return (double)1;
       break;
     case 137:
       return (double)1;
       break;
     case 138:
       return (double)1;
       break;
     case 139:
       return (double)1;
       break;
     case 140:
       return (double)1;
       break;
   }
}

