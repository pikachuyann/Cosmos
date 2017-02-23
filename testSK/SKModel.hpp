class SKTransition {
public:
	size_t Id;
	std::string label;
	DistributionType DistTypeIndex;

	std::array<abstractBinding, 1> bindingList;
};

class SKMarking {
public:
	void printHeader(ostream&);
	void print(ostream&, float);
	void printSedCmd(ostream&);

	double signalA;
	double signalB;
	double signalC;
};

template <class EQT>
class SKModel {
public:
	abstractMarking Marking;
	std::vector<SKTransition> Transition;

	size_t lastTransition;
	double lastTransitionTime;

	SKModel();

	void reset();
	void initialEventsQueue(EQT&, timeGen&);
	void generateEvent(double ctime,Event& E,size_t Id,timeGen& TG);
	void fire(size_t, const abstractBinding&, double);
	void update(double, size_t, const abstractBinding&, EQT&, timeGen&);
};
