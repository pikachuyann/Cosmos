function [ ECGParams] = genECGParam( EKG,rate,time )
%GENECGPARAM Summary of this function goes here
%   Detailed explanation goes here
[R_data,S_data,T_data,Q_data,P_data,PQ_i, QR_i,RT_i,RR_i, ectopic, R_filtered, P_filtered, T_filtered, S_filtered, Q_filtered, heart_rate,buffer_plot]=peakdetect_offline(EKG,rate,time);
[ dT2 , hT2, wT2] = extractDelay( R_filtered,S_filtered,T_filtered,Q_filtered,P_filtered,rate)

index=19

dT=dT2
hT=hT2
wT=wT2

RRdelay = dT(:,1)*1000;
PQdelay = dT(:,2)*1000;
QRdelay = (dT(:,3)-dT(:,2))*1000;
Sdelay =  (dT(:,4)-dT(:,3))*1000;
RTdelay = (dT(:,5)-dT(:,3))*1000;

delay = [RRdelay PQdelay QRdelay Sdelay RTdelay];

%ECGParams =  [ hT(index,:)' (wT(index,:)') (delay(index,:)') ];

ECGParams =  [ hT wT delay];

end


