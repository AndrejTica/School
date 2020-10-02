/*
 * Konto.h
 *
 *  Created on: 15.09.2012
 *      Author: informatik
 */

#ifndef KONTO_H_
#define KONTO_H_

#include <string>
using namespace std;

class Konto {
private:
	// !!!!!!!!!!!!!!!!!!!!!!!!!!
	static int nextKontoNummer;


	int m_nummer;
	string m_inhaber;
	double m_betrag;

	friend class Bank;

	// only a Bank can create Accounts
	Konto(string inhaber, double betrag);
	~Konto();

public:
	double getBetrag() const;
	void setBetrag(double betrag);

	const string& getInhaber() const;
	void setInhaber(const string& inhaber);

	int getNummer() const;
	void setNummer(int nummer);

	void abheben(double betrag);
	void einlegen(double betrag);

	string toString() const;


};

#endif /* KONTO_H_ */
