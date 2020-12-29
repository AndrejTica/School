/**
 * test postfix calculator
 */

#include "postfixcalculator.h"

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main() {

  PostfixCalculator calculator;
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
  std::cout << "BEGIN: Test PostfixCalculator  ... \n";
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
  std::cout << "... all Tests passed ...\n";
  system("date");
  std::cout << "END: Test PostfixCalculator  ... \n";
  std::cout << "===========================  ... \n";

  return 0;
}
