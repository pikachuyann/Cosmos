#!env sage

import sys
import os
import re


#prismpath="prism";

prismpath="~/Documents/prism/prism-ptasmc/prism/bin/prism ";

sagepath,ext = os.path.splitext(str(sys.argv[1]));
outpath=sagepath+'.grml';

isIsotropic=False;

if len(sys.argv)>2:
    outpath=str(sys.argv[2]);

print(str(sys.argv[1]) + ' -> ' + sagepath + '.sage' );

retval=os.system(prismpath + ' ' + str(sys.argv[1]) + ' -exportsplitreach ' + sagepath + '.sage');
print(sagepath + '.sage -> ' + outpath );
load(sagepath+'.sage')

#REDO THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!
#Put [] in sink states using iteration on graphs;
#modified=true;#true until fixed point is reached
#while modified==true:
#    modified=false;
#    for state in statelist:
#        new_state=[];
#        for trans in state['transition']:
#            trans2=[trans[k] for k in range(4)];
#            trans2.append([]);
#            trans2.append(trans[5]);
#            print(trans);
#            for edge in trans['miniedge']:
#                if statelist[edge[0]]==[]:
#                    modified=true;
#                else:
#                    trans2[4].append(edge)
#            if trans2[4]!=[]:
#                new_state.append(trans2);
#        statelist[state]=new_state;

#New indexing of states
#new_index=[];
#count=-1;
#for i in range(len(statelist)):
#    if statelist[i]==[]:
#        new_index.append(-1);
#    else:
#        count=count+1;
#        new_index.append(count);
        
#Remove sink states
#namelist=[namelist[i] for i in range(len(statelist)) if statelist[i]!=[]];
#redcoord=[redcoord[i] for i in range(len(statelist)) if statelist[i]!=[]];
#statelist=[statelist[i] for i in range(len(statelist)) if statelist[i]!=[]];

#Update the indexing for outgoing transitions
#for i in range(len(statelist)):
#    for j in range(len(statelist[i])):
#        for k in range(len(statelist[i][j][4])):
#            statelist[i][j][4][k][0]=new_index[statelist[i][j][4][k][0]];            


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

#assign a unique identifier per transition and edge and compute inverse mapping
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
    
    
def poly_to_c_first(p):
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

def matrix_to_c(tab,name):
    n = len(tab);
    m = len(tab[0]);
    s= 'const int '+name+'[%d]' %n +'[%d] ={ '%m;
    for v in tab:
        s+= '{ ';
        v.reverse();
        for v2 in v:
            s+= '%d, ' %v2;
        s+= '}, ';
    
    return s+'};\n';
    
def poly_to_c_ter(poly):
    s0=re.sub('\{\(','{{',str(poly.dict()))
    s1=re.sub('\, *?\(','}, {',s0)
    s2=re.sub('\):' , ',' ,s1)
    s3='0'
    for i in range(cardclocks):
        s3 = s3+',0';
    if poly != 0:
        return (s2+ ',{ ' +s3+',0}' +'}');
    else :
        return ('{{ ' +s3+',0}}');
    
def poly_to_c(p):
    return (poly_to_c_ter(p));

fichier_data=open(outpath+'.data',"w");
nbpoly= -1;

def poly_to_data(p):
    #print poly_to_c_first(p);
    global nbpoly;
    nbpoly+=1;
    fichier_data.write((str(cardclocks+1)+','));
    s0=re.sub('\(','',str(p.dict()))
    s1=re.sub('\, *?\(',' , ',s0)
    s2=re.sub('\):' , ',' ,s1)
    s3=re.sub('}' , '' , s2)
    s4=re.sub('{' , '' , s3)
    fichier_data.write(s4);
    fichier_data.write('\n');
    return nbpoly;


def poly_to_c_data(p):
    n =poly_to_data(p);
    s= "{0";
    for i in range(cardclocks):
        s+=",x_%d " %(i+1);
        
    return ("customDistr.evalPoly(%i" %n) + (",%s,0.0})" %s);

def sumlist(l):
    accu=0;
    for i in range(len(l)):
        accu=accu+l[i];
    return(accu);

#numpoly=5;
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

for state in statelist:
    for trans in state['transition']:
        trans['lowerBound']=R(trans['zone'][0]-clockO(x,int(state['id']),trans['zone'][1]));
        trans['lowerBoundId']=poly_to_data( trans['lowerBound'] );
        trans['upperBound']=R(trans['zone'][2]-clockO(x,int(state['id']),trans['zone'][3]));
        trans['upperBoundId']=poly_to_data( trans['upperBound']);

