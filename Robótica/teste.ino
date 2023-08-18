#include <Ultrasonic.h>
int distancia;
int pinLED = 8;
Ultrasonic ultrasonic(6,7);
//echo 7
//trig 6

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
}

void loop() {  
  distancia = ultrasonic.read();
  if (distancia <= 15){
    digitalWrite(pinLED, HIGH);
  } else {
    digitalWrite(pinLED, LOW);
  }
}
