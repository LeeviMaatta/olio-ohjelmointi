#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(std::string nimi)
    : nimi(nimi)
{
    std::cout << "Luodaan seuraaja " << nimi << std::endl;
}

std::string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(std::string viesti)
{
    std::cout << nimi << " Uusi viesti: " << viesti << std::endl;
}
