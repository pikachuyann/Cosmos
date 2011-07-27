#include "BatchR.hpp"

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
  write(STDOUT_FILENO,reinterpret_cast<char*>(&IsBernoulli),sizeof(bool));
  write(STDOUT_FILENO,reinterpret_cast<char*>(&I),sizeof(int));
  write(STDOUT_FILENO,reinterpret_cast<char*>(&Isucc),sizeof(int));
  write(STDOUT_FILENO,reinterpret_cast<char*>(&Mean),sizeof(double));
  write(STDOUT_FILENO,reinterpret_cast<char*>(&M2),sizeof(double));
  fflush(stdout);
}

void BatchR::inputR(FILE* f) {
  double read;
  bool readb;
  int readi;

  fread(reinterpret_cast<char*>( &readb ), sizeof readb ,1, f);
  IsBernoulli=readb;
  fread(reinterpret_cast<char*>( &readi ), sizeof readi ,1, f);
  I=readi;
  fread(reinterpret_cast<char*>( &readi ), sizeof readi ,1, f);
  Isucc=readi;
  fread(reinterpret_cast<char*>( &read ), sizeof read ,1, f);
  Mean=read;
  fread(reinterpret_cast<char*>( &read ), sizeof read ,1, f);
  M2=read;

}
