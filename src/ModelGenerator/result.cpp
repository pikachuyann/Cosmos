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

#include <sys/stat.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <tuple>
#include <ctime>
#include <ratio>
#include <chrono>

#include "result.hpp"
#include "HaslFormula.hpp"
#include "server.hpp"

using namespace std;

result::result():HaslResult(P.HaslFormulasname.size()) {
    //P= Q;
	gnuplotstream= NULL;
    lastprint = chrono::system_clock::now();
    lastdraw = chrono::system_clock::now();

    MeanM2 = new BatchR(P.nbAlgebraic);

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
    }
	if(P.gnuplotDriver){
		if(false && system("which gnuplot > /dev/null")!=0){
			cerr << "gnuplot not found" << endl;
			P.gnuplotDriver=false;
		}else{
			string gnuplotcmd = "(tee "+P.tmpPath + "/gnuplotscript.gp) | gnuplot";
			gnuplotstream = popen(gnuplotcmd.c_str(), "w");
			if(P.verbose>2)cout << "Gnuplot opened" << endl;
			if(gnuplotstream == NULL){
				perror("Fail to lauch gnuplot");
				exit(EXIT_FAILURE);
			}
			if(P.alligatorMode){
				fputs("set terminal png font 'arial,12' size 1000, 400\n",gnuplotstream);
				//fputs("set output 'dataout.png'\n",gnuplotstream);
			} else {
				//fputs("set terminal pngcairo font 'arial,10' size 1024, 768\n",gnuplotstream);
			}
			fputs("set grid lt 4 lc rgb '#909090'\n",gnuplotstream);
			fputs("set style fill solid 0.2 noborder\n",gnuplotstream);
			flushgnuplot();
		}
	}

    start = chrono::system_clock::now();;
    lastprint = chrono::system_clock::now();
    if(P.verbose>0)cout << endl << endl << endl;
}

result::~result(){
    delete MeanM2;
	//close_gnuplot();
}

void result::close_gnuplot(){
	if(gnuplotstream != NULL){
		fputs("exit\n", gnuplotstream);
		flushgnuplot();
		pclose(gnuplotstream);
	}
}

void result::addBatch(BatchR &batchResult){
    MeanM2->unionR(batchResult);
	RelErr = 0;
    for(size_t i =0; i<P.HaslFormulasname.size(); i++){
		HaslResult[i] = P.HaslFormulas[i]->eval(*MeanM2);
        if(P.BoundedContinuous){
            HaslResult[i].low *=  (1 - P.epsilon);
        }

        if(P.relative){
            RelErrArray[i] =  fabs((HaslResult[i].width() /  HaslResult[i].mean));
        }else RelErrArray[i] = HaslResult[i].width();//	/ max(1.0, abs(MeanM2->Mean[i]/MeanM2->Isucc));

		if(P.HaslFormulas[i]->TypeOp==HYPOTHESIS){
			if (RelErrArray[i] <1)RelErrArray[i]=0;
			// If the Hypothesis confidence interval is less than 1 then test has finished.
		}

		RelErr = max(RelErr,RelErrArray[i]);

    }
    if(outdatastream.is_open())outputData();
}

bool result::continueSim(){
	if(MeanM2->I >= P.MaxRuns)return false;
	if(!P.sequential)return true;
	if(P.Width==0)return true;

	for(auto &it : RelErrArray)if(it > P.Width)return true;

	return false;
}

void result::printPercent(double i, double j){
    const double t = 106;
    double u;
    if(j != 0){
		u = fmax(0.0,fmin(t,(t * i)/j));
    }else u=0;
    cout << "[";
    for(int k = 1; k<t;k++){
        if(k<u){cout<<"|";}
        else cout<<" ";
    };
    cout << "] "<< (int)(100*(u/t)) <<"%\t"<< endl;
}

