#include <Arduino.h>
#include <Wire.h>

#define peri_addr 9

int LED = 2;

int receivedData; // Val de reception de la donnée mappé du controler
int vitesseBlink; // Val vitesse de blink

// fonction à exécuter lorsque des données sont reçues du periphérique
void receiveEvent(int bytes) {
  receivedData = Wire.read();    // lire un caractère à partir de l'I2C qui sera entre 1-255
}

void setup() {
  
  pinMode (LED, OUTPUT);

  // Démarrer le bus I2C comme periphérique à l'adresse 9
  Wire.begin(peri_addr); 

  // Attachez une fonction qui se déclenche lorsque une donée est reçue
  Wire.onReceive(receiveEvent);

  Serial.begin(9600);
  
}

void loop() {

  delay(50);

  // Calcul valeur de vitesse de blink entre 100 et 2000 ms
  vitesseBlink = map(receivedData, 1, 255, 100, 2000);

  digitalWrite(LED, HIGH);
  delay(vitesseBlink);
  digitalWrite(LED, LOW);
  delay(vitesseBlink);

}