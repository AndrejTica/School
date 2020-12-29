// postfixcalculator

#pragma once

#include "infix2postfix.h"
#include "scanner.h"
#include <stack>
using namespace std;

class PostfixCalculator {
public:
  PostfixCalculator(){};
  double calc(string infix);
  //  TODO: double calc(string postfix)

private:
};

double PostfixCalculator::calc(string infix) {

  Infix2Postfix in2post(infix);

  string expression = in2post.getPostfix();

  expression += " = "; // end of calculation
  int op1, op2;

  Scanner scan(expression);
  int token;
  string value;

  stack<double> stk;

  while ((token = scan.getTOKEN(value)) != EQUAL) {
    switch (token) {
    case NUMBER:
      stk.push(stod(value));
      break;
    case PLUS:
      op1 = stk.top();
      stk.pop();
      op2 = stk.top();
      stk.pop();
      stk.push(op1 + op2);
      break;
    case MINUS:
      op1 = stk.top();
      stk.pop();
      op2 = stk.top();
      stk.pop();
      stk.push(op2 - op1);
      break;
    case MULT:
      op1 = stk.top();
      stk.pop();
      op2 = stk.top();
      stk.pop();
      stk.push(op1 * op2);
      break;
    case DIV:
      op1 = stk.top();
      stk.pop();
      if (op1 == 0.0)
        throw "Division by zero condition!";
      else {
        op2 = stk.top();
        stk.pop();
        stk.push(op2 / op1);
      }
      break;
    default:
      throw "wrong token";
    }
  }
  return stk.top();
}
