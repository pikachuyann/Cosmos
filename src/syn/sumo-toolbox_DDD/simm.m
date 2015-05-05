sumoPath='~/Projects/Cosmos/src/syn/sumo-toolbox_DDD/';
pyPath='~/Projects/pacemaker/PaceMakerModel/';
%sumoPath='~/work/gitFolders/Cosmos/src/syn/sumo-toolbox_DDD/';
%pyPath='~/work/gitFolders/pacemaker/PaceMakerModel/';

cd(sumoPath);
mat2py = strcat(pyPath,'mat2py.dat');
py2mat = strcat(pyPath,'py2mat.dat');

% default
% saferegscript = 'saferegion';
% PM
saferegscript = 'safeRegPM';
nParams=2;
ranges = [150,200;600,1000];
paramNames = {'TURI','TLRI'};
safeRegionFile = 'PM_TURI_TLRI.mat';
experimentName = 'PM_TURI_TLRI';
numInitSamples = 4;
numTotalSamples = 10;


startSumoOptimization(mat2py, py2mat, saferegscript, ...
    nParams, ranges, paramNames, safeRegionFile, experimentName, ...
    numInitSamples, numTotalSamples) 