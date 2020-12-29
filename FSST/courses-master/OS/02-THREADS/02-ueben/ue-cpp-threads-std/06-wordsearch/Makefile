all:
	g++ wordsearch.cpp -o wordsearch.exe -lpthread
	g++ async-wordsearch.cpp -o async-wordsearch.exe -lpthread
	g++ async-wordsearch-mutex.cpp -o async-wordsearch-mutex.exe -lpthread
run:
	./wordsearch.exe ..turn
	./async-wordsearch.exe ..turn
	./async-wordsearch-mutex.exe ..turn
clean:
	rm *.exe
