#include "ServerSocket.h"
#include "SocketException.h"
#include <string>

// ht
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <iostream>
using namespace std;

// ht
int main(int argc, char *argv[]) {
  try {

    // Create the socket
    ServerSocket server(30000);
    std::cout << "running.... port " << 30000 << endl;

    while (true) { // i am a server

      ServerSocket new_sock;
      server.accept(new_sock);

      === ENTER CODE ===
      if (=== ENTER CODE ===) {
        // child ----------------------------------------------
        try {

          bool quit = false;
          while (!quit) {    // communicate with client
            string data;

            new_sock >> data;

            quit === ENTER CODE ===

            std::cout << "Server got: <" << data << ">" << std::endl;

            new_sock << data;
          }

          std::cout << "Server closing connection..." << std::endl;

        } catch (SocketException &) {
        }

        exit(0); // !!!! dont forget

      } else {
        // parent ------------------------------------------------------
        === ENTER CODE ===
      }

    } // while endless loop (i am a server)

  } catch (SocketException &e) {
    std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
  }

  return 0;
}
