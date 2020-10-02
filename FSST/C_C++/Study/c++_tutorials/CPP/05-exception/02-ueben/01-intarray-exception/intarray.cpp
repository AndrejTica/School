b// ahofmann 2016
// intarray.cpp

#include "intarray.h"

#include <sstream>
#include <new>				// !!!!!!!!!! std::bad_alloc
#include <stdexcept>      	// !!!!!!!!!! std::out_of_range

using namespace std;


void Intarray::setAt(int i, int value)throw (std::out_of_range){
	if (i>=0 && i<size)
		a[i]= value;
	else{
		// !!!!!!!!!!!!! exception
		ostringstream oErr;
		oErr << __FILE__ <<":" << __LINE__ << ": Error: out_of_range ";
		oErr << "size= " << this->size << " index= " << i << endl; 
		oErr << this->toString();

		throw std::out_of_range(oErr.str());

	}
}

Intarray::Intarray(int size, int value)throw (std::bad_alloc){ //allg. cons
	try{
		a= new int[size];		
	} catch(const std::bad_alloc& ex){
		throw ex;
	}
	this->size= size;
	
	for(int i=0; i<size; i++)
		a[i]= value;
	
}

Intarray::Intarray(const Intarray& other)throw (std::bad_alloc){ 
	this->size= other.size;

	try{
		this->a= new int[other.size];
	} catch(const std::bad_alloc& ex){
		throw ex;
	}
	
	for(int i=0; i<other.size; i++)
		a[i]= other.a[i];

}

Intarray::Intarray(int* o, int len)throw (std::bad_alloc){
	size= len;

	try{
		a= new int[size];
	} catch(const std::bad_alloc& ex){
		throw ex;
	}
	
	for(int i=0; i<size; i++)
		a[i]= o[i];
	
}

// Destructor
Intarray::~Intarray(){
	delete [] a;
}

string Intarray::toString() const{
	ostringstream os;
	
	for(int i=0; i<size; i++)
		os<<a[i]<<",";
	
	os << endl;
	
	return os.str();
}

void Intarray::append(const Intarray& other)throw (std::bad_alloc){
	int* h;
	int i;
	
	// new big ram
	try{
		h= new int[this->size + other.size];
	} catch(const std::bad_alloc& ex){
		throw ex;
	}

	// copy this into new big ram
	for( i=0; i<this->size; i++)
		h[i]= a[i];
		
	// copy other into new big ram
	for (int j=0; j<other.size; j++)
		h[j+i]= other.a[j];
		
	// DONT forget to free old small ram
	delete [] a;
	
	// a point to prev. allocated new big ram
	this->a= h;
	this->size += other.size; 
	
}

Intarray* Intarray::clone()throw (std::bad_alloc){
	Intarray* p;

	try{
		p= new Intarray(*this);
	} catch(const std::bad_alloc& ex){
		throw ex;
	}

	return p;
}

