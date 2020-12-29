/*
infix2postfix:
------------------------------------------------------------------------
http://de.wikipedia.org/wiki/Shunting-yard-Algorithmus

Stack f. Operatoren:

- Zu deutsch "Rangierbahnhof"-Algo, weil es einen Operator-Stack gibt,
- in den jeder Operator erst mal hineinfährt, und
- nach gewissen Regeln fährt er dann wieder raus in die Ausgabe.

Zahlen: direkt in die Ausgabe

- Jede gelesene Zahl geht direkt in die Ausgabe.

Die Stack-Regel:

- Bevor ein neuer Operator auf den Stack darf,
- werden alle Operatoren **höheren oder gleichen** Ranges
  vom Stack in die Ausgabe übertragen.

~~~
Rang 3: /
Rang 3: *
Rang 2: -
Rang 2: +
~~~

Merke: Hoher Rang muss oben sein!

- Der Stack ist also sortiert: der höchste Rang **muss immer obenauf** sein.

Klammern:

- Die Klammer AUF verdrängt KEINEN Operator/Zahl vom Stack.
- Die Klammer ZU flusht dann den Stack in die Ausgabe, bis hin zur Klammer AUF.
- Die Klammer AUF und Klammer ZU sind nicht mehr auf dem Stack.

Ablauf:
1. Token lesen
2. Zahl: in d. Ausgabe kopieren
3. Operatoren: vor dem Einparken am Stack müssen ranghöhere/gleiche
   Operatoren vom Stack zur Ausgabe.

Zusammenfassung: Shunting - yard Algorithmus

Zahl: ... direkt in die Ausgabe
+,-:  ... 1. verdrängt alle *,/  und +,-
      ... 2. +,- auf den Stack

*,/:  ... 1. verdrängt alle *,/
      ... 2. *,/ auf den Stack

Klammer AUF: AUF auf den Stack

Klammer ZU: 1. stack leeren bis zur Klammer AUF (inkl)
            2. nichts auf den Stack


Beispiel:
(3 + 2) * (15 / 3 - 8)

Schritt  Op-Stack   Postfix-Ausgabe
(        (
3        (          3
+        ( +        3
2        ( +        3 2
)                   3 2 +

*        *          3 2 +

(        * (        3 2 +
15       * (        3 2 + 15
/        * ( /      3 2 + 15
3        * ( /      3 2 + 15 3
-        * ( -      3 2 + 15 3 /

8        * ( -      3 2 + 15 3 / 8
)        *          3 2 + 15 3 / 8 -
<rest-flush>        3 2 + 15 3 / 8 - *
*/

#pragma once

#include "scanner.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Infix2Postfix {
public:
  Infix2Postfix(string infix);

  string getPostfix() { return postfix; };

private:
  string infix;
  string postfix;
};

Infix2Postfix::Infix2Postfix(string infix) {
  this->infix = infix;
  this->postfix = " ";  // 1. char space

  stack<int> operator_stack;

  Scanner scan(infix);
  string value;
  bool done;

  int token;
  bool finish = false;
  while (finish == false) {
    token = scan.getTOKEN(value);
    switch (token) {
    // ---------------------------
    case NUMBER:
#ifdef DEBUG
      cout << "NUMBER: " + value << endl;
#endif
      postfix += value + " ";
      break;

    // ---------------------------
    case OPEN:
#ifdef DEBUG
      cout << "OPEN: " + value << endl;
#endif
      // Klammer AUF: AUF auf den Stack
      operator_stack.push(token);
      break;

    // ---------------------------
    case CLOSE:
#ifdef DEBUG
      cout << "CLOSE: " + value << endl;
#endif
      // Klammer ZU:
      //    1. stack leeren bis zur Klammer AUF (inkl)
      //    2. nichts auf den Stack
      done = false;
      while (done == false && !operator_stack.empty()) {
        int token = operator_stack.top();
        operator_stack.pop();

        if (token == OPEN) {
          done = true;
        } else if (token == PLUS) {
          postfix += "+ ";
        } else if (token == MINUS) {
          postfix += "- ";
        } else if (token == MULT) {
          postfix += "* ";
        } else if (token == DIV) {
          postfix += "/ ";
        }
      } // end while
      break;

    // ---------------------------
    case PLUS:
    case MINUS:
#ifdef DEBUG
      if (token == PLUS)
        cout << "PLUS: " + value << endl;
      else
        cout << "MINUS: " + value << endl;
#endif
      // +,-: 1. pop  all: *,/  +,-
      //      2. push: +,- 

      done = false;
      while (done == false && !operator_stack.empty()) {
        int token = operator_stack.top();
        operator_stack.pop();

        if (token == PLUS) {
          postfix += "+ ";
        } else if (token == MINUS) {
          postfix += "- ";
        } else if (token == MULT) {
          postfix += "* ";
        } else if (token == DIV) {
          postfix += "/ ";
        } else {
          done = true;
          operator_stack.push(token); // was no +-*/
        }
      } // end while

      // push: +,-
      operator_stack.push(token);
      break;

    // ---------------------------
    case MULT:
    case DIV:
#ifdef DEBUG
      if (token == MULT)
        cout << "MULT: " + value << endl;
      else
        cout << "DIV: " + value << endl;
#endif
      // *,/: 1. pop all: *,/
      //      2. push: *,/ 
      done = false;
      while (done == false && !operator_stack.empty()) {
        int token = operator_stack.top();
        operator_stack.pop();

        if (token == MULT) {
          postfix += "* ";
        } else if (token == DIV) {
          postfix += "/ ";
        } else {
          done= true;
          operator_stack.push(token); // undo last pop
        }
      } // end while

      // push: *,/
      operator_stack.push(token);
      break;

    // --------------------------- ignore equal sign
    case EQUAL:
#ifdef DEBUG
      cout << "EQUAL: " + value << endl;
#endif
      break;

    // --------------------------- unknown token
    case NOTHING:
#ifdef DEBUG
      cout << "NOTHING: " + value << endl;
#endif
      finish = true;
      break;

    // --------------------------- EOF or end of line
    case DONE:
    case EOL:
#ifdef DEBUG
      cout << "DONE: " + value << endl;
#endif
      // flush stack
      while (!operator_stack.empty()) {
        int token = operator_stack.top();
        operator_stack.pop();

        if (token == PLUS) {
          postfix += "+ ";
        } else if (token == MINUS) {
          postfix += "- ";
        } else if (token == MULT) {
          postfix += "* ";
        } else if (token == DIV) {
          postfix += "/ ";
        }
      }

      finish = true;
      // postfix += " = "; // END_CHAR for postfix-calculator.cpp
      break;

    default:
      cout << "ERROR: wrong TOKEN: " + token << endl;
      finish = true;
    }
  }
}
