/*
 * Author: JP Meijers
 * Date: 2016-02-07
 * Previous filename: TTN-Mapper-TTNEnschede-V1
 *
 * This program is meant to be used with an Arduino UNO or NANO, conencted to an RNxx3 radio module.
 * It will most likely also work on other compatible Arduino or Arduino compatible boards, like The Things Uno, but might need some slight modifications.
 *
 * Transmit a one byte packet via TTN. This happens as fast as possible, while still keeping to
 * the 1% duty cycle rules enforced by the RN2483's built in LoRaWAN stack. Even though this is
 * allowed by the radio regulations of the 868MHz band, the fair use policy of TTN may prohibit this.
 *
 * CHECK THE RULES BEFORE USING THIS PROGRAM!
 *
 * CHANGE ADDRESS!
 * Change the device address, network (session) key, and app (session) key to the values
 * that are registered via the TTN dashboard.
 * The appropriate line is "myLora.initABP(XXX);" or "myLora.initOTAA(XXX);"
 * When using ABP, it is advised to enable "relax frame count".
 *
 * Connect the RN2xx3 as follows:
 * RN2xx3 -- Arduino
 * Uart TX -- 10
 * Uart RX -- 11
 * Reset -- 12
 * Vcc -- 3.3V
 * Gnd -- Gnd
 *
 * If you use an Arduino with a free hardware serial port, you can replace
 * the line "rn2xx3 myLora(mySerial);"
 * with     "rn2xx3 myLora(SerialX);"
 * where the parameter is the serial port the RN2xx3 is connected to.
 * Remember that the serial port should be initialised before calling initTTN().
 * For best performance the serial port should be set to 57600 baud, which is impossible with a software serial port.
 * If you use 57600 baud, you can remove the line "myLora.autobaud();".
 *
 */
#include <rn2xx3.h>
#include <SoftwareSerial.h>

//définition des PINs
#define potentiometrePin A0
#define GazSensorPin A1

//initialisation de la valeur du potentiometre
int Pot;
int Pot_ancienne = 0;
int GazSensor;

//Initialisation de la led
int led=13;
//Initialisation de la variable de la led qui permet d'envoyer le bon rapport cyclique à la led
int val_led;

SoftwareSerial mySerial(10, 11); // RX, TX

//create an instance of the rn2xx3 library,
//giving the software serial as port to use
rn2xx3 myLora(mySerial);

// the setup routine runs once when you press reset:
void setup()
{
  //output LED pin
  pinMode(13, OUTPUT);
  led_on();

  pinMode(potentiometrePin, INPUT);
  pinMode(GazSensorPin, INPUT);

  //attachInterrupt(0, envoiData, RISING); 

  // Open serial communications and wait for port to open:
  Serial.begin(57600); //serial port to computer
  mySerial.begin(9600); //serial port to radio
  Serial.println("Startup");

  initialize_radio();

  //transmit a startup message
  myLora.tx("TTN Mapper on TTN Enschede node");

  led_off();
  delay(20);
}

/*int envoiData(int Pot, int Pot_ancienne, int led, int val_led){
  if((Pot_ancienne > Pot+10) || (Pot_ancienne < Pot-10)){
    Serial.println(Pot);  
    led_on();
    myLora.tx(Pot); //one byte, blocking function
    //val_led = map(Pot,0,1023,0,255);
    led_off();    
    analogWrite(led, val_led);    
    Pot_ancienne = Pot;
  }else{
     Serial.println("Pas de changement");
  }
  return Pot_ancienne;
  
}*/

void initialize_radio()
{
  //reset rn2483
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  delay(500);
  digitalWrite(12, HIGH);

  delay(1000); //wait for the RN2xx3's startup message
  mySerial.flush();

  //Autobaud the rn2483 module to 9600. The default would otherwise be 57600.
  myLora.autobaud();

  //check communication with radio
  String hweui = myLora.hweui();
  while(hweui.length() != 16)
  {
    Serial.println("Communication with RN2xx3 unsuccessful. Power cycle the board.");
    Serial.println(hweui);
    delay(10);
    hweui = myLora.hweui();
  }

  //print out the HWEUI so that we can register it via ttnctl
  Serial.println("When using OTAA, register this DevEUI: ");
  Serial.println(myLora.hweui());
  Serial.println("RN2xx3 firmware version:");
  Serial.println(myLora.sysver());

  //configure your keys and join the network
  Serial.println("Trying to join TTN");
  bool join_result = false;


  /*
   * ABP: initABP(String addr, String AppSKey, String NwkSKey);
   * Paste the example code from the TTN console here:
   */
const char *devAddr = "26011665";
const char *nwkSKey = "6ECAEDF845E8EA3E0E81F46263669E23";
const char *appSKey = "EBFE16A516BEEF67041441D99B0E70D5";

  join_result = myLora.initABP(devAddr, appSKey, nwkSKey);

  /*
   * OTAA: initOTAA(String AppEUI, String AppKey);
   * If you are using OTAA, paste the example code from the TTN console here:
   */
  //const char *appEui = "70B3D57ED00001A6";
  //const char *appKey = "A23C96EE13804963F8C2BD6285448198";

  //join_result = myLora.initOTAA(appEui, appKey);


  while(!join_result)
  {
    Serial.println("Unable to join. Are your keys correct, and do you have TTN coverage?");
    delay(60000); //delay a minute before retry
    join_result = myLora.init();
  }
  Serial.println("Successfully joined TTN");

}

// the loop routine runs over and over again forever:
void loop()
{
    // Lire la valeur du potentiomètre
    int Pot = analogRead(potentiometrePin);
    delay(100);
    int GazSensor= analogRead(GazSensorPin);

    //fonction qui gère l'envoi que si 
    //Pot_ancienne = envoiData(Pot, Pot_ancienne, led, val_led);  
    char str[4];
    str[0] =(Pot >> 8) & 0xFF;
    str[1] = Pot & 0xFF;
    str[2] = (GazSensor >> 8) & 0xFF;
    str[3] = GazSensor & 0xFF;

    Serial.print("value of Potentiomètre: ");
    Serial.println(Pot);
    Serial.print("value of Gaz Sensor: ");
    Serial.println(GazSensor);
    Serial.print("RS/RL= ");
    Serial.println((float)(1023-GazSensor)/GazSensor);

    myLora.txBytes(str, sizeof(str));
    
    delay(200);
}

void led_on()
{
  digitalWrite(13, 1);
}

void led_off()
{
  digitalWrite(13, 0);
}
