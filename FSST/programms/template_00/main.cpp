#include <iostream>
#include <string>

using namespace std;


 template<typename T>
void Print(T value){      // t Print ??

  cout << value << endl;
 }


template<typename T, int N> //typename heisst jede variable kann ersetzt werden
 class Array{
private:
    T Array[N];             //ein array muss schon vor compilieren normalerweise definiert sein. mit template können wir es verändern
public:
    int GetSize() const { return N;}
 };







int main()
{
    Array<int, 6> array;

    Print<int>(5);  //specify the type
    Print("Hello");
    cout << array.GetSize() << endl;


    return 0;
}
