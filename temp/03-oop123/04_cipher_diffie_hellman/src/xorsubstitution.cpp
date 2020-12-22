/*
 * xorsubstitution.cpp
 */

#include "xorsubstitution.h"

    char XORSubstitution::encrypt(char ch, int key){
        return ch ^ key; //x oder verschlüsselm

    };

    char XORSubstitution::decrypt(char ch, int key){
         return ch ^ key;

    };
