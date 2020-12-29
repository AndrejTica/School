// ahofmann, 2017, stack.h

#include <cstdlib>  // size_t

#pragma once

class Stack{
	private:
		double* stack;
		size_t size;
		size_t sp;
	public:
		Stack(size_t size=100);
		Stack(const Stack& other);
		~Stack();
		
		double top();			// liefert oberstes Stack-Element
		void push(double v);	// legt einen Wert auf den Stack
		void pop();				// 'löscht' oberstes Stack-Element
};
