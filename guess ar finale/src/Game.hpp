#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

class Game {
private:
    int targetNumber;
    int maxAttempts;
    int attemptsLeft;
    std::vector<int> history;

public:
    Game();                      // Constructeur par défaut
    int getMaxAttempts() const;  // Retourne le nombre maximum d'essais
    void start(int target);      // Initialise le jeu avec un nombre cible
    std::string guess(int number);  // Devine un nombre et retourne le résultat
    int getAttemptsLeft() const;   // Retourne le nombre d'essais restants
    std::string getHistory() const; // Retourne l'historique des devinettes
};

#endif
