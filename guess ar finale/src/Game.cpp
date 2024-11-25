#include "Game.hpp"
#include <stdexcept>
#include <sstream>

Game::Game() : maxAttempts(5), attempts(0), targetNumber(0) {}

void Game::start(int target) {
    if (target < 1 || target > 100) {
        throw std::out_of_range("Target number must be between 1 and 100.");
    }
    targetNumber = target;
    attempts = 0;
    history.clear();
}

std::string Game::guess(int number) {
    if (attempts >= maxAttempts) {
        return "game over";
    }

    history.push_back(number);
    attempts++;

    if (number == targetNumber) {
        return "correct";
    } else if (number < targetNumber) {
        return "too low";
    } else {
        return "too high";
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

int Game::getMaxAttempts() const {
    return maxAttempts; // Retourne le nombre maximal d'essais
}
