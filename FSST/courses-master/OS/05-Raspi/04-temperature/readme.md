# Raspi - temperature

[https://www.modmypi.com/blog/ds18b20-one-wire-digital-temperature-sensor-and-the-raspberry-pi]()

## configure
~~~
* red(=lila)       - Pin1 (3V3)
* blue (GND,VDD)   - Pin3/25 (GND)
* gray (DQ)        - Pin4 (GPIO4)
~~~

## install 
* [http://www.netzmafia.de/skripten/hardware/RasPi/Projekt-Onewire/]()
* [https://www.kompf.de/weather/pionewiremini.html]( )

* [https://wiki.fhem.de/wiki/Raspberry_Pi_und_1-Wire]()

* http://fluuux.de/2016/04/raspberry-pi-ds1820-temperatursensoren-auslesen/

 "... Ab Kernelversion 3.18 wird für das Einsetzen der Module der sogenannte Device Tree verwendet. Ab dann wird die One-Wire-Schnittstelle in der Datei **/boot/config.txt** aktiviert, indem dort zwei Zeilen eingetragen werden:

```
dtoverlay=w1-gpio,gpiopin=4,pullup=on
```


## get temperature - shell
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



## lab: getTemperature.c
Write a program to get the actual room temperature. As argument one
give a time in seconds for periodically output of the temperature.
```
./getTemperature.exe 1
```



## lab: sendTemperature.c (volkszaehler)
1. create a channel on http://demo.volkszaehler.org/frontend/
2. Write a program to send your actual room temperature to your channel.

```
./sendTemperature.exe 1
```

Hint: send temperature 15 to channel 98fd2600-b4bb-11e3-afa6-fd34350f1281
```c
system("wget \"http://demo.volkszaehler.org/middleware.php/data/98fd2600-b4bb-11e3-afa6-fd34350f1281.json?operation=add&value=15\" --delete-after");
```

1. abbonieren Sie den öffentlichen Kanal
* middleware: Volkszähler Demo
* Kanal: Temperatur Baden



## lab: Volkszähler - curl, grep und awk
Lesen Sie von zamg die Temp-Daten v. Salzburg und schreiben diese in Ihren Kanal.

Gehen Sie dabei folgendermaßen vor:
Versuchen Sie in einem lxterminal folgendes:
```
curl -s -L http://www.zamg.ac.at/ogd|grep Salzburg|awk -F\; '{print $6}'
```

Im Falle, dass Proxy-Angaben nötig sind, fügen Sie folgendes hinzu:
```
curl -x http://tmg-z2.htl.org:8080 --proxy-user USERNAME:PWD -s ….
oder noch besser:
Another solution is to use (maybe the better solution) the ~/.curlrc file (create it if it does not exist) :
proxy = username:password@tmg-z2.htl.org:8080
(http://stackoverflow.com/questions/7559103/how-to-setup-curl-to-permanently-use-a-proxy)
```


Frage: Was bewirkt diese Anweisung?
```
curl -s -L http://www.zamg.ac.at/ogd | grep Salzburg | awk -F";" '{print "curl -s -L \"http://demo.volkszaehler.org/middleware.php/data/98fd2600-b4bb-11e3-afa6-fd34350f1281.json?operation=add&value=" $6 "\""}'
```


Frage: Wie können Sie nun erreichen, dass der output des obigen Befehls als Befehl interpretiert und ausgeführt wird?

> Hinweis: man xargs

Lösung:
```
curl -s -L http://www.zamg.ac.at/ogd | grep Salzburg | awk -F";" '{print "curl -s -L \"http://demo.volkszaehler.org/middleware.php/data/98fd2600-b4bb-11e3-afa6-fd34350f1281.json?operation=add&value=" $6 "\""}' | xargs -0 sh -c
```


### lab: shellscript zamg2vz.sh programmieren
Programmieren Sie das Shellscript zamg2vz.sh, dem Sie als Argument folgendes übergeben:
~~~
	./zamg2vz.sh Salzburg  98fd2600-b4bb-11e3-afa6-fd34350f1281
~~~
Hinweise: 
shellscript und Argumente aus der Kommandozeile
	$1 , $2, ...
awk kann variablen einsetzen
	awk -v uuid=$2


Lösung: zamg2vz.sh
~~~
	# chmod 755 zamg2vz.sh
	# ./zamg2vz.sh Salzburg  98fd2600-b4bb-11e3-afa6-fd34350f1281
	# ./zamg2vz.sh Bregenz  c1b717a0-b5b6-11e3-a58c-ef8aeeeb51dc
	# ./zamg2vz.sh Linz/Hörsching     2cc3ce40-b5b8-11e3-ae7a-c5e4bb8633c9
	# ./zamg2vz.sh Retz            	c803b980-b5b6-11e3-9f74-152449a53762
	# ./zamg2vz.sh Kremsmünster       0684e4a0-b5b8-11e3-a70f-edd61321fe02
	# ./zamg2vz.sh "Wien/Hohe Warte"  c34283a0-b5b6-11e3-a4ac-0b13b97cbac0
	# ./zamg2vz.sh Wien/Schwechat     d54447a0-b5b6-11e3-846a-b7388ef567a1
	# ./zamg2vz.sh Bregenz     	c1b717a0-b5b6-11e3-a58c-ef8aeeeb51dc
	# ./zamg2vz.sh Kufstein        	147578f0-b5b7-11e3-9c82-85cc4f734eef
	# ./zamg2vz.sh Feuerkogel       	1293ac50-b5b8-11e3-8d38-ad9f6f0d5630
	# ./zamg2vz.sh Innsbruck        	c256ebd0-b5b6-11e3-907e-c78475285974
	# ./zamg2vz.sh Patscherkofel   	245dd830-b5b7-11e3-904a-73dde2ae6d47

	curl -s -L http://www.zamg.ac.at/ogd | grep $1 | awk -F";" -v uuid=$2 '{print "curl -s -L \"http://demo.volkszaehler.org/middleware.php/data/" uuid ".json?operation=add&value=" $6 "\""}' | xargs -0 sh -c
~~~

### lab: php script
~~~
<html>
<head>
  <title>Temperatursensoren</title>
  <style type="text/css">
    .box { margin:50px auto; width:800px;}
    .room { line-height:100px;width:500px; float:left; font-size:50pt; color:#009999; }
    .temp { line-height:100px;width:300px; float:left; font-size:50pt; color:#green; }
    .shadow { text-shadow: 0 0 5px #123; }
  </style>
</head>
<body>
 
<?php
#Mit folgender Zeile kann man die Verzeichnisse der angeschlossenen Sensoren auslesen
#Für jeden Sensor der angeschlossen wird, wird automatisch ein Unterverzeichnis erstellt
#cat /sys/bus/w1/devices/w1_bus_master1/w1_master_slaves
 
 
$sensors = array("Wohnzimmer"=>"28-000003beaee3",
                "Schlafzimmer"=>"10-000802573877");
 
 
foreach ($sensors as $room => $directory)
{
  $temp = exec('cat /sys/bus/w1/devices/'.$directory.'/w1_slave |grep t=');
  $temp = explode('t=',$temp);
  $temp = $temp[1] / 1000;
  $temp = round($temp,2);
  $temp = number_format($temp,1,',','.');
 
  echo "<div class=\"box\">";
  echo "<div class=\"room\">".$room.":</div>\n";
  echo "<div class=\"temp shadow\"> ". $temp . " °C</div>\n";
  echo "<div style=\"clear:both;\"></div>\n";
  echo "</div>";
}
?>
</body>
</html>
~~~
