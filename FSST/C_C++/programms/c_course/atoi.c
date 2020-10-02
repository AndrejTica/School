// Andrej Tica 2019

#include <stdio>

int main(){
 int zahl=0;
 int ch;

   ch= fgetc(stdin);
    while (ch != '\n'){
    zahl = 10*zahl + ch - '0');
    ch= fgetc(stdin);
}

 printf("\nZahl= %i\n", zahl);
return 0;
}

