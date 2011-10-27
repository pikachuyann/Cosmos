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
   bool RareEvent;
   bool DoubleIS;
	 bool GMLinput;
};

double StrToDbl(string st);
int StrToInt(string st);
long int StrToLongInt(string st);

void LauchServer(SimParam& P);


#endif	/* _SERVER_HPP */
