#include <Event.h>
#include <EventsQueueLight.h>
#include <markingImpl.h>
#include <SimLight.h>
#include <spnLight.h>

#include <Timer1.h>
#define AP_PORT 12
#define VP_PORT 11

#define MARKER_PORT_ONE 7
#define MARKER_PORT_TWO 4

#define SET_BOTH_LOW(PORT_ONE, PORT_TWO) B00000000
#define SET_BOTH_HIGH(PORT_ONE, PORT_TWO) ((B1<<PORT_ONE) | (B1<<PORT_TWO))
#define SET_ONEH_TWOL(PORT_ONE, PORT_TWO) (B1<<PORT_ONE)
#define SET_ONEL_TWOH(PORT_ONE, PORT_TWO) (B1<<PORT_TWO)


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

    //digitalWrite(MARKER_PORT_ONE, HIGH);
    //digitalWrite(MARKER_PORT_TWO, HIGH);
    PORTD = SET_BOTH_HIGH(MARKER_PORT_ONE, MARKER_PORT_TWO);
    
    bool davailable = false;
    while(!davailable && millis1()< ti ){
        davailable = Serial.available();
    }
    
    //digitalWrite(MARKER_PORT_ONE, LOW);
    //digitalWrite(MARKER_PORT_TWO, LOW);
    PORTD = SET_BOTH_LOW(MARKER_PORT_ONE, MARKER_PORT_TWO);
    
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
            PORTD = SET_ONEH_TWOL(MARKER_PORT_ONE, MARKER_PORT_TWO);
            //delay(5);
        
            //Serial.write(h);
            //Serial.flush();
        }
        
        Serial.write(h);
        Serial.flush();
    }
}

void ClearMarkers(void)
{
    PORTD = SET_BOTH_LOW(MARKER_PORT_ONE, MARKER_PORT_TWO);
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
    char buff[6];
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
                //digitalWrite(MARKER_PORT_ONE, LOW);
                //digitalWrite(MARKER_PORT_TWO, HIGH);
                PORTD = SET_ONEL_TWOH(MARKER_PORT_ONE, MARKER_PORT_TWO);

                buff[0] = Serial.read();
                Serial.flush();

                mySim.StopSimulation();
                
                break;
                
            case 'W':
                //digitalWrite(MARKER_PORT_TWO, LOW);
                //digitalWrite(MARKER_PORT_ONE, LOW);
                PORTD = SET_BOTH_LOW(MARKER_PORT_ONE, MARKER_PORT_TWO);
                
                buff[0] = Serial.read();
                Serial.flush();

                
                mySim.StartSimulation();
                
                initTimer1();
                
                break;
                
            case 'D':
                Serial.readBytes( &buff[0], 6);
                
                /*
                buff[0] = Serial.read();
                cnt = 0;
                
                while(cnt<5) {
                    if(Serial.available()) {
                        buff[cnt] = Serial.read();
                        cnt++;
                    }
                }
                */
                
                r = BytesToLong(&buff[2]);
                Serial.println(buff[1]);
                Serial.println(r);
                SetParameters((unsigned char)(buff[1]), r);
                mySim.N.GetDistParameters(66);
                Serial.print(mySim.N.ParamDistr[0]);

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
