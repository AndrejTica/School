/*
 * Andrej Tica 2019
*/
#include <stdio.h>

int main(){
 int ziffernsumme=0;
 int ch;

 while( (ch= fgetc(stdin)) != '\n') {
	ziffernsumme = ziffernsumme + ch - '0';
}

	printf("\nZiffernsumme= %i\n", ziffernsumme);
    return 0;

}
