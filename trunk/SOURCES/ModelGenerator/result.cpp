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
#include "HaslFormula.hpp"

#include <boost/math/distributions/binomial.hpp>

using namespace std;

result::result(parameters &Q){
    P= Q;
   
    MeanM2 = new BatchR(P.nbAlgebraic);
	for(int i =0; i<P.HaslFormulasname.size(); i++){
		HaslResult.push_back(new ConfInt());
	}
	
    RelErr = 0;
	RelErrArray = vector<double>(P.HaslFormulasname.size()); //relative error
	
    endline = 0;
    
    if(P.dataoutput.compare("")){
        cout << "Output Data to: " << P.dataoutput << endl;
        outdatastream.open(P.dataoutput.c_str(),fstream::out);
        outdatastream.precision(15);
        outdatastream << "#Number of trajectory, Number of successfull trajectory ";
        for(int i =0; i<P.HaslFormulasname.size(); i++){
			string iname = P.HaslFormulasname[i];
			if(!iname.compare("")){
				outdatastream << ", Mean["<<i<<"], Second Moment["<<i<<"], Confidence interval lower bound [" << i <<"] ,Confidence interval upper bound ["<<i<<"]";
			}else{
            outdatastream << ", Mean["<<iname<<"], Second Moment["<<iname<<"], Confidence interval lower bound ["<<iname<<"] ,Confidence interval upper bound ["<<iname<<"]";
			}
        }
        outdatastream << endl;
    }
    
    time(&start);
    if(P.verbose>0)cout << endl << endl << endl;
}

result::~result(){
    delete MeanM2;
}

void result::addBatch(BatchR *batchResult){
    MeanM2->unionR(batchResult);
	RelErr = 0;
    for(int i =0; i<P.HaslFormulasname.size(); i++){
		delete HaslResult[i];
		HaslResult[i] = P.HaslFormulas[i].eval(*MeanM2);
        if(P.BoundedContinuous){
            HaslResult[i]->low *=  (1 - P.epsilon);
        }
		
        if(P.RareEvent || P.BoundedRE>0){
            RelErrArray[i] =  HaslResult[i]->width() /  abs(MeanM2->Mean[i]/MeanM2->Isucc);
        }else RelErrArray[i] = HaslResult[i]->width();//	/ max(1.0, abs(MeanM2->Mean[i]/MeanM2->Isucc));
		
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
}

void result::printProgress(){
    cout.precision(15);
    while(endline>=0){
        endline--;
        cout << "\033[A\033[2K";
    }
    cout << "Total paths: " << MeanM2->I << "\t accepted paths: ";
	cout << MeanM2->Isucc << endl;
    endline++;
	if(P.verbose >1){
		for(int i=0; i<P.HaslFormulasname.size(); i++){
			
			cout<< P.HaslFormulasname[i] << ":\t Mean" << "="
			<< HaslResult[i]->mean;
			cout << "\t  width=" << HaslResult[i]->width() << endl;
			endline++;
			if(!P.RareEvent && RelErrArray[i] != 0 && P.verbose >2){
				cout << "% of width:\t";
				printPercent( pow(RelErrArray[i],-2.0), pow(P.Width,-2.0));
				endline++;
			}
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
        
        for(int i =0; i<P.HaslFormulasname.size(); i++){
            /*if (MeanM2->IsBernoulli[i]) {
                low[i] = (0 > low[i]) ? 0.0 : low[i];
                up[i] = (1 < up[i]) ? 1.0 : up[i];
                width[i] = up[i] - low[i];
            }*/
            
            s << P.HaslFormulasname[i] << ":" << endl;
            
            if(P.RareEvent){
                s << "Rare Event Result" << endl;
                double mean = 1.0 / (double)MeanM2->I;
                mean *= MeanM2->Mean[i];
                s << "Estimated value:\t" << mean << endl;
                double l = binomlow(MeanM2->I, MeanM2->Isucc, (1-P.Level)/2);
                double u = binomup(MeanM2->I, MeanM2->Isucc, (1-P.Level)/2);
                // Print Clopper Pearson Limits:
                s << "Binomiale confidence interval:\t[" <<
					l*MeanM2->Mean[i]/MeanM2->Isucc << " , " <<
					u*MeanM2->Mean[i]/MeanM2->Isucc << "]"<< endl;
                s << "Binomiale width:\t"<< (u-l)*MeanM2->Mean[i]/MeanM2->Isucc
					<< endl <<endl;
            } else {
                s << "Estimated value:\t" << HaslResult[i]->mean << endl;
                s << "Confidence interval:\t[" << HaslResult[i]->low << " , " << HaslResult[i]->up << "]" << endl;
                s << "Width:\t" << HaslResult[i]->width() << endl;
            }
        }
		s << "Confidence level:\t" << P.Level << endl;
        s << "Relative error:\t" << RelErr << endl;
        s << "Total paths:\t" << MeanM2->I << endl;
        s << "Accepted paths:\t" << MeanM2->Isucc << endl;
        s << "Time for simulation:\t"<< cpu_time_used << "s" << endl;
        
    }
}

void result::outputData(){
    outdatastream << MeanM2->I << " "<< MeanM2-> Isucc;
    for(int i =0; i<P.HaslFormulasname.size(); i++){
        outdatastream << " "<< HaslResult[i]->mean
		<< " "<< HaslResult[i]->width()
		<< " " << HaslResult[i]->low << " " << HaslResult[i]->up;
    }
    outdatastream << endl;
}

void result::printResultFile(string f){
    ofstream ResultsFile(f.c_str(), ios::out | ios::trunc);
    
    if (!ResultsFile) cout << "File '" << f << "' not Created" << endl;
    else {
        print(ResultsFile);
        if(P.verbose>0)cout << "Results are saved in '" << f << "'" << endl;
        ResultsFile.close();
    }
}

void result::printAlligator(){
	print(cout);
	
    /*cout << "alligatorResult" << endl;
    for (int i=0; i<P.HaslFormulas.size(); i++){
        cout << MeanM2->Mean[i] << endl;
        cout << "[" << low[i] << "," << up[i] << "]" << endl;
        cout << stdev[i] << endl;
        cout << width[i] << endl;
    }
    cout << MeanM2->I << endl;
    cout << MeanM2->Isucc << endl;*/
    //cout << cpu_time_used << endl;
}