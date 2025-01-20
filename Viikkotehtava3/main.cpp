#include <iostream>
#include <chef.h>

using namespace std;

int main()
{
    Chef chef1("Pasi");

    chef1.getName();
    cout << chef1.makeSalad(30) << endl;
    cout << chef1.makeSoup(30) << endl;

    ItalianChef ichef1("Jorma");

    ichef1.getName();
    cout << ichef1.makeSalad(30) << endl;
    cout << ichef1.makeSoup(30) << endl;
    ichef1.askSecret("pizza", 30, 30);
    ichef1.askSecret("lasagne", 30, 30);

    return 0;
}
