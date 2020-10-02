# Raspi-electrical sockets


## RF transmitter module
links:
* [electrical socket1] (http://alexbloggt.com/funksteckdosen-raspberry-pi-teil1/)
* [electrical socket2] (http://www.pcwelt.de/ratgeber/Funksteckdosen_mit_dem_Raspberry_Pi_einrichten-Schalten___walten-8655824.html)
* [buy a RF transmitter] (http://www.dx.com/p/433mhz-rf-transmitter-module-receiver-module-link-kit-for-arduino-arm-mcu-wl-green-220194#.VNzb97s-qRs)


modul:

	| Sender  | Raspberry Pi
	|---------|-------------
	| ANT*    |
	| GND     | GND (Pin 6)
	| DATA    | GPIO17 (Pin 11)
	| VCC     | 5V (Pin 4)

install:
```bash
cd
git clone git://github.com/xkonni/raspberry-remote.git
cd raspberry-remote
make send
```

test:
```bash
sudo ./send <Hauscode> <Steckdosennummer> <Zustand 1 AN, 0 AUS>
sudo ./send 11111 1 1
sudo ./send 11111 1 0
```

### conrad Funksteckdose
Die Conrad Steckdosen sind folgendermaßen Codiert:

1. 4 Bits Gruppenadresse + 
1. 4 Bits Steckdosenadresse + 
1. 1 ungenutzter Adress Bit (= "0") + 
1. 1 ungenutzer Daten Bit (= "0") + 
1. 2 Daten/Befehls Bits (On = “FF” bzw. Off = "F0") + 
1. 1 Sync Bit (="0")

Gruppenadressen:
* Gruppenadresse I = "0FFF"
* Gruppenadresse II = "F0FF"
* Gruppenadresse III = "FF0F"
* Gruppenadresse IV = "FFF0"

Steckdosen:
* Steckdose 1 = “0FFF”
* Steckdose 2 = “F0FF”
* Steckdose 3 = “FF0F”
* Steckdose 4 = “FFF0″

Beispiel: GerätGruppe I und Steckdose 1
* 0FFF0FFF00**FF**0   **ein**schalten
* 0FFF0FFF00**F0**0   **aus**schalten


### lab: send-conrad.c
Based on *send.cpp* write *send-conrad.cpp*.

Programmaufruf:
```
sudo ./send-conrad I 1 on
	-> 0FFF0FFF00FF0
sudo ./send-conrad I 1 off
	-> 0FFF0FFF00F00

sudo ./send-conrad I 2 on
	-> 0FFFF0FF00FF0
sudo ./send-conrad I 2 off
	-> 0FFFF0FF00F00

sudo ./send-conrad I 3 on
	-> 0FFFFF0F00FF0
sudo ./send-conrad I 3 off
	-> 0FFFFF0F00F00
```

## ssh - executing remote commands
we want execute our send commands without login into our raspi.
This can be performed by the use of ssh

```
ssh pi@192.168.62.150 "sudo /home/pi/send-conrad I 3 on"
```

if you want to execute these commands without entering your password,
look 


## remote login without password
[ssh login]: http://linuxproblem.org/art_9.html

soure: [ssh login]

### Your aim
You want to use Linux and OpenSSH to automate your tasks. Therefore you need an
**automatic login** from host A / user a to Host B / user b. You don't want to 
enter any passwords, because you want to call ssh from a within a shell script.

### How to do it
First log in on A as user a and generate a pair of authentication keys. 
Do **not enter a passphrase**:


```bash
a@A:~> ssh-keygen -t rsa
Generating public/private rsa key pair.
Enter file in which to save the key (/home/a/.ssh/id_rsa): 
Created directory '/home/a/.ssh'.
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/a/.ssh/id_rsa.
Your public key has been saved in /home/a/.ssh/id_rsa.pub.
The key fingerprint is:
3e:4f:05:79:3a:9f:96:7c:3b:ad:e9:58:37:bc:37:e4 a@A
```

Now use ssh to create a directory ~/.ssh as user b on B. 
(The directory may already exist, which is fine):

```
a@A:~> ssh b@B mkdir -p .ssh
b@B's password: 
```

Finally append a's new public key to b@B:.ssh/authorized_keys and enter 
b's password one last time:

```
a@A:~> cat .ssh/id_rsa.pub | ssh b@B 'cat >> .ssh/authorized_keys'
b@B's password: 
```
From now on you can log into B as b from A as a without password:
```
a@A:~> ssh b@B
```
A note from one of our readers: Depending on your version of SSH you might 
also have to do the following changes: 
* Put the public key in .ssh/authorized_keys2 
* Change the permissions of .ssh to 700 
* Change the permissions of .ssh/authorized_keys2 to 640

## lab: UI with zenity
write a zenity script on your host to control (via raspi) your electrical 
yout sockets remotely:

> hint: man zenity

	Control electrical sockets:
	socket 1|on|off
	socket 2|on|off
	socket 3|on|off

