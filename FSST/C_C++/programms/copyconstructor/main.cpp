#include <iostream>

using namespace std;

class Demo{

   int * ptr;

    public:
    Demo(int a) {
    ptr = new int(a);
    }

    ~Demo() {
    delete ptr;
    }

    void set(int a){
    *ptr = a;
    }

    int get() const { //const because this function doesnt change anything, ensurance
    return *ptr;
    }

    Demo(const Demo& d){ //it has to be a reference to the source object. const to not change the source object
    ptr = new int; //brand new int pointer because it has different memory location
    *ptr = *(d.ptr); //den wert von source pointer in den neuen pointer kopieren
    }



};

//ccopy constructor is used when having pointers in your class because a pointer ptr

int main()
{
    Demo dog(8);

    Demo cat(dog); // Demo cat = dog;

    cout << dog.get() << "\t" << cat.get() << "\n";

    dog.set(99); //without copy constructor, we get output 99 after setting cat to dog, because the pointer of them both is pointing to the same variable
                    //ccopy cconstrucotr gets ccalled when we pass an object into an object, it creates new variables basically

    cout << dog.get() << "\t" << cat.get() << "\n";


}
