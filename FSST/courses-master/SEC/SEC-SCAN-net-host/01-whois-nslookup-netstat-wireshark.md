# 1. Footprinting: SCAN von Netzen und Computern

* <https://de.wikipedia.org/wiki/Footprinting>

## MERKE
1. **NUR EIGENE SYSTEME** scannen , ....
2. ALLES ANDERE IST kriminell.

## Ziel und Ablauf
Ziele:
	1. SCAN das Netz
	2. SCAN den Computer
	3. SCAN das OS
	4. SCAN die App
	5. SCAN den Admin
	6. Werkzeuge kennen lernen: <http://sectools.org/>

## Net Scan with Google
	<www.google.at>
		query: htl-salzburg.ac.at IP
		…
		liefert u.a. 
		<https://www.ipaddress.com/websites/www.htl-salzburg.ac.at>
		...

## Net Scan with whois
	sudo apt-get install whois
	whois htl-salzburg.ac.at


## Net Scan Aufgabe: Finde Nameserver und Personen, von
	1. htl-salzburg.ac.at
	2. uni-salzburg.ac.at
	3. fh-salzburg.ac.at
	
## nslookup (IP Bereiche)
	nslookup -q=any wikipedia.org 8.8.8.8
	
	nslookup htl-salzburg.ac.at
	nslookup www.htl-salzburg.ac.at
	nslookup ms-z.htl-salzburg.ac.at
	...
	nslookup 195.70.113.50
	
## dig (DNS Abfragen)
	dig htl-salzburg.ac.at
	dig ms-z.htl-salzburg.ac.at

### +Aufgabe: t_host.exe 172.16.49.49
Studiere *WEB-NW-PROG/01-SOCKET/01-lernen/nw-prog-01-grundlagen-c.odt* und
1. bringe das Programm *t_host.c* zum Laufen
2. +adaptiere das Programm *t_host.c* derart, dass ganze Bereiche
	ausgewertet werden können.
```	
	./t_host.exe 172.16.49.10-50
	172.16.49.10
	172.16.49.11
	...
```

## +traceroute (tracert)	
	traceroute -q1 www.htl-salzburg.ac.at
	traceroute -q1 ms-z.htl-salzburg.ac.at
	
	-- -n keine namensauflösung
	
### +hping3 (tracen mit tcp, udp,icmp) 
	-- TCP SYN port 80 versuchen.

	hping3 --ttl 1 --traceroute --destport 80 --syn www.htl-salzburg.ac.at
	hping3 --ttl 1 --traceroute --destport 80 --syn ms-z.htl-salzburg.ac.at

	-- syn setzt das SYN-Flag im TCP Header
	-- ttl beginnt mit 1s und wird bei jedem Hop um 1 erhöht.


### +Aufgabe:
1. Analysieren Sie den Output des Kommandos: 
	```
    traceroute apple.com. 
    ```
    
2. *Welche Routers sind für den transatlantischen Sprung verantwortlich*? 
	Können Sie die geographische Lage aller involvierten Router festlegen?*
	http://de.wikipedia.org/wiki/Geotargeting
	
## Abschluss-Aufgabe: Finde Nameserver, Webserver, Mailserver von
	1. uni-salzburg.ac.at
	2. fh-salzburg.ac.at
	

## netstat - aktive Verbindungen auflisten
    netstat
    netstat -a
    netstat -ai


## Wireshark
----------------------------------------------------------------------
* <http://www.nwlab.net/tutorials/wireshark/>


### Aufgabe: wireshark - ftp
1. starten Sie den FTP-Server
    ``` sudo /opt/lampp/lampp startftp ```
2. starten Sie wireshark und ```capture: loopback filter: ftp```
3. melden Sie sich beim ftp-server an
	```
    ftp localhost
	user: nobody
	password: lampp
    ```
	Können Sie mittels wireshark das passwort ermitteln?




## nmap (http://insecure.org/)  
siehe 02-nmap-zenmap.md

 
