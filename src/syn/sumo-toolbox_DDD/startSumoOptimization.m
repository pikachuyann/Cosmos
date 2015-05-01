
function startSumoOptimization(mat2py, py2mat, nonLinearConstrainsFile, ...
    nParams, ranges, paramNames, safeRegIn, experimentName, numInitSamples, numTotalSamples, usePipes)
% init SUMO toolbox
%startup

%load the safe region file
global safeReg;
safeReg = safeRegIn;

%global var to store the current number of samples
global currentSampleNum;
currentSampleNum=0;

global pipes;
pipes = usePipes;

%file descriptor where simulated results are taken
global inFile;
if pipes
    inFile=fopen(py2mat,'r');
    if inFile < 1
        error(strcat('Error opening ', py2mat))
    end

else
    inFile = py2mat;
end


%path of the file where points to simulate are written
global outFile;
if pipes
    outFile=fopen(mat2py,'w');
    if outFile < 1
        disp(strcat('Error opening ', mat2py))
    end
else outFile=mat2py;
    
end

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
