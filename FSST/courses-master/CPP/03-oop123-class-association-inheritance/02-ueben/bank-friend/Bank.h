/*
 * Bank.h
 *
 *  Created on: 15.09.2012
 *      Author: informatik
 */

#ifndef BANK_H_
#define BANK_H_

#include "Konto.h"

#include <string>
#include <vector>
using namespace std;

class Bank {
private:
	string m_name;
	vector<Konto*> m_konten;
public:
	Bank(string name);
	~Bank();

	const string& getName() const;
	void setName(const string& name);

	int addKonto(string name, double betrag);
	void delKonto(string name);

	Konto& getKonto(int nr);


	void addBetrag(double betrag); // for all accounts
	void minBetrag(double betrag); // for all accounts

	string toString() const;

};

#endif /* BANK_H_ */
