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

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <sys/stat.h>
#include <err.h>
#include <errno.h>

//#include "directsim.hpp"
#include "./LhaParser/Lha-Reader.hpp"
#include "./GspnParser/Gspn-Reader.hpp"
#include "server.hpp"
#include "parameters.hpp"


/*
	Retrive the real absolute path of the executable of Cosmos
	This is usefull for finding the library containing all the
	code for the simulator.
	Thoses functions fill the variable P.Path
	This code is system dependant.
 */
#ifdef __APPLE__
#include <mach-o/dyld.h>
void FindPathMac(parameters& P) {
	char path[1024];
	uint32_t size = sizeof(path);
	if (_NSGetExecutablePath(path, &size) != 0){
		printf("buffer too small; need size %u\n", size);
		exit(0);
	}
	
	P.Path=path;
	std::string::size_type t = P.Path.find_last_of("/");
	P.Path = P.Path.substr(0, t);
	P.Path.append("/");
}

#define FindPath FindPathMac
#elif __linux__
void FindPathLinux(parameters& P) {
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

#define FindPath FindPathLinux
#else
#error "Operating system not supported"
#endif

using namespace std;

/*
 Parse the input file
 Return true iff the parsing was successfull
 input file are read as Grml file or .gspn and .lha file
 according to the P.GMLinput parameters.
 
 
 */
bool ParseBuild(parameters& P) {
	Gspn_Reader gReader;
	
	if(P.verbose>0)cout << "Start Parsing " << P.PathGspn << endl;
	int parseresult;
	
    try{
        if(P.GMLinput){
            parseresult = gReader.parse_gml_file(P.PathGspn,P.RareEvent);
        }else {
            parseresult = gReader.parse_file(P.PathGspn);
        }
        
        if (!parseresult) {
            gReader.MyGspn.Path = P.PathGspn.substr(0, P.PathGspn.find_last_of("."));
            if(P.tmpStatus==0||P.tmpStatus==2)gReader.WriteFile(P);
        } else {
            Gspn_Reader gr;
            gReader = gr;
            return false;
        }
	}catch (exception& e)
    {
        cerr << "The following exception append during import: "<< e.what() << endl;
        return false;
    }
	
	Lha_Reader lReader;
	
	lReader.MyLha.TransitionIndex = gReader.MyGspn.TransId;
	lReader.MyLha.PlaceIndex = gReader.MyGspn.PlacesId;
	
	Gspn_Reader gr;
	gReader = gr;
	
	if(P.verbose>0)cout << "Start Parsing " << P.PathLha << endl;
	
    try{
        if(P.GMLinput){
            parseresult = lReader.parse_gml_file(P);
        }else {
            parseresult = lReader.parse_file(P);
        }
        
        if (!parseresult) {
            P.HaslFormulasname = vector<string>(lReader.MyLha.HASLname);
			P.HaslFormulas = vector<HaslFormulasTop*>(lReader.MyLha.HASLtop);
			P.nbAlgebraic = lReader.MyLha.Algebraic.size();
			if(P.CountTrans){
				for (size_t tr=0; tr < lReader.MyLha.Edge.size(); tr++) {
					P.nbAlgebraic++;
					std::stringstream transname;
					transname << "P_";
					transname << lReader.MyLha.LocLabel[lReader.MyLha.Edge[tr].Source];
					transname << "->";
					transname << lReader.MyLha.LocLabel[lReader.MyLha.Edge[tr].Target];
					P.HaslFormulasname.push_back(transname.str());
					P.HaslFormulas.push_back(new HaslFormulasTop(lReader.MyLha.Algebraic.size()+tr,
															lReader.MyLha.ConfidenceLevel));
					
				}
			}
			
            if(P.tmpStatus==0||P.tmpStatus==2)lReader.WriteFile(P);
            
        } else {
            Lha_Reader lr;
            lr = lReader;
            
            return false;
        }
    }catch (exception& e)
    {
        cerr << "The following exception append during import: "<< e.what() << endl;
        return false;
    }
	Lha_Reader lr;
	lr = lReader;
	if(P.tmpStatus==1||P.tmpStatus==3)return true;
	if(P.verbose>0){
        cout << "Parsing OK.\n" << endl;
        cout << "Start building ... " << endl;
    }
    
    if(!P.RareEvent){
        //string lumpfunpath = P.Path + "../SOURCES/Cosmos/lumpingfun.cpp";
        string lumpfunpath = P.tmpPath + "/lumpingfun.cpp";
		ofstream lumpfun(lumpfunpath.c_str(), ios::out | ios::trunc);
        lumpfun << "void SPN::lumpingFun(vector<int>* vect){}" << endl;
        lumpfun.close();
    }
    
	string cmd;
	string bcmd = P.gcccmd + " " + P.gccflags;
	
	if(P.RareEvent){
		cmd = "cp muFile " + P.tmpPath +"/muFile";
		if (system(cmd.c_str())) return false;
		cmd = "cp lumpingfun.cpp " + P.tmpPath +"/lumpingfun.cpp";
		if (system(cmd.c_str())) return false;
	}
	
	cmd = bcmd + " -c -I"+P.Path+"../includes -o "+P.tmpPath+"/spn.o "+P.tmpPath+"/spn.cpp";
	if (system(cmd.c_str())) return false;
	
	cmd = bcmd + " -c -I"+P.Path+"../includes -o "+P.tmpPath+"/LHA.o "+P.tmpPath+"/LHA.cpp";
	if (system(cmd.c_str())) return false;
	
	cmd = bcmd + " -o "+P.tmpPath+"/ClientSim "+P.tmpPath+"/spn.o "+P.tmpPath+"/LHA.o "+P.Path+"libClientSim.a ";
	if (system(cmd.c_str())) return false;
	
	
	/*cmd = "make -s -C " + P.Path + ".. sim";
	if (system(cmd.c_str())) return false;
	*/
	if(P.verbose>0)cout << "Building OK.\n" << endl;
	
	return true;
}

void cleanTmp(parameters& P){
	if(P.tmpStatus==0 || P.tmpStatus==1){
		string cmd;
		cmd = "rm -rf " + P.tmpPath;
		system(cmd.c_str());
	}
}

int main(int argc, char** argv) {
	parameters P;
	time_t startbuild,endbuild;
	
    P.parseCommandLine(argc,argv);
    time(&startbuild);
	
	if(mkdir(P.tmpPath.c_str(), 0777) != 0){
		if(errno != EEXIST){
			err(EXIT_FAILURE,"Fail to build temporary directory:%s",P.tmpPath.c_str());
		}
	}
	
    if (P.verbose>0)cout << "Cosmos" << endl;
	
	if(P.Path.compare("")==0){
		string st = argv[0];
		if (st == "./Cosmos") P.Path = "";
		else if (st == "Cosmos")FindPath(P);
		else P.Path.assign(st.begin(), st.end() - 6);
	}
	if ( ! ParseBuild(P)) {
		cout << "Fail to build the model.";
		cleanTmp(P);
		return(EXIT_FAILURE);
	}
	time(&endbuild);
	if(P.verbose>0)cout<<"Time for building the simulator:\t"<<difftime(endbuild,startbuild)<< "s"<< endl;
	
	if(P.computeStateSpace){
		launchExport(P);
	} else launchServer(P);
	
	cleanTmp(P);
	
	return (EXIT_SUCCESS);
}
