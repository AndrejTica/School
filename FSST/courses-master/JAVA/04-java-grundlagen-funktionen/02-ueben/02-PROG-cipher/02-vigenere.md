# Vigenere-Verfahren [wischenär]

Das Vigenère-Verfahren ist eine Weiterentwicklung des Cäsar-Verfahrens,
es verwendet jedoch statt eines einzigen Keys __ein Key-Wort__ .

Damit wird ein Buchstabe des Klartextes nicht immer auf den gleichen Schlüssel-Buchstaben verschoben,
das Verfahren ist also __polyalphabetisch__.

## 1. Beispiel

~~~ bash
String sPlain_txt = "HALLO WELT";
String sKey_txt = "ABC";

String sCipher_txt= " ??? ";  // bitte weiter lesen
~~~

## 2. Verschlüsseln

### Schritt 1: Erstelle den sKey_txt

> Wenn sKey_txt kürzer als der sPlain_txt ist ?  
Man __wiederholt sKey_txt__ bis Längengleichheit mit sPlain_txt erreicht ist.

~~~ bash
HALLO WELT
ABCAB CABC
~~~

> Wenn Wenn sKey_txt länger als der sPlain_txt ist ?  
Man verwendet nur was man braucht.

~~~ bash
HALLO WELT
GEHEI MWORT

wird zu:

HALLO WELT
GEHEI MWOR
~~~

### Schritt 2: Berechne sCipher_txt

~~~ bash
1. Berechne aus sKey_txt[i] den Key nach folg. Regel:

'A'-'A' liefert 0 als Key
'B'-'A' liefert 1 als Key
'C'-'A' liefert 2 als Key
.....
'Z'-'A' liefert 25 als Key


1. Addiere den berechneten Key

key= sKey_txt[i] - 'A';
sCipher_txt[i] = sPlain_txt[i] + key;

Beachte:
- wenn die Addition ein Zeichen > 'Z' liefert,
- dann subtrahiert man 26. Analog für Kleinbuchstaben
~~~

~~~ bash
Beispiel:

HALLO WELT
ABCAB CABC

wird zu:

HALLO WELT
01201 2012
----------
HBNLP YEMV
~~~

## 3. Entschlüsseln

wie beim Verschlüsseln, allerdings wird Subtrahiert.

Beachte: wenn das Zeichen > 'Z' dann addiert man 26. Analog für Kleinbuchstaben.


## 4. Aufgabe: cipher.Cipher.java mit vigenere

Fügen Sie zu __cipher.Cipher.java__ folg. Methoden:

~~~ java
    public static String vigenere_encode(String key, String plain){
        return "todo";
    }

    public static String vigenere_decode(String key, String cipher){
        return "todo";
    }
~~~

## 5. Aufgabe: test.Test_vigenere.java (ein JUNIT test Case)

Erstellen Sie __test.Test_vigenere.java__ mit je 2 Tests zum Ver- und Entschlüsseln und 
testen Sie ihre Algorithmen.

~~~ java
package test
;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

import cipher.Cipher;

class Test_vigenere {
	@Test
	void testVigenere_encode() {
		
		assertEquals("acedfhgi", cipher.Cipher.vigenere_encode("abc", "abcdefgh"));
		assertEquals("Rldk mxl wbvp Qxwjd.", cipher.Cipher.vigenere_encode("ilikefsst", "Java ist eine Insel."));
	}

	@Test
	void testVigenere_decode() {

		assertEquals("abcdefgh", cipher.Cipher.vigenere_decode("abc", "acedfhgi")); 
		assertEquals("Java ist eine Insel.", cipher.Cipher.vigenere_decode("ilikefsst", "Rldk mxl wbvp Qxwjd."));  
	}

}
~~~

## 6. Aufgabe: gui.SwingCipher.java
- Fügen Sie noch folg. Button zum Programm:
  - btn_vigenere_encode
  - btn_vigenere_decode
- Fügen Sie noch ein JTextField
  - txt_vigenere_key 
  
- Achten Sie auf ein schönes übersichtliches Layout ihres GUI-Programmes.

## 7. Tipps:

Bei Vigenere kann man zur Verschlüsselung der einzelnen Zeichen Caesar verwenden.

~~~ java
public static String vigenere_encode(String key, String plain){
	// to chararray
	char[] arr_plain= plain.toCharArray();
	char[] arr_key= new char[plain.length()];

	// need only lower chars (see below: .... caesar_encode(arr_key[i]-'a', ....) ) 
	key= key.toLowerCase();

	// prepare: arr_key
	int k=0; // key index
	for (int i = 0; i < arr_plain.length; i++) {
		if (arr_plain[i]==' ') {
			arr_key[i]= ' ';
		}else {
			arr_key[i]= key.charAt(k);
			// next key index
			k= k+1;
			if (k>=key.length()) {
				k=0;
			}
		}
	}

	// call caesar cipher: take care it uses strings
	String scipher="";
	for (int i = 0; i < arr_plain.length; i++) {
		scipher+= caesar_encode(arr_key[i]-'a', ""+arr_plain[i]);
	}
		

	return scipher;
}
~~~
