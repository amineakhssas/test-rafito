#include "Game.hpp"
#include <iostream>
#include <random>

int main() {
    Game game;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    int target = dis(gen);
    game.start(target);

    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "Guess the number between 1 and 100. You have " << game.getMaxAttempts() << " attempts." << std::endl;

    while (game.getAttemptsLeft() > 0) {
        int guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        std::string result = game.guess(guess);
        std::cout << result << std::endl;

        if (result == "correct") {
            std::cout << "You won!" << std::endl;
            break;
        }

        if (game.getAttemptsLeft() == 0) {
            std::cout << "You lost. The correct number was: " << target << std::endl;
        }
    }

    return 0;
}
