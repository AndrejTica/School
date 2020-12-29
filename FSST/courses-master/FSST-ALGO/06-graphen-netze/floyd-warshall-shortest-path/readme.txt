/*
RDP-AUFGABE: FSST-ALGO: FLOYD-WARSHALL-APSP

- Gegeben: Template Klasse: Matrix
- Gegeben: Skriptum: Floyd-Warshall all pair shortest path
- Gegeben: net.h (s.u.)
- Gegeben: main.cpp (s.u.)
- GESUCHT: net.cpp


- Gegeben: Folgendes Netz
	- 0(Salzburg) 	<-> 2(Linz)			: 120
	- 0(Salzburg) 	<-> 3(Innsbruck)	: 100
	- 0(Salzburg) 	<-> 4(Graz)			: 200
	- 2(Linz) 		<-> 1(Wien)			: 230
	- 4(Graz) 		<-> 1(Wien)			: 260

				........ (2/L) ........
				.                     .
				.                     .
				120                   230
				.                     .
				.                     .
(3/I)...100...(0/S)                  (1/W)
				.                     .
				.                     .
				.                     .
				200                   260
				.                     .
				.                     .
				........ (4/G).........
				


- Folgende Ausgabe muss generiert werden, wenn der
	kürzeste Weg von Innsbruck nach Wien gesucht wird.

	Kürzeste Verbindung: von (3/I) nach (1/W): 450 
	Route:
	(3/I) nach (0/S): 100
	(0/S) nach (2/L): 120
	(2/L) nach (1/W): 230

*/
