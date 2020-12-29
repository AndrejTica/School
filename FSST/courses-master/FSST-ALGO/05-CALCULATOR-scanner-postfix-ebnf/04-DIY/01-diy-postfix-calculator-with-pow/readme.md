# 1. DIY: PostfixCalculator with pow

implement the pow operator: ^

- example: 2^3      ... result: 8
- example: 2^3 * 2  ... result: 16
- example: 2^(3+1)  ... result: 16

## 1.1. test your new scanner.h

adapt **include/scanner.h**

- #define POW ...
- ...
- return POW

test with: **test/test-scanner.cpp**

  1. adapt,
  2. compile and
  3. run

## 1.2. test your new infix2postfix.h

adapt **include/infix2postfix.h**

- adapt shunting yard algorithm with pow operator (has highest priority)

test with: **test/test-infix2postfix.cpp**

  1. adapt,
  2. compile and
  3. run

## 1.3. test your postfixcalculator.h

adapt **include/postfixcalculator.h**

test with: **test/test-postfix-calculator.cpp**

  1. compile and
  2. run
