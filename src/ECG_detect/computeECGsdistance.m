function [score,scores,ECGmean_1,ECGsd_1,ECG_distr_1,ECGmean_2,ECGsd_2,ECG_distr_2] = computeECGsdistance(ecg_1,fs_1,ecg_2,fs_2,plot,nbinsDiscreteDistr)

if nargin < 6
    nbinsDiscreteDistr = 10;
    if nargin < 5
        plot = 0;
    end
end

ecgBins=min(fs_1,fs_2)/2;
[ECGmean_1,ECGsd_1,ECG_distr_1] = computeECGDistr(ecg_1',fs_1,ecgBins,plot,'Data 1');
[ECGmean_2,ECGsd_2,ECG_distr_2] = computeECGDistr(ecg_2',fs_2,ecgBins,plot,'Data 2');

[score,scores] = discreteDistrsDistance(ECG_distr_1,ECG_distr_2,nbinsDiscreteDistr,ecgBins);
end

function [ECGmean,ECGsd,discreteDistrs] = computeECGDistr(data,fs,bins,plot,desc)

if nargin == 3
    plot = 0;
    desc = '';
end

teta = 0;                                       % desired phase shift
f = 1;                                          % approximate R-peak frequency

bsline = LPFilter(data,.7/fs);                 % baseline wander removal (may be replaced by other approaches)

x = data-bsline;
peaks = PeakDetection(x,f/fs);                  % peak detection

[phase phasepos] = PhaseCalculation(peaks);     % phase calculation

pphase = PhaseShifting(phase,teta);             % phase shifting

%bins = fs/2;                                     % number of phase bins
[ECGmean,ECGsd,meanphase,discreteDistrs] = MeanECGExtraction(x,pphase,bins,1); % mean ECG extraction
if plot
    t = (0:length(data)-1)/fs;
    figure;
    plot(t,data*6/max(data),'b');
    hold on
    plot(t,peaks*2,'ro');
    plot(t,phase,'c--','linewidth',1);
    plot(t,pphase,'g','linewidth',1);
    grid;
    xlabel('time (sec.)');
    legend(strcat('Scaled ECG ',desc),strcat('ECG Peaks ',desc),strcat('phase ',desc),strcat('shifted phase ',desc));
    
    figure;
    errorbar(meanphase,ECGmean,ECGsd/2);
    hold on;
    plot(meanphase,ECGmean,'r');
    legend(strcat('SD Bar ',desc),strcat('Mean ECG ',desc));
    xlabel('phase (rads.)');
    grid
end
end