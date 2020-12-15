/*
 * cipher.h
 *
 */

#ifndef CIPHER_H_
#define CIPHER_H_
#include <string>
using namespace std;

class Cipher{
    public:
    virtual string encrypt(string s, int key); //virtual können überschrieben werden
    virtual string decrypt(string s, int key);

    virtual char encrypt(char ch, int key)=0;   //pure virtual muss von unterklasse ausprogrammiert werden 
    virtual char decrypt(char ch, int key)=0;
};

#endif /* CIPHER_H_ */
