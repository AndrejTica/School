#include <iostream>
#include <string>

class Printable{
public:
    virtual std::string getClassName() = 0; //pure virtual funct. Every class has to have this, otherwise you cant instanciate it
};

class Entity : public Printable{
public:

   std::string getClassName(){return "Entity";}
                                                    
};

class Player : public Entity{
private:
    std::string m_Name;
public:
    Player(const std::string& name) : m_Name(name){}

    std::string getClassName(){return "Player";}
};



void Print(Printable* obj){ //this funct knows that printable has getClassName
                            //we can create here as many classes as we want and give them a different getClassName implementation, as long as it inherents from base

    std::cout << obj->getClassName() << std::endl;
}

int main(){

    Entity* e = new Entity();


    Player* p = new Player("Ondre"); 


    Print(e);
    Print(p);

}