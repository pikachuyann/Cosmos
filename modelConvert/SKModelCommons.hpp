#ifndef SKModel_Commons
#define SKModel_Commons

class SKTime {
public:
	SKTime();
	SKTime(double);
	SKTime(size_t,int64_t);

	void updatePrecision(size_t);
	void set_to(double);
	void increment(double);
	size_t getPrecision();
	int64_t getBareTime();
	double getDouble();

	SKTime& operator = (double);
	SKTime operator + (SKTime);
	SKTime operator - (SKTime);
	SKTime operator + (double);
	SKTime operator - (double);
	bool operator == (SKTime);
	bool operator != (SKTime);
	bool operator < (SKTime);
	bool operator > (SKTime);
//	operator double();

private:
	size_t precision;
	int64_t time;
	double power;
};

#endif
