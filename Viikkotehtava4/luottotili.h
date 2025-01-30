#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "pankkitili.h"
#include <string>

class Luottotili : public Pankkitili
{
public:
    Luottotili(std::string omistaja, double luottoraja);
    ~Luottotili();
    bool deposit(double dAmount) override;
    bool withdraw(double wAmount) override;
protected:
    double luottoraja = 0;
};

#endif // LUOTTOTILI_H
