/*
 * cipher.cpp
 *
 */

#include "cipher.h"

    string Cipher::encrypt(string s, int key){
        for (size_t i = 0; i < s.size(); i++)
        {
            s[i]= encrypt(s[i], key);
        }
        
        return s;

    }
    string Cipher::decrypt(string s, int key){
         for (size_t i = 0; i < s.size(); i++)
        {
            s[i]= decrypt(s[i], key);
        }
        
        return s;


    }
// ENTER CODE
