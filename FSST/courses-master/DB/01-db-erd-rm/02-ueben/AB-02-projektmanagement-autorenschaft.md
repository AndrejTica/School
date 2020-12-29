# AUFGABEN: ER-Diagramme
file: AB-02-projektmanagement-autorenschaft.md


## 1. Aufgabe: ERD-PROJEKTMANAGEMENT
---
~~~
Stellen Sie folgende Zusammenhänge in einem Projektmanagementsystem 
als ER-Diagramm dar, und geben Sie an, ob es sich bei den Beziehungen
jeweils um eine 1 : n- oder n : m-Beziehung handelt.
(in Klammern die Primärschlüssel).

• Ein Projekt (P-NR) besteht aus n Arbeitspaketen (A-NR), die jeweils einem Projekt
	eindeutig zugeordnet sind. Die Arbeitspakete sind untereinander zu einem
	hierarchischen Projektstrukturplan verbunden, wobei ein Arbeitspaket in mehrere
	weitere Arbeitspakete untergliedert werden kann, während jedes Arbeitspaket
	genau einem, hierarchisch übergeordneten Arbeitspaket untergeordnet ist.

• Jedem Arbeitspaket werden ein oder mehrere Mitarbeiter (SV-NR) zugewiesen,
	wobei Mitarbeiter auch in mehreren Arbeitspaketen beschäftigt sein können.
	Mitarbeiter weisen bestimmte Qualifikationen (Q-ID) auf und werden Abteilungen
	(A-ID) zugewiesen.

• Ein Arbeitspaket kann eine oder mehrere Qualifikationen erfordern.

• Jedes Projekt hat einen Mitarbeiter als Verantwortlichen, wobei allerdings ein
	Mitarbeiter auch für mehrere Projekte Verantwortung tragen kann.
~~~

1. **Führen Sie obiges ER-Modell in eine relationale Tabellendefinition über,
	wobei Sie zu jeder Tabelle den Primärschlüssel angeben.**  
	
2. **Kann ein Informationssystem, das auf diesem ER-Modell basiert, die
	Information liefern, welche Qualifikationen in Summe für die Abarbeitung
	eines Projektes**


## 2. Aufgabe: ERD-AUTORENSCHAFT
---
~~~
Bücher werden von Autoren erstellt. Dabei ist die Reihenfolge der
	Autorenauflistung für die Entlohnung wichtig.
~~~


