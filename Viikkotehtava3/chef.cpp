#include "chef.h"
#include <iostream>

Chef::Chef(std::string chefName) : chefName(chefName) {
    std::cout << "CONSTRUCTOR: object Chef initialized" << std::endl;
}

Chef::~Chef()
{
    std::cout << "GAME DESTRUCTOR: object Chef cleared from stack memory" << std::endl;
}

ItalianChef::ItalianChef(std::string chefName) : Chef(chefName) {
    std::cout << "CONSTRUCTOR: object ItalianChef initialized" << std::endl;
}

ItalianChef::~ItalianChef()
{
    std::cout << "GAME DESTRUCTOR: object ItalianChef cleared from stack memory" << std::endl;
}

int Chef::makeSalad(int num)
{
    std::cout << std::endl << "Making salad..." << std::endl << "Salads made: ";
    return num / 5;
}

int Chef::makeSoup(int num)
{
    std::cout << "Making soup..." << std::endl << "Soups made: ";
    return num / 3;
}

std::string Chef::getName()
{
    std::cout << std::endl << "Chef's name: Chef " << chefName << std::endl;
    return chefName;
}

bool ItalianChef::askSecret(std::string passwordInput, int flour, int water)
{
    ItalianChef::flour = flour;
    ItalianChef::water = water;
    if (passwordInput == password) {
        std::cout << std::endl << makepizza() << " Pizzas made" << std::endl;
        return true;
    } else {
        std::cout << "Wrong password!" << std::endl;
        return false;
    }
}

int ItalianChef::makepizza()
{
    int numPizza = std::min(flour / 5, water / 5);
    flour -= numPizza * 5;
    water -= numPizza * 5;
    return numPizza;
}
