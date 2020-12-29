======================================================================
LEHRSTOFF: SEC-SSL
======================================================================

Inhalt:
-------
1. SEC-SSL/01-lernen/01-openSSL-zertifikate.odt

	Theorie: Zertifikate mit openssl: 
		Was ist das?
		Wie erstellt man solche?
		Welche Informationen beinhalten Zertifikate?
		Was ist eine CA?
	
2. SEC-SSL/02-ueben/AB_01_ws-ssl-zertifikate.tgz

	Praxis: Zertifikate mit openssl erstellen und verwenden


	
3. SEC-SSL/02-ueben/AB_01_ws-ssl-zertifikate-SOLVED.tgz

	Praxis: Zertifikate mit openssl erstellen und verwenden
	Eine Lösung f. (www.hofmann.org)



9. OPTIONAL bzw. weitere vertiefende Informationen:	
	SEC-SSL/01-lernen/02-openSSL-socket-client-server.odt
			Zertifikate und Client/Server (Socket-cpp)-Programme

	SEC-SSL/01-lernen/03-install-apache-ssl.odt
			Zertifikate und ein Web-Server
			
	SEC-SSL/01-lernen/04-howto-openssl-secure-filetransfer.md
	SEC-SSL/01-lernen/05-howto-ecryptfs.md
	SEC-SSL/01-lernen/06-howto-gpg.txt
	SEC-SSL/01-lernen/07-howto-hash.txt

______________________________________________________________________
01-lernen: Theorie: Zertifikate und openssl
______________________________________________________________________
Didaktik: 
	Skriptum gemeinsam lesen

1. SEC-SSL/01-lernen/01-openSSL-zertifikate.odt

	Theorie: Zertifikate mit openssl: 
		Was ist das?
		Wie erstellt man solche?
		Welche Informationen beinhalten Zertifikate?
		Was ist eine CA?


______________________________________________________________________
02-ueben: Praxis: Zertifikate erstellen mit openssl
______________________________________________________________________
Didaktik: 
	Selbst ein Makefile erstellen , um 
	Zertifikate zu erstellen und zu testen.
	
2. SEC-SSL/02-ueben/AB_01_ws-ssl-zertifikate.tgz

	Praxis: Zertifikate mit openssl erstellen und verwenden

	
	
STEP 01:
	S/S müssen in /etc/hosts einen DNS-Eintrag erstellen (mit dem eigenen Namen)
	1. /etc/hosts
		www.hofmann.org 	127.0.0.1

STEP 02:
	S/S müssen 
		1. die Dateien editieren und  Namen anpassen)
			# Anpassen der Dateinamen
			SERVER.config
			CA.config

			
		2. das File UE_Makefile anpassen (editieren und  Namen anpassen)
			SERVER_PRIV_KEY	= www-hofmann-org-private-key.pem
			SERVER_CSR		= www-hofmann-org-cert.csr
			SERVER_CERT		= www-hofmann-org-cert.pem
			
		3. das File UE_Makefile anpassen (editieren und 
				Bringen Sie die aufgelisteten Befehle an die richtige Stelle 
				in der Datei UE_Makefile.
				
		4. Geben Sie dieser Datei den Namen Makefile (mv UE_Makefile Makefile)
		
		5. Das Makefile nutzen, um Zertifikate zu erstellen und zu testen
			make
			make 1
			make 2
			...
		
