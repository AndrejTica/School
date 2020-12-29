# ServerSocket_secure/ClientSocket_secure using class CipherStream
---
- File: 04-streams-socket-secure.md

## 1. Aufgabe: Write ServerSocket_secure, ClientSocket_secure
---
1.1. First: **create a new Project/Directory Socket_secure** with a copy of your classes:

* Socket
* SocketException
* ServerSocket
* ClientSocket
* Cipherstream
* simple_server_main
* simple_client_main

1.2. **Change** the class ServerSocket and ClientSocket to:

```
* ServerSocket_secure
* ClientSocket_secure
```

Their constructor gets an additional argument representing the key for StreamCipher encryption. So they are able to transport the data in an encrypted way.

1.3. ServerSocket_secure and ClientSocket_secure **use the CipherStream class**. One CipherStream-object for sending and one for receiving.

```
	... 
private:
	CipherStream* in;
	CipherStream* out;
	... 
```

1.4. Hint:
You can see **Socket-secure-UE.zip**. But its obviously much better to use your own code.


## 2. Aufgabe: test-serversocket_secure.cpp, test-clientsocket_secure.cpp
---

2.1. **Write** two test programs (see: simple_server_main/simple_client_main) :

```
* ./test-serversocket_secure.exe 1
* ./test-clientsocket_secure.exe "Hallo, Welt" 1
```

The client:

```
* argv[2] holds the key
* sends the encrypted Text to the server (Port: 4444) and
* reads the (encrypted) answer from the server and
* outputs the answer to the console (as plainText) and
* quits
```

The server:

```
* argv[1] holds the key
* reads the (encrypted) text from the client and
* outputs the text to the console (as plainText) and
* sends the text (encrypted) back to the client and
* accepts another client's request.
```

## 3. Aufgabe: wireshark
---

Control your programs and encryption using **wireshark**     (filter: tcp.port=####)
