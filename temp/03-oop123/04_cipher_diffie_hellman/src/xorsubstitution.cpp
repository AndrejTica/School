/*
 * xorsubstitution.cpp
 */

#include "xorsubstitution.h"

    char XORSubstitution::encrypt(char ch, int key){
        return ch ^ key;

    };

    char XORSubstitution::decrypt(char ch, int key){
         return ch ^ key;

    };
