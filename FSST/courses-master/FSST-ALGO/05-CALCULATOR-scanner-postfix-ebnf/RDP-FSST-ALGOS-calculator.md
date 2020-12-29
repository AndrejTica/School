# RDP-ALGOS: CALCULATOR

Gegeben ist folgender arithmetischer Ausdruck:

~~~bash
(3 + 2) * (15 / 3 - 8)
~~~

Wandeln Sie diesen infix-Ausdruck in einen postfix-Ausdruck um.

- Besprechen Sie in diesem Zusammenhang folgende Algorithmen:
  - infix2postfix (Shunting-Yard-Algorithmus)
  - postfix-calculator (Stack-Datenstruktur/Algorithmus)

Arithmetische Ausdrücke werden auch im Compilerbau behandelt:

- Besprechen Sie in diesem Zusammenhang:
  - EBNF-Grammatiken am Beispiel arithm. Ausdrücke
  
    ~~~bash
    expression = term { + | - term }
    term       = factor { * | / factor }
    factor     = value | ( "(" expression ")" )
    value      = <decimal number>
    ~~~

  - Wie werden derartige EBNF Regeln programmtechnisch implementiert?
  
Lesen Sie: <http://schorsch.efi.fh-nuernberg.de/roettger/index.php?n=Tutorials.Compilerbau&action=publish&include=include#pub6>
