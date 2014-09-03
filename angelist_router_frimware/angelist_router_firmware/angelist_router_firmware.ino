#include "SoftwareSerial.h"

#define brx 2
#define btx 3

#define baudrate 9600

int in_Int;
int x;

SoftwareSerial mySS(brx,btx);

void setup(){
  Serial.begin(baudrate);
  mySS.begin(baudrate);  
  pinMode(12,OUTPUT);
}

void loop(){
  Serial.write("hello Xbee-2");
}


