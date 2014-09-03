
//-------------------INI ROUTER----------------------
#define baud 9600

void setup(){
  Serial.begin(baud);
}

void loop(){
  if(Serial.available()>0){
    String terima="";
    while(Serial.available()>0){
      int x = Serial.read();
      char y= (char) x;
      terima = terima+y; 
    }
    Serial.print(terima);
  }
}

/*------------INI COORDINATOR
Serial.println("lalalalala");
delay(2000);
if(serial.available()>0){
  digitalwite(12,H);
}
*/
