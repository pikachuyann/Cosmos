using namespace std;

#ifndef _SERVER_HPP
#define	_SERVER_HPP


struct SimParam {
	int Njob;
	double Level;
	double Width;
	int Batch;
	long int MaxRuns;
	string Path;
	string PathGspn;
	string PathLha;
	bool RareEvent;
	bool DoubleIS;
	int BoundedRE;
    int horizon;
	bool GMLinput;
    bool computeStateSpace;
	bool alligatorMode;
};

double StrToDbl(string st);
int StrToInt(string st);
long int StrToLongInt(string st);

void LauchServer(SimParam& P);


#endif	/* _SERVER_HPP */
