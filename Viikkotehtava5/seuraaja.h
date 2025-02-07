#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <string>

class Seuraaja
{
public:
    Seuraaja(std::string nimi);
    Seuraaja* next = nullptr;
    std::string getNimi();
    void paivitys(std::string);
private:
    std::string nimi;
};

#endif // SEURAAJA_H
