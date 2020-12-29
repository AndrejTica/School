# aircrack-ng
---

* https://www.wardriving-forum.de/wiki/Aircrack-Tutorial/WEP_mit_Client


## WiFi security:

> __Monitoring:__ Packet capture and export of data to text files for further processing by third party tools.
**Attacking:** Replay attacks, deauthentication, fake access points and others via packet injection.
**Testing:** Checking WiFi cards and driver capabilities (capture and injection).
**Cracking:** WEP and WPA PSK (WPA 1 and 2).

## a typical session for Cracking

### Monitor Mode: 
```sudo airmon-ng start wlan0```

```iwconfig```


### Dump: ```sudo airodump-ng wlan0mon```


> BSSID = MAC-Adresse des Access-Point
PWR = Signalstärke
RXQ = RXQ ist einer von airodump berechneter Wert, das Maximum liegt bei 100
Beacons = Daran kann man erkennen ob der Empfang gut oder schlecht ist. Wenn die Zahlen langsam und stockend laufen ist das Signal zu schwach.
#Data = Anzahl der aufgefangenen Pakete (und somit auch IV)
#/s = Paketanzahl in der Sekunde
CH = Kanal des WLAN-Netzes
MB = Geschwindigkeit des WLAN-Netzes (in MBit)
ENC = Verschlüsselung
Cipher =
Auth =
ESSID = Name des Access-Point, z.B. wardriving-forum.de


```sudo airodump-ng -w wlan0mon.cap -c 2 --bssid D4:61:2E:AF:51:40 wlan0mon```

### Cracking


### Verbinden

Jetzt kann man die Wlan Karte wieder in Managed Mode bringen,
```sudo ifconfig wlan0mon down```

```sudo iwconfig wlan0 mode managed```
```sudo ifconfig wlan0 up```

und sich mit dem Wlan verbinden, entweder mit einen beliebigen Network Manager oder über die konsole
```sudo iwconfig wlan0 essid FORTI_INTERNET key ??????74:65:73:74:31```

Wenn auf dem Router ein DHCP-server vorhanden ist (Also man eine automatische IP bekommt) muss die noch angefragt werden
```sudo dhclient wlan0```





