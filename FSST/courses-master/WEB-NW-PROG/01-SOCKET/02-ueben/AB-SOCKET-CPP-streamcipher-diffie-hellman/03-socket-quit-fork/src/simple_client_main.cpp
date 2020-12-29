#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  try {

    ClientSocket client_socket("localhost", 30000);

    std::string reply;

    try {
      client_socket << "===TEST MESSAGE===";
      client_socket >> reply;
    } catch (SocketException &) {
    }

    cout << "We received:" << endl << "\"" << reply << "\"" << endl;

  } catch (SocketException &e) {
    std::cout << "Exception was caught:" << e.description() << "\n";
  }

  return 0;
}
