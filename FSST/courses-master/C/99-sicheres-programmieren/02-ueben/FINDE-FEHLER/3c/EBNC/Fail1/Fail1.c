/*
  fail1.c
  C.Ebner
  2012
*/

#include <stdio.h>
#include <stdlib.h>

void openf(FILE* fp, char* file, char* modus)
{
	fp = fopen(file, modus);
	if(0 == fp)
	{
		fprintf(stderr, "Error: open %s\n", file);
		exit(1);
	}
}

int main(){
	FILE* f_in;
	
	openf(f_in, "input.txt", "rt");

	return 0;
}