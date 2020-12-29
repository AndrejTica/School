// demo_pipe_dup_exec_sort.c
// Beispiel fuer pipe, dup, fork, exec 

#include <stdio.h> 
#include <stdlib.h> 

#include <unistd.h> 
#include <sys/types.h> 
#include <fcntl.h> 

#define MSG_SIZE 512 

// 2 pipes
// PARENT:                              CHILD:
//       ---> fdout[1] --- fdout[0] ---> 
//       <--- fdin[0]  --- fdin[1] <---
int fdout[2];
int fdin[2];

// use macros for better understanding
#define child_in fdout[0]
#define child_out fdin[1]

#define parent_in fdin[0]
#define parent_out fdout[1]
                


//   write (parent_out, ...) ----> read (child_in, ...) 
//   read (parent_in, ...)   <---- write (child_out, ...)


int sortieren(char* fname){ 
    int fdout[2];
    int fdin[2];

	int fd, nread; 
	char buf[MSG_SIZE]; 

	// PIPES 
	if (pipe(fdout) < 0 || pipe(fdin) < 0) { 
		perror("Fehler bei pipe"); 
		exit(1); 
	} 

    // FORK
	switch (fork()) { 
		case -1: /* Fehler */ 
			perror("Fehler bei fork"); 
			exit(1); 

	    // CHILD: richtet eine pipe zw. parent und unix utility sort ein
		case  0: 
		// schliesst stdin, stdout 
		// 
		// dadurch werden die filedeskriptoren 0 und 1 frei 
		// 
		// beim nächsten dup() 
		// werden diese freien filedeskriptoren vom System 
		// wieder verwendet. 
		// 
		// Dadurch werden (s.u.), die mit dup() duplizierten 
		//      child_in an filedeskriptor 0 und 
		//      child_out an filedeskriptor 1 gebunden 
		// 
		// dies ist ideal für den mit execlp() aufgerufenen 
		// sort-Befehl, da dieser 
		// mit stdin und stdout arbeitet. 
		// 
		// D.h. 
		// Die Ausgabe des PARENT wird an die stdin des Sort-Befehls
		// und 
		// Die Eingabe des PARENT wird an die stdout des Sort-Befehls
        // gebunden 
		// 
		// die standardkanäle des sort-prozesses sind mit den zuvor 
		// duplizierten Kanälen verbunden. d.h. 

		// ein read(0,buf,len) des sort-prozesses liest 
		// tatsächlich vom 
		//     parent2child[0] 

		// ein write(1,buf,len) des sort-prozesses schreibt 
		// tatsächlich nach 
		//     child2parent[1] 
		// 
		// nun kommuniziert d. Parent direkt mit d. externen Programm sort



		//stdin schliessen 
		close(0);
		dup(child_in);
		 
		//stdout schliessen 
		close(1);
		dup(child_out);

		//werden nicht mehr gebraucht, da sort den child überlagert 
		close(parent_out); 
		close(parent_in); 
		close(child_in); 
		close(child_out); 

		execlp("/usr/bin/sort", "sort", NULL); 


	// PARENT: 
		default: 
        // werden hier nicht gebraucht
		close(child_in); 
		close(child_out); 

		// FILE open
		if ((fd = open(fname, O_RDONLY)) < 0) { 
			perror("Fehler bei open"); 
			exit(1); 
		} 

        // FILE read
		while ((nread = read(fd, buf, sizeof(buf))) != 0) { 
			if (nread == -1) { 
				perror("Fehler bei read"); 
				exit(1); 
			} 

            // write to child/sort
			if (write(parent_out, buf, nread) == -1) { 
				perror("Fehler bei write auf Pipe"); 
				exit(1); 
			} 
		}//while 

		close(fd); 
		close(parent_out); 


		// sortierte Daten lesen 
		while((nread=read(parent_in, buf, sizeof(buf))) != 0){ 
			if (nread == -1) { 
				perror("Fehler bei read von Pipe"); 
				exit(1); 
			} 

			if (write(1, buf, nread) == -1) { 
				perror("Fehler bei write"); 
				exit(1); 
			} 
		} 

		close(parent_in); 
	}//switch 

	return 0; 
} 


int main(int argc, char* argv[]) { 
	if (argc < 2) { 
		fprintf(stderr, "Aufruf: %s file\n", argv[0]); 
		exit(1); 
	} 

	sortieren(argv[1]);

    // auch das geht
    // sortieren("/etc/passwd");

    return 0; 
} 

// Wir lassen das Programm seinen eigenen Quelltext sortieren. 
// gcc -o demo_pipe_dup_exec_sort.exe demo_pipe_dup_exec_sort.c 
// ./demo_pipe_dup_exec_sort.exe demo_pipe_dup_exec_sort.c 