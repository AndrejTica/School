
//demo_punktstrich.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// child und parent verwenden diese Funktion
void arbeite(char*);

int main() {
    int i = 0;
    int status;

    // -------------------------------
    // Prozess erzeugen
    // -------------------------------
    status= fork(); 


    // -------------------------------
    // CHILD
    // -------------------------------
    if (status == 0) {
       arbeite(".");
    }
    
    // -------------------------------
    // PARENT
    // -------------------------------
    else if (status > 0) 
       arbeite("-");

    else
       printf("\nERROR: Kein Child erzeugt!!\n");

    return 0;
}

void arbeite(char *s) {
    while(1) {
        printf("%s", s);
    }

}

// gcc punktstrich.c -o punktstrich.exe; ./punktstrich.exe
