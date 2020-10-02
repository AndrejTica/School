/**
* Finden Sie mit gdb den/die Fehler
*
* zu GDB: 
* siehe eine Liste der Befehle weiter unten
*
* break factorial
* run
* watch n
* watch result
* step
*
*/

#include <stdio.h>
 
long factorial(int n);
 
int main()
{
    int n=0;
    scanf("%i", &n);
    
    long val=factorial(n);
    
    printf("fakt=%ld\n\n", val);
    return 0;
}
 
long factorial(int n)
{
    long result=1;
    while(n--)
    {
        result*=n;
    }
    return result;
}


/*
GDB
...................................................
http://www.cprogramming.com/gdb.html
http://www.cprogramming.com/debuggers.html
http://beej.us/guide/bggdb/



Übersetzen
...................................................
g++ main.cpp -g -Wall -Werror -o main.exe
oder
gcc main.c -g -Wall -Werror -o main.exe


Starten
...................................................
gdb main.exe -tui

gdb main.exe


Quellcode ansehen
...................................................
list von,bis


Breakpoints setzen/löschen
...................................................
break lineNR
break function

enable lineNR
disable lineNR

delete lineNR


Varibel beobachten
...................................................
watch variable
set variable= wert



Programm starten/beenden
...................................................
run
kill

setp
next		springt nicht in funktionen
continue	lauf weiter


Inhalte ansehen
...................................................
backtrace
where

disas

print variable
printf "%d\n", variable

x/ adr
*/
