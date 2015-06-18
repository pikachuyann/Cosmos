load workspace_unstruct.mat
% idRecording = '118';
% tLimit = 120; %2 minutes
% tLimit_sim = 120;
% [ecg_sig,fs] = extractSignal(idRecording, tLimit);
% ecg_sig=EKG_andrea_light_activity(1:ceil(end/2));
ecg_sig=EKG_andrea_light_activity;
fs=100;
tLimit_sim = length(ecg_sig)/fs;
[ParECG,filteredECG] = genECGParam(ecg_sig,fs,1,true);
out=sim('HeartModelECG2','StopTime', sprintf('%d',tLimit_sim),'SaveOutput','on','OutputSaveName','heart_Events');
synth_ECG=ECGfromTrace(get(out,'heart_Events'),ParECG,1/fs);
score=computeECGsdistance(filteredECG,fs,synth_ECG,fs,true);

%out=sim('HeartModelECG','StopTime', sprintf('%d',tLimit_sim),'SaveOutput','on','OutputSaveName','synth_ECG');
%synth_ECG=get(out,'synth_ECG');
%score=computeECGsdistance(filteredECG,fs,synth_ECG,fs,true);