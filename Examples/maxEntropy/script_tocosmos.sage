#!/Applications/Sage-6.7.app/Contents/Resources/sage/sage

import sys
import os

prismpath="~/Documents/prism-ptasmc/prism/bin/prism";

sagepath,ext = os.path.splitext(str(sys.argv[1]))
print(str(sys.argv[1]) + ' -> ' + sagepath + '.sage' );

retval=os.system(prismpath + ' ' + str(sys.argv[1]) + ' -exportsplitreach ' + sagepath + '.sage');

print(sagepath + '.sage -> ' + sys.argv[2] );
load(sagepath+'.sage')
numpoly=3;
if len(sys.argv)>3:
    numpoly=int(sys.argv[3])



cardclocks=len(translist[0][0][4][0])-2;
card_states=len(translist);
xsanszero=['x_%d' %i for i in range(1,cardclocks+1)];
xsanszero.append('t');
#R = PolynomialRing(QQ,cardclocks+1,xsanszero);#Put QQ to have rational
accuracy=53;
R = PolynomialRing(RealField(accuracy),cardclocks+1,xsanszero);
R.inject_variables();
x=list(R.gens());

#assign a unique identifier per transition and compute inverse mapping
idtrans=[[0 for j in range(len(translist[i]))] for i in range(len(translist))];
c=0;
idtransinv=[];
for i in range(len(translist)):
    for j in range(len(translist[i])):
        idtrans[i][j]=c;
        idtransinv.append((i,j));
        c=c+1;

def toDisjointSet(list,m):
    res=DisjointSet(m)
    for i in range(len(list)):
        for j in range(len(list[i])):
            res.union(list[i][0],list[i][j]);
    return(res);

yy=[[toDisjointSet(redcoord[i],cardclocks+1).find(j) for j in range(1,cardclocks+1)] for i in range(len(redcoord))];

#Two next function two change coefficient of translist to R 
def tominiedge(miniedge,R):
    miniedge[len(miniedge)-1]=R(miniedge[len(miniedge)-1])
    return();
def toRing(R):
    for i in range(card_states):
        for j in range(len(translist[i])):
            trans=translist[i][j];
            probaedges=trans[4];
            for k in range(len(probaedges)):
                tominiedge(probaedges[k],R);
    return();
    
toRing(R);

def succtrans(curloc,Delta):
    s=0;
    transl=translist[curloc];
    for j in range(len(transl)):
        for k in range(len(transl[j][4])):
            if Delta==s:
                return([j,k]);    
            s=s+1;
    print(crach);
    return();

def clockO(list,i,l): #In the ith state the lth clock is either equal to 0 either equal to x_{yy[i][l-1]-1}
    if l==0:
        return 0;
    if yy[i][l-1]==0:
        return 0;
    return list[yy[i][l-1]-1];

def Op(f):
    psif=[];
    for i in range(card_states):
        psif.append(0);
        for j in range(len(translist[i])):
            trans=translist[i][j];
            probaedges=trans[4];
            for k in range(len(probaedges)):
                pol1=f[probaedges[k][0]];
                listcoef=[(probaedges[k][l])*(clockO(x,i,l)+t) for l in range(1,cardclocks+1)];
                listcoef.append(0);
                pol2=pol1(listcoef);
                pol=integral(pol2,t);
                #print(listcoef,pol);
                psif[i]=(psif[i])+(probaedges[k][len(probaedges[k])-1])*(pol(t=trans[2]-clockO(x,i,trans[3]))-pol(t=trans[0]-clockO(x,i,trans[1])))
    return(psif);
    
def WeightsPdfCdf(f):
    psiDeltaf=[];            #psiDeltaf[i][j][k] weight of Delta
    Cdf=[];                #Integ[i][j][k] primitive of f(r(x+t)) wrt t;
    Pdf=[];
    lowerBound=[];
    for i in range(card_states):
        psiDeltaf.append([]);
        Cdf.append([]);
        Pdf.append([]);
        lowerBound.append([]);
        for j in range(len(translist[i])):
            trans=translist[i][j];
            probaedges=trans[4];
            for k in range(len(probaedges)):
                pol1=f[probaedges[k][0]];
                listcoef=[(probaedges[k][l])*(clockO(x,i,l)+t) for l in range(1,cardclocks+1)];
                listcoef.append(0);
                pol2=pol1(listcoef);
                pol=(probaedges[k][len(probaedges[k])-1])*integral(pol2,t);
                cdf=pol - pol(t=trans[0]-clockO(x,i,trans[1]));
                weight=pol(t=trans[2]-clockO(x,i,trans[3]))-pol(t=trans[0]-clockO(x,i,trans[1]));
                lb=trans[2]-clockO(x,i,trans[3]);
                psiDeltaf[i].append(weight);
                Pdf[i].append(pol2);
                Cdf[i].append(cdf);
                lowerBound[i].append(R(lb));
    return([psiDeltaf,Pdf,Cdf,lowerBound]);    

