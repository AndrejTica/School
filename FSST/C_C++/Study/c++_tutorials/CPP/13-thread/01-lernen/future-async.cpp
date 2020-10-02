#include <future>
#include <thread>
#include <chrono>
#include <string>
#include <iostream>
using namespace std;

// Hilfsklasse zur zeitmessung
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

// simulierte IO
string get_data_from_DB(){
        this_thread::sleep_for(chrono::seconds(4));
        return "... DATA FROM DB arrived ...";
}

string get_data_from_FILE(){
        this_thread::sleep_for(chrono::seconds(4));
        return "... DATA FROM FILE arrived ...";
}

int main(){
        cout << endl;
        cout << "DEMO: Data access via FILE and DB" << endl;
        cout << endl;

        cout << "1. without multithreading ..." << endl;
        cout << Time::getTime() << "... waiting for data from file" << endl;
        string data= get_data_from_FILE();
        cout << Time::getTime() << data << endl;

        cout << Time::getTime() << "... waiting for data from db" << endl;
        data= get_data_from_DB();
        cout << Time::getTime() << data << endl;

        cout << endl<<endl;

        Time::init();
        cout << "2. with multithreading ..." << endl;

        future<string> future_data_file= async(launch::async, get_data_from_FILE);
        future<string> future_data_db= async(launch::async, get_data_from_DB);

        cout << Time::getTime() << "... waiting for data from file" << endl;
        data= future_data_file.get();
        cout << Time::getTime() << data << endl;

        cout << Time::getTime() << "... waiting for data from db" << endl;
        data= future_data_db.get();
        cout << Time::getTime() << data << endl;
        cout << Time::getTime() << "...DONE..." <<endl;

}

