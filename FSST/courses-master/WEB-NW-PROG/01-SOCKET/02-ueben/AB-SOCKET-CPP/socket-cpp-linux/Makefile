# Makefile for the socket programming example
#
# http://www.pcs.cnu.edu/~dgame/sockets/socketsC++/sockets.html
# see also: http://www.pcs.cnu.edu/~dgame/cs502sum06/currentsemester.html
#
#
###ht socklibs = -lnsl -lsocket
socklibs= 

simple_server_objects = ServerSocket.o Socket.o simple_server_main.o
simple_client_objects = ClientSocket.o Socket.o simple_client_main.o


all : simple_server simple_client

simple_server: $(simple_server_objects)
	g++ -o simple_server $(socklibs) $(simple_server_objects)


simple_client: $(simple_client_objects)
	g++ -o simple_client $(socklibs) $(simple_client_objects)


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
simple_server_main: simple_server_main.cpp
simple_client_main: simple_client_main.cpp


clean:
	rm -f *.o simple_server simple_client

