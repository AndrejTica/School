/*
 * t_fileserver.c 	TCP server (Virtual Circiut)
 * anton hofmann 9.6.97
 * ./t_fileserver &
 *  prints out hostname and portname, which should be used by clients
 *  Anwendungsprotokoll
	  get filename
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h> 	/* sockaddr_in socket-address internet-style 	*/
#include <netdb.h>			/* /etc/hosts table entries			*/
#include <arpa/inet.h>

#define MSGSIZE 256


int main (int argc, char * argv[]) {
	int rc;			/* system call return code	*/
	int sd, ld;		/* server/listen descriptors	*/
	int addrlen, nbytes;	/* sockaddr length; read nbytes	*/

	struct sockaddr_in	name;	/* Internet socket name	*/
	struct sockaddr_in*	ptr;	/* pointer to get port number	*/
	struct sockaddr		addr;	/* generic socket name		*/

	char 		buf[MSGSIZE];			/* basic I/O buffer		*/
	struct hostent*	hp;		/* host entry			*/


	/* 1. create a listen socket */
	/* ------------------------- */
	ld = socket (AF_INET, SOCK_STREAM,0);
	if (ld < 0) {	
		perror ("INET Domain Socket"); exit(1);}


	/* 2. init fields in an internet address structure */
	/* ----------------------------------------------- */
	name.sin_family	= AF_INET;
	name.sin_port	= htons(0);		/* system binds a free port#	*/
	name.sin_addr.s_addr= INADDR_ANY;	/* wildcard accept		*/


	/* 3. bind the internet address to the internet socket	*/
	/* ---------------------------------------------------- */
	if (bind (ld, (struct sockaddr*)&name, sizeof (name)) < 0) {	
		perror ("INET Domain Bind"); exit(2);}


	/* 4. find out the port number assigned to our socket	*/
	/* ---------------------------------------------------- */
	addrlen= sizeof (addr);	/* need int to store return value */
	if ( (rc= getsockname (ld, &addr, &addrlen)) < 0){	
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
		sd= accept (ld, &addr, &addrlen);
		if ( sd < 0){
			perror ("INET Domain Accept"); exit(5);}

		
		/* 7. find out who's calling us ..... */
		/* ---------------------------------- */
		rc = getpeername (sd, &addr, &addrlen);
		if ( rc < 0){
			perror ("INET Domain getpeername"); exit(6);}
		

	/**/	/* announce the caller, just for our example	*/
	/**/	puts ("\n>>>--SERVER-LOG-BEGIN------->>>");
	/**/	printf("\n     REMOTE HOST: %s", inet_ntoa (ptr->sin_addr));
	/**/	printf (" (port number #%d)\n", htons(ptr->sin_port));
	/**/
	/**/	if ((hp= gethostbyaddr ((char*)&ptr->sin_addr, 4, AF_INET)) != NULL) {
	/**/		printf ("     REMOTE hostname: %s\n     With aliases: ",hp->h_name);
	/**/		while (*hp->h_aliases)
	/**/			printf("\n     %s", *hp->h_aliases++);
	/**/		printf("\n");
	/**/	}
	/**/	else {
	/**/		perror ("\n\tgethostbyaddr() faild");
	/**/		printf ("\n\th_errno is %d\n\n", h_errno);
	/**/	}
    /**/	printf ("\n>>>--SERVER-LOG-END------->>>\n");
	

		
		// -----------------------------
		// 1. Anwendungsprotokoll
		// get filename
		  nbytes= read (sd, buf, MSGSIZE);

		  if ( nbytes < 0){
		    perror ("INET Domain Read"); 
		    exit(7);
		  }
		  else if (nbytes == 0){
		    printf ("\nClosing connection ....\n");
		    close(sd);
		  }
		  else{
			// ------------------------------
			// OK go and read and send the file
    			FILE* fp;

	    		fp=fopen(buf+4, "r"); // überlies get_ 
    			if (fp == NULL){
					strcpy(buf, "\n-1 File not found\n");
			   		write (sd, buf , MSGSIZE);
				}
				else{ // read and send the file
					char *ret;
					while (fgets(buf, MSGSIZE, fp)){						
						write (sd, buf, MSGSIZE);
					}//while

					fclose (fp);
				}//else		

			
			// unbedingt den socket wieder schliessen
			close (sd);
		}//else

	}//while(1) mit accept()
}//main

