#define _CRT_SECURE_NO_WARNINGS 1
#include "Trougao.h"

Trougao::Trougao(const char* ime, Tacka* tacka1, Tacka* tacka2, Tacka* tacka3) {
	this->ime = new char[strlen(ime) + 1];
	strcpy(this->ime, ime);

	temena[0] = tacka1;
	temena[1] = tacka2;
	temena[2] = tacka3;
}

Trougao::Trougao(const Trougao& drugi) {
	if (strstr(drugi.ime, "_klon") == nullptr) {
		this->ime = new char[strlen(drugi.ime) + 6];  // 6ica je za "_klon" i '\0'
		strcpy(this->ime, drugi.ime);
		strcat(this->ime, "_klon");
	}
	else {
		this->ime = new char[strlen(drugi.ime) + 1];
		strcpy(this->ime, drugi.ime);
	}

	temena[0] = drugi.temena[0];
	temena[1] = drugi.temena[1];
	temena[2] = drugi.temena[2];
}

ostream& operator<<(ostream& os, const Trougao& trougao) {
	os << trougao.ime << '[' << *(trougao.temena[0]) << ", " << *(trougao.temena[1]) << ", " << *(trougao.temena[2]) << ": " << trougao.aritmetickaSredinaOdPocetka() << ']';

	return os;
}

const Tacka* Trougao::dohvatiTeme(int i)const {
	if (i >= 0 && i < 3) return temena[i];

	return nullptr;
}

double Trougao::aritmetickaSredinaOdPocetka()const {
	return (temena[0]->rastojanje() + temena[1]->rastojanje() + temena[2]->rastojanje()) / 3.0;
}