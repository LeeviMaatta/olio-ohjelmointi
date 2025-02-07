#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>

using namespace std;

int main()
{
    Notifikaattori N;

    Seuraaja *A = new Seuraaja("Aapeli");
    Seuraaja *B = new Seuraaja("Beepeli");
    Seuraaja *C = new Seuraaja("Ceepeli");

    N.lisaa(A);
    N.lisaa(B);
    N.lisaa(C);

    N.poista(B);

    N.tulosta();

    N.postita("Juupajuu");

    delete A;
    delete B;
    delete C;

    return 0;
}
