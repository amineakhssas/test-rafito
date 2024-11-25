#include <iostream>
#include <vector>
#include "Game.hpp"
#include <ctime>
#include <cstdlib>
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
        history.push_back(a);

        if (cin.fail()) { // Gestion des entrées invalides
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrée invalide. Réessayez.\n";
            history.pop_back();
            i--;
            continue;
        }

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
