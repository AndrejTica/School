#
# Test state machines
#

all:
	gcc ungerade.c -o ungerade.exe
	gcc wortfolge.c -o wortfolge.exe
	gcc halt.c -o halt.exe
	
run:
	./ungerade.exe 2>err-ungerade.log
	./wortfolge.exe 2>err-wortfolge.log
	./halt.exe 2>err-halt.log
	
