#ifndef GAME_HPP
#define GAME_HPP

#include <string>

class Game {
public:
    Game();
    void start(int target);
    std::string guess(int value);
    int getMaxAttempts() const;
    int getAttemptsLeft() const;
    std::string getHistory() const;
private:
    int maxAttempts;
    int attemptsLeft;
    int target;
    std::vector<int> history;
};

#endif
