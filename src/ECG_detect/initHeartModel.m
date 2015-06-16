load workspace_unstruct.mat
idRecording = '100';
tLimit = 120; %2 minutes
tLimit_sim = 10;
[ecg_sig,fs] = extractSignal(idRecording, tLimit);
[ParECG,filteredECG] = genECGParam(ecg_sig,fs,1,false);
sim('HeartModelECG','SimulationMode','accelerator','StopTime', sprintf('%d',tLimit_sim));