# Alice and Bob: Encrypted communication using Diffie-Hellman (Trustcenter)

## Topic

- programs:
  - TRUSTCENTER on port 30000
  - ALICE (acts like a client)
  - BOB (acts like a server on port 4444)
- use symmetric cipher (streamcipher)
  - instead of key-exchange use Diffie-Hellman
  - Alice and Bob use encrypted communication
  - Alice,Bob use plain communication with trustcenter
  - test with wireshark

## 1. Overview

- Alice uses:
  - Socket, SocketException
  - ClientSocket
  - ClientSocket_secure.cpp
  - DiffieHellman.h
  - alice-main.cpp

- Bob uses:
  - Socket, SocketException
  - ClientSocket
  - ServerSocket_secure.cpp
  - DiffieHellman.h
  - bob-main.cpp

- TrustCenter uses:
  - Socket, SocketException
  - ServerSocket
  - trustcenter.h, trustcenter-main.cpp

## 2. LAB: class DiffieHellman

- used by Alice and Bob
  - to communicte with trustcenter
  - to calculate the KEY for sym. encrypted communication

- how alice usees class DiffieHellman

~~~ cpp
// user: alice
DiffieHellman diffie_hellman(TRUSTCENTER_HOST, TRUSTCENTER_PORT,"ALICE", "BOB");
int KEY= diffie_hellman.getKEY();
~~~

- how bob usees class DiffieHellman

~~~ cpp
// user: bob
DiffieHellman diffie_hellman(TRUSTCENTER_HOST, TRUSTCENTER_PORT,"BOB", "ALICE");
int KEY= diffie_hellman.getKEY();
~~~

### 2.1. Lab: given DiffieHellman.h

~~~ cpp
class DiffieHellman {
private:
  // comm partner
  string myName;
  string partnerName;

  // trustcenter
  int trustcenter_port;
  string trustcenter_hostname;
  int n, g;
  int myPubKey;
  int partnerPubKey;
  int secretNumber;
  int KEY;

  // helper methods are private
  void getNG();
  void calcPubKey();
  void sendPubKey();
  void receivePartnerPubKey();
  void calcKEY();

public:
  DiffieHellman(string trustcenter_hostname, int trustcenter_port,
                string myName, string partnerName) ;
  ~DiffieHellman();

  int getKEY() const;
};
~~~

### 2.2. Lab: DiffieHellman.cpp

- implement DiffieHellman.cpp
- hint: choose a secret number

~~~ cpp
secretNumber = rand() % 5;
~~~

- hint: wait until PublicKey from partner is available

~~~ cpp
  partnerPubKey = -1;
  do {
    usleep(1000 * 1000 * 5); // 5sec

    string getPubKey=string("GET:PK:") + this->partnerName;

    ClientSocket trustcenter(trustcenter_hostname, trustcenter_port);
    trustcenter << getPubKey;
    string data;
    trustcenter >> data;

  
    if (data != "-401" && data != "-402") {
      this->partnerPubKey= stoi(data);
    }
  } while (partnerPubKey == -1);
~~~

- hint: calculate KEY
  
~~~ cpp
KEY = (int)pow(partnerPubKey, secretNumber) % n;
~~~

## 3. Lab: alice.cpp

- acts like a client
- see: 05-socket-secure/src/simple_client_main.cpp
- hint: add this to get the KEY for encrypted comm.

~~~ cpp
// user: alice
DiffieHellman diffie_hellman(TRUSTCENTER_HOST, TRUSTCENTER_PORT,"ALICE", "BOB");
int KEY= diffie_hellman.getKEY();
~~~

## 4. Lab: bob.cpp

- acts like a server
- see: 05-socket-secure/src/simple_server_main.cpp
- hint: add this to get the KEY for encrypted comm.

~~~ cpp
// user: bob
DiffieHellman diffie_hellman(TRUSTCENTER_HOST, TRUSTCENTER_PORT,"BOB", "ALICE");
int KEY= diffie_hellman.getKEY();
~~~

## 5. compile alice and bob

~~~ bash
cd build
cmake ..
make
~~~

## 6. Lab: wireshark

~~~ bash
tcp port 30000 || tcp port 4444

[PSH,ACK] ... tcp soll data an übergeordnete Ebene weiter reichen.
data ........ zeigt die Daten

Menue->Aufzeichnungen->starten/stoppen

siehe: Info from-port <--> to-port
~~~

## 7. TEST it ALL

### 1. run trustcenter

- new terminal 1

~~~ bash
./06-diffie-hellman-trustcenter/build/trustcenter-main
~~~

### 2. run alice

- new terminal 2

~~~ bash
./07-alice-and-bob/build/alice
~~~

### 3. run bob

- new terminal 3

~~~ bash
./07-alice-and-bob/build/bob
~~~
