// a.hofmann
// demo_fork.c 

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

void childs_code(); 
void parents_code(); 

int main() { 
	int i; 
	int pid= getpid(); 

	printf("\nJust one process till now: PID= %i", pid); 
	printf("\nCalling fork() in 5 sec ...\n"); 

	for(i=1; i<=5; i++){ 
		printf("%i sec, \n", i); 
		sleep(1); 
	} 

	switch(fork()){ 
		case  -1: exit(1); // error 
		case   0: childs_code(); break; 
		default: parents_code(); break; 
	} 
	 
	printf("\n\n"); 
	return 0; 
} 

void childs_code(){ 
	int pid= getpid(); 
	int i; 

	for (i=1; i<=10; i++){ 
		printf("\n                    CHILD: PID= %i i=%i\n", pid, i); 
		sleep(1); 
	} 
	
	exit(0);
} 

void parents_code(){ 
	int pid= getpid(); 
	int i=1; 

	for (i=1; i<=10; i++){ 
		printf("\nPARENT: PID= %i i=%i\n", pid, i); 
		sleep(1); 
	} 
} 

// gcc demo_fork.c -o demo_fork.exe; ./demo_fork.exe 
