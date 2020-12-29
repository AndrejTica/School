/* 12. Beispiel: Schnelles Potenzieren

X hoch y kann man wie folgt sehr schnell berechnen:
wenn y ungerade:
   ergebnis= ergebnis*x;
   y= y-1;
wenn y gerade:
   x= x*x;   
   y= y/2;

Beispiel: x=3 und y=16
   ergebnis= 3 hoch 16
   ergebnis= (3 hoch 2) hoch 8

Beispiel: x=3 und y=17
   ergebnis= 3 hoch 17
   ergebnis= 3 hoch 16 * 3
   ergebnis*3=3 hoch 16
*/
