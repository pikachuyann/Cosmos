load workspace_unstruct.mat
idRecording = '100';
tLimit = 120; %2 minutes
tLimit_sim = 3;
[ecg_sig,fs] = extractSignal(idRecording, tLimit);
[ParECG,filteredECG] = genECGParam(ecg_sig,fs,1,false);
%sim('HeartModelECG','SimulationMode','accelerator','StopTime', sprintf('%d',tLimit_sim));
%out=sim('HeartModelECG','StopTime', sprintf('%d',tLimit_sim),'SaveOutput','on','OutputSaveName','synth_ECG');
%synth_ECG=get(out,'synth_ECG');
%score=computeECGsdistance(filteredECG,fs,synth_ECG,1000,false);