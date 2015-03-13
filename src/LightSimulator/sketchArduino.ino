#include <Event.h>
#include <EventsQueueLight.h>
#include <markingImpl.h>
#include <SimLight.h>
#include <spnLight.h>

#include <Timer1.h>
#define MARKER_PORT_ONE 7
#define MARKER_PORT_TWO 4
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
    const int wait_sleep = 2;
    if(t<=0)return;

    unsigned long ti = millis1() + min(wait_sleep,t);

#ifndef NO_STRING_SIM
    Serial.println("->Sleep");
#endif
    
    Serial.flush();

    digitalWrite(MARKER_PORT_ONE, HIGH);
    digitalWrite(MARKER_PORT_TWO, HIGH);
    
    bool davailable = false;
    while(!davailable && millis1()< ti ){
        davailable = Serial.available();
    }
    
    digitalWrite(MARKER_PORT_ONE, LOW);
    digitalWrite(MARKER_PORT_TWO, LOW);
    
    if(!davailable){
        t-= wait_sleep;
        if (t>0) sleepMillis((unsigned long)(t));
    }
    
}

REAL_TYPE cRealTime(){
    return (REAL_TYPE)millis1();
}

//Serial comm function
unsigned char InDataAvailable(){
    if(Serial.available()){
        if (Serial.peek()=='A' || Serial.peek()=='S' || Serial.peek()=='W' || Serial.peek()=='D')
            return 2;
        else{
#ifndef NO_STRING_SIM
            print("DATA R\n");
#endif
            return 1;
        }
    } else {
        return 0;
    }
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
    if (Serial) {
        if(h>=0x35 && h<=0x3A) {
            digitalWrite(MARKER_PORT_ONE, HIGH);
            digitalWrite(MARKER_PORT_TWO, LOW);
        }
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

unsigned long BytesToLong(char iBytes[4])
{
    unsigned long ri = 0;
    
    ri = (unsigned long)(iBytes[3]);
    ri = (ri << 8) | (unsigned long)(iBytes[2]);
    ri = (ri << 8) | (unsigned long)(iBytes[1]);
    ri = (ri << 8) | (unsigned long)(iBytes[0]);
    
    return ri;
}

void AddTransitionID(TR_PL_ID tranID)
{
}

void setup() {
    //Switch off all leds
    /*DDRD &= B00000011;       // set Arduino pins 2 to 7 as inputs, leaves 0 & 1 (RX & TX) as is
    DDRB = B00000000;        // set pins 8 to 13 as inputs
    PORTD |= B11111100;      // enable pullups on pins 2 to 7, leave pins 0 and 1 alone
    PORTB |= B11111111;      // enable pullups on pins 8 to 13*/
    pinMode(MARKER_PORT_ONE,OUTPUT);
    pinMode(MARKER_PORT_TWO,OUTPUT);
    pinMode(AP_PORT,OUTPUT);
    pinMode(VP_PORT,OUTPUT);
    digitalWrite(MARKER_PORT_ONE, LOW);
    digitalWrite(MARKER_PORT_TWO, HIGH);
    digitalWrite(AP_PORT, LOW);
    digitalWrite(VP_PORT, LOW);

    Serial.begin(57600);
    mySim.verbose= VERBOSE_LEVEL;
    initTimer1();
    
}



void loop() {
    char buff[5];
    char cnt;
    unsigned long ri = 0;
    double r;
    
    delay(1);
    
    //digitalWrite(MARKER_PORT_TWO, LOW);
    
    mySim.SimulateSinglePath(); //simulate a batch of trajectory

    if(InDataAvailable()==2) {
        switch (Serial.peek()) {
            case 'A':
            case 'S':
                digitalWrite(MARKER_PORT_ONE, LOW);
                digitalWrite(MARKER_PORT_TWO, HIGH);
                
                buff[0] = Serial.read();
                
                mySim.StopSimulation();
                
                break;
                
            case 'W':
                digitalWrite(MARKER_PORT_TWO, LOW);
                digitalWrite(MARKER_PORT_ONE, LOW);
                
                buff[0] = Serial.read();
                
                mySim.StartSimulation();
                
                initTimer1();
                
                break;
                
            case 'D':
                buff[0] = Serial.read();
                cnt = 0;
                
                while(cnt<5) {
                    if(Serial.available()) {
                        buff[cnt] = Serial.read();
                        cnt++;
                    }
                }
                
                r = BytesToLong(&buff[1]);
                SetParameters((unsigned char)(buff[0]), r);
                
                if (Serial) {
                    Serial.write(0xF6);
                    Serial.flush();
                }
                break;
                
            default:
                break;
        }
    }

}
