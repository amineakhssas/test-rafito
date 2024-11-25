#ifndef GAME_HPP
#define GAME_HPP

#include <string>

class Game {
public:
    void newGame();
    void newGame(int nbr);
    std::string play(int tentatif);

private:
    int target;
    int nbRemainingTries;
};

#endif
