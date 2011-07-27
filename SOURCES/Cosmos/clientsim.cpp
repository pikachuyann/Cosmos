#include "spn.hpp"
#include "LHA.hpp"
#include "BatchR.hpp"
#include "Simulator.hpp"

double StrToDbl(string st) {

    std::istringstream iss(st);
    double x;
    iss >> x;
    return x;
}

int StrToInt(string st) {

    std::istringstream iss(st);
    int x;
    iss >> x;
    return x;
}

long int StrToLongInt(string st) {

    std::istringstream iss(st);
    long int x;
    iss >> x;
    return x;
}


int main(int argc, char** argv) {
  
  
    Simulator mySim;
    mySim.RareEvent_mode = false;
    mySim.doubleIS_mode = false;
    string str;

    if(argc > 2){
      str = argv[2];
      if(str== "-RE")mySim.RareEvent_mode=true;
      if(str== "-RE2"){
	mySim.RareEvent_mode=true;
	mySim.doubleIS_mode=true;
      }
    };
    
    mySim.Load();

    str = argv[1];
    mySim.SetBatchSize(StrToDbl(str));

    while( !cin.eof() ){
      BatchR* batchResult = mySim.RunBatch();

      batchResult->outputR();
      
      /*cout << batchR->I <<":"<< batchR->Isucc <<":"<< batchR->Mean 
	<< ":" << batchR->M2 << endl;*/

      delete batchResult;
      
    }

    return (EXIT_SUCCESS);


}
