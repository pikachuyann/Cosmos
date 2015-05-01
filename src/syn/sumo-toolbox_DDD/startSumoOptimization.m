
function startSumoOptimization(outFileName, inFileName, nonLinearConstrainsFile, ...
    nParams, ranges, paramNames, safeRegionFile, experimentName, numInitSamples, numTotalSamples)
% init SUMO toolbox
%startup

%global var to store the current number of samples
global currentSampleNum;
currentSampleNum=0;

%path of the file where points to simulate are written
global outFile;
outFile=outFileName;

%file descriptor where simulated results are taken
global inFile;
inFile = inFileName;

%load the safe region file
global safeReg;
safeReg=load(safeRegionFile);

global experimentNam;
experimentNam=experimentName;

global currentSamples;
currentSamples=zeros(numTotalSamples,nParams+1);

if nParams==1
    configFile=writeConfigFile1D(numInitSamples, numTotalSamples, experimentName);
    writeExampleFile1D(nonLinearConstrainsFile, ranges(1,:), paramNames{1}, experimentName);
    surrogateModels = go(configFile);
    plotGP1d(surrogateModels{1}{1}, currentSamples, paramNames{1},ranges(1,:),experimentName);
elseif nParams==2
    configFile=writeConfigFile2D(numInitSamples, numTotalSamples, experimentName);
	writeExampleFile2D(nonLinearConstrainsFile, ranges, paramNames, experimentName);
    surrogateModels = go(configFile);
    plotGP2d(surrogateModels{1}{1}, currentSamples, paramNames,ranges,experimentName);
else 
    disp('Only two params are supported. Exiting...');
end

end
