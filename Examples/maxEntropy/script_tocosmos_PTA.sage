#!env sage

import sys
import os
import re
from exportGrML import *

## Set Parameters 
#prismpath="prism";
prismpath="~/Documents/prism/prism-ptasmc/prism/bin/prism ";

sagepath,ext = os.path.splitext(str(sys.argv[1]));
outpath=sagepath+'.grml';

isIsotropic=False;

numpoly=3;
if len(sys.argv)>3:
    numpoly=int(sys.argv[3])

Dline=50;
if len(sys.argv)>4:
    Dline = int(sys.argv[4])

if len(sys.argv)>5:
    if sys.argv[5] == "-isotropic" :
        isIsotropic = True;

        
objregexp= re.compile('')
if len(sys.argv)>5:
    objregexp=re.compile(sys.argv[5])

if len(sys.argv)>2:
    outpath=str(sys.argv[2]);
################################################################################   

## Launch Prism    
print(str(sys.argv[1]) + ' -> ' + sagepath + '.sage' );
retval=os.system(prismpath + ' ' + str(sys.argv[1]) + ' -exportsplitreach ' + sagepath + '.sage');
print(sagepath + '.sage -> ' + outpath );

## Load Region Graph
load(sagepath+'.sage')


finstate = [ objregexp.match(statelist[i]['name']) for i in range(len(statelist))];

#cardclocks=len(statelist[0]['transition'][0]['miniedge'][0]['reset']);#@Benoit: il faut que une ligne en plus en sortie de PRISM qui donne cardclocks=TRUC; Done;
card_states=len(statelist);
xsanszero=['x_%d' %i for i in range(1,cardclocks+1)];
xsanszero.append('t');
#R = PolynomialRing(QQ,cardclocks+1,xsanszero);#Put QQ to have rational
accuracy=53;
R = PolynomialRing(RealField(accuracy),cardclocks+1,xsanszero);
R.inject_variables();
x=list(R.gens());

## Assign a unique identifier per transition and edge and compute inverse mapping
c=0;
d=0;
idtransinv=[];
idedgeinv=[];
for state in statelist:
    j=-1;
    for trans in state['transition']:
        j=j+1;
        trans['id']=c;
        idtransinv.append((state['id'],j));
        c=c+1;
        k=-1;
        for edge in trans['miniedge']:
            k=k+1;
            edge['id']=d;
            idedgeinv.append((state['id'],j,k));
            d=d+1;

def toDisjointSet(list,m):
    res=DisjointSet(m)
    for i in range(len(list)):
        for j in range(len(list[i])):
            res.union(list[i][0],list[i][j]);
    return(res);

yy=[[toDisjointSet(state['redcoord'],cardclocks+1).find(j) for j in range(1,cardclocks+1)] for state in statelist];

#Change proability coefficients of miniedge to R: real field with a given accuracy (53 bits)
for state in statelist:
    for trans in state['transition']:
        for edge in trans['miniedge']:
            edge['prob']=R(edge['prob']);

def clockO(list,i,l): #In the ith state the lth clock is either equal to 0 either equal to x_{yy[i][l-1]-1}
    if l==0:
        return 0;
    if yy[i][l-1]==0:
        return 0;
    return list[yy[i][l-1]-1];
    
def WeightsPdfCdf(f): #Compute one iteration of operator Op with all weights/pdf/cdf computed for this iteration.
    psiDeltaf=[];            #psiDeltaf[i][j][k] weight of Delta
    Cdf=[];                #Integ[i][j][k][e] primitive of f(r(x+t)) wrt t;
    Pdf=[];
    for state in statelist:
        i=state['id'];
        psiDeltaf.append([]);        
        Cdf.append([]);
        Pdf.append([]);
        j=-1;
        for trans in state['transition']:
            j=j+1;
            psiDeltaf[i].append(0);
            Cdf[i].append(0);
            Pdf[i].append(0);
            for edge in trans['miniedge']: #for each mini-edge (in TA there is only 1)
                pol1=f[edge['target']];
                listcoef=[(edge['reset'][l])*(clockO(x,i,l+1)+t) for l in range(cardclocks)];#the reset depend on the mini-edge
                listcoef.append(0);
                pdf=pol1(listcoef);
                pol=integral(pdf,t);
                z=trans['zone'];
                cdf=pol - pol(t=z[0]-clockO(x,i,z[1]));
                weight=pol(t=z[2]-clockO(x,i,z[3]))-pol(t=z[0]-clockO(x,i,z[1]));
                psiDeltaf[i][j]=psiDeltaf[i][j]+(edge['prob'])*weight;
                Pdf[i][j]=Pdf[i][j]+ (edge['prob'])*pdf;
                Cdf[i][j]=Cdf[i][j]+ (edge['prob'])*cdf;
    return({'psiDeltaf':psiDeltaf,
            'Pdf':Pdf,
            'Cdf':Cdf});

