/*
 *Andrej Tica, 2019
 *in2out.c	
 */

#include <stdio.h>

int main(){
 int ch;

 ch= fgetc(stdin);

 fputc(ch, stdout);

 return 0;

}


