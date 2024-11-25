cmake_minimum_required(VERSION 3.10)
project(guess)

# Ajout de Catch2
find_package(Catch2 REQUIRED)

# Exécutable principal
add_executable(guess src/main.cpp src/Game.cpp)

# Cible pour les tests unitaires
add_executable(guess-test test/game_test.cpp src/Game.cpp)
target_link_libraries(guess-test Catch2::Catch2WithMain)

# Activer les tests
enable_testing()
add_test(NAME guess-test COMMAND guess-test)
