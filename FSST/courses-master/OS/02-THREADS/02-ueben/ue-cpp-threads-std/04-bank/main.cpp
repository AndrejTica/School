/*
main.cpp

g++ -std=c++11 main.cpp angestellter.cpp bank.cpp -o main.exe -lpthread
*/


#include "simplebank.h"
#include "angestellter.h"

#include <iostream>
using namespace std;

int main() {
	SimpleBank bank;
	
	cout<< endl<< "*** LOST Update Problematik ***"<<endl;
	cout<< endl<< "Es sollen 20 Euro überwiesen werden..."<<endl<<endl;

	cout <<"VOR den Überweisungen:------------------------------"<<endl;
	bank.kontostand();

	// Eine ringförmige Überweisung

	std::thread A1(std::move(Angestellter(&bank, 0, 1, 20)));
	std::thread A2(std::move(Angestellter(&bank, 1, 2, 20)));
	std::thread A3(std::move(Angestellter(&bank, 2, 0, 20)));

	A1.join();
	A2.join();
	A3.join();

	cout <<"NACH den Überweisungen:-----------------------------"<<endl;
	bank.kontostand();
   
	return 0;
	}

/*

/*
01-thread-create04.cpp
g++ -std=c++11 01-thread-create04.cpp -o01-thread-create04.exe -lpthread


#include <iostream>
#include <thread>
 
class runnable{
    public:
        void operator()(){
            std::cout << "Hello World" << std::endl;
        }
};
 
int main(){
    std::thread t(std::move(runnable()));

    t.join();
    return 0;
}
*/
