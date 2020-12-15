/*
 * xorsubstitution.h
 *
 */

#ifndef XORSUBSTITUTION_H_
#define XORSUBSTITUTION_H_
#include "cipher.h"

class XORSubstitution : public Cipher{
public:
    char encrypt(char ch, int key) override; //selbstschutz zum falls falsch geschrieben
    char decrypt(char ch, int key) override; 


};


#endif /* XORSUBSTITUTION_H_ */
