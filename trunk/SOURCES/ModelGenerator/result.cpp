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
#include <cstdlib>
#include "result.hpp"
#include "HaslFormula.hpp"
#include <iomanip>
#include <math.h>

using namespace std;

result::result(parameters &Q){
    P= Q;
	gnuplotstream= NULL;
	gettimeofday(&lastprint,NULL);
	gettimeofday(&lastdraw,NULL);
   
    MeanM2 = new BatchR(P.nbAlgebraic);
	for(size_t i =0; i<P.HaslFormulasname.size(); i++){
		HaslResult.push_back(new ConfInt());
	}
	
    RelErr = 0;
	RelErrArray = vector<double>(P.HaslFormulasname.size()); //relative error
	
    endline = 0;
    
    if(P.dataoutput.compare("")){
        if(P.verbose>0)cout << "Output Data to: " << P.dataoutput << endl;
        outdatastream.open(P.dataoutput.c_str(),fstream::out);
        outdatastream.precision(15);
        outdatastream << "\"Number of trajectory\" \"Number of successfull trajectory\"";
        for(size_t i =0; i<P.HaslFormulasname.size(); i++){
			string iname = P.HaslFormulasname[i];
			if(!iname.compare("")){
				outdatastream << " \"Mean["<<i<<"]\" \"Confidence interval Width["<<i<<"]\" \"Confidence interval lower bound [" << i <<"]\" \"Confidence interval upper bound ["<<i<<"]\"";
			}else{
            outdatastream << " \"Mean["<<iname<<"]\" \"Confidence interval Width["<<iname<<"]\" \"Confidence interval lower bound ["<<iname<<"]\" \"Confidence interval upper bound ["<<iname<<"]\"";
			}
        }
        outdatastream << endl;
		
		if(P.gnuplotDriver){
			gnuplotstream = popen("gnuplot > /dev/null", "w");
			if(gnuplotstream<=0){
				perror("Fail to lauch gnuplot");
				exit(EXIT_FAILURE);
			}
			if(P.alligatorMode){
				fputs("set terminal pngcairo font 'arial,10' size 500, 200\n",gnuplotstream);
				//fputs("set output 'dataout.png'\n",gnuplotstream);
			}
			fputs("set grid lc rgb 'black'\n",gnuplotstream);
			fputs("set style fill solid 0.2 noborder\n",gnuplotstream);
			fflush(gnuplotstream);
			
		}
    }
    
	gettimeofday(&start, NULL);
	gettimeofday(&lastprint, NULL);
    if(P.verbose>0)cout << endl << endl << endl;
}

result::~result(){
    delete MeanM2;
	close_gnuplot();
}

void result::close_gnuplot(){
	if(gnuplotstream>0){
		fputs("exit\n", gnuplotstream);
		fflush(gnuplotstream);
		pclose(gnuplotstream);
	}
}

