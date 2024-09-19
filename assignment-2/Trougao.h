#pragma once

#include "Tacka.h"
#include <iostream>

using namespace std;

class Trougao {
	char* ime;
	Tacka* temena[3];

public:
	Trougao(const char* ime, Tacka* tacka1, Tacka* tacka2, Tacka* tacka3);

	Trougao(const Trougao& drugi);

	friend ostream& operator<<(ostream & os, const Trougao & trougao);

	const Tacka* dohvatiTeme(int i)const;

	double aritmetickaSredinaOdPocetka()const;


	~Trougao() {
		delete[] ime;
	}
};