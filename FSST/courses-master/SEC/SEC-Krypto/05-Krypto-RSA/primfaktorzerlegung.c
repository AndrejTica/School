// ahofmann, 2017
// primfaktorzerlegung.c
// http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/005_c_basisdatentypen_005.htm
// unsigned long long (8 Bytes) 0 … 18446744073709551615
//
// 55141
// 17699629
// 176996291123

#include <stdio.h>

int main(){
	unsigned long long zahl;

	printf("\nPrimfaktorzerlegung: (max: 18446744073709551615)\n");
	printf("Zahl? ");
	scanf("%llu", &zahl);
	printf("%llu= ", zahl);

	long long teiler=2;
	do{
		long long rest= zahl%teiler;

		if (rest==0){
			printf("%llu*", teiler);
			zahl= zahl/teiler;		
		}
		else
			teiler++;

	}while (zahl>1);
	
	printf("\n");
	return 0;
}

