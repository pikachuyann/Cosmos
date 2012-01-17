//#include "spn.hpp"
//#include "LHA.hpp"
#include "BatchR.hpp"
#include "Simulator.hpp"
#include "SimulatorRE.hpp"
#include "SimulatorBoundedRE.hpp"
#include <sys/types.h>
#include <unistd.h>

// convert a string to an integer
int StrToInt(string st) {
    std::istringstream iss(st);
    int x;
    iss >> x;
    return x;
}

// main function it read the options given as arguments and initialyse 
// the simulator.
// Then it start a while loop which compute a batch of trajectory
// and output the result.
// The loop stop only when the programme receive end_of_file on
// his standart input
int main(int argc, char** argv) {
		//cerr << "start client"<< endl;	
	pid_t pid =getpid();
	write(STDOUT_FILENO,reinterpret_cast<char*>(&pid),sizeof(pid));
	fflush(stdout);
	//cerr << "pid : "<< pid << endl;
    Simulator* mySim; 
	
	string str;
	
	if(argc > 2){

		str = argv[2];
		if(str== "-RE"){
			mySim= (new SimulatorRE(false));
			//mySim->RareEvent_mode=true;
		}
		if(str== "-RE2"){
			mySim= (new SimulatorRE(true));
			//mySim->RareEvent_mode=true;
			//mySim->doubleIS_mode=true;
		}
		if(str== "-BURE"){
            int m = atoi(argv[3]);
            int T = atoi(argv[4]);
			mySim= (new SimulatorBoundedRE(m,T));
			//mySim->RareEvent_mode=true;
			//mySim->doubleIS_mode=true;
		}
		if(str== "-STSP"){
			stateSpace states;
			states.exploreStateSpace();
			states.buildTransitionMatrix();
			//states.printP();
			states.outputMat();
			exit(EXIT_SUCCESS);
		}
    } else {
		mySim= (new Simulator);
	}
    
    //mySim->Load(); //initialize the simulator
	
    str = argv[1];
    mySim->SetBatchSize(StrToInt(str)); //set the batch size

    while( !cin.eof() ){
      BatchR* batchResult = mySim->RunBatch(); //simulate a batch of trajectory

      batchResult->outputR();// output the result on the standart output
      
      /*cout << batchR->I <<":"<< batchR->Isucc <<":"<< batchR->Mean 
	<< ":" << batchR->M2 << endl;*/

      delete batchResult;
      
    }

    return (EXIT_SUCCESS);


}
