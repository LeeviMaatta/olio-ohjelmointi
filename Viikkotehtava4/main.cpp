#include <iostream>
#include "asiakas.h"

using namespace std;

void menu();
void tilinValintaMenu();

Asiakas tiliPasi("Pasi Kuikka", 500);
Asiakas tiliJari("Jari Kuikka", 700);
Asiakas* nykyinenAsiakas = nullptr;

int main()
{
    tilinValintaMenu();

    if (nykyinenAsiakas != nullptr) {
        cout << nykyinenAsiakas->getName() << endl;
        nykyinenAsiakas->showSaldo();
    }

    while (1) {
        menu();
    }

    return 0;
}

void tilinValintaMenu() {
    int vastaus;

    cout << "Mita tilia haluat kayttaa: " << endl
         << tiliPasi.getName() << " = 1" << endl
         << tiliJari.getName() << " = 2" << endl;

    cin >> vastaus;

    switch (vastaus) {
    case 1:
        nykyinenAsiakas = &tiliPasi;  // Valitaan Pasi
        break;
    case 2:
        nykyinenAsiakas = &tiliJari;  // Valitaan Jari
        break;
    default:
        cout << "Virheellinen valinta." << endl;
        tilinValintaMenu();
        break;
    }
}

void menu()
{
    int vastaus;

    if (nykyinenAsiakas == nullptr) {
        cout << "Valitse asiakas ensin!" << endl;
        return;
    }

    cout << "1 = Talletus" << endl
         << "2 = Nosto" << endl
         << "3 = Luoton nosto" << endl
         << "4 = Luoton maksu" << endl
         << "5 = Nayta saldo" << endl
         << "6 = Tilisiirto" << endl
         << "7 = Vaihda tili" << endl;  // ✅ Lisätty tilinvaihto

    cin >> vastaus;

    switch (vastaus) {
    case 1:
        cout << "Paljonko haluat tallettaa: ";
        cin >> vastaus;
        if (nykyinenAsiakas->talletus(vastaus)) {
            cout << "Talletus onnistui" << endl;
        } else {
            cout << "Talletus epaonnistui" << endl;
        }
        break;
    case 2:
        cout << "Paljonko haluat nostaa: ";
        cin >> vastaus;
        if (nykyinenAsiakas->nosto(vastaus)) {
            cout << "Nosto onnistui";
        } else {
            cout << "Nosto epaonnistui" << endl;
        }
        break;
    case 3:
        cout << "Paljonko haluat nostaa luottoa: ";
        cin >> vastaus;
        if (nykyinenAsiakas->luotonNosto(vastaus)) {
            cout << "Nosto onnistui";
        } else {
            cout << "Nosto epaonnistui" << endl;
        }
        break;
    case 4:
        cout << "Paljonko haluat maksaa luottoa: ";
        cin >> vastaus;
        if (nykyinenAsiakas->luotonMaksu(vastaus)) {
            cout << "Maksu onnistui";
        } else {
            cout << "Maksu epaonnistui" << endl;
        }
        break;
    case 5:
        nykyinenAsiakas->showSaldo();
        break;
    case 6: {
        cout << "Kelle haluat siirtaa rahaa? (1 = " << tiliPasi.getName()
        << ", 2 = " << tiliJari.getName() << "): ";
        int vastaanottajaValinta;
        cin >> vastaanottajaValinta;

        cout << "Paljonko rahaa siirretaan: ";
        double siirtoSumma;
        cin >> siirtoSumma;

        Asiakas* vastaanottaja = nullptr;
        if (vastaanottajaValinta == 1 && nykyinenAsiakas != &tiliPasi) {
            vastaanottaja = &tiliPasi;
        } else if (vastaanottajaValinta == 2 && nykyinenAsiakas != &tiliJari) {
            vastaanottaja = &tiliJari;
        } else {
            cout << "Et voi siirtaa itsellesi!" << endl;
        }

        if (vastaanottaja != nullptr) {
            if (nykyinenAsiakas->tiliSiirto(siirtoSumma, *vastaanottaja)) {
                cout << "Siirto onnistui!" << endl;
            } else {
                cout << "Siirto epaonnistui!" << endl;
            }
        }
        break;
    }
    case 7:  // ✅ Tilinvaihto
        tilinValintaMenu();
        break;
    default:
        cout << "Virheellinen valinta!" << endl;
        break;
    }
}