void result::addBatch(BatchR *batchResult){
    MeanM2->unionR(batchResult);
	RelErr = 0;
    for(size_t i =0; i<P.HaslFormulasname.size(); i++){
		delete HaslResult[i];
		HaslResult[i] = P.HaslFormulas[i]->eval(*MeanM2);
        if(P.BoundedContinuous){
            HaslResult[i]->low *=  (1 - P.epsilon);
        }
		
        if(P.RareEvent || P.BoundedRE>0){
            RelErrArray[i] =  HaslResult[i]->width() /  fabs(MeanM2->Mean[i]/MeanM2->Isucc);
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
	timeval current;
	gettimeofday(&current,NULL);
	if((current.tv_sec-lastprint.tv_sec +
		(current.tv_usec-lastprint.tv_usec)/1000000.0) < P.updatetime)
			return;
	lastprint = current;
	if(P.alligatorMode){
		printAlligator();
		return;
	}
    while(endline>=0){
        endline--;
        cout << "\033[A\033[2K";
    }
	cout.precision(15);
    cout << "Total paths: ";
	cout << setw(15) << MeanM2->I << "\t accepted paths: ";
	cout << setw(15) << MeanM2->Isucc << endl;
    endline++;
	
	size_t maxformulaname=0;
	for(size_t i=0; i<P.HaslFormulasname.size(); i++)
		maxformulaname = max(maxformulaname,P.HaslFormulasname[i].size());
	
	if(P.verbose >1){
		for(size_t i=0; i<P.HaslFormulasname.size(); i++){
			
			cout << setw(maxformulaname+1)<<left << (P.HaslFormulasname[i]+":") << " Mean=";
			cout << setw(15) << HaslResult[i]->mean;
			cout << "\t  width=";
			cout << setw(15) << HaslResult[i]->width() << endl;
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
    printPercent(MeanM2->I, P.MaxRuns);
    endline++;
}

void result::stopclock(){
    gettimeofday(&end,NULL);
    cpu_time_used = end.tv_sec-start.tv_sec +(end.tv_usec-start.tv_usec)/1000000.0;
}


void result::print(ostream &s){
    s.precision(15);
    
    if(!P.computeStateSpace){
        
        for(size_t i =0; i<P.HaslFormulasname.size(); i++){
            /*if (MeanM2->IsBernoulli[i]) {
                low[i] = (0 > low[i]) ? 0.0 : low[i];
                up[i] = (1 < up[i]) ? 1.0 : up[i];
                width[i] = up[i] - low[i];
            }*/
            
            s << P.HaslFormulasname[i] << ":" << endl;
            
			s << "Estimated value:\t" << HaslResult[i]->mean << endl;
			s << "Confidence interval:\t[" << HaslResult[i]->low << " , " << HaslResult[i]->up << "]" << endl;
			s << "Width:\t" << HaslResult[i]->width() << endl;
        }
		s << "Confidence level:\t" << P.Level << endl;
        s << "Relative error:\t" << RelErr << endl;
        s << "Total paths:\t" << MeanM2->I << endl;
        s << "Accepted paths:\t" << MeanM2->Isucc << endl;
        s << "Time for simulation:\t"<< cpu_time_used << "s" << endl;
		rusage cpu_child;
		getrusage(RUSAGE_CHILDREN, &cpu_child);
		double child_time = cpu_child.ru_utime.tv_sec + cpu_child.ru_utime.tv_usec / 1000000.0;
		child_time += cpu_child.ru_stime.tv_sec + cpu_child.ru_stime.tv_usec / 1000000.0;
		getrusage(RUSAGE_SELF, &cpu_child);
		child_time += cpu_child.ru_utime.tv_sec + cpu_child.ru_utime.tv_usec / 1000000.0;
		child_time += cpu_child.ru_stime.tv_sec + cpu_child.ru_stime.tv_usec / 1000000.0;
		s << "Total CPU time:\t" << child_time << endl;
        
    }
}

void result::outputCDFPDF(string f){
	ofstream outFile(f.c_str(), ios::out | ios::trunc);
	for(size_t i =0; i<P.HaslFormulasname.size(); i++){
		if(P.HaslFormulas[i]->TypeOp == CDF_PART
		   || P.HaslFormulas[i]->TypeOp == PDF_PART){
			size_t fb = P.HaslFormulasname[i].find("[");
			size_t comma = P.HaslFormulasname[i].find(",",fb);
			outFile << P.HaslFormulasname[i].substr(comma+2,
						P.HaslFormulasname[i].length() -comma-3 ) << " ";
			outFile << HaslResult[i]->low << " "<< HaslResult[i]->mean;
			outFile << " " << HaslResult[i]->up << endl;
		}
	}
	outFile.close();
}

void result::printGnuplot(){
	if(gnuplotstream<=0)return;
	if(P.verbose>2)cout << "invoke gnuplot" << endl;
	if(P.alligatorMode)fputs("set output 'dataout.png'\n",gnuplotstream);
	fputs("plot '", gnuplotstream);
	fputs(P.dataoutput.c_str(), gnuplotstream);
	fputs("' using 1:5:6 w filledcu ls 1 title columnheader(4), '' using 1:5 notitle with lines lw 1 lc rgb 'black', '' using 1:6 notitle with lines lw 1 lc rgb 'black', '' using 1:3 title columnheader(3) w lines ls 1 lw 2\n", gnuplotstream);
	if(P.alligatorMode)fputs("set output\n", gnuplotstream);
	fflush(gnuplotstream);
}

void result::outputData(){
    outdatastream << MeanM2->I << " "<< MeanM2-> Isucc;
    for(size_t i =0; i<P.HaslFormulasname.size(); i++){
        outdatastream << " "<< HaslResult[i]->mean
		<< " "<< HaslResult[i]->width()
		<< " " << HaslResult[i]->low << " " << HaslResult[i]->up;
    }
    outdatastream << endl;
	outdatastream.flush();
	if(P.gnuplotDriver && MeanM2->I > P.Batch){
		timeval current;
		gettimeofday(&current,NULL);
		if((current.tv_sec-lastdraw.tv_sec +
			(current.tv_usec-lastdraw.tv_usec)/1000000.0) < P.updatetime)
			return;
		lastdraw = current;
		printGnuplot();
	}
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
}