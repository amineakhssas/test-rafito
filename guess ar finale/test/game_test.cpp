#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "../src/Game.hpp"

TEST_CASE("Game Initialization", "[Game]") {
    Game game;
    REQUIRE(game.getMaxAttempts() == 5);
}

TEST_CASE("Game Guess Logic - Too Low", "[Game]") {
    Game game;
    game.start(50); // Initialiser le jeu avec la cible 50

    REQUIRE(game.guess(10) == "too low");
    REQUIRE(game.getAttemptsLeft() == 4);
}

TEST_CASE("Game Guess Logic - Too High", "[Game]") {
    Game game;
    game.start(50); // Initialiser le jeu avec la cible 50

    REQUIRE(game.guess(80) == "too high");
    REQUIRE(game.getAttemptsLeft() == 4);
}

TEST_CASE("Game Guess Logic - Correct Guess", "[Game]") {
    Game game;
    game.start(50); // Initialiser le jeu avec la cible 50

    REQUIRE(game.guess(50) == "correct");
    REQUIRE(game.getAttemptsLeft() == 5); // Le nombre d'essais ne change pas après une bonne réponse
}

TEST_CASE("Game Over Condition", "[Game]") {
    Game game;
    game.start(50); // Initialiser le jeu avec la cible 50

    game.guess(10); // 1er essai
    game.guess(20); // 2e essai
    game.guess(30); // 3e essai
    game.guess(40); // 4e essai
    REQUIRE(game.guess(60) == "game over"); // 5e essai - jeu terminé
}

TEST_CASE("Game History", "[Game]") {
    Game game;
    game.start(50); // Initialiser le jeu avec la cible 50

    game.guess(10);
    game.guess(20);
    game.guess(50);

    REQUIRE(game.getHistory() == "10 20 50");
}
