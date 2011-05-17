#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <unistd.h>

#include "./LhaParser/Lha-Reader.hpp"
#include "./GspnParser/Gspn-Reader.hpp"

#ifdef __APPLE__
#define FindPath FindPathMac   
#elif __linux__
#define FindPath FindPathLinux
#else
#error "Operating system not supported"
#endif

using namespace std;

 struct SimParam {
    double Level;
    double Width;
    int Batch;
    long int MaxRuns;
    string Path;
};

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
    string options = "g++ -Wno-deprecated ";
    cmd = options + P.Path + "../SOURCES/Cosmos/spn.cpp -c -o " + P.Path + "../Obj/Cosmos/spn.o";

    if (system(cmd.c_str())) return false;

    cmd = options + P.Path + "../SOURCES/Cosmos/LHA.cpp -c -o " + P.Path + "../Obj/Cosmos/LHA.o";
    if (system(cmd.c_str())) return false;



    cmd = options + P.Path + "../SOURCES/Cosmos/main.cpp -c -o " + P.Path + "../Obj/Cosmos/main.o";
    if (system(cmd.c_str())) return false;

    cmd = options + P.Path + "../SOURCES/Cosmos/Simulator.cpp -c -o " + P.Path + "../Obj/Cosmos/Simulator.o";
    if (system(cmd.c_str())) return false;

    cmd = options + P.Path + "../SOURCES/Cosmos/RareEvent.cpp -c -o " + P.Path + "../Obj/Cosmos/RareEvent.o";
    if (system(cmd.c_str())) return false;

    cmd = options + P.Path + "../Obj/Cosmos/main.o " + P.Path + "../Obj/Cosmos/Event.o " + P.Path + "../Obj/Cosmos/EventsQueue.o ";
    cmd = cmd + P.Path + "../Obj/Cosmos/LHA.o  \\" + P.Path + "../Obj/Cosmos/Simulator.o " + P.Path + "../Obj/Cosmos/StandardNormalDist.o ";
    cmd = cmd + P.Path + "../Obj/Cosmos/ap.o  " + P.Path + "../Obj/Cosmos/RareEvent.o "+ P.Path + "../Obj/Cosmos/tab.o " +  P.Path + "../Obj/Cosmos/spn.o -o " + P.Path + "SimGPP";
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
            if (P.Path == "") os << "./SimGPP " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns;
            else os << P.Path << "SimGPP " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns;
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
        if (P.Path == "") os << "./SimGPP " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns;
        else os << P.Path << "SimGPP " << P.Level << " " << P.Width << " " << P.Batch << " " << P.MaxRuns;
        system((os.str()).c_str());

    }
}

void LoadSimParam(SimParam& P) {
    P.Level = 0.99;
    P.Width = 0.00000000000000000000001;
    P.Batch = 1000;
    P.MaxRuns = 1000000;
}

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

void FindPathMac(SimParam& P) {
    //to be done
    cout << "Unknow Cosmos directory" << endl;
    exit(1);
}

int main(int argc, char** argv) {
    SimParam P;

    LoadSimParam(P);


    string st = argv[0];
    if (st == "./CosmosGPP") P.Path = "";
    else if (st == "CosmosGPP")FindPath(P);
    else P.Path.assign(st.begin(), st.end() - 9);

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
