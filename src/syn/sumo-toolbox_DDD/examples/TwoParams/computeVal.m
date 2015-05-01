function f = computeVal(x)
%f = x(:,1) + x(:,2);

global currentSampleNum;
global outFile;
global inFile;
global currentSamples;
global pipes;

if pipes
    fprintf(outFile,'%d,',ceil(x(:,1)));
    fprintf(outFile,'%d\n',ceil(x(:,2)));
    disp(strcat(sprintf('%d',currentSampleNum+1),'-th sample. Value: ',sprintf('%f,%f',x)));
    disp('Waiting for simulation results...');
    tline = fgetl(inFile);
    
else
    if currentSampleNum == 0
        fid_out = fopen(outFile,'w');
    else
        fid_out = fopen(outFile,'a');
    end
    
    fprintf(fid_out,'%d,',ceil(x(:,1)));
    fprintf(fid_out,'%d\n',ceil(x(:,2)));
    fclose(fid_out);
    disp(strcat(sprintf('%d',currentSampleNum+1),'-th sample. Value: ',sprintf('%f,%f',x)));
    disp('Waiting for simulation results...');
    pause(5);%wait 5 seconds
    fid_in=fopen(inFile,'r');
    fid_in=readLines(fid_in,currentSampleNum);
    tline = fgetl(fid_in);
    fclose(fid_in);
    %until results are written, wait 1 second and try to read
    while ~ischar(tline)
        pause(1);
        fid_in=fopen(inFile,'r');
        fid_in=readLines(fid_in,currentSampleNum);
        tline = fgetl(fid_in);
        fclose(fid_in);
    end
    
end
f=sscanf(tline,'%f');
disp(strcat('Result: ',tline));
currentSampleNum=currentSampleNum+1;
currentSamples(currentSampleNum,:)=[x,f];

