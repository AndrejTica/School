// association.h
//
#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <cstring>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Association {
	private:
		struct pair {char* key; T value; };
		pair* vect;
		int max;
		int current;
	public:
		Association (int);

		// search for aKey
		// return a reference to the integer part of its "pair"
		// if aKey has not been seen --> make a new pair
		//    but check for overflow: if so , grow the assoc-vector
		//...
		T& operator[] (const char*);
		void print_all() const;
	};

#endif
