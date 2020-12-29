# BANK und LOSTUPDATE-Problem

## Aufgaben:

1. Bringen Sie das SimpleBank Programm zum Laufen

2. Korrigieren Sie das SimpleBank Programm, sodass das LOST-UPDATE-Problem nicht mehr auftaucht.

3. Beschreiben Sie mit eigenen Worten das LOST-UPDATE-Problem und gehen Sie auf die Begriffe critical section, mutual exclusion ein.

4. Welche Art von Synchronisation wird hier verwendet?

5. Beschreiben Sie in diesem Zusammenhang das Konzept der Semaphore-Variablen.

Viel Erfolg!

---

## Beschreibung: SimpleBank

- Die  Klasse **SimpleBank** besitzt das Array **konten**, das die Stände der einzelnen Konten enthält. 

- Der Arrayindex soll als **Kontonummer** dienen. 

- Für Transaktionen zwischen zwei Konten stellt die Bank die Methode **ueberweisung()** zur Verfügung. Ihr werden die beiden beteiligten Kontonummern sowie der Betrag der Überweisung übergeben. 

- Sie verfügt auch über die Methode **kontostand()** zum Anzeigen der aktuellen Kontostände.

---

~~~ java
 class SimpleBank {
	static int[] konten = {30, 50, 100};

	public void ueberweisung(int von, int nach, int betrag) {
		int neuerBetrag;

	// --> 1. ABHEBEN vom alten Konto
		neuerBetrag = konten[von];
		// Inkonsistenz, da neuer Betrag noch nicht vermerkt
		try {Thread.sleep((int)Math.random()*3000);}
		catch(InterruptedException e) {}

		neuerBetrag -= betrag;
		konten[von] = neuerBetrag;


	// --> 2. EINLEGEN aufs neue Konto
		neuerBetrag = konten[nach];
		// Inkonsistenz, da neuer Betrag noch nicht vermerkt
		try {Thread.sleep((int)Math.random()*3000);}
		catch(InterruptedException e) {}

		neuerBetrag += betrag;
		konten[nach] = neuerBetrag;
	}

	public void kontostand() {
		for(int i = 0; i < konten.length; i++)
			System.out.println("Konto "+ i +": " + konten[i]);
	}
}     
~~~

---

Angestellte einer Bank machen Überweisungen. 

- Damit mehrere **Angestellte** gleichzeitig Überweisungen vornehmen können, werden sie von **Thread** abgeleitet. 

- Jeder Angestellte gehört zu einer Bank. 
  
- Deshalb wird dem Konstruktor ein **Verweis auf Bank** übergeben. 

- Über diesen Verweis wird die Methode **ueberweisung()** aufgerufen. 

- Die beiden beteiligten Kontonummern sowie der Betrag werden dem Konstruktor ebenfalls übergeben und in entsprechenden privaten Membern der Klasse Angestellte gespeichert. 

---

~~~java
class Angestellter extends Thread {

	SimpleBank bank;
	int von, nach, betrag;

	public Angestellter(SimpleBank bank, int von,
			int nach, int betrag) {
		this.bank = bank;
		this.von = von;
		this.nach = nach;
		this.betrag = betrag;
	}

	public void run() {
		// Überweisung vornehmen
		bank.ueberweisung(von, nach, betrag);
		// Kontostand ausgeben
		System.out.println("Nachher:");
		bank.kontostand();
	}

} 
~~~

---

- Das Demonstrationsprogramm vereinbart drei Verweise auf die Klasse Angestellter. 

- Anschließend wird ein Bank-Objekt erzeugt und eine Übersicht über den Anfangsstand der Konten gegeben. 

- Dann werden die drei Thread-Objekte erzeugt. Die Konten werden hierbei so gewählt, dass sich eine **ringförmige Überweisung** ergibt. 

- Wenn alles ordnungsgemäß verläuft, dann müsste also die Kontenübersicht am Ende genauso aussehen wie am Anfang. 

~~~java
public class SimpleBankDemo {

	public static void main(String[] args) {
		Angestellter A1, A2, A3;
		SimpleBank b = new SimpleBank();

		System.out.println("Vorher: 20 Euro überweisen");
		System.out.println("        Konto_0->Konto_1->Konto_2->Konto_0");
		b.kontostand();

		// Eine ringförmige Überweisung
		A1 = new Angestellter(b, 0, 1, 20);
		A2 = new Angestellter(b, 1, 2, 20);
		A3 = new Angestellter(b, 2, 0, 20);

		A1.start();
		A2.start();
		A3.start();
	}
}
~~~

---

Wenn Sie das Programm starten, kann es sein, dass ein bestimmter Betrag 'verloren' geht. Man spricht vom 'LOST-UPDATE'-Problem.

