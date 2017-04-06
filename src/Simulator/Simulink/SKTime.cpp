#include <stdio.h>
#include "SKModelCommons.hpp"
#include <math.h>
#include <utility>

template<class EQT>
std::pair<double, double> SKModel<EQT>::rk45(double step, double xCurr, double xPrev, double yPrev) {
	printf ("Step: %E",step);
	double kA = step * xPrev;
	double kC = step * (xPrev + 3/8*step*(xCurr-xPrev));
	double kD = step * (xPrev + 12/13*step*(xCurr-xPrev));
	double kE = step * xCurr;
	double kF = step * (xPrev + 1/2*step*(xCurr-xPrev));
        printf ("xC: %E, xP: %E, yP: %E\n",xCurr,xPrev,yPrev);
        double tmp = yPrev + 25./216.*kA;
        printf ("yp+ 25/216*k1 = %E\n",tmp);
	double res4 = yPrev + 25./216.*kA + 1408./2565.*kC + 2197./4104.*kD - 1./5.*kE;
	double res5 = yPrev + 16./135.*kA + 6656./12825.*kC + 28561./56430.*kD - 9./50.*kE + 2./55.*kF;
        printf ("r4: %E - r5: %E\n", res4, res5);
	double diff = abs(res4 - res5);
        printf ("diff: %E\n",diff);
	if (diff < 0.0001) {
		printf ("OK\n");
		return std::make_pair(step,res4);
	}
	else {
		printf ("Hum : %E\n",step/2.);
		return std::make_pair(step/2.,res4);
	}
}

template<class EQT>
double SKModel<EQT>::rk4(double step, double xCurr, double xPrev, double yPrev) {
	std::pair<double,double> rk45res = rk45(step, xCurr, xPrev, yPrev);
	return rk45res.second;
}

template<class EQT>
int SKModel<EQT>::findLatencyIndex(double latency) {
	SKTime currTime = Marking.P->_TIME[Marking.P->lastEntry];
	while (Marking.P->countDown > 0 && Marking.P->_TIME[Marking.P->countDown] > (currTime - latency)) {
		Marking.P->countDown--;
	}
	if (Marking.P->_TIME[Marking.P->countDown] > (currTime - latency)) { return -1;
	} else { return Marking.P->countDown; }
}

SKTime::SKTime() {
	power=0; precision=0; time=0;
	updatePrecision(5);
	set_to(0.0);
}
SKTime::SKTime(double initTime) {
	power=0; precision=0; time=0;
	updatePrecision(5); set_to(initTime);
}
SKTime::SKTime(size_t prec, int64_t bareTime) {
	power=0; precision=0; time=0;
	updatePrecision(prec);
	time = bareTime;
}
void SKTime::updatePrecision(size_t prec) {
	if (prec > precision) {
		precision = prec;
		power = pow(10., prec);
		time = pow(10,(prec-precision)) * time;
	}
}
void SKTime::set_to(double newTime) {
	time = round(newTime * power);
}
int64_t SKTime::getBareTime() { return time; }
size_t SKTime::getPrecision() { return precision; }
double SKTime::getDouble() {
	double approxTime = time / power;
	return approxTime;
}
SKTime& SKTime::operator= (double newTime) { updatePrecision(5); set_to(newTime); }
bool SKTime::operator== (SKTime otherTime) {
	int precB = otherTime.getPrecision();
	if (precB > precision) { updatePrecision(precB); }
	else if (precB < precision) { otherTime.updatePrecision(precision); }
	return (time == otherTime.time);
}
bool SKTime::operator!= (SKTime otherTime) {
	int precB = otherTime.getPrecision();
	if (precB > precision) { updatePrecision(precB); }
	else if (precB < precision) { otherTime.updatePrecision(precision); }
	return (time != otherTime.time);
}
SKTime SKTime::operator+ (SKTime otherTime) {
	int precB = otherTime.getPrecision();
	if (precB > precision) { updatePrecision(precB); }
	else if (precB < precision) { otherTime.updatePrecision(precision); }
	return SKTime(precision,time+otherTime.getBareTime());
}
SKTime SKTime::operator- (SKTime otherTime) {
	int precB = otherTime.getPrecision();
	if (precB > precision) { updatePrecision(precB); }
	else if (precB < precision) { otherTime.updatePrecision(precision); }
	return SKTime(precision,time-otherTime.getBareTime());
}
SKTime SKTime::operator- (double otherTime) {
	int64_t oTime = round(otherTime * power);
	return SKTime(precision,time-oTime);
}
SKTime SKTime::operator+ (double otherTime) {
	int64_t oTime = round(otherTime * power);
	return SKTime(precision,time+oTime);
}
bool SKTime::operator< (SKTime otherTime) {
	int prec = getPrecision();
	int precB = otherTime.getPrecision();
	if (precB > prec) { updatePrecision(precB); }
	else if (precB < prec) { otherTime.updatePrecision(prec); }
	return getBareTime() < otherTime.getBareTime();
}
bool SKTime::operator> (SKTime otherTime) {
	int prec = getPrecision();
	int precB = otherTime.getPrecision();
	if (precB > prec) { updatePrecision(precB); }
	else if (precB < prec) { otherTime.updatePrecision(prec); }
	return getBareTime() > otherTime.getBareTime();
}
// SKTime::operator double() { return time / power; }
