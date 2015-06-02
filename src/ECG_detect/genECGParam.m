function [ ECGParams,RTdelay,RRdelay,PQdelay,QRdelay ] = genECGParam( EKG,rate,time )
%GENECGPARAM Summary of this function goes here
%   Detailed explanation goes here
[R_data,S_data,T_data,Q_data,P_data,PQ_i, QR_i,RT_i,RR_i, ectopic, S_data_filtered, Q_data_filtered, heart_rate,buffer_plot]=peakdetect_offline(EKG,rate,time);
[ dT2 , hT2, wT2] = extractDelay( R_data,S_data,T_data,Q_data,P_data,rate)

index=19

dT=dT2
hT=hT2
wT=wT2

RRdelay = dT(index,1)*1000;
PQdelay = dT(index,2)*1000;
QRdelay = (dT(index,3)-dT(index,2))*1000;
Sdelay =  (dT(index,4)-dT(index,3))*1000;
RTdelay = (dT(index,5)-dT(index,3))*1000;

delay = [1.000000000000000;
         1.00000000000000;
         1.000000000000000;
         1.00000000000000 + Sdelay/1000 ;
         1.000000000000000];

ECGParams =  [hT(index,:)' (wT(index,:)') delay];

end


