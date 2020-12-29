#include "ServerSocket.h"
#include "SocketException.h"
#include <string>

//ht
#include <iostream>
using namespace std;


// ht
int main ( int argc, char* argv[] )
{

  try
    {
      // Create the socket
      ServerSocket server ( 30000 );
      std::cout << "running.... port " << 30000<<endl;

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;

          cout << "SERVER: got <" << data << ">" << endl;
		  new_sock << data;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
