// Mittelwert 3er Zahlen berechnen
// D.Karnutsch, 2012

#include <stdlib.h>
#include <stdio.h>

#define ANZ = 3

int main(int argc, char *argv[])
{
	int zahlen[ANZ];
	zahlen[0] = 4;
	zahlen[1] = 2;
	zahlen[2] = 3;

	printf("Mittelwert: %i\n", mittelwert(zahlen, ANZ));
}

double mittelwert(int zahlen[], int l)
{
	int i;
	int sum = 0;

	for(i=0; i < l; i++)
	{
		sum += zahlen[i];
	}

	return sum/l;
}