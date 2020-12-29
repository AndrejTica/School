# Raspi - temperature

[] (https://www.modmypi.com/blog/ds18b20-one-wire-digital-temperature-sensor-and-the-raspberry-pi)

## configure
red(=lila)	Pin1
blue		Pin3
gray		Pin7

## install 
The following two commands load the 1-Wire and thermometer drivers on GPIO 4.
```
sudo modprobe w1-gpio
sudo modprobe w1-therm
```

We then need to change directory cd to our 1-Wire device folder and list 
ls the devices in order to ensure that our thermometer has loaded correctly.

```
cd /sys/bus/w1/devices/
ls
```

In the device drivers, your sensor should be listed as a series of numbers 
and letters. In this case, the device is registered as 
28-000005e2fdc3. You then need to access the sensor with the cd command, 
replacing our serial number with your own.

```
cd 28-000005e2fdc3
```

The sensor periodically writes to the w1_slave file, so we simply use the 
cat command to read it.
```
cat w1_slave
```
This yields the following two lines of text, with the output 
t= showing the temperature in degrees Celsius. 
A decimal point should be placed after the first two digits e.g. 
the temperature reading we’ve received is 23.125 degrees Celsius.

72 01 4b 46 7f ff 0e 10 57 : crc=57 YES
72 01 4b 46 7f ff 0e 10 57 t=23125




