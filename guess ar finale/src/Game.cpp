#include "Game.hpp"

void Game::newGame() {
    target = 10;
    nbRemainingTries = 5;
}

void Game::newGame(int nbr) {
    target = nbr;
    nbRemainingTries = 5;
}

std::string Game::play(int tentatif) {
    if (tentatif < 0 || tentatif > 100) {
        return "Invalid";
    }
    nbRemainingTries--;
    if (tentatif == target) {
        return "Win";
    } else if (tentatif < target) {
        return "too low";
    } else {
        return "too high";
    }
}
