# SOCKET-CPP: Socket with quit and fork

# 1. Server with quit
- change the Server  *src/simple_server_main.cpp*.  
    - If the client sends *"quit"* or *"quit\r\n"* then the connection will be closed by the client and the server. 
    - So the server accepts a new connection request from another client.

- hint:
~~~ cpp
bool done=false;
while (done==false){
    ...
    done= (data=="quit"||date=="quit\r\n") ? true : false;
    ...
}
~~~

* 2. Test Server with quit
- compile:
~~~ bash
cd build
cmake
make
~~~

- use 3 terminals

- terminal 1 start the server: 
~~~ bash
cd build
./server
~~~

- in terminal 2 start the client (use telnet): 
~~~ bash
telnet localhost 30000
~~~

- in terminal 3 start the client (use telnet): 
~~~ bash
telnet localhost 30000
~~~

- test
    - by entering "quit" the connection should be closed

- watch the problem that 
    - at one time the server can handle only one connection.


# 5. Server with fork
- server should use a dedicated process/thread to service all clients parallel.
- use fork() (a posix function) to start a child-process for each client request.

- hint:
~~~ cpp
... accept();
int pid= fork();
if (pid==0){
    // CHILD process
    // service: client communication
    ...
    exit(0);
}else{
    // PARENT process
    // get child state
    int state;
    wait_pid(-1, &state, WNOHANG);
}
~~~


# Advice:
- [man fork](http://manpages.debian.org/cgi-bin/man.cgi?query=fork&apropos=0&sektion=2&manpath=Debian+7.0+wheezy&format=html&locale=en)
