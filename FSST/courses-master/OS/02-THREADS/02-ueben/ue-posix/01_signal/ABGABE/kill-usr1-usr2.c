/*
1.3.5.  Aufgabe: kill-usr1-usr2.c (SIGUSR1, SIGUSR2)
Mit dem Shell-Kommando kill (man kill) kann man von der Shell aus Programmen Signale schicken. Oft werden hier die Signale USR1 bzw. USR2 verwendet. Hier ein Beispiel:

Aufruf:
$> ./kill-usr1-usr2.exe &
[1]     4720

$> kill -USR1  4720
received SIGUSR1


$> kill -USR2  4720
received SIGUSR2


$> kill 4720

Bringen Sie das folgende Programm kill-usr1-usr2.c zum Laufen:
/* Datei: kill-usr1-usr2.c
 * demo signal()
 * gcc kill-usr1-usr2.c -o kill-usr1-usr2.exe
 * aufruf: ./kill-usr1-usr2.exe &
 * [1]     4720
 * $ kill -USR1  4720
 * $ kill -USR2  4720
 * $ kill  4720
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>


int main(){
	
	// ENTER CODE

	for (;;)
    		pause(); 
		// pause() forces a process to pause until a signal is received
	
	return 0;
}