void result::printProgress(){
	auto current = chrono::system_clock::now();
	if( chrono::duration_cast<chrono::milliseconds>(current - lastprint) < P.updatetime)
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
    cout << "Total paths: ";
	cout << setw(10) << MeanM2->I << "\t Accepted paths: ";
	cout << setw(10) << MeanM2->Isucc << "\t Wall-clock time: ";
	auto wallclock = current-start;

	auto estimated = wallclock * (1.0 / fmax(pow(RelErr,-2.0)/pow(P.Width,-2.0), (double)MeanM2->I / (double)P.MaxRuns ) - 1.0 );
	cout << chrono::duration_cast<chrono::seconds>(wallclock).count() << "s\t Remaining(approximative): " ;
	cout << chrono::duration_cast<chrono::seconds>(estimated).count()  << "s\t Trajectory per second: " ;
	cout.precision(2);
	cout << ((double)MeanM2->I)/chrono::duration_cast<chrono::seconds>(wallclock).count() << endl;
	cout.precision(12);

    endline++;

	size_t maxformulaname=11;
	for(size_t i=0; i<P.HaslFormulasname.size(); i++)
		maxformulaname = max(maxformulaname,P.HaslFormulasname[i].size());

	if(P.verbose >1){
		for(size_t i=0; i<P.HaslFormulasname.size(); i++)
			if(P.HaslFormulasname[i].find("$GRAPH$") == string::npos){
                cout << setw(maxformulaname+1)<<left << (P.HaslFormulasname[i]+":") << " |< ";
                cout << setw(17) << HaslResult[i].min << " --[ ";
                cout << setw(17) << HaslResult[i].low << " < ";
                cout << setw(17) << HaslResult[i].mean << " > ";
                cout << setw(17) << HaslResult[i].up << " ]-- ";
                cout << setw(17) << HaslResult[i].max << " >| ";
                cout << "width=";
                cout << setw(15) << HaslResult[i].width() << endl;
                endline++;
                if(!P.RareEvent && RelErrArray[i] != 0 && P.verbose >2 && P.sequential){
                    cout << setw(maxformulaname+2)<<left << "% of width:";
                    printPercent( pow(RelErrArray[i],-2.0), pow(P.Width,-2.0));
                    endline++;
                }
            }
	}
	if(P.sequential){
		cout << setw(maxformulaname+2)<<left << "% of Err: ";
		printPercent( pow(RelErr,-2.0), pow(P.Width,-2.0));
		endline++;
	}
    cout << setw(maxformulaname+2)<<left << "% of run: ";
    printPercent(MeanM2->I, P.MaxRuns);
    endline++;
}

void result::stopclock(){
    end = chrono::system_clock::now();
    cpu_time_used = chrono::duration_cast<chrono::duration<double> >(end-start).count();
}


void result::print(ostream &s){
    s.precision(15);

    //if(!P.computeStateSpace)
    {
    s << "Model path:\t" << P.PathGspn << endl;
    if(P.loopLHA>0.0){
        s << "LHA loop:\t" << P.loopLHA << " transient:\t" << P.loopTransientLHA << endl;
    } else if(!P.CSLformula.empty()){
        s << "Formula:\t" << P.CSLformula << endl;
    } else s << "LHA path:\t" << P.PathLha << endl;

    for(size_t i =0; i<P.HaslFormulasname.size(); i++){
        if(!P.alligatorMode || ( P.HaslFormulas[i]->TypeOp != PDF_PART &&  P.HaslFormulas[i]->TypeOp != CDF_PART)){
            /*if (MeanM2->IsBernoulli[i]) {
             low[i] = (0 > low[i]) ? 0.0 : low[i];
             up[i] = (1 < up[i]) ? 1.0 : up[i];
             width[i] = up[i] - low[i];
             }*/

            s << P.HaslFormulasname[i] << ":" << endl;

            s << "Estimated value:\t" << HaslResult[i].mean << endl;
            if(P.sequential){
                if(P.computeStateSpace>0){
                    s << "Confidence interval:\t[" << HaslResult[i].mean*0.999 << " , " << HaslResult[i].mean*1.0001 << "]" << endl;
                }else{
                s << "Confidence interval:\t[" << HaslResult[i].low << " , " << HaslResult[i].up << "]" << endl;
                }
                s << "Minimal and maximal value:\t[" << HaslResult[i].min << " , " << HaslResult[i].max << "]" << endl;
                s << "Width:\t" << HaslResult[i].width() << endl;
            }else{
                s << "Confidence interval:\t[" << HaslResult[i].mean-P.Width/2.0 << " , " << HaslResult[i].mean+P.Width/2.0 << "]" << endl;
                s << "Minimal and maximal value:\t[" << HaslResult[i].min << " , " << HaslResult[i].max << "]" << endl;
                s << "Width:\t" << P.Width << endl;
            }
        }
    }
    s << "Method:\t";
    if(P.computeStateSpace > 0){
        s << "Result computed numerically" << endl;
    }else if(!P.sequential){
        s << "Confidence interval computed using Chernoff-Hoeffding bound."<<endl;
    }else if(P.MaxRuns > MeanM2->I ){
        s << "Confidence interval computed sequentially using Chows-Robbin algorithm or SPRT."<<endl;
    }else
        s << "Confidence interval computed using approximation to normal low." << endl;

    s << "Confidence level:\t" << P.Level << endl;
    //s << "Relative error:\t" << RelErr << endl;
    s << "Total paths:\t" << MeanM2->I << endl;
    s << "Accepted paths:\t" << MeanM2->Isucc << endl;
    stopclock();
    s << "Batch size:\t" << P.Batch << endl;
    s << "Time for simulation:\t"<< cpu_time_used << "s" << endl;
    rusage cpu_child;
    getrusage(RUSAGE_CHILDREN, &cpu_child);
    double child_time = cpu_child.ru_utime.tv_sec + cpu_child.ru_utime.tv_usec / 1000000.0;
    child_time += cpu_child.ru_stime.tv_sec + cpu_child.ru_stime.tv_usec / 1000000.0;
    double child_memory = cpu_child.ru_maxrss;
    getrusage(RUSAGE_SELF, &cpu_child);
    child_time += cpu_child.ru_utime.tv_sec + cpu_child.ru_utime.tv_usec / 1000000.0;
    child_time += cpu_child.ru_stime.tv_sec + cpu_child.ru_stime.tv_usec / 1000000.0;
    child_memory += cpu_child.ru_maxrss;
    s << "Total CPU time:\t" << child_time << endl;
    child_memory /= 1024;
#ifdef __APPLE__
    //getrusage return the memory used in byte on darwin whereas it
    //is return in kbyte on linux.
    child_memory /= 1024;
#endif
    s << "Total Memory used:\t" << setprecision(4) << child_memory << " MB" << endl;
    s << "Number of jobs:\t" << P.Njob << endl;
    }
}

