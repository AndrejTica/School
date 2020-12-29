# Raspi-java
[jdk arm]: http://www.oracle.com/technetwork/java/javase/downloads/jdk8-arm-downloads-2187472.html


## install new java version on pi
1. download [jdk arm]. 
2. example: 

```
wget http://download.oracle.com/otn-pub/java/jdk/8u33-b05/jdk-8u33-linux-arm-vfp-hflt.tar.gz
sudo tar -xvf jdk-8-ea-b124-linux-arm-vfp-hflt-17_jan_2014.tar.gz -C /opt
sudo update-alternatives --install /usr/bin/java java /opt/jdk1.8.0/bin/java 1
sudo update-alternatives --set java /opt/jdk1.8.0/bin/java
cd

nano .profile
JAVA_HOME="/opt/jdk1.8.0"
export JAVA_HOME
PATH="$JAVA_HOME/bin:$PATH"

sudo reboot
java -version
javac -version
```



## pi4j framework
> note: pi4j uses wiringPi Pin (wPi) number schema.  
gpio readall


### install
```bash
wget http://get.pi4j.com/download/pi4j-1.0-SNAPSHOT.deb
sudo dpkg -i pi4j-1.0-SNAPSHOT.deb
```


### example: leds
Program: ControlGpioExample.java
* <http://pi4j.com/example/control.html>

watch: yellow traffic-light

```bash
javac -classpath .:classes:/opt/pi4j/lib/'*' -d . ControlGpioExample.java
sudo java -classpath .:classes:/opt/pi4j/lib/'*' ControlGpioExample
```

### example: button-input
Program: ListenGpioExample.java
* <http://pi4j.com/example/listener.html>


```bash
javac -classpath .:classes:/opt/pi4j/lib/'*' -d . ListenGpioExample.java
sudo java -classpath .:classes:/opt/pi4j/lib/'*' ListenGpioExample
```

### lab: further examples
Program: shutdown GPIO
* <http://pi4j.com/example/shutdown.html>



## bluej on Raspi
Links:
* [bluej raspi] (http://www.bluej.org/raspberrypi/)
* [DukePad] (https://wiki.openjdk.java.net/display/OpenJFX/DukePad)
* [pi4j] (http://pi4j.com/)
* [oracle raspi tipps] (http://www.oracle.com/technetwork/articles/java/raspberrypi-1704896.html)

### install: 
```bash
wget http://bluej.org/download/files/bluej-314b.deb
sudo dpkg -i bluej-314b.deb
```

### example: servomotor
[Bluej servomotor] (http://www.bluej.org/raspberrypi/ServoMotor.html)





## java-project: pi-camera
* [pi camera](http://www.rmnd.net/building-an-action-camera-using-a-raspberry-pi-and-java/)




