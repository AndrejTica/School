# multithreading with std cpp

~~~
S/S
--------------------------------------------------------------------------------
cd os
git clone https://gitlab.com/htl_fsst/os/cpp-std.git
cd cpp-std
git checkout -b NAME
git add .....
git commit -m"done"
git push -set-upstream origin NAME



edit-compile-test-commit-push
--------------------------------------------------------------------------------
for each folder:
	1. edit *.cpp  (replace "===ENTER CODE===" with correct cpp)
	2. compile (use make)
	3. test (make run)
	4. edit *.org  (replace "===ENTER CODE===" with correct cpp)
	4. git commit -m "done"
	5. git push


01-basic
--------------------------------------------------------------------------------
01-thread-func.cpp
02-thread-func-with-args.cpp
03-thread-lambda.cpp
04-thread-class.cpp
05-thread-punkt-strich.cpp
06-thread-vector-sum.cpp
07-async-vector-sum.cpp
demo-thread.cpp
demo-tlog.cpp
hw-concurrency.cpp
Makefile
tlog.h


02-lost-update
--------------------------------------------------------------------------------
06-lost-update.cpp
07-lost-update-mutex.cpp
08-lost-update-lock_guard.cpp
Makefile


03-producer-consumer
--------------------------------------------------------------------------------
09-test-fifo.cpp  
10-fifo-threadsafe.cpp  
fifo.h  
fifo-threadsafe.h
Makefile


04-bank
--------------------------------------------------------------------------------
angestellter.cpp  
angestellter.h  
main.cpp  
simplebank.cpp  
simplebank.h
Makefile  


05-sieb-eratosthenes
--------------------------------------------------------------------------------
05-sieb-eratosthenes.cpp  
fifo-threadsafe.h  
worker.h
Makefile  


05-wordsearch
--------------------------------------------------------------------------------
wordsearch-read-only.cpp
demo-regex.cpp  
wordsearch.cpp  
async-wordsearch.cpp  
async-wordsearch-mutex.cpp  
input.txt  
Makefile  
tlog.h  
~~~
