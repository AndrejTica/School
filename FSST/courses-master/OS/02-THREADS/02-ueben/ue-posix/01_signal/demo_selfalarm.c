// a.hofmann
// demo_selfalarm.c

#include <stdio.h>
#include <stdlib.h> 

#include <unistd.h>

int main(int argc, char * argv[]){
    if (argc==1){
        printf("usage: selfalarm.exe #"); exit(1);
    }

    alarm(10);    //nach 10 sekunden, bricht das Programm ab

    while(1)
        printf("%s", argv[1]);

	return 0;
}

// gcc demo_selfalarm.c -o demo_selfalarm.exe
// starte mit: 
// ./demo_selfalarm.exe 1 & ./demo_selfalarm.exe 0
