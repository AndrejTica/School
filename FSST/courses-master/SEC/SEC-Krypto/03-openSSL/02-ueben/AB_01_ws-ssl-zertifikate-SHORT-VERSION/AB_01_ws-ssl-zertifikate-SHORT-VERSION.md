# openSSL

- install openssl
- create keys
- create csr
- create a CA
- CA signs the csr
- tests

---

## 1. openssl install

~~~cpp
sudo apt-get install openssl
~~~

---

## 2. create keys

~~~bash
openssl genrsa -out www-name-org.key -des3 2048
~~~

---

## 3. remove Triple-DES encryption

~~~bash
openssl rsa -in www-name-org.key > www-name-org-unencrypted.key
~~~

---

## 4. see key content (optional)

~~~bash
openssl rsa -in www-name-org.key -text -noout
~~~

---

## 5. create Certification Signing Request (CSR)

~~~bash
openssl req -new -key www-name-org.key -out www-name-org.csr

for cn enter: www.name.org
~~~

---

## 6. show CSR (optional)

~~~bash
openssl req -in www-name-org.csr -text -noout
~~~

---

## 7. create (private) Certification Authority (CA)

~~~
openssl req -x509 -newkey rsa:512 -keyout CA.key -out CA.crt
~~~

---

## 8. CA signs the CSR

~~~
openssl x509 -req  -in www-name-org.csr -CA CA.crt -CAkey CA.key -CAcreateserial -out www-name-org.crt -days 365
~~~

---

## 9. see certificate (optional)

~~~
openssl x509 -in www-name-org.crt -text -noout
~~~

---

# SHORT

## 1. create KEY & CSR

~~~
openssl req -new -keyout www-name-org.key -out www-name-org.csr -newkey rsa:2048 -nodes
~~~

---

## 2. create CA-root certificate

~~~
openssl req -x509 -newkey rsa:512 -keyout CA.key -out CA.crt
~~~

---

## 3. sign CSR

~~~
openssl x509 -req  -in www-name-org.csr -CA CA.crt -CAkey CA.key -CAcreateserial -out www-name-org.crt -days 365
~~~

---

## TEST

### 1. /etc/hosts enter www.name.org

~~~
sudo nano /etc/hosts -> 127.0.0.1  www.name.org
~~~

---

### 1. start Server

~~~
openssl s_server -WWW -accept 8000 -key www-name-org.key -cert www-name-org.crt
~~~

---

### 1. Test using Browser

~~~
https://www.name.org:8000/CA.config
~~~

---

### 1. Test using console

~~~
openssl s_client -connect WWW.NAME.ORG:8000 -key www-name-org.key -cert www-name-org.crt
~~~
