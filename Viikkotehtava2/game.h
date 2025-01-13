#ifndef GAME_H
#define GAME_H

#include <iostream>

class Game {
private:
    int randomNumber;
    int playerGuess;
    int numOfGuesses;
    const int maxNumber;
    void printGameResult();

public:
    Game();
    ~Game();
    void play();
};

#endif // GAME_H
