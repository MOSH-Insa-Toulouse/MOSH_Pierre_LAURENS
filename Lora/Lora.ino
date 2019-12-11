#include <SoftwareSerial.h>


SoftwareSerial mySerial (10,11);
 
void setup(){
 pinMode(12,OUTPUT);
  
 Serial.begin(9600);
 mySerial.begin(57600);
 digitalWrite(12,HIGH);
 delay(20);
 digitalWrite(12,LOW);
 
}

void loop(){

  mySerial.println("sys get ver");
  if(mySerial.available()){
     Serial.print(mySerial.read());
  }
 
  
 /*delay(1000);
 Serial.print(1, BIN);
 delay(1000);*/
}
