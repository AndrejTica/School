/*
QMutex is the basic class for enforcing mutual exclusion. A thread locks a mutex in order to gain access to a shared resource. If a second thread tries to lock the mutex while it is already locked, the second thread will be put to sleep until the first thread completes its task and unlocks the mutex.
*/
#include <QThread>
#include <QMutex> // !!!!!!!!!!!!
#include <string>
#include <iostream>
using namespace std;

class LostUpdate : public QThread{
private:
	string s;

	// gemeinsamer Speicher: Hier eine static Variable
	static int count;
	
	// gegenseitiger Ausschluß !!!!!!!!!!!!!!!!!!!!!!
	// ***** ENTER CODE HERE ***** //
	static ________________________ mutex;
	
public:
	LostUpdate(string s){
		this->s=s;
	}

	void run() override {
		for (int i = 1; i <=5; i++) {

			// ***** ENTER CODE HERE ***** //

			// READ
			int temp;
			temp= count;
			cout << s << "READ: " << temp<<endl;
			QThread::msleep(50);

			// INCR
			temp= temp + 1;
			cout << s << "INCR: " << temp<<endl;
			QThread::msleep(20);

			//WRITE
			count= temp;
			cout << s << "WRITTEN: " << temp<<endl;
			QThread::msleep(20);

			// ***** ENTER CODE HERE ***** //

		}
	}
};

// static member
int LostUpdate::count=1;

// ***** ENTER CODE HERE ***** //
QMutex ____________________________;



int main(int argc, char *argv[]){
	LostUpdate* t1= new LostUpdate("THREAD1: ");
	LostUpdate* t2= new LostUpdate("\t\t\t\tTHREAD2: ");

	t1->start();
	t2->start();

	t1->wait();  //vgl. join
	t2->wait();

	return 0;
}
