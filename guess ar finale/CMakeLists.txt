cmake_minimum_required(VERSION 3.10)
project(guess)

include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.10 # Vous pouvez remplacer par une version compatible
)
FetchContent_MakeAvailable(Catch2)

add_executable(guess
    src/main.cpp src/Game.cpp)

add_executable(guess-test
    test/game_test.cpp src/Game.cpp)
target_link_libraries(guess-test Catch2::Catch2)

enable_testing()
add_test(NAME guess-test COMMAND guess-test)
