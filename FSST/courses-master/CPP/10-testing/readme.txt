testing: CPP Testing
--------------------------------------------------------------------------------
readme.txt


Aufgabenstellungen

1. Erstellen Sie Programme zu den folgenden Aufgaben aus 
--------------------------------------------------------------------------------
	CPP/testing/01-lernen/

	Beispiel: CUTETest-01-ggt  --erstes kleines Beispiel



2. Erstellen Sie C-Programme zu den folgenden Aufgaben aus 
--------------------------------------------------------------------------------
	CPP/testing/02-ueben/

	Übung: CUTETest-01-ggt -- vervollständigen mit 22 Testfällen und Fehlerfinden
	
	Übung: CUTETest-02-stack
		void testEmptyStack() { … }	
		void testPush() { … }   // nach push() nicht leer?
		void testPopOnEmptyStack() {… }   // StackEmptyException
		void testPopOnStackWithOneElement(){ … }
		void testStackWithMoreThanOneElement() {...}
		
	Übung: CUTETest-03-queue
		void testEmpty(){}
		void testFull() throw (FullException){}
		void testEnqueueAndEmpty() throw FullException{}
		void testEnqueueDequeueAndEmpty() throws 
				EmptyException, FullException{ }
		void testFullException(){}
		void testEmptyException(){}
		void testtoString() throws FullException{}

Hinweis: Exception-Handling – Cpp
	http://www.cplusplus.com/reference/new/bad_alloc/ 

	// bad_alloc example
	#include <iostream>     // std::cout
	#include <new>          // std::bad_alloc

	int main () {
	  try
	  {
		int* myarray= new int[10000];
	  }
	  catch (std::bad_alloc& ba)
	  {
		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
	  }
	  return 0;
	}

	siehe auch:
	<stdexcept>
		overflow_error
		underflow_error
		
	

Zur Abgabe 
	1. TERMIN: Abgabe vor der nächsten Laboreinheit
	2. SVN-Ordner: testing
