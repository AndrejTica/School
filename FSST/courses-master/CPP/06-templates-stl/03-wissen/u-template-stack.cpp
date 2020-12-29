/*
 * u-template-stack.cpp
 * This file is part of TEMPLATES in CPP
 *
 * Copyright (C) 2012 - htl
 *
 * TEMPLATES in CPP is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * TEMPLATES in CPP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with TEMPLATES in CPP. If not, see <http://www.gnu.org/licenses/>.
 */


/* TODO:
 * Bringen Sie dieses Programm zum Laufen
 */
 
#include <iostream>
using namespace std;


template <class TYPE, int SIZE>	
class Stack{
	private:
		m_stack[]; // Festdimensioniertes Feld
		int m_stackpointer; // Index des naechsten freien Elements
public:
	Stack() : m_stackpointer(0) { }

	Stack<TYPE, SIZE>& push(const TYPE& w){
		m_stack[m_stackpointer++] = w; 
	}

	Stack<TYPE, SIZE>& pop(){ 
		m_stackpointer--; 
	}

	top() { 
		return m_stack[m_stackpointer - 1]; 
	}

	int Stacktiefe() { 
		return m_stackpointer; 
	}

	int istleer() { 

	}
};

// Ein kleines Testprogramm
int main(){
	Stack<int, 100> is; 
	Stack<double, 20> ds;

	is.push(13); is.push(11); is.push(40); 
	ds.push(3.14);

	int i = is.top();
	cout << i << endl;

	double d = ds.top();
	cout << d << endl;

	is.push(ds.top());

	return 0;
}
// g++ u-template-stack.cpp -o u-template-stack.exe

