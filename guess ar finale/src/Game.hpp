#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

class Game {
public:
    Game(int maxAttempts = 5);

    void start(int target);
    std::string guess(int number);
    int getAttemptsLeft() const;
    std::string getHistory() const;

private:
    int maxAttempts;
    int attemptsLeft;
    int targetNumber;
    std::vector<int> history;
};

#endif // GAME_HPP
