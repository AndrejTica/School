#include "ClientSocket_secure.h"
#include "SocketException.h"

#include <iostream>
using namespace std;

#include "DiffieHellman.h"

int main(int argc, char *argv[]) {
 
  cout << "ALICE connects to trustcenter ...." << endl;

  DiffieHellman diffie_hellman(TRUSTCENTER_HOST, TRUSTCENTER_PORT, "ALICE",
                                "BOB");
  int KEY = diffie_hellman.getKEY();

  cout << "... ALICE got the KEY for encryption: " << KEY << endl;


  ClientSocket_secure client_socket(BOB_HOST, BOB_PORT, KEY);
  string data = "";
  string reply = "";

  do {

    cout << "... ALICE: enter data to send (end with quit)> ";
    getline(cin, data);

    try {
      cout << "... ALICE: sending <" << data << ">" << endl;

      client_socket << data;
      client_socket >> reply;

      cout << "... ALICE: received: <" << reply << ">" << endl;
    } catch (SocketException &) {
    cerr << "error: SocketException ..." << endl;
    exit(1);
    }
  } while (data != "quit");


  cout << "ALICE finished ...." << endl;

  return 0;
}
