// demo_lock.c 
// implement critical section using lock-files 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <unistd.h> 

#define LOCKDIR "/tmp/" 
#define MAX_LOCKNAME 5+64+1 
#define MAX_ATTEMPTS 10 
#define SLPTIME (unsigned int)1 


/* Lock-File in Besitz bringen */ 
int lock(char* name){ 
	int fd; 
	int nAttempts; 
	char full_lockname[MAX_LOCKNAME]; 

	// absolute path of the lock-file: 
	// /tmp/..... erstellen 
	strcpy(full_lockname, LOCKDIR); 
	strncat(full_lockname, name, 64); 

	// try to create lock-file 
	nAttempts = 1; 
	fd = open(full_lockname, O_WRONLY|O_CREAT|O_EXCL,0666); 
	while (fd==-1 && errno==EEXIST){ 
		// lockfile exists-> so try again 

		if (nAttempts >= MAX_ATTEMPTS) 
			 return -nAttempts; 
	 
		 
		sleep(SLPTIME); 
		nAttempts++; 
		fd = open(full_lockname, O_WRONLY|O_CREAT|O_EXCL,0666);	 
	} 
	 
	return nAttempts; 
} 

/* Lock-File freigeben */ 
void unlock(char* name) { 
	char full_lockname[MAX_LOCKNAME]; 

	// absolute path of the lock-file: 
	// /tmp/..... erstellen 
	strcpy(full_lockname, LOCKDIR); 
	strncat(full_lockname, name, 64); 

	if (unlink(full_lockname) == -1) { 
		fprintf(stderr, "Error: unlock().\n"); 
		exit(1); 
	} 
} 


int main(int argc, char* argv[]){ 
	char lockname[128]; 
	int  pid, i, l, nLoops; 
	int ret_lock; 
	 
	if (argc != 4) { 
		fprintf(stderr, "usage: %s processname lock-filename nLoops\n", argv[0]); 
		exit(1); 
	} 

	strcpy(lockname, argv[2]); 
	nLoops = atoi(argv[3]); 


	for (i=0; i<nLoops; i++) { 
		// TRY LOCK 
		printf("\n%s: TRY to ENTER critical section", argv[1]); 
		printf(" (nLoop=%2i Lock-File=%s)", i, lockname); 
		fflush(stdout); 
		 
		ret_lock = lock(lockname); 
		if (ret_lock < 0) { 
			fprintf(stderr,"%2i attempts failed to create Lock-File %s\n", 
				ret_lock, lockname);    
			exit(1); 
		} 
		 
		// critical section 
		printf("\n%s: IN critical section", argv[1]); 
		printf(" (nLoop=%2i locking-attempts=%2i)",  i, ret_lock); 
		fflush(stdout); 
		 
		//UNLOCK 
		unlock(lockname); 
		printf("\n%s: LEFT critical section", argv[1]); 
		printf(" (nLoop=%2i Lock-File=%s)", i, lockname); 
		fflush(stdout); 

		sleep(2); 
	}/*for*/ 
	 
	printf("\n\n"); 
	return 0; 
} 