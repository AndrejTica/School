/**
 * scanner
 * Lexical Analysis
 */

#pragma once

#include <string>
using namespace std;

#define NUMBER 256
#define PLUS 257  /* + */
#define MINUS 258 /* - */
#define MULT 259  /* * */
#define DIV 260   /* / */
#define OPEN 261  /* ( */
#define CLOSE 262 /* ) */
#define NOTHING 263
#define EOL 264   /* End of Line*/
#define DONE 265  /*EOF*/
#define EQUAL 266 /* = */

class Scanner {
public:
  Scanner(string expression) {
    this->buffer = expression;
    this->pos = 0;
  }

  int getTOKEN(string& value);

private:
  string buffer;
  size_t pos;

  // helper
  char getChar();
  void ungetChar(char);
  
};


char Scanner::getChar() {
  if (pos == buffer.size()) { // already at end?
    return '\0';
  } else {
    char ret = buffer[pos];
    pos++;
    return ret;
  }
}
void Scanner::ungetChar(char ch) {
  pos--;
  buffer[pos] = ch;
}

// ----------------------------------------
int Scanner::getTOKEN(string& value) {
  char ch;

  while (1) {
    // next char
    ch = getChar();

    // -- ignore white char
    if (ch == ' ' || ch == '\t') {
      ;
    } else if (ch == '\n') {
      return EOL;

    } else if (isdigit(ch)) {
      value = "";
      int i = 0;
      do {
        value += ch;
        i++;
        ch = getChar();
      } while (isdigit(ch) || ch == '.');
      ungetChar(ch); /* read ahead */

      return NUMBER;

      // -- DONE?
    } else if (ch == '\0') {
      return DONE;

    } else {
      switch (ch) {
      case '+':
        value = "+";
        return PLUS;
      case '-':
        value = "-";
        return MINUS;
      case '*':
        value = "*";
        return MULT;
      case '/':
        value = "/";
        return DIV;
      case '(':
        value = "(";
        return OPEN;
      case ')':
        value = ")";
        return CLOSE;
      case '=':
        value = "=";
        return EQUAL;
      default:
        value = "none";
        return NOTHING;
      }
    }
  }
}
