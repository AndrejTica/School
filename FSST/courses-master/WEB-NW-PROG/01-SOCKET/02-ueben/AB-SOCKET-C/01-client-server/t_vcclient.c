/*
 * t_ vcclient.c 	TCP client (Virtual Circiut)
 * anton hofmann 9.6.97
 * ./t_vcclient.exe hostname port#
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h> 	/* sockaddr_in socket-address internet-style 	*/
#include <netdb.h>		/* /etc/hosts table entries			*/
#include <arpa/inet.h>

#define DATA	"Dinner is ready when the smoke alarm goes off.\n"

int main (int argc, char * argv[]){
	int sd;				/* socket descriptors	*/
	struct sockaddr_in	name;	/* Internet socket name	*/
	struct hostent*	hp;		/* host entry		*/

	/* 1. create a client socket */
	/* ------------------------- */
	sd = socket (AF_INET, SOCK_STREAM,0);
	if (sd < 0) {	
		perror ("INET Domain Socket"); exit(1);
	}

	/* 2. init fields in an internet address structure */
	/* ----------------------------------------------- */
	name.sin_family	= AF_INET;
	name.sin_port	= htons(atoi (argv[2]));	/* system binds a port#	*/

	hp= gethostbyname (argv[1]);

	memcpy (&name.sin_addr.s_addr, hp->h_addr, hp->h_length);

	/* 3. connect to server */
	/* -------------------- */
	if ( connect (sd, (struct sockaddr*)&name, sizeof(name)) < 0) {
	  perror ("INET Domain Connect"); exit(2);
	}

	write (sd, DATA , sizeof(DATA));
	close(sd);	
	return 0;
}
