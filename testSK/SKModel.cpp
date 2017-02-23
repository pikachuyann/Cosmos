/* template class SimulatorBase<Simulator<EventsQueue<vector<SKTransition>>, SKModel<EventsQueue<vector<SKTransition>>>>, EventsQueue<vector<SKTransition>>, SKModel<EventsQueue<vector<SKTransition>>>>;
template class Simulator<EventsQueue<vector<SKTransition>>, SKModel<EventsQueue<vector<SKTransition>>>>; */

/*
void SKMarking::printHeader(ostream& logtrace) {
	logtrace << "printHeader of SKMarking has been called";
}
void SKMarking::print(ostream& logtrace,float eTime) {
	logtrace << "print of SKMarking has been called";
}
void SKMarking::printSedCmd(ostream& logtrace) {
	logtrace << "printSedCmd of SKMarking has been called";
}
*/

#include "marking.hpp"
#include "markingImpl.hpp"

void abstractMarking::resetToInitMarking() {
	P->_SIG_S1 = 0.0;
	P->_SIG_S2 = 0.0;
	P->_SIG_S3 = 0.0;
}

abstractMarking::abstractMarking() {
	P=new abstractMarkingImpl;
	resetToInitMarking();
}
/*
abstractMarking::abstractMarking(const std::vector<float>& m) {
	P=new abstractMarkingImpl;
	setVector(m);
}
*/
abstractMarking::abstractMarking(const abstractMarking& m) {
	P=new abstractMarkingImpl;
	*this = m;
}
abstractMarking& abstractMarking::operator = (const abstractMarking& m) {
	*P = *(m.P);
	return *this;
}
abstractMarking::~abstractMarking() {
	delete(P);
}

void abstractMarking::swap(abstractMarking& m) {
	abstractMarkingImpl* tmp = m.P;
	m.P = P;
	P = tmp;
}

void abstractMarking::printHeader(ostream& s) const{
	s << setw(5) << "S1";
	s << setw(5) << "S2";
	s << setw(5) << "S3";
}
void abstractMarking::print(ostream& s,double eTime) const{
	s << setw(4) << P->_SIG_S1 << " ";
	s << setw(4) << P->_SIG_S2 << " ";
	s << setw(4) << P->_SIG_S3 << " ";
}
void abstractMarking::printSedCmd(ostream& s) const{
	s << "-e 's/\\$S1\\$/" << P->_SIG_S1 << "/g' ";
	s << "-e 's/\\$S2\\$/" << P->_SIG_S2 << "/g' ";
	s << "-e 's/\\$S3\\$/" << P->_SIG_S3 << "/g' ";
}

/*
std::vector<float> abstractMarking::getVector() const{
	std::vector<float> v(3); v.reserve(4);
	v[1] = P->_SIG_S1;
	v[2] = P->_SIG_S2;
	v[3] = P->_SIG_S3;
	return v;
}
void abstractMarking::setVector(const std::vector<float>& v) {
	P->_SIG_S1 = v[1];
	P->_SIG_S2 = v[2];
	P->_SIG_S3 = v[3];
}
*/

bool abstractBinding::next() {
	idcount++;
	return false;
}
abstractBinding::abstractBinding() {
	idcount=0;
}
abstractBinding::abstractBinding(const abstractBinding& m) {
	idcount=m.idcount;
}
abstractBinding::~abstractBinding() { }
abstractBinding& abstractBinding::operator = (const abstractBinding& m) {
	idcount = m.idcount;
	return *this;
}
void abstractBinding::print() const{ }
int abstractBinding::id() const { return idcount; }
int abstractBinding::idTotal() const { return 0; }

template<class EQT>
SKModel<EQT>::SKModel() {
	Transition.push_back(SKTransition());
};

template<class EQT>
void SKModel<EQT>::initialEventsQueue(EQT& EQ, timeGen& tg) {
	Event E;
	generateEvent(0.0, E, 0, tg);
	EQ.insert(E);
};

template<class EQT>
void SKModel<EQT>::generateEvent(double ctime, Event& E,size_t Id, timeGen& tg) {
	double t = ctime;

	E.transition = Id;
	E.time = t;
	E.priority = 1;
	E.weight = 1;
};

template<class EQT>
void SKModel<EQT>::reset() {
	Marking.resetToInitMarking();
};

template<class EQT>
void SKModel<EQT>::fire(size_t tr,const abstractBinding&, double ctime) {
	Marking.P->_SIG_S1 = sin(ctime);
	Marking.P->_SIG_S2 = cos(ctime);
	Marking.P->_SIG_S3 = Marking.P->_SIG_S1 + Marking.P->_SIG_S2;
};

template<class EQT>
void SKModel<EQT>::update(double ctime, size_t tr, const abstractBinding& b, EQT &EQ, timeGen &TG) {
	EQ.remove(tr,b.id());
	double t = ctime;
	Event E;
	if (t < 10.0) {
		t = t + 0.5;
		generateEvent(t, E, 0, TG);
		EQ.insert(E);
	} else { EQ.reset(); }
};

template class SKModel<EventsQueue<std::vector<SKTransition>>>;
