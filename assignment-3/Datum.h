#pragma once

#include <iostream>

using namespace std;

class Datum
{
	int mesec;
	int godina;

public:
	Datum(int mesec, int godina);

	int dohvatiMesec()const;
	int dohvatiGodina()const;

	bool operator==(const Datum& drugi)const;
	bool operator!=(const Datum& drugi)const;

	friend ostream& operator<<(ostream& os, const Datum& datum);

};

