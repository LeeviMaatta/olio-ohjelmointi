#include "asiakas.h"
#include <iostream>

Asiakas::Asiakas(std::string nimi, double luottoraja)
    : kayttotili(nimi), luottotili(nimi, luottoraja), nimi(nimi)
{

}

Asiakas::~Asiakas()
{

}

std::string Asiakas::getName()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    std::cout << "Kayttotilin saldo: " << kayttotili.getBalance() << std::endl;
    std::cout << "Luottotilin saldo: " << luottotili.getBalance() << std::endl;
}

bool Asiakas::talletus(double talletusMaara)
{
    return kayttotili.deposit(talletusMaara);
}

bool Asiakas::nosto(double nostoMaara)
{
    return kayttotili.withdraw(nostoMaara);
}

bool Asiakas::luotonMaksu(double talletusMaara)
{
    return luottotili.deposit(talletusMaara);
}

bool Asiakas::luotonNosto(double nostoMaara)
{
    return luottotili.withdraw(nostoMaara);
}

bool Asiakas::tiliSiirto(double siirtoMaara, Asiakas &vastaanottaja)
{
    if (!kayttotili.withdraw(siirtoMaara)) {
        return false;
    } else {
        return vastaanottaja.kayttotili.deposit(siirtoMaara);
    }
}
