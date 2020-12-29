# How to encrypt a big file using OpenSSL a)without or b)with your partner's public key

<http://www.czeskis.com/random/openssl-encrypt-file.html>


You want to **send securely a big file**

1. you 
	* have not or 
	* have a public key from your partner,
2. you have a big file.


## quick steps:

1. tar xvfz UE-ws-openssl.tgz
2. cd ws-openssl
3. see readme.md


## 1. Situation: You call your partner and aggree on a symmetric key?

If you can call your partner, then **agree on a symmetric key**. Then just use that key to encrypt the file without having to build or use a key/certificate structure. 

You have to remember

1. a password (**symmetric key**) and
2. the **cipher algorithm** for encryption.

To choose a cipher ask openssl for a list in one of two ways.

```bash
openssl -h 
or
openssl list-cipher-commands
```

After you choose a cipher (e.g. aes-256-cbc), you’ll also have to decide if you want to **base64-encode** (e.g. -a) the data. Doing so will mean the encrypted data can be, say, pasted into an email message. Otherwise, the output will be a binary file.


### encrypt file.txt to file.enc using 256-bit AES in CBC mode

```bash
openssl enc -aes-256-cbc -salt -in file.txt -out file.enc
```

the same, only the output is base64 (use -a) encoded for, e.g., e-mail

```bash
openssl enc -aes-256-cbc -a -salt -in file.txt -out file.enc
```

### decrypt

To decrypt file.enc you or the file’s recipient will need to remember 

1. the cipher and 
2. the passphrase.


decrypt binary file.enc
```
openssl enc -d -aes-256-cbc -in file.enc
```

decrypt (use -d) base64-encoded (use -a) version
```
openssl enc -d -aes-256-cbc -a -in file.enc
```


If you’d like to avoid typing a passphrase every time you encrypt or decrypt a file, the openssl(1) man page provides the details under the heading “PASS PHRASE ARGUMENTS.” The format of the password argument is fairly simple.

provide password on command line (base64-encoded)
```
openssl enc -aes-256-cbc -salt -a -in file.txt \
  -out file.enc -pass pass:mySillyPassword
```

provide password in a file
openssl enc -aes-256-cbc -salt -a -in file.txt \
  -out file.enc -pass file:/path/to/secret/password.txt




---
## 2. Situation: Use public key/certificate structure

### 1. Step(your partner): Get your partner's public key 

Your partner has to send you his public key in .pem format.
If your partner uses ssh there will be a public/private key pair in 
his ~/.ssh directory. Otherwise you can use openssl to generate a 
public/private key pair.

#### a) if ssh is used: use public/private keys in rsa format (ssh)

If the public key is in rsa format (often used for ssh), then convert it to .pem by:

```
openssl rsa -in id_rsa -outform pem > id_rsa.pem

openssl rsa -in id_rsa -pubout -outform pem > id_rsa.pub.pem
```

**Receive id_rsa.pub.pem** from your partner.


Hint: ssh keys

man ssh-keygen
and see in your ~/.ssh directory for
* id_rsa (your private key) and
* id_rsa.pub (the public key)

#### b) if openssl is used to get public and private keys

```
openssl genrsa  -out id_rsa.pem 2048 -des3
openssl rsa -in id_rsa.pem -pubout > id_rsa.pub.pem
```
**Receive id_rsa.pub.pem** from your partner.


### 2. Step(you): receive id_rsa.pub.pem from your partner

#### (you) check hash-code from received public key
call your partner of use a certificate
```
openssl dgst -sha1 id_rsa.pub.pem
```


### 3. Step(you): Generate a 256 bit (32 byte) random symmetric key

```
openssl rand -base64 32 > symmetric-key.bin
```


### 4. Step(you): Encrypt the symmetric key

```
openssl rsautl -encrypt -inkey id_rsa.pub.pem -pubin \
-in symmetric-key.bin -out symmetric-key.bin.enc
```


### 5. Step(you): Encrypt the large file
```
openssl enc -aes-256-cbc -salt -in file.txt -out file.enc -pass file:./symmetric-key.bin
```


### 6. Step(you): Send file.enc and symmetric-key.enc to your partner

Send the .enc files to your partner.


### 7. Step(partner): decrypt symmetric-key.enc and file.enc

```
openssl rsautl -decrypt -inkey id_rsa.pem -in symmetric-key.bin.enc -out symmetric-key.bin
```

```
openssl enc -d -aes-256-cbc -in file.enc -out file.txt -pass file:./symmetric-key.bin
```



## Notes on man-in-the-middle

You should always verify the hash of the file with the recipient or sign it with your private key, so the other person knows it actually came from you.


If there is a man-in-the-middle, then he/she could substitute the other person's public key for his/her own and then you're screwed. 
**Always verify the other person's public key (take a hash and read it to each other over the phone)**.


### (partner, you) generate hash-code of the public-key
openssl dgst -sha1 id_rsa.pub.pem



# openssl hints
<https://www.madboa.com/geek/openssl/#encrypt-simple>

## How do I base64-encode something?

Use the enc -base64 option.

```
openssl enc -base64 -in file.txt -out file-base64.txt.enc
```


## Digests (hash-codes)

How do I create an MD5 or SHA1 digest of a file?

Digests are created using the dgst option.

### MD5 digest

```
openssl dgst -md5 filename
```

### SHA1 digest
```
openssl dgst -sha1 filename
```

The MD5 digests are identical to those created with the widely available md5sum 
command, though the output formats differ.

```
$ openssl dgst -md5 foo-2.23.tar.gz
MD5(foo-2.23.tar.gz)= 81eda7985e99d28acd6d286aa0e13e07
$ md5sum foo-2.23.tar.gz
81eda7985e99d28acd6d286aa0e13e07  foo-2.23.tar.gz
```

The same is true for SHA1 digests and the output of the sha1sum application.

```
$ openssl dgst -sha1 foo-2.23.tar.gz
SHA1(foo-2.23.tar.gz)= e4eabc78894e2c204d788521812497e021f45c08
$ sha1sum foo-2.23.tar.gz
e4eabc78894e2c204d788521812497e021f45c08  foo-2.23.tar.gz
```


### How do I sign a digest?

If you want to ensure that the digest you create doesn’t get modified without 
your permission, you can sign it using your private key. 
The following example assumes that you want to sign the SHA1 sum of a 
file called foo-1.23.tar.gz.

#### signed digest will be foo-1.23.tar.gz.sha1
```
openssl dgst -sha1 \
  -sign mykey.pem
  -out foo-1.23.tar.gz.sha1 \
  foo-1.23.tar.gz
```

How do I verify a signed digest?

To verify a signed digest you’ll need the file from which the digest was derived, 
the signed digest, and the signer’s public key.


#### to verify foo-1.23.tar.gz using foo-1.23.tar.gz.sha1 and pubkey.pem

```
openssl dgst -sha1 \
  -verify pubkey.pem \
  -signature foo-1.23.tar.gz.sha1 \
  foo-1.23.tar.gz
```


