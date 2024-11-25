cmake_minimum_required(VERSION 3.10)
project(guess)

# Ajoutez cette ligne pour trouver Catch2
find_package(Catch2 REQUIRED)

# Exécutable principal
add_executable(guess src/main.cpp src/Game.cpp)

# Exécutable pour les tests
add_executable(guess-test test/game_test.cpp src/Game.cpp)

# Liez Catch2 à l'exécutable des tests
target_link_libraries(guess-test Catch2::Catch2WithMain)

# Activez les tests
enable_testing()
add_test(NAME guess-test COMMAND guess-test)
