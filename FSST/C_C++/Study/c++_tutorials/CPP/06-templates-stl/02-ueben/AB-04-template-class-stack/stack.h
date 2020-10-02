// ANLAGE stack.h
// see: http://msdn.microsoft.com/en-us/library/f1b2td24.aspx

#pragma once
#include <iostream>
#include <sstream>
#include <stdexcept> // std::underflow_error, std::overflow_errer
#include <new> 		// std::bad_alloc
using namespace std;

// forward decl and // decl of c-func
template <typename T> class Stack;
template <typename T> ostream& operator<< ( ostream& o, const Stack<T>& other);

// the class stack as template class
template <typename T>
class Stack{
private:
	T* stack_;
	unsigned size_;
	unsigned stackptr_;
public:
	Stack(int iSize=100) 			throw (std::bad_alloc);
	Stack(const Stack<T>& other) 	throw (std::bad_alloc);
	~Stack();

	T& top() const;
	void pop() 						throw (std::underflow_error);
	void push(T& value) 			throw (std::overflow_error);

	friend ostream& operator<< <>( ostream& o, const Stack<T>& other);

// Question: Which operator is missing?
// Answer: 
};

// cons, destr
// -----------------------------------------------------------------------------
template <typename T>
Stack<T>::Stack(int isize) throw (std::bad_alloc) {
	size_= isize;

	stack_= _________________________________________

	stackptr_= 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) throw (std::bad_alloc) {
	size_= other.size_;

	stack_= _________________________________________

	for (int i=0; i < size_; i++){
		stack_[i]= other.stack_ [i];
	}
}

template <typename T>
Stack<T>::~Stack(){
	_________________________________________________
}

// methods for stack
// -----------------------------------------------------------------------------

___________________________________________top() const{

	_________________________________________________
}


___________________________________________pop() throw (std::underflow_error){
	if (stackptr_ <= 0){
		ostringstream o;
		o << "\nerror:" <<__FILE__ << ":" << __LINE__ << ": pop(): ";
		o << "stackptr_: " << stackptr_ << endl;
		o << *this<<endl;

		throw std::underflow_error(o.str());		
	}else{
		
		_________________________________________________
	}
}

____________________________________push(T& value) throw (std::overflow_error){
	if (stackptr_ >= size_){
		ostringstream o;
		o << "\nerror:" <<__FILE__ << ":" << __LINE__ << ": push(): ";
		o << "stackptr_: " << stackptr_ << endl;
		o << *this<<endl;

		throw std::overflow_error(o.str());		
	}else{

		____________________________________________________
	}
}

// operators
// -----------------------------------------------------------------------------
// ????????????????????







// output
template <typename T>
ostream& operator<<( ostream& o, const Stack<T>& other){
	o << "The Stack ... " << "size= " << other.size_ << " ..." << endl;
	for (int i=0; i < other.size_; i++){
			o << "." << i << ". " << other.stack_[i] << endl;
	}
	return o;
}
