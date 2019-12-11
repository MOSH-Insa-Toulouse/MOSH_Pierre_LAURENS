#include <RadioHead.h>
#include <radio_config_Si4460.h>
#include <RHGenericDriver.h>
#include <RHGenericSPI.h>
#include <RHHardwareSPI.h>
#include <RHSPIDriver.h>
#include <RH_RF95.h>

#include <SPI.h> //bibliothèque de communication SPI



 
#define RFM95_CS 10 //broche Shield Lora sur Arduino MEGA
#define RFM95_RST 9 //broche Shield Lora sur Arduino MEGA
#define RFM95_INT 2 //broche Shield Lora sur Arduino MEGA
 

#define RF95_FREQ 868 //fréquence de travail Shield LoRa, peut être changer en 433 ou 916 en fonction de l'usage
 
RH_RF95 rf95(RFM95_CS, RFM95_INT); // Shield LoRa détermination des broche de communication
 

#define LED 13 // Led clignotante récéption


void setup()
{

 
  pinMode(LED, OUTPUT);     
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);
 
  while (!Serial);
  Serial.begin(9600); // Vitesse de Commuication pour ce shield
  delay(100);
 
  Serial.println("Arduino LoRa Récépteur");
 
  //Séquence de reset
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);
 
  while (!rf95.init()) {
    Serial.println("LoRa signal en erreur");//Erreur de programmetion vérifier la fréquence, la tension, le paramétrage broche
    while (1);
  }
  Serial.println("LoRa signal initialise"); // tout va bien
 
 // Si la fréquence est incorrect
  if (!rf95.setFrequency(RF95_FREQ)) {
    Serial.println("Mauvaise frequence ?");
    while (1);
  }
  Serial.print("Set Freq to: "); Serial.println(RF95_FREQ); // Juste une information de la fréquence
 

 
  //rf95.setTxPower(23, false);
}
 
void loop()
{
 

  if (rf95.available())
  {
    // Récéption d'un message ?
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
   
    if (rf95.recv(buf, &len))
    {
      digitalWrite(LED, HIGH);
      RH_RF95::printBuffer("Reçu :  ", buf, len);
      Serial.print("Got: ");
      Serial.println((char*)buf);
   
       Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);
     
      // Send a reply
      uint8_t data[] = "Message retour :  ";
      rf95.send(data, sizeof(data));
      rf95.waitPacketSent();
      Serial.println("Envoye de la réponse");
      digitalWrite(LED, LOW);
    }
    else
    {
      Serial.println("Envoie echoué");
    }
  }

 
}
