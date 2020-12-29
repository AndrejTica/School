# KEY-signing-Party: HOWTO

 
Ziel:  
* Eine **KEY-signing-Party** organisieren um
	1. eigenen **public** und **private** Key zu erzeugen
	2. eigenen **public** key auf einen Key-Server zu schicken
	3. die **public** Keys der Kollegen zu **unterschreiben** (**Web Of Trust**)
	4. Emails zu
		* **verschlüsseln**
		* **unterschreiben**
	


## 1. Aufgabe des Party-Koordinators

1. Die Schlüssel-Liste generieren und
2. eine Kopie der Schlüssel-Liste für jeden der Party-Teilnehmer ausdrucken

| Schlüssel-ID | Schlüssel-Besitzer | Schlüssel-Fingerprint | Schlüssel-Größe  | Schlüssel-Typ  | 1. Schlüssel-Infos passen? | 2. Besitzer-Identifikation (Ausweis) passt? |
|--|--|--|--|--|--|--|
| 0A444677	| "Anton Hofmann <anton.hofmann@htl-salzburg.ac.at>" | 820C 8783 2F4C 8659 56F4  F3BF 56AF 8035 0A44 4677 | 4096 | RSA |  |
|...|...|...|...|...|...|...|


## 2. Aufgabe der Teilnehmer

1. Ein Schlüssel-Paar erstellen
2. Den öffentlichen Schlüssel an den gewählten Keyserver <http://pgp.mit.edu/> senden
3. Die Informationen zum öffentlichen Schlüssel an den Party-Koordinator schicken
4. Zur Party kommen
5. Ihre eigenen Schlüssel-Informationen bestätigen
6. Die Schlüssel-Informationen der anderen prüfen. Prüfen Sie von jedem die Identität für die Schlüssel-IDs, die Sie signieren wollen
7. Alle geprüften Schlüssel auf den eigenen PC laden und signieren
8. Die signierten Schlüssel an den gewählten Keyserver  <http://pgp.mit.edu/> senden

## 3. Was man zur Party mitbringen soll

1. Einen amtlichen Lichtbildausweis
2. Eine geprüfte (über den eigenen Schlüsseleintrag) Kopie der Schlüssel-Liste
3. Einen Stift, um die anderen Schlüssel auf der Schlüssel-Liste zu prüfen.


## 4. Party-Teilnehmer Vorbereitungen (mit gpg)
* eventuell: `sudo apt-get install gpg` 
* infos: <https://www.gnupg.org/howtos/de/index.html>

### 4.1. Schlüsselpaar erstellen
> $> gpg --gen-key

~~~
$> gpg --gen-key

a) Wählen Sie den Schlüsseltyp, den Sie wünschen - die Voreinstellung passt.
	Bitte wählen Sie, welche Art von Schlüssel Sie möchten:
	(1) DSA und ElGamal (voreingestellt)
	(2) DSA (nur signieren/beglaubigen)
	(5) RSA (nur signieren/beglaubigen)
	Ihre Auswahl? <return>

b) Wählen Sie ihre Schlüsselgröße: 2048
	Das DSA-Schlüsselpaar wird 1024 Bit haben.
	Es wird ein neues ELG-E Schlüsselpaar erzeugt.
	kleinste Schlüssellänge ist 768 Bit
	standard Schlüssellänge ist 1024 Bit
	größte sinnvolle Schlüssellänge ist 2048 Bit
	Welche Schlüssellänge wünschen Sie? (1024) 
	2048<return>

c) Wählen Sie die Lebensdauer des Schlüssels: 5 Jahre ist brauchbar.
	Die verlangte Schlüssellänge beträgt 2048 Bit
	Bitte wählen Sie, wie lange der Schlüssel gültig bleiben soll.
	0 = Schlüssel verfällt nie
	<n> = Schlüssel verfällt nach n Tagen
	<n>w = Schlüssel verfällt nach n Wochen
	<n>m = Schlüssel verfällt nach n Monaten
	<n>y = Schlüssel verfällt nach n Jahren
	Wie lange bleibt der Schlüssel gültig? (0) 5y<return>
	Key verfällt am Mon 31 Mär 2008 08:18:12 CEST
	Ist dies richtig? (j/n) 
	j<return>

