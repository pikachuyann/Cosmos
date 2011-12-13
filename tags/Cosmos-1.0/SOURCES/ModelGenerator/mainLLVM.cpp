/*******************************************************************************
 *									       *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)dels (S)tochastique *
 *									       *
 * Copyright (C) 2009-2011 LSV, ENS Cachan & CNRS & INRIA                      *
 * Author: Paolo Ballarini & Hilal Djafri                                      *
 * Website: http://www.lsv.ens-cachan.fr/Software/Cosmos                       *
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
 *                                                                             *
 *******************************************************************************
 */



#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

#include <sstream>
#include <unistd.h>

#include "./LhaParser/Lha-Reader.hpp"
#include "./GspnParser/Gspn-Reader.hpp"


using namespace std;

typedef struct  {
    double Level;
    double Width;
    int Batch;
    long int MaxRuns;
    string Path;
} SimParam;

#ifdef __APPLE__
#include <mach-o/dyld.h>
void FindPathMac(SimParam& P) {
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
void FindPathLinux(SimParam& P) {

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

#elif __FreeBSD__
void FindPathFreeBSD(SimParam& P) {

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
#define FindPath FindPathFreeBSD
#else
#error "Operating system not supported"
#endif

void ViewParameters(SimParam& P) {
    cout << "Confidence interval width:      " << P.Width << endl;
    cout << "Confidence interval level:      " << P.Level << endl;
    cout << "Maximum number of trajectories: " << P.MaxRuns << endl;
    cout << "Batch size:                     " << P.Batch << endl;
}

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

bool ParseBuild(string filename, SimParam& P) {
    Gspn_Reader gReader;
    string GspnFileName = filename;
    GspnFileName.append(".gspn");

    cout << "Start Parsing ... " << endl;
    if (!gReader.parse_file(GspnFileName)) {

        gReader.MyGspn.Path = filename;
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

    string LhaFileName = filename;
    LhaFileName.append(".lha");

    if (!lReader.parse_file(LhaFileName)) {
        lReader.WriteFile(P.Path);

    } else {
        Lha_Reader lr;
        lr = lReader;

        return false;
    }
    Lha_Reader lr;
    lr = lReader;
    cout << "Parsing OK.\n" << endl;
    cout << "Start building ... " << endl;
    string cmd;
    cmd = "g++ -O3  -emit-llvm " + P.Path + "../SOURCES/Cosmos/spn.cpp -c -o " + P.Path + "../Obj/Cosmos/spn.bc";

    if (system(cmd.c_str())) return false;

    cmd = "g++   -O3 -emit-llvm " + P.Path + "../SOURCES/Cosmos/LHA.cpp -c -o " + P.Path + "../Obj/Cosmos/LHA.bc";
    if (system(cmd.c_str())) return false;

    cmd = "llc  " + P.Path + "../Obj/Cosmos/spn.bc -o " + P.Path + "../Obj/Cosmos/spn.s";
    if (system(cmd.c_str())) return false;

    cmd = "llc  " + P.Path + "../Obj/Cosmos/LHA.bc -o " + P.Path + "../Obj/Cosmos/LHA.s";
    if (system(cmd.c_str())) return false;

    cmd = "g++ -O3  -emit-llvm " + P.Path + "../SOURCES/Cosmos/main.cpp -c -o " + P.Path + "../Obj/Cosmos/main.bc";
    if (system(cmd.c_str())) return false;

    cmd = "g++  -O3  -emit-llvm " + P.Path + "../SOURCES/Cosmos/Simulator.cpp -c -o " + P.Path + "../Obj/Cosmos/Simulator.bc";
    if (system(cmd.c_str())) return false;

    cmd = "llc  " + P.Path + "../Obj/Cosmos/main.bc -o " + P.Path + "../Obj/Cosmos/main.s";
    if (system(cmd.c_str())) return false;

    cmd = "llc  " + P.Path + "../Obj/Cosmos/Simulator.bc -o " + P.Path + "../Obj/Cosmos/Simulator.s";
    if (system(cmd.c_str())) return false;

    cmd = "g++  " + P.Path + "../Obj/Cosmos/main.s " + P.Path + "../Obj/Cosmos/Event.s " + P.Path + "../Obj/Cosmos/EventsQueue.s ";
    cmd = cmd + P.Path + "../Obj/Cosmos/LHA.s  \\" + P.Path + "../Obj/Cosmos/Simulator.s ";
    cmd = cmd + P.Path + "../Obj/Cosmos/ap.s  " + P.Path + "../Obj/Cosmos/spn.s -o " + P.Path + "SimLLVM";
    if (system(cmd.c_str())) return false;

    cout << "Building OK.\n" << endl;

    return true;
}

void Command(string str, SimParam& P) {

    if (str == "sim") {

        cout << "Type the path of the files: ";
        string filename;
        getline(cin, filename);
        if (ParseBuild(filename, P)) {
            ostringstream os;
            if (P.Path == "") os << "./SimLLVM " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns;
            else os << P.Path << "SimLLVM " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns;
            system((os.str()).c_str());

        }
    } 
    else if (str == "regensim") {

        cout << "Type the path of the files: ";
        string filename;
        getline(cin, filename);
        if (ParseBuild(filename, P)) {
            ostringstream os;
            if (P.Path == "") os << "./SimLLVM " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns <<" regen";
            else os << P.Path << "SimLLVM " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns << " regen";
            system((os.str()).c_str());

        }
    } 
    else if (str == "width") {
        string st;
        cout << "Type the confidence width: ";
        getline(cin, st);

        double y = StrToDbl(st);
        if (y <= 0 || y >= 1)
            cout << "width should be in ]0,1[" << endl;
        else {
            P.Width = y;
            cout << "New width: " << y << endl;
        }

    } else if (str == "level") {
        string st;
        cout << "Type the confidence level: ";
        getline(cin, st);

        double y = StrToDbl(st);
        if (y <= 0 || y >= 1)
            cout << "level should be in ]0,1[" << endl;
        else {
            P.Level = y;
            cout << "New level: " << y << endl;
        }

    } else if (str == "batch") {
        string st;
        cout << "Type batch size: ";
        getline(cin, st);

        int y = StrToInt(st);
        if (y > P.MaxRuns || y < 1)
            cout << "batch size  should be in [1,maxpaths]" << endl;
        else {
            P.Batch = y;
            cout << "New batch size: " << y << endl;
        }
    } else if (str == "maxpaths") {
        string st;
        cout << "Type maximum number of paths: ";
        getline(cin, st);

        long int y = StrToLongInt(st);
        if (y < P.Batch)
            cout << "maxpaths  should be >  Batch size" << endl;
        else {
            P.MaxRuns = y;
            cout << "New maxpaths: " << y << endl;
        }

    } else if (str == "params") {

        ViewParameters(P);
    } else if (str == "help") {
        cout << "Allowed commands\n" << endl;
        cout << "\tsim" << endl;	
        cout << "\twidth" << endl;
        cout << "\tlevel" << endl;
        cout << "\tbatch" << endl;
        cout << "\tmaxpaths" << endl;
        cout << "\tparams" << endl;
        cout << "\thelp" << endl;
        cout << "\tstop\n" << endl;
    } else
        cout << "Unknown command, for more information type 'help':\n" << endl;
}

void DirectSim(string filename, SimParam& P) {

    if (ParseBuild(filename, P)) {
        ostringstream os;
        if (P.Path == "") os << "./SimLLVM " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns;
        else os << P.Path << "SimLLVM " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns;
        system((os.str()).c_str());

    }
}

void LoadSimParam(SimParam& P) {
    P.Level = 0.99;
    P.Width = 0.01;
    P.Batch = 1000;
    P.MaxRuns = 10000000;
}

int main(int argc, char** argv) {
    SimParam P;

    LoadSimParam(P);

    string st = argv[0];


    if (st == "./CosmosLLVM") P.Path = "";
    else if (st == "CosmosLLVM")FindPath(P);
    else P.Path.assign(st.begin(), st.end() - 10);

    if (argc > 1) {
        st = argv[1];
        DirectSim(st, P);
        return (EXIT_SUCCESS);
    }


    while (true) {
        string str;
        cout << "COSMOS: ";
        getline(cin, str);
        if (str == "stop")
            break;
        else Command(str, P);

    }

    return (EXIT_SUCCESS);
}
