// ClientSocket_secure.h
// Definition of the ClientSocket_secure class

#pragma once

#include "Socket.h"
// !!!!!!!!!!!!!!!!!!!!!!
#include "cipherstream.h"
using namespace std;

class ClientSocket_secure : private Socket {
public:
  // !!!!!!!!!!!!!!!!!!!!!!
  ClientSocket_secure(string host, int port, int key);

  // !!!!!!!!!!!!!!!!!!!!!!
  virtual ~ClientSocket_secure() {
    delete out;
    delete in;
  };

  const ClientSocket_secure &operator<<(const string &) const;
  const ClientSocket_secure &operator>>(string &) const;

private:
  // !!!!!!!!!!!!!!!!!!!!!!
  CipherStream *out;
  CipherStream *in;
};
