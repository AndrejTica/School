// a.hofmann 2004
// pipe-fork.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#define LESE_KANAL 0
#define SCHREIB_KANAL 1

// der Text soll vom Parent ->zum-> Child geschickt werden.
char *mes1 = "Hallo, Welt Nr.1";
char *mes2 = "Hallo, Welt Nr.2";
char *mes3 = "Hallo, Welt Nr.3";

int main(){
   char buf[128];
   int fd[2], k, pid;
   
/* Pipe oeffnen */
   if (pipe(fd) < 0) {
      perror("Fehler bei pipe");
      exit(1);
   }

   /* Child-Prozess erzeugen */
   if ((pid = fork()) < 0) {
      perror("Fehler bei fork");
      exit(1);
   }

   /* Parent-Prozess: 
	 1. Leseseite der Pipe schliessen und 
	 2. in die Pipe schreiben */
   else if (pid > 0) { /* PARENT ===================== */
      int status;

      close(fd[LESE_KANAL]);

      write(fd[SCHREIB_KANAL], mes1, strlen(mes1));    //inkl EOS
      write(fd[SCHREIB_KANAL], mes2, strlen(mes2));
      write(fd[SCHREIB_KANAL], mes3, strlen(mes3)+1);

      close(fd[SCHREIB_KANAL]);

      wait(&status);

   }

   /* Child-Prozess: 
	 1. Schreibseite der Pipe schliessen und 
	 2. von der Pipe lesen */
   else if (pid == 0) { /* CHILD ===================================*/

      int len;
      close(fd[SCHREIB_KANAL]);

      len=read(fd[LESE_KANAL], buf, sizeof(buf));


      printf("%s\n%d Bytes gelesen!\nFrage: Warum wird nur die erste Zeile angezeigt?\n\n", buf, len);

      close(fd[SCHREIB_KANAL]);

      exit(1);
   }

	return 0;
}

// gcc pipe-fork.c -o pipe-fork.exe; ./pipe-fork.exe

