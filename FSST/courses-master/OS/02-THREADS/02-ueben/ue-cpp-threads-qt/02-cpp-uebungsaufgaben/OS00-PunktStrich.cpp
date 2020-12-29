/**
 * Punkte und Striche werden abwechselnd gezeigt.
 * Der Scheduler ist für das Wechseln zuständig.
 */

#include <QThread>
#include <iostream>
using namespace std;

//                      !!!!!!!!!!!!!!!
class PunktStrichThread : public  QThread {
private:
	string s;
public:
	PunktStrichThread(string s){
		this->s= s;
	}
	// ***** ENTER CODE HERE ***** //
};

int main(int argc, char *argv[]){
	PunktStrichThread punkt(".");
	PunktStrichThread strich("-");

	punkt.start();   
	strich.start();  

	punkt.wait(5000); // wait 5 sec
	punkt.terminate();
	strich.terminate();

	return 0;
}
