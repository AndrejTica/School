// doubleStack.h
void init();
	// l�scht d. Stack,d.h. stackpointer auf 0 setzen
void push(double value)      ;
	// legt value auf den Stack,
	// wenn dieser aber bereits voll ist, wird auf stderr
	// �Stack voll� gewchrieben und der Wert nicht auf den Stack gelegt.
double  pop();
	// gibt den obersten Wert des Stack zur�ck,
	// wenn dieser aber bereits leer ist, wird auf stderr
	// �Stack leer� geschrieben.
