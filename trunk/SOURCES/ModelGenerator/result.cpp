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
    K = 0;
    Ksucc = 0; //counter of succesfull generated paths
    Ksucc_sqrt =0 ; //square root of Ksucc
    
    CurrentWidth = 1;
    RelErr = 1;
    
    Mean = 0;
    Var = 0; //variance
    stdev = 0; //standard deviation
    M2 = 0;
    Normal_quantile = quantile(norma, 0.5 + P.Level / 2.0);
    
    low=0;
    up=0;
    IsBernoulli = true;
    Dif=0;
    
    time(&start);
    cout << endl << endl << endl;
}

result::~result(){
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
    
    IsBernoulli = IsBernoulli && batchResult->IsBernoulli;
    
    K = K + batchResult->I;
    Ksucc = Ksucc + batchResult->Isucc;
    
    Dif = batchResult->Mean - Mean;
    Mean = Mean + batchResult->Isucc * Dif / Ksucc;
    
    Dif = batchResult->M2 - M2;
    M2 = M2 + batchResult->Isucc * Dif / Ksucc;
    
    Var = M2 - pow(Mean, 2);
    
    
    stdev = sqrt(Var);
    Ksucc_sqrt = sqrt(Ksucc);
    CurrentWidth = 2 * Normal_quantile * stdev / Ksucc_sqrt;
    
    low = Mean - CurrentWidth / 2.0;
    up = Mean + CurrentWidth / 2.0;
    
    if(P.BoundedContinuous){
        low = low * (1 - P.epsilon);
        CurrentWidth = up - low;
    }
    
    if(P.RareEvent || P.BoundedRE>0){
        RelErr = CurrentWidth /  abs(Mean);
    }else RelErr = CurrentWidth / max(1.0, abs(Mean));
}

bool result::continueSim(){
    return (RelErr > P.Width) && (K < P.MaxRuns);
}

void printPercent(int i, int j){
    int t = 100;
    int u = (t * i)/j; 
    cout << "[";
    for(int k = 1;k<u;k++)cout<<"|";
    for(int k = u;k<t;k++)cout<<" ";
    cout << "]"<< endl;
}

void result::printProgress(){
    cout << "\033[A\033[2K"<< "\033[A\033[2K" << "\033[A\033[2K";
    cout << "Total paths: " << K << "\t accepted paths: " << Ksucc << "\t Mean" << "=" << Mean << "\t stdev=" << stdev << "\t  width=" << CurrentWidth << endl;
    cout << "% of run:\t";
    printPercent(Ksucc, P.MaxRuns);
    cout << "% of width:\t";
    printPercent(1000*pow(-log(CurrentWidth),0.5), 1000*pow(-log(P.Width),0.5));
}

void result::stopclock(){
    time(&end);
    cpu_time_used = difftime(end, start);
}

void result::printResult(){
    if (IsBernoulli) {
        low = (0 > low) ? 0.0 : low;
        up = (1 < up) ? 1.0 : up;
        CurrentWidth = up - low;
        
    }
    
    cout << "Estimated value: " << Mean << endl;
    cout << "Confidence interval: [" << low << "," << up << "]" << endl;
    if(IsBernoulli){
        cout << "The distribution look like a binomial!" << endl;
        using namespace boost::math;
        double successes = Ksucc * Mean;
        double l = binomial_distribution<>::find_lower_bound_on_p(
            Ksucc, successes, (1-P.Level)/2);
        double u = binomial_distribution<>::find_upper_bound_on_p(
            Ksucc, successes, (1-P.Level)/2);
        // Print Clopper Pearson Limits:
        cout << "Binomiale Confidence Interval: [" << l << "," << u << "]"<< endl;
        cout << "Binomiale Width: "<< u-l << endl;
        
    }
    cout << "Standard deviation: " << stdev << "\tWidth: " << CurrentWidth << endl;
    cout << "Total paths: " << K << "\tAccepted paths: " << Ksucc << endl;
    cout << "Time for simulation:"<< cpu_time_used << "s" << endl;
}

void result::printResultFile(string f){
    ofstream ResultsFile(f.c_str(), ios::out | ios::trunc);
    
    if (!ResultsFile) cout << "File '" << f << "' not Created" << endl;
    else {
        
        ResultsFile << "Estimated value: " << Mean << endl;
        ResultsFile << "Confidence interval: [" << low << "," << up << "]" << endl;
        if(IsBernoulli){
            ResultsFile << "The distribution look like a binomial!" << endl;
            using namespace boost::math;
            double successes = Ksucc * Mean;
            double l = binomial_distribution<>::find_lower_bound_on_p(
                                                                      Ksucc, successes, (1-P.Level)/2);
            double u = binomial_distribution<>::find_upper_bound_on_p(
                                                                      Ksucc, successes, (1-P.Level)/2);
            // Print Clopper Pearson Limits:
            ResultsFile << "Binomiale Confidence Interval: [" << l << "," << u << "]"<< endl;
            ResultsFile << "Binomiale Width: "<< u-l << endl;
            
        }
        ResultsFile << "Standard deviation: " << stdev << "\tWidth: " << CurrentWidth << endl;
        ResultsFile << "Total paths: " << K << "\tAccepted paths: " << Ksucc << endl;
        ResultsFile << "Time for simulation:"<< cpu_time_used << "s" << endl;
        
        cout << "Results are saved in '" << f << "'" << endl;
        ResultsFile.close();
        
        
    }

}

void result::printAlligator(){
    cout << "alligatorResult" << endl;
    cout << Mean << endl;
    cout << "[" << low << "," << up << "]" << endl;
    cout << stdev << endl;
    cout << CurrentWidth << endl;
    cout << K << endl;
    cout << Ksucc << endl;
    //cout << cpu_time_used << endl;
}