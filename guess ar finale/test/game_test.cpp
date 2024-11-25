#include "../src/Game.hpp"
#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Initialisation de newGame") {
    Game game;
    game.newGame();
    REQUIRE(game.play(50) == "too high");
}

TEST_CASE("Initialisation avec cible prédéfinie") {
    Game game;
    game.newGame(42);
    REQUIRE(game.play(42) == "Win");
    REQUIRE(game.play(20) == "too low");
    REQUIRE(game.play(60) == "too high");
}

TEST_CASE("Gestion des entrées invalides") {
    Game game;
    game.newGame(42);
    REQUIRE(game.play(200) == "Invalid");
    REQUIRE(game.play(-10) == "Invalid");
}

TEST_CASE("Historique des tentatives") {
    Game game;
    game.newGame(42);

    vector<int> history;
    history.push_back(10);
    REQUIRE(game.play(10) == "too low");

    history.push_back(50);
    REQUIRE(game.play(50) == "too high");

    history.push_back(42);
    REQUIRE(game.play(42) == "Win");

    REQUIRE(history[0] == 10);
    REQUIRE(history[1] == 50);
    REQUIRE(history[2] == 42);
}
