#include <Event.h>
#include <EventsQueueLight.h>
#include <markingImpl.h>
#include <SimLight.h>
#include <spnLight.h>

#include <Timer1.h>

void print(const char * s){
    Serial.print(s);
}
void print(TR_PL_ID i){
    Serial.print(i);
}
void print(REAL_TYPE r){
    Serial.print(r);
}

void wait(REAL_TYPE t){
    if(t<=0)return;
    Serial.println("Got to Sleep");
    Serial.flush();
    sleepMillis((unsigned long)t);
}

REAL_TYPE cRealTime(){
    return (REAL_TYPE)millis1();
}

bool InDataAvailable(){
    Serial.available();
}

SimulatorLight mySim;
bool blink = false;

REAL_TYPE getPr(TR_PL_ID t){
    return (REAL_TYPE)mySim.N.GetPriority(t);
}


void setup() {
    Serial.begin(115200);
    mySim.verbose=1;
    initTimer1();
}



void loop() {
    Serial.println("\nStart");
    if(blink){
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
    blink = ! blink;
    // put your main code here, to run repeatedly:
    mySim.SimulateSinglePath(); //simulate a batch of trajectory
}
