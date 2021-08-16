#include <LiquidCrystal.h>
LiquidCrystal lcd(0,1,8,9,10,11);
int vrx=A0;
int vry=A1;
//int pressed=A2;

int vx;
int vy;



void setup() {
  lcd.begin(16,2);
  pinMode(vrx,INPUT);
  pinMode(vry,INPUT);
  //pinMode(pressed,INPUT_PULLUP);
}

void loop() {
  vx=analogRead(vrx);
  vy=analogRead(vry);
  int x;
  int y;
lcd.print("*");
  if(vx==1023){
    x++;}
  else if(vx==1023){
    y--;
  }
 
   lcd.setCursor(x,y);
}
