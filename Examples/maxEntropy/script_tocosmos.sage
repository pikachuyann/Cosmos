#!env sage

import sys
import os
import re


prismpath="/Users/benbot/Documents/prism-ptasmc/prism/bin/prism";


sagepath,ext = os.path.splitext(str(sys.argv[1]));
outpath=sagepath+'.grml';

isIsotropic=False;

if len(sys.argv)>2:
    outpath=str(sys.argv[2]);

print(str(sys.argv[1]) + ' -> ' + sagepath + '.sage' );

retval=os.system(prismpath + ' ' + str(sys.argv[1]) + ' -exportsplitreach ' + sagepath + '.sage');

print(sagepath + '.sage -> ' + outpath );
load(sagepath+'.sage')
numpoly=3;
if len(sys.argv)>3:
    numpoly=int(sys.argv[3])

if len(sys.argv)>4:
    if sys.argv[4] == "-isotropic" :
        isIsotropic = True;

objregexp= re.compile('')
if len(sys.argv)>5:
    objregexp=re.compile(sys.argv[5])

finstate = [ objregexp.match(namelist[i]) for i in range(len(namelist))];

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

#Two next function too change coefficient of translist to R 
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
    upperBound=[];
    for i in range(card_states):
        psiDeltaf.append([]);
        Cdf.append([]);
        Pdf.append([]);
        lowerBound.append([]);
        upperBound.append([]);
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
                lb=trans[0]-clockO(x,i,trans[1]);
                ub=trans[2]-clockO(x,i,trans[3]);
                psiDeltaf[i].append(weight);
                Pdf[i].append(pol2);
                Cdf[i].append(cdf);
                lowerBound[i].append(R(lb));
                upperBound[i].append(R(ub));
    return([psiDeltaf,Pdf,Cdf,lowerBound,upperBound]);    

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
if not isIsotropic :
    for i in range(1,numpoly+1):
        listres.append(Op(listres[i-1]));
    lastone=WeightsPdfCdf(listres[numpoly]);
else :
    lastone=WeightsPdfCdf(listres[0]);

def escapename(s):
    s2=s.replace('(','').replace(')','').replace('>','G').replace('<','L').replace('&','^');
    s3=s2.replace(',','_').replace('{','').replace('}','').replace('=','E').replace('-','M');
    return s3

def printGRML_distribution(quadriple):
    s="";
    for i in range(len(quadriple[1])):
        for j in range(len(quadriple[1][i])):
            s+='    <attribute name=\"UserDefineDistribution\">\n';            
            s+='      <attribute name=\"name\"> '+ "trans_%d"%i+"_%d"%j+ ' </attribute>\n';
            s+='      <attribute name=\"var\"> t </attribute>\n';
            s+='      <attribute name=\"lowerBound\">' + poly_to_c(quadriple[3][i][j]) + '</attribute>\n';
            s+='      <attribute name=\"upperBound\">' + poly_to_c(quadriple[4][i][j]) + '</attribute>\n';
            s+='      <attribute name=\"cdf\">('+ poly_to_c(quadriple[2][i][j]) +')/('+ poly_to_c(quadriple[0][i][j]) +')'+ '</attribute>\n';
            s+='      <attribute name=\"pdf\">('+ poly_to_c(quadriple[1][i][j]) +')/('+ poly_to_c(quadriple[0][i][j]) +')'+ '</attribute>\n';
            s+='    </attribute>\n'
    return(s);

def printGRML_OneArc(id,source,target):
    s="";
    s+='  <arc id=\"%s\"' %id +' arcType=\"arc\" source=\"%s\" ' %source + 'target=\"%s\" ' %target+'>\n';
    s+='    <attribute name=\"valuation\"><attribute name=\"expr\">\n';
    s+='      <attribute name=\"numValue\">1</attribute>\n';
    s+='    </attribute></attribute>\n';
    s+='  </arc>\n';
    return s;


def printGRML_OnePlace(id,name,marking):
    s="";
    s+='  <node id=\"%s\" ' %id +' nodeType=\"place\">\n';
    s+='    <attribute name=\"name\">%s' %name + ' </attribute>\n';
    s+='    <attribute name=\"marking\"><attribute name=\"expr\">\n';
    s+='      <attribute name=\"numValue\">%d '%marking+' </attribute>\n';
    s+='    </attribute></attribute>\n';
    s+='  </node>\n';
    return(s);

idalpha=dict((alphabet[i],i) for i in range(len(alphabet)));

def printGRML_arc(translist):
    s="";
    for i in range(len(alphabet)):
        s+=printGRML_OneArc('22%d' %i, '20%d' %i, '21%d' %i);
    for i in range(len(translist)):
        for j in range(len(translist[i])):
            action=idalpha[translist[i][j][5]];
            s+=printGRML_OneArc('14%d'%(idtrans[i][j]) , '11%d' %i, '13%d' %(idtrans[i][j]));
            s+=printGRML_OneArc('15%d'%(idtrans[i][j]) , '13%d' %(idtrans[i][j]), '12%d' %(idtrans[i][j]));
            s+=printGRML_OneArc('17%d'%(idtrans[i][j]) , '12%d' %(idtrans[i][j]), '16%d' %(idtrans[i][j]));
            s+=printGRML_OneArc('18%d'%(idtrans[i][j]) , '16%d' %(idtrans[i][j]), '11%d' %(translist[i][j][4][0][0]));
            s+=printGRML_OneArc('23%d' %(idtrans[i][j]), '16%d' %(idtrans[i][j]), '20%d' %action);
            if ( finstate[translist[i][j][4][0][0]]) :
                s+=printGRML_OneArc('18%d'%(idtrans[i][j]) , '16%d' %(idtrans[i][j]), '19');
    return(s);

    