tuple<string,double> result::split_name(string s){
    size_t fb = s.find("[");
    size_t comma = s.find(",",fb);
    if (comma != string::npos) {
        return make_tuple(s.substr(0,fb),
                          stod(s.substr(comma+2,s.length()-comma-3)));
    } else {
        size_t fb = s.find("$GRAPH$");
        size_t comma = s.find("$",fb+7);
        size_t enddol = s.find("$",comma+1);
        if (enddol != string::npos) {
            return make_tuple(s.substr(0,fb),(
                                              stod(s.substr(fb+7,comma-1))+
                                              stod(s.substr(comma+1,enddol-comma-1)))/2.0);
        } else return make_tuple("EMPTY",0.0);
    }
}

void result::outputCDFPDF(string f){
	ofstream outFile(f.c_str(), ios::out | ios::trunc);
    map<string,int> namelist;
    map<double,int> valuelist;
    for(size_t i =0; i<P.HaslFormulasname.size(); i++){
        auto nv = split_name(P.HaslFormulasname[i]);
        if (get<0>(nv)!= "EMPTY") {
            if(namelist.find(get<0>(nv)) == namelist.end())
                namelist.insert(make_pair(get<0>(nv),namelist.size()));
            if(valuelist.find(get<1>(nv)) == valuelist.end())
                valuelist.insert(make_pair(get<1>(nv),valuelist.size()));
        }
    }

    outFile << "abscissa" << " ";
    for(auto itname : namelist){
        outFile << itname.first<< "_low ";
        outFile << itname.first<< "_mean ";
        outFile << itname.first<< "_up ";
    }
    nbColumnGraph = namelist.size();
    outFile << endl;

    for(auto itval: valuelist){
        outFile << itval.first;
        for(size_t i =0; i<P.HaslFormulasname.size(); i++){
            auto nv = split_name(P.HaslFormulasname[i]);
            if (itval.first == get<1>(nv)) {
                if(P.HaslFormulas[i]->TypeOp == CDF_PART
                   || P.HaslFormulas[i]->TypeOp == PDF_PART
                   || P.HaslFormulasname[i].find("$GRAPH$") != string::npos){
                    outFile << " " << HaslResult[i].low;
                    outFile << " "<< HaslResult[i].mean;
                    outFile << " " << HaslResult[i].up;
                }
            }
        }
        outFile << endl;
    }
	outFile.close();
}

