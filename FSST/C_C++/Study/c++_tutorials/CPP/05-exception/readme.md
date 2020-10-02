# CPP exception


## 1. Aufgabe: Studieren Sie die folgenden Beispiele:
-------------------------------------------------------------------
* <http://www.cplusplus.com/reference/new/bad_alloc/>
* <http://www.cplusplus.com/reference/stdexcept/>
* <http://www.cplusplus.com/reference/stdexcept/out_of_range/>
* <http://www.cplusplus.com/reference/stdexcept/overflow_error/>
* <http://www.cplusplus.com/reference/stdexcept/underflow_error/>



## 2. Aufgabe: intarray
-------------------------------------------------------------------
Verwenden Sie die obigen Exception-Klassen für die Klasse Intarray
und testen Sie diese.

~~~
...
Intarray a1(5,99);

try{
	a1.setAt(-9,17);	
}catch (std::out_of_range& ex){
	cerr << ex.what() << endl;
}
...
~~~


## 3. Weitere Aufgaben: Intervall, Stack
-------------------------------------------------------------------
* siehe: <https://gitlab.com/4me/courses/blob/master/CPP/05-exception/02-ueben/AB-CPP-EXCEPTION-intarray-intervall-stack.txt>

