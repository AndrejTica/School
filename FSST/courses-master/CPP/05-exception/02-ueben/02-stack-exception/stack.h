// ahofmann, 2017, stack.h

#include <cstdlib>  // size_t

#include <new>				// !!!!!!!!!! std::bad_alloc
#include <stdexcept>      	// !!!!!!!!!! std::out_of_range
							// !!!!!!!!!! std::overflow_error
							// !!!!!!!!!! std::underflow_error

#pragma once

class Stack{
	private:
		double* stack;
		size_t size;
		size_t sp;
	public:
		Stack(size_t size=100) 		throw (std::bad_alloc);
		~Stack();
		
		double top() 				throw (std::underflow_error);
		void push(double v) 		throw (std::overflow_error);
		void pop() 					throw (std::underflow_error);
};
