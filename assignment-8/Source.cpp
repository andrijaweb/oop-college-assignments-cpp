#include "PrirodniLogaritam.h"
#include "Polinom.h"

int main() {
	try
	{
		Funkcija* logF = new PrirodniLogaritam();
		logF->citaj(cin);
		cout << "Funkcija: ";
		logF->pisi(cout);
		cout << "\nUnesi x: ";
		double x;
		cin >> x;
		cout << "logF(" << x << ") = " << (*logF)(x) << '\n';
		delete logF;
			
		int red;
		cout << "\nUnesite red polinoma: ";
		cin >> red;
		Polinom p(red);
		p.citaj(cin);
		cout << "Polinom: ";
		p.pisi(cout);
		cout << "\nRed polinoma: " << +p << '\n';
		cout << "Unesite x za p(x): ";
		cin >> x;
		cout << "p(" << x << ") = " << p(x) << '\n';

		cout << "Koeficijenti:\n";
		for (int i = 0; i <= +p; ++i) {
			cout << "p[" << i << "] = " << p[i] << '\n';
		}
	}
	catch (const std::exception& e)
	{
		cerr << "Greska: " << e.what() << endl;
	}


	return 0;
}