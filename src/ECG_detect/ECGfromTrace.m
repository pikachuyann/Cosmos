function [ y,time] = ECGfromTrace( trace,ECGPar,sample)
%ECGFROMTRACE Summary of this function goes here
%   Detailed explanation goes here

elist = EventOfTrace(trace);
elist = [elist(:,1:3) elist(:,3) elist(:,4)];
%Add S wave:
for i=1:length(elist)
   if(elist(i,4)~=0)
       r = unidrnd(size(ECGPar,1),1,1);
       elist(i,4) = elist(i,4) + ECGPar(r,14)/1000;
   end
end
time = max(max(elist))+1;
nbsample = ceil(time/sample);

ne = 5;

time = zeros(nbsample,1);
y = zeros(nbsample,1);

mins = 1;
maxs = 1;

HeightL = elist;
WidthL = elist;
for i=1:length(elist)
   for j=1:5
    if(elist(i,j)~=0)
       rh = unidrnd(size(ECGPar,1),1,1);
       HeightL(i,j) = ECGPar(rh,j);
       rw = unidrnd(size(ECGPar,1),1,1);
       WidthL(i,j) = ECGPar(rw,j+5);
    end
    end
end
   
for i=1:nbsample
   x= i*sample;
   time(i,1)=x;
   while(elist(mins,1)<x-5.0 && mins<length(elist) )
       mins = mins+1;
   end
   while(elist(maxs,5)<x+5.0 && maxs<length(elist))
       maxs = maxs+1;
   end
   
   for j=mins:maxs
       for k=1:ne
           if(elist(j,k)~=0)
            y(i,1) = y(i,1) + HeightL(j,k)*exp(- (((x-elist(j,k))/(WidthL(j,k)))^2.0) *4*log(2));
           end
       end
   end
end

end


