
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <winsock2.h>

/*************************Socket-DLL initialisieren ************************/

void WSAInit(void) 
{
	int err;
	//struct that contains info about windows socket
	WSADATA wsaData; 
	WORD sdsd;
	// Initialize Winsock dll
	//MAKEWORD is a macro to set the version of winsock -> 2.0
	//also needs an address of the wsaData struct
	//returns a 0 if successful
	err = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (err != 0)
	{
		printf("Fehler beim initialisieren der winsock.dll\n");
	}

	printf("Winsock initialisiert\n");

}

//hostent is used by functions to store info about our host, such as host name, IP-Adress and so on
struct hostent* getHostEntry(const char*);

#define DATA "Dinner is ready when the smoke alarm goes off.\r\n"


int main(int argc, char** argv) 
{

	int sd; //socker descriptor. A socket is just a number that is internally linked to a address (server address)
	struct sockaddr_in server_address; //internet socket name or practically the server address
	struct hostent* hp; //host entry. Here all out system stuff is stored 
	
	WSAInit();

	/**************** 1. create a client socket ***************/

	//AF_INET means internet socket. We could connect with a different server
	//SOCK_STREAM means its a TCP socket (Connection oriented) not UDP (dataframm)
	//dont question the 0
	sd = socket(AF_INET, SOCK_STREAM, 0); 

	/****************2. Setup the client socket****************/
	
	//specify address family, same as above
	server_address.sin_family = AF_INET; 
	//specify port. Could be any free port. We need to use htons because the
	//way the bytes are stores is different from TCP protocoll than it is on PC.
	//What is different is the order of the bytes. TCP uses big-endian, our PC little-endian.
	//In TCP sense big-endian is called network order and little-endian host order
	//the function htons converts host order to network order.
	//in our case we input a port number with command line.
	// We need atoi to convert from string to int
	server_address.sin_port = htons(atoi(argv[2]));

	hp = getHostEntry(argv[1]); 
	if (hp == NULL) {
		perror("ERROR: getHostEntry()"); exit(1);
	}
	//we copy the address inside hostent and set it as the socket address (server address).
	//The macro h_addr is defined to be h_addr_list[0]
	memcpy(&server_address.sin_addr.s_addr, hp->h_addr, hp->h_length); 

	/************* 3. connect to server **********************/

	//connect takes in the socket itself (sd),
	//the information about the socket (server_address) but its needs to be cast because conncect demands it
	//at the end the sizeof our socket info
	//if it returns 0 it worked
	int conncetion_status = connect(sd, (struct sockaddr*)&server_address, sizeof(server_address));
	if (conncetion_status < 0)
	{
		printf("Error with connect");
	}

	send(sd, DATA, sizeof(DATA), 0);
	closesocket(sd);
	WSACleanup();

	return 0;
}

//nur da damit wir auch domain angeben koennen
struct hostent* getHostEntry(const char* pHost)

{
	struct hostent* hp;
	u_long addr;

	//gethostbyname sets the hostent struct data to the argument we pass in
	//in our case we pass in a command line arg
	//getHostName is just there to fill in the hostent struct
	
	hp = gethostbyname(pHost);
	if (hp == NULL)
	{
		//is the entered ip address valid? If not inet_addr converts it into proper form
		if ((int)(addr = inet_addr(pHost)) == -1) //if its not a name
		{
			return NULL;
			//wir haben bullshit eingegeben
		}

		hp = gethostbyaddr((char*)&addr, sizeof(addr), AF_INET); //10.0.0.1
		return hp;
	}
	return hp;
}