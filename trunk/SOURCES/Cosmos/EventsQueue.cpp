#include "EventsQueue.hpp"
#include "Event.hpp"
#include <iostream>

using namespace std;

EventsQueue::EventsQueue(int i) {
    eq = new vector <Event > (i);
    Qsize = 0;


    TransTableSize = i;
    TransTable = new vector <int> (TransTableSize);
    for (int k = 0; k < TransTableSize; k++)
        (*TransTable)[k] = -1;


}

EventsQueue::EventsQueue(EQueue* EQ) {

    eq = EQ;
    Qsize = 0;



}

bool EventsQueue::isPriorer(Event& E1, Event& E2) {
    //smallest time is priorer
    if (E1.time > E2.time) return false;
    if (E1.time < E2.time) return true;
    // if not(< or >) so it is =
    // highest priority is priorer
    if (E1.priority < E2.priority) return false;
    if (E1.priority > E2.priority) return true;
    //bigest weight is priorer
    if (E1.weight > E2.weight) return false;
    else return true;

}

void EventsQueue::reset() {
    for (int i = 0; i < TransTableSize; i++)
        (*TransTable)[i] = -1;
    Qsize = 0;

}

EventsQueue::EventsQueue(const EventsQueue& orig) {
    eq = orig.eq;
    Qsize = orig.Qsize;

    TransTableSize = orig.TransTableSize;
    TransTable = orig.TransTable;

}

EventsQueue::~EventsQueue() {
}

void EventsQueue::insert(Event &e) {

	(*eq)[Qsize] = e;

    Qsize++;

    (*TransTable)[(*eq)[Qsize - 1].transition] = Qsize - 1;
    siftUp(Qsize - 1);


}

void EventsQueue::replace(Event &e, int k) {

    if (e.transition != (*eq)[k].transition)
        (*TransTable)[(*eq)[k].transition] = -1;

    (*eq)[k] = e;
    (*TransTable)[(*eq)[k].transition] = k;
    siftUp(k);
    siftDown(k);
}

Event EventsQueue::InPosition(int i) {
    return (*eq)[i];
}

void EventsQueue::siftUp(int i) {
    int parentIndex;


    if (i != 0) {
        parentIndex = getParentIndex(i);

        if (isPriorer((*eq)[i], (*eq)[parentIndex])) {
            Event eswap((*eq)[parentIndex]);


            (*TransTable)[(*eq)[parentIndex].transition] = i;
            (*TransTable)[(*eq)[i].transition] = parentIndex;

            (*eq)[parentIndex] = (*eq)[i];
            (*eq)[i] = eswap;


            siftUp(parentIndex);

        }


    }




}

void EventsQueue::remove(int i) {

    if (i == Qsize - 1) {

        (*TransTable)[(*eq)[Qsize - 1].transition] = -1;
        Qsize--;

    } else {


        (*TransTable)[(*eq)[Qsize - 1].transition] = i;
        (*TransTable)[(*eq)[i].transition] = -1;
        (*eq)[i] = (*eq)[Qsize - 1];

        Qsize--;

        siftDown(i);
        siftUp(i);
    }

}

void EventsQueue::siftDown(int i) {
    //int parentIndex;
    int leftChildIndex, rightChildIndex, minIndex;
	//int tmp;
    leftChildIndex = getLeftChildIndex(i);
    rightChildIndex = getRightChildIndex(i);
    if (rightChildIndex >= Qsize) {
        if (leftChildIndex >= Qsize)
            return;
        else
            minIndex = leftChildIndex;
    } else {

        if (isPriorer((*eq)[leftChildIndex], (*eq)[rightChildIndex]))
            minIndex = leftChildIndex;
        else
            minIndex = rightChildIndex;
    }

    if (isPriorer((*eq)[minIndex], (*eq)[i])) {

        (*TransTable)[(*eq)[minIndex].transition] = i;
        (*TransTable)[(*eq)[i].transition] = minIndex;

        Event eswap((*eq)[minIndex]);
        (*eq)[minIndex] = (*eq)[i];
        (*eq)[i] = eswap;

        siftDown(minIndex);
    }


}

bool EventsQueue::isEmpty() {
    return (Qsize == 0);
}

void EventsQueue::copyEvents(Event& e1, Event& e2) {

    e1.transition = e2.transition;
    e1.time = e2.time;
    e1.priority = e2.priority;
    e1.weight = e2.weight;

}

void EventsQueue::view() {
    cout << "********** EVENTS-QUEUE VIEW **********" << endl;

    cout << "Qsize:" << Qsize << endl;

    if (Qsize == 0)
        cout << "EVENTS-QUEUE is empty!" << endl;
    else
        for (unsigned int i = 0; i < Qsize; i++)
            cout << "Equeue[" << i << "]:" << "(tr" << (*eq)[i].transition << ",t=" << (*eq)[i].time << ", p=" << (*eq)[i].priority << ", w=" << (*eq)[i].weight << ")" << endl;
}

int EventsQueue::TransTabValue(int i) {
    return (*TransTable)[i];
}

void EventsQueue::UpdateTransTab(int trans, int value) {

    (*TransTable)[trans] = value;

}

void EventsQueue::ViewTransTab() {
    cout << "Position of transitions in the heap:" << endl;

    for (int i = 0; i < TransTableSize; i++)
        cout << "Trans[" << i + 1 << "]=" << (*TransTable)[i] << endl;

}

int EventsQueue::getSize() {
    return Qsize;
}

EQueue* EventsQueue::getEq() {
    return eq;
}
