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
    Serial.println("Got to Sleep");
    Serial.flush();
#endif
    sleepMillis((unsigned long)t);
}
REAL_TYPE cRealTime(){
    return (REAL_TYPE)millis1();
}

//Serial comm function
char buff[4];

bool InDataAvailable(){
    if(Serial.available()){
        print("DATA Available\n");
        return true;
    } else return false;
}

long SReceive4(){
    Serial.readBytes(buff,4);
    Serial.print("Received'");
    Serial.print(buff[0]);
    Serial.print(buff[1]);
    Serial.print(buff[2]);
    Serial.print(buff[3]);
    Serial.println("'");
    return ((long)buff[0]+ ((long)buff[1] << 4)+ ((long)buff[2] << 8)+ ((long)buff[4] << 12));
}
int SReceive2(){
    Serial.readBytes(buff,2);
    Serial.print("Received'");
    Serial.print(buff[0]);
    Serial.print(buff[1]);
    Serial.println("'");


    return ((int)buff[0]+ ((int)buff[1] << 4));
}
char SReceive(){
    Serial.readBytes(buff,1);
    Serial.print("Received'");
    Serial.print(buff[0]);
    Serial.println("'");
    return buff[0];
}
void SWrite(char h, char d, char e){
    if(blink){
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
    blink = ! blink;
    if (Serial) {
        Serial.write((byte)h);
        Serial.write((byte)d);
        Serial.write((byte)e);
    }
}


SimulatorLight mySim;


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
    // put your main code here, to run repeatedly:
    mySim.SimulateSinglePath(); //simulate a batch of trajectory
}
