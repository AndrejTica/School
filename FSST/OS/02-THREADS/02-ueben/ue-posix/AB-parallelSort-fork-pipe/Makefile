
all:
	@echo "1. make compile"
	@echo "2. make create-daten"
	@echo "3. make sort"
	@echo "4. make clean"


compile:
	gcc create-daten.c -o create-daten.exe
	gcc parallelSort-fork-pipe.c -o parallelSort-fork-pipe.exe

create-daten:
	./create-daten.exe daten.txt 300

sort:
	./parallelSort-fork-pipe.exe daten.txt

clean:
	rm *.exe

