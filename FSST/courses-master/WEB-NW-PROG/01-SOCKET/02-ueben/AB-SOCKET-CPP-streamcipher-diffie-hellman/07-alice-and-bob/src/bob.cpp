#include "ServerSocket_secure.h"
#include "SocketException.h"

#include <iostream>
using namespace std;

#include <sys/wait.h>

#include "DiffieHellman.h"

int main(int argc, char *argv[]) {
  cout << "BOB connects to trustcenter ...." << endl;
  // me     //partner
  DiffieHellman diffie_hellman(TRUSTCENTER_HOST, TRUSTCENTER_PORT, "BOB",
                               "ALICE");
  int KEY = diffie_hellman.getKEY();
  cout << "... BOB got the KEY for encryption: " << KEY << endl;

  // Create the socket
  ServerSocket_secure server(BOB_PORT, KEY);
  cout << "... BOB running on port " << BOB_PORT << "...." << endl;

  while (true) {
    ServerSocket_secure new_sock(KEY);
    server.accept(new_sock);

    int pid = fork();
    if (pid == 0) { // child ----------------------------------------------
      try {
        bool quit = false;
        while (!quit) {
          string data;

          new_sock >> data;

          quit = (data == "quit" || data == "quit\r\n") ? true : false;
          std::cout << "... BOB got: <" << data << ">" << std::endl;

          new_sock << data;
        }

        std::cout << "BOB closing connection..." << std::endl;

      } catch (SocketException &) {
      }

      exit(0);
    } else {
      // parent ------------------------------------------------------
      int state;
      waitpid(-1, &state, WNOHANG);
    }
  } // while

  return 0;
}
