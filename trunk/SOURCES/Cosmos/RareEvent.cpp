#include <set>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include "RareEvent.hpp"

#include <cmath>

double mu(TAB &gammaprob, SPN &N){
 
  vector<int> vect (N.Msimpletab.size());
  for(int i=0; i< N.Msimpletab.size();i++){
    vect[i] = N.Marking[N.Msimpletab[i]];
    //cout << i << " : " << N.Msimpletab[i] << " : " << N.Marking[N.Msimpletab[i]] << endl;
  };
  
  return(gammaprob.find(&vect));
}


double ComputeDistr(SPN &N, int t , double origin_rate){

  double mux = mu(N.gammaprob,N);
  if( mux==0.0 || mux==1.0) return(origin_rate);
    
  if(t== N.tr-1){
    if(N.Origine_Rate_Sum >= N.Rate_Sum){
      return( (N.Origine_Rate_Sum - N.Rate_Sum)  );
    }else{ 
      return 0.0 ;};
  }; 

  double distr;
  N.fire(t);
  distr = origin_rate *( mu(N.gammaprob,N) / mux);
  N.unfire(t);
  return(distr);
}
