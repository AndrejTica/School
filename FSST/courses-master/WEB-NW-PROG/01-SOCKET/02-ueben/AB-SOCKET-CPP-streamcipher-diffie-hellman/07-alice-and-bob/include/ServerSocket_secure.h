// ServerSocket_secure.h
// Definition of the ServerSocket_secure class

#pragma once

#include "Socket.h"

// !!!!!!!!!!!!!!!!!!!!!!
#include "cipherstream.h"
using namespace std;

class ServerSocket_secure : private Socket{
	public:
		ServerSocket_secure ( int port, int key );
		ServerSocket_secure ( int key );
		ServerSocket_secure (){};
// !!!!!!!!!!!!!!!!!!!!!!
		virtual ~ServerSocket_secure(){
			delete in;
			delete out;
		};

		const ServerSocket_secure& operator << ( const std::string& ) const;
		const ServerSocket_secure& operator >> ( std::string& ) const;

		void accept ( ServerSocket_secure& );

	private:
// !!!!!!!!!!!!!!!!!!!!!!
		CipherStream* out;
		CipherStream* in;

};