d) Geben Sie ihren Namen und die E-Mail Adresse(n) ein...
	Ihr Name ("Vorname Nachname"): Max Mustermann<return>
	E-Mail-Adresse: max.mustermann@email.domain<return>
	Kommentar:
	Sie haben diese User-ID gewählt:
	"Max Mustermann <max.mustermann@email.domain>"

	Ändern: (N)ame, (K)ommentar, (E)-Mail oder (F)ertig/(B)eenden? 
	F<return>

e) Wählen Sie ein Mantra. 
	Es sollte lang und sehr schwer zu erraten sein. 
	Es sollte etwas sein, das Sie nicht vergessen werden. 
	Falls Sie ihr Mantra vergessen können Sie ihren Schlüssel nicht wiederherstellen.

f) Bewegen Sie die Maus, drücken einige Tasten. 
	GPG liest von /dev/random, um etwas Zufälligkeit für ihre Schlüsselgenerierung zu erhalten.

~~~

Kontrolle:

> $> gpg --list-secret-keys

~~~
/home/hofmann/.gnupg/pubring.kbx
--------------------------------
pub   rsa4096 2016-08-22 [SCA] [verfällt: 2021-08-21]
      820C87832F4C865956F4F3BF56AF80350A444677
uid        [ unbekannt ] hofmann <anton.hofmann@htl-salzburg.ac.at>
...
~~~

Merke:  
* Die letzten 8 Zeichen sind die sog. Key-ID (hier: 0A444677)


### 4.2. Public-Key an den Keyserver senden

> $> gpg --keyserver <pgp.mit.edu> --send-key <Ihre_Key_ID>

