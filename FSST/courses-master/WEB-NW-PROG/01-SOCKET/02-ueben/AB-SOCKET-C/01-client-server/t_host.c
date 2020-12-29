/*
 t_host.c
 anton hofmann 6.6.97
 t_host.exe www 141.201.53.20 info.sbg.ac.at localhost
 gcc -s -O -o t_host.exe t_host.c -lsocket -lnsl

 Host entries are represented by the struct hostent structure
 defined in <netdb.h>:

 struct hostent {
   char   *h_name;          canonical name of host 
   char   **h_aliases;      alias list 
   int    h_addrtype;       host address type 
   int    h_length;         length of address 
   char   **h_addr_list;    list of addresses 
 };



 * Internet address defined in <netinet/in.h>
 *      This definition contains obsolete fields for compatibility
 *      with SunOS 3.x and 4.2bsd.  The presence of subnets renders
 *      divisions into fixed fields misleading at best.  New code
 *      should use only the s_addr field.

struct in_addr {
        union {
                struct { u_char s_b1, s_b2, s_b3, s_b4; } S_un_b;
                struct { u_short s_w1, s_w2; } S_un_w;
                u_long S_addr;
        } S_un;
#define s_addr  S_un.S_addr              should be used for all code 
#define s_host  S_un.S_un_b.s_b2         OBSOLETE: host on imp 
#define s_net   S_un.S_un_b.s_b1         OBSOLETE: network 
#define s_imp   S_un.S_un_w.s_w2         OBSOLETE: imp 
#define s_impno S_un.S_un_b.s_b4         OBSOLETE: imp # 
#define s_lh    S_un.S_un_b.s_b3         OBSOLETE: logical host 
};
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>     /* Internet addresses struct in_addr */
#include <arpa/inet.h>      /* inet (3N) function definitions    */
#include <netdb.h>          /* /etc/hosts data structure         */
 
int main(int argc, const char **argv){
	u_long addr;
	struct hostent *hp;
	char **p;
	int i;

	for (i=1; i< argc; i++){
		hp = gethostbyname(argv[i]);
		if (hp == NULL){

		/* inet_addr(): "a.b.c.a"  --> InternetAddress u_long */
		if ((int)(addr = inet_addr(argv[i])) == -1){
			printf("%s", "IP-address must be of the form a.b.c.d\n"); exit (2);
		}

		hp = gethostbyaddr((char *)&addr, sizeof (addr), AF_INET);
		if (hp == NULL) {
			printf("\nhost information for %s not found\n", argv[i]); exit (3);
		}
	}


	for (p = hp->h_addr_list; *p != 0; p++) {
		struct in_addr in;
		char **q;

		memcpy(&in.s_addr, *p, sizeof (in.s_addr));

		/* inet_ntoa(): struct in_addr --> "a.b.c.d" */
		printf("%s\t%s", inet_ntoa(in), hp->h_name);

		for (q = hp->h_aliases; *q != 0; q++)
			printf(" %s", *q);

		putchar('\n');
		}
	} 
	return 0;
}

/* Note:
  inet_addr(): "a.b.c.a"  --> InternetAddress u_long 
  inet_ntoa(): struct in_addr --> "a.b.c.d"
*/
