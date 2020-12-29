# Key-signing-party with Thunderbird, K9-mail, mailvelope

## 1. Information zu

- mails mit Sicherheit
- WEB-of-Trust
- openPGP (Pretty Good Privacy)
- gpg (gnu privacy guard)
- Verschlüsseln / signieren

## 2. Video

- <https://www.bsi-fuer-buerger.de/BSIFB/DE/Empfehlungen/Verschluesselung/EMail_Verschluesselung/EasyGPG/EMail_EasyGPG_node.html>

## 3. install

- thunderbird
- plugin/enigma
- config your email-account: name@htl-salzburg.ac.at

~~~ bash
SMTP
	Servername: smtp.office365.com
	Port: 587
	Verschlüsselungsmethode: STARTTLS

IMAP:
	Servername: outlook.office365.com
	Port: 993
	Verschlüsselungsmethode: TLS
~~~

## 4. S/S enigma: create public-keys

- create Key-pair (RSA 4096)
- upload your public key to Keyserver <https://keyserver.ubuntu.com/>
- send Public-key -> julian.puerstinger@htl-salzburg.ac.at

## 5. Key-Manager

- save K:/fsst/key-signing-party/PUBLIC-KEYS-5BHEL-2020.txt

## 6. S/S import and sign and upload public keys

- import PUBLIC-KEYS-5BHEL-2020.txt
- enigma: sign all public keys
- enigma: upload public-keys to KEY-Server <https://keyserver.ubuntu.com/>

## 7. S/S communicate using thunderbird

- sign and/or encrypt messages

## 8. Handy: android

- install K9-mail
- install openKeychain
- import Keys

## 9. HTTP-email: plugin: mailvelope

- firefox: install mailvelope
- manage keys

## 10. Schlüsselpaar widerrufen

~~~ bash
gpg --output revcert.asc --gen-revoke <Ihre_Key_ID>
~~~
