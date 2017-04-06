#include <stdio.h>
#include "SKTime.hpp"
#include <math.h>

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
