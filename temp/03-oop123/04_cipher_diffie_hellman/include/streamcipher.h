/*
 * streamcipher.h
 *
 */

#ifndef STREAMCIPHER_H_
#define STREAMCIPHER_H_

#include "xorsubstitution.h"

class StreamCipher : public XORSubstitution{
public:
    string encrypt(string s, int key) override;
    string decrypt(string s, int key) override;



};


#endif /* STREAMCIPHER_H_ */
