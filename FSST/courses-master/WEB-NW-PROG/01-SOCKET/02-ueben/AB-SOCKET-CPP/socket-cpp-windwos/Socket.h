// Definition of the Socket class

#pragma once

#include <sys/types.h>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <fcntl.h>

#pragma comment(lib, "Ws2_32.lib")

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;
const int MSG_NOSIGNAL = 0; // defined by dgame

static void WSAInit(void) {
	int err;
	WORD wVersionReg = MAKEWORD(2, 0);
	WSADATA wsaData;
	if (err = WSAStartup(wVersionReg, &wsaData) != 0) {
		printf("Fehler beim initialisieren der Winsock.dll!\n");
	}
}

class Socket {
public:
	Socket();
	virtual ~Socket();

	// Server initialization
	bool create();
	bool bind(const int port);
	bool listen() const;
	bool accept(Socket&) const;

	// Client initialization
	bool connect(const std::string host, const int port);

	// Data Transimission
	bool send(const std::string) const;
	int recv(std::string&) const;


	void set_non_blocking(const bool);

	bool is_valid() const { return m_sock != -1; }

private:

	int m_sock;
	sockaddr_in m_addr;


};

