#ifndef _MarkingImpl_HPP
#define    _MarkingImpl_HPP
using namespace std;
#include <string.h>
#include "marking.hpp"
#include "markingTemplate.hpp"
class abstractBindingImpl {
public:
};
class abstractMarkingImpl {
public:
	int _PL_N_Queue1;
	int _PL_Queue1;
	int _PL_Phase1;
	int _PL_Phase2;
	int _PL_Queue2;
	int _PL_N_Queue2;
};

class abstractBindingIteratorImpl {
public:
	void reset(abstractMarkingImpl& m){};
	bool next(size_t& t, abstractMarkingImpl& m){return false;};
	size_t getIndex(){return 0;};
	abstractBinding getBinding(){return abstractBinding();};
};
#endif
