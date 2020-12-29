package cipher;

public class Cipher {

	// https://www.cryptool.org/de/cto-chiffren/caesar
	public static String caesar_encode(int key, String sPlain) {
		String sCipher="";
		//TODO
		return sCipher;
	}

	public static String caesar_decode(int key, String sCipher) {
		
		return "todo";
	}


	// https://www.cryptool.org/de/cto-chiffren/skytale
	public static String skytale_encode(int key, String sPlain) {
		String sCipher="";
		
		/*
		fall1:
		key=4
		sPlain=abcdefgh
		
		8/4 -> 2
		8%4 -> 0
		abcd
		efgh
		==> aebfcgdh
		
		fall2:
		key=3
		sPlain=abcdefgh
		
		8/3 -> 2
		8%3 -> 2
		abc
		def
		gh$
		==> adgbehcf$
		
		
		fall3:
		key= 5
		sPlain=abcdefgh
		8/5 -> 1
		8%5 -> 3
		
		abcde
		fgh$$
		==> afbgchd$e$
		
		*/
		
		return sCipher;
	}
	public static String skytale_decode(int key, String sCipher) {
		String sPlain="";
		
		// get rows/cols
		
		// alloc matrix
		
		// read column-wise
		
		// write row-wise
		
		// delete trailing $
		
		
		//TODO
		return sPlain;
	}

}
