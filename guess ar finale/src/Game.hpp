#include "Game.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>

Game::Game() : maxAttempts(5), attempts(0), targetNumber(0) {}

void Game::start(int target) {
    targetNumber = target;
    attempts = 0;
    history.clear();
}

std::string Game::guess(int number) {
    if (attempts >= maxAttempts) {
        return "game over";
    }

    attempts++;
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
    return maxAttempts - attempts;
}

std::string Game::getHistory() const {
    std::ostringstream oss;
    for (size_t i = 0; i < history.size(); ++i) {
        if (i > 0) {
            oss << " ";
        }
        oss << history[i];
    }
    return oss.str();
}
