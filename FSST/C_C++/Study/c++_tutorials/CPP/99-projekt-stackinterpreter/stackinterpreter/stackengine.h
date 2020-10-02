//stackengine.h
//ahofmann dez 2004
#ifndef stackengine_h
#define stackengine_h stackengine_h

#include <iostream>
#include <stack>
using namespace std;


class CStackengine {
	private:
		stack<double> m_stack;
	public:
	void pop();				//v1
	void push(double);
	double top();
	bool empty();
	void clear();				//v3
	
	void add();				//v1
	void mul();
	void sub();
	void div();
	void mod();
	
	bool neq();			//v3
	bool eq();
	bool lt();
	bool le();
	bool gt();
	bool ge();
	

	
	friend ostream& operator<<(ostream& o, CStackengine& e);	//v2
};

#endif
