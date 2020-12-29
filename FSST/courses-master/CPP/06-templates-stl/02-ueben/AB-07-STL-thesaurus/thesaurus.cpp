/*
* @file thesaurus.cpp
* @name ????????????????
*
* @description
Ein Thesaurus ist eine systematische Sammlung von Worten und Begriffen, 
die es erlaubt, zu einem vorgegebenem Begriff/Wort passende Begriffe 
(Synonyme) zu finden. Die Begriffe können verwandt sein oder aber auch das 
Gegenteil darstellen. Insofern ist ein Thesaurus das Gegenstück zu einem 
Wörterbuch. 
Das Wörterbuch erläutert das zu einem gegebenen Begriff gehörende Konzept.
Der Thesaurus präsentiert zu einem gegebenen Konzept sinn- und sachverwandte 
Worte.
Der hier verwendete Thesaurus ist in seiner Urform 1852 von Peter Mark Roget 
veröffentlicht worden. Er ist in der Datei *roget.dat* enthalten. 
Die Datei ist über FTP erhältlich.

Die Zeilen der Datei haben folgendes Aussehen:

	1existence:2 69 125 149 156 166 193 455 506 527
	2inexistence:1 4 167 192 194 368 458 526 527 771
	3substantiality:4 323 325
	4unsubstantiality:3 34 194 360 432 452 458 527 
	...usw....
	Die Zahlen hinter dem Konzept substantiality haben die Bedeutung, dass 
	dazu passende Einträge in den Zeilen 4, 323 und 325 zu finden sind. 


* Aufgabe:
Erstellen sie ein Programm **thesaurus.cpp** , mit dem man 

1. einen Begriff eingeben kann und 
2. anschliessend wird der Thesaurus verwendet, um passende Begriffe oder  auch das Gegenteil anzuzeigen.


* Hint: <http://acm2005.cct.lsu.edu/problems/8.cpp.html> 

	/* Split a string along any of the characters in the delim string.
	 * The delimiters themselves are included at the beginning of the split
	 * substrings. Leading white space in all the strings is removed.
	 */
	vector<string> split(string word, char* delim){
		int pos = 0;
		vector<string> list;

		ltrim(word); /* Remove leading white space and locate first delimiter */
		pos = word.find_first_of(delim);
		
		while(pos != string::npos) {/*splitting until no more delimiters found */
		        
		    /* Create new string from everything to the left of delimiter */
		    list.push_back(word.substr(0, pos));
		        
		    word.erase(0, pos); /* Remove everything to the left of delimiter */
		    
		    /* Skip over the delimiter left at beginning of string */
		    pos = word.find_first_of(delim, 1);
		}
		
		ltrim(word);  /* Append the remaining delimiter-less word to list */
		list.push_back(word);
		
		return list;
	}

* Hint: split with stringstream and getline() 

	```cpp
		string cm="ADD:PK:3"
		stringstream ss(cmd);

		string part;
		std::getline(ss, part, ':');
		cout << part << endl;

		std::getline(ss, part, ':');
		cout << part << endl;

		std::getline(ss, part, ':');
		cout << part << endl;
	```
*/


#include <cctype> // isdigit

#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <list>
#include <vector>


using namespace std;
void 
printWords(
	map<string, list<int> > & thesaurus, 
	vector<string> & words, 
	string& word);


// -----------------------------------------------------------------------------
int main(){
	ifstream fin;
	string line;

	string word;
	map<string, list<int> > thesaurus;
	list<int> lines;
	vector<string> words(4000);
	int iLine;

// open file
	fin.open("roget.dat");
	if (fin.fail()){
		cerr << "error: open roget.dat" << endl;
		return 1;
	}

// READ roget.dat
	cout << "reading roget.dat ..." << endl;
	// get over first documentation lines
	do{
		getline(fin, line);
		//cout << line << endl;
	}while(! isdigit(line[0]));


	// read roget.dat into a map<string, list<int> >
	// store word in a vector<string> for access by index

	while( isdigit(line[0])){
		// clear list of lineNumbers
		lines.clear();
		// cout << "new line ->" << line << endl;


		// ...................
		

		// make an entry in the map
		thesaurus[word]= lines;

		// read next line
		getline(fin, line);
	}


	//cout << "read rest of file ========================"<< endl;
	do{
		getline(fin, line);
		//cout << line << endl;
	}while(! fin.eof());



// READ user input
	cout << "Enter word: " ;
	cin >> word;

	printWords(thesaurus, words, word);


	fin.close();
	
	return 0;
}
