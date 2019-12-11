int ledPin=13;// LED connected to digital pin 13


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);// initialize the digital pin as an output:
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(1000); // set the LED on delay(1000);
  digitalWrite(ledPin, LOW);// wait for a second digitalWrite(ledPin, LOW);
  delay(1000);// set the LED off delay(1000);
  // wait for a second

}