def poly_to_c(p):
    supp=p.exponents();
    s='0.0';
    for triplet in supp:
        s+='+('+ str(p[triplet])+')';
        for j in range(cardclocks):
            if triplet[j]==1:
                s+="*param[%d]" %(j+1);
            if triplet[j]>1:
                s+="*pow(param[%d]," %(j+1)+ str(triplet[j]) +')';
        if triplet[cardclocks]==1:
            s+="*t";
        if triplet[cardclocks]>1:
            s+="*pow(t,"+ str(triplet[cardclocks])+')';
    return(s);
    
def poly_to_c_bis(p):
    supp=p.exponents();
    s='0.0';
    for triplet in supp:
        s+='+('+ str(p[triplet])+')';
        for j in range(cardclocks):
            if triplet[j]==1:
                s+="*x_%d" %(j+1);
            if triplet[j]>1:
                s+="*pow(x_%d," %(j+1)+ str(triplet[j]) +')';
        if triplet[cardclocks]==1:
            s+="*t";
        if triplet[cardclocks]>1:
            s+="*pow(t,"+ str(triplet[cardclocks])+')';
    return(s);

def sumlist(l):
    accu=0;
    for i in range(len(l)):
        accu=accu+l[i];
    return(accu);

listres=[[R(1) for i in range(card_states)]];
for i in range(1,numpoly+1):
    listres.append(Op(listres[i-1]));

lastone=WeightsPdfCdf(listres[numpoly]);

