#include "SoftwareSerial.h"

#define brx 8
#define btx 9
#define baud 9600
#define indikator 12
SoftwareSerial mySS(8,9);

int x,xx,in_Int;
char y;

char library[]={'1','2','3','4','5',
                'u','d','p','m','o',
                'c','i','a','l','h',};
                
void setup(){
  Serial.begin(baud);
  mySS.begin(baud);
}

void loop(){
  if(mySS.available()>0){
    x = mySS.read();
    char y = (char) x;
    for(int q=0;q<15;q++){
      if(library[q]==y)
      Serial.println(y);
    }
  }
  //------------------------------------
  if(Serial.available()>0){
    String terima="";
    while(Serial.available()>0){
      in_Int = Serial.read(); 
      char y = (char) in_Int;
      terima=terima+""+y;
    }  
    mySS.println(terima);
  }
}
