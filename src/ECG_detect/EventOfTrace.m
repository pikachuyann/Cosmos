function [ elist ] = EventOfTrace( trace )
%EVENTOFTRACE Summary of this function goes here
%   Detailed explanation goes here

ne = 4;
elist = zeros(1,ne);
indexes=ones(1,ne);

for i=1:length(trace)
    for j=1:ne
        indexes(1,j) = max(indexes(1,j),indexes(1,ne));
        if(trace(i,j) == 1)
            elist(indexes(1,j),j)=i/1000;
            indexes(1,j)=indexes(1,j)+1;
            if(indexes(1,j) > length(elist))
               elist = [elist ; zeros(1,ne)];
            end
        end
    end
end




end

