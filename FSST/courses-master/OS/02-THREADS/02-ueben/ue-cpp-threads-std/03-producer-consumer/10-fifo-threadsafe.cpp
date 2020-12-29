/*
10-fifo-threadsafe.cpp
g++ 10-fifo-threadsafe.cpp -o 10-fifo-threadsafe.exe -lpthread
*/

#include <iostream>
#include <thread>
using namespace std;

#include "===ENTER CODE==="

// --------------------------------------
class Producer{
private:
  FIFO *fifo;

public:
  Producer(FIFO *fifo) { this->fifo = fifo; }

  void produce() {
    for (int i = 1; i <= 5000; i++) {
      cout << "PRODUCER: enqueue " << i << endl;
      fifo->enqueue(i);
    }
  }

  void operator()() { produce(); }
};


// --------------------------------------
class Consumer {
private:
  FIFO *fifo;

public:
  Consumer(FIFO *fifo) { this->fifo = fifo; }

  void consume() {
    for (int i = 1; i <= 5000; i++)
      cout << "\t\t\t\tCONSUMER: dequeue " << fifo->dequeue() << endl;
  }
  void operator()() { consume(); }
};


// --------------------------------------
int main(int argc, char *argv[]) {

  FIFO *fifo = ===ENTER CODE===(5);

  Producer producer(===ENTER CODE===);
  Consumer consumer(===ENTER CODE===);

  thread thread_producer(producer);
  thread thread_consumer(consumer);

  thread_producer.join();
  thread_consumer.join();

  return 0;
}
