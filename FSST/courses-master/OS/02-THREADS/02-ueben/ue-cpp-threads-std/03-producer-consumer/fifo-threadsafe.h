/*
 * fifo-threadsafe.h
 */

===ENTER CODE===
#include <stdexcept>
using namespace std;

// ----------------------------------------
class FIFO {
private:
  int *queue;
  int size, begin, end;

  // Sperrsync
  ===ENTER CODE=== mutex_sperr;

  // Ereignissync
  condition_variable cv;

public:
  FIFO(int size) {
    ===ENTER CODE===
  }
  ~FIFO() { ===ENTER CODE=== }

  int dequeue() {
    ===ENTER CODE===
  }

  bool isEmpty() {
  ===ENTER CODE===
  }

  bool isFull() {
  ===ENTER CODE===
  }

  void enqueue(int item) {
  ===ENTER CODE===
  }
};
