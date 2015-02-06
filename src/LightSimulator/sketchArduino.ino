#include <Event.h>
#include <EventsQueueLight.h>
#include <markingImpl.h>
#include <SimLight.h>
#include <spnLight.h>

void print(const char * s){
    Serial.print(s);
}
void print(TR_PL_ID i){
    Serial.print(i);
}
void print(REAL_TYPE r){
    Serial.print(r);
}

SimulatorLight mySim;
bool blink = false;

REAL_TYPE getPr(TR_PL_ID t){
    return (REAL_TYPE)mySim.N.GetPriority(t);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\nStart");
  mySim.SetBatchSize(1); //set the batch size
  mySim.verbose=5;

  
}

void loop() {
    if(blink){
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
    blink = ! blink;
  // put your main code here, to run repeatedly:
  mySim.RunBatch(); //simulate a batch of trajectory
}
