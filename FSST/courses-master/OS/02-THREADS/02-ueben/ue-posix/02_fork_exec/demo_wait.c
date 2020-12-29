// demo_wait.c
// 2 unabh. prozesse starten: fork-> execlp | wait

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

int main() {
   int pid;
   printf("Demo: fork(), execlp(), wait(): Ausfuehrung von sort\n");
   printf("   Bitte geben sie einzelne Textzeilen ein.\n");
   printf("   Diese werden nach <Ctrl-D> sortiert ausgegeben\n");

   pid = fork();

   /* Parent-Prozeß ----------------------  */
   if (pid > 0) {
      int status;
      
      wait(&status); /* wartet, bis Child fertig */

      printf("PARENT-Process: CHILD is ready & returned: %i\n", status);
      exit(0);
   }

   /* Child-Process ----------------------- */
   if (pid == 0) {

      execlp("/usr/bin/sort", "sort", NULL);

      /* Fehlerfall */
      printf("Fehler bei execlp");
      exit(1);
   }

}
// gcc -o demo_wait.exe demo_wait.c ; ./demo_wait.exe
