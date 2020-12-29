#include "ClientSocket_secure.h"
#include "SocketException.h"
#include <iostream>
#include <string>
using namespace std;

// ht
const int port = 4444;
const int key = 1;

int main(int argc, char *argv[]) {
  try {

    ClientSocket_secure client_socket("localhost", port, key);

    string reply="";
    string data;

    do {

      cout << "enter data to send (end with quit)> ";
      //cin >> data;
      getline(cin, data);

      try {
        client_socket << data;
        client_socket >> reply;

        cout << "We received:" << endl << "\"" << reply << "\"" << endl;

      } catch (SocketException &) {
      }

    } while (data != "quit");

  } catch (SocketException &e) {
    std::cout << "Exception was caught:" << e.description() << "\n";
  }

  return 0;
}