def toCOSMOS(quadriple):
    s='<?xml version="1.0" encoding=\"UTF-8\"?>\n\n<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">\n';
    s+='  <attribute name=\"declaration\">\n';
    for i in range(len(quadriple[1])):
        for j in range(len(quadriple[1][i])):
            s+='    <attribute name=\"UserDefineDistribution\">\n';            
            s+='      <attribute name=\"name\"> '+ "trans_%d"%i+"_%d"%j+ ' </attribute>\n';
            s+='      <attribute name=\"var\"> t </attribute>\n';
            s+='      <attribute name=\"lowerBound\">' + poly_to_c(quadriple[3][i][j]) + '</attribute>\n';
            s+='      <attribute name=\"cdf\">('+ poly_to_c(quadriple[2][i][j]) +')/('+ poly_to_c(quadriple[3][i][j]) +')'+ '</attribute>\n';
            s+='      <attribute name=\"pdf\">('+ poly_to_c(quadriple[1][i][j]) +')/('+ poly_to_c(quadriple[3][i][j]) +')'+ '</attribute>\n';
            s+='    </attribute>\n';
    s+='    <attribute name="variables">\n';
    s+='      <attribute name="clocks">\n';
    for i in range(cardclocks):
        s+='        <attribute name="clock">\n';
        s+='        <attribute name="name"> x_%d '%(i+1)+'</attribute>\n';
        s+='        </attribute>\n';
    s+='      </attribute>\n';
    s+='    </attribute>\n';
    s+='  </attribute>\n';
    for i in range(len(translist)):
        s+='  <node id=\"1%d\" ' %i +' nodeType=\"place\">\n';
        s+='    <attribute name=\"name\">s_%d ' %i +' </attribute>\n';
        s+='    <attribute name=\"marking\"><attribute name=\"expr\">\n';
        s+='      <attribute name=\"numValue\">%d '%(i==0)+' </attribute>\n';
        s+='    </attribute></attribute>\n';
        s+='  </node>\n';
        for j in  range(len(translist[i])):
            s+='  <node id=\"2%d\" ' %(idtrans[i][j]) +' nodeType=\"place\">\n';
            s+='    <attribute name=\"name\">s_%d' %i +'_%d' %j +'</attribute>\n';
            s+='    <attribute name=\"marking\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"numValue\"> 0 </attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='  </node>\n';
    for i in range(len(translist)):
        for j in  range(len(translist[i])):
            s+='  <node id=\"3%d\" ' %(idtrans[i][j]) +' nodeType=\"transition\">\n';
            s+='    <attribute name=\"name\">t_%d' %i +'_%d' %j +'</attribute>\n';
            s+='    <attribute name=\"distribution\">\n';
            s+='      <attribute name=\"type\">\n';
            s+='      IMDT\n';
            s+='      </attribute>\n'
            s+='    </attribute>\n';
            s+='    <attribute name=\"priority\"><attribute name=\"expr\">\n';
            s+='    <attribute name=\"numValue\"> 1.000000 </attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='    <attribute name=\"weight\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"unParsed\">'+ poly_to_c_bis(quadriple[0][i][j]) +'</attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='  </node>\n';
    for i in range(len(translist)):
        for j in  range(len(translist[i])):
            s+='  <node id=\"6%d\" ' %(idtrans[i][j]) +' nodeType=\"transition\">\n';
            s+='    <attribute name=\"name\">tt_%d' %i +'_%d' %j +'</attribute>\n';
            s+='    <attribute name=\"distribution\">\n';
            s+='      <attribute name=\"type\">\n' ;
            s+='      USERDEFINE\n';
            s+='      </attribute>\n';
            s+='      <attribute name="param">\n'
            s+='        <attribute name="expr"><attribute name=\"'+'trans_%d'%i+'_%d'%j+'\">\n';
            s+='        </attribute></attribute>\n';
            s+='      </attribute>\n';
            for c in range(cardclocks):
                s+='      <attribute name="param">\n';
                s+='        <attribute name="expr"><attribute name="name">\n';
                s+='          x_%d'%(c+1)+'\n';
                s+='        </attribute></attribute>\n';
                s+='      </attribute>\n';
            s+='    </attribute>\n';
            s+='    <attribute name=\"update\">\n    ';
            for c in range(cardclocks):
                s+='x_%d'%(c+1)+'=0;';
            s+='\n    </attribute>\n';
            s+='    <attribute name=\"priority\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"numValue\"> 1.000000 </attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='    <attribute name=\"weight\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"numValue\">1</attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='  </node>\n';
    for i in range(len(translist)):
        for j in  range(len(translist[i])):
            s+='  <arc id=\"4%d\"'%(idtrans[i][j])+' arcType=\"arc\" source=\"1%d\" ' %i + 'target=\"3%d\" ' %(idtrans[i][j])+'>\n';
            s+='    <attribute name=\"valuation\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"numValue\">1</attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='  </arc>\n';
    for i in range(len(translist)):
        for j in  range(len(translist[i])):
            s+='  <arc id=\"5%d\"'%(idtrans[i][j])+' arcType=\"arc\" source=\"3%d\" ' %(idtrans[i][j]) + 'target=\"2%d\" '%(idtrans[i][j])+'>\n';
            s+='    <attribute name=\"valuation\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"numValue\"> 1 </attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='  </arc>\n';
    for i in range(len(translist)):
        for j in  range(len(translist[i])):
            s+='   <arc id=\"7%d\"'%(idtrans[i][j])+' arcType=\"arc\" source=\"2%d\" ' %(idtrans[i][j]) + 'target=\"6%d\" '%(idtrans[i][j])+'>\n';
            s+='    <attribute name=\"valuation\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"numValue\">1</attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='  </arc>\n';
    for i in range(len(translist)):
        for j in  range(len(translist[i])):
            s+='  <arc id=\"8%d\"'%(idtrans[i][j])+' arcType=\"arc\" source=\"6%d\" ' %(idtrans[i][j]) + 'target=\"1%d\" '%(translist[i][j][4][0][0])+'>\n';
            s+='    <attribute name=\"valuation\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"numValue\">1</attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='  </arc>\n';
    s+='</model>\n';
    return(s);

fichier=open(str(sys.argv[2]),"w");
fichier.write(toCOSMOS(lastone));
fichier.close();
print ("output written in "+str(sys.argv[2])) ;
