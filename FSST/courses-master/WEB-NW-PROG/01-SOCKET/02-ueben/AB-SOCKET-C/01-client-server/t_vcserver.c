/*
 * t_vcserver.c 	TCP server (Virtual Circiut)
 * anton hofmann 9.6.97
 * ./t_vcserver &
 * prints out hostname and portname, which should be used by (t_vcclient.exe)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h> 	/* sockaddr_in socket-address internet-style 	*/
#include <netdb.h>			/* /etc/hosts table entries			*/
#include <arpa/inet.h>

int main (int argc, char * argv[]){
	int rc;			/* system call return code	*/
	int sd, ld;		/* server/listen descriptors	*/
	int addrlen, nbytes;	/* sockaddr length; read nbytes	*/

	struct sockaddr_in	name;	/* Internet socket name	*/
	struct sockaddr_in*	ptr;	/* pointer to get port number	*/
	struct sockaddr		addr;	/* generic socket name		*/

	char 		buf[256];	/* basic I/O buffer		*/
	struct hostent*	hp;		/* host entry			*/


	/* 1. create a listen socket */
	/* ------------------------- */
	ld = socket (AF_INET, SOCK_STREAM,0);
	if (ld < 0) {	
		perror ("INET Domain Socket"); exit(1);}


	/* 2. init fields in an internet address structure */
	/* ----------------------------------------------- */
	name.sin_family	= AF_INET;
	name.sin_port	= htons(0);			/* system binds a free port# */
	name.sin_addr.s_addr= INADDR_ANY;	/* wildcard accept		*/




	/* 3. bind the internet address to the internet socket	*/
	/* ---------------------------------------------------- */
	if (bind (ld, (struct sockaddr*)&name, sizeof (name)) < 0) {	
		perror ("INET Domain Bind"); exit(2);}


	/* 4. find out the port number assigned to our socket	*/
	/* ---------------------------------------------------- */
	addrlen= sizeof (addr);	/* need int to store return value */
	if ((rc= getsockname (ld, (struct sockaddr*) &addr, (socklen_t*)&addrlen))< 0){	
		perror ("INET Domain getsockname"); exit(3);}


	ptr= (struct sockaddr_in *) &addr;
	printf ("\n\tSocket has port number: #%d\n", htons(ptr->sin_port));

	
	/* 5. mark socket as passive listen socket */
	/* --------------------------------------- */
	if ( listen(ld, 5) < 0) {
		perror ("INET Domain Listen"); exit(4);}

	while (1){
		/* 6. wait and answer */
		/* ------------------ */
		sd= accept (ld, (struct sockaddr*) &addr, (socklen_t*) &addrlen);
		if ( sd < 0){
			perror ("INET Domain Accept"); exit(5);}

		
		/* 7. find out who's calling us ..... */
		/* ---------------------------------- */
		rc = getpeername (sd, (struct sockaddr*) &addr, (socklen_t*)&addrlen);
		if ( rc < 0){
			perror ("INET Domain getpeername"); exit(6);}
		

	/**/	ptr= (struct sockaddr_in *) &addr;
	/**/	/* announce the caller, just for our example	*/
	/**/	printf ("%s", "\n>>>--SERVER-LOG-BEGIN------->>>");
	/**/	printf("\n     REMOTE HOST: %s", inet_ntoa (ptr->sin_addr));
	/**/	printf (" (port number #%d)\n", ptr->sin_port);
	/**/
	/**/	if ((hp= gethostbyaddr ((char*)&ptr->sin_addr, 4, AF_INET)) != NULL) {
	/**/		printf ("     REMOTE hostname: %s\n     With aliases: ",hp->h_name);
	/**/		while (*hp->h_aliases)
	/**/			printf("     %s\n", *hp->h_aliases++);
	/**/	}
	/**/	else {
	/**/		perror ("\n\tgethostbyaddr() faild");
	/**/		printf ("\n\th_errno is %d\n\n", h_errno);
	/**/	}
    /**/	printf ("%s", "\n>>>--SERVER-LOG-END------->>>\n");

		
		do
		{
		  memset (buf, 0, sizeof(buf));
		  nbytes= read (sd, buf, sizeof (buf));

		  if ( nbytes < 0){
		    perror ("INET Domain Read"); exit(7);}

		  else if (nbytes == 0)
		    printf ("\nClosing connection ....\n");
		  else
		    printf ("\nReceived: %s\n", buf);
		}while (nbytes != 0);
		
	    close(sd);
	}//while accept
	return 0;
}//main

