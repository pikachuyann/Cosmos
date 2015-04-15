/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
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
 *******************************************************************************
 */

/**
 *
 *
 * \author   Benoît Barbot
 */


#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <math.h>

#include "server.hpp"
#include "parameters.hpp"
#include "Generator.hpp"

/**
 * Retrive the real absolute path of the executable of Cosmos
 * This is usefull for finding the library containing all the
 * code for the simulator.
 * Thoses functions fill the variable P.Path
 * This code is system dependant.
 * @param P is a structure of parameters
 */
void FindPath(parameters& P);

/**
 * A function to manipulate call to system
 * The result of the call to cmd is read from its standart
 * ouput and put in a string.
 */
string systemStringResult(const char* cmd);

/**
 * Clean the temporary directory
 */
void cleanTmp(void);

#ifdef __APPLE__
#include <mach-o/dyld.h>
void FindPath(parameters& P) {
	char path[1024];
	uint32_t size = sizeof(path);
	if (_NSGetExecutablePath(path, &size) != 0){
		printf("buffer too small; need size %u\n", size);
		exit(EXIT_FAILURE);
	}
	
	P.Path=path;
	std::string::size_type t = P.Path.find_last_of("/");
	P.Path = P.Path.substr(0, t);
	P.Path.append("/");
}
#elif __linux__
void FindPath(parameters& P) {
	char path[1024];
	char link[512];
	sprintf(link, "/proc/%d/exe", getpid());
	int sz = readlink(link, path, 1024);
	if (sz >= 0) {
		path[sz] = 0;
		P.Path = path;
		std::string::size_type t = P.Path.find_last_of("/");
		P.Path = P.Path.substr(0, t);
		P.Path.append("/");
	}
}

#else
#error "Operating system not supported"
#endif

using namespace std;

string systemStringResult(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "";
    char buffer[128];
    string result;
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}


/**
 * The global parameter structure
 */
parameters P;

void cleanTmp(void){
	if(P.tmpStatus==0 || P.tmpStatus==1){
		string cmd;
		cmd = "rm -rf " + P.tmpPath;
		if(system(cmd.c_str()) !=0)warnx("Fail to clean temporary file");
	}
}


/**
 * Main function
 * Build the simulator and launch it.
 */
int main(int argc, char** argv) {

    //Start the timer for build time.
    auto startbuild = chrono::steady_clock::now();
	
	// Fill the P structure from the command line
	P.parseCommandLine(argc,argv);

    if (P.verbose>0){
        cout << "################################################################################" << endl;
        cout << "##########################           Cosmos           ##########################" << endl;
        cout << "################################################################################" << endl;
    }
	//assert(cout<< "Cosmos compile in DEBUG mode!"<<endl);
	
	//If tmpStatus is zero generate random tmp directory
	if (P.tmpStatus == 0) {
		string newtmp = systemStringResult("mktemp -d tmpCosmos-XXXXXX");
		if(!newtmp.empty())P.tmpPath=newtmp.substr(0,newtmp.length()-1);
	}
	//If the tmp directory did not exist generate it.
	if(mkdir(P.tmpPath.c_str(), 0777) != 0){
		if(errno != EEXIST){
			err(EXIT_FAILURE,"Fail to build temporary directory:%s",P.tmpPath.c_str());
		}
	}
	if(P.verbose>2)cout << "Temporary directory set to:" << P.tmpPath << endl;
	atexit(cleanTmp);

    if(P.generateLHA==2 && P.dataPDFCDF.empty())
        P.dataPDFCDF = P.tmpPath+"/defaultOutput.dat";

	//Find the path to the directory containing the binary of cosmos.
	if(P.Path.compare("")==0){
		string st = argv[0];
        if (st == "./Cosmos")P.Path = "";
        else if(st.length()>6)P.Path=st.substr(0,st.length()-6);
        else FindPath(P);
    }
    if(P.verbose>2)cout << "Binary directory path set to:" << P.Path << endl;

    if(P.prismPath.empty())P.prismPath="prism";

    //Parse and generate the gspn and lha.
    if ( ! Parse()) {
        cout << "Fail to build the model.";
        return(EXIT_FAILURE);
    }

    if(!P.unfold.empty())return EXIT_SUCCESS;

    if(P.MaxRuns == 0 && P.lightSimulator){
        auto cmd = "cp "+P.Path+"../src/LightSimulator/*.* "+P.tmpPath;
        if(P.verbose>=3)cout << cmd << endl;
        system(cmd.c_str());
        cmd = "cd "+P.tmpPath+"; ./build.sh";
        if(P.verbose>=3)cout << cmd << endl;
        system(cmd.c_str());
        return EXIT_SUCCESS;
    }
    if(P.MaxRuns==0)return EXIT_SUCCESS;

    //Compile the simulator
    if(P.tmpStatus==0 || P.tmpStatus==2){
        if ( !build()) {
            cout << "Fail to Compile the model.";
            return(EXIT_FAILURE);
        }
    }

    //stop the timer for building, display the time if required.
    auto endtime = chrono::steady_clock::now();
    chrono::duration<double> buildtime= endtime-startbuild;
    if(P.verbose>0)cout<<"Time for building the simulator:\t"<< buildtime.count() << "s"<< endl;

    if(!P.sequential){ //Compute Chernoff-Hoeffding bounds
        double b = 0.0;
        for(const auto it : P.HaslFormulas) b = fmax(b,it->bound());
        if(b== INFINITY){
            cerr << "Cannot use Chernoff-Hoeffding bounds: no bounds on the computed value" << endl;
            return EXIT_FAILURE;
        }
		if(P.MaxRuns== (unsigned long)-1){
			P.MaxRuns = (int)(2.0*2.0*2.0*b*b/(P.Width*P.Width) * log(2/(1-P.Level)));
		}else if(P.Width == 0){
			P.Width = 2.0*b * sqrt( (2.0/P.MaxRuns) * log(2.0/(1.0-P.Level)));
		}else if(P.Level ==0){
			P.Level = (1.0 - (2.0* fmin(0.5 ,exp( (double)P.MaxRuns * P.Width*P.Width / (-2.0*2.0*2.0*b*b)))));
		}
	}
    launchServer(P);
	
	return (EXIT_SUCCESS);
}
