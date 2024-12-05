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
    try {  
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
    
    
    } catch (const std::exception &e) {
        std::cerr << "Exception non capturée : " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Exception inconnue capturée !" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
