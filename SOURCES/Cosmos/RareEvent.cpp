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
const double fork1 = 1.000000;
const double fork2 = 100.000000;
const double eat   = 10.000000;

double mu(TAB &gammaprob, int nthink,int nwait,int nserv){
  char pos[64];
  hash_prob::iterator it;
  int neat = n-nthink-nwait ;
  /*for (it = gammaprob.M.begin(); it != gammaprob.M.end(); it++)
    cout << * new string (it->first) << " " << it->second << endl ;*/
  snprintf(pos, 64, "(%i,%i,%i,%i,%i)", nthink,nwait,neat,nserv, n-nwait-2*neat);
  /*cout << pos << ":" << gammaprob.M[pos]
       << "-" << strlen (pos)
       << endl;*/

  return(gammaprob.M[pos]);
}

double ComputeDistr(vector<int>& Mark , int i , TAB &gammaprob, double distrorigin, double tprob2){

  if(!ImportanceSampling){
    return distrorigin;
  };


  int nthink = Mark[4*n];
  int nwait  = Mark[4*n+1];
  int nserv  = Mark[4*n+2];
  
  
  double distr;
  double mux = mu(gammaprob,nthink , nwait ,nserv);
  
  
   
 

  //cout << "i: " << i << endl;
  if(i==3*n){

    double tprob = 0.0;
    double tgamma = 0.0;

    for(int j=0;j<=n-1;j++){
      tprob += ( fork1  * Mark[4*j]*Mark[4*j+3]
		 +fork2 * Mark[4*j+1]*Mark[4*((j+n-1)%n)+3]
		 + eat  * Mark[4*j+2]);
    };

    /*if(tprob != tprob2 && mux >0){
      cout << "tprob :" << tprob << " tprob2 :" << tprob2 << endl;
      };*/

    for(int j=0;j<=n-1;j++){
      
      if(Mark[4*j]*Mark[4*j+3]>0){
	tgamma += (fork1/tprob)*mu(gammaprob,nthink-1 , nwait+1 ,nserv);
      }
      
      if(Mark[4*j+1]*Mark[4*((j+n-1)%n)+3]>0){
	tgamma += (fork2/tprob)*mu(gammaprob,nthink , nwait-1 ,nserv);
      }
      
      if(Mark[4*j+2]>0){
	tgamma += (eat/tprob) * mu(gammaprob,nthink+1 , nwait ,nserv+1);
      }
    }


    //cout << "rapport sum / mu: " << (tgamma / gammaprob.M[nthink][nwait  ][nserv])<< endl;
    if( mux >= tgamma){
      //cout << " mu >= sum: rate: " << (gammaprob.M[nthink][nwait  ][nserv] - tgamma) /  gammaprob.M[nthink  ][nwait  ][nserv] << endl;
      return( tprob * (mux - tgamma) / mux  );
    }else{ 
      return 0.0 ;};
  };


  if( mux==0.0 || mux==1.0){
    //cout << "\nstuck" << endl;
    return distrorigin;
  }else{
  
    //cout << "transition " << i;
     switch(i % 3){
       case 0:
	 //cout << "transition 0" ;
	 //cout << "gammanext: nthink:\t " << nthink-1 << " nwait:\t" << nwait+1 << "nserv:\t" << nserv << "gamma:\t" << gammaprob.M[nthink-1][nwait+1][nserv] << endl;
	 //distr = (fork1 /tprob) *( mu(gammaprob,nthink -1, nwait+1 ,nserv) / mux);
	 distr = (fork1) *( mu(gammaprob,nthink -1, nwait+1 ,nserv) / mux);
	 break;
       case 1:
	 //cout << "transition 1" ;
	 //cout << "gammanext: nthink:\t" << nthink << " nwait:\t" << nwait-1 << "nserv:\t" << nserv << "gamma:\t" << gammaprob.M[nthink][nwait-1][nserv] << endl;
	 //distr = (fork2 / tprob) *( mu(gammaprob,nthink , nwait-1 ,nserv) / mux);
	 distr = (fork2) *( mu(gammaprob,nthink , nwait-1 ,nserv) / mux);
	 break;
       case 2:
	 //cout << "transition 2";
	 //cout << "gammanext: nthink:\t" << nthink+1 << " nwait:\t" << nwait << "nserv:\t" << nserv +1 << "gamma:\t" << gammaprob.M[nthink+1][nwait][nserv+1] << endl;
	 //distr = (eat / tprob) *(  mu(gammaprob,nthink+1 , nwait ,nserv+1) / mux );;
	 distr = (eat) *(  mu(gammaprob,nthink+1 , nwait ,nserv+1) / mux );
	 break;
     };   
     
     //cout << "distr: " << distr << endl;

     return distr;
  };
};
