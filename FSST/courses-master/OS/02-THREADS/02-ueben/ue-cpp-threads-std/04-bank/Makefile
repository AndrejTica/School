all:
	g++ -std=c++11 -c simplebank.cpp
	g++ -std=c++11 -c angestellter.cpp
	g++ -std=c++11 main.cpp simplebank.o angestellter.o -o main.exe -lpthread

run:
	./main.exe
	
clean:
	rm *.o
	rm *.exe
