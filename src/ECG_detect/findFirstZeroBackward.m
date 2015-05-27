function i = findFirstZeroBackward(startIdx, array, useDiffSignal, interpolationAttempts)
if nargin == 3
    interpolationAttempts = 0;
end

diffSignal = array;
if useDiffSignal
    diffSignal = diff(array);
end

i = startIdx - 1;
while i > 1 && sign(diffSignal(i))==sign(diffSignal(i-1))
    i = i-1;
end

if i == 1 && sign(diffSignal(i))==sign(diffSignal(i+1))
    if interpolationAttempts > 10
        i = -inf;
    else
        x = 1:startIdx;
        y = array(x);
        x_interp = 1:.5:startIdx;
        interp = interp1(x,y,x_interp);
        intr1 = fliplr(interp);
        i = startIdx - floor((findFirstZero(1, intr1, useDiffSignal, interpolationAttempts+1))/2);
    end
end