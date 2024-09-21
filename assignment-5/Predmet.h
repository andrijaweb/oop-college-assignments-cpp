#pragma once
#include <iostream>
#include <memory>

using namespace std;

class Predmet
{
protected: 
	double specificnaTezina;

public:
	Predmet(double specificnaTezina);

	virtual double zapremina()const = 0;
	double tezina()const;
	virtual void ispisi()const = 0;
	virtual unique_ptr<Predmet> kopiraj()const = 0;

	virtual ~Predmet() {}
};

