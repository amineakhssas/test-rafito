#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "../src/Game.hpp"

TEST_CASE("Game Initialization") {
    Game game;
    REQUIRE(game.getAttemptsLeft() == 5);
}

TEST_CASE("Game Guessing - Too Low") {
    Game game;
    game.start(50);
    REQUIRE(game.guess(10) == "too low");
    REQUIRE(game.getAttemptsLeft() == 4);
}

TEST_CASE("Game Guessing - Too High") {
    Game game;
    game.start(50);
    REQUIRE(game.guess(80) == "too high");
    REQUIRE(game.getAttemptsLeft() == 4);
}

TEST_CASE("Game Guessing - Correct") {
    Game game;
    game.start(50);
    REQUIRE(game.guess(50) == "correct");
    REQUIRE(game.getAttemptsLeft() == 5); // Correct guess doesn't reduce attempts
}

TEST_CASE("Game Over") {
    Game game;
    game.start(50);
    game.guess(10);
    game.guess(20);
    game.guess(30);
    game.guess(40);
    REQUIRE(game.guess(60) == "game over");
}

TEST_CASE("Game History") {
    Game game;
    game.start(50);
    game.guess(10);
    game.guess(20);
    game.guess(50);
    REQUIRE(game.getHistory() == "10 20 50");
}
