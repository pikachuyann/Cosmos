function f = computeVal(x)

inFile = load('inFile_tmp.mat');
inFile = inFile.inFile;
outFile = load('outFile_tmp.mat');
outFile = outFile.outFile;

currentSamples = load('samples_tmp.mat');
smpls = currentSamples.smpls;
currentSampleNum = size(smpls,1)+1;

fprintf(outFile,'%d\n',ceil(x(:,1)));
disp(strcat(sprintf('%d',currentSampleNum),'-th sample. Value: ',sprintf('%f',x)));
disp('Waiting for simulation results...');

tline = fgetl(inFile);


while strcmp(tline,'')
    tline = fgetl(inFile);
end


f=sscanf(tline,'%f');
disp(strcat('Result: ',tline));

smpls(currentSampleNum,:)=[x(:,1),f];
save('samples_tmp.mat','smpls');
