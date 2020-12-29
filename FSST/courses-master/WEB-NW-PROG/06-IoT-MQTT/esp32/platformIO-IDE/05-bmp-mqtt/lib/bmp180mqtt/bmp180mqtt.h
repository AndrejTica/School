#pragma once

#include <Sodaq_BMP085.h>
#include <Wire.h>

#include <AsyncMqttClient.h>

#include <string>
using namespace std;

class BMP180MQTT {

public:
  BMP180MQTT();
  ~BMP180MQTT();

  void startWifi(string wifi_ssid, string wifi_password);
  float getTemperature(void);
  void publish(string host, int port, string topic, string message);

private:
  Sodaq_BMP085 bmp;
  AsyncMqttClient mqttClient;
};
