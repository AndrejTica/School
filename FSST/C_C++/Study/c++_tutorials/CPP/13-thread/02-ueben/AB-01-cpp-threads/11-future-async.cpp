/*
g++ 11-future-async.cpp -o 11-future-async.exe -lpthread
*/
#include <future>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using namespace std;

// Hilfsklasse zur Zeitmessung ------------------------------
class Time{
private:
    static chrono::steady_clock::time_point start;
public:
    static string getTime(){
        chrono::duration<double> d= chrono::steady_clock::now() - start;
        return "[" + to_string(d.count()) + "s] ";
    }

    static void init(){
        start= chrono::steady_clock::now();
    }
};
chrono::steady_clock::time_point Time::start= chrono::steady_clock::now();



// simulierte IO ------------------------------------------
string get_data_from_DB(){
	this_thread::sleep_for(chrono::seconds(4)); 
	return "... DATA FROM DB arrived ...";
}


// simulierte IO ------------------------------------------
string get_data_from_FILE(){
	this_thread::sleep_for(chrono::seconds(4)); 
	return "... DATA FROM FILE arrived ...";
}

// --------------------------------------------------------
int main(){
	cout << endl;
	cout << "DEMO: Data access via FILE and DB" << endl;
	cout << endl;

	cout << "1. without multithreading ..." << endl;
  cout << Time::getTime() << "... waiting for data from FILE"<<endl;
  string data= get_data_from_FILE();
	cout << Time::getTime() << data << endl;

  cout << Time::getTime() << "... waitingfor data from DB"<<endl;
  data= get_data_from_DB();
	cout << Time::getTime() << data <<endl;
  cout << Time::getTime() << "... DONE";
	cout << endl;



  Time::init();
  cout << endl;
	cout << "2. with multithreading (future, async) ..." << endl;
	future<string> future_data_FILE= async(get_data_from_FILE);
	future<string> future_data_DB= async(get_data_from_DB);

  cout << Time::getTime() << "... waiting for data from FILE"<<endl;
  data= future_data_FILE.get();
	cout << Time::getTime() << data << endl;

  cout << Time::getTime() << "... waiting for data from DB"<<endl;
  data= future_data_DB.get();
  cout << Time::getTime() << data << endl;
  cout << Time::getTime() << "... DONE";
	cout << endl;

	return 0;
}

/* output:
   
DEMO: Data access via FILE and DB

1. without multithreading ...
[0.000043s] ... waiting for data from FILE
[4.000168s] ... DATA FROM FILE arrived ...
[4.000188s] ... waitingfor data from DB
[8.000280s] ... DATA FROM DB arrived ...
[8.000311s] ... DONE

2. with multithreading (future, async) ...
[0.000116s] ... waiting for data from FILE
[4.000396s] ... DATA FROM FILE arrived ...
[4.000429s] ... waiting for data from DB
[4.000441s] ... DATA FROM DB arrived ...
[4.000445s] ... DONE

 */
