# Function, array, JUnit: Lotto

## 1. Aufgabe: lotto.Lotto.java
- Projekt: 03-JAVA-LOTTO
- package: lotto
- class: lotto.Lotto.java

~~~java
package lotto;

public class Lotto{
	public static void getLottoTip(int[] a){ } // get 6 unique numbers between 1-45
	public static void sort(int[] a) {}
	public static boolean isUnique(int[] a){return false;}
	public static boolean isSorted(int[] a){return false;}
	public static boolean hasOnly(int[] a, int start, int end) {return false;} // [start, end[   example: 1,46
	public static int getWin(int[] tip, int[] drawing ) {return 0;}
}
~~~

## 2. Aufgabe: test.Test_lotto.java (JUnit testcase)
- package: test
- JUNIT TEST CASE: test.Test_lotto.java

~~~java
package test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.fail;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import lotto.Lotto;

class Test_lotto {

	@BeforeEach
	void setUp() throws Exception {
	}

	@AfterEach
	void tearDown() throws Exception {
	}

	@Test
	void testGetLottoTip() {
		int[] tipp= new int[6];
		lotto.Lotto.getLottoTip(tipp);
		
		assertEquals(true, lotto.Lotto.isUnique(tipp));
		assertEquals(true, lotto.Lotto.hasOnly(tipp,1,46));
	}

	
	@Test
	void testIsUnique() {
		
		int[] a= {1,2,3,4,5,6};
		boolean ret= lotto.Lotto.isUnique(a);
		assertEquals(true, ret);
		
		int[] b= {1,2,3,4,6,6};
		ret= lotto.Lotto.isUnique(b);
		assertEquals(false, ret);
	}

	@Test
	void testIsSorted() {
		int[] tipp= {1,2,3,4,5,6};
		lotto.Lotto.sort(tipp);
		assertEquals(true, lotto.Lotto.isSorted(tipp));

		int[] tipp1= {1,12,3,4,5,6};
		lotto.Lotto.sort(tipp1);
		assertEquals(true, lotto.Lotto.isSorted(tipp1));
		
		int[] tipp2= {21,12,3,34,15,6};
		assertEquals(false, lotto.Lotto.isSorted(tipp2));
		}

	@Test
	void testHasOnly() {
		int[] tipp= {1,2,3,4,5,6};
		assertEquals(true, lotto.Lotto.hasOnly(tipp,1,46));

		int[] tipp1= {1,2,3,4,55,6};
		assertEquals(false, lotto.Lotto.hasOnly(tipp1,1,46));
	}

	@Test
	void testGetWin() {
		int[] tipp= {1,2,3,4,5,6};
		int[] drawing= {1,2,3,4,5,6};
		assertEquals(6, lotto.Lotto.getWin(tipp,drawing));
		
		int[] tipp1= {1,2,3,4,5,6};
		int[] drawing1= {11,12,13,14,15,16};
		assertEquals(0, lotto.Lotto.getWin(tipp1,drawing1));
	}
}
~~~

## 3. Aufgabe: Run as Junit Test
- Testen Sie mit dem Junit-Test-Case alle Lotto Funktionen.

## 4. Aufgabe: gui.SwingLotto.java
Erstellen Sie eine GUI-Anwendung, die

1. button_new: 
- Ermittelt 6 garantiert verschiedene Zufallszahlen und zeigt diese an.
- Fügt diese neuen Lotto-Zahlen an eine Liste (zB: JTextArea,...) bereits zuvor getippter Zahlen.
- Zeigt auch an, wieviele 1-er, 2-er, ..., 45-er bisher insgesamt vorgekommen sind.
- Fühlen Sie sich völlig frei bei der Oberflächengestaltung. Sie soll Ihnen gefallen.

