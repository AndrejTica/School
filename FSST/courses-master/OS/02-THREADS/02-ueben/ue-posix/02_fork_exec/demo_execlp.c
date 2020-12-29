// Prozessüberlagerung mit execlp(), ....
// demo_execlp.c

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 

int main(){
    int rv;

    printf("Demo: execlp(): Ausfuehrung von sort:\n");
    printf("   Bitte geben sie einzelne Textzeilen ein.\n");
    printf("   Diese werden nach <Ctrl-D> sortiert ausgegeben\n");

    rv = execlp("/usr/bin/sort", "sort", NULL);

    /* Fehlerfall!!: Dürfte eigentlich nicht mehr ausgeführt werden */
    printf("Fehler bei execlp");
    exit(1);
}

// gcc -o demo_execlp.exe demo_execlp.c; ./demo_execlp.exe
