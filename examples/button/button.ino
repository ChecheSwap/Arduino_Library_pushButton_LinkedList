
#include <Arduino.h>
#include "determinebitport.h"
#include "xbutton.h"

#define PINLED 3
#define PINLED2 4

void tosend(void);
void tosend2(void);

xbutton btn0(8);

void setup()
{
    pinMode(PINLED,OUTPUT);
	Serial.begin(9600);
    btn0.add("ADDING FOR TEST", tosend);
}

//xbutton btn1(9, "HOLAx", tosend2);

void loop()
{
    btn0.check();
    //btn1.check();
}

void tosend()
{
    if((bitRead((determinebitport(PINLED)),PINLED))==LOW)
    {
        digitalWrite(PINLED,HIGH);
        btn0.setText("CHANGE TO HIGH");
    }
    else
    {
        digitalWrite(PINLED,LOW);
        btn0.setText("CHANGE TO LOW");
    }

}

void tosend2()
{
    if((bitRead((determinebitport(PINLED2)),PINLED2))==LOW)
        digitalWrite(PINLED2,HIGH);
    else
        digitalWrite(PINLED2,LOW);
}
