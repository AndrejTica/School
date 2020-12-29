# symmetrc encryption and transfer(email) of (very) big files

- ALICE sends to BOB an encrypted (very long) message and uses:
  1. openssl
  2. public key of BOB (key-public-BOB.pem)
  3. a symmetric key (key.bin)
  4. a (very long) message (rfc822.txt)
  
- see: <http://www.czeskis.com/random/openssl-encrypt-file.html>

## 1. ALICE and BOB create their private and public Keys

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

## 2. ALICE and BOB exchange their public keys

- copy your public-key to K:fsst/krypto
- copy your public-key to BOB

## 3. Generate a symmetric key to encrypt large files

~~~ bash
openssl rand -base64 32 > key.bin
~~~

## 4. Encrypt the large file using the symmetric key

~~~ bash
openssl enc -aes-256-cbc -salt -pbkdf2 -in rfc822.txt -out rfc822.txt.enc -pass file:./key.bin
~~~

## 5. Encrypt the symmetric key (using BOB's public key) 

- so you can safely send the sym.key to the other person

~~~ bash
openssl rsautl -encrypt -inkey key-public-BOB.pem -pubin -in key.bin -out key.bin.enc
~~~

## 6. Destroy the un-encrypted symmetric key so nobody finds it

~~~ bash
shred -u key.bin
~~~

## 7. At this point, ALICE sends

1. the encrypted symmetric key (key.bin.enc) and
2. the encrypted large file (rfc822.txt.enc) as one zip-file to the other person

## 8. BOB can then decrypt the symmetric key with his private key using

~~~ bash
openssl rsautl -decrypt -inkey private.pem -in key.bin.enc -out key.bin
~~~

## 9. BOB can use the symmetric key to decrypt the file

~~~bash
openssl enc -d -aes-256-cbc -pbkdf2 -in rfc822.txt.enc -out rfc822.txt -pass file:./key.bin
~~~
  
And you're done. The other person (BOB) has the decrypted file and it was safely sent.
