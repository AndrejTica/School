# Zuordnungsproblem: Stabile Hochzeit

- <https://de.wikipedia.org/wiki/Globales_Matching>
- <https://www.imn.htwk-leipzig.de/~medocpro/buecher/sedge1/k34t3.html>

## Zweck: verschiedene Zuordnungsprobleme

- __Teameinteilung__: Wer ist in welcher Mannschaft/Gruppe?
- __Sitzordnung__:  Wer sitzt neben wem?
- __Partnervermittlung__: Wer heiratet wenn?

## Ziele

- Sie wissen was ein Heiratsproblem ist.
- Sie können selbst erklären, was man dabei unter einer "stabilen Heirat" versteht.
- Sie kennen den Algorithmus zum Finden einer Mann- oder Frau-optimalen stabilen Heirat.
- Sie können diesen Algorithmus in eigenen Worten formulieren.
- Sie können diesen Algorithmus von Hand durchführen.
- Sie können diesen Algorithmus in einer Programmiersprache programmieren

## Annahmen: Stabile Hochzeit

Wir nehmen folg. an:

- n Herren
- n Damen
- Jeder Herr/Dame führt eine Rangliste.

Das Problem besteht nun darin, eine __Menge von n Ehen/Zuordnungen zu finden__, bei der __die Präferenzen aller__ Beteiligten berücksichtigt werden.

## RDP-Aufgabenstellung: FSST-ALGO-STABILE-HOCHZEIT

Bei Zuordnungsproblemen der folgenden Art

- Teameinteilung: Wer ist in welcher Mannschaft/Gruppe?
- Sitzordnung:  Wer sitzt neben wem?
- Partnervermittlung: Wer heiratet wenn?

kann als Mapping Algorithmus der sogenannte 'Stabile Hochzeits-Algorithmus'
eingesetzt werden.

1. Erklären Sie diesen Algorithmus auf der Grundlage der ANLAGE STABILE HOCHZEIT.
2. Zeigen Sie eine mögliche Implementierung in einer Programmiersprache Ihrer Wahl.
3. Was versteht man unter einer 'stabilen-Hochzeit'?
4. Was versteht man unter einer Mann bzw. Frau optimalen Lösung?

## ANLAGE STABILE HOCHZEIT

- Es gibt zwei Personengruppen, Männer und Frauen
- Jede Person hat eine Positionsliste von allen Personen des anderen Geschlechts.

- Die Personen werden nun so verheiratet/zugeordnet, dass
  - jede Person mit einer anderen verheiratet ist, die die beste Position in der Positionsliste der verbliebenen Heiratskandidaten hat.

- Gruppe der Frauen:

| Name  | Partner | Positionsliste     |
| ----- | ------- | ------------------ |
| Ann   |         | Pat,Romeo,Adam,Bob |
| Julia |         | Romeo,Adam,Bob,Pat |
| Eva   |         | Adam,Pat,Romeo,Bob |
| Alice |         | Bob,Romeo,Adam,Pat |
|       |         |                    |

- Gruppe der Männer:

| Name  | Partner | Rangliste           |
| ----- | ------- | ------------------- |
| Pat   |         | Ann,Julia,Eva,Alice |
| Romeo |         | Julia,Eva,Alice,Ann |
| Adam  |         | Eva,Ann,Julia,Alice |
| Bob   |         | Alice,Ann,Julia,Eva |
|       |         |                     |

## Hinweise zur Implementierung

Die Klasse Group:

~~~cpp
class Group {
private:
  map<string, Person *> members;
public:
  Group();
  ~Group();

  void addPerson(string name);
  // operator overloading
  Person& operator[](string name);

  Person *getPerson(string name);

  // Marry 
  void marry(Group& others);

  void printPartners();
};
~~~

Die Klasse Person:

~~~cpp
class Person {
private:
  string name;
  Person *partner;
  vector<string> positionList;  // stores name of Person

public:
  Person(string name);

  // operator overloading
  Person& operator<< (string name);

  // hochzeitsproblem lösung
  vector<string> getPositionList();

  bool isNotMarried();
  void divorce();
  void marry(Person *p);
  bool lovesMeMore(Person *p); // is p a better partner?

  string toString();
};
~~~


Die „Präferenzen“ stellen eine

- Liste mit den Namen aller möglichen Partner des anderen Geschlechts dar.
- Der vordere Listeneintrag verweist auf den Partner, den die Person am liebsten hätte.

## Instabile Hochzeit

- Ein Mann und eine Frau haben sich gegenseitig lieber als ihre jeweiligen Ehepartner.

## Algorithmus: Frau-optimale Lösung, weil Frau aussucht

- solange es noch eine unverheiratete Frau gibt:
  - Unverheiratete Frau macht oberstem Mann auf ihrer Rangliste einen Antrag:
    - wenn er unverheiratet ist
      - sie heiraten.
    - wenn er sie lieber hat als seine Frau 
      - er scheidet sich von seiner Frau 
      - und sie heiraten. 
    - sonst
      - sie streicht ihn von ihrer Liste.

~~~ cpp

#include "group.h"

int main()
{
  Group male;
  Group female;

  male.addPerson("Adam");  
  male.addPerson("Pat");   
  male.addPerson("Romeo"); 
  male.addPerson("Bob");   

  female.addPerson("Eva");   
  female.addPerson("Julia"); 
  female.addPerson("Ann");   
  female.addPerson("Alice"); 

  male["Adam"]  << "Eva"<<"Julia"<<"Ann"<< "Alice";
  male["Pat"]   << "Ann"<<"Julia"<<"Eva"<<"Alice";
  male["Romeo"] << "Julia"<<"Eva"<<"Ann"<<"Alice";
  male["Bob"]   << "Alice"<<"Julia"<<"Ann"<<"Eva";


  female["Alice"] << "Bob"<<"Pat"<<"Romeo"<<"Adam";
  female["Ann"]   << "Pat"<<"Romeo"<<"Bob"<<"Adam";
  female["Julia"] << "Romeo"<<"Pat"<<"Bob"<<"Adam";
  female["Eva"]   << "Adam"<<"Pat"<<"Bob"<<"Romeo";

  
  cout << "=== Female optimized ===" << endl;
  female.marry(male);
  female.printPartners(); // person-partner , person-partner, ...
  cout << endl;

  cout << "=== Male optimized ===" << endl;
  male.marry(female);
  male.printPartners();
  cout << endl;

  return 0;
}

// Ausgabe:
=== Female optimized ===
Alice   Partner(Bob)    ... positionlist: Bob,Pat,Romeo,Adam,
Ann     Partner(Pat)    ... positionlist: Pat,Romeo,Bob,Adam,
Eva     Partner(Adam)   ... positionlist: Adam,Pat,Bob,Romeo,
Julia   Partner(Romeo)  ... positionlist: Romeo,Pat,Bob,Adam,

=== Male optimized ===
Adam    Partner(Eva)    ... positionlist: Eva,Julia,Ann,Alice,
Bob     Partner(Alice)  ... positionlist: Alice,Julia,Ann,Eva,
Pat     Partner(Ann)    ... positionlist: Ann,Julia,Eva,Alice,
Romeo   Partner(Julia)  ... positionlist: Julia,Eva,Ann,Alice,
~~~
