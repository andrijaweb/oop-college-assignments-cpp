#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Tacka {
	float x, y;

public:
	Tacka(float x = 0.0, float y = 0.0);

	friend ostream& operator<<(ostream& os, const Tacka& tacka);

	float rastojanje(const Tacka& druga = Tacka()) const;
};