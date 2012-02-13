#include "BatchR.hpp"

using namespace std;

BatchR::BatchR() {
  IsBernoulli = true;
  I =0;
  Isucc=0;
  Mean=0;
  M2=0;
}

BatchR::~BatchR() {
}

void BatchR::outputR() {
  int size;
  size = write(STDOUT_FILENO,reinterpret_cast<char*>(&IsBernoulli),sizeof(bool));
  size = write(STDOUT_FILENO,reinterpret_cast<char*>(&I),sizeof(int));
  size = write(STDOUT_FILENO,reinterpret_cast<char*>(&Isucc),sizeof(int));
  size = write(STDOUT_FILENO,reinterpret_cast<char*>(&Mean),sizeof(double));
  size = write(STDOUT_FILENO,reinterpret_cast<char*>(&M2),sizeof(double));
  fflush(stdout);
}

void BatchR::inputR(FILE* f) {
  double read;
  bool readb;
  int readi;
  int size;

  size = fread(reinterpret_cast<char*>( &readb ), sizeof readb ,1, f);
  IsBernoulli=readb;
  size = fread(reinterpret_cast<char*>( &readi ), sizeof readi ,1, f);
  I=readi;
  size = fread(reinterpret_cast<char*>( &readi ), sizeof readi ,1, f);
  Isucc=readi;
  size = fread(reinterpret_cast<char*>( &read ), sizeof read ,1, f);
  Mean=read;
  size = fread(reinterpret_cast<char*>( &read ), sizeof read ,1, f);
  M2=read;

}

void BatchR::print(){
    cerr << "IsBernoulli:\t" << IsBernoulli << endl
    << "I:\t" << I << endl
    << "Isucc:\t" << Isucc << endl
    << "Mean:\t" << Mean << endl
    << "M2:\t" << M2 << endl;
}