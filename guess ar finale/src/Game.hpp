#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

class Game {
public:
    Game();
    void start(int target);
    std::string guess(int number);
    int getAttemptsLeft() const;
    std::string getHistory() const;
    int getMaxAttempts() const; // Méthode publique pour accéder à maxAttempts

private:
    int maxAttempts;
    int attempts;
    int targetNumber;
    std::vector<int> history;
};

#endif // GAME_HPP
