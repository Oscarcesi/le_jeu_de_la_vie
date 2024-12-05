#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include "Simulation.h"
#include "grid.h"
#include <SFML/Graphics.hpp>

class Graphique : public Simulation
{
    private:
    sf::RenderWindow window;
    int vitesse;
    sf::RectangleShape button1;
    sf::RectangleShape construction;


    public:
        Graphique() : Simulation(), vitesse(8), button1(sf::Vector2f(200, 50)), construction(sf::Vector2f(grille.getCellSize(), grille.getCellSize())){}
        ~Graphique(){};

        void print();
        void run();
        void interactions();
};



#endif //GRAPHIQUE_H
