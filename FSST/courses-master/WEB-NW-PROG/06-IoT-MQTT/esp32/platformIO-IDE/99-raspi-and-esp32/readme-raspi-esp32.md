# 1. IoT: raspi and esp32

connecting ESP32 -> RASPI -> INTERNET using these components:

- esp32 pico-kit (htl)
- raspi: debian lite (user: pi/raspberry)
  - mosquitto (running at port: 1883)
  - node-red (running at http://raspi-ip:1880 )
- PC: vscode and platformio-IDE

## 1.1. using esp32 on raspi - quick start

we use: platformio CLI - pico32 (htl)

~~~bash
cd /home/pi/GIT/06-IoT-MQTT/esp32/platformIO-IDE/

1. change to one of the project folder
cd 01-hello  
cd 02-bmp  
cd 03-mqtt  
cd 03-mqtt-pubsubclient  
cd 03-wifi  
cd 04-json  
cd 05-bmp-mqtt  
cd 06-node-red

2. and compile,upload and monitor with
pio run
pio run -t upload
pio run -t monitor
~~~


## 1.2. install: Debian lite

### 1.2.1. networking - overview

1. pc: 192.168.62.222
2. raspi: 192.168.62.104
3. esp32: wlan: FORTI_INTERNET
  
### 1.2.2. networking - config - raspi
- /etc/dhcpcd.conf

~~~bash
# It is possible to fall back to a static IP if DHCP fails:
# define static profile
profile static_eth0
static ip_address=192.168.62.104/24
static routers=192.168.62.222
static domain_name_servers=192.168.62.222

# fallback to static profile on eth0
interface eth0
fallback static_eth0
~~~

- /etc/wpa_supplicant/wpa_supplicant.conf

~~~bash
▶ cat wpa_supplicant/wpa_supplicant.conf 
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1


network={
    ssid="FORTI_INTERNET"
    psk="******"
    priority=2
    id_str="htl forti_internet"
}

network={
    ssid="HTL_INTERNET"
    psk="*******"
    priority=2
    id_str="htl htl_internet"
}
~~~

### 1.2.3. enable ssh and upgrade

~~~bash
sudo touch /boot/ssh (to enable ssh)
sudo route del default (if using 192.168.62.104)
sudo apt update
sudo apt upgrade
~~~

### 1.2.4. build tools

~~~ bash
sudo apt install git build-essential cmake
~~~

## 1.3. install: mosquitto

~~~ bash
sudo apt install mosquitto mosquitto-clients

sudo systemctl enable mosquitto.service
~~~

### 1.3.1. using mosquitto-clients

~~~bash
change below 'channel' with your preferred topic name.

Terminal 1:
mosquitto_sub -d -t channel

Terminal 2:
mosquitto_pub -d -t channel -m "Hello from Terminal 2!"
~~~

## 1.4. install: node

~~~ bash
mkdir bin
cd bin
tar xJf node...

add to ~/.profile
PATH="$HOME/bin/node/bin:$PATH"
~~~

## 1.5. install: node-red

~~~bash
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)


node-red-start
http://<hostname>:1880


sudo systemctl enable nodered.service
sudo systemctl disable nodered.service
~~~

## 1.6. install: platformio CLI

~~~bash
sudo python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"
~~~

### 1.6.1. install: 99-platformio-udev.rules

~~~bash
curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core/master/scripts/99-platformio-udev.rules | sudo tee /etc/udev/rules.d/99-platformio-udev.rules


sudo usermod -a -G dialout $USER
sudo usermod -a -G plugdev $USER

~~~

## 1.7. use: platformio CLI - general

~~~bash
pio boards pico32

pio device list
pio device monitor

//Build project: cd project-folder
pio run
pio run -t upload
pio run -t monitor


//Build specific environment
platformio run -e pico32

//Upload firmware for the specific environment
platformio run -e pico32 --target upload

//Clean build files
platformio run -t clean
~~~

## 1.8. PC: vscode: remote fs and remote ssh

- install extension: remote fs and remote ssh
