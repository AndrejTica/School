/*
	Ein recht bekanntes und einfaches Spiel ist das Nimm-Spiel:
	Es werden z.B. zwanzig Muenzen (20) auf den Tisch gelegt, und die beiden 
	Spieler duerfen abwechselnd eine, zwei oder drei Muenzen (1,2,3)nehmen. 
	Wer die letzte Muenze nimmt, der hat gewonnen. 
	Wir wollen dieses Spiel gegen den Rechner spielen.
	Der grosse Rahmen des Programms koennte ungefaehr so aussehen:
	   

	   Eingabe der Anfangs-Muenzenanzahl

	   Endlosschleife
	      Rechner zieht
	      if(keine Muenzen mehr da)
	         rechner hat gewonnen
	         ende des Programms

	      Mensch zieht
	      if(keine Muenzen mehr da)
	         Mensch hat gewonnen
	         ende des Programms
	
	
	Das Programm scheint sehr einfach und uebersichtlich zu werden, nur die Zeilen
	      Rechner zieht     und        Mensch zieht
	koennten noch ein wenig Aufwand bedeuten. 
	
	Um diesen Aufwand druecken wir uns zunaechst, indem wir diese beiden Zeilen als 
	Funktionen auslagern und zunaechst nur das Hauptprogramm schreiben. 
	Dazu muss aber die Schnittstelle der Funktionen klar sein. 
	Das heisst, es muss klar sein, welche Parameter die Funktion bekommt, 
	und welchen Wert sie zurueckgibt. Sinnvoll ist z.B. folgendes: 
	Die Funktion bekommt als Parameter die aktuelle Muenzenanzahl und 
	gibt zurueck, wie viele Muenzen weggenommen werden sollen. 
	
*/

#include <stdio.h>
int zugRechner(int anzahlDerMuenzen);
int zugMensch(int anzahlDerMuenzen);

int main() {
   int anzahlDerMuenzen;
   int anzahlZugRechner;
   int anzahlZugMensch;
   
   // Eingabe der Anfangs-Muenzenanzahl
   puts("Mit wievielen Muenzen fangen wir an? ");
   scanf("%d", &anzahlDerMuenzen);
   
   // endlosschleife
   while(1)   {
      ??????
      if(anzahlDerMuenzen==0){
         puts("Ich habe gewonnen!\n");
         return 0;
      }

      ??????
      if(anzahlDerMuenzen==0) {
         puts("Sie haben gewonnen!\n");
         return 0;
      }
   } //while
} //main



/* 
	Angenommen, die beiden Zug-Funktionen seien korrekt, dann muesste 
	ja alles funktionieren. Wir schreiben die einfachere zuerst: 
*/

int zugMensch(int anzahlDerMuenzen) {
    ???????????????
    }

/* 
  Und gleich darauf die schwierigere. Und davor steht, 
          eine Gewinnstrategie zu finden.
	Wenn nur eine Muenze auf dem Tisch liegt, und man ist am Zug ist, 
	dann nimmt man sie. Ebenso bei zwei oder drei Muenzen. 
	
	Aber bei vier Muenzen ist jeder Zug ein Fehler, denn 
	nimmt man eine, dann nimmt der Gegner drei, 
	nimmt man zwei, dann nimmt der Gegner zwei, 
	nimmt man drei, dann nimmt der Gegner eine.
	Hier eine kleine Aufstellung, wieviele Muenzen 
	man bei welcher Muenzenanzahl nehmen sollte:
	1 => 1
	2 => 2
	3 => 3
	4 => egal
	5 => 1
	6 => 2
	7 => 3
	8 => egal
	9 => 1
	Zum Vergleich die Zahlen modulo 4:
	1%4==1
	2%4==2
	3%4==3
	4%4==0
	5%4==1
	6%4==2
	7%4==3
	8%4==0
	9%4==1
	Ueberall, wo eine 0 steht, ist egal, was man zieht (z.B. nur eine Muenze), 
	sonst zieht man Muenzenanzahl modulo 4. 
	Das ergibt also folgende Funktion: 
*/
int zugRechner(int anzahlDerMuenzen) {
    ??????????????????
}
/*
Uebung: 
	Der Rechner soll jeweils anzeigen, wieviele Muenzen er nimmt.
	Ausserdem sollen fuer den Menschen nur gueltige Zuege moeglich sein.
*/
