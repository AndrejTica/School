# Aufgaben: SOCKET-Stream-library for CPP

- File: 02-streams-socket.md
- source: <http://www.pcs.cnu.edu/~dgame/sockets/socketsC++/sockets.html>

## 1. **Study**

and give a short description (members, methods) of  

<https://gitlab.com/4me/courses/tree/master/WEB-NW-PROG/01-SOCKET/02-ueben/AB-SOCKET-CPP/socket-stream-lib-cpp>  

- class Socket
- class ClientSocket
- class ServerSocket

## 2. **Compile**

Compile all Socket classes and test them with **simple_server_main.cpp**  and **simple_client_main.cpp**.

See and use: Makefile , make

## 3. **Test**

Start 2 terminals. One for  **simple_server_main** and one for  **simple_client_main**. Communicate.

## 4. **Server with quit**

Change the Server program **simple_server_main.cpp**.  If the client sends **"quit"** or **"quit\r\n"** then the connection will  be closed by the client and the server. So the server accepts a  connection request from another client.

## 5. **Server with fork**

The server program should use a dedicated process to service the  client request. In that way the server is able to support many clients  at the same time.

## **Advice:**

[man fork](http://manpages.debian.org/cgi-bin/man.cgi?query=fork&apropos=0&sektion=2&manpath=Debian+7.0+wheezy&format=html&locale=en)
