#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Simulation.h"
#include "Console.h"
#include "Graphique.h"
#include <iostream>
#include <string>

using namespace std;


int main() {
    int choix;
    cout << "Quel mode voulez vous (1 : console, 2 : graphique) ?";
    cin >> choix;

    if (choix == 1)
    {
        int x;
        cout << "Combien d'itérations voulez vous effectuer ?";
        cin >> x;
        Console console(5, 10, 10, x);
        console.run();
    }
    else if (choix == 2)
    {
        Graphique graphique(5, 100, 100);
        graphique.run();
    }
    else
    {
        cout << "Réponse invalide.";
    }

    return 0;
}
