#include <SoftwareSerial.h>
SoftwareSerial myserial(12,13);

int dist; //actual distance measurements of LiDAR
int angle;
int strength; //signal strength of LiDAR
int check; //save check value
int i;
String together;
int uart[9]; //save data measured by LiDAR
const int HEADER=0x59; //frame header of data package
void setup() {
 Serial.begin(9600); //set bit rate of serial port connecting Arduino with computerPage 3
 myserial.begin(115200); //set bit rate of serial port connecting LiDAR with Arduino
}
void loop() {
   for(int j = 0 ; j<360 ; j+=10)
 { 
 if (myserial.available()) { //check if serial port has data input
 if(myserial.read() == HEADER) { //assess data package frame header 0x59
 uart[0]=HEADER;
 if (myserial.read() == HEADER) { //assess data package frame header 0x59
 uart[1] = HEADER;
 for (i = 2; i < 9; i++) { //save data in array
 uart[i] = myserial.read();
 }
 check = uart[0] + uart[1] + uart[2] + uart[3] + uart[4] + uart[5] + uart[6] + uart[7];
 if (uart[8] == (check & 0xff)){ //verify the received data as per protocol
 dist = uart[2] + uart[3] * 256; //calculate distance value


 angle = j;
 String angle_str = String(angle);
 String dist_str = String(dist);
 together = angle_str + "," + dist_str ;
 delay(500);
 Serial.println(together);
 }
 }
 }
 }
 }
}
