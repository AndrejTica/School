/*
*---------------------------------------------------------------------
* bufover0.c
*---------------------------------------------------------------------
* buffer overflow: ein Beispiel
*  
* gcc -Wall -pedantic bufover0.c -o bufover0.exe
*  // overflow wird erkannt!!! 
* 
* gcc -Wall -pedantic -fno-stack-protector bufover0.c -o bufover0.exe
*  // overflow wird NICHT erkannt!!! ---->yy ändert seinen Wert
*---------------------------------------------------------------------*/

#include <stdio.h>

int foo() {
	unsigned int yy = 0;
	char buffer[5]; 
	char ch; 
	int i = 0;

	printf("Say something: ");
	while ((ch = getchar()) != '\n')
		buffer[i++] = ch;
	buffer[i] = '\0';

	printf("You said: %s\n", buffer);
	printf("The variable yy: %d\n", yy);
	return 0;
}

int main() {
	while(1)
		foo();

	return 0;
}
