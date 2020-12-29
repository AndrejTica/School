# Diffie-Hellmans Trustcenter , Alice and Bob
---------------------------------------------

- File: 05-streams-diffie-hellman.md

## 1. Aufgabe: Study Diffie-Hellman's Trustcenter
-------------------------------------------------

**Study** and **explain**

```
* <http://de.wikipedia.org/wiki/Diffie-Hellman-Schl%C3%BCsselaustausch>
* <http://en.wikipedia.org/wiki/Diffie%E2%80%93Hellman_key_exchange>
```



## 2. Augabe: Trustcenter (command line program)
------------------------------------------------

Create class **Trustcenter** and a test program. Your test programm should act like a TrustCenter that can be called by every program using

```
* hostname
* port
* and the TrustCenter protocol
```

![Figure 1: uml-trustcenter](uml-trustcenter.png "UML Diagram Project Trustcenter")


### 2.1. TrustCenter protocol

- connection

  - host: localhost
  - port: 30000

- howto get n, g from trustcenter

  - send: "GET:NG"
  - receive: "123:456"

- howto add a public key

  - send: "ADD:PK:BOB:123"
  - receive:    "200 OK"

- howto get a public key

  - send: "GET:PK:BOB"
  - receive:    

    - "123" (ok)
    - "-402" (error)

- what if protocol error?

  - send: "?"
  - receive:    "-401"


### 2.2. test-trustcenter.cpp
----------------------------------------
```cpp
/*
 * @file test-trustcenter.cpp
 * @author N.N.
 * @date dd.mm.yyyy
 * @description The TrustCenter protocol

"GET:NG"
    "123:456"
"ADD:PK:BOB:123"
    "200 OK"
"GET:PK:BOB"
    "123"
    "-402"
"?"
    "-401"

 * @startup: ./test-trustcenter.exe 30000 5 7
*/

#include "trustcenter.h"

int main ( int argc, char* argv[] ){
    int port=30000;
    string n="5";
    string g="7";

    TrustCenter trustcenter(port,n,g);

    trustcenter.accept();

    return 0;
}
```



## 3. Aufgabe: Alice and Bob
----------------------------------------------------

Using **ClientSocket_secure** and **ServerSocket_secure** we want to test our TrustCenter.

We use:

1. trustcenter.cpp (see: test-trustcenter.exe 30000 5 7)
2. alice.cpp (see: test-clientsocket_secure.exe "Hallo, Welt" 1 )
3. bob.cpp (see: ./test-serversocket_secure.exe 1)

But we don't use the argument (here 1) as key for the streamcipher encryption.

See how Alice gets the key for the streamcipher encryption:

```
1. receive: n,g from trustcenter at port 30000
2. choose: int secretKeyAlice; //(SKA)
3. calculate: int publicKeyAlice= pow(g, SKA) % n; // PKA
4. send: PKA to trustcenter

5. wait until PKB is available from trustcenter
6. calculate: int key= ????????

7. do the encrypted communication like in test-clientsocket_secure.cpp
```
