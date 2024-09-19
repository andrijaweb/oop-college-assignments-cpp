#pragma once
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

#include "Pitanje.h"

class Formular
{
	vector<Pitanje> pitanja;
	int odKoliko;
	int doKoliko;

public:
	Formular(int odKoliko = 1, int doKoliko = 7);

	friend ostream& operator<<(ostream& os, const Formular& formular);

	void dodajPitanje(const Pitanje& pitanje);
	void postaviOdgovor(int i, int odgovor);
	const Pitanje& dohvatiPitanje(int i)const;
};

