//instance of objects, heap vs stack

#include <iostream>
#include <string>

class Entity{

private:
 const char* m_Name; //char pointers are always read only, if there was no const and we try to edit the string -> error. Thats why its always const. 
                //if we want to edit this string we need to define it like an array usually char s[]

public: 
    Entity() : m_Name("Unknown"){} //constructor without paraments. He sets unknown as private variable
    Entity(const char* name) : m_Name(name){} //2. constructor with member init list.

  const char* getName() const {return m_Name;} //1. const -> we get a char* that cannot be modified, 2. const -> means the method itself can't change anything of the class. 
                                              //the 2. const always good when we have a method that is read only like getter. Cuz then const instances can't use that method
};


int main(){


  {
    Entity e("Hello from stack"); //stack init with 2. constructor. This object gets destroyed automatically at the end of scope (end of bracket) because its on stack
    std::cout << e.getName() << std::endl;
  }
  
    Entity* e2; 
    {
      e2 = new Entity(); //new gives back a void pointer of alocated mem space for object and the left part says what type the pointer is. With objects it also calls the constructor
    //e2 = (Entity*)malloc(sizeof(Entity)) -> this is the same as above in C. the only difference is that the constructor is not called here
      
   //we use this when we dont want the object to be destroyed at the end of scope
    }

    {
    std::cout << e2->getName() << std::endl;  //we could also write (*e2) to derefence the e2 pointer. Arrow does the same thing
    }
 
  delete e2;

}