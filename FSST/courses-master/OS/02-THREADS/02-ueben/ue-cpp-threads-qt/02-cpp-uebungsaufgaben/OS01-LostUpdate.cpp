#include <QThread>
#include <string>
#include <iostream>
using namespace std;

class LostUpdate : public QThread{
private:
	string s;

	// gemeinsamer Speicher: Hier eine static Variable
	static int count;

public:
	LostUpdate(string s){
		this->s=s;
	}

	void run() override {
		for (int i = 1; i <=5; i++) {
			// READ
			int temp;
			temp= count;
			cout << s << "READ: " << temp<<endl;
			//QThread::msleep(50);

			// INCR
			temp= temp + 1;
			cout << s << "INCR: " << temp<<endl;
			QThread::msleep(20);

			//WRITE
			count= temp;
			cout << s << "WRITTEN: " << temp<<endl;
			//QThread::msleep(20);
		}
	}
};
int LostUpdate::count=1; // static member


int main(int argc, char *argv[])
{
	LostUpdate* t1= new LostUpdate("THREAD1: ");
	LostUpdate* t2= new LostUpdate("\t\t\t\tTHREAD2: ");

	t1->start();
	t2->start();

	t1->wait();  //vgl. join
	t2->wait();

	return 0;
}
