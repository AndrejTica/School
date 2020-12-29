#ifndef SIMPLEBANK_H
#define SIMPLEBANK_H

#include <iostream>       // std::cout
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <mutex>
using namespace std;


class SimpleBank {
	private:	
		int konten[3]={30, 50, 100}; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		===ENTER CODE===

	public:
		void ueberweisung(int von, int nach, int betrag) {
			int neuerBetrag;
===ENTER CODE===

			neuerBetrag = konten[von];
			neuerBetrag -= betrag;

			// Inkonsistenz, da neuer Betrag noch nicht vermerkt
			std::chrono::seconds one_second(1);
 			std::this_thread::sleep_for (one_second);


			konten[von] = neuerBetrag;

			neuerBetrag = konten[nach];
			neuerBetrag += betrag;
			// dito
			konten[nach] = neuerBetrag;
===ENTER CODE===
		}

		
		void kontostand() {
			for(int i = 0; i < 3; i++)
				cout << "Konto " << i << ": " << konten[i] << endl;
		}
};

#endif


/*
// this_thread::sleep_for example
#include <iostream>       // std::cout
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
 
int main() 
{
  std::cout << "countdown:\n";
  std::chrono::seconds one_second(1);
  for (int i=10; i>0; --i) {
    std::cout << i << '\n';
    std::this_thread::sleep_for (one_second);
  }
  std::cout << "Lift off!\n";

  return 0;
}
*/
