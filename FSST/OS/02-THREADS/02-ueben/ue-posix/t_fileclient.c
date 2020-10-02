/*
 * t_fileclient.c 	TCP client (Virtual Circiut)
 * anton hofmann 9.6.97
 * ./t_fileclient.exe hostname port#
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h> 	/* sockaddr_in socket-address internet-style 	*/
#include <netdb.h>			/* /etc/hosts table entries			*/

#define MSGSIZE 256

int main (int argc, char * argv[])
{
	char input[MSGSIZE];
	int anz;

	int sd;						/* socket descriptors	*/
	struct sockaddr_in	name;	/* Internet socket name	*/
	struct hostent*	hp;			/* host entry		*/

	if (argc < 3){
		fprintf(stderr,"usage: %s hostname port#\n", argv[0]);
		exit(1);
	}

	while(1){

		/* 1. create a client socket */
		/* ------------------------- */
		sd = socket (AF_INET, SOCK_STREAM,0);
		if (sd < 0) {	
			perror ("INET Domain Socket"); exit(1);
		}

		/* 2. init fields in an internet address structure */
		/* ----------------------------------------------- */
		name.sin_family	= AF_INET;
		name.sin_port	= htons(atoi (argv[2]));
		hp= gethostbyname (argv[1]);
		memcpy (&name.sin_addr.s_addr, hp->h_addr, hp->h_length);

		/* 3. connect to server */
		/* -------------------- */
		if ( connect (sd, (struct sockaddr*)&name, sizeof(name)) < 0) {
		  perror ("INET Domain Connect"); exit(2);
		}

		printf("\n>>>%s", "CLIENT (get filename | ENDE mit quit)> ");
		gets(input);
		if (strcmp(input,"quit")==0){
			close(sd);
			exit(1);
		}

		// Befehl versenden: zB: "get /etc/passwd"
		write (sd, input , MSGSIZE);

		//- File vom Server lesen und auf stdout ausgeben
		do {
			anz= read(sd, input, MSGSIZE);
			if (anz!=0) printf("%s", input);
		}while (anz != 0);

		close(sd);

	} //while (1)

	return 0;	
}

