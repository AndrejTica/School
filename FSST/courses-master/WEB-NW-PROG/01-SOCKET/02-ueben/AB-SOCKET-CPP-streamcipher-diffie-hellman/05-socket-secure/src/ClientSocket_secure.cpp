// ClientSocket_secure.cpp
// Implementation of the ClientSocket_secure class

#include "ClientSocket_secure.h"
#include "SocketException.h"

#include <iostream>
using namespace std;

ClientSocket_secure::ClientSocket_secure(string host, int port, int key) {
  if (!Socket::create()) {
    throw SocketException("Could not create client socket.");
  }

  if (!Socket::connect(host, port)) {
    throw SocketException("Could not bind to port.");
  }

  // !!!!!!!!!!!!!!!!!!!!!!
  === ENTER CODE ===
}



const ClientSocket_secure &
ClientSocket_secure::operator<<(const string &plain) const {

  // !!!!!!!!!!!!!!!!!!!!!!
  string scipher=== ENTER CODE ===

  
#ifdef DEBUG
  cout << "ClientSocket_secure::operator<< SEND(plainText) is:" << plain << endl;
  cout << "ClientSocket_secure::operator<< SEND(cryptText) is:" << scipher << endl;
  cout << "ClientSocket_secure::operator>> SENDING ..." << endl;
#endif

  // !!!!!!!!!!!!!!!!!!!!!!
  if (!Socket::send(scipher)) {
    throw SocketException("Could not write to socket.");
  }

  return *this;
}




const ClientSocket_secure &
ClientSocket_secure::operator>>(string &plain) const {

string scipher="";

#ifdef DEBUG
  cout << "ClientSocket_secure::operator>> RECEIVING ..." << endl;
#endif

  if (!Socket::recv(scipher)) {
    throw SocketException("Could not read from socket.");
  } else { // !!!!!!!!!!!!!!!!!!!!!!

#ifdef DEBUG
    cout << "ClientSocket_secure::operator>> RECEIVED(cryptText) is:" << scipher
         << endl;
#endif

  plain=== ENTER CODE ===

#ifdef DEBUG
    cout << "ClientSocket_secure::operator>> RECEIVED(plainText) is:" << plain
         << endl;
#endif
  }

  return *this;
}
