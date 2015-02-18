#include <Event.h>
#include <EventsQueueLight.h>
#include <markingImpl.h>
#include <SimLight.h>
#include <spnLight.h>

#include <Timer1.h>

bool blink = true;

//print function
void print(const char * s){
    Serial.print(s);
}
void print(TR_PL_ID i){
    Serial.print(i);
}
void print(REAL_TYPE r){
    Serial.print(r);
}


//Real time function
void wait(REAL_TYPE t){
    if(t<=0)return;
#ifndef NO_STRING_SIM
    Serial.println("Go to Sleep");
#endif
    unsigned long ti = millis() + t;
    Serial.flush();
    while(!Serial.available() && millis()< ti ){}
    //sleepMillis((unsigned long)t);
}
REAL_TYPE cRealTime(){
    return (REAL_TYPE)millis();
}

//Serial comm function
char buff[4];

bool InDataAvailable(){
    if(Serial.available()){
#ifndef NO_STRING_SIM
        print("DATA Available\n");
#endif
        return true;
    } else return false;
}

unsigned char SReceive(){
    Serial.readBytes(buff,1);
#ifndef NO_STRING_SIM
    Serial.print("Received'");
    Serial.print(buff[0]);
    Serial.println("'");
#endif
    return (unsigned char)buff[0];
}
void SWrite(unsigned char h,unsigned char d, unsigned char e){
    if(blink){
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
    blink = ! blink;
    if (Serial) {
        Serial.write(h);
        Serial.write(d);
        Serial.write(e);
        Serial.flush();
    }
}


SimulatorLight mySim;


REAL_TYPE getPr(TR_PL_ID t){
    return (REAL_TYPE)mySim.N.GetPriority(t);
}


void setup() {
    Serial.begin(57600);
    mySim.verbose=0;
    initTimer1();
}



void loop() {
    Serial.println("\nStart");
    // put your main code here, to run repeatedly:
    mySim.SimulateSinglePath(); //simulate a batch of trajectory
}
