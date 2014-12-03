let data = [
"SA_noiseD",1000000.0;
"SA_d",1000.0;
"SA_ectopD",10400.0;
"SA_dV",50.0;
"SA_ectopdV",50.0;
"Atr_refrD",50.0;
"RA_anteD",30.0;
"RA_retroD",30.0;
"AV_alpha",150.0;
"AV_beta",250.0;
"AV_delta",10.0;
"AV_theta",10.0;
"AV_k4",0.0300;
"AV_tr",500.0;
"AV_Vr",-90.0;
"AV_Vt",-40.0;
"AV_anteDMin",100.0;
"AV_retroDMin",100.0;
"AV_refrDMin",50.0;
"AV_tauC",100.0;
"RV_anteD",50.0;
"RV_retroD",50.0;
"VRG_d",3000.0;
"VRG_ectopD",30450.0;
"VRG_noiseD",1000000.0;
"Vtr_refrD",200.0;
"PM_TAVI",150.0;
"PM_TLRI",1000.0;
"PM_TURI",1200.0;
"PM_TPVAB",50.0;
"PM_TPVARP",250.0;
"PM_TVRP",320.0;
"Skrewness",0.2000]


let var= [
  "avj_refr"; "avj_t4"; "avj_refr_0"; "avj_tRec"; "refractorylast";
  "recoverylast" ; "antelast" ; "a_dV"
]

let func= [
"double modulateRefrAnte(double t,double t0,double dV){
  return AV_refrDMin*pow(t/t0,AV_theta)*pow(fmin(1,dV/(AV_Vt-AV_Vr)),AV_delta);
}";
"double modulateRefrRetro(double t,double t0){
    return AV_refrDMin*pow(t/t0,AV_theta);
}";
"double timeToDep(double Vm){
    return fmax(0,(AV_Vt-Vm)/AV_k4);
}";
"double initRefrPeriod(double tRec){
    return AV_refrDMin + AV_beta*(1 - exp(-tRec/AV_tr));
}";
"void magicReset(){
    avj_t4=timeToDep(AV_Vr);
    recoverylast=0;
    antelast=0;
    refractorylast=0;
}";
]
