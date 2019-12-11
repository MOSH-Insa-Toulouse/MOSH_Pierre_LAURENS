int ledPin=  13;    // LED connected to digital pin 13


void setup() {
  // put your setup code here, to run once:
  // opens serial port, sets data rate to 9600 bps 
  Serial.begin(9600); // initialize the digital pin as an output: 
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);   // set the LED on Serial.print("LED Status: ON\n"); 
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off Serial.print("LED Status: OFF\n"); 
  delay(1000);                  // waitfor a second
  Serial.println("Arduino, pour te servir!!!!");
}
