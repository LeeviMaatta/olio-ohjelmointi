#include "luottotili.h"
#include <string>

Luottotili::Luottotili(std::string omistaja, double luottoraja) : Pankkitili(omistaja), luottoraja(luottoraja)
{

}

Luottotili::~Luottotili()
{

}

bool Luottotili::deposit(double dAmount)
{
    if (dAmount > 0 && saldo + dAmount < 0) {
        saldo += dAmount;
        return true;
    } else {
        return false;
    }
}

bool Luottotili::withdraw(double wAmount)
{
    int nostoVara = luottoraja + saldo;

    if ((nostoVara - wAmount) > 0) {
        saldo -= wAmount;
        return true;
    } else {
        return false;
    }
}
