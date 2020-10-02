/** 
 * @brief A calculator using postfix notation and a stack
 * 
 * A stack module (doubleStack.h, doubleStack.c) is 
 * implemented to help to caculate the result.
 *
 * @file test_taschenrechner.cpp
 * @author Anton Hofmann 
 * @date 12 Feb 2017
 *
 * g++ test_taschenrechner.cpp CDblStack.cpp -o test_taschenrechner.exe
 * ./test_taschenrechner.exe
 */

#include <cstdio>
#include <cctype>		// wegen isdigit()
#include <cstdlib>		// wegen atof()
#include <iostream>
using namespace std;

#define IL_MAX   20
#define END_CHAR '='

#include "stack.h"		//Die eigene Klasse Stack



/*
 * @brief read a value (number or operator) from stdin
 *
 * @param str a char array holding the input
 * @param len holds the max. length of the input array
 * @return '0' if the input was a number
 * @return str[0] if the input was no number but an operator +,-,...
 */
char mygetline(char str[], int len){
	scanf ("%s", str);
	if (isdigit(str[0]))
		return('0');
	else
		return(str[0]);
}

// ---------------------------------------------------------------------
int  main(){
	double  op1,op2;			// hold an operand of an expression
	char input_line[IL_MAX+1]; // input line
	char ch; 				// hold return value of mygetline()

	Stack stack(1024); ///< stack with max. 1024 values

	cout << "\nTaschenrechner ...";
	cout << "\nZahlen in umgekehrter polnischer Notation eingeben.";
	cout << "\n ... Beispiel: 12 2 * 4 + 2 / = ";
	cout << "\n ... dies entspricht infix: (12 * 2 + 4) / 2 =";
	cout << "\n ... Ergebnis=14.00\n\n";

	do {
		ch=mygetline(input_line,IL_MAX);

		switch(ch){
			case '+':
				op1= stack.top(); stack.pop();
				op2= stack.top(); stack.pop();	
				stack.push(op1+op2);
				break;
			case '-':
				op1= stack.top(); stack.pop();
				op2= stack.top(); stack.pop();	
				stack.push(op1-op2);
				break;
			case '*':
				op1= stack.top(); stack.pop();
				op2= stack.top(); stack.pop();	
				stack.push(op1*op2);
				break;
			case '/':
				op2 = stack.top(); stack.pop();
				if (op2 == 0.0){
					cerr << "\nDivision durch 0 nicht definiert!\n";
					stack.pop(); 	///< zweiten operanden v. stack, 
							///< d.h. / wurde nicht ausgefuehrt
				}
				else{
					op1= stack.top(); stack.pop();
					stack.push(op1/op2);
				}
				break;
			case '0': // a number was entered
				stack.push(atof(input_line));
				break;
			case '=':
				cout.precision(2);
				cout << "\nErgebnis = " << stack.top() << endl;
			break;
		}
	} while (input_line[0]!='=');

	return 0;
}
