#include "spn.hpp"
#include "LHA.hpp"
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
    string str;

    if(argc > 5){
      str = argv[5];
      if(str== "-RE")mySim.RareEvent_mode=true;
    };
    
    mySim.Load();

    str = argv[1];
    mySim.SetConfLevel(StrToDbl(str));

    str = argv[2];
    mySim.SetConfWidth(StrToDbl(str));

    str = argv[3];
    mySim.SetBatchSize(StrToDbl(str));

    str = argv[4];
    mySim.SetMaxRuns(StrToLongInt(str));

   
    while( !cin.eof() ){
      BatchResult* batchR = mySim.RunBatch();

      write(STDOUT_FILENO,(void *)&batchR->I,sizeof(double));
      write(STDOUT_FILENO,(void *)&batchR->Isucc,sizeof(double));
      write(STDOUT_FILENO,(void *)&batchR->Mean,sizeof(double));
      write(STDOUT_FILENO,(void *)&batchR->M2,sizeof(double));

      //cout << batchR->I <<":"<< batchR->Isucc <<":"<< batchR->Mean 
      // << ":" << batchR->M2 << endl;
      

      delete batchR;
      
    }

    return (EXIT_SUCCESS);


}
