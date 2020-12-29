
#include "scanner.h"

#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

int main(){

// #define TEST_WITH_ASSERT
#define TEST_INTERACTIVE

#ifdef TEST_WITH_ASSERT
    system("date");
    std::cout << "BEGIN: Test Scanner  ... \n";
    std::cout << "===================  ... \n";
	
    {
    Scanner scan("3+3");
    string value="";
	assert(scan.getTOKEN(value)==NUMBER && "NUMBER expected");
    assert(scan.getTOKEN(value)==PLUS && "PLUS expected");
    assert(scan.getTOKEN(value)==NUMBER && "NUMBER expected");
	}
	
	{
    Scanner scan("3.+ 3=");
    string value="";	
    assert(scan.getTOKEN(value)==NUMBER && "NUMBER expected");
    assert(scan.getTOKEN(value)==PLUS && "PLUS expected");
    assert(scan.getTOKEN(value)==NUMBER && "NUMBER expected");
    assert(scan.getTOKEN(value)==EQUAL && "EQUAL expected");
	}

    {
    Scanner scan("(3+ 3.14)*7=");
    string value="";	
    assert(scan.getTOKEN(value)==OPEN && "OPEN expected");
    assert(scan.getTOKEN(value)==NUMBER && "NUMBER expected");
    assert(scan.getTOKEN(value)==PLUS && "PLUS expected");
    assert(scan.getTOKEN(value)==NUMBER && "NUMBER expected");
    assert(scan.getTOKEN(value)==CLOSE && "CLOSE expected");
    assert(scan.getTOKEN(value)==MULT && "MULT expected");
    assert(scan.getTOKEN(value)==NUMBER && "NUMBER expected");
    assert(scan.getTOKEN(value)==EQUAL && "EQUAL expected");
	}

    std::cout << "... all Tests passed ...\n";
    std::cout << "==================== ... \n";
    std::cout << "END: Test Scanner    ... \n";
    system("date");
#endif

#ifdef TEST_INTERACTIVE

    // oder so testen
    //    char infix[1024+1];
    //    char postfix[1024+1];
    // scanner Rückgaben
    // int scan_token; // PLUS,MINUS,...,NUMBER
    // char value[128+1];  // +,-,*,/,^,1.234
    string input;

    cout << "enter expression: (3.14+ 2 )/2.0= " << endl;
    std::getline(cin,input);

    Scanner scan(input);
    string value;

    bool  finish= false;
    int token;
    while (finish==false && (token=scan.getTOKEN(value)) != DONE){
        switch(token){

            case NUMBER:
            cout << "NUMBER: " + value << endl;
            break;
            
            case OPEN:
            cout << "OPEN: " + value << endl;
            break;

            case CLOSE:
            cout << "CLOSE: " + value << endl;
            break;
            
            case PLUS:
            cout << "PLUS: " + value << endl;
            break;
            
            case MINUS:
            cout << "MINUS: " + value << endl;
            break;

            case MULT:
            cout << "MULT: " + value << endl;
            break;
            
            case DIV:
            cout << "DIV: " + value << endl;
            break;
            
            case EQUAL:
            cout << "EQUAL: " + value << endl;
            break;
            
            case NOTHING:
            cout << "NOTHIG: " + value << endl;
            break;
            
            case DONE:
            cout << "DONE: " + value << endl;
            finish= true;
            break;
            
        }
    }
#endif

    cout << endl;
    return  0;
}

/* output:
./test-scanner
enter expression: (3.14+ 2 )/2.0= 
(3.14+ 2 )/2.0=
OPEN: (
NUMBER: 3.14
PLUS: +
NUMBER: 2
CLOSE: )
DIV: /
NUMBER: 2.0
EQUAL: =
*/
