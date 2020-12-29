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

  double calculate(string expression);

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
  double potenz();
  double value();

  void print_error(string file, int line, string func) {
    cout << "error: " << file << ":" << line << ":" << func
         << ":token=" << token << endl;
  }
};

////////////////////
double EBNFCalculator::calculate(string expression) {

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

/*
 *
 *
 * Dies ist die Lösung ohne ^ Operator
// factor     = value | ( "(" expression ")" )
double EBNFCalculator::factor(){
        double result;

        token= scanner();

        if (token==AUF) {

                result=expression();

                if (token!=ZU)
                        print_error(__FILE__ , __LINE__ , __FUNCTION__);
        }
        else { //Value
                result=tokenwert;

        }

        token= scanner();

        return result;
}
*/

// ------------------------------------------------------
// factor     = potenz {^ potenz}
double EBNFCalculator::factor() {
  double result;

  result = potenz();

  while (token == HOCH) {
    result = pow(result, potenz());
  }

  return result;
}

// potenz     = value | ( "(" expression ")" )
double EBNFCalculator::potenz() {
  double result;

  token = scanner();

  if (token == AUF) {

    result = expression();

    if (token != ZU)
      print_error(__FILE__, __LINE__, __FUNCTION__);
  } else { // Value
    result = tokenwert;
  }

  token = scanner();

  return result;
}
// ------------------------------------------------------
