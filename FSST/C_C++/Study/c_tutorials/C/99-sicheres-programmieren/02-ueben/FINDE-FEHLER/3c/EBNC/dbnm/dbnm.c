/*
  dbnm.cpp
  C.Ebner
  2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stddef.h>

/*
   Strukturen
 */
//person
struct person{
    int pers_id;
    char* vname;
    char* nname;
    int abt_id;
};
typedef struct person TPERS;

//abteilungen
struct abteilung{
    int abt_id;
    char* abt_name;
};
typedef struct abteilung TABT;

//pers-abt
struct pers_abt{
	int pers_id;
	int abt_id;
};
typedef struct pers_abt TPERSABT;

void openf(FILE** fpp, char* file, char* modus);

int abtLesen(TABT* abteilungen, FILE* f_abteilungen, int abtlen);
int persLesen(TPERS* person, FILE* f_personen, int perslen);
int persabtLesen(TPERSABT* persabt, FILE* f_persabt, int persabtlen);

int dataOut(TABT* abteilungen, TPERS* person, TPERSABT* persabt, int perslen, int abtlen, int persabtlen);

int main()
{
    FILE* f_personen;
    FILE* f_abteilungen;
	FILE* f_persabt;
	
	TABT* abteilungen;
	TPERS* person;
	TPERSABT* persabt;
	
    int perslen = 0;
    int abtlen = 0;
	int persabtlen = 0;
    int test = 0;


    //Dateien oeffnen
    //personen
	openf(&f_personen, "personen.txt", "rt");
	
    //abteilungen
	openf(&f_abteilungen, "abteilungen.txt", "rt");
	
	//personen-abteilungen
	openf(&f_persabt, "personen-abteilungen.txt", "rt");


    //Erste Zeile lesen
    //Array laengen definieren
    //Personenlaenge lesen
    fscanf(f_personen, "%i", &perslen);
    person = (TPERS*) malloc(perslen*sizeof(TPERS));


    //Abteilungslaenge lesen
    fscanf(f_abteilungen, "%i", &abtlen);
    abteilungen = (TABT*) malloc(abtlen*sizeof(TABT));
	
	//persabt laenge lesen
    fscanf(f_persabt, "%i", &persabtlen);
    persabt = (TPERSABT*) malloc(persabtlen*sizeof(TPERSABT));


    //Abteilungen einlesen
	test = abtLesen(abteilungen, f_abteilungen, abtlen);
	if(abtlen != test)
	{
		fprintf(stdout, "Fehler beim einlesen von abteilungen.txt");
		exit(2);
	}
    fclose(f_abteilungen);

    //Personen einlesen
	test = persLesen(person, f_personen, perslen);	
	if(perslen != test)
	{
		fprintf(stdout, "Fehler beim einlesen von personen.txt");
		exit(2);
	}
	fclose(f_personen);
	
	//personen-abteilungen einlesen
	test = persabtLesen(persabt, f_persabt, persabtlen);	
	if(persabtlen != test)
	{
		fprintf(stdout, "Fehler beim einlesen von personen-abteilungen.txt");
		exit(2);
	}
	fclose(f_persabt);
	
	//Daten ausgeben
	test = dataOut(abteilungen, person, persabt, abtlen, perslen, persabtlen);
	if(persabtlen != test)
	{
		fprintf(stdout, "Fehler beim ausgeben der Daten");
		exit(1);
	}	


	free(abteilungen);
	free(person);	
	
	system("pause");
	return 0;
}

void openf(FILE** fpp,char* file, char* modus)
{
	*fpp = fopen(file, modus);
	if(0 == *fpp)
	{
		fprintf(stderr, "Error: open %s\n", file);
		exit(1);
	}
}

int abtLesen(TABT* abteilungen, FILE* f_abteilungen, int abtlen)
{
	char str1[50];
    int i = 0;
    int test = 0;

	for(i = 0; i < abtlen; i++)
    {
      test = fscanf(f_abteilungen, "%i %s", &abteilungen[i].abt_id, str1);
      if(EOF == test)
        break;

      abteilungen[i].abt_name = (char*) malloc(strlen(str1)+1);
      if(NULL == abteilungen[i].abt_name)
      {
        printf("No RAM");
		break;
      }
      strcpy(abteilungen[i].abt_name, str1);
    }
	
	return i;
}

int persLesen(TPERS* person, FILE* f_personen, int perslen)
{
	char str1[50];
	char str2[50];
    int i = 0;
    int test = 0;

    for(i = 0; i < perslen; i++)
    {
        test = fscanf(f_personen, "%i %s %s", &person[i].pers_id, str1, str2);
        if(EOF == test)
          exit(1);
		
        person[i].vname = (char*) malloc(strlen(str1)+1);
        if(NULL == person[i].vname)
        {
          printf("No RAM");
          exit(2);
        }
        strcpy(person[i].vname, str1);

        person[i].nname = (char*) malloc(strlen(str2)+1);
        if(NULL == person[i].nname)
        {
          printf("No RAM");
          exit(3);
        }
        strcpy(person[i].nname, str2);
    }
	
	return i;
}

int persabtLesen(TPERSABT* persabt, FILE* f_persabt, int persabtlen)
{
    int i = 0;
    int test = 0;

    for(i = 0; i < persabtlen; i++)
    {
        test = fscanf(f_persabt, "%i %i", &persabt[i].pers_id, &persabt[i].abt_id);
        if(EOF == test)
          exit(2);
    }
	return i;
}

int dataOut(TABT* abteilungen, TPERS* person, TPERSABT* persabt, int perslen, int abtlen, int persabtlen)
{
	int i, j, k;
	
	for(i = 0; i < persabtlen; i++)
	{
		for(j = 0; j < perslen; j++)
		{
			if(persabt[i].pers_id == person[j].pers_id)
			{
				break;
			}
		}
		
		for(k = 0; k < abtlen; k++)
		{		
			if(persabt[i].abt_id == abteilungen[k].abt_id)
			{
				break;
			}
		}
		
		fprintf(stdout, "%i %s %s %i %s \n", person[j].pers_id, person[j].vname, person[j].nname, abteilungen[k].abt_id, abteilungen[k].abt_name);
	}	
	return i;
}
