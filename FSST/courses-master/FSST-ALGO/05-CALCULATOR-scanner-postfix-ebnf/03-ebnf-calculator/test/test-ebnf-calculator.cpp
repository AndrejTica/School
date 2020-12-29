/*
http://schorsch.efi.fh-nuernberg.de/roettger/index.php?n=Tutorials.Compilerbau&action=publish&include=include#pub6

EBNF Grammatik für arithmetische Ausdrücke:

expression = term { + | - term }
term       = factor { * | / factor }
factor     = value | ( "(" expression ")" )
value      = <decimal number>

// -------------------
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

  cout << "enter expression: (3 + 2) * (15 / 3 - 8) or quit:" << endl;
  std::getline(cin, input);

  while (input != "quit") {

    double result= calculator.calc(input);
    cout << "result= " << result<<endl;
    
    // read next input
    cout << "enter expression: (3 + 2) * (15 / 3 - 8) or quit:" << endl;
    std::getline(cin, input);
  }

  std::cout << "=============================  ... \n";
  system("date");
  std::cout << "BEGIN: Test EBNFCalculator     ... \n";
  std::cout << "=============================  ... \n";

  {
    string infix = "(3 + 2) * (15 / 3 - 8)";
    
    double result = calculator.calc(infix);
    cout << "... expression   ... " << infix << endl;
    cout << "... result       ... " << result << endl << endl;

    assert(result == -15.0 && "error: (3 + 2) * (15 / 3 - 8)");
  }

  {
    string infix = "(3.0+2) *2";
    double result = calculator.calc(infix);
    cout << "... expression   ... " << infix << endl;
    cout << "... result       ... " << result << endl << endl;

    assert(result == 10.0  && "error: (3.0+2) *2");
  }

  {
    string infix = "(1.2*3+4 )-5.6";

    double result = calculator.calc(infix);
    cout << "... expression   ... " << infix << endl;
    cout << "... result       ... " << result << endl << endl;

    assert(result == 2.0 && "error: (1.2*3+4 )-5.6");
  }

  std::cout << "===========================  ... \n";
  std::cout << "... all Tests passed         ...\n";
  system("date");
  std::cout << "END: Test EBNFCalculator     ... \n";
  std::cout << "===========================  ... \n";

  return 0;
}
