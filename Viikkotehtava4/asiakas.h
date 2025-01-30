#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "luottotili.h"
#include "pankkitili.h"
#include <string>

class Asiakas
{
public:
    Asiakas(std::string nimi, double luottoraja);
    ~Asiakas();
    std::string getName();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tiliSiirto(double, Asiakas &vastaanottaja);
private:
    Pankkitili kayttotili;
    Luottotili luottotili;
    std::string nimi;
};
#endif // ASIAKAS_H
