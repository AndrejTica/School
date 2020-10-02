// fail 1
long i = 0;
while(1) {
	printf("%d\n", i++);
	if(i = 13)
		i = 0;
}


// fail 2
#define MACRO(x,y) {
	y = ++x;
	y--;
}


// fail 3
char buffer[256] = "hallo";
memset(buffer, 0, strlen(buffer)); // set buffer to 0


// fail 4
char string[5] = "hallo";


// fail 5
int* array = malloc(6);


// fail 6
int* daten = malloc(5 * sizeof(int));


// fail 7
int* daten = (int*)malloc(5 * sizeof(int));
memset(daten, 0, sizeof(daten));
