function y = saferegion(x)

safeReg = load('tmp/safeReg.mat');
p1_dis = ceil(x(:,1));
p2_dis = ceil(x(:,2));
y= p1_dis;
for i=1:size(y,1)
    y(i) = (p1_dis(i)>size(safeReg.paramSpace,1) || p2_dis(i)>size(safeReg.paramSpace,2) || safeReg.paramSpace(p1_dis(i),p2_dis(i))>0)*200;
end
end
