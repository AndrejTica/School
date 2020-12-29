=============================================
VOLKSZAEHLER
=============================================


http://demo.volkszaehler.org/frontend/
---------------------------------------------------------------
permalink:
http://demo.volkszaehler.org/frontend/?from=1396381607705&to=1396468007705&uuid%5B%5D=c1b717a0-b5b6-11e3-a58c-ef8aeeeb51dc&uuid%5B%5D=147578f0-b5b7-11e3-9c82-85cc4f734eef&uuid%5B%5D=2cc3ce40-b5b8-11e3-ae7a-c5e4bb8633c9&uuid%5B%5D=245dd830-b5b7-11e3-904a-73dde2ae6d47&uuid%5B%5D=98fd2600-b4bb-11e3-afa6-fd34350f1281


Die einzelnen Kanäle
------------------------------------------------------------------
Salzburg:			98fd2600-b4bb-11e3-afa6-fd34350f1281
Linz/Hörsching:     2cc3ce40-b5b8-11e3-ae7a-c5e4bb8633c9
Retz:            	c803b980-b5b6-11e3-9f74-152449a53762
Kremsmünster:       0684e4a0-b5b8-11e3-a70f-edd61321fe02
Wien/Hohe Warte:    c34283a0-b5b6-11e3-a4ac-0b13b97cbac0
Wien/Schwechat:     d54447a0-b5b6-11e3-846a-b7388ef567a1
Bregenz:         	c1b717a0-b5b6-11e3-a58c-ef8aeeeb51dc
Kufstein:        	147578f0-b5b7-11e3-9c82-85cc4f734eef
Feuerkogel:        	1293ac50-b5b8-11e3-8d38-ad9f6f0d5630
Innsbruck:        	c256ebd0-b5b6-11e3-907e-c78475285974
Patscherkofel:    	245dd830-b5b7-11e3-904a-73dde2ae6d47



REST-API - Allgemein
---------------------------------------------------------------
http://wiki.volkszaehler.org/development/api/start?s[]=rest


REST-API - Volkszaehler
---------------------------------------------------------------
http://wiki.volkszaehler.org/development/api/reference


REST-API - Volkszaehler - Beispiel
---------------------------------------------------------------
Linz/Hörsching habe 25 grad

http://demo.volkszaehler.org/middleware.php/data/2cc3ce40-b5b8-11e3-ae7a-c5e4bb8633c9.json?operation=add&value=25

Salzburg habe 25 Grad:
http://demo.volkszaehler.org/middleware.php/data/98fd2600-b4bb-11e3-afa6-fd34350f1281.json?operation=add&value=25

Nachsehen:
http://demo.volkszaehler.org/frontend/?uuid=98fd2600-b4bb-11e3-afa6-fd34350f1281



REST-API - Volkszaehler - Beispiel mit Zugriff auf die aktuellen ONLINE Daten
-----------------------------------------------------------------------------
Proxy eintragen: 
~/.curlrc file (create it if it does not exist) :
proxy = username:password@tmg-z2.htl.org:8080


Salzburg:
curl -s -L http://www.zamg.ac.at/ogd | grep Salzburg | awk -F";" '{print "curl -s -L \"http://demo.volkszaehler.org/middleware.php/data/98fd2600-b4bb-11e3-afa6-fd34350f1281.json?operation=add&value=" $6 "\""}'

FRAGE:
Wie kann man erreichen, dass der generierte Befehl gleich ausgeführt wird?

 
WEITERES siehe:
AB-volkszaehler-libcurl-SOLVED.odt
