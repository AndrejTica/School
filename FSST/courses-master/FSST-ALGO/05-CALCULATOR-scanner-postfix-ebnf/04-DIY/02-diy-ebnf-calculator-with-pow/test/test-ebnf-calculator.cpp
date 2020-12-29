/*

test ebnf calculator with pow

implement the pow operator (i.e. ^)
- example: 2^3      ... result: 8
- example: 2^3 * 2  ... result: 16
- example: 2^(3+1)  ... result: 16


http://schorsch.efi.fh-nuernberg.de/roettger/index.php?n=Tutorials.Compilerbau&action=publish&include=include#pub6

EBNF Grammar for arithmetic expression with pow:
expression = term { + | - term }
term       = factor { * | / factor }
factor     = potenz {^ potenz} 
potenz     = value | ( "(" expression ")" )
value      = <decimal number>

*/

#include <string>
#include <iostream>
#include <cassert>
using namespace std;

#include "ebnfcalculator.h"

// ------------------------------------------------------------
int main(){
	EBNFCalculator calculator;


    string input;

  cout << "enter expression: (1 + 1) ^ (15 / 3 - 2) or quit:" << endl;
  std::getline(cin, input);

  while (input != "quit") {

    double result= calculator.calc(input);
    cout << "result= " << result<<endl;
    
    // read next input
    cout << "enter expression: (1 + 1) ^ (15 / 3 - 2) or quit:" << endl;
    std::getline(cin, input);
  }

  std::cout << "=====================================  ... \n";
  system("date");
  std::cout << "BEGIN: Test EBNFCalculator with pow    ... \n";
  std::cout << "=====================================  ... \n";

  {
    string infix = "(1 + 1) ^ (15 / 3 - 2)";
    
    double result = calculator.calc(infix);
    cout << "... expression   ... " << infix << endl;
    cout << "... result       ... " << result << endl << endl;

    assert(result == 8.0 && "error: (1 + 1) ^ (15 / 3 - 2)");
  }

  {
    string infix = "(3.0+2) ^2 +5";
    double result = calculator.calc(infix);
    cout << "... expression   ... " << infix << endl;
    cout << "... result       ... " << result << endl << endl;

    assert(result == 30.0  && "error: (3.0+2) ^2 +5");
  }

  {
    string infix = "(2^3*4 )-2";

    double result = calculator.calc(infix);
    cout << "... expression   ... " << infix << endl;
    cout << "... result       ... " << result << endl << endl;

    assert(result == 30.0 && "error: (2^3*4 )-2");
  }

  std::cout << "=================================  ... \n";
  std::cout << "... all Tests passed               ...\n";
  system("date");
  std::cout << "END: Test EBNFCalculator with pow  ... \n";
  std::cout << "=================================  ... \n";

  return 0;
}
