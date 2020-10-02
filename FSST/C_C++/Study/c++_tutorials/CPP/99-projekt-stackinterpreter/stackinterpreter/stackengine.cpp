//stackengine.cpp
//a.hofmann dez 2005
#include "stackengine.h"
void CStackengine::pop(){
	m_stack.pop();
}

void CStackengine::push(double p){
	m_stack.push(p);
}

double CStackengine::top(){
	return m_stack.top();
}
bool CStackengine::empty(){
	return m_stack.empty();
}

void CStackengine::clear(){
	while (empty() == false)
		m_stack.pop();
}


	
void CStackengine::add(){
	double op1, op2;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	m_stack.push(op1+op2);
}

void CStackengine::mul(){
	double op1, op2;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	m_stack.push(op1*op2);
}

void CStackengine::sub(){
	double op1, op2;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	m_stack.push(op1-op2);
}

void CStackengine::div(){
	double op1, op2;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	m_stack.push(op1/op2);
}

void CStackengine::mod(){
	double op1, op2;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	m_stack.push( (int)op1 % (int)op2);
}

bool CStackengine::neq(){
	double op1, op2;
	bool ret;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	ret= (op1 != op2);
//	m_stack.push(op1);
	return ret;
}
bool CStackengine::eq(){
	double op1, op2;
	bool ret;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	ret= (op1 == op2);
//	m_stack.push(op1);
	return ret;
}
bool CStackengine::lt(){
	double op1, op2;
	bool ret;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	ret= (op1 < op2);
//	m_stack.push(op1);
	return ret;
}
bool CStackengine::le(){
	double op1, op2;
	bool ret;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	ret= (op1 <= op2);
//	m_stack.push(op1);
	return ret;
}
bool CStackengine::gt(){
	double op1, op2;
	bool ret;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	ret= (op1 > op2);
//	m_stack.push(op1);
	return ret;
}
bool CStackengine::ge(){
	double op1, op2;
	bool ret;
	
	op2= m_stack.top();
	m_stack.pop();
	op1= m_stack.top();
	m_stack.pop();
	
	ret= (op1 >= op2);
//	m_stack.push(op1);
	return ret;
}

	
ostream& operator<<(ostream& o,  CStackengine& e){
	stack<double> tmp;
	
	o<<"   STACK:> TOP" <<endl;
	while (e.empty() == false){
		o<<"   STACK:> " <<e.top()<<endl;
		tmp.push(e.top());
		e.pop();
	}
	
	while (tmp.empty() == false){
		e.push(tmp.top());
		tmp.pop();
	}
	
	o<<"   STACK:> BOTTUM" <<endl;
	return o;
}

