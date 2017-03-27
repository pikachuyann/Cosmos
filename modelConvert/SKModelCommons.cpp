#include <stdio.h>

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
	double currTime = Marking.P->_TIME[Marking.P->lastEntry];
	while (Marking.P->countDown > 0 && Marking.P->_TIME[Marking.P->countDown] > (currTime - latency)) {
		Marking.P->countDown--;
	}
	if (Marking.P->_TIME[Marking.P->countDown] > (currTime - latency)) { return -1;
	} else { return Marking.P->countDown; }
}
