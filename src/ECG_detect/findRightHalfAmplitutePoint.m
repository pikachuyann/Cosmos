function i = findRightHalfAmplitutePoint(startIdx, array)


amp = array(startIdx);
if amp<0
    array = -array;
    amp = -amp;
end

i = startIdx;
while i < length(array) && array(i)~=amp/2 && ~(array(i)>amp/2 && array(i+1)<amp/2)
    i = i+1;
end

if i == length(array) && array(i-1)~=amp/2 && ~(array(i-1)>amp/2 && array(i)<amp/2)
    i = inf;
end