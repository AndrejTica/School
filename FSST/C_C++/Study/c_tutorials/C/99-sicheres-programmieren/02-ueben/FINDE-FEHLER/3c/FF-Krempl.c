#include <stdio.h>

int add(double i, int j);

int main(void)
{
    char text1[] = "Hallo";
    char text2[] = "Du!!";
    int i = 2;
    int j = 21;
    int z = 0;

    strcat(text1, ' ');
    strcat(text1, text2);
    printf("%s\n", text1);

    printf("Jetzt addieren wir %i mit %i", i,j);
    z = add(i,j);

    return 0;
}

int add(double i, int j)
{
    int help;
    help == i + j;
}

