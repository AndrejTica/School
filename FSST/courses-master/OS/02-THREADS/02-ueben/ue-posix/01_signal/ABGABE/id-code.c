/* Datei: id-code.c Hofmann Anton
 * 
 * Demo: Zeiger auf Funktionen und Interprocess Communication
 * Read with timeout 
 */ 
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 

int toolong; 
int count; 

void wakeup(int signum){
    toolong=1;
    count++;

    #ifdef DEBUG 
    printf("wakeup was called\n"); fflush(stdout); 
    #endif 
    
    alarm(10); 
}

int main(){ 
    int idcode; 
    
    //Pointer,um die Adresse der 'alten' Alarmfunktion zu speichern. 
    void (*alrm_func)(); 

    while(1) { 
        printf("Wie lautet Ihr ID-CODE ? "); 
        toolong= 0; 

		// setze das Alarmsignal auf wakeup() und 
		//speichere den alten Zeiger alrm_func. 
        alrm_func= signal(?????????, ???????????); 

        /* setze den Alarm-Timer */ 
        alarm(10); 

        /* lies ID-CODE */ 
        scanf("%d", &idcode); 

        /* ID-CODE wurde ohne timeout eingeben->verlasse Schleife */ 
        if (toolong == 0) break; 

        if (count == 1) /* Antwort auf ersten timeout */ { 
            printf("\nIhren ID-CODE finden Sie auf Ihrer ID-KARTE.\n"); 
            fflush(stdout); 
        } 
        else { 
            printf("\nFragen Sie im Sekretariat nach einer neuen "); 
            printf("ID-KARTE, \nfalls sie verloren gegangen ist.\n"); 
            exit(1); /* PROGRAMMABBRUCH */ 
        } 
    } /* end_while */ 


    /* setze das Alarmsignal wieder zurueck*/
    signal(????????????, ??????????????); 
    alarm(0); 

    printf("\nID-CODE: %d\n", idcode); 

    return 0;
}