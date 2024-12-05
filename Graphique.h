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

    public:
        Graphique() : Simulation(), vitesse(8), button1(sf::Vector2f(200, 50)){}
        ~Graphique(){};

        void print();
        void run();
        void deplacementClavier();
};



#endif //GRAPHIQUE_H
