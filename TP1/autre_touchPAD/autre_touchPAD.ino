#include <TouchScreen.h> 
TouchScreen ts = TouchScreen(8, 10, 11, 9);
void setup() { 
  Serial.begin(38400); } 
  void loop() { 
    int coords[2]; 
    ts.read(coords); 
    Serial.print(coords[0]); 
    Serial.print(","); 
    Serial.print(coords[1]);
  if((coords[0] > 696) && (coords[0] < 866) && (coords[1] > 546) && (coords[1] < 831)) { 
    Serial.print(", Fan ON"); } 
    if((coords[0] > 696) && (coords[0] < 866) && (coords[1] > 208) && (coords[1] < 476)) {
      Serial.print(", Fan OFF"); } if((coords[0] > 420) && (coords[0] < 577) && (coords[1] > 540) && (coords[1] < 866)) { 
      Serial.print(", Drapes OPEN"); } if((coords[0] > 420) && (coords[0] < 577) && (coords[1] > 208) && (coords[1] < 476)) {
      Serial.print(", Drapes CLOSE"); } if((coords[0] > 139) && (coords[0] < 327) && (coords[1] > 208) && (coords[1] < 866)) {
      Serial.print(", Illumination:"); 
      Serial.print(constrain(map(coords[1], 318, 756, 0, 100), 0, 100));
      Serial.print("%"); } 
      Serial.println(); 
      delay(100);
}
