cd('~/Projects/Cosmos/src/syn/sumo-toolbox_DDD/');
path = '~/Projects/pacemaker/PaceMakerModel/';
mat2py = strcat(path,'mat2py.dat');
py2mat = strcat(path,'py2mat.dat');

% default
% saferegscript = 'saferegion';
% PM
saferegscript = 'safeRegPM';
nParams=2;
ranges = [150,200;600,1000];
paramNames = {'TURI','TLRI'};
safeRegionFile = 'PM_TURI_TLRI.mat';
experimentName = 'PM_TURI_TLRI';
numInitSamples = 3;
numTotalSamples = 50;

load(safeRegionFile);

startSumoOptimization(mat2py, py2mat, saferegscript, ...
    nParams, ranges, paramNames, paramSpace, experimentName, numInitSamples, numTotalSamples) 