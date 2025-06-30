#include "Kazino.h"
#include "Pseudorulet.h"
#include "Blekdzek.h"
#include "Igrac.h"
#include "Skor.h"
#include "Izuzeci.h"

class KazinoManager {
private:
    unique_ptr<Kazino> kazino;
    vector<unique_ptr<Igrac>> igraci;

public:
    KazinoManager() {
        kazino = make_unique<Kazino>(10000.0);

        kazino->dodajIgru(make_unique<Pseudorulet>());
        kazino->dodajIgru(make_unique<Blekdzek>());

        cout << "=== DOBRODOSLI U KAZINO ===" << endl;
        cout << "Pocetni budzet kazina: " << kazino->dohvatiBudzet() << endl;
    }

    void prikaziGlavniMeni() {
        cout << "\n=== GLAVNI MENI ===" << endl;
        cout << "1. Kreiraj novog igraca" << endl;
        cout << "2. Prikazi sve igrace" << endl;
        cout << "3. Prikazi dostupne igre" << endl;
        cout << "4. Odigraj igru" << endl;
        cout << "5. Prikazi budzet kazina" << endl;
        cout << "6. Prikazi skorove igre" << endl;
        cout << "0. Izlaz" << endl;
        cout << "Izaberite opciju: ";
    }

    void kreirajIgraca() {
        try {
            string ime;
            double balans;

            cout << "Unesite ime igraca: ";
            cin.ignore();
            getline(cin, ime);

            cout << "Unesite pocetni balans: ";
            cin >> balans;

            auto igrac = make_unique<Igrac>(ime, balans);
            cout << "Igrac kreiran: " << *igrac << endl;
            igraci.push_back(move(igrac));

        }
        catch (const KazinoIzuzetak& e) {
            cout << "Greska: " << e.what() << endl;
        }
    }

    void prikaziIgrace() {
        if (igraci.empty()) {
            cout << "Nema registrovanih igraca." << endl;
            return;
        }

        cout << "\n=== REGISTROVANI IGRACI ===" << endl;
        for (size_t i = 0; i < igraci.size(); ++i) {
            cout << (i + 1) << ". " << *igraci[i] << endl;
        }
    }

    void odigrajIgru() {
        try {
            if (igraci.empty()) {
                cout << "Nema registrovanih igraca. Kreeirajte igraca prvo." << endl;
                return;
            }

            prikaziIgrace();
            cout << "Odaberite igrca (broj): ";
            int igracBroj;
            cin >> igracBroj;

            if (igracBroj < 1 || igracBroj > static_cast<int>(igraci.size())) {
                throw NevazeciIndeksIzuzetak();
            }

            Igrac& odabraniIgrac = *igraci[igracBroj - 1];

            kazino->prikaziListuIgara();
            cout << "Odaberite igru (broj): ";
            int igraBroj;
            cin >> igraBroj;

            Igra* odabranaIgra = kazino->odaberiIgru(igraBroj, odabraniIgrac);

            cout << "\nOdabrana igra: " << odabranaIgra->dohvatiNaziv() << endl;
            cout << "Igrac: " << odabraniIgrac << endl;

            if (auto* pseudorulet = dynamic_cast<Pseudorulet*>(odabranaIgra)) {
                odigrajPseudorulet(pseudorulet, odabraniIgrac);
            }
            else if (auto* blekdzek = dynamic_cast<Blekdzek*>(odabranaIgra)) {
                odigrajBlekdzek(blekdzek, odabraniIgrac);
            }

        }
        catch (const KazinoIzuzetak& e) {
            cout << "Greska: " << e.what() << endl;
        }
    }

