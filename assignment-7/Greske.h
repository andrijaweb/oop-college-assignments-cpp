#pragma once
#include <string>

using namespace std;

class Greska : public exception {
	string poruka;

public:
	Greska(string p) : poruka(p) {}

	const char* what() const noexcept override {
		return poruka.c_str();
	}
};