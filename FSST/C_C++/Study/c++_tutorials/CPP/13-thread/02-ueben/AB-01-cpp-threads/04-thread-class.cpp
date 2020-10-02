/*
01-thread-class.cpp
g++ -std=c++11 01-thread-class.cpp -o01-thread-class.exe -lpthread
*/

#include <iostream>
#include <thread>

class MyThread{
    public:
        void operator()(){
            std::cout << "Hello World" << std::endl;
        }
};

int main(){

	MyThread mythread;

	std::thread t(mythread);

    t.join();

    return 0;
}
