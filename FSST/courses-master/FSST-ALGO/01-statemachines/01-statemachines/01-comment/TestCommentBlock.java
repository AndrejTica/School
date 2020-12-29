/**
 * @file N.N.
 * @date dd.mm.yyyy
 *
 * javac  TestCommentBlock.java
 * java  TestCommentBlock
 *
 * Die Datei CommentBlock_UE.java muss im aktuellen Ordner sein.
 */
 
// AUFGABE:
// Schreiben Sie ein Programm, das den Java-Quelltext von der einer Datei liest, 
// daraus Kommentare (/*  … */) entfernt und den Rest wieder ausgibt. 

// Zur Vereinfachung können Sie davon ausgehen, dass im Quelltext 
// keine Zeilenkommentare(//), 
// keine Stringliterale/Textkonstante, 
// keine Zeichenkonstanten vorkommen. 

//Beachten Sie, dass Kommentare nicht ersatzlos gelöscht werden dürfen. 
// Sie haben im Quelltext die Funktion von Zwischenraum. 
//


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TestCommentBlock {
	public static void main(String[] args) throws IOException {
		BufferedReader in= new BufferedReader(
				new FileReader("CommentBlock_UE.java"));

		String withComment="";
		String line;
		String withoutComment;
		
		while((line= in.readLine()) !=null)
			withComment+= line + '\n';
		in.close();
		
		System.out.println("-- with comment ---------------------------");
		System.out.println(withComment);
		
		withoutComment= delCommentBlock(withComment);		
		System.out.println("-- without comment ------------------------");
		System.out.println(withoutComment);
	}

	public static String delCommentBlock(String sIn){
		String sRet="";	
		//
		// ENTER CODE HERE
		//
	}
}
