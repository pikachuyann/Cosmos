#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <unistd.h>

//#include "directsim.hpp"
#include "./LhaParser/Lha-Reader.hpp"
#include "./GspnParser/Gspn-Reader.hpp"
#include "server.hpp"
#include "parameters.hpp"

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
	//cout << "Unknow Cosmos directory" << endl;
	//exit(1);
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



bool ParseBuild(parameters& P) {
	Gspn_Reader gReader;
	
	/*if(P.GMLinput){
		GspnFileName.append(".gml");
	}else {
		GspnFileName.append(".gspn");
	}*/
	
	if(P.verbose>0)cout << "Start Parsing " << P.PathGspn << endl;
	int parseresult;
	
	if(P.GMLinput){
		parseresult = gReader.parse_gml_file(P.PathGspn);
	}else {
		parseresult = gReader.parse_file(P.PathGspn);
	}
	
	
	if (!parseresult) {
		gReader.MyGspn.Path = P.PathGspn.substr(0, P.PathGspn.find_last_of("."));
		gReader.WriteFile(P.Path);
	} else {
		Gspn_Reader gr;
		gReader = gr;
		return false;
	}
	
	
	Lha_Reader lReader;
	
	
	lReader.MyLha.TransitionIndex = gReader.MyGspn.TransId;
	lReader.MyLha.PlaceIndex = gReader.MyGspn.PlacesId;
	
	
	Gspn_Reader gr;
	gReader = gr;
	
	
	/*if(P.GMLinput){
		LhaFileName.append(".lha.gml");
	}else {
		LhaFileName.append(".lha");
	}*/
	
	if(P.verbose>0)cout << "Start Parsing " << P.PathLha << endl;
	
	if(P.GMLinput){
		parseresult = lReader.parse_gml_file(P.PathLha);
	}else {
		parseresult = lReader.parse_file(P.PathLha);
	}
	
	if (!parseresult) {
		lReader.WriteFile(P.Path);
		
	} else {
		Lha_Reader lr;
		lr = lReader;
		
		return false;
	}
	Lha_Reader lr;
	lr = lReader;
	if(P.verbose>0){
        cout << "Parsing OK.\n" << endl;
        cout << "Start building ... " << endl;
    }
	string cmd;
	
	cmd = "make -s -C " + P.Path + ".. sim";
	if (system(cmd.c_str())) return false;
	
	if(P.verbose>0)cout << "Building OK.\n" << endl;
	
	return true;
}

void DirectSim(parameters& P) {
	if (ParseBuild(P)) {
		LauchServer(P);
	}
}


int main(int argc, char** argv) {
	parameters P;
	
    P.parseCommandLine(argc,argv);
	
	// Declare the supported options.
		
	if(P.Path.compare("")==0){
		string st = argv[0];
		if (st == "./Cosmos") P.Path = "";
		else if (st == "Cosmos")FindPath(P);
		else P.Path.assign(st.begin(), st.end() - 6);
	}
		
	//cout << "executable absolute path: "<<P.Path <<endl;
	
	DirectSim(P);
	
	
	return (EXIT_SUCCESS);
}
