#ifndef _EVENT_HPP
#define	_EVENT_HPP

class Event {
public:
    Event();
    Event(unsigned int, double);
    Event(unsigned int, double, unsigned int, double);
    Event(const Event& orig);
    virtual ~Event();
    unsigned int getTrans();
    double getTime();
    unsigned int getPriority();
    double getWeight();
    void setTrans(int);
    void setTime(double);
    void setPriority(unsigned int);
    void setWeight(double);


    unsigned int transition;
    double time;
    unsigned int priority;
    double weight;

private:


};


#endif	/* _EVENT_HPP */

