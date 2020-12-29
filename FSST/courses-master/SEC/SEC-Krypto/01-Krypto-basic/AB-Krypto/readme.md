# RDP: providing security with openssl

## Aufgaben: AB-KRYPTO

Laden Sie die Datei AB-KRYPTO.zip und bearbeiten Sie

1. AB-01-mac (Authentizität+Verbindlichkeit)
2. AB-02-symmetric-enc (symmetrische Verschlüsselung)
    1. übertrage den verschlüsselten symmetrischen Schlüssel
    2. übertrage die mit 1. verschlüsselte (grosse) Datei
3. MAB-01-mac  - Symmetrische Verschlüsselung

## Hinweis: openssl

### 0. install openssl

~~~bash
sudo apt-get install openssl-dev
oder
sudo apt-get install openssl
~~~

### 1. Private-key  (RSA 4096 Bits) erzeugen

~~~bash
openssl genrsa  -out private.pem  4096
~~~

### 2. Schlüssel Leseschutz

~~~bash
chmod 600 private.pem
~~~

### 3. Public-Key erzeugen

~~~bash
openssl rsa -pubout -in private.pem -out key-public-NAME.pem
~~~

### 4. Fingerprint/digest einer Textdatei erzeugen

wenn nur Integrität gefordert

~~~bash
openssl dgst -sha512 -out digest.txt plain-NAME.txt
~~~

### 5. Fingerprint einer Textdatei erzeugen und diesen Fingerprint signieren

wenn NICHTABSTREITBARKEIT (Integrität und Authentizität) gefordert

~~~bash
openssl dgst -sha512 -sign private.pem -out mac.txt.enc -hex plain-NAME.txt
~~~

### 6. Eine Signatur/Unterschrift (MAC) verifizieren

~~~bash 
openssl dgst -sha512 -verify key-public-NAME.pem -signature mac.txt.enc plain-NAME.txt
~~~
