/*
g++ 08-lost-update-lock_guard.cpp -o 08-lost-update-lock_guard.exe -lpthread

AUFGABE:
Verwenden Sie statt des Mutex einen sogenannten lock_guard.
*/

#include <thread>
#include <mutex>
#include <iostream>
using namespace std;


class LostUpdate{
private:
	// shared memory
	static int count;
	static mutex m;
	
public:
	static int getCount(){
		return count;
	}

	void operator() (){
		
		for (int i=1; i<=10000000; i++){
			===ENTER CODE===; //!!!!!!!!!!!!!!!!!!!!
			count++;
		}
	}
};
// init shared memory
int LostUpdate::count=0;
mutex LostUpdate::m;

int main(){
	LostUpdate obj1;
	LostUpdate obj2;

	cout << "LostUpdate Problem: 2 threads increment shared memory (each by 10000000)."<< endl;
	cout << "... Result should be: " << "20000000"<<endl;

	cout << "... Before incr: Shared memory= " << LostUpdate::getCount() << endl;

	thread t1(obj1);
	thread t2(obj2);
 
	t1.join();
	t2.join();

	cout << "... After incr: Shared memory= " << LostUpdate::getCount() << endl;

	return 0;
}

