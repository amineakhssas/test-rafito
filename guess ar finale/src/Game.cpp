#include "Game.hpp"
#include <algorithm> // for std::to_string

Game::Game() : maxAttempts(5), attemptsLeft(5), target(0) {}

void Game::newGame(int target) {
    this->target = target;
    attemptsLeft = maxAttempts;
    history.clear();
}

std::string Game::play(int guess) {
    if (attemptsLeft <= 0) {
        return "game over";
    }

    attemptsLeft--;
    history.push_back(guess);

    if (guess < target) {
        return "too low";
    } else if (guess > target) {
        return "too high";
    } else {
        return "Win";
    }
}

int Game::getMaxAttempts() const {
    return maxAttempts;
}

int Game::getAttemptsLeft() const {
    return attemptsLeft;
}

std::string Game::getHistory() const {
    std::string result;
    for (int h : history) {
        result += std::to_string(h) + " ";
    }
    if (!result.empty()) {
        result.pop_back(); // Remove the trailing space
    }
    return result;
}
