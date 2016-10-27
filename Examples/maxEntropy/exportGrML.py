import re

nbpoly= -1;
## Exporting Polynomes
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

def poly_to_data(p,fichier_data,cardclocks):
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


def poly_to_c_data(p,fichier_data,cardclocks):
    n =poly_to_data(p,fichier_data,cardclocks);
    s= "{0";
    for i in range(cardclocks):
        s+=",x_%d " %(i+1);
        
    return ("customDistr.evalPoly(%i" %n) + (",%s,0.0})" %s);
################################################################################

def escapename(s):
    s2=s.replace('(','').replace(')','').replace('>','G').replace('<','L').replace('&','^');
    s3=s2.replace(',','_').replace('{','').replace('}','').replace('=','E').replace('-','M');
    return s3

def printGRML_distribution(alldistr,idtransinv,statelist,data_path,cardclocks,fichier_data):
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
                s+='      <attribute name=\"polyDataFile\"> '+data_path + '.data </attribute>\n';
                s+='      <attribute name=\"name\"> '+ "trans_%d"%i+"_%d"%j+"_%d"%k + ' </attribute>\n';
                s+='      <attribute name=\"var\"> t </attribute>\n';
                s+='      <attribute name=\"nbParam\">'+ "%i"%(cardclocks+1) + '</attribute>\n';
                s+="      <attribute name=\"lowerBound\">%i</attribute>\n" %trans['lowerBoundId'];
                s+="      <attribute name=\"upperBound\">%i</attribute>\n" %trans['upperBoundId'];
                poly_to_data(triple['psiDeltaf'][i][j],fichier_data,cardclocks);
                s+="      <attribute name=\"norm\">%i</attribute>\n"%nbpoly;
                poly_to_data(triple['Cdf'][i][j],fichier_data,cardclocks);
                s+="      <attribute name=\"cdf\">%i</attribute>\n"%nbpoly;
                poly_to_data(triple['Pdf'][i][j],fichier_data,cardclocks);
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
    
