/**
 * test infix2postfix
 */

#include "infix2postfix.h"

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main() {

  string input;

  cout << "enter expression: (3 + 2) * (15 / 3 - 8) or quit:" << endl;
  // 3 2 + 15 3 / 8 - *
  std::getline(cin, input);

  while (input != "quit") {

    Infix2Postfix in2post(input);
    cout << "postfix: ";
    cout << in2post.getPostfix() << endl;

    // read next input
    cout << "enter expression: (3 + 2) * (15 / 3 - 8) or quit:" << endl;
    std::getline(cin, input);
  }

  std::cout << "=========================  ... \n";
  system("date");
  std::cout << "BEGIN: Test Infix2postfix  ... \n";
  std::cout << "=========================  ... \n";

  {
    string infix = "(3 + 2) * (15 / 3 - 8)";
    string postfix = " 3 2 + 15 3 / 8 - * ";
    Infix2Postfix in2post(infix);
    string ret = in2post.getPostfix();
    cout << "... infix   ... " << infix << endl;
    cout << "... postfix ... " << postfix << endl << endl;

    assert(ret == postfix && "error: (3 + 2) * (15 / 3 - 8)");
  }

  {
    string infix = "(3.0+2) *2";
    string postfix = " 3.0 2 + 2 * ";
    Infix2Postfix in2post(infix);
    string ret = in2post.getPostfix();
    cout << "... infix   ... " << infix << endl;
    cout << "... postfix ... " << postfix << endl << endl;

    assert(ret == postfix && "error: (3.0+2) *2");
  }

  {
    string infix = "(1.2*3+4 )-5.6";
    string postfix = " 1.2 3 * 4 + 5.6 - ";
    Infix2Postfix in2post(infix);
    string ret = in2post.getPostfix();
    cout << "... infix   ... " << infix << endl;
    cout << "... postfix ... " << postfix << endl << endl;

    assert(ret == postfix && "error: (1.2*3+4 )-5.6");
  }

  std::cout << "=========================  ... \n";
  std::cout << "... all Tests passed ...\n";
  system("date");
  std::cout << "END: Test Infix2postfix  ... \n";
  std::cout << "=========================  ... \n";

  return 0;
}
