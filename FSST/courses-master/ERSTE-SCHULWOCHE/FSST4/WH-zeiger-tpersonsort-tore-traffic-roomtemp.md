# Erste Schulwoche FSST4:C
---------------------------------------------------
A.Hofmann, 2016, Gitlab/ERSTE-SCHULWOCHE

## 1. Ein Mustertest (gemeinsam): 
---------------------------------------------------
* TPERSON-SORT.c (programmieren)
* TORE.c (gemeinsam programmieren) 

~~~
MS: Zeiger,Strukturen, Files (24) NAME:                   DATUM:
================================================================================

1. (6) 
--------------------------------------------------------------------------------
1.2. (2)Folgender C-Code ist gegeben:
	char str[128+1];
	strcpy(str , "Hallo");
	printf("<%s>strlen=<%i>sizeof=<%i>\n", str, strlen(str), sizeof(str));

	Welcher Text wird mit printf auf stdout ausgegeben?


	____________________________________________________________________

1.1. (4) Was gibt das folg. Programm aus?
	int a[]={111,222,333,444,555};
	int* p;

	p= &a[1];
	int x= *p +2;  
	p++;
	int y= *(p +2); 

	printf("x= %i y= %i", x,y);

	Ausgabe:
	x= ____________________________________________________________________

	Y= ____________________________________________________________________


2. (10) TPERSONSORT.c (programmieren)
--------------------------------------------------------------------------------
typedef struct person {
	int persnr;
	char name[40];
} TPERSON;
#define ANZ  3

void sort_persnr(TPERSON* p, int anzahl);

int main(int argc, char* argv[]){
	TPERSON wir[ANZ];
	int i;

	printf("\nBitte %d Datensaetze eingeben:\n", ANZ);
	for (i=0; i < ANZ; i++){
		printf("\n%d:persnr> ", i);

2.1.(1)	scanf("%d", ___________________________);
		printf("%d:Name> ", i);

2.2.(1)	scanf("%s", _________________________________);
	}

	// Das Array mit dem Namen wir soll sortiert werden

2.3.(1)	sort_persnr(________________________, ___________________);


	printf("\nAusgabe: Sortiert wurde nach persnr:\n");
	for (i=0; i < ANZ; i++){

2.4.(1)		printf("\n%6d | %-20s", _________________ , ________________);
	}
	return 0;
}

void sort_persnr(TPERSON* p, int anzahl){
	int i;
	int fertig;

	fertig=0;
	while (0==fertig){
		fertig= 1;

2.5.(1)		for (i=0; i < ___________________; i++){

2.6.(1)			if ( (p _________)->persnr > (p _____________)->persnr){

					___________________ help;

2.7.(1)				help= _________________;

2.8.(1)				_________________ = _________________;

2.9.(1)				_________________ = help;

2.10.(1)			fertig= _________________;
				}//if
			}//for
		}//while
	}



3) (8) TORE.c (gemeinsam programmieren)
--------------------------------------------------------------------------------
* Gegeben ist die Datei tore.txt (s.u.)
* (4) Lesen Sie die Datei ein und 
* (4) Geben Sie die Anzahl der insgesamt erzielten Tore aus.

Hinweis: 
FILE* fopen(char*, char*);

char* fgets(char*, int, FILE*);

char * strtok(char *string, char *delimiters);
	char string[] = "Kurt,Kanns;555678;DE";
	char delimiter[] = ",;";
	char *ptr;

	// initialisieren und ersten Abschnitt erstellen
	ptr = strtok(string, delimiter);

	while(ptr != NULL) {
		printf("Abschnitt gefunden: %s\n", ptr);
		// naechsten Abschnitt erstellen
	 	ptr = strtok(NULL, delimiter);
	}

	Abschnitt gefunden: Kurt
	Abschnitt gefunden: Kanns
	Abschnitt gefunden: 555678
	Abschnitt gefunden: DE

tore.txt
	4
	groedig:salzburg:0:0
	frankfurt:stuttgart:4:5
	gladbach:bayer:0:0
	real:barca:3:1
~~~





## 2. Programm: TRAFFIC.java
------------------------------------------------------------
1. (2) Definiere geeignete Datenstruktur-Typen (in C) zur Verarbeitung der
	obigen Daten.

2. (2) Lies die Daten in ein 
   (2) mit malloc() zu alloziierendes Array.

~~~
Given input.txt
3
Maserati,1000 kg,2 Persons
VM,800 kg,4 Persons
Bus,2500 kg,8 Persons
    
output:
With 3 vehicles we transport 14 persons using 4300 kg.
So for 1 person we have to move about 307,14 kg 'vehicle weight'.
~~~



## 3. FRAGEN:
--------------------------------------------
~~~
2.1. (3) Erklärung für:
	a) static global    b) cast operator     c) call-by-reference

2.2. (8) wahr oder falsch (inkl. Begründung)
	a) char* p1; double* p2;  sizeof(p2) > sizeof(p1)   ....liefert true
	b) int wert; scanf("%i", &wert);
	c) Das letzte Zeichen löschen: str[strlen(str)]= '/0';
	d) int x=5, y=2; float erg; erg= x/y;  printf("%.1f", erg); ... gibt 2.5 aus

2.3. (1) Definieren Sie ein Array namens a mit 10 Zeigern auf char als Elementen
~~~

## 4. Quiz:
--------------------------------------------------
* Moodle-Test: HEL-INFORMATIK (MAB-C-Zeiger)


## 5. Freiwillig: ROOM-TEMP.c
------------------------------------------------
~~~
Zu erstellen ist ein vollständiges C-Programm (room-temp.c).

Gegeben: room-temp.txt
	3
	Schlafzimmer:20
	Kueche:25
	Keller:15


1. (2) Definiere geeignete Datenstruktur-Typen (in C) zur Verarbeitung der
	obigen Daten.

2. (2) Lies die Daten in ein 
   (2) mit malloc() zu alloziierendes Array.

3. (2) Für alle Zimmer mit einer Temperatur über 19 Grad soll der Text
	"Fenster öffnen" und der Raumname und die aktuelle Raumtemperatur 
	auf die Konsole ausgegeben werden.

4. Schreib die Funktion printDurchschnitt(), die von allen Räumen die
	Durchschnittstemperatur berechnet und diese auf die Konsole ausgibt.
	4.1. (2) Wie lautet der Funktions-Prototyp
	4.2. (2) Wie lautet der Funktions-Aufruf.
	4.3. (2) Die Funktion printDurchschnitt() ausprogrammiert.
 

Beispiel für die Ausgabe zur obigen room-temp.txt:
	Fester öffnen:Schlafzimmer:20
	Fester öffnen:Kueche:25
	Durschnittstemperatur: 20
~~~