void result::printGnuplot(){
	if(gnuplotstream == NULL)return;

	if(P.dataPDFCDF.compare("")!=0){
		struct stat filestatus;
		stat(P.dataPDFCDF.c_str() , &filestatus );
		if(filestatus.st_size > 0){
			if(P.verbose>2)cout << "invoke gnuplot for PDFCDF" << endl;
			if(P.alligatorMode)fputs("set output 'pdfcdfout.png'\n",gnuplotstream);
            fputs("plot for [i=1:", gnuplotstream);
            fputs(to_string(nbColumnGraph).c_str(), gnuplotstream);
            fputs("] '", gnuplotstream);
			fputs(P.dataPDFCDF.c_str(), gnuplotstream);
            fputs("' using 1:3*i-1:3*i+1 w filledcu ls 1 notitle, ",gnuplotstream);
            fputs("for [i=1:", gnuplotstream);
            fputs(to_string(nbColumnGraph).c_str(), gnuplotstream);
            fputs("] '' using 1:3*i title columnheader with lines lw 1\n", gnuplotstream);
			if(P.alligatorMode)fputs("set output\n", gnuplotstream);
			flushgnuplot();
		}
	}

	if(P.dataoutput.compare("")!=0){
		if(P.verbose>2)cout << "invoke gnuplot for data" << endl;
		if(P.alligatorMode)fputs("set output 'dataout.png'\n",gnuplotstream);
		fputs("plot '", gnuplotstream);
		fputs(P.dataoutput.c_str(), gnuplotstream);
		fputs("' using 1:5:6 w filledcu ls 1 title columnheader(4), '' using 1:5 notitle with lines lw 1 lc rgb 'black', '' using 1:6 notitle with lines lw 1 lc rgb 'black', '' using 1:3 title columnheader(3) w lines ls 2 lw 2\n", gnuplotstream);
		if(P.alligatorMode)fputs("set output\n", gnuplotstream);
		flushgnuplot();
	}

	if(P.datatrace.compare("")!=0){
		if(P.verbose>2)cout << "invoke gnuplot for trace" << endl;
		string combicmd;
		//combicmd = "cp " + P.datatrace + " " + P.tmpPath + "/tmpdatafilecombcp.dat";
		//if(P.verbose>2)cout << combicmd << endl;
		//system(combicmd.c_str());

		combicmd = P.Path + "linecombinator " + P.datatrace + " " + P.tmpPath + "/tmpdatafilecomb.dat " + to_string(MeanM2->I);
		if(P.verbose>2)cout << combicmd << endl;
		systemsigsafe(combicmd.c_str());
		cout << "system returned" << endl;
		if(P.alligatorMode)fputs("set output 'traceout.png'\n",gnuplotstream);
		fputs("plot for [i=2:", gnuplotstream);
		char buff[10];
		sprintf(buff, "%u", (unsigned int)(P.nbPlace+1));
		fputs(buff, gnuplotstream);
		fputs("] '", gnuplotstream);
		fputs(P.tmpPath.c_str(), gnuplotstream);
		fputs("/tmpdatafilecomb.dat", gnuplotstream);
		fputs("' using 1:i title  columnheader(i) with lines\n", gnuplotstream);
		if(P.alligatorMode)fputs("set output\n", gnuplotstream);
		flushgnuplot();
	}
}

void result::flushgnuplot(){
	fflush(gnuplotstream);
}

/*	if(0!=ferror(gnuplotstream)){
 int statgnu = fflush(gnuplotstream);
 return;
 }
 cerr << "Gnuplot crashes " << endl;
 gnuplotstream = NULL;
 }*/

void result::outputData(){
    outdatastream << MeanM2->I << " "<< MeanM2-> Isucc;
    for(size_t i =0; i<P.HaslFormulasname.size(); i++){
        outdatastream << " "<< HaslResult[i].mean
		<< " "<< HaslResult[i].width()
		<< " " << HaslResult[i].low << " " << HaslResult[i].up;
    }
    outdatastream << endl;
	outdatastream.flush();
	if(P.gnuplotDriver && MeanM2->I > P.Batch){
        auto current = chrono::system_clock::now();

		if( chrono::duration_cast<chrono::duration<double>>(current-lastdraw) < P.updatetime)
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
