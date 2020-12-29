// esp32 pico htl

#include <Arduino.h>

#define PORT_LED0 14
#define PORT_LED1 27
#define PORT_LED2 32
#define PORT_LED3 33

void setup() {
  pinMode(PORT_LED0, OUTPUT);
  pinMode(PORT_LED1, OUTPUT);
  pinMode(PORT_LED2, OUTPUT);
  pinMode(PORT_LED3, OUTPUT);
  
  Serial.begin(115200);
  Serial.println("setup");
}

void loop() {
  Serial.println("------------");
  Serial.println("PORT_LED0 14");
  Serial.println("PORT_LED1 27");
  Serial.println("PORT_LED2 32");
  Serial.println("PORT_LED3 33");
  
  digitalWrite(PORT_LED0, HIGH);
  digitalWrite(PORT_LED1, HIGH);
  digitalWrite(PORT_LED2, HIGH);
  digitalWrite(PORT_LED3, HIGH);
  
  
  delay(1000);// 1s wait
  digitalWrite(PORT_LED0, LOW);
  digitalWrite(PORT_LED1, LOW);
  digitalWrite(PORT_LED2, LOW);
  digitalWrite(PORT_LED3, LOW);
  
  delay(1000);// 1s wait
}