def escapename(s):
    s2=s.replace('(','').replace(')','').replace('>','G').replace('<','L').replace('&','^');
    s3=s2.replace(',','_').replace('{','').replace('}','').replace('=','E').replace('-','M');
    return s3

def printGRML_distribution(alldistr):
    s="";
    maxid = len(idtransinv);
    tabidDistrHorizon = [[ -1 for k in range(len(alldistr)) ] for id in range(maxid)]
    count=0;
    for k in range(len(alldistr)):
        triple = alldistr[k];
        for state in statelist:
            i=state['id'];
            j=-1
            for trans in state['transition']:
                j= j+1;
                tabidDistrHorizon[trans['id']][k]=count;
                count+=1;
                s+='    <attribute name=\"UserDefineDistributionPoly\">\n';
                s+='      <attribute name=\"polyDataFile\"> '+outpath + '.data </attribute>\n';
                s+='      <attribute name=\"name\"> '+ "trans_%d"%i+"_%d"%j+"_%d"%k + ' </attribute>\n';
                s+='      <attribute name=\"var\"> t </attribute>\n';
                s+='      <attribute name=\"nbParam\">'+ "%i"%(cardclocks+1) + '</attribute>\n';
                s+="      <attribute name=\"lowerBound\">%i</attribute>\n" %trans['lowerBoundId'];
                s+="      <attribute name=\"upperBound\">%i</attribute>\n" %trans['upperBoundId'];
                poly_to_data(triple['psiDeltaf'][i][j]);
                s+="      <attribute name=\"norm\">%i</attribute>\n"%nbpoly;
                poly_to_data(triple['Cdf'][i][j]);
                s+="      <attribute name=\"cdf\">%i</attribute>\n"%nbpoly;
                poly_to_data(triple['Pdf'][i][j]);
                s+="      <attribute name=\"pdf\">%i</attribute>\n"%nbpoly;
                s+='    </attribute>\n'
    #fichier_data.write("//fin distr\n")
    return((s,tabidDistrHorizon));

arcCounter= -1;

def printGRML_OneArc(id,source,target):
    global arcCounter
    arcCounter+=1;
    s="";
    s+='  <arc id=\"%s' %id +'%d\"' %arcCounter +' arcType=\"arc\" source=\"%s\" ' %source + 'target=\"%s\" ' %target+'>\n';
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

def printGRML_OneTransition(id,name,distribution,priority,weight,extra):
    s="";
    s+='  <node id=\"'+ id + '\"  nodeType=\"transition\">\n';
    s+='    <attribute name=\"name\">'+ name +'</attribute>\n';
    s+='    <attribute name=\"distribution\">\n';
    s+=distribution
    s+='    </attribute>\n';
    s+='    <attribute name=\"priority\"><attribute name=\"expr\">\n';
    s+='    <attribute name=\"numValue\">'+ priority + '</attribute>\n';
    s+='    </attribute></attribute>\n';
    s+='    <attribute name=\"weight\"><attribute name=\"expr\">\n';
    s+='    '+ weight + '\n';
    s+='    </attribute></attribute>\n';
    s+='    '+extra+'\n';
    s+='  </node>\n';
    return(s);

def printGRML_OneInstaTransition(id,name,priority,weight,extra):
    s='      <attribute name=\"type\">\n';
    s+='      IMDT\n';
    s+='      </attribute>\n'
    return(printGRML_OneTransition(id,name,s,priority,weight,extra));
    
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
                    poly_to_c_data(allones[k]['psiDeltaf'][i][j]);#poids de la transition i j
                    
                t+= ', {0.0,x_1,x_2,0.0}) </attribute>\n';#C est quoi ca -> c'est pour passer les valeur d'horloge
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
                t+='        <attribute name="expr"><attribute name=\"unParsed\">'+ poly_to_c_data(trans['lowerBound']) +'</attribute></attribute>\n';
                t+='      </attribute>\n'
                t+='      <attribute name="param">\n'
                t+='        <attribute name="expr"><attribute name=\"unParsed\">'+ poly_to_c_data(trans['upperBound']) +'</attribute></attribute>\n';
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
        (s2,tab2)=printGRML_distribution(allones);#alldistr
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
