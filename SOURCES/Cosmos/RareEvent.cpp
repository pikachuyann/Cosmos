#include <set>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <hash_map>
#include "RareEvent.hpp"
#include "tab.hpp"

#include <cmath>


const int n = 5;
const bool ImportanceSampling = true;
const int l1 = 7;
const int l2 = 8;
const double p = 0.300000;
const double q = 0.700000;

double mu(TAB &gammaprob, vector<int>& Mark){
 
  vector<int> vect ((2*n+1)*(l1+l2) - (2*n)*(l1+l2));
  for(int j= (2*n)*(l1+l2) ; j< (2*n+1)*(l1+l2) ; j++){
    vect[j-(2*n)*(l1+l2)] = Mark[j];
   }
  return(gammaprob.find(&vect));

}


double ComputeDistr(SPN &N, int t , double origin_rate){
 
  double mux = mu(N.gammaprob,N.Marking);
  if( mux==0.0 || mux==1.0) return(origin_rate);
    
  if(t== N.tr-1){
    if(N.Origine_Rate_Sum >= N.Rate_Sum){
      return( (N.Origine_Rate_Sum - N.Rate_Sum)  );
    }else{ 
      return 0.0 ;};
  };

  double distr;
  N.fire(t);
  distr = origin_rate *( mu(N.gammaprob,N.Marking) / mux);
  N.unfire(t);
  return(distr);
}
