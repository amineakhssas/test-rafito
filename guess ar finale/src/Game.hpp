#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

class Game {
public:
    Game();
    void newGame(int target);
    std::string play(int guess);
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
