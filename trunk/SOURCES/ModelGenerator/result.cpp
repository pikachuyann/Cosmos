/*******************************************************************************
 *									                                           *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *			                                    						       *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini Benoît Barbot & Hilal Djafri                       *
 * Website: http://www.lsv.ens-cachan.fr/Software/cosmos                       *
 *                                                                             *
 * This program is free software; you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation; either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License along     *
 * with this program; if not, write to the Free Software Foundation, Inc.,     *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                 *
 * file result.cpp created by Benoit Barbot on 22/05/12.                       *
 *******************************************************************************
 */

#include <iostream>
#include "result.hpp"


#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
boost::math::normal norma;

using namespace std;

result::result(parameters &Q){
    P= Q;
   
    MeanM2 = new BatchR(P.HaslFormulas.size());
    
    CurrentWidth = 1;
    RelErr = 0;
    
    Var = vector<double>(P.HaslFormulas.size()); //variance
    stdev = vector<double>(P.HaslFormulas.size()); //standard deviation
    width = vector<double>(P.HaslFormulas.size()); //Confidence interval width
    
    Normal_quantile = quantile(norma, 0.5 + P.Level / 2.0);
    
    low = vector<double>(P.HaslFormulas.size()); //confidence interval lowerbound
    up = vector<double>(P.HaslFormulas.size()); //confidence interval upperbound
    
	RelErrArray = vector<double>(P.HaslFormulas.size()); //relative error
	
    endline = 0;
    
    if(P.dataoutput.compare("")){
        cout << "Output Data to: " << P.dataoutput << endl;
        outdatastream.open(P.dataoutput.c_str(),fstream::out);
        outdatastream.precision(15);
        outdatastream << "#Number of trajectory, Number of successfull trajectory ";
        for(int i =0; i<P.HaslFormulas.size(); i++){
			string iname = P.HaslFormulas[i];
			if(!iname.compare("")){
				outdatastream << ", Mean["<<i<<"], Second Moment["<<i<<"], Confidence interval lower bound [" << i <<"] ,Confidence interval upper bound ["<<i<<"]";
			}else{
            outdatastream << ", Mean["<<iname<<"], Second Moment["<<iname<<"], Confidence interval lower bound ["<<iname<<"] ,Confidence interval upper bound ["<<iname<<"]";
			}
        }
        outdatastream << endl;
    }
    
    time(&start);
    cout << endl << endl << endl;
}

result::~result(){
    delete MeanM2;
}

void result::addBatch(BatchR *batchResult){
    
    ////////////////////////////////////////////////////////////////////////////
    // Some remarks about the estimation of the confidence interval adopted here
    // Let l=ConfLevel, the confidence level
    // l=1-alpha
    // Let w=ConfWidth, the size of the confidence interval
    
    // Let mu the value to estimate, and x the estimation of mu
    // then Prob(x-w/2 <= mu <= x+w/2) = 1-alpha
    
    // The confidence interval is given by :
    // [x-z(1-alpha/2) * StandardDeviation / sqrt(NumberOfObservations) ,  
    //          x+z(1-alpha/2) * StandardDeviation / sqrt(NumberOfObservations)]
    
    // z(1-alpha/2)=z(1-(1-l)/2) = z(0.5+l/2)
    ////////////////////////////////////////////////////////////////////////////
    
    MeanM2->unionR(batchResult);
     
    // The factor (Isucc/Isucc-1) ensuire that var is an unbiased estimator of
    // the true variance
    double corrvar = MeanM2->Isucc/(MeanM2->Isucc-1);
    
    double Ksucc_sqrt= sqrt(MeanM2->Isucc);
    RelErr = 0;
    for(int i =0; i<P.HaslFormulas.size(); i++){
        //cout<< "vari:" << i<< endl;
        Var[i] = corrvar * (MeanM2->M2[i] - pow(MeanM2->Mean[i], 2));
        stdev[i] = sqrt(Var[i]);
        width[i] = 2 * Normal_quantile * stdev[i] / Ksucc_sqrt;
        
        low[i] = MeanM2->Mean[i] - width[i] / 2.0;
        up[i] = MeanM2->Mean[i] + width[i] / 2.0;
        
        if(P.BoundedContinuous){
            low[i] = low[i] * (1 - P.epsilon);
            width[i] = up[i] - low[i];
        }
        
        if(P.RareEvent || P.BoundedRE>0){
            RelErrArray[i] =  width[i] /  abs(MeanM2->Mean[i]);
        }else RelErrArray[i] = width[i] / max(1.0, abs(MeanM2->Mean[i]));
		
		RelErr = max(RelErr,RelErrArray[i]);
        
    }
    if(outdatastream.is_open())outputData();
   
}

bool result::continueSim(){
    return (RelErr > P.Width) && (MeanM2->I < P.MaxRuns);
}

void printPercent(double i, double j){
    double t = 100;
    double u;
    if(j != 0){
       u = (t * i)/j;      
    }else u=0;
    cout << "[";
    for(int k = 1; k<t;k++){
        if(k<u){cout<<"|";}
        else cout<<" ";
    };
    cout << "]\t"<< endl;
	//(long unsigned int)i << "/" << (long unsigned int)j << endl;
}

