#include "ServerSocket_secure.h"
#include "SocketException.h"

#include <iostream>
#include <string>

#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// ht
const int port = 4444;
const int key = 1;

int main(int argc, char *argv[]) {

  try {
    // Create the socket
    ServerSocket_secure server(port, key);
    cout << "running on port " << port << "...." << endl;

    while (true) {
      ServerSocket_secure new_sock(key);
      server.accept(new_sock);

      int pid = fork();
      if (pid == 0) { // child ----------------------------------------------
        try {
          bool quit = false;
          while (!quit) {
            string data;

            new_sock >> data;

            quit = (data == "quit" || data == "quit\r\n") ? true : false;
            std::cout << "Server got: <" << data << ">" << std::endl;

            new_sock << data;
          }

          std::cout << "Server closing connection..." << std::endl;

        } catch (SocketException &) {
        }

        exit(0);
      } else {
        // parent ------------------------------------------------------
        int state;
        waitpid(-1, &state, WNOHANG);
      }
    }

  } catch (SocketException &e) {
    std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
  }

  return 0;
}
