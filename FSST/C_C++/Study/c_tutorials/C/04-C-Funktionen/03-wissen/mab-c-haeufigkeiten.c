// mab-c-haeufigkeiten.c (6)
// H1, H2,..:abs Häufigkeit und h1, h2, ...:rel. Häufigkeit (hi = Hi/n)
#include <stdio.h>
#include <string.h>

void get_H(const char* s, int* H); // abs. Haeufigkeit berechnen
void get_h(const char* s, double* h); // rel. Haeufigkeit berechnen
void print_h_H(const char* s, double* h, int* H);// ausgabe

int main(){
	char s[128];
	double h[256];	// rel. haeufigkeiten hi= Hi/n
	int H[256]; 	// abs. haeufigkeiten
	int n;

	printf("Text? ");
	gets(s);	
	n= strlen(s);	// Umfang der Stichproben
	get_H(s,H);		// Abs. Haeufigkeit
	get_h(s,h);		// rel. Haeufigkeit	
	print_h_H(s,h,H);// ausgabe
		
	return 0;
}

void get_h(const char* s, double* h){
	int i,n;
	int H[256];
	
	for(i=0; i< 256; i++)
		h[i]= 0.0;
	
	get_H(s,H);
	n= strlen(s);
	
	for(i=0; i< 256; i++)
		h[i]= H[i] / n;
}

void get_H(const char* s, int* H){
	int i,n;	
	for(i=0; i< 256; i++)
		H[i]= 0;
	
	n= strlen(s);
	for(i=0; i< n; i++)
		H[s[i]]++;
}

void print_h_H(const char* s, double* h, int* H){
	int i, n;
	n=strlen(s);
	
	printf("Statistik: Haeufigkeiten\n");
	printf("\tEingabe: <%s>\n", s);
	
	printf("\tH abs. Haeufigkeiten:\n");
	for(i=0; i< n; i++)
		printf("\t\tH[%i]= %i (%c)\n", s[i], H[i], s[i]);
		
	printf("\th rel. Haeufigkeiten:\n");
	for(i=0; i< n; i++)
		printf("\t\th[%i]= %lf (%c)\n", s[i], h[i], s[i]);
}
