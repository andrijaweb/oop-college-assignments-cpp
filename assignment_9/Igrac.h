#pragma once

#include <iostream>
#include <string>

using namespace std;

class Igrac
{
private:
	static int sledeci_id;
	int id;
	string ime;
	double balans;

public:
	Igrac(const string& ime, double balans);
	Igrac(const Igrac& drugi);

	Igrac& operator=(const Igrac& drugi);

	int dohvatiId() const;
	string dohvatiIme() const;
	double dohvatiBalans() const;

	void podesiBalans(double noviBalans);
	void promeniBalans(double iznos);

	friend istream& operator>>(istream& in, Igrac& igrac);
	friend ostream& operator<<(ostream& out, const Igrac& igrac);

	~Igrac();
};

