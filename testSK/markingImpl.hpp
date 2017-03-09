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
	float _SIG_S1;
	float _SIG_S2;
	float _SIG_S3;
};

class abstractBindingIteratorImpl {
public:
	void reset(abstractMarkingImpl& m){};
	bool next(size_t& t, abstractMarkingImpl& m){return false;};
	size_t getIndex(){return 0;};
	abstractBinding getBinding(){ return abstractBinding(); };
};

#endif