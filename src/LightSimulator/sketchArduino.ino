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
    Serial.println("->Sleep");
#endif
    Serial.flush();
    /*unsigned long ti = millis() + t;
    bool davailable = false;
    while(!davailable && millis()< ti ){
        davailable = Serial.available();
    }*/

    unsigned long ti = millis1() + 5;
    Serial.flush();
    bool davailable = false;
    while(!davailable && millis1()< ti ){
        davailable = Serial.available();
    }
    if(!davailable){
        t-=5;
        if(t>0){
            digitalWrite(13, LOW);
            sleepMillis((unsigned long)(t));
            digitalWrite(13, HIGH);
        }

    }
}

REAL_TYPE cRealTime(){
    return (REAL_TYPE)millis1();
}

//Serial comm function
char buff[4];

bool InDataAvailable(){
    if(Serial.available()){
#ifndef NO_STRING_SIM
        print("DATA R\n");
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
void SWrite(unsigned char h){
    /*if(blink){
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
    blink = ! blink;*/
    if (Serial) {
        Serial.write(h);
        Serial.flush();
    }
}


SimulatorLight mySim;


REAL_TYPE getPr(TR_PL_ID t){
    return (REAL_TYPE)mySim.N.GetPriority(t);
}


void setup() {
    Serial.begin(57600);
    mySim.verbose=5;
    initTimer1();
}



void loop() {
    Serial.println("\nStart");
    // put your main code here, to run repeatedly:
    mySim.SimulateSinglePath(); //simulate a batch of trajectory
}
