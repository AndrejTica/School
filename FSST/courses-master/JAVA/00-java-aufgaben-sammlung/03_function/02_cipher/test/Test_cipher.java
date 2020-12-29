package test;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;


import cipher.Cipher;


class Test_cipher {
// --------------------------------------------
	@Test
	void test01_Caesar_encode() {
		
		assertEquals("bcd", Cipher.caesar_encode(1, "abc"));
		
		assertEquals("bcA", Cipher.caesar_encode(1, "abZ"));
		
	}
	// --------------------------------------------
	
	@Test
	void test02_Caesar_decode() {
		
		assertEquals("abZ", cipher.Cipher.caesar_decode(1, "bcA"));
		
		assertEquals("DER WERWOLF EINES NACHTS ENTWICH UND SICH BEGAB", 
				cipher.Cipher.caesar_decode(8, "LMZ EMZEWTN MQVMA VIKPBA MVBEQKP CVL AQKP JMOIJ"));
				
	}

	// --------------------------------------------
	
	@Test
	void test03_Skytale_encode() {	
		
		assertEquals("aebfcgdh", 
				cipher.Cipher.skytale_encode(4, "abcdefgh"));
		
		assertEquals("adgbehcf$", 
				cipher.Cipher.skytale_encode(3, "abcdefgh"));

		assertEquals("afbgchd$e$", 
				cipher.Cipher.skytale_encode(5, "abcdefgh"));
	}

// --------------------------------------------
	
	@Test
	void test04_Skytale_decode() {
		assertEquals("abcdefgh", 
				cipher.Cipher.skytale_decode(4, "aebfcgdh"));
		
		assertEquals("abcdefgh", 
				cipher.Cipher.skytale_decode(3, "adgbehcf$"));

		assertEquals("abcdefgh", 
				cipher.Cipher.skytale_decode(5, "afbgchd$e$"));
	
	}
}

