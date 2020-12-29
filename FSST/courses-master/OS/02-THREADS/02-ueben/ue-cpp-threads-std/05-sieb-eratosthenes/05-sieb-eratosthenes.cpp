/**
g++ 05-sieb-eratosthenes.cpp -o 05-sieb-eratosthenes.exe -lpthread


Architektur:
- Main-thread -> worker(3) -> worker(5) -> worker(7) -> worker(11) -> ....

Main-thread: ist ein Zahlengenerator.
- erzeugt einen FIFO (threadsafe) namens buffer_send mit size 1
- erzeugt ein Worker-Objekt mit
        - Primzahl 3 und buffer_send
- erzeugt den Worker-thread für die Primzahl 3
- schreibt in den FIFO die Zahlen 5,7,9,11,13,...
        - buffer_send.enqueue(5)
        - ...
- schreibt in den FIFO -1 als Ende-Kennung
- join mit Worker-thread
- schreibt --- finished --- auf die Konsole


worker(prim): Konstruktor
- bekommt Primzahl (myPrime)
- bekommt Zeiger auf FIFO (buffer_receive; wurde vom Vorgänger-worker erzeugt)


worker (prim): operator()
- liest vom Vorgänger-worker die Zahl (int zahl= buffer_receive.dequeue())
- filtert alle Vielfachen von prim
- wenn kein Vielfaches und es gibt keinen worker_next
        - erzeugt einen FIFO (threadsafe; buffer_send mit size 1)
        - erzeugt ein Worker-Objekt mit (next= new Worker(zahl, buffer_send))
                - Primzahl (zahl)
                - Zeiger auf buffer_send
        - erzeugt einen Worker_thread (thread_next= new thread(next))
- wenn kein Vielfaches und es gibt einen worker_next
        - sende Zahl an thread_next (buffer_send.enqueue(zahl))

- wenn zahl==-1
        - gib myPrime aus
        - join mit thread_next, falls es diesen gibt

*/

#include <iostream>
using namespace std;

#include "fifo-threadsafe.h"
#include "worker.h"

int main(int argc, char *argv[]) {

  // zur Kommunkation mit dem Worker
  FIFO *buffer_send = ===ENTER CODE===(1);

  // ersten Worker für Primzahl 3
  Worker *worker = new Worker(3, buffer_send);
  thread *thread_worker = new thread(*worker);

  // 2 ist die kleinste Primzahl
  cout << 2 << ": thread-id= " << std::this_thread::get_id() << endl;

  // nächste ungerade Zahl
  int i = 5;
  while (i < 1000) {
    // ungerade Zahl an Worker senden: 5,7,9,11,...
    buffer_send===ENTER CODE===(i);
    i += 2;
  }

  // Abschlusskennung senden
  buffer_send===ENTER CODE===(-1);

  // join
  thread_worker->join();

  // clean and shutdown
  if (thread_worker)
    delete thread_worker;
  if (worker)
    delete worker;
  if (buffer_send)
    delete buffer_send;

  cout << "--- finished ---" << endl << endl;

  return 0;
}
