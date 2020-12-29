# howto-nodemcu-arduino.md

<!-- vscode-markdown-toc -->
* 1. [PC: install and config ARDUINO](#PC:installandconfigARDUINO)
* 2. [Erste Programme](#ErsteProgramme)
	* 2.1. [sketch_01_blink](#sketch_01_blink)
	* 2.2. [sketch_02_hello](#sketch_02_hello)
* 3. [RASPI: MQTT - MOSQUITTO](#RASPI:MQTT-MOSQUITTO)
	* 3.1. [install mosquitto](#installmosquitto)
	* 3.2. [test mosquitto](#testmosquitto)
* 4. [ESP8266: MQTT (and Arduino)](#ESP8266:MQTTandArduino)
	* 4.1. [sketch_03_mqtt](#sketch_03_mqtt)
* 5. [RASPI: NODE-RED, NODE-RED-DASHBOARD](#RASPI:NODE-REDNODE-RED-DASHBOARD)
	* 5.1. [read](#read)
	* 5.2. [install node-red](#installnode-red)
	* 5.3. [start node-red](#startnode-red)
	* 5.4. [install node-red-dashboard](#installnode-red-dashboard)
	* 5.5. [install wiring-pi, ...](#installwiring-pi...)
	* 5.6. [start Webbrowser](#startWebbrowser)
* 6. [Projects](#Projects)
	* 6.1. [Project: ESP->RASPI(mqtt,node-red, node-red-dashboard)](#Project:ESP-RASPImqttnode-rednode-red-dashboard)
	* 6.2. [Project: ESP->Funksteckdosen (mqtt,node-red,node-red-dashboard)](#Project:ESP-Funksteckdosenmqttnode-rednode-red-dashboard)
	* 6.3. [Project: ESP and DS18B20 (Temp)](#Project:ESPandDS18B20Temp)
	* 6.4. [ Project: ESP->RASPI(mqtt,node-red)->volkszaehler.org](#Project:ESP-RASPImqttnode-red-volkszaehler.org)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

* http://www.instructables.com/id/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/


##  1. <a name='PC:installandconfigARDUINO'></a>PC: install and config ARDUINO
------------------------------------------------------------------------------
	* download: https://www.arduino.cc/en/main/software
	* Menue->Datei->Voreinstellungen:
		* http://arduino.esp8266.com/stable/package_esp8266com_index.json
	* Tools->BoardManager->esp8266->install
	* nodemcu-1.0-ESP 12E auswählen
	* port /dev/ttyUSB0
	* Baud: 115200
	* Serieller Monitor starten



##  2. <a name='ErsteProgramme'></a>Erste Programme 
------------------------------------------------------------------------------

###  2.1. <a name='sketch_01_blink'></a>sketch_01_blink
------------------------------------------------------------------------------

~~~
// http://arduino-er.blogspot.co.at/2016/03/blink-nodemcu-on-board-led-using.html
/*
 ESP8266 Blink by Simon Peter
 Blink the blue LED on the ESP-01 module
 This example code is in the public domain

 The blue LED on the ESP-01 module is connected to GPIO1
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)

 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
#include <Arduino.h>

// -----------------------------------------------------------------------------------
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}


// -----------------------------------------------------------------------------------
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}

~~~


###  2.2. <a name='sketch_02_hello'></a>sketch_02_hello
------------------------------------------------------------------------------

~~~
// sketch_02_hello
// ahofmann, 2017

#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  delay(1000);
  Serial.println("Hello World!");
}
~~~



##  3. <a name='RASPI:MQTT-MOSQUITTO'></a>RASPI: MQTT - MOSQUITTO
------------------------------------------------------------------------------
* http://www.switchdoc.com/2016/02/tutorial-installing-and-testing-mosquitto-mqtt-on-raspberry-pi/

###  3.1. <a name='installmosquitto'></a>install mosquitto
~~~
sudo wget http://repo.mosquitto.org/debian/mosquitto-repo.gpg.key
sudo apt-key add mosquitto-repo.gpg.key
cd /etc/apt/sources.list.d/
sudo wget http://repo.mosquitto.org/debian/mosquitto-jessie.list
sudo apt-get update
sudo apt-get install mosquitto mosquitto-clients python-mosquitto
~~~

###  3.2. <a name='testmosquitto'></a>test mosquitto
~~~

terminal 1: (subscribe to topic "testTopic")
	mosquitto_sub -h RASPI_IP -t testTopic

terminal 2: (publish to topic "testTopic")
	mosquitto_pub -h RASPI_IP -t testTopic -m "hello,world!"

~~~



##  4. <a name='ESP8266:MQTTandArduino'></a>ESP8266: MQTT (and Arduino)
---------------------------------------------------------------------------
* install: PubSubClient mit dem Paket Installer
	* Menue->Sketch->Bibliothek einbinden/verwalten->PubSub->install


###  4.1. <a name='sketch_03_mqtt'></a>sketch_03_mqtt
------------------------------------------------------------------------------
~~~
Überblick: PC-ESP-RASPI

   PC -  (arduino) --------->sketch_03_mqtt.ino ----------> ESP8266
    |
  (console/Qt)
    |
    |
    |
  RASPI (=mosquitto-server)


Testen
mosquitto_pub -h RASPI_IP -t /esp/to -m ledon
mosquitto_pub -h RASPI_IP -t /esp/to -m ledoff

bzw.:

mosquitto_sub -h RASPI_IP -t /esp/from 

~~~

~~~
// sketch_03_mqtt.ino
// 
// ahofmann, 2017
//
// http://platformio.org/lib/show/89/PubSubClient/examples?file=mqtt_esp8266.ino
// http://pubsubclient.knolleary.net/api.html
//

/*
TEIL I: ESP subscribes to topic /esp/to und schaltet die LED ein/aus
--------------------------------------------------------------------
topic: /esp/to
message: ledon | ledoff

testen mit:
mosquitto_pub -h test.mosquitto.org -t /esp/to -m ledon
mosquitto_pub -h test.mosquitto.org -t /esp/to -m ledoff


TEIL II: ESP publishes to topic /esp/from every 5 sec a random number between 0 and 50
---------------------------------------------------------------------------------------
topic: /esp/from

test with:
mosquitto_sub -h test.mosquitto.org -t /esp/from


*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h> //mqtt

#include <string>
#include <sstream>
#include <cstdlib> //rand()
using namespace std;


//const char* ssid = "A1-AF5137";
//const char* password = "********";
const char* ssid = "FORTI_INTERNET";
const char* password = "HTLInternet";

const char* mqtt_server= "test.mosquitto.org";
//const char*  mqtt_server= "10.0.0.2";
//const char*  mqtt_server= "172.17.9.163";  // u01
const int mqtt_port= 1883;


// WIFI and MQTT clients
WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);



 

// handle message received for subscribed topic /eps/to
void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  // get Message from parameter payload
  std::string m="";
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
    m+= (char)payload[i];
  }
  Serial.println();


  // handle ledon or ledoff
  if (m == "ledon"){
    Serial.println("turning led on ...");
    // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)

    digitalWrite(LED_BUILTIN, LOW);

  }
  else{
    Serial.println("turning led off ...");

    // Turn the LED off by making the voltage HIGH
    digitalWrite(LED_BUILTIN, HIGH);
  }
}


// MQTT reconnect
void reconnect() {
  // Loop until we're reconnected
  while (!mqtt_client.connected()) {
    Serial.println("Attempting MQTT connection...");
    // Attempt to connect, just a name to identify the client

    // OK
    if (mqtt_client.connect(mqtt_server)) {
      Serial.println("MQTT connected...");

      // Once connected, publish an announcement...
      mqtt_client.publish("/esp/from","10");

      // ... and resubscribe
      mqtt_client.subscribe("/esp/to");
      
    } else {
      // NOK
      Serial.print("failed, rc=");
      Serial.print(mqtt_client.state());
      Serial.println(" try again in 5 seconds");

      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup(void){
  // Initialize the LED_BUILTIN pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

// serial
  Serial.begin(115200);

  // -- wifi
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

//connect to MQTT server
  mqtt_client.setServer(mqtt_server, mqtt_port);
  mqtt_client.setCallback(mqtt_callback);
}



void loop() {
  if (! mqtt_client.connected()) {
    reconnect();
  }

  mqtt_client.loop();

  // wait 5 seconds
  delay(5000);

  char sTemp[100];
  sprintf(sTemp,"%i", rand()%51);
  mqtt_client.publish("/esp/from", sTemp);
}

~~~


##  5. <a name='RASPI:NODE-REDNODE-RED-DASHBOARD'></a>RASPI: NODE-RED, NODE-RED-DASHBOARD
---------------------------------------------------------------------------

###  5.1. <a name='read'></a>read
* https://jaxenter.de/baukasten-fuer-das-internet-dinge-13532
* http://noderedguide.com/


###  5.2. <a name='installnode-red'></a>install node-red
* https://nodered.org/docs/hardware/raspberrypi

~~~
update-nodejs-and-nodered
or
bash <(curl -sL https://raw.githubusercontent.com/node-red/raspbian-deb-package/master/resources/update-nodejs-and-nodered)

cd ~/.node-red
npm rebuild
~~~

###  5.3. <a name='startnode-red'></a>start node-red
~~~
node-red-start

or with autostart

sudo systemctl enable nodered.service
~~~


###  5.4. <a name='installnode-red-dashboard'></a>install node-red-dashboard
* [https://github.com/node-red/node-red-dashboard]()
~~~
npm i node-red-dashboard
~~~

###  5.5. <a name='installwiring-pi...'></a>install wiring-pi, ...
* [https://nodered.org/docs/hardware/raspberrypi]()


###  5.6. <a name='startWebbrowser'></a>start Webbrowser
* http://RASPI_PI:1880


##  6. <a name='Projects'></a>Projects
###  6.1. <a name='Project:ESP-RASPImqttnode-rednode-red-dashboard'></a>Project: ESP->RASPI(mqtt,node-red, node-red-dashboard)
TODO


###  6.2. <a name='Project:ESP-Funksteckdosenmqttnode-rednode-red-dashboard'></a>Project: ESP->Funksteckdosen (mqtt,node-red,node-red-dashboard)
* [https://www.youtube.com/watch?v=O_cgfj6SiTY]()

###  6.3. <a name='Project:ESPandDS18B20Temp'></a>Project: ESP and DS18B20 (Temp)
* <http://www.jerome-bernard.com/blog/2015/10/04/wifi-temperature-sensor-with-nodemcu-esp8266/>
* [https://vaasa.hacklab.fi/2016/02/06/esp8266-on-nodemcu-board-ds18b20-arduinoide-thingspeak/]()


###  6.4. <a name='Project:ESP-RASPImqttnode-red-volkszaehler.org'></a> Project: ESP->RASPI(mqtt,node-red)->volkszaehler.org

node-red flow:
~~~
[
    {
        "id": "98542eab.761fd",
        "type": "function",
        "z": "cb443cc5.9b56a8",
        "name": "url-volkszaehler-salzburg",
        "func": "msg.url= 'http://demo.volkszaehler.org/middleware.php/data/98fd2600-b4bb-11e3-afa6-fd34350f1281.json?operation=add&value=' + msg.payload;\nreturn msg;\n",
        "outputs": 1,
        "noerr": 0,
        "x": 149.61666870117188,
        "y": 250.7166748046875,
        "wires": [
            [
                "9781eafd.9931",
                "bc93c746.b9386"
            ]
        ]
    }
]
~~~


