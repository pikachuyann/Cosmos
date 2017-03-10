#ifndef _MarkingImpl_HPP
#define _MarkingImpl_HPP
using namespace std;
#include <string.h>
#include "marking.hpp"
#include "markingTemplate.hpp"

class abstractBindingImpl {
public:
};

class abstractBindingIteratorImpl {
public:
	void reset(abstractMarkingImpl& m){};
	bool next(size_t& t, abstractMarkingImpl& m){ return false; };
	size_t getIndex(){ return 0; };
	abstractBinding getBinding(){ return abstractBinding(); };
};

class abstractMarkingImpl {
public:
	size_t lastPrintEntry;
	size_t lastEntry;
	size_t totalEntries;
	size_t countDown;
	vector<double> _TIME;
	// Block 2 - type Integrator (named Integrator) :
	vector<double> _BLOCK2_OUT1;
	// Block 1 - type Constant (named Constant) :
	vector<double> _BLOCK1_OUT1;
	// Block 3 - type Sum (named Add) :
	vector<double> _BLOCK3_OUT1;
};

#endif