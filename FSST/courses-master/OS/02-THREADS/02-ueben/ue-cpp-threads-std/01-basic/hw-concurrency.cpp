/*
hw-concurrency.cpp
g++ -std=c++11 hw-concurrency.cpp -o hw-concurrency.exe -lpthread
*/

#include <iostream>
#include <thread>

int main() {
	    std::cout << std::thread::hardware_concurrency() << std::endl;
	        return 0;
}


