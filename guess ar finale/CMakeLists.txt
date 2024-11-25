cmake_minimum_required(VERSION 3.10)
project(guess)

# Inclure FetchContent pour télécharger Catch2 automatiquement
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.10 # Utilisez la version que vous préférez
)
FetchContent_MakeAvailable(Catch2)

# Cible principale : le jeu
add_executable(guess
    src/main.cpp
    src/Game.cpp
)

# Tests unitaires
add_executable(guess-test
    test/game_test.cpp
    src/Game.cpp
)

# Lier Catch2 avec les tests
target_link_libraries(guess-test PRIVATE Catch2::Catch2WithMain)

# Activer les tests
enable_testing()
add_test(NAME guess-test COMMAND guess-test)
