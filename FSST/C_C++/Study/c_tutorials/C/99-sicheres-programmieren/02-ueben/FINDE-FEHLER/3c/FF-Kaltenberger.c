//Kaltenberger Simon 	HTL-Salzburg	3CHELI
//Finde die 3 Fehler!!!	
//Programm: Sortieren von Zahlen!
int main(int argc, char *argv[])
{

    int *zahlen;
    int anzahl;

    anzahl = argc-2;
    zahlen = malloc(anzahl*sizeof(int));
    if(NULL == zahlen){
        fprintf(stderr,"\nNo RAM\n");
        exit(2);
    }


    for(int i=0;i<anzahl;i++)
        sscanf(argv[i+2], "%i", zahlen[i]);



    sort(*zahlen, anzahl);		//Sortiert die Zahlen!
    for(int i=0; i< anzahl; i++){
        printf("%i, ", &zahlen);
    }

    free(zahlen);


    return 0;
}

