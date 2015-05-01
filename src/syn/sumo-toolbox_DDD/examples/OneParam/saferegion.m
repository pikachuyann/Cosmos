function y = saferegion(x)
global safeReg;
p1_dis = ceil(x(:,1));
reg=safeReg.paramSpace;
y= p1_dis;
for i=1:size(y,1)
    y(i) = (p1_dis(i)>size(reg,1) || reg(p1_dis(i))>0)*200;
end
end
