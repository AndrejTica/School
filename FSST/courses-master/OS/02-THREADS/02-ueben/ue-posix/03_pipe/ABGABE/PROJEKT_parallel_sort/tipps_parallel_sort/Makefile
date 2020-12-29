
all:
	@echo "1. make compile"
	@echo "2. make create-daten"
	@echo "3. make sort"
	@echo "4. make clean"


compile:
	gcc create-daten.c -o create-daten.exe
	gcc parallel_sort.c -o parallel_sort.exe

create-daten:
	./create-daten.exe daten.txt 300

sort:
	./parallel_sort.exe daten.txt

clean:
	rm *.exe

