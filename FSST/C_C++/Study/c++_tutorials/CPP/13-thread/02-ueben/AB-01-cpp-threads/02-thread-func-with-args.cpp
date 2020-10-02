/*
01-thread-func-with-args.cpp
g++ -std=c++11 01-thread-func-with-args.cpp -o 01-thread-func-with-args.exe -lpthread
*/


#include <iostream>
#include <thread>

static void func(int a, int b){
    std::cout << "Hello World: " << a << ", " << b << std::endl;
}

int main(){

    std::thread t(func, 10, 20);

    t.join();

    return 0;
}
