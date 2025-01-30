#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>

class Pankkitili
{
public:
    Pankkitili(std::string omistaja);
    ~Pankkitili();
    double getBalance();
    virtual bool deposit(double dAmount);
    virtual bool withdraw(double wAmount);
protected:
    std::string omistaja;
    double saldo = 0;
};

#endif // PANKKITILI_H
