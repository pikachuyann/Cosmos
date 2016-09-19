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

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <cstdlib>
#include <err.h>
#include <errno.h>
#include <math.h>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "server.hpp"
#include "parameters.hpp"
#include "Generator.hpp"
#include "GspnParser/unfolder.hpp"
#include "GspnParser/Gspn-Grml-Output.hpp"

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
	if(P.tmpStatus & TS_DESTROY){
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
        if(P.isTTY && !P.guiGreatSpnMode){
            cout << "\033(0";
            cout << setw(P.terminalWidth/2-14) << "\x6c";
            cout.fill('\x71');
            cout << setw(28) << "\x6b" << endl;
            cout.fill(' ');
            cout << setw(P.terminalWidth/2-14) << "\x78";
            cout << "\033(B" << "           Cosmos          " << "\033(0";
            cout << "\x78" << endl;
            cout << setw(P.terminalWidth/2-14) << "\x6d";
            cout.fill('\x71');
            cout << setw(28) << "\x6a" << endl;
            cout.fill(' ');
            cout << "\033(B";
        }else {
            cout.fill('#');
            cout << setw(P.terminalWidth) << "#" << endl;
            cout << setw(P.terminalWidth/2+14) << "           Cosmos           ";
            cout << setw(P.terminalWidth-(P.terminalWidth/2 +14)) << "#" << endl;
            cout << setw(P.terminalWidth) << "#" << endl;
            cout.fill(' ');
        }
    }
    if(P.verbose>1){
        cout << "Actions: " << ((P.tmpStatus& TS_GEN) ? "Generate " : "");
        cout << ((P.tmpStatus& TS_BUILD) ? " Build " : "");
        cout << ((P.tmpStatus& TS_RUN) ? " Run " : "");
        cout << ((P.tmpStatus& TS_DESTROY) ? " Clean " : "") << endl;
    }
	//assert(cout<< "Cosmos compile in DEBUG mode!"<<endl);

	//If tmpStatus require it generate random tmp directory
	if (P.tmpStatus & TS_DESTROY) {
		string newtmp = systemStringResult("mktemp -d tmpCosmos-XXXXXX");
		if(!newtmp.empty())P.tmpPath=newtmp.substr(0,newtmp.length()-1);
	}
	//If the tmp directory do not exist generate it.
	if(mkdir(P.tmpPath.c_str(), 0777) != 0){
		if(errno != EEXIST){
			err(EXIT_FAILURE,"Fail to build temporary directory:%s",P.tmpPath.c_str());
        }
    }
    if(P.verbose>2)cout << "Temporary directory set to:" << P.tmpPath << endl;
    atexit(cleanTmp);

    if(P.generateLHA==SamplingLoop && P.dataPDFCDF.empty())
        P.dataPDFCDF = P.tmpPath+"/defaultOutput.dat";

    //Find the path to the directory containing the binary of cosmos.
    if(P.Path.compare("")==0){
        string st = argv[0];
        if (st == "./Cosmos")P.Path = ""; //local directory
        else if(st.length()>6)P.Path=st.substr(0,st.length()-6); //direct Path to Cosmos
        else FindPath(P); //Ask the system where Cosmos is (System dependant)
    }
    if(P.verbose>2)cout << "Binary directory path set to:" << P.Path << endl;

    //Parse models and generate code
    if(P.tmpStatus & TS_GEN){
        //Parse and generate the gspn and lha.
        shared_ptr<GspnType> pGSPN = ParseGSPN();
        if ( !pGSPN ) {
            cout << "Fail to build the GSPN." << endl;
            return(EXIT_FAILURE);
        }

        if (!P.unfold.empty()) {
            unfolder unfold(*pGSPN);
            ofstream unfoldfile(P.unfold, ios::out | ios::trunc);
            unfold.export_grml(unfoldfile);
            return EXIT_SUCCESS;
        }

        if (!P.outputModel.empty()) {
            GspnGrmlOutput outspn(*pGSPN);
            ofstream outfile(P.outputModel, ios::out | ios::trunc);
            outspn.print(outfile);
            return EXIT_SUCCESS;
        }
        
        if(P.MaxRuns == 0 && P.lightSimulator){
            auto cmd = "cp "+P.Path+"../src/LightSimulator/*.* "+P.tmpPath;
            if(P.verbose>=3)cout << cmd << endl;
            system(cmd.c_str());
            cmd = "cd "+P.tmpPath+"; ./build.sh";
            if(P.verbose>=3)cout << cmd << endl;
            system(cmd.c_str());
            return EXIT_SUCCESS;
        }

        if(!P.lightSimulator)
            if ( ! ParseLHA(*pGSPN)) {
                cout << "Fail to build the LHA." << endl;;
                return(EXIT_FAILURE);
            }
    } else {
        if ( ! ParseLHA()) {
            cout << "Fail to build the LHA. Try to go on anyway" << endl;;
        }
    }

    //Compile the simulator
    if(P.tmpStatus & TS_BUILD){
        if ( !build()) {
            cout << "Fail to Compile the model.";
            return(EXIT_FAILURE);
        }
    }

    //stop the timer for building, display the time if required.
    auto endtime = chrono::steady_clock::now();
    chrono::duration<double> buildtime= endtime-startbuild;
    if(P.verbose>0)cout<<"Time for building the simulator:\t"<< buildtime.count() << "s"<< endl;
    if(P.guiGreatSpnMode)cout << "#{GUI}# RESULT STAT build_time " << buildtime.count() << endl;

    // Run
    if(P.tmpStatus & TS_RUN){
        launchServer(P);
    }

    cleanTmp();
	return (EXIT_SUCCESS);
}
