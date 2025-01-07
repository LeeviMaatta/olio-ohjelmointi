#include <iostream>
#include <time.h>

using namespace std;

int game(int);

int main()
{
    int maxNum = 20;
    int guessCount = 0;

    guessCount = game(maxNum);

    cout << "Arvasit " << guessCount << " kertaa" << endl;

    return 0;
}

int game(int maxNum)
{
    int guessCount = 0;

    srand(time(0));
    cout << "Arvaa luku valilta 0 - 20: ";
    int randomNum = rand() % maxNum;

    while (1) {
        int guessedNum = 0;

        cin >> guessedNum;
        guessCount++;

        if (guessedNum == randomNum) {
            cout << "Arvasit oikein!" << endl;
            break;
        }
        else if (guessedNum != randomNum) {
            if (guessedNum > randomNum) {
                cout << "Arvasit liian ison numeron, arvaa uudelleen: ";
            }
            else if (guessedNum < randomNum) {
                cout << "Arvasit liian pienen numeron, arvaa uudelleen: ";
            }
        }
    }
    return guessCount;
}
