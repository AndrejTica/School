/*
 * Andrej Tica 2019
*/

#include <stdio.h>

int main(){
 int i;
 
 for(i=0; i<=255; i++){
  
    if(i !=0 && i%24==0){
    printf("Weiter mit <enter> ...");
    fgetc(stdin);
}
	printf("%i:<%c>\n", i , i );

}
	printf("\n");
	return 0;
}