    void odigrajPseudorulet(Pseudorulet* rulet, Igrac& igrac) {
        try {
            rulet->zapocniIgru();

            cout << "\n=== PSEUDORULET ===" << endl;
            cout << "1. Ulozite na konkretni broj (0-35)" << endl;
            cout << "2. Ulozite na boju (r-crvena, c-crna)" << endl;
            cout << "3. Ulozite na parne brojeve" << endl;
            cout << "Odaberite tip uloga: ";

            int tipUloga;
            cin >> tipUloga;

            switch (tipUloga) {
            case 1: {
                cout << "Unesite broj (0-35): ";
                int broj;
                cin >> broj;
                (*rulet) += broj;
                break;
            }
            case 2: {
                cout << "Unesite boju (r ili c): ";
                char boja;
                cin >> boja;
                *rulet *= boja;
                break;
            }
            case 3: {
                *rulet /= true;
                break;
            }
            default:
                cout << "Nevazeca opcija!" << endl;
                return;
            }

            cout << "Izvlacenje broja..." << endl;
            double budzet = kazino->dohvatiBudzet();
            rulet->promeniBalansIgraca(igrac, 1.0, budzet);
            kazino->promeniBudzet(budzet - kazino->dohvatiBudzet());

            auto skor = make_unique<Skor>(igrac, rulet->dohvatiKrajnjiIshod());
            *rulet += move(skor);

        }
        catch (const KazinoIzuzetak& e) {
            cout << "Greska u igri: " << e.what() << endl;
        }
    }

    void odigrajBlekdzek(Blekdzek* blekdzek, Igrac& igrac) {
        try {
            blekdzek->zapocniIgru();

            cout << "\n=== BLEKDZEK ===" << endl;
            cout << "1. Uzmi novu kartu" << endl;
            cout << "2. Prekini igru" << endl;

            while (true) {
                cout << "Odaberite akciju: ";
                int akcija;
                cin >> akcija;

                double budzet = kazino->dohvatiBudzet();

                if (akcija == 1) {
                    blekdzek->promeniBalansIgraca(igrac, 0, budzet);
                    kazino->promeniBudzet(budzet - kazino->dohvatiBudzet());
                }
                else if (akcija == 2) {
                    bool pobeda = blekdzek->prekiniIgru(igrac, budzet);
                    kazino->promeniBudzet(budzet - kazino->dohvatiBudzet());

                    auto skor = make_unique<Skor>(igrac, pobeda ? 1 : 0);
                    *blekdzek += move(skor);
                    break;
                }
                else {
                    cout << "Nevazeca akcija!" << endl;
                }
            }

        }
        catch (const PrekidIgreIzuzetak& e) {
            cout << "Igra se zavrsila: " << e.what() << endl;

            auto skor = make_unique<Skor>(igrac, 0);
            *blekdzek += move(skor);
        }
        catch (const KazinoIzuzetak& e) {
            cout << "Greska u igri: " << e.what() << endl;
        }
    }

    void prikaziSkorove() {
        try {
            kazino->prikaziListuIgara();
            cout << "Odaberite igru za prikaz skorova: ";
            int igraBroj;
            cin >> igraBroj;

            if (igraBroj < 1 || igraBroj > static_cast<int>(kazino->dohvatiIgre().size())) {
                throw NevazeciIndeksIzuzetak();
            }

            const auto& igra = kazino->dohvatiIgre()[igraBroj - 1];
            cout << *igra << endl;

        }
        catch (const KazinoIzuzetak& e) {
            cout << "Greska: " << e.what() << endl;
        }
    }

    void pokreni() {
        int opcija;

        do {
            prikaziGlavniMeni();
            cin >> opcija;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nevazeci unos!" << endl;
                continue;
            }

            switch (opcija) {
            case 1:
                kreirajIgraca();
                break;
            case 2:
                prikaziIgrace();
                break;
            case 3:
                kazino->prikaziListuIgara();
                break;
            case 4:
                odigrajIgru();
                break;
            case 5:
                cout << "Budzet kazina: " << kazino->dohvatiBudzet() << endl;
                break;
            case 6:
                prikaziSkorove();
                break;
            case 0:
                cout << "Hvala na igranju! Dovidjenja!" << endl;
                break;
            default:
                cout << "Nevazeca opcija!" << endl;
                break;
            }

        } while (opcija != 0);
    }
};

int main() {
    try {
        KazinoManager manager;
        manager.pokreni();
    }
    catch (const exception& e) {
        cout << "Kriticna greska: " << e.what() << endl;
        return 1;
    }

    return 0;
}