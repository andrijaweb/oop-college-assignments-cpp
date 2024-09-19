#pragma once

#include <iostream>
#include <vector>
#include "Trougao.h"

using namespace std;

class Ravan {
	char* ime;
	vector<Trougao> trouglovi;

public:
	Ravan(const char* ime);

	Ravan(const Ravan& druga);

	friend ostream& operator<<(ostream& os, const Ravan& ravan);

	void dodajTrougaoURavan(const Trougao& trougao);

	Ravan kreirajRavan(float min, float max)const;

	~Ravan() {
		delete[] ime;
	}
};