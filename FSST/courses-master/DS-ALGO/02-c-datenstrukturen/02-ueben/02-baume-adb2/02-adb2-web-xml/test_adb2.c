// a.hofmann sept. 2002
// test_adb2.c
// AdressbuchVerwaltung: Testprogramm
//

#include <stdio.h>
#include <string.h>

#include "adb2.h"

#define CLS system("clear")
#define PAUSE printf("weiter mit enter ...");fgetc(stdin)

//#define CLS system("cls")
//#define PAUSE system("pause");


int main(int argc, char *argv[]){
	enum {false, true} ende= false;
	char choice;
	char input[MAXLINE];
	char email[MAXLINE];
	char *p_email;
	int ret;
	
	while (ende !=  true){
		CLS;
		printf("\n\n\t*** Adressbuch Version 1.0 (A.hofmann Sept 2002) ***\n\n");
		
		printf("\ta) adb_open  (user gibt name der Email-Adressdatenbankdatei ein)\n");
		printf("\tb) adb_list	(user gibt Name der output-datei an: zb.: stdout)\n");
		printf("\tc) adb_get_email (user gibt nickname an)\n");
		printf("\td) adb_asveAS_xml (marker.xml)\n");

		printf("\te) ende\n");
		printf("\t");
		
		choice= fgetc(stdin);
		fgetc(stdin);	// wegen enter
		
		switch(choice){
			case 'a':
				printf("\n\tAdressbuch (tourist.txt): ");
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
				
				p_email= adb_get_email (input, email);
				if (p_email == NULL)
					fprintf(stderr, "\t%s nicht gefunden.", input);
				else
					printf("\t%s", email);
				
				printf("\n");
				PAUSE;
				break;
			
			case 'd':
				ret= adb_saveas_xml("marker.xml");
				if (ret == -1)
					perror (input);
				
				printf("\n");
				PAUSE;
				break;

			case 'e':
				ende = true;
				break;
			
			default:
				ende = true;
		} //switch
	}//while

	return 0;
}
