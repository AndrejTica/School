#include <iostream>
#include <cstring>

//copy constructor:
/*
    int a = 2;
    int b = a; 2 variablen mit verschiedenen addressen, bei ändern von b, a bleibt 2
    b = 3;       man kopiert was in a ist, in b, das gleiche funktioniert mit classen, structs

    wenn man es mit pointern macht, wird es ganz anders

    struct  Vector{
        float x, y;
    }

    Vector* a = new Vector();
    Vector* b = a;
    b++                 am anfang zeigen die beiden pointer auf die gleiche addresse, mit b++ wird der pointer b nur nach rechts verschoben, a bleibt
    b->x = 2;           wenn man ohne b++ das macht, ändert man den address wert, da a und b beide auf gleiche addresse zeigen, wird beides beeinflust

    copyconsttructor brauchen wir also wenn wir ein object kopieren, um für die pointer variablen einen eigenen address bereich zu bekommen,
    so, wenn wir einen verändern, wird der andere verschont

*/

using namespace std;

class MyString{

private:
    char* buffer;
    unsigned int size;
public:
    MyString(const char* string){

    size = strlen(string);  //ccalculate how long the string is
    buffer = new char[size+1]; //give that much memory to the buffer with the string ende zeichen
    for (int i = 0; i < size; i++)
        buffer[i] = string[i];     //fill the buffer with the string

    buffer[size] = 0; //string ende zeichen wird am ende gesetzt. dient dazu das der pointer nicht über unser string geht

    }
    friend ostream& operator<<(ostream& o, const MyString& string);


    ~MyString(){        //destructor to free the memory at the end so that it doesnt overflow
        delete[] buffer;

    }

    /*
    Standard c++ copy constructor: (shallow copy)

    MyString(const String& other) : buffer(other.buffer), size(other.size) { }
    */

    //now the real copy constructor (deep copy)
    MyString(const MyString& other) : size(other.size) { //always pass the objects by const reference
        buffer = new char[size+1];  //neuer speicher wurde fregegeben
        for (int i = 0; i < size; i++)
        buffer[i] = other.buffer[i];    //fühle den neuen buffer mit den werten von other buffer (og classe)

    }          //int kann man shallow copy machen

     char& operator[](unsigned int index){ //überladung für [], damit er weiß mit einer mit der referenz können wir den char array überarbeiten mit sglobal1[1] = 5; wenn keine referenz, dann heisst es, es ist eine copie
        return this->buffer[index]; //bei op überladen ist wie eine normale funktion, zu erst der rückgabe typ
             //das this-> is überflüssig, weil wir eh auf buffer zugreifen können. es ist ja ein pointer buffer auf die erste stelle die mit inded verändert wird
     }


};



 ostream& operator<<(ostream& o, const MyString& string){ //<< wird überladen das es von einem Object eine variable (buffer) ausgeben kann
 o << string.buffer;    //wir können die private memeber deswegen zugreifen weil diese op überladung ein freund von der klasse MyString ist
 }

int main()
{
   MyString string1 = "Andrej";
   //jetzt sagen wir wollen den string kopieren in ein anderes onjekt
   MyString string2(string1); //wir haben also jetzt 2 char pointer die auf die gleiche addresse zeigen. Das programm stürtzt so ab wegen dem destructor
                               //wenn wir am ende des programms sind, freet der destructor den gleichen speicher block 2 mal, also stürtzt es ab
   string2[3] = 'O';       //wir wollen unser string an stelle 1 bearbeiten, aber vorher []operator überladen damit er mit einer klasse funktioniert
                            //beide werden wieder überschrieben

   cout << string1 << endl;
   cout << string2 << endl;
}
