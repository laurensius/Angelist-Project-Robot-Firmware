#include <SoftwareSerial.h>
#include <Servo.h>

#define pwm_1 5                                  //Pengatur kecepatan motor_1 (motor kiri)
#define motor_11 6
#define motor_12 7

#define pwm_2 8                                  //Pengatur kecepatan motor_2 (motor kanan)
#define motor_21 9
#define motor_22 10

#define baudrate 9600                              //baudrate default Serial Com DFR Mega

Servo capit;
Servo putar;
Servo bahu_1;
Servo bahu_2;
Servo cam_bawah;
Servo cam_atas;

int in_Int;
int x;

void setup(){
  Serial.begin(baudrate);

  pinMode(pwm_1,OUTPUT);
  pinMode(motor_11,OUTPUT);
  pinMode(motor_12,OUTPUT);
  pinMode(pwm_2,OUTPUT);
  pinMode(motor_22,OUTPUT);
  pinMode(motor_22,OUTPUT);
  
  capit.attach(22);
  putar.attach(24);
  bahu_1.attach(26);
  bahu_2.attach(28);
  cam_atas.attach(31);
  cam_bawah.attach(33);
  
  capit.write(0);
  putar.write(0);
  bahu_1.write(20);
  bahu_2.write(20);
  cam_atas.write(150);
  cam_bawah.write(120);
  
}

void loop(){
  if(Serial.available() > 0){
    in_Int = Serial.read(); 
    char y = (char) in_Int;
    //Serial.print("Data yang diterima dari XBee : ");
    //Serial.println(y);
    //-----------------------
      if(in_Int=='1'){    
        goDepan();
      }else
      if(in_Int=='4'){
        goKiri();
      }else
      if(in_Int=='2'){
        goKanan();
      }else
      if(in_Int=='3'){
        goBelakang();
      }else
      if(in_Int=='5'){
        goStop();
      }else  
      if(in_Int=='u'){
        goAtas();
      }else  
      if(in_Int=='d'){
        goBawah();
      }else  
      if(in_Int=='p'){
        goPlus();
      }else  
      if(in_Int=='m'){
        goMinus();
      }else  
      if(in_Int=='o'){
        goBuka();
      }else  
      if(in_Int=='c'){ 
        goTutup();
      }else
      if(in_Int=='i'){
        goLihatKiri();
      }else
      if(in_Int=='a'){
        goLihatKanan();
      }else
      if(in_Int=='l'){
        goLihatAtas();
      }else
      if(in_Int=='h'){
        goLihatBawah();
      }
  }else{
       
  }
}

void goDepan(){
  analogWrite(pwm_1,255);
  digitalWrite(motor_11,HIGH);
  digitalWrite(motor_12,LOW);
  analogWrite(pwm_2,255);
  digitalWrite(motor_21,HIGH);
  digitalWrite(motor_22,LOW);
}

void goKiri(){
  analogWrite(pwm_1,255);
  digitalWrite(motor_11,LOW);
  digitalWrite(motor_12,HIGH);
  analogWrite(pwm_2,255);
  digitalWrite(motor_21,HIGH);
  digitalWrite(motor_22,LOW);
}

void goKanan(){
  analogWrite(pwm_1,255);
  digitalWrite(motor_11,HIGH);
  digitalWrite(motor_12,LOW);
  analogWrite(pwm_2,255);
  digitalWrite(motor_21,LOW);
  digitalWrite(motor_22,HIGH);
}

void goBelakang(){
  analogWrite(pwm_1,255);
  digitalWrite(motor_11,LOW);
  digitalWrite(motor_12,HIGH);
  analogWrite(pwm_2,255);
  digitalWrite(motor_21,LOW);
  digitalWrite(motor_22,HIGH);
}

void goStop(){
  analogWrite(pwm_1,0);
  digitalWrite(motor_11,LOW);
  digitalWrite(motor_12,LOW);
  analogWrite(pwm_2,0);
  digitalWrite(motor_21,LOW);
  digitalWrite(motor_22,LOW);
}

void goAtas(){
  int curr;
  curr = bahu_1.read();
    while(curr<=80 && Serial.read()!='5'){
    bahu_1.write(curr);
    bahu_2.write(curr);
    curr = bahu_1.read();
    curr++;
    if(curr>=80){
      Serial.println("MAX!");
    }
    delay(50);
  }
  
}

void goBawah(){
  int curr;
  curr = bahu_1.read();
  while(curr>=10 && Serial.read()!='5'){
    bahu_1.write(curr);
    bahu_2.write(curr);
    curr = bahu_1.read();
    curr--;
    if(curr<=10){
      Serial.println("MAX!");
    }
    delay(50);
  }
}

void goBuka(){
  int curr;
  curr = capit.read();
  while(curr>=0 && Serial.read()!='5'){
    capit.write(curr);
    curr = capit.read();
    curr--;//Serial.println(curr);
    if(curr<=0){
      Serial.println("MAX!");
    }
    delay(50);
  }
}

void goTutup(){
  int curr;
  curr = capit.read();
  while(curr<=180 && Serial.read()!='5'){
    capit.write(curr);
    curr = capit.read();
    curr++;//Serial.println(curr);
    if(curr>=180){
      Serial.println("MAX!");
    }
    delay(50);
  }
}

void goPlus(){
  int curr;
  curr = putar.read();
  while(curr<=180 && Serial.read()!='5'){
    putar.write(curr);
    curr = putar.read();
    curr++;//Serial.println(curr);
    if(curr>=180){
      Serial.println("MAX!");
    }
    delay(50);
  }
}

void goMinus(){
  int curr;
  curr = putar.read();
  while(curr>=0 && Serial.read()!='5'){
    putar.write(curr);
    curr = putar.read();
    curr--;//Serial.println(curr);
    if(curr<=0){
      Serial.println("MAX!");
    }
    delay(50);
  }
}

void goLihatKiri(){
  int curr;
  curr = cam_bawah.read();
  while(curr>=0 && Serial.read()!='5'){
    cam_bawah.write(curr);
    curr = cam_bawah.read();
    curr--;//Serial.println(curr);
    if(curr<=0){
      Serial.println("MAX!");
    }
    delay(50);
  }
}

void goLihatKanan(){
  int curr;
  curr = cam_bawah.read();
  while(curr<=180 && Serial.read()!='5'){
    cam_bawah.write(curr);
    curr = cam_bawah.read();
    curr++;
    //Serial.println(curr);
    if(curr>=180){
      Serial.println("MAX!");
    }
    delay(50);
  }
}

void goLihatAtas(){
  int curr;
  curr = cam_atas.read();
  while(curr>=60 && Serial.read()!='5'){
    cam_atas.write(curr);
    curr = cam_atas.read();
    curr--;//Serial.println(curr);
    if(curr<=60){
      Serial.println("MAX!");
    }
    delay(50);
  }
}

void goLihatBawah(){
  int curr;
  curr = cam_atas.read();
  while(curr<=180 && Serial.read()!='5'){
    cam_atas.write(curr);
    curr = cam_atas.read();
    curr++;//Serial.println(curr);
    if(curr>=180){
      Serial.println("MAX!");
    }
    delay(50);
  }
}

