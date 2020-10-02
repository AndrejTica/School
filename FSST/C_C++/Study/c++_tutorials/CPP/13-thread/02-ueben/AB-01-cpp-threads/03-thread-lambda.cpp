/*
01-thread-lambda.cpp

g++ -std=c++11  01-thread-lambda.cpp -o 01-thread-lambda.exe -lpthread

 */

#include <thread>
#include <iostream>
using namespace std;

int main(){

	thread t1([](){ cout << "Hi from thread" << endl;});

	t1.join();

	return 0;
}
