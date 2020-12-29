// ServerSocket_secure.cpp
// Implementation of the ServerSocket_secure class

// !!!!!!!!!!!!!!!!!!!!!!
#include "ServerSocket_secure.h"

#include "SocketException.h"
#include <iostream>
using namespace std;

ServerSocket_secure::ServerSocket_secure(int port, int key) {
  if (!Socket::create()) {
    throw SocketException("Could not create server socket.");
  }

  if (!Socket::bind(port)) {
    throw SocketException("Could not bind to port.");
  }

  if (!Socket::listen()) {
    throw SocketException("Could not listen to socket.");
  }

  // !!!!!!!!!!!!!!!!!!!!!!
  in = new CipherStream(key);
  out = new CipherStream(key);
}

ServerSocket_secure::ServerSocket_secure(int key) : Socket() {
  // !!!!!!!!!!!!!!!!!!!!!!
  in = new CipherStream(key);
  out = new CipherStream(key);
}

const ServerSocket_secure &
ServerSocket_secure::operator<<(const std::string &plain) const {

  // !!!!!!!!!!!!!!!!!!!!!!
  string scipher = out->plain2cipher(plain);

#ifdef DEBUG
  cout << "ServerSocket_secure::operator<< SEND(plainText) is:" << plain
       << endl;
  cout << "ServerSocket_secure::operator<< SEND(cryptText) is:" << scipher
       << endl;
  cout << "ServerSocket_secure::operator>> SENDING ..." << endl;
#endif

  if (!Socket::send(scipher)) {
    throw SocketException("Could not write to socket.");
  }

  return *this;
}




const ServerSocket_secure &
ServerSocket_secure::operator>>(string &plain) const {
  // !!!!!!!!!!!!!!!!!!!!!!
  string cipherText = "";

#ifdef DEBUG
  cout << "ServerSocket_secure::operator>> RECEIVING ..." << endl;
#endif

  if (!Socket::recv(cipherText)) {
    throw SocketException("Could not read from socket.");
  }

  // !!!!!!!!!!!!!!!!!!!!!!

  plain = in->cipher2plain(cipherText);

#ifdef DEBUG
  cout << "ServerSocket_secure::operator>> RECEIVED(cryptText) is:"
       << cipherText << endl;
  cout << "ServerSocket_secure::operator>> RECEIVED(plainText) is:" << plain
       << endl;
#endif

  return *this;
}

void ServerSocket_secure::accept(ServerSocket_secure &sock) {
  if (!Socket::accept(sock)) {
    throw SocketException("Could not accept socket.");
  }
}
