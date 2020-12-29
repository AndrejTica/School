// Definition of the Socket class

#ifndef Socket_class
#define Socket_class

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//! bei Qt und windows
//! LIBS += C:/Qt/Qt5.8.0/Tools/mingw530_32/i686-w64-mingw32/lib/libws2_32.a
//!

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//! https://stackoverflow.com/questions/28027937/cross-platform-sockets
//!
#ifdef _WIN32
	/* See http://stackoverflow.com/questions/12765743/getaddrinfo-on-win32 */
	#ifndef _WIN32_WINNT
		#define _WIN32_WINNT 0x0501  /* Windows XP. */
	#endif
	#include <winsock2.h>
	#include <Ws2tcpip.h>


	static void WSAInit(void) {
		int err;
		WORD wVersionReg = MAKEWORD(2, 0);
		WSADATA wsaData;
		if (err = WSAStartup(wVersionReg, &wsaData) != 0) {
			//printf("Fehler beim initialisieren der Winsock.dll!\n");
		}
	}
#else
	/* Assume that any non-Windows platform uses POSIX-style sockets instead. */
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <netdb.h>  /* Needed for getaddrinfo() and freeaddrinfo() */
	#include <unistd.h> /* Needed for close() */
#endif


#include <string>
const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

#ifdef _WIN32
const int MSG_NOSIGNAL = 0; // defined by dgame
#endif

class Socket{
public:
	Socket();
	virtual ~Socket();

	// Server initialization
	bool create();
	bool bind ( const int port );
	bool listen() const;
	bool accept ( Socket& ) const;

	// Client initialization
	bool connect ( const std::string host, const int port );

	// Data Transimission
	bool send ( const std::string ) const;
	int recv ( std::string& ) const;

	void set_non_blocking ( const bool );
	bool is_valid() const { return m_sock != -1; }

private:
	int m_sock;
	sockaddr_in m_addr;
};

#endif
