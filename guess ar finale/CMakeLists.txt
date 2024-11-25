cmake_minimum_required(VERSION 3.10)
project(guess)

set(CMAKE_CXX_STANDARD 17)

add_executable(guess
    src/main.cpp
    src/Game.cpp)

add_executable(guess-test
    test/game_test.cpp
    src/Game.cpp)

find_package(Catch2 REQUIRED)
target_link_libraries(guess-test PRIVATE Catch2::Catch2WithMain)

enable_testing()
add_test(NAME guess-test COMMAND guess-test)
