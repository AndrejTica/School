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

## 1.2. test your ebnfcalculator.h

adapt **include/ebnfcalculator.h**

~~~cpp
EBNF Grammar for arithmetic expression with pow:

expression = term { + | - term }
term       = factor { * | / factor }
factor     = potenz {^ potenz}
potenz     = value | ( "(" expression ")" )
value      = <decimal number>
~~~

see: <http://schorsch.efi.fh-nuernberg.de/roettger/index.php?n=Tutorials.Compilerbau&action=publish&include=include#pub6>

test with: **test/test-ebnf-calculator.cpp**

  1. compile and
  2. run
