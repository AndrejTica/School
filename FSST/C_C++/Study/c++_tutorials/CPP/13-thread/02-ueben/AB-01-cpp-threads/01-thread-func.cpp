/*
01-thread-func.cpp
g++ -std=c++11 01-thread-func.cpp -o01-thread-func.exe -lpthread
*/
#include <iostream>
#include <thread>

static void func(){
    std::cout << "Hello World" << std::endl;
}

int main(){
    std::thread t(func);

    t.join();

    return 0;
}
