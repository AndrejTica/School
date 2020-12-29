/*
 * AUTHOR: 
 * DATE:
 * FILE: test-fifo.c
  
1.4.2. Aufgabe: Modul fifo, Ein Ringschlangen-Speicher
Eine Ringschlange od. Fifo od. Queue ist eine Datenstruktur, 
die aus einem Array besteht und 2 sog. Zeiger hat. 
- Einer zeigt auf den Anfang: begin
- Einer zeigt auf das Ende: end

Die Ringschlange unterstützt u.a. folgende Funktionen:

- void enqueue(int value);
	fügt den Wert value in die Ringschlange

- int dequeue(void)
	löscht einen Wert aus der Ringschlange und gibt diesen zurück

Die Ringschlange arbeitet nach dem FIFO-Prinzip.

Der Name Ringschlange kommt daher, weil folgendes gelten muss:
- wenn begin == end ... dann ist die Ringschlange leer

- beim Einfügen(enqueue) 
	wird der Wert an der Stelle des end-Zeigers gespeichert. 
	Dann wird der end-Zeiger erhöht.
	Wenn der end-Zeiger das Arrayende erreicht hat, wird der 
	end-Zeiger wieder auf 0 gesetzt.
	Aber ACHTUNG: der end-Zeiger darf den begin-Zeiger nie überholen und 
	auch nicht einholen.

- Beim Löschen(dequeue) 
	wird der Wert an der Stelle begin-Zeiger zurückgegeben. 
	Dann wird der begin-Zeiger erhöht. 
	Wenn der begin-Zeiger das Arrayende erreicht hat, wird der 
	begin-Zeiger wieder auf 0 gesetzt.
	Aber ACHTUNG: der begin-Zeiger darf den end-Zeiger nie überholen 
	oder einholen.

- Wenn (end+1) % Anzahl_der_Arrayelemente == begin ... dann ist die 
	Ringschlange voll

Aufgabe:
- Erstellen Sie den Modul fifo (fifo.h, fifo.c), wie oben beschrieben.
- Erstellen Sie ein Testprogramm (test-fifo.c):
*/




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


#include "fifo.h"



int main(){	
	printf("\nSTART testing fifo ...\n"); system("date");fflush(stdout);

	fifo_init();
	
	assert( fifo_empty() == true && "Testing: fifo_empty()");
	
	
	fifo_enqueue(1);
	int value= fifo_dequeue();	
	
	assert( value == 1 && "Testing: fifo_dequeue()");
	assert( fifo_empty() == true && "Testing: fifo_empty()");
	
	fifo_enqueue(1);
	fifo_enqueue(2);
	fifo_enqueue(3);
	
	value= fifo_dequeue();	
	assert( value == 1 && "Testing: fifo_dequeue()");
	
	value= fifo_dequeue();	
	assert( value == 2 && "Testing: fifo_dequeue()");

	value= fifo_dequeue();	
	assert( value == 3 && "Testing: fifo_dequeue()");

	assert( fifo_empty() == true && "Testing: fifo_empty()");

	
	printf("\nEND testing fifo ...\n"); system("date");fflush(stdout);
	printf("\nAll Tests are OK ...\n\n");
	
	return 0;
}
