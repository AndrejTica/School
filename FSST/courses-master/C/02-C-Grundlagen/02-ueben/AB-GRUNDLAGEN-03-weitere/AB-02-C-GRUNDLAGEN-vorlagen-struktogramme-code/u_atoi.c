/* Datei: u_atoi.c    Hofmann Anton
 * Liest einen Ziffernstring ein und 
 * Wandelt diesen in eine INT-Zahl um und
 * Gibt die umgewandelte INT-Zahl aus
 */

#include <stdio.h>

int main(){
	int ch, num=???????;

	ch=fgetc(stdin); // oder   ch=getchar()
	while (ch != '\n'){
		num= (10*num) + ch ?????????;
		ch= fgetc(stdin);
	}

	printf("\n Die eingegebene Zahl war %d\n", ??????);

	return 0;
}

