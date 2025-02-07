#include "notifikaattori.h"
#include "iostream"

Notifikaattori::Notifikaattori()
{

}

void Notifikaattori::lisaa(Seuraaja* uusi) {
    uusi->next = seuraajat;
    seuraajat = uusi;
}

void Notifikaattori::poista(Seuraaja *poisto)
{
    if (seuraajat == poisto) {
        seuraajat = poisto->next;
        std::cout << "Poistetaan " << poisto->getNimi() << std::endl;
    }
    else {
        Seuraaja *alku = seuraajat;
        while(alku != nullptr) {
            if(alku->next == poisto) {
                alku->next = poisto->next;
                std::cout << "Poistetaan " << poisto->getNimi() << std::endl;
            }
            alku = alku->next;
        }
    }
}

void Notifikaattori::postita(std::string viesti)
{
    Seuraaja* i = seuraajat;
    while (i) {
        i->paivitys(viesti);
        i = i->next;
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja *i = seuraajat;
    while (i != nullptr) {
        std::cout << "Listassa nyt: " << i->getNimi() << std::endl;
        i = i->next;
    }
}
