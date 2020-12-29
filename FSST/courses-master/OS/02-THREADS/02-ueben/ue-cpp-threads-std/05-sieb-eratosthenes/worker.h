// worker.h

#ifndef WORKER_H
#define WORKER_H

#include <thread>
#include <iostream>
using namespace std;

#include "fifo-threadsafe.h"

class Worker {
private:
  /** die Primzahl, für die der Worker zuständig ist */
  int myPrime;

  /** der nächste Worker in der "Pipe" */
  Worker *next = nullptr;
  thread *thread_next = nullptr;

  /** der Sende-/Empfangs-Puffer zur Kommunikation*/
  FIFO *buffer_receive;
  FIFO *buffer_send;

public:
  Worker(int prime, FIFO *buffer_receive) {
    ===ENTER CODE===
  }

  /** "Arbeitsroutine" des Workers.
   * Es werden ungerade Zahlen empfangen, wenn diese
   * Vielfache der "eigenen" Primzahl sind, dann werden
   * sie "verschluckt", andernfalls an den nächsten
   * Worker weitergereicht
   */
  void operator()() {

    // Zahl empfangen
    int zahl = buffer_receive->dequeue();

    while (zahl > 0) { // arbeite, solange i positiv ist
        // wenn zahl nicht Vielfaches von myPrime
        // erzeuge neuen Nachfolger-Thread oder
        // wenn er bereits existiert sende ihm
        // die Variable zahl
      
      ===ENTER CODE===
      
      
      // nächste Zahl holen
      zahl = this->buffer_receive->dequeue();

    } // end while

    // ENDE:
    // gib myPrime aus und
    cout << myPrime << ": thread-id= " << std::this_thread::get_id() << endl;
    
    // sende -1 evtl. weiter
    ===ENTER CODE===
    // evtl. join 
    ===ENTER CODE===
  }

}; // end Worker

#endif // WORKER_H
