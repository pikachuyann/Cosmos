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
#include <sys/time.h>
#include <err.h>
#include <errno.h>

//#include "directsim.hpp"
#include "./LhaParser/Lha-Reader.hpp"
#include "./GspnParser/Gspn-Reader.hpp"
#include "server.hpp"
#include "parameters.hpp"


/**
 * Retrive the real absolute path of the executable of Cosmos
 * This is usefull for finding the library containing all the
 * code for the simulator.
 * Thoses functions fill the variable P.Path
 * This code is system dependant.
 * @param P is a structure of parameters
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

/**
 * Parse the input file and build the simulator
 * Return true iff the parsing was successfull
 * input file are read as Grml file or .gspn and .lha file or 
 * directly .cpp for LHA
 * according to the P.GMLinput parameters or extension.
 * @param P is a structure of parameters
 * @return a boolean equal to true if everything run correctly
 */
bool ParseBuild(parameters& P) {
	Gspn_Reader gReader;
	
	if(P.verbose>0)cout << "Start Parsing " << P.PathGspn << endl;
	int parseresult;
	
    try{
        if(P.GMLinput || (P.PathGspn.compare(P.PathGspn.length()-4,4,"grml") ==0)){
            parseresult = gReader.parse_gml_file(P);
        }else {
            parseresult = gReader.parse_file(P.PathGspn);
        }
        
        if (!parseresult && gReader.MyGspn.pl >0 && gReader.MyGspn.tr >0) {
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
	
	Lha_Reader lReader(gReader.MyGspn);
	
	lReader.MyLha.TransitionIndex = gReader.MyGspn.TransId;
	lReader.MyLha.PlaceIndex = gReader.MyGspn.PlacesId;
	
	
	
	if(P.verbose>0)cout << "Start Parsing " << P.PathLha << endl;
	
    try{
		//check the type of the LHA file.
		if(P.PathLha.compare(P.PathLha.length()-3,3,"cpp")!=0){
			//here LHA is absent or in LHA file format or in GRML file format
			if(P.loopLHA>0.0){
				//The LHA is absent one with two loop is produced.
				lReader.MyLha.ConfidenceLevel = P.Level;
				map<string,int>::const_iterator itt;
				stringstream lhastr;
				lhastr << "NbVariables = "<<1+gReader.MyGspn.tr + gReader.MyGspn.pl <<";\nNbLocations = 3;\n";
				lhastr << "const double T="<< P.loopLHA << ";\n";
				lhastr << "const double invT=" << 1/P.loopLHA << ";\n";
				lhastr << "const double Ttrans="<< P.loopTransientLHA << ";\n";
				lhastr << "VariablesList = {time";
				for (itt = gReader.MyGspn.TransId.begin(); itt != gReader.MyGspn.TransId.end(); ++itt) {
					lhastr<< ", "<< itt->first;
				}
				for (itt = gReader.MyGspn.PlacesId.begin(); itt != gReader.MyGspn.PlacesId.end(); ++itt) {
					lhastr<< ", PLVAR_"<< itt->first;
				}
				lhastr<<"} ;\nLocationsList = {l0, l1,l2};\n";
				
				for (itt = gReader.MyGspn.TransId.begin(); itt != gReader.MyGspn.TransId.end(); ++itt) {
					lhastr<< "Throughput_"<< itt->first<< "= AVG(Last(" << itt->first<<"));\n";
				}
				for (itt = gReader.MyGspn.PlacesId.begin(); itt != gReader.MyGspn.PlacesId.end(); ++itt) {
					lhastr<< "MeanToken_"<< itt->first<< "= AVG(Last( PLVAR_" << itt->first<<"));\n";
				}
				lhastr << P.externalHASL << endl;
				lhastr << "InitialLocations={l0};\nFinalLocations={l2};\n";
				lhastr << "Locations={(l0, TRUE, (time:1));(l1, TRUE, (time:1 ";
				for (itt = gReader.MyGspn.PlacesId.begin(); itt != gReader.MyGspn.PlacesId.end(); ++itt) {
					lhastr<< ", PLVAR_"<< itt->first << ": "<< itt->first << "* invT " ;
				}
				
				lhastr << "));(l2, TRUE);};\n";
				lhastr << "Edges={((l0,l0),ALL,time<= Ttrans ,#);((l0,l1),#,time=Ttrans ,{time=0});";
				for (itt = gReader.MyGspn.TransId.begin(); itt != gReader.MyGspn.TransId.end(); ++itt) {
					lhastr << "((l1,l1),{"<< itt->first <<"},time<=T,{"<<itt->first<<" = " <<itt->first<<" + "<< 1.0/P.loopLHA << " });\n";
				}
				lhastr << "((l1,l2),#,time=T ,#);};";
				string s = lhastr.str();
				parseresult = lReader.parse(s);
				P.externalHASL = "";
			} else if(P.GMLinput || (P.PathLha.compare(P.PathLha.length()-4,4,"grml")==0))  {
				//The LHA is in the GRML file format
				parseresult = lReader.parse_gml_file(P);
			}else {
				//The LHA is in the LHA file format
				parseresult = lReader.parse_file(P);
			}
			
			//Add external HASL formula to the lha.
			if(P.externalHASL.compare("")!=0)
				lReader.parse(P.externalHASL);
			
			//If everythink work correctly, copy the HASL formula and generate the code
			if (!parseresult && lReader.MyLha.NbLoc>0) {
				P.HaslFormulasname = lReader.MyLha.HASLname;
				P.HaslFormulas = vector<HaslFormulasTop*>(lReader.MyLha.HASLtop);
				P.nbAlgebraic = lReader.MyLha.Algebraic.size();
				//If the countTrans option is set then add HASL formula counting the occurance of each transition of the LHA.
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
				
				//Generate the code for the LHA
				if(P.tmpStatus==0||P.tmpStatus==2)lReader.WriteFile(P);
				
			} else {
				Lha_Reader lr(gReader.MyGspn);
				return false;
			}
		} else if(P.PathLha.compare(P.PathLha.length()-3,3,"cpp")==0){
			//The code for the LHA is provided by the user
			lReader.MyLha.ConfidenceLevel = P.Level;
			//Add external HASL formula
			if(P.externalHASL.compare("")==0){
				P.HaslFormulasname.push_back("preComputedLHA");
				HaslFormulasTop *ht = new HaslFormulasTop( (size_t)0, P.Level);
				P.HaslFormulas.push_back(ht);
				P.nbAlgebraic = 1;
			}else{
				parseresult = lReader.parse(P.externalHASL);
				if(!parseresult){
					P.HaslFormulasname = lReader.MyLha.HASLname;
					P.HaslFormulas = vector<HaslFormulasTop*>(lReader.MyLha.HASLtop);
					P.nbAlgebraic = lReader.MyLha.Algebraic.size();
				} else
					cerr << "Fail to parse extra Hasl Formula"<< endl;
			}
			
			//Copy the code into the temporary directory
			string cmd = "cp "+P.PathLha +" " + P.tmpPath +"/LHA.cpp";
			system(cmd.c_str());
		}
	}catch (exception& e)
	{
		cerr << "The following exception append during import: "<< e.what() << endl;
		return false;
    }
	
	//If the code should not be compiled return
	if(P.tmpStatus==1||P.tmpStatus==3)return true;
	
	if(P.verbose>0){
        cout << "Parsing OK.\n" << endl;
        cout << "Start building ... " << endl;
    }
    
    string cmd;
	string bcmd = P.gcccmd + " " + P.gccflags;
	
	if(!P.RareEvent){
		//If rareenvent handling is not require copy an empty lumping function code to the temporary directory
        string lumpfunpath = P.tmpPath + "/lumpingfun.cpp";
		ofstream lumpfun(lumpfunpath.c_str(), ios::out | ios::trunc);
        lumpfun << "void SPN::lumpingFun(vector<int>* vect){}" << endl;
        lumpfun.close();
    }else {
		//If rareevent handling is require copy the lumping function and table of value to the temporary directory
		if(P.BoundedRE==0)cmd = "cp muFile " + P.tmpPath +"/muFile";
		else cmd = "cp matrixFile " + P.tmpPath +"/matrixFile";
		if (system(cmd.c_str())) return false;
		cmd = "cp lumpingfun.cpp " + P.tmpPath +"/lumpingfun.cpp";
		if (system(cmd.c_str())) return false;
		
		for(vector<HaslFormulasTop*>::iterator it = P.HaslFormulas.begin();
			it != P.HaslFormulas.end(); ++it)
			if ( (*it)->TypeOp == EXPECTANCY ) (*it)->TypeOp = RE_AVG;
	}

	//Compile the SPN
	cmd = bcmd + " -c -I"+P.Path+"../includes -o "+P.tmpPath+"/spn.o "+P.tmpPath+"/spn.cpp";
	if(P.verbose>2)cout << cmd << endl;
	if (system(cmd.c_str())) return false;
	
	//Compile the LHA
	cmd = bcmd + " -c -I"+P.Path+"../includes -o "+P.tmpPath+"/LHA.o "+P.tmpPath+"/LHA.cpp";
	if(P.verbose>2)cout << cmd << endl;
	if (system(cmd.c_str())) return false;
	
	//Link SPN and LHA with the library
	cmd = bcmd + " -o "+P.tmpPath+"/ClientSim "+P.tmpPath+"/spn.o "+P.tmpPath+"/LHA.o "+P.Path+"libClientSim.a ";
	if(P.verbose>2)cout << cmd << endl;
	if (system(cmd.c_str())) return false;
	
	if(P.verbose>0)cout << "Building OK.\n" << endl;
	
	return true;
}

/**
 * Clean the temporary directory
 * @param P is a structure of parameters
 */
void cleanTmp(parameters& P){
	if(P.tmpStatus==0 || P.tmpStatus==1){
		string cmd;
		cmd = "rm -rf " + P.tmpPath;
		system(cmd.c_str());
	}
}

/**
 * Main function
 * Build the simulator and launch it.
 */
int main(int argc, char** argv) {
	parameters P;
	timeval startbuild,endbuild;
	
	P.parseCommandLine(argc,argv);
	
	//Start the timer for build time.
	gettimeofday(&startbuild, NULL);
	
	//If the tmp directory did not exist generate it.
	if(mkdir(P.tmpPath.c_str(), 0777) != 0){
		if(errno != EEXIST){
			err(EXIT_FAILURE,"Fail to build temporary directory:%s",P.tmpPath.c_str());
		}
	}
	
	if (P.verbose>0)cout << "Cosmos" << endl;
	
	//Find the path to the directory containing the binary of cosmos.
	if(P.Path.compare("")==0){
		string st = argv[0];
		if (st == "./Cosmos") P.Path = "";
		else if (st == "Cosmos")FindPath(P);
		else P.Path.assign(st.begin(), st.end() - 6);
	}
	
	//Build the model and lha.
	if ( ! ParseBuild(P)) {
		cout << "Fail to build the model.";
		cleanTmp(P);
		return(EXIT_FAILURE);
	}
	
	//stop the timer for building, display the time if required.
	gettimeofday(&endbuild, NULL);
	double buildTime = endbuild.tv_sec - startbuild.tv_sec + ((endbuild.tv_usec - startbuild.tv_usec) / 1000000.0);
	if(P.verbose>0)cout<<"Time for building the simulator:\t"<< buildTime<< "s"<< endl;
	
	//Lauch the client for generating the state space or for building.
	if(P.computeStateSpace>0){
		launchExport(P);
	} else launchServer(P);
	
	cleanTmp(P);
	
	return (EXIT_SUCCESS);
}
