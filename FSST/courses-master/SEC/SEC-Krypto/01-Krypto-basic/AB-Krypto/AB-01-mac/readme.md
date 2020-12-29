# MAC (message authentication code)

Dienst der VERBINDLICHKEIT/NICHTABSTREITBARKEIT (=Integrität + Authentizität) von Daten

<https://en.wikipedia.org/wiki/Message_authentication_code>

![img](mac.png)

ALICE sends to BOB a message using (=Integrität + Authentizität) using:

  1. openssl
  2. a signed fingerprint/digest (mac.txt.enc)
  3. the message (rfc-index.txt)

Alice cannot deny this.

## 1. Sender ALICE (overview)

1. create a fingerprint/digest (digest.txt) of message (rfc-index.txt)
2. sign fingerprint (mac.txt.enc)
3. send to BOB:
    - message (rfc-index.txt)
    - signed fingerprint (mac.txt.enc)
    - key-public-ALICE.pem

## 2. Receiver BOB (overview)

1. create a fingerprint/digest (digest.txt) of message (rfc-index.txt)
2. decrypt mac.txt.enc with key-public-ALICE.pem
3. compare digest.txt with mac.txt
4. if equal Bei Gleichheit wurden die Daten
    - message (rfc-index.txt) was not altered
    - message was sent from ALICE (no one else)

## 3. ALICE and BOB create their private and public Keys

- sender: ALICE
  - private.pem
  - key-public-ALICE.pem
  
- receiver: BOB
  - private.pem
  - key-public-BOB.pem

use this script

~~~bash
#!/bin/bash
# ./do_create_keys.sh NAME
#

if [ $# -eq 0 ]
  then
    echo "enter NAME for key-public-NAME.pem"
    read NAME
  else
    NAME=$1
fi

openssl genrsa -out private.pem 4096
chmod 600 private.pem
openssl rsa -pubout -in private.pem -out key-public-$NAME.pem

echo ""
echo "[done] created private.pem"
echo "[done] created key-public-$NAME.pem"
echo ""
~~~

## 5. ALICE and BOB exchange their public keys

- copy your public-key to K:fsst/key-public

## 6. ALICE creates fingerprint/MAC

### 6.1. if only INTEGRITÄT is claimed

~~~bash
openssl dgst -sha512 -out digest.txt rfc-index.txt
~~~

### 6.2. if NICHTABSTREITBARKEIT (Integrität und Authentizität) is claimed

~~~bash
openssl dgst -sha512 -sign private.pem -out mac.txt.enc rfc-index.txt
~~~

## 7. ALICE sends

- rfc-index.txt
- mac.txt.enc (is signed)
- key-public-ALICE.pem

## 8. Receiver BOB

Verify a signature (Unterschrift) of a fingerprint (MAC).

~~~bash
openssl dgst -sha512 -verify key-public-ALICE.pem -signature mac.txt.enc rfc-index.txt
~~~

IF EQUAL

- rfc-index.txt was not altered and
- comes from ALICE (no one else)

## 9. summary

### 9.1. create keys

~~~bash
openssl genrsa  -out private.pem  4096
chmod 600 private.pem
openssl rsa -pubout -in private.pem -out public.pem
~~~

### 9.2. create MAC

~~~bash
openssl dgst -sha512 -sign private.pem -out mac.txt.enc rfc-index.txt
~~~

### 9.3. verify MAC

~~~bash
openssl dgst -sha512 -verify key-public-ALICE.pem -signature mac.txt.enc rfc-index.txt
~~~
