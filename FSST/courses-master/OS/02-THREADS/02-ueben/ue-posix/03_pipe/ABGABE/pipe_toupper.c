/*
1.7.5.  Aufgabe: pipe_toupper.c   (SOLVED)
Erstellen Sie das Programm pipe-toupper.c, wobei
der Vaterprozess
schliesst Lesekanal und 
liest von der Tastaur Text ein (Ende mit "quit") und schreibt diesen in den Schreibekanal (inkl.EOS)
der Child-Prozess
schliesst den Schreibkanal und 
liest aus dem Lesekanal und 
wandelt das Gelesene in Grossbuchstaben um (toupper()) und 
schreibt den Text auf den Bildschirm
printf("                                        CHILD: %s\n", buf); fflush(stdout);
Der Kommunikationsbuffer soll 128 Bytes sein. D.h. während der Vaterprozess die Benutzereingabe liest und an den Childprozess weiter reicht, soll der Childprozesse die gelesenen Daten in Grossbuchstaben umwandeln und ausgeben.

Hinweis:
Verwenden Sie read(), write() zur Kommunikation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <sys/wait.h>

#include <unistd.h>


#define SIZE 128

int main(){
	int fd[2];
	int pid;

	char buf[SIZE];

	// pipe erzeugen
	if(pipe(fd)<0){ perror("error: pipe"); exit(1);}

	// fork
	pid=fork();
	if (pid < 0) { perror("error: fork"); exit(2);}
	else if(pid>0){
	// PARENT ------------------------------------------------------------------
		close(fd[0]);		

		write(0, "Text? ", strlen("Text? ") );
		fgets(buf, SIZE, stdin);
		buf[strlen(buf)-1]= '\0';  // enter löschen

//		printf("<%s>\n", buf);

		write(fd[1], buf, SIZE);
		
		close(fd[1]);

		wait(NULL);
	}else{
	// CHILD ------------------------------------------------------------------
		close(fd[1]);

		int len= read(fd[0], buf, SIZE);

		for (int i=0; i< strlen(buf); i++)
			buf[i]= toupper(buf[i]);

		printf("<%s>\n", buf);
		
		printf("\n");

		close(fd[0]);
				
		exit(0);
	}

	return 0;
}

