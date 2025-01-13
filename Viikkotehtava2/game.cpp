#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game() : randomNumber(0), playerGuess(0), numOfGuesses(0), maxNumber(20) {
    srand(time(0)); // Seed the random number generator
    cout << "GAME CONSTRUCTOR: object initialized with 20 as maximum value" << endl;
}

Game::~Game() {
    cout << "GAME DESTRUCTOR: object cleared from stack memory";
}

void Game::printGameResult() {
    cout << "Arvasit oikein!" << endl;
    cout << "Arvasit " << numOfGuesses << " kertaa!" << endl;
}

void Game::play() {
    cout << "Arvaa luku valilta 0 - 20: ";
    randomNumber = rand() % maxNumber;

    while (true) {
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess == randomNumber) {
            printGameResult();
            break;
        } else if (playerGuess > randomNumber) {
            cout << "Arvasit liian ison numeron, arvaa uudelleen: ";
        } else {
            cout << "Arvasit liian pienen numeron, arvaa uudelleen: ";
        }
    }
}
