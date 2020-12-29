// demo_pipe_fork.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define pipe_in fd[0]
#define pipe_out fd[1]

#define MSG_SIZE 128

// der Text soll vom Parent ->zum-> Child geschickt werden.
char mes1[MSG_SIZE] = "Hallo, Welt Nr.1";
char mes2[MSG_SIZE] = "Hallo, Welt Nr.2";
char mes3[MSG_SIZE] = "Hallo, Welt Nr.3";

int main()
{
   char buf[MSG_SIZE];
   int fd[2]; // pipe
   pid_t pid;

   // PIPE
   if (pipe(fd) < 0)
   {
      perror("Fehler bei pipe");
      exit(1);
   }

   // FORK
   if ((pid = fork()) < 0)
   {
      perror("Fehler bei fork");
      exit(1);
   }

   // PARENT =====================
   //  1. fd[0] schliessen und
   //  2. in fd[1] schreiben
   else if (pid > 0)
   {

      close(pipe_in);

      write(pipe_out, mes1, MSG_SIZE);
      write(pipe_out, mes2, MSG_SIZE);
      write(pipe_out, mes3, MSG_SIZE);

      close(pipe_out);

      wait(NULL);
   }

   //CHILD ===================================
   //  1. fd[1] schliessen und
   //  2. von fd[0] lesen
   else if (pid == 0)
   {

      int len;

      close(pipe_out);

      len = read(pipe_in, buf, MSG_SIZE);
      printf("%i Bytes gelesen: <%s>\n", len, buf);

      len = read(pipe_in, buf, MSG_SIZE);
      printf("%i Bytes gelesen: <%s>\n", len, buf);

      len = read(pipe_in, buf, MSG_SIZE);
      printf("%i Bytes gelesen: <%s>\n", len, buf);

      close(pipe_in);

      exit(EXIT_SUCCESS);
   }

   return 0;
}

// gcc demo_pipe_fork.c -o demo_pipe_fork.exe; ./demo_pipe_fork.exe
/* output:
128 Bytes gelesen: <Hallo, Welt Nr.1>
128 Bytes gelesen: <Hallo, Welt Nr.2>
128 Bytes gelesen: <Hallo, Welt Nr.3>
*/