#include <Event.h>
#include <EventsQueueLight.h>
#include <markingImpl.h>
#include <SimLight.h>
#include <spnLight.h>

#include <Timer1.h>
#define MARKER_PORT 4
#define AP_PORT 12
#define VP_PORT 11

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
    /*unsigned long ti = millis() + t;
    bool davailable = false;
    while(!davailable && millis()< ti ){
        davailable = Serial.available();
    }*/

    unsigned long ti = millis1() + min(2,t);
    digitalWrite(MARKER_PORT, HIGH);
    
    Serial.flush();
    bool davailable = false;
    while(!davailable && millis1()< ti ){
        davailable = Serial.available();
    }
    
    digitalWrite(MARKER_PORT, LOW);
    if(!davailable){
        t-=2;
        if(t>0){
            //digitalWrite(13, LOW);
            sleepMillis((unsigned long)(t));
            //digitalWrite(13, HIGH);
        }

    }
}

REAL_TYPE cRealTime(){
    return (REAL_TYPE)millis1();
}

//Serial comm function
unsigned char InDataAvailable(){
    char buff[5];
    if(Serial.available()){
        if (Serial.peek()=='A') {
            buff[0] = Serial.read();
            Serial.println(buff[0]);
            char cnt = 0;
            //Serial.readBytes(buff, 5);
            while(cnt<5) {
                if(Serial.available()) {
                    buff[cnt] = Serial.read();
                    Serial.println(buff[cnt]);
                    cnt++;
                }
            }
            
            unsigned long ri = 0;
            ri = (unsigned long)(buff[1]);
            ri = (ri << 8) | (unsigned long)(buff[2]);
            ri = (ri << 8) | (unsigned long)(buff[3]);
            ri = (ri << 8) | (unsigned long)(buff[4]);
            
            double r = *(double*)&ri;
            SetParameters((unsigned char)(buff[0]), r);
            
            return 2;
        }else{
#ifndef NO_STRING_SIM
            print("DATA R\n");
#endif
            return 1;
        }
    } else return 0;
}

unsigned char SReceive(){
    char buff[2];
    Serial.readBytes(&buff[0],1);
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

void dW(uint8 port, uint8 value)
{
    digitalWrite(port, value);
}

SimulatorLight mySim;


REAL_TYPE getPr(TR_PL_ID t){
    return (REAL_TYPE)mySim.N.GetPriority(t);
}


void setup() {
    //Switch off all leds
    /*DDRD &= B00000011;       // set Arduino pins 2 to 7 as inputs, leaves 0 & 1 (RX & TX) as is
    DDRB = B00000000;        // set pins 8 to 13 as inputs
    PORTD |= B11111100;      // enable pullups on pins 2 to 7, leave pins 0 and 1 alone
    PORTB |= B11111111;      // enable pullups on pins 8 to 13*/
    pinMode(MARKER_PORT,OUTPUT);
    pinMode(AP_PORT,OUTPUT);
    pinMode(VP_PORT,OUTPUT);
    digitalWrite(MARKER_PORT, LOW);
    
    Serial.begin(57600);
    mySim.verbose= VERBOSE_LEVEL;
    initTimer1();
}



void loop() {
    Serial.println("\nStart");
    // put your main code here, to run repeatedly:
    mySim.SimulateSinglePath(); //simulate a batch of trajectory
}
