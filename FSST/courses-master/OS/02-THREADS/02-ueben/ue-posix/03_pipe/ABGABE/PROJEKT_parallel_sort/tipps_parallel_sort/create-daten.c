//a.hofmann
// generiert eine datei mit zufallszahlen
// aufruf: ./create-daten.exe filename anzahl
//         ./create-daten.exe daten.txt 500000
// gcc create-daten.c -ocreate-daten.exe

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]){
	int anzahl;
	int i;
	FILE* fp;

	if (argc != 3){
		printf("\nAufruf: ./create-daten.exe daten.txt 500000\n");
		exit(1);
	}

	if (isdigit(argv[2][0]))
		anzahl= atoi(argv[2]);
	else {
		printf("\nAufruf: ./create-daten.exe daten.txt 500000\n");
		exit(1);
	}

	fp= fopen(argv[1], "w");
	if (fp==NULL){
		perror(argv[1]);
		exit(1);
	}

	printf("\n....generating file: %s with %d integers ....\n",argv[1], anzahl);

	for (i=0; i< anzahl; i++)
		fprintf(fp,"%d\n", rand()%10000);

	close(fp);

	return 0;
}

