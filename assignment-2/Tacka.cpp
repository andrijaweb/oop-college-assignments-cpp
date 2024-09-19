#include "Tacka.h"

Tacka::Tacka(float x, float y): x(x), y(y) {}

ostream& operator<<(ostream& os, const Tacka& tacka) {
	os << "(" << tacka.x << ", " << tacka.y << ")";
	return os;
}

float Tacka::rastojanje(const Tacka& druga)const {
	return sqrt((x - druga.x) * (x - druga.x) + (y - druga.y) * (y - druga.y));
}