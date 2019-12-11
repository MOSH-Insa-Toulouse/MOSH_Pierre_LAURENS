int incomingByte= 0; // for incomingserial data
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// opens serial port, sets data rate to 9600 bps 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) { 
    // readthe incomingbyte:
    incomingByte= Serial.read();

    // say what you got: 
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC); }

}
