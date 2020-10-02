# Raspi - getting started


## get connected
on RASPI:
edit file:

```
sudo nano /etc/network/interfaces
```
 
~~~
# interfaces(5) file used by ifup(8) and ifdown(8)

# Please note that this file is written to be used with dhcpcd
# For static IP, consult /etc/dhcpcd.conf and 'man dhcpcd.conf'

# Include files from /etc/network/interfaces.d:
source-directory /etc/network/interfaces.d

auto lo
iface lo inet loopback

iface eth0 inet manual

allow-hotplug wlan0
iface wlan0 inet manual
    wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf

allow-hotplug wlan1
iface wlan1 inet manual
    wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf
~~~

```
sudo nano /etc/dhcpcd.conf
```
~~~
# A sample configuration for dhcpcd.
# See dhcpcd.conf(5) for details.

# Allow users of this group to interact with dhcpcd via the control socket.
#controlgroup wheel

# Inform the DHCP server of our hostname for DDNS.
hostname

# Use the hardware address of the interface for the Client ID.
clientid
# or
# Use the same DUID + IAID as set in DHCPv6 for DHCPv4 ClientID as per RFC4361.
#duid

# Persist interface configuration when dhcpcd exits.
persistent

# Rapid commit support.
# Safe to enable by default because it requires the equivalent option set
# on the server to actually work.
option rapid_commit

# A list of options to request from the DHCP server.
option domain_name_servers, domain_name, domain_search, host_name
option classless_static_routes
# Most distributions have NTP support.
option ntp_servers
# Respect the network MTU.
# Some interface drivers reset when changing the MTU so disabled by default.
#option interface_mtu

# A ServerID is required by RFC2131.
require dhcp_server_identifier

# Generate Stable Private IPv6 Addresses instead of hardware based ones
slaac private

interface eth0
static ip_address=192.168.62.104/24
static routers=192.168.62.104
static domain_name_servers=192.168.62.104

# A hook script is provided to lookup the hostname if not set by the DHCP
# server, but it should not be run by default.
nohook lookup-hostname

~~~

```
sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```

~~~
country=AT
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1

network={
        ssid="FORTI_INTERNET"
        psk="HTLInternet"
}
network={
        ssid="A1-AF5137"
        key_mgmt=NONE
}

~~~


on PC:  
	* sudo ifconfig eth0 192.168.62.222 up

on PC:  
you can use a bridge from eth0 to wlan0 for internet access
~~~
	# begin ip_forward.sh 
	# sudo ./ip_forward.sh
	# ---------------------------
	sudo iptables --table nat --append POSTROUTING --out-interface wlan0 -j MASQUERADE	
	sudo iptables --append FORWARD --in-interface eth0 -j ACCEPT
	echo 1 > /proc/sys/net/ipv4/ip_forward
	# end ip_forward.sh
	# --------------------------
~~~


### login
	ssh -l pi 192.168.62.104
	pwd: raspberry


### which raspi version 
```
cat /proc/cmdline | awk -v RS=" " -F= '/boardrev/ { print $2 }'
```


## install history
~~~
    1  sudo dpkg-reconfigure fbi
    2  ls
    3  sudo mv splash.png /etc/
    4  sudo nano /etc/init.d/asplashscreen
    5  sudo chmod a+x /etc/init.d/asplashscreen
    6  sudo insserv /etc/init.d/asplashscreen
    7  ./install.sh 
    8  ls -l /usr/lib/raspi-config/
    9  sudo nano /usr/lib/raspi-config/init_resize.sh 
   10  sudo dpkg-reconfigure ssh
   11  sudo dpkg-reconfigure openssh-server 
   12  sudo nano /usr/lib/raspi-config/init_resize.sh 
   15  sudo rm -v /etc/ssh/ssh_host_*
   16  sudo dpkg-reconfigure openssh-server 
   17  sudo reboot
   18  sudo nano /etc/motd 
   21  sudo service dhcpcd status
   22  sudo nano /etc/dhcpcd.conf
   23  sudo service dhcpcd restart 
   24  ifconfig 
   25  sudo reboot
   29  gcc
   30  g++
   31  javac
   32  more install.sh 
   39  cd /etc/wpa_supplicant/
   40  sudo nano wpa_supplicant.conf 
   41  sudo ifdown wlan0
   42  sudo ifup wlan0
   43  ifconfig
~~~

Hier noch die Datei *install.sh*:
~~~
#!/bin/sh
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install pi4j
sudo apt-get install qt5-default qtcreator qttools5-dev-tools qt5-doc 
sudo apt-get install openSSL
sudo apt-get install pgp
~~~


## install wiringPI
[install wiringPI] (http://www.raspberrypi-tutorials.de/software/wiringpi-auf-dem-raspberry-pi-installieren.html)

```bash
cd
git clone git://git.drogon.net/wiringPi
cd wiringPi
./build
```

test with
```bash
gpio readall
```
<pre>
 +-----+-----+---------+------+---+-Model B1-+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   0 |   8 |   SDA.1 |   IN | 1 |  3 || 4  |   |      | 5V      |     |     |
 |   1 |   9 |   SCL.1 |   IN | 1 |  5 || 6  |   |      | 0v      |     |     |
 |   4 |   7 | GPIO. 7 |   IN | 1 |  7 || 8  | 1 | ALT0 | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | ALT0 | RxD     | 16  | 15  |
 |  17 |   0 | GPIO. 0 |   IN | 0 | 11 || 12 | 0 | IN   | GPIO. 1 | 1   | 18  |
 |  21 |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |  22 |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | IN   | GPIO. 5 | 5   | 24  |
 |  10 |  12 |    MOSI |   IN | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   9 |  13 |    MISO |   IN | 0 | 21 || 22 | 0 | IN   | GPIO. 6 | 6   | 25  |
 |  11 |  14 |    SCLK |   IN | 0 | 23 || 24 | 1 | IN   | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | IN   | CE1     | 11  | 7   |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+-Model B1-+---+------+---------+-----+-----+
</pre>

Some example:
* Pin 1 3.3V
* Pin 2 5V
* Pin 4 5V
* Pin 6 0V GND
* Pin22 GPIO25
* Pin13 GPIO21

