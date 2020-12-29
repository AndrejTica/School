/*

Geändert von Gregor Bachinger am 1.April.2015
Die Server-Bibliothek wurde so umgeschrieben, dass sie mit der
Winsock2 API funktioniert. Außerdem zu Debug-Zwecken eine Funktion
eingebaut, um mehrere Nachrichten vom Client zu senden ohne diesen
schließen zu müssen.

Alle Programme wurden mit Visual Studio 2015 compiliert und getestet.
Zielplattform: 8.1
Platform Toolset: Visual Studio 2015(v140)

*/

#include "ServerSocket.h"
#include "SocketException.h"
#include <string>

//ht
#include <iostream>
using namespace std;


// ht
int main(int argc, char* argv[]) {

	try {
		// Create the socket
		ServerSocket server(30000);
		std::cout << "running.... port " << 30000 << endl;

		while (true) {

			ServerSocket new_sock;
			server.accept(new_sock);

			try {
				while (true) {
					std::string data;
					new_sock >> data;

					cout << "SERVER: got <" << data << ">" << endl;
					new_sock << data;
				}
			} catch (SocketException&) {}

		}
	} catch (SocketException& e) {
		std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}

	return 0;
}
