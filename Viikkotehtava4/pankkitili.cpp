#include "pankkitili.h"
#include <string>
#include <iostream>

Pankkitili::Pankkitili(std::string omistaja) : omistaja(omistaja)
{

}

Pankkitili::~Pankkitili()
{

}

bool Pankkitili::deposit(double dAmount)
{
    if (dAmount > 0) {
        saldo += dAmount;
        return true;
    } else {
        return false;
    }
}

bool Pankkitili::withdraw(double wAmount)
{
    if (wAmount > 0 && wAmount <= saldo) {
        saldo -= wAmount;
        return true;
    } else {
        return false;
    }
}

double Pankkitili::getBalance()
{
    return saldo;
}
