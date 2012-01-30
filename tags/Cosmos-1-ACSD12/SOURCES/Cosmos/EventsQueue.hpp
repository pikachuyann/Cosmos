#include <vector>
#include "Event.hpp"


#ifndef _EVENTSQUEUE_HPP
#define	_EVENTSQUEUE_HPP

using namespace std;

typedef vector <int> Tab;
typedef vector <Event> EQueue;
typedef vector <Event>::iterator EQit;

class EventsQueue {
public:
    EventsQueue(EQueue *);
    EventsQueue(int);

    EventsQueue(const EventsQueue& orig);
    virtual ~EventsQueue();

    void insert(Event &);
    void replace(Event &, int);
    void remove(int);
    void siftUp(int);
    void siftDown(int);

    bool isEmpty();
    void copyEvents(Event&, Event&);
    void view();
    bool isPriorer(Event&, Event&);

    int TransTabValue(int);
    void UpdateTransTab(int, int);
    void ViewTransTab();

    void reset();
    int getSize();

    EQueue* getEq();



    Event InPosition(int);
    EQueue* eq;
private:

    EQit* it;
    int Qsize;



    Tab* TransTable;
    int TransTableSize;

    int getLeftChildIndex(int nodeIndex) {
        return 2 * nodeIndex + 1;
    }

    int getRightChildIndex(int nodeIndex) {
        return 2 * nodeIndex + 2;
    }

    int getParentIndex(int nodeIndex) {
        return (nodeIndex - 1) / 2;
    }


};


#endif	/* _EVENTSQUEUE_HPP */

