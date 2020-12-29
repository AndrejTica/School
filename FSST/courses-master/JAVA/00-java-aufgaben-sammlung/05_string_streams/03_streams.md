# Streams

- F_noten
- F_lotto
- F_bookmark
- F_tarif
- F_java2html

---

## F_noten

~~~ bash
Erstelle eine Konsolenanwendung, die die input-Dateien einliest und die output-Datei erzeugt.

noten_in.txt
Anton Hofmann,18
Beta Hofmann,21
Gamma Hofmann,11
…

punkte_in.txt
00:12:5
13:15:4
16:18:3
19:21:2
22:24:1

noten_out.txt
Anton Hofmann,18,3
Beta Hofmann,21,2
Gamma Hofmann,11,5
--------
Punktedurchschnitt: 16.6
Notendurchschnitt: 3.3
Der Test muss nicht wiederholt werden.
~~~

Tipp: Verwenden Sie Klassen wie zum Beispiel: Person, Test, ...

---

## F_lotto

~~~bash
Erstelle eine Konsolenanwendung, die die input-Dateien einliest und die output-Datei erzeugt.

tipp_in.txt
Anton Hofmann,18,4,5,7,12,16
Beta Hofmann,18,4,25,37,12,1
Gamma Hofmann,1,4,5,17,22,33
…

ziehung_in.txt
5,4,44,40,21,22

gewinne_out.txt
Anton Hofmann,2 richtige
Beta Hofmann,1 richtige
Gamma Hofmann,3 richtige
~~~

---

## F_bookmark

~~~bash
Erstelle eine Konsolenanwendung, die die input-Dateien einliest und die output-Datei erzeugt.

bookmark_in.txt
Anton Hofmann,http://www.htl-salzburg.ac.at
Anton Hofmann,http://www.javabuch.de
Anton Hofmann,http://www.cppreference.de
Anton Hofmann,http://www.pronix.de
Anton Hofmann,http://www.cppreference.de
Beta Hofmann,http://www.cppreference.de
Beta Hofmann,http://www.htl-innovativ.at
Gamma Hofmann,http://www.selfhtml.de
Gamma Hofmann,http://www.ubuntu.com
…

meineBookmarks_in.txt
http://www.cppreference.de
http://www.pronix.de
…

bookmark_out.txt
Anton Hofmann, 2 Treffer
Beta Hofmann,1 Treffer
Gamma Hofmann,0 Treffer

bookmark_out.txt muss nach der Anzahl der Treffer sortiert sein!!
~~~

---

## F_tarif

~~~ bash
Erstelle eine Konsolenanwendung, die die input-Dateien einliest und die output-Datei erzeugt.

tarife_in.txt
Firma1:100:500:0.07:0.04
Firma2:1000:300:0.04:0.06
Firma3:500:200:0.05:0.05
…

Aufbau:
Firmenname:Anzahl freie SMS: Anzahl freie Minuten: Kosten pro zusätzl SMS: Kosten pro Min

monate_in.txt
01:2322:300
02:2110:205
03:1950:210
04:1800:200
05:2000:250
06:3000:200
…

Aufbau:
Monat:Anzahl der sms: Anzahl der Minuten

empfehlung_out.txt
01:2322:300:FirmaXXX
02:2110:205:FirmaXXX
03:1950:210:FirmaXXX
04:1800:200:FirmaXXX
05:2000:250:FirmaXXX
06:3000:200:FirmaXXX
~~~

---

## F_java2html

~~~ java
Erstellen Sie das Programm F_java2html, das als Eingabe eine Java Quellprogramm liest und davon eine Kopie erstellt, wobei die Java Schlüsselwörter (class, for, if, public, ....) durch das HTML-Tag für fett (<b>.....</b>) umgeben werden.

Die fett zu schreibenden Wörter sollen aus der Datei java-keywords.txt gelesen werden. 
Hinweis: java-keywords.txt
class,public,private
int,long,char,byte,boolean,float,double
if,else,for,while,do,switch,case,break
 
Hier ein Beispiel: JavaSource.java
public class JavaSource {
  public static void main ( String[] args ) {
    if ( args.length == 3 )
      new BigObject();
    else
      System.out.println("Too few arguments.");
  }
}

wird übersetzt zu: JavaSource.htm
<b>public</b> <b>class</b> JavaSource {
  <b>public</b> <b>static</b> <b>void</b> main ( String[] args ) {
    <b>if</b> ( args.length == 3 )
      <b>new</b> BigObject();
    <b>else</b>
      System.out.println("Too few arguments.");
  }
}
In einem Webbrowser soll das dann so aus sehen:
public class JavaSource {
  public static void main ( String[] args ) {
    if ( args.length == 3 )
      new BigObject();
    else
      System.out.println("Too few arguments.");
  }
}
~~~

Hinweise:

~~~java
Hinweis: html (s. http://www.selfhtml.net/ )

    fhtml= new PrintWriter(new File(input+".html"));
    fhtml.println("<html><head><title>Java2html</title></head>");
    fhtml.println("<body><pre>");
    …
    fhtml.println("</pre></body></html>");


Hinweis: Zeilenschaltung

    <br />

Hnweis: Leerzeichen
	&nbsp;

Tipp: 

Erstellen Sie die Klasse JAVA_HTML, die die Aufgaben erfüllt.
	setKeywords(String filename);
	printHTMLHeader(String Title)
	…
~~~
