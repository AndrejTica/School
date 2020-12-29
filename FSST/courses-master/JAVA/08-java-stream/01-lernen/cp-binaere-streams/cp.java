/**
 * Daniel Pekarek, 23.09.2011
 * cp
 *
 * Kopiert eine Datei (1. Argument) 1:1 (bin‰r) in eine 2. Datei (2. Argument)
 * Aufruf: java cp file.in file.out
 * ‹bersetzen: javac cp.java
 */

import java.io.*;

public class cp {
	public final static int BUFSIZE = 256;
	public static void main(String[] args) {
		// Argumente
		if(args.length != 2) {
			System.err.println("Usage: java cp file.in file.out");
			return;
		}

		String from = args[0];
		String to = args[1];

		try {
			// Streams und Buffer
			int nbytes;
			byte[] b = new byte[BUFSIZE];

			InputStream in = new FileInputStream(from);
			OutputStream out = new FileOutputStream(to);

			// lesen und schreiben
			while((nbytes = in.read(b, 0, b.length)) != -1) {
				out.write(b, 0, nbytes);
			}

			// schlieﬂen
			out.close();
			in.close();

		// Fehlerbehandlung
		} catch(FileNotFoundException e) {
			System.err.println("Datei wurde nicht gefunden");
		} catch(IOException e) {
			System.err.println("I/O-Fehler: " + e.getMessage());
		} catch(Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
	}
}
