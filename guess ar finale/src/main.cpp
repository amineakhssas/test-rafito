#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include "Game.hpp"

using namespace std;

int main() {
    Game g;
    srand(time(0));

    vector<int> history; // Historique des tentatives
    int aleatoire = rand() % 100 + 1; // Génération d'un nombre aléatoire
    g.newGame(aleatoire);

    cout << "Devinez un nombre entre 1 et 100 : \n";

    for (int i = 0; i < 5; i++) {
        cout << "Tentative #" << (i + 1) << ": ";
        int a;
        cin >> a;

        if (cin.fail()) { // Gestion des entrées invalides
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrée invalide. Réessayez.\n";
            i--; // Ne pas compter l'entrée invalide
            continue;
        }

        history.push_back(a); // Ajout de la tentative dans l'historique

        string result = g.play(a);
        cout << "Historique : ";
        for (int h : history) {
            cout << h << " ";
        }
        cout << "\n" << result << endl;

        if (result == "Win") {
            cout << "Félicitations ! Vous avez gagné.\n";
            return 0;
        }
    }

    cout << "Dommage ! Vous avez perdu. Le nombre à deviner était : " << aleatoire << endl;
    return 0;
}
