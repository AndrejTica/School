/*
# AUFGABE

mab_inheritance_polymorphism.cpp

- <http://www.cplusplus.com/doc/tutorial/polymorphism/>

1. Gegeben ist die Klassenhierarchie:
  - Polygon
    - Triangle
    - Rectangle
	
2. Bringen Sie das Programm zum Laufen, sodass die Ausgabe lautet: 
20
10

*/

#include <iostream>
using namespace std;

class Polygon
{

protected:

  int width, height;

public:
  void set_values(int a, int b)
  {
    width = a;
    height = b;
  }

  virtual int area(void) = 0;

  void printarea(void) { cout << this->area() << endl; }
};

class Rectangle : public Polygon
{
public:
  int area(void) { return (width * height); }
};

class Triangle : public Polygon
{
public:
  int area(void) { return (width * height / 2); }
};

int main()
{
  Polygon *ppoly1 = new Rectangle(); //base class pointer vvvvvvvvvvvv
  Polygon *ppoly2 = new Triangle();

  ppoly1->set_values(4, 5);
  ppoly2->set_values(4, 5);

  ppoly1->printarea();
  ppoly2->printarea();

  delete ppoly1;
  delete ppoly2;

  return 0;
}
