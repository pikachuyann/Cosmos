function y = safeRegPM(x)
global safeReg;
p1_dis = ceil(x(:,1)/10);
p2_dis = ceil(x(:,2)/10);
reg=safeReg.paramSpace;
y= p1_dis;
for i=1:size(y,1)
    y(i) = (p1_dis(i)>size(reg,1) || p2_dis(i)>size(reg,2) || reg(p1_dis(i),p2_dis(i))>0)*2000;
end
end
