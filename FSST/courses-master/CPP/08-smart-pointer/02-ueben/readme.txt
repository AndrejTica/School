shared_ptr
------------------------------------------------------------------------
02-ueben/readme.txt



Aufgaben:
------------------------------------------------------------------------
1. Bringen Sie die in 01-lernen gezeigten Beispiele zum Laufen

	g++ demo-auto_ptr.cpp -o demo-auto_ptr.exe

	g++ -std=c++11 demo-shared_ptr-01.cpp -o demo-shared_ptr-01.exe
	g++ -std=c++11 demo-shared_ptr-02.cpp -o demo-shared_ptr-02.exe

	g++ -std=c++11 demo-shared_ptr-sort.cpp -o demo-shared_ptr-sort.exe



2. Ergänzen Sie das Beispiel demo-shared_ptr-02.cpp derart, dass
	der Vector nach dem Namen der Personen
	a) sortiert wird und
	b) die Personen dann ausgeben werden.



Fragen/Übungen/Dokumentationen
------------------------------------------------------------------------
	1. Studiere und stelle vor: 
		http://www.josuttis.com/libbook/cont/countptr.hpp.html
	2. Studiere und stelle vor: 
		http://en.wikipedia.org/wiki/Smart_pointer
	3. Was sind auto_ptr und shared__ptr ?
	4. Beantworte folgende Fragen:
		1. shared_ptr.reset() ...
		2. shared_ptr.get() ...
		3. shared_ptr.unique() ...
		4. auto_ptr und die STL
	5. Versuche eine eigene Implementierung der Klasse shared_ptr
		name: MySharedPointer
		Siehe z.B: 
		http://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c


