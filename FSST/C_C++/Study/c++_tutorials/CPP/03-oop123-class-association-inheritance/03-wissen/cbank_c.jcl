<?xml version="1.0" encoding="ISO-8859-1"?>

<hotpot-jcloze-file>
<rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#" xmlns:dc="http://purl.org/dc/elements/1.1/">
  <rdf:Description rdf:about="">
    <dc:creator>anton hofmann</dc:creator>
    <dc:title>cbank.cpp</dc:title>
  </rdf:Description>
</rdf:RDF><version>6</version>

<data>
<title>cbank.cpp</title>

<timer><seconds>60</seconds><include-timer>0</include-timer></timer>

<reading>
<include-reading>0</include-reading>
<reading-title></reading-title>
<reading-text></reading-text>

</reading>

<gap-fill>&amp;#x003C;pre&amp;#x003E;
// a.hofmann 10.06
// cbank.cpp
// demo: klasse und objekt

#include &quot;ckonto.h&quot;
#include &quot;cbank.h&quot;

#include &amp;#x0026;lt;iostream&amp;#x0026;gt;
#include &amp;#x0026;lt;string&amp;#x0026;gt;
using namespace std;

// Konstruktoren
CBank::CBank(string pname){
	m_name= pname;
	m_konten_idx= -1;
}

// Methoden
void CBank::add(<question-record><question></question><answer><text>const</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record> CKonto&amp;#x0026; pkonto){
	if (m_konten_idx &amp;#x0026;lt; 1024 - 1) {
		m_konten_idx++;
		m_konten[m_konten_idx]= <question-record><question></question><answer><text>pkonto</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>;
	}
}


