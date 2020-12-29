all:
	gcc -Wall ssl-client.c -lssl -lcrypto -o ssl-client.exe
	gcc -Wall ssl-server.c -lssl -lcrypto -o ssl-server.exe

run:
	./openssl-socket-client.exe

clean:
	rm *.exe
