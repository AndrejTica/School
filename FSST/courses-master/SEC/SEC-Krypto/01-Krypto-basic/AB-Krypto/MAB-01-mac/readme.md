# MAB: Check if file werwolf-orig.txt has been altered

Receiver BOB (see folder bob) got from ALICE

1. werwolf-orig.txt
1. mac.txt.enc (sha512, signed)
1. key-public-ALICE.pem

BOB wants to know

1. if werwolf-orig.txt has been altered and
2. if werwolf-orig.txt is really from ALICE

## ANSWER 1: openssl command to verify

~~~bash
openssl dgst -sha512 -verify key-public-ALICE.pem -signature mac.txt.enc
~~~

o true  
o false

## ANSWER 2: werwolf-orig.txt

o was altered
o was not altered

## ANSWER 3: What did ALICE to generate mac.txt.enc (see: ../readme.md)

~~~bash









~~~

## ANSWER 4: Give a short but complete explanation of

1. Kryptoanalyse
2. Kryptografie
3. Kryptologie
4. Fingerprint
5. MAC
6. Dienst der Authentizität
7. authentifizieren
8. authentisieren
9. Dienst der Vertraulichkeit
10. Dienst der Integrität
11. Dienst der Verbindlichkeit
