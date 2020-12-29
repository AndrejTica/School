<?xml version="1.0" encoding="ISO-8859-1"?>
<hotpot-jcloze-file>
<rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#" xmlns:dc="http://purl.org/dc/elements/1.1/">
<rdf:Description rdf:about="">
</rdf:Description>
</rdf:RDF>
<version>6</version>
<data>
<title>CBankVector</title>
<timer>
<include-timer>0</include-timer>
<seconds>59</seconds>
</timer>
<reading>
<reading-text></reading-text>
<include-reading>0</include-reading>
<reading-title></reading-title>
</reading>
<gap-fill>&amp;#x003C;pre&amp;#x003E;

// ---------------------------------------------------------------
// a.hofmann 10.06
// cbank.h
// demo: klasse und objekt und container
// demo: StL-Klasse vector
// 	Die Konten werden in einem vector gespeichert
// ---------------------------------------------------------------

#ifndef CBANK_H
#define CBANK_H  CBANK_H

#include &amp;#x003C;string&amp;#x003E;
#include &amp;#x003C;iostream&amp;#x003E;

#include &amp;#x003C;<question-record><question></question><answer><text>vector</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x003E;

#include &quot;ckonto.h&quot;
using <question-record><question></question><answer><text>namespace</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record> std;

class CBank {
	private:
		<question-record><question></question><answer><text>vector</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x003C;<question-record><question></question><answer><text>CKonto</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>&amp;#x003E; m_konten;
		string m_name;
	public:
		// Konstruktoren
		CBank(string powner);

		// Methoden
		void addKonto(const CKonto&amp;#x0026; akonto);
		void removeKonto(const int);
		
		void addBetrag(double);
		void minBetrag(double);
		
		void sortKonten();

		// Friends
		friend ostream&amp;#x0026; operator&amp;#x003C;&amp;#x003C;(ostream&amp;#x0026;, const CBank&amp;#x0026;);

		// Destruktor
		~CBank();
};
#endif

// --------------------------------------------------------------------
// a.hofmann 10.06
// cbank.cpp
// demo: klasse und objekt
// ---------------------------------------------------------------

#include &quot;ckonto.h&quot;
#include &quot;cbank.h&quot;

#include &amp;#x003C;iostream&amp;#x003E;
#include &amp;#x003C;string&amp;#x003E;
using namespace std;

// Konstruktoren
CBank::CBank(string pname){
	m_name= pname;
}

// Methoden
void CBank::addKonto(const CKonto&amp;#x0026; akonto){
	m_konten.<question-record><question></question><answer><text>push_back</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>(akonto);
}

void CBank::removeKonto(const int kontoNR){
	vector&amp;#x003C;CKonto&amp;#x003E;::<question-record><question></question><answer><text>iterator</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record> it;
	
	for (it= m_konten.<question-record><question></question><answer><text>begin</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>(); it != m_konten.<question-record><question></question><answer><text>end</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>(); it++){
		if (it-&amp;#x003E;getNR() == kontoNR){
			m_konten.<question-record><question></question><answer><text>erase</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>(it);
			return;
		}
	}
}


// ......

// friends
ostream&amp;#x0026; operator&amp;#x003C;&amp;#x003C;(ostream&amp;#x0026; o, const CBank&amp;#x0026; e) {
	double gesamt=0.0;
    vector&amp;#x003C;CKonto&amp;#x003E;::const_iterator it;
    
    for (it= <question-record><question></question><answer><text>e.m_konten.begin</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>(); it != <question-record><question></question><answer><text>e.m_konten.end</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>(); it++)
		gesamt += it-&amp;#x003E;getBetrag();
        	
    o&amp;#x003C;&amp;#x003C; &quot;... BANK &quot; &amp;#x003C;&amp;#x003C; e.m_name &amp;#x003C;&amp;#x003C; &quot; ...&quot; &amp;#x003C;&amp;#x003C; endl;
    o&amp;#x003C;&amp;#x003C; &quot;... hat &quot; &amp;#x003C;&amp;#x003C; e.m_konten.<question-record><question></question><answer><text>size</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>();
    o&amp;#x003C;&amp;#x003C; &quot; Konten mit einem Gesamtbetrag von &quot; &amp;#x003C;&amp;#x003C; gesamt &amp;#x003C;&amp;#x003C; &quot; Euro.&quot; &amp;#x003C;&amp;#x003C; endl;

