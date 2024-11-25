cmake_minimum_required(VERSION 3.0)
project(guess)

add_executable(guess
    src/main.cpp src/Game.cpp)

add_executable(guess-test
    test/game_test.cpp src/Game.cpp)

enable_testing()
add_test(guess-test guess-test)
