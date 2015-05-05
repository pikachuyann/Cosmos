
function startSumoOptimization(mat2py, py2mat, nonLinearConstrainsFile, ...
    nParams, ranges, paramNames, safeRegIn, experimentName, numInitSamples, numTotalSamples)
% init SUMO toolbox
%startup

%save the safe region file on a default .mat
safeReg = load(safeRegIn);
paramSpace = safeReg.paramSpace;
save('safeReg_tmp.mat','paramSpace');


%file descriptor where simulated results are taken
inFile=fopen(py2mat,'r');
if inFile < 1
    error(strcat('Error opening ', py2mat))
end
save('inFile_tmp.mat','inFile');


%path of the file where points to simulate are written
outFile=fopen(mat2py,'w');
if outFile < 1
    disp(strcat('Error opening ', mat2py))
end

save('outFile_tmp.mat','outFile');

smpls=zeros(0,nParams+1);
save('samples_tmp.mat','smpls');

if nParams==1
    configFile=writeConfigFile1D(numInitSamples, numTotalSamples, experimentName);
    writeExampleFile1D(nonLinearConstrainsFile, ranges(1,:), paramNames{1}, experimentName);
    surrogateModels = go(configFile);
    currentSamples = load('samples_tmp.mat');
    plotGP1d(surrogateModels{1}{1}, currentSamples.smpls, paramNames{1},ranges(1,:),experimentName);
elseif nParams==2
    configFile=writeConfigFile2D(numInitSamples, numTotalSamples, experimentName);
    writeExampleFile2D(nonLinearConstrainsFile, ranges, paramNames, experimentName);
    surrogateModels = go(configFile);
    currentSamples = load('samples_tmp.mat');
    plotGP2d(surrogateModels{1}{1}, currentSamples.smpls, paramNames,ranges,experimentName);
else
    disp('Only two params are supported. Exiting...');
end

%close pipes
inFile = load('inFile_tmp.mat');
fclose(inFile.inFile);
outFile = load('outFile_tmp.mat');
fclose(outFile.outFile);

end
