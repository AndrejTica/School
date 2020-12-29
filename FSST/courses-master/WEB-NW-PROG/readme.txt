====================================================================
STUNDENPLAN - SOCKET - C
====================================================================
Quelle: http://openbook.galileocomputing.de/linux_unix_programmierung/Kap11-000.htm#Xxx999235


NW-PROG:
1. Grundlagen
	nslookup
2. SOCKET-API
	file-server/fileclient
3. SOCKET-API
	popen-server
	port80-server
4. SOCKET-API
	AB-SOCKET-C-portscanner-popenserver.odt
	portscanner
	nmap
5. SSL: -> UNTERRICHTSMATERIAL/SEC-SSL
	Zertifikate
	ssl-socket
6. WEBSERVICE-SOAP
	Calculator
	mab: waether webservicex.net
7. RESTful
	C: json, libcurl
	volkszaehler
	WEB-NW-PROG/WEBservices_REST/
	ABS/WEB-NW-PROG/AB-SOCKET-C-temperatur-logger.odt
	



--------------------------------------------------------------------
GRUNDLAGEN - nslookup (1)
--------------------------------------------------------------------
1.
2. Grundlagen: 
	OSI, IP, TCP/UDP, Namensauflösung, /etc/hosts, /etc/services
	netstat -a, netstat -i
	
2. t_host.c
3.


--------------------------------------------------------------------
SOCKET-API- fileserver (2)
--------------------------------------------------------------------
1.
2. SOCKET-API
	Socket-Datenstrukturen (port, ip, AF_INET)
	Verbindungsaufbau
	Datenaustausch: read,write
2. t_vcclient.c/t_vcserver.c
2. t_fileclient.c/t_fileserver.c
2. t_server_port80.c
3.



--------------------------------------------------------------------
SOCKET-API- portscanner (2)
--------------------------------------------------------------------
1.
2. t_popenclient.c/t_popenserver.c
2. AB-SOCKET-C-portscanner-popenserver.odt
	nmap
3. MAB: grep, rate



--------------------------------------------------------------------
SOCKET-API- SSL (2)
--------------------------------------------------------------------
1.
2. SEC-SSL
	Zertifikate verwalten
	ssl-socket.c und js
3.

--------------------------------------------------------------------
WEBSERVICE - SOAP (2)
--------------------------------------------------------------------
1.
2. WEBSERVICE-SOAP
	Calculator
3. mab: waether webservicex.net



--------------------------------------------------------------------
RESTful - curl (2)
--------------------------------------------------------------------
1.
2. install libcurl
3. RESTful
	C: json
	C: libcurl



--------------------------------------------------------------------
PROJEKT: Volkszähler (2)
--------------------------------------------------------------------
1.
2. AB-SOCKET-C-temperatur-logger
	install volkszaehler
	get data from zamg and put it into volkszaehler
3.

