#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <float.h>

#include "ap.hpp"

#ifndef _STANDARDNORMALDIST_HPP
#define	_STANDARDNORMALDIST_HPP

class normaldistr {
public:
    normaldistr();
    double erf(double);
    double erfc(double);
    double normaldistribution(double);
    double inverf(double);
    double invnormaldistribution(double);
};






#endif	/* _STANDARDNORMALDIST_HPP */