def sumlist(l):
    accu=0;
    for i in range(len(l)):
        accu=accu+l[i];
    return(accu);

#numpoly=5;

## Polynomes Computation #######################################################
allones=[WeightsPdfCdf([R(1) for i in range(card_states)])];
if not isIsotropic :
    print("Polynome Computation: ["),
    for k in range(1,numpoly+1):
        allones.append(WeightsPdfCdf([sumlist(allones[k-1]['psiDeltaf'][i]) for i in range(len(allones[k-1]['psiDeltaf']))]));
        print("|"),
        sys.stdout.flush(),
    #lastone=WeightsPdfCdf(listres[numpoly]);
    print("]\n");
lastone=allones[len(allones)-1];
################################################################################

fichier_data=open(outpath+'.data',"w");

## GrML export
for state in statelist:
    for trans in state['transition']:
        trans['lowerBound']=R(trans['zone'][0]-clockO(x,int(state['id']),trans['zone'][1]));
        trans['lowerBoundId']=poly_to_data( trans['lowerBound'],fichier_data,cardclocks );
        trans['upperBound']=R(trans['zone'][2]-clockO(x,int(state['id']),trans['zone'][3]));
        trans['upperBoundId']=poly_to_data( trans['upperBound'],fichier_data,cardclocks);


idalpha=dict((alphabet[i],i) for i in range(len(alphabet)));

def printGRML_arc(statelist):
    s="";
    for i in range(len(alphabet)):
        s+=printGRML_OneArc('22', '20%d' %i, '21%d' %i);
    for state in statelist:
        for trans in state['transition']:
            action=idalpha[trans['action']];
            s+=printGRML_OneArc('14', "11%d" %(state['id']), '13%d' %(trans['id']));
            s+=printGRML_OneArc('15', '13%d' %(trans['id']), '12%d' %(trans['id']));
            s+=printGRML_OneArc('17', '12%d' %(trans['id']), '16%d' %(trans['id']));
            s+=printGRML_OneArc('23', '16%d' %(trans['id']), '20%d' %action);#C est quoi? -> ca active une transition qui porte le meme label que l'action 
            s+=printGRML_OneArc('31', '16%d' %(trans['id']), '240');#C est quoi? -> ca compte le nombre d'action
            s+=printGRML_OneArc('18', '16%d' %(trans['id']), '30%d' %(trans['id']));
            for edge in trans['miniedge']:#NEW
                s+=printGRML_OneArc('24', '30%d' %(trans['id']), '25%d' %(edge['id']));
                s+=printGRML_OneArc('26', '25%d' %(edge['id']), '11%d' %(edge['target']));
                if ( finstate[edge['target']]) :#Ca sert a quoi? c'est pour ecrire des formul (F s) ou s est un etat 
                    s+=printGRML_OneArc('19', '16%d' %(trans['id']), '19');
    return(s);

    
def printGRML_place(statelist):
    s="";
    s+= printGRML_OnePlace('240','Counter',0);
    s+= printGRML_OnePlace('19','TargetState',0);
    for state in statelist:
        i=state['id'];
        s+= printGRML_OnePlace('11%d' %i,'s_%d_1' %i, (i==0) );
        j=-1;
        for trans in state['transition']:
            j=j+1;        
            s+= printGRML_OnePlace('12%d' %(trans['id']),'s_%d' %i +'_%d_2' %j, 0 );#The place before choosing time associated to transition i,j
            s+= printGRML_OnePlace('30%d' %(trans['id']),'s_%d' %i +'_%d_3' %j, 0 );#The place after choosing time, before choosing mini-edge
    for i in range(len(alphabet)):
        s+= printGRML_OnePlace('20%d' %i,'s_%s_' %(alphabet[i]), 0);
    return(s);

passingClockParameters = "0.0";
for i in range(cardclocks):
    passingClockParameters += ",x_%d" %(i+1);




