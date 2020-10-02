/* 
 * pipe2.c: Demo: pipe, fork, fdopen 
 * PARENT: 
 *    fgets(stdin) 
 *    fputs(parent_out) → 
 * CHILD: 
 *    fgets(child_in) 
 *    fputs(newfile_out) 
 *
 * gcc pipe2.c -o pipe2.exe ; ./pipe2.exe pipe2-out.txt 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <fcntl.h> 

#define USAGE printf("usage : %s dateiname.txt\n",argv[0]); 
#define MAX 4096 

int main(int argc, char *argv[]){ 
	int fd[2],i, n; 
	pid_t pid; 
	char puffer[MAX]; 

	FILE *child_in, *parent_out, *newfile_out; 

	if(argc !=2) { USAGE; exit(0); } 

	/*Wir erstellen eine pipe*/ 
	if(pipe(fd) <0) { perror("pipe2: "); exit(0); } 


	/*Wir erzeugen einen neuen Prozess*/ 
	if((pid=fork()) < 0) { perror("pipe : "); exit(0); } 

	/* PARENT ==================================== */ 
	else if(pid > 0) { 
		close(fd[0]); /*Leseseite schliessen*/ 

		parent_out=fdopen(fd[1], "w"); 
		if(parent_out==NULL){ perror(" fdopen : "); exit(0); } 

		fputs("\nBitte einen Text: ", stdout); 
		fgets(puffer, MAX, stdin); /*Wir lesen von stdin */ 
		fputs(puffer, parent_out); /*Wir schreiben in die Pipe*/ 

		fclose(parent_out);
 
		wait(NULL);
	} 
	/* CHILD ==================================== */ 
	else { 
		close(fd[1]); /*Schreibseite schliessen*/ 

		child_in= fdopen(fd[0], "r"); 
		if(child_in == NULL) { perror(" fdopen : "); exit(0); } 

		newfile_out=fopen(argv[1], "a+"); 
		if (newfile_out == NULL){ perror("fopen : "); exit(0); } 

		fgets(puffer, MAX, child_in); /*Wir lesen aus der Pipe*/ 
		fputs(puffer, newfile_out);   /*und schreiben in die Datei*/ 


		fclose(newfile_out); 
		fclose(child_in);

		exit(0); 
	} 

	return 0; 
}

