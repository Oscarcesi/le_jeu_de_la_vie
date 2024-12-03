#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Simulation.h"
#include "Console.h"
#include "Graphique.h"
#include <iostream>
#include <fstream>
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
        Console console(x);
        console.run();
    }
    else if (choix == 2)
    {
        Graphique graphique;
        graphique.run();
        
    }
    else
    {
        cout << "Réponse invalide.";
    }

    return 0;
}