~~~
Sie sollten eine Erfolgsmeldung wie diese sehen:
gpg: Senden an `<keyserver>' erfolgreich (status=200)
~~~
oder verwenden Sie das Web-Interface von <http://pgp.mit.edu/>


Falls Sie ihren Schlüssel nicht auf einem öffentlichen Keyserver haben wollen, sollten Sie ihn stattdessen direkt an ihre Partner schicken.
Sehen Sie dazu hier <https://www.gnupg.org/gph/de/manual/x193.html>

### 4.3. Ein Widerruf-Zertifikat erstellen

> $> gpg --output revcert.asc --gen-revoke <Ihre_Key_ID>

### 4.4. Informationen an den Party-Koordinator schicken
Schicken Sie ihre Informationen per E-Mail an den Koordinator und erzählen Sie ihm, dass Sie zur Key-Signing-Party erscheinen werden. Der unten angeführte Befehl wird die Informationen anzeigen, die Sie an den Koordinator schicken sollten, falls Sie einen Keyserver benutzen. Sie können dann diese Informationen in einer verschlüsselten E-Mail-Nachricht an den Koordinator schicken.

> $> gpg --fingerprint <Ihre_Key_ID>


### 4.5. Beachte: KEIN fremder Zugriff auf .gnupg Ordner
~~~
$ cd
$> ls -la | grep gnu
drwx------  4 hofmann hofmann     4096 Jän 25 22:09 .gnupg
~~~

## 5. Erscheinen Sie auf der Party
1. Kontrollieren Sie Ihren eigenen Fingerprint auf der Schlüssel-Liste
2. Kontrollieren Sie die Identität der anderen Personen und deren Schlüssel.

## 6.  Andere Schlüssel signieren
### 6.1. Besorgen Sie sich eine Kopie des Schlüssels
Üblicherweise werden Sie über einen Keyserver arbeiten. Falls Sie jedoch einen Schlüssel signieren, der nicht auf einem Keyserver verfügbar ist, können Sie den Schlüssel einfach mit gpg --import importieren. Falls Sie mit einem Keyserver arbeiten, wird der folgende Befehl den Schlüssel vom Keyserver in ihren öffentlichen Keyring herunterladen.

> $> gpg --keyserver <keyserver> --recv-keys <Key_ID>

Falls Sie einen Lese-Fehler erhalten, bedeutet es, dass der Keyserver überlastet ist. Versuchen Sie es bitte in ein paar Sekunden erneut.

### 6.2. Fingerprint und Prüfung des Schlüssels

> $> gpg --fingerprint <Key_ID>

GPG wird den Fingerprint des Schlüssels mit <Key_ID > ausgeben (der Schlüssel, den Sie gerade heruntergeladen haben). Vergleichen Sie den Fingerprint mit der Prüfliste, die Sie auf der Party erhalten haben. 

### 6.3. Signieren Sie den Schlüssel

> $> gpg --sign-key <Key_ID>


### 6.4. Schicken Sie den signierten Schlüssel retour oder laden Sie ihn hoch
> $> gpg --keyserver <keyserver> --send-key <Key_ID>

Gratulation, die Signatur auf dem Schlüssel der anderen Person ist nun beendet und ihre Signatur wurde in deren öffentlichen Schlüssel eingearbeitet. Ein Vertrauenspfad wurde erstellt.

## 7. Ihr Schlüsselpaar widerrufen
Falls Sie vermuten, dass ihr geheimer Schlüssel kompromitiert wurde, sollten Sie ihren öffentlichen Schlüssel unverzüglich widerrufen. Das Widerrufen eines Schlüssels funktioniert **durch das Hinzufügen einer Widerruf-Signatur auf dem öffentlichen Schlüssel**. Das Widerrufen eines Schlüssels schlägt vor, dass ein Schlüssel nicht mehr gültig (sicher) ist und nicht verwendet werden sollte. Wenn ein Widerruf-Zertifikat angewendet wird, kann es nichtmehr zurückgenommen werden.

Als Wiederholung hier der Befehl, um ein Widerruf-Zertifikat zu erstellen:

> $> gpg --output revcert.asc --gen-revoke <Ihre_Key_ID>


## 8. Teilnehmer Vorbereitungen (mit Thunderbird und Enigmail):
1. install thunderbird
2. intstall enigmail-plugin for thunderbird
3. Menu->Enigmail->Schlüsselverwaltung
	1. create Key-pair
	2. create Widerrufs-Zertifikat (mit GPA oder Kleopatra oder Enigmail,...)
	3. send Public-Key to Party-Koordinator

### 8.1. Aufgabe Party-Koordinator:
1. Public-Keys der Teilnehmer empfangen und importieren
2. ALLE Public-Keys exportieren (alle.asc)
3. Key-Party-Liste erzeugen (xls-Datei) und ausdrucken od. auf Klassenlaufwerk stellen

### 8.2. Aufgabe Party-Teilnehmer:
1. Den eigenen Public-Key-Fingerprint mit dem Fingerprint in der Key-Party-Liste überprüfen
2. Wenn alle Fingerprints überprüft wurden dann die Identität der Party-Teilnehmer (Passport, ...) prüfen
3. Alle Public-Keys vom Koordinator empfangen und importieren
3. Alle Public-Keys unterschreiben
4. Alle Public-Keys auf den Keyserver senden



## 9. Gute Erklärung  
<http://fenon.de/category/sonstiges/sicherheit/>



## 10. Über dieses Dokument
Copyright (c) 2000 - 2003 V. Alex Brennen.

Hiermit ist die Erlaubnis erteilt, dieses Dokument zu den Bedingungen der GNU Free Documentation License, Version 1.1 oder jeder neueren von der Free Software Foundation veröffentlichten Version zu kopieren, verteilen und/oder zu verändern.

Dieses Dokument ist auf http://www.cryptnet.net/fdp/crypto/gpg-party.html zu finden.

2018 verändert von Anton Hofmann 


