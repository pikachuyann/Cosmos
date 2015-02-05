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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySim.SetBatchSize(1); //set the batch size
  mySim.verbose=4;

  
}

void loop() {
  // put your main code here, to run repeatedly:
  mySim.RunBatch(); //simulate a batch of trajectory
}