    o&amp;#x003C;&amp;#x003C; &quot;Hier nun eine Liste der einzelnen Konten:&quot; &amp;#x003C;&amp;#x003C;endl;
    for (it= <question-record><question></question><answer><text>e.m_konten.begin</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>(); it != <question-record><question></question><answer><text>e.m_konten.end</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>(); it++)
       o&amp;#x003C;&amp;#x003C; *(<question-record><question></question><answer><text>it</text><feedback></feedback><correct>1</correct></answer><clue></clue></question-record>);	//Hier wird genutzt, dass CKonto den operator &amp;#x003C;&amp;#x003C; &amp;#x00fc;berschrieben hat

    return o;
}
&amp;#x003C;/pre&amp;#x003E;
</gap-fill>
</data>
<hotpot-config-file>
<global>
<separate-js-file>0</separate-js-file>
<clue-caption>Clue</clue-caption>
<next-q-caption>=&amp;#x003E;</next-q-caption>
<last-q-caption>&amp;#x003C;=</last-q-caption>
<incorrect-indicator>X</incorrect-indicator>
<font-size>small</font-size>
<include-next-ex>1</include-next-ex>
<restart-caption>Restart</restart-caption>
<contents-url>index.htm</contents-url>
<include-timer>0</include-timer>
<font-face>Lucida Grande, Arial Unicode MS, Sans Serif</font-face>
<include-scorm-12>0</include-scorm-12>
<user-string-3></user-string-3>
<show-correct-first-time>0</show-correct-first-time>
<user-string-2></user-string-2>
<user-string-1></user-string-1>
<vlink-color>#0000cc</vlink-color>
<title-color>#000033</title-color>
<correct-indicator>:-)</correct-indicator>
<contents-caption>Index</contents-caption>
<show-all-questions-caption>Show all questions</show-all-questions-caption>
<undo-caption>Undo</undo-caption>
<header-code></header-code>
<hint-caption>Hint</hint-caption>
<check-button-caption>Check</check-button-caption>
<email>you@yourplace.com</email>
<show-one-by-one-caption>Show questions one by one</show-one-by-one-caption>
<name-please>Please enter your name:</name-please>
<formmail-url>http://your.server.address/cgi-bin/FormMail.pl</formmail-url>
<next-ex-caption>=&amp;#x003E;</next-ex-caption>
<back-caption>&amp;#x003C;=</back-caption>
<text-color>#000000</text-color>
<page-bg-color>#ffffff</page-bg-color>
<times-up>Your time has expired.</times-up>
<nav-bar-color>#000066</nav-bar-color>
<include-contents>1</include-contents>
<your-score-is>Your score is:</your-score-is>
<graphic-url></graphic-url>
<link-color>#0000ff</link-color>
<keypad-characters></keypad-characters>
<show-also-correct>1</show-also-correct>
<correct-first-time>Include score of questions answered correctly first time.</correct-first-time>
<include-cgi>0</include-cgi>
<ex-bg-color>#bbbbee</ex-bg-color>
<ok-caption>OK</ok-caption>
<process-for-rtl>0</process-for-rtl>
<check-caption>Check</check-caption>
<include-back>1</include-back>
<next-correct-letter>Next correct letter is: </next-correct-letter>
</global>
<jcloze>
<instructions></instructions>
<guesses-correct>Correct!</guesses-correct>
<guesses-incorrect>Some of your answers are incorrect. They have been left in place.</guesses-incorrect>
<header-code></header-code>
<include-hint>0</include-hint>
<include-keypad>0</include-keypad>
<include-word-list>0</include-word-list>
<case-sensitive>0</case-sensitive>
<next-ex-url>nextpage.htm</next-ex-url>
<send-email>0</send-email>
<show-also-correct>1</show-also-correct>
<exercise-subtitle></exercise-subtitle>
<next-correct-letter>Next correct letter is: </next-correct-letter>
<include-clue>0</include-clue>
<include-show-answer>0</include-show-answer>
<minimum-gap-size>6</minimum-gap-size>
<separate-javascript-file>0</separate-javascript-file>
<use-drop-down-list>0</use-drop-down-list>
</jcloze>
</hotpot-config-file>

</hotpot-jcloze-file>
