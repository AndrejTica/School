/**
 * test postfix calculator with pow
 * 
 * implement the pow operator: ^
 * example: 2^3      ... result: 8
 * example: 2^3 + 1  ... result: 9
 * example: 2^(3+1)  ... result: 16
 */

#include "postfixcalculator.h"

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main() {

  PostfixCalculator calculator;
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

  std::cout << "======================================  ... \n";
  system("date");
  std::cout << "BEGIN: Test PostfixCalculator with pow ... \n";
  std::cout << "======================================  ... \n";

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

  std::cout << "====================================  ... \n";
  std::cout << "... all Tests passed ...\n";
  system("date");
  std::cout << "END: Test PostfixCalculator with pow ... \n";
  std::cout << "====================================  ... \n";

  return 0;
}
