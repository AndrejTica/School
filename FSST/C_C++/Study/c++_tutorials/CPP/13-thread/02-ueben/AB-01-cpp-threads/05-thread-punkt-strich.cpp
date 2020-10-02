/*
  g++ -std=c++11 punkt-strich.cpp -o punkt-strich.exe -l pthread
*/

#include <thread>
#include <iostream>
#include <string>
using namespace std;

class PunktStrich {
private:
	string s;
public:
	PunktStrich(string s){
		this->s= s;
	}

	void operator() (){
		while(true){
			cout << s;
		}
	}
};

int main(){
	PunktStrich obj1(".");
	PunktStrich obj2("-");

	// treads starten
	thread t1(obj1);
	thread t2(obj2);

	// warten.
	t1.join();

	return 0;
}

