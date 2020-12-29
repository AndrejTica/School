// GET MAC Address

#include "WiFi.h"

#define WIFI_SSID "FORTI_INTERNET"
#define WIFI_PASSWORD "PASSWORD"

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to WiFi..");
  Serial.println("Mac: " + WiFi.macAddress());
  Serial.println("IP:  " + WiFi.localIP().toString());
}

void loop() {}
