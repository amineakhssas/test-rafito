#include "Game.hpp"
#include <sstream>

Game::Game() : maxAttempts(5), attemptsLeft(5), targetNumber(0) {}

int Game::getMaxAttempts() const {
    return maxAttempts;
}

void Game::start(int target) {
    targetNumber = target;
    attemptsLeft = maxAttempts;
    history.clear();
}

std::string Game::guess(int number) {
    if (attemptsLeft <= 0) {
        return "game over";
    }
    attemptsLeft--;
    history.push_back(number);

    if (number < targetNumber) {
        return "too low";
    } else if (number > targetNumber) {
        return "too high";
    } else {
        return "correct";
    }
}

int Game::getAttemptsLeft() const {
    return attemptsLeft;
}

std::string Game::getHistory() const {
    std::ostringstream oss;
    for (size_t i = 0; i < history.size(); ++i) {
        if (i > 0) oss << " ";
        oss << history[i];
    }
    return oss.str();
}