void result::printProgress(){
    cout.precision(15);
    //cout<<"\033[A\033[2K"<< "\033[A\033[2K"<< "\033[A\033[2K" ;
    while(endline>=0){
        endline--;
        cout << "\033[A\033[2K";
    }
    cout << "Total paths: " << MeanM2->I << "\t accepted paths: " << MeanM2->Isucc << endl;
    endline++;
    for(int i=0; i<P.HaslFormulas.size(); i++){
        cout << P.HaslFormulas[i] << ":\t Mean" << "=" << MeanM2->Mean[i] << "\t stdev=" << stdev[i] << "\t  width=" << width[i] << endl;
        endline++;
        if(!P.RareEvent && RelErrArray[i] != 0 && P.verbose >1){
			cout << "% of width:\t";
			printPercent( pow(RelErrArray[i],-2.0), pow(P.Width,-2.0));
			endline++;
        }
    }
	cout << "% of rel Err:\t";
	printPercent( pow(RelErr,-2.0), pow(P.Width,-2.0));
	endline++;
    cout << "% of run:\t";
    printPercent(MeanM2->Isucc, P.MaxRuns);
    endline++;
}

void result::stopclock(){
    time(&end);
    cpu_time_used = difftime(end, start);
}

double binomlow(int i,int j , double l){
    return boost::math::binomial_distribution<>::find_lower_bound_on_p(i,j,l);
}

double binomup(int i,int j , double l){
    return boost::math::binomial_distribution<>::find_upper_bound_on_p(i,j,l);
}

void result::print(ostream &s){
    s.precision(15);
    
    if(!P.computeStateSpace){
        
        for(int i =0; i<P.HaslFormulas.size(); i++){
            if (MeanM2->IsBernoulli[i]) {
                low[i] = (0 > low[i]) ? 0.0 : low[i];
                up[i] = (1 < up[i]) ? 1.0 : up[i];
                width[i] = up[i] - low[i];
            }
            
            s << P.HaslFormulas[i] << ":" << endl;
            
            if(P.RareEvent){
                s << "Rare Event Result" << endl;
                double mean = (double)MeanM2->Isucc / (double)MeanM2->I;
                mean *= MeanM2->Mean[i];
                s << "Mean:  " << mean << endl;
                double l = binomlow(MeanM2->I, MeanM2->Isucc, (1-P.Level)/2);
                double u = binomup(MeanM2->I, MeanM2->Isucc, (1-P.Level)/2);
                // Print Clopper Pearson Limits:
                s << "Binomiale Confidence Interval: [" << l*MeanM2->Mean[i] << " , " << u*MeanM2->Mean[i] << "]"<< endl;
                s << "Binomiale Width: "<< (u-l)*MeanM2->Mean[i] << endl <<endl;
            } else {
                s << "Estimated value:\t" << MeanM2->Mean[i] << endl;
                s << "Confidence interval:\t[" << low[i] << " , " << up[i] << "]" << endl;
                
                if(MeanM2->IsBernoulli[i]){
                    s << "The distribution look like a binomial!" << endl;
                    using namespace boost::math;
                    double successes = MeanM2->Isucc * MeanM2->Mean[i];
                    double l = binomlow(MeanM2->Isucc, successes, (1-P.Level)/2);
                    double u = binomup(MeanM2->Isucc, successes, (1-P.Level)/2);
                    // Print Clopper Pearson Limits:
                    s << "Binomiale Confidence Interval:\t[" << l << " , " << u << "]"<< endl;
                    s << "Binomiale Width:\t"<< u-l << endl;
                    
                }
                s << "Standard deviation:\t" << stdev[i] << endl;
                s << "Width:\t" << width[i] << endl;
            }
        }
        s << "Relative Error:\t" << RelErr << endl;
        s << "Total paths:\t" << MeanM2->I << endl;
        s << "Accepted paths:\t" << MeanM2->Isucc << endl;
        s << "Time for simulation:\t"<< cpu_time_used << "s" << endl;
        
    }
}

void result::outputData(){
    outdatastream << MeanM2->I << " "<< MeanM2-> Isucc;
    for(int i =0; i<P.HaslFormulas.size(); i++){
        outdatastream << " "<<MeanM2->Mean[i] << " "<< MeanM2->M2[i] << " " << low[i] << " " << up[i]; 
    }
    outdatastream << endl;
}

void result::printResultFile(string f){
    ofstream ResultsFile(f.c_str(), ios::out | ios::trunc);
    
    if (!ResultsFile) cout << "File '" << f << "' not Created" << endl;
    else {
        print(ResultsFile);
        cout << "Results are saved in '" << f << "'" << endl;
        ResultsFile.close();
    }
}

void result::printAlligator(){
    cout << "alligatorResult" << endl;
    for (int i=0; i<P.HaslFormulas.size(); i++){
        cout << MeanM2->Mean[i] << endl;
        cout << "[" << low[i] << "," << up[i] << "]" << endl;
        cout << stdev[i] << endl;
        cout << width[i] << endl;
    }
    cout << MeanM2->I << endl;
    cout << MeanM2->Isucc << endl;
    //cout << cpu_time_used << endl;
}