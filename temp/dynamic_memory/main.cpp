#include <iostream>



void stackArray(int size)       //stack array
{      

    int arr[size];

    for(int i=0; i<size; i++)
    {
        arr[i]=i;
       std::cout << "arr[" << i << "]=" << arr[i]  << std::endl;

    };

};

void heapArray(int size)
{

    int* ptr = new int[size];
     for(int i=0; i<size; i++)
    {
        ptr[i]=i;
       std::cout << "arr[" << i << "]=" << ptr[i]  << std::endl;

    };

    delete[] ptr;

};



int main(){

    // int sizeStack;
    // int sizeHeap;
    // std::cout << "Enter stack array size" << std::endl;
    // std::cin >> sizeStack;

    // stackArray(sizeStack);


    // std::cout << "Enter heap array size" << std::endl;
    // std::cin >> sizeHeap;
    // stackArray(sizeHeap);


    int test;

    {
        int test2 = 4;
        test = test2;
    }

    std::cout << test << std::endl;
 
};