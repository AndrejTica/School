// http://docs.platformio.org/en/latest/projectconf/section_env_build.html#build-flags


// mosquitto_sub -h test.mosquitto.org -t iot_esp32/bmp 
#include <Arduino.h>

#include <string>
#include <sstream>
using namespace std;

#include <bmp180mqtt.h>


#define WIFI_SSID "FORTI_INTERNET"
#define WIFI_PASSWORD "PASSWORD"

string HOST = "test.mosquitto.org";
int PORT=1883;
string TOPIC= "iot_esp32/bmp";
string MESSAGE= "{\"sensor\":\"bmp180\","
  "\"name\":\"===ENTER NAME===\","
  "\"latlon\":[47.80949,13.05501],"
  "\"temp\":";


BMP180MQTT bmp;


void setup() {
  Serial.begin(115200);
  bmp.startWifi(WIFI_SSID, WIFI_PASSWORD);
}

void loop() {

  double temperature= bmp.getTemperature();
  ostringstream msg;
  msg << MESSAGE << temperature << "}";
  bmp.publish(HOST,PORT,TOPIC, msg.str() );
  
  delay(10000);
}