def printGRML_place(translist):
    s="";
    s+= printGRML_OnePlace('19','TargetState',0);
    for i in range(len(translist)):
        s+= printGRML_OnePlace('11%d' %i,'s_%d_' %i, (i==0) );
        for j in  range(len(translist[i])):
            s+= printGRML_OnePlace('12%d' %(idtrans[i][j]),'s_%d' %i +'_%d' %j, 0 );
    for i in range(len(alphabet)):
        s+= printGRML_OnePlace('20%d' %i,'s_%s_' %(alphabet[i]), 0);
    return(s);

def printGRML_transition(translist,quadriple,isIsotropic):
    s="";
    for i in range(len(alphabet)):
        s+='  <node id=\"21%d\" ' %i +' nodeType=\"transition\">\n';
        s+='    <attribute name=\"name\">t_%s' %(alphabet[i]) +'</attribute>\n';
        s+='    <attribute name=\"distribution\">\n';
        s+='      <attribute name=\"type\">\n';
        s+='      IMDT\n';
        s+='      </attribute>\n'
        s+='    </attribute>\n';
        s+='    <attribute name=\"priority\"><attribute name=\"expr\">\n';
        s+='    <attribute name=\"numValue\"> 2.000000 </attribute>\n';
        s+='    </attribute></attribute>\n';
        s+='    <attribute name=\"weight\"><attribute name=\"expr\">\n';
        s+='    <attribute name=\"numValue\"> 1.000000 </attribute>\n';
        s+='    </attribute></attribute>\n';
        s+='  </node>\n';
    for i in range(len(translist)):
        for j in  range(len(translist[i])):
            s+='  <node id=\"13%d\" ' %(idtrans[i][j]) +' nodeType=\"transition\">\n';
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
            if(isIsotropic):
                s+='    <attribute name=\"numValue\"> 1.000000 </attribute>\n';
            else:
                s+='    <attribute name=\"unParsed\">'+ poly_to_c_bis(quadriple[0][i][j]) +'</attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='  </node>\n';
    for i in range(len(translist)):
        for j in  range(len(translist[i])):
            s+='  <node id=\"16%d\" ' %(idtrans[i][j]) +' nodeType=\"transition\">\n';
            s+='    <attribute name=\"name\">tt_%d' %i +'_%d' %j +'</attribute>\n';
            s+='    <attribute name=\"distribution\">\n';
            s+='      <attribute name=\"type\">\n' ;
            if(isIsotropic):
                s+='      UNIFORM\n';
            else:
                s+='      USERDEFINE\n';
            s+='      </attribute>\n';

            if(isIsotropic):
                s+='      <attribute name="param">\n'
                s+='        <attribute name="expr"><attribute name=\"unParsed\">'+ poly_to_c_bis(quadriple[3][i][j]) +'</attribute></attribute>\n';
                s+='      </attribute>\n'
                s+='      <attribute name="param">\n'
                s+='        <attribute name="expr"><attribute name=\"unParsed\">'+ poly_to_c_bis(quadriple[4][i][j]) +'</attribute></attribute>\n';
                s+='      </attribute>\n'
            else:
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
                if translist[i][j][4][0][c+1]==0:
                    s+='x_%d'%(c+1)+'=0;';
            s+='\n    </attribute>\n';
            s+='    <attribute name=\"priority\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"numValue\"> 1.000000 </attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='    <attribute name=\"weight\"><attribute name=\"expr\">\n';
            s+='      <attribute name=\"numValue\">1</attribute>\n';
            s+='    </attribute></attribute>\n';
            s+='  </node>\n';
    return(s);

def toCOSMOS(quadriple,isIsotropic):
    s='<?xml version="1.0" encoding=\"UTF-8\"?>\n\n<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">\n';
    s+='  <attribute name=\"declaration\">\n';
    if( not isIsotropic):
        s+=printGRML_distribution(quadriple);
    s+='    <attribute name="variables">\n';
    s+='      <attribute name="clocks">\n';
    for i in range(cardclocks):
        s+='        <attribute name="clock">\n';
        s+='        <attribute name="name"> x_%d '%(i+1)+'</attribute>\n';
        s+='        </attribute>\n';
    s+='      </attribute>\n';
    s+='    </attribute>\n';
    s+='  </attribute>\n';
    s+=printGRML_place(translist);
    s+=printGRML_transition(translist,quadriple,isIsotropic);
    s+=printGRML_arc(translist);
    s+='</model>\n';
    return(s);

fichier=open(outpath,"w");
fichier.write(toCOSMOS(lastone,isIsotropic));
fichier.close();
print ("output written in "+outpath) ;

if(not isIsotropic):
    fichier=open("Iso_"+outpath,"w");
    fichier.write(toCOSMOS(lastone,true));
    fichier.close();
