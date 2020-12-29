/*
 * N.N.
 * 2019
 *
 Die Funktion find_max_min_pos() soll von einem Integer-Array 
 die Position des Maximums und 
 die Position des Minimums liefern. 
 
 Mit einem herkömmlichen return kann man ja nur einen Wert zurückgeben. 
 Zur Lösung verwenden wir die bereits bekannte Methode Call-by-Reference.
*/

include <stdio.h>


void find_max_min_pos( int* a, int len, int* posmaxi, int* posmini);


int main(){
  int element[8]= {12,22,4,8,16,128,64,10};
  int max_pos, min_pos;

  find_max_min_pos (element, 8, & max_pos, & min_pos);

  printf("\nMaximum= %d liegt an Stelle %i", element[max_pos], max_pos);
  printf("\nMinimum= %d liegt an Stelle %i", element[min_pos], min_pos);

  return 0;
}


void find_max_min_pos( int* a, int len, int* posmaxi, int* posmini){
  int i, themax, themin;

	// ENTER CODE 
	
}
