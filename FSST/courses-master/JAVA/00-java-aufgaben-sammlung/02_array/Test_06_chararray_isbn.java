package main;

public class Test_06_chararray_isbn {

	public static void main(String[] args) {
		/**
		 * Goods are declared using EAN-Codes (european article numbers with 13 digits)
		 * Books use ISBN-numbers.
		 * the last digit is a check-digit which is calculated using the other 12 digits.

		ISBN-13: calculation of check-digit
			- digits at even position: 2,4,6,8,10,12
				sum= sum + 3*digits[i]

			- digits at odd position: 1,3,5,7,9,11
				sum= sum + digits[i]

			- get last position (unit position) of this sum
				sum = sum % 10
			- check_digit= 10 - sum

		hint:
			if you sum up all 13 digits according to the above algorithm you get 0. 
			this means that the ISBN/EAN-13 is correct.

		example:
			978-3-7657-2781-?
			caclulation for check_digit:
			9 + 8 + 7 + 5 + 2 + 8 +    3 * (7 + 3 + 6 + 7 + 7 + 1) = 39 + 3 * 31 = 39 + 93 = 132
			132 % 10 = 2
			10 − 2 % 10 = 8
			=> check_digit is 8

		1. read an ISBN from stdin (for example: 978-3-12-732320-?)
		2.1. if last character is '?' 
			 calculate check_digit
			 output check-digits
		2.2. if last character is a digit
			 check if the ISBN is correct
			 output: ISBN is correct or
			 output: ISBN is NOT correct
		*/

		// Aufgabe 1:
		// ------------------------------------------------------------
		// Ermittle die Prüfziffer von "40123457890?" und gib diese aus
		// Lösung: Prüffziffer ist 1.
		
		String ean= "40123457890?";
		char check_digit='?';
		
		// ENTER CODE

		System.out.println("Die Prüfziffer von " + ean + " ist " + check_digit);
		System.out.println();
		
		
		// Aufgabe 2:
		// ------------------------------------------------------------
		// Ermitte, ob die EAN  "5449000096241" korrekt ist?
		// Lösung: true
		
		boolean is_ok=false;
		ean="5449000096241";
		
		// ENTER CODE
		
		System.out.println("Die EAN " + ean + " ist korrekt: " + is_ok);
	}
}
