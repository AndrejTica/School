class SimpleBank {
	static int[] konten = {30, 50, 100};

	public void überweisung(int von, int nach, int betrag) {
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
