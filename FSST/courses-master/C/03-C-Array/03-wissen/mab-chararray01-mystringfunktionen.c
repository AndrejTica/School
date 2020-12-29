mab (6): chararray01-stringfunktionen.c
--------------------------------------------------------------

// char arrays: strlen, strcpy, strcat, 
// chararray01-stringfunktionen.c

#include <stdio.h>
#include <stdlib.h>
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <string.h>

#define ANZ 128

int main(int argc, char *argv[])
{
    char str1[ANZ];    
    char str2[ANZ];    
    int len;
    int i;
    
    printf("\nchararray01-stringfunktionen.c");
    printf("strlen(), strcpy(), strcat(), \n");
    printf("....................................................\n");
    
    // strlen
    gets(str1);
    //len= strlen(str1);
(2)    // TODO: strlen selber ausprogrammieren  ...............
    printf("\nstrlen(str1) lieferte %i\n", len);
    
    //strcpy
    //strcpy(str2, str1);
    // TODO: strcpy selber ausprogrammieren  ...............
(2)    //strcpy(str2, "Mustermann");
    fputs(str2, stdout);
    
    // strcat
    strcat(str2, "Das haengt so dran");
(2)    //strcat(str2, str1);
	// TODO: strcat selber ausprogrammieren  ...............

    printf("\nstrcat: %s\n", str2);
     
    
  printf("\n");

  return 0;
}
