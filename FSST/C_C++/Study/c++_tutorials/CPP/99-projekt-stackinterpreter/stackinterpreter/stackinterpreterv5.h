#ifndef stackinterpreter_h
#define stackinterpreter_h stackinterpreter_h
#include "stackengine.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

class CStackinterpreter {
    private:
        	int m_pc;        //ProgrammCounter
		int m_nol;       //Number of Lines
		string m_code[1024];   				//Code-Speicher
		map< string, double, less<string> > m_data;	//Daten-Speicher
		CStackengine m_stackengine;
    public:
		CStackinterpreter(){m_pc=m_nol=0;};
		CStackinterpreter(const char* pFilename);
		
		//Memeberzugriff
		void set_pc(); 	//??????
		int get_pc(); 	//??????
		int get_nol(); 	//??????
		
		//öffnet eine Textdatei (s.unten) und liest in den Code-Speichher
		bool open(const char* pFilename);
		
		//gibt den Speicher aus
		friend ostream& operator<<(ostream& o,  CStackinterpreter& e);

		
		//arbeitet den Code-Speicher schritt f. schritt ab
		//und gibt im Fehlerfall einen negativen Fehlercode zurück
		//sonst wird der Programmcounter (m_pc) zurückgegeben
		int run();
		
		//führt den Befehl auf den der PC zeigt aus
		//und gibt im Fehlerfall einen negativen Fehlercode zurück
		//sonst wird der Programmcounter (m_pc) zurückgegeben
		int step();		//?????? 
		int step(int pLine);	//??????führt die Befehle bis zur Zeiel pLine aus, sofern PC < pLine 
		
		void reset();	//v3
		

		//gibt das oberste Element der stackengine zurück
		double top();
   };
   
   //TODO: //????????? fertigprogrammieren, BREAKPOINT verwaltung, STACKengine alleine anzeigen lassen (vgl. Watch)
#endif


