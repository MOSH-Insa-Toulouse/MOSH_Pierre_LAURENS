/*   Mesure de la temp�rature �  l'aide d'un TMP36  et Affichage sur LCD: MOP-AL162A-BBTW: LCD 2x16   
/* Le montage:  Afficheur LCD  
* LCD RS     - pin 2  
* LCD Enable - pin 3  
* LCD D4     - pin 4  
* LCD D5     - pin 5 
* LCD D6     - pin 6 
* LCD D7     - pin 7 
* LCD R/W    - GND 
* LCD Vo contrast- potentiom�tre 10K (entre Gnd et +5V) 
 
Senseur de temp�rature: 
 * TMP36 Analog Output - Pin A0 (analogique)    */

// include the library code:
 #include <LiquidCrystal.h>
 int tempSensorPin = 0; // Pin analogique pour lecture de la tension de sortie du TMP36 (Vout).                       
 // Resolution: 10 mV / degree celsius avec une offset de 500 mv. // Definition du caractere �
// initialize the library with the numbers of the interface pins 
byte degrees[8] = {   B00000,   B01000,   B10100,   B01000,   B00000,   B00000,   B00000,   B00000, }; 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 

void setup()
{   
  lcd.begin(16, 2);   // set up the LCD's number of columns and rows:  
  lcd.clear();    //efface l'�cran
  lcd.createChar( 0, degrees );// initialiser le caract�re � dans le LCD   
}


int lastTemp = -100; // m�morise la derni�re temp�rature affich�e 

void loop()
{  
  float temp = lectureTemp();      // rafraichit le LCD que si la   // température a varié sensiblement  
  if( abs(temp-lastTemp)<0.20 )     return;   lastTemp = temp;      // Afficher la valeur en évitant le   // lcd.clear(), pour éviter l'effet de   // scintillement.  
  lcd.setCursor(0,0);   
  lcd.print( temp );  
  lcd.write((byte) 0 ); // affiche le signe degré  
  lcd.print( "c" );   // Efface les derniers caractères si   // la température chute subitement  
  lcd.print( " " );      // ne pas rafraichir trop souvent  
  delay(800);
} 

//Description: //  Lecture de la température sur la pin A0 // //Returns: //  La température en degré Celcius. // 
float lectureTemp()
{
  // Lecture de la valeur sur l'entrée analogique  // Retourne une valeur entre 0->1024 pour 0->5v 
  int valeur = analogRead(tempSensorPin);  // Converti la lecture en tension  
  float tension = valeur * 5.0;  tension /= 1024.0;     // Convertir la tension (mv) en temperature 
  float temperature = ((tension * 1000) - 500) / 10;  
  return temperature;
} 
