/*
* CPP STL: Crossreference
* 
* @file: crossreference.cpp
* @name: ?????????????
*
* g++ crossreference.cpp -o crossreference.exe
* ./crossreference.exe
*
*
* @description:
  Es soll eine Cross-Referenzlist erzeugt werden.
  (vergleichbar mit den Index-Seiten eines Buches). 
  Einem Wort sind die Seitennummern oder Zeilennummer als Liste beigefügt:

	Standardalgorithmen:	23, 123, 233
	STL: 33, 234
	Datenstrukturen: 4
	... usw. ...

* Aufgabe:
  Das folgende Programm liest die Datei *crossreference.txt* und gibt die 
  darin enthaltenen Wörter inkl. einer Liste von Zeilennummern aus.

**crossreference.txt**

	STL ist die Abkürzung für Standard Template Library. 
	Sie ist eine komplexe Sammlung von Templateklassen und 
	Templatefunktionen, welche viele bekannte und häufig 
	gebrauchte Algorithmen und Datenstrukturen kapseln. 
	Man findet in ihr zum Beispiel Vektoren 
	(das sind dynamische Arrays), Listen, Stacks, 
	sowie Such- und Sortieralgorithmen. 
	Die Standard Template Library ist seit 
	1994 ein Teil von C++.


Ausgabe:

	...
	sowie: 8,
	und: 3,3,4,5,8,
	viele: 4,
	von: 3,10,
	...


Bringen Sie folg. Programm **crossreference.cpp** zum Laufen:
*/

#include <map> 
#include <list> 
#include <algorithm> 
#include <string> 
#include <sstream> 
#include <fstream> 
#include <iostream> 
#include <cctype> 
using namespace std; 

//
class crossref{ 
	private: 
		ifstream fin; 
		map<string,list<int> > m_map; 
		 
	public: 
		crossref(const string& filename); 
		~crossref(); 
		 
		friend ostream& operator<< (ostream& o, const crossref& e);	 
}; 


crossref::crossref(const string& filename){ 
	int lineno= 0; 
	string s, word; 
	 
	fin.open(filename.c_str()); // Datei öffnen
	if (! fin.fail()){ 
		 
		// zeilenweise lesen
		lineno= 0; 
		while (getline(fin,s, '\n')){ 
			lineno++; 
		
			// zeile in wörter zerlegen: hier mit istringstream
			istringstream sin(s); 
			while (!sin.eof()){
				sin >> word; 

				if ( isalnum(word[0])) // wenns ein Wort ist
					m_map[word].push_back(lineno); 
			}
		} 
	} 
} 

crossref::~crossref(){ 
	fin.close(); 
} 

ostream& operator<< (ostream& o, const crossref& e){ 
	map<string, list<int> >::const_iterator it; 
	list<int>::const_iterator lines; 
	 
	//über die map
	for(it= e.m_map.begin(); it != e.m_map.end(); it++){ 
		o << endl << it->first << ": "; 
	
		// über den vector
		for(lines= (it->second).begin(); 
			lines != (it->second).end(); lines++)
 
			o<< *lines << ","; 
	} 
	 
	return o; 
} 


int main(){ 
	crossref reader("crossreference.txt"); 
	 
	cout << reader; 
	 
	return 0; 
} 
