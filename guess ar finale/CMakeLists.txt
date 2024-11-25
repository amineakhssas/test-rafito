cmake_minimum_required(VERSION 3.10)

project(guess_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter le fichier de source principal
add_executable(guess src/main.cpp src/Game.cpp)

# Tests avec Catch2
find_package(Catch2 REQUIRED)
add_executable(guess-test test/game_test.cpp src/Game.cpp)
target_link_libraries(guess-test PRIVATE Catch2::Catch2WithMain)
