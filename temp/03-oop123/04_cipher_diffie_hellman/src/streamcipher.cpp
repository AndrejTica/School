/*
 * streamcipher.cpp
 *
 *  Created on: 06.11.2012
 *      Author: informatik
 */

#include "streamcipher.h"
#include <cstdlib>


    string StreamCipher::encrypt(string s, int key){

        //keygenerator
        srand(key);

        for (size_t i = 0; i < s.size(); i++)
        {
            int new_key = rand(); //liefert immer neuen schlüsel
            s[i]= XORSubstitution::encrypt(s[i], new_key);
        }
        
        return s;


    }

    string StreamCipher::decrypt(string s, int key){

        //keygenerator
        srand(key);

        for (size_t i = 0; i < s.size(); i++)
        {
            int new_key = rand(); //liefert immer neuen schlüsel
            s[i]= XORSubstitution::decrypt(s[i], new_key);
        }
        
        return s;

    }
