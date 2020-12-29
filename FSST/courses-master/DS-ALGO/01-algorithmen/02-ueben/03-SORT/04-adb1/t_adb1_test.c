/** \mainpage ADB1
 *
 * \section intro_sec Introduction
 Adressbuchverwaltung: ADB1
 		Indexsequentieller Zugriff auf die Daten
 		Die Index-Tabelle besteht aus nickname/offset-Elementen,
 		die sortiert sind und beim Zugriff wird durch die
 		binŠre Suche (nach nickname) der offset fŸr den
 		seek in der Datei ermittlet.
 *
 * \section gcc_sec	Kompiler
 	gcc t_adb1_test.c adb1.c -o t_adb1_test.exe
 	
 * \subsection run_sec Ausführen
 	./t_adb1_test.exe
 *  
 * Datendatei: adb.txt
 <pre>
 nickname
 email
 comment
 ....
 </pre>
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "adb1.h"

#define CLS system("clear") 
#define PAUSE printf("\nweiter mit enter ... ");fgetc(stdin) 

int main(int argc, char *argv[]){
	enum {false, true} ende= false;
	char choice;
	char input[MAXLINE];
	char email[MAXLINE];
	int ret;

	while (ende !=  true){
		CLS;
		printf("\n\n\t*** Adressbuch Version 1.0 (NAME) ***\n\n");
		
		printf("\ta) adb_open  (user gibt name der Email-Adressdatenbankdatei ein)\n");
		printf("\tb) adb_list	(zeigt alle Datensätze an)\n");
		printf("\tc) adb_get_email (user gibt nickname an)\n");
		printf("\td) ende\n");
		printf("\t");
		
		choice= fgetc(stdin);
		fgetc(stdin); // wegen ENTER
		
		switch(choice){
			   case 'a':
					printf("\n\tAdressbuch (adb.txt): ");
					fgets (input, 256, stdin);
					input[strlen(input) -1] = '\0';
	
					ret= adb_open (input);
					if (ret == -1)
					   perror (input);
	
					printf("\n");
					PAUSE;
					break;
	
			   case 'b':
					adb_list(stdout);
	
					printf("\n");
					PAUSE;
					break;
	
			   case 'c':
					printf("\n\tNickname: ");
					fgets (input, 256, stdin);
					input[strlen(input) -1] = '\0';
	
					adb_get_email (input, email);
					if (strlen(email) == 0)
					   fprintf(stderr, "\t%s nicht gefunden.", input);
					else
					   printf("\t%s", email);
					
					printf("\n");
					PAUSE;
					break;
	
			   case 'd':
					adb_close();
					ende = true;
					break;
	
			   default:
					adb_close();
					ende = true;
		} //switch
	}//while

  return 0;
}

