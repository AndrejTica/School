/*
 * dhcpher.cpp
 */

#include <cmath>
#include <cstdlib>

#include "dhcipher.h"
#include "streamcipher.h"


DHCipher::DHCipher(int n, int g){
	this->n= n;
	secretKey= rand() %(n-1) + 1;
	publicKey= (int) pow((double)g, secretKey) % this->n;
}

// ENTER CODE
