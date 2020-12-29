#include <condition_variable>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
using namespace std;

#pragma once

// ----------------------------------------
class FIFO {
private:
  int *queue;
  int size, begin, end;

  // Sperrsync
  mutex mutex_sperr;

  // Ereignissync
  condition_variable cv;

public:
  FIFO(int size) {
    this->size = size + 1;
    this->queue = new int[size + 1];
    begin = 0;
    end = 0;
  }
  ~FIFO() { delete[] queue; }

  int dequeue() {
    unique_lock<std::mutex> lck(mutex_sperr);

    while (isEmpty())
      cv.wait(lck);

    int value = queue[end];
    end++;
    end %= size;

    cv.notify_all();
    return value;
  }

  bool isEmpty() {
    if (begin == end) {
      return true;
    }
    return false;
  }

  bool isFull() {
    if (end == (begin + 1) % size) {
      return true;
    }
    return false;
  }

  void enqueue(int item) {
    unique_lock<mutex> lck(mutex_sperr);

    while (isFull())
      cv.wait(lck);
    
    queue[begin] = item;
    begin++;
    begin %= size;

    cv.notify_all();
  }
};