def printGRML_transition(statelist,allones,isIsotropic,Dline):
    s="";
    for i in range(len(alphabet)):
        s+=printGRML_OneInstaTransition('21%d' %i,'t_%s' %(alphabet[i]),"2",
                                        "<attribute name=\"numValue\"> 1.000000 </attribute>",
                                        "");
    for state in statelist:
        i=state['id'];
        j=-1;
        for trans in state['transition']:
            j=j+1;
            # Choose action
            t="";
            if(isIsotropic):
                t+='    <attribute name=\"numValue\"> 1.000000 </attribute>\n';
            else:
                t+='    <attribute name=\"unParsed\"> customDistr.evalPoly(%d' %nbpoly +' + min( %i '%(Dline) + '-Marking.P->_PL_Counter, %d )' %(len(allones)-1);
                for k in range(len(allones)):
                    poly_to_c_data(allones[k]['psiDeltaf'][i][j],fichier_data,cardclocks);#poids de la transition i j
                    
                t+= ', {'+ passingClockParameters +',0.0}) </attribute>\n';#C est quoi ca -> c'est pour passer les valeur d'horloge
                #Pour cosmos les horloge sont juste des variable il faut mapper les variable du polynomes aux horloges 
            s+=printGRML_OneInstaTransition('13%d' %(trans['id']),
                                            't_%d' %i +'_%d_' %j + (trans['action']),
                                            "1",
                                            t,
                                            "");
                
            #choose time
            t='      <attribute name=\"type\">\n';
            if(isIsotropic):
                t+='      UNIFORM\n';
            else:
                t+='      USERDEFINE\n';
            t+='      </attribute>\n';

            if(isIsotropic):
                t+='      <attribute name="param">\n'
                t+='        <attribute name="expr"><attribute name=\"unParsed\">'+ poly_to_c_data(trans['lowerBound'],fichier_data,cardclocks) +'</attribute></attribute>\n';
                t+='      </attribute>\n'
                t+='      <attribute name="param">\n'
                t+='        <attribute name="expr"><attribute name=\"unParsed\">'+ poly_to_c_data(trans['upperBound'],fichier_data,cardclocks) +'</attribute></attribute>\n';
                t+='      </attribute>\n'
            else:
                t+='      <attribute name="param">\n'
                t+='        <attribute name="expr"><attribute name=\"unParsed\"> transDistrTab[%d]' %(trans['id']) +'[min( %i' %(Dline) + '-Marking.P->_PL_Counter, %d )]' %(len(allones)-1); 
                t+='        </attribute></attribute>\n';
                t+='      </attribute>\n';
                for c in range(cardclocks):
                    t+='      <attribute name="param">\n';
                    t+='        <attribute name="expr"><attribute name="name">\n';
                    t+='          x_%d'%(c+1)+'\n';
                    t+='        </attribute></attribute>\n';
                    t+='      </attribute>\n';

            s+=printGRML_OneTransition('16%d' %(trans['id']),
                                       'tt_%d' %i +'_%d' %j,
                                       t,
                                       "1.00",
                                       "<attribute name=\"numValue\">1</attribute>",
                                       "");
                                    
            k=-1;
            for edge in trans['miniedge']:
                k=k+1;
                t='<attribute name=\"update\">\n    ';
                for c in range(cardclocks):
                    if edge['reset'][c]==0:
                        t+='x_%d'%(c+1)+'=0;';
                t+='\n    </attribute>';
                
                s+=printGRML_OneInstaTransition('25%d' %(edge['id']),
                                             'ttt_%d' %i +'_%d_' %j + '%d' %k,
                                             "1",
                                             '<attribute name=\"numValue\"> %f </attribute>\n' %(edge['prob']),
                                             t);
    return(s);

def toCOSMOS(allones,isIsotropic,Dline):
    s='<?xml version="1.0" encoding=\"UTF-8\"?>\n\n<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">\n';
    s+='  <attribute name=\"declaration\">\n';
    s+='  <attribute name=\"constants\">\n';
    s+='  <attribute name=\"intConsts\">\n';
    s+='  <attribute name=\"intConst\">\n';
    s+='      <attribute name=\"name\">Dline</attribute>\n';
    s+='      <attribute name=\"expr\"><attribute name=\"numValue\">%i</attribute></attribute>\n' %(Dline);
    s+='  </attribute>\n';
    s+='  </attribute>\n';
    s+='  </attribute>\n';    
    tab = "";
    if( not isIsotropic):
        (s2,tab2)=printGRML_distribution(allones,idtransinv,statelist,outpath,cardclocks,fichier_data);#alldistr
        s+=s2;
        tab=matrix_to_c(tab2,"transDistrTab");
    s+='    <attribute name="variables">\n';
    s+='      <attribute name="clocks">\n';
    for i in range(cardclocks):
        s+='        <attribute name="clock">\n';
        s+='        <attribute name="name"> x_%d '%(i+1)+'</attribute>\n';
        s+='        </attribute>\n';
    s+='      </attribute>\n';
    s+='    </attribute>\n';
    s+='  </attribute>\n';
    s+= '  <attribute name=\"externalDeclaration\">\n'
    s+= 'void magicReset(){};\n'
    s+= 'bool magicConditional(int){return true;};\n'
    s+= 'void magicUpdate(int,double){};\n'
    s+= 'int print_magic(int i){return i;};\n'
    s+= tab+'</attribute>\n';
    s+=printGRML_place(statelist);
    s+=printGRML_transition(statelist,allones,isIsotropic,Dline);
    s+=printGRML_arc(statelist);
    s+='</model>\n';
    return(s);

fichier=open(outpath,"w");
fichier.write(toCOSMOS(allones,isIsotropic,Dline));
fichier.close();

print ("output written in "+outpath) ;
if(not isIsotropic):
    fichier=open("Iso_"+outpath,"w");
    fichier.write(toCOSMOS(allones,true,Dline));
    fichier.close();
