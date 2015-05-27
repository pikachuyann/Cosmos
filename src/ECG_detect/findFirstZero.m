function i = findFirstZero(startIdx, array, useDiffSignal, interpolationAttempts)

if nargin == 3
    interpolationAttempts = 0;
end

diffSignal = array;
if useDiffSignal
    diffSignal = diff(array);
end

i = startIdx;
while i < length(diffSignal) && sign(diffSignal(i))==sign(diffSignal(i+1))
    i = i+1;
end

if i == length(diffSignal) && sign(diffSignal(i))==sign(diffSignal(i-1))
    if interpolationAttempts > 10
        i = inf;
    else
        x = startIdx:length(array);
        y = array(x);
        x_interp = startIdx:.5:length(array);
        interp = interp1(x,y,x_interp);
        i = startIdx + floor((findFirstZero(1, interp, useDiffSignal, interpolationAttempts+1))/2);
    end
end