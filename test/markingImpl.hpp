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
	int _PL_RE_Queue1;
	int _PL_RE_Queue2;
	int _PL_Puit;
};

class abstractBindingIteratorImpl {
public:
	void reset(abstractMarkingImpl& m);
	bool next(size_t& t, abstractMarkingImpl& m);
	size_t getIndex();
	abstractBinding getBinding();
};
#endif
