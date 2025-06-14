#pragma once
#include <iostream>

using namespace std;

class Funkcija {
public:
	virtual double operator()(double x) const = 0;
	virtual void citaj(istream& in) = 0;
	virtual void pisi(ostream& out) const = 0;

	virtual ~Funkcija() {}
};