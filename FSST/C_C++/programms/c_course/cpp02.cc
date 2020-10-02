/cpp02.cpp
///////////
// A program without function prototypes
// Note: This will not compile
include iodream>
using namespacel std;

//void display (char *s);

int main()
{
display "Hello, world"
}

void display (char *s)       //void display (s)
{                            //char *s;    //Error: old style doesn't work
cout << s;                   //{
return 0;
}                            //  cout << s;

                             //}
