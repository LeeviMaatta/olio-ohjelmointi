#ifndef CHEF_H
#define CHEF_H
#include <string>

class Chef
{
public:
    Chef(std::string chefName);
    ~Chef();
    std::string getName();
    int makeSalad(int);
    int makeSoup(int);
protected:
    std::string chefName;
};

class ItalianChef: public Chef
{
public:
    ItalianChef(std::string chefName);
    ~ItalianChef();
    bool askSecret(std::string, int flour, int water);
private:
    int makepizza();
    std::string password = "pizza";
    int flour;
    int water;
};

#endif // CHEF_H
