#include "Event.hpp"


Event::Event() {
}

Event::Event(unsigned int tr, double t) {
    transition = tr;
    time = t;
}

Event::Event(unsigned int tr, double t, unsigned int pr, double w) {
    transition = tr;
    time = t;
    priority = pr;
    weight = w;
}

Event::Event(const Event& orig) {
    transition = orig.transition;
    time = orig.time;
    priority = orig.priority;
    weight = orig.weight;

}

Event::~Event() {
}

double Event::getTime() {
    return (this->time);
}

unsigned int Event::getPriority() {
    return (this->priority);
}

double Event::getWeight() {
    return (this->weight);
}

unsigned int Event::getTrans() {
    return (this->transition);
}

void Event::setTrans(int tr) {
    transition = tr;
}

void Event::setTime(double t) {
    time = t;
}

void Event::setPriority(unsigned int pr) {
    priority = pr;

}

void Event::setWeight(double w) {
    weight = w;

}