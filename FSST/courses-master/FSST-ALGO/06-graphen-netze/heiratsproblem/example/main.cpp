
#include "group.h"

int main()
{
  Group male;
  Group female;

  male.addPerson("Adam");  
  male.addPerson("Pat");   
  male.addPerson("Romeo"); 
  male.addPerson("Bob");   

  female.addPerson("Eva");   
  female.addPerson("Julia"); 
  female.addPerson("Ann");   
  female.addPerson("Alice"); 

  male["Adam"]  << "Eva"<<"Julia"<<"Ann"<< "Alice";
  male["Pat"]   << "Ann"<<"Julia"<<"Eva"<<"Alice";
  male["Romeo"] << "Julia"<<"Eva"<<"Ann"<<"Alice";
  male["Bob"]   << "Alice"<<"Julia"<<"Ann"<<"Eva";


  female["Alice"] << "Bob"<<"Pat"<<"Romeo"<<"Adam";
  female["Ann"]   << "Pat"<<"Romeo"<<"Bob"<<"Adam";
  female["Julia"] << "Romeo"<<"Pat"<<"Bob"<<"Adam";
  female["Eva"]   << "Adam"<<"Pat"<<"Bob"<<"Romeo";

  
  cout << "=== Female optimized ===" << endl;
  female.marry(male);
  female.printPartners(); // person-partner , person-partner, ...
  cout << endl;

  cout << "=== Male optimized ===" << endl;
  male.marry(female);
  male.printPartners();
  cout << endl;

  return 0;
}
