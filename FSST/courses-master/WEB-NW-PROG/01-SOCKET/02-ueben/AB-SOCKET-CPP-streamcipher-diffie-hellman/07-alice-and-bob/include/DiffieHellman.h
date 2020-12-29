#include "SocketException.h"

#include <iostream>
#include <string>
using namespace std;

#include <cmath>
#include <cstdlib>

// consts
const int TRUSTCENTER_PORT = 30000;
const char *TRUSTCENTER_HOST = "localhost";
const int BOB_PORT = 4444;
const char *BOB_HOST = "localhost";

#include "ClientSocket.h"

class DiffieHellman {
private:
  int trustcenter_port;
  string trustcenter_hostname;

  string myName;
  string partnerName;

  int n, g;
  int myPubKey;
  int partnerPubKey;
  int secretNumber;
  int KEY;

  void getNG();
  void calcPubKey();
  void sendPubKey();
  void receivePartnerPubKey();
  void calcKEY();

public:
  DiffieHellman(string trustcenter_hostname, int trustcenter_port,
                string myName, string partnerName);

  ~DiffieHellman();

  int getKEY() const;
};
/*
void DH::getNG(){}
void DH::calcPubKey(){}
void DH::sendPubKey(){}
void DH::receivePartnerPubKey(){}
void DH::calcSymKEY(){}
*/

DiffieHellman::DiffieHellman(string trustcenter_hostname, int trustcenter_port,
                             string myName, string partnerName) {
  this->trustcenter_hostname = trustcenter_hostname;
  this->trustcenter_port = trustcenter_port;
  this->myName = myName;
  this->partnerName = partnerName;

  // init other private members
  getNG();
  calcPubKey();
  sendPubKey();
  receivePartnerPubKey();
  calcKEY();
}

DiffieHellman::~DiffieHellman() {}


int DiffieHellman::getKEY() const {
  return KEY;
}


void DiffieHellman::getNG() {
  // 1. RECEIVE g,n from trustcenter
  string data, part;

  ClientSocket trustcenter(trustcenter_hostname, trustcenter_port);
  trustcenter << "GET:NG";
  trustcenter >> data;

  stringstream ss(data);
  // N
  std::getline(ss, part, ':');
  n = stoi(part);
  // G
  std::getline(ss, part, ':');
  g = stoi(part);

#ifdef DEBUG
  cout << "... receiving n,g from trustcenter (GET:NG)" << endl;
  cout << "... got n= " << n << ", g=" << g << endl;
#endif
}

void DiffieHellman::calcPubKey() {
  secretNumber = rand() % 5;
  myPubKey = (int)=== ENTER CODE ===;

#ifdef DEBUG
  cout << "... choosing secret number: = " << secretNumber << endl;
  cout << "... calculating Public Key: PK= (int) pow(" << g << ","
       << secretNumber << ") % " << n << endl;
  cout << "... Public key= " << myPubKey << endl;
#endif
}

void DiffieHellman::sendPubKey() {
  ClientSocket trustcenter(trustcenter_hostname, trustcenter_port);
  trustcenter << string("ADD:PK:") + myName + ":" + to_string(myPubKey);

#ifdef DEBUG
  cout << "... sending Public Key to TC: = " << myPubKey << endl;
  cout << "... ADD:PK:" << myName << ":" << myPubKey << endl;
#endif
}

void DiffieHellman::receivePartnerPubKey() {
#ifdef DEBUG
  cout << "... receiving/waiting for partner public key" << endl;
#endif

  partnerPubKey = -1;
  do {
    usleep(1000 * 1000 * 5); // 5sec

    ClientSocket trustcenter(trustcenter_hostname, trustcenter_port);
    string data;
    trustcenter << string("GET:PK:") + partnerName;
    trustcenter >> data;

#ifdef DEBUG
    cout << "... got from trustcenter: " << data << endl;
#endif

    if (data != "-401" && data != "-402") {
      partnerPubKey = stoi(data);
    }

  } while (partnerPubKey == -1);

#ifdef DEBUG
  cout << "... got from trustcenter Partner's Public Key = " << partnerPubKey
       << endl;
#endif
}

void DiffieHellman::calcKEY() {
  this->KEY = (int)=== ENTER CODE ===;

#ifdef DEBUG
  cout << "... calculating KEY = (int) pow(";
  cout << partnerPubKey << "," << secretNumber << ")%" << n << "= " << KEY
       << endl;
#endif
}
