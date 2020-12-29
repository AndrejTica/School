# Aufgabe: Write class CipherStream - A stream with encryption

- File: 03-streams-cipher

## 1. study encryption

Give a short description of Stream_cipher <http://en.wikipedia.org/wiki/Stream_cipher>

## 2. create  class **CipherStream**

We want to create a Stream which encrypts all its input data. This stream will be  used later for encrypted communication via sockets.

**Create** class **CipherStream** so that the following program works.

```cpp
/**
 * @file: test-cipherstream.cpp
 * @author: N.N.
 * @date: dd.mm.yyyy
 */

#include <iostream>
#include <string>
using namespace std;

#include "cipherstream.h"

int main() {
    CipherStream cipherStream(1);    // uses Streamcipher with XORSubstitution
                                    // key is 1
    string s= "Hallo";
    string plainText;
    string cipherText;

//4 encrypt:
    cipherStream << s;                // encrypts and appends the Text to the stream
     cout << cipherStream << endl;      // outputs the encrypted Text
                                    // in the form:
                                    // [ 47,-89,5,31,62 ]
    // or
    cipherStream.encrypt(s);        // encrypts and appends the Text to the stream
    cout << cipherStream << endl;      // outputs the encrypted Text
                                    // in the form:
                                    // [ 47,-89,5,31,62,-73,43,-128,69,-94 ]

//2 decrypt:
    cipherStream >> plainText;        //
    cout << plainText << endl;      // outputs HalloHallo

    // or
    plainText= cipherStream.decrypt();
    cout << plainText << endl;      // outputs HalloHallo


//2 str()
    cipherText= cipherStream.str();
    cout << cipherText << endl;      // outputs encrypted Text (unformatted)
                                    // Question: is this usefull ?

//2 reset()
    cipherStream.reset();            // deletes the content of the stream and
                                    // resets the key generator
    cipherStream << s;
    cout << cipherStream << endl;    // outputs the encrypted Text
                                    // in the form:
                                    // [ 47,-89,5,31,62 ]

    cipherStream << "Hallo";        // encrypts and appends the Text to the stream
    cout << cipherStream<<endl;      // outputs the encrypted Text
                                    // in the form:
                                    // [ 47,-89,5,31,62,-73,43,-128,69,-94 ]

    return 0;    
}
```
