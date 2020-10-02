#include "notenmanager.h"

#include <fstream>
#include <iostream>


Notenmanager::Notenmanager(string name)
{
    this->name= name;
}

Notenmanager::~Notenmanager()
{
    // todo
}

void Notenmanager::readFromFile(string fn)
{
    ifstream file;
    string line;

    file.exceptions ( /*std::ifstream::failbit |*/ std::ifstream::badbit );

    try {

        file.open(fn);
		  
		  cout << endl << "*** EINGABE ***" << endl;

        // read 4 lines: ->grades
		  // grades[0] is not used
		  // grades[1] is used for Note1
		  // ...
		  // grades[4] is used for Note4
		  
        for(int i=1; i<=4; i++){
            // >=87.5%Note1
            std::getline(file, line, '\n');
				cout <<line << endl;
            string grade= line.substr(2, 4);
            grades[i]= stod(grade);
        }

        // read headline
        std::getline(file, line, '\n');
		  	cout <<line << endl;
        

        while(std::getline(file, line, '\n')){
            cout <<line << endl;

            tests.push_back(new Test(line));
        }


        file.close();

    } catch (std::ifstream::failure e) {
        std::cerr << "Exception opening/reading/closing: " << fn << endl;
    }

}


/*
- Folgende Ausgabe auf den Bildschirm soll dann erzeugt werden: 
Name:			MAX MUSTERMAN 
Punktestand: 		39 Punkte von 100 
Prozent:     		39% 
Note: 				5 
Schlechtestes Ergebnis: 	2013.05.01:20:4:C-Dateien 
Bestes Ergebnis: 		2013.03.10:20:20:C-Funktionen 
*/
void Notenmanager::printResult()
{
	cout << endl;
	cout << "*** ERGEBNIS ***" <<endl;
    cout << "... Name: " << this->name << endl;

    // punkte
    int sum_hat_pkte=0;
    for ( auto p : tests){
        sum_hat_pkte += p->getHatPkte();
    }

    int sum_max_pkte=0;
    for ( auto p : tests){
        sum_max_pkte += p->getMaxPkte();
    }

    cout << "... Punkte: " << sum_hat_pkte << " von " << sum_max_pkte << " Punkte"<< endl;

	 double prozent= (sum_hat_pkte/(double)sum_max_pkte) *100.0;
	cout << "... Prozent: " <<  prozent << "%" << endl;
	cout << "... Note: " << this->getNote(prozent) << endl;

	// Schlechtestes/bestes Ergbnis
	
	auto worstTest= tests[0];
	for (auto p: tests)
		if (worstTest->getProzent() < p->getProzent())
			worstTest= p;
	
	auto bestTest= tests[0];
	for (auto p: tests)
		if (bestTest->getProzent() > p->getProzent())
			bestTest= p;
	

	
	
	cout << "... Schlechtestes Ergebnis: " << worstTest->getLine() << endl;
	cout << "... Bestes Ergebnis: 	" << bestTest->getLine() << endl << endl;
}




int Notenmanager::getNote(double prozent){

		if (prozent >= grades[1])
			return 1;
		else if (prozent >= grades[2])
			return 2;
		else if (prozent >= grades[3])
			return 3;
		else if (prozent >= grades[4])
			return 4;
		else
			return 5;
}
