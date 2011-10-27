#include <iostream>
#include <fstream>

#ifndef _BATCHR_HPP
#define	_BATCHR_HPP

class BatchR {
public:
  BatchR();
  virtual ~BatchR();
  bool IsBernoulli;
  int I;
  int Isucc;
  double Mean;
  double M2;
  void outputR();
  void inputR(FILE* f);

};


#endif /* _BATCHR_HPP */
