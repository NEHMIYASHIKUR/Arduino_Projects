int redpin=10;
int yellowpin=8;
int redblink;
int yellowblink;
int redon=500;
int redoff=300;
int yellowon=700;
int yellowoff=100;
int redx;
int redvol;
int yellowvol;
int greenpin=6;
int greenblink;
int greenon=500;
int greenoff=300;

void setup() {
  
  Serial.begin(9600);
  pinMode(redpin,OUTPUT);
  pinMode(yellowpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  
  Serial.println("how many times should z green light blink ??");
  while(Serial.available()==0){}
  greenblink=Serial.parseInt(); 

  
  Serial.println("how many times should z red light blink ??");
  while(Serial.available()==0){}
  redblink=Serial.parseInt(); 

Serial.println("how many times should z yellow light blink ??");
  while(Serial.available()==0){}
  yellowblink=Serial.parseInt();
  

/**Serial.println("choose a voltage for z yellow light");
 while(Serial.available()==0){}
  yellowvol=Serial.parseInt();

   Serial.println("choose a voltage for z red light");
 while(Serial.available()==0){}
  redvol=Serial.parseInt(); **/




}

void loop() {
 // int redx;
  // int redvol=51 * redx;
 Serial.println("the green led is blinking");
 for(int j=0;j<greenblink ;j++    ){
  Serial.println(j);
  digitalWrite(greenpin,HIGH);
  delay(redon);
  digitalWrite(greenpin,LOW);
  delay(redoff); }
  
  Serial.println("the yellow led is blinking");
 for(int j=0; j<yellowblink ;j++){
  Serial.println(j);
  digitalWrite(yellowpin,HIGH);
  delay(yellowon);
  digitalWrite(yellowpin,LOW);
  delay(yellowoff);

  Serial.println("the red led is blinking");
 for(int j=0;j<redblink ;j++    ){
  Serial.println(j);
  digitalWrite(redpin,HIGH);
  delay(redon);
  digitalWrite(redpin,LOW);
  delay(redoff);
  
  } 
  
  }








 

}
