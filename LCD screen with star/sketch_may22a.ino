int vrx=A0;
int vry=A1;
int pr=A2;


void setup() {
  Serial.begin(9600);
  pinMode(vrx,INPUT);
  pinMode(vry,INPUT);
  pinMode(pr,INPUT_PULLUP);
}

void loop() {
  int a;
  int b;
 
  int x=analogRead(vrx);
  int y=analogRead(vry);
  Serial.print("*");
  if (x==0){
    a++;
    }
 else if(x==1023){
  a--;
  }
  else if(y==0){
    b++;
    }
  else if(y==1023){
    
    b--;
    }
    Serial.print(a,b);
    
}
