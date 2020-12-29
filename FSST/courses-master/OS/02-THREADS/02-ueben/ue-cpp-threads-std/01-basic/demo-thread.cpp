/*
 * g++ demo-thread.cpp -o demo-thread-exe -lpthread
 */
#include <iostream>
#include <thread>
using namespace std;

class FAQ {
public:
  int x_;

  FAQ(int x) {
    x_ = x;
    cout << "constructor: x_=" << x_ << ":" << this_thread::get_id() << endl;
  }

  void operator()() {
    cout << "thread-begin: x_=" << x_ << ":" << this_thread::get_id() << endl;

    while (x_ < 4) {
      x_++;
      cout << "thread-.....: x_=" << x_ << ":" << this_thread::get_id() << endl;
    }
  }

private:
};

int main() {
  cout << "main-tread-begin: " << this_thread::get_id() << endl;
  FAQ a(1);
  thread th_a(a);

  a.x_ = 3; // hat nur für den folg. th_b eine Auswirkung
  thread th_b(a);

  thread *th_c = new thread(a); // arbeitet auch wie th_b mit a.x_= 4
  a.x_ = 1000;                  // hat f. die threads keine bedeutung

  th_a.join();
  th_b.join();
  th_c->join();
  delete th_c;

  return 0;
}
