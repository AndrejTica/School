#include <iostream>
#include <string>


class Entity{
public:
   virtual std::string getName() {return "Entity";} //virtual immer in base class schreiben. Basically just tells c++ to watch out what type of object intance 
                                                    //it recieves. WIthout virtual it just kinda doesn't care and takes the base method every time
};

class Player : public Entity{
private:
    std::string m_Name;
public:
    Player(const std::string& name) : m_Name(name){}

    std::string getName(){return m_Name;}

};

void PrintName(Entity* entity){ //hier wird immer die baseclass genommen weswegen er immer die base methode nimmt

    std::cout << entity->getName() << std::endl; //so this function and every else have the option to basically override the base function. 
                                                //Virtual basically allows overrides
}

int main(){

    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player("Ondre"); //player instanz, aber wenn wir es der funct übergeben, nimmt es getName von der Baseclass, wir wollen aber von subclass player
    PrintName(p);   //wie können wir C++ sagen, dass wenn wir Player haben, er auch die player funktion nimmt? -> virtual functions saves the day

}