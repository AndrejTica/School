# MAB: symmetric decryption

## 1. S/S: gernate keys and export public-key

- cd MAB-02-symmetric-enc
- create key-pair:
  ```./do_create_keys.sh # ``` (# ... your katalognummer: 1,2,3,...)

- copy key-public-#.pem to K:/fsst/krypto
- wait ...

## 2. S/S: get encrypted files as zip and decrypt

- get to-#.zip from K:/fsst/krypto
- decrypt symmetric key with private.pem
- decrypt text-file rfc#.txt.enc with symmetric key

## 3. upload only rfc#.txt

- upload rfc#.txt
