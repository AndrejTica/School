/*mab-inheritance-polymorphism.cpp
=================================================================
http://www.cplusplus.com/doc/tutorial/polymorphism/

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
