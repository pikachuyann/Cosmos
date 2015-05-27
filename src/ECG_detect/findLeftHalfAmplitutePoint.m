function i = findLeftHalfAmplitutePoint(startIdx, array)


amp = array(startIdx);
if amp<0
    array = -array;
    amp = -amp;
end

i = startIdx - 1;
while i > 1 && array(i)~=amp/2 && ~(array(i)>amp/2 && array(i-1)<amp/2)
    i = i-1;
end

if i == 1 && array(i+1)~=amp/2 && ~(array(i)>amp/2 && array(i+1)<amp/2)
    i = -inf;
end