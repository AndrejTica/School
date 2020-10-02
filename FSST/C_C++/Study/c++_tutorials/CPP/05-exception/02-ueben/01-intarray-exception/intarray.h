// intarray.h
// with exception
// ahofman, 2016

#pragma once

#include <string>

#include <new>				// !!!!!!!!!! std::bad_alloc
#include <stdexcept>      	// !!!!!!!!!! std::out_of_range

using namespace std;


class Intarray{
	private:
        int* a;
        int size;
public:
	// Konstruktoren
	//Intarray() throw (std::bad_alloc) ;            			// default cons
	Intarray(int size=100, int value=99) throw (std::bad_alloc) ;// 100 mal 99

	Intarray(const Intarray& other)throw (std::bad_alloc);  // Copy cons !!!!!
	Intarray(int* o, int len)throw (std::bad_alloc);    // Typumwandlungs-cons

	// Destructor
	~Intarray();

	// Konvertierungen
	string toString() const;
	

	void setAt(int i, int value)throw (std::out_of_range);

	void append(const Intarray& other)throw (std::bad_alloc);
	
	Intarray* clone()throw (std::bad_alloc);
	


/*	
	//+Intarray(100);		 // allg. cons 100 mal 0
	//+Intarray(6,1,45);    // 6 Zufallszahlen zw. 1...45
	// allg. Methoden
	//+void sort();
	//+double getMittelwert() const;

	//get/set
	void setAt(int i, int value);
	//+int getAt(int) const;

	void append(const Intarray& other);
//mab: void append(int* arr, int len);
	//+void append(int value);

	Intarray* clone();
//mab:	Intarray* getSubArray(int von_idx, int bis_idx);
//mab:	void insertAt(int i, const Intarray& other);

	// math
	void add(const Intarray& other) // Elementweises addieren
	int skalarProdukt(const Intarray& other);
	Intarray* durchschnitt(const Intarray& other);
	Intarray* vereinigung(const Intarray& other);
	Intarray* differenz(const Intarray& other);
*/
};
