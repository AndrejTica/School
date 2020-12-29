# Erste Schulwoche FSST5:CPP
---------------------------------------------------
A.Hofmann, 2016, Gitlab/ERSTE-SCHULWOCHE


## 1. AUFGABE: MYSTRING.CPP (programmieren)
---------------------------------------------------
* CPP/06-operator-overloading/03-wissen/01-mab-ue-mystring.cpp



## 2. AUFGABE: CFIRMA (CPP)
---------------------------------------------------
~~~
In der ANLAGE_UML_CFIRMA.pdf ist ein UML Diagramm gegeben.

a)Besprechen Sie die dargestellten Elemente und 
	beantworten Sie die enthaltenen Fragen.

b) Es sollen noch Programmierer hinzugefügt werden. 
Programmierer werden wie Arbeiter entlohnt und erhalten für ihren 
jeweiligen LinesOfCode-Wert eine Zusatzentlohnung. 
Fügen Sie die Klasse Programmierer in das UML-Diagramm ein.

c) Es soll nun die Klasse Firma erstellt werden, die alle Arbeiter, 
Verkäufer, … speichert und das monatliche Gehaltsaufkommen aller 
Personen errechnen lässt. 
Fügen Sie die Klasse Firma in das UML-Diagramm ein.

d) Programmieren Sie die obigen Aufgabenstellungen in der 
objektorientierten Programmiersprache C++ und 
gehen Sie auf die Begriffe Polymorphismus und spätes Binden ein.
Anlage: OOP1-COMPANY.zip

~~~



## 3. Quiz: mab-inheritance-polymorphism.cpp
---------------------------------------------------------
~~~
﻿/*
Quelle: http://www.cplusplus.com/doc/tutorial/polymorphism/

1.
-----------------------------------------------------------
Gegeben ist die Klassenhierarchie:
Polygon
	Triangle
	Rectangle
	
1.1. Bringen Sie das Programm zum Laufen, sodass die Ausgabe lautet: 
20
10
*/
// dynamic allocation and polymorphism
#include <iostream>
using namespace std;

class CPolygon {
	?????????????????????????????:
    int width, height;
  public:
    void set_values (int a, int b) { width=a; height=b; }
	//?????????????????????????????
    
    void printarea (void) { cout << this->area() << endl; }
  };

class CRectangle: public CPolygon {
  public:
    int area (void) { return (width * height); }
  };

class CTriangle: public CPolygon {
  public:
    int area (void){ return (width * height / 2); }
  };

int main () {
  CPolygon * ppoly1 = new CRectangle();
  CPolygon * ppoly2 = new CTriangle();
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly1->printarea();
  ppoly2->printarea();
  delete ppoly1;
  delete ppoly2;
  return 0;
}
~~~
