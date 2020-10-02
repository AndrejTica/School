//cpp06.cpp
///////////
// A macro versus an inline function
#include <iostream>
using namespace std;

#define MAX(A,B)   ((A) > (B) ? (A) : (B))

inline int max(int a, int b)
{
if a > b then 
	return a;
else
	return b;
}

int main()
{
int i,x=23,y=45;

i= MAX (x++,y++);    //Side-effect:
                     //larger value incremented twice
cout << "x= " << x << "y= " << y << '\n';


x=23; y= 45;
i= max(x++,y++);     // Works as expected
cout << "x= " << x << "y= " << y << '\n';

return 0;
}
