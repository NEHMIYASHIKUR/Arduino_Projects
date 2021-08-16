#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,7,6,5,4);

int vrx=A1;
int vry=A0;
int pressed=2;


int xval;
int yval;
int pr;



void setup() {
  lcd.begin(16,2);
  pinMode(vrx,INPUT);
  pinMode(vry,INPUT);
  pinMode(pressed,INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  xval=analogRead(vrx);
  yval=analogRead(vry);
  pr=analogRead(pressed);
  
  int x;
  int y;
  lcd.print("#");
  lcd.setCursor(0,5);
if(xval>900){
  lcd.setCursor(0,7);
      
    }
    
else if (xval<200){
 lcd.print(0,3);
  }
else if(yval>900){
    lcd.setCursor(0,5);
    }
else if(yval<200){
      lcd.setCursor(0,5);
      }
    

  delay(500);
  lcd.clear();
 
}
