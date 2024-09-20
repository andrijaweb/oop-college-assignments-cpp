#pragma once
#include "Datum.h"

using namespace std;

class Karta
{
protected:
	static int brojac;
	int identifikator;

	Karta();

public:
	virtual bool jeIspravna(float cena, const Datum& datum)const = 0;

	Karta(const Karta&) = delete;
	Karta& operator=(const Karta&) = delete;

	friend ostream& operator<<(ostream& os, const Karta& karta);

	virtual ~Karta() {}
};
