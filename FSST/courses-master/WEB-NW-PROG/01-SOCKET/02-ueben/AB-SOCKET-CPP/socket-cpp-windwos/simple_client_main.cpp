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

#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {


	try {

		ClientSocket client_socket("127.0.0.1", 30000);

		std::string reply;

		std::cout << "Simple Client! Type a message to send to the Server. (Type '!!exit' to close the client)..." << std::endl;

		try {
			while (1) {
				std::string toSend;
				std::string toReceive;
				getline(std::cin, toSend);
				if (toSend == "!!exit") break;
				client_socket << toSend;
				client_socket >> toReceive;
				std::cout << "Received Message: " << toReceive << std::endl;
			}

		} catch(SocketException&) { }

	} catch (SocketException& e) {
		std::cout << "Exception was caught:" << e.description() << "\n";
	}

	return 0;
}

