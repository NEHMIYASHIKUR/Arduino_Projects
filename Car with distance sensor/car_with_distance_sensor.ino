#include <Servo.h>
int SERVO1_PIN=6;
int SERVO2_PIN=7;

int TriggerPin=26;
int EchoPin=36;

int TriggerPin2=46;
int EchoPin2=40;

int delaynum=200;

Servo myservo;
Servo mymotor;

void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin,OUTPUT);
  pinMode(EchoPin,INPUT_PULLUP); 

  pinMode(TriggerPin2,OUTPUT);
  pinMode(EchoPin2,INPUT_PULLUP); 
  
  myservo.attach(SERVO1_PIN);
  mymotor.attach(SERVO2_PIN);
  mymotor.write(85);
  delay(delaynum);
  mymotor.write(158);
  delay(delaynum);
  
}

void loop() {
   int response;
  digitalWrite(TriggerPin,LOW); 
  delayMicroseconds(10);
  digitalWrite(TriggerPin,HIGH);
  delayMicroseconds(10);
  response=(pulseIn(EchoPin,HIGH)/58);
  Serial.println(response);

     int response2;
  digitalWrite(TriggerPin2,LOW); 
  delayMicroseconds(10);
  digitalWrite(TriggerPin2,HIGH);
  delayMicroseconds(10);
  response2=(pulseIn(EchoPin2,HIGH)/58);
  Serial.println(response2);
  
  mymotor.write(90);
  delay(delaynum);
  myservo.write(108);
  delay(200);

  if(response<80){
      for(int i=0;i<6;i++){
       myservo.write(75);
       delay(1000);
       }


  }

   if(response2<80){
      for(int i=0;i<6;i++){
       myservo.write(108);
       delay(1000);
       }


  }
  
    
      
  
}




