/*
http://schorsch.efi.fh-nuernberg.de/roettger/index.php?n=Tutorials.Compilerbau&action=publish&include=include#pub6

EBNF grammar for arithmetic expressions

expression = term { + | - term }
term       = factor { * | / factor }
factor     = value | ( "(" expression ")" )
value      = <decimal number>

*/

#include "scanner.h"

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class EBNFCalculator {
public:
  EBNFCalculator() {}
  ~EBNFCalculator() {
    if (scan)
      delete scan;
  }

  double calc(string infix);

private:
  Scanner *scan;
  int token;
  string tokenvalue;
  // if token is NUMBER then
  // stod(tokenvalue) holds the double-value

  // ebnf-parsing
  double expression();
  double term();
  double factor();
  double value();

  void print_error(string file, int line, string func) {
    cout << "error: " << file << ":" << line << ":" << func
         << ":token=" << token << endl;
  }
};

////////////////////
double EBNFCalculator::calc(string infix) {

  scan= new Scanner(infix);

  double result;
  result = this->expression();
  return result;
}

// expression = term { + | - term }
double EBNFCalculator::expression() {
  double result;

  result = term();

  while (token == PLUS || token == MINUS) {
    if (token == PLUS) {
      result += term();
    } else {
      result -= term();
    }
  }

  return result;
}

// term = factor { * | / factor }
double EBNFCalculator::term() {
  double result;

  result = factor();

  while (token == MULT || token == DIV) {
    if (token == MULT) {
      result *= factor();
    } else {
      result /= factor();
    }
  }

  return result;
}

// factor = value | ( "(" expression ")" )
double EBNFCalculator::factor() {
  double result;

  token = scan->getTOKEN(tokenvalue);

  if (token == OPEN) {

    result = expression();

    if (token != CLOSE)
      print_error(__FILE__, __LINE__, __FUNCTION__);
  } else { // Value
    result = stod(tokenvalue);
  }

  token = scan->getTOKEN(tokenvalue);

  return result;
}