void CBank::display() <question-record><question></question><answer><text>const</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record> {
	double gesamt=0.0;

	for (int i=0; i &amp;#x0026;lt;= m_konten_idx; i++)
		gesamt += m_konten[i].getBetrag();

	cout &amp;#x0026;lt;&amp;#x0026;lt; &quot;\nBank: \&quot;&quot; &amp;#x0026;lt;&amp;#x0026;lt; m_name &amp;#x0026;lt;&amp;#x0026;lt; &quot;\&quot; hat &quot; &amp;#x0026;lt;&amp;#x0026;lt; m_konten_idx +1 &amp;#x0026;lt;&amp;#x0026;lt; &quot; Konten mit &quot;;
	cout &amp;#x0026;lt;&amp;#x0026;lt; &quot; einem Betrag von insgesamt &quot; &amp;#x0026;lt;&amp;#x0026;lt; gesamt &amp;#x0026;lt;&amp;#x0026;lt; &quot; Euro.&quot; &amp;#x0026;lt;&amp;#x0026;lt; endl;
}

// Destruktor
<question-record><question></question><answer><text>CBank</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>::~<question-record><question></question><answer><text>CBank</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>(){
}

// friends
<question-record><question></question><answer><text>ostream</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x0026; <question-record><question></question><answer><text>operator</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record> &amp;#x0026;lt;&amp;#x0026;lt;(<question-record><question></question><answer><text>ostream</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x0026; o, <question-record><question></question><answer><text>const</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record> <question-record><question></question><answer><text>CBank</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x0026; e) {
	double gesamt=0.0;

        for (int i=0; i &amp;#x0026;lt;= e.m_konten_idx; i++)
	       gesamt += <question-record><question></question><answer><text>e</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>.m_konten[i].<question-record><question></question><answer><text>getBetrag</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>();
	
	<question-record><question></question><answer><text>o</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x0026;lt;&amp;#x0026;lt; &quot;*** BANK &quot; &amp;#x0026;lt;&amp;#x0026;lt; <question-record><question></question><answer><text>e</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>.m_name &amp;#x0026;lt;&amp;#x0026;lt; &quot; ***&quot; &amp;#x0026;lt;&amp;#x0026;lt; endl;
	<question-record><question></question><answer><text>o</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x0026;lt;&amp;#x0026;lt; &quot;*** hat &quot; &amp;#x0026;lt;&amp;#x0026;lt; <question-record><question></question><answer><text>e</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>.m_konten_idx +1 &amp;#x0026;lt;&amp;#x0026;lt; &quot; Konten mit einem Gesamtbetrag von &quot; &amp;#x0026;lt;&amp;#x0026;lt; gesamt &amp;#x0026;lt;&amp;#x0026;lt; &quot; Euro.&quot; &amp;#x0026;lt;&amp;#x0026;lt; endl;

	<question-record><question></question><answer><text>o</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x0026;lt;&amp;#x0026;lt; &quot;Hier nun eine Liste der einzelnen Konten:&quot; &amp;#x0026;lt;&amp;#x0026;lt;endl;
        for (int i=0; i &amp;#x0026;lt;= <question-record><question></question><answer><text>e</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>.m_konten_idx; i++)
	       <question-record><question></question><answer><text>o</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x0026;lt;&amp;#x0026;lt; <question-record><question></question><answer><text>e</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>.m_konten[i];	//Hier wird genutzt, dass CKonto den operator &amp;#x0026;lt;&amp;#x0026;lt; ueberschrieben hat

	return <question-record><question></question><answer><text>o</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>;
}
&amp;#x003C;/pre&amp;#x003E;</gap-fill>
</data>

<hotpot-config-file>
<jcloze>
<exercise-subtitle>Gap-fill exercise</exercise-subtitle>
<instructions>Fill in all the gaps, then press &quot;Check&quot; to check your answers. Use the &quot;Hint&quot; button to get a free letter if an answer is giving you trouble. You can also click on the &quot;[?]&quot; button to get a clue. Note that you will lose points if you ask for hints or clues!</instructions>
<guesses-correct>Correct! Well done.</guesses-correct>
<guesses-incorrect>Some of your answers are incorrect. Incorrect answers have been left in place for you to change.</guesses-incorrect>
<next-correct-letter>The next correct letter has been added to the answer.</next-correct-letter>
<include-hint>1</include-hint>
<case-sensitive>0</case-sensitive>
<include-word-list>0</include-word-list>
<use-drop-down-list>0</use-drop-down-list>
<minimum-gap-size>6</minimum-gap-size>
<next-ex-url>nextpage.htm</next-ex-url>
<send-email>0</send-email>
<include-clues>1</include-clues>
<include-keypad>0</include-keypad>
<separate-javascript-file>0</separate-javascript-file>
</jcloze>

<global>

<times-up>Your time is over!</times-up>
<check-caption>Check</check-caption>
<ok-caption>OK</ok-caption>
<hint-caption>Hint</hint-caption>
<clue-caption>[?]</clue-caption>
<process-for-rtl>0</process-for-rtl>
<your-score-is>Your score is </your-score-is>
<keypad-characters></keypad-characters>
<next-ex-caption>=&amp;#x003E;</next-ex-caption>
<back-caption>&amp;#x003C;=</back-caption>
<contents-caption>Index</contents-caption>
<include-next-ex>1</include-next-ex>
<include-contents>1</include-contents>
<include-back>0</include-back>
<contents-url>contents.htm</contents-url>
<contents-url>contents.htm</contents-url>
<graphic-url></graphic-url>
<font-face>Geneva,Arial,sans-serif</font-face>
<font-size>small</font-size>
<page-bg-color>#C0C0C0</page-bg-color>
<title-color>#000000</title-color>
<ex-bg-color>#FFFFFF</ex-bg-color>
<text-color>#000000</text-color>
<link-color>#0000FF</link-color>
<vlink-color>#0000CC</vlink-color>
<nav-bar-color>#000000</nav-bar-color>
<formmail-url>http://yourserver.com/cgi-bin/FormMail.pl</formmail-url>
<email>you@yourserver.com</email>
<name-please>Please enter your name:</name-please>
<user-string-1>one</user-string-1>
<user-string-2>two</user-string-2>
<user-string-3>three</user-string-3>
<header-code></header-code>
</global>
</hotpot-config-file>
</hotpot-jcloze-file>
