#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
//#include <unistd.h>

using namespace std;

int main(int argc, char** argv){

  FILE* stream;
  string cmd = "ClientSim 0.99 0.1 1000 10000";
  char buff[sizeof(double)];


  stream = popen(cmd.c_str(), "r");

  while(true){

    read(buff,sizeof(double),stream);
    cout << (double)*buff << endl;

  };

}
