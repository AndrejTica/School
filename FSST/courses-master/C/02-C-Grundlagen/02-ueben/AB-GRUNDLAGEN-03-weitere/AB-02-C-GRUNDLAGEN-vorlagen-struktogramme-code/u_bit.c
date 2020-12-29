/* datei: u_bits.c     Hofmann Anton
 * Ermittlung der Bitbreite ganzzahliger Datentypen
 */

#include <stdio.h>
int main(){
   unsigned int ganzzahl;
   long int lang;
   int breite= 0;
   
   ganzzahl= ?????????????;   /* alle bits setzen */
   while (ganzzahl != 0){
      ganzzahl= ????????????????;  /* eine 0 von links shiften */
      breite++;
   }
   printf("Die Breite einer INT-Zahl ist %d Bits\n", breite);
   
   lang= 1;
   for (breite= 1; lang ????????; breite ++){
      lang= lang << ????????????;
   }
   printf("Die Breite einer LONG-Zahl ist %d Bits\n", breite);
   
   return 0;
}

